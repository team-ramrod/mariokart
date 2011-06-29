/*
 * AtmlDemobinHeader.h
 *
 *  Created on: 2009-3-15
 *      Author: Tony.Liu
 */

#ifndef DEMOBINHEADER_H_
#define DEMOBINHEADER_H_

#include <string.h>

#define MAXSCRIPTSTRINGLINE 128

#define MAXSLIDESPERBIN 300

#define MAXLINKLEN 50

#define MAX_LINK_PER_SLIDE 10

#define MAX_DISPBOX_PER_SLIDE 4

#define DEMOSLIDEWIDTH 240

#define DEMOSLIDEHEIGHT 320

#define ClearDemoBINHeader(pHead) memset((pHead), 0xFF, sizeof(DemoBINHeader))

#define ClearSlideINFOHeader(pHead) memset((pHead), 0xFF, sizeof(SlideINFOHeader))

/// ATMEL DEMO BIN tag value
#define ATMLBINTAG 0x4C4D5441

//demo bin file header
typedef struct {
	unsigned int tag;//demo bin head,'A','T','M','L'
	unsigned int filesize;//bin file size
	unsigned int headersize;//headsize including all SlideINFOHeader fields
	unsigned int slidecount;//slide numbers
//	PPTINFO pptinfo[MAXSLIDESPERBIN];
} DemoBINHeader;

typedef struct {
	//value are converted from slides script. noted BMP anticlockwise rotated 90 degree
	unsigned int linkboxbottom;
	unsigned int linkboxleft;
	unsigned int linkboxwidth;
	unsigned int linkboxheight;
	//link string
	char linkstring[MAXLINKLEN];
}SlideLinkINFO;

typedef struct {
	//value are converted from slides script. noted BMP anticlockwise rotated 90 degree
	unsigned int dispboxbottom;
	unsigned int dispboxleft;
	unsigned int dispboxwidth;
	unsigned int dispboxheight;
} SlideDispINFO;

typedef struct {
	//properties for each slide, command string line supported only now.
	unsigned int propcnt; //numbers of properties
	char onInitCmds[MAXLINKLEN];
	char onRefreshCmds[MAXLINKLEN];
	char onCloseCmds[MAXLINKLEN];
} SlidePropINFO;

typedef struct {
	unsigned int slideoffset;
	unsigned int slidedatalength;
	unsigned int slidewidth;
	unsigned int slideheight;
	unsigned int dispboxcount;//0 means no display box, others mean yes
	SlideDispINFO dispboxinfo[MAX_DISPBOX_PER_SLIDE];
	unsigned int linkcount;
	SlideLinkINFO linkinfo[MAX_LINK_PER_SLIDE];
	unsigned int propyes;// 0 means no property settings, 1 or others mean yes
	SlidePropINFO propinfo;
} SlideINFOHeader;

#endif /* DEMOBINHEADER_H_ */
