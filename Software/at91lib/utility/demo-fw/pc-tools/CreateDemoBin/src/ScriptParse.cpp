/*
 * ScriptParse.cpp
 *
 *  Created on: 2009-3-15
 *      Author: Tony.Liu
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "regex.h"
#include "ScriptParse.h"
#include "DemoBinHeader.h"

#define SUBSLEN 10
#define EBUFLEN 128 /* error buffer length */
#define BUFLEN 1024 /* matched buffer length */

using namespace std;

static size_t len;
static regex_t reSpace;
static regex_t reSlideCnt;
static regex_t reSlideSize;
static regex_t reSlideWidth;
static regex_t reSlideHeight;

static regex_t reSlideDispString;
static regex_t reSlideDispTop;
static regex_t reSlideDispLeft;
static regex_t reSlideDispWidth;
static regex_t reSlideDispHeight;

static regex_t reSlideLink;
static regex_t reSlideLinkAddr;
static regex_t reSlideLinkTop;
static regex_t reSlideLinkLeft;
static regex_t reSlideLinkWidth;
static regex_t reSlideLinkHeight;

static regex_t reSlideProps;
static regex_t reSlideOnInitCmds;
static regex_t reSlideOnRefreshCmds;
static regex_t reSlideOnCloseCmds;

static regmatch_t subs[SUBSLEN];
static char matched[BUFLEN];
static char errbuf[EBUFLEN];

static char *pSpacePtn = "^[[:space:]]+$";
static char *pSlideCntPtn = "^Slide[[:blank:]]+([[:digit:]]+):[[:space:]]+$";
static char *pSlideSizePtn = "^Slide Size:[[:space:]]+$";
static char *pSlideWidthPtn = "^Width:[[:blank:]]+([[:digit:]]+([.][[:digit:]]+)?)[[:space:]]+$";
static char *pSlideHeightPtn = "^Height:[[:blank:]]+([[:digit:]]+([.][[:digit:]]+)?)[[:space:]]+$";

static char *pSlideDispBoxStringPtn = "^Display Box:[[:space:]]+$";
static char *pSlideDispBoxTopPtn = "^Top:[[:blank:]]+([[:digit:]]+([.][[:digit:]]+)?)[[:space:]]+$";
static char *pSlideDispBoxLeftPtn = "^Left:[[:blank:]]+([[:digit:]]+([.][[:digit:]]+)?)[[:space:]]+$";
static char *pSlideDispBoxWidthPtn = "^Width:[[:blank:]]+([[:digit:]]+([.][[:digit:]]+)?)[[:space:]]+$";
static char *pSlideDispBoxHeightPtn = "^Height:[[:blank:]]+([[:digit:]]+([.][[:digit:]]+)?)[[:space:]]+$";

static char *pSlideLinkPtn = "^HyperLink[[:blank:]]+([[:digit:]]+)::[[:space:]]+$";
static char *pSlideLinkAddrPtn = "^\"Link Address\":[[:blank:]]+[[:cntrl:]]*(.*)[[:space:]]+[[:cntrl:]]+$";
static char *pSlideLinkTopPtn = "^Top:[[:blank:]]+([[:digit:]]+([.][[:digit:]]+)?)[[:space:]]+$";
static char *pSlideLinkLeftPtn = "^Left:[[:blank:]]+([[:digit:]]+([.][[:digit:]]+)?)[[:space:]]+$";
static char *pSlideLinkWidthPtn = "^Width:[[:blank:]]+([[:digit:]]+([.][[:digit:]]+)?)[[:space:]]+$";
static char *pSlideLinkHeightPtn = "^Height:[[:blank:]]+([[:digit:]]+([.][[:digit:]]+)?)[[:space:]]+$";

static char *pSlidePropsPtn = "^Properties::[[:space:]]+$";
static char *pSlideOnInitCmdsPtn = "^OnInitCmds:[[:blank:]]*[[:cntrl:]]*(.*)[[:space:]]+[[:cntrl:]]+$";
static char *pSlideOnRefreshCmdsPtn = "^OnRefreshCmds:[[:blank:]]*[[:cntrl:]]*(.*)[[:space:]]+[[:cntrl:]]+$";
static char *pSlideOnCloseCmdsPtn = "^OnCloseCmds:[[:blank:]]*[[:cntrl:]]*(.*)[[:space:]]+[[:cntrl:]]+$";

//compile pattern
static bool CompileRegexPtn(regex_t *compiled, const char *pattern, int cflags)
{
	int err = regcomp (compiled, pattern, cflags);
	if (err)
	{
		len = regerror (err, compiled, errbuf, sizeof (errbuf));
		//printf("\n\r error compilation!");
		fprintf (stderr, "error: regcomp: %s\n", errbuf);
		return false;
	}

	return true;
}

//compile all pattern
bool CompileAllPtn()
{
	bool bRet=true;

	//compile slide section head pattern
	bRet &= CompileRegexPtn(&reSpace, pSpacePtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideCnt, pSlideCntPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideSize, pSlideSizePtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideWidth, pSlideWidthPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideHeight, pSlideHeightPtn, REG_EXTENDED | REG_NEWLINE);

	//compile display box section pattern
	bRet &= CompileRegexPtn(&reSlideDispString, pSlideDispBoxStringPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideDispTop, pSlideDispBoxTopPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideDispLeft, pSlideDispBoxLeftPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideDispWidth, pSlideDispBoxWidthPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideDispHeight, pSlideDispBoxHeightPtn, REG_EXTENDED | REG_NEWLINE);

	//compile hyperlink section pattern
	bRet &= CompileRegexPtn(&reSlideLink, pSlideLinkPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideLinkAddr, pSlideLinkAddrPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideLinkTop, pSlideLinkTopPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideLinkLeft, pSlideLinkLeftPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideLinkWidth, pSlideLinkWidthPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideLinkHeight, pSlideLinkHeightPtn, REG_EXTENDED | REG_NEWLINE);

	//compile slide config section pattern
	bRet &= CompileRegexPtn(&reSlideProps, pSlidePropsPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideOnInitCmds, pSlideOnInitCmdsPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideOnRefreshCmds, pSlideOnRefreshCmdsPtn, REG_EXTENDED | REG_NEWLINE);
	bRet &= CompileRegexPtn(&reSlideOnCloseCmds, pSlideOnCloseCmdsPtn, REG_EXTENDED | REG_NEWLINE);

	return bRet;
}

//free compiled regex pattern
void FreeAllRegex()
{
	//free slide section head patterns
	regfree(&reSlideCnt);
	regfree(&reSlideSize);
	regfree(&reSlideWidth);
	regfree(&reSlideHeight);

	//free slide display box section patterns
	regfree(&reSlideDispString);
	regfree(&reSlideDispTop);
	regfree(&reSlideDispLeft);
	regfree(&reSlideDispWidth);
	regfree(&reSlideDispHeight);

	//free slide hyperlink section patterns
	regfree(&reSlideLink);
	regfree(&reSlideLinkAddr);
	regfree(&reSlideLinkTop);
	regfree(&reSlideLinkLeft);
	regfree(&reSlideWidth);
	regfree(&reSlideHeight);

	//free slide config section pattern
	regfree(&reSlideProps);
	regfree(&reSlideOnInitCmds);
	regfree(&reSlideOnRefreshCmds);
	regfree(&reSlideOnCloseCmds);;
}

//match the pattern?
bool RegexMatch(const regex_t *compiled, const char *string, size_t nmatch, regmatch_t *matchptr, int eflags)
{
	bool bRet = true;

	int err = regexec (compiled, string, (size_t)nmatch, matchptr,eflags);

	if (err == REG_NOMATCH)
	{
		//fprintf (stderr, "Sorry, no match ...\n");
		bRet = false;
	}
	else if (err)
	{
		len = regerror (err, compiled, errbuf, sizeof (errbuf));
		fprintf (stderr, "error: regexec: %s\n", errbuf);
		bRet = false;
	}

	return bRet;
}

//is a space line?
bool IsSpaceLine(const char *string)
{
	bool bRet = RegexMatch(&reSpace, string, 0,0,0);

	return bRet;
}

//match slide count line and return the count
bool GetSlideCount( const char *string, unsigned int *slidenum)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_SLIDESECTION)
	printf("\n\r [Parsing slide count string is %s", string);
#endif

	bRet = RegexMatch(&reSlideCnt,string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot slide count line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_SLIDESECTION)
	printf("\n\r Parsed slide count is %s]",matched);
#endif

	*slidenum = (unsigned int)floor(atof(matched));

	return bRet;
}

//check slide size line is correct
bool IsSlideSizeString(const char *string)
{
	bool bRet = false;

	bRet = RegexMatch(&reSlideSize,string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot slide size string line...!");
		return bRet;
	}

	return bRet;
}

//match slide width line and return the width
bool GetSlideWidth( const char *string, unsigned int *slidewidth)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_SLIDESECTION)
	printf("\n\r [Parsing slide width string is %s", string);
#endif

	bRet = RegexMatch(&reSlideWidth,string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot slide width line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_SLIDESECTION)
	printf("\n\r Parsed slide width is %s]",matched);
#endif

	*slidewidth = (unsigned int)floor(atof(matched));

	return bRet;
}

//match slide height line and return the height
bool GetSlideHeight( const char *string, unsigned int *slideheight)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_SLIDESECTION)
	printf("\n\r [Parsing slide height string is %s", string);
#endif

	bRet = RegexMatch(&reSlideHeight,string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot slide height line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_SLIDESECTION)
	printf("\n\r Parsed slide height is %s]",matched);
#endif

	*slideheight = (unsigned int)floor(atof(matched));

	return bRet;
}

//match link top line and return link top position
bool GetDispBoxTop(const char *string, unsigned int *top)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_DISPBOXSECTION)
	printf("\n\r [Parsing display box top string is %s", string);
#endif

	bRet = RegexMatch(&reSlideDispTop, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot link top line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_DISPBOXSECTION)
	printf("\n\r Parsed display box top is %s]",matched);
#endif

	*top = (unsigned int)floor(atof(matched));

	return bRet;
}

//match link left line and return link left position
bool GetDispBoxLeft(const char *string, unsigned int *left)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_DISPBOXSECTION)
	printf("\n\r [Parsing display box left string is %s", string);
#endif

	bRet = RegexMatch(&reSlideDispLeft, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot link left line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_DISPBOXSECTION)
	printf("\n\r Parsed display box left is %s]",matched);
#endif

	*left = (unsigned int)floor(atof(matched));

	return bRet;
}

//match link width line and return width value
bool GetDispBoxWidth(const char *string, unsigned int *width)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_DISPBOXSECTION)
	printf("\n\r [Parsing display box width string is %s", string);
#endif

	bRet = RegexMatch(&reSlideDispWidth, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot link width line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_DISPBOXSECTION)
	printf("\n\r Parsed display box width is %s]",matched);
#endif

	*width = (unsigned int)floor(atof(matched));

	return bRet;
}

//match link width line and return width value
bool GetDispBoxHeight(const char *string, unsigned int *height)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_DISPBOXSECTION)
	printf("\n\r [Parsing display box height string is %s", string);
#endif

	bRet = RegexMatch(&reSlideDispHeight, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot link height line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_DISPBOXSECTION)
	printf("\n\r Parsed display box height is %s]",matched);
#endif

	*height = (unsigned int)floor(atof(matched));

	return bRet;
}

//match hyperlink line and return link count
bool GetLinkCount(const char *string, unsigned int *linkcnt)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r [Parsing link count string is %s", string);
#endif

	bRet = RegexMatch(&reSlideLink, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot hyperlink line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r Parsed link count is %s]",matched);
#endif

	*linkcnt = (unsigned int)floor(atof(matched));

	return bRet;
}

//match link address line and return the address
bool GetLinkAddr(const char *string, char *link)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r [Parsing link address string is %s", string);
#endif

	bRet = RegexMatch(&reSlideLinkAddr, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot link address line...!");
		return bRet;
	}

	//printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;

	if(len > MAXLINKLEN - 1) {
		fprintf(stderr, "\n\r link address is too long!");
		return false;
	}

	memcpy (link, string + subs[1].rm_so, len);
	link[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r");
	for(int j=0;j<len;++j) {
		printf(" %d",link[j]);
	}
	printf("\n\r Parsed link address %s]",link);
#endif

	return bRet;
}

//match link top line and return link top position
bool GetLinkTop(const char *string, unsigned int *top)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r [Parsing link top string is %s", string);
#endif

	bRet = RegexMatch(&reSlideLinkTop, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot link top line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r Parsed link top is %s]",matched);
#endif

	*top = (unsigned int)floor(atof(matched));

	return bRet;
}

//match link left line and return link left position
bool GetLinkLeft(const char *string, unsigned int *left)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r [Parsing link left string is %s", string);
#endif

	bRet = RegexMatch(&reSlideLinkLeft, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot link left line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r Parsed link left is %s]",matched);
#endif

	*left = (unsigned int)floor(atof(matched));

	return bRet;
}

//match link width line and return width value
bool GetLinkWidth(const char *string, unsigned int *width)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r [Parsing link width string is %s", string);
#endif

	bRet = RegexMatch(&reSlideLinkWidth, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot link width line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r Parsed link width is %s]",matched);
#endif

	*width = (unsigned int)floor(atof(matched));

	return bRet;
}

//match link width line and return width value
bool GetLinkHeight(const char *string, unsigned int *height)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r [Parsing link height string is %s", string);
#endif

	bRet = RegexMatch(&reSlideLinkHeight, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot link height line...!");
		return bRet;
	}

//	printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;
	memcpy (matched, string + subs[1].rm_so, len);
	matched[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_LINKSECTION)
	printf("\n\r Parsed link height is %s]",matched);
#endif

	*height = (unsigned int)floor(atof(matched));

	return bRet;
}

//get OnInit cmds of slide
bool GetSlideOnInitCmds(const char *string, char * pOnInitCmds)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_PROPSECTION)
	printf("\n\r [Parsing OnInitCmds string is %s", string);
#endif

	bRet = RegexMatch(&reSlideOnInitCmds, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\r Not OnInit commands line...!");
		return bRet;
	}

	//printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;

	if(len > MAXLINKLEN - 1) {
		fprintf(stderr, "\n\r OnInitCmds line is too long!");
		return false;
	}

	memcpy (pOnInitCmds, string + subs[1].rm_so, len);
	pOnInitCmds[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_PROPSECTION)
	printf("\n\r Hex code of parsed: ");
	for(int j=0;j<len;++j) {
		printf(" %d",pOnInitCmds[j]);
	}
	printf("\n\r Parsed OnInitCmds: %s]",pOnInitCmds);
#endif

	return bRet;
}

//Get OnRefreshCmds of slide
bool GetSlideOnRefreshCmds(const char *string, char *pOnRefreshCmds)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_PROPSECTION)
	printf("\n\r [Parsing OnRefresh string is %s", string);
#endif

	bRet = RegexMatch(&reSlideOnRefreshCmds, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot OnRefresh commands line...!");
		return bRet;
	}

	//printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;

	if(len > MAXLINKLEN - 1) {
		fprintf(stderr, "\n\r OnRefreshCmds is too long!");
		return false;
	}

	memcpy (pOnRefreshCmds, string + subs[1].rm_so, len);
	pOnRefreshCmds[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_PROPSECTION)
	printf("\n\r Hex code of parsed: ");
	for(int j=0;j<len;++j) {
		printf(" %d",pOnRefreshCmds[j]);
	}
	printf("\n\r Parsed OnRefreshCmds: %s]",pOnRefreshCmds);
#endif

	return bRet;
}

//Get OnCloseCmds of slide
bool GetSlideOnCloseCmds(const char *string, char *pOnCloseCmds)
{
	bool bRet = false;

#if defined(DEBUG_BEFOREPARSE) && defined(DEBUG_PROPSECTION)
	printf("\n\r [Parsing OnCloseCmds string is %s", string);
#endif

	bRet = RegexMatch(&reSlideOnCloseCmds, string, (size_t)SUBSLEN, subs, 0);
	//not match pattern
	if(!bRet) {
		fprintf(stderr, "\n\rNot OnCloseCmds line...!");
		return bRet;
	}

	//printf("\n\r %d, %d",subs[1].rm_eo, subs[1].rm_so);
	int len = subs[1].rm_eo - subs[1].rm_so;

	if(len > MAXLINKLEN - 1) {
		fprintf(stderr, "\n\r OnCloseCmds is too long!");
		return false;
	}

	memcpy (pOnCloseCmds, string + subs[1].rm_so, len);
	pOnCloseCmds[len] = '\0';

#if defined(DEBUG_AFTERPARSE) && defined(DEBUG_PROPSECTION)
	printf("\n\r  Hex code of parsed: ");
	for(int j=0;j<len;++j) {
		printf(" %d",pOnCloseCmds[j]);
	}
	printf("\n\r Parsed OncloseCmds %s]",pOnCloseCmds);
#endif

	return bRet;
}

//Parse slide section of script
bool ParseSlideSection(const char *string, \
		unsigned int *slideindex, \
		unsigned int *slidewidth, \
		unsigned int *slideheight)
{
	bool bRet = true;

	//parse slide section
	bRet &= GetSlideCount(string, slideindex);
	bRet &= IsSlideSizeString(string+MAXSCRIPTSTRINGLINE);
	bRet &= GetSlideWidth(string+MAXSCRIPTSTRINGLINE*2, slidewidth);
	bRet &= GetSlideHeight(string+MAXSCRIPTSTRINGLINE*3, slideheight);

	//one of parsing fails
	if(!bRet) {
		fprintf(stderr, "\n\rScript section format is not right!");
		return false;
	}

	return bRet;
}

//Parse hyperlink section of script
bool ParseLinkSection(const char *string, \
		unsigned int *linkindex, \
		char *linkstr, \
		unsigned int *linktop, \
		unsigned int *linkleft, \
		unsigned int *linkwidth, \
		unsigned int *linkheight)
{
	bool bRet = true;

	//parse link section
	bRet &= GetLinkCount(string, linkindex);
	bRet &= GetLinkAddr(string+MAXSCRIPTSTRINGLINE, linkstr);
	bRet &= GetLinkTop(string+MAXSCRIPTSTRINGLINE*2, linktop);
	bRet &= GetLinkLeft(string+MAXSCRIPTSTRINGLINE*3, linkleft);
	bRet &= GetLinkWidth(string+MAXSCRIPTSTRINGLINE*4, linkwidth);
	bRet &= GetLinkHeight(string+MAXSCRIPTSTRINGLINE*5, linkheight);

	//one of parsing fails
	if(!bRet) {
		fprintf(stderr, "\n\r Script link section format is not right!");
		return false;
	}

	return bRet;
}

//Parse display box section of script
bool ParseDispBoxSection(const char *string, \
		unsigned int *disptop, \
		unsigned int *displeft, \
		unsigned int *dispwidth, \
		unsigned int *dispheight)
{
	bool bRet = true;

	//parse link section
	bRet &= IsDispBoxSectionStart(string);
	bRet &= GetDispBoxTop(string+MAXSCRIPTSTRINGLINE, disptop);
	bRet &= GetDispBoxLeft(string+MAXSCRIPTSTRINGLINE*2, displeft);
	bRet &= GetDispBoxWidth(string+MAXSCRIPTSTRINGLINE*3, dispwidth);
	bRet &= GetDispBoxHeight(string+MAXSCRIPTSTRINGLINE*4, dispheight);

	//one of parsing fails
	if(!bRet) {
		fprintf(stderr, "\n\r Script link section format is not right!");
		return false;
	}

	return bRet;
}

//Parse slide properties section of script
bool ParsePropertiesSection(const char *string, \
		char *pOnInitCmds, \
		char *pOnRefreshCmds, \
		char *pOnCloseCmds)
{
	bool bRet = true;

	//parse slide properties section
	bRet &= IsPropertiesSectionStart(string);
	bRet &= GetSlideOnInitCmds(string+MAXSCRIPTSTRINGLINE, pOnInitCmds);
	bRet &= GetSlideOnRefreshCmds(string+MAXSCRIPTSTRINGLINE*2, pOnRefreshCmds);
	bRet &= GetSlideOnCloseCmds(string+MAXSCRIPTSTRINGLINE*3, pOnCloseCmds);

	//if any one of parsing fails
	if(!bRet) {
		fprintf(stderr, "\n\r Script slide properties section format is not right!");
		return false;
	}

	return bRet;
}

//Is slide section starting?
bool IsSlideSectionStart(const char *string)
{
	bool bRet;
	bRet = RegexMatch(&reSlideCnt,string, (size_t)SUBSLEN, subs, 0);

	return bRet;
}

//Is hyperlink section starting?
bool IsLinkSectionStart(const char *string)
{
	bool bRet;
	bRet = RegexMatch(&reSlideLink, string, (size_t)SUBSLEN, subs, 0);

	return bRet;
}

//Is Display Box section starting?
bool IsDispBoxSectionStart(const char *string)
{
	bool bRet;
	bRet = RegexMatch(&reSlideDispString, string, (size_t)SUBSLEN, subs, 0);

	return bRet;
}

//Is slide properties section starting?
bool IsPropertiesSectionStart(const char *string)
{
	bool bRet;

	bRet = RegexMatch(&reSlideProps, string, (size_t)SUBSLEN, subs, 0);

	return bRet;
}




