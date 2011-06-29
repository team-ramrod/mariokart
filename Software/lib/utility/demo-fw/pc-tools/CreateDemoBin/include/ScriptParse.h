/*
 * ScriptParse.h
 *
 *  Created on: 2009-3-15
 *      Author: Tony.Liu
 */

#ifndef SCRIPTPARSE_H_
#define SCRIPTPARSE_H_

//compile all pattern
bool CompileAllPtn();

//free all regex objects
void FreeAllRegex();

//is a space line?
bool IsSpaceLine(const char *string);

//match slide count line and return the count
bool GetSlideCount( const char *string, unsigned int *slidenum);

//check slide size line is correct
bool IsSlideSizeString(const char *string);

//match slide width line and return the width
bool GetSlideWidth( const char *string, unsigned int *slidewidth);

//match slide height line and return the height
bool GetSlideHeight( const char *string, unsigned int *slideheight);

//Is Display Box section starting?
bool IsDispBoxSectionStart(const char *string);

//match link top line and return link top position
bool GetDispBoxTop(const char *string, unsigned int *top);

//match link left line and return link left position
bool GetDispBoxLeft(const char *string, unsigned int *left);

//match link width line and return width value
bool GetDispBoxWidth(const char *string, unsigned int *width);

//match link width line and return width value
bool GetDispBoxHeight(const char *string, unsigned int *height);

//match hyperlink line and return link count
bool GetLinkCount(const char *string, unsigned int *linkcnt);

//match link address line and return the address
bool GetLinkAddr(const char *string, char *link);

//match link top line and return link top position
bool GetLinkTop(const char *string, unsigned int *top);

//match link left line and return link left position
bool GetLinkLeft(const char *string, unsigned int *left);

//match link width line and return width value
bool GetLinkWidth(const char *string, unsigned int *width);

//match link width line and return width value
bool GetLinkHeight(const char *string, unsigned int *height);

//Parse slide section of script
//Parse slide section of script
bool ParseSlideSection(const char *string, \
		unsigned int *slideindex, \
		unsigned int *slidewidth, \
		unsigned int *slideheight);

//Parse hyperlink section of script
bool ParseLinkSection(const char *string, \
		unsigned int *linkindex, \
		char *linkstr, \
		unsigned int *linktop, \
		unsigned int *linkleft, \
		unsigned int *linkwidth, \
		unsigned int *linkheight);

//Parse display box section of script
bool ParseDispBoxSection(const char *string, \
		unsigned int *disptop, \
		unsigned int *displeft, \
		unsigned int *dispwidth, \
		unsigned int *dispheight);

//Parse slide properties section of script
bool ParsePropertiesSection(const char *string, \
		char *pOnInitCmds, \
		char *pOnRefreshCmds, \
		char *pOnCloseCmds);

//Is slide section starting?
bool IsSlideSectionStart(const char *string);

//Is hyperlink section starting?
bool IsLinkSectionStart(const char *string);

//Is slide properties section starting?
bool IsPropertiesSectionStart(const char *string);

#endif /* SCRIPTPARSE_H_ */
