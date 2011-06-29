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
/// \unit
///
/// This file contains  algorithms and drivers for tilt sensing.
///
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include "dfm_accelerometer.h"
#include "board.h"
#include <irq/irq.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <adc/adc12.h>
#include <lcd/draw.h>

#include <stdio.h>

#include <math.h>

#include "dfm_config.h"
#include "dfm_cmd.h"
#include "dfm_lcd_tsd.h"
#include "dfm_dispboxmgr.h"
#include "dfm_it.h"
#include "dfm_init.h"

//------------------------------------------------------------------------------
//         Macros
//------------------------------------------------------------------------------
#define BOARD_ADC12_FREQ 5000000 //! ADC clock
#define ADC12_VREF       3300    //! reference voltage 3.3 * 1000,make sure the jumper setting is right
#define PINS_ACC_ADC PIN_ADC0_AD2,PIN_ADC0_AD6,PIN_ADC0_AD7

#define TAN30 (37) //! fixed point for tanget tan(45)*0x40
#define TAN15 17   //! fixed point for tangent tan(15)*0x40
#define DELAY 100
#define SAMPLES 1

#if defined(at91sam3u4)
#define AT91C_ID_ADC_PRESENT AT91C_ID_ADC12B
#define AT91C_BASE_ADC AT91C_BASE_ADC12B
#endif
//------------------------------------------------------------------------------
//         External Variables
//------------------------------------------------------------------------------
extern const char * gpActiveBinFile;
extern unsigned int gLcdRefreshFlag;
extern int rotation_axes_cpt;
/// record measurement times
static int count =0;
//------------------------------------------------------------------------------
//         Variables
//------------------------------------------------------------------------------


unsigned char ADC12_channel_x = ADC12_CHANNEL_2;                  //!< X Channel For Accelerometer
unsigned char ADC12_channel_y = ADC12_CHANNEL_6;                  //!< Y Channel For Accelerometer
unsigned char ADC12_channel_z = ADC12_CHANNEL_7;                  //!< Z Channel For Accelerometer
/// Indicates that the conversion is finished.
static volatile unsigned char conversionDone;

acc_t acc = { //!< Accelerometer Instance
  .m = { .x=0 , .y=0 , .z=0 } ,
  .k = { .x=ACC_ZERO_X , .y=ACC_ZERO_Y , .z=ACC_ZERO_Z } ,
  .ak = { .x=0 , .y=0 , .z=0 } ,
} ;

static const Pin pinsADC[] = {PINS_ACC_ADC};

static xyz_t lastMeasure = {0};
int gDir = DIR_UNCHANGED;
int gLastDir = DIR_UNCHANGED;

///push button to configure for the applicatino.
static Pin pinBP4 = PIN_PUSHBUTTON_1;
//------------------------------------------------------------------------------
//         Functions
//------------------------------------------------------------------------------
int DV_Check_AccStatus();

//------------------------------------------------------------------------------
/// add position
//------------------------------------------------------------------------------
xyz_t xyz_add (xyz_t p, xyz_t q)
{
  xyz_t r ;
  r.x = p.x + q.x ;
  r.y = p.y + q.y ;
  r.z = p.z + q.z ;
  return r ;
}

//------------------------------------------------------------------------------
/// sub position
//------------------------------------------------------------------------------
xyz_t xyz_diff (xyz_t p, xyz_t q)
{
  xyz_t r ;
  r.x = p.x - q.x ;
  r.y = p.y - q.y ;
  r.z = p.z - q.z ;
  return r ;
}

//------------------------------------------------------------------------------
/// Invoke platform api to get converted data
/// \param pAdc  address pointer for ADC12B controller
/// \param ADC12_channel_x channel number for x axis
/// \param ADC12_channel_y channel number for y axis
/// \param ADC12_channel_z channel number for z axis
/// \return converted data for three channels
//------------------------------------------------------------------------------
xyz_t acc_get_value (  AT91S_ADC12B *pAdc , unsigned char ADC12_channel_x, unsigned char ADC12_channel_y, unsigned char ADC12_channel_z)
{
  xyz_t val ;
  
  val.x = ADC12_GetConvertedData(pAdc, ADC12_channel_x);
  val.y = ADC12_GetConvertedData(pAdc, ADC12_channel_y);
  val.z = ADC12_GetConvertedData(pAdc, ADC12_channel_z);
  
  val.x = val.x>>ACC_SHIFT;
  val.y = val.y>>ACC_SHIFT;
  val.z = val.z>>ACC_SHIFT;
  
  return val ;
}


//------------------------------------------------------------------------------
/// get present acceleration value as 0-g value for x and y, 1-g value for z
//------------------------------------------------------------------------------
void DoCalibration()
{ 
  int i = 0,j;
  xyz_t temp ={0};
  count = 0;
  acc.m.x = 0;
  acc.m.y = 0;
  acc.m.z = 0;
  for(i = 0; i < 16 ; i++)
  {
    if(DV_Check_AccStatus()){
        temp = xyz_add(acc.m,temp);
        for(j=0;j<DELAY;j++);
    }
     
  }
  acc.m.x = temp.x /count;
  acc.m.y = temp.y /count;
  acc.m.z = temp.z /count;
  
  count = 0;
  acc.k = acc.m;
  
  
}

//------------------------------------------------------------------------------
///check if the tilt angles are big enough.If yes,get rotation direction 
///according to the sign of two axes
/// \return rotation direction
//------------------------------------------------------------------------------
int DV_Accelerometer_Tilt()
{
  int dir = DV_Accelerometer_Unchanged;
  int x=0,y=0,z=0;
  
  int i = 0,j;
  acc.m.x = 0;
  acc.m.y = 0;
  acc.m.z = 0;
  
  count = 0;
  
  for(i = 0; i < SAMPLES ; i++)
  {
    DV_Check_AccStatus();
    for(j=0;j<DELAY;j++);
  }
  acc.m.x = acc.m.x /count;
  acc.m.y = acc.m.y /count;
  acc.m.z = acc.m.z /count;
  count = 0;
  
  acc.ak = xyz_diff(acc.m,acc.k);
  
  

  x = acc.ak.x;
  y = acc.ak.y;
  z = (acc.ak.z + ACC_1G);
 
  
  if( (unsigned int)(x*x)<<12 > (TAN15*TAN15)*(y*y+z*z) || (unsigned int)(y*y)<<12 > (TAN15*TAN15)*(x*x+z*z))
  {    
    if((unsigned int)(x*x)<<12 > (TAN15*TAN15)*(y*y+z*z))
    {
      if((unsigned int)(y*y)<<12 > (TAN15*TAN15)*(x*x+z*z))
      {
        if(x < 0)
        {
          if(y < 0)
          {
            dir = DV_Accelerometer_up_right;
          }
          else
          {
             dir =DV_Accelerometer_down_right;
          }
        }
        else 
        {
          if(y < 0)
          {
            dir = DV_Accelerometer_up_left;
          }
          else
          {
            dir = DV_Accelerometer_down_left;
            
          }
        }
      }
      else
      {
        if(x < 0)
        {
          dir = DV_Accelerometer_right;
        }
        else
        {
          dir =  DV_Accelerometer_left;
        }
      }
      
    }
    else
    {
      if(y < 0)
      {
        dir = DV_Accelerometer_up;
      }
      else
      {
        dir = DV_Accelerometer_down;
      }
    }
  }
  
  return dir;
  
}


//------------------------------------------------------------------------------
/// get the direction of the board
/// \return direction
//------------------------------------------------------------------------------
int DV_Accelerometer_Dir()
{
  
  int dir = gDir;
  int x=0,y=0,z=0;
  xyz_t diff = {0};

  ///measure the difference between the last one and the present one
  diff = xyz_diff(acc.m,lastMeasure);
  
  ///check the status,acc.m will be changed after called routine
  ///if conversion is done,otherwise,return immediately
  DV_Check_AccStatus();

  
  ///no big change since last measurement
  if( diff.x*diff.x + diff.y*diff.y + diff.z*diff.z < ((ACC_1G*ACC_1G)>>11)) 
  {
    ///keep the old direction
    return gDir;
    
  }
  ///update lastMeasure to the new one
  lastMeasure = acc.m;
  
  ///get acceleration offset
  acc.ak = xyz_diff(acc.m,acc.k);

  

  x = acc.ak.x;
  y = acc.ak.y;
  z = (acc.ak.z + ACC_1G);
  /// filter non-tilting operation
  if( (x*x + y*y+z*z > ACC_AMPLITUDE_UPPER) ||(x*x + y*y+z*z < ACC_AMPLITUDE_LOWER) ){
      return gDir;
  }
 
  ///the board plane is angled with the horizontal surface 
  if( (unsigned int)(x*x)<<12 > (TAN30*TAN30)*(y*y+z*z) || (unsigned int)(y*y)<<12 > (TAN30*TAN30)*(x*x+z*z))
  {  
    
    if(x*x > y*y + (y*y>>1))
    {
      if(x > 0)
      {
        dir = DIR_HORIZIONTAL_UP;
      }
      else
      {
        dir = DIR_HORIZIONTAL_DOWN;
      }
    }
    else if(x*x + (x*x>>1) < y*y)
    {
      if(y > 0)
      {
        dir = DIR_VERTICAL_UP;
      }
      else
      {
        dir = DIR_VERTICAL_DOWN;
      }
    }
    //else dir = previous dir
    //leave gap enough  for stabilization
    ///renew the direction
    gDir = dir;
  }

  return gDir;
  
}
//------------------------------------------------------------------------------
///  Check accelerometer is ready?
///  if the direction is unchanged since last measurement,return "not ready"
///  \return 0 not ready, other value means ready and command string length
//------------------------------------------------------------------------------
unsigned int ACC_CommandIsReady()
{
  int dir = DIR_UNCHANGED;
  unsigned int ret;
  dir = DV_Accelerometer_Dir();
  //no change of direction since last measurement
  if(gLastDir == dir)
  {
    ret = 0;
  }
  else
  { 
    ret = 1;
  }
  gLastDir = dir;
  return ret;
}


//------------------------------------------------------------------------------
// get flipped ppt page
//------------------------------------------------------------------------------
const char * ACC_GetCommand()
{  
  if(gDir == DIR_HORIZIONTAL_UP || gDir == DIR_HORIZIONTAL_DOWN)
  {  
    //update to portait image file 
    gpActiveBinFile = LCDSLIDEVIMAGEFILE;
    gLcdRefreshFlag = 1;
     
  }
  else
  {     
     gpActiveBinFile = LCDSLIDEIMAGEFILE;
     gLcdRefreshFlag = 1;  
    
  }
  return NULL;
}

//an example of ShowPrompt
int ACC_ShowPrompt()
{
//  int i;
//   switch(gDir)//gDir
//    {
//      
//    case DIR_HORIZIONTAL_UP:
//      printf("Horizontal Up!\n");
//      //LCDD_DrawRectangle((void *)BOARD_LCD_BASE, x,y,width,height,0xE0E0C0);
//      break;
//    case DIR_HORIZIONTAL_DOWN:
//      printf("Horizontal Down!\n");
//      break;
//    case DIR_VERTICAL_UP:
//      printf("Vertical Up!\n");
//      break;
//    case DIR_VERTICAL_DOWN:
//      printf("Vertical Down!\n");
//      break;
//    default:
//      printf("Unchanged!\n");
//      break;
//    }
//    for(i=0;i<5000;i++);
  return 0;
}

//global accelerometer entry variable
TInputEntry gAccEntry = {0, {NULL,NULL},ACC_ShowPrompt, ACC_CommandIsReady, ACC_GetCommand, NULL};
//------------------------------------------------------------------------------
/// Check if conversion is done.If done,read the corresponding parameters and 
///start new measurement
//------------------------------------------------------------------------------
int DV_Check_AccStatus()
{
  //check if conversation is done
  //if done, read and measure,and start new conversation
  //else, return directly
  
  
  if(conversionDone == ((1<<ADC12_channel_x)|(1<<ADC12_channel_y)|(1<<ADC12_channel_z)))//x,y,z all done
  {
    // IRQ_DisableIT(AT91C_ID_ADC_PRESENT);
    DV_ACCELEROMETER_Measure();
    //sharing variable for main and isr
    conversionDone= 0;
    // record the number of measurement
    count++;
    
    // Start new measurement
    ADC12_EnableIt(AT91C_BASE_ADC, 1<<ADC12_channel_x);//Enable EOCx interrupt
    ADC12_EnableIt(AT91C_BASE_ADC, 1<<ADC12_channel_y);//Enable EOCx interrupt
    ADC12_EnableIt(AT91C_BASE_ADC, 1<<ADC12_channel_z);//Enable EOCx interrupt
    ADC12_StartConversion(AT91C_BASE_ADC);
    // conversionDone for all 3 channels
    return 1;
   }else{
    return 0;
   }
   
  
  
}

//------------------------------------------------------------------------------
/// Interrupt handler for the ADC. Signals that the conversion is finished by
/// setting a flag variable.
//------------------------------------------------------------------------------
void ADC12B_IrqHandler(void)
{
  unsigned int status, i;
  static unsigned char chns[3];
  AT91PS_ADC12B padc = AT91C_BASE_ADC;
  chns[0] = ADC12_channel_x;
  chns[1] = ADC12_channel_y;
  chns[2] = ADC12_channel_z;;
  
  
  status = ADC12_GetStatus(padc);
  //printf("status =0x%X\n\r", status);
  //TRACE_DEBUG("ADC12_imr=0x%X\n\r", ADC12_GetInterruptMaskStatus());
  
  for(i=0;i<sizeof(chns)/sizeof(unsigned char);i++) {
    if (ADC12_IsChannelInterruptStatusSet(status, chns[i])) {
      
      //printf("channel %d\n\r", chns[i]);
      ADC12_DisableIt(AT91C_BASE_ADC, 1<<chns[i]);//disable EOCx interrupt
      conversionDone |= 1<<chns[i];
    }
  }
}

#if defined(USE_IT_CHAIN_MGR)
TDFM_ItServList gAccADC12BHandler = {AT91C_ID_ADC_PRESENT, ADC12B_IrqHandler, NULL};
#endif
//------------------------------------------------------------------------------
/// ADC12B and accelerometer initialization
//------------------------------------------------------------------------------
int DV_ACCELEROMETER_Init(void)
{
  int cali_done = 0;
  char keyStatus = 0;
  Pin pinSleep;
  pinSleep.attribute = PIO_DEFAULT;
  pinSleep.mask = (1<<13);
  pinSleep.id = AT91C_ID_PIOC;
  pinSleep.pio = AT91C_BASE_PIOC;
  pinSleep.type = PIO_OUTPUT_1;
  
  ///Normal mode
  PIO_Configure(&pinSleep,1);
  PIO_Set(&pinSleep);
  
#ifdef PINS_ADC
  PIO_Configure(pinsADC, PIO_LISTSIZE(pinsADC));
#endif
  ///ADC12B configuration
  ADC12_Initialize( AT91C_BASE_ADC,
                   AT91C_ID_ADC_PRESENT,
                   AT91C_ADC12B_MR_TRGEN_DIS,
                   0,
                   AT91C_ADC12B_MR_SLEEP_NORMAL,
                   AT91C_ADC12B_MR_LOWRES_12_BIT,//for 12bit adc,0 means 12bits,1-10bits
                   BOARD_MCK,
                   BOARD_ADC12_FREQ,
                   10,
                   2400);
  ///Enable 3 channels for x,y and z
  ADC12_EnableChannel(AT91C_BASE_ADC, ADC12_channel_x);
  ADC12_EnableChannel(AT91C_BASE_ADC, ADC12_channel_y);
  ADC12_EnableChannel(AT91C_BASE_ADC, ADC12_channel_z);
  
  ///Enable adc12b interrupt 
  //IRQ_ConfigureIT(AT91C_ID_ADC_PRESENT, 0, ADCC0_IrqHandler);
 // IRQ_EnableIT(AT91C_ID_ADC_PRESENT);
#if defined(USE_IT_CHAIN_MGR)
  DFM_RegisterItHandler(&gAccADC12BHandler);
#endif
  
   IRQ_EnableIT(AT91C_ID_ADC_PRESENT);
  
  conversionDone = 0;
  
  ///Enable channel interrupt
  ADC12_EnableIt(AT91C_BASE_ADC, 1<<ADC12_channel_x);
  ADC12_EnableIt(AT91C_BASE_ADC, 1<<ADC12_channel_y);
  ADC12_EnableIt(AT91C_BASE_ADC, 1<<ADC12_channel_z);
  
  /// Start measurement
  ADC12_StartConversion(AT91C_BASE_ADC);
  
  ///if calibration needed here?
    
  // Do calibration first,ineteract with users
  LCDD_Fill(((void *)BOARD_LCD_BASE),0xffffff);
  //LCDD_DrawString((void *)BOARD_LCD_BASE,10,100,"Put the board on \nthe horizontal \nsurface and press \nBP4 to start \ncalibration!",0x0);

  //PIO_InitializeInterrupts(0);
  //PIO_Configure(&pinBP4,1);
  //keyStatus = 1;
  while(cali_done == 0)
  {
    // Check if button state has changed
    //unsigned char isButtonPressed = PIO_Get(&pinBP4);
    //if (isButtonPressed != keyStatus) {
      
      // Update button state
      //if (!isButtonPressed) {
        
        // Key has been pressed
        //printf("BP4 has been pressed!\n");
        //keyStatus = 0;         
        
        DoCalibration();
        cali_done = 1;
       
              
      //}
    //}
  }
  return 0;
  
}

//------------------------------------------------------------------------------
/// Get immediate acceleration
//------------------------------------------------------------------------------
void DV_ACCELEROMETER_Measure(void)
{
 acc.m = acc_get_value(AT91C_BASE_ADC, ADC12_channel_x, ADC12_channel_y, ADC12_channel_z) ;
 
}


//------------------------------------------------------------------------------
///
///Measure the direction,left,right,forward,backward,then switch rotation axis
///appopriately
///
//------------------------------------------------------------------------------
void DV_Accelerometer_Turn()
{
  int dir = DV_Accelerometer_Tilt();
  switch(dir)
  {
  case  DV_Accelerometer_Unchanged:
    rotation_axes_cpt = 0;
    break;
  case DV_Accelerometer_left:
    rotation_axes_cpt = 4;
    break;
  case DV_Accelerometer_right:
    rotation_axes_cpt = 3;
    break;
  case DV_Accelerometer_up:
    rotation_axes_cpt = 2;
    break;
  case DV_Accelerometer_down:
    rotation_axes_cpt = 1;
    break;    
  case DV_Accelerometer_up_right:
    rotation_axes_cpt = 6;
    break;
  case DV_Accelerometer_up_left:
    rotation_axes_cpt = 8;
    break;    
  case DV_Accelerometer_down_right:
    rotation_axes_cpt = 5;
    break;
  case DV_Accelerometer_down_left:
    rotation_axes_cpt = 7;
    break;
  }
}


//Accelerometer init in level 6
DFM_INIT(6, DV_ACCELEROMETER_Init);


