
#include "dfm_entry.h"
#include "dfm_cmd.h"

//-----------------------------------------------------------------------------
///           Internal Variables                   
//-----------------------------------------------------------------------------


#ifndef NULL
#define NULL 0
#endif

//point to first input entry
static TInputEntry *gpFirstInputEntry = NULL;

//-----------------------------------------------------------------------------
///           Exported Function                   
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/// register prompt display entry fucntion into prompt list for calling
/// The image should be same size as the LCD.
/// \param pPromptFunc, pointer to global variable of prompt display function
/// \return 0 success, other value fail
//------------------------------------------------------------------------------
int RegisterInputEntry(TInputEntry *pEntryStruct)
{
  TInputEntry *pTmpEntry;
  
  pTmpEntry = gpFirstInputEntry;
  
  if(pTmpEntry == NULL) {
    gpFirstInputEntry = pEntryStruct;
    gpFirstInputEntry->next  = NULL;
    
    return 0;
  }
  
  while(pTmpEntry->next != NULL)
    pTmpEntry = pTmpEntry->next;
  
  pTmpEntry->next = pEntryStruct;
  pEntryStruct->next = NULL;
  
  return 0;
}

//-----------------------------------------------------------------------------
/// Calling prompt display entry chained in prompt list 
/// \return 0 success, other value fail
//------------------------------------------------------------------------------
int ShowPrompt()
{
  TInputEntry *pTmpEntry;
  
  pTmpEntry = gpFirstInputEntry;
  while(pTmpEntry != NULL) {
    //printf("\n\r ********DisplayPrompt********* "); 
    if(pTmpEntry->Prompt)
      pTmpEntry->Prompt();
    pTmpEntry = pTmpEntry->next;
  }
  
  return 0;
}

//-----------------------------------------------------------------------------
/// Check if any command is ready in all input entry, if yes, set the flag
/// \return 0 no command ready, other means yes and value represents number of
///   ready input entry
//------------------------------------------------------------------------------
unsigned int CommandIsReady()
{
  unsigned int ret = 0;
  TInputEntry *pTmpEntry;
  
  pTmpEntry = gpFirstInputEntry;
  while(pTmpEntry != NULL) {
    if(pTmpEntry->CommandIsReady && pTmpEntry->CommandIsReady()) {
      pTmpEntry->readyFlag = 1;
      ++ ret;
    }
    
    pTmpEntry = pTmpEntry->next;
  }
  
  return ret;  
}

//-----------------------------------------------------------------------------
/// Get Command Queue
/// \return 0 no command ready, other means ready and value is available numbers
//------------------------------------------------------------------------------
TCmdQueue * GetCommandQueue()
{
  TInputEntry *pTmpEntry;
  TCmdQueue *pQueueFirst, *pTmpQueue = NULL;
  
  pTmpEntry = gpFirstInputEntry;
  while(pTmpEntry != NULL) {
    //check if command ready flag is set
    if(pTmpEntry->readyFlag) {

      if(pTmpQueue == NULL) {
        //Set pointer to first available command element of queue
        pQueueFirst = &(pTmpEntry->CmdElement);
        pTmpQueue = pQueueFirst;
      } else {
        pTmpQueue->next = &(pTmpEntry->CmdElement);
        pTmpQueue = pTmpQueue->next;
      }
      
      pTmpQueue->command = pTmpEntry->GetCommand();
      pTmpQueue->next = NULL;
      
      pTmpEntry->readyFlag = 0;
    }
    
    pTmpEntry = pTmpEntry->next;
  }
      
  return pQueueFirst;
}

//-----------------------------------------------------------------------------
/// Run Command Queue
/// \return 0 success for all, other value fail
//------------------------------------------------------------------------------
int RunCommandQueue(TCmdQueue *pCmdQueue)
{
  int ret = 0;
  TCmdQueue *pTmpQueue;
  
  pTmpQueue = pCmdQueue;
  while(pTmpQueue != NULL) {
    ret |= ParseAndRunMultiCmds(pTmpQueue->command);
    pTmpQueue = pTmpQueue->next;
  }
  
  return ret;  
}
