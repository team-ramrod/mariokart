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

/*
    Title: FPGA / CAP synchronization routines
*/

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include <board.h>
#include <rtt/rtt.h>
#include <slck/slck.h>
#include <pio/pio.h>
#include <utility/trace.h>
#include "board_fpga_init.h"


//------------------------------------------------------------------------------
//         FPGA Config done on PC13 (CAP9S3-DKZ only)
//------------------------------------------------------------------------------
#define PIN_FPGA_CONFDONE  {1 << 13, AT91C_BASE_PIOC, AT91C_ID_PIOABCD, PIO_INPUT, PIO_DEGLITCH}
static const Pin pinPC13 = PIN_FPGA_CONFDONE;


//------------------------------------------------------------------------------
// Prototype of internal functions
//------------------------------------------------------------------------------
unsigned int fpga_synchro_newIF(void);
unsigned int init_mpblock_revC(unsigned char mode);
unsigned int fpga_synchro_revC(void);
void init_mpbs_revC(volatile unsigned int* mpbs,char pun,char lp,char sup);
unsigned int init_mpblock_revB(void);
unsigned int fpga_synchro_revB(void);
void init_mpbs_revB(volatile unsigned int* mpbs,char pun,char lp,char sup);
void wait_slck_periods(int periods);
void wait_for_FPGA_config(void);
void wait_for_FPGA_config_CAP9S3(void);
unsigned int search_last_match(void);
unsigned int search_first_match(void);
int fpga_pattern_ok(void);

//------------------------------------------------------------------------------
// Globlal variables
//------------------------------------------------------------------------------
int delay_status, master_cnt_hold, master_cnt;


//------------------------------------------------------------------------------
// FPGA access initialization
// Returns : programmed clk out delay if success
//           error code with pattern CACAB0Fx if fail
//------------------------------------------------------------------------------
unsigned int BOARD_InitMPBlock(unsigned char mode)
{
    // Switch to external 32KHz if not done
    if(!SLCK_Is32k())SLCK_RCto32k();
  
    if (!(RSTC_SR_REG&0x00000600)){      	
      wait_for_FPGA_config_CAP9S3(); // if POR, wait until FPGA is ready
      }
  
    if(CAP9_CHECK_REVISION_REG == REV_B_CHECK_VALUE) {
        TRACE_INFO("Init MPBlock rev B\n\r");    	
        return(init_mpblock_revB()); // CAP9 revB detected
    }
    else {
        if(EXTENDED_CHIP_ID_REG) {
            TRACE_INFO("No init MPBlock : it is not a dev chip\n\r");        	
            return(NOT_A_DEV_CHIP_ERROR); // not a dev chip
        }
        else {	
            TRACE_INFO("Init MPBlock rev C\n\r");
            return(init_mpblock_revC(mode)); // CAP9 revC detected
        }
    }
}

//------------------------------------------------------------------------------
// CAP9 / FPGA synchronization loop - CAP9 RevC / new interface
//------------------------------------------------------------------------------
unsigned int fpga_synchro_newIF (void)
{
  unsigned int time = 0;
  unsigned int wait_loop1;
  unsigned int wait_loop2;
  unsigned int wait_loop3;
  unsigned int delay_ctrl, clkin_delay, clkin_delay_max,dw_width;  
  
  
  //-- Write in CONFIG_INIT register
  //--   - dllin_used bit = 0 (used clock coming from FPGA)
  //--   - dllout_used bit = 0 (bypass the DelayLine OUT)
  //--   - drive_pad_by_sfr = - (drive pad by register)
  CONFIG_INIT_REG &= 0xFFFFFE7F; //outi(0xFDF00000+0x28, (ini(0xFDF00000+0x28) & 0xFFFFFE7F));
 
  // clk_in setup
  delay_status = DELAY_STATUS_REG;  //-- read in DELAY_STATUS register
  master_cnt_hold = ((delay_status & 0xFF00) >> 8) + 6;
  master_cnt      = (delay_status & 0xFF0000) >> 16;


//ERr
  //clkin_delay = (master_cnt_hold >> 2)-2; //start in data window
  clkin_delay = 0;
  DELAY_CTRL_REG=(clkin_delay << 16)|0x1;
     
  //-- FPGA I/F INIT
  INIT_ARG_REG = 0x5C00;
  INIT_CMD_REG = 0x01;       // INIT_CMD = INIT_CMD_START_INIT
  wait_loop1 = 5000000;while(wait_loop1--);
  wait_loop2 = 5000000;while(wait_loop2--);
  wait_loop3 = 5000000;while(wait_loop3--);
  
  if (fpga_pattern_ok()){ // already in data window
    clkin_delay_max = search_last_match();
    clkin_delay = search_first_match();
    dw_width = clkin_delay_max + master_cnt_hold-clkin_delay;
    //ERr debug purppose
       printf("-I- Data window  : 0x%02X to 0x%02X\n\r", clkin_delay,clkin_delay_max);
    clkin_delay = (clkin_delay+dw_width/2)%master_cnt_hold;
    }
  else{ // not in data window
    clkin_delay = search_first_match();
    clkin_delay_max = search_last_match();
    dw_width = clkin_delay_max-clkin_delay;
    //ERr debug purppose
       printf("-I- Data window  : 0x%02X to 0x%02X\n\r", clkin_delay,clkin_delay_max);
    clkin_delay = (clkin_delay+dw_width/2)%master_cnt_hold;
    }
    
  
// debug purppose
  printf("-I- Master count : 0x%02X\n\r", master_cnt);
//clkin_delay = (master_cnt_hold >> 2)-2; //start in data window
  printf("-I- clk_in delay : 0x%02X\n\r", clkin_delay);
  printf("-I- data window width : 0x%02X (%dns)\n\r", dw_width,(dw_width*10/master_cnt));

  
  // Set clk in delay
  delay_ctrl = DELAY_CTRL_REG;
  DELAY_CTRL_REG=((delay_ctrl & ~(0xFF << 16)) | clkin_delay << 16);
  DELAY_CTRL_REG|=0x1;
   
  
  
  // Cycle index select
  time = 0;
  while((CYCLE_IDX_RESP_R_LSB_REG != 0x0A7014E0)&&time++<FPGA_SYNCHRO_TIMEOUT3){
    INIT_ARG_REG = 0x02; // INIT_ARG = 2
    INIT_CMD_REG = 0x02; // INIT_CMD = INIT_CMD_ADD_CYCLE
    }
  if(time>FPGA_SYNCHRO_TIMEOUT3)return(FPGA_SYNCHRO_ERROR3);


  // Return the number of iterations
  return(time);
}





//------------------------------------------------------------------------------
// FPGA access initialization - CAP9 RevC
//------------------------------------------------------------------------------
unsigned int init_mpblock_revC(unsigned char mode)
{
//  AT91PS_CCFG   pCCFG   = (AT91PS_CCFG) AT91C_BASE_CCFG; //not used
  unsigned int ret_value;
  
  // Enable clk
  *((unsigned int*)0xFFFFFC00)|=0x4;
  init_mpbs_revC(MPBS0,PULLUP_ON,MPIO_LP,MPIO_SUPPLY);

  // User IF pad config 
  /*
  *((unsigned int*)0xFDF00028)&=0xFFFFFFFD; // Drive pad by user if
  *((unsigned int*)0xFDF00034)=0x01000000; // MPIOB SUP
  *((unsigned int*)0xFDF00038)=0x00000000; // MPIOB SUP
  *((unsigned int*)0xFDF0003C)=0x00000000; // MPIOA SUP
  *((unsigned int*)0xFDF00040)=0x01000000; // MPIOB LP1
  *((unsigned int*)0xFDF00044)=0x00000000; // MPIOB LP2
  *((unsigned int*)0xFDF00048)=0x00000000; // MPIOA LP
  *((unsigned int*)0xFDF0004C)=0x00000000; // MPIOB PU1
  *((unsigned int*)0xFDF00050)=0x00000000; // MPIOB PU2
  *((unsigned int*)0xFDF00054)=0x00000000; // MPIOA PU
  */

  
  #ifdef __FPGA_IF_TYPE_DIV3
    FPGA_IF_TYPE_REG = 0x01;
  #endif

  // DELAY LINE SETUP
  DELAY_CTRL_REG = 0x03;              // write in DELAY_CTRL register enable_delay = 1 and update_delay = 1
  while (!(DELAY_STATUS_REG & 0x1)){} // wait master_is_locked = 1


  // FPGA IF synchronization loop
  TRACE_INFO("FPGA IF synchro loop...\n\r");  
  
  //#ifdef NEW_INTERFACE
  if (mode==NEW_IF){
    ret_value = fpga_synchro_newIF();
    if(ret_value>FPGA_SYNCHRO_TIMEOUT3)return(FPGA_SYNCHRO_ERROR3);
    }
  else{
    ret_value = fpga_synchro_revC();
    if ((ret_value&0xFFFF0000) == 0xCACA0000)return(ret_value);
    }
  //#endif
  TRACE_INFO("Synchro done\n\r");
  
  // Switch to functionnal mode
  //outi(0x30DC00, 0xDC00);
  INIT_ARG_REG = 0x4C727354; // INIT_ARG = INIT_CMD_START_INIT
  INIT_ARG_REG = 0x4C6F634B; // INIT_ARG = INIT_CMD_START_INIT
  INIT_CMD_REG = 0x03;       // INIT_CMD = INIT_CMD_CYCLE_IDX_LOCKED

  // Return the programmed clock_out_delay value
  return(ret_value);
}

//------------------------------------------------------------------------------
// FPGA access initialization - CAP9 RevC
//------------------------------------------------------------------------------
unsigned int fpga_synchro_revC(void)
{
  unsigned char clk_out_delay_mean;
  unsigned char clk_out_delay = 0;
  unsigned int time = 0;
  
  INIT_ARG_REG = 0x5C00; //
  wait_slck_periods(1);  // about 30us (wait 10us for FPGA PLL relock)
  INIT_CMD_REG = 0x01;   // INIT_CMD = INIT_CMD_START_INIT

  //Search first match value
  time = 0;
  while(((CYCLE_IDX_RESP_R_LSB_REG != CYCLE_IDX_RESP_F_LSB_REG)||(CYCLE_IDX_RESP_R_MSB_REG != ~CYCLE_IDX_RESP_F_MSB_REG))&&time++<FPGA_SYNCHRO_TIMEOUT1)DELAY_CTRL_REG=(clk_out_delay++ << 8)|0x1;
  if(time > FPGA_SYNCHRO_TIMEOUT1)return(FPGA_SYNCHRO_ERROR1);
  clk_out_delay_mean = clk_out_delay;

  //Search last match value
  DELAY_CTRL_REG=(clk_out_delay++ << 8)|0x1;
  while(((CYCLE_IDX_RESP_R_LSB_REG == CYCLE_IDX_RESP_F_LSB_REG)&&(CYCLE_IDX_RESP_R_MSB_REG == ~CYCLE_IDX_RESP_F_MSB_REG))&&time++<FPGA_SYNCHRO_TIMEOUT2)DELAY_CTRL_REG=(clk_out_delay++ << 8)|0x1;
  if(time>FPGA_SYNCHRO_TIMEOUT2)return(FPGA_SYNCHRO_ERROR2);
  clk_out_delay_mean = (clk_out_delay_mean + clk_out_delay)/2;

  // Setup to middle match value
  DELAY_CTRL_REG = (clk_out_delay_mean << 8) | 0x1;

  
  // Cycle index select
  time = 0;
  while((CYCLE_IDX_RESP_R_LSB_REG != 0x0A7014E0)&&time++<FPGA_SYNCHRO_TIMEOUT3) {
    INIT_ARG_REG = 0x02; // INIT_ARG = 2
    INIT_CMD_REG = 0x02; // INIT_CMD = INIT_CMD_ADD_CYCLE
    }
  if(time>FPGA_SYNCHRO_TIMEOUT3)return(FPGA_SYNCHRO_ERROR3);
  
  // Return the programmed clock_out_delay value
  return ((unsigned int)clk_out_delay_mean);
}

//------------------------------------------------------------------------------
// Enable CAP to FPGA clock, and configure pads - CAP9 RevC
//------------------------------------------------------------------------------
// Updated for UMC pads
void init_mpbs_revC(volatile unsigned int* mpbs,char pun,char lp,char sup)
{
  unsigned int value;

  if (mpbs!=MPBS0 && mpbs!=MPBS1 && mpbs!=MPBS2 && mpbs!=MPBS3)
    return;
  value = *mpbs | MPBS_ENABLE_BIT;

  if (pun==PULLUP_ON) value&= ~(MPIOB_PUN_BIT|MPIOA_PUN_BIT);
  else if (pun==PULLUP_OFF) value|= (MPIOB_PUN_BIT|MPIOA_PUN_BIT);

  if (lp==LOWPOWER_OFF) value|= (MPIOB_LP_BIT|MPIOA_LP_BIT);
  else if(lp==LOWPOWER_ON)value&= ~(MPIOB_LP_BIT|MPIOA_LP_BIT);

  if (sup==SUPPLY_18) value|= (MPIOB_SUP_BIT|MPIOA_SUP_BIT);
  else if(sup==SUPPLY_33)value&= ~(MPIOB_SUP_BIT|MPIOA_SUP_BIT);

  *mpbs = value;
}

//------------------------------------------------------------------------------
// FPGA access initialization - CAP9 RevB
//------------------------------------------------------------------------------
unsigned int init_mpblock_revB(void)
{
//  AT91PS_CCFG   pCCFG   = (AT91PS_CCFG) AT91C_BASE_CCFG; // not used
  unsigned int ret_value;
  
  // Enable clk
  init_mpbs_revB(MPBS0,PULLUP_ON,MPIO_LP,MPIO_SUPPLY);

  TRACE_INFO("FPGA IF synchro loop...\n\r");
  
  #ifdef __FPGA_IF_TYPE_DIV3
    FPGA_IF_TYPE_REG = 0x01;
  #endif
  // DELAY LINE SETUP
  DELAY_CTRL_REG = 0x03;              // write in DELAY_CTRL register enable_delay = 1 and update_delay = 1
  while (!(DELAY_STATUS_REG & 0x1)){} // wait master_is_locked = 1

  // FPGA IF synchronization loop
  //ret_value = fpga_synchro_old();
  ret_value = fpga_synchro_revB();
  if ((ret_value&0xFFFF0000) == 0xCACA0000)return(ret_value);

  TRACE_INFO("Synchro done\n\r");
  
  // Switch to functionnal mode
  //outi(0x30DC00, 0xDC00);
  INIT_ARG_REG = 0x4C727354; // INIT_ARG = INIT_CMD_START_INIT
  INIT_ARG_REG = 0x4C6F634B; // INIT_ARG = INIT_CMD_START_INIT
  INIT_CMD_REG = 0x03;       // INIT_CMD = INIT_CMD_CYCLE_IDX_LOCKED

  // Return the programmed clock_out_delay value
  return(ret_value);
}

//------------------------------------------------------------------------------
// CAP9 / FPGA synchronization loop - CAP9 RevB
//------------------------------------------------------------------------------
unsigned int fpga_synchro_revB(void)
{
  unsigned char clk_out_delay_mean;
  unsigned char clk_out_delay = 0;
  unsigned int time = 0;
  

  INIT_ARG_REG = 0x5C00; //
  wait_slck_periods(1);  // about 30us (wait 10us for FPGA PLL relock)
  INIT_CMD_REG = 0x01;   // INIT_CMD = INIT_CMD_START_INIT

  //Search first match value
  time = 0;
  while(((CYCLE_IDX_RESP_R_LSB_REG != CYCLE_IDX_RESP_F_LSB_REG)||(CYCLE_IDX_RESP_R_MSB_REG != ~CYCLE_IDX_RESP_F_MSB_REG))&&time++<FPGA_SYNCHRO_TIMEOUT1)DELAY_CTRL_REG=(clk_out_delay++ << 8)|0x1;
  if(time > FPGA_SYNCHRO_TIMEOUT1)return(FPGA_SYNCHRO_ERROR1);
  clk_out_delay_mean = clk_out_delay;

  //Search last match value
  DELAY_CTRL_REG=(clk_out_delay++ << 8)|0x1;
  while(((CYCLE_IDX_RESP_R_LSB_REG == CYCLE_IDX_RESP_F_LSB_REG)&&(CYCLE_IDX_RESP_R_MSB_REG == ~CYCLE_IDX_RESP_F_MSB_REG))&&time++<FPGA_SYNCHRO_TIMEOUT2)DELAY_CTRL_REG=(clk_out_delay++ << 8)|0x1;
  if(time>FPGA_SYNCHRO_TIMEOUT2)return(FPGA_SYNCHRO_ERROR2);
  clk_out_delay_mean = (clk_out_delay_mean + clk_out_delay)/2;

  // Setup to middle match value
  DELAY_CTRL_REG = (clk_out_delay_mean << 8) | 0x1;
  
  // Cycle index select
  time = 0;
  while((CYCLE_IDX_RESP_R_LSB_REG != 0x0A7014E0)&&time++<FPGA_SYNCHRO_TIMEOUT3) {
    INIT_ARG_REG = 0x02; // INIT_ARG = 2
    INIT_CMD_REG = 0x02; // INIT_CMD = INIT_CMD_ADD_CYCLE
    }
  if(time>FPGA_SYNCHRO_TIMEOUT3)return(FPGA_SYNCHRO_ERROR3);
  
  // Return the programmed clock_out_delay value
  return ((unsigned int)clk_out_delay_mean);
}

//------------------------------------------------------------------------------
// Enable CAP to FPGA clock, and configure pads - CAP9 RevB
//------------------------------------------------------------------------------
void init_mpbs_revB(volatile unsigned int* mpbs,char pun,char lp,char sup)
{
  //AT91PS_CCFG   pCCFG   = (AT91PS_CCFG) AT91C_BASE_CCFG;
  //pCCFG->CCFG_MPBS0 |= (1<<31) | (1<<16) | (1<<24);
  unsigned int value;

  if (mpbs!=MPBS0 && mpbs!=MPBS1 && mpbs!=MPBS2 && mpbs!=MPBS3)
    return;
  value = *mpbs | MPBS_ENABLE_BIT;

  if (pun==PULLUP_ON) value&= ~(MPIOB_PUN_BIT|MPIOA_PUN_BIT);
  else if (pun==PULLUP_OFF) value|= (MPIOB_PUN_BIT|MPIOA_PUN_BIT);

  if (lp==LOWPOWER_ON) value|= (MPIOB_LP_BIT|MPIOA_LP_BIT);
  else if(lp==LOWPOWER_OFF)value&= ~(MPIOB_LP_BIT|MPIOA_LP_BIT);

  if (sup==SUPPLY_33) value|= (MPIOB_SUP_BIT|MPIOA_SUP_BIT);
  else if(sup==SUPPLY_18)value&= ~(MPIOB_SUP_BIT|MPIOA_SUP_BIT);

  *mpbs = value;
}


//------------------------------------------------------------------------------
/// Wait specified number of slow clock periods (30.52uS if external 32KHz)
//------------------------------------------------------------------------------
void wait_slck_periods(int periods)
{
  RTT_SetPrescaler(AT91C_BASE_RTTC, 1);
  while(RTT_GetTime(AT91C_BASE_RTTC)!=periods);
}


//------------------------------------------------------------------------------
/// Wait for correct FPGA configuration (used after POR)
//------------------------------------------------------------------------------
void wait_for_FPGA_config()
{ 
  int i;
  for(i=0;i<POWER_ON_TEMPO;++i);
}


//------------------------------------------------------------------------------
/// Wait for correct FPGA configuration (used after POR) / CAP9S3-DKZ
//------------------------------------------------------------------------------
void wait_for_FPGA_config_CAP9S3()
{ 
  PIO_Configure(&pinPC13, 1);
  while(!PIO_Get(&pinPC13)); // Wait for config_done
  wait_slck_periods(4);      // Wait 100us more for user mode
}


//------------------------------------------------------------------------------
// FPGA pattern checking
//------------------------------------------------------------------------------
unsigned int search_last_match()
{
  unsigned int clkin_delay;
  
  clkin_delay = (DELAY_CTRL_REG >> 16)&(0xFF);
  while (fpga_pattern_ok() && (clkin_delay++ < master_cnt_hold))
    DELAY_CTRL_REG=(clkin_delay << 16)|0x1;

  return clkin_delay;
}

unsigned int search_first_match()
{
  unsigned int clkin_delay;
  
  clkin_delay = (DELAY_CTRL_REG >> 16)&(0xFF);
  while (!fpga_pattern_ok() && (clkin_delay++ < master_cnt_hold))
    DELAY_CTRL_REG=(clkin_delay << 16)|0x1;

  return clkin_delay;
}

int fpga_pattern_ok()
{
  return((CYCLE_IDX_RESP_R_LSB_REG == CYCLE_IDX_RESP_F_LSB_REG)&&(CYCLE_IDX_RESP_R_MSB_REG == ~CYCLE_IDX_RESP_F_MSB_REG));
}

