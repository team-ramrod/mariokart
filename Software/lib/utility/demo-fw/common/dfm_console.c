//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include <string.h>
#include <dbgu/dbgu.h>
#include <stdio.h>

#include "dfm_console.h"
#include "dfm_entry.h"
#include "dfm_cmd.h"

//------------------------------------------------------------------------------
//         Internal variables
//------------------------------------------------------------------------------

///DBGU input buffer
static char gpConsoleBuffer[DBGU_CMDBUFSIZE];

///prompt refresh flag
static unsigned char gDBGUPromptFlag = 0;

///erase sequence	
static char gpEraseSeq[] = "\b \b";
///used to expand TABS
static char   gpTabSeq[] = "        ";

//------------------------------------------------------------------------------
//         Export variables
//------------------------------------------------------------------------------

// global DBGU entry
TInputEntry gDBGUEntry = \
  {0, {NULL,NULL},DBGU_ShowPrompt, DBGU_CommandIsReady, DBGU_GetCommand, NULL};

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///  output a string to console
///  \param pStr, string to output to DBGU console
//------------------------------------------------------------------------------
static inline void DBGU_puts(const char *pStr)
{
  while(*pStr) {
    DBGU_PutChar(*pStr++);
  }
}

//------------------------------------------------------------------------------
///  remove charaters from buffer positions
//------------------------------------------------------------------------------
static char * DBGU_RemoveCharFromBuf (char *buffer, char *p, int *colp, int *np, int plen)
{
	char *s;

	if (*np == 0) {
		return (p);
	}

	if (*(--p) == '\t') {
		while (*colp > plen) {
			DBGU_puts (gpEraseSeq);
			(*colp)--;
		}
		for (s=buffer; s<p; ++s) {
			if (*s == '\t') {
				DBGU_puts (gpTabSeq+((*colp) & 07));
				*colp += 8 - ((*colp) & 07);
			} else {
				++(*colp);
				DBGU_PutChar (*s);
			}
		}
	} else {
		DBGU_puts (gpEraseSeq);
		(*colp)--;
	}
	(*np)--;
	return (p);
}

//------------------------------------------------------------------------------
///  Check console is ready?
///  \return 0 not ready, other value means ready and command string length
//------------------------------------------------------------------------------
unsigned int DBGU_CommandIsReady()
{
  unsigned char c;
  static char *p = gpConsoleBuffer;
  int     escflag = 0;
  char *  p_buf = gpConsoleBuffer;
  static int	n = 0;				// buffer index
  int	plen = 0;			// prompt length
  static int col=0;				// output column cnt
  unsigned int cmdLen;
  
  plen = strlen(GS_SHELL_PROMPT);
  
  //right beginning of a new command input
  if(col == 0)
    col = plen;
  
Tag_for_CombinedKey:
  
  if(DBGU_IsRxReady()) {
    c = DBGU_GetChar();
    
    //
    // Special character handling
    //
    switch (c) {
    case '\r':				// Enter
    case '\n':
      *p = '\0';
      cmdLen = p - p_buf;
      p = gpConsoleBuffer;
      n = 0; //clear buffer index as 0
      col = 0; // this is set for indicate next time input considered as new command
      gDBGUPromptFlag = 1;//DBGU_puts ("\r\n");
      return cmdLen;
      
    case '\0':				// nul
      return 0;
      
    case 0x03:				// ^C - break
      //p_buf[0] = '\0';	// discard input
      return 0;
      
    case 0x15:				// ^U - erase line
      while (col > plen) {
        DBGU_puts (gpEraseSeq);
        --col;
      }
      p = p_buf;
      n = 0;
      return 0;
      
    case 0x17:				// ^W - erase word
      p=DBGU_RemoveCharFromBuf(p_buf, p, &col, &n, plen);
      while ((n > 0) && (*p != ' ')) {
        p=DBGU_RemoveCharFromBuf(p_buf, p, &col, &n, plen);
      }
      return 0;
      
    case 0x08:				// ^H  - backspace
    case 0x7F:				// DEL - backspace
      p=DBGU_RemoveCharFromBuf(p_buf, p, &col, &n, plen);
      return 0;
      
    case 0x1b:                              // arrow, home flag
      escflag = 1;
      goto Tag_for_CombinedKey;//in window hyperterminal, arrow and home flag
                               // keys are combined 1b + x
      
    case 'D':                               //ignore arrow,home key
    case 'C':
    case 'H':
    case 'A':
    case 'B':
      if(escflag) {
        escflag = 0;
        return 0;
      }
      
      
    default:
      //
      // Must be a normal character then
      //
      if (n < DBGU_CMDBUFSIZE-2) {
        if (c == '\t') {	// expand TABs
          DBGU_puts (gpTabSeq+(col&07));
          col += 8 - (col&07);
        } else {
          ++col;		// echo input
          DBGU_PutChar (c);
        }
        *p++ = c;
        ++n;
      } else {			// Buffer full
        DBGU_PutChar ('\a');
      }
    }    
  }
  
  return 0;
}

//------------------------------------------------------------------------------
///  get a const pointer to global console input buffer
///  \return pointer to global DBGU console input buffer
//------------------------------------------------------------------------------
const char * DBGU_GetCommand() {
  return (const char *)gpConsoleBuffer;
}

//------------------------------------------------------------------------------
///  Show DBGU console prompt information
///  \return 0, success
//------------------------------------------------------------------------------
int DBGU_ShowPrompt()
{
  
#if defined(GS_SHELL_PROMPT)
  // print prompt
  if(gDBGUPromptFlag) {
  DBGU_puts("\n\r");
  DBGU_puts (GS_SHELL_PROMPT);
    gDBGUPromptFlag = 0;
  }
#endif
  
  return 0;    
}
