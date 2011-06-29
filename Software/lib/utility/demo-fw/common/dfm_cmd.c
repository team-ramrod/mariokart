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

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include <string.h>
#include <stdio.h>
#include "dfm_cmd.h"
#include "dfm_init.h"
#include "dfm_fatfs.h"
#include "dfm_console.h"
#include "dfm_lcd_tsd.h"
#include "dfm_button.h"

//------------------------------------------------------------------------------
//        variable definition
//------------------------------------------------------------------------------
#if defined(__ICCARM__)//IAR Compiler ID

///no need for declaration of section start and end variable in IAR

#elif defined(__CC_ARM) //MDK ARM Compiler ID

///variables for group start/end address
  extern unsigned int Image$$GShell_region$$Base;
  extern unsigned int Image$$GShell_region$$Limit;

#elif defined(__GNUC__)//GNU ARM Compiler ID

///variables for group start/end address 
extern long __gs_section_start, __gs_section_end;

#endif

///active group for execution of searching of commands. End with NULL
static char *gpActGroups[MAX_ACT_GROUP + 1] = {SYS_GROUP};// default group init first.

///entry

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///  parse a tring into '*argv[]', delimitor is space or tab
///  \param pRawString, the whole line of command string
///  \param argv, parsed argument string array 
///  \return number of parsed argument
//------------------------------------------------------------------------------
static int StringLineToArgs(char *pRawString, char *argv[]) {
  int argc = 0;
  
  if(pRawString == NULL)
    return 0;
  
  while(argc < MAX_CMD_ARGS) {
    
    // skip white space characters of string head 
    while ((*pRawString == ' ') || (*pRawString == '\t')) {
      ++pRawString;
    }
    
    if (*pRawString == '\0') {
      argv[argc] = NULL;
      return (argc);
    }
    
    argv[argc++] = pRawString;
    
    // find end of string 
    while (*pRawString && (*pRawString != ' ') && (*pRawString != '\t')) {
      ++pRawString;
    }

    if (*pRawString == '\0') {
    argv[argc] = NULL;
    return (argc);
    }
    
    *pRawString++ = '\0';
  }
  
  printf ("\n\r Too many arguments. Maximum argus supported is %d!", MAX_CMD_ARGS);
  
  return (argc);
}

//------------------------------------------------------------------------------
///  search active group name in array and return index. 
///  \param pStr, group name string
///  \param pStrArray, group array 
///  \param iArrayLen, array length
///  \return group index in group array, -1 if not found
//------------------------------------------------------------------------------
static int FindStrIdx(const char * pStr, const char * const pStrArray[], int iArrayLen)
{
  int i;
  
  //search, end when find NULL or exceed max len
  for(i = 0; i < iArrayLen && pStrArray[i] != NULL; ++i) {
    //printf("\n\r str is %s, %s, %d",pStr, pStrArray[i], iArrayLen);
    if(strcmp(pStr, pStrArray[i])==0) {
      break;
    }
  }
  
  //if not found
  if(i==iArrayLen || pStrArray[i] == NULL) {
    i = -1;
  }
  
  return i;
}

//------------------------------------------------------------------------------
///  Find command in active groups
///  \param pCmd, command name
///  \return pointer to command portal, NULL if not found
//------------------------------------------------------------------------------
static FStruct * FindCommand(const char * pCmd)
{
  int iGrpIdxAct;
  unsigned int i, iCmdNum;
  unsigned short int gm, im;// max:0xffff,  init value used to id fail search
  FStruct *pTmpFs, *pFsStart, *pFsEnd;
  
#if defined(__ICCARM__)  
  pFsStart = __section_begin(GSHELL_SECTION);
  pFsEnd   = __section_end(GSHELL_SECTION);
#elif defined(__CC_ARM)
  pFsStart	= (FStruct *)&Image$$GShell_region$$Base;
  pFsEnd	= (FStruct *)&Image$$GShell_region$$Limit;
#elif defined(__GNUC__)
  pFsStart  = (FStruct *)&__gs_section_start;
  pFsEnd    = (FStruct *)&__gs_section_end;
#else
#error "Unsupported tool chain"
#endif
  
  iCmdNum = pFsEnd - pFsStart;
  
  for(i=0,gm=0xffff, im=0xffff; i < iCmdNum; ++i) {
    if(strcmp((pFsStart + i)->pCmdName, pCmd)==0) {
      iGrpIdxAct =  FindStrIdx((pFsStart + i)->pGrpName, 
                                   gpActGroups,
                                   MAX_ACT_GROUP);
      
      //group is not in active group list
      if(iGrpIdxAct == -1) {
        continue;
      }
      
      if(iGrpIdxAct < gm) {
        gm = iGrpIdxAct;
        im = i;
      }
    }
    
  }
  
  
  if(gm != 0xffff) {// found
    pTmpFs = pFsStart + im;
  } else {//not found
    pTmpFs = NULL;
  }
  
  return pTmpFs;
}
      
//------------------------------------------------------------------------------
//      Exported Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///  Parse a command string and search in active groups, run if matched
///  \param pCmdString, command string including arguments
///  \return 0 succeed, other value failure
//------------------------------------------------------------------------------
int ParseAndRunCmd(const char * pCmdString)
{
  FStruct  *pFsCmd;
  int argc, iRet;
  char args[DBGU_CMDBUFSIZE];
  char *argv[MAX_CMD_ARGS + 1];
  
  //if NULL string, no run
  if(!pCmdString)
    return 0;
  
  unsigned int strLength = strlen(pCmdString);
  
  //empty string, no run
  if(strLength == 0)
    return 0;
  
  if(strLength < DBGU_CMDBUFSIZE) {
    strcpy(args, pCmdString);
  }
  else {
    memcpy(args, pCmdString, DBGU_CMDBUFSIZE-1);
    args[DBGU_CMDBUFSIZE-1] = '\0';
  }
  
  // parse a command string to *argv[] 
  argc = StringLineToArgs(args, argv);
    
  // find matched command 
  if((pFsCmd = FindCommand(argv[0])) == NULL) {

    printf("\n\r Command -'%s'- not found in active groups!", argv[0]);
    iRet = 1;
    
  } else {
    // run command 
    iRet = (pFsCmd->cmdProcess)(argc, argv);
  }
  
  // return command running result
  return iRet;
}

//------------------------------------------------------------------------------
///  Parse a string line containing multi commands and arguments, then
///  search in active groups, run if matched
///  \param pMultiCmdStr, string line containing multi commands and arguments
///  \return 0 succeed, other value failure
//------------------------------------------------------------------------------
int ParseAndRunMultiCmds(const char * pMultiCmdStr)
{
  char pMultiCmdStrBuf[DBGU_CMDBUFSIZE];
  char *cmds[MAX_MULTI_CMD + 1], *pCmdsStr;
  unsigned int i;
  int iRet;
  
  //if NULL string, no run
  if(!pMultiCmdStr)
    return 0;
  
  unsigned int strLength = strlen(pMultiCmdStr);
  
  //empty string, no run
  if(strLength == 0)
    return 0;
  
  if(strLength < DBGU_CMDBUFSIZE) {
    strcpy(pMultiCmdStrBuf, pMultiCmdStr);
  }
  else {
    memcpy(pMultiCmdStrBuf, pMultiCmdStr, DBGU_CMDBUFSIZE-1);
    pMultiCmdStrBuf[DBGU_CMDBUFSIZE-1] = '\0';
  }

  i = 0;
  pCmdsStr = (char *)(&pMultiCmdStrBuf[0]);
  //parse multi commands
  while(i < MAX_MULTI_CMD) {

    // skip white space characters of string head 
    while ((*pCmdsStr == ' ') || (*pCmdsStr == '\t')) {
      ++pCmdsStr;
    }    
   
    if (*pCmdsStr == '\0') {
      cmds[i] = NULL;
      break;
    }
    
    cmds[i++] = pCmdsStr;
    
    // parse commands 
    while (*pCmdsStr) {
      if( ((*(pCmdsStr - 1) == ' ') || (*(pCmdsStr - 1) == '\t'))
           && (*pCmdsStr == '&')
             && (*(pCmdsStr + 1) == '&'))
        break;// find the mark for next commands, then break
      else
        ++ pCmdsStr; 
    }

    if (*pCmdsStr == '\0') {
	cmds[i] = NULL;
	break;
    }
    
    *(pCmdsStr - 1) = '\0';
    pCmdsStr += 2;
    
  }// end of parse

  //if too many command in a line, warning
  if(i >= MAX_MULTI_CMD)
    printf ("\n\r Too many command in one line. Maximum cmds supported is %d!", MAX_MULTI_CMD);
  
  unsigned int j;
  for (j = 0; j < i; ++j) {
    iRet |= ParseAndRunCmd(cmds[j]);
  }
  
  return iRet;
}

//------------------------------------------------------------------------------
///  Run batch command
///  \param argc, number of command string
///  \param argv, pointer array to command string 
///  \return 0 succeed, other value failure
//------------------------------------------------------------------------------
int RunScript(int argc, char *argv[])
{
  int i, iRet=0;
  
  // run script
  for(i = 0; i<argc; ++i) {
    iRet |= ParseAndRunMultiCmds(argv[i]);
  }
  
  return iRet;
}

//------------------------------------------------------------------------------
///  Show all groups and commands, portal of command 'showall'
///  \param argc, number of argument
///  \param argv, argument string array
///  \return 0 succeed, other value failure
//------------------------------------------------------------------------------
int DFM_ShowAllGrpCmd(int argc, char **argv)
{
  int i, j, iGrpCnt, iCmdCnt, iCmdNum;
  char *pGrpList[MAX_LIST_GROUP+1];
  FStruct *pCmdList[MAX_ACT_CMD];
  FStruct *pFsStart, *pFsEnd, *pFsTmp;

#if defined(__ICCARM__)  
  pFsStart  = __section_begin(GSHELL_SECTION);
  pFsEnd    = __section_end(GSHELL_SECTION);
#elif defined(__CC_ARM)
  pFsStart	= (FStruct *)&Image$$GShell_region$$Base;
  pFsEnd	= (FStruct *)&Image$$GShell_region$$Limit;
#elif defined(__GNUC__)
  pFsStart  = (FStruct *) &__gs_section_start;
  pFsEnd    = (FStruct *) &__gs_section_end;
#else
#error "Unsupported tool chain"
#endif
  
  iCmdNum   = pFsEnd - pFsStart;
  
  //dumb, time consumption but less ram consumption way to list group  
  //get group list in section, MAX_LIST_GROUP limit
  pGrpList[0] = NULL;
  for(i=0,iGrpCnt=0; i<iCmdNum && iGrpCnt < MAX_LIST_GROUP; ++i) {
    
    if(FindStrIdx((pFsStart+i)->pGrpName, pGrpList, MAX_LIST_GROUP) == -1) {
      pGrpList[iGrpCnt++] = (pFsStart+i)->pGrpName;
      pGrpList[iGrpCnt]   = NULL;
    }
  }
  
  if(iGrpCnt >= MAX_LIST_GROUP) {
    printf("\n\r  Only first 100 groups are shown!");
  }
  
  //list all command under group list, sorted  
  //Get command lists first
  iGrpCnt=0;
  while(pGrpList[iGrpCnt] != NULL) {
    for(i=0,iCmdCnt=0;i<iCmdNum && iCmdCnt<MAX_ACT_CMD;++i) {
      if(strcmp((pFsStart+i)->pGrpName, pGrpList[iGrpCnt]) ==0) {
        pCmdList[iCmdCnt++]=pFsStart+i;
      }
    }
    
    //show prompt info
    if(iCmdCnt>=MAX_ACT_CMD) {
      printf("\n\r Group: %s, (>=%d) commands", pGrpList[iGrpCnt], iCmdCnt);
    } else {
      printf("\n\r Group: %s, (%d) commands", pGrpList[iGrpCnt], iCmdCnt);
    }
    
    int bExchgFlag;
    //sort command list
    for(i = 0; i < iCmdCnt - 1; ++i) {
      // flag, if no exchange, then array has been sorted  
      bExchgFlag = 0;
      
      //bubble sort in ascending order
      for(j = iCmdCnt - 1; j > i; --j){
        if(strcmp(pCmdList[j]->pCmdName, pCmdList[j-1]->pCmdName) < 0) {
          pFsTmp          = pCmdList[j];
          pCmdList[j]     = pCmdList[j-1];
          pCmdList[j-1]   = pFsTmp;
          
          // exchanged
          bExchgFlag = 1;
        }
      }
      
      // if no exchange, array sorted
      if(!bExchgFlag)
        break;
    }
    
    //print commands under group
    for(i=0;i<iCmdCnt;++i) {
      printf("\n\r     %s",pCmdList[i]->pCmdName);
    }
    
    //check next group then
    ++iGrpCnt;
  }
  
  printf("\n\r");

  return 0;
}

///define a new system command 'showall'
DFM_CMD(showall, DFM_ShowAllGrpCmd, "show all groups and commands.", SYS_GROUP);

//------------------------------------------------------------------------------
///  Show command help message, portal of command 'help'
///  \param argc, number of argument
///  \param argv, argument string array
///  \return 0 succeed, other value failure
//------------------------------------------------------------------------------
int DFM_Help(int argc, char **argv)
{
  int i, iRet = 0;
  FStruct *pTmpFs;
  
  if(argc == 1) { // show all command in active groups
    int j, iCmdNum, iCmdCnt, bExchgFlag;
    FStruct *pFsCmds[MAX_ACT_CMD];
    FStruct *pFsStart, *pFsEnd;
    
#if defined(__ICCARM__)  
    pFsStart  = __section_begin(GSHELL_SECTION);
    pFsEnd    = __section_end(GSHELL_SECTION);
#elif defined(__CC_ARM)
  pFsStart	= (FStruct *)&Image$$GShell_region$$Base;
  pFsEnd	= (FStruct *)&Image$$GShell_region$$Limit;
#elif defined(__GNUC__)
    pFsStart  = (FStruct *)&__gs_section_start;
    pFsEnd    = (FStruct *)&__gs_section_end;
#else
#error "Unsupported tool chain"
#endif
    
    //total command numbers in GSHELL_SECTION
    iCmdNum   = pFsEnd - pFsStart;
    
    i = 0; iCmdCnt=0;
    //get all commands in active groups
    while(i < iCmdNum && iCmdCnt < MAX_ACT_CMD) {
      if(FindStrIdx((pFsStart+i)->pGrpName, gpActGroups, MAX_ACT_GROUP) != -1) {
        pFsCmds[iCmdCnt++] = pFsStart + i;
      }
      ++i;
    }
    //now 'iCmdCnt' has value of available command numbers in active groups
    if(iCmdCnt < MAX_ACT_CMD) {
      printf("\n\r Total %d commands available.\n\r", iCmdCnt);
    } else {
      printf("\n\r Too many, Only %d commands are shown!", MAX_ACT_CMD);
    }
    
   
    // sort active group commands for better help result print 
    for(i = 0; i < iCmdCnt - 1; ++i) {
      // flag, if no exchange, then array has been sorted  
      bExchgFlag = 0;
      
      //bubble sort in ascending order
      for(j = iCmdCnt - 1; j > i; --j){
        if(strcmp(pFsCmds[j]->pCmdName, pFsCmds[j-1]->pCmdName) < 0) {
          pTmpFs        = pFsCmds[j];
          pFsCmds[j]    = pFsCmds[j-1];
          pFsCmds[j-1]  = pTmpFs;
          
          // exchanged
          bExchgFlag = 1;
        }
      }
      
      // no exchange, array sorted
      if(!bExchgFlag)
        break;
    }
    
    printf("\n\r");
    //print command, and help message if there is
    for(i = 0; i < iCmdCnt; ++i) {
      if(pFsCmds[i] == NULL)
        continue;
      
      printf(" %s ",pFsCmds[i]->pCmdName);
#ifdef USAGE_HELP
      printf("     %s",pFsCmds[i]->pUsage);
#endif
      printf("\n\r");
    }
    //end of argc== 1
    
  } else {

    //print available command help or error message
    for(i = 1; i < argc; ++i) {
      pTmpFs = FindCommand(argv[i]);
      
      if(pTmpFs != NULL) {
        
#ifdef USAGE_HELP
        printf("\n\r%s", pTmpFs->pCmdName);
        if(pTmpFs->pUsage) {
          printf("     %s\n\r",pTmpFs->pUsage);
        } else {
          printf("     <No help information>\n\r");
          iRet = 1;
        }
        
#else
        printf("\n\r <No usage help for '%s'>", argv[i]);

#endif
        
      } else {
        printf("\n\r No command '%s' under active groups!\n\r", argv[i]);
        iRet = 2;
      }
    }
  }
  
  return iRet;
}

///define a new system command 'help'
DFM_CMD(help, DFM_Help, "help command usage", SYS_GROUP);

//------------------------------------------------------------------------------
///  Set active groups, portal of command 'setact'
///  \param argc, number of argument
///  \param argv, argument string array
///  \return 0 succeed, other value failure
//------------------------------------------------------------------------------
int DFM_SetActiveGrp(int argc, char **argv)
{
  int i, iIdxList, iCmdNum, iRet = 0;
  char *pGrpList[MAX_LIST_GROUP+1];
  FStruct *pFsStart, *pFsEnd;
  
  //fill array with NULL, last NULL will act as an end
  for(i = 0; i < MAX_LIST_GROUP+1; ++i) {
    pGrpList[i] = NULL;
  }

#if defined(__ICCARM__)  
  pFsStart  = __section_begin(GSHELL_SECTION);
  pFsEnd    = __section_end(GSHELL_SECTION);
#elif defined(__CC_ARM)
  pFsStart	= (FStruct *)&Image$$GShell_region$$Base;
  pFsEnd	= (FStruct *)&Image$$GShell_region$$Limit;
#elif defined(__GNUC__)
  pFsStart  = (FStruct *)&__gs_section_start;
  pFsEnd    = (FStruct *)&__gs_section_end;
#else
#error "Unsupported tool chain"
#endif
  
  iCmdNum = pFsEnd - pFsStart;
  //printf("\n\r pFsStart is %d", pFsStart);
  
  if(argc == 1) { //show available groups for help
     
    printf("\n\r  Available Groups:\n\r");

    //collect all buildin group names, only MAX_LIST_GROUP will be shown
    for(i=0,iIdxList=0; i<iCmdNum && iIdxList<MAX_LIST_GROUP; ++i) {
      //printf("\n\r group name is %s, cmd name is %s", (pFsStart+i)->pGrpName, (pFsStart+i)->pCmdName);
      //no group name in list already
      if(FindStrIdx((pFsStart+i)->pGrpName, pGrpList, MAX_LIST_GROUP) == -1) {
        pGrpList[iIdxList++] = (pFsStart+i)->pGrpName;
        //printf("\n\r %s", pGrpList[iIdxList-1]);
      }
    }
    
    
    //show avail group list, MAX_LIST_GROUP 
    for(i=0; pGrpList[i] != NULL; ++i) {
      printf("     %s\n\r", pGrpList[i]);
    }
    
    //reach MAX_LIST_GROUP, show info
    if(i== MAX_LIST_GROUP) {
      printf("     ...\n\r");
      printf("     -Only '%d' groups will be shown!\n\r", MAX_LIST_GROUP);
    }
    // end of argc==1 
    
  } else {
    
    int j,iIdxAct, bFindFlag = 0;
    
    // used as index in active groups arrays below. Begin after 0(SYS_GROUP/"default")
    // no appending mode. Previous active groups except SYS_GROUP/"default" will be removed,
    // if not listed in *argv[]. 
    iIdxAct = 1;
    
    for(i = 1; i < argc ; ++i) {
      //flag for group name argument match check/
      bFindFlag = 0;
      
      //reach limit number of MAX_ACT_GROUP
      if(iIdxAct >= MAX_ACT_GROUP) {
        printf("\n\rWarning : Active group number is limited within -'%d'- !\n\r",MAX_ACT_GROUP);
        iRet = 1;//identify maxium active groups
        break;
      }
      
      //default group is always active, and at the first priority 
      if(strcmp(argv[i], SYS_GROUP) == 0) {
        continue;
      }
      
      //search for matched groups
      for(j = 0; j < iCmdNum; ++j) {
        if(strcmp(argv[i], (pFsStart+j)->pGrpName) == 0) {
          bFindFlag = 1;
          break;
        }
      }
      
      //group name argument matched
      if(bFindFlag) {
        gpActGroups[iIdxAct++] = (pFsStart+j)->pGrpName;
      } else {
        printf("\n\r No group '%s' in available list!", argv[i]);
        iRet = 2;// some error group name input 
      }
    }
    
    // no appending mode. previous active groups excetp SYS_GROUP/"default" will be removed,
    // if not listed in *argv[].
    while(iIdxAct < MAX_ACT_GROUP) {
      gpActGroups[iIdxAct++] = NULL;
    }
    
  }
  
  // show active group
  i =0;
  printf("\n\r\n\r ----Active Group: ");
  while(gpActGroups[i] != NULL && i < MAX_ACT_GROUP) {
    printf(" %s;", gpActGroups[i]);
    i++;
  }
  printf(" ----\n\r");
  
  return iRet;
}

///define a new system command 'setact'
DFM_CMD(setact, DFM_SetActiveGrp, "set active groups", SYS_GROUP);

#if defined(HELLO_TUTOR)
//------------------------------------------------------------------------------
///  A simple tutor for using gshell, portal of command 'showall'
///  \param argc, number of argument
///  \param argv, argument string array
///  \return 0 succeed, other value failure
//------------------------------------------------------------------------------
int DFM_HelloTutor(int argc, char **argv)
{
  char *pTutorInfo = {
    "\n\r -----------------------------Hello, World----------------------------"
    "\n\r  As a COMMAND 'thirsty' system, you may not know how to talk with me."
    "\n\r  I learnt much to write this message to explain how I can learn new "
    "\n\r  COMMANDs from you."
    "\n\r"  
    "\n\r  --- gs_cmd.h --- under project's --- include ---  directory tell you"
    "\n\r  definitions of macros and limits of my system. Put it in your comma-"
    "\n\r  nd portal code's header or source file."
    "\n\r"
    "\n\r  In this head file, an important macro acts as the translator that is" 
    "\n\r  used to teach me your new commands:"
    "\n\r        DFM_CMD(cmdString, procFunc, hlpString, grpName)"
    "\n\r"
    "\n\r  I'd like to tell you some rules about parameters of above macro."
    "\n\r  'cmdString' is the command name you want to teach me. Double  quota-"
    "\n\r  tion marks, \", is not necessary; 'procFunc' is the portal fuction t-"
    "\n\r  hat perform what this command do; 'hlpString' is help message to re-"
    "\n\r  member what is this command's usage, please note, double  quotation "
    "\n\r  marks, \", is necessary; 'grpName' is double quoted string that cla-"
    "\n\r  ssify what group this command belongs to. Use it carefully to avoid "
    "\n\r  mess classification, because I don't limit the name choice."
    "\n\r"
    "\n\r  The last thing remeber is definition of your portal function should has"
    "\n\r  the same number and type of parameters and return type like following:"
    "\n\r    int FuncName(int argc, char **argv)"
    "\n\r"
    "\n\r  'func' is normally pointed yourself portal function when I call this."
    "\n\r  'argc' and '*argv[]' work as the same way that you learn C language, "
    "\n\r  but they are parsed from command string typed in my console window. " 
    "\n\r"
    "\n\r  If you want to see an example of teaching me a new command, try to type"
    "\n\r  this command under 'DFM_CMD:>'              hello example"
    "\n\r"
  }; 
  
  char *pTutorExample = {
    "\n\r /* example, hi.c */"
    "\n\r #include \"gs_cmd.h\""
    "\n\r"
    "\n\r int DFM_Hi(int argc, char *argv[])"
    "\n\r {"
    "\n\r     printf(\"Command %s say HI!\", argv[0]);"
    "\n\r }"
    "\n\r"
    "\n\r DFM_CMD(hi, DFM_Hi, \"say hi to everybody!\", \"default\");"
    "\n\r\n\r"
  };
  
  if(argc == 2 && strcmp(argv[1], "example")==0) {
    printf("\n\r%s", pTutorExample);
  } else {
    printf("\n\r%s", pTutorInfo);
  }
  
  return 0;
}

///define the new system command for tutor, 'hello'
DFM_CMD(hello, DFM_HelloTutor, "A simple tutor for develop guide", SYS_GROUP);

#endif


//-----------------------------------------------------------------------------
///           Exported Function                  
//-----------------------------------------------------------------------------

//------------------------------------------------------------------------------
///  Demo Frame main portal route to get command and interpret it to run
///  \param argc, command number of initial running
///  \param argv, pointer array to initial running command strings
//------------------------------------------------------------------------------
//	void Gshell_MainProcess(int argc, char *argv[])
//	{
//	  TCmdQueue *pCmdQueue;
//	  
//	  //Run autorun script
//	  RunScript(argc, argv);
//	  
//	  //register input entry
//	  RegisterInputEntry(&gDBGUEntry);
//	  RegisterInputEntry(&gLCDEntry);
//	  RegisterInputEntry(&gButtonEntry);
//	  
//	  ShowPrompt();
//	  
//	  while(1) {
//	    if(!CommandIsReady())
//	      continue;
//	    
//	    pCmdQueue = GetCommandQueue();
//	    
//	    RunCommandQueue(pCmdQueue);
//	    
//	    ShowPrompt();
//	  }
//	  
//	//  while(1) {
//	//    
//	//    unsigned int index;
//	//    if(index = TSD_CommandIsReady()) {
//	//      pStr = TSD_GetCommand(index);
//	//      
//	//      printf("\n\r %s", pStr);
//	//
//	//    }
//	//    
//	//    // Check DBGU console input is ready
//	//    if(!DBGU_CommandIsReady())
//	//      continue;
//	//
//	//    
//	//#if 0
//	//    //temp code to test sdcard and nandflash mount availability for every time
//	//    // a new command is launched to run.
//	//    FIL test;
//	//    FRESULT res;
//	//    unsigned int i;
//	//    unsigned char buf[110];
//	//    
//	//    res = f_open(&test, SDCARD_ROOT_DIRECTORY"sam3demo.bin",  FA_OPEN_EXISTING | FA_READ);
//	//    if(res != FR_OK) {
//	//      printf("\n\r Open file in SDCard fail!");
//	//    } else {
//	//      printf("\n\r Open file in SDCard succeed!");
//	//      //test read file
//	//      res = f_read(&test, buf, 100, &i);
//	//      if(res!= FR_OK) {
//	//        printf("\n\r --read first 100 bytes fail!");
//	//      }else {
//	//        printf("\n\r --read first 100 bytes succeeds!");
//	//      }
//	//    }
//	//    
//	//    f_close(&test);
//	//    
//	//    res = f_open(&test, NAND_ROOT_DIRECTORY"basic.bin", FA_OPEN_EXISTING | FA_READ);
//	//    if(res != FR_OK) {
//	//      printf("\n\r Open file in nandflash fail!");
//	//    } else {
//	//      printf("\n\r Open file in nandflash succeed!");
//	//      
//	//      res = f_read(&test, buf, 100, &i);
//	//      if(res!= FR_OK) {
//	//        printf("\n\r --read first 100 bytes fail!");
//	//      }else {
//	//        printf("\n\r --read first 100 bytes succeeds!");
//	//      }
//	//    }
//	//    f_close(&test);
//	//#endif
//	//
//	//    
//	//    pStr = DBGU_GetCommand();
//	//    
//	//    // empty in DBGU command buffer
//	//    if(*pStr == '\0') {
//	//      continue;
//	//    }
//	//    
//	//    if (strlen(pStr) >= DBGU_CMDBUFSIZE) {
//	//      printf ("\n\r Command String is too long(max. %d)!\n\r", DBGU_CMDBUFSIZE);
//	//      continue;
//	//    }
//	//    
//	//    // create a local copy to protect console  buffer 
//	//    strcpy (pCmdString, pStr);
//	//    
//	//    // parse and run command string 
//	//    ParseAndRunMultiCmds(pCmdString);
//	//
//	////    DBGU_ShowPrompt();
//	////    LCD_ShowPrompt();
//	//    
//	//    ShowPrompt();
//	//  }
//	}

