#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "regex.h"
#include "EasyBMP.h"
#include "ScriptParse.h"
#include "DemoBinHeader.h"
#include "CreateDemoBin.h"

using namespace std;

#define _GNU_SOURCE

///////////////////////////////////////////////////////////////////////////////////////////
//variable used
//////////////////////////////////////////////////////////////////////////////////////////

//slide bmp file name array
static char  pptSlidesBmp[MAXSLIDESPERBIN][256];
//converted slide bmp file name array;
static char  pptSlidesResizedBmp[MAXSLIDESPERBIN][256];

//generated PPT information txt file,default set as Sam3DEMO.txt
//will be changed based execution argument
static char pptScriptLink[256] = "Sam3DEMO.txt";
//generated demo bin file name
//will be changed based on execution argument
static char pAtmlDemoBin[256] = "Sam3DEMO.bin";
//temp file to link all bitmap file, used during creation,will be removed
//in the end of conversion
static char pBinContent[256] = "Sam3DEMOContent.tmp";

//variables for parsing script file
static char line[6*MAXSCRIPTSTRINGLINE];//[6][128];
static unsigned int slidecnt, slidewidth, slideheight;
static unsigned int linkcnt, linktop, linkleft, linkwidth, linkheight;
static unsigned int dispboxtop, dispboxleft, dispboxwidth, dispboxheight;
static char linkaddr[MAXLINKLEN];
static char oninitcmds[MAXLINKLEN], onrefreshcmds[MAXLINKLEN], onclosecmds[MAXLINKLEN];

//used to count slides parsed.
static unsigned int loop=0;
//binfile header
static DemoBINHeader binhead;
//each slide information. valid count is binhead.slidecount
static SlideINFOHeader slideinfo[MAXSLIDESPERBIN];
//used to store parsed slides index for reading slide bmp file
static unsigned int parsedslides[MAXSLIDESPERBIN];

//////////////////////////////////////////////////////////////////////////////////
//Internal function
/////////////////////////////////////////////////////////////////////////////////

//rotate BMP with clockwise angel 90 degree
static bool Rotate90(BMP &Input, BMP &Output)
{
	bool bRet = true;
    int srcHeight = Input.TellHeight();
    int srcWidth = Input.TellWidth();

    bRet &= Output.SetSize(srcHeight,srcWidth);

    for(int xpos = 0;xpos < srcWidth; xpos++)
    {
        for(int ypos=0;ypos<srcHeight;ypos++)
        {
        	bRet &= Output.SetPixel(srcHeight-1-ypos,xpos,Input.GetPixel(xpos,ypos));
        }
    }

    return bRet;
}

//Rotate BMP with clockwise angel 180 degree
static bool Rotate180(BMP &Input, BMP &Output)
{
	bool bRet = true;
	int srcHeight = Input.TellHeight();
	int srcWidth = Input.TellWidth();

	bRet &= Output.SetSize(srcWidth,srcHeight);

	for(int xpos = 0;xpos < srcWidth; xpos++)
	{
		for(int ypos=0;ypos<srcHeight;ypos++)
		{
			bRet &= Output.SetPixel(srcWidth-1-xpos,srcHeight-1-ypos,Input.GetPixel(xpos,ypos));
		}
	}

	return bRet;
}

//Rotate BMP with clockwise angel 270 degree
static bool Rotate270(BMP &Input, BMP &Output)
{
	bool bRet = true;
	int srcHeight = Input.TellHeight();
	int srcWidth = Input.TellWidth();

	bRet &= Output.SetSize(srcHeight,srcWidth);

	for(int xpos = 0;xpos < srcWidth; xpos++)
	{
		for(int ypos=0;ypos<srcHeight;ypos++)
		{
			bRet &= Output.SetPixel(ypos,srcWidth-1-xpos,Input.GetPixel(xpos,ypos));
		}
	}

	return bRet;
}

//rotate bmp file with clockwise angel
static bool Rotate(char *pInBmp, char *pOutBmp, unsigned int angle)
{
	bool bRet=false;

	//no need to do anything for 0,360,720...
	if(angle % 360 == 0) {
		return true;
	}

	BMP Input;
	Input.ReadFromFile(pInBmp);
	BMP Output;
	Output.SetBitDepth(Input.TellBitDepth());

	switch(angle) {
	case 90:
		bRet = Rotate90(Input, Output);
		break;

	case 180:
		bRet = Rotate180(Input,Output);
		break;

	case 270:
		bRet = Rotate270(Input,Output);
		break;

	default:
		fprintf(stderr, "\n\r Sorry, rotation angle other than 90,180,270 is not supported yet!");
		bRet = false;
		break;
	}

	if(bRet)
		bRet &= Output.WriteToFile(pOutBmp);

	return bRet;
}

//Read a not empty string line from file
static bool GetLineNoEmpty(FILE *fp, char *buf, size_t len)
{
	char *str=NULL;

	do {
	str = fgets(buf, len, fp);

	if(!str) {
		//fprintf(stderr, "\n\rFail to get a line!");
		return false;
	}
	}while(IsSpaceLine(buf));

	return true;
}

//convert a box zone coordinate based on rotate angle and coordinate origin
//input coordinate value use upper left as (0,0) coordinate origin
static bool HotZoneCoordinateConversion(
		//following four params define a box zone
		//value is in unresized coordinate, origin point is UPPER_LEFT
		unsigned int raw_zone_top,
		unsigned int raw_zone_left,
		unsigned int raw_zone_width,
		unsigned int raw_zone_height,
		//following four param discribe
		unsigned int resizedwidth,
		unsigned int resizedheight,
		double widthresizeratio,
		double heightresizeratio,
		//clockwise rotate angle
		unsigned int rotateangle,
		//coordinate origin remap, input values use PIC UPPER_LEFT as origin point
		unsigned int *out_zone_bottom,
		unsigned int *out_zone_left,
		unsigned int *out_zone_width,
		unsigned int *out_zone_height)
{
	unsigned int resizedzonetop, resizedzoneleft, resizedzonewidth, resizedzoneheight;
	unsigned int rotatedzonetop, rotatedzoneleft, rotatedzonewidth, rotatedzoneheight;

	resizedzonetop = (unsigned int)(raw_zone_top * heightresizeratio);
	resizedzoneleft = (unsigned int)(raw_zone_left * widthresizeratio);
	resizedzonewidth  = (unsigned int)(raw_zone_width * widthresizeratio);
	resizedzoneheight = (unsigned int)(raw_zone_height * heightresizeratio);

	switch(rotateangle) {
	case 0:
		rotatedzonetop = resizedzonetop;
		rotatedzoneleft = resizedzoneleft;
		rotatedzonewidth = resizedzonewidth;
		rotatedzoneheight = resizedzoneheight;
		break;
	case 90:
		rotatedzonetop = resizedwidth - (resizedzoneleft + resizedzonewidth);
		rotatedzoneleft = resizedheight - (resizedzonetop + resizedzoneheight);
		rotatedzonewidth = resizedzoneheight;
		rotatedzoneheight = resizedzonewidth;
		break;
	case 180:
		rotatedzonetop = resizedheight - (resizedzonetop + resizedzoneheight);
		rotatedzoneleft = resizedwidth - (resizedzoneleft + resizedzonewidth);
		rotatedzonewidth = resizedzonewidth;
		rotatedzoneheight = resizedzoneheight;
		break;
	case 270:
		rotatedzonetop = resizedwidth - (resizedzoneleft + resizedzonewidth);
		rotatedzoneleft = resizedzonetop;
		rotatedzonewidth = resizedzoneheight;
		rotatedzoneheight = resizedzonewidth;
		break;
	case 360:
		rotatedzonetop = resizedzonetop;
		rotatedzoneleft = resizedzoneleft;
		rotatedzonewidth = resizedzonewidth;
		rotatedzoneheight = resizedzoneheight;
		break;
	default:
		fprintf(stderr, "\n Sorry, rotate angle other than 0, 90, 180, 270,360 not supported yet!");
		return false;
	}

	if(out_zone_bottom && out_zone_left && out_zone_width && out_zone_height) {
		*out_zone_bottom  = rotatedzonetop + rotatedzoneheight;
		*out_zone_left = rotatedzoneleft;
		*out_zone_width = rotatedzonewidth;
		*out_zone_height = rotatedzoneheight;
	}else {
		fprintf(stderr, "\n One of output param point is null in HotZoneCoordinateConversion(...)!");
		return false;
	}

	return true;
}

/////////////////////////////////////////////////////////////////////////////////////
//Export functions:
//        Steps to Create demo bin
////////////////////////////////////////////////////////////////////////////////////

//Initialize filename variables
void Step1_CreateFileNameVars(char * name)
{
	sprintf(pptScriptLink, "%s.txt", name);

	for(int i = 0; i < MAXSLIDESPERBIN; ++i) {
        #if !defined(MOVIE_MERGE_on)
		sprintf(&pptSlidesBmp[i][0],"%s\\\\slide%d.bmp",name, i+1);
        #else
		if(i<9 && i>=0){
		    sprintf(&pptSlidesBmp[i][0],"%s\\\\speedway_loop_medium00%d.bmp",name, i+1);
		} else if (i <99) {
			sprintf(&pptSlidesBmp[i][0],"%s\\\\speedway_loop_medium0%d.bmp",name, i+1);
		} else{
			sprintf(&pptSlidesBmp[i][0],"%s\\\\speedway_loop_medium%d.bmp",name, i+1);
		}
		printf("\n\r name: %s", &pptSlidesBmp[i][0]);
        #endif
	}

	for(int j = 0; j < MAXSLIDESPERBIN; ++j) {
		sprintf(&pptSlidesResizedBmp[j][0], "%s\\\\slide%d_resized.bmp", name, j+1);
	}

	sprintf(pBinContent, "%scontent.tmp", name);
	sprintf(pAtmlDemoBin, "%s.bin", name);

}

//Process ppt information txt file
bool Step2_ProcessPPTInfoFile(BMPConvOpt *pOption)
{
	//open script file to process
	FILE *pScriptfile = fopen(pptScriptLink, "rb");
	if(!pScriptfile)
	{
		fclose(pScriptfile);
		fprintf(stderr, "\n\r Open ppt info txt file %s for creating demo bin fails!", pptScriptLink);
		return false;
	}

	//compile all regex pattern, if fail return
	if(!CompileAllPtn()) {
		fclose(pScriptfile);
		FreeAllRegex();
		fprintf(stderr, "\n\r Compilation pattern fails!");
		return false;
	}

	//clear all fields with 0xFF
	ClearDemoBINHeader(&binhead);
	for(int i=0;i<MAXSLIDESPERBIN;++i){
		ClearSlideINFOHeader(&slideinfo[i]);// use 0xFF to clear, considering flash using 0xff as raw data
	}

	//clear count fields as 0
	binhead.slidecount = 0;
	for(int i=0;i<MAXSLIDESPERBIN;++i){
		slideinfo[i].linkcount = 0;
		slideinfo[i].dispboxcount = 0;//default 0 means no display box
		slideinfo[i].propyes = 0; //default 0 means no properties settings
	}

	//read first line of script file
	if(!GetLineNoEmpty(pScriptfile, line, MAXSCRIPTSTRINGLINE)) {
		fclose(pScriptfile);
		FreeAllRegex();
		fprintf(stderr, "\n\r Fail to read a effective string line from script file !");
		return false;
	}

	//check first line if it match start of slide section
	if(!IsSlideSectionStart(line)) {
		fclose(pScriptfile);
		FreeAllRegex();
		fprintf(stderr, "\n\r Script file format is not right for slide section starting!");
		return false;
	}

	//start loop of parsing script
	for(loop = 0;loop < MAXSLIDESPERBIN ;++loop) {

		//read slide section from script file, 4 lines information each slide section
		for(int i = 1; i < 4; ++i) {
			if(!GetLineNoEmpty(pScriptfile, line+i*MAXSCRIPTSTRINGLINE, MAXSCRIPTSTRINGLINE)) {
				fclose(pScriptfile);
				FreeAllRegex();
				fprintf(stderr, "\n\r Script file format is not right for slide section!");
				return false;
			}
		}

		//parse slide section, to get slide count, slide width, slide height
		if(!ParseSlideSection(line, &slidecnt, &slidewidth, &slideheight)) {
			fclose(pScriptfile);
			FreeAllRegex();
			fprintf(stderr, "\n\r Script file format is not right for slide section!");
			return false;
		}

		//a slide section found, set some fields.
		//width and height gotten above will be used to calculating resized link box
		//gotten slide count will be used to index file name
		++binhead.slidecount;
		if(binhead.slidecount > MAXSLIDESPERBIN){
			//reach max slide per bin
			binhead.slidecount = MAXSLIDESPERBIN;
			break;
		}

		parsedslides[loop]= slidecnt - 1;//record file index in the file name array

		//store temp, as index to file name array, slides index in bin file not depends on this
		//parsedslides[binhead.slidecount - 1] = slidecnt;//store temp, as index to file name array

		//if rotate angle is times of 180 degree, then no need to switch width and height
        #if defined(SLIDESHOW_MERGE_on)
        if(pOption->ssPageNumber > 0 && loop < pOption->ssPageNumber){
        #endif
            if(pOption->rotateangle % 180 == 0){
                slideinfo[binhead.slidecount - 1].slidewidth = pOption->width;//fixed for demo
                slideinfo[binhead.slidecount - 1].slideheight = pOption->height;//fixed for demo
            } else if(pOption->rotateangle % 90 == 0) {
                //if rotate angle is times of 90 degree, but not times of 2*90 degree,
                //then switch width and height
                slideinfo[binhead.slidecount - 1].slidewidth = pOption->height;//fixed for demo
                slideinfo[binhead.slidecount - 1].slideheight = pOption->width;//fixed for demo
            } else {
                fprintf(stderr, "\n Sorry, rotate angle %u not supported for coordinate conversion!", pOption->rotateangle);
                fclose(pScriptfile);
                FreeAllRegex();
                return false;
            }
       #if defined(SLIDESHOW_MERGE_on)
       } 
       else {
            if(pOption->ssRotateangle % 180 == 0){
                slideinfo[binhead.slidecount - 1].slidewidth = pOption->ssWidth;//fixed for demo
                slideinfo[binhead.slidecount - 1].slideheight = pOption->ssHeight;//fixed for demo
            } else if(pOption->ssRotateangle % 90 == 0) {
                //if rotate angle is times of 90 degree, but not times of 2*90 degree,
                //then switch width and height
                slideinfo[binhead.slidecount - 1].slidewidth = pOption->ssHeight;//fixed for demo
                slideinfo[binhead.slidecount - 1].slideheight = pOption->ssWidth;//fixed for demo
            } else {
                fprintf(stderr, "\n Sorry, rotate angle %u not supported for coordinate conversion!", pOption->ssRotateangle);
                fclose(pScriptfile);
                FreeAllRegex();
                return false;
            }
       }
       #endif

		//parse each slide info field,i.e. display box, hyperlink, property config section for now
		for(;;) {
			//read available line in ppt information txt file
			if(!GetLineNoEmpty(pScriptfile, line, MAXSCRIPTSTRINGLINE)) {
				if(feof(pScriptfile)) {
					//end of file
					printf("\n\r OK, reach script file end!");
					fclose(pScriptfile);
					FreeAllRegex();
					return true;
				}
				fclose(pScriptfile);
				FreeAllRegex();
				fprintf(stderr, "\n\r Script file format is not right for slide info organization!");
				return false;
			}

			//
			//Is it slide section?
			//
			if(IsSlideSectionStart(line))
				break;//yes, break parsing slide info loop and goto next loop of parsing slide section

			//
			//Is it slide properties section?
			//
			if(IsPropertiesSectionStart(line)) {
				//
				//Note: Ony 1 properties field in bin file,
				//      So only the lastest properties section content will be recorded!!!
				//

				//properties section, read remained section string lines
				for(int i = 1; i < 4; ++i) {
					if(!GetLineNoEmpty(pScriptfile, line+i*MAXSCRIPTSTRINGLINE, MAXSCRIPTSTRINGLINE)) {
						fclose(pScriptfile);
						FreeAllRegex();
						fprintf(stderr, "\n\r Script file format is not right for 'Properties' section!");
						return false;
					}
				}

				if(!ParsePropertiesSection(line, \
						oninitcmds, \
						onrefreshcmds, \
						onclosecmds)) {
					fclose(pScriptfile);
					FreeAllRegex();
					fprintf(stderr, "\n\r Script file format is not righ for slide 'Properties' section!");
					return false;
				}

				//setting flag to indicate having property settings for this slide
				slideinfo[binhead.slidecount - 1].propyes = 1;
				slideinfo[binhead.slidecount - 1].propinfo.propcnt = 3;
				strcpy(slideinfo[binhead.slidecount - 1].propinfo.onInitCmds, oninitcmds);
				strcpy(slideinfo[binhead.slidecount - 1].propinfo.onRefreshCmds, onrefreshcmds);
				strcpy(slideinfo[binhead.slidecount - 1].propinfo.onCloseCmds, onclosecmds);

				continue;
			}

			//
			//Is it Display box section?
			//
			if(IsDispBoxSectionStart(line)) {
				//display box section, read remained section string lines
				for(int i = 1; i < 5; ++i) {
					if(!GetLineNoEmpty(pScriptfile, line+i*MAXSCRIPTSTRINGLINE, MAXSCRIPTSTRINGLINE)) {
						fclose(pScriptfile);
						FreeAllRegex();
						fprintf(stderr, "\n\r Script file format is not right for 'DisplayBox' section!");
						return false;
					}
				}

				//parse display box section
				if(!ParseDispBoxSection(line, \
						&dispboxtop, &dispboxleft, &dispboxwidth, &dispboxheight)) {
					fclose(pScriptfile);
					FreeAllRegex();
					fprintf(stderr, "\n\r Script file format is not right for 'DisplayBox' section!");
					return false;
				}

				//have display box in slide
				++slideinfo[binhead.slidecount - 1].dispboxcount;
				if(slideinfo[binhead.slidecount - 1].dispboxcount > MAX_DISPBOX_PER_SLIDE) {
					//reach max display box for a slide
					slideinfo[binhead.slidecount - 1].dispboxcount = MAX_DISPBOX_PER_SLIDE;
					continue;
				}

				//resized ratio
				double width_ratio;
				double height_ratio;
				unsigned int conv_bottom, conv_left, conv_width, conv_height;
                #if defined(SLIDESHOW_MERGE_on)
                if(pOption->ssPageNumber > 0 && loop < pOption->ssPageNumber){
                #endif
                    width_ratio = pOption->width / (double)slidewidth;
                    height_ratio = pOption->height / (double)slideheight;
                    
                #if defined(SLIDESHOW_MERGE_on)
                }
                else{
                    width_ratio = pOption->ssWidth / (double)slidewidth;
                    height_ratio = pOption->ssHeight / (double)slideheight;
               }
				#endif

               unsigned int tmpRet;
               #if defined(SLIDESHOW_MERGE_on)
               if(pOption->ssPageNumber > 0 && loop < pOption->ssPageNumber){
               #endif
			       tmpRet = HotZoneCoordinateConversion(
						dispboxtop,
						dispboxleft,
						dispboxwidth,
						dispboxheight,
						pOption->width,
						pOption->height,
						width_ratio,
						height_ratio,
						pOption->rotateangle,
						&conv_bottom,
						&conv_left,
						&conv_width,
						&conv_height);
               	#if defined(SLIDESHOW_MERGE_on)
                }
                else{
					tmpRet = HotZoneCoordinateConversion(
						dispboxtop,
						dispboxleft,
						dispboxwidth,
						dispboxheight,
						pOption->ssWidth,
						pOption->ssHeight,
						width_ratio,
						height_ratio,
						pOption->ssRotateangle,
						&conv_bottom,
						&conv_left,
						&conv_width,
						&conv_height);
                }
				#endif
				if(!tmpRet)
				{
					fclose(pScriptfile);
					FreeAllRegex();
					fprintf(stderr, "\n Script file format is not right!");
					return false;
				}
				unsigned int slideindex = binhead.slidecount - 1;
				unsigned int dispboxindex = slideinfo[binhead.slidecount-1].dispboxcount - 1;
				slideinfo[slideindex].dispboxinfo[dispboxindex].dispboxbottom = conv_bottom;
				slideinfo[slideindex].dispboxinfo[dispboxindex].dispboxleft = conv_left;
				slideinfo[slideindex].dispboxinfo[dispboxindex].dispboxwidth = conv_width;
				slideinfo[slideindex].dispboxinfo[dispboxindex].dispboxheight = conv_height;

				continue;
			}

			//
			//Is it hyperlink section?
			//
			if(IsLinkSectionStart(line)) {

				//hyperlink section, read remained section string lines
				for(int i = 1; i < 6; ++i) {
					if(!GetLineNoEmpty(pScriptfile, line+i*MAXSCRIPTSTRINGLINE, MAXSCRIPTSTRINGLINE)) {
						fclose(pScriptfile);
						FreeAllRegex();
						fprintf(stderr, "\n\r Script file format is not right!");
						return false;
					}
				}

				//parse hyperlink section
				if(!ParseLinkSection(line, &linkcnt, linkaddr, \
						&linktop, &linkleft, &linkwidth, &linkheight)) {
					fclose(pScriptfile);
					FreeAllRegex();
					fprintf(stderr, "\n\r Script file format is not right!");
					return false;
				}

				//parsed linkcnt is not used, considering if some links were removed by manual
				++(slideinfo[binhead.slidecount - 1].linkcount);
				if(slideinfo[binhead.slidecount - 1].linkcount > MAX_LINK_PER_SLIDE) {
					//reach max link limit for a slide
					slideinfo[binhead.slidecount - 1].linkcount = MAX_LINK_PER_SLIDE;
					continue;
				}

				//resize ratio
				double width_ratio;
                double height_ratio;
				unsigned int conv_bottom, conv_left, conv_width, conv_height;
				#if defined(SLIDESHOW_MERGE_on)
                if(pOption->ssPageNumber > 0 && loop < pOption->ssPageNumber){
                #endif
                    width_ratio = pOption->width / (double)slidewidth;
                    height_ratio = pOption->height / (double)slideheight;
                #if defined(SLIDESHOW_MERGE_on)
                }
                else{
                    width_ratio = pOption->ssWidth / (double)slidewidth;
                    height_ratio = pOption->ssHeight / (double)slideheight;
               }
				#endif
				//printf("\n linktop %u, linkleft %u, linkwidth %u, linkheight %u",\
				//		linktop, linkleft, linkwidth, linkheight);
				unsigned int tmpRet;
               #if defined(SLIDESHOW_MERGE_on)
               if(pOption->ssPageNumber > 0 && loop < pOption->ssPageNumber){
               #endif
			       tmpRet = HotZoneCoordinateConversion(
						//original link zone params, gotten from slide info txt file
						linktop,
						linkleft,
						linkwidth,
						linkheight,
						//resized slide width and height
						pOption->width,
						pOption->height,
						//resize ratio of width and height
						width_ratio,
						height_ratio,
						//clockwise rotate angle
						pOption->rotateangle,
						//pointer of output link zone param
						&conv_bottom,
						&conv_left,
						&conv_width,
						&conv_height);
               	#if defined(SLIDESHOW_MERGE_on)
                }
                else{
					tmpRet = HotZoneCoordinateConversion(
						//original link zone params, gotten from slide info txt file
						linktop,
						linkleft,
						linkwidth,
						linkheight,
						//resized slide width and height
						pOption->ssWidth,
						pOption->ssHeight,
						//resize ratio of width and height
						width_ratio,
						height_ratio,
						//clockwise rotate angle
						pOption->ssRotateangle,
						//pointer of output link zone param
						&conv_bottom,
						&conv_left,
						&conv_width,
						&conv_height);
                }
				#endif
				if(!tmpRet)
				{
					//link hot zone coordinate conversion fail, then return false
					fclose(pScriptfile);
					FreeAllRegex();
					fprintf(stderr, "\n Link zone coordinate conversion fail!");
					return false;
				}

				//set the slideinfo link value, noted bmp was rotated and resized.
				unsigned int linkindex = slideinfo[binhead.slidecount-1].linkcount - 1;
				unsigned int slideindex = binhead.slidecount - 1;
				slideinfo[slideindex].linkinfo[linkindex].linkboxbottom = conv_bottom;
				slideinfo[slideindex].linkinfo[linkindex].linkboxleft = conv_left;
				slideinfo[slideindex].linkinfo[linkindex].linkboxwidth = conv_width;
				slideinfo[slideindex].linkinfo[linkindex].linkboxheight = conv_height;

#ifdef DEBUG_LINKSECTION
				printf("\n\r [slide %d, link box %d is %u, %u, %u, %u,addr %s]", slideindex, linkindex,\
						slideinfo[slideindex].linkinfo[linkindex].linkboxbottom,\
						slideinfo[slideindex].linkinfo[linkindex].linkboxleft,\
						slideinfo[slideindex].linkinfo[linkindex].linkboxwidth,\
						slideinfo[slideindex].linkinfo[linkindex].linkboxheight, \
						linkaddr);
#endif

				strcpy(slideinfo[slideindex].linkinfo[linkindex].linkstring, linkaddr);

				continue;
			}

				//not slide section, not hyperlink section, not display box section, then err
				fclose(pScriptfile);
				FreeAllRegex();
				fprintf(stderr, "\n\r Script file format is not right!");
				return false;

		}
	}

	return true;
}


//Resize and Rotate slides
bool Step3_ResizeAndRotateSlideBMP(BMPConvOpt *pOption)
{
	bool bRet=true;
	BMP pptBMP;
	
	SetEasyBMPwarningsOff();//set warning message on

	//set pic width and height
	ScaleParam scale;

	//picture number
    #if defined(MOVIE_MERGE_on)
	binhead.slidecount = pOption->mvSlideNumber;
    #endif
	int picNum = binhead.slidecount; //sizeof(pptSlidesBmp)/sizeof(char*);
	//printf("\n\r has %d slides", picNum);

	//resize all picture
	int i;
	for(i=0; i<picNum;++i) {

        #if defined(SLIDESHOW_MERGE_on)
        if(pOption->ssPageNumber > 0 && i < pOption->ssPageNumber){
        #endif
		    scale.dimension.width = pOption->width;
    	    scale.dimension.height = pOption->height;
        #if defined(SLIDESHOW_MERGE_on)
        }
        else{
            scale.dimension.width = pOption->ssWidth;
    	    scale.dimension.height = pOption->ssHeight;
        }
        #endif
		//printf("\n\r process %s before create object",pptSlidesBmp[i]);
		if(!pptBMP.ReadFromFile(pptSlidesBmp[i])) {
			fprintf(stderr, "Fail to open slide bit map file for operation!");
			return false;
		}
		//printf("\n\r process %s before rescale",pptSlidesBmp[i]);
		bRet &= Rescale(pptBMP, 'd', scale);
		//printf("\n\r process %s before setbitdepth",pptSlidesBmp[i]);
        #if defined(SLIDESHOW_MERGE_on)
        if(pOption->ssPageNumber > 0 && i < pOption->ssPageNumber){
        #endif
		    bRet &= pptBMP.SetBitDepth(pOption->bitdepth);
        #if defined(SLIDESHOW_MERGE_on)
        }
        else{
            bRet &= pptBMP.SetBitDepth(pOption->ssBitdepth);
        }
        #endif

		//printf("\n\r process %s before writefile",pptSlidesBmp[i]);
		if(!pptBMP.WriteToFile(pptSlidesResizedBmp[i])) {
			fprintf(stderr, "Fail to open file to write converted bitmap file!");
			return false;
		}

		//Rotate BMP
		

        
        #if defined(SLIDESHOW_MERGE_on)
        if(pOption->ssPageNumber > 0 && i < pOption->ssPageNumber){
        #endif
            bRet &= Rotate(pptSlidesResizedBmp[i], pptSlidesResizedBmp[i], pOption->rotateangle);
        #if defined(SLIDESHOW_MERGE_on)
		}
		else{
			bRet &= Rotate(pptSlidesResizedBmp[i], pptSlidesResizedBmp[i], pOption->ssRotateangle);
		}
        #endif
#ifdef DEBUG_CONVBMPINFO
		FILE *pBmpFile;
		pBmpFile = fopen(pptSlidesResizedBmp[i], "rb");
		if(!pBmpFile) {
			fprintf(stderr, "\n\r fail to open");
			exit(3);
		}
		BMPHeader bmpHead;
		fread((char*)&bmpHead, 1, sizeof(BMPHeader), pBmpFile);
		fclose(pBmpFile);

		printf("\n\r============bmp header==============");
		printf("\n\r bmp.type is %x", bmpHead.type);
		printf("\n\r bmp.filesize is %d", bmpHead.fileSize);
		printf("\n\r bmp.width is %d", bmpHead.width);
		printf("\n\r bmp.height is %d", bmpHead.height);
		printf("\n\r bmp.compressed is %d", bmpHead.compression);
		printf("\n\r bmp.bitdepth is %d", bmpHead.bits);

#endif

	}

	return bRet;
}

//create demo bin from above variables
bool Step4_GenerateDemoBin(BMPConvOpt *pOption)
{
	FILE *pBMPfile, *pBinContentfile, *pDemoBin;
	unsigned int offset;
	unsigned int slideoffset[MAXSLIDESPERBIN];//store each slide offset in temp file
	char buf[1024];//as read/write file buffer

	//bin file tag 'ATML'
	binhead.tag = (unsigned int)'L'<<24 | (unsigned int)'M'<<16 |
	(unsigned int)'T'<<8 | (unsigned int) 'A';

	//first open bincontentfile to store all parsed slide bmp file
	pBinContentfile = fopen(pBinContent, "wb");
	if(!pBinContentfile) {
	fclose(pBinContentfile);
		fprintf(stderr, "\n Open file fail during creating bin!");
		return false;
	}

	slideoffset[0] = 0; offset = 0;
	//write all parsed slide bmp files into a bincontentfile
	for(unsigned int i = 0; i<binhead.slidecount; ++i) {

		//at start of each loop, offset is stored with end of position of bincontentfile
		unsigned int startoffset = offset;

		//slides index bigger than available bmp files
		if(parsedslides[i]> sizeof(pptSlidesResizedBmp)/ sizeof(char *)) {
			fclose(pBinContentfile);
			fprintf(stderr, "\n slide %u,i %u",parsedslides[i], i);
			fprintf(stderr, "\n Script file and bmp file count is not consistent!");
			return false;
		}

        #if !defined(MOVIE_MERGE_on)
        pBMPfile = fopen(pptSlidesResizedBmp[parsedslides[i]], "rb");
        #else
        pBMPfile = fopen(pptSlidesResizedBmp[i], "rb");
        #endif
		if(!pBMPfile) {
			fclose(pBinContentfile);
			fclose(pBMPfile);
			fprintf(stderr, "\n Open bmp file fail!");
			return false;
		}

		//convert bmp file bitmap data format to meet sam3 lcd coordinate
		if(pOption->reversebitmaporder){

			struct stat filestat;
			//////////////////////////
			unsigned int width = 0;
			unsigned int height = 0;

			#if defined(SLIDESHOW_MERGE_on)
            if(pOption->ssPageNumber > 0 && i < pOption->ssPageNumber){
            #endif
                width = pOption->width;
			    height = pOption->height;
            #if defined(SLIDESHOW_MERGE_on)
		    }
		    else{
			    width = pOption->ssWidth;
    			height = pOption->ssHeight;
		    }
            #endif
			//default 270 rotate make the bmp look like column-aligned store
			if(pOption->rotateangle % 180 == 0)
			{
			   width = pOption->height;
			   height = pOption->width;
			}
			#if defined(SLIDESHOW_MERGE_on)
            if(pOption->ssPageNumber > 0 && i < pOption->ssPageNumber){
            #endif
                if(pOption->rotateangle % 180 == 0)
			    {
			       width = pOption->height;
			       height = pOption->width;
			    }
            #if defined(SLIDESHOW_MERGE_on)
		    }
		    else{
			    if(pOption->ssRotateangle % 180 == 0)
			    {
			       width = pOption->ssHeight;
			       height = pOption->ssWidth;
			    }
		    }
            #endif
			//////////////////////////
			fstat(fileno(pBMPfile), &filestat);

			//printf("\n\r filesize is %u", filestat.st_size);
			char *bmpfilebuf = (char *)malloc(filestat.st_size+1024);
			char *convbmpbuf = (char *)malloc(filestat.st_size+1024);

			if(!bmpfilebuf || !convbmpbuf) {
				fclose(pBMPfile);
				fclose(pBinContentfile);
				fprintf(stderr, "\n malloc space for bmp file fail!");
				return false;
			}

			size_t numread = fread(bmpfilebuf, 1, filestat.st_size, pBMPfile);
			if(numread != filestat.st_size) {
				fclose(pBMPfile);
				fclose(pBinContentfile);
				fprintf(stderr, "\n Read bmp file length is not right!");
				return false;
			}
			unsigned int bitmapoffset = ((BMPHeader *)bmpfilebuf)->offset;

			unsigned int byteperpixel = ((BMPHeader *)bmpfilebuf)->bits;
			if(byteperpixel != 8 && byteperpixel != 16 && byteperpixel !=24 ) {
				fclose(pBMPfile);
				fclose(pBinContentfile);
				fprintf(stderr, "\n Conversion of bitmap order of bit depth %u is not supported yet!", byteperpixel);
				return false;
			}
			byteperpixel /= 8;

			memcpy(convbmpbuf, bmpfilebuf, bitmapoffset);

			//printf("\n\r Begin to convert %ubit bitmap data to meet sam3 lcd format!",byteperpixel*8);
			//convert orignal bitmap data to sam3-ek LCD api coordinate format
			unsigned int j,k,s;
			for (j = 0, s=0; j < width; ++j) {

				for (k = 0; k < height && j*k*byteperpixel < filestat.st_size; k++) {

					*(convbmpbuf+bitmapoffset+s) = bmpfilebuf[ bitmapoffset + \
					                                           ((width -j - 1)*height + k)*byteperpixel];
					if(byteperpixel == 2) {
						*(convbmpbuf+bitmapoffset+s+1) = bmpfilebuf[ bitmapoffset + \
						                                             ((width -j - 1)*height + k)*byteperpixel+1];
					}
					if(byteperpixel == 3) {
						*(convbmpbuf+bitmapoffset+s+2) = bmpfilebuf[ bitmapoffset + \
						                                             ((width -j - 1)*height + k)*byteperpixel+2];
					}
					s += byteperpixel;
				}
				//printf("\n\r j is %d",j);
			}

			//printf("\n\r End to convert %ubit bitmap data!",byteperpixel*8);

			//check if right long data conversion
			if(j != width || k != height) {
				fclose(pBMPfile);
				fclose(pBinContentfile);
				fprintf(stderr, "\n\r not all expected bitmap data converted!");
				return false;
			}

			fwrite(convbmpbuf, 1, filestat.st_size, pBinContentfile);
			offset += filestat.st_size;

			free(convbmpbuf);
			free(bmpfilebuf);
		} else {
			//directly write all bmp file into the tmp bincontent file
			while(!feof(pBMPfile)) {
				size_t numread = fread(buf, 1, 1024, pBMPfile);
				fwrite(buf, 1, numread, pBinContentfile);
				offset += numread;
			}
		}

		//store this slide bmp file size
		slideinfo[i].slidedatalength = offset - startoffset;
		//printf("\n\r slide size is %u", slideinfo[i].slidedatalength);

		//store offset for next slides
		slideoffset[i+1]= offset;
		//printf("\n\r offset is %d", offset);
		fclose(pBMPfile);

#ifdef DEBUG_DISPSECTION
		printf("\n --Slide %u has %u display box", i+1, slideinfo[i].dispboxcount);
		unsigned s;
		for(s = 0; s < slideinfo[i].dispboxcount; ++s) {
			printf("\n slide count is %d, botm %d, left %d, width %d, height %d",\
					i+1, slideinfo[i].dispboxinfo[s].dispboxbottom, \
					slideinfo[i].dispboxinfo[s].dispboxleft, \
					slideinfo[i].dispboxinfo[s].dispboxwidth, \
					slideinfo[i].dispboxinfo[s].dispboxheight);
		}
#endif

	}
	fclose(pBinContentfile);

	//get header size
	unsigned int headersize = sizeof(DemoBINHeader) + sizeof(SlideINFOHeader)* binhead.slidecount;

	//set headersize field of DemoBINHeader
	binhead.headersize = headersize;
	//printf("\n\r headersize is %d", headersize);

	//set file size field of DemoBINHeader
	binhead.filesize = headersize + offset;//offset should be bincontent filesize now

	//correct slide offset and then set them info information struct
	for(unsigned int i = 0; i < binhead.slidecount; ++i) {
		slideinfo[i].slideoffset = slideoffset[i] + headersize;
}

	pDemoBin = fopen(pAtmlDemoBin, "wb");
	if(!pDemoBin) {
		fclose(pDemoBin);
		fprintf(stderr, "\n\r Open file fail during creating bin!");
		return false;
	}

    #if !defined(MOVIE_MERGE_on)
	fwrite(&binhead, 1, sizeof(DemoBINHeader), pDemoBin);
	for(unsigned int i = 0; i < binhead.slidecount; ++i) {
		fwrite(&slideinfo[i], 1, sizeof(SlideINFOHeader), pDemoBin);
	}
    #else
    unsigned int tmpSlideCount = binhead.slidecount;
    fwrite(&tmpSlideCount, 1, sizeof(unsigned int), pDemoBin);
    #endif

	//open pBinContentfile in read mode for writing final demo bin
	pBinContentfile = fopen(pBinContent, "rb");
	if(!pBinContentfile) {
		fclose(pBinContentfile);
		fprintf(stderr, "\n\r Open file fail during creating bin!");
		return false;
	}

	//write the slide bin file to final demo bin
	while(!feof(pBinContentfile)) {
		size_t numread = fread(buf, 1, 1024, pBinContentfile);
		fwrite(buf, 1, numread, pDemoBin);
	}

	fclose(pBinContentfile);
	fclose(pDemoBin);

	//remove temporary bincontentfile
	if(remove(pBinContent))
		fprintf(stderr, "\n\r Can't remove temporary file!");

	return true;
}

//show generated bin contained bmp information
void ShowEachBmpHeader()
{
	FILE *pBinfile;
	DemoBINHeader binheader;
	SlideINFOHeader slideinfo;
	BMPHeader bmphead;

	pBinfile = fopen(pAtmlDemoBin, "rb");
	if(!pBinfile) {
		fprintf(stderr, "\n\r Fail to open demo bin file!!");
		return;
	}

	fread(&binheader, 1, sizeof(DemoBINHeader),pBinfile);
	unsigned int slidecount = binheader.slidecount;
	printf("\n\r Demo bin has %u slides", slidecount);

	for(unsigned int j=0; j < slidecount;++j) {
		fseek(pBinfile, sizeof(DemoBINHeader) + j *sizeof(SlideINFOHeader), SEEK_SET);
		fread(&slideinfo, 1, sizeof(SlideINFOHeader), pBinfile);
		printf("\n\r slide %d bitdata in %u,length %u",j, slideinfo.slideoffset, slideinfo.slidedatalength);
		fseek(pBinfile, slideinfo.slideoffset, SEEK_SET);
		fread(&bmphead, 1, sizeof(BMPHeader), pBinfile);
		printf("\n\r============bmp header==============");
		printf("\n\r bmp.type is %x", bmphead.type);
		printf("\n\r bmp.filesize is %d", bmphead.fileSize);
		printf("\n\r bmp.width is %d", bmphead.width);
		printf("\n\r bmp.height is %d", bmphead.height);
		printf("\n\r bmp.compressed is %d", bmphead.compression);
		printf("\n\r bmp.bitdepth is %d", bmphead.bits);

	}

	fclose(pBinfile);
}

