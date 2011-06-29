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

#ifndef __DFM_ENTRY_H_
#define __DFM_ENTRY_H_

//structure for command queue
typedef struct _tCmdQueue {
  const char * command;
  struct _tCmdQueue * next;
} TCmdQueue;

//structure for prompt registry definition
typedef struct _tInputEntry {
  unsigned int readyFlag;
  TCmdQueue CmdElement;
  int (*Prompt)(void);
  unsigned int (*CommandIsReady)(void);
  const char *(*GetCommand)(void);
  struct _tInputEntry *next;
} TInputEntry;



//Register input entry
extern int RegisterInputEntry(TInputEntry *pEntryStruct);

//Show prompt registered
extern int ShowPrompt();

//Check if any command is ready
extern unsigned int CommandIsReady();

//Get command queue
extern TCmdQueue * GetCommandQueue();

//Run command queue
extern int RunCommandQueue(TCmdQueue *pCmdQueue);

#endif // end of __DFM_ENTRY_H_

