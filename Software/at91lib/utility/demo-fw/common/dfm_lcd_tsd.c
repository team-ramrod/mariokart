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

#include <board.h>
#include <board_memories.h>
#include <utility/trace.h>
#include <utility/bmp.h>
#include <systick/systick.h>
#include <lcd/color.h>
#include <lcd/draw.h>
#include <lcd/lcdd.h>
#include <hx8347/hx8347.h>
#include <tsd/tsd.h>
#include <flash/flashd.h>

#include "dfm_cmd.h"
#include "dfm_lcd_tsd.h"
#include "dfm_dispboxmgr.h"
#include "dfm_config.h"
#include "dfm_it.h"
#include "dfm_init.h"
#include "dfm_fatfs.h"
#include "dfm_entry.h"
#include "dfm_varloc.h"

//global LCD prompt display register entry variable
TInputEntry gLCDEntry = {0, {NULL,NULL},LCD_ShowPrompt, TSD_CommandIsReady, TSD_GetCommand, NULL};

#define GLOBALSLIDEINFO

#if defined(GLOBALSLIDEINFO)
///active for slide information
RLOC_OBJ SlideINFOHeader gActiveSlideHeader _AT(ACTIVESLIDE_INFOHEAD_ADDR);
#endif

///lcd refresh show flag
unsigned int gLcdRefreshFlag = 0;

///current slide index shown on LCD
///the init value is the first slide after program start up.
unsigned short gActiveSlideIndex = 0;

/// active demo bin max slides
static unsigned int gActiveBinSlideCount = 0xffffffff;

/// point to the active demo bin file name
const char * gpActiveBinFile = LCDSLIDEIMAGEFILE;

/// used in system tick count
volatile unsigned int gTimeStamp = 0;

/// Coordinates at which the pen was last pressed.
static volatile unsigned int gTSDxPressed;
static volatile unsigned int gTSDyPressed;
static volatile unsigned char gTSDPressed = 0;

/// link string index for hot zone hitted, starting from 1, 0 means not hitted
static unsigned int gLinkIndex = 0;

///Flash1 start address to store demo bin in at91sam3u4
#define gDemoBinAddrInFlash 0x108000


//file buffer used to read bitmap data
#if defined(__CC_ARM) || defined(__ICCARM__)//up to now, KEIL AND IAR supported
RLOC_OBJ static unsigned char gpFileBuffer[FILE_BUF_SIZE] _AT(FILE_BUFFER_ADDR);
#endif

#if defined(BOARD_PSRAM_PINS)

#if defined(__GNUC__) && !defined(__CC_ARM)
  static unsigned char *gpFileBuffer   = (unsigned char *) (BOARD_EBI_PSRAM + 0xa0000);
#endif
  
  //PSRAM init entry
  int Psram_Init(void)
  {
    printf("\n\r Init Psram");
    
    BOARD_ConfigurePsram();
    
    return 0;
  }

  //init psram in level 5
  //lvl5_init(Psram_Init);
  DFM_INIT(5, Psram_Init);

#elif defined(PINS_SDRAM)

#if defined(__GNUC__) && !defined(__CC_ARM)
  static unsigned char *gpFileBuffer   = (unsigned char *) (AT91C_EBI_SDRAM+ 0xa0000);
#endif

  //SDRAM init entry
  int Sdram_Init(void)
  {
    printf("\n\r Init Sdram");
    
    BOARD_ConfigureSdram(BOARD_SDRAM_BUSWIDTH);
  }

  //init sdram in level 5
  //lvl5_init(Psram_Init);
  DFM_INIT(5, Sdram_Init);

#elif defined(PINGS_DDRAM)

#if defined(__GNUC__) && !defined(__CC_ARM)
  static unsigned char *gpFileBuffer   = (unsigned char *) (AT91C_EBI_SDRAM);
#endif

  //ddram init entry
  int Ddram_Init(void)
  {
    printf("\n\r Init Ddram");
    
    //configure DDRAM for use
    BOARD_ConfigureDdram(0, BOARD_DDRAM_BUSWIDTH);
  }
  
  //init ddram in level 5
  //lvl5_init(Psram_Init);
  DFM_INIT(5, Ddram_Init);
  
#else
  #define USE_SRAM_BUF
  #define BUF_LEN_SRAM 1024
#endif

//////////////////////////
///LCD prompt display    /
//////////////////////////
  
#if defined(USE_LCD_TSD)

#if defined(LCDC_HX8347) //USE hx8347 controller
//------------------------------------------------------------------------------
/// Handler for SysTick interrupt. Increments the timestamp counter.
//------------------------------------------------------------------------------
void SysTick_HandlerLcdTsd(void)
{
    gTimeStamp++;
    
    // Call TSD_TimerHandler per 10ms
    if ((gTimeStamp % 10) == 0) {
        
        TSD_TimerHandler();
    }
}

#if defined(USE_IT_CHAIN_MGR)
TDFM_ItServList gSysTkItHandlerLcdTsd = {SysTick_IRQn, SysTick_HandlerLcdTsd, NULL};
#endif

//------------------------------------------------------
/// Init LCD controller of 8347
//------------------------------------------------------
int LCD_Init()
{
    
  printf("\n\r LCD init in Level 5");
  
  // 1ms tick, in driver, a wait is called.
  SysTick_Configure(1, BOARD_MCK/1000, SysTick_HandlerLcdTsd);
  
#if defined(USE_IT_CHAIN_MGR)
  DFM_RegisterItHandler(&gSysTkItHandlerLcdTsd);
#endif
  
  // Initialize LCD
  LCDD_Initialize();
  LCDD_Fill((void *)BOARD_LCD_BASE, COLOR_WHITE);
  LCDD_Start();

  return 0;  
}

#else //use internal LCD controller
//------------------------------------------------------
/// Init LCD controller of 8347
//------------------------------------------------------
int LCD_Init()
{
    // Enable peripheral clock
    AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_LCDC;

#if defined(at91sam9g10)||defined(at91sam9261)
    AT91C_BASE_PMC->PMC_SCER = AT91C_PMC_HCK1;
#endif

    // Disable the LCD and the DMA
    LCD_DisableDma();
    LCD_Disable(0);

    // Configure the LCD controller
    LCD_SetPixelClock(BOARD_MCK, BOARD_LCD_PIXELCLOCK);
    LCD_SetDisplayType(BOARD_LCD_DISPLAYTYPE);
    LCD_SetScanMode(AT91C_LCDC_SCANMOD_SINGLESCAN);
    LCD_SetBitsPerPixel(BOARD_LCD_BPP);
    LCD_SetPolarities(BOARD_LCD_POLARITY_INVVD,
                      BOARD_LCD_POLARITY_INVFRAME,
                      BOARD_LCD_POLARITY_INVLINE,
                      BOARD_LCD_POLARITY_INVCLK,
                      BOARD_LCD_POLARITY_INVDVAL);
    LCD_SetClockMode(BOARD_LCD_CLOCKMODE);
    LCD_SetMemoryFormat((unsigned int) AT91C_LCDC_MEMOR_LITTLEIND);
    LCD_SetSize(BOARD_LCD_WIDTH, BOARD_LCD_HEIGHT);

    // Configure timings
    LCD_SetVerticalTimings(BOARD_LCD_TIMING_VFP,
                           BOARD_LCD_TIMING_VBP,
                           BOARD_LCD_TIMING_VPW,
                           BOARD_LCD_TIMING_VHDLY);
    LCD_SetHorizontalTimings(BOARD_LCD_TIMING_HBP,
                             BOARD_LCD_TIMING_HPW,
                             BOARD_LCD_TIMING_HFP);

    // Configure contrast (TODO functions)
    LCD_SetContrastPrescaler(AT91C_LCDC_PS_NOTDIVIDED);
    LCD_SetContrastPolarity(AT91C_LCDC_POL_POSITIVEPULSE);
    LCD_SetContrastValue(0x80);
    LCD_EnableContrast();

    // Configure DMA
    LCD_SetFrameSize(BOARD_LCD_FRAMESIZE);
    LCD_SetBurstLength(4);

    // Set frame buffer
    LCD_SetFrameBufferAddress(images[0]);

    // Enable DMA and LCD
    LCD_EnableDma();
    LCD_Enable(0x0C);
}

#endif

//lvl5_init(LCD_Init);
DFM_INIT(5, LCD_Init);

//------------------------------------------------------------------------------
/// Delay millisecond. Use SysTick interrupt for function implement, so ensure
/// the SysTick interrupt is enabled before using this function.
/// \param ms   millisecond to be delay
//------------------------------------------------------------------------------
void DelayMS(unsigned int ms)
{
    unsigned int st = gTimeStamp;

    while (gTimeStamp - st < ms);
}

//------------------------------------------------------------------------------
/// Callback called when the pen is pressed on the touchscreen
/// /param horizontal position (in pixel if ts calibrated)
/// /param vertical position (in pixel if ts calibrated)
//------------------------------------------------------------------------------
void TSD_PenPressed(unsigned int x, unsigned int y)
{
    //printf("Pen pressed at  (%03u, %03u)\n\r", x, y);
    
    // Save the coordinates for use by TSD_PenReleased
    gTSDxPressed = x;
    gTSDyPressed = y;
    TSD_SetTouched();
}

//------------------------------------------------------------------------------
/// Callback called when the pen is moved on the touchscreen
/// /param horizontal position (in pixel if ts calibrated)
/// /param vertical position (in pixel if ts calibrated)
//------------------------------------------------------------------------------
void TSD_PenMoved(unsigned int x, unsigned int y)
{
    // printf("Pen moved at    (%03u, %03u)\n\r", x, y);
}

//------------------------------------------------------------------------------
/// Callback called when the touchscreen is released on the touchscreen
/// /param horizontal position (in pixel if ts calibrated)
/// /param vertical position (in pixel if ts calibrated)
//------------------------------------------------------------------------------
void TSD_PenReleased(unsigned int x, unsigned int y)
{

}

//------------------------------------------------------------------------------
/// Get last pen press position
/// /param point to horizontal position (in pixel if ts calibrated)
/// /param point vertical position (in pixel if ts calibrated)
//------------------------------------------------------------------------------
void TSD_GetPenLastPosition(unsigned int *pX, unsigned int *pY)
{
    *pX = gTSDxPressed;
    *pY = gTSDyPressed;
}

//---------------------------------------------
/// init touchscreen
//---------------------------------------------
int TSD_Init()
{
    printf("\n\r Init TouchScreen");

    gTSDxPressed = gTSDyPressed = 0;

#if defined(at91sam3u4)
// Internal Flash1 
#define IFLASH1                 (0x100000)
#define IFLASH1_SIZE             (0x20000)
#define IFLASH1_PAGE_SIZE            (256) // Internal FLASH 1 Page Size: 256 bytes
#define IFLASH1_NB_OF_PAGES          (512) // Internal FLASH 1 Number of Pages: 512
#define IFLASH1_LOCK_REGION_SIZE    (8192) // Internal FLASH 1 Lock Region Size: 8 Kbytes
#define IFLASH1_NB_OF_LOCK_BITS       (16) // Internal FLASH 1 Number of Lock Bits: 16

    unsigned char error;
    unsigned int pBuffer[IFLASH1_PAGE_SIZE / 4];
    unsigned int lastPageAddress;
    volatile unsigned int *pLastPageData;

    // Read touch screen calibration data
    // Initialize flash driver
    FLASHD_Initialize(BOARD_MCK);

    // Calibration data are stored on last page
    lastPageAddress = IFLASH1 + IFLASH1_SIZE - IFLASH1_PAGE_SIZE;
    pLastPageData = (volatile unsigned int *) lastPageAddress;

    TSDCom_RestoreCalibrateData((void *)pLastPageData, IFLASH1_PAGE_SIZE);

    // Initialize touchscreen
    TSD_Initialize((void *)BOARD_LCD_BASE);

    // Save touch screen calibration data
    // Unlock whole flash
    error = FLASHD_Unlock(IFLASH1, IFLASH1 + IFLASH1_SIZE, 0, 0);
    if(error) {
        printf(" Unlock flash fail.\n\r");
    } else {
        TSDCom_ReadCalibrateData(pBuffer, sizeof(pBuffer));
        error = FLASHD_Write(lastPageAddress, pBuffer, IFLASH1_PAGE_SIZE);
        if(error) {
            printf(" Fail to write touch srceen calibration data.\n\r");
        }
    }
#endif

    return 0;
}

//TouchScreen init in level 5
DFM_INIT(5, TSD_Init);

#endif


///////////////////////////////////////////////////
/// following is dealling with show slide on slide/
///////////////////////////////////////////////////

//-----------------------------------------------------------------------------
/// Displays the given image on the LCD. 
/// The image should be same size as the LCD.
/// TODO: this display interface should be generalized to consider other LCD properties
/// \param pImage  point to image buffer
/// \param width   image width in pixels.
/// \param height  image height in pixels.
//------------------------------------------------------------------------------
static void LCDD_DrawImageRGB565(
    unsigned short *pImage,
    unsigned int width,
    unsigned int height)
{
    unsigned int i;

    if ((width != BOARD_LCD_WIDTH) || (height != BOARD_LCD_HEIGHT)) {

        printf("LCDD_DrawImageRGB565: Image size is not fit the LCD");
        return;
    }
    

    if(LCDD_IsBusy()) return;
    
     LCDD_SetBusy();


    LCD_SetCursor((void *)BOARD_LCD_BASE, 0, 0);
    LCD_WriteRAM_Prepare((void *)BOARD_LCD_BASE);

    for (i = 0; i < (width * height); i++) {
        LCD_WriteRAM((void *)BOARD_LCD_BASE, *(pImage));
        pImage++;
    }
    
    LCDD_ClearBusy();
}

//------------------------------------------------------------------------------
///Get slide info header from fatfs file interface
//------------------------------------------------------------------------------
static unsigned int GetSlideInfoHeaderFromFile(
    //fatfs file pointer to demo bin file
    FIL *pFile, 
    //slide index for get info
    unsigned int slideIdx, 
    //store read slide info
    SlideINFOHeader *pSlideheader,
    //to return actual slide index been read
    unsigned int *realSlideIdx)
{
  DemoBINHeader binheader;
  FRESULT res;
  unsigned int i, offset;
  
  if(!pSlideheader) {
    TRACE_ERROR(" No slide info returned for null pointer!\n\r");
    return 1;
  }
  
  //seek to start point of file
  res = f_lseek(pFile, 0);
  if(res != FR_OK) {
    TRACE_ERROR(" Operation demo bin file fail! \n\r");
    return 1;
  }
  
  //Read demo bin header information
  res = f_read(pFile, &binheader, sizeof(DemoBINHeader), &i);
  if(res != FR_OK ) {
    TRACE_ERROR(" Fail to read demo bin! \n\r");
    return 1;
  }
  
  TRACE_DEBUG(" demo bin tag is %x \n\r", binheader.tag);
  TRACE_DEBUG(" demo bin has %u slides \n\r", binheader.slidecount);
  //Check if it is atmel demo bin
  if( i != sizeof(DemoBINHeader) || binheader.tag != ATMLBINTAG) {
    TRACE_ERROR(" Not expected demo bin file! \n\r");
    return 1;
  }

  //save max slide count of active demo bin file
  gActiveBinSlideCount = binheader.slidecount;
    
  //requested slide index larger than available one in current demo bin
  if(slideIdx >= binheader.slidecount) {
    TRACE_WARNING(" Reach max slide count! \n\r");
    
    if(realSlideIdx)
      *realSlideIdx = binheader.slidecount - 1;
    
    slideIdx = binheader.slidecount - 1;
  }
  
  //seek the offset to the 'slideindex'th bit map data
  offset = sizeof(DemoBINHeader) + slideIdx * sizeof(SlideINFOHeader);
  
  TRACE_DEBUG("\n\r slide header offset is %u", offset);
  
  //Seek to the position of slide information field
  res = f_lseek(pFile, offset);
  if(res != FR_OK) {
    TRACE_ERROR(" Operation demo bin file fail! \n\r");
    return 1;
  }
  
  //read slide information
  res = f_read(pFile, pSlideheader, sizeof(SlideINFOHeader), &i);
  if(res != FR_OK || i != sizeof(SlideINFOHeader)) {
    TRACE_ERROR(" Read demo bin file fail! \n\r");
    return 1;
  }
  
  return 0;
}

//------------------------------------------------------------------------------
/// read slide information from SDCARD, and Show
/// \param slideIdx, slidex index for reading slide and show
/// \return 0 succeed, other fail
//------------------------------------------------------------------------------
static int ProcessBinFromSDcard(unsigned int slideIdx, const char *pFileWithPath)
{
  
//  DemoBINHeader binheader;
  SlideINFOHeader slideheader;
  unsigned int offset;

  TRACE_DEBUG(" file name is %s \n\r", pFileWithPath);

  FIL demoBinFile;
  FRESULT res;
  unsigned int i;
  
//  strcpy(pFile,SDCARD_ROOT_DIRECTORY);
//  strncat(pFile, pFileWithPath, 256-1-strlen(SDCARD_ROOT_DIRECTORY));
  
  //Open demo bin file
  res = f_open(&demoBinFile, pFileWithPath, FA_OPEN_EXISTING | FA_READ);
  if(res != FR_OK) {
    TRACE_ERROR(" Open demo bin file fail! \n\r");
    f_close(&demoBinFile);
    return 1;
  }
  
  //get slide info from file
  if(GetSlideInfoHeaderFromFile(\
      &demoBinFile,\
        slideIdx,\
          &slideheader,\
            &slideIdx))
  {
    TRACE_ERROR(" Read slide header fail!\n\r");
    f_close(&demoBinFile);
    return 1;
  }
  
  //set real slide index as active
  gActiveSlideIndex = slideIdx;
  
  //get the 'slideindex'th slide bit map data offset
  offset = slideheader.slideoffset;
  
  TRACE_DEBUG(" slide %u bitmap data at %u \n\r", slideIdx, offset);
  
#if defined(GLOBALSLIDEINFO)  
  //copy current active slide information to global variable
  memcpy(&gActiveSlideHeader, &slideheader, sizeof(SlideINFOHeader));
#endif
  
  //print the link box information
  TRACE_DEBUG(" slide has link %u\n\r", gActiveSlideHeader.linkcount);
  if(slideheader.linkcount) {
    unsigned int j;
    for(j = 0; j < slideheader.linkcount; ++j) {
      TRACE_DEBUG(" link bottom %u, left %u, width %u, height %u \n\r", \
        slideheader.linkinfo[j].linkboxbottom,\
          slideheader.linkinfo[j].linkboxleft,\
            slideheader.linkinfo[j].linkboxwidth,\
              slideheader.linkinfo[j].linkboxheight);
    }
  }
  
  //seek to offset of the 'slideindex'th slide bit map data
  res = f_lseek(&demoBinFile, offset);
  if(res != FR_OK) {
    TRACE_DEBUG(" Operation demo bin file fail! \n\r");
    f_close(&demoBinFile);
    return 1;
  }
  
#if !defined(USE_SRAM_BUF)
  //Read all single slide bitmap data into PSRAM buffer, then write to LCD 
  TRACE_DEBUG(" Ready to read bit map data len %u \n\r", slideheader.slidedatalength);
  
  //read slide bit map data
  res = f_read(&demoBinFile, gpFileBuffer, slideheader.slidedatalength, &i);
  
  TRACE_DEBUG(" Data read len is %u \n\r", i);
  
  if(res != FR_OK || i != slideheader.slidedatalength) {
    TRACE_ERROR(" Read bitmap data fail! \n\r");
    f_close(&demoBinFile);
    return 1;
  }
  f_close(&demoBinFile);

  //Define a pointer to cast bmp header  
  struct BMPHeader *header = (struct BMPHeader *)gpFileBuffer;
  offset = header->offset;

  //Show slide bitmap header information  
  TRACE_DEBUG("============bmp header outside calling============== \n\r");
  TRACE_DEBUG(" bmp.type is %x \n\r", header->type);
  TRACE_DEBUG(" bmp.filesize is %u \n\r", header->fileSize);
  TRACE_DEBUG(" bmp.width is %u \n\r", header->width);
  TRACE_DEBUG(" bmp.height is %u \n\r", header->height);
  TRACE_DEBUG(" bmp.compressed is %u \n\r", header->compression);
  TRACE_DEBUG(" bmp.bitdepth is %d \n\r", header->bits);
  TRACE_DEBUG(" bmp.offset is %u \n\r", header->offset);

  //LCDD_DrawImageRGB565((unsigned short *)(pLcdBuffer),BOARD_LCD_WIDTH, BOARD_LCD_HEIGHT);
  LCDD_DrawImageRGB565((unsigned short *)(gpFileBuffer + offset),BOARD_LCD_WIDTH, BOARD_LCD_HEIGHT);

#else //USE_SRAM_BUF defined
  
  //USE sram buffer to read bitmap data and then write to LCD
  unsigned int k;
  char srambuf[BUF_LEN_SRAM];
  unsigned short *lcddata;
    
  //buffer len is not even. 
  if(BUF_LEN_SRAM % 2 != 0) {
    TRACE_ERROR("SRAM buffer size must be even! \n\r");
    f_close(&demofilebin);
    return 1;
  }
      
  //buffer len is too short to fit a bmp file header
  if(BUF_LEN_SRAM < sizeof(struct BMPHeader)) {
    TRACE_ERROR("SRAM buffer size is too short, Add it large than %u \n\r", sizeof(struct BMPHeader));
    f_close(&demofilebin);
    return 1;
  }
  
  //read slide bit map header
  res = f_read(&demofilebin, srambuf, sizeof(struct BMPHeader), &i);
  
  struct BMPHeader *header = (struct BMPHeader *)&srambuf[0];
  //Get BMP bitmap data offset
  offset = header->offset + slideheader.slideoffset;
  
  //seek to the bitmap data offset
  res = f_lseek(&demofilebin, offset);
  if(res != FR_OK) {
    TRACE_DEBUG(" Can't find BMP bitmap Data in bin file! \n\r");
    f_close(&demofilebin);
    return 1;
    }
    
  //prepare to write lcd
  LCD_SetCursor((void *)BOARD_LCD_BASE, 0, 0);
  LCD_WriteRAM_Prepare((void *)BOARD_LCD_BASE);
      
  for(k = 0; k < slideheader.slidedatalength && k < LCD16BITDATALEN; k += BUF_LEN_SRAM) {
    
    lcddata = (unsigned short *)&srambuf[0];
    
    //read data to buffer
    res = f_read(&demofilebin, srambuf, \
      (k + BUF_LEN_SRAM)> slideheader.slidedatalength ? (slideheader.slidedatalength - k): BUF_LEN_SRAM, &i);
    
    if(res != FR_OK) {
      TRACE_ERROR(" Read bitmap data fail! \n\r");
      f_close(&demofilebin);
      return 1;
    }
    
    //write the data to LCD base address
    while(i>0) {
      LCD_WriteRAM((void *)BOARD_LCD_BASE, *(lcddata++));
      i-=2;
    }
  }
  
  f_close(&demofilebin);
  
#endif//end of USE_SRAM_BUF  
  unsigned int k; 
  if(slideheader.dispboxcount) {
    for(k = 0; k < slideheader.dispboxcount; ++k) {
      //conversion rule based on SAM3U current setting.
      unsigned int top = slideheader.dispboxinfo[k].dispboxleft;
      unsigned int left = DEMOSLIDEHEIGHT - slideheader.dispboxinfo[k].dispboxbottom;
      unsigned int width = slideheader.dispboxinfo[k].dispboxheight;
      unsigned int height = slideheader.dispboxinfo[k].dispboxwidth;
      
      SetDispBoxPos(k+1, DISPBOX_ENABLE,  \
        top, left, width, height);
      
      EnableDispBox(k);
    }
    
  } else {
    for(k = 0; k < MAX_DISPBOX_PER_SLIDE; ++k) {
      DisableDispBox(k);
    }
  }
  
  return 0;
}

//------------------------------------------------------------------------------
///read slide information from External NandFlash, and Show
//------------------------------------------------------------------------------
static int ProcessBinFromNandFlash(unsigned int slideIdx, const char *pFileWithPath)
{
  unsigned int iRet;
  
  //fatfs mounted on NAND FLASH also, so reuse SDCard code
  iRet = ProcessBinFromSDcard(slideIdx, pFileWithPath);
  
  return iRet;  
}


//------------------------------------------------------------------------------
///read slide information from Internal flash, and Show
//------------------------------------------------------------------------------
static int ProcessBinFromInternalFlash(unsigned int binStartAddr, unsigned int slideIdx)
{
  DemoBINHeader binheader;
  SlideINFOHeader slideheader;
  unsigned int offset;
  
  //get demo bin header information
  binheader = *(DemoBINHeader*)binStartAddr;
  TRACE_DEBUG(" bin tag is %x\n\r", binheader.tag);
  TRACE_DEBUG(" filesize is %u\n\r", binheader.filesize);
  TRACE_DEBUG(" headersize is %u\n\r", binheader.headersize);
  TRACE_DEBUG(" bin has %u slide\n\r", binheader.slidecount);

  //check if it has atmel demo bin header tag
  if(binheader.tag != ATMLBINTAG) {
    TRACE_ERROR(" Not Atmel demo bin in FLASH1!\n\r");
    return 1;
  }

  //check if slide index reachs max 
  if(slideIdx >= binheader.slidecount) {
    slideIdx = binheader.slidecount - 1;
    TRACE_WARNING(" Reach max slides!\n\r");
  }

  //set real slide index as active
  gActiveSlideIndex = slideIdx;

  //offset of slide info header
  offset = sizeof(DemoBINHeader) + slideIdx * sizeof(SlideINFOHeader);
#if defined(GLOBALSLIDEINFO)
  memcpy(&gActiveSlideHeader, (void*)(binStartAddr+offset), sizeof(SlideINFOHeader));
#endif
  
  slideheader = *(SlideINFOHeader *)(binStartAddr+offset); 
  TRACE_DEBUG(" slide has dispbox?%s\n\r",slideheader.dispboxyes?"yes":"no");
  TRACE_DEBUG(" slideoffset is %u\n\r", slideheader.slideoffset);
  TRACE_DEBUG(" slidedatalength is %u\n\r", slideheader.slidedatalength);
  TRACE_DEBUG(" slidewidth is %u\n\r", slideheader.slidewidth);
  TRACE_DEBUG(" slideheight is %u\n\r", slideheader.slideheight);
  TRACE_DEBUG(" slide has %u links\n\r", slideheader.linkcount);
  if(slideheader.linkcount) {
    TRACE_DEBUG(" link 0'addr is %s\n\r", slideheader.linkinfo[0].linkstring);
  }

  //offset of slide bmp file
  offset = slideheader.slideoffset;
  BMP_displayHeader((unsigned int*)binStartAddr+offset);

  //Get slide bmp file header
  struct BMPHeader *bmpheader = (struct BMPHeader*)(binStartAddr+offset);
  if(bmpheader->type != 0x4d42) {
    TRACE_ERROR(" Slide bitmap file is not correct!\n\r");
    return 1;
  }

  //check bitdepth if it is 8. 1,4bitdepth is not supported for complicate
  //pixel color conversion. 16,24bitdepth bitmap data length too big.
  //TODO: Care more case of IFlash of some EK board less than 8bit bmp file size, 77k
  if(bmpheader->bits !=8) {
    TRACE_ERROR(" Slide bitmap color bitdepth %d is not supported!", bmpheader->bits);
    return 1;
  }

  BMP_Decode((void *)(binStartAddr + offset), gpFileBuffer, \
              bmpheader->width, bmpheader->height, 24);

  unsigned int i;
  unsigned int color24;
  unsigned short color16;

  LCD_SetCursor((void *)BOARD_LCD_BASE, 0, 0);
  LCD_WriteRAM_Prepare((void *)BOARD_LCD_BASE);
  unsigned char * pImage = gpFileBuffer;
  for (i = 0; i < (BOARD_LCD_WIDTH * BOARD_LCD_HEIGHT); i++) {

      color24 = (*pImage << 16) | (*(pImage+1) << 8) | (*(pImage+2));
      pImage += 3;
      color16 = RGB24ToRGB16(color24);
      LCD_WriteRAM((void *)BOARD_LCD_BASE, color16);
  }


  unsigned int k; 
  if(slideheader.dispboxcount) {
    for(k = 0; k < slideheader.dispboxcount; ++k) {
      //conversion rule based on SAM3U current setting.
      unsigned int top = slideheader.dispboxinfo[k].dispboxleft;
      unsigned int left = DEMOSLIDEHEIGHT - slideheader.dispboxinfo[k].dispboxbottom;
      unsigned int width = slideheader.dispboxinfo[k].dispboxheight;
      unsigned int height = slideheader.dispboxinfo[k].dispboxwidth;
      
      SetDispBoxPos(k+1, DISPBOX_ENABLE,  \
        top, left, width, height);
      
      EnableDispBox(k);
    }
    
  } else {
    for(k = 0; k < MAX_DISPBOX_PER_SLIDE; ++k) {
      DisableDispBox(k);
    }
  }
  
  return 0;
}

//------------------------------------------------------------------------------
/// Show LCD prompt information, normally it is slide from demo bin
/// \param pFileName, demo bin file name without designated drive path
//------------------------------------------------------------------------------
int ReadSlideInfoAndShow(const char * pFileName)
{
  int iRet;
  char pFile[256];
  
  strcpy(pFile,SDCARD_ROOT_DIRECTORY);
  strncat(pFile, pFileName, 256-1-strlen(SDCARD_ROOT_DIRECTORY));
  //gpActiveBinFile = "sam3demo.bin";//fname;
  iRet = ProcessBinFromSDcard(gActiveSlideIndex, pFile);
  
  //read from SDCard fail
  if(iRet) {
    strcpy(pFile, NAND_ROOT_DIRECTORY);
    strncat(pFile, pFileName, 256-1-strlen(NAND_ROOT_DIRECTORY));
    
    iRet = ProcessBinFromNandFlash(gActiveSlideIndex, pFile);

    if(iRet){
        iRet = ProcessBinFromInternalFlash(gDemoBinAddrInFlash, 0);
    }
  }
  
  //both reading from sdcard and nand flash fail!
  if(iRet) {
    TRACE_ERROR("\n\r Read LCD prompt slide information fail!");
  }
  
  return iRet;
}

//------------------------------------------------------------------------------
/// Check the hit point if it is in hyperlink zone of active slide
/// \param slideIdx  slide index to check the hyperlink on the slide
/// \return 0 means not in hot zone; other values is the link index start from 1
//------------------------------------------------------------------------------
static unsigned int CheckHitLink()
{
  unsigned int bottom, left, width, height;
  unsigned int linkcnt;
  
#if !defined(GLOBALSLIDEINFO)
  SlideINFOHeader gActiveSlideHeader;//to consistent with global one

  if(GetActiveSlideInfoHeader(gActiveSlideIndex,\
    &gActiveSlideHeader,\
      0)) 
  {
    //can't get active slide info, Consider as not hit
    return 0;
  }
  
#endif
  
  linkcnt = gActiveSlideHeader.linkcount;
  unsigned int i;
  for(i = 0; i < linkcnt; ++i) {
    bottom = gActiveSlideHeader.linkinfo[i].linkboxbottom;
    left = gActiveSlideHeader.linkinfo[i].linkboxleft;
    width = gActiveSlideHeader.linkinfo[i].linkboxwidth;
    height = gActiveSlideHeader.linkinfo[i].linkboxheight;
    
    //inside the link box?
    if((gTSDxPressed > left) && (gTSDxPressed < (left + width)) && \
      (gTSDyPressed < bottom) && (gTSDyPressed > (bottom - height)))
        return i+1;
  }
        
  return 0;       
}

//------------------------------------------------------------------------------
/// Get link string from link index on active slide
/// \param linkIdx  link index on active slide, start from 1
/// \return NULL means no link string; otherwise, link string
//------------------------------------------------------------------------------
char * GetLinkStrFromActiveSlide(unsigned int linkIdx)
{
  
#if !defined(GLOBALSLIDEINFO)
  SlideINFOHeader gActiveSlideHeader;//to consistent with global one

  if(GetActiveSlideInfoHeader(gActiveSlideIndex,\
    &gActiveSlideHeader,\
      0)) 
  {
    //can't get active slide info, Consider as NULL
    return NULL;
  }

  
#endif
  return gActiveSlideHeader.linkinfo[linkIdx-1].linkstring;
}

//////////////////////////////////////////////////////
///                    exported function             /
//////////////////////////////////////////////////////

//-------------------------------------------------------------------------
/// Set Touch screen is touched
//-------------------------------------------------------------------------
void TSD_SetTouched(void)
{
    gTSDPressed = 1;
}

//-------------------------------------------------------------------------
/// Clear Touch screen is touched
//-------------------------------------------------------------------------
void TSD_ClearTouched(void)
{
    gTSDPressed = 0;
}

//-------------------------------------------------------------------------
/// Get Touch screen is touched
//-------------------------------------------------------------------------
unsigned char TSD_GetTouched(void)
{
    return gTSDPressed;
}

//-------------------------------------------------------------------------
/// Check if touchscreen hit in a hot zone
/// \return 0 means no, other values mean yes
//-------------------------------------------------------------------------
unsigned int TSD_CommandIsReady()
{
  unsigned int ret;
  
  if(0 == gTSDxPressed && 0 == gTSDyPressed) {
    return 0;
  }
  
  ret = CheckHitLink();
  
  //set global variable for link index
  gLinkIndex = ret;
  
  gTSDxPressed = gTSDyPressed = 0;
  
  return ret;
}

//----------------------------------------------------------
/// Get ready command
/// \return string pointer to link string
//----------------------------------------------------------
const char * TSD_GetCommand()
{
  char *pStr;
  
  //get link string from index
  pStr = GetLinkStrFromActiveSlide(gLinkIndex);
  
  //clear
  gLinkIndex = 0;
  
  return pStr;
}

//------------------------------------------------------------------------------
///  Set LCD fresh show flag, this will cause next call to LCD_ShowPrompt reload
///  slide page data any way.
//------------------------------------------------------------------------------
void LCD_SetRefreshFlag()
{
  gLcdRefreshFlag = 1;
}

//------------------------------------------------------------------------------
///  Clear LCD fresh show flag
//------------------------------------------------------------------------------
void LCD_ClearRefreshFlag()
{
  gLcdRefreshFlag = 0;
}

//------------------------------------------------------------------------------
///  Show LCD prompt information, normally it is slide from demo bin
//------------------------------------------------------------------------------
int LCD_ShowPrompt()
{
  static unsigned int slideIndexLoaded = 0xffffffff;
  int ret;

  if(gActiveSlideHeader.propyes) {
    if(slideIndexLoaded != gActiveSlideIndex && slideIndexLoaded != 0xffffffff) {
      ParseAndRunMultiCmds(gActiveSlideHeader.propinfo.onCloseCmds);
    }
  }

  //reload show only slide index changed or fresh flag is set
  if(slideIndexLoaded != gActiveSlideIndex || gLcdRefreshFlag) {
    ret = ReadSlideInfoAndShow(gpActiveBinFile);
    
    if(gActiveSlideHeader.propyes && slideIndexLoaded != gActiveSlideIndex) {      
      ParseAndRunMultiCmds(gActiveSlideHeader.propinfo.onInitCmds);
    }
    
    slideIndexLoaded = gActiveSlideIndex;
    gLcdRefreshFlag = 0;
  }

  if(gActiveSlideHeader.propyes) {
    ParseAndRunMultiCmds(gActiveSlideHeader.propinfo.onRefreshCmds);
  }
  
  return ret;
}

