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

#ifndef FPGA_INIT_H
#define FPGA_INIT_H

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

// PAD configuration //////////////////////////////////////////////////////////
#define MPIO_LP     LOWPOWER_ON

/*
#ifdef MPIO18
  #define MPIO_SUPPLY SUPPLY_18
#else
  #define MPIO_SUPPLY SUPPLY_33
#endif
*/
#define MPIO_SUPPLY SUPPLY_33

//////////////////////////////////////////////////////////////////////

// CAP9 Part identification //////////////////////////////////////////
#define EXTENDED_CHIP_ID_REG *((volatile unsigned int*)0xFFFFEE44)
#define NOT_A_DEV_CHIP_ERROR 0xCACAB0F0
#define CAP9_CHECK_REVISION_REG *((volatile unsigned int*)0xFFFFFCFC)
#define REV_C_CHECK_VALUE 0x00000601
#define REV_B_CHECK_VALUE 0x00000399
#define NEW_IF 0
#define OLD_IF 1
//////////////////////////////////////////////////////////////////////

#define RSTC_SR_REG *((volatile unsigned int*)0xFFFFFD04)
#define POWER_ON_TEMPO 0x00FFFFFF

#define __FPGA_IF_TYPE_DIV5
// #define __FPGA_IF_TYPE_DIV3
#define CLK_OUT_DELAY_MIN 28
#define CLK_OUT_DELAY_MAX 50

#define FPGA_SYNCHRO_TIMEOUT1 180 // max iteration number for first clk_out_delay match value research
#define FPGA_SYNCHRO_TIMEOUT2 180 // max iteration number for last clk_out_delay match value research
#define FPGA_SYNCHRO_TIMEOUT3 10  // max iteration number for cycle index match value

#define FPGA_SYNCHRO_ERROR1 0xCACAB0F1 // timeout occured for first clk_out_delay match value research
#define FPGA_SYNCHRO_ERROR2 0xCACAB0F2 // timeout occured for last clk_out_delay match value research
#define FPGA_SYNCHRO_ERROR3 0xCACAB0F3 // timeout occured for cycle index match value

// CAP9 MP Block user interface registers /////////////////////////////////////
#define MPBLOCK_USER_INTERFACE_BASE_ADDR (char*)0xFDF00000
#define INIT_CMD_REG_OFFSET             0x00
#define INIT_ARG_REG_OFFSET             0x04
#define FPGA_IF_TYPE_REG_OFFSET         0x08
#define CYCLE_IDX_RESP_R_LSB_REG_OFFSET 0x10
#define CYCLE_IDX_RESP_R_MSB_REG_OFFSET 0x14
#define CYCLE_IDX_RESP_F_LSB_REG_OFFSET 0x18
#define CYCLE_IDX_RESP_F_MSB_REG_OFFSET 0x1C
#define DELAY_CTRL_REG_OFFSET           0x20
#define DELAY_STATUS_REG_OFFSET         0x24
#define CONFIG_INIT_REG_OFFSET          0x28
#define LOCK_IPS_KEY1_REG_OFFSET        0x30
#define LOCK_IPS_KEY2_REG_OFFSET        0x34
#define LOCK_IPS_KEY3_REG_OFFSET        0x38
#define LOCK_IPS_KEY4_REG_OFFSET        0x3C
#define UNLOCK_IPS_REG_OFFSET           0x40

#define INIT_CMD_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+INIT_CMD_REG_OFFSET))
#define INIT_ARG_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+INIT_ARG_REG_OFFSET))
#define FPGA_IF_TYPE_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+FPGA_IF_TYPE_REG_OFFSET))
#define CYCLE_IDX_RESP_R_LSB_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+CYCLE_IDX_RESP_R_LSB_REG_OFFSET))
#define CYCLE_IDX_RESP_R_MSB_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+CYCLE_IDX_RESP_R_MSB_REG_OFFSET))
#define CYCLE_IDX_RESP_F_LSB_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+CYCLE_IDX_RESP_F_LSB_REG_OFFSET))
#define CYCLE_IDX_RESP_F_MSB_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+CYCLE_IDX_RESP_F_MSB_REG_OFFSET))
#define DELAY_CTRL_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+DELAY_CTRL_REG_OFFSET))
#define DELAY_STATUS_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+DELAY_STATUS_REG_OFFSET))
#define CONFIG_INIT_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+CONFIG_INIT_REG_OFFSET))
#define LOCK_IPS_KEY1_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+LOCK_IPS_KEY1_REG_OFFSET))
#define LOCK_IPS_KEY2_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+LOCK_IPS_KEY2_REG_OFFSET))
#define LOCK_IPS_KEY3_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+LOCK_IPS_KEY3_REG_OFFSET))
#define LOCK_IPS_KEY4_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+LOCK_IPS_KEY4_REG_OFFSET))
#define UNLOCK_IPS_REG *((volatile unsigned int*)(MPBLOCK_USER_INTERFACE_BASE_ADDR+UNLOCK_IPS_REG_OFFSET))
///////////////////////////////////////////////////////////////////////////////

// CAP9 chip configuration user interface /////////////////////////////////////
#define CCF_INTERFACE_BASE_ADDR (char*)0xFFFFEA00
#define MPBS0_SFR_OFFSET         0x0114
#define MPBS1_SFR_OFFSET         0x011C
#define EBI_CSA_OFFSET           0x0120
#define MPBS2_SFR_OFFSET         0x012C
#define MPBS3_SFR_OFFSET         0x0130

#define MPBS_ENABLE_BIT 0x80000000
#define MPIOB_PUN_BIT   0x04000000
#define MPIOB_LP_BIT    0x02000000
#define MPIOB_SUP_BIT   0x01000000
#define MPIOA_PUN_BIT   0x00040000
#define MPIOA_LP_BIT    0x00020000
#define MPIOA_SUP_BIT   0x00010000

#define MPBS0_SFR_REG *((volatile unsigned int*)(CCF_INTERFACE_BASE_ADDR+MPBS0_SFR_OFFSET))
#define MPBS1_SFR_REG *((volatile unsigned int*)(CCF_INTERFACE_BASE_ADDR+MPBS1_SFR_OFFSET))
#define EBI_CSA_REG *((volatile unsigned int*)(CCF_INTERFACE_BASE_ADDR+EBI_CSA_OFFSET))
#define MPBS2_SFR_REG *((volatile unsigned int*)(CCF_INTERFACE_BASE_ADDR+MPBS2_SFR_OFFSET))
#define MPBS3_SFR_REG *((volatile unsigned int*)(CCF_INTERFACE_BASE_ADDR+MPBS3_SFR_OFFSET))

#define MPBS0 ((volatile unsigned int*)(CCF_INTERFACE_BASE_ADDR+MPBS0_SFR_OFFSET))
#define MPBS1 ((volatile unsigned int*)(CCF_INTERFACE_BASE_ADDR+MPBS1_SFR_OFFSET))
#define MPBS2 ((volatile unsigned int*)(CCF_INTERFACE_BASE_ADDR+MPBS2_SFR_OFFSET))
#define MPBS3 ((volatile unsigned int*)(CCF_INTERFACE_BASE_ADDR+MPBS3_SFR_OFFSET))
#define PULLUP_ON    1
#define PULLUP_OFF   2
#define LOWPOWER_ON  3
#define LOWPOWER_OFF 4
#define SUPPLY_33    33
#define SUPPLY_18    18
///////////////////////////////////////////////////////////////////////////////

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
extern unsigned int BOARD_InitMPBlock(unsigned char mode);


#endif // FPGA_INIT_H
