/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

#ifndef DEMOBINHEADER_H_
#define DEMOBINHEADER_H_

#include <string.h>

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

#define MAXSCRIPTSTRINGLINE 128

#define MAXSLIDESPERBIN 50

#define MAXLINKLEN 50

#define MAX_LINK_PER_SLIDE 10

#define MAX_DISPBOX_PER_SLIDE 4

#define DEMOSLIDEWIDTH 240

#define DEMOSLIDEHEIGHT 320

#define ClearDemoBINHeader(pHead) memset((pHead), 0xFF, sizeof(DemoBINHeader))

#define ClearSlideINFOHeader(pHead) memset((pHead), 0xFF, sizeof(SlideINFOHeader))

/// ATMEL DEMO BIN tag value
#define ATMLBINTAG 0x4C4D5441

/// demo bin file header
typedef struct {
	unsigned int tag;///demo bin head,'A','T','M','L'
	unsigned int filesize;///bin file size
	unsigned int headersize;///headsize including all SlideINFOHeader fields
	unsigned int slidecount;///slide numbers
} DemoBINHeader;

typedef struct {
	///value are converted from slides script. noted BMP anticlockwise rotated 90 degree
	unsigned int linkboxbottom;
	unsigned int linkboxleft;
	unsigned int linkboxwidth;
	unsigned int linkboxheight;
	///link string
	char linkstring[MAXLINKLEN];
}SlideLinkINFO;

typedef struct {
	///value are converted from slides script. noted BMP anticlockwise rotated 90 degree
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

#endif /// DEMOBINHEADER_H_
