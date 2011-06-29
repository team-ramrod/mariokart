//============================================================================
// Name        : CreateAtmelDemoBin.cpp
// Author      : Tony.Liu
// Version     :
// Copyright   : Your copyright notice
// Description : CreateAtmelDemoBin, c,c++ mix using for EasyBMP and regex compilation
//============================================================================


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "profile.h"
#include "CreateDemoBin.h"
#include "DemoBinHeader.h"


//show usage help
void ShowHelp(const char * exeName)
{
	printf("\n");
	printf("Usage: %s [options] <PPTpathAndnameWithoutExtName>", exeName);
	printf("\n  For example, sam3demo.ppt, after running VBS macro in PowerPoint, ");
	printf("\n  copy this file under the same directory, then Run:\n");
	printf("\n		            %s sam3demo", exeName);
	printf("\n  Options:");
	printf("\n  --help, show this information");
	printf("\n  -profile <EK-board-name>, build-in option sets, default board name is at91sam3u-ek");
	printf("\n  -profile help, display all build-in profile details");
	printf("\n  -width <resizedwith>, default is 320 pixel");
	printf("\n  -height <resizedheight>, default is 240 pixel");
	printf("\n  -bitdepth <bitdepth>, default is 16 bit");
	printf("\n  -rotate <clockwise_angel>, times of 90 degree within 360, default is 270 degree");
	printf("\n  -noreversebitmaporder, keep bitmap data original order, default reverse the order for at91sam3u-ek");
	printf("\n");
}

//show profile details
void ShowProfiles()
{
	printf("\n\r profiles details:");
	printf("\n\r -profile at91sam3u-ek <-> -bitdepth 16 -width 320 -height 240 -rotate 0");

}

//seek matched profile
static int ProfileOption(char *pProfile, BMPConvOpt *const pOption )
{
	unsigned int j;
	unsigned int i = sizeof(profile)/sizeof(Profile);

	for(j = 0; j < i; j++) {
		if(strcmp(pProfile, profile[j].pProfileName) == 0) {
			pOption->bitdepth			= profile[j].options.bitdepth;
			pOption->width				= profile[j].options.width;
			pOption->height				= profile[j].options.height;
			pOption->rotateangle		= profile[j].options.rotateangle;
			pOption->reversebitmaporder = profile[j].options.reversebitmaporder;
			return 0;
		}
	}

	return 1;
}

//get conversion setting option from execution arguments
static void GetOptsFromargv(int argc, char **argv, BMPConvOpt *pOption)
{
	int i;

	//set default option value, it is used for at91SAM3u-ek demo on SDCARD or NANDFLASH
	pOption->bitdepth = 16;
	pOption->width = 320;
	pOption->height = 240;
	pOption->rotateangle = 270;
	pOption->reversebitmaporder = 1;
    #if defined(MOVIE_MERGE_on)
    pOption->mvSlideNumber = 5;
    #endif
    #if defined(SLIDESHOW_MERGE_on)
    pOption->ssPageNumber = MAXSLIDESPERBIN;
    pOption->ssBitdepth = 16;
	pOption->ssWidth = 320;
	pOption->ssHeight = 240;
	pOption->ssRotateangle = 270;
	pOption->ssReverseBmpOrder = 1;
    #endif

	//parse argument
	for(i=1;i<argc-1;++i) {
		if(strcmp(argv[i], "-profile")==0) {
			if(!ProfileOption(argv[++i], pOption)) {
				break;
			}

			continue;
		}

		if(strcmp(argv[i], "-width")== 0) {
			pOption->width = (unsigned int)floor(atof(argv[++i]));
			continue;
		}

		if(strcmp(argv[i], "-height")==0) {
			pOption->height = (unsigned int)floor(atof(argv[++i]));
			continue;
		}

		if(strcmp(argv[i], "-bitdepth")==0) {
			pOption->bitdepth = (unsigned int)floor(atof(argv[++i]));
			continue;
		}

		if(strcmp(argv[i], "-rotate")==0) {
			pOption->rotateangle = (unsigned int)floor(atof(argv[++i]));
			continue;
		}

		if(strcmp(argv[i], "-noreversebitmaporder")==0) {
			pOption->reversebitmaporder = 0;
			continue;
		}
		
        #if defined(MOVIE_MERGE_on)
        if(strcmp(argv[i], "-movieSlideNumber")==0) {
            pOption->mvSlideNumber = (unsigned int)floor(atof(argv[++i]));
            continue;
        }
        #endif
       
        #if defined(SLIDESHOW_MERGE_on)
        if(strcmp(argv[i], "-ssPageNumber")== 0) {
			pOption->ssPageNumber = (unsigned int)floor(atof(argv[++i]));
			continue;
		}
		
        if(strcmp(argv[i], "-ssWidth")== 0) {
			pOption->ssWidth = (unsigned int)floor(atof(argv[++i]));
			continue;
		}

		if(strcmp(argv[i], "-ssHeight")==0) {
			pOption->ssHeight = (unsigned int)floor(atof(argv[++i]));
			continue;
		}

		if(strcmp(argv[i], "-ssBitdepth")==0) {
			pOption->ssBitdepth = (unsigned int)floor(atof(argv[++i]));
			continue;
		}

		if(strcmp(argv[i], "-ssRotate")==0) {
			pOption->ssRotateangle = (unsigned int)floor(atof(argv[++i]));
			continue;
		}

		if(strcmp(argv[i], "-ssNoreversebitmaporder")==0) {
			pOption->ssReverseBmpOrder = 0;
			continue;
		}
        #endif
	}

	printf("\n *****Prepare: Converstion will use following options:");
    #if defined(SLIDESHOW_MERGE_on)
	printf("\n Bitdepth: %u; Width: %u; Height: %u; rotate angel: %u; reversebitorder: %s; SS Slide number: %u; SSBitdepth: %u; SSWidth: %u; SSHeight: %u; SS rotate angel: %u;",\
			pOption->bitdepth,\
			pOption->width,\
			pOption->height,\
			pOption->rotateangle,\
			pOption->reversebitmaporder ? "yes":"no",\
			pOption->ssPageNumber,\
            pOption->ssBitdepth,\
			pOption->ssWidth,\
			pOption->ssHeight,\
			pOption->ssRotateangle);
	#else
	printf("\n Bitdepth: %u; Width: %u; Height: %u; rotate angel: %u; reversebitorder: %s;",\
			pOption->bitdepth,\
			pOption->width,\
			pOption->height,\
			pOption->rotateangle,\
			pOption->reversebitmaporder ? "yes":"no");
	#endif

}

////////////////////////////////////////////////////////////////////
//Main portal
///////////////////////////////////////////////////////////////////

int main(int argc, char**argv)
{
	bool bRet=true;
	BMPConvOpt option;

	//Show usage help
	if(argc == 1 || \
			strcmp(argv[1], "--help")==0 || \
			strcmp(argv[1], "/?")==0 \
			)
	{
		ShowHelp(argv[0]);
		return 1;
	}

	if(argc == 3 && strcmp(argv[1], "-profile") == 0 && strcmp(argv[2], "help") == 0) {
		ShowProfiles();
		return 0;
	}

	//parse execution options ready for following conversion
	GetOptsFromargv(argc, argv, &option);

	//Init filename variables based on command argument
	printf("\n\n *****Step1: Create Neccesary file names!");
	Step1_CreateFileNameVars(argv[argc-1]);

#if 0
	//check if created file names are correct
	printf("\n\r %s ", pptScriptLink);
	printf("\n\r %s", pAtmlDemoBin);
	printf("\n\r %s", pBinContent);
	for(int i = 0; i< MAXSLIDESPERBIN; ++i) {
		printf("\n\r %s", pptSlidesBmp[i]);
	}
	for(int j=0; j < MAXSLIDESPERBIN; ++j) {
		printf("\n\r %s", pptSlides320x240Bmp[j]);
	}
	exit(0);
#endif

	//Parsed generated Script file
    #if !defined(MOVIE_MERGE_on)
	printf("\n\n *****Step2: Parse PPT slide information txt file");
	bRet &= Step2_ProcessPPTInfoFile(&option);
	printf("\n ****Step2 Result: %s ****", bRet?"Success":"Failure");
    #endif
 
	//Resize and rotate saved slide bmp files
	printf("\n\n *****Step3: Resize,rotate and reset bit depth of slide bmp file");
	printf("\nbitdepth %u, width %u, height %u, rotateangle %u",option.bitdepth, option.width, option.height, option.rotateangle);
    bRet &= Step3_ResizeAndRotateSlideBMP(&option);
	printf("\n ****Step3 Result: %s ****", bRet?"Success":"Failure");

	//Create Atmel Demo bin file
	printf("\n\n *****Step4: Create demo bin from above step generated information");
	bRet &= Step4_GenerateDemoBin(&option);
	printf("\n ****Step4 Result: %s ****", bRet?"Success":"Failure");

#if !defined(MOVIE_MERGE_on)
	//Show each bmp bitmap file header in demo bin file
	printf("\n\n *****Done: Check bitmap file information in generated demo bin");
	ShowEachBmpHeader();
#endif

	if(bRet) {
		printf("\n\n -----------Result: Creating demo bin file succeeds!-----------");
		return 0;
	}
	else {
		printf("\n\n ------------Result: Fail to Create right demo bin!-----------");
		return 1;
	}

}


