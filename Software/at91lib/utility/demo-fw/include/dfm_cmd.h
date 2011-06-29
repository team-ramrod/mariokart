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

#ifndef __DFM_CMD_H
#define __DFM_CMD_H

//------------------------------------------------------------------------------
//      Definitions
//------------------------------------------------------------------------------

///limits definition
#define MAX_LIST_GROUP 100
/// max active groups
#define MAX_ACT_GROUP 10
/// max active commands
#define MAX_ACT_CMD 255
/// max command arguments
#define MAX_CMD_ARGS 10
/// max command number concatenated in one line
#define MAX_MULTI_CMD 5

///define NULL
#ifndef NULL
#define NULL 0
#endif

/// structure for describe function
struct _FStruct {
        char *pGrpName;
	char *pCmdName;
	int (*cmdProcess)(int argc, char **argv);
#ifdef USAGE_HELP
	char *pUsage;
#endif
};

typedef struct _FStruct FStruct;


/// max group numbers allowed to build in
#define MAX_BUILDIN_GROUP 32

/// section to put all commands
#define GSHELL_SECTION ".gs_section"

/// system group name, will be always active at the first priority
#define SYS_GROUP "default"

/// section macro definition
#if defined(__GNUC__)

#define CMD_OBJ const
#define INSECTION(secname)   __attribute__ ((unused, section(secname)))

#elif defined(__ICCARM__)

#pragma section = GSHELL_SECTION

#define CMD_OBJ  __root const
#define INSECTION(secname) @ secname

#else

#error "unsupported tool chain"

#endif


/// usage help compiled
#ifdef USAGE_HELP

#define DFM_CMD(cmdString, procFunc, hlpString, grpName) \
  CMD_OBJ FStruct GS_Func_##cmdString INSECTION(GSHELL_SECTION) = {\
                grpName,\
                #cmdString,\
		procFunc,\
		hlpString\
	}

#else

#define DFM_CMD(cmdString, procFunc, hlpString, grpName) \
  CMD_OBJ FStruct GS_Func_##cmdString INSECTION(GSHELL_SECTION)= {\
                grpName,\
		#cmdString,\
		procFunc,\
	}

#endif

//------------------------------------------------------------------------------
//      Exported Functions
//------------------------------------------------------------------------------

// Parse a command string and search in active groups, run if matched
int ParseAndRunCmd(const char * pCmdString);

//  Parse a string line containing multi commands and arguments, then
//  search in active groups, run if matched
int ParseAndRunMultiCmds(const char * pMultiCmdStr);

//------------------------------------------------------------------------------
///  Run batch command
//------------------------------------------------------------------------------
int RunScript(int argc, char *argv[]);

//	// Main portal function of gshell
//	void Gshell_MainProcess(int argc, char *argv[]);

#endif /// end of __DFM_CMD_H
