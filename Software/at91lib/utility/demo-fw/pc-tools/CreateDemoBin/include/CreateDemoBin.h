#ifndef __CREATEDEMOBIN_H
#define __CREATEDEMOBIN_H

////////////////////////////////////////////////////////////
//type definition
///////////////////////////////////////////////////////////
// BMP (Windows) Header Format
typedef struct  __attribute__ ((packed)) {
    /// signature, must be 4D42 hex
    unsigned short type;
    /// size of BMP file in bytes (unreliable)
    unsigned int fileSize;
    /// reserved, must be zero
    unsigned short reserved1;
    /// reserved, must be zero
    unsigned short reserved2;
    /// offset to start of image data in bytes
    unsigned int offset;
    /// size of BITMAPINFOHEADER structure
    unsigned int headerSize;
    /// image width in pixels
    unsigned int width;
    /// image height in pixels
    unsigned int height;
    /// number of planes in the image, must be 1
    unsigned short planes;
    /// number of bits per pixel (1, 4, 8, 16, 24, 32)
    unsigned short bits;
    /// compression type (0=none, 1=RLE-8, 2=RLE-4)
    unsigned int compression;
    /// size of image data in bytes (including padding)
    unsigned int imageSize;
    /// horizontal resolution in pixels per meter (unreliable)
    unsigned int xresolution;
    /// vertical resolution in pixels per meter (unreliable)
    unsigned int yresolution;
    /// number of colors in image, or zero
    unsigned int ncolours;
    /// number of important colors, or zero
    unsigned int importantcolours;
} BMPHeader;

//option structure for image conversion
typedef struct _BMPConvOptions {
	//bitdepth of bmp file stored in demo bin file
	unsigned int bitdepth;
	//IMPORTANT NOTES: following width and height means
	//                 resized image without any rotation
	//resized bmp width
	unsigned int width;
	//resized bmp height
	unsigned int height;
	//anti-clockwise rotate angle
	unsigned int rotateangle;
	//reverse bmp bitmap data order
	//some lcd controller needs to get BMP bitmap data from bottom to top
	//this is used to indicate conversion
	unsigned int reversebitmaporder;
    #if defined(MOVIE_MERGE_on)
    //slide number for movie binary
    unsigned int mvSlideNumber;
    #endif
    #if defined(SLIDESHOW_MERGE_on)
    unsigned int ssPageNumber;
    unsigned int ssBitdepth;
    unsigned int ssWidth;
    unsigned int ssHeight;
    unsigned int ssRotateangle;
    unsigned int ssReverseBmpOrder;
    #endif
} BMPConvOpt;

#define BMP24MAPLEN 320*240*3
#define BMP16MAPLEN 320*240*2

///////////////////////////////////////////////////////////////////////
//export functions, steps of creation of atmel demo bin file
//////////////////////////////////////////////////////////////////////

//Initialize filename variables
void Step1_CreateFileNameVars(char * name);

//Process ppt information txt file
bool Step2_ProcessPPTInfoFile(BMPConvOpt *pOption);

//Resize and Rotate slides
bool Step3_ResizeAndRotateSlideBMP(BMPConvOpt *pOption);

//create demo bin from above variables
bool Step4_GenerateDemoBin(BMPConvOpt *pOption);

//show generated bin contained bmp information
void ShowEachBmpHeader();


#endif
