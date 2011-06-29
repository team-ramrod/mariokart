//  ----------------------------------------------------------------------------
//          ATMEL Microcontroller Software Support  -  ROUSSET  -
//  ----------------------------------------------------------------------------
//  Copyright (c) 2008, Atmel Corporation
// 
//  All rights reserved.
// 
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
// 
//  - Redistributions of source code must retain the above copyright notice,
//  this list of conditions and the disclaimer below.
// 
//  - Redistributions in binary form must reproduce the above copyright notice,
//  this list of conditions and the disclaimer below in the documentation and/or
//  other materials provided with the distribution. 
// 
//  Atmel's name may not be used to endorse or promote products derived from
//  this software without specific prior written permission. 
//  
//  DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
//  DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
//  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
//  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//  ----------------------------------------------------------------------------
// File Name           : AT91SAM3X.h
// Object              : AT91SAM3X definitions
// Generated           : AT91 SW Application Group  07/30/2009 (17:07:53)
// 
// CVS Reference       : /AT91SAM3X.pl/1.43/Wed Jul 29 14:44:28 2009//
// CVS Reference       : /ADC_SAM3XE.pl/1.5/Tue Jan 27 13:39:00 2009//
// CVS Reference       : /CORTEX_M3.pl/1.1/Mon Sep 15 15:22:06 2008//
// CVS Reference       : /CORTEX_M3_NVIC.pl/1.8/Fri Jun 19 12:00:55 2009//
// CVS Reference       : /CAN_6019B.pl/1.1/Mon Jan 31 13:54:30 2005//
// CVS Reference       : /DAC_SAM3XE.pl/1.3/Thu Feb  5 08:10:57 2009//
// CVS Reference       : /DBGU_6059D.pl/1.1/Mon Jan 31 13:54:41 2005//
// CVS Reference       : /EBI_SAM9260.pl/1.1/Fri Sep 30 12:12:14 2005//
// CVS Reference       : /EFC2_SAM3UE256.pl/1.3/Mon Mar  2 10:12:06 2009//
// CVS Reference       : /EMACB_SAM9264.pl/1.1/Tue Sep 25 12:07:23 2007//
// CVS Reference       : /HDMA_SAM3X.pl/1.1/Mon Jul 13 18:24:17 2009//
// CVS Reference       : /HMATRIX1_SAM9RL64.pl/1.1/Wed Sep 13 16:29:30 2006//
// CVS Reference       : /CCR_SAM9RL64.pl/1.1/Wed Sep 13 16:29:30 2006//
// CVS Reference       : /MCI_6101F.pl/1.3/Fri Jan 23 09:15:32 2009//
// CVS Reference       : /OTGHS_10ept4dma10iso.pl/1.2/Thu Feb 26 17:09:56 2009//
// CVS Reference       : /PDC_6074C.pl/1.2/Thu Feb  3 09:02:11 2005//
// CVS Reference       : /PIO3_xxxx.pl/1.6/Mon Mar  9 10:43:37 2009//
// CVS Reference       : /PMC_SAM3X.pl/1.3/Thu Feb 19 07:59:39 2009//
// CVS Reference       : /PWM_6343B_V400.pl/1.3/Fri Oct 17 13:27:54 2008//
// CVS Reference       : /RSTC_6098A.pl/1.4/Fri Oct 17 13:27:55 2008//
// CVS Reference       : /RTC_1245D.pl/1.3/Fri Sep 17 14:01:31 2004//
// CVS Reference       : /RTTC_6081A.pl/1.2/Thu Nov  4 13:57:22 2004//
// CVS Reference       : /HSDRAMC1_6100A.pl/1.2/Mon Aug  9 10:52:25 2004//
// CVS Reference       : /HSMC4_xxxx.pl/1.9/Fri Oct 17 13:27:56 2008//
// CVS Reference       : /SPI_6088D.pl/1.3/Fri May 20 14:23:02 2005//
// CVS Reference       : /SSC_6078B.pl/1.3/Fri Oct 17 13:27:57 2008//
// CVS Reference       : /SUPC_SAM3UE256.pl/1.2/Tue May  5 11:29:05 2009//
// CVS Reference       : /SYS_SAM3XE512.pl/1.5/Thu Dec  4 15:14:30 2008//
// CVS Reference       : /TC_6082A.pl/1.8/Fri Oct 17 13:27:58 2008//
// CVS Reference       : /TRNG_xxxxx.pl/1.1/Wed Jul 18 12:02:58 2007//
// CVS Reference       : /TWI_6061B.pl/1.3/Fri Oct 17 13:27:59 2008//
// CVS Reference       : /US_6089J.pl/1.4/Tue Jul  7 12:01:26 2009//
// CVS Reference       : /WDTC_6080A.pl/1.3/Thu Nov  4 13:58:52 2004//
//  ----------------------------------------------------------------------------

#ifndef AT91SAM3X_H
#define AT91SAM3X_H

#ifndef __ASSEMBLY__
typedef volatile unsigned int AT91_REG;// Hardware register definition
#define AT91_CAST(a) (a)
#else
#define AT91_CAST(a)
#endif

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR System Peripherals
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_SYS {
	AT91_REG	 EBI_SRAM_CFG; 	// Configuration Register
	AT91_REG	 EBI_SRAM_CTRL; 	// Control Register
	AT91_REG	 EBI_SRAM_SR; 	// Status Register
	AT91_REG	 EBI_SRAM_IER; 	// Interrupt Enable Register
	AT91_REG	 EBI_SRAM_IDR; 	// Interrupt Disable Register
	AT91_REG	 EBI_SRAM_IMR; 	// Interrupt Mask Register
	AT91_REG	 EBI_SRAM_ADDR; 	// Address Cycle Zero Register
	AT91_REG	 EBI_SRAM_BANK; 	// Bank Register
	AT91_REG	 EBI_SRAM_ECCCR; 	// ECC reset register
	AT91_REG	 EBI_SRAM_ECCCMD; 	// ECC Page size register
	AT91_REG	 EBI_SRAM_ECCSR1; 	// ECC Status register 1
	AT91_REG	 EBI_SRAM_ECCPR0; 	// ECC Parity register 0
	AT91_REG	 EBI_SRAM_ECCPR1; 	// ECC Parity register 1
	AT91_REG	 EBI_SRAM_ECCSR2; 	// ECC Status register 2
	AT91_REG	 EBI_SRAM_ECCPR2; 	// ECC Parity register 2
	AT91_REG	 EBI_SRAM_ECCPR3; 	// ECC Parity register 3
	AT91_REG	 EBI_SRAM_ECCPR4; 	// ECC Parity register 4
	AT91_REG	 EBI_SRAM_ECCPR5; 	// ECC Parity register 5
	AT91_REG	 EBI_SRAM_ECCPR6; 	// ECC Parity register 6
	AT91_REG	 EBI_SRAM_ECCPR7; 	// ECC Parity register 7
	AT91_REG	 EBI_SRAM_ECCPR8; 	// ECC Parity register 8
	AT91_REG	 EBI_SRAM_ECCPR9; 	// ECC Parity register 9
	AT91_REG	 EBI_SRAM_ECCPR10; 	// ECC Parity register 10
	AT91_REG	 EBI_SRAM_ECCPR11; 	// ECC Parity register 11
	AT91_REG	 EBI_SRAM_ECCPR12; 	// ECC Parity register 12
	AT91_REG	 EBI_SRAM_ECCPR13; 	// ECC Parity register 13
	AT91_REG	 EBI_SRAM_ECCPR14; 	// ECC Parity register 14
	AT91_REG	 EBI_SRAM_Eccpr15; 	// ECC Parity register 15
	AT91_REG	 Reserved0[40]; 	// 
	AT91_REG	 EBI_SRAM_OCMS; 	// OCMS MODE register
	AT91_REG	 EBI_SRAM_KEY1; 	// KEY1 Register
	AT91_REG	 EBI_SRAM_KEY2; 	// KEY2 Register
	AT91_REG	 Reserved1[50]; 	// 
	AT91_REG	 EBI_SRAM_WPCR; 	// Write Protection Control register
	AT91_REG	 EBI_SRAM_WPSR; 	// Write Protection Status Register
	AT91_REG	 EBI_SRAM_ADDRSIZE; 	// Write Protection Status Register
	AT91_REG	 EBI_SRAM_IPNAME1; 	// Write Protection Status Register
	AT91_REG	 EBI_SRAM_IPNAME2; 	// Write Protection Status Register
	AT91_REG	 EBI_SRAM_FEATURES; 	// Write Protection Status Register
	AT91_REG	 EBI_SRAM_VER; 	// HSMC4 Version Register
	AT91_REG	 EBI_SDRAM_MR; 	// SDRAM Controller Mode Register
	AT91_REG	 EBI_SDRAM_TR; 	// SDRAM Controller Refresh Timer Register
	AT91_REG	 EBI_SDRAM_CR; 	// SDRAM Controller Configuration Register
	AT91_REG	 EBI_SDRAM_HSR; 	// SDRAM Controller High Speed Register
	AT91_REG	 EBI_SDRAM_LPR; 	// SDRAM Controller Low Power Register
	AT91_REG	 EBI_SDRAM_IER; 	// SDRAM Controller Interrupt Enable Register
	AT91_REG	 EBI_SDRAM_IDR; 	// SDRAM Controller Interrupt Disable Register
	AT91_REG	 EBI_SDRAM_IMR; 	// SDRAM Controller Interrupt Mask Register
	AT91_REG	 EBI_SDRAM_ISR; 	// SDRAM Controller Interrupt Mask Register
	AT91_REG	 EBI_SDRAM_MDR; 	// SDRAM Memory Device Register
	AT91_REG	 Reserved2[118]; 	// 
	AT91_REG	 HMATRIX_MCFG0; 	//  Master Configuration Register 0 : rom
	AT91_REG	 HMATRIX_MCFG1; 	//  Master Configuration Register 1 ; htcm
	AT91_REG	 HMATRIX_MCFG2; 	//  Master Configuration Register 2 : lcdc
	AT91_REG	 HMATRIX_MCFG3; 	//  Master Configuration Register 3 : usb_dev_hs
	AT91_REG	 HMATRIX_MCFG4; 	//  Master Configuration Register 4 : ebi
	AT91_REG	 HMATRIX_MCFG5; 	//  Master Configuration Register 5 : bridge
	AT91_REG	 HMATRIX_MCFG6; 	//  Master Configuration Register 6 
	AT91_REG	 HMATRIX_MCFG7; 	//  Master Configuration Register 7 
	AT91_REG	 HMATRIX_MCFG8; 	//  Master Configuration Register 8 
	AT91_REG	 Reserved3[7]; 	// 
	AT91_REG	 HMATRIX_SCFG0; 	//  Slave Configuration Register 0 : rom
	AT91_REG	 HMATRIX_SCFG1; 	//  Slave Configuration Register 1 : htcm
	AT91_REG	 HMATRIX_SCFG2; 	//  Slave Configuration Register 2 : lcdc
	AT91_REG	 HMATRIX_SCFG3; 	//  Slave Configuration Register 3 : usb_dev_hs
	AT91_REG	 HMATRIX_SCFG4; 	//  Slave Configuration Register 4 ; ebi
	AT91_REG	 HMATRIX_SCFG5; 	//  Slave Configuration Register 5 : bridge
	AT91_REG	 HMATRIX_SCFG6; 	//  Slave Configuration Register 6
	AT91_REG	 HMATRIX_SCFG7; 	//  Slave Configuration Register 7
	AT91_REG	 Reserved4[8]; 	// 
	AT91_REG	 HMATRIX_PRAS0; 	//  PRAS0 : rom
	AT91_REG	 HMATRIX_PRBS0; 	//  PRBS0 : rom
	AT91_REG	 HMATRIX_PRAS1; 	//  PRAS1 : htcm
	AT91_REG	 HMATRIX_PRBS1; 	//  PRBS1 : htcm
	AT91_REG	 HMATRIX_PRAS2; 	//  PRAS2 : lcdc
	AT91_REG	 HMATRIX_PRBS2; 	//  PRBS2 : lcdc
	AT91_REG	 HMATRIX_PRAS3; 	//  PRAS3 : usb_dev_hs
	AT91_REG	 HMATRIX_PRBS3; 	//  PRBS3 : usb_dev_hs
	AT91_REG	 HMATRIX_PRAS4; 	//  PRAS4 : ebi
	AT91_REG	 HMATRIX_PRBS4; 	//  PRBS4 : ebi
	AT91_REG	 HMATRIX_PRAS5; 	//  PRAS5 : bridge
	AT91_REG	 HMATRIX_PRBS5; 	//  PRBS5 : bridge
	AT91_REG	 HMATRIX_PRAS6; 	//  PRAS6
	AT91_REG	 HMATRIX_PRBS6; 	//  PRBS6
	AT91_REG	 HMATRIX_PRAS7; 	//  PRAS7
	AT91_REG	 HMATRIX_PRBS7; 	//  PRBS7
	AT91_REG	 Reserved5[16]; 	// 
	AT91_REG	 HMATRIX_MRCR; 	//  Master Remp Control Register 
	AT91_REG	 Reserved6[63]; 	// 
	AT91_REG	 PMC_SCER; 	// System Clock Enable Register
	AT91_REG	 PMC_SCDR; 	// System Clock Disable Register
	AT91_REG	 PMC_SCSR; 	// System Clock Status Register
	AT91_REG	 Reserved7[1]; 	// 
	AT91_REG	 PMC_PCER; 	// Peripheral Clock Enable Register 0:31 PERI_ID
	AT91_REG	 PMC_PCDR; 	// Peripheral Clock Disable Register 0:31 PERI_ID
	AT91_REG	 PMC_PCSR; 	// Peripheral Clock Status Register 0:31 PERI_ID
	AT91_REG	 PMC_UCKR; 	// UTMI Clock Configuration Register
	AT91_REG	 PMC_MOR; 	// Main Oscillator Register
	AT91_REG	 PMC_MCFR; 	// Main Clock  Frequency Register
	AT91_REG	 PMC_PLLAR; 	// PLL Register
	AT91_REG	 Reserved8[1]; 	// 
	AT91_REG	 PMC_MCKR; 	// Master Clock Register
	AT91_REG	 Reserved9[3]; 	// 
	AT91_REG	 PMC_PCKR[8]; 	// Programmable Clock Register
	AT91_REG	 PMC_IER; 	// Interrupt Enable Register
	AT91_REG	 PMC_IDR; 	// Interrupt Disable Register
	AT91_REG	 PMC_SR; 	// Status Register
	AT91_REG	 PMC_IMR; 	// Interrupt Mask Register
	AT91_REG	 PMC_FSMR; 	// Fast Startup Mode Register
	AT91_REG	 PMC_FSPR; 	// Fast Startup Polarity Register
	AT91_REG	 PMC_FOCR; 	// Fault Output Clear Register
	AT91_REG	 Reserved10[33]; 	// 
	AT91_REG	 PMC_PCER1; 	// Peripheral Clock Enable Register 32:63 PERI_ID
	AT91_REG	 PMC_PCDR1; 	// Peripheral Clock Disable Register 32:63 PERI_ID
	AT91_REG	 PMC_PCSR1; 	// Peripheral Clock Status Register 32:63 PERI_ID
	AT91_REG	 Reserved11[61]; 	// 
	AT91_REG	 DBGU_CR; 	// Control Register
	AT91_REG	 DBGU_MR; 	// Mode Register
	AT91_REG	 DBGU_IER; 	// Interrupt Enable Register
	AT91_REG	 DBGU_IDR; 	// Interrupt Disable Register
	AT91_REG	 DBGU_IMR; 	// Interrupt Mask Register
	AT91_REG	 DBGU_CSR; 	// Channel Status Register
	AT91_REG	 DBGU_RHR; 	// Receiver Holding Register
	AT91_REG	 DBGU_THR; 	// Transmitter Holding Register
	AT91_REG	 DBGU_BRGR; 	// Baud Rate Generator Register
	AT91_REG	 Reserved12[7]; 	// 
	AT91_REG	 DBGU_CIDR; 	// Chip ID Register
	AT91_REG	 DBGU_EXID; 	// Chip ID Extension Register
	AT91_REG	 DBGU_FNTR; 	// Force NTRST Register
	AT91_REG	 Reserved13[45]; 	// 
	AT91_REG	 DBGU_RPR; 	// Receive Pointer Register
	AT91_REG	 DBGU_RCR; 	// Receive Counter Register
	AT91_REG	 DBGU_TPR; 	// Transmit Pointer Register
	AT91_REG	 DBGU_TCR; 	// Transmit Counter Register
	AT91_REG	 DBGU_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 DBGU_RNCR; 	// Receive Next Counter Register
	AT91_REG	 DBGU_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 DBGU_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 DBGU_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 DBGU_PTSR; 	// PDC Transfer Status Register
	AT91_REG	 Reserved14[54]; 	// 
	AT91_REG	 EFC0_FMR; 	// EFC Flash Mode Register
	AT91_REG	 EFC0_FCR; 	// EFC Flash Command Register
	AT91_REG	 EFC0_FSR; 	// EFC Flash Status Register
	AT91_REG	 EFC0_FRR; 	// EFC Flash Result Register
	AT91_REG	 Reserved15[1]; 	// 
	AT91_REG	 EFC0_FVR; 	// EFC Flash Version Register
	AT91_REG	 Reserved16[122]; 	// 
	AT91_REG	 EFC1_FMR; 	// EFC Flash Mode Register
	AT91_REG	 EFC1_FCR; 	// EFC Flash Command Register
	AT91_REG	 EFC1_FSR; 	// EFC Flash Status Register
	AT91_REG	 EFC1_FRR; 	// EFC Flash Result Register
	AT91_REG	 Reserved17[1]; 	// 
	AT91_REG	 EFC1_FVR; 	// EFC Flash Version Register
	AT91_REG	 Reserved18[122]; 	// 
	AT91_REG	 PIOA_PER; 	// PIO Enable Register
	AT91_REG	 PIOA_PDR; 	// PIO Disable Register
	AT91_REG	 PIOA_PSR; 	// PIO Status Register
	AT91_REG	 Reserved19[1]; 	// 
	AT91_REG	 PIOA_OER; 	// Output Enable Register
	AT91_REG	 PIOA_ODR; 	// Output Disable Registerr
	AT91_REG	 PIOA_OSR; 	// Output Status Register
	AT91_REG	 Reserved20[1]; 	// 
	AT91_REG	 PIOA_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIOA_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIOA_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved21[1]; 	// 
	AT91_REG	 PIOA_SODR; 	// Set Output Data Register
	AT91_REG	 PIOA_CODR; 	// Clear Output Data Register
	AT91_REG	 PIOA_ODSR; 	// Output Data Status Register
	AT91_REG	 PIOA_PDSR; 	// Pin Data Status Register
	AT91_REG	 PIOA_IER; 	// Interrupt Enable Register
	AT91_REG	 PIOA_IDR; 	// Interrupt Disable Register
	AT91_REG	 PIOA_IMR; 	// Interrupt Mask Register
	AT91_REG	 PIOA_ISR; 	// Interrupt Status Register
	AT91_REG	 PIOA_MDER; 	// Multi-driver Enable Register
	AT91_REG	 PIOA_MDDR; 	// Multi-driver Disable Register
	AT91_REG	 PIOA_MDSR; 	// Multi-driver Status Register
	AT91_REG	 Reserved22[1]; 	// 
	AT91_REG	 PIOA_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIOA_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIOA_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved23[1]; 	// 
	AT91_REG	 PIOA_ABSR; 	// Peripheral AB Select Register
	AT91_REG	 Reserved24[3]; 	// 
	AT91_REG	 PIOA_SCIFSR; 	// System Clock Glitch Input Filter Select Register
	AT91_REG	 PIOA_DIFSR; 	// Debouncing Input Filter Select Register
	AT91_REG	 PIOA_IFDGSR; 	// Glitch or Debouncing Input Filter Clock Selection Status Register
	AT91_REG	 PIOA_SCDR; 	// Slow Clock Divider Debouncing Register
	AT91_REG	 Reserved25[4]; 	// 
	AT91_REG	 PIOA_OWER; 	// Output Write Enable Register
	AT91_REG	 PIOA_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIOA_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved26[1]; 	// 
	AT91_REG	 PIOA_AIMER; 	// Additional Interrupt Modes Enable Register
	AT91_REG	 PIOA_AIMDR; 	// Additional Interrupt Modes Disables Register
	AT91_REG	 PIOA_AIMMR; 	// Additional Interrupt Modes Mask Register
	AT91_REG	 Reserved27[1]; 	// 
	AT91_REG	 PIOA_ESR; 	// Edge Select Register
	AT91_REG	 PIOA_LSR; 	// Level Select Register
	AT91_REG	 PIOA_ELSR; 	// Edge/Level Status Register
	AT91_REG	 Reserved28[1]; 	// 
	AT91_REG	 PIOA_FELLSR; 	// Falling Edge/Low Level Select Register
	AT91_REG	 PIOA_REHLSR; 	// Rising Edge/ High Level Select Register
	AT91_REG	 PIOA_FRLHSR; 	// Fall/Rise - Low/High Status Register
	AT91_REG	 Reserved29[1]; 	// 
	AT91_REG	 PIOA_LOCKSR; 	// Lock Status Register
	AT91_REG	 Reserved30[6]; 	// 
	AT91_REG	 PIOA_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 Reserved31[8]; 	// 
	AT91_REG	 PIOA_KER; 	// Keypad Controller Enable Register
	AT91_REG	 PIOA_KRCR; 	// Keypad Controller Row Column Register
	AT91_REG	 PIOA_KDR; 	// Keypad Controller Debouncing Register
	AT91_REG	 Reserved32[1]; 	// 
	AT91_REG	 PIOA_KIER; 	// Keypad Controller Interrupt Enable Register
	AT91_REG	 PIOA_KIDR; 	// Keypad Controller Interrupt Disable Register
	AT91_REG	 PIOA_KIMR; 	// Keypad Controller Interrupt Mask Register
	AT91_REG	 PIOA_KSR; 	// Keypad Controller Status Register
	AT91_REG	 PIOA_KKPR; 	// Keypad Controller Key Press Register
	AT91_REG	 PIOA_KKRR; 	// Keypad Controller Key Release Register
	AT91_REG	 Reserved33[46]; 	// 
	AT91_REG	 PIOB_PER; 	// PIO Enable Register
	AT91_REG	 PIOB_PDR; 	// PIO Disable Register
	AT91_REG	 PIOB_PSR; 	// PIO Status Register
	AT91_REG	 Reserved34[1]; 	// 
	AT91_REG	 PIOB_OER; 	// Output Enable Register
	AT91_REG	 PIOB_ODR; 	// Output Disable Registerr
	AT91_REG	 PIOB_OSR; 	// Output Status Register
	AT91_REG	 Reserved35[1]; 	// 
	AT91_REG	 PIOB_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIOB_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIOB_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved36[1]; 	// 
	AT91_REG	 PIOB_SODR; 	// Set Output Data Register
	AT91_REG	 PIOB_CODR; 	// Clear Output Data Register
	AT91_REG	 PIOB_ODSR; 	// Output Data Status Register
	AT91_REG	 PIOB_PDSR; 	// Pin Data Status Register
	AT91_REG	 PIOB_IER; 	// Interrupt Enable Register
	AT91_REG	 PIOB_IDR; 	// Interrupt Disable Register
	AT91_REG	 PIOB_IMR; 	// Interrupt Mask Register
	AT91_REG	 PIOB_ISR; 	// Interrupt Status Register
	AT91_REG	 PIOB_MDER; 	// Multi-driver Enable Register
	AT91_REG	 PIOB_MDDR; 	// Multi-driver Disable Register
	AT91_REG	 PIOB_MDSR; 	// Multi-driver Status Register
	AT91_REG	 Reserved37[1]; 	// 
	AT91_REG	 PIOB_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIOB_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIOB_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved38[1]; 	// 
	AT91_REG	 PIOB_ABSR; 	// Peripheral AB Select Register
	AT91_REG	 Reserved39[3]; 	// 
	AT91_REG	 PIOB_SCIFSR; 	// System Clock Glitch Input Filter Select Register
	AT91_REG	 PIOB_DIFSR; 	// Debouncing Input Filter Select Register
	AT91_REG	 PIOB_IFDGSR; 	// Glitch or Debouncing Input Filter Clock Selection Status Register
	AT91_REG	 PIOB_SCDR; 	// Slow Clock Divider Debouncing Register
	AT91_REG	 Reserved40[4]; 	// 
	AT91_REG	 PIOB_OWER; 	// Output Write Enable Register
	AT91_REG	 PIOB_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIOB_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved41[1]; 	// 
	AT91_REG	 PIOB_AIMER; 	// Additional Interrupt Modes Enable Register
	AT91_REG	 PIOB_AIMDR; 	// Additional Interrupt Modes Disables Register
	AT91_REG	 PIOB_AIMMR; 	// Additional Interrupt Modes Mask Register
	AT91_REG	 Reserved42[1]; 	// 
	AT91_REG	 PIOB_ESR; 	// Edge Select Register
	AT91_REG	 PIOB_LSR; 	// Level Select Register
	AT91_REG	 PIOB_ELSR; 	// Edge/Level Status Register
	AT91_REG	 Reserved43[1]; 	// 
	AT91_REG	 PIOB_FELLSR; 	// Falling Edge/Low Level Select Register
	AT91_REG	 PIOB_REHLSR; 	// Rising Edge/ High Level Select Register
	AT91_REG	 PIOB_FRLHSR; 	// Fall/Rise - Low/High Status Register
	AT91_REG	 Reserved44[1]; 	// 
	AT91_REG	 PIOB_LOCKSR; 	// Lock Status Register
	AT91_REG	 Reserved45[6]; 	// 
	AT91_REG	 PIOB_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 Reserved46[8]; 	// 
	AT91_REG	 PIOB_KER; 	// Keypad Controller Enable Register
	AT91_REG	 PIOB_KRCR; 	// Keypad Controller Row Column Register
	AT91_REG	 PIOB_KDR; 	// Keypad Controller Debouncing Register
	AT91_REG	 Reserved47[1]; 	// 
	AT91_REG	 PIOB_KIER; 	// Keypad Controller Interrupt Enable Register
	AT91_REG	 PIOB_KIDR; 	// Keypad Controller Interrupt Disable Register
	AT91_REG	 PIOB_KIMR; 	// Keypad Controller Interrupt Mask Register
	AT91_REG	 PIOB_KSR; 	// Keypad Controller Status Register
	AT91_REG	 PIOB_KKPR; 	// Keypad Controller Key Press Register
	AT91_REG	 PIOB_KKRR; 	// Keypad Controller Key Release Register
	AT91_REG	 Reserved48[46]; 	// 
	AT91_REG	 PIOC_PER; 	// PIO Enable Register
	AT91_REG	 PIOC_PDR; 	// PIO Disable Register
	AT91_REG	 PIOC_PSR; 	// PIO Status Register
	AT91_REG	 Reserved49[1]; 	// 
	AT91_REG	 PIOC_OER; 	// Output Enable Register
	AT91_REG	 PIOC_ODR; 	// Output Disable Registerr
	AT91_REG	 PIOC_OSR; 	// Output Status Register
	AT91_REG	 Reserved50[1]; 	// 
	AT91_REG	 PIOC_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIOC_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIOC_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved51[1]; 	// 
	AT91_REG	 PIOC_SODR; 	// Set Output Data Register
	AT91_REG	 PIOC_CODR; 	// Clear Output Data Register
	AT91_REG	 PIOC_ODSR; 	// Output Data Status Register
	AT91_REG	 PIOC_PDSR; 	// Pin Data Status Register
	AT91_REG	 PIOC_IER; 	// Interrupt Enable Register
	AT91_REG	 PIOC_IDR; 	// Interrupt Disable Register
	AT91_REG	 PIOC_IMR; 	// Interrupt Mask Register
	AT91_REG	 PIOC_ISR; 	// Interrupt Status Register
	AT91_REG	 PIOC_MDER; 	// Multi-driver Enable Register
	AT91_REG	 PIOC_MDDR; 	// Multi-driver Disable Register
	AT91_REG	 PIOC_MDSR; 	// Multi-driver Status Register
	AT91_REG	 Reserved52[1]; 	// 
	AT91_REG	 PIOC_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIOC_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIOC_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved53[1]; 	// 
	AT91_REG	 PIOC_ABSR; 	// Peripheral AB Select Register
	AT91_REG	 Reserved54[3]; 	// 
	AT91_REG	 PIOC_SCIFSR; 	// System Clock Glitch Input Filter Select Register
	AT91_REG	 PIOC_DIFSR; 	// Debouncing Input Filter Select Register
	AT91_REG	 PIOC_IFDGSR; 	// Glitch or Debouncing Input Filter Clock Selection Status Register
	AT91_REG	 PIOC_SCDR; 	// Slow Clock Divider Debouncing Register
	AT91_REG	 Reserved55[4]; 	// 
	AT91_REG	 PIOC_OWER; 	// Output Write Enable Register
	AT91_REG	 PIOC_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIOC_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved56[1]; 	// 
	AT91_REG	 PIOC_AIMER; 	// Additional Interrupt Modes Enable Register
	AT91_REG	 PIOC_AIMDR; 	// Additional Interrupt Modes Disables Register
	AT91_REG	 PIOC_AIMMR; 	// Additional Interrupt Modes Mask Register
	AT91_REG	 Reserved57[1]; 	// 
	AT91_REG	 PIOC_ESR; 	// Edge Select Register
	AT91_REG	 PIOC_LSR; 	// Level Select Register
	AT91_REG	 PIOC_ELSR; 	// Edge/Level Status Register
	AT91_REG	 Reserved58[1]; 	// 
	AT91_REG	 PIOC_FELLSR; 	// Falling Edge/Low Level Select Register
	AT91_REG	 PIOC_REHLSR; 	// Rising Edge/ High Level Select Register
	AT91_REG	 PIOC_FRLHSR; 	// Fall/Rise - Low/High Status Register
	AT91_REG	 Reserved59[1]; 	// 
	AT91_REG	 PIOC_LOCKSR; 	// Lock Status Register
	AT91_REG	 Reserved60[6]; 	// 
	AT91_REG	 PIOC_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 Reserved61[8]; 	// 
	AT91_REG	 PIOC_KER; 	// Keypad Controller Enable Register
	AT91_REG	 PIOC_KRCR; 	// Keypad Controller Row Column Register
	AT91_REG	 PIOC_KDR; 	// Keypad Controller Debouncing Register
	AT91_REG	 Reserved62[1]; 	// 
	AT91_REG	 PIOC_KIER; 	// Keypad Controller Interrupt Enable Register
	AT91_REG	 PIOC_KIDR; 	// Keypad Controller Interrupt Disable Register
	AT91_REG	 PIOC_KIMR; 	// Keypad Controller Interrupt Mask Register
	AT91_REG	 PIOC_KSR; 	// Keypad Controller Status Register
	AT91_REG	 PIOC_KKPR; 	// Keypad Controller Key Press Register
	AT91_REG	 PIOC_KKRR; 	// Keypad Controller Key Release Register
	AT91_REG	 Reserved63[46]; 	// 
	AT91_REG	 PIOD_PER; 	// PIO Enable Register
	AT91_REG	 PIOD_PDR; 	// PIO Disable Register
	AT91_REG	 PIOD_PSR; 	// PIO Status Register
	AT91_REG	 Reserved64[1]; 	// 
	AT91_REG	 PIOD_OER; 	// Output Enable Register
	AT91_REG	 PIOD_ODR; 	// Output Disable Registerr
	AT91_REG	 PIOD_OSR; 	// Output Status Register
	AT91_REG	 Reserved65[1]; 	// 
	AT91_REG	 PIOD_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIOD_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIOD_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved66[1]; 	// 
	AT91_REG	 PIOD_SODR; 	// Set Output Data Register
	AT91_REG	 PIOD_CODR; 	// Clear Output Data Register
	AT91_REG	 PIOD_ODSR; 	// Output Data Status Register
	AT91_REG	 PIOD_PDSR; 	// Pin Data Status Register
	AT91_REG	 PIOD_IER; 	// Interrupt Enable Register
	AT91_REG	 PIOD_IDR; 	// Interrupt Disable Register
	AT91_REG	 PIOD_IMR; 	// Interrupt Mask Register
	AT91_REG	 PIOD_ISR; 	// Interrupt Status Register
	AT91_REG	 PIOD_MDER; 	// Multi-driver Enable Register
	AT91_REG	 PIOD_MDDR; 	// Multi-driver Disable Register
	AT91_REG	 PIOD_MDSR; 	// Multi-driver Status Register
	AT91_REG	 Reserved67[1]; 	// 
	AT91_REG	 PIOD_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIOD_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIOD_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved68[1]; 	// 
	AT91_REG	 PIOD_ABSR; 	// Peripheral AB Select Register
	AT91_REG	 Reserved69[3]; 	// 
	AT91_REG	 PIOD_SCIFSR; 	// System Clock Glitch Input Filter Select Register
	AT91_REG	 PIOD_DIFSR; 	// Debouncing Input Filter Select Register
	AT91_REG	 PIOD_IFDGSR; 	// Glitch or Debouncing Input Filter Clock Selection Status Register
	AT91_REG	 PIOD_SCDR; 	// Slow Clock Divider Debouncing Register
	AT91_REG	 Reserved70[4]; 	// 
	AT91_REG	 PIOD_OWER; 	// Output Write Enable Register
	AT91_REG	 PIOD_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIOD_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved71[1]; 	// 
	AT91_REG	 PIOD_AIMER; 	// Additional Interrupt Modes Enable Register
	AT91_REG	 PIOD_AIMDR; 	// Additional Interrupt Modes Disables Register
	AT91_REG	 PIOD_AIMMR; 	// Additional Interrupt Modes Mask Register
	AT91_REG	 Reserved72[1]; 	// 
	AT91_REG	 PIOD_ESR; 	// Edge Select Register
	AT91_REG	 PIOD_LSR; 	// Level Select Register
	AT91_REG	 PIOD_ELSR; 	// Edge/Level Status Register
	AT91_REG	 Reserved73[1]; 	// 
	AT91_REG	 PIOD_FELLSR; 	// Falling Edge/Low Level Select Register
	AT91_REG	 PIOD_REHLSR; 	// Rising Edge/ High Level Select Register
	AT91_REG	 PIOD_FRLHSR; 	// Fall/Rise - Low/High Status Register
	AT91_REG	 Reserved74[1]; 	// 
	AT91_REG	 PIOD_LOCKSR; 	// Lock Status Register
	AT91_REG	 Reserved75[6]; 	// 
	AT91_REG	 PIOD_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 Reserved76[8]; 	// 
	AT91_REG	 PIOD_KER; 	// Keypad Controller Enable Register
	AT91_REG	 PIOD_KRCR; 	// Keypad Controller Row Column Register
	AT91_REG	 PIOD_KDR; 	// Keypad Controller Debouncing Register
	AT91_REG	 Reserved77[1]; 	// 
	AT91_REG	 PIOD_KIER; 	// Keypad Controller Interrupt Enable Register
	AT91_REG	 PIOD_KIDR; 	// Keypad Controller Interrupt Disable Register
	AT91_REG	 PIOD_KIMR; 	// Keypad Controller Interrupt Mask Register
	AT91_REG	 PIOD_KSR; 	// Keypad Controller Status Register
	AT91_REG	 PIOD_KKPR; 	// Keypad Controller Key Press Register
	AT91_REG	 PIOD_KKRR; 	// Keypad Controller Key Release Register
	AT91_REG	 Reserved78[46]; 	// 
	AT91_REG	 PIOE_PER; 	// PIO Enable Register
	AT91_REG	 PIOE_PDR; 	// PIO Disable Register
	AT91_REG	 PIOE_PSR; 	// PIO Status Register
	AT91_REG	 Reserved79[1]; 	// 
	AT91_REG	 PIOE_OER; 	// Output Enable Register
	AT91_REG	 PIOE_ODR; 	// Output Disable Registerr
	AT91_REG	 PIOE_OSR; 	// Output Status Register
	AT91_REG	 Reserved80[1]; 	// 
	AT91_REG	 PIOE_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIOE_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIOE_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved81[1]; 	// 
	AT91_REG	 PIOE_SODR; 	// Set Output Data Register
	AT91_REG	 PIOE_CODR; 	// Clear Output Data Register
	AT91_REG	 PIOE_ODSR; 	// Output Data Status Register
	AT91_REG	 PIOE_PDSR; 	// Pin Data Status Register
	AT91_REG	 PIOE_IER; 	// Interrupt Enable Register
	AT91_REG	 PIOE_IDR; 	// Interrupt Disable Register
	AT91_REG	 PIOE_IMR; 	// Interrupt Mask Register
	AT91_REG	 PIOE_ISR; 	// Interrupt Status Register
	AT91_REG	 PIOE_MDER; 	// Multi-driver Enable Register
	AT91_REG	 PIOE_MDDR; 	// Multi-driver Disable Register
	AT91_REG	 PIOE_MDSR; 	// Multi-driver Status Register
	AT91_REG	 Reserved82[1]; 	// 
	AT91_REG	 PIOE_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIOE_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIOE_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved83[1]; 	// 
	AT91_REG	 PIOE_ABSR; 	// Peripheral AB Select Register
	AT91_REG	 Reserved84[3]; 	// 
	AT91_REG	 PIOE_SCIFSR; 	// System Clock Glitch Input Filter Select Register
	AT91_REG	 PIOE_DIFSR; 	// Debouncing Input Filter Select Register
	AT91_REG	 PIOE_IFDGSR; 	// Glitch or Debouncing Input Filter Clock Selection Status Register
	AT91_REG	 PIOE_SCDR; 	// Slow Clock Divider Debouncing Register
	AT91_REG	 Reserved85[4]; 	// 
	AT91_REG	 PIOE_OWER; 	// Output Write Enable Register
	AT91_REG	 PIOE_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIOE_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved86[1]; 	// 
	AT91_REG	 PIOE_AIMER; 	// Additional Interrupt Modes Enable Register
	AT91_REG	 PIOE_AIMDR; 	// Additional Interrupt Modes Disables Register
	AT91_REG	 PIOE_AIMMR; 	// Additional Interrupt Modes Mask Register
	AT91_REG	 Reserved87[1]; 	// 
	AT91_REG	 PIOE_ESR; 	// Edge Select Register
	AT91_REG	 PIOE_LSR; 	// Level Select Register
	AT91_REG	 PIOE_ELSR; 	// Edge/Level Status Register
	AT91_REG	 Reserved88[1]; 	// 
	AT91_REG	 PIOE_FELLSR; 	// Falling Edge/Low Level Select Register
	AT91_REG	 PIOE_REHLSR; 	// Rising Edge/ High Level Select Register
	AT91_REG	 PIOE_FRLHSR; 	// Fall/Rise - Low/High Status Register
	AT91_REG	 Reserved89[1]; 	// 
	AT91_REG	 PIOE_LOCKSR; 	// Lock Status Register
	AT91_REG	 Reserved90[6]; 	// 
	AT91_REG	 PIOE_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 Reserved91[8]; 	// 
	AT91_REG	 PIOE_KER; 	// Keypad Controller Enable Register
	AT91_REG	 PIOE_KRCR; 	// Keypad Controller Row Column Register
	AT91_REG	 PIOE_KDR; 	// Keypad Controller Debouncing Register
	AT91_REG	 Reserved92[1]; 	// 
	AT91_REG	 PIOE_KIER; 	// Keypad Controller Interrupt Enable Register
	AT91_REG	 PIOE_KIDR; 	// Keypad Controller Interrupt Disable Register
	AT91_REG	 PIOE_KIMR; 	// Keypad Controller Interrupt Mask Register
	AT91_REG	 PIOE_KSR; 	// Keypad Controller Status Register
	AT91_REG	 PIOE_KKPR; 	// Keypad Controller Key Press Register
	AT91_REG	 PIOE_KKRR; 	// Keypad Controller Key Release Register
	AT91_REG	 Reserved93[46]; 	// 
	AT91_REG	 PIOF_PER; 	// PIO Enable Register
	AT91_REG	 PIOF_PDR; 	// PIO Disable Register
	AT91_REG	 PIOF_PSR; 	// PIO Status Register
	AT91_REG	 Reserved94[1]; 	// 
	AT91_REG	 PIOF_OER; 	// Output Enable Register
	AT91_REG	 PIOF_ODR; 	// Output Disable Registerr
	AT91_REG	 PIOF_OSR; 	// Output Status Register
	AT91_REG	 Reserved95[1]; 	// 
	AT91_REG	 PIOF_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIOF_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIOF_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved96[1]; 	// 
	AT91_REG	 PIOF_SODR; 	// Set Output Data Register
	AT91_REG	 PIOF_CODR; 	// Clear Output Data Register
	AT91_REG	 PIOF_ODSR; 	// Output Data Status Register
	AT91_REG	 PIOF_PDSR; 	// Pin Data Status Register
	AT91_REG	 PIOF_IER; 	// Interrupt Enable Register
	AT91_REG	 PIOF_IDR; 	// Interrupt Disable Register
	AT91_REG	 PIOF_IMR; 	// Interrupt Mask Register
	AT91_REG	 PIOF_ISR; 	// Interrupt Status Register
	AT91_REG	 PIOF_MDER; 	// Multi-driver Enable Register
	AT91_REG	 PIOF_MDDR; 	// Multi-driver Disable Register
	AT91_REG	 PIOF_MDSR; 	// Multi-driver Status Register
	AT91_REG	 Reserved97[1]; 	// 
	AT91_REG	 PIOF_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIOF_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIOF_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved98[1]; 	// 
	AT91_REG	 PIOF_ABSR; 	// Peripheral AB Select Register
	AT91_REG	 Reserved99[3]; 	// 
	AT91_REG	 PIOF_SCIFSR; 	// System Clock Glitch Input Filter Select Register
	AT91_REG	 PIOF_DIFSR; 	// Debouncing Input Filter Select Register
	AT91_REG	 PIOF_IFDGSR; 	// Glitch or Debouncing Input Filter Clock Selection Status Register
	AT91_REG	 PIOF_SCDR; 	// Slow Clock Divider Debouncing Register
	AT91_REG	 Reserved100[4]; 	// 
	AT91_REG	 PIOF_OWER; 	// Output Write Enable Register
	AT91_REG	 PIOF_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIOF_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved101[1]; 	// 
	AT91_REG	 PIOF_AIMER; 	// Additional Interrupt Modes Enable Register
	AT91_REG	 PIOF_AIMDR; 	// Additional Interrupt Modes Disables Register
	AT91_REG	 PIOF_AIMMR; 	// Additional Interrupt Modes Mask Register
	AT91_REG	 Reserved102[1]; 	// 
	AT91_REG	 PIOF_ESR; 	// Edge Select Register
	AT91_REG	 PIOF_LSR; 	// Level Select Register
	AT91_REG	 PIOF_ELSR; 	// Edge/Level Status Register
	AT91_REG	 Reserved103[1]; 	// 
	AT91_REG	 PIOF_FELLSR; 	// Falling Edge/Low Level Select Register
	AT91_REG	 PIOF_REHLSR; 	// Rising Edge/ High Level Select Register
	AT91_REG	 PIOF_FRLHSR; 	// Fall/Rise - Low/High Status Register
	AT91_REG	 Reserved104[1]; 	// 
	AT91_REG	 PIOF_LOCKSR; 	// Lock Status Register
	AT91_REG	 Reserved105[6]; 	// 
	AT91_REG	 PIOF_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 Reserved106[8]; 	// 
	AT91_REG	 PIOF_KER; 	// Keypad Controller Enable Register
	AT91_REG	 PIOF_KRCR; 	// Keypad Controller Row Column Register
	AT91_REG	 PIOF_KDR; 	// Keypad Controller Debouncing Register
	AT91_REG	 Reserved107[1]; 	// 
	AT91_REG	 PIOF_KIER; 	// Keypad Controller Interrupt Enable Register
	AT91_REG	 PIOF_KIDR; 	// Keypad Controller Interrupt Disable Register
	AT91_REG	 PIOF_KIMR; 	// Keypad Controller Interrupt Mask Register
	AT91_REG	 PIOF_KSR; 	// Keypad Controller Status Register
	AT91_REG	 PIOF_KKPR; 	// Keypad Controller Key Press Register
	AT91_REG	 PIOF_KKRR; 	// Keypad Controller Key Release Register
	AT91_REG	 Reserved108[46]; 	// 
	AT91_REG	 RSTC_RCR; 	// Reset Control Register
	AT91_REG	 RSTC_RSR; 	// Reset Status Register
	AT91_REG	 RSTC_RMR; 	// Reset Mode Register
	AT91_REG	 Reserved109[1]; 	// 
	AT91_REG	 SUPC_CR; 	// Control Register
	AT91_REG	 SUPC_BOMR; 	// Brown Out Mode Register
	AT91_REG	 SUPC_MR; 	// Mode Register
	AT91_REG	 SUPC_WUMR; 	// Wake Up Mode Register
	AT91_REG	 SUPC_WUIR; 	// Wake Up Inputs Register
	AT91_REG	 SUPC_SR; 	// Status Register
	AT91_REG	 SUPC_FWUTR; 	// Flash Wake-up Timer Register
	AT91_REG	 Reserved110[1]; 	// 
	AT91_REG	 RTTC_RTMR; 	// Real-time Mode Register
	AT91_REG	 RTTC_RTAR; 	// Real-time Alarm Register
	AT91_REG	 RTTC_RTVR; 	// Real-time Value Register
	AT91_REG	 RTTC_RTSR; 	// Real-time Status Register
	AT91_REG	 Reserved111[4]; 	// 
	AT91_REG	 WDTC_WDCR; 	// Watchdog Control Register
	AT91_REG	 WDTC_WDMR; 	// Watchdog Mode Register
	AT91_REG	 WDTC_WDSR; 	// Watchdog Status Register
	AT91_REG	 Reserved112[1]; 	// 
	AT91_REG	 RTC_CR; 	// Control Register
	AT91_REG	 RTC_MR; 	// Mode Register
	AT91_REG	 RTC_TIMR; 	// Time Register
	AT91_REG	 RTC_CALR; 	// Calendar Register
	AT91_REG	 RTC_TIMALR; 	// Time Alarm Register
	AT91_REG	 RTC_CALALR; 	// Calendar Alarm Register
	AT91_REG	 RTC_SR; 	// Status Register
	AT91_REG	 RTC_SCCR; 	// Status Clear Command Register
	AT91_REG	 RTC_IER; 	// Interrupt Enable Register
	AT91_REG	 RTC_IDR; 	// Interrupt Disable Register
	AT91_REG	 RTC_IMR; 	// Interrupt Mask Register
	AT91_REG	 RTC_VER; 	// Valid Entry Register
	AT91_REG	 SYS_GPBR[8]; 	// General Purpose Registers
	AT91_REG	 Reserved113[19]; 	// 
	AT91_REG	 RSTC_VER; 	// Version Register
} AT91S_SYS, *AT91PS_SYS;
#else
#define SYS_GPBR        (AT91_CAST(AT91_REG *) 	0x00001A90) // (SYS_GPBR) General Purpose Registers

#endif
// -------- GPBR : (SYS Offset: 0x1a90) GPBR General Purpose Register -------- 
#define AT91C_GPBR_GPRV       (0x0 <<  0) // (SYS) General Purpose Register Value

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR External Bus Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_EBI {
	AT91_REG	 EBI_DUMMY; 	// Dummy register - Do not use
} AT91S_EBI, *AT91PS_EBI;
#else
#define EBI_DUMMY       (AT91_CAST(AT91_REG *) 	0x00000000) // (EBI_DUMMY) Dummy register - Do not use

#endif

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR HSMC4 Chip Select interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_HSMC4_CS {
	AT91_REG	 HSMC4_SETUP; 	// Setup Register
	AT91_REG	 HSMC4_PULSE; 	// Pulse Register
	AT91_REG	 HSMC4_CYCLE; 	// Cycle Register
	AT91_REG	 HSMC4_TIMINGS; 	// Timmings Register
	AT91_REG	 HSMC4_MODE; 	// Mode Register
} AT91S_HSMC4_CS, *AT91PS_HSMC4_CS;
#else
#define HSMC4_SETUP     (AT91_CAST(AT91_REG *) 	0x00000000) // (HSMC4_SETUP) Setup Register
#define HSMC4_PULSE     (AT91_CAST(AT91_REG *) 	0x00000004) // (HSMC4_PULSE) Pulse Register
#define HSMC4_CYCLE     (AT91_CAST(AT91_REG *) 	0x00000008) // (HSMC4_CYCLE) Cycle Register
#define HSMC4_TIMINGS   (AT91_CAST(AT91_REG *) 	0x0000000C) // (HSMC4_TIMINGS) Timmings Register
#define HSMC4_MODE      (AT91_CAST(AT91_REG *) 	0x00000010) // (HSMC4_MODE) Mode Register

#endif
// -------- HSMC4_SETUP : (HSMC4_CS Offset: 0x0) HSMC4 SETUP -------- 
#define AT91C_HSMC4_NWE_SETUP (0x3F <<  0) // (HSMC4_CS) NWE Setup length
#define AT91C_HSMC4_NCS_WR_SETUP (0x3F <<  8) // (HSMC4_CS) NCS Setup length in Write access
#define AT91C_HSMC4_NRD_SETUP (0x3F << 16) // (HSMC4_CS) NRD Setup length
#define AT91C_HSMC4_NCS_RD_SETUP (0x3F << 24) // (HSMC4_CS) NCS Setup legnth in Read access
// -------- HSMC4_PULSE : (HSMC4_CS Offset: 0x4) HSMC4 PULSE -------- 
#define AT91C_HSMC4_NWE_PULSE (0x3F <<  0) // (HSMC4_CS) NWE Pulse Length
#define AT91C_HSMC4_NCS_WR_PULSE (0x3F <<  8) // (HSMC4_CS) NCS Pulse length in WRITE access
#define AT91C_HSMC4_NRD_PULSE (0x3F << 16) // (HSMC4_CS) NRD Pulse length
#define AT91C_HSMC4_NCS_RD_PULSE (0x3F << 24) // (HSMC4_CS) NCS Pulse length in READ access
// -------- HSMC4_CYCLE : (HSMC4_CS Offset: 0x8) HSMC4 CYCLE -------- 
#define AT91C_HSMC4_NWE_CYCLE (0x1FF <<  0) // (HSMC4_CS) Total Write Cycle Length
#define AT91C_HSMC4_NRD_CYCLE (0x1FF << 16) // (HSMC4_CS) Total Read Cycle Length
// -------- HSMC4_TIMINGS : (HSMC4_CS Offset: 0xc) HSMC4 TIMINGS -------- 
#define AT91C_HSMC4_TCLR      (0xF <<  0) // (HSMC4_CS) CLE to REN low delay
#define AT91C_HSMC4_TADL      (0xF <<  4) // (HSMC4_CS) ALE to data start
#define AT91C_HSMC4_TAR       (0xF <<  8) // (HSMC4_CS) ALE to REN low delay
#define AT91C_HSMC4_OCMSEN    (0x1 << 12) // (HSMC4_CS) Off Chip Memory Scrambling Enable
#define AT91C_HSMC4_TRR       (0xF << 16) // (HSMC4_CS) Ready to REN low delay
#define AT91C_HSMC4_TWB       (0xF << 24) // (HSMC4_CS) WEN high to REN to busy
#define AT91C_HSMC4_RBNSEL    (0x7 << 28) // (HSMC4_CS) Ready/Busy Line Selection
#define AT91C_HSMC4_NFSEL     (0x1 << 31) // (HSMC4_CS) Nand Flash Selection
// -------- HSMC4_MODE : (HSMC4_CS Offset: 0x10) HSMC4 MODE -------- 
#define AT91C_HSMC4_READ_MODE (0x1 <<  0) // (HSMC4_CS) Read Mode
#define AT91C_HSMC4_WRITE_MODE (0x1 <<  1) // (HSMC4_CS) Write Mode
#define AT91C_HSMC4_EXNW_MODE (0x3 <<  4) // (HSMC4_CS) NWAIT Mode
#define 	AT91C_HSMC4_EXNW_MODE_NWAIT_DISABLE        (0x0 <<  4) // (HSMC4_CS) External NWAIT disabled.
#define 	AT91C_HSMC4_EXNW_MODE_NWAIT_ENABLE_FROZEN  (0x2 <<  4) // (HSMC4_CS) External NWAIT enabled in frozen mode.
#define 	AT91C_HSMC4_EXNW_MODE_NWAIT_ENABLE_READY   (0x3 <<  4) // (HSMC4_CS) External NWAIT enabled in ready mode.
#define AT91C_HSMC4_BAT       (0x1 <<  8) // (HSMC4_CS) Byte Access Type
#define 	AT91C_HSMC4_BAT_BYTE_SELECT          (0x0 <<  8) // (HSMC4_CS) Write controled by ncs, nbs0, nbs1, nbs2, nbs3. Read controled by ncs, nrd, nbs0, nbs1, nbs2, nbs3.
#define 	AT91C_HSMC4_BAT_BYTE_WRITE           (0x1 <<  8) // (HSMC4_CS) Write controled by ncs, nwe0, nwe1, nwe2, nwe3. Read controled by ncs and nrd.
#define AT91C_HSMC4_DBW       (0x3 << 12) // (HSMC4_CS) Data Bus Width
#define 	AT91C_HSMC4_DBW_WIDTH_EIGTH_BITS     (0x0 << 12) // (HSMC4_CS) 8 bits.
#define 	AT91C_HSMC4_DBW_WIDTH_SIXTEEN_BITS   (0x1 << 12) // (HSMC4_CS) 16 bits.
#define 	AT91C_HSMC4_DBW_WIDTH_THIRTY_TWO_BITS (0x2 << 12) // (HSMC4_CS) 32 bits.
#define AT91C_HSMC4_TDF_CYCLES (0xF << 16) // (HSMC4_CS) Data Float Time.
#define AT91C_HSMC4_TDF_MODE  (0x1 << 20) // (HSMC4_CS) TDF Enabled.
#define AT91C_HSMC4_PMEN      (0x1 << 24) // (HSMC4_CS) Page Mode Enabled.
#define AT91C_HSMC4_PS        (0x3 << 28) // (HSMC4_CS) Page Size
#define 	AT91C_HSMC4_PS_SIZE_FOUR_BYTES      (0x0 << 28) // (HSMC4_CS) 4 bytes.
#define 	AT91C_HSMC4_PS_SIZE_EIGHT_BYTES     (0x1 << 28) // (HSMC4_CS) 8 bytes.
#define 	AT91C_HSMC4_PS_SIZE_SIXTEEN_BYTES   (0x2 << 28) // (HSMC4_CS) 16 bytes.
#define 	AT91C_HSMC4_PS_SIZE_THIRTY_TWO_BYTES (0x3 << 28) // (HSMC4_CS) 32 bytes.

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR AHB Static Memory Controller 4 Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_HSMC4 {
	AT91_REG	 HSMC4_CFG; 	// Configuration Register
	AT91_REG	 HSMC4_CTRL; 	// Control Register
	AT91_REG	 HSMC4_SR; 	// Status Register
	AT91_REG	 HSMC4_IER; 	// Interrupt Enable Register
	AT91_REG	 HSMC4_IDR; 	// Interrupt Disable Register
	AT91_REG	 HSMC4_IMR; 	// Interrupt Mask Register
	AT91_REG	 HSMC4_ADDR; 	// Address Cycle Zero Register
	AT91_REG	 HSMC4_BANK; 	// Bank Register
	AT91_REG	 HSMC4_ECCCR; 	// ECC reset register
	AT91_REG	 HSMC4_ECCCMD; 	// ECC Page size register
	AT91_REG	 HSMC4_ECCSR1; 	// ECC Status register 1
	AT91_REG	 HSMC4_ECCPR0; 	// ECC Parity register 0
	AT91_REG	 HSMC4_ECCPR1; 	// ECC Parity register 1
	AT91_REG	 HSMC4_ECCSR2; 	// ECC Status register 2
	AT91_REG	 HSMC4_ECCPR2; 	// ECC Parity register 2
	AT91_REG	 HSMC4_ECCPR3; 	// ECC Parity register 3
	AT91_REG	 HSMC4_ECCPR4; 	// ECC Parity register 4
	AT91_REG	 HSMC4_ECCPR5; 	// ECC Parity register 5
	AT91_REG	 HSMC4_ECCPR6; 	// ECC Parity register 6
	AT91_REG	 HSMC4_ECCPR7; 	// ECC Parity register 7
	AT91_REG	 HSMC4_ECCPR8; 	// ECC Parity register 8
	AT91_REG	 HSMC4_ECCPR9; 	// ECC Parity register 9
	AT91_REG	 HSMC4_ECCPR10; 	// ECC Parity register 10
	AT91_REG	 HSMC4_ECCPR11; 	// ECC Parity register 11
	AT91_REG	 HSMC4_ECCPR12; 	// ECC Parity register 12
	AT91_REG	 HSMC4_ECCPR13; 	// ECC Parity register 13
	AT91_REG	 HSMC4_ECCPR14; 	// ECC Parity register 14
	AT91_REG	 HSMC4_Eccpr15; 	// ECC Parity register 15
	AT91_REG	 Reserved0[40]; 	// 
	AT91_REG	 HSMC4_OCMS; 	// OCMS MODE register
	AT91_REG	 HSMC4_KEY1; 	// KEY1 Register
	AT91_REG	 HSMC4_KEY2; 	// KEY2 Register
	AT91_REG	 Reserved1[50]; 	// 
	AT91_REG	 HSMC4_WPCR; 	// Write Protection Control register
	AT91_REG	 HSMC4_WPSR; 	// Write Protection Status Register
	AT91_REG	 HSMC4_ADDRSIZE; 	// Write Protection Status Register
	AT91_REG	 HSMC4_IPNAME1; 	// Write Protection Status Register
	AT91_REG	 HSMC4_IPNAME2; 	// Write Protection Status Register
	AT91_REG	 HSMC4_FEATURES; 	// Write Protection Status Register
	AT91_REG	 HSMC4_VER; 	// HSMC4 Version Register
	AT91_REG	 HSMC4_DUMMY; 	// This rtegister was created only ti have AHB constants
} AT91S_HSMC4, *AT91PS_HSMC4;
#else
#define HSMC4_CFG       (AT91_CAST(AT91_REG *) 	0x00000000) // (HSMC4_CFG) Configuration Register
#define HSMC4_CTRL      (AT91_CAST(AT91_REG *) 	0x00000004) // (HSMC4_CTRL) Control Register
#define HSMC4_SR        (AT91_CAST(AT91_REG *) 	0x00000008) // (HSMC4_SR) Status Register
#define HSMC4_IER       (AT91_CAST(AT91_REG *) 	0x0000000C) // (HSMC4_IER) Interrupt Enable Register
#define HSMC4_IDR       (AT91_CAST(AT91_REG *) 	0x00000010) // (HSMC4_IDR) Interrupt Disable Register
#define HSMC4_IMR       (AT91_CAST(AT91_REG *) 	0x00000014) // (HSMC4_IMR) Interrupt Mask Register
#define HSMC4_ADDR      (AT91_CAST(AT91_REG *) 	0x00000018) // (HSMC4_ADDR) Address Cycle Zero Register
#define HSMC4_BANK      (AT91_CAST(AT91_REG *) 	0x0000001C) // (HSMC4_BANK) Bank Register
#define HSMC4_ECCCR     (AT91_CAST(AT91_REG *) 	0x00000020) // (HSMC4_ECCCR) ECC reset register
#define HSMC4_ECCCMD    (AT91_CAST(AT91_REG *) 	0x00000024) // (HSMC4_ECCCMD) ECC Page size register
#define HSMC4_ECCSR1    (AT91_CAST(AT91_REG *) 	0x00000028) // (HSMC4_ECCSR1) ECC Status register 1
#define HSMC4_ECCPR0    (AT91_CAST(AT91_REG *) 	0x0000002C) // (HSMC4_ECCPR0) ECC Parity register 0
#define HSMC4_ECCPR1    (AT91_CAST(AT91_REG *) 	0x00000030) // (HSMC4_ECCPR1) ECC Parity register 1
#define HSMC4_ECCSR2    (AT91_CAST(AT91_REG *) 	0x00000034) // (HSMC4_ECCSR2) ECC Status register 2
#define HSMC4_ECCPR2    (AT91_CAST(AT91_REG *) 	0x00000038) // (HSMC4_ECCPR2) ECC Parity register 2
#define HSMC4_ECCPR3    (AT91_CAST(AT91_REG *) 	0x0000003C) // (HSMC4_ECCPR3) ECC Parity register 3
#define HSMC4_ECCPR4    (AT91_CAST(AT91_REG *) 	0x00000040) // (HSMC4_ECCPR4) ECC Parity register 4
#define HSMC4_ECCPR5    (AT91_CAST(AT91_REG *) 	0x00000044) // (HSMC4_ECCPR5) ECC Parity register 5
#define HSMC4_ECCPR6    (AT91_CAST(AT91_REG *) 	0x00000048) // (HSMC4_ECCPR6) ECC Parity register 6
#define HSMC4_ECCPR7    (AT91_CAST(AT91_REG *) 	0x0000004C) // (HSMC4_ECCPR7) ECC Parity register 7
#define HSMC4_ECCPR8    (AT91_CAST(AT91_REG *) 	0x00000050) // (HSMC4_ECCPR8) ECC Parity register 8
#define HSMC4_ECCPR9    (AT91_CAST(AT91_REG *) 	0x00000054) // (HSMC4_ECCPR9) ECC Parity register 9
#define HSMC4_ECCPR10   (AT91_CAST(AT91_REG *) 	0x00000058) // (HSMC4_ECCPR10) ECC Parity register 10
#define HSMC4_ECCPR11   (AT91_CAST(AT91_REG *) 	0x0000005C) // (HSMC4_ECCPR11) ECC Parity register 11
#define HSMC4_ECCPR12   (AT91_CAST(AT91_REG *) 	0x00000060) // (HSMC4_ECCPR12) ECC Parity register 12
#define HSMC4_ECCPR13   (AT91_CAST(AT91_REG *) 	0x00000064) // (HSMC4_ECCPR13) ECC Parity register 13
#define HSMC4_ECCPR14   (AT91_CAST(AT91_REG *) 	0x00000068) // (HSMC4_ECCPR14) ECC Parity register 14
#define Hsmc4_Eccpr15   (AT91_CAST(AT91_REG *) 	0x0000006C) // (Hsmc4_Eccpr15) ECC Parity register 15
#define HSMC4_OCMS      (AT91_CAST(AT91_REG *) 	0x00000110) // (HSMC4_OCMS) OCMS MODE register
#define HSMC4_KEY1      (AT91_CAST(AT91_REG *) 	0x00000114) // (HSMC4_KEY1) KEY1 Register
#define HSMC4_KEY2      (AT91_CAST(AT91_REG *) 	0x00000118) // (HSMC4_KEY2) KEY2 Register
#define HSMC4_WPCR      (AT91_CAST(AT91_REG *) 	0x000001E4) // (HSMC4_WPCR) Write Protection Control register
#define HSMC4_WPSR      (AT91_CAST(AT91_REG *) 	0x000001E8) // (HSMC4_WPSR) Write Protection Status Register
#define HSMC4_ADDRSIZE  (AT91_CAST(AT91_REG *) 	0x000001EC) // (HSMC4_ADDRSIZE) Write Protection Status Register
#define HSMC4_IPNAME1   (AT91_CAST(AT91_REG *) 	0x000001F0) // (HSMC4_IPNAME1) Write Protection Status Register
#define HSMC4_IPNAME2   (AT91_CAST(AT91_REG *) 	0x000001F4) // (HSMC4_IPNAME2) Write Protection Status Register
#define HSMC4_FEATURES  (AT91_CAST(AT91_REG *) 	0x000001F8) // (HSMC4_FEATURES) Write Protection Status Register
#define HSMC4_VER       (AT91_CAST(AT91_REG *) 	0x000001FC) // (HSMC4_VER) HSMC4 Version Register
#define HSMC4_DUMMY     (AT91_CAST(AT91_REG *) 	0x00000200) // (HSMC4_DUMMY) This rtegister was created only ti have AHB constants

#endif
// -------- HSMC4_CFG : (HSMC4 Offset: 0x0) Configuration Register -------- 
#define AT91C_HSMC4_PAGESIZE  (0x3 <<  0) // (HSMC4) PAGESIZE field description
#define 	AT91C_HSMC4_PAGESIZE_528_Bytes            (0x0) // (HSMC4) 512 bytes plus 16 bytes page size
#define 	AT91C_HSMC4_PAGESIZE_1056_Bytes           (0x1) // (HSMC4) 1024 bytes plus 32 bytes page size
#define 	AT91C_HSMC4_PAGESIZE_2112_Bytes           (0x2) // (HSMC4) 2048 bytes plus 64 bytes page size
#define 	AT91C_HSMC4_PAGESIZE_4224_Bytes           (0x3) // (HSMC4) 4096 bytes plus 128 bytes page size
#define AT91C_HSMC4_WSPARE    (0x1 <<  8) // (HSMC4) Spare area access in Write Mode
#define AT91C_HSMC4_RSPARE    (0x1 <<  9) // (HSMC4) Spare area access in Read Mode
#define AT91C_HSMC4_EDGECTRL  (0x1 << 12) // (HSMC4) Rising/Falling Edge Detection Control
#define AT91C_HSMC4_RBEDGE    (0x1 << 13) // (HSMC4) Ready/Busy Signal edge Detection
#define AT91C_HSMC4_DTOCYC    (0xF << 16) // (HSMC4) Data Timeout Cycle Number
#define AT91C_HSMC4_DTOMUL    (0x7 << 20) // (HSMC4) Data Timeout Multiplier
#define 	AT91C_HSMC4_DTOMUL_1                    (0x0 << 20) // (HSMC4) DTOCYC x 1
#define 	AT91C_HSMC4_DTOMUL_16                   (0x1 << 20) // (HSMC4) DTOCYC x 16
#define 	AT91C_HSMC4_DTOMUL_128                  (0x2 << 20) // (HSMC4) DTOCYC x 128
#define 	AT91C_HSMC4_DTOMUL_256                  (0x3 << 20) // (HSMC4) DTOCYC x 256
#define 	AT91C_HSMC4_DTOMUL_1024                 (0x4 << 20) // (HSMC4) DTOCYC x 1024
#define 	AT91C_HSMC4_DTOMUL_4096                 (0x5 << 20) // (HSMC4) DTOCYC x 4096
#define 	AT91C_HSMC4_DTOMUL_65536                (0x6 << 20) // (HSMC4) DTOCYC x 65536
#define 	AT91C_HSMC4_DTOMUL_1048576              (0x7 << 20) // (HSMC4) DTOCYC x 1048576
// -------- HSMC4_CTRL : (HSMC4 Offset: 0x4) Control Register -------- 
#define AT91C_HSMC4_NFCEN     (0x1 <<  0) // (HSMC4) Nand Flash Controller Host Enable
#define AT91C_HSMC4_NFCDIS    (0x1 <<  1) // (HSMC4) Nand Flash Controller Host Disable
#define AT91C_HSMC4_HOSTEN    (0x1 <<  8) // (HSMC4) If set to one, the Host controller is activated and perform a data transfer phase.
#define AT91C_HSMC4_HOSTWR    (0x1 << 11) // (HSMC4) If this field is set to one, the host transfers data from the internal SRAM to the Memory Device.
#define AT91C_HSMC4_HOSTCSID  (0x7 << 12) // (HSMC4) Host Controller Chip select Id
#define 	AT91C_HSMC4_HOSTCSID_0                    (0x0 << 12) // (HSMC4) CS0
#define 	AT91C_HSMC4_HOSTCSID_1                    (0x1 << 12) // (HSMC4) CS1
#define 	AT91C_HSMC4_HOSTCSID_2                    (0x2 << 12) // (HSMC4) CS2
#define 	AT91C_HSMC4_HOSTCSID_3                    (0x3 << 12) // (HSMC4) CS3
#define 	AT91C_HSMC4_HOSTCSID_4                    (0x4 << 12) // (HSMC4) CS4
#define 	AT91C_HSMC4_HOSTCSID_5                    (0x5 << 12) // (HSMC4) CS5
#define 	AT91C_HSMC4_HOSTCSID_6                    (0x6 << 12) // (HSMC4) CS6
#define 	AT91C_HSMC4_HOSTCSID_7                    (0x7 << 12) // (HSMC4) CS7
#define AT91C_HSMC4_VALID     (0x1 << 15) // (HSMC4) When set to 1, a write operation modifies both HOSTCSID and HOSTWR fields.
// -------- HSMC4_SR : (HSMC4 Offset: 0x8) HSMC4 Status Register -------- 
#define AT91C_HSMC4_NFCSTS    (0x1 <<  0) // (HSMC4) Nand Flash Controller status
#define AT91C_HSMC4_RBRISE    (0x1 <<  4) // (HSMC4) Selected Ready Busy Rising Edge Detected flag
#define AT91C_HSMC4_RBFALL    (0x1 <<  5) // (HSMC4) Selected Ready Busy Falling Edge Detected flag
#define AT91C_HSMC4_HOSTBUSY  (0x1 <<  8) // (HSMC4) Host Busy
#define AT91C_HSMC4_HOSTW     (0x1 << 11) // (HSMC4) Host Write/Read Operation
#define AT91C_HSMC4_HOSTCS    (0x7 << 12) // (HSMC4) Host Controller Chip select Id
#define 	AT91C_HSMC4_HOSTCS_0                    (0x0 << 12) // (HSMC4) CS0
#define 	AT91C_HSMC4_HOSTCS_1                    (0x1 << 12) // (HSMC4) CS1
#define 	AT91C_HSMC4_HOSTCS_2                    (0x2 << 12) // (HSMC4) CS2
#define 	AT91C_HSMC4_HOSTCS_3                    (0x3 << 12) // (HSMC4) CS3
#define 	AT91C_HSMC4_HOSTCS_4                    (0x4 << 12) // (HSMC4) CS4
#define 	AT91C_HSMC4_HOSTCS_5                    (0x5 << 12) // (HSMC4) CS5
#define 	AT91C_HSMC4_HOSTCS_6                    (0x6 << 12) // (HSMC4) CS6
#define 	AT91C_HSMC4_HOSTCS_7                    (0x7 << 12) // (HSMC4) CS7
#define AT91C_HSMC4_XFRDONE   (0x1 << 16) // (HSMC4) Host Data Transfer Terminated
#define AT91C_HSMC4_CMDDONE   (0x1 << 17) // (HSMC4) Command Done
#define AT91C_HSMC4_ECCRDY    (0x1 << 18) // (HSMC4) ECC ready
#define AT91C_HSMC4_DTOE      (0x1 << 20) // (HSMC4) Data timeout Error
#define AT91C_HSMC4_UNDEF     (0x1 << 21) // (HSMC4) Undefined Area Error
#define AT91C_HSMC4_AWB       (0x1 << 22) // (HSMC4) Accessing While Busy Error
#define AT91C_HSMC4_HASE      (0x1 << 23) // (HSMC4) Host Controller Access Size Error
#define AT91C_HSMC4_RBEDGE0   (0x1 << 24) // (HSMC4) Ready Busy line 0 Edge detected
#define AT91C_HSMC4_RBEDGE1   (0x1 << 25) // (HSMC4) Ready Busy line 1 Edge detected
#define AT91C_HSMC4_RBEDGE2   (0x1 << 26) // (HSMC4) Ready Busy line 2 Edge detected
#define AT91C_HSMC4_RBEDGE3   (0x1 << 27) // (HSMC4) Ready Busy line 3 Edge detected
#define AT91C_HSMC4_RBEDGE4   (0x1 << 28) // (HSMC4) Ready Busy line 4 Edge detected
#define AT91C_HSMC4_RBEDGE5   (0x1 << 29) // (HSMC4) Ready Busy line 5 Edge detected
#define AT91C_HSMC4_RBEDGE6   (0x1 << 30) // (HSMC4) Ready Busy line 6 Edge detected
#define AT91C_HSMC4_RBEDGE7   (0x1 << 31) // (HSMC4) Ready Busy line 7 Edge detected
// -------- HSMC4_IER : (HSMC4 Offset: 0xc) HSMC4 Interrupt Enable Register -------- 
// -------- HSMC4_IDR : (HSMC4 Offset: 0x10) HSMC4 Interrupt Disable Register -------- 
// -------- HSMC4_IMR : (HSMC4 Offset: 0x14) HSMC4 Interrupt Mask Register -------- 
// -------- HSMC4_ADDR : (HSMC4 Offset: 0x18) Address Cycle Zero Register -------- 
#define AT91C_HSMC4_ADDRCYCLE0 (0xFF <<  0) // (HSMC4) Nand Flash Array Address cycle 0
// -------- HSMC4_BANK : (HSMC4 Offset: 0x1c) Bank Register -------- 
#define AT91C_BANK            (0x7 <<  0) // (HSMC4) Bank identifier
#define 	AT91C_BANK_0                    (0x0) // (HSMC4) BANK0
#define 	AT91C_BANK_1                    (0x1) // (HSMC4) BANK1
#define 	AT91C_BANK_2                    (0x2) // (HSMC4) BANK2
#define 	AT91C_BANK_3                    (0x3) // (HSMC4) BANK3
#define 	AT91C_BANK_4                    (0x4) // (HSMC4) BANK4
#define 	AT91C_BANK_5                    (0x5) // (HSMC4) BANK5
#define 	AT91C_BANK_6                    (0x6) // (HSMC4) BANK6
#define 	AT91C_BANK_7                    (0x7) // (HSMC4) BANK7
// -------- HSMC4_ECCCR : (HSMC4 Offset: 0x20) ECC Control Register -------- 
#define AT91C_HSMC4_ECCRESET  (0x1 <<  0) // (HSMC4) Reset ECC
// -------- HSMC4_ECCCMD : (HSMC4 Offset: 0x24) ECC mode register -------- 
#define AT91C_ECC_PAGE_SIZE   (0x3 <<  0) // (HSMC4) Nand Flash page size
#define 	AT91C_ECC_PAGE_SIZE_528_Bytes            (0x0) // (HSMC4) 512 bytes plus 16 bytes page size
#define 	AT91C_ECC_PAGE_SIZE_1056_Bytes           (0x1) // (HSMC4) 1024 bytes plus 32 bytes page size
#define 	AT91C_ECC_PAGE_SIZE_2112_Bytes           (0x2) // (HSMC4) 2048 bytes plus 64 bytes page size
#define 	AT91C_ECC_PAGE_SIZE_4224_Bytes           (0x3) // (HSMC4) 4096 bytes plus 128 bytes page size
#define AT91C_ECC_TYPCORRECT  (0x3 <<  4) // (HSMC4) Nand Flash page size
#define 	AT91C_ECC_TYPCORRECT_ONE_PER_PAGE         (0x0 <<  4) // (HSMC4) 
#define 	AT91C_ECC_TYPCORRECT_ONE_EVERY_256_BYTES  (0x1 <<  4) // (HSMC4) 
#define 	AT91C_ECC_TYPCORRECT_ONE_EVERY_512_BYTES  (0x2 <<  4) // (HSMC4) 
// -------- HSMC4_ECCSR1 : (HSMC4 Offset: 0x28) ECC Status Register 1 -------- 
#define AT91C_HSMC4_ECC_RECERR0 (0x1 <<  0) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR0 (0x1 <<  1) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR0 (0x1 <<  2) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR1 (0x1 <<  4) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR1 (0x1 <<  5) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR1 (0x1 <<  6) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR2 (0x1 <<  8) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR2 (0x1 <<  9) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR2 (0x1 << 10) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR3 (0x1 << 12) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR3 (0x1 << 13) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR3 (0x1 << 14) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR4 (0x1 << 16) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR4 (0x1 << 17) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR4 (0x1 << 18) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR5 (0x1 << 20) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR5 (0x1 << 21) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR5 (0x1 << 22) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR6 (0x1 << 24) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR6 (0x1 << 25) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR6 (0x1 << 26) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR7 (0x1 << 28) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR7 (0x1 << 29) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR7 (0x1 << 30) // (HSMC4) Multiple Error
// -------- HSMC4_ECCPR0 : (HSMC4 Offset: 0x2c) HSMC4 ECC parity Register 0 -------- 
#define AT91C_HSMC4_ECC_BITADDR (0x7 <<  0) // (HSMC4) Corrupted Bit Address in the page
#define AT91C_HSMC4_ECC_WORDADDR (0xFF <<  3) // (HSMC4) Corrupted Word Address in the page
#define AT91C_HSMC4_ECC_NPARITY (0x7FF << 12) // (HSMC4) Parity N
// -------- HSMC4_ECCPR1 : (HSMC4 Offset: 0x30) HSMC4 ECC parity Register 1 -------- 
// -------- HSMC4_ECCSR2 : (HSMC4 Offset: 0x34) ECC Status Register 2 -------- 
#define AT91C_HSMC4_ECC_RECERR8 (0x1 <<  0) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR8 (0x1 <<  1) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR8 (0x1 <<  2) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR9 (0x1 <<  4) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR9 (0x1 <<  5) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR9 (0x1 <<  6) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR10 (0x1 <<  8) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR10 (0x1 <<  9) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR10 (0x1 << 10) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR11 (0x1 << 12) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR11 (0x1 << 13) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR11 (0x1 << 14) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR12 (0x1 << 16) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR12 (0x1 << 17) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR12 (0x1 << 18) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR13 (0x1 << 20) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR13 (0x1 << 21) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR13 (0x1 << 22) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR14 (0x1 << 24) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR14 (0x1 << 25) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR14 (0x1 << 26) // (HSMC4) Multiple Error
#define AT91C_HSMC4_ECC_RECERR15 (0x1 << 28) // (HSMC4) Recoverable Error
#define AT91C_HSMC4_ECC_ECCERR15 (0x1 << 29) // (HSMC4) ECC Error
#define AT91C_HSMC4_ECC_MULERR15 (0x1 << 30) // (HSMC4) Multiple Error
// -------- HSMC4_ECCPR2 : (HSMC4 Offset: 0x38) HSMC4 ECC parity Register 2 -------- 
// -------- HSMC4_ECCPR3 : (HSMC4 Offset: 0x3c) HSMC4 ECC parity Register 3 -------- 
// -------- HSMC4_ECCPR4 : (HSMC4 Offset: 0x40) HSMC4 ECC parity Register 4 -------- 
// -------- HSMC4_ECCPR5 : (HSMC4 Offset: 0x44) HSMC4 ECC parity Register 5 -------- 
// -------- HSMC4_ECCPR6 : (HSMC4 Offset: 0x48) HSMC4 ECC parity Register 6 -------- 
// -------- HSMC4_ECCPR7 : (HSMC4 Offset: 0x4c) HSMC4 ECC parity Register 7 -------- 
// -------- HSMC4_ECCPR8 : (HSMC4 Offset: 0x50) HSMC4 ECC parity Register 8 -------- 
// -------- HSMC4_ECCPR9 : (HSMC4 Offset: 0x54) HSMC4 ECC parity Register 9 -------- 
// -------- HSMC4_ECCPR10 : (HSMC4 Offset: 0x58) HSMC4 ECC parity Register 10 -------- 
// -------- HSMC4_ECCPR11 : (HSMC4 Offset: 0x5c) HSMC4 ECC parity Register 11 -------- 
// -------- HSMC4_ECCPR12 : (HSMC4 Offset: 0x60) HSMC4 ECC parity Register 12 -------- 
// -------- HSMC4_ECCPR13 : (HSMC4 Offset: 0x64) HSMC4 ECC parity Register 13 -------- 
// -------- HSMC4_ECCPR14 : (HSMC4 Offset: 0x68) HSMC4 ECC parity Register 14 -------- 
// -------- HSMC4_ECCPR15 : (HSMC4 Offset: 0x6c) HSMC4 ECC parity Register 15 -------- 
// -------- HSMC4_OCMS : (HSMC4 Offset: 0x110) HSMC4 OCMS Register -------- 
#define AT91C_HSMC4_OCMS_SRSE (0x1 <<  0) // (HSMC4) Static Memory Controller Scrambling Enable
#define AT91C_HSMC4_OCMS_SMSE (0x1 <<  1) // (HSMC4) SRAM Scramling Enable
// -------- HSMC4_KEY1 : (HSMC4 Offset: 0x114) HSMC4 OCMS KEY1 Register -------- 
#define AT91C_HSMC4_OCMS_KEY1 (0x0 <<  0) // (HSMC4) OCMS Key 2
// -------- HSMC4_OCMS_KEY2 : (HSMC4 Offset: 0x118) HSMC4 OCMS KEY2 Register -------- 
#define AT91C_HSMC4_OCMS_KEY2 (0x0 <<  0) // (HSMC4) OCMS Key 2
// -------- HSMC4_WPCR : (HSMC4 Offset: 0x1e4) HSMC4 Witre Protection Control Register -------- 
#define AT91C_HSMC4_WP_EN     (0x1 <<  0) // (HSMC4) Write Protection Enable
#define AT91C_HSMC4_WP_KEY    (0xFFFFFF <<  8) // (HSMC4) Protection Password
// -------- HSMC4_WPSR : (HSMC4 Offset: 0x1e8) HSMC4 WPSR Register -------- 
#define AT91C_HSMC4_WP_VS     (0xF <<  0) // (HSMC4) Write Protection Violation Status
#define 	AT91C_HSMC4_WP_VS_WP_VS0               (0x0) // (HSMC4) No write protection violation since the last read of this register
#define 	AT91C_HSMC4_WP_VS_WP_VS1               (0x1) // (HSMC4) write protection detected unauthorized attempt to write a control register had occured (since the last read)
#define 	AT91C_HSMC4_WP_VS_WP_VS2               (0x2) // (HSMC4) Software reset had been performed while write protection was enabled (since the last read)
#define 	AT91C_HSMC4_WP_VS_WP_VS3               (0x3) // (HSMC4) Both write protection violation and software reset with write protection enabled had occured since the last read
#define AT91C_                (0x0 <<  8) // (HSMC4) 
// -------- HSMC4_VER : (HSMC4 Offset: 0x1fc) HSMC4 VERSION Register -------- 
// -------- HSMC4_DUMMY : (HSMC4 Offset: 0x200) HSMC4 DUMMY REGISTER -------- 
#define AT91C_HSMC4_CMD1      (0xFF <<  2) // (HSMC4) Command Register Value for Cycle 1
#define AT91C_HSMC4_CMD2      (0xFF << 10) // (HSMC4) Command Register Value for Cycle 2
#define AT91C_HSMC4_VCMD2     (0x1 << 18) // (HSMC4) Valid Cycle 2 Command
#define AT91C_HSMC4_ACYCLE    (0x7 << 19) // (HSMC4) Number of Address required for the current command
#define 	AT91C_HSMC4_ACYCLE_HSMC4_ACYCLE_NONE    (0x0 << 19) // (HSMC4) No address cycle
#define 	AT91C_HSMC4_ACYCLE_HSMC4_ACYCLE_ONE     (0x1 << 19) // (HSMC4) One address cycle
#define 	AT91C_HSMC4_ACYCLE_HSMC4_ACYCLE_TWO     (0x2 << 19) // (HSMC4) Two address cycles
#define 	AT91C_HSMC4_ACYCLE_HSMC4_ACYCLE_THREE   (0x3 << 19) // (HSMC4) Three address cycles
#define 	AT91C_HSMC4_ACYCLE_HSMC4_ACYCLE_FOUR    (0x4 << 19) // (HSMC4) Four address cycles
#define 	AT91C_HSMC4_ACYCLE_HSMC4_ACYCLE_FIVE    (0x5 << 19) // (HSMC4) Five address cycles
#define AT91C_HSMC4_CSID      (0x7 << 22) // (HSMC4) Chip Select Identifier
#define 	AT91C_HSMC4_CSID_0                    (0x0 << 22) // (HSMC4) CS0
#define 	AT91C_HSMC4_CSID_1                    (0x1 << 22) // (HSMC4) CS1
#define 	AT91C_HSMC4_CSID_2                    (0x2 << 22) // (HSMC4) CS2
#define 	AT91C_HSMC4_CSID_3                    (0x3 << 22) // (HSMC4) CS3
#define 	AT91C_HSMC4_CSID_4                    (0x4 << 22) // (HSMC4) CS4
#define 	AT91C_HSMC4_CSID_5                    (0x5 << 22) // (HSMC4) CS5
#define 	AT91C_HSMC4_CSID_6                    (0x6 << 22) // (HSMC4) CS6
#define 	AT91C_HSMC4_CSID_7                    (0x7 << 22) // (HSMC4) CS7
#define AT91C_HSMC4_HOST_EN   (0x1 << 25) // (HSMC4) Host Main Controller Enable
#define AT91C_HSMC4_HOST_WR   (0x1 << 26) // (HSMC4) HOSTWR : Host Main Controller Write Enable
#define AT91C_HSMC4_HOSTCMD   (0x1 << 27) // (HSMC4) Host Command Enable

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR AHB Matrix Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_MATRIX {
	AT91_REG	 MATRIX_MCFG0; 	//  Master Configuration Register 0 : rom
	AT91_REG	 MATRIX_MCFG1; 	//  Master Configuration Register 1 ; htcm
	AT91_REG	 MATRIX_MCFG2; 	//  Master Configuration Register 2 : lcdc
	AT91_REG	 MATRIX_MCFG3; 	//  Master Configuration Register 3 : usb_dev_hs
	AT91_REG	 MATRIX_MCFG4; 	//  Master Configuration Register 4 : ebi
	AT91_REG	 MATRIX_MCFG5; 	//  Master Configuration Register 5 : bridge
	AT91_REG	 MATRIX_MCFG6; 	//  Master Configuration Register 6 
	AT91_REG	 MATRIX_MCFG7; 	//  Master Configuration Register 7 
	AT91_REG	 MATRIX_MCFG8; 	//  Master Configuration Register 8 
	AT91_REG	 Reserved0[7]; 	// 
	AT91_REG	 MATRIX_SCFG0; 	//  Slave Configuration Register 0 : rom
	AT91_REG	 MATRIX_SCFG1; 	//  Slave Configuration Register 1 : htcm
	AT91_REG	 MATRIX_SCFG2; 	//  Slave Configuration Register 2 : lcdc
	AT91_REG	 MATRIX_SCFG3; 	//  Slave Configuration Register 3 : usb_dev_hs
	AT91_REG	 MATRIX_SCFG4; 	//  Slave Configuration Register 4 ; ebi
	AT91_REG	 MATRIX_SCFG5; 	//  Slave Configuration Register 5 : bridge
	AT91_REG	 MATRIX_SCFG6; 	//  Slave Configuration Register 6
	AT91_REG	 MATRIX_SCFG7; 	//  Slave Configuration Register 7
	AT91_REG	 Reserved1[8]; 	// 
	AT91_REG	 MATRIX_PRAS0; 	//  PRAS0 : rom
	AT91_REG	 MATRIX_PRBS0; 	//  PRBS0 : rom
	AT91_REG	 MATRIX_PRAS1; 	//  PRAS1 : htcm
	AT91_REG	 MATRIX_PRBS1; 	//  PRBS1 : htcm
	AT91_REG	 MATRIX_PRAS2; 	//  PRAS2 : lcdc
	AT91_REG	 MATRIX_PRBS2; 	//  PRBS2 : lcdc
	AT91_REG	 MATRIX_PRAS3; 	//  PRAS3 : usb_dev_hs
	AT91_REG	 MATRIX_PRBS3; 	//  PRBS3 : usb_dev_hs
	AT91_REG	 MATRIX_PRAS4; 	//  PRAS4 : ebi
	AT91_REG	 MATRIX_PRBS4; 	//  PRBS4 : ebi
	AT91_REG	 MATRIX_PRAS5; 	//  PRAS5 : bridge
	AT91_REG	 MATRIX_PRBS5; 	//  PRBS5 : bridge
	AT91_REG	 MATRIX_PRAS6; 	//  PRAS6
	AT91_REG	 MATRIX_PRBS6; 	//  PRBS6
	AT91_REG	 MATRIX_PRAS7; 	//  PRAS7
	AT91_REG	 MATRIX_PRBS7; 	//  PRBS7
	AT91_REG	 Reserved2[16]; 	// 
	AT91_REG	 MATRIX_MRCR; 	//  Master Remp Control Register 
} AT91S_MATRIX, *AT91PS_MATRIX;
#else
#define MATRIX_MCFG0    (AT91_CAST(AT91_REG *) 	0x00000000) // (MATRIX_MCFG0)  Master Configuration Register 0 : rom
#define MATRIX_MCFG1    (AT91_CAST(AT91_REG *) 	0x00000004) // (MATRIX_MCFG1)  Master Configuration Register 1 ; htcm
#define MATRIX_MCFG2    (AT91_CAST(AT91_REG *) 	0x00000008) // (MATRIX_MCFG2)  Master Configuration Register 2 : lcdc
#define MATRIX_MCFG3    (AT91_CAST(AT91_REG *) 	0x0000000C) // (MATRIX_MCFG3)  Master Configuration Register 3 : usb_dev_hs
#define MATRIX_MCFG4    (AT91_CAST(AT91_REG *) 	0x00000010) // (MATRIX_MCFG4)  Master Configuration Register 4 : ebi
#define MATRIX_MCFG5    (AT91_CAST(AT91_REG *) 	0x00000014) // (MATRIX_MCFG5)  Master Configuration Register 5 : bridge
#define MATRIX_MCFG6    (AT91_CAST(AT91_REG *) 	0x00000018) // (MATRIX_MCFG6)  Master Configuration Register 6 
#define MATRIX_MCFG7    (AT91_CAST(AT91_REG *) 	0x0000001C) // (MATRIX_MCFG7)  Master Configuration Register 7 
#define MATRIX_MCFG8    (AT91_CAST(AT91_REG *) 	0x00000020) // (MATRIX_MCFG8)  Master Configuration Register 8 
#define MATRIX_SCFG0    (AT91_CAST(AT91_REG *) 	0x00000040) // (MATRIX_SCFG0)  Slave Configuration Register 0 : rom
#define MATRIX_SCFG1    (AT91_CAST(AT91_REG *) 	0x00000044) // (MATRIX_SCFG1)  Slave Configuration Register 1 : htcm
#define MATRIX_SCFG2    (AT91_CAST(AT91_REG *) 	0x00000048) // (MATRIX_SCFG2)  Slave Configuration Register 2 : lcdc
#define MATRIX_SCFG3    (AT91_CAST(AT91_REG *) 	0x0000004C) // (MATRIX_SCFG3)  Slave Configuration Register 3 : usb_dev_hs
#define MATRIX_SCFG4    (AT91_CAST(AT91_REG *) 	0x00000050) // (MATRIX_SCFG4)  Slave Configuration Register 4 ; ebi
#define MATRIX_SCFG5    (AT91_CAST(AT91_REG *) 	0x00000054) // (MATRIX_SCFG5)  Slave Configuration Register 5 : bridge
#define MATRIX_SCFG6    (AT91_CAST(AT91_REG *) 	0x00000058) // (MATRIX_SCFG6)  Slave Configuration Register 6
#define MATRIX_SCFG7    (AT91_CAST(AT91_REG *) 	0x0000005C) // (MATRIX_SCFG7)  Slave Configuration Register 7
#define MATRIX_PRAS0    (AT91_CAST(AT91_REG *) 	0x00000080) // (MATRIX_PRAS0)  PRAS0 : rom
#define MATRIX_PRBS0    (AT91_CAST(AT91_REG *) 	0x00000084) // (MATRIX_PRBS0)  PRBS0 : rom
#define MATRIX_PRAS1    (AT91_CAST(AT91_REG *) 	0x00000088) // (MATRIX_PRAS1)  PRAS1 : htcm
#define MATRIX_PRBS1    (AT91_CAST(AT91_REG *) 	0x0000008C) // (MATRIX_PRBS1)  PRBS1 : htcm
#define MATRIX_PRAS2    (AT91_CAST(AT91_REG *) 	0x00000090) // (MATRIX_PRAS2)  PRAS2 : lcdc
#define MATRIX_PRBS2    (AT91_CAST(AT91_REG *) 	0x00000094) // (MATRIX_PRBS2)  PRBS2 : lcdc
#define MATRIX_PRAS3    (AT91_CAST(AT91_REG *) 	0x00000098) // (MATRIX_PRAS3)  PRAS3 : usb_dev_hs
#define MATRIX_PRBS3    (AT91_CAST(AT91_REG *) 	0x0000009C) // (MATRIX_PRBS3)  PRBS3 : usb_dev_hs
#define MATRIX_PRAS4    (AT91_CAST(AT91_REG *) 	0x000000A0) // (MATRIX_PRAS4)  PRAS4 : ebi
#define MATRIX_PRBS4    (AT91_CAST(AT91_REG *) 	0x000000A4) // (MATRIX_PRBS4)  PRBS4 : ebi
#define MATRIX_PRAS5    (AT91_CAST(AT91_REG *) 	0x000000A8) // (MATRIX_PRAS5)  PRAS5 : bridge
#define MATRIX_PRBS5    (AT91_CAST(AT91_REG *) 	0x000000AC) // (MATRIX_PRBS5)  PRBS5 : bridge
#define MATRIX_PRAS6    (AT91_CAST(AT91_REG *) 	0x000000B0) // (MATRIX_PRAS6)  PRAS6
#define MATRIX_PRBS6    (AT91_CAST(AT91_REG *) 	0x000000B4) // (MATRIX_PRBS6)  PRBS6
#define MATRIX_PRAS7    (AT91_CAST(AT91_REG *) 	0x000000B8) // (MATRIX_PRAS7)  PRAS7
#define MATRIX_PRBS7    (AT91_CAST(AT91_REG *) 	0x000000BC) // (MATRIX_PRBS7)  PRBS7
#define MATRIX_MRCR     (AT91_CAST(AT91_REG *) 	0x00000100) // (MATRIX_MRCR)  Master Remp Control Register 

#endif
// -------- MATRIX_MCFG0 : (MATRIX Offset: 0x0) Master Configuration Register rom -------- 
#define AT91C_MATRIX_ULBT     (0x7 <<  0) // (MATRIX) Undefined Length Burst Type
// -------- MATRIX_MCFG1 : (MATRIX Offset: 0x4) Master Configuration Register htcm -------- 
// -------- MATRIX_MCFG2 : (MATRIX Offset: 0x8) Master Configuration Register gps_tcm -------- 
// -------- MATRIX_MCFG3 : (MATRIX Offset: 0xc) Master Configuration Register hperiphs -------- 
// -------- MATRIX_MCFG4 : (MATRIX Offset: 0x10) Master Configuration Register ebi0 -------- 
// -------- MATRIX_MCFG5 : (MATRIX Offset: 0x14) Master Configuration Register ebi1 -------- 
// -------- MATRIX_MCFG6 : (MATRIX Offset: 0x18) Master Configuration Register bridge -------- 
// -------- MATRIX_MCFG7 : (MATRIX Offset: 0x1c) Master Configuration Register gps -------- 
// -------- MATRIX_MCFG8 : (MATRIX Offset: 0x20) Master Configuration Register gps -------- 
// -------- MATRIX_SCFG0 : (MATRIX Offset: 0x40) Slave Configuration Register 0 -------- 
#define AT91C_MATRIX_SLOT_CYCLE (0xFF <<  0) // (MATRIX) Maximum Number of Allowed Cycles for a Burst
#define AT91C_MATRIX_DEFMSTR_TYPE (0x3 << 16) // (MATRIX) Default Master Type
#define 	AT91C_MATRIX_DEFMSTR_TYPE_NO_DEFMSTR           (0x0 << 16) // (MATRIX) No Default Master. At the end of current slave access, if no other master request is pending, the slave is deconnected from all masters. This results in having a one cycle latency for the first transfer of a burst.
#define 	AT91C_MATRIX_DEFMSTR_TYPE_LAST_DEFMSTR         (0x1 << 16) // (MATRIX) Last Default Master. At the end of current slave access, if no other master request is pending, the slave stay connected with the last master having accessed it. This results in not having the one cycle latency when the last master re-trying access on the slave.
#define 	AT91C_MATRIX_DEFMSTR_TYPE_FIXED_DEFMSTR        (0x2 << 16) // (MATRIX) Fixed Default Master. At the end of current slave access, if no other master request is pending, the slave connects with fixed which number is in FIXED_DEFMSTR field. This results in not having the one cycle latency when the fixed master re-trying access on the slave.
#define AT91C_MATRIX_FIXED_DEFMSTR0 (0x7 << 18) // (MATRIX) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR0_ARM926I              (0x0 << 18) // (MATRIX) ARM926EJ-S Instruction Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR0_ARM926D              (0x1 << 18) // (MATRIX) ARM926EJ-S Data Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR0_PDC                  (0x2 << 18) // (MATRIX) PDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR0_LCDC                 (0x3 << 18) // (MATRIX) LCDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR0_2DGC                 (0x4 << 18) // (MATRIX) 2DGC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR0_ISI                  (0x5 << 18) // (MATRIX) ISI Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR0_DMA                  (0x6 << 18) // (MATRIX) DMA Controller Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR0_EMAC                 (0x7 << 18) // (MATRIX) EMAC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR0_USB                  (0x8 << 18) // (MATRIX) USB Master is Default Master
#define AT91C_MATRIX_ARBT     (0x3 << 24) // (MATRIX) Arbitration Type
// -------- MATRIX_SCFG1 : (MATRIX Offset: 0x44) Slave Configuration Register 1 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR1 (0x7 << 18) // (MATRIX) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR1_ARM926I              (0x0 << 18) // (MATRIX) ARM926EJ-S Instruction Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR1_ARM926D              (0x1 << 18) // (MATRIX) ARM926EJ-S Data Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR1_PDC                  (0x2 << 18) // (MATRIX) PDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR1_LCDC                 (0x3 << 18) // (MATRIX) LCDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR1_2DGC                 (0x4 << 18) // (MATRIX) 2DGC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR1_ISI                  (0x5 << 18) // (MATRIX) ISI Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR1_DMA                  (0x6 << 18) // (MATRIX) DMA Controller Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR1_EMAC                 (0x7 << 18) // (MATRIX) EMAC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR1_USB                  (0x8 << 18) // (MATRIX) USB Master is Default Master
// -------- MATRIX_SCFG2 : (MATRIX Offset: 0x48) Slave Configuration Register 2 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR2 (0x1 << 18) // (MATRIX) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR2_ARM926I              (0x0 << 18) // (MATRIX) ARM926EJ-S Instruction Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR2_ARM926D              (0x1 << 18) // (MATRIX) ARM926EJ-S Data Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR2_DMA                  (0x6 << 18) // (MATRIX) DMA Controller Master is Default Master
// -------- MATRIX_SCFG3 : (MATRIX Offset: 0x4c) Slave Configuration Register 3 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR3 (0x7 << 18) // (MATRIX) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR3_ARM926I              (0x0 << 18) // (MATRIX) ARM926EJ-S Instruction Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR3_ARM926D              (0x1 << 18) // (MATRIX) ARM926EJ-S Data Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR3_PDC                  (0x2 << 18) // (MATRIX) PDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR3_LCDC                 (0x3 << 18) // (MATRIX) LCDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR3_2DGC                 (0x4 << 18) // (MATRIX) 2DGC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR3_ISI                  (0x5 << 18) // (MATRIX) ISI Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR3_DMA                  (0x6 << 18) // (MATRIX) DMA Controller Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR3_EMAC                 (0x7 << 18) // (MATRIX) EMAC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR3_USB                  (0x8 << 18) // (MATRIX) USB Master is Default Master
// -------- MATRIX_SCFG4 : (MATRIX Offset: 0x50) Slave Configuration Register 4 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR4 (0x3 << 18) // (MATRIX) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR4_ARM926I              (0x0 << 18) // (MATRIX) ARM926EJ-S Instruction Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR4_ARM926D              (0x1 << 18) // (MATRIX) ARM926EJ-S Data Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR4_DMA                  (0x6 << 18) // (MATRIX) DMA Controller Master is Default Master
// -------- MATRIX_SCFG5 : (MATRIX Offset: 0x54) Slave Configuration Register 5 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR5 (0x3 << 18) // (MATRIX) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR5_ARM926I              (0x0 << 18) // (MATRIX) ARM926EJ-S Instruction Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR5_ARM926D              (0x1 << 18) // (MATRIX) ARM926EJ-S Data Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR5_PDC                  (0x2 << 18) // (MATRIX) PDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR5_LCDC                 (0x3 << 18) // (MATRIX) LCDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR5_2DGC                 (0x4 << 18) // (MATRIX) 2DGC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR5_ISI                  (0x5 << 18) // (MATRIX) ISI Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR5_DMA                  (0x6 << 18) // (MATRIX) DMA Controller Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR5_EMAC                 (0x7 << 18) // (MATRIX) EMAC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR5_USB                  (0x8 << 18) // (MATRIX) USB Master is Default Master
// -------- MATRIX_SCFG6 : (MATRIX Offset: 0x58) Slave Configuration Register 6 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR6 (0x3 << 18) // (MATRIX) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR6_ARM926I              (0x0 << 18) // (MATRIX) ARM926EJ-S Instruction Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR6_ARM926D              (0x1 << 18) // (MATRIX) ARM926EJ-S Data Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR6_PDC                  (0x2 << 18) // (MATRIX) PDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR6_LCDC                 (0x3 << 18) // (MATRIX) LCDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR6_2DGC                 (0x4 << 18) // (MATRIX) 2DGC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR6_ISI                  (0x5 << 18) // (MATRIX) ISI Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR6_DMA                  (0x6 << 18) // (MATRIX) DMA Controller Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR6_EMAC                 (0x7 << 18) // (MATRIX) EMAC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR6_USB                  (0x8 << 18) // (MATRIX) USB Master is Default Master
// -------- MATRIX_SCFG7 : (MATRIX Offset: 0x5c) Slave Configuration Register 7 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR7 (0x3 << 18) // (MATRIX) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR7_ARM926I              (0x0 << 18) // (MATRIX) ARM926EJ-S Instruction Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR7_ARM926D              (0x1 << 18) // (MATRIX) ARM926EJ-S Data Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR7_PDC                  (0x2 << 18) // (MATRIX) PDC Master is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR7_DMA                  (0x6 << 18) // (MATRIX) DMA Controller Master is Default Master
// -------- MATRIX_PRAS0 : (MATRIX Offset: 0x80) PRAS0 Register -------- 
#define AT91C_MATRIX_M0PR     (0x3 <<  0) // (MATRIX) ARM926EJ-S Instruction priority
#define AT91C_MATRIX_M1PR     (0x3 <<  4) // (MATRIX) ARM926EJ-S Data priority
#define AT91C_MATRIX_M2PR     (0x3 <<  8) // (MATRIX) PDC priority
#define AT91C_MATRIX_M3PR     (0x3 << 12) // (MATRIX) LCDC priority
#define AT91C_MATRIX_M4PR     (0x3 << 16) // (MATRIX) 2DGC priority
#define AT91C_MATRIX_M5PR     (0x3 << 20) // (MATRIX) ISI priority
#define AT91C_MATRIX_M6PR     (0x3 << 24) // (MATRIX) DMA priority
#define AT91C_MATRIX_M7PR     (0x3 << 28) // (MATRIX) EMAC priority
// -------- MATRIX_PRBS0 : (MATRIX Offset: 0x84) PRBS0 Register -------- 
#define AT91C_MATRIX_M8PR     (0x3 <<  0) // (MATRIX) USB priority
// -------- MATRIX_PRAS1 : (MATRIX Offset: 0x88) PRAS1 Register -------- 
// -------- MATRIX_PRBS1 : (MATRIX Offset: 0x8c) PRBS1 Register -------- 
// -------- MATRIX_PRAS2 : (MATRIX Offset: 0x90) PRAS2 Register -------- 
// -------- MATRIX_PRBS2 : (MATRIX Offset: 0x94) PRBS2 Register -------- 
// -------- MATRIX_PRAS3 : (MATRIX Offset: 0x98) PRAS3 Register -------- 
// -------- MATRIX_PRBS3 : (MATRIX Offset: 0x9c) PRBS3 Register -------- 
// -------- MATRIX_PRAS4 : (MATRIX Offset: 0xa0) PRAS4 Register -------- 
// -------- MATRIX_PRBS4 : (MATRIX Offset: 0xa4) PRBS4 Register -------- 
// -------- MATRIX_PRAS5 : (MATRIX Offset: 0xa8) PRAS5 Register -------- 
// -------- MATRIX_PRBS5 : (MATRIX Offset: 0xac) PRBS5 Register -------- 
// -------- MATRIX_PRAS6 : (MATRIX Offset: 0xb0) PRAS6 Register -------- 
// -------- MATRIX_PRBS6 : (MATRIX Offset: 0xb4) PRBS6 Register -------- 
// -------- MATRIX_PRAS7 : (MATRIX Offset: 0xb8) PRAS7 Register -------- 
// -------- MATRIX_PRBS7 : (MATRIX Offset: 0xbc) PRBS7 Register -------- 
// -------- MATRIX_MRCR : (MATRIX Offset: 0x100) MRCR Register -------- 
#define AT91C_MATRIX_RCA926I  (0x1 <<  0) // (MATRIX) Remap Command Bit for ARM926EJ-S Instruction
#define AT91C_MATRIX_RCA926D  (0x1 <<  1) // (MATRIX) Remap Command Bit for ARM926EJ-S Data
#define AT91C_MATRIX_RCB2     (0x1 <<  2) // (MATRIX) Remap Command Bit for PDC
#define AT91C_MATRIX_RCB3     (0x1 <<  3) // (MATRIX) Remap Command Bit for LCD
#define AT91C_MATRIX_RCB4     (0x1 <<  4) // (MATRIX) Remap Command Bit for 2DGC
#define AT91C_MATRIX_RCB5     (0x1 <<  5) // (MATRIX) Remap Command Bit for ISI
#define AT91C_MATRIX_RCB6     (0x1 <<  6) // (MATRIX) Remap Command Bit for DMA
#define AT91C_MATRIX_RCB7     (0x1 <<  7) // (MATRIX) Remap Command Bit for EMAC
#define AT91C_MATRIX_RCB8     (0x1 <<  8) // (MATRIX) Remap Command Bit for USB

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR AHB CCFG Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_CCFG {
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 CCFG_TCMR; 	//  TCM configuration
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 CCFG_UDPHS; 	//  USB Device HS configuration
	AT91_REG	 CCFG_EBICSA; 	//  EBI Chip Select Assignement Register
	AT91_REG	 Reserved2[54]; 	// 
	AT91_REG	 CCFG_MATRIXVERSION; 	//  Version Register
} AT91S_CCFG, *AT91PS_CCFG;
#else
#define CCFG_TCMR       (AT91_CAST(AT91_REG *) 	0x00000004) // (CCFG_TCMR)  TCM configuration
#define CCFG_UDPHS      (AT91_CAST(AT91_REG *) 	0x0000000C) // (CCFG_UDPHS)  USB Device HS configuration
#define CCFG_EBICSA     (AT91_CAST(AT91_REG *) 	0x00000010) // (CCFG_EBICSA)  EBI Chip Select Assignement Register
#define CCFG_MATRIXVERSION (AT91_CAST(AT91_REG *) 	0x000000EC) // (CCFG_MATRIXVERSION)  Version Register

#endif
// -------- CCFG_TCMR : (CCFG Offset: 0x4) TCM Configuration -------- 
#define AT91C_CCFG_ITCM_SIZE  (0xF <<  0) // (CCFG) Size of ITCM enabled memory block
#define 	AT91C_CCFG_ITCM_SIZE_0KB                  (0x0) // (CCFG) 0 KB (No ITCM Memory)
#define 	AT91C_CCFG_ITCM_SIZE_16KB                 (0x5) // (CCFG) 16 KB
#define 	AT91C_CCFG_ITCM_SIZE_32KB                 (0x6) // (CCFG) 32 KB
#define AT91C_CCFG_DTCM_SIZE  (0xF <<  4) // (CCFG) Size of DTCM enabled memory block
#define 	AT91C_CCFG_DTCM_SIZE_0KB                  (0x0 <<  4) // (CCFG) 0 KB (No DTCM Memory)
#define 	AT91C_CCFG_DTCM_SIZE_16KB                 (0x5 <<  4) // (CCFG) 16 KB
#define 	AT91C_CCFG_DTCM_SIZE_32KB                 (0x6 <<  4) // (CCFG) 32 KB
#define AT91C_CCFG_RM         (0xF <<  8) // (CCFG) Read Margin registers
// -------- CCFG_UDPHS : (CCFG Offset: 0xc) USB Device HS configuration -------- 
#define AT91C_CCFG_DONT_USE_UTMI_LOCK (0x1 <<  0) // (CCFG) 
#define 	AT91C_CCFG_DONT_USE_UTMI_LOCK_DONT_USE_LOCK        (0x0) // (CCFG) 
// -------- CCFG_EBICSA : (CCFG Offset: 0x10) EBI Chip Select Assignement Register -------- 
#define AT91C_EBI_CS1A        (0x1 <<  1) // (CCFG) Chip Select 1 Assignment
#define 	AT91C_EBI_CS1A_SMC                  (0x0 <<  1) // (CCFG) Chip Select 1 is assigned to the Static Memory Controller.
#define 	AT91C_EBI_CS1A_SDRAMC               (0x1 <<  1) // (CCFG) Chip Select 1 is assigned to the SDRAM Controller.
#define AT91C_EBI_CS3A        (0x1 <<  3) // (CCFG) Chip Select 3 Assignment
#define 	AT91C_EBI_CS3A_SMC                  (0x0 <<  3) // (CCFG) Chip Select 3 is only assigned to the Static Memory Controller and NCS3 behaves as defined by the SMC.
#define 	AT91C_EBI_CS3A_SM                   (0x1 <<  3) // (CCFG) Chip Select 3 is assigned to the Static Memory Controller and the SmartMedia Logic is activated.
#define AT91C_EBI_CS4A        (0x1 <<  4) // (CCFG) Chip Select 4 Assignment
#define 	AT91C_EBI_CS4A_SMC                  (0x0 <<  4) // (CCFG) Chip Select 4 is only assigned to the Static Memory Controller and NCS4 behaves as defined by the SMC.
#define 	AT91C_EBI_CS4A_CF                   (0x1 <<  4) // (CCFG) Chip Select 4 is assigned to the Static Memory Controller and the CompactFlash Logic (first slot) is activated.
#define AT91C_EBI_CS5A        (0x1 <<  5) // (CCFG) Chip Select 5 Assignment
#define 	AT91C_EBI_CS5A_SMC                  (0x0 <<  5) // (CCFG) Chip Select 5 is only assigned to the Static Memory Controller and NCS5 behaves as defined by the SMC
#define 	AT91C_EBI_CS5A_CF                   (0x1 <<  5) // (CCFG) Chip Select 5 is assigned to the Static Memory Controller and the CompactFlash Logic (second slot) is activated.
#define AT91C_EBI_DBPUC       (0x1 <<  8) // (CCFG) Data Bus Pull-up Configuration
#define AT91C_EBI_SUPPLY      (0x1 << 16) // (CCFG) EBI supply set to 1.8

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR NESTED vector Interrupt Controller
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_NVIC {
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 NVIC_ICTR; 	// Interrupt Control Type Register
	AT91_REG	 Reserved1[2]; 	// 
	AT91_REG	 NVIC_STICKCSR; 	// SysTick Control and Status Register
	AT91_REG	 NVIC_STICKRVR; 	// SysTick Reload Value Register
	AT91_REG	 NVIC_STICKCVR; 	// SysTick Current Value Register
	AT91_REG	 NVIC_STICKCALVR; 	// SysTick Calibration Value Register
	AT91_REG	 Reserved2[56]; 	// 
	AT91_REG	 NVIC_ISER[8]; 	// Set Enable Register
	AT91_REG	 Reserved3[24]; 	// 
	AT91_REG	 NVIC_ICER[8]; 	// Clear enable Register
	AT91_REG	 Reserved4[24]; 	// 
	AT91_REG	 NVIC_ISPR[8]; 	// Set Pending Register
	AT91_REG	 Reserved5[24]; 	// 
	AT91_REG	 NVIC_ICPR[8]; 	// Clear Pending Register
	AT91_REG	 Reserved6[24]; 	// 
	AT91_REG	 NVIC_ABR[8]; 	// Active Bit Register
	AT91_REG	 Reserved7[56]; 	// 
	AT91_REG	 NVIC_IPR[60]; 	// Interrupt Mask Register
	AT91_REG	 Reserved8[516]; 	// 
	AT91_REG	 NVIC_CPUID; 	// CPUID Base Register
	AT91_REG	 NVIC_ICSR; 	// Interrupt Control State Register
	AT91_REG	 NVIC_VTOFFR; 	// Vector Table Offset Register
	AT91_REG	 NVIC_AIRCR; 	// Application Interrupt/Reset Control Reg
	AT91_REG	 NVIC_SCR; 	// System Control Register
	AT91_REG	 NVIC_CCR; 	// Configuration Control Register
	AT91_REG	 NVIC_HAND4PR; 	// System Handlers 4-7 Priority Register
	AT91_REG	 NVIC_HAND8PR; 	// System Handlers 8-11 Priority Register
	AT91_REG	 NVIC_HAND12PR; 	// System Handlers 12-15 Priority Register
	AT91_REG	 NVIC_HANDCSR; 	// System Handler Control and State Register
	AT91_REG	 NVIC_CFSR; 	// Configurable Fault Status Register
	AT91_REG	 NVIC_HFSR; 	// Hard Fault Status Register
	AT91_REG	 NVIC_DFSR; 	// Debug Fault Status Register
	AT91_REG	 NVIC_MMAR; 	// Mem Manage Address Register
	AT91_REG	 NVIC_BFAR; 	// Bus Fault Address Register
	AT91_REG	 NVIC_AFSR; 	// Auxiliary Fault Status Register
	AT91_REG	 NVIC_PFR0; 	// Processor Feature register0
	AT91_REG	 NVIC_PFR1; 	// Processor Feature register1
	AT91_REG	 NVIC_DFR0; 	// Debug Feature register0
	AT91_REG	 NVIC_AFR0; 	// Auxiliary Feature register0
	AT91_REG	 NVIC_MMFR0; 	// Memory Model Feature register0
	AT91_REG	 NVIC_MMFR1; 	// Memory Model Feature register1
	AT91_REG	 NVIC_MMFR2; 	// Memory Model Feature register2
	AT91_REG	 NVIC_MMFR3; 	// Memory Model Feature register3
	AT91_REG	 NVIC_ISAR0; 	// ISA Feature register0
	AT91_REG	 NVIC_ISAR1; 	// ISA Feature register1
	AT91_REG	 NVIC_ISAR2; 	// ISA Feature register2
	AT91_REG	 NVIC_ISAR3; 	// ISA Feature register3
	AT91_REG	 NVIC_ISAR4; 	// ISA Feature register4
	AT91_REG	 Reserved9[99]; 	// 
	AT91_REG	 NVIC_STIR; 	// Software Trigger Interrupt Register
	AT91_REG	 Reserved10[51]; 	// 
	AT91_REG	 NVIC_PID4; 	// Peripheral identification register
	AT91_REG	 NVIC_PID5; 	// Peripheral identification register
	AT91_REG	 NVIC_PID6; 	// Peripheral identification register
	AT91_REG	 NVIC_PID7; 	// Peripheral identification register
	AT91_REG	 NVIC_PID0; 	// Peripheral identification register b7:0
	AT91_REG	 NVIC_PID1; 	// Peripheral identification register b15:8
	AT91_REG	 NVIC_PID2; 	// Peripheral identification register b23:16
	AT91_REG	 NVIC_PID3; 	// Peripheral identification register b31:24
	AT91_REG	 NVIC_CID0; 	// Component identification register b7:0
	AT91_REG	 NVIC_CID1; 	// Component identification register b15:8
	AT91_REG	 NVIC_CID2; 	// Component identification register b23:16
	AT91_REG	 NVIC_CID3; 	// Component identification register b31:24
} AT91S_NVIC, *AT91PS_NVIC;
#else
#define NVIC_ICTR       (AT91_CAST(AT91_REG *) 	0x00000004) // (NVIC_ICTR) Interrupt Control Type Register
#define NVIC_STICKCSR   (AT91_CAST(AT91_REG *) 	0x00000010) // (NVIC_STICKCSR) SysTick Control and Status Register
#define NVIC_STICKRVR   (AT91_CAST(AT91_REG *) 	0x00000014) // (NVIC_STICKRVR) SysTick Reload Value Register
#define NVIC_STICKCVR   (AT91_CAST(AT91_REG *) 	0x00000018) // (NVIC_STICKCVR) SysTick Current Value Register
#define NVIC_STICKCALVR (AT91_CAST(AT91_REG *) 	0x0000001C) // (NVIC_STICKCALVR) SysTick Calibration Value Register
#define NVIC_ISER       (AT91_CAST(AT91_REG *) 	0x00000100) // (NVIC_ISER) Set Enable Register
#define NVIC_ICER       (AT91_CAST(AT91_REG *) 	0x00000180) // (NVIC_ICER) Clear enable Register
#define NVIC_ISPR       (AT91_CAST(AT91_REG *) 	0x00000200) // (NVIC_ISPR) Set Pending Register
#define NVIC_ICPR       (AT91_CAST(AT91_REG *) 	0x00000280) // (NVIC_ICPR) Clear Pending Register
#define NVIC_IABR       (AT91_CAST(AT91_REG *) 	0x00000300) // (NVIC_IABR) Active Bit Register
#define NVIC_IPR        (AT91_CAST(AT91_REG *) 	0x00000400) // (NVIC_IPR) Interrupt Mask Register
#define NVIC_CPUID      (AT91_CAST(AT91_REG *) 	0x00000D00) // (NVIC_CPUID) CPUID Base Register
#define NVIC_ICSR       (AT91_CAST(AT91_REG *) 	0x00000D04) // (NVIC_ICSR) Interrupt Control State Register
#define NVIC_VTOFFR     (AT91_CAST(AT91_REG *) 	0x00000D08) // (NVIC_VTOFFR) Vector Table Offset Register
#define NVIC_AIRCR      (AT91_CAST(AT91_REG *) 	0x00000D0C) // (NVIC_AIRCR) Application Interrupt/Reset Control Reg
#define NVIC_SCR        (AT91_CAST(AT91_REG *) 	0x00000D10) // (NVIC_SCR) System Control Register
#define NVIC_CCR        (AT91_CAST(AT91_REG *) 	0x00000D14) // (NVIC_CCR) Configuration Control Register
#define NVIC_HAND4PR    (AT91_CAST(AT91_REG *) 	0x00000D18) // (NVIC_HAND4PR) System Handlers 4-7 Priority Register
#define NVIC_HAND8PR    (AT91_CAST(AT91_REG *) 	0x00000D1C) // (NVIC_HAND8PR) System Handlers 8-11 Priority Register
#define NVIC_HAND12PR   (AT91_CAST(AT91_REG *) 	0x00000D20) // (NVIC_HAND12PR) System Handlers 12-15 Priority Register
#define NVIC_HANDCSR    (AT91_CAST(AT91_REG *) 	0x00000D24) // (NVIC_HANDCSR) System Handler Control and State Register
#define NVIC_CFSR       (AT91_CAST(AT91_REG *) 	0x00000D28) // (NVIC_CFSR) Configurable Fault Status Register
#define NVIC_HFSR       (AT91_CAST(AT91_REG *) 	0x00000D2C) // (NVIC_HFSR) Hard Fault Status Register
#define NVIC_DFSR       (AT91_CAST(AT91_REG *) 	0x00000D30) // (NVIC_DFSR) Debug Fault Status Register
#define NVIC_MMAR       (AT91_CAST(AT91_REG *) 	0x00000D34) // (NVIC_MMAR) Mem Manage Address Register
#define NVIC_BFAR       (AT91_CAST(AT91_REG *) 	0x00000D38) // (NVIC_BFAR) Bus Fault Address Register
#define NVIC_AFSR       (AT91_CAST(AT91_REG *) 	0x00000D3C) // (NVIC_AFSR) Auxiliary Fault Status Register
#define NVIC_PFR0       (AT91_CAST(AT91_REG *) 	0x00000D40) // (NVIC_PFR0) Processor Feature register0
#define NVIC_PFR1       (AT91_CAST(AT91_REG *) 	0x00000D44) // (NVIC_PFR1) Processor Feature register1
#define NVIC_DFR0       (AT91_CAST(AT91_REG *) 	0x00000D48) // (NVIC_DFR0) Debug Feature register0
#define NVIC_AFR0       (AT91_CAST(AT91_REG *) 	0x00000D4C) // (NVIC_AFR0) Auxiliary Feature register0
#define NVIC_MMFR0      (AT91_CAST(AT91_REG *) 	0x00000D50) // (NVIC_MMFR0) Memory Model Feature register0
#define NVIC_MMFR1      (AT91_CAST(AT91_REG *) 	0x00000D54) // (NVIC_MMFR1) Memory Model Feature register1
#define NVIC_MMFR2      (AT91_CAST(AT91_REG *) 	0x00000D58) // (NVIC_MMFR2) Memory Model Feature register2
#define NVIC_MMFR3      (AT91_CAST(AT91_REG *) 	0x00000D5C) // (NVIC_MMFR3) Memory Model Feature register3
#define NVIC_ISAR0      (AT91_CAST(AT91_REG *) 	0x00000D60) // (NVIC_ISAR0) ISA Feature register0
#define NVIC_ISAR1      (AT91_CAST(AT91_REG *) 	0x00000D64) // (NVIC_ISAR1) ISA Feature register1
#define NVIC_ISAR2      (AT91_CAST(AT91_REG *) 	0x00000D68) // (NVIC_ISAR2) ISA Feature register2
#define NVIC_ISAR3      (AT91_CAST(AT91_REG *) 	0x00000D6C) // (NVIC_ISAR3) ISA Feature register3
#define NVIC_ISAR4      (AT91_CAST(AT91_REG *) 	0x00000D70) // (NVIC_ISAR4) ISA Feature register4
#define NVIC_STIR       (AT91_CAST(AT91_REG *) 	0x00000F00) // (NVIC_STIR) Software Trigger Interrupt Register
#define NVIC_PID4       (AT91_CAST(AT91_REG *) 	0x00000FD0) // (NVIC_PID4) Peripheral identification register
#define NVIC_PID5       (AT91_CAST(AT91_REG *) 	0x00000FD4) // (NVIC_PID5) Peripheral identification register
#define NVIC_PID6       (AT91_CAST(AT91_REG *) 	0x00000FD8) // (NVIC_PID6) Peripheral identification register
#define NVIC_PID7       (AT91_CAST(AT91_REG *) 	0x00000FDC) // (NVIC_PID7) Peripheral identification register
#define NVIC_PID0       (AT91_CAST(AT91_REG *) 	0x00000FE0) // (NVIC_PID0) Peripheral identification register b7:0
#define NVIC_PID1       (AT91_CAST(AT91_REG *) 	0x00000FE4) // (NVIC_PID1) Peripheral identification register b15:8
#define NVIC_PID2       (AT91_CAST(AT91_REG *) 	0x00000FE8) // (NVIC_PID2) Peripheral identification register b23:16
#define NVIC_PID3       (AT91_CAST(AT91_REG *) 	0x00000FEC) // (NVIC_PID3) Peripheral identification register b31:24
#define NVIC_CID0       (AT91_CAST(AT91_REG *) 	0x00000FF0) // (NVIC_CID0) Component identification register b7:0
#define NVIC_CID1       (AT91_CAST(AT91_REG *) 	0x00000FF4) // (NVIC_CID1) Component identification register b15:8
#define NVIC_CID2       (AT91_CAST(AT91_REG *) 	0x00000FF8) // (NVIC_CID2) Component identification register b23:16
#define NVIC_CID3       (AT91_CAST(AT91_REG *) 	0x00000FFC) // (NVIC_CID3) Component identification register b31:24

#endif
// -------- NVIC_ICTR : (NVIC Offset: 0x4) Interrupt Controller Type Register -------- 
#define AT91C_NVIC_INTLINESNUM (0xF <<  0) // (NVIC) Total number of interrupt lines
#define 	AT91C_NVIC_INTLINESNUM_32                   (0x0) // (NVIC) up to 32 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_64                   (0x1) // (NVIC) up to 64 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_96                   (0x2) // (NVIC) up to 96 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_128                  (0x3) // (NVIC) up to 128 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_160                  (0x4) // (NVIC) up to 160 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_192                  (0x5) // (NVIC) up to 192 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_224                  (0x6) // (NVIC) up to 224 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_256                  (0x7) // (NVIC) up to 256 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_288                  (0x8) // (NVIC) up to 288 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_320                  (0x9) // (NVIC) up to 320 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_352                  (0xA) // (NVIC) up to 352 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_384                  (0xB) // (NVIC) up to 384 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_416                  (0xC) // (NVIC) up to 416 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_448                  (0xD) // (NVIC) up to 448 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_480                  (0xE) // (NVIC) up to 480 interrupt lines supported
#define 	AT91C_NVIC_INTLINESNUM_496                  (0xF) // (NVIC) up to 496 interrupt lines supported)
// -------- NVIC_STICKCSR : (NVIC Offset: 0x10) SysTick Control and Status Register -------- 
#define AT91C_NVIC_STICKENABLE (0x1 <<  0) // (NVIC) SysTick counter enable.
#define AT91C_NVIC_STICKINT   (0x1 <<  1) // (NVIC) SysTick interrupt enable.
#define AT91C_NVIC_STICKCLKSOURCE (0x1 <<  2) // (NVIC) Reference clock selection.
#define AT91C_NVIC_STICKCOUNTFLAG (0x1 << 16) // (NVIC) Return 1 if timer counted to 0 since last read.
// -------- NVIC_STICKRVR : (NVIC Offset: 0x14) SysTick Reload Value Register -------- 
#define AT91C_NVIC_STICKRELOAD (0xFFFFFF <<  0) // (NVIC) SysTick reload value.
// -------- NVIC_STICKCVR : (NVIC Offset: 0x18) SysTick Current Value Register -------- 
#define AT91C_NVIC_STICKCURRENT (0x7FFFFFFF <<  0) // (NVIC) SysTick current value.
// -------- NVIC_STICKCALVR : (NVIC Offset: 0x1c) SysTick Calibration Value Register -------- 
#define AT91C_NVIC_STICKTENMS (0xFFFFFF <<  0) // (NVIC) Reload value to use for 10ms timing.
#define AT91C_NVIC_STICKSKEW  (0x1 << 30) // (NVIC) Read as 1 if the calibration value is not exactly 10ms because of clock frequency.
#define AT91C_NVIC_STICKNOREF (0x1 << 31) // (NVIC) Read as 1 if the reference clock is not provided.
// -------- NVIC_IPR : (NVIC Offset: 0x400) Interrupt Priority Registers -------- 
#define AT91C_NVIC_PRI_N      (0xFF <<  0) // (NVIC) Priority of interrupt N (0, 4, 8, etc)
#define AT91C_NVIC_PRI_N1     (0xFF <<  8) // (NVIC) Priority of interrupt N+1 (1, 5, 9, etc)
#define AT91C_NVIC_PRI_N2     (0xFF << 16) // (NVIC) Priority of interrupt N+2 (2, 6, 10, etc)
#define AT91C_NVIC_PRI_N3     (0xFF << 24) // (NVIC) Priority of interrupt N+3 (3, 7, 11, etc)
// -------- NVIC_CPUID : (NVIC Offset: 0xd00) CPU ID Base Register -------- 
#define AT91C_NVIC_REVISION   (0xF <<  0) // (NVIC) Implementation defined revision number.
#define AT91C_NVIC_PARTNO     (0xFFF <<  4) // (NVIC) Number of processor within family
#define AT91C_NVIC_CONSTANT   (0xF << 16) // (NVIC) Reads as 0xF
#define AT91C_NVIC_VARIANT    (0xF << 20) // (NVIC) Implementation defined variant number.
#define AT91C_NVIC_IMPLEMENTER (0xFF << 24) // (NVIC) Implementer code. ARM is 0x41
// -------- NVIC_ICSR : (NVIC Offset: 0xd04) Interrupt Control State Register -------- 
#define AT91C_NVIC_VECTACTIVE (0x1FF <<  0) // (NVIC) Read-only Active ISR number field
#define AT91C_NVIC_RETTOBASE  (0x1 << 11) // (NVIC) Read-only
#define AT91C_NVIC_VECTPENDING (0x1FF << 12) // (NVIC) Read-only Pending ISR number field
#define AT91C_NVIC_ISRPENDING (0x1 << 22) // (NVIC) Read-only Interrupt pending flag.
#define AT91C_NVIC_ISRPREEMPT (0x1 << 23) // (NVIC) Read-only You must only use this at debug time
#define AT91C_NVIC_PENDSTCLR  (0x1 << 25) // (NVIC) Write-only Clear pending SysTick bit
#define AT91C_NVIC_PENDSTSET  (0x1 << 26) // (NVIC) Read/write Set a pending SysTick bit
#define AT91C_NVIC_PENDSVCLR  (0x1 << 27) // (NVIC) Write-only Clear pending pendSV bit
#define AT91C_NVIC_PENDSVSET  (0x1 << 28) // (NVIC) Read/write Set pending pendSV bit
#define AT91C_NVIC_NMIPENDSET (0x1 << 31) // (NVIC) Read/write Set pending NMI
// -------- NVIC_VTOFFR : (NVIC Offset: 0xd08) Vector Table Offset Register -------- 
#define AT91C_NVIC_TBLOFF     (0x3FFFFF <<  7) // (NVIC) Vector table base offset field
#define AT91C_NVIC_TBLBASE    (0x1 << 29) // (NVIC) Table base is in Code (0) or RAM (1)
#define 	AT91C_NVIC_TBLBASE_CODE                 (0x0 << 29) // (NVIC) Table base is in CODE
#define 	AT91C_NVIC_TBLBASE_RAM                  (0x1 << 29) // (NVIC) Table base is in RAM
// -------- NVIC_AIRCR : (NVIC Offset: 0xd0c) Application Interrupt and Reset Control Register -------- 
#define AT91C_NVIC_VECTRESET  (0x1 <<  0) // (NVIC) System Reset bit
#define AT91C_NVIC_VECTCLRACTIVE (0x1 <<  1) // (NVIC) Clear active vector bit
#define AT91C_NVIC_SYSRESETREQ (0x1 <<  2) // (NVIC) Causes a signal to be asserted to the outer system that indicates a reset is requested
#define AT91C_NVIC_PRIGROUP   (0x7 <<  8) // (NVIC) Interrupt priority grouping field
#define 	AT91C_NVIC_PRIGROUP_3                    (0x3 <<  8) // (NVIC) indicates four bits of pre-emption priority, none bit of subpriority
#define 	AT91C_NVIC_PRIGROUP_4                    (0x4 <<  8) // (NVIC) indicates three bits of pre-emption priority, one bit of subpriority
#define 	AT91C_NVIC_PRIGROUP_5                    (0x5 <<  8) // (NVIC) indicates two bits of pre-emption priority, two bits of subpriority
#define 	AT91C_NVIC_PRIGROUP_6                    (0x6 <<  8) // (NVIC) indicates one bit of pre-emption priority, three bits of subpriority
#define 	AT91C_NVIC_PRIGROUP_7                    (0x7 <<  8) // (NVIC) indicates no pre-emption priority, four bits of subpriority
#define AT91C_NVIC_ENDIANESS  (0x1 << 15) // (NVIC) Data endianness bit
#define AT91C_NVIC_VECTKEY    (0xFFFF << 16) // (NVIC) Register key
// -------- NVIC_SCR : (NVIC Offset: 0xd10) System Control Register -------- 
#define AT91C_NVIC_SLEEPONEXIT (0x1 <<  1) // (NVIC) Sleep on exit when returning from Handler mode to Thread mode
#define AT91C_NVIC_SLEEPDEEP  (0x1 <<  2) // (NVIC) Sleep deep bit
#define AT91C_NVIC_SEVONPEND  (0x1 <<  4) // (NVIC) When enabled, this causes WFE to wake up when an interrupt moves from inactive to pended
// -------- NVIC_CCR : (NVIC Offset: 0xd14) Configuration Control Register -------- 
#define AT91C_NVIC_NONEBASETHRDENA (0x1 <<  0) // (NVIC) When 0, default, It is only possible to enter Thread mode when returning from the last exception
#define AT91C_NVIC_USERSETMPEND (0x1 <<  1) // (NVIC) 
#define AT91C_NVIC_UNALIGN_TRP (0x1 <<  3) // (NVIC) Trap for unaligned access
#define AT91C_NVIC_DIV_0_TRP  (0x1 <<  4) // (NVIC) Trap on Divide by 0
#define AT91C_NVIC_BFHFNMIGN  (0x1 <<  8) // (NVIC) 
#define AT91C_NVIC_STKALIGN   (0x1 <<  9) // (NVIC) 
// -------- NVIC_HAND4PR : (NVIC Offset: 0xd18) System Handlers 4-7 Priority Register -------- 
#define AT91C_NVIC_PRI_4      (0xFF <<  0) // (NVIC) 
#define AT91C_NVIC_PRI_5      (0xFF <<  8) // (NVIC) 
#define AT91C_NVIC_PRI_6      (0xFF << 16) // (NVIC) 
#define AT91C_NVIC_PRI_7      (0xFF << 24) // (NVIC) 
// -------- NVIC_HAND8PR : (NVIC Offset: 0xd1c) System Handlers 8-11 Priority Register -------- 
#define AT91C_NVIC_PRI_8      (0xFF <<  0) // (NVIC) 
#define AT91C_NVIC_PRI_9      (0xFF <<  8) // (NVIC) 
#define AT91C_NVIC_PRI_10     (0xFF << 16) // (NVIC) 
#define AT91C_NVIC_PRI_11     (0xFF << 24) // (NVIC) 
// -------- NVIC_HAND12PR : (NVIC Offset: 0xd20) System Handlers 12-15 Priority Register -------- 
#define AT91C_NVIC_PRI_12     (0xFF <<  0) // (NVIC) 
#define AT91C_NVIC_PRI_13     (0xFF <<  8) // (NVIC) 
#define AT91C_NVIC_PRI_14     (0xFF << 16) // (NVIC) 
#define AT91C_NVIC_PRI_15     (0xFF << 24) // (NVIC) 
// -------- NVIC_HANDCSR : (NVIC Offset: 0xd24) System Handler Control and State Register -------- 
#define AT91C_NVIC_MEMFAULTACT (0x1 <<  0) // (NVIC) 
#define AT91C_NVIC_BUSFAULTACT (0x1 <<  1) // (NVIC) 
#define AT91C_NVIC_USGFAULTACT (0x1 <<  3) // (NVIC) 
#define AT91C_NVIC_SVCALLACT  (0x1 <<  7) // (NVIC) 
#define AT91C_NVIC_MONITORACT (0x1 <<  8) // (NVIC) 
#define AT91C_NVIC_PENDSVACT  (0x1 << 10) // (NVIC) 
#define AT91C_NVIC_SYSTICKACT (0x1 << 11) // (NVIC) 
#define AT91C_NVIC_USGFAULTPENDED (0x1 << 12) // (NVIC) 
#define AT91C_NVIC_MEMFAULTPENDED (0x1 << 13) // (NVIC) 
#define AT91C_NVIC_BUSFAULTPENDED (0x1 << 14) // (NVIC) 
#define AT91C_NVIC_SVCALLPENDED (0x1 << 15) // (NVIC) 
#define AT91C_NVIC_MEMFAULTENA (0x1 << 16) // (NVIC) 
#define AT91C_NVIC_BUSFAULTENA (0x1 << 17) // (NVIC) 
#define AT91C_NVIC_USGFAULTENA (0x1 << 18) // (NVIC) 
// -------- NVIC_CFSR : (NVIC Offset: 0xd28) Configurable Fault Status Registers -------- 
#define AT91C_NVIC_MEMMANAGE  (0xFF <<  0) // (NVIC) 
#define AT91C_NVIC_BUSFAULT   (0xFF <<  8) // (NVIC) 
#define AT91C_NVIC_USAGEFAULT (0xFF << 16) // (NVIC) 
// -------- NVIC_BFAR : (NVIC Offset: 0xd38) Bus Fault Address Register -------- 
#define AT91C_NVIC_IBUSERR    (0x1 <<  0) // (NVIC) This bit indicates a bus fault on an instruction prefetch
#define AT91C_NVIC_PRECISERR  (0x1 <<  1) // (NVIC) Precise data access error. The BFAR is written with the faulting address
#define AT91C_NVIC_IMPRECISERR (0x1 <<  2) // (NVIC) Imprecise data access error
#define AT91C_NVIC_UNSTKERR   (0x1 <<  3) // (NVIC) This bit indicates a derived bus fault has occurred on exception return
#define AT91C_NVIC_STKERR     (0x1 <<  4) // (NVIC) This bit indicates a derived bus fault has occurred on exception entry
#define AT91C_NVIC_BFARVALID  (0x1 <<  7) // (NVIC) This bit is set if the BFAR register has valid contents
// -------- NVIC_PFR0 : (NVIC Offset: 0xd40) Processor Feature register0 (ID_PFR0) -------- 
#define AT91C_NVIC_ID_PFR0_0  (0xF <<  0) // (NVIC) State0 (T-bit == 0)
#define AT91C_NVIC_ID_PRF0_1  (0xF <<  4) // (NVIC) State1 (T-bit == 1)
// -------- NVIC_PFR1 : (NVIC Offset: 0xd44) Processor Feature register1 (ID_PFR1) -------- 
#define AT91C_NVIC_ID_PRF1_MODEL (0xF <<  8) // (NVIC) Microcontroller programmer’s model
// -------- NVIC_DFR0 : (NVIC Offset: 0xd48) Debug Feature register0 (ID_DFR0) -------- 
#define AT91C_NVIC_ID_DFR0_MODEL (0xF << 20) // (NVIC) Microcontroller Debug Model – memory mapped
// -------- NVIC_MMFR0 : (NVIC Offset: 0xd50) Memory Model Feature register0 (ID_MMFR0) -------- 
#define AT91C_NVIC_ID_MMFR0_PMSA (0xF <<  4) // (NVIC) Microcontroller Debug Model – memory mapped
#define AT91C_NVIC_ID_MMFR0_CACHE (0xF <<  8) // (NVIC) Microcontroller Debug Model – memory mapped

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR CORTEX_M3 Registers
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_CM3 {
	AT91_REG	 CM3_CPUID; 	// CPU ID Base Register
	AT91_REG	 CM3_ICSR; 	// Interrupt Control State Register
	AT91_REG	 CM3_VTOR; 	// Vector Table Offset Register
	AT91_REG	 CM3_AIRCR; 	// Application Interrupt and Reset Control Register
	AT91_REG	 CM3_SCR; 	// System Controller Register
	AT91_REG	 CM3_CCR; 	// Configuration Control Register
	AT91_REG	 CM3_SHPR[3]; 	// System Handler Priority Register
	AT91_REG	 CM3_SHCSR; 	// System Handler Control and State Register
} AT91S_CM3, *AT91PS_CM3;
#else
#define CM3_CPUID       (AT91_CAST(AT91_REG *) 	0x00000000) // (CM3_CPUID) CPU ID Base Register
#define CM3_ICSR        (AT91_CAST(AT91_REG *) 	0x00000004) // (CM3_ICSR) Interrupt Control State Register
#define CM3_VTOR        (AT91_CAST(AT91_REG *) 	0x00000008) // (CM3_VTOR) Vector Table Offset Register
#define CM3_AIRCR       (AT91_CAST(AT91_REG *) 	0x0000000C) // (CM3_AIRCR) Application Interrupt and Reset Control Register
#define CM3_SCR         (AT91_CAST(AT91_REG *) 	0x00000010) // (CM3_SCR) System Controller Register
#define CM3_CCR         (AT91_CAST(AT91_REG *) 	0x00000014) // (CM3_CCR) Configuration Control Register
#define CM3_SHPR        (AT91_CAST(AT91_REG *) 	0x00000018) // (CM3_SHPR) System Handler Priority Register
#define CM3_SHCSR       (AT91_CAST(AT91_REG *) 	0x00000024) // (CM3_SHCSR) System Handler Control and State Register

#endif
// -------- CM3_CPUID : (CM3 Offset: 0x0)  -------- 
// -------- CM3_AIRCR : (CM3 Offset: 0xc)  -------- 
#define AT91C_CM3_SYSRESETREQ (0x1 <<  2) // (CM3) A reset is requested by the processor.
// -------- CM3_SCR : (CM3 Offset: 0x10)  -------- 
#define AT91C_CM3_SLEEPONEXIT (0x1 <<  1) // (CM3) Sleep on exit when returning from Handler mode to Thread mode. Enables interrupt driven applications to avoid returning to empty main application.
#define AT91C_CM3_SLEEPDEEP   (0x1 <<  2) // (CM3) Sleep deep bit.
#define AT91C_CM3_SEVONPEND   (0x1 <<  4) // (CM3) When enabled, this causes WFE to wake up when an interrupt moves from inactive to pended.
// -------- CM3_SHCSR : (CM3 Offset: 0x24)  -------- 
#define AT91C_CM3_SYSTICKACT  (0x1 << 11) // (CM3) Reads as 1 if SysTick is active.

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Clock Generator Controler
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_CKGR {
	AT91_REG	 CKGR_UCKR; 	// UTMI Clock Configuration Register
	AT91_REG	 CKGR_MOR; 	// Main Oscillator Register
	AT91_REG	 CKGR_MCFR; 	// Main Clock  Frequency Register
	AT91_REG	 CKGR_PLLAR; 	// PLL Register
} AT91S_CKGR, *AT91PS_CKGR;
#else
#define CKGR_UCKR       (AT91_CAST(AT91_REG *) 	0x00000000) // (CKGR_UCKR) UTMI Clock Configuration Register
#define CKGR_MOR        (AT91_CAST(AT91_REG *) 	0x00000004) // (CKGR_MOR) Main Oscillator Register
#define CKGR_MCFR       (AT91_CAST(AT91_REG *) 	0x00000008) // (CKGR_MCFR) Main Clock  Frequency Register
#define CKGR_PLLAR      (AT91_CAST(AT91_REG *) 	0x0000000C) // (CKGR_PLLAR) PLL Register

#endif
// -------- CKGR_UCKR : (CKGR Offset: 0x0) UTMI Clock Configuration Register -------- 
#define AT91C_CKGR_UPLLEN     (0x1 << 16) // (CKGR) UTMI PLL Enable
#define 	AT91C_CKGR_UPLLEN_DISABLED             (0x0 << 16) // (CKGR) The UTMI PLL is disabled
#define 	AT91C_CKGR_UPLLEN_ENABLED              (0x1 << 16) // (CKGR) The UTMI PLL is enabled
#define AT91C_CKGR_UPLLCOUNT  (0xF << 20) // (CKGR) UTMI Oscillator Start-up Time
#define AT91C_CKGR_BIASEN     (0x1 << 24) // (CKGR) UTMI BIAS Enable
#define 	AT91C_CKGR_BIASEN_DISABLED             (0x0 << 24) // (CKGR) The UTMI BIAS is disabled
#define 	AT91C_CKGR_BIASEN_ENABLED              (0x1 << 24) // (CKGR) The UTMI BIAS is enabled
#define AT91C_CKGR_BIASCOUNT  (0xF << 28) // (CKGR) UTMI BIAS Start-up Time
// -------- CKGR_MOR : (CKGR Offset: 0x4) Main Oscillator Register -------- 
#define AT91C_CKGR_MOSCXTEN   (0x1 <<  0) // (CKGR) Main Crystal Oscillator Enable
#define AT91C_CKGR_MOSCXTBY   (0x1 <<  1) // (CKGR) Main Crystal Oscillator Bypass
#define AT91C_CKGR_WAITMODE   (0x1 <<  2) // (CKGR) Main Crystal Oscillator Bypass
#define AT91C_CKGR_MOSCRCEN   (0x1 <<  3) // (CKGR) Main On-Chip RC Oscillator Enable
#define AT91C_CKGR_MOSCRCF    (0x7 <<  4) // (CKGR) Main On-Chip RC Oscillator Frequency Selection
#define AT91C_CKGR_MOSCXTST   (0xFF <<  8) // (CKGR) Main Crystal Oscillator Start-up Time
#define AT91C_CKGR_KEY        (0xFF << 16) // (CKGR) Clock Generator Controller Writing Protection Key
#define AT91C_CKGR_MOSCSEL    (0x1 << 24) // (CKGR) Main Oscillator Selection
#define AT91C_CKGR_CFDEN      (0x1 << 25) // (CKGR) Clock Failure Detector Enable
// -------- CKGR_MCFR : (CKGR Offset: 0x8) Main Clock Frequency Register -------- 
#define AT91C_CKGR_MAINF      (0xFFFF <<  0) // (CKGR) Main Clock Frequency
#define AT91C_CKGR_MAINRDY    (0x1 << 16) // (CKGR) Main Clock Ready
// -------- CKGR_PLLAR : (CKGR Offset: 0xc) PLL A Register -------- 
#define AT91C_CKGR_DIVA       (0xFF <<  0) // (CKGR) Divider Selected
#define 	AT91C_CKGR_DIVA_0                    (0x0) // (CKGR) Divider output is 0
#define 	AT91C_CKGR_DIVA_BYPASS               (0x1) // (CKGR) Divider is bypassed
#define AT91C_CKGR_PLLACOUNT  (0x3F <<  8) // (CKGR) PLLA Counter
#define AT91C_CKGR_STMODE     (0x3 << 14) // (CKGR) Start Mode
#define 	AT91C_CKGR_STMODE_0                    (0x0 << 14) // (CKGR) Fast startup
#define 	AT91C_CKGR_STMODE_1                    (0x1 << 14) // (CKGR) Reserved
#define 	AT91C_CKGR_STMODE_2                    (0x2 << 14) // (CKGR) Normal startup
#define 	AT91C_CKGR_STMODE_3                    (0x3 << 14) // (CKGR) Reserved
#define AT91C_CKGR_MULA       (0x7FF << 16) // (CKGR) PLL Multiplier
#define AT91C_CKGR_SRC        (0x1 << 29) // (CKGR) 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Supply Controller Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_SUPC {
	AT91_REG	 SUPC_CR; 	// Control Register
	AT91_REG	 SUPC_BOMR; 	// Brown Out Mode Register
	AT91_REG	 SUPC_MR; 	// Mode Register
	AT91_REG	 SUPC_WUMR; 	// Wake Up Mode Register
	AT91_REG	 SUPC_WUIR; 	// Wake Up Inputs Register
	AT91_REG	 SUPC_SR; 	// Status Register
	AT91_REG	 SUPC_FWUTR; 	// Flash Wake-up Timer Register
} AT91S_SUPC, *AT91PS_SUPC;
#else
#define SUPC_CR         (AT91_CAST(AT91_REG *) 	0x00000000) // (SUPC_CR) Control Register
#define SUPC_BOMR       (AT91_CAST(AT91_REG *) 	0x00000004) // (SUPC_BOMR) Brown Out Mode Register
#define SUPC_MR         (AT91_CAST(AT91_REG *) 	0x00000008) // (SUPC_MR) Mode Register
#define SUPC_WUMR       (AT91_CAST(AT91_REG *) 	0x0000000C) // (SUPC_WUMR) Wake Up Mode Register
#define SUPC_WUIR       (AT91_CAST(AT91_REG *) 	0x00000010) // (SUPC_WUIR) Wake Up Inputs Register
#define SUPC_SR         (AT91_CAST(AT91_REG *) 	0x00000014) // (SUPC_SR) Status Register
#define SUPC_FWUTR      (AT91_CAST(AT91_REG *) 	0x00000018) // (SUPC_FWUTR) Flash Wake-up Timer Register

#endif
// -------- SUPC_CR : (SUPC Offset: 0x0) Control Register -------- 
#define AT91C_SUPC_SHDW       (0x1 <<  0) // (SUPC) Shut Down Command
#define AT91C_SUPC_SHDWEOF    (0x1 <<  1) // (SUPC) Shut Down after End Of Frame
#define AT91C_SUPC_VROFF      (0x1 <<  2) // (SUPC) Voltage Regulator Off
#define AT91C_SUPC_XTALSEL    (0x1 <<  3) // (SUPC) Crystal Oscillator Select
#define AT91C_SUPC_KEY        (0xFF << 24) // (SUPC) Supply Controller Writing Protection Key
// -------- SUPC_BOMR : (SUPC Offset: 0x4) Brown Out Mode Register -------- 
#define AT91C_SUPC_BODTH      (0xF <<  0) // (SUPC) Brown Out Threshold
#define AT91C_SUPC_BODSMPL    (0x7 <<  8) // (SUPC) Brown Out Sampling Period
#define 	AT91C_SUPC_BODSMPL_DISABLED             (0x0 <<  8) // (SUPC) Brown Out Detector disabled
#define 	AT91C_SUPC_BODSMPL_CONTINUOUS           (0x1 <<  8) // (SUPC) Continuous Brown Out Detector
#define 	AT91C_SUPC_BODSMPL_32_SLCK              (0x2 <<  8) // (SUPC) Brown Out Detector enabled one SLCK period every 32 SLCK periods
#define 	AT91C_SUPC_BODSMPL_256_SLCK             (0x3 <<  8) // (SUPC) Brown Out Detector enabled one SLCK period every 256 SLCK periods
#define 	AT91C_SUPC_BODSMPL_2048_SLCK            (0x4 <<  8) // (SUPC) Brown Out Detector enabled one SLCK period every 2048 SLCK periods
#define AT91C_SUPC_BODRSTEN   (0x1 << 12) // (SUPC) Brownout Reset Enable
// -------- SUPC_MR : (SUPC Offset: 0x8) Supply Controller Mode Register -------- 
#define AT91C_SUPC_LCDOUT     (0xF <<  0) // (SUPC) LCD Charge Pump Output Voltage Selection
#define AT91C_SUPC_LCDMODE    (0x3 <<  4) // (SUPC) Segment LCD Supply Mode
#define 	AT91C_SUPC_LCDMODE_OFF                  (0x0 <<  4) // (SUPC) The internal and external supply sources are both deselected and the on-chip charge pump is turned off
#define 	AT91C_SUPC_LCDMODE_OFF_AFTER_EOF        (0x1 <<  4) // (SUPC) At the End Of Frame from LCD controller, the internal and external supply sources are both deselected and the on-chip charge pump is turned off
#define 	AT91C_SUPC_LCDMODE_EXTERNAL             (0x2 <<  4) // (SUPC) The external supply source is selected
#define 	AT91C_SUPC_LCDMODE_INTERNAL             (0x3 <<  4) // (SUPC) The internal supply source is selected and the on-chip charge pump is turned on
#define AT91C_SUPC_VRDEEP     (0x1 <<  8) // (SUPC) Voltage Regulator Deep Mode
#define AT91C_SUPC_VRVDD      (0x7 <<  9) // (SUPC) Voltage Regulator Output Voltage Selection
#define AT91C_SUPC_VRRSTEN    (0x1 << 12) // (SUPC) Voltage Regulation Loss Reset Enable
#define AT91C_SUPC_GPBRON     (0x1 << 16) // (SUPC) GPBR ON
#define AT91C_SUPC_SRAMON     (0x1 << 17) // (SUPC) SRAM ON
#define AT91C_SUPC_RTCON      (0x1 << 18) // (SUPC) Real Time Clock Power switch ON
#define AT91C_SUPC_FLASHON    (0x1 << 19) // (SUPC) Flash Power switch On
#define AT91C_SUPC_BYPASS     (0x1 << 20) // (SUPC) 32kHz oscillator bypass
#define AT91C_SUPC_MKEY       (0xFF << 24) // (SUPC) Supply Controller Writing Protection Key
// -------- SUPC_WUMR : (SUPC Offset: 0xc) Wake Up Mode Register -------- 
#define AT91C_SUPC_FWUPEN     (0x1 <<  0) // (SUPC) Force Wake Up Enable
#define AT91C_SUPC_BODEN      (0x1 <<  1) // (SUPC) Brown Out Wake Up Enable
#define AT91C_SUPC_RTTEN      (0x1 <<  2) // (SUPC) Real Time Timer Wake Up Enable
#define AT91C_SUPC_RTCEN      (0x1 <<  3) // (SUPC) Real Time Clock Wake Up Enable
#define AT91C_SUPC_FWUPDBC    (0x7 <<  8) // (SUPC) Force Wake Up debouncer
#define 	AT91C_SUPC_FWUPDBC_IMMEDIATE            (0x0 <<  8) // (SUPC) Immediate, No debouncing, detected active at least one Slow clock edge
#define 	AT91C_SUPC_FWUPDBC_3_SLCK               (0x1 <<  8) // (SUPC) An enabled Wake Up input shall be low for at least 3 SLCK periods
#define 	AT91C_SUPC_FWUPDBC_32_SLCK              (0x2 <<  8) // (SUPC) An enabled Wake Up input  shall be low for at least 32 SLCK periods
#define 	AT91C_SUPC_FWUPDBC_512_SLCK             (0x3 <<  8) // (SUPC) An enabled Wake Up input  shall be low for at least 512 SLCK periods
#define 	AT91C_SUPC_FWUPDBC_4096_SLCK            (0x4 <<  8) // (SUPC) An enabled Wake Up input  shall be low for at least 4096 SLCK periods
#define 	AT91C_SUPC_FWUPDBC_32768_SLCK           (0x5 <<  8) // (SUPC) An enabled Wake Up input  shall be low for at least 32768 SLCK periods
#define AT91C_SUPC_WKUPDBC    (0x7 << 12) // (SUPC) Force Wake Up debouncer
#define 	AT91C_SUPC_WKUPDBC_IMMEDIATE            (0x0 << 12) // (SUPC) Immediate, No debouncing, detected active at least one Slow clock edge
#define 	AT91C_SUPC_WKUPDBC_3_SLCK               (0x1 << 12) // (SUPC) FWUP shall be low for at least 3 SLCK periods
#define 	AT91C_SUPC_WKUPDBC_32_SLCK              (0x2 << 12) // (SUPC) FWUP shall be low for at least 32 SLCK periods
#define 	AT91C_SUPC_WKUPDBC_512_SLCK             (0x3 << 12) // (SUPC) FWUP shall be low for at least 512 SLCK periods
#define 	AT91C_SUPC_WKUPDBC_4096_SLCK            (0x4 << 12) // (SUPC) FWUP shall be low for at least 4096 SLCK periods
#define 	AT91C_SUPC_WKUPDBC_32768_SLCK           (0x5 << 12) // (SUPC) FWUP shall be low for at least 32768 SLCK periods
// -------- SUPC_WUIR : (SUPC Offset: 0x10) Wake Up Inputs Register -------- 
#define AT91C_SUPC_WKUPEN0    (0x1 <<  0) // (SUPC) Wake Up Input Enable 0
#define AT91C_SUPC_WKUPEN1    (0x1 <<  1) // (SUPC) Wake Up Input Enable 1
#define AT91C_SUPC_WKUPEN2    (0x1 <<  2) // (SUPC) Wake Up Input Enable 2
#define AT91C_SUPC_WKUPEN3    (0x1 <<  3) // (SUPC) Wake Up Input Enable 3
#define AT91C_SUPC_WKUPEN4    (0x1 <<  4) // (SUPC) Wake Up Input Enable 4
#define AT91C_SUPC_WKUPEN5    (0x1 <<  5) // (SUPC) Wake Up Input Enable 5
#define AT91C_SUPC_WKUPEN6    (0x1 <<  6) // (SUPC) Wake Up Input Enable 6
#define AT91C_SUPC_WKUPEN7    (0x1 <<  7) // (SUPC) Wake Up Input Enable 7
#define AT91C_SUPC_WKUPEN8    (0x1 <<  8) // (SUPC) Wake Up Input Enable 8
#define AT91C_SUPC_WKUPEN9    (0x1 <<  9) // (SUPC) Wake Up Input Enable 9
#define AT91C_SUPC_WKUPEN10   (0x1 << 10) // (SUPC) Wake Up Input Enable 10
#define AT91C_SUPC_WKUPEN11   (0x1 << 11) // (SUPC) Wake Up Input Enable 11
#define AT91C_SUPC_WKUPEN12   (0x1 << 12) // (SUPC) Wake Up Input Enable 12
#define AT91C_SUPC_WKUPEN13   (0x1 << 13) // (SUPC) Wake Up Input Enable 13
#define AT91C_SUPC_WKUPEN14   (0x1 << 14) // (SUPC) Wake Up Input Enable 14
#define AT91C_SUPC_WKUPEN15   (0x1 << 15) // (SUPC) Wake Up Input Enable 15
#define AT91C_SUPC_WKUPT0     (0x1 << 16) // (SUPC) Wake Up Input Transition 0
#define AT91C_SUPC_WKUPT1     (0x1 << 17) // (SUPC) Wake Up Input Transition 1
#define AT91C_SUPC_WKUPT2     (0x1 << 18) // (SUPC) Wake Up Input Transition 2
#define AT91C_SUPC_WKUPT3     (0x1 << 19) // (SUPC) Wake Up Input Transition 3
#define AT91C_SUPC_WKUPT4     (0x1 << 20) // (SUPC) Wake Up Input Transition 4
#define AT91C_SUPC_WKUPT5     (0x1 << 21) // (SUPC) Wake Up Input Transition 5
#define AT91C_SUPC_WKUPT6     (0x1 << 22) // (SUPC) Wake Up Input Transition 6
#define AT91C_SUPC_WKUPT7     (0x1 << 23) // (SUPC) Wake Up Input Transition 7
#define AT91C_SUPC_WKUPT8     (0x1 << 24) // (SUPC) Wake Up Input Transition 8
#define AT91C_SUPC_WKUPT9     (0x1 << 25) // (SUPC) Wake Up Input Transition 9
#define AT91C_SUPC_WKUPT10    (0x1 << 26) // (SUPC) Wake Up Input Transition 10
#define AT91C_SUPC_WKUPT11    (0x1 << 27) // (SUPC) Wake Up Input Transition 11
#define AT91C_SUPC_WKUPT12    (0x1 << 28) // (SUPC) Wake Up Input Transition 12
#define AT91C_SUPC_WKUPT13    (0x1 << 29) // (SUPC) Wake Up Input Transition 13
#define AT91C_SUPC_WKUPT14    (0x1 << 30) // (SUPC) Wake Up Input Transition 14
#define AT91C_SUPC_WKUPT15    (0x1 << 31) // (SUPC) Wake Up Input Transition 15
// -------- SUPC_SR : (SUPC Offset: 0x14) Status Register -------- 
#define AT91C_SUPC_FWUPS      (0x1 <<  0) // (SUPC) Force Wake Up Status
#define AT91C_SUPC_WKUPS      (0x1 <<  1) // (SUPC) Wake Up Status
#define AT91C_SUPC_BODWS      (0x1 <<  2) // (SUPC) BOD Detection Wake Up Status
#define AT91C_SUPC_VRRSTS     (0x1 <<  3) // (SUPC) Voltage regulation Loss Reset Status
#define AT91C_SUPC_BODRSTS    (0x1 <<  4) // (SUPC) BOD detection Reset Status
#define AT91C_SUPC_BODS       (0x1 <<  5) // (SUPC) BOD Status
#define AT91C_SUPC_BROWNOUT   (0x1 <<  6) // (SUPC) BOD Output Status
#define AT91C_SUPC_OSCSEL     (0x1 <<  7) // (SUPC) 32kHz Oscillator Selection Status
#define AT91C_SUPC_LCDS       (0x1 <<  8) // (SUPC) LCD Status
#define AT91C_SUPC_GPBRS      (0x1 <<  9) // (SUPC) General Purpose Back-up registers Status
#define AT91C_SUPC_RTS        (0x1 << 10) // (SUPC) Clock Status
#define AT91C_SUPC_FLASHS     (0x1 << 11) // (SUPC) FLASH Memory Status
#define AT91C_SUPC_FWUPIS     (0x1 << 12) // (SUPC) WKUP Input Status
#define AT91C_SUPC_WKUPIS0    (0x1 << 16) // (SUPC) WKUP Input 0 Status
#define AT91C_SUPC_WKUPIS1    (0x1 << 17) // (SUPC) WKUP Input 1 Status
#define AT91C_SUPC_WKUPIS2    (0x1 << 18) // (SUPC) WKUP Input 2 Status
#define AT91C_SUPC_WKUPIS3    (0x1 << 19) // (SUPC) WKUP Input 3 Status
#define AT91C_SUPC_WKUPIS4    (0x1 << 20) // (SUPC) WKUP Input 4 Status
#define AT91C_SUPC_WKUPIS5    (0x1 << 21) // (SUPC) WKUP Input 5 Status
#define AT91C_SUPC_WKUPIS6    (0x1 << 22) // (SUPC) WKUP Input 6 Status
#define AT91C_SUPC_WKUPIS7    (0x1 << 23) // (SUPC) WKUP Input 7 Status
#define AT91C_SUPC_WKUPIS8    (0x1 << 24) // (SUPC) WKUP Input 8 Status
#define AT91C_SUPC_WKUPIS9    (0x1 << 25) // (SUPC) WKUP Input 9 Status
#define AT91C_SUPC_WKUPIS10   (0x1 << 26) // (SUPC) WKUP Input 10 Status
#define AT91C_SUPC_WKUPIS11   (0x1 << 27) // (SUPC) WKUP Input 11 Status
#define AT91C_SUPC_WKUPIS12   (0x1 << 28) // (SUPC) WKUP Input 12 Status
#define AT91C_SUPC_WKUPIS13   (0x1 << 29) // (SUPC) WKUP Input 13 Status
#define AT91C_SUPC_WKUPIS14   (0x1 << 30) // (SUPC) WKUP Input 14 Status
#define AT91C_SUPC_WKUPIS15   (0x1 << 31) // (SUPC) WKUP Input 15 Status
// -------- SUPC_FWUTR : (SUPC Offset: 0x18) Flash Wake Up Timer Register -------- 
#define AT91C_SUPC_FWUT       (0x3FF <<  0) // (SUPC) Flash Wake Up Timer

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Reset Controller Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_RSTC {
	AT91_REG	 RSTC_RCR; 	// Reset Control Register
	AT91_REG	 RSTC_RSR; 	// Reset Status Register
	AT91_REG	 RSTC_RMR; 	// Reset Mode Register
	AT91_REG	 Reserved0[60]; 	// 
	AT91_REG	 RSTC_VER; 	// Version Register
} AT91S_RSTC, *AT91PS_RSTC;
#else
#define RSTC_RCR        (AT91_CAST(AT91_REG *) 	0x00000000) // (RSTC_RCR) Reset Control Register
#define RSTC_RSR        (AT91_CAST(AT91_REG *) 	0x00000004) // (RSTC_RSR) Reset Status Register
#define RSTC_RMR        (AT91_CAST(AT91_REG *) 	0x00000008) // (RSTC_RMR) Reset Mode Register
#define RSTC_VER        (AT91_CAST(AT91_REG *) 	0x000000FC) // (RSTC_VER) Version Register

#endif
// -------- RSTC_RCR : (RSTC Offset: 0x0) Reset Control Register -------- 
#define AT91C_RSTC_PROCRST    (0x1 <<  0) // (RSTC) Processor Reset
#define AT91C_RSTC_ICERST     (0x1 <<  1) // (RSTC) ICE Interface Reset
#define AT91C_RSTC_PERRST     (0x1 <<  2) // (RSTC) Peripheral Reset
#define AT91C_RSTC_EXTRST     (0x1 <<  3) // (RSTC) External Reset
#define AT91C_RSTC_KEY        (0xFF << 24) // (RSTC) Password
// -------- RSTC_RSR : (RSTC Offset: 0x4) Reset Status Register -------- 
#define AT91C_RSTC_URSTS      (0x1 <<  0) // (RSTC) User Reset Status
#define AT91C_RSTC_RSTTYP     (0x7 <<  8) // (RSTC) Reset Type
#define 	AT91C_RSTC_RSTTYP_GENERAL              (0x0 <<  8) // (RSTC) General reset. Both VDDCORE and VDDBU rising.
#define 	AT91C_RSTC_RSTTYP_WAKEUP               (0x1 <<  8) // (RSTC) WakeUp Reset. VDDCORE rising.
#define 	AT91C_RSTC_RSTTYP_WATCHDOG             (0x2 <<  8) // (RSTC) Watchdog Reset. Watchdog overflow occured.
#define 	AT91C_RSTC_RSTTYP_SOFTWARE             (0x3 <<  8) // (RSTC) Software Reset. Processor reset required by the software.
#define 	AT91C_RSTC_RSTTYP_USER                 (0x4 <<  8) // (RSTC) User Reset. NRST pin detected low.
#define AT91C_RSTC_NRSTL      (0x1 << 16) // (RSTC) NRST pin level
#define AT91C_RSTC_SRCMP      (0x1 << 17) // (RSTC) Software Reset Command in Progress.
// -------- RSTC_RMR : (RSTC Offset: 0x8) Reset Mode Register -------- 
#define AT91C_RSTC_URSTEN     (0x1 <<  0) // (RSTC) User Reset Enable
#define AT91C_RSTC_URSTIEN    (0x1 <<  4) // (RSTC) User Reset Interrupt Enable
#define AT91C_RSTC_ERSTL      (0xF <<  8) // (RSTC) User Reset Enable

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Real-time Clock Alarm and Parallel Load Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_RTC {
	AT91_REG	 RTC_CR; 	// Control Register
	AT91_REG	 RTC_MR; 	// Mode Register
	AT91_REG	 RTC_TIMR; 	// Time Register
	AT91_REG	 RTC_CALR; 	// Calendar Register
	AT91_REG	 RTC_TIMALR; 	// Time Alarm Register
	AT91_REG	 RTC_CALALR; 	// Calendar Alarm Register
	AT91_REG	 RTC_SR; 	// Status Register
	AT91_REG	 RTC_SCCR; 	// Status Clear Command Register
	AT91_REG	 RTC_IER; 	// Interrupt Enable Register
	AT91_REG	 RTC_IDR; 	// Interrupt Disable Register
	AT91_REG	 RTC_IMR; 	// Interrupt Mask Register
	AT91_REG	 RTC_VER; 	// Valid Entry Register
} AT91S_RTC, *AT91PS_RTC;
#else
#define RTC_CR          (AT91_CAST(AT91_REG *) 	0x00000000) // (RTC_CR) Control Register
#define RTC_MR          (AT91_CAST(AT91_REG *) 	0x00000004) // (RTC_MR) Mode Register
#define RTC_TIMR        (AT91_CAST(AT91_REG *) 	0x00000008) // (RTC_TIMR) Time Register
#define RTC_CALR        (AT91_CAST(AT91_REG *) 	0x0000000C) // (RTC_CALR) Calendar Register
#define RTC_TIMALR      (AT91_CAST(AT91_REG *) 	0x00000010) // (RTC_TIMALR) Time Alarm Register
#define RTC_CALALR      (AT91_CAST(AT91_REG *) 	0x00000014) // (RTC_CALALR) Calendar Alarm Register
#define RTC_SR          (AT91_CAST(AT91_REG *) 	0x00000018) // (RTC_SR) Status Register
#define RTC_SCCR        (AT91_CAST(AT91_REG *) 	0x0000001C) // (RTC_SCCR) Status Clear Command Register
#define RTC_IER         (AT91_CAST(AT91_REG *) 	0x00000020) // (RTC_IER) Interrupt Enable Register
#define RTC_IDR         (AT91_CAST(AT91_REG *) 	0x00000024) // (RTC_IDR) Interrupt Disable Register
#define RTC_IMR         (AT91_CAST(AT91_REG *) 	0x00000028) // (RTC_IMR) Interrupt Mask Register
#define RTC_VER         (AT91_CAST(AT91_REG *) 	0x0000002C) // (RTC_VER) Valid Entry Register

#endif
// -------- RTC_CR : (RTC Offset: 0x0) RTC Control Register -------- 
#define AT91C_RTC_UPDTIM      (0x1 <<  0) // (RTC) Update Request Time Register
#define AT91C_RTC_UPDCAL      (0x1 <<  1) // (RTC) Update Request Calendar Register
#define AT91C_RTC_TIMEVSEL    (0x3 <<  8) // (RTC) Time Event Selection
#define 	AT91C_RTC_TIMEVSEL_MINUTE               (0x0 <<  8) // (RTC) Minute change.
#define 	AT91C_RTC_TIMEVSEL_HOUR                 (0x1 <<  8) // (RTC) Hour change.
#define 	AT91C_RTC_TIMEVSEL_DAY24                (0x2 <<  8) // (RTC) Every day at midnight.
#define 	AT91C_RTC_TIMEVSEL_DAY12                (0x3 <<  8) // (RTC) Every day at noon.
#define AT91C_RTC_CALEVSEL    (0x3 << 16) // (RTC) Calendar Event Selection
#define 	AT91C_RTC_CALEVSEL_WEEK                 (0x0 << 16) // (RTC) Week change (every Monday at time 00:00:00).
#define 	AT91C_RTC_CALEVSEL_MONTH                (0x1 << 16) // (RTC) Month change (every 01 of each month at time 00:00:00).
#define 	AT91C_RTC_CALEVSEL_YEAR                 (0x2 << 16) // (RTC) Year change (every January 1 at time 00:00:00).
// -------- RTC_MR : (RTC Offset: 0x4) RTC Mode Register -------- 
#define AT91C_RTC_HRMOD       (0x1 <<  0) // (RTC) 12-24 hour Mode
// -------- RTC_TIMR : (RTC Offset: 0x8) RTC Time Register -------- 
#define AT91C_RTC_SEC         (0x7F <<  0) // (RTC) Current Second
#define AT91C_RTC_MIN         (0x7F <<  8) // (RTC) Current Minute
#define AT91C_RTC_HOUR        (0x3F << 16) // (RTC) Current Hour
#define AT91C_RTC_AMPM        (0x1 << 22) // (RTC) Ante Meridiem, Post Meridiem Indicator
// -------- RTC_CALR : (RTC Offset: 0xc) RTC Calendar Register -------- 
#define AT91C_RTC_CENT        (0x3F <<  0) // (RTC) Current Century
#define AT91C_RTC_YEAR        (0xFF <<  8) // (RTC) Current Year
#define AT91C_RTC_MONTH       (0x1F << 16) // (RTC) Current Month
#define AT91C_RTC_DAY         (0x7 << 21) // (RTC) Current Day
#define AT91C_RTC_DATE        (0x3F << 24) // (RTC) Current Date
// -------- RTC_TIMALR : (RTC Offset: 0x10) RTC Time Alarm Register -------- 
#define AT91C_RTC_SECEN       (0x1 <<  7) // (RTC) Second Alarm Enable
#define AT91C_RTC_MINEN       (0x1 << 15) // (RTC) Minute Alarm
#define AT91C_RTC_HOUREN      (0x1 << 23) // (RTC) Current Hour
// -------- RTC_CALALR : (RTC Offset: 0x14) RTC Calendar Alarm Register -------- 
#define AT91C_RTC_MONTHEN     (0x1 << 23) // (RTC) Month Alarm Enable
#define AT91C_RTC_DATEEN      (0x1 << 31) // (RTC) Date Alarm Enable
// -------- RTC_SR : (RTC Offset: 0x18) RTC Status Register -------- 
#define AT91C_RTC_ACKUPD      (0x1 <<  0) // (RTC) Acknowledge for Update
#define AT91C_RTC_ALARM       (0x1 <<  1) // (RTC) Alarm Flag
#define AT91C_RTC_SECEV       (0x1 <<  2) // (RTC) Second Event
#define AT91C_RTC_TIMEV       (0x1 <<  3) // (RTC) Time Event
#define AT91C_RTC_CALEV       (0x1 <<  4) // (RTC) Calendar event
// -------- RTC_SCCR : (RTC Offset: 0x1c) RTC Status Clear Command Register -------- 
// -------- RTC_IER : (RTC Offset: 0x20) RTC Interrupt Enable Register -------- 
// -------- RTC_IDR : (RTC Offset: 0x24) RTC Interrupt Disable Register -------- 
// -------- RTC_IMR : (RTC Offset: 0x28) RTC Interrupt Mask Register -------- 
// -------- RTC_VER : (RTC Offset: 0x2c) RTC Valid Entry Register -------- 
#define AT91C_RTC_NVTIM       (0x1 <<  0) // (RTC) Non valid Time
#define AT91C_RTC_NVCAL       (0x1 <<  1) // (RTC) Non valid Calendar
#define AT91C_RTC_NVTIMALR    (0x1 <<  2) // (RTC) Non valid time Alarm
#define AT91C_RTC_NVCALALR    (0x1 <<  3) // (RTC) Nonvalid Calendar Alarm

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Real Time Timer Controller Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_RTTC {
	AT91_REG	 RTTC_RTMR; 	// Real-time Mode Register
	AT91_REG	 RTTC_RTAR; 	// Real-time Alarm Register
	AT91_REG	 RTTC_RTVR; 	// Real-time Value Register
	AT91_REG	 RTTC_RTSR; 	// Real-time Status Register
} AT91S_RTTC, *AT91PS_RTTC;
#else
#define RTTC_RTMR       (AT91_CAST(AT91_REG *) 	0x00000000) // (RTTC_RTMR) Real-time Mode Register
#define RTTC_RTAR       (AT91_CAST(AT91_REG *) 	0x00000004) // (RTTC_RTAR) Real-time Alarm Register
#define RTTC_RTVR       (AT91_CAST(AT91_REG *) 	0x00000008) // (RTTC_RTVR) Real-time Value Register
#define RTTC_RTSR       (AT91_CAST(AT91_REG *) 	0x0000000C) // (RTTC_RTSR) Real-time Status Register

#endif
// -------- RTTC_RTMR : (RTTC Offset: 0x0) Real-time Mode Register -------- 
#define AT91C_RTTC_RTPRES     (0xFFFF <<  0) // (RTTC) Real-time Timer Prescaler Value
#define AT91C_RTTC_ALMIEN     (0x1 << 16) // (RTTC) Alarm Interrupt Enable
#define AT91C_RTTC_RTTINCIEN  (0x1 << 17) // (RTTC) Real Time Timer Increment Interrupt Enable
#define AT91C_RTTC_RTTRST     (0x1 << 18) // (RTTC) Real Time Timer Restart
// -------- RTTC_RTAR : (RTTC Offset: 0x4) Real-time Alarm Register -------- 
#define AT91C_RTTC_ALMV       (0x0 <<  0) // (RTTC) Alarm Value
// -------- RTTC_RTVR : (RTTC Offset: 0x8) Current Real-time Value Register -------- 
#define AT91C_RTTC_CRTV       (0x0 <<  0) // (RTTC) Current Real-time Value
// -------- RTTC_RTSR : (RTTC Offset: 0xc) Real-time Status Register -------- 
#define AT91C_RTTC_ALMS       (0x1 <<  0) // (RTTC) Real-time Alarm Status
#define AT91C_RTTC_RTTINC     (0x1 <<  1) // (RTTC) Real-time Timer Increment

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Watchdog Timer Controller Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_WDTC {
	AT91_REG	 WDTC_WDCR; 	// Watchdog Control Register
	AT91_REG	 WDTC_WDMR; 	// Watchdog Mode Register
	AT91_REG	 WDTC_WDSR; 	// Watchdog Status Register
} AT91S_WDTC, *AT91PS_WDTC;
#else
#define WDTC_WDCR       (AT91_CAST(AT91_REG *) 	0x00000000) // (WDTC_WDCR) Watchdog Control Register
#define WDTC_WDMR       (AT91_CAST(AT91_REG *) 	0x00000004) // (WDTC_WDMR) Watchdog Mode Register
#define WDTC_WDSR       (AT91_CAST(AT91_REG *) 	0x00000008) // (WDTC_WDSR) Watchdog Status Register

#endif
// -------- WDTC_WDCR : (WDTC Offset: 0x0) Periodic Interval Image Register -------- 
#define AT91C_WDTC_WDRSTT     (0x1 <<  0) // (WDTC) Watchdog Restart
#define AT91C_WDTC_KEY        (0xFF << 24) // (WDTC) Watchdog KEY Password
// -------- WDTC_WDMR : (WDTC Offset: 0x4) Watchdog Mode Register -------- 
#define AT91C_WDTC_WDV        (0xFFF <<  0) // (WDTC) Watchdog Timer Restart
#define AT91C_WDTC_WDFIEN     (0x1 << 12) // (WDTC) Watchdog Fault Interrupt Enable
#define AT91C_WDTC_WDRSTEN    (0x1 << 13) // (WDTC) Watchdog Reset Enable
#define AT91C_WDTC_WDRPROC    (0x1 << 14) // (WDTC) Watchdog Timer Restart
#define AT91C_WDTC_WDDIS      (0x1 << 15) // (WDTC) Watchdog Disable
#define AT91C_WDTC_WDD        (0xFFF << 16) // (WDTC) Watchdog Delta Value
#define AT91C_WDTC_WDDBGHLT   (0x1 << 28) // (WDTC) Watchdog Debug Halt
#define AT91C_WDTC_WDIDLEHLT  (0x1 << 29) // (WDTC) Watchdog Idle Halt
// -------- WDTC_WDSR : (WDTC Offset: 0x8) Watchdog Status Register -------- 
#define AT91C_WDTC_WDUNF      (0x1 <<  0) // (WDTC) Watchdog Underflow
#define AT91C_WDTC_WDERR      (0x1 <<  1) // (WDTC) Watchdog Error

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Power Management Controler
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_PMC {
	AT91_REG	 PMC_SCER; 	// System Clock Enable Register
	AT91_REG	 PMC_SCDR; 	// System Clock Disable Register
	AT91_REG	 PMC_SCSR; 	// System Clock Status Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 PMC_PCER; 	// Peripheral Clock Enable Register 0:31 PERI_ID
	AT91_REG	 PMC_PCDR; 	// Peripheral Clock Disable Register 0:31 PERI_ID
	AT91_REG	 PMC_PCSR; 	// Peripheral Clock Status Register 0:31 PERI_ID
	AT91_REG	 PMC_UCKR; 	// UTMI Clock Configuration Register
	AT91_REG	 PMC_MOR; 	// Main Oscillator Register
	AT91_REG	 PMC_MCFR; 	// Main Clock  Frequency Register
	AT91_REG	 PMC_PLLAR; 	// PLL Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 PMC_MCKR; 	// Master Clock Register
	AT91_REG	 Reserved2[3]; 	// 
	AT91_REG	 PMC_PCKR[8]; 	// Programmable Clock Register
	AT91_REG	 PMC_IER; 	// Interrupt Enable Register
	AT91_REG	 PMC_IDR; 	// Interrupt Disable Register
	AT91_REG	 PMC_SR; 	// Status Register
	AT91_REG	 PMC_IMR; 	// Interrupt Mask Register
	AT91_REG	 PMC_FSMR; 	// Fast Startup Mode Register
	AT91_REG	 PMC_FSPR; 	// Fast Startup Polarity Register
	AT91_REG	 PMC_FOCR; 	// Fault Output Clear Register
	AT91_REG	 Reserved3[33]; 	// 
	AT91_REG	 PMC_PCER1; 	// Peripheral Clock Enable Register 32:63 PERI_ID
	AT91_REG	 PMC_PCDR1; 	// Peripheral Clock Disable Register 32:63 PERI_ID
	AT91_REG	 PMC_PCSR1; 	// Peripheral Clock Status Register 32:63 PERI_ID
} AT91S_PMC, *AT91PS_PMC;
#else
#define PMC_SCER        (AT91_CAST(AT91_REG *) 	0x00000000) // (PMC_SCER) System Clock Enable Register
#define PMC_SCDR        (AT91_CAST(AT91_REG *) 	0x00000004) // (PMC_SCDR) System Clock Disable Register
#define PMC_SCSR        (AT91_CAST(AT91_REG *) 	0x00000008) // (PMC_SCSR) System Clock Status Register
#define PMC_PCER        (AT91_CAST(AT91_REG *) 	0x00000010) // (PMC_PCER) Peripheral Clock Enable Register 0:31 PERI_ID
#define PMC_PCDR        (AT91_CAST(AT91_REG *) 	0x00000014) // (PMC_PCDR) Peripheral Clock Disable Register 0:31 PERI_ID
#define PMC_PCSR        (AT91_CAST(AT91_REG *) 	0x00000018) // (PMC_PCSR) Peripheral Clock Status Register 0:31 PERI_ID
#define PMC_MCKR        (AT91_CAST(AT91_REG *) 	0x00000030) // (PMC_MCKR) Master Clock Register
#define PMC_PCKR        (AT91_CAST(AT91_REG *) 	0x00000040) // (PMC_PCKR) Programmable Clock Register
#define PMC_IER         (AT91_CAST(AT91_REG *) 	0x00000060) // (PMC_IER) Interrupt Enable Register
#define PMC_IDR         (AT91_CAST(AT91_REG *) 	0x00000064) // (PMC_IDR) Interrupt Disable Register
#define PMC_SR          (AT91_CAST(AT91_REG *) 	0x00000068) // (PMC_SR) Status Register
#define PMC_IMR         (AT91_CAST(AT91_REG *) 	0x0000006C) // (PMC_IMR) Interrupt Mask Register
#define PMC_FSMR        (AT91_CAST(AT91_REG *) 	0x00000070) // (PMC_FSMR) Fast Startup Mode Register
#define PMC_FSPR        (AT91_CAST(AT91_REG *) 	0x00000074) // (PMC_FSPR) Fast Startup Polarity Register
#define PMC_FOCR        (AT91_CAST(AT91_REG *) 	0x00000078) // (PMC_FOCR) Fault Output Clear Register
#define PMC_PCER1       (AT91_CAST(AT91_REG *) 	0x00000100) // (PMC_PCER1) Peripheral Clock Enable Register 32:63 PERI_ID
#define PMC_PCDR1       (AT91_CAST(AT91_REG *) 	0x00000104) // (PMC_PCDR1) Peripheral Clock Disable Register 32:63 PERI_ID
#define PMC_PCSR1       (AT91_CAST(AT91_REG *) 	0x00000108) // (PMC_PCSR1) Peripheral Clock Status Register 32:63 PERI_ID

#endif
// -------- PMC_SCER : (PMC Offset: 0x0) System Clock Enable Register -------- 
#define AT91C_PMC_PCK         (0x1 <<  0) // (PMC) Processor Clock
#define AT91C_PMC_PCK0        (0x1 <<  8) // (PMC) Programmable Clock Output
#define AT91C_PMC_PCK1        (0x1 <<  9) // (PMC) Programmable Clock Output
#define AT91C_PMC_PCK2        (0x1 << 10) // (PMC) Programmable Clock Output
// -------- PMC_SCDR : (PMC Offset: 0x4) System Clock Disable Register -------- 
// -------- PMC_SCSR : (PMC Offset: 0x8) System Clock Status Register -------- 
// -------- CKGR_UCKR : (PMC Offset: 0x1c) UTMI Clock Configuration Register -------- 
// -------- CKGR_MOR : (PMC Offset: 0x20) Main Oscillator Register -------- 
// -------- CKGR_MCFR : (PMC Offset: 0x24) Main Clock Frequency Register -------- 
// -------- CKGR_PLLAR : (PMC Offset: 0x28) PLL A Register -------- 
// -------- PMC_MCKR : (PMC Offset: 0x30) Master Clock Register -------- 
#define AT91C_PMC_CSS         (0x7 <<  0) // (PMC) Programmable Clock Selection
#define 	AT91C_PMC_CSS_SLOW_CLK             (0x0) // (PMC) Slow Clock is selected
#define 	AT91C_PMC_CSS_MAIN_CLK             (0x1) // (PMC) Main Clock is selected
#define 	AT91C_PMC_CSS_PLLA_CLK             (0x2) // (PMC) Clock from PLL A is selected
#define 	AT91C_PMC_CSS_UPLL_CLK             (0x3) // (PMC) Clock from UPLL is selected
#define 	AT91C_PMC_CSS_SYS_CLK              (0x4) // (PMC) System clock is selected
#define AT91C_PMC_PRES        (0x7 <<  4) // (PMC) Programmable Clock Prescaler
#define 	AT91C_PMC_PRES_CLK                  (0x0 <<  4) // (PMC) Selected clock
#define 	AT91C_PMC_PRES_CLK_2                (0x1 <<  4) // (PMC) Selected clock divided by 2
#define 	AT91C_PMC_PRES_CLK_4                (0x2 <<  4) // (PMC) Selected clock divided by 4
#define 	AT91C_PMC_PRES_CLK_8                (0x3 <<  4) // (PMC) Selected clock divided by 8
#define 	AT91C_PMC_PRES_CLK_16               (0x4 <<  4) // (PMC) Selected clock divided by 16
#define 	AT91C_PMC_PRES_CLK_32               (0x5 <<  4) // (PMC) Selected clock divided by 32
#define 	AT91C_PMC_PRES_CLK_64               (0x6 <<  4) // (PMC) Selected clock divided by 64
#define 	AT91C_PMC_PRES_CLK_6                (0x7 <<  4) // (PMC) Selected clock divided by 6
// -------- PMC_PCKR : (PMC Offset: 0x40) Programmable Clock Register -------- 
// -------- PMC_IER : (PMC Offset: 0x60) PMC Interrupt Enable Register -------- 
#define AT91C_PMC_MOSCXTS     (0x1 <<  0) // (PMC) Main Crystal Oscillator Status/Enable/Disable/Mask
#define AT91C_PMC_LOCKA       (0x1 <<  1) // (PMC) PLL A Status/Enable/Disable/Mask
#define AT91C_PMC_MCKRDY      (0x1 <<  3) // (PMC) Master Clock Status/Enable/Disable/Mask
#define AT91C_PMC_LOCKU       (0x1 <<  6) // (PMC) PLL UTMI Status/Enable/Disable/Mask
#define AT91C_PMC_PCKRDY0     (0x1 <<  8) // (PMC) PCK0_RDY Status/Enable/Disable/Mask
#define AT91C_PMC_PCKRDY1     (0x1 <<  9) // (PMC) PCK1_RDY Status/Enable/Disable/Mask
#define AT91C_PMC_PCKRDY2     (0x1 << 10) // (PMC) PCK2_RDY Status/Enable/Disable/Mask
#define AT91C_PMC_MOSCSELS    (0x1 << 16) // (PMC) Main Oscillator Selection Status
#define AT91C_PMC_MOSCRCS     (0x1 << 17) // (PMC) Main On-Chip RC Oscillator Status
#define AT91C_PMC_CFDEV       (0x1 << 18) // (PMC) Clock Failure Detector Event
// -------- PMC_IDR : (PMC Offset: 0x64) PMC Interrupt Disable Register -------- 
// -------- PMC_SR : (PMC Offset: 0x68) PMC Status Register -------- 
#define AT91C_PMC_CFDS        (0x1 << 19) // (PMC) Clock Failure Detector Status
#define AT91C_PMC_FOS         (0x1 << 20) // (PMC) Clock Failure Detector Fault Output Status
// -------- PMC_IMR : (PMC Offset: 0x6c) PMC Interrupt Mask Register -------- 
// -------- PMC_FSMR : (PMC Offset: 0x70) Fast Startup Mode Register -------- 
#define AT91C_PMC_FSTT        (0xFFFF <<  0) // (PMC) Fast Start-up Input Enable 0 to 15
#define AT91C_PMC_RTTAL       (0x1 << 16) // (PMC) RTT Alarm Enable
#define AT91C_PMC_RTCAL       (0x1 << 17) // (PMC) RTC Alarm Enable
#define AT91C_PMC_USBAL       (0x1 << 18) // (PMC) USB Alarm Enable
#define AT91C_PMC_LPM         (0x1 << 20) // (PMC) Low Power Mode
// -------- PMC_FSPR : (PMC Offset: 0x74) Fast Startup Polarity Register -------- 
#define AT91C_PMC_FSTP        (0xFFFF <<  0) // (PMC) Fast Start-up Input Polarity 0 to 15
// -------- PMC_FOCR : (PMC Offset: 0x78) Fault Output Clear Register -------- 
#define AT91C_PMC_FOCLR       (0x1 <<  0) // (PMC) Fault Output Clear

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Embedded Flash Controller 2.0
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_EFC {
	AT91_REG	 EFC_FMR; 	// EFC Flash Mode Register
	AT91_REG	 EFC_FCR; 	// EFC Flash Command Register
	AT91_REG	 EFC_FSR; 	// EFC Flash Status Register
	AT91_REG	 EFC_FRR; 	// EFC Flash Result Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 EFC_FVR; 	// EFC Flash Version Register
} AT91S_EFC, *AT91PS_EFC;
#else
#define EFC_FMR         (AT91_CAST(AT91_REG *) 	0x00000000) // (EFC_FMR) EFC Flash Mode Register
#define EFC_FCR         (AT91_CAST(AT91_REG *) 	0x00000004) // (EFC_FCR) EFC Flash Command Register
#define EFC_FSR         (AT91_CAST(AT91_REG *) 	0x00000008) // (EFC_FSR) EFC Flash Status Register
#define EFC_FRR         (AT91_CAST(AT91_REG *) 	0x0000000C) // (EFC_FRR) EFC Flash Result Register
#define EFC_FVR         (AT91_CAST(AT91_REG *) 	0x00000014) // (EFC_FVR) EFC Flash Version Register

#endif
// -------- EFC_FMR : (EFC Offset: 0x0) EFC Flash Mode Register -------- 
#define AT91C_EFC_FRDY        (0x1 <<  0) // (EFC) Ready Interrupt Enable
#define AT91C_EFC_FWS         (0xF <<  8) // (EFC) Flash Wait State.
#define 	AT91C_EFC_FWS_0WS                  (0x0 <<  8) // (EFC) 0 Wait State
#define 	AT91C_EFC_FWS_1WS                  (0x1 <<  8) // (EFC) 1 Wait State
#define 	AT91C_EFC_FWS_2WS                  (0x2 <<  8) // (EFC) 2 Wait States
#define 	AT91C_EFC_FWS_3WS                  (0x3 <<  8) // (EFC) 3 Wait States
// -------- EFC_FCR : (EFC Offset: 0x4) EFC Flash Command Register -------- 
#define AT91C_EFC_FCMD        (0xFF <<  0) // (EFC) Flash Command
#define 	AT91C_EFC_FCMD_GETD                 (0x0) // (EFC) Get Flash Descriptor
#define 	AT91C_EFC_FCMD_WP                   (0x1) // (EFC) Write Page
#define 	AT91C_EFC_FCMD_WPL                  (0x2) // (EFC) Write Page and Lock
#define 	AT91C_EFC_FCMD_EWP                  (0x3) // (EFC) Erase Page and Write Page
#define 	AT91C_EFC_FCMD_EWPL                 (0x4) // (EFC) Erase Page and Write Page then Lock
#define 	AT91C_EFC_FCMD_EA                   (0x5) // (EFC) Erase All
#define 	AT91C_EFC_FCMD_EPL                  (0x6) // (EFC) Erase Plane
#define 	AT91C_EFC_FCMD_EPA                  (0x7) // (EFC) Erase Pages
#define 	AT91C_EFC_FCMD_SLB                  (0x8) // (EFC) Set Lock Bit
#define 	AT91C_EFC_FCMD_CLB                  (0x9) // (EFC) Clear Lock Bit
#define 	AT91C_EFC_FCMD_GLB                  (0xA) // (EFC) Get Lock Bit
#define 	AT91C_EFC_FCMD_SFB                  (0xB) // (EFC) Set Fuse Bit
#define 	AT91C_EFC_FCMD_CFB                  (0xC) // (EFC) Clear Fuse Bit
#define 	AT91C_EFC_FCMD_GFB                  (0xD) // (EFC) Get Fuse Bit
#define 	AT91C_EFC_FCMD_STUI                 (0xE) // (EFC) Start Read Unique ID
#define 	AT91C_EFC_FCMD_SPUI                 (0xF) // (EFC) Stop Read Unique ID
#define AT91C_EFC_FARG        (0xFFFF <<  8) // (EFC) Flash Command Argument
#define AT91C_EFC_FKEY        (0xFF << 24) // (EFC) Flash Writing Protection Key
// -------- EFC_FSR : (EFC Offset: 0x8) EFC Flash Status Register -------- 
#define AT91C_EFC_FRDY_S      (0x1 <<  0) // (EFC) Flash Ready Status
#define AT91C_EFC_FCMDE       (0x1 <<  1) // (EFC) Flash Command Error Status
#define AT91C_EFC_LOCKE       (0x1 <<  2) // (EFC) Flash Lock Error Status
// -------- EFC_FRR : (EFC Offset: 0xc) EFC Flash Result Register -------- 
#define AT91C_EFC_FVALUE      (0x0 <<  0) // (EFC) Flash Result Value

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Peripheral DMA Controller
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_PDC {
	AT91_REG	 PDC_RPR; 	// Receive Pointer Register
	AT91_REG	 PDC_RCR; 	// Receive Counter Register
	AT91_REG	 PDC_TPR; 	// Transmit Pointer Register
	AT91_REG	 PDC_TCR; 	// Transmit Counter Register
	AT91_REG	 PDC_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 PDC_RNCR; 	// Receive Next Counter Register
	AT91_REG	 PDC_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 PDC_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 PDC_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 PDC_PTSR; 	// PDC Transfer Status Register
} AT91S_PDC, *AT91PS_PDC;
#else
#define PDC_RPR         (AT91_CAST(AT91_REG *) 	0x00000000) // (PDC_RPR) Receive Pointer Register
#define PDC_RCR         (AT91_CAST(AT91_REG *) 	0x00000004) // (PDC_RCR) Receive Counter Register
#define PDC_TPR         (AT91_CAST(AT91_REG *) 	0x00000008) // (PDC_TPR) Transmit Pointer Register
#define PDC_TCR         (AT91_CAST(AT91_REG *) 	0x0000000C) // (PDC_TCR) Transmit Counter Register
#define PDC_RNPR        (AT91_CAST(AT91_REG *) 	0x00000010) // (PDC_RNPR) Receive Next Pointer Register
#define PDC_RNCR        (AT91_CAST(AT91_REG *) 	0x00000014) // (PDC_RNCR) Receive Next Counter Register
#define PDC_TNPR        (AT91_CAST(AT91_REG *) 	0x00000018) // (PDC_TNPR) Transmit Next Pointer Register
#define PDC_TNCR        (AT91_CAST(AT91_REG *) 	0x0000001C) // (PDC_TNCR) Transmit Next Counter Register
#define PDC_PTCR        (AT91_CAST(AT91_REG *) 	0x00000020) // (PDC_PTCR) PDC Transfer Control Register
#define PDC_PTSR        (AT91_CAST(AT91_REG *) 	0x00000024) // (PDC_PTSR) PDC Transfer Status Register

#endif
// -------- PDC_PTCR : (PDC Offset: 0x20) PDC Transfer Control Register -------- 
#define AT91C_PDC_RXTEN       (0x1 <<  0) // (PDC) Receiver Transfer Enable
#define AT91C_PDC_RXTDIS      (0x1 <<  1) // (PDC) Receiver Transfer Disable
#define AT91C_PDC_TXTEN       (0x1 <<  8) // (PDC) Transmitter Transfer Enable
#define AT91C_PDC_TXTDIS      (0x1 <<  9) // (PDC) Transmitter Transfer Disable
// -------- PDC_PTSR : (PDC Offset: 0x24) PDC Transfer Status Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Debug Unit
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_DBGU {
	AT91_REG	 DBGU_CR; 	// Control Register
	AT91_REG	 DBGU_MR; 	// Mode Register
	AT91_REG	 DBGU_IER; 	// Interrupt Enable Register
	AT91_REG	 DBGU_IDR; 	// Interrupt Disable Register
	AT91_REG	 DBGU_IMR; 	// Interrupt Mask Register
	AT91_REG	 DBGU_CSR; 	// Channel Status Register
	AT91_REG	 DBGU_RHR; 	// Receiver Holding Register
	AT91_REG	 DBGU_THR; 	// Transmitter Holding Register
	AT91_REG	 DBGU_BRGR; 	// Baud Rate Generator Register
	AT91_REG	 Reserved0[7]; 	// 
	AT91_REG	 DBGU_CIDR; 	// Chip ID Register
	AT91_REG	 DBGU_EXID; 	// Chip ID Extension Register
	AT91_REG	 DBGU_FNTR; 	// Force NTRST Register
	AT91_REG	 Reserved1[45]; 	// 
	AT91_REG	 DBGU_RPR; 	// Receive Pointer Register
	AT91_REG	 DBGU_RCR; 	// Receive Counter Register
	AT91_REG	 DBGU_TPR; 	// Transmit Pointer Register
	AT91_REG	 DBGU_TCR; 	// Transmit Counter Register
	AT91_REG	 DBGU_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 DBGU_RNCR; 	// Receive Next Counter Register
	AT91_REG	 DBGU_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 DBGU_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 DBGU_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 DBGU_PTSR; 	// PDC Transfer Status Register
} AT91S_DBGU, *AT91PS_DBGU;
#else
#define DBGU_CR         (AT91_CAST(AT91_REG *) 	0x00000000) // (DBGU_CR) Control Register
#define DBGU_MR         (AT91_CAST(AT91_REG *) 	0x00000004) // (DBGU_MR) Mode Register
#define DBGU_IER        (AT91_CAST(AT91_REG *) 	0x00000008) // (DBGU_IER) Interrupt Enable Register
#define DBGU_IDR        (AT91_CAST(AT91_REG *) 	0x0000000C) // (DBGU_IDR) Interrupt Disable Register
#define DBGU_IMR        (AT91_CAST(AT91_REG *) 	0x00000010) // (DBGU_IMR) Interrupt Mask Register
#define DBGU_CSR        (AT91_CAST(AT91_REG *) 	0x00000014) // (DBGU_CSR) Channel Status Register
#define DBGU_RHR        (AT91_CAST(AT91_REG *) 	0x00000018) // (DBGU_RHR) Receiver Holding Register
#define DBGU_THR        (AT91_CAST(AT91_REG *) 	0x0000001C) // (DBGU_THR) Transmitter Holding Register
#define DBGU_BRGR       (AT91_CAST(AT91_REG *) 	0x00000020) // (DBGU_BRGR) Baud Rate Generator Register
#define DBGU_CIDR       (AT91_CAST(AT91_REG *) 	0x00000040) // (DBGU_CIDR) Chip ID Register
#define DBGU_EXID       (AT91_CAST(AT91_REG *) 	0x00000044) // (DBGU_EXID) Chip ID Extension Register
#define DBGU_FNTR       (AT91_CAST(AT91_REG *) 	0x00000048) // (DBGU_FNTR) Force NTRST Register

#endif
// -------- DBGU_CR : (DBGU Offset: 0x0) Debug Unit Control Register -------- 
#define AT91C_US_RSTRX        (0x1 <<  2) // (DBGU) Reset Receiver
#define AT91C_US_RSTTX        (0x1 <<  3) // (DBGU) Reset Transmitter
#define AT91C_US_RXEN         (0x1 <<  4) // (DBGU) Receiver Enable
#define AT91C_US_RXDIS        (0x1 <<  5) // (DBGU) Receiver Disable
#define AT91C_US_TXEN         (0x1 <<  6) // (DBGU) Transmitter Enable
#define AT91C_US_TXDIS        (0x1 <<  7) // (DBGU) Transmitter Disable
#define AT91C_US_RSTSTA       (0x1 <<  8) // (DBGU) Reset Status Bits
// -------- DBGU_MR : (DBGU Offset: 0x4) Debug Unit Mode Register -------- 
#define AT91C_US_PAR          (0x7 <<  9) // (DBGU) Parity type
#define 	AT91C_US_PAR_EVEN                 (0x0 <<  9) // (DBGU) Even Parity
#define 	AT91C_US_PAR_ODD                  (0x1 <<  9) // (DBGU) Odd Parity
#define 	AT91C_US_PAR_SPACE                (0x2 <<  9) // (DBGU) Parity forced to 0 (Space)
#define 	AT91C_US_PAR_MARK                 (0x3 <<  9) // (DBGU) Parity forced to 1 (Mark)
#define 	AT91C_US_PAR_NONE                 (0x4 <<  9) // (DBGU) No Parity
#define 	AT91C_US_PAR_MULTI_DROP           (0x6 <<  9) // (DBGU) Multi-drop mode
#define AT91C_US_CHMODE       (0x3 << 14) // (DBGU) Channel Mode
#define 	AT91C_US_CHMODE_NORMAL               (0x0 << 14) // (DBGU) Normal Mode: The USART channel operates as an RX/TX USART.
#define 	AT91C_US_CHMODE_AUTO                 (0x1 << 14) // (DBGU) Automatic Echo: Receiver Data Input is connected to the TXD pin.
#define 	AT91C_US_CHMODE_LOCAL                (0x2 << 14) // (DBGU) Local Loopback: Transmitter Output Signal is connected to Receiver Input Signal.
#define 	AT91C_US_CHMODE_REMOTE               (0x3 << 14) // (DBGU) Remote Loopback: RXD pin is internally connected to TXD pin.
// -------- DBGU_IER : (DBGU Offset: 0x8) Debug Unit Interrupt Enable Register -------- 
#define AT91C_US_RXRDY        (0x1 <<  0) // (DBGU) RXRDY Interrupt
#define AT91C_US_TXRDY        (0x1 <<  1) // (DBGU) TXRDY Interrupt
#define AT91C_US_ENDRX        (0x1 <<  3) // (DBGU) End of Receive Transfer Interrupt
#define AT91C_US_ENDTX        (0x1 <<  4) // (DBGU) End of Transmit Interrupt
#define AT91C_US_OVRE         (0x1 <<  5) // (DBGU) Overrun Interrupt
#define AT91C_US_FRAME        (0x1 <<  6) // (DBGU) Framing Error Interrupt
#define AT91C_US_PARE         (0x1 <<  7) // (DBGU) Parity Error Interrupt
#define AT91C_US_TXEMPTY      (0x1 <<  9) // (DBGU) TXEMPTY Interrupt
#define AT91C_US_TXBUFE       (0x1 << 11) // (DBGU) TXBUFE Interrupt
#define AT91C_US_RXBUFF       (0x1 << 12) // (DBGU) RXBUFF Interrupt
#define AT91C_US_COMM_TX      (0x1 << 30) // (DBGU) COMM_TX Interrupt
#define AT91C_US_COMM_RX      (0x1 << 31) // (DBGU) COMM_RX Interrupt
// -------- DBGU_IDR : (DBGU Offset: 0xc) Debug Unit Interrupt Disable Register -------- 
// -------- DBGU_IMR : (DBGU Offset: 0x10) Debug Unit Interrupt Mask Register -------- 
// -------- DBGU_CSR : (DBGU Offset: 0x14) Debug Unit Channel Status Register -------- 
// -------- DBGU_FNTR : (DBGU Offset: 0x48) Debug Unit FORCE_NTRST Register -------- 
#define AT91C_US_FORCE_NTRST  (0x1 <<  0) // (DBGU) Force NTRST in JTAG

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR SDRAM Controller Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_SDRAMC {
	AT91_REG	 SDRAMC_MR; 	// SDRAM Controller Mode Register
	AT91_REG	 SDRAMC_TR; 	// SDRAM Controller Refresh Timer Register
	AT91_REG	 SDRAMC_CR; 	// SDRAM Controller Configuration Register
	AT91_REG	 SDRAMC_HSR; 	// SDRAM Controller High Speed Register
	AT91_REG	 SDRAMC_LPR; 	// SDRAM Controller Low Power Register
	AT91_REG	 SDRAMC_IER; 	// SDRAM Controller Interrupt Enable Register
	AT91_REG	 SDRAMC_IDR; 	// SDRAM Controller Interrupt Disable Register
	AT91_REG	 SDRAMC_IMR; 	// SDRAM Controller Interrupt Mask Register
	AT91_REG	 SDRAMC_ISR; 	// SDRAM Controller Interrupt Mask Register
	AT91_REG	 SDRAMC_MDR; 	// SDRAM Memory Device Register
} AT91S_SDRAMC, *AT91PS_SDRAMC;
#else
#define SDRAMC_MR       (AT91_CAST(AT91_REG *) 	0x00000000) // (SDRAMC_MR) SDRAM Controller Mode Register
#define SDRAMC_TR       (AT91_CAST(AT91_REG *) 	0x00000004) // (SDRAMC_TR) SDRAM Controller Refresh Timer Register
#define SDRAMC_CR       (AT91_CAST(AT91_REG *) 	0x00000008) // (SDRAMC_CR) SDRAM Controller Configuration Register
#define SDRAMC_HSR      (AT91_CAST(AT91_REG *) 	0x0000000C) // (SDRAMC_HSR) SDRAM Controller High Speed Register
#define SDRAMC_LPR      (AT91_CAST(AT91_REG *) 	0x00000010) // (SDRAMC_LPR) SDRAM Controller Low Power Register
#define SDRAMC_IER      (AT91_CAST(AT91_REG *) 	0x00000014) // (SDRAMC_IER) SDRAM Controller Interrupt Enable Register
#define SDRAMC_IDR      (AT91_CAST(AT91_REG *) 	0x00000018) // (SDRAMC_IDR) SDRAM Controller Interrupt Disable Register
#define SDRAMC_IMR      (AT91_CAST(AT91_REG *) 	0x0000001C) // (SDRAMC_IMR) SDRAM Controller Interrupt Mask Register
#define SDRAMC_ISR      (AT91_CAST(AT91_REG *) 	0x00000020) // (SDRAMC_ISR) SDRAM Controller Interrupt Mask Register
#define SDRAMC_MDR      (AT91_CAST(AT91_REG *) 	0x00000024) // (SDRAMC_MDR) SDRAM Memory Device Register

#endif
// -------- SDRAMC_MR : (SDRAMC Offset: 0x0) SDRAM Controller Mode Register -------- 
#define AT91C_SDRAMC_MODE     (0xF <<  0) // (SDRAMC) Mode
#define 	AT91C_SDRAMC_MODE_NORMAL_CMD           (0x0) // (SDRAMC) Normal Mode
#define 	AT91C_SDRAMC_MODE_NOP_CMD              (0x1) // (SDRAMC) Issue a NOP Command at every access
#define 	AT91C_SDRAMC_MODE_PRCGALL_CMD          (0x2) // (SDRAMC) Issue a All Banks Precharge Command at every access
#define 	AT91C_SDRAMC_MODE_LMR_CMD              (0x3) // (SDRAMC) Issue a Load Mode Register at every access
#define 	AT91C_SDRAMC_MODE_RFSH_CMD             (0x4) // (SDRAMC) Issue a Refresh
#define 	AT91C_SDRAMC_MODE_EXT_LMR_CMD          (0x5) // (SDRAMC) Issue an Extended Load Mode Register
#define 	AT91C_SDRAMC_MODE_DEEP_CMD             (0x6) // (SDRAMC) Enter Deep Power Mode
// -------- SDRAMC_TR : (SDRAMC Offset: 0x4) SDRAMC Refresh Timer Register -------- 
#define AT91C_SDRAMC_COUNT    (0xFFF <<  0) // (SDRAMC) Refresh Counter
// -------- SDRAMC_CR : (SDRAMC Offset: 0x8) SDRAM Configuration Register -------- 
#define AT91C_SDRAMC_NC       (0x3 <<  0) // (SDRAMC) Number of Column Bits
#define 	AT91C_SDRAMC_NC_8                    (0x0) // (SDRAMC) 8 Bits
#define 	AT91C_SDRAMC_NC_9                    (0x1) // (SDRAMC) 9 Bits
#define 	AT91C_SDRAMC_NC_10                   (0x2) // (SDRAMC) 10 Bits
#define 	AT91C_SDRAMC_NC_11                   (0x3) // (SDRAMC) 11 Bits
#define AT91C_SDRAMC_NR       (0x3 <<  2) // (SDRAMC) Number of Row Bits
#define 	AT91C_SDRAMC_NR_11                   (0x0 <<  2) // (SDRAMC) 11 Bits
#define 	AT91C_SDRAMC_NR_12                   (0x1 <<  2) // (SDRAMC) 12 Bits
#define 	AT91C_SDRAMC_NR_13                   (0x2 <<  2) // (SDRAMC) 13 Bits
#define AT91C_SDRAMC_NB       (0x1 <<  4) // (SDRAMC) Number of Banks
#define 	AT91C_SDRAMC_NB_2_BANKS              (0x0 <<  4) // (SDRAMC) 2 banks
#define 	AT91C_SDRAMC_NB_4_BANKS              (0x1 <<  4) // (SDRAMC) 4 banks
#define AT91C_SDRAMC_CAS      (0x3 <<  5) // (SDRAMC) CAS Latency
#define 	AT91C_SDRAMC_CAS_2                    (0x2 <<  5) // (SDRAMC) 2 cycles
#define 	AT91C_SDRAMC_CAS_3                    (0x3 <<  5) // (SDRAMC) 3 cycles
#define AT91C_SDRAMC_DBW      (0x1 <<  7) // (SDRAMC) Data Bus Width
#define 	AT91C_SDRAMC_DBW_32_BITS              (0x0 <<  7) // (SDRAMC) 32 Bits datas bus
#define 	AT91C_SDRAMC_DBW_16_BITS              (0x1 <<  7) // (SDRAMC) 16 Bits datas bus
#define AT91C_SDRAMC_TWR      (0xF <<  8) // (SDRAMC) Number of Write Recovery Time Cycles
#define 	AT91C_SDRAMC_TWR_0                    (0x0 <<  8) // (SDRAMC) Value :  0
#define 	AT91C_SDRAMC_TWR_1                    (0x1 <<  8) // (SDRAMC) Value :  1
#define 	AT91C_SDRAMC_TWR_2                    (0x2 <<  8) // (SDRAMC) Value :  2
#define 	AT91C_SDRAMC_TWR_3                    (0x3 <<  8) // (SDRAMC) Value :  3
#define 	AT91C_SDRAMC_TWR_4                    (0x4 <<  8) // (SDRAMC) Value :  4
#define 	AT91C_SDRAMC_TWR_5                    (0x5 <<  8) // (SDRAMC) Value :  5
#define 	AT91C_SDRAMC_TWR_6                    (0x6 <<  8) // (SDRAMC) Value :  6
#define 	AT91C_SDRAMC_TWR_7                    (0x7 <<  8) // (SDRAMC) Value :  7
#define 	AT91C_SDRAMC_TWR_8                    (0x8 <<  8) // (SDRAMC) Value :  8
#define 	AT91C_SDRAMC_TWR_9                    (0x9 <<  8) // (SDRAMC) Value :  9
#define 	AT91C_SDRAMC_TWR_10                   (0xA <<  8) // (SDRAMC) Value : 10
#define 	AT91C_SDRAMC_TWR_11                   (0xB <<  8) // (SDRAMC) Value : 11
#define 	AT91C_SDRAMC_TWR_12                   (0xC <<  8) // (SDRAMC) Value : 12
#define 	AT91C_SDRAMC_TWR_13                   (0xD <<  8) // (SDRAMC) Value : 13
#define 	AT91C_SDRAMC_TWR_14                   (0xE <<  8) // (SDRAMC) Value : 14
#define 	AT91C_SDRAMC_TWR_15                   (0xF <<  8) // (SDRAMC) Value : 15
#define AT91C_SDRAMC_TRC      (0xF << 12) // (SDRAMC) Number of RAS Cycle Time Cycles
#define 	AT91C_SDRAMC_TRC_0                    (0x0 << 12) // (SDRAMC) Value :  0
#define 	AT91C_SDRAMC_TRC_1                    (0x1 << 12) // (SDRAMC) Value :  1
#define 	AT91C_SDRAMC_TRC_2                    (0x2 << 12) // (SDRAMC) Value :  2
#define 	AT91C_SDRAMC_TRC_3                    (0x3 << 12) // (SDRAMC) Value :  3
#define 	AT91C_SDRAMC_TRC_4                    (0x4 << 12) // (SDRAMC) Value :  4
#define 	AT91C_SDRAMC_TRC_5                    (0x5 << 12) // (SDRAMC) Value :  5
#define 	AT91C_SDRAMC_TRC_6                    (0x6 << 12) // (SDRAMC) Value :  6
#define 	AT91C_SDRAMC_TRC_7                    (0x7 << 12) // (SDRAMC) Value :  7
#define 	AT91C_SDRAMC_TRC_8                    (0x8 << 12) // (SDRAMC) Value :  8
#define 	AT91C_SDRAMC_TRC_9                    (0x9 << 12) // (SDRAMC) Value :  9
#define 	AT91C_SDRAMC_TRC_10                   (0xA << 12) // (SDRAMC) Value : 10
#define 	AT91C_SDRAMC_TRC_11                   (0xB << 12) // (SDRAMC) Value : 11
#define 	AT91C_SDRAMC_TRC_12                   (0xC << 12) // (SDRAMC) Value : 12
#define 	AT91C_SDRAMC_TRC_13                   (0xD << 12) // (SDRAMC) Value : 13
#define 	AT91C_SDRAMC_TRC_14                   (0xE << 12) // (SDRAMC) Value : 14
#define 	AT91C_SDRAMC_TRC_15                   (0xF << 12) // (SDRAMC) Value : 15
#define AT91C_SDRAMC_TRP      (0xF << 16) // (SDRAMC) Number of RAS Precharge Time Cycles
#define 	AT91C_SDRAMC_TRP_0                    (0x0 << 16) // (SDRAMC) Value :  0
#define 	AT91C_SDRAMC_TRP_1                    (0x1 << 16) // (SDRAMC) Value :  1
#define 	AT91C_SDRAMC_TRP_2                    (0x2 << 16) // (SDRAMC) Value :  2
#define 	AT91C_SDRAMC_TRP_3                    (0x3 << 16) // (SDRAMC) Value :  3
#define 	AT91C_SDRAMC_TRP_4                    (0x4 << 16) // (SDRAMC) Value :  4
#define 	AT91C_SDRAMC_TRP_5                    (0x5 << 16) // (SDRAMC) Value :  5
#define 	AT91C_SDRAMC_TRP_6                    (0x6 << 16) // (SDRAMC) Value :  6
#define 	AT91C_SDRAMC_TRP_7                    (0x7 << 16) // (SDRAMC) Value :  7
#define 	AT91C_SDRAMC_TRP_8                    (0x8 << 16) // (SDRAMC) Value :  8
#define 	AT91C_SDRAMC_TRP_9                    (0x9 << 16) // (SDRAMC) Value :  9
#define 	AT91C_SDRAMC_TRP_10                   (0xA << 16) // (SDRAMC) Value : 10
#define 	AT91C_SDRAMC_TRP_11                   (0xB << 16) // (SDRAMC) Value : 11
#define 	AT91C_SDRAMC_TRP_12                   (0xC << 16) // (SDRAMC) Value : 12
#define 	AT91C_SDRAMC_TRP_13                   (0xD << 16) // (SDRAMC) Value : 13
#define 	AT91C_SDRAMC_TRP_14                   (0xE << 16) // (SDRAMC) Value : 14
#define 	AT91C_SDRAMC_TRP_15                   (0xF << 16) // (SDRAMC) Value : 15
#define AT91C_SDRAMC_TRCD     (0xF << 20) // (SDRAMC) Number of RAS to CAS Delay Cycles
#define 	AT91C_SDRAMC_TRCD_0                    (0x0 << 20) // (SDRAMC) Value :  0
#define 	AT91C_SDRAMC_TRCD_1                    (0x1 << 20) // (SDRAMC) Value :  1
#define 	AT91C_SDRAMC_TRCD_2                    (0x2 << 20) // (SDRAMC) Value :  2
#define 	AT91C_SDRAMC_TRCD_3                    (0x3 << 20) // (SDRAMC) Value :  3
#define 	AT91C_SDRAMC_TRCD_4                    (0x4 << 20) // (SDRAMC) Value :  4
#define 	AT91C_SDRAMC_TRCD_5                    (0x5 << 20) // (SDRAMC) Value :  5
#define 	AT91C_SDRAMC_TRCD_6                    (0x6 << 20) // (SDRAMC) Value :  6
#define 	AT91C_SDRAMC_TRCD_7                    (0x7 << 20) // (SDRAMC) Value :  7
#define 	AT91C_SDRAMC_TRCD_8                    (0x8 << 20) // (SDRAMC) Value :  8
#define 	AT91C_SDRAMC_TRCD_9                    (0x9 << 20) // (SDRAMC) Value :  9
#define 	AT91C_SDRAMC_TRCD_10                   (0xA << 20) // (SDRAMC) Value : 10
#define 	AT91C_SDRAMC_TRCD_11                   (0xB << 20) // (SDRAMC) Value : 11
#define 	AT91C_SDRAMC_TRCD_12                   (0xC << 20) // (SDRAMC) Value : 12
#define 	AT91C_SDRAMC_TRCD_13                   (0xD << 20) // (SDRAMC) Value : 13
#define 	AT91C_SDRAMC_TRCD_14                   (0xE << 20) // (SDRAMC) Value : 14
#define 	AT91C_SDRAMC_TRCD_15                   (0xF << 20) // (SDRAMC) Value : 15
#define AT91C_SDRAMC_TRAS     (0xF << 24) // (SDRAMC) Number of RAS Active Time Cycles
#define 	AT91C_SDRAMC_TRAS_0                    (0x0 << 24) // (SDRAMC) Value :  0
#define 	AT91C_SDRAMC_TRAS_1                    (0x1 << 24) // (SDRAMC) Value :  1
#define 	AT91C_SDRAMC_TRAS_2                    (0x2 << 24) // (SDRAMC) Value :  2
#define 	AT91C_SDRAMC_TRAS_3                    (0x3 << 24) // (SDRAMC) Value :  3
#define 	AT91C_SDRAMC_TRAS_4                    (0x4 << 24) // (SDRAMC) Value :  4
#define 	AT91C_SDRAMC_TRAS_5                    (0x5 << 24) // (SDRAMC) Value :  5
#define 	AT91C_SDRAMC_TRAS_6                    (0x6 << 24) // (SDRAMC) Value :  6
#define 	AT91C_SDRAMC_TRAS_7                    (0x7 << 24) // (SDRAMC) Value :  7
#define 	AT91C_SDRAMC_TRAS_8                    (0x8 << 24) // (SDRAMC) Value :  8
#define 	AT91C_SDRAMC_TRAS_9                    (0x9 << 24) // (SDRAMC) Value :  9
#define 	AT91C_SDRAMC_TRAS_10                   (0xA << 24) // (SDRAMC) Value : 10
#define 	AT91C_SDRAMC_TRAS_11                   (0xB << 24) // (SDRAMC) Value : 11
#define 	AT91C_SDRAMC_TRAS_12                   (0xC << 24) // (SDRAMC) Value : 12
#define 	AT91C_SDRAMC_TRAS_13                   (0xD << 24) // (SDRAMC) Value : 13
#define 	AT91C_SDRAMC_TRAS_14                   (0xE << 24) // (SDRAMC) Value : 14
#define 	AT91C_SDRAMC_TRAS_15                   (0xF << 24) // (SDRAMC) Value : 15
#define AT91C_SDRAMC_TXSR     (0xF << 28) // (SDRAMC) Number of Command Recovery Time Cycles
#define 	AT91C_SDRAMC_TXSR_0                    (0x0 << 28) // (SDRAMC) Value :  0
#define 	AT91C_SDRAMC_TXSR_1                    (0x1 << 28) // (SDRAMC) Value :  1
#define 	AT91C_SDRAMC_TXSR_2                    (0x2 << 28) // (SDRAMC) Value :  2
#define 	AT91C_SDRAMC_TXSR_3                    (0x3 << 28) // (SDRAMC) Value :  3
#define 	AT91C_SDRAMC_TXSR_4                    (0x4 << 28) // (SDRAMC) Value :  4
#define 	AT91C_SDRAMC_TXSR_5                    (0x5 << 28) // (SDRAMC) Value :  5
#define 	AT91C_SDRAMC_TXSR_6                    (0x6 << 28) // (SDRAMC) Value :  6
#define 	AT91C_SDRAMC_TXSR_7                    (0x7 << 28) // (SDRAMC) Value :  7
#define 	AT91C_SDRAMC_TXSR_8                    (0x8 << 28) // (SDRAMC) Value :  8
#define 	AT91C_SDRAMC_TXSR_9                    (0x9 << 28) // (SDRAMC) Value :  9
#define 	AT91C_SDRAMC_TXSR_10                   (0xA << 28) // (SDRAMC) Value : 10
#define 	AT91C_SDRAMC_TXSR_11                   (0xB << 28) // (SDRAMC) Value : 11
#define 	AT91C_SDRAMC_TXSR_12                   (0xC << 28) // (SDRAMC) Value : 12
#define 	AT91C_SDRAMC_TXSR_13                   (0xD << 28) // (SDRAMC) Value : 13
#define 	AT91C_SDRAMC_TXSR_14                   (0xE << 28) // (SDRAMC) Value : 14
#define 	AT91C_SDRAMC_TXSR_15                   (0xF << 28) // (SDRAMC) Value : 15
// -------- SDRAMC_HSR : (SDRAMC Offset: 0xc) SDRAM Controller High Speed Register -------- 
#define AT91C_SDRAMC_DA       (0x1 <<  0) // (SDRAMC) Decode Cycle Enable Bit
#define 	AT91C_SDRAMC_DA_DISABLE              (0x0) // (SDRAMC) Disable Decode Cycle
#define 	AT91C_SDRAMC_DA_ENABLE               (0x1) // (SDRAMC) Enable Decode Cycle
// -------- SDRAMC_LPR : (SDRAMC Offset: 0x10) SDRAM Controller Low-power Register -------- 
#define AT91C_SDRAMC_LPCB     (0x3 <<  0) // (SDRAMC) Low-power Configurations
#define 	AT91C_SDRAMC_LPCB_DISABLE              (0x0) // (SDRAMC) Disable Low Power Features
#define 	AT91C_SDRAMC_LPCB_SELF_REFRESH         (0x1) // (SDRAMC) Enable SELF_REFRESH
#define 	AT91C_SDRAMC_LPCB_POWER_DOWN           (0x2) // (SDRAMC) Enable POWER_DOWN
#define 	AT91C_SDRAMC_LPCB_DEEP_POWER_DOWN      (0x3) // (SDRAMC) Enable DEEP_POWER_DOWN
#define AT91C_SDRAMC_PASR     (0x7 <<  4) // (SDRAMC) Partial Array Self Refresh (only for Low Power SDRAM)
#define AT91C_SDRAMC_TCSR     (0x3 <<  8) // (SDRAMC) Temperature Compensated Self Refresh (only for Low Power SDRAM)
#define AT91C_SDRAMC_DS       (0x3 << 10) // (SDRAMC) Drive Strenght (only for Low Power SDRAM)
#define AT91C_SDRAMC_TIMEOUT  (0x3 << 12) // (SDRAMC) Time to define when Low Power Mode is enabled
#define 	AT91C_SDRAMC_TIMEOUT_0_CLK_CYCLES         (0x0 << 12) // (SDRAMC) Activate SDRAM Low Power Mode Immediately
#define 	AT91C_SDRAMC_TIMEOUT_64_CLK_CYCLES        (0x1 << 12) // (SDRAMC) Activate SDRAM Low Power Mode after 64 clock cycles after the end of the last transfer
#define 	AT91C_SDRAMC_TIMEOUT_128_CLK_CYCLES       (0x2 << 12) // (SDRAMC) Activate SDRAM Low Power Mode after 64 clock cycles after the end of the last transfer
// -------- SDRAMC_IER : (SDRAMC Offset: 0x14) SDRAM Controller Interrupt Enable Register -------- 
#define AT91C_SDRAMC_RES      (0x1 <<  0) // (SDRAMC) Refresh Error Status
// -------- SDRAMC_IDR : (SDRAMC Offset: 0x18) SDRAM Controller Interrupt Disable Register -------- 
// -------- SDRAMC_IMR : (SDRAMC Offset: 0x1c) SDRAM Controller Interrupt Mask Register -------- 
// -------- SDRAMC_ISR : (SDRAMC Offset: 0x20) SDRAM Controller Interrupt Status Register -------- 
// -------- SDRAMC_MDR : (SDRAMC Offset: 0x24) SDRAM Controller Memory Device Register -------- 
#define AT91C_SDRAMC_MD       (0x3 <<  0) // (SDRAMC) Memory Device Type
#define 	AT91C_SDRAMC_MD_SDRAM                (0x0) // (SDRAMC) SDRAM Mode
#define 	AT91C_SDRAMC_MD_LOW_POWER_SDRAM      (0x1) // (SDRAMC) SDRAM Low Power Mode

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Parallel Input Output Controler
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_PIO {
	AT91_REG	 PIO_PER; 	// PIO Enable Register
	AT91_REG	 PIO_PDR; 	// PIO Disable Register
	AT91_REG	 PIO_PSR; 	// PIO Status Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 PIO_OER; 	// Output Enable Register
	AT91_REG	 PIO_ODR; 	// Output Disable Registerr
	AT91_REG	 PIO_OSR; 	// Output Status Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 PIO_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIO_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIO_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved2[1]; 	// 
	AT91_REG	 PIO_SODR; 	// Set Output Data Register
	AT91_REG	 PIO_CODR; 	// Clear Output Data Register
	AT91_REG	 PIO_ODSR; 	// Output Data Status Register
	AT91_REG	 PIO_PDSR; 	// Pin Data Status Register
	AT91_REG	 PIO_IER; 	// Interrupt Enable Register
	AT91_REG	 PIO_IDR; 	// Interrupt Disable Register
	AT91_REG	 PIO_IMR; 	// Interrupt Mask Register
	AT91_REG	 PIO_ISR; 	// Interrupt Status Register
	AT91_REG	 PIO_MDER; 	// Multi-driver Enable Register
	AT91_REG	 PIO_MDDR; 	// Multi-driver Disable Register
	AT91_REG	 PIO_MDSR; 	// Multi-driver Status Register
	AT91_REG	 Reserved3[1]; 	// 
	AT91_REG	 PIO_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIO_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIO_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved4[1]; 	// 
	AT91_REG	 PIO_ABSR; 	// Peripheral AB Select Register
	AT91_REG	 Reserved5[3]; 	// 
	AT91_REG	 PIO_SCIFSR; 	// System Clock Glitch Input Filter Select Register
	AT91_REG	 PIO_DIFSR; 	// Debouncing Input Filter Select Register
	AT91_REG	 PIO_IFDGSR; 	// Glitch or Debouncing Input Filter Clock Selection Status Register
	AT91_REG	 PIO_SCDR; 	// Slow Clock Divider Debouncing Register
	AT91_REG	 Reserved6[4]; 	// 
	AT91_REG	 PIO_OWER; 	// Output Write Enable Register
	AT91_REG	 PIO_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIO_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved7[1]; 	// 
	AT91_REG	 PIO_AIMER; 	// Additional Interrupt Modes Enable Register
	AT91_REG	 PIO_AIMDR; 	// Additional Interrupt Modes Disables Register
	AT91_REG	 PIO_AIMMR; 	// Additional Interrupt Modes Mask Register
	AT91_REG	 Reserved8[1]; 	// 
	AT91_REG	 PIO_ESR; 	// Edge Select Register
	AT91_REG	 PIO_LSR; 	// Level Select Register
	AT91_REG	 PIO_ELSR; 	// Edge/Level Status Register
	AT91_REG	 Reserved9[1]; 	// 
	AT91_REG	 PIO_FELLSR; 	// Falling Edge/Low Level Select Register
	AT91_REG	 PIO_REHLSR; 	// Rising Edge/ High Level Select Register
	AT91_REG	 PIO_FRLHSR; 	// Fall/Rise - Low/High Status Register
	AT91_REG	 Reserved10[1]; 	// 
	AT91_REG	 PIO_LOCKSR; 	// Lock Status Register
	AT91_REG	 Reserved11[6]; 	// 
	AT91_REG	 PIO_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 Reserved12[8]; 	// 
	AT91_REG	 PIO_KER; 	// Keypad Controller Enable Register
	AT91_REG	 PIO_KRCR; 	// Keypad Controller Row Column Register
	AT91_REG	 PIO_KDR; 	// Keypad Controller Debouncing Register
	AT91_REG	 Reserved13[1]; 	// 
	AT91_REG	 PIO_KIER; 	// Keypad Controller Interrupt Enable Register
	AT91_REG	 PIO_KIDR; 	// Keypad Controller Interrupt Disable Register
	AT91_REG	 PIO_KIMR; 	// Keypad Controller Interrupt Mask Register
	AT91_REG	 PIO_KSR; 	// Keypad Controller Status Register
	AT91_REG	 PIO_KKPR; 	// Keypad Controller Key Press Register
	AT91_REG	 PIO_KKRR; 	// Keypad Controller Key Release Register
} AT91S_PIO, *AT91PS_PIO;
#else
#define PIO_PER         (AT91_CAST(AT91_REG *) 	0x00000000) // (PIO_PER) PIO Enable Register
#define PIO_PDR         (AT91_CAST(AT91_REG *) 	0x00000004) // (PIO_PDR) PIO Disable Register
#define PIO_PSR         (AT91_CAST(AT91_REG *) 	0x00000008) // (PIO_PSR) PIO Status Register
#define PIO_OER         (AT91_CAST(AT91_REG *) 	0x00000010) // (PIO_OER) Output Enable Register
#define PIO_ODR         (AT91_CAST(AT91_REG *) 	0x00000014) // (PIO_ODR) Output Disable Registerr
#define PIO_OSR         (AT91_CAST(AT91_REG *) 	0x00000018) // (PIO_OSR) Output Status Register
#define PIO_IFER        (AT91_CAST(AT91_REG *) 	0x00000020) // (PIO_IFER) Input Filter Enable Register
#define PIO_IFDR        (AT91_CAST(AT91_REG *) 	0x00000024) // (PIO_IFDR) Input Filter Disable Register
#define PIO_IFSR        (AT91_CAST(AT91_REG *) 	0x00000028) // (PIO_IFSR) Input Filter Status Register
#define PIO_SODR        (AT91_CAST(AT91_REG *) 	0x00000030) // (PIO_SODR) Set Output Data Register
#define PIO_CODR        (AT91_CAST(AT91_REG *) 	0x00000034) // (PIO_CODR) Clear Output Data Register
#define PIO_ODSR        (AT91_CAST(AT91_REG *) 	0x00000038) // (PIO_ODSR) Output Data Status Register
#define PIO_PDSR        (AT91_CAST(AT91_REG *) 	0x0000003C) // (PIO_PDSR) Pin Data Status Register
#define PIO_IER         (AT91_CAST(AT91_REG *) 	0x00000040) // (PIO_IER) Interrupt Enable Register
#define PIO_IDR         (AT91_CAST(AT91_REG *) 	0x00000044) // (PIO_IDR) Interrupt Disable Register
#define PIO_IMR         (AT91_CAST(AT91_REG *) 	0x00000048) // (PIO_IMR) Interrupt Mask Register
#define PIO_ISR         (AT91_CAST(AT91_REG *) 	0x0000004C) // (PIO_ISR) Interrupt Status Register
#define PIO_MDER        (AT91_CAST(AT91_REG *) 	0x00000050) // (PIO_MDER) Multi-driver Enable Register
#define PIO_MDDR        (AT91_CAST(AT91_REG *) 	0x00000054) // (PIO_MDDR) Multi-driver Disable Register
#define PIO_MDSR        (AT91_CAST(AT91_REG *) 	0x00000058) // (PIO_MDSR) Multi-driver Status Register
#define PIO_PPUDR       (AT91_CAST(AT91_REG *) 	0x00000060) // (PIO_PPUDR) Pull-up Disable Register
#define PIO_PPUER       (AT91_CAST(AT91_REG *) 	0x00000064) // (PIO_PPUER) Pull-up Enable Register
#define PIO_PPUSR       (AT91_CAST(AT91_REG *) 	0x00000068) // (PIO_PPUSR) Pull-up Status Register
#define PIO_ABSR        (AT91_CAST(AT91_REG *) 	0x00000070) // (PIO_ABSR) Peripheral AB Select Register
#define PIO_SCIFSR      (AT91_CAST(AT91_REG *) 	0x00000080) // (PIO_SCIFSR) System Clock Glitch Input Filter Select Register
#define PIO_DIFSR       (AT91_CAST(AT91_REG *) 	0x00000084) // (PIO_DIFSR) Debouncing Input Filter Select Register
#define PIO_IFDGSR      (AT91_CAST(AT91_REG *) 	0x00000088) // (PIO_IFDGSR) Glitch or Debouncing Input Filter Clock Selection Status Register
#define PIO_SCDR        (AT91_CAST(AT91_REG *) 	0x0000008C) // (PIO_SCDR) Slow Clock Divider Debouncing Register
#define PIO_OWER        (AT91_CAST(AT91_REG *) 	0x000000A0) // (PIO_OWER) Output Write Enable Register
#define PIO_OWDR        (AT91_CAST(AT91_REG *) 	0x000000A4) // (PIO_OWDR) Output Write Disable Register
#define PIO_OWSR        (AT91_CAST(AT91_REG *) 	0x000000A8) // (PIO_OWSR) Output Write Status Register
#define PIO_AIMER       (AT91_CAST(AT91_REG *) 	0x000000B0) // (PIO_AIMER) Additional Interrupt Modes Enable Register
#define PIO_AIMDR       (AT91_CAST(AT91_REG *) 	0x000000B4) // (PIO_AIMDR) Additional Interrupt Modes Disables Register
#define PIO_AIMMR       (AT91_CAST(AT91_REG *) 	0x000000B8) // (PIO_AIMMR) Additional Interrupt Modes Mask Register
#define PIO_ESR         (AT91_CAST(AT91_REG *) 	0x000000C0) // (PIO_ESR) Edge Select Register
#define PIO_LSR         (AT91_CAST(AT91_REG *) 	0x000000C4) // (PIO_LSR) Level Select Register
#define PIO_ELSR        (AT91_CAST(AT91_REG *) 	0x000000C8) // (PIO_ELSR) Edge/Level Status Register
#define PIO_FELLSR      (AT91_CAST(AT91_REG *) 	0x000000D0) // (PIO_FELLSR) Falling Edge/Low Level Select Register
#define PIO_REHLSR      (AT91_CAST(AT91_REG *) 	0x000000D4) // (PIO_REHLSR) Rising Edge/ High Level Select Register
#define PIO_FRLHSR      (AT91_CAST(AT91_REG *) 	0x000000D8) // (PIO_FRLHSR) Fall/Rise - Low/High Status Register
#define PIO_LOCKSR      (AT91_CAST(AT91_REG *) 	0x000000E0) // (PIO_LOCKSR) Lock Status Register
#define PIO_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (PIO_VER) PIO VERSION REGISTER 
#define PIO_KER         (AT91_CAST(AT91_REG *) 	0x00000120) // (PIO_KER) Keypad Controller Enable Register
#define PIO_KRCR        (AT91_CAST(AT91_REG *) 	0x00000124) // (PIO_KRCR) Keypad Controller Row Column Register
#define PIO_KDR         (AT91_CAST(AT91_REG *) 	0x00000128) // (PIO_KDR) Keypad Controller Debouncing Register
#define PIO_KIER        (AT91_CAST(AT91_REG *) 	0x00000130) // (PIO_KIER) Keypad Controller Interrupt Enable Register
#define PIO_KIDR        (AT91_CAST(AT91_REG *) 	0x00000134) // (PIO_KIDR) Keypad Controller Interrupt Disable Register
#define PIO_KIMR        (AT91_CAST(AT91_REG *) 	0x00000138) // (PIO_KIMR) Keypad Controller Interrupt Mask Register
#define PIO_KSR         (AT91_CAST(AT91_REG *) 	0x0000013C) // (PIO_KSR) Keypad Controller Status Register
#define PIO_KKPR        (AT91_CAST(AT91_REG *) 	0x00000140) // (PIO_KKPR) Keypad Controller Key Press Register
#define PIO_KKRR        (AT91_CAST(AT91_REG *) 	0x00000144) // (PIO_KKRR) Keypad Controller Key Release Register

#endif
// -------- PIO_KER : (PIO Offset: 0x120) Keypad Controller Enable Register -------- 
#define AT91C_PIO_KCE         (0x1 <<  0) // (PIO) Keypad Controller Enable
// -------- PIO_KRCR : (PIO Offset: 0x124) Keypad Controller Row Column Register -------- 
#define AT91C_PIO_NBR         (0x7 <<  0) // (PIO) Number of Columns of the Keypad Matrix
#define AT91C_PIO_NBC         (0x7 <<  8) // (PIO) Number of Rows of the Keypad Matrix
// -------- PIO_KDR : (PIO Offset: 0x128) Keypad Controller Debouncing Register -------- 
#define AT91C_PIO_DBC         (0x3FF <<  0) // (PIO) Debouncing Value
// -------- PIO_KIER : (PIO Offset: 0x130) Keypad Controller Interrupt Enable Register -------- 
#define AT91C_PIO_KPR         (0x1 <<  0) // (PIO) Key Press Interrupt Enable
#define AT91C_PIO_KRL         (0x1 <<  1) // (PIO) Key Release Interrupt Enable
// -------- PIO_KIDR : (PIO Offset: 0x134) Keypad Controller Interrupt Disable Register -------- 
// -------- PIO_KIMR : (PIO Offset: 0x138) Keypad Controller Interrupt Mask Register -------- 
// -------- PIO_KSR : (PIO Offset: 0x13c) Keypad Controller Status Register -------- 
#define AT91C_PIO_NBKPR       (0x3 <<  8) // (PIO) Number of Simultaneous Key Presses
#define AT91C_PIO_NBKRL       (0x3 << 16) // (PIO) Number of Simultaneous Key Releases
// -------- PIO_KKPR : (PIO Offset: 0x140) Keypad Controller Key Press Register -------- 
#define AT91C_KEY0ROW         (0x7 <<  0) // (PIO) Row index of the first detected Key Press
#define AT91C_KEY0COL         (0x7 <<  4) // (PIO) Column index of the first detected Key Press
#define AT91C_KEY1ROW         (0x7 <<  8) // (PIO) Row index of the second detected Key Press
#define AT91C_KEY1COL         (0x7 << 12) // (PIO) Column index of the second detected Key Press
#define AT91C_KEY2ROW         (0x7 << 16) // (PIO) Row index of the third detected Key Press
#define AT91C_KEY2COL         (0x7 << 20) // (PIO) Column index of the third detected Key Press
#define AT91C_KEY3ROW         (0x7 << 24) // (PIO) Row index of the fourth detected Key Press
#define AT91C_KEY3COL         (0x7 << 28) // (PIO) Column index of the fourth detected Key Press
// -------- PIO_KKRR : (PIO Offset: 0x144) Keypad Controller Key Release Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Usart
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_USART {
	AT91_REG	 US_CR; 	// Control Register
	AT91_REG	 US_MR; 	// Mode Register
	AT91_REG	 US_IER; 	// Interrupt Enable Register
	AT91_REG	 US_IDR; 	// Interrupt Disable Register
	AT91_REG	 US_IMR; 	// Interrupt Mask Register
	AT91_REG	 US_CSR; 	// Channel Status Register
	AT91_REG	 US_RHR; 	// Receiver Holding Register
	AT91_REG	 US_THR; 	// Transmitter Holding Register
	AT91_REG	 US_BRGR; 	// Baud Rate Generator Register
	AT91_REG	 US_RTOR; 	// Receiver Time-out Register
	AT91_REG	 US_TTGR; 	// Transmitter Time-guard Register
	AT91_REG	 Reserved0[5]; 	// 
	AT91_REG	 US_FIDI; 	// FI_DI_Ratio Register
	AT91_REG	 US_NER; 	// Nb Errors Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 US_IF; 	// IRDA_FILTER Register
	AT91_REG	 US_MAN; 	// Manchester Encoder Decoder Register
	AT91_REG	 Reserved2[38]; 	// 
	AT91_REG	 US_ADDRSIZE; 	// US ADDRSIZE REGISTER 
	AT91_REG	 US_IPNAME1; 	// US IPNAME1 REGISTER 
	AT91_REG	 US_IPNAME2; 	// US IPNAME2 REGISTER 
	AT91_REG	 US_FEATURES; 	// US FEATURES REGISTER 
	AT91_REG	 US_VER; 	// VERSION Register
	AT91_REG	 US_RPR; 	// Receive Pointer Register
	AT91_REG	 US_RCR; 	// Receive Counter Register
	AT91_REG	 US_TPR; 	// Transmit Pointer Register
	AT91_REG	 US_TCR; 	// Transmit Counter Register
	AT91_REG	 US_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 US_RNCR; 	// Receive Next Counter Register
	AT91_REG	 US_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 US_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 US_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 US_PTSR; 	// PDC Transfer Status Register
} AT91S_USART, *AT91PS_USART;
#else
#define US_CR           (AT91_CAST(AT91_REG *) 	0x00000000) // (US_CR) Control Register
#define US_MR           (AT91_CAST(AT91_REG *) 	0x00000004) // (US_MR) Mode Register
#define US_IER          (AT91_CAST(AT91_REG *) 	0x00000008) // (US_IER) Interrupt Enable Register
#define US_IDR          (AT91_CAST(AT91_REG *) 	0x0000000C) // (US_IDR) Interrupt Disable Register
#define US_IMR          (AT91_CAST(AT91_REG *) 	0x00000010) // (US_IMR) Interrupt Mask Register
#define US_CSR          (AT91_CAST(AT91_REG *) 	0x00000014) // (US_CSR) Channel Status Register
#define US_RHR          (AT91_CAST(AT91_REG *) 	0x00000018) // (US_RHR) Receiver Holding Register
#define US_THR          (AT91_CAST(AT91_REG *) 	0x0000001C) // (US_THR) Transmitter Holding Register
#define US_BRGR         (AT91_CAST(AT91_REG *) 	0x00000020) // (US_BRGR) Baud Rate Generator Register
#define US_RTOR         (AT91_CAST(AT91_REG *) 	0x00000024) // (US_RTOR) Receiver Time-out Register
#define US_TTGR         (AT91_CAST(AT91_REG *) 	0x00000028) // (US_TTGR) Transmitter Time-guard Register
#define US_FIDI         (AT91_CAST(AT91_REG *) 	0x00000040) // (US_FIDI) FI_DI_Ratio Register
#define US_NER          (AT91_CAST(AT91_REG *) 	0x00000044) // (US_NER) Nb Errors Register
#define US_IF           (AT91_CAST(AT91_REG *) 	0x0000004C) // (US_IF) IRDA_FILTER Register
#define US_MAN          (AT91_CAST(AT91_REG *) 	0x00000050) // (US_MAN) Manchester Encoder Decoder Register
#define US_ADDRSIZE     (AT91_CAST(AT91_REG *) 	0x000000EC) // (US_ADDRSIZE) US ADDRSIZE REGISTER 
#define US_IPNAME1      (AT91_CAST(AT91_REG *) 	0x000000F0) // (US_IPNAME1) US IPNAME1 REGISTER 
#define US_IPNAME2      (AT91_CAST(AT91_REG *) 	0x000000F4) // (US_IPNAME2) US IPNAME2 REGISTER 
#define US_FEATURES     (AT91_CAST(AT91_REG *) 	0x000000F8) // (US_FEATURES) US FEATURES REGISTER 
#define US_VER          (AT91_CAST(AT91_REG *) 	0x000000FC) // (US_VER) VERSION Register

#endif
// -------- US_CR : (USART Offset: 0x0)  Control Register -------- 
#define AT91C_US_STTBRK       (0x1 <<  9) // (USART) Start Break
#define AT91C_US_STPBRK       (0x1 << 10) // (USART) Stop Break
#define AT91C_US_STTTO        (0x1 << 11) // (USART) Start Time-out
#define AT91C_US_SENDA        (0x1 << 12) // (USART) Send Address
#define AT91C_US_RSTIT        (0x1 << 13) // (USART) Reset Iterations
#define AT91C_US_RSTNACK      (0x1 << 14) // (USART) Reset Non Acknowledge
#define AT91C_US_RETTO        (0x1 << 15) // (USART) Rearm Time-out
#define AT91C_US_DTREN        (0x1 << 16) // (USART) Data Terminal ready Enable
#define AT91C_US_DTRDIS       (0x1 << 17) // (USART) Data Terminal ready Disable
#define AT91C_US_RTSEN        (0x1 << 18) // (USART) Request to Send enable
#define AT91C_US_RTSDIS       (0x1 << 19) // (USART) Request to Send Disable
// -------- US_MR : (USART Offset: 0x4)  Mode Register -------- 
#define AT91C_US_USMODE       (0xF <<  0) // (USART) Usart mode
#define 	AT91C_US_USMODE_NORMAL               (0x0) // (USART) Normal
#define 	AT91C_US_USMODE_RS485                (0x1) // (USART) RS485
#define 	AT91C_US_USMODE_HWHSH                (0x2) // (USART) Hardware Handshaking
#define 	AT91C_US_USMODE_MODEM                (0x3) // (USART) Modem
#define 	AT91C_US_USMODE_ISO7816_0            (0x4) // (USART) ISO7816 protocol: T = 0
#define 	AT91C_US_USMODE_ISO7816_1            (0x6) // (USART) ISO7816 protocol: T = 1
#define 	AT91C_US_USMODE_IRDA                 (0x8) // (USART) IrDA
#define AT91C_US_CLKS         (0x3 <<  4) // (USART) Clock Selection (Baud Rate generator Input Clock
#define 	AT91C_US_CLKS_CLOCK                (0x0 <<  4) // (USART) Clock
#define 	AT91C_US_CLKS_FDIV1                (0x1 <<  4) // (USART) fdiv1
#define 	AT91C_US_CLKS_SLOW                 (0x2 <<  4) // (USART) slow_clock (ARM)
#define 	AT91C_US_CLKS_EXT                  (0x3 <<  4) // (USART) External (SCK)
#define AT91C_US_CHRL         (0x3 <<  6) // (USART) Clock Selection (Baud Rate generator Input Clock
#define 	AT91C_US_CHRL_5_BITS               (0x0 <<  6) // (USART) Character Length: 5 bits
#define 	AT91C_US_CHRL_6_BITS               (0x1 <<  6) // (USART) Character Length: 6 bits
#define 	AT91C_US_CHRL_7_BITS               (0x2 <<  6) // (USART) Character Length: 7 bits
#define 	AT91C_US_CHRL_8_BITS               (0x3 <<  6) // (USART) Character Length: 8 bits
#define AT91C_US_SYNC         (0x1 <<  8) // (USART) Synchronous Mode Select
#define AT91C_US_NBSTOP       (0x3 << 12) // (USART) Number of Stop bits
#define 	AT91C_US_NBSTOP_1_BIT                (0x0 << 12) // (USART) 1 stop bit
#define 	AT91C_US_NBSTOP_15_BIT               (0x1 << 12) // (USART) Asynchronous (SYNC=0) 2 stop bits Synchronous (SYNC=1) 2 stop bits
#define 	AT91C_US_NBSTOP_2_BIT                (0x2 << 12) // (USART) 2 stop bits
#define AT91C_US_MSBF         (0x1 << 16) // (USART) Bit Order
#define AT91C_US_MODE9        (0x1 << 17) // (USART) 9-bit Character length
#define AT91C_US_CKLO         (0x1 << 18) // (USART) Clock Output Select
#define AT91C_US_OVER         (0x1 << 19) // (USART) Over Sampling Mode
#define AT91C_US_INACK        (0x1 << 20) // (USART) Inhibit Non Acknowledge
#define AT91C_US_DSNACK       (0x1 << 21) // (USART) Disable Successive NACK
#define AT91C_US_VAR_SYNC     (0x1 << 22) // (USART) Variable synchronization of command/data sync Start Frame Delimiter
#define AT91C_US_MAX_ITER     (0x1 << 24) // (USART) Number of Repetitions
#define AT91C_US_FILTER       (0x1 << 28) // (USART) Receive Line Filter
#define AT91C_US_MANMODE      (0x1 << 29) // (USART) Manchester Encoder/Decoder Enable
#define AT91C_US_MODSYNC      (0x1 << 30) // (USART) Manchester Synchronization mode
#define AT91C_US_ONEBIT       (0x1 << 31) // (USART) Start Frame Delimiter selector
// -------- US_IER : (USART Offset: 0x8)  Interrupt Enable Register -------- 
#define AT91C_US_RXBRK        (0x1 <<  2) // (USART) Break Received/End of Break
#define AT91C_US_TIMEOUT      (0x1 <<  8) // (USART) Receiver Time-out
#define AT91C_US_ITERATION    (0x1 << 10) // (USART) Max number of Repetitions Reached
#define AT91C_US_NACK         (0x1 << 13) // (USART) Non Acknowledge
#define AT91C_US_RIIC         (0x1 << 16) // (USART) Ring INdicator Input Change Flag
#define AT91C_US_DSRIC        (0x1 << 17) // (USART) Data Set Ready Input Change Flag
#define AT91C_US_DCDIC        (0x1 << 18) // (USART) Data Carrier Flag
#define AT91C_US_CTSIC        (0x1 << 19) // (USART) Clear To Send Input Change Flag
#define AT91C_US_MANE         (0x1 << 20) // (USART) Manchester Error Interrupt
// -------- US_IDR : (USART Offset: 0xc)  Interrupt Disable Register -------- 
// -------- US_IMR : (USART Offset: 0x10)  Interrupt Mask Register -------- 
// -------- US_CSR : (USART Offset: 0x14)  Channel Status Register -------- 
#define AT91C_US_RI           (0x1 << 20) // (USART) Image of RI Input
#define AT91C_US_DSR          (0x1 << 21) // (USART) Image of DSR Input
#define AT91C_US_DCD          (0x1 << 22) // (USART) Image of DCD Input
#define AT91C_US_CTS          (0x1 << 23) // (USART) Image of CTS Input
#define AT91C_US_MANERR       (0x1 << 24) // (USART) Manchester Error
// -------- US_MAN : (USART Offset: 0x50) Manchester Encoder Decoder Register -------- 
#define AT91C_US_TX_PL        (0xF <<  0) // (USART) Transmitter Preamble Length
#define AT91C_US_TX_PP        (0x3 <<  8) // (USART) Transmitter Preamble Pattern
#define 	AT91C_US_TX_PP_ALL_ONE              (0x0 <<  8) // (USART) ALL_ONE
#define 	AT91C_US_TX_PP_ALL_ZERO             (0x1 <<  8) // (USART) ALL_ZERO
#define 	AT91C_US_TX_PP_ZERO_ONE             (0x2 <<  8) // (USART) ZERO_ONE
#define 	AT91C_US_TX_PP_ONE_ZERO             (0x3 <<  8) // (USART) ONE_ZERO
#define AT91C_US_TX_MPOL      (0x1 << 12) // (USART) Transmitter Manchester Polarity
#define AT91C_US_RX_PL        (0xF << 16) // (USART) Receiver Preamble Length
#define AT91C_US_RX_PP        (0x3 << 24) // (USART) Receiver Preamble Pattern detected
#define 	AT91C_US_RX_PP_ALL_ONE              (0x0 << 24) // (USART) ALL_ONE
#define 	AT91C_US_RX_PP_ALL_ZERO             (0x1 << 24) // (USART) ALL_ZERO
#define 	AT91C_US_RX_PP_ZERO_ONE             (0x2 << 24) // (USART) ZERO_ONE
#define 	AT91C_US_RX_PP_ONE_ZERO             (0x3 << 24) // (USART) ONE_ZERO
#define AT91C_US_RX_MPOL      (0x1 << 28) // (USART) Receiver Manchester Polarity
#define AT91C_US_DRIFT        (0x1 << 30) // (USART) Drift compensation

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Multimedia Card Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_MCI {
	AT91_REG	 MCI_CR; 	// MCI Control Register
	AT91_REG	 MCI_MR; 	// MCI Mode Register
	AT91_REG	 MCI_DTOR; 	// MCI Data Timeout Register
	AT91_REG	 MCI_SDCR; 	// MCI SD/SDIO Card Register
	AT91_REG	 MCI_ARGR; 	// MCI Argument Register
	AT91_REG	 MCI_CMDR; 	// MCI Command Register
	AT91_REG	 MCI_BLKR; 	// MCI Block Register
	AT91_REG	 MCI_CSTOR; 	// MCI Completion Signal Timeout Register
	AT91_REG	 MCI_RSPR[4]; 	// MCI Response Register
	AT91_REG	 MCI_RDR; 	// MCI Receive Data Register
	AT91_REG	 MCI_TDR; 	// MCI Transmit Data Register
	AT91_REG	 Reserved0[2]; 	// 
	AT91_REG	 MCI_SR; 	// MCI Status Register
	AT91_REG	 MCI_IER; 	// MCI Interrupt Enable Register
	AT91_REG	 MCI_IDR; 	// MCI Interrupt Disable Register
	AT91_REG	 MCI_IMR; 	// MCI Interrupt Mask Register
	AT91_REG	 MCI_DMA; 	// MCI DMA Configuration Register
	AT91_REG	 MCI_CFG; 	// MCI Configuration Register
	AT91_REG	 Reserved1[35]; 	// 
	AT91_REG	 MCI_WPCR; 	// MCI Write Protection Control Register
	AT91_REG	 MCI_WPSR; 	// MCI Write Protection Status Register
	AT91_REG	 MCI_ADDRSIZE; 	// MCI ADDRSIZE REGISTER 
	AT91_REG	 MCI_IPNAME1; 	// MCI IPNAME1 REGISTER 
	AT91_REG	 MCI_IPNAME2; 	// MCI IPNAME2 REGISTER 
	AT91_REG	 MCI_FEATURES; 	// MCI FEATURES REGISTER 
	AT91_REG	 MCI_VER; 	// MCI VERSION REGISTER 
	AT91_REG	 MCI_RPR; 	// Receive Pointer Register
	AT91_REG	 MCI_RCR; 	// Receive Counter Register
	AT91_REG	 MCI_TPR; 	// Transmit Pointer Register
	AT91_REG	 MCI_TCR; 	// Transmit Counter Register
	AT91_REG	 MCI_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 MCI_RNCR; 	// Receive Next Counter Register
	AT91_REG	 MCI_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 MCI_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 MCI_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 MCI_PTSR; 	// PDC Transfer Status Register
	AT91_REG	 Reserved2[54]; 	// 
	AT91_REG	 MCI_FIFO; 	// MCI FIFO Aperture Register
} AT91S_MCI, *AT91PS_MCI;
#else
#define MCI_CR          (AT91_CAST(AT91_REG *) 	0x00000000) // (MCI_CR) MCI Control Register
#define MCI_MR          (AT91_CAST(AT91_REG *) 	0x00000004) // (MCI_MR) MCI Mode Register
#define MCI_DTOR        (AT91_CAST(AT91_REG *) 	0x00000008) // (MCI_DTOR) MCI Data Timeout Register
#define MCI_SDCR        (AT91_CAST(AT91_REG *) 	0x0000000C) // (MCI_SDCR) MCI SD/SDIO Card Register
#define MCI_ARGR        (AT91_CAST(AT91_REG *) 	0x00000010) // (MCI_ARGR) MCI Argument Register
#define MCI_CMDR        (AT91_CAST(AT91_REG *) 	0x00000014) // (MCI_CMDR) MCI Command Register
#define MCI_BLKR        (AT91_CAST(AT91_REG *) 	0x00000018) // (MCI_BLKR) MCI Block Register
#define MCI_CSTOR       (AT91_CAST(AT91_REG *) 	0x0000001C) // (MCI_CSTOR) MCI Completion Signal Timeout Register
#define MCI_RSPR        (AT91_CAST(AT91_REG *) 	0x00000020) // (MCI_RSPR) MCI Response Register
#define MCI_RDR         (AT91_CAST(AT91_REG *) 	0x00000030) // (MCI_RDR) MCI Receive Data Register
#define MCI_TDR         (AT91_CAST(AT91_REG *) 	0x00000034) // (MCI_TDR) MCI Transmit Data Register
#define MCI_SR          (AT91_CAST(AT91_REG *) 	0x00000040) // (MCI_SR) MCI Status Register
#define MCI_IER         (AT91_CAST(AT91_REG *) 	0x00000044) // (MCI_IER) MCI Interrupt Enable Register
#define MCI_IDR         (AT91_CAST(AT91_REG *) 	0x00000048) // (MCI_IDR) MCI Interrupt Disable Register
#define MCI_IMR         (AT91_CAST(AT91_REG *) 	0x0000004C) // (MCI_IMR) MCI Interrupt Mask Register
#define MCI_DMA         (AT91_CAST(AT91_REG *) 	0x00000050) // (MCI_DMA) MCI DMA Configuration Register
#define MCI_CFG         (AT91_CAST(AT91_REG *) 	0x00000054) // (MCI_CFG) MCI Configuration Register
#define MCI_WPCR        (AT91_CAST(AT91_REG *) 	0x000000E4) // (MCI_WPCR) MCI Write Protection Control Register
#define MCI_WPSR        (AT91_CAST(AT91_REG *) 	0x000000E8) // (MCI_WPSR) MCI Write Protection Status Register
#define MCI_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000EC) // (MCI_ADDRSIZE) MCI ADDRSIZE REGISTER 
#define MCI_IPNAME1     (AT91_CAST(AT91_REG *) 	0x000000F0) // (MCI_IPNAME1) MCI IPNAME1 REGISTER 
#define MCI_IPNAME2     (AT91_CAST(AT91_REG *) 	0x000000F4) // (MCI_IPNAME2) MCI IPNAME2 REGISTER 
#define MCI_FEATURES    (AT91_CAST(AT91_REG *) 	0x000000F8) // (MCI_FEATURES) MCI FEATURES REGISTER 
#define MCI_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (MCI_VER) MCI VERSION REGISTER 
#define MCI_FIFO        (AT91_CAST(AT91_REG *) 	0x00000200) // (MCI_FIFO) MCI FIFO Aperture Register

#endif
// -------- MCI_CR : (MCI Offset: 0x0) MCI Control Register -------- 
#define AT91C_MCI_MCIEN       (0x1 <<  0) // (MCI) Multimedia Interface Enable
#define 	AT91C_MCI_MCIEN_0                    (0x0) // (MCI) No effect
#define 	AT91C_MCI_MCIEN_1                    (0x1) // (MCI) Enable the MultiMedia Interface if MCIDIS is 0
#define AT91C_MCI_MCIDIS      (0x1 <<  1) // (MCI) Multimedia Interface Disable
#define 	AT91C_MCI_MCIDIS_0                    (0x0 <<  1) // (MCI) No effect
#define 	AT91C_MCI_MCIDIS_1                    (0x1 <<  1) // (MCI) Disable the MultiMedia Interface
#define AT91C_MCI_PWSEN       (0x1 <<  2) // (MCI) Power Save Mode Enable
#define 	AT91C_MCI_PWSEN_0                    (0x0 <<  2) // (MCI) No effect
#define 	AT91C_MCI_PWSEN_1                    (0x1 <<  2) // (MCI) Enable the Power-saving mode if PWSDIS is 0.
#define AT91C_MCI_PWSDIS      (0x1 <<  3) // (MCI) Power Save Mode Disable
#define 	AT91C_MCI_PWSDIS_0                    (0x0 <<  3) // (MCI) No effect
#define 	AT91C_MCI_PWSDIS_1                    (0x1 <<  3) // (MCI) Disable the Power-saving mode.
#define AT91C_MCI_IOWAITEN    (0x1 <<  4) // (MCI) SDIO Read Wait Enable
#define 	AT91C_MCI_IOWAITEN_0                    (0x0 <<  4) // (MCI) No effect
#define 	AT91C_MCI_IOWAITEN_1                    (0x1 <<  4) // (MCI) Enables the SDIO Read Wait Operation.
#define AT91C_MCI_IOWAITDIS   (0x1 <<  5) // (MCI) SDIO Read Wait Disable
#define 	AT91C_MCI_IOWAITDIS_0                    (0x0 <<  5) // (MCI) No effect
#define 	AT91C_MCI_IOWAITDIS_1                    (0x1 <<  5) // (MCI) Disables the SDIO Read Wait Operation.
#define AT91C_MCI_SWRST       (0x1 <<  7) // (MCI) MCI Software reset
#define 	AT91C_MCI_SWRST_0                    (0x0 <<  7) // (MCI) No effect
#define 	AT91C_MCI_SWRST_1                    (0x1 <<  7) // (MCI) Resets the MCI
// -------- MCI_MR : (MCI Offset: 0x4) MCI Mode Register -------- 
#define AT91C_MCI_CLKDIV      (0xFF <<  0) // (MCI) Clock Divider
#define AT91C_MCI_PWSDIV      (0x7 <<  8) // (MCI) Power Saving Divider
#define AT91C_MCI_RDPROOF     (0x1 << 11) // (MCI) Read Proof Enable
#define 	AT91C_MCI_RDPROOF_DISABLE              (0x0 << 11) // (MCI) Disables Read Proof
#define 	AT91C_MCI_RDPROOF_ENABLE               (0x1 << 11) // (MCI) Enables Read Proof
#define AT91C_MCI_WRPROOF     (0x1 << 12) // (MCI) Write Proof Enable
#define 	AT91C_MCI_WRPROOF_DISABLE              (0x0 << 12) // (MCI) Disables Write Proof
#define 	AT91C_MCI_WRPROOF_ENABLE               (0x1 << 12) // (MCI) Enables Write Proof
#define AT91C_MCI_PDCFBYTE    (0x1 << 13) // (MCI) PDC Force Byte Transfer
#define 	AT91C_MCI_PDCFBYTE_DISABLE              (0x0 << 13) // (MCI) Disables PDC Force Byte Transfer
#define 	AT91C_MCI_PDCFBYTE_ENABLE               (0x1 << 13) // (MCI) Enables PDC Force Byte Transfer
#define AT91C_MCI_PDCPADV     (0x1 << 14) // (MCI) PDC Padding Value
#define AT91C_MCI_PDCMODE     (0x1 << 15) // (MCI) PDC Oriented Mode
#define 	AT91C_MCI_PDCMODE_DISABLE              (0x0 << 15) // (MCI) Disables PDC Transfer
#define 	AT91C_MCI_PDCMODE_ENABLE               (0x1 << 15) // (MCI) Enables PDC Transfer
#define AT91C_MCI_BLKLEN      (0xFFFF << 16) // (MCI) Data Block Length
// -------- MCI_DTOR : (MCI Offset: 0x8) MCI Data Timeout Register -------- 
#define AT91C_MCI_DTOCYC      (0xF <<  0) // (MCI) Data Timeout Cycle Number
#define AT91C_MCI_DTOMUL      (0x7 <<  4) // (MCI) Data Timeout Multiplier
#define 	AT91C_MCI_DTOMUL_1                    (0x0 <<  4) // (MCI) DTOCYC x 1
#define 	AT91C_MCI_DTOMUL_16                   (0x1 <<  4) // (MCI) DTOCYC x 16
#define 	AT91C_MCI_DTOMUL_128                  (0x2 <<  4) // (MCI) DTOCYC x 128
#define 	AT91C_MCI_DTOMUL_256                  (0x3 <<  4) // (MCI) DTOCYC x 256
#define 	AT91C_MCI_DTOMUL_1024                 (0x4 <<  4) // (MCI) DTOCYC x 1024
#define 	AT91C_MCI_DTOMUL_4096                 (0x5 <<  4) // (MCI) DTOCYC x 4096
#define 	AT91C_MCI_DTOMUL_65536                (0x6 <<  4) // (MCI) DTOCYC x 65536
#define 	AT91C_MCI_DTOMUL_1048576              (0x7 <<  4) // (MCI) DTOCYC x 1048576
// -------- MCI_SDCR : (MCI Offset: 0xc) MCI SD Card Register -------- 
#define AT91C_MCI_SCDSEL      (0x3 <<  0) // (MCI) SD Card/SDIO Selector
#define 	AT91C_MCI_SCDSEL_SLOTA                (0x0) // (MCI) Slot A selected
#define 	AT91C_MCI_SCDSEL_SLOTB                (0x1) // (MCI) Slot B selected
#define 	AT91C_MCI_SCDSEL_SLOTC                (0x2) // (MCI) Slot C selected
#define 	AT91C_MCI_SCDSEL_SLOTD                (0x3) // (MCI) Slot D selected
#define AT91C_MCI_SCDBUS      (0x3 <<  6) // (MCI) SDCard/SDIO Bus Width
#define 	AT91C_MCI_SCDBUS_1BIT                 (0x0 <<  6) // (MCI) 1-bit data bus
#define 	AT91C_MCI_SCDBUS_4BITS                (0x2 <<  6) // (MCI) 4-bits data bus
#define 	AT91C_MCI_SCDBUS_8BITS                (0x3 <<  6) // (MCI) 8-bits data bus
// -------- MCI_CMDR : (MCI Offset: 0x14) MCI Command Register -------- 
#define AT91C_MCI_CMDNB       (0x3F <<  0) // (MCI) Command Number
#define AT91C_MCI_RSPTYP      (0x3 <<  6) // (MCI) Response Type
#define 	AT91C_MCI_RSPTYP_NO                   (0x0 <<  6) // (MCI) No response
#define 	AT91C_MCI_RSPTYP_48                   (0x1 <<  6) // (MCI) 48-bit response
#define 	AT91C_MCI_RSPTYP_136                  (0x2 <<  6) // (MCI) 136-bit response
#define 	AT91C_MCI_RSPTYP_R1B                  (0x3 <<  6) // (MCI) R1b response
#define AT91C_MCI_SPCMD       (0x7 <<  8) // (MCI) Special CMD
#define 	AT91C_MCI_SPCMD_NONE                 (0x0 <<  8) // (MCI) Not a special CMD
#define 	AT91C_MCI_SPCMD_INIT                 (0x1 <<  8) // (MCI) Initialization CMD
#define 	AT91C_MCI_SPCMD_SYNC                 (0x2 <<  8) // (MCI) Synchronized CMD
#define 	AT91C_MCI_SPCMD_CE_ATA               (0x3 <<  8) // (MCI) CE-ATA Completion Signal disable CMD
#define 	AT91C_MCI_SPCMD_IT_CMD               (0x4 <<  8) // (MCI) Interrupt command
#define 	AT91C_MCI_SPCMD_IT_REP               (0x5 <<  8) // (MCI) Interrupt response
#define AT91C_MCI_OPDCMD      (0x1 << 11) // (MCI) Open Drain Command
#define 	AT91C_MCI_OPDCMD_PUSHPULL             (0x0 << 11) // (MCI) Push/pull command
#define 	AT91C_MCI_OPDCMD_OPENDRAIN            (0x1 << 11) // (MCI) Open drain command
#define AT91C_MCI_MAXLAT      (0x1 << 12) // (MCI) Maximum Latency for Command to respond
#define 	AT91C_MCI_MAXLAT_5                    (0x0 << 12) // (MCI) 5 cycles maximum latency
#define 	AT91C_MCI_MAXLAT_64                   (0x1 << 12) // (MCI) 64 cycles maximum latency
#define AT91C_MCI_TRCMD       (0x3 << 16) // (MCI) Transfer CMD
#define 	AT91C_MCI_TRCMD_NO                   (0x0 << 16) // (MCI) No transfer
#define 	AT91C_MCI_TRCMD_START                (0x1 << 16) // (MCI) Start transfer
#define 	AT91C_MCI_TRCMD_STOP                 (0x2 << 16) // (MCI) Stop transfer
#define AT91C_MCI_TRDIR       (0x1 << 18) // (MCI) Transfer Direction
#define 	AT91C_MCI_TRDIR_WRITE                (0x0 << 18) // (MCI) Write
#define 	AT91C_MCI_TRDIR_READ                 (0x1 << 18) // (MCI) Read
#define AT91C_MCI_TRTYP       (0x7 << 19) // (MCI) Transfer Type
#define 	AT91C_MCI_TRTYP_BLOCK                (0x0 << 19) // (MCI) MMC/SDCard Single Block Transfer type
#define 	AT91C_MCI_TRTYP_MULTIPLE             (0x1 << 19) // (MCI) MMC/SDCard Multiple Block transfer type
#define 	AT91C_MCI_TRTYP_STREAM               (0x2 << 19) // (MCI) MMC Stream transfer type
#define 	AT91C_MCI_TRTYP_SDIO_BYTE            (0x4 << 19) // (MCI) SDIO Byte transfer type
#define 	AT91C_MCI_TRTYP_SDIO_BLOCK           (0x5 << 19) // (MCI) SDIO Block transfer type
#define AT91C_MCI_IOSPCMD     (0x3 << 24) // (MCI) SDIO Special Command
#define 	AT91C_MCI_IOSPCMD_NONE                 (0x0 << 24) // (MCI) NOT a special command
#define 	AT91C_MCI_IOSPCMD_SUSPEND              (0x1 << 24) // (MCI) SDIO Suspend Command
#define 	AT91C_MCI_IOSPCMD_RESUME               (0x2 << 24) // (MCI) SDIO Resume Command
#define AT91C_MCI_ATACS       (0x1 << 26) // (MCI) ATA with command completion signal
#define 	AT91C_MCI_ATACS_NORMAL               (0x0 << 26) // (MCI) normal operation mode
#define 	AT91C_MCI_ATACS_COMPLETION           (0x1 << 26) // (MCI) completion signal is expected within MCI_CSTOR
// -------- MCI_BLKR : (MCI Offset: 0x18) MCI Block Register -------- 
#define AT91C_MCI_BCNT        (0xFFFF <<  0) // (MCI) MMC/SDIO Block Count / SDIO Byte Count
// -------- MCI_CSTOR : (MCI Offset: 0x1c) MCI Completion Signal Timeout Register -------- 
#define AT91C_MCI_CSTOCYC     (0xF <<  0) // (MCI) Completion Signal Timeout Cycle Number
#define AT91C_MCI_CSTOMUL     (0x7 <<  4) // (MCI) Completion Signal Timeout Multiplier
#define 	AT91C_MCI_CSTOMUL_1                    (0x0 <<  4) // (MCI) CSTOCYC x 1
#define 	AT91C_MCI_CSTOMUL_16                   (0x1 <<  4) // (MCI) CSTOCYC x  16
#define 	AT91C_MCI_CSTOMUL_128                  (0x2 <<  4) // (MCI) CSTOCYC x  128
#define 	AT91C_MCI_CSTOMUL_256                  (0x3 <<  4) // (MCI) CSTOCYC x  256
#define 	AT91C_MCI_CSTOMUL_1024                 (0x4 <<  4) // (MCI) CSTOCYC x  1024
#define 	AT91C_MCI_CSTOMUL_4096                 (0x5 <<  4) // (MCI) CSTOCYC x  4096
#define 	AT91C_MCI_CSTOMUL_65536                (0x6 <<  4) // (MCI) CSTOCYC x  65536
#define 	AT91C_MCI_CSTOMUL_1048576              (0x7 <<  4) // (MCI) CSTOCYC x  1048576
// -------- MCI_SR : (MCI Offset: 0x40) MCI Status Register -------- 
#define AT91C_MCI_CMDRDY      (0x1 <<  0) // (MCI) Command Ready flag
#define AT91C_MCI_RXRDY       (0x1 <<  1) // (MCI) RX Ready flag
#define AT91C_MCI_TXRDY       (0x1 <<  2) // (MCI) TX Ready flag
#define AT91C_MCI_BLKE        (0x1 <<  3) // (MCI) Data Block Transfer Ended flag
#define AT91C_MCI_DTIP        (0x1 <<  4) // (MCI) Data Transfer in Progress flag
#define AT91C_MCI_NOTBUSY     (0x1 <<  5) // (MCI) Data Line Not Busy flag
#define AT91C_MCI_ENDRX       (0x1 <<  6) // (MCI) End of RX Buffer flag
#define AT91C_MCI_ENDTX       (0x1 <<  7) // (MCI) End of TX Buffer flag
#define AT91C_MCI_SDIOIRQA    (0x1 <<  8) // (MCI) SDIO Interrupt for Slot A
#define AT91C_MCI_SDIOIRQB    (0x1 <<  9) // (MCI) SDIO Interrupt for Slot B
#define AT91C_MCI_SDIOIRQC    (0x1 << 10) // (MCI) SDIO Interrupt for Slot C
#define AT91C_MCI_SDIOIRQD    (0x1 << 11) // (MCI) SDIO Interrupt for Slot D
#define AT91C_MCI_SDIOWAIT    (0x1 << 12) // (MCI) SDIO Read Wait operation flag
#define AT91C_MCI_CSRCV       (0x1 << 13) // (MCI) CE-ATA Completion Signal flag
#define AT91C_MCI_RXBUFF      (0x1 << 14) // (MCI) RX Buffer Full flag
#define AT91C_MCI_TXBUFE      (0x1 << 15) // (MCI) TX Buffer Empty flag
#define AT91C_MCI_RINDE       (0x1 << 16) // (MCI) Response Index Error flag
#define AT91C_MCI_RDIRE       (0x1 << 17) // (MCI) Response Direction Error flag
#define AT91C_MCI_RCRCE       (0x1 << 18) // (MCI) Response CRC Error flag
#define AT91C_MCI_RENDE       (0x1 << 19) // (MCI) Response End Bit Error flag
#define AT91C_MCI_RTOE        (0x1 << 20) // (MCI) Response Time-out Error flag
#define AT91C_MCI_DCRCE       (0x1 << 21) // (MCI) data CRC Error flag
#define AT91C_MCI_DTOE        (0x1 << 22) // (MCI) Data timeout Error flag
#define AT91C_MCI_CSTOE       (0x1 << 23) // (MCI) Completion Signal timeout Error flag
#define AT91C_MCI_BLKOVRE     (0x1 << 24) // (MCI) DMA Block Overrun Error flag
#define AT91C_MCI_DMADONE     (0x1 << 25) // (MCI) DMA Transfer Done flag
#define AT91C_MCI_FIFOEMPTY   (0x1 << 26) // (MCI) FIFO Empty flag
#define AT91C_MCI_XFRDONE     (0x1 << 27) // (MCI) Transfer Done flag
#define AT91C_MCI_OVRE        (0x1 << 30) // (MCI) Overrun flag
#define AT91C_MCI_UNRE        (0x1 << 31) // (MCI) Underrun flag
// -------- MCI_IER : (MCI Offset: 0x44) MCI Interrupt Enable Register -------- 
// -------- MCI_IDR : (MCI Offset: 0x48) MCI Interrupt Disable Register -------- 
// -------- MCI_IMR : (MCI Offset: 0x4c) MCI Interrupt Mask Register -------- 
// -------- MCI_DMA : (MCI Offset: 0x50) MCI DMA Configuration Register -------- 
#define AT91C_MCI_OFFSET      (0x3 <<  0) // (MCI) DMA Write Buffer Offset
#define AT91C_MCI_CHKSIZE     (0x7 <<  4) // (MCI) DMA Channel Read/Write Chunk Size
#define 	AT91C_MCI_CHKSIZE_1                    (0x0 <<  4) // (MCI) Number of data transferred is 1
#define 	AT91C_MCI_CHKSIZE_4                    (0x1 <<  4) // (MCI) Number of data transferred is 4
#define 	AT91C_MCI_CHKSIZE_8                    (0x2 <<  4) // (MCI) Number of data transferred is 8
#define 	AT91C_MCI_CHKSIZE_16                   (0x3 <<  4) // (MCI) Number of data transferred is 16
#define 	AT91C_MCI_CHKSIZE_32                   (0x4 <<  4) // (MCI) Number of data transferred is 32
#define AT91C_MCI_DMAEN       (0x1 <<  8) // (MCI) DMA Hardware Handshaking Enable
#define 	AT91C_MCI_DMAEN_DISABLE              (0x0 <<  8) // (MCI) DMA interface is disabled
#define 	AT91C_MCI_DMAEN_ENABLE               (0x1 <<  8) // (MCI) DMA interface is enabled
// -------- MCI_CFG : (MCI Offset: 0x54) MCI Configuration Register -------- 
#define AT91C_MCI_FIFOMODE    (0x1 <<  0) // (MCI) MCI Internal FIFO Control Mode
#define 	AT91C_MCI_FIFOMODE_AMOUNTDATA           (0x0) // (MCI) A write transfer starts when a sufficient amount of datas is written into the FIFO
#define 	AT91C_MCI_FIFOMODE_ONEDATA              (0x1) // (MCI) A write transfer starts as soon as one data is written into the FIFO
#define AT91C_MCI_FERRCTRL    (0x1 <<  4) // (MCI) Flow Error Flag Reset Control Mode
#define 	AT91C_MCI_FERRCTRL_RWCMD                (0x0 <<  4) // (MCI) When an underflow/overflow condition flag is set, a new Write/Read command is needed to reset the flag
#define 	AT91C_MCI_FERRCTRL_READSR               (0x1 <<  4) // (MCI) When an underflow/overflow condition flag is set, a read status resets the flag
#define AT91C_MCI_HSMODE      (0x1 <<  8) // (MCI) High Speed Mode
#define 	AT91C_MCI_HSMODE_DISABLE              (0x0 <<  8) // (MCI) Default Bus Timing Mode
#define 	AT91C_MCI_HSMODE_ENABLE               (0x1 <<  8) // (MCI) High Speed Mode
#define AT91C_MCI_LSYNC       (0x1 << 12) // (MCI) Synchronize on last block
#define 	AT91C_MCI_LSYNC_CURRENT              (0x0 << 12) // (MCI) Pending command sent at end of current data block
#define 	AT91C_MCI_LSYNC_INFINITE             (0x1 << 12) // (MCI) Pending command sent at end of block transfer when transfer length is not infinite
// -------- MCI_WPCR : (MCI Offset: 0xe4) Write Protection Control Register -------- 
#define AT91C_MCI_WP_EN       (0x1 <<  0) // (MCI) Write Protection Enable
#define 	AT91C_MCI_WP_EN_DISABLE              (0x0) // (MCI) Write Operation is disabled (if WP_KEY corresponds)
#define 	AT91C_MCI_WP_EN_ENABLE               (0x1) // (MCI) Write Operation is enabled (if WP_KEY corresponds)
#define AT91C_MCI_WP_KEY      (0xFFFFFF <<  8) // (MCI) Write Protection Key
// -------- MCI_WPSR : (MCI Offset: 0xe8) Write Protection Status Register -------- 
#define AT91C_MCI_WP_VS       (0xF <<  0) // (MCI) Write Protection Violation Status
#define 	AT91C_MCI_WP_VS_NO_VIOLATION         (0x0) // (MCI) No Write Protection Violation detected since last read
#define 	AT91C_MCI_WP_VS_ON_WRITE             (0x1) // (MCI) Write Protection Violation detected since last read
#define 	AT91C_MCI_WP_VS_ON_RESET             (0x2) // (MCI) Software Reset Violation detected since last read
#define 	AT91C_MCI_WP_VS_ON_BOTH              (0x3) // (MCI) Write Protection and Software Reset Violation detected since last read
#define AT91C_MCI_WP_VSRC     (0xF <<  8) // (MCI) Write Protection Violation Source
#define 	AT91C_MCI_WP_VSRC_NO_VIOLATION         (0x0 <<  8) // (MCI) No Write Protection Violation detected since last read
#define 	AT91C_MCI_WP_VSRC_MCI_MR               (0x1 <<  8) // (MCI) Write Protection Violation detected on MCI_MR since last read
#define 	AT91C_MCI_WP_VSRC_MCI_DTOR             (0x2 <<  8) // (MCI) Write Protection Violation detected on MCI_DTOR since last read
#define 	AT91C_MCI_WP_VSRC_MCI_SDCR             (0x3 <<  8) // (MCI) Write Protection Violation detected on MCI_SDCR since last read
#define 	AT91C_MCI_WP_VSRC_MCI_CSTOR            (0x4 <<  8) // (MCI) Write Protection Violation detected on MCI_CSTOR since last read
#define 	AT91C_MCI_WP_VSRC_MCI_DMA              (0x5 <<  8) // (MCI) Write Protection Violation detected on MCI_DMA since last read
#define 	AT91C_MCI_WP_VSRC_MCI_CFG              (0x6 <<  8) // (MCI) Write Protection Violation detected on MCI_CFG since last read
#define 	AT91C_MCI_WP_VSRC_MCI_DEL              (0x7 <<  8) // (MCI) Write Protection Violation detected on MCI_DEL since last read
// -------- MCI_VER : (MCI Offset: 0xfc)  VERSION  Register -------- 
#define AT91C_MCI_VER         (0xF <<  0) // (MCI)  VERSION  Register

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Two-wire Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_TWI {
	AT91_REG	 TWI_CR; 	// Control Register
	AT91_REG	 TWI_MMR; 	// Master Mode Register
	AT91_REG	 TWI_SMR; 	// Slave Mode Register
	AT91_REG	 TWI_IADR; 	// Internal Address Register
	AT91_REG	 TWI_CWGR; 	// Clock Waveform Generator Register
	AT91_REG	 Reserved0[3]; 	// 
	AT91_REG	 TWI_SR; 	// Status Register
	AT91_REG	 TWI_IER; 	// Interrupt Enable Register
	AT91_REG	 TWI_IDR; 	// Interrupt Disable Register
	AT91_REG	 TWI_IMR; 	// Interrupt Mask Register
	AT91_REG	 TWI_RHR; 	// Receive Holding Register
	AT91_REG	 TWI_THR; 	// Transmit Holding Register
	AT91_REG	 Reserved1[45]; 	// 
	AT91_REG	 TWI_ADDRSIZE; 	// TWI ADDRSIZE REGISTER 
	AT91_REG	 TWI_IPNAME1; 	// TWI IPNAME1 REGISTER 
	AT91_REG	 TWI_IPNAME2; 	// TWI IPNAME2 REGISTER 
	AT91_REG	 TWI_FEATURES; 	// TWI FEATURES REGISTER 
	AT91_REG	 TWI_VER; 	// Version Register
	AT91_REG	 TWI_RPR; 	// Receive Pointer Register
	AT91_REG	 TWI_RCR; 	// Receive Counter Register
	AT91_REG	 TWI_TPR; 	// Transmit Pointer Register
	AT91_REG	 TWI_TCR; 	// Transmit Counter Register
	AT91_REG	 TWI_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 TWI_RNCR; 	// Receive Next Counter Register
	AT91_REG	 TWI_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 TWI_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 TWI_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 TWI_PTSR; 	// PDC Transfer Status Register
} AT91S_TWI, *AT91PS_TWI;
#else
#define TWI_CR          (AT91_CAST(AT91_REG *) 	0x00000000) // (TWI_CR) Control Register
#define TWI_MMR         (AT91_CAST(AT91_REG *) 	0x00000004) // (TWI_MMR) Master Mode Register
#define TWI_SMR         (AT91_CAST(AT91_REG *) 	0x00000008) // (TWI_SMR) Slave Mode Register
#define TWI_IADR        (AT91_CAST(AT91_REG *) 	0x0000000C) // (TWI_IADR) Internal Address Register
#define TWI_CWGR        (AT91_CAST(AT91_REG *) 	0x00000010) // (TWI_CWGR) Clock Waveform Generator Register
#define TWI_SR          (AT91_CAST(AT91_REG *) 	0x00000020) // (TWI_SR) Status Register
#define TWI_IER         (AT91_CAST(AT91_REG *) 	0x00000024) // (TWI_IER) Interrupt Enable Register
#define TWI_IDR         (AT91_CAST(AT91_REG *) 	0x00000028) // (TWI_IDR) Interrupt Disable Register
#define TWI_IMR         (AT91_CAST(AT91_REG *) 	0x0000002C) // (TWI_IMR) Interrupt Mask Register
#define TWI_RHR         (AT91_CAST(AT91_REG *) 	0x00000030) // (TWI_RHR) Receive Holding Register
#define TWI_THR         (AT91_CAST(AT91_REG *) 	0x00000034) // (TWI_THR) Transmit Holding Register
#define TWI_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000EC) // (TWI_ADDRSIZE) TWI ADDRSIZE REGISTER 
#define TWI_IPNAME1     (AT91_CAST(AT91_REG *) 	0x000000F0) // (TWI_IPNAME1) TWI IPNAME1 REGISTER 
#define TWI_IPNAME2     (AT91_CAST(AT91_REG *) 	0x000000F4) // (TWI_IPNAME2) TWI IPNAME2 REGISTER 
#define TWI_FEATURES    (AT91_CAST(AT91_REG *) 	0x000000F8) // (TWI_FEATURES) TWI FEATURES REGISTER 
#define TWI_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (TWI_VER) Version Register

#endif
// -------- TWI_CR : (TWI Offset: 0x0) TWI Control Register -------- 
#define AT91C_TWI_START       (0x1 <<  0) // (TWI) Send a START Condition
#define AT91C_TWI_STOP        (0x1 <<  1) // (TWI) Send a STOP Condition
#define AT91C_TWI_MSEN        (0x1 <<  2) // (TWI) TWI Master Transfer Enabled
#define AT91C_TWI_MSDIS       (0x1 <<  3) // (TWI) TWI Master Transfer Disabled
#define AT91C_TWI_SVEN        (0x1 <<  4) // (TWI) TWI Slave mode Enabled
#define AT91C_TWI_SVDIS       (0x1 <<  5) // (TWI) TWI Slave mode Disabled
#define AT91C_TWI_SWRST       (0x1 <<  7) // (TWI) Software Reset
// -------- TWI_MMR : (TWI Offset: 0x4) TWI Master Mode Register -------- 
#define AT91C_TWI_IADRSZ      (0x3 <<  8) // (TWI) Internal Device Address Size
#define 	AT91C_TWI_IADRSZ_NO                   (0x0 <<  8) // (TWI) No internal device address
#define 	AT91C_TWI_IADRSZ_1_BYTE               (0x1 <<  8) // (TWI) One-byte internal device address
#define 	AT91C_TWI_IADRSZ_2_BYTE               (0x2 <<  8) // (TWI) Two-byte internal device address
#define 	AT91C_TWI_IADRSZ_3_BYTE               (0x3 <<  8) // (TWI) Three-byte internal device address
#define AT91C_TWI_MREAD       (0x1 << 12) // (TWI) Master Read Direction
#define AT91C_TWI_DADR        (0x7F << 16) // (TWI) Device Address
// -------- TWI_SMR : (TWI Offset: 0x8) TWI Slave Mode Register -------- 
#define AT91C_TWI_SADR        (0x7F << 16) // (TWI) Slave Address
// -------- TWI_CWGR : (TWI Offset: 0x10) TWI Clock Waveform Generator Register -------- 
#define AT91C_TWI_CLDIV       (0xFF <<  0) // (TWI) Clock Low Divider
#define AT91C_TWI_CHDIV       (0xFF <<  8) // (TWI) Clock High Divider
#define AT91C_TWI_CKDIV       (0x7 << 16) // (TWI) Clock Divider
// -------- TWI_SR : (TWI Offset: 0x20) TWI Status Register -------- 
#define AT91C_TWI_TXCOMP_SLAVE (0x1 <<  0) // (TWI) Transmission Completed
#define AT91C_TWI_TXCOMP_MASTER (0x1 <<  0) // (TWI) Transmission Completed
#define AT91C_TWI_RXRDY       (0x1 <<  1) // (TWI) Receive holding register ReaDY
#define AT91C_TWI_TXRDY_MASTER (0x1 <<  2) // (TWI) Transmit holding register ReaDY
#define AT91C_TWI_TXRDY_SLAVE (0x1 <<  2) // (TWI) Transmit holding register ReaDY
#define AT91C_TWI_SVREAD      (0x1 <<  3) // (TWI) Slave READ (used only in Slave mode)
#define AT91C_TWI_SVACC       (0x1 <<  4) // (TWI) Slave ACCess (used only in Slave mode)
#define AT91C_TWI_GACC        (0x1 <<  5) // (TWI) General Call ACcess (used only in Slave mode)
#define AT91C_TWI_OVRE        (0x1 <<  6) // (TWI) Overrun Error (used only in Master and Multi-master mode)
#define AT91C_TWI_NACK_SLAVE  (0x1 <<  8) // (TWI) Not Acknowledged
#define AT91C_TWI_NACK_MASTER (0x1 <<  8) // (TWI) Not Acknowledged
#define AT91C_TWI_ARBLST_MULTI_MASTER (0x1 <<  9) // (TWI) Arbitration Lost (used only in Multimaster mode)
#define AT91C_TWI_SCLWS       (0x1 << 10) // (TWI) Clock Wait State (used only in Slave mode)
#define AT91C_TWI_EOSACC      (0x1 << 11) // (TWI) End Of Slave ACCess (used only in Slave mode)
#define AT91C_TWI_ENDRX       (0x1 << 12) // (TWI) End of Receiver Transfer
#define AT91C_TWI_ENDTX       (0x1 << 13) // (TWI) End of Receiver Transfer
#define AT91C_TWI_RXBUFF      (0x1 << 14) // (TWI) RXBUFF Interrupt
#define AT91C_TWI_TXBUFE      (0x1 << 15) // (TWI) TXBUFE Interrupt
// -------- TWI_IER : (TWI Offset: 0x24) TWI Interrupt Enable Register -------- 
// -------- TWI_IDR : (TWI Offset: 0x28) TWI Interrupt Disable Register -------- 
// -------- TWI_IMR : (TWI Offset: 0x2c) TWI Interrupt Mask Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Serial Parallel Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_SPI {
	AT91_REG	 SPI_CR; 	// Control Register
	AT91_REG	 SPI_MR; 	// Mode Register
	AT91_REG	 SPI_RDR; 	// Receive Data Register
	AT91_REG	 SPI_TDR; 	// Transmit Data Register
	AT91_REG	 SPI_SR; 	// Status Register
	AT91_REG	 SPI_IER; 	// Interrupt Enable Register
	AT91_REG	 SPI_IDR; 	// Interrupt Disable Register
	AT91_REG	 SPI_IMR; 	// Interrupt Mask Register
	AT91_REG	 Reserved0[4]; 	// 
	AT91_REG	 SPI_CSR[4]; 	// Chip Select Register
	AT91_REG	 Reserved1[48]; 	// 
	AT91_REG	 SPI_RPR; 	// Receive Pointer Register
	AT91_REG	 SPI_RCR; 	// Receive Counter Register
	AT91_REG	 SPI_TPR; 	// Transmit Pointer Register
	AT91_REG	 SPI_TCR; 	// Transmit Counter Register
	AT91_REG	 SPI_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 SPI_RNCR; 	// Receive Next Counter Register
	AT91_REG	 SPI_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 SPI_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 SPI_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 SPI_PTSR; 	// PDC Transfer Status Register
} AT91S_SPI, *AT91PS_SPI;
#else
#define SPI_CR          (AT91_CAST(AT91_REG *) 	0x00000000) // (SPI_CR) Control Register
#define SPI_MR          (AT91_CAST(AT91_REG *) 	0x00000004) // (SPI_MR) Mode Register
#define SPI_RDR         (AT91_CAST(AT91_REG *) 	0x00000008) // (SPI_RDR) Receive Data Register
#define SPI_TDR         (AT91_CAST(AT91_REG *) 	0x0000000C) // (SPI_TDR) Transmit Data Register
#define SPI_SR          (AT91_CAST(AT91_REG *) 	0x00000010) // (SPI_SR) Status Register
#define SPI_IER         (AT91_CAST(AT91_REG *) 	0x00000014) // (SPI_IER) Interrupt Enable Register
#define SPI_IDR         (AT91_CAST(AT91_REG *) 	0x00000018) // (SPI_IDR) Interrupt Disable Register
#define SPI_IMR         (AT91_CAST(AT91_REG *) 	0x0000001C) // (SPI_IMR) Interrupt Mask Register
#define SPI_CSR         (AT91_CAST(AT91_REG *) 	0x00000030) // (SPI_CSR) Chip Select Register

#endif
// -------- SPI_CR : (SPI Offset: 0x0) SPI Control Register -------- 
#define AT91C_SPI_SPIEN       (0x1 <<  0) // (SPI) SPI Enable
#define AT91C_SPI_SPIDIS      (0x1 <<  1) // (SPI) SPI Disable
#define AT91C_SPI_SWRST       (0x1 <<  7) // (SPI) SPI Software reset
#define AT91C_SPI_LASTXFER    (0x1 << 24) // (SPI) SPI Last Transfer
// -------- SPI_MR : (SPI Offset: 0x4) SPI Mode Register -------- 
#define AT91C_SPI_MSTR        (0x1 <<  0) // (SPI) Master/Slave Mode
#define AT91C_SPI_PS          (0x1 <<  1) // (SPI) Peripheral Select
#define 	AT91C_SPI_PS_FIXED                (0x0 <<  1) // (SPI) Fixed Peripheral Select
#define 	AT91C_SPI_PS_VARIABLE             (0x1 <<  1) // (SPI) Variable Peripheral Select
#define AT91C_SPI_PCSDEC      (0x1 <<  2) // (SPI) Chip Select Decode
#define AT91C_SPI_FDIV        (0x1 <<  3) // (SPI) Clock Selection
#define AT91C_SPI_MODFDIS     (0x1 <<  4) // (SPI) Mode Fault Detection
#define AT91C_SPI_LLB         (0x1 <<  7) // (SPI) Clock Selection
#define AT91C_SPI_PCS         (0xF << 16) // (SPI) Peripheral Chip Select
#define AT91C_SPI_DLYBCS      (0xFF << 24) // (SPI) Delay Between Chip Selects
// -------- SPI_RDR : (SPI Offset: 0x8) Receive Data Register -------- 
#define AT91C_SPI_RD          (0xFFFF <<  0) // (SPI) Receive Data
#define AT91C_SPI_RPCS        (0xF << 16) // (SPI) Peripheral Chip Select Status
// -------- SPI_TDR : (SPI Offset: 0xc) Transmit Data Register -------- 
#define AT91C_SPI_TD          (0xFFFF <<  0) // (SPI) Transmit Data
#define AT91C_SPI_TPCS        (0xF << 16) // (SPI) Peripheral Chip Select Status
// -------- SPI_SR : (SPI Offset: 0x10) Status Register -------- 
#define AT91C_SPI_RDRF        (0x1 <<  0) // (SPI) Receive Data Register Full
#define AT91C_SPI_TDRE        (0x1 <<  1) // (SPI) Transmit Data Register Empty
#define AT91C_SPI_MODF        (0x1 <<  2) // (SPI) Mode Fault Error
#define AT91C_SPI_OVRES       (0x1 <<  3) // (SPI) Overrun Error Status
#define AT91C_SPI_ENDRX       (0x1 <<  4) // (SPI) End of Receiver Transfer
#define AT91C_SPI_ENDTX       (0x1 <<  5) // (SPI) End of Receiver Transfer
#define AT91C_SPI_RXBUFF      (0x1 <<  6) // (SPI) RXBUFF Interrupt
#define AT91C_SPI_TXBUFE      (0x1 <<  7) // (SPI) TXBUFE Interrupt
#define AT91C_SPI_NSSR        (0x1 <<  8) // (SPI) NSSR Interrupt
#define AT91C_SPI_TXEMPTY     (0x1 <<  9) // (SPI) TXEMPTY Interrupt
#define AT91C_SPI_SPIENS      (0x1 << 16) // (SPI) Enable Status
// -------- SPI_IER : (SPI Offset: 0x14) Interrupt Enable Register -------- 
// -------- SPI_IDR : (SPI Offset: 0x18) Interrupt Disable Register -------- 
// -------- SPI_IMR : (SPI Offset: 0x1c) Interrupt Mask Register -------- 
// -------- SPI_CSR : (SPI Offset: 0x30) Chip Select Register -------- 
#define AT91C_SPI_CPOL        (0x1 <<  0) // (SPI) Clock Polarity
#define AT91C_SPI_NCPHA       (0x1 <<  1) // (SPI) Clock Phase
#define AT91C_SPI_CSAAT       (0x1 <<  3) // (SPI) Chip Select Active After Transfer
#define AT91C_SPI_BITS        (0xF <<  4) // (SPI) Bits Per Transfer
#define 	AT91C_SPI_BITS_8                    (0x0 <<  4) // (SPI) 8 Bits Per transfer
#define 	AT91C_SPI_BITS_9                    (0x1 <<  4) // (SPI) 9 Bits Per transfer
#define 	AT91C_SPI_BITS_10                   (0x2 <<  4) // (SPI) 10 Bits Per transfer
#define 	AT91C_SPI_BITS_11                   (0x3 <<  4) // (SPI) 11 Bits Per transfer
#define 	AT91C_SPI_BITS_12                   (0x4 <<  4) // (SPI) 12 Bits Per transfer
#define 	AT91C_SPI_BITS_13                   (0x5 <<  4) // (SPI) 13 Bits Per transfer
#define 	AT91C_SPI_BITS_14                   (0x6 <<  4) // (SPI) 14 Bits Per transfer
#define 	AT91C_SPI_BITS_15                   (0x7 <<  4) // (SPI) 15 Bits Per transfer
#define 	AT91C_SPI_BITS_16                   (0x8 <<  4) // (SPI) 16 Bits Per transfer
#define AT91C_SPI_SCBR        (0xFF <<  8) // (SPI) Serial Clock Baud Rate
#define AT91C_SPI_DLYBS       (0xFF << 16) // (SPI) Delay Before SPCK
#define AT91C_SPI_DLYBCT      (0xFF << 24) // (SPI) Delay Between Consecutive Transfers

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Synchronous Serial Controller Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_SSC {
	AT91_REG	 SSC_CR; 	// Control Register
	AT91_REG	 SSC_CMR; 	// Clock Mode Register
	AT91_REG	 Reserved0[2]; 	// 
	AT91_REG	 SSC_RCMR; 	// Receive Clock ModeRegister
	AT91_REG	 SSC_RFMR; 	// Receive Frame Mode Register
	AT91_REG	 SSC_TCMR; 	// Transmit Clock Mode Register
	AT91_REG	 SSC_TFMR; 	// Transmit Frame Mode Register
	AT91_REG	 SSC_RHR; 	// Receive Holding Register
	AT91_REG	 SSC_THR; 	// Transmit Holding Register
	AT91_REG	 Reserved1[2]; 	// 
	AT91_REG	 SSC_RSHR; 	// Receive Sync Holding Register
	AT91_REG	 SSC_TSHR; 	// Transmit Sync Holding Register
	AT91_REG	 Reserved2[2]; 	// 
	AT91_REG	 SSC_SR; 	// Status Register
	AT91_REG	 SSC_IER; 	// Interrupt Enable Register
	AT91_REG	 SSC_IDR; 	// Interrupt Disable Register
	AT91_REG	 SSC_IMR; 	// Interrupt Mask Register
	AT91_REG	 Reserved3[39]; 	// 
	AT91_REG	 SSC_ADDRSIZE; 	// SSC ADDRSIZE REGISTER 
	AT91_REG	 SSC_IPNAME1; 	// SSC IPNAME1 REGISTER 
	AT91_REG	 SSC_IPNAME2; 	// SSC IPNAME2 REGISTER 
	AT91_REG	 SSC_FEATURES; 	// SSC FEATURES REGISTER 
	AT91_REG	 SSC_VER; 	// Version Register
	AT91_REG	 SSC_RPR; 	// Receive Pointer Register
	AT91_REG	 SSC_RCR; 	// Receive Counter Register
	AT91_REG	 SSC_TPR; 	// Transmit Pointer Register
	AT91_REG	 SSC_TCR; 	// Transmit Counter Register
	AT91_REG	 SSC_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 SSC_RNCR; 	// Receive Next Counter Register
	AT91_REG	 SSC_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 SSC_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 SSC_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 SSC_PTSR; 	// PDC Transfer Status Register
} AT91S_SSC, *AT91PS_SSC;
#else
#define SSC_CR          (AT91_CAST(AT91_REG *) 	0x00000000) // (SSC_CR) Control Register
#define SSC_CMR         (AT91_CAST(AT91_REG *) 	0x00000004) // (SSC_CMR) Clock Mode Register
#define SSC_RCMR        (AT91_CAST(AT91_REG *) 	0x00000010) // (SSC_RCMR) Receive Clock ModeRegister
#define SSC_RFMR        (AT91_CAST(AT91_REG *) 	0x00000014) // (SSC_RFMR) Receive Frame Mode Register
#define SSC_TCMR        (AT91_CAST(AT91_REG *) 	0x00000018) // (SSC_TCMR) Transmit Clock Mode Register
#define SSC_TFMR        (AT91_CAST(AT91_REG *) 	0x0000001C) // (SSC_TFMR) Transmit Frame Mode Register
#define SSC_RHR         (AT91_CAST(AT91_REG *) 	0x00000020) // (SSC_RHR) Receive Holding Register
#define SSC_THR         (AT91_CAST(AT91_REG *) 	0x00000024) // (SSC_THR) Transmit Holding Register
#define SSC_RSHR        (AT91_CAST(AT91_REG *) 	0x00000030) // (SSC_RSHR) Receive Sync Holding Register
#define SSC_TSHR        (AT91_CAST(AT91_REG *) 	0x00000034) // (SSC_TSHR) Transmit Sync Holding Register
#define SSC_SR          (AT91_CAST(AT91_REG *) 	0x00000040) // (SSC_SR) Status Register
#define SSC_IER         (AT91_CAST(AT91_REG *) 	0x00000044) // (SSC_IER) Interrupt Enable Register
#define SSC_IDR         (AT91_CAST(AT91_REG *) 	0x00000048) // (SSC_IDR) Interrupt Disable Register
#define SSC_IMR         (AT91_CAST(AT91_REG *) 	0x0000004C) // (SSC_IMR) Interrupt Mask Register
#define SSC_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000EC) // (SSC_ADDRSIZE) SSC ADDRSIZE REGISTER 
#define SSC_IPNAME1     (AT91_CAST(AT91_REG *) 	0x000000F0) // (SSC_IPNAME1) SSC IPNAME1 REGISTER 
#define SSC_IPNAME2     (AT91_CAST(AT91_REG *) 	0x000000F4) // (SSC_IPNAME2) SSC IPNAME2 REGISTER 
#define SSC_FEATURES    (AT91_CAST(AT91_REG *) 	0x000000F8) // (SSC_FEATURES) SSC FEATURES REGISTER 
#define SSC_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (SSC_VER) Version Register

#endif
// -------- SSC_CR : (SSC Offset: 0x0) SSC Control Register -------- 
#define AT91C_SSC_RXEN        (0x1 <<  0) // (SSC) Receive Enable
#define AT91C_SSC_RXDIS       (0x1 <<  1) // (SSC) Receive Disable
#define AT91C_SSC_TXEN        (0x1 <<  8) // (SSC) Transmit Enable
#define AT91C_SSC_TXDIS       (0x1 <<  9) // (SSC) Transmit Disable
#define AT91C_SSC_SWRST       (0x1 << 15) // (SSC) Software Reset
// -------- SSC_RCMR : (SSC Offset: 0x10) SSC Receive Clock Mode Register -------- 
#define AT91C_SSC_CKS         (0x3 <<  0) // (SSC) Receive/Transmit Clock Selection
#define 	AT91C_SSC_CKS_DIV                  (0x0) // (SSC) Divided Clock
#define 	AT91C_SSC_CKS_TK                   (0x1) // (SSC) TK Clock signal
#define 	AT91C_SSC_CKS_RK                   (0x2) // (SSC) RK pin
#define AT91C_SSC_CKO         (0x7 <<  2) // (SSC) Receive/Transmit Clock Output Mode Selection
#define 	AT91C_SSC_CKO_NONE                 (0x0 <<  2) // (SSC) Receive/Transmit Clock Output Mode: None RK pin: Input-only
#define 	AT91C_SSC_CKO_CONTINOUS            (0x1 <<  2) // (SSC) Continuous Receive/Transmit Clock RK pin: Output
#define 	AT91C_SSC_CKO_DATA_TX              (0x2 <<  2) // (SSC) Receive/Transmit Clock only during data transfers RK pin: Output
#define AT91C_SSC_CKI         (0x1 <<  5) // (SSC) Receive/Transmit Clock Inversion
#define AT91C_SSC_CKG         (0x3 <<  6) // (SSC) Receive/Transmit Clock Gating Selection
#define 	AT91C_SSC_CKG_NONE                 (0x0 <<  6) // (SSC) Receive/Transmit Clock Gating: None, continuous clock
#define 	AT91C_SSC_CKG_LOW                  (0x1 <<  6) // (SSC) Receive/Transmit Clock enabled only if RF Low
#define 	AT91C_SSC_CKG_HIGH                 (0x2 <<  6) // (SSC) Receive/Transmit Clock enabled only if RF High
#define AT91C_SSC_START       (0xF <<  8) // (SSC) Receive/Transmit Start Selection
#define 	AT91C_SSC_START_CONTINOUS            (0x0 <<  8) // (SSC) Continuous, as soon as the receiver is enabled, and immediately after the end of transfer of the previous data.
#define 	AT91C_SSC_START_TX                   (0x1 <<  8) // (SSC) Transmit/Receive start
#define 	AT91C_SSC_START_LOW_RF               (0x2 <<  8) // (SSC) Detection of a low level on RF input
#define 	AT91C_SSC_START_HIGH_RF              (0x3 <<  8) // (SSC) Detection of a high level on RF input
#define 	AT91C_SSC_START_FALL_RF              (0x4 <<  8) // (SSC) Detection of a falling edge on RF input
#define 	AT91C_SSC_START_RISE_RF              (0x5 <<  8) // (SSC) Detection of a rising edge on RF input
#define 	AT91C_SSC_START_LEVEL_RF             (0x6 <<  8) // (SSC) Detection of any level change on RF input
#define 	AT91C_SSC_START_EDGE_RF              (0x7 <<  8) // (SSC) Detection of any edge on RF input
#define 	AT91C_SSC_START_0                    (0x8 <<  8) // (SSC) Compare 0
#define AT91C_SSC_STOP        (0x1 << 12) // (SSC) Receive Stop Selection
#define AT91C_SSC_STTDLY      (0xFF << 16) // (SSC) Receive/Transmit Start Delay
#define AT91C_SSC_PERIOD      (0xFF << 24) // (SSC) Receive/Transmit Period Divider Selection
// -------- SSC_RFMR : (SSC Offset: 0x14) SSC Receive Frame Mode Register -------- 
#define AT91C_SSC_DATLEN      (0x1F <<  0) // (SSC) Data Length
#define AT91C_SSC_LOOP        (0x1 <<  5) // (SSC) Loop Mode
#define AT91C_SSC_MSBF        (0x1 <<  7) // (SSC) Most Significant Bit First
#define AT91C_SSC_DATNB       (0xF <<  8) // (SSC) Data Number per Frame
#define AT91C_SSC_FSLEN       (0xF << 16) // (SSC) Receive/Transmit Frame Sync length
#define AT91C_SSC_FSOS        (0x7 << 20) // (SSC) Receive/Transmit Frame Sync Output Selection
#define 	AT91C_SSC_FSOS_NONE                 (0x0 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: None RK pin Input-only
#define 	AT91C_SSC_FSOS_NEGATIVE             (0x1 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Negative Pulse
#define 	AT91C_SSC_FSOS_POSITIVE             (0x2 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Positive Pulse
#define 	AT91C_SSC_FSOS_LOW                  (0x3 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Driver Low during data transfer
#define 	AT91C_SSC_FSOS_HIGH                 (0x4 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Driver High during data transfer
#define 	AT91C_SSC_FSOS_TOGGLE               (0x5 << 20) // (SSC) Selected Receive/Transmit Frame Sync Signal: Toggling at each start of data transfer
#define AT91C_SSC_FSEDGE      (0x1 << 24) // (SSC) Frame Sync Edge Detection
// -------- SSC_TCMR : (SSC Offset: 0x18) SSC Transmit Clock Mode Register -------- 
// -------- SSC_TFMR : (SSC Offset: 0x1c) SSC Transmit Frame Mode Register -------- 
#define AT91C_SSC_DATDEF      (0x1 <<  5) // (SSC) Data Default Value
#define AT91C_SSC_FSDEN       (0x1 << 23) // (SSC) Frame Sync Data Enable
// -------- SSC_SR : (SSC Offset: 0x40) SSC Status Register -------- 
#define AT91C_SSC_TXRDY       (0x1 <<  0) // (SSC) Transmit Ready
#define AT91C_SSC_TXEMPTY     (0x1 <<  1) // (SSC) Transmit Empty
#define AT91C_SSC_ENDTX       (0x1 <<  2) // (SSC) End Of Transmission
#define AT91C_SSC_TXBUFE      (0x1 <<  3) // (SSC) Transmit Buffer Empty
#define AT91C_SSC_RXRDY       (0x1 <<  4) // (SSC) Receive Ready
#define AT91C_SSC_OVRUN       (0x1 <<  5) // (SSC) Receive Overrun
#define AT91C_SSC_ENDRX       (0x1 <<  6) // (SSC) End of Reception
#define AT91C_SSC_RXBUFF      (0x1 <<  7) // (SSC) Receive Buffer Full
#define AT91C_SSC_CP0         (0x1 <<  8) // (SSC) Compare 0
#define AT91C_SSC_CP1         (0x1 <<  9) // (SSC) Compare 1
#define AT91C_SSC_TXSYN       (0x1 << 10) // (SSC) Transmit Sync
#define AT91C_SSC_RXSYN       (0x1 << 11) // (SSC) Receive Sync
#define AT91C_SSC_TXENA       (0x1 << 16) // (SSC) Transmit Enable
#define AT91C_SSC_RXENA       (0x1 << 17) // (SSC) Receive Enable
// -------- SSC_IER : (SSC Offset: 0x44) SSC Interrupt Enable Register -------- 
// -------- SSC_IDR : (SSC Offset: 0x48) SSC Interrupt Disable Register -------- 
// -------- SSC_IMR : (SSC Offset: 0x4c) SSC Interrupt Mask Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Timer Counter Channel Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_TC {
	AT91_REG	 TC_CCR; 	// Channel Control Register
	AT91_REG	 TC_CMR; 	// Channel Mode Register (Capture Mode / Waveform Mode)
	AT91_REG	 Reserved0[2]; 	// 
	AT91_REG	 TC_CV; 	// Counter Value
	AT91_REG	 TC_RA; 	// Register A
	AT91_REG	 TC_RB; 	// Register B
	AT91_REG	 TC_RC; 	// Register C
	AT91_REG	 TC_SR; 	// Status Register
	AT91_REG	 TC_IER; 	// Interrupt Enable Register
	AT91_REG	 TC_IDR; 	// Interrupt Disable Register
	AT91_REG	 TC_IMR; 	// Interrupt Mask Register
} AT91S_TC, *AT91PS_TC;
#else
#define TC_CCR          (AT91_CAST(AT91_REG *) 	0x00000000) // (TC_CCR) Channel Control Register
#define TC_CMR          (AT91_CAST(AT91_REG *) 	0x00000004) // (TC_CMR) Channel Mode Register (Capture Mode / Waveform Mode)
#define TC_CV           (AT91_CAST(AT91_REG *) 	0x00000010) // (TC_CV) Counter Value
#define TC_RA           (AT91_CAST(AT91_REG *) 	0x00000014) // (TC_RA) Register A
#define TC_RB           (AT91_CAST(AT91_REG *) 	0x00000018) // (TC_RB) Register B
#define TC_RC           (AT91_CAST(AT91_REG *) 	0x0000001C) // (TC_RC) Register C
#define TC_SR           (AT91_CAST(AT91_REG *) 	0x00000020) // (TC_SR) Status Register
#define TC_IER          (AT91_CAST(AT91_REG *) 	0x00000024) // (TC_IER) Interrupt Enable Register
#define TC_IDR          (AT91_CAST(AT91_REG *) 	0x00000028) // (TC_IDR) Interrupt Disable Register
#define TC_IMR          (AT91_CAST(AT91_REG *) 	0x0000002C) // (TC_IMR) Interrupt Mask Register

#endif
// -------- TC_CCR : (TC Offset: 0x0) TC Channel Control Register -------- 
#define AT91C_TC_CLKEN        (0x1 <<  0) // (TC) Counter Clock Enable Command
#define AT91C_TC_CLKDIS       (0x1 <<  1) // (TC) Counter Clock Disable Command
#define AT91C_TC_SWTRG        (0x1 <<  2) // (TC) Software Trigger Command
// -------- TC_CMR : (TC Offset: 0x4) TC Channel Mode Register: Capture Mode / Waveform Mode -------- 
#define AT91C_TC_CLKS         (0x7 <<  0) // (TC) Clock Selection
#define 	AT91C_TC_CLKS_TIMER_DIV1_CLOCK     (0x0) // (TC) Clock selected: TIMER_DIV1_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV2_CLOCK     (0x1) // (TC) Clock selected: TIMER_DIV2_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV3_CLOCK     (0x2) // (TC) Clock selected: TIMER_DIV3_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV4_CLOCK     (0x3) // (TC) Clock selected: TIMER_DIV4_CLOCK
#define 	AT91C_TC_CLKS_TIMER_DIV5_CLOCK     (0x4) // (TC) Clock selected: TIMER_DIV5_CLOCK
#define 	AT91C_TC_CLKS_XC0                  (0x5) // (TC) Clock selected: XC0
#define 	AT91C_TC_CLKS_XC1                  (0x6) // (TC) Clock selected: XC1
#define 	AT91C_TC_CLKS_XC2                  (0x7) // (TC) Clock selected: XC2
#define AT91C_TC_CLKI         (0x1 <<  3) // (TC) Clock Invert
#define AT91C_TC_BURST        (0x3 <<  4) // (TC) Burst Signal Selection
#define 	AT91C_TC_BURST_NONE                 (0x0 <<  4) // (TC) The clock is not gated by an external signal
#define 	AT91C_TC_BURST_XC0                  (0x1 <<  4) // (TC) XC0 is ANDed with the selected clock
#define 	AT91C_TC_BURST_XC1                  (0x2 <<  4) // (TC) XC1 is ANDed with the selected clock
#define 	AT91C_TC_BURST_XC2                  (0x3 <<  4) // (TC) XC2 is ANDed with the selected clock
#define AT91C_TC_CPCSTOP      (0x1 <<  6) // (TC) Counter Clock Stopped with RC Compare
#define AT91C_TC_LDBSTOP      (0x1 <<  6) // (TC) Counter Clock Stopped with RB Loading
#define AT91C_TC_CPCDIS       (0x1 <<  7) // (TC) Counter Clock Disable with RC Compare
#define AT91C_TC_LDBDIS       (0x1 <<  7) // (TC) Counter Clock Disabled with RB Loading
#define AT91C_TC_ETRGEDG      (0x3 <<  8) // (TC) External Trigger Edge Selection
#define 	AT91C_TC_ETRGEDG_NONE                 (0x0 <<  8) // (TC) Edge: None
#define 	AT91C_TC_ETRGEDG_RISING               (0x1 <<  8) // (TC) Edge: rising edge
#define 	AT91C_TC_ETRGEDG_FALLING              (0x2 <<  8) // (TC) Edge: falling edge
#define 	AT91C_TC_ETRGEDG_BOTH                 (0x3 <<  8) // (TC) Edge: each edge
#define AT91C_TC_EEVTEDG      (0x3 <<  8) // (TC) External Event Edge Selection
#define 	AT91C_TC_EEVTEDG_NONE                 (0x0 <<  8) // (TC) Edge: None
#define 	AT91C_TC_EEVTEDG_RISING               (0x1 <<  8) // (TC) Edge: rising edge
#define 	AT91C_TC_EEVTEDG_FALLING              (0x2 <<  8) // (TC) Edge: falling edge
#define 	AT91C_TC_EEVTEDG_BOTH                 (0x3 <<  8) // (TC) Edge: each edge
#define AT91C_TC_EEVT         (0x3 << 10) // (TC) External Event  Selection
#define 	AT91C_TC_EEVT_TIOB                 (0x0 << 10) // (TC) Signal selected as external event: TIOB TIOB direction: input
#define 	AT91C_TC_EEVT_XC0                  (0x1 << 10) // (TC) Signal selected as external event: XC0 TIOB direction: output
#define 	AT91C_TC_EEVT_XC1                  (0x2 << 10) // (TC) Signal selected as external event: XC1 TIOB direction: output
#define 	AT91C_TC_EEVT_XC2                  (0x3 << 10) // (TC) Signal selected as external event: XC2 TIOB direction: output
#define AT91C_TC_ABETRG       (0x1 << 10) // (TC) TIOA or TIOB External Trigger Selection
#define AT91C_TC_ENETRG       (0x1 << 12) // (TC) External Event Trigger enable
#define AT91C_TC_WAVESEL      (0x3 << 13) // (TC) Waveform  Selection
#define 	AT91C_TC_WAVESEL_UP                   (0x0 << 13) // (TC) UP mode without atomatic trigger on RC Compare
#define 	AT91C_TC_WAVESEL_UPDOWN               (0x1 << 13) // (TC) UPDOWN mode without automatic trigger on RC Compare
#define 	AT91C_TC_WAVESEL_UP_AUTO              (0x2 << 13) // (TC) UP mode with automatic trigger on RC Compare
#define 	AT91C_TC_WAVESEL_UPDOWN_AUTO          (0x3 << 13) // (TC) UPDOWN mode with automatic trigger on RC Compare
#define AT91C_TC_CPCTRG       (0x1 << 14) // (TC) RC Compare Trigger Enable
#define AT91C_TC_WAVE         (0x1 << 15) // (TC) 
#define AT91C_TC_ACPA         (0x3 << 16) // (TC) RA Compare Effect on TIOA
#define 	AT91C_TC_ACPA_NONE                 (0x0 << 16) // (TC) Effect: none
#define 	AT91C_TC_ACPA_SET                  (0x1 << 16) // (TC) Effect: set
#define 	AT91C_TC_ACPA_CLEAR                (0x2 << 16) // (TC) Effect: clear
#define 	AT91C_TC_ACPA_TOGGLE               (0x3 << 16) // (TC) Effect: toggle
#define AT91C_TC_LDRA         (0x3 << 16) // (TC) RA Loading Selection
#define 	AT91C_TC_LDRA_NONE                 (0x0 << 16) // (TC) Edge: None
#define 	AT91C_TC_LDRA_RISING               (0x1 << 16) // (TC) Edge: rising edge of TIOA
#define 	AT91C_TC_LDRA_FALLING              (0x2 << 16) // (TC) Edge: falling edge of TIOA
#define 	AT91C_TC_LDRA_BOTH                 (0x3 << 16) // (TC) Edge: each edge of TIOA
#define AT91C_TC_ACPC         (0x3 << 18) // (TC) RC Compare Effect on TIOA
#define 	AT91C_TC_ACPC_NONE                 (0x0 << 18) // (TC) Effect: none
#define 	AT91C_TC_ACPC_SET                  (0x1 << 18) // (TC) Effect: set
#define 	AT91C_TC_ACPC_CLEAR                (0x2 << 18) // (TC) Effect: clear
#define 	AT91C_TC_ACPC_TOGGLE               (0x3 << 18) // (TC) Effect: toggle
#define AT91C_TC_LDRB         (0x3 << 18) // (TC) RB Loading Selection
#define 	AT91C_TC_LDRB_NONE                 (0x0 << 18) // (TC) Edge: None
#define 	AT91C_TC_LDRB_RISING               (0x1 << 18) // (TC) Edge: rising edge of TIOA
#define 	AT91C_TC_LDRB_FALLING              (0x2 << 18) // (TC) Edge: falling edge of TIOA
#define 	AT91C_TC_LDRB_BOTH                 (0x3 << 18) // (TC) Edge: each edge of TIOA
#define AT91C_TC_AEEVT        (0x3 << 20) // (TC) External Event Effect on TIOA
#define 	AT91C_TC_AEEVT_NONE                 (0x0 << 20) // (TC) Effect: none
#define 	AT91C_TC_AEEVT_SET                  (0x1 << 20) // (TC) Effect: set
#define 	AT91C_TC_AEEVT_CLEAR                (0x2 << 20) // (TC) Effect: clear
#define 	AT91C_TC_AEEVT_TOGGLE               (0x3 << 20) // (TC) Effect: toggle
#define AT91C_TC_ASWTRG       (0x3 << 22) // (TC) Software Trigger Effect on TIOA
#define 	AT91C_TC_ASWTRG_NONE                 (0x0 << 22) // (TC) Effect: none
#define 	AT91C_TC_ASWTRG_SET                  (0x1 << 22) // (TC) Effect: set
#define 	AT91C_TC_ASWTRG_CLEAR                (0x2 << 22) // (TC) Effect: clear
#define 	AT91C_TC_ASWTRG_TOGGLE               (0x3 << 22) // (TC) Effect: toggle
#define AT91C_TC_BCPB         (0x3 << 24) // (TC) RB Compare Effect on TIOB
#define 	AT91C_TC_BCPB_NONE                 (0x0 << 24) // (TC) Effect: none
#define 	AT91C_TC_BCPB_SET                  (0x1 << 24) // (TC) Effect: set
#define 	AT91C_TC_BCPB_CLEAR                (0x2 << 24) // (TC) Effect: clear
#define 	AT91C_TC_BCPB_TOGGLE               (0x3 << 24) // (TC) Effect: toggle
#define AT91C_TC_BCPC         (0x3 << 26) // (TC) RC Compare Effect on TIOB
#define 	AT91C_TC_BCPC_NONE                 (0x0 << 26) // (TC) Effect: none
#define 	AT91C_TC_BCPC_SET                  (0x1 << 26) // (TC) Effect: set
#define 	AT91C_TC_BCPC_CLEAR                (0x2 << 26) // (TC) Effect: clear
#define 	AT91C_TC_BCPC_TOGGLE               (0x3 << 26) // (TC) Effect: toggle
#define AT91C_TC_BEEVT        (0x3 << 28) // (TC) External Event Effect on TIOB
#define 	AT91C_TC_BEEVT_NONE                 (0x0 << 28) // (TC) Effect: none
#define 	AT91C_TC_BEEVT_SET                  (0x1 << 28) // (TC) Effect: set
#define 	AT91C_TC_BEEVT_CLEAR                (0x2 << 28) // (TC) Effect: clear
#define 	AT91C_TC_BEEVT_TOGGLE               (0x3 << 28) // (TC) Effect: toggle
#define AT91C_TC_BSWTRG       (0x3 << 30) // (TC) Software Trigger Effect on TIOB
#define 	AT91C_TC_BSWTRG_NONE                 (0x0 << 30) // (TC) Effect: none
#define 	AT91C_TC_BSWTRG_SET                  (0x1 << 30) // (TC) Effect: set
#define 	AT91C_TC_BSWTRG_CLEAR                (0x2 << 30) // (TC) Effect: clear
#define 	AT91C_TC_BSWTRG_TOGGLE               (0x3 << 30) // (TC) Effect: toggle
// -------- TC_SR : (TC Offset: 0x20) TC Channel Status Register -------- 
#define AT91C_TC_COVFS        (0x1 <<  0) // (TC) Counter Overflow
#define AT91C_TC_LOVRS        (0x1 <<  1) // (TC) Load Overrun
#define AT91C_TC_CPAS         (0x1 <<  2) // (TC) RA Compare
#define AT91C_TC_CPBS         (0x1 <<  3) // (TC) RB Compare
#define AT91C_TC_CPCS         (0x1 <<  4) // (TC) RC Compare
#define AT91C_TC_LDRAS        (0x1 <<  5) // (TC) RA Loading
#define AT91C_TC_LDRBS        (0x1 <<  6) // (TC) RB Loading
#define AT91C_TC_ETRGS        (0x1 <<  7) // (TC) External Trigger
#define AT91C_TC_CLKSTA       (0x1 << 16) // (TC) Clock Enabling
#define AT91C_TC_MTIOA        (0x1 << 17) // (TC) TIOA Mirror
#define AT91C_TC_MTIOB        (0x1 << 18) // (TC) TIOA Mirror
// -------- TC_IER : (TC Offset: 0x24) TC Channel Interrupt Enable Register -------- 
// -------- TC_IDR : (TC Offset: 0x28) TC Channel Interrupt Disable Register -------- 
// -------- TC_IMR : (TC Offset: 0x2c) TC Channel Interrupt Mask Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Timer Counter Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_TCB {
	AT91S_TC	 TCB_TC0; 	// TC Channel 0
	AT91_REG	 Reserved0[4]; 	// 
	AT91S_TC	 TCB_TC1; 	// TC Channel 1
	AT91_REG	 Reserved1[4]; 	// 
	AT91S_TC	 TCB_TC2; 	// TC Channel 2
	AT91_REG	 Reserved2[4]; 	// 
	AT91_REG	 TCB_BCR; 	// TC Block Control Register
	AT91_REG	 TCB_BMR; 	// TC Block Mode Register
	AT91_REG	 Reserved3[9]; 	// 
	AT91_REG	 TCB_ADDRSIZE; 	// TC ADDRSIZE REGISTER 
	AT91_REG	 TCB_IPNAME1; 	// TC IPNAME1 REGISTER 
	AT91_REG	 TCB_IPNAME2; 	// TC IPNAME2 REGISTER 
	AT91_REG	 TCB_FEATURES; 	// TC FEATURES REGISTER 
	AT91_REG	 TCB_VER; 	//  Version Register
} AT91S_TCB, *AT91PS_TCB;
#else
#define TCB_BCR         (AT91_CAST(AT91_REG *) 	0x000000C0) // (TCB_BCR) TC Block Control Register
#define TCB_BMR         (AT91_CAST(AT91_REG *) 	0x000000C4) // (TCB_BMR) TC Block Mode Register
#define TC_ADDRSIZE     (AT91_CAST(AT91_REG *) 	0x000000EC) // (TC_ADDRSIZE) TC ADDRSIZE REGISTER 
#define TC_IPNAME1      (AT91_CAST(AT91_REG *) 	0x000000F0) // (TC_IPNAME1) TC IPNAME1 REGISTER 
#define TC_IPNAME2      (AT91_CAST(AT91_REG *) 	0x000000F4) // (TC_IPNAME2) TC IPNAME2 REGISTER 
#define TC_FEATURES     (AT91_CAST(AT91_REG *) 	0x000000F8) // (TC_FEATURES) TC FEATURES REGISTER 
#define TC_VER          (AT91_CAST(AT91_REG *) 	0x000000FC) // (TC_VER)  Version Register

#endif
// -------- TCB_BCR : (TCB Offset: 0xc0) TC Block Control Register -------- 
#define AT91C_TCB_SYNC        (0x1 <<  0) // (TCB) Synchro Command
// -------- TCB_BMR : (TCB Offset: 0xc4) TC Block Mode Register -------- 
#define AT91C_TCB_TC0XC0S     (0x3 <<  0) // (TCB) External Clock Signal 0 Selection
#define 	AT91C_TCB_TC0XC0S_TCLK0                (0x0) // (TCB) TCLK0 connected to XC0
#define 	AT91C_TCB_TC0XC0S_NONE                 (0x1) // (TCB) None signal connected to XC0
#define 	AT91C_TCB_TC0XC0S_TIOA1                (0x2) // (TCB) TIOA1 connected to XC0
#define 	AT91C_TCB_TC0XC0S_TIOA2                (0x3) // (TCB) TIOA2 connected to XC0
#define AT91C_TCB_TC1XC1S     (0x3 <<  2) // (TCB) External Clock Signal 1 Selection
#define 	AT91C_TCB_TC1XC1S_TCLK1                (0x0 <<  2) // (TCB) TCLK1 connected to XC1
#define 	AT91C_TCB_TC1XC1S_NONE                 (0x1 <<  2) // (TCB) None signal connected to XC1
#define 	AT91C_TCB_TC1XC1S_TIOA0                (0x2 <<  2) // (TCB) TIOA0 connected to XC1
#define 	AT91C_TCB_TC1XC1S_TIOA2                (0x3 <<  2) // (TCB) TIOA2 connected to XC1
#define AT91C_TCB_TC2XC2S     (0x3 <<  4) // (TCB) External Clock Signal 2 Selection
#define 	AT91C_TCB_TC2XC2S_TCLK2                (0x0 <<  4) // (TCB) TCLK2 connected to XC2
#define 	AT91C_TCB_TC2XC2S_NONE                 (0x1 <<  4) // (TCB) None signal connected to XC2
#define 	AT91C_TCB_TC2XC2S_TIOA0                (0x2 <<  4) // (TCB) TIOA0 connected to XC2
#define 	AT91C_TCB_TC2XC2S_TIOA1                (0x3 <<  4) // (TCB) TIOA2 connected to XC2

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR PWMC Channel Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_PWMC_CH {
	AT91_REG	 PWMC_CMR; 	// Channel Mode Register
	AT91_REG	 PWMC_CDTYR; 	// Channel Duty Cycle Register
	AT91_REG	 PWMC_CDTYUPDR; 	// Channel Duty Cycle Update Register
	AT91_REG	 PWMC_CPRDR; 	// Channel Period Register
	AT91_REG	 PWMC_CPRDUPDR; 	// Channel Period Update Register
	AT91_REG	 PWMC_CCNTR; 	// Channel Counter Register
	AT91_REG	 PWMC_DTR; 	// Channel Dead Time Value Register
	AT91_REG	 PWMC_DTUPDR; 	// Channel Dead Time Update Value Register
} AT91S_PWMC_CH, *AT91PS_PWMC_CH;
#else
#define PWMC_CMR        (AT91_CAST(AT91_REG *) 	0x00000000) // (PWMC_CMR) Channel Mode Register
#define PWMC_CDTYR      (AT91_CAST(AT91_REG *) 	0x00000004) // (PWMC_CDTYR) Channel Duty Cycle Register
#define PWMC_CDTYUPDR   (AT91_CAST(AT91_REG *) 	0x00000008) // (PWMC_CDTYUPDR) Channel Duty Cycle Update Register
#define PWMC_CPRDR      (AT91_CAST(AT91_REG *) 	0x0000000C) // (PWMC_CPRDR) Channel Period Register
#define PWMC_CPRDUPDR   (AT91_CAST(AT91_REG *) 	0x00000010) // (PWMC_CPRDUPDR) Channel Period Update Register
#define PWMC_CCNTR      (AT91_CAST(AT91_REG *) 	0x00000014) // (PWMC_CCNTR) Channel Counter Register
#define PWMC_DTR        (AT91_CAST(AT91_REG *) 	0x00000018) // (PWMC_DTR) Channel Dead Time Value Register
#define PWMC_DTUPDR     (AT91_CAST(AT91_REG *) 	0x0000001C) // (PWMC_DTUPDR) Channel Dead Time Update Value Register

#endif
// -------- PWMC_CMR : (PWMC_CH Offset: 0x0) PWMC Channel Mode Register -------- 
#define AT91C_PWMC_CPRE       (0xF <<  0) // (PWMC_CH) Channel Pre-scaler : PWMC_CLKx
#define 	AT91C_PWMC_CPRE_MCK                  (0x0) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCK_DIV_2            (0x1) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCK_DIV_4            (0x2) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCK_DIV_8            (0x3) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCK_DIV_16           (0x4) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCK_DIV_32           (0x5) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCK_DIV_64           (0x6) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCK_DIV_128          (0x7) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCK_DIV_256          (0x8) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCK_DIV_512          (0x9) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCK_DIV_1024         (0xA) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCKA                 (0xB) // (PWMC_CH) 
#define 	AT91C_PWMC_CPRE_MCKB                 (0xC) // (PWMC_CH) 
#define AT91C_PWMC_CALG       (0x1 <<  8) // (PWMC_CH) Channel Alignment
#define AT91C_PWMC_CPOL       (0x1 <<  9) // (PWMC_CH) Channel Polarity
#define AT91C_PWMC_CES        (0x1 << 10) // (PWMC_CH) Counter Event Selection
#define AT91C_PWMC_DTE        (0x1 << 16) // (PWMC_CH) Dead Time Genrator Enable
#define AT91C_PWMC_DTHI       (0x1 << 17) // (PWMC_CH) Dead Time PWMHx Output Inverted
#define AT91C_PWMC_DTLI       (0x1 << 18) // (PWMC_CH) Dead Time PWMLx Output Inverted
// -------- PWMC_CDTYR : (PWMC_CH Offset: 0x4) PWMC Channel Duty Cycle Register -------- 
#define AT91C_PWMC_CDTY       (0xFFFFFF <<  0) // (PWMC_CH) Channel Duty Cycle
// -------- PWMC_CDTYUPDR : (PWMC_CH Offset: 0x8) PWMC Channel Duty Cycle Update Register -------- 
#define AT91C_PWMC_CDTYUPD    (0xFFFFFF <<  0) // (PWMC_CH) Channel Duty Cycle Update
// -------- PWMC_CPRDR : (PWMC_CH Offset: 0xc) PWMC Channel Period Register -------- 
#define AT91C_PWMC_CPRD       (0xFFFFFF <<  0) // (PWMC_CH) Channel Period
// -------- PWMC_CPRDUPDR : (PWMC_CH Offset: 0x10) PWMC Channel Period Update Register -------- 
#define AT91C_PWMC_CPRDUPD    (0xFFFFFF <<  0) // (PWMC_CH) Channel Period Update
// -------- PWMC_CCNTR : (PWMC_CH Offset: 0x14) PWMC Channel Counter Register -------- 
#define AT91C_PWMC_CCNT       (0xFFFFFF <<  0) // (PWMC_CH) Channel Counter
// -------- PWMC_DTR : (PWMC_CH Offset: 0x18) Channel Dead Time Value Register -------- 
#define AT91C_PWMC_DTL        (0xFFFF <<  0) // (PWMC_CH) Channel Dead Time for PWML
#define AT91C_PWMC_DTH        (0xFFFF << 16) // (PWMC_CH) Channel Dead Time for PWMH
// -------- PWMC_DTUPDR : (PWMC_CH Offset: 0x1c) Channel Dead Time Value Register -------- 
#define AT91C_PWMC_DTLUPD     (0xFFFF <<  0) // (PWMC_CH) Channel Dead Time Update for PWML.
#define AT91C_PWMC_DTHUPD     (0xFFFF << 16) // (PWMC_CH) Channel Dead Time Update for PWMH.

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Pulse Width Modulation Controller Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_PWMC {
	AT91_REG	 PWMC_MR; 	// PWMC Mode Register
	AT91_REG	 PWMC_ENA; 	// PWMC Enable Register
	AT91_REG	 PWMC_DIS; 	// PWMC Disable Register
	AT91_REG	 PWMC_SR; 	// PWMC Status Register
	AT91_REG	 PWMC_IER1; 	// PWMC Interrupt Enable Register 1
	AT91_REG	 PWMC_IDR1; 	// PWMC Interrupt Disable Register 1
	AT91_REG	 PWMC_IMR1; 	// PWMC Interrupt Mask Register 1
	AT91_REG	 PWMC_ISR1; 	// PWMC Interrupt Status Register 1
	AT91_REG	 PWMC_SYNC; 	// PWM Synchronized Channels Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 PWMC_UPCR; 	// PWM Update Control Register
	AT91_REG	 PWMC_SCUP; 	// PWM Update Period Register
	AT91_REG	 PWMC_SCUPUPD; 	// PWM Update Period Update Register
	AT91_REG	 PWMC_IER2; 	// PWMC Interrupt Enable Register 2
	AT91_REG	 PWMC_IDR2; 	// PWMC Interrupt Disable Register 2
	AT91_REG	 PWMC_IMR2; 	// PWMC Interrupt Mask Register 2
	AT91_REG	 PWMC_ISR2; 	// PWMC Interrupt Status Register 2
	AT91_REG	 PWMC_OOV; 	// PWM Output Override Value Register
	AT91_REG	 PWMC_OS; 	// PWM Output Selection Register
	AT91_REG	 PWMC_OSS; 	// PWM Output Selection Set Register
	AT91_REG	 PWMC_OSC; 	// PWM Output Selection Clear Register
	AT91_REG	 PWMC_OSSUPD; 	// PWM Output Selection Set Update Register
	AT91_REG	 PWMC_OSCUPD; 	// PWM Output Selection Clear Update Register
	AT91_REG	 PWMC_FMR; 	// PWM Fault Mode Register
	AT91_REG	 PWMC_FSR; 	// PWM Fault Mode Status Register
	AT91_REG	 PWMC_FCR; 	// PWM Fault Mode Clear Register
	AT91_REG	 PWMC_FPV; 	// PWM Fault Protection Value Register
	AT91_REG	 PWMC_FPER1; 	// PWM Fault Protection Enable Register 1
	AT91_REG	 PWMC_FPER2; 	// PWM Fault Protection Enable Register 2
	AT91_REG	 PWMC_FPER3; 	// PWM Fault Protection Enable Register 3
	AT91_REG	 PWMC_FPER4; 	// PWM Fault Protection Enable Register 4
	AT91_REG	 PWMC_EL0MR; 	// PWM Event Line 0 Mode Register
	AT91_REG	 PWMC_EL1MR; 	// PWM Event Line 1 Mode Register
	AT91_REG	 PWMC_EL2MR; 	// PWM Event Line 2 Mode Register
	AT91_REG	 PWMC_EL3MR; 	// PWM Event Line 3 Mode Register
	AT91_REG	 PWMC_EL4MR; 	// PWM Event Line 4 Mode Register
	AT91_REG	 PWMC_EL5MR; 	// PWM Event Line 5 Mode Register
	AT91_REG	 PWMC_EL6MR; 	// PWM Event Line 6 Mode Register
	AT91_REG	 PWMC_EL7MR; 	// PWM Event Line 7 Mode Register
	AT91_REG	 Reserved1[18]; 	// 
	AT91_REG	 PWMC_WPCR; 	// PWM Write Protection Enable Register
	AT91_REG	 PWMC_WPSR; 	// PWM Write Protection Status Register
	AT91_REG	 PWMC_ADDRSIZE; 	// PWMC ADDRSIZE REGISTER 
	AT91_REG	 PWMC_IPNAME1; 	// PWMC IPNAME1 REGISTER 
	AT91_REG	 PWMC_IPNAME2; 	// PWMC IPNAME2 REGISTER 
	AT91_REG	 PWMC_FEATURES; 	// PWMC FEATURES REGISTER 
	AT91_REG	 PWMC_VER; 	// PWMC Version Register
	AT91_REG	 PWMC_RPR; 	// Receive Pointer Register
	AT91_REG	 PWMC_RCR; 	// Receive Counter Register
	AT91_REG	 PWMC_TPR; 	// Transmit Pointer Register
	AT91_REG	 PWMC_TCR; 	// Transmit Counter Register
	AT91_REG	 PWMC_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 PWMC_RNCR; 	// Receive Next Counter Register
	AT91_REG	 PWMC_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 PWMC_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 PWMC_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 PWMC_PTSR; 	// PDC Transfer Status Register
	AT91_REG	 Reserved2[2]; 	// 
	AT91_REG	 PWMC_CMP0V; 	// PWM Comparison Value 0 Register
	AT91_REG	 PWMC_CMP0VUPD; 	// PWM Comparison Value 0 Update Register
	AT91_REG	 PWMC_CMP0M; 	// PWM Comparison Mode 0 Register
	AT91_REG	 PWMC_CMP0MUPD; 	// PWM Comparison Mode 0 Update Register
	AT91_REG	 PWMC_CMP1V; 	// PWM Comparison Value 1 Register
	AT91_REG	 PWMC_CMP1VUPD; 	// PWM Comparison Value 1 Update Register
	AT91_REG	 PWMC_CMP1M; 	// PWM Comparison Mode 1 Register
	AT91_REG	 PWMC_CMP1MUPD; 	// PWM Comparison Mode 1 Update Register
	AT91_REG	 PWMC_CMP2V; 	// PWM Comparison Value 2 Register
	AT91_REG	 PWMC_CMP2VUPD; 	// PWM Comparison Value 2 Update Register
	AT91_REG	 PWMC_CMP2M; 	// PWM Comparison Mode 2 Register
	AT91_REG	 PWMC_CMP2MUPD; 	// PWM Comparison Mode 2 Update Register
	AT91_REG	 PWMC_CMP3V; 	// PWM Comparison Value 3 Register
	AT91_REG	 PWMC_CMP3VUPD; 	// PWM Comparison Value 3 Update Register
	AT91_REG	 PWMC_CMP3M; 	// PWM Comparison Mode 3 Register
	AT91_REG	 PWMC_CMP3MUPD; 	// PWM Comparison Mode 3 Update Register
	AT91_REG	 PWMC_CMP4V; 	// PWM Comparison Value 4 Register
	AT91_REG	 PWMC_CMP4VUPD; 	// PWM Comparison Value 4 Update Register
	AT91_REG	 PWMC_CMP4M; 	// PWM Comparison Mode 4 Register
	AT91_REG	 PWMC_CMP4MUPD; 	// PWM Comparison Mode 4 Update Register
	AT91_REG	 PWMC_CMP5V; 	// PWM Comparison Value 5 Register
	AT91_REG	 PWMC_CMP5VUPD; 	// PWM Comparison Value 5 Update Register
	AT91_REG	 PWMC_CMP5M; 	// PWM Comparison Mode 5 Register
	AT91_REG	 PWMC_CMP5MUPD; 	// PWM Comparison Mode 5 Update Register
	AT91_REG	 PWMC_CMP6V; 	// PWM Comparison Value 6 Register
	AT91_REG	 PWMC_CMP6VUPD; 	// PWM Comparison Value 6 Update Register
	AT91_REG	 PWMC_CMP6M; 	// PWM Comparison Mode 6 Register
	AT91_REG	 PWMC_CMP6MUPD; 	// PWM Comparison Mode 6 Update Register
	AT91_REG	 PWMC_CMP7V; 	// PWM Comparison Value 7 Register
	AT91_REG	 PWMC_CMP7VUPD; 	// PWM Comparison Value 7 Update Register
	AT91_REG	 PWMC_CMP7M; 	// PWM Comparison Mode 7 Register
	AT91_REG	 PWMC_CMP7MUPD; 	// PWM Comparison Mode 7 Update Register
	AT91_REG	 Reserved3[20]; 	// 
	AT91S_PWMC_CH	 PWMC_CH[8]; 	// PWMC Channel 0
} AT91S_PWMC, *AT91PS_PWMC;
#else
#define PWMC_MR         (AT91_CAST(AT91_REG *) 	0x00000000) // (PWMC_MR) PWMC Mode Register
#define PWMC_ENA        (AT91_CAST(AT91_REG *) 	0x00000004) // (PWMC_ENA) PWMC Enable Register
#define PWMC_DIS        (AT91_CAST(AT91_REG *) 	0x00000008) // (PWMC_DIS) PWMC Disable Register
#define PWMC_SR         (AT91_CAST(AT91_REG *) 	0x0000000C) // (PWMC_SR) PWMC Status Register
#define PWMC_IER1       (AT91_CAST(AT91_REG *) 	0x00000010) // (PWMC_IER1) PWMC Interrupt Enable Register 1
#define PWMC_IDR1       (AT91_CAST(AT91_REG *) 	0x00000014) // (PWMC_IDR1) PWMC Interrupt Disable Register 1
#define PWMC_IMR1       (AT91_CAST(AT91_REG *) 	0x00000018) // (PWMC_IMR1) PWMC Interrupt Mask Register 1
#define PWMC_ISR1       (AT91_CAST(AT91_REG *) 	0x0000001C) // (PWMC_ISR1) PWMC Interrupt Status Register 1
#define PWMC_SYNC       (AT91_CAST(AT91_REG *) 	0x00000020) // (PWMC_SYNC) PWM Synchronized Channels Register
#define PWMC_UPCR       (AT91_CAST(AT91_REG *) 	0x00000028) // (PWMC_UPCR) PWM Update Control Register
#define PWMC_SCUP       (AT91_CAST(AT91_REG *) 	0x0000002C) // (PWMC_SCUP) PWM Update Period Register
#define PWMC_SCUPUPD    (AT91_CAST(AT91_REG *) 	0x00000030) // (PWMC_SCUPUPD) PWM Update Period Update Register
#define PWMC_IER2       (AT91_CAST(AT91_REG *) 	0x00000034) // (PWMC_IER2) PWMC Interrupt Enable Register 2
#define PWMC_IDR2       (AT91_CAST(AT91_REG *) 	0x00000038) // (PWMC_IDR2) PWMC Interrupt Disable Register 2
#define PWMC_IMR2       (AT91_CAST(AT91_REG *) 	0x0000003C) // (PWMC_IMR2) PWMC Interrupt Mask Register 2
#define PWMC_ISR2       (AT91_CAST(AT91_REG *) 	0x00000040) // (PWMC_ISR2) PWMC Interrupt Status Register 2
#define PWMC_OOV        (AT91_CAST(AT91_REG *) 	0x00000044) // (PWMC_OOV) PWM Output Override Value Register
#define PWMC_OS         (AT91_CAST(AT91_REG *) 	0x00000048) // (PWMC_OS) PWM Output Selection Register
#define PWMC_OSS        (AT91_CAST(AT91_REG *) 	0x0000004C) // (PWMC_OSS) PWM Output Selection Set Register
#define PWMC_OSC        (AT91_CAST(AT91_REG *) 	0x00000050) // (PWMC_OSC) PWM Output Selection Clear Register
#define PWMC_OSSUPD     (AT91_CAST(AT91_REG *) 	0x00000054) // (PWMC_OSSUPD) PWM Output Selection Set Update Register
#define PWMC_OSCUPD     (AT91_CAST(AT91_REG *) 	0x00000058) // (PWMC_OSCUPD) PWM Output Selection Clear Update Register
#define PWMC_FMR        (AT91_CAST(AT91_REG *) 	0x0000005C) // (PWMC_FMR) PWM Fault Mode Register
#define PWMC_FSR        (AT91_CAST(AT91_REG *) 	0x00000060) // (PWMC_FSR) PWM Fault Mode Status Register
#define PWMC_FCR        (AT91_CAST(AT91_REG *) 	0x00000064) // (PWMC_FCR) PWM Fault Mode Clear Register
#define PWMC_FPV        (AT91_CAST(AT91_REG *) 	0x00000068) // (PWMC_FPV) PWM Fault Protection Value Register
#define PWMC_FPER1      (AT91_CAST(AT91_REG *) 	0x0000006C) // (PWMC_FPER1) PWM Fault Protection Enable Register 1
#define PWMC_FPER2      (AT91_CAST(AT91_REG *) 	0x00000070) // (PWMC_FPER2) PWM Fault Protection Enable Register 2
#define PWMC_FPER3      (AT91_CAST(AT91_REG *) 	0x00000074) // (PWMC_FPER3) PWM Fault Protection Enable Register 3
#define PWMC_FPER4      (AT91_CAST(AT91_REG *) 	0x00000078) // (PWMC_FPER4) PWM Fault Protection Enable Register 4
#define PWMC_EL0MR      (AT91_CAST(AT91_REG *) 	0x0000007C) // (PWMC_EL0MR) PWM Event Line 0 Mode Register
#define PWMC_EL1MR      (AT91_CAST(AT91_REG *) 	0x00000080) // (PWMC_EL1MR) PWM Event Line 1 Mode Register
#define PWMC_EL2MR      (AT91_CAST(AT91_REG *) 	0x00000084) // (PWMC_EL2MR) PWM Event Line 2 Mode Register
#define PWMC_EL3MR      (AT91_CAST(AT91_REG *) 	0x00000088) // (PWMC_EL3MR) PWM Event Line 3 Mode Register
#define PWMC_EL4MR      (AT91_CAST(AT91_REG *) 	0x0000008C) // (PWMC_EL4MR) PWM Event Line 4 Mode Register
#define PWMC_EL5MR      (AT91_CAST(AT91_REG *) 	0x00000090) // (PWMC_EL5MR) PWM Event Line 5 Mode Register
#define PWMC_EL6MR      (AT91_CAST(AT91_REG *) 	0x00000094) // (PWMC_EL6MR) PWM Event Line 6 Mode Register
#define PWMC_EL7MR      (AT91_CAST(AT91_REG *) 	0x00000098) // (PWMC_EL7MR) PWM Event Line 7 Mode Register
#define PWMC_WPCR       (AT91_CAST(AT91_REG *) 	0x000000E4) // (PWMC_WPCR) PWM Write Protection Enable Register
#define PWMC_WPSR       (AT91_CAST(AT91_REG *) 	0x000000E8) // (PWMC_WPSR) PWM Write Protection Status Register
#define PWMC_ADDRSIZE   (AT91_CAST(AT91_REG *) 	0x000000EC) // (PWMC_ADDRSIZE) PWMC ADDRSIZE REGISTER 
#define PWMC_IPNAME1    (AT91_CAST(AT91_REG *) 	0x000000F0) // (PWMC_IPNAME1) PWMC IPNAME1 REGISTER 
#define PWMC_IPNAME2    (AT91_CAST(AT91_REG *) 	0x000000F4) // (PWMC_IPNAME2) PWMC IPNAME2 REGISTER 
#define PWMC_FEATURES   (AT91_CAST(AT91_REG *) 	0x000000F8) // (PWMC_FEATURES) PWMC FEATURES REGISTER 
#define PWMC_VER        (AT91_CAST(AT91_REG *) 	0x000000FC) // (PWMC_VER) PWMC Version Register
#define PWMC_CMP0V      (AT91_CAST(AT91_REG *) 	0x00000130) // (PWMC_CMP0V) PWM Comparison Value 0 Register
#define PWMC_CMP0VUPD   (AT91_CAST(AT91_REG *) 	0x00000134) // (PWMC_CMP0VUPD) PWM Comparison Value 0 Update Register
#define PWMC_CMP0M      (AT91_CAST(AT91_REG *) 	0x00000138) // (PWMC_CMP0M) PWM Comparison Mode 0 Register
#define PWMC_CMP0MUPD   (AT91_CAST(AT91_REG *) 	0x0000013C) // (PWMC_CMP0MUPD) PWM Comparison Mode 0 Update Register
#define PWMC_CMP1V      (AT91_CAST(AT91_REG *) 	0x00000140) // (PWMC_CMP1V) PWM Comparison Value 1 Register
#define PWMC_CMP1VUPD   (AT91_CAST(AT91_REG *) 	0x00000144) // (PWMC_CMP1VUPD) PWM Comparison Value 1 Update Register
#define PWMC_CMP1M      (AT91_CAST(AT91_REG *) 	0x00000148) // (PWMC_CMP1M) PWM Comparison Mode 1 Register
#define PWMC_CMP1MUPD   (AT91_CAST(AT91_REG *) 	0x0000014C) // (PWMC_CMP1MUPD) PWM Comparison Mode 1 Update Register
#define PWMC_CMP2V      (AT91_CAST(AT91_REG *) 	0x00000150) // (PWMC_CMP2V) PWM Comparison Value 2 Register
#define PWMC_CMP2VUPD   (AT91_CAST(AT91_REG *) 	0x00000154) // (PWMC_CMP2VUPD) PWM Comparison Value 2 Update Register
#define PWMC_CMP2M      (AT91_CAST(AT91_REG *) 	0x00000158) // (PWMC_CMP2M) PWM Comparison Mode 2 Register
#define PWMC_CMP2MUPD   (AT91_CAST(AT91_REG *) 	0x0000015C) // (PWMC_CMP2MUPD) PWM Comparison Mode 2 Update Register
#define PWMC_CMP3V      (AT91_CAST(AT91_REG *) 	0x00000160) // (PWMC_CMP3V) PWM Comparison Value 3 Register
#define PWMC_CMP3VUPD   (AT91_CAST(AT91_REG *) 	0x00000164) // (PWMC_CMP3VUPD) PWM Comparison Value 3 Update Register
#define PWMC_CMP3M      (AT91_CAST(AT91_REG *) 	0x00000168) // (PWMC_CMP3M) PWM Comparison Mode 3 Register
#define PWMC_CMP3MUPD   (AT91_CAST(AT91_REG *) 	0x0000016C) // (PWMC_CMP3MUPD) PWM Comparison Mode 3 Update Register
#define PWMC_CMP4V      (AT91_CAST(AT91_REG *) 	0x00000170) // (PWMC_CMP4V) PWM Comparison Value 4 Register
#define PWMC_CMP4VUPD   (AT91_CAST(AT91_REG *) 	0x00000174) // (PWMC_CMP4VUPD) PWM Comparison Value 4 Update Register
#define PWMC_CMP4M      (AT91_CAST(AT91_REG *) 	0x00000178) // (PWMC_CMP4M) PWM Comparison Mode 4 Register
#define PWMC_CMP4MUPD   (AT91_CAST(AT91_REG *) 	0x0000017C) // (PWMC_CMP4MUPD) PWM Comparison Mode 4 Update Register
#define PWMC_CMP5V      (AT91_CAST(AT91_REG *) 	0x00000180) // (PWMC_CMP5V) PWM Comparison Value 5 Register
#define PWMC_CMP5VUPD   (AT91_CAST(AT91_REG *) 	0x00000184) // (PWMC_CMP5VUPD) PWM Comparison Value 5 Update Register
#define PWMC_CMP5M      (AT91_CAST(AT91_REG *) 	0x00000188) // (PWMC_CMP5M) PWM Comparison Mode 5 Register
#define PWMC_CMP5MUPD   (AT91_CAST(AT91_REG *) 	0x0000018C) // (PWMC_CMP5MUPD) PWM Comparison Mode 5 Update Register
#define PWMC_CMP6V      (AT91_CAST(AT91_REG *) 	0x00000190) // (PWMC_CMP6V) PWM Comparison Value 6 Register
#define PWMC_CMP6VUPD   (AT91_CAST(AT91_REG *) 	0x00000194) // (PWMC_CMP6VUPD) PWM Comparison Value 6 Update Register
#define PWMC_CMP6M      (AT91_CAST(AT91_REG *) 	0x00000198) // (PWMC_CMP6M) PWM Comparison Mode 6 Register
#define PWMC_CMP6MUPD   (AT91_CAST(AT91_REG *) 	0x0000019C) // (PWMC_CMP6MUPD) PWM Comparison Mode 6 Update Register
#define PWMC_CMP7V      (AT91_CAST(AT91_REG *) 	0x000001A0) // (PWMC_CMP7V) PWM Comparison Value 7 Register
#define PWMC_CMP7VUPD   (AT91_CAST(AT91_REG *) 	0x000001A4) // (PWMC_CMP7VUPD) PWM Comparison Value 7 Update Register
#define PWMC_CMP7M      (AT91_CAST(AT91_REG *) 	0x000001A8) // (PWMC_CMP7M) PWM Comparison Mode 7 Register
#define PWMC_CMP7MUPD   (AT91_CAST(AT91_REG *) 	0x000001AC) // (PWMC_CMP7MUPD) PWM Comparison Mode 7 Update Register

#endif
// -------- PWMC_MR : (PWMC Offset: 0x0) PWMC Mode Register -------- 
#define AT91C_PWMC_DIVA       (0xFF <<  0) // (PWMC) CLKA divide factor.
#define AT91C_PWMC_PREA       (0xF <<  8) // (PWMC) Divider Input Clock Prescaler A
#define 	AT91C_PWMC_PREA_MCK                  (0x0 <<  8) // (PWMC) 
#define 	AT91C_PWMC_PREA_MCK_DIV_2            (0x1 <<  8) // (PWMC) 
#define 	AT91C_PWMC_PREA_MCK_DIV_4            (0x2 <<  8) // (PWMC) 
#define 	AT91C_PWMC_PREA_MCK_DIV_8            (0x3 <<  8) // (PWMC) 
#define 	AT91C_PWMC_PREA_MCK_DIV_16           (0x4 <<  8) // (PWMC) 
#define 	AT91C_PWMC_PREA_MCK_DIV_32           (0x5 <<  8) // (PWMC) 
#define 	AT91C_PWMC_PREA_MCK_DIV_64           (0x6 <<  8) // (PWMC) 
#define 	AT91C_PWMC_PREA_MCK_DIV_128          (0x7 <<  8) // (PWMC) 
#define 	AT91C_PWMC_PREA_MCK_DIV_256          (0x8 <<  8) // (PWMC) 
#define AT91C_PWMC_DIVB       (0xFF << 16) // (PWMC) CLKB divide factor.
#define AT91C_PWMC_PREB       (0xF << 24) // (PWMC) Divider Input Clock Prescaler B
#define 	AT91C_PWMC_PREB_MCK                  (0x0 << 24) // (PWMC) 
#define 	AT91C_PWMC_PREB_MCK_DIV_2            (0x1 << 24) // (PWMC) 
#define 	AT91C_PWMC_PREB_MCK_DIV_4            (0x2 << 24) // (PWMC) 
#define 	AT91C_PWMC_PREB_MCK_DIV_8            (0x3 << 24) // (PWMC) 
#define 	AT91C_PWMC_PREB_MCK_DIV_16           (0x4 << 24) // (PWMC) 
#define 	AT91C_PWMC_PREB_MCK_DIV_32           (0x5 << 24) // (PWMC) 
#define 	AT91C_PWMC_PREB_MCK_DIV_64           (0x6 << 24) // (PWMC) 
#define 	AT91C_PWMC_PREB_MCK_DIV_128          (0x7 << 24) // (PWMC) 
#define 	AT91C_PWMC_PREB_MCK_DIV_256          (0x8 << 24) // (PWMC) 
#define AT91C_PWMC_CLKSEL     (0x1 << 31) // (PWMC) CCK Source Clock Selection
// -------- PWMC_ENA : (PWMC Offset: 0x4) PWMC Enable Register -------- 
#define AT91C_PWMC_CHID0      (0x1 <<  0) // (PWMC) Channel ID 0
#define AT91C_PWMC_CHID1      (0x1 <<  1) // (PWMC) Channel ID 1
#define AT91C_PWMC_CHID2      (0x1 <<  2) // (PWMC) Channel ID 2
#define AT91C_PWMC_CHID3      (0x1 <<  3) // (PWMC) Channel ID 3
#define AT91C_PWMC_CHID4      (0x1 <<  4) // (PWMC) Channel ID 4
#define AT91C_PWMC_CHID5      (0x1 <<  5) // (PWMC) Channel ID 5
#define AT91C_PWMC_CHID6      (0x1 <<  6) // (PWMC) Channel ID 6
#define AT91C_PWMC_CHID7      (0x1 <<  7) // (PWMC) Channel ID 7
#define AT91C_PWMC_CHID8      (0x1 <<  8) // (PWMC) Channel ID 8
#define AT91C_PWMC_CHID9      (0x1 <<  9) // (PWMC) Channel ID 9
#define AT91C_PWMC_CHID10     (0x1 << 10) // (PWMC) Channel ID 10
#define AT91C_PWMC_CHID11     (0x1 << 11) // (PWMC) Channel ID 11
#define AT91C_PWMC_CHID12     (0x1 << 12) // (PWMC) Channel ID 12
#define AT91C_PWMC_CHID13     (0x1 << 13) // (PWMC) Channel ID 13
#define AT91C_PWMC_CHID14     (0x1 << 14) // (PWMC) Channel ID 14
#define AT91C_PWMC_CHID15     (0x1 << 15) // (PWMC) Channel ID 15
// -------- PWMC_DIS : (PWMC Offset: 0x8) PWMC Disable Register -------- 
// -------- PWMC_SR : (PWMC Offset: 0xc) PWMC Status Register -------- 
// -------- PWMC_IER1 : (PWMC Offset: 0x10) PWMC Interrupt Enable Register -------- 
#define AT91C_PWMC_FCHID0     (0x1 << 16) // (PWMC) Fault Event Channel ID 0
#define AT91C_PWMC_FCHID1     (0x1 << 17) // (PWMC) Fault Event Channel ID 1
#define AT91C_PWMC_FCHID2     (0x1 << 18) // (PWMC) Fault Event Channel ID 2
#define AT91C_PWMC_FCHID3     (0x1 << 19) // (PWMC) Fault Event Channel ID 3
#define AT91C_PWMC_FCHID4     (0x1 << 20) // (PWMC) Fault Event Channel ID 4
#define AT91C_PWMC_FCHID5     (0x1 << 21) // (PWMC) Fault Event Channel ID 5
#define AT91C_PWMC_FCHID6     (0x1 << 22) // (PWMC) Fault Event Channel ID 6
#define AT91C_PWMC_FCHID7     (0x1 << 23) // (PWMC) Fault Event Channel ID 7
#define AT91C_PWMC_FCHID8     (0x1 << 24) // (PWMC) Fault Event Channel ID 8
#define AT91C_PWMC_FCHID9     (0x1 << 25) // (PWMC) Fault Event Channel ID 9
#define AT91C_PWMC_FCHID10    (0x1 << 26) // (PWMC) Fault Event Channel ID 10
#define AT91C_PWMC_FCHID11    (0x1 << 27) // (PWMC) Fault Event Channel ID 11
#define AT91C_PWMC_FCHID12    (0x1 << 28) // (PWMC) Fault Event Channel ID 12
#define AT91C_PWMC_FCHID13    (0x1 << 29) // (PWMC) Fault Event Channel ID 13
#define AT91C_PWMC_FCHID14    (0x1 << 30) // (PWMC) Fault Event Channel ID 14
#define AT91C_PWMC_FCHID15    (0x1 << 31) // (PWMC) Fault Event Channel ID 15
// -------- PWMC_IDR1 : (PWMC Offset: 0x14) PWMC Interrupt Disable Register -------- 
// -------- PWMC_IMR1 : (PWMC Offset: 0x18) PWMC Interrupt Mask Register -------- 
// -------- PWMC_ISR1 : (PWMC Offset: 0x1c) PWMC Interrupt Status Register -------- 
// -------- PWMC_SYNC : (PWMC Offset: 0x20) PWMC Synchronous Channels Register -------- 
#define AT91C_PWMC_SYNC0      (0x1 <<  0) // (PWMC) Synchronous Channel ID 0
#define AT91C_PWMC_SYNC1      (0x1 <<  1) // (PWMC) Synchronous Channel ID 1
#define AT91C_PWMC_SYNC2      (0x1 <<  2) // (PWMC) Synchronous Channel ID 2
#define AT91C_PWMC_SYNC3      (0x1 <<  3) // (PWMC) Synchronous Channel ID 3
#define AT91C_PWMC_SYNC4      (0x1 <<  4) // (PWMC) Synchronous Channel ID 4
#define AT91C_PWMC_SYNC5      (0x1 <<  5) // (PWMC) Synchronous Channel ID 5
#define AT91C_PWMC_SYNC6      (0x1 <<  6) // (PWMC) Synchronous Channel ID 6
#define AT91C_PWMC_SYNC7      (0x1 <<  7) // (PWMC) Synchronous Channel ID 7
#define AT91C_PWMC_SYNC8      (0x1 <<  8) // (PWMC) Synchronous Channel ID 8
#define AT91C_PWMC_SYNC9      (0x1 <<  9) // (PWMC) Synchronous Channel ID 9
#define AT91C_PWMC_SYNC10     (0x1 << 10) // (PWMC) Synchronous Channel ID 10
#define AT91C_PWMC_SYNC11     (0x1 << 11) // (PWMC) Synchronous Channel ID 11
#define AT91C_PWMC_SYNC12     (0x1 << 12) // (PWMC) Synchronous Channel ID 12
#define AT91C_PWMC_SYNC13     (0x1 << 13) // (PWMC) Synchronous Channel ID 13
#define AT91C_PWMC_SYNC14     (0x1 << 14) // (PWMC) Synchronous Channel ID 14
#define AT91C_PWMC_SYNC15     (0x1 << 15) // (PWMC) Synchronous Channel ID 15
#define AT91C_PWMC_UPDM       (0x3 << 16) // (PWMC) Synchronous Channels Update mode
#define 	AT91C_PWMC_UPDM_MODE0                (0x0 << 16) // (PWMC) Manual write of data and manual trigger of the update
#define 	AT91C_PWMC_UPDM_MODE1                (0x1 << 16) // (PWMC) Manual write of data and automatic trigger of the update
#define 	AT91C_PWMC_UPDM_MODE2                (0x2 << 16) // (PWMC) Automatic write of data and automatic trigger of the update
// -------- PWMC_UPCR : (PWMC Offset: 0x28) PWMC Update Control Register -------- 
#define AT91C_PWMC_UPDULOCK   (0x1 <<  0) // (PWMC) Synchronized Channels Duty Cycle Update Unlock
// -------- PWMC_SCUP : (PWMC Offset: 0x2c) PWM Update Period Register -------- 
#define AT91C_PWMC_UPR        (0xF <<  0) // (PWMC) PWM Update Period.
#define AT91C_PWMC_UPRCNT     (0xF <<  4) // (PWMC) PWM Update Period Counter.
// -------- PWMC_SCUPUPD : (PWMC Offset: 0x30) PWM Update Period Update Register -------- 
#define AT91C_PWMC_UPVUPDAL   (0xF <<  0) // (PWMC) PWM Update Period Update.
// -------- PWMC_IER2 : (PWMC Offset: 0x34) PWMC Interrupt Enable Register -------- 
#define AT91C_PWMC_WRDY       (0x1 <<  0) // (PWMC) PDC Write Ready
#define AT91C_PWMC_ENDTX      (0x1 <<  1) // (PWMC) PDC End of TX Buffer
#define AT91C_PWMC_TXBUFE     (0x1 <<  2) // (PWMC) PDC End of TX Buffer
#define AT91C_PWMC_UNRE       (0x1 <<  3) // (PWMC) PDC End of TX Buffer
// -------- PWMC_IDR2 : (PWMC Offset: 0x38) PWMC Interrupt Disable Register -------- 
// -------- PWMC_IMR2 : (PWMC Offset: 0x3c) PWMC Interrupt Mask Register -------- 
// -------- PWMC_ISR2 : (PWMC Offset: 0x40) PWMC Interrupt Status Register -------- 
#define AT91C_PWMC_CMPM0      (0x1 <<  8) // (PWMC) Comparison x Match
#define AT91C_PWMC_CMPM1      (0x1 <<  9) // (PWMC) Comparison x Match
#define AT91C_PWMC_CMPM2      (0x1 << 10) // (PWMC) Comparison x Match
#define AT91C_PWMC_CMPM3      (0x1 << 11) // (PWMC) Comparison x Match
#define AT91C_PWMC_CMPM4      (0x1 << 12) // (PWMC) Comparison x Match
#define AT91C_PWMC_CMPM5      (0x1 << 13) // (PWMC) Comparison x Match
#define AT91C_PWMC_CMPM6      (0x1 << 14) // (PWMC) Comparison x Match
#define AT91C_PWMC_CMPM7      (0x1 << 15) // (PWMC) Comparison x Match
#define AT91C_PWMC_CMPU0      (0x1 << 16) // (PWMC) Comparison x Update
#define AT91C_PWMC_CMPU1      (0x1 << 17) // (PWMC) Comparison x Update
#define AT91C_PWMC_CMPU2      (0x1 << 18) // (PWMC) Comparison x Update
#define AT91C_PWMC_CMPU3      (0x1 << 19) // (PWMC) Comparison x Update
#define AT91C_PWMC_CMPU4      (0x1 << 20) // (PWMC) Comparison x Update
#define AT91C_PWMC_CMPU5      (0x1 << 21) // (PWMC) Comparison x Update
#define AT91C_PWMC_CMPU6      (0x1 << 22) // (PWMC) Comparison x Update
#define AT91C_PWMC_CMPU7      (0x1 << 23) // (PWMC) Comparison x Update
// -------- PWMC_OOV : (PWMC Offset: 0x44) PWM Output Override Value Register -------- 
#define AT91C_PWMC_OOVH0      (0x1 <<  0) // (PWMC) Output Override Value for PWMH output of the channel 0
#define AT91C_PWMC_OOVH1      (0x1 <<  1) // (PWMC) Output Override Value for PWMH output of the channel 1
#define AT91C_PWMC_OOVH2      (0x1 <<  2) // (PWMC) Output Override Value for PWMH output of the channel 2
#define AT91C_PWMC_OOVH3      (0x1 <<  3) // (PWMC) Output Override Value for PWMH output of the channel 3
#define AT91C_PWMC_OOVH4      (0x1 <<  4) // (PWMC) Output Override Value for PWMH output of the channel 4
#define AT91C_PWMC_OOVH5      (0x1 <<  5) // (PWMC) Output Override Value for PWMH output of the channel 5
#define AT91C_PWMC_OOVH6      (0x1 <<  6) // (PWMC) Output Override Value for PWMH output of the channel 6
#define AT91C_PWMC_OOVH7      (0x1 <<  7) // (PWMC) Output Override Value for PWMH output of the channel 7
#define AT91C_PWMC_OOVH8      (0x1 <<  8) // (PWMC) Output Override Value for PWMH output of the channel 8
#define AT91C_PWMC_OOVH9      (0x1 <<  9) // (PWMC) Output Override Value for PWMH output of the channel 9
#define AT91C_PWMC_OOVH10     (0x1 << 10) // (PWMC) Output Override Value for PWMH output of the channel 10
#define AT91C_PWMC_OOVH11     (0x1 << 11) // (PWMC) Output Override Value for PWMH output of the channel 11
#define AT91C_PWMC_OOVH12     (0x1 << 12) // (PWMC) Output Override Value for PWMH output of the channel 12
#define AT91C_PWMC_OOVH13     (0x1 << 13) // (PWMC) Output Override Value for PWMH output of the channel 13
#define AT91C_PWMC_OOVH14     (0x1 << 14) // (PWMC) Output Override Value for PWMH output of the channel 14
#define AT91C_PWMC_OOVH15     (0x1 << 15) // (PWMC) Output Override Value for PWMH output of the channel 15
#define AT91C_PWMC_OOVL0      (0x1 << 16) // (PWMC) Output Override Value for PWML output of the channel 0
#define AT91C_PWMC_OOVL1      (0x1 << 17) // (PWMC) Output Override Value for PWML output of the channel 1
#define AT91C_PWMC_OOVL2      (0x1 << 18) // (PWMC) Output Override Value for PWML output of the channel 2
#define AT91C_PWMC_OOVL3      (0x1 << 19) // (PWMC) Output Override Value for PWML output of the channel 3
#define AT91C_PWMC_OOVL4      (0x1 << 20) // (PWMC) Output Override Value for PWML output of the channel 4
#define AT91C_PWMC_OOVL5      (0x1 << 21) // (PWMC) Output Override Value for PWML output of the channel 5
#define AT91C_PWMC_OOVL6      (0x1 << 22) // (PWMC) Output Override Value for PWML output of the channel 6
#define AT91C_PWMC_OOVL7      (0x1 << 23) // (PWMC) Output Override Value for PWML output of the channel 7
#define AT91C_PWMC_OOVL8      (0x1 << 24) // (PWMC) Output Override Value for PWML output of the channel 8
#define AT91C_PWMC_OOVL9      (0x1 << 25) // (PWMC) Output Override Value for PWML output of the channel 9
#define AT91C_PWMC_OOVL10     (0x1 << 26) // (PWMC) Output Override Value for PWML output of the channel 10
#define AT91C_PWMC_OOVL11     (0x1 << 27) // (PWMC) Output Override Value for PWML output of the channel 11
#define AT91C_PWMC_OOVL12     (0x1 << 28) // (PWMC) Output Override Value for PWML output of the channel 12
#define AT91C_PWMC_OOVL13     (0x1 << 29) // (PWMC) Output Override Value for PWML output of the channel 13
#define AT91C_PWMC_OOVL14     (0x1 << 30) // (PWMC) Output Override Value for PWML output of the channel 14
#define AT91C_PWMC_OOVL15     (0x1 << 31) // (PWMC) Output Override Value for PWML output of the channel 15
// -------- PWMC_OS : (PWMC Offset: 0x48) PWM Output Selection Register -------- 
#define AT91C_PWMC_OSH0       (0x1 <<  0) // (PWMC) Output Selection for PWMH output of the channel 0
#define AT91C_PWMC_OSH1       (0x1 <<  1) // (PWMC) Output Selection for PWMH output of the channel 1
#define AT91C_PWMC_OSH2       (0x1 <<  2) // (PWMC) Output Selection for PWMH output of the channel 2
#define AT91C_PWMC_OSH3       (0x1 <<  3) // (PWMC) Output Selection for PWMH output of the channel 3
#define AT91C_PWMC_OSH4       (0x1 <<  4) // (PWMC) Output Selection for PWMH output of the channel 4
#define AT91C_PWMC_OSH5       (0x1 <<  5) // (PWMC) Output Selection for PWMH output of the channel 5
#define AT91C_PWMC_OSH6       (0x1 <<  6) // (PWMC) Output Selection for PWMH output of the channel 6
#define AT91C_PWMC_OSH7       (0x1 <<  7) // (PWMC) Output Selection for PWMH output of the channel 7
#define AT91C_PWMC_OSH8       (0x1 <<  8) // (PWMC) Output Selection for PWMH output of the channel 8
#define AT91C_PWMC_OSH9       (0x1 <<  9) // (PWMC) Output Selection for PWMH output of the channel 9
#define AT91C_PWMC_OSH10      (0x1 << 10) // (PWMC) Output Selection for PWMH output of the channel 10
#define AT91C_PWMC_OSH11      (0x1 << 11) // (PWMC) Output Selection for PWMH output of the channel 11
#define AT91C_PWMC_OSH12      (0x1 << 12) // (PWMC) Output Selection for PWMH output of the channel 12
#define AT91C_PWMC_OSH13      (0x1 << 13) // (PWMC) Output Selection for PWMH output of the channel 13
#define AT91C_PWMC_OSH14      (0x1 << 14) // (PWMC) Output Selection for PWMH output of the channel 14
#define AT91C_PWMC_OSH15      (0x1 << 15) // (PWMC) Output Selection for PWMH output of the channel 15
#define AT91C_PWMC_OSL0       (0x1 << 16) // (PWMC) Output Selection for PWML output of the channel 0
#define AT91C_PWMC_OSL1       (0x1 << 17) // (PWMC) Output Selection for PWML output of the channel 1
#define AT91C_PWMC_OSL2       (0x1 << 18) // (PWMC) Output Selection for PWML output of the channel 2
#define AT91C_PWMC_OSL3       (0x1 << 19) // (PWMC) Output Selection for PWML output of the channel 3
#define AT91C_PWMC_OSL4       (0x1 << 20) // (PWMC) Output Selection for PWML output of the channel 4
#define AT91C_PWMC_OSL5       (0x1 << 21) // (PWMC) Output Selection for PWML output of the channel 5
#define AT91C_PWMC_OSL6       (0x1 << 22) // (PWMC) Output Selection for PWML output of the channel 6
#define AT91C_PWMC_OSL7       (0x1 << 23) // (PWMC) Output Selection for PWML output of the channel 7
#define AT91C_PWMC_OSL8       (0x1 << 24) // (PWMC) Output Selection for PWML output of the channel 8
#define AT91C_PWMC_OSL9       (0x1 << 25) // (PWMC) Output Selection for PWML output of the channel 9
#define AT91C_PWMC_OSL10      (0x1 << 26) // (PWMC) Output Selection for PWML output of the channel 10
#define AT91C_PWMC_OSL11      (0x1 << 27) // (PWMC) Output Selection for PWML output of the channel 11
#define AT91C_PWMC_OSL12      (0x1 << 28) // (PWMC) Output Selection for PWML output of the channel 12
#define AT91C_PWMC_OSL13      (0x1 << 29) // (PWMC) Output Selection for PWML output of the channel 13
#define AT91C_PWMC_OSL14      (0x1 << 30) // (PWMC) Output Selection for PWML output of the channel 14
#define AT91C_PWMC_OSL15      (0x1 << 31) // (PWMC) Output Selection for PWML output of the channel 15
// -------- PWMC_OSS : (PWMC Offset: 0x4c) PWM Output Selection Set Register -------- 
#define AT91C_PWMC_OSSH0      (0x1 <<  0) // (PWMC) Output Selection Set for PWMH output of the channel 0
#define AT91C_PWMC_OSSH1      (0x1 <<  1) // (PWMC) Output Selection Set for PWMH output of the channel 1
#define AT91C_PWMC_OSSH2      (0x1 <<  2) // (PWMC) Output Selection Set for PWMH output of the channel 2
#define AT91C_PWMC_OSSH3      (0x1 <<  3) // (PWMC) Output Selection Set for PWMH output of the channel 3
#define AT91C_PWMC_OSSH4      (0x1 <<  4) // (PWMC) Output Selection Set for PWMH output of the channel 4
#define AT91C_PWMC_OSSH5      (0x1 <<  5) // (PWMC) Output Selection Set for PWMH output of the channel 5
#define AT91C_PWMC_OSSH6      (0x1 <<  6) // (PWMC) Output Selection Set for PWMH output of the channel 6
#define AT91C_PWMC_OSSH7      (0x1 <<  7) // (PWMC) Output Selection Set for PWMH output of the channel 7
#define AT91C_PWMC_OSSH8      (0x1 <<  8) // (PWMC) Output Selection Set for PWMH output of the channel 8
#define AT91C_PWMC_OSSH9      (0x1 <<  9) // (PWMC) Output Selection Set for PWMH output of the channel 9
#define AT91C_PWMC_OSSH10     (0x1 << 10) // (PWMC) Output Selection Set for PWMH output of the channel 10
#define AT91C_PWMC_OSSH11     (0x1 << 11) // (PWMC) Output Selection Set for PWMH output of the channel 11
#define AT91C_PWMC_OSSH12     (0x1 << 12) // (PWMC) Output Selection Set for PWMH output of the channel 12
#define AT91C_PWMC_OSSH13     (0x1 << 13) // (PWMC) Output Selection Set for PWMH output of the channel 13
#define AT91C_PWMC_OSSH14     (0x1 << 14) // (PWMC) Output Selection Set for PWMH output of the channel 14
#define AT91C_PWMC_OSSH15     (0x1 << 15) // (PWMC) Output Selection Set for PWMH output of the channel 15
#define AT91C_PWMC_OSSL0      (0x1 << 16) // (PWMC) Output Selection Set for PWML output of the channel 0
#define AT91C_PWMC_OSSL1      (0x1 << 17) // (PWMC) Output Selection Set for PWML output of the channel 1
#define AT91C_PWMC_OSSL2      (0x1 << 18) // (PWMC) Output Selection Set for PWML output of the channel 2
#define AT91C_PWMC_OSSL3      (0x1 << 19) // (PWMC) Output Selection Set for PWML output of the channel 3
#define AT91C_PWMC_OSSL4      (0x1 << 20) // (PWMC) Output Selection Set for PWML output of the channel 4
#define AT91C_PWMC_OSSL5      (0x1 << 21) // (PWMC) Output Selection Set for PWML output of the channel 5
#define AT91C_PWMC_OSSL6      (0x1 << 22) // (PWMC) Output Selection Set for PWML output of the channel 6
#define AT91C_PWMC_OSSL7      (0x1 << 23) // (PWMC) Output Selection Set for PWML output of the channel 7
#define AT91C_PWMC_OSSL8      (0x1 << 24) // (PWMC) Output Selection Set for PWML output of the channel 8
#define AT91C_PWMC_OSSL9      (0x1 << 25) // (PWMC) Output Selection Set for PWML output of the channel 9
#define AT91C_PWMC_OSSL10     (0x1 << 26) // (PWMC) Output Selection Set for PWML output of the channel 10
#define AT91C_PWMC_OSSL11     (0x1 << 27) // (PWMC) Output Selection Set for PWML output of the channel 11
#define AT91C_PWMC_OSSL12     (0x1 << 28) // (PWMC) Output Selection Set for PWML output of the channel 12
#define AT91C_PWMC_OSSL13     (0x1 << 29) // (PWMC) Output Selection Set for PWML output of the channel 13
#define AT91C_PWMC_OSSL14     (0x1 << 30) // (PWMC) Output Selection Set for PWML output of the channel 14
#define AT91C_PWMC_OSSL15     (0x1 << 31) // (PWMC) Output Selection Set for PWML output of the channel 15
// -------- PWMC_OSC : (PWMC Offset: 0x50) PWM Output Selection Clear Register -------- 
#define AT91C_PWMC_OSCH0      (0x1 <<  0) // (PWMC) Output Selection Clear for PWMH output of the channel 0
#define AT91C_PWMC_OSCH1      (0x1 <<  1) // (PWMC) Output Selection Clear for PWMH output of the channel 1
#define AT91C_PWMC_OSCH2      (0x1 <<  2) // (PWMC) Output Selection Clear for PWMH output of the channel 2
#define AT91C_PWMC_OSCH3      (0x1 <<  3) // (PWMC) Output Selection Clear for PWMH output of the channel 3
#define AT91C_PWMC_OSCH4      (0x1 <<  4) // (PWMC) Output Selection Clear for PWMH output of the channel 4
#define AT91C_PWMC_OSCH5      (0x1 <<  5) // (PWMC) Output Selection Clear for PWMH output of the channel 5
#define AT91C_PWMC_OSCH6      (0x1 <<  6) // (PWMC) Output Selection Clear for PWMH output of the channel 6
#define AT91C_PWMC_OSCH7      (0x1 <<  7) // (PWMC) Output Selection Clear for PWMH output of the channel 7
#define AT91C_PWMC_OSCH8      (0x1 <<  8) // (PWMC) Output Selection Clear for PWMH output of the channel 8
#define AT91C_PWMC_OSCH9      (0x1 <<  9) // (PWMC) Output Selection Clear for PWMH output of the channel 9
#define AT91C_PWMC_OSCH10     (0x1 << 10) // (PWMC) Output Selection Clear for PWMH output of the channel 10
#define AT91C_PWMC_OSCH11     (0x1 << 11) // (PWMC) Output Selection Clear for PWMH output of the channel 11
#define AT91C_PWMC_OSCH12     (0x1 << 12) // (PWMC) Output Selection Clear for PWMH output of the channel 12
#define AT91C_PWMC_OSCH13     (0x1 << 13) // (PWMC) Output Selection Clear for PWMH output of the channel 13
#define AT91C_PWMC_OSCH14     (0x1 << 14) // (PWMC) Output Selection Clear for PWMH output of the channel 14
#define AT91C_PWMC_OSCH15     (0x1 << 15) // (PWMC) Output Selection Clear for PWMH output of the channel 15
#define AT91C_PWMC_OSCL0      (0x1 << 16) // (PWMC) Output Selection Clear for PWML output of the channel 0
#define AT91C_PWMC_OSCL1      (0x1 << 17) // (PWMC) Output Selection Clear for PWML output of the channel 1
#define AT91C_PWMC_OSCL2      (0x1 << 18) // (PWMC) Output Selection Clear for PWML output of the channel 2
#define AT91C_PWMC_OSCL3      (0x1 << 19) // (PWMC) Output Selection Clear for PWML output of the channel 3
#define AT91C_PWMC_OSCL4      (0x1 << 20) // (PWMC) Output Selection Clear for PWML output of the channel 4
#define AT91C_PWMC_OSCL5      (0x1 << 21) // (PWMC) Output Selection Clear for PWML output of the channel 5
#define AT91C_PWMC_OSCL6      (0x1 << 22) // (PWMC) Output Selection Clear for PWML output of the channel 6
#define AT91C_PWMC_OSCL7      (0x1 << 23) // (PWMC) Output Selection Clear for PWML output of the channel 7
#define AT91C_PWMC_OSCL8      (0x1 << 24) // (PWMC) Output Selection Clear for PWML output of the channel 8
#define AT91C_PWMC_OSCL9      (0x1 << 25) // (PWMC) Output Selection Clear for PWML output of the channel 9
#define AT91C_PWMC_OSCL10     (0x1 << 26) // (PWMC) Output Selection Clear for PWML output of the channel 10
#define AT91C_PWMC_OSCL11     (0x1 << 27) // (PWMC) Output Selection Clear for PWML output of the channel 11
#define AT91C_PWMC_OSCL12     (0x1 << 28) // (PWMC) Output Selection Clear for PWML output of the channel 12
#define AT91C_PWMC_OSCL13     (0x1 << 29) // (PWMC) Output Selection Clear for PWML output of the channel 13
#define AT91C_PWMC_OSCL14     (0x1 << 30) // (PWMC) Output Selection Clear for PWML output of the channel 14
#define AT91C_PWMC_OSCL15     (0x1 << 31) // (PWMC) Output Selection Clear for PWML output of the channel 15
// -------- PWMC_OSSUPD : (PWMC Offset: 0x54) Output Selection Set for PWMH / PWML output of the channel x -------- 
#define AT91C_PWMC_OSSUPDH0   (0x1 <<  0) // (PWMC) Output Selection Set for PWMH output of the channel 0
#define AT91C_PWMC_OSSUPDH1   (0x1 <<  1) // (PWMC) Output Selection Set for PWMH output of the channel 1
#define AT91C_PWMC_OSSUPDH2   (0x1 <<  2) // (PWMC) Output Selection Set for PWMH output of the channel 2
#define AT91C_PWMC_OSSUPDH3   (0x1 <<  3) // (PWMC) Output Selection Set for PWMH output of the channel 3
#define AT91C_PWMC_OSSUPDH4   (0x1 <<  4) // (PWMC) Output Selection Set for PWMH output of the channel 4
#define AT91C_PWMC_OSSUPDH5   (0x1 <<  5) // (PWMC) Output Selection Set for PWMH output of the channel 5
#define AT91C_PWMC_OSSUPDH6   (0x1 <<  6) // (PWMC) Output Selection Set for PWMH output of the channel 6
#define AT91C_PWMC_OSSUPDH7   (0x1 <<  7) // (PWMC) Output Selection Set for PWMH output of the channel 7
#define AT91C_PWMC_OSSUPDH8   (0x1 <<  8) // (PWMC) Output Selection Set for PWMH output of the channel 8
#define AT91C_PWMC_OSSUPDH9   (0x1 <<  9) // (PWMC) Output Selection Set for PWMH output of the channel 9
#define AT91C_PWMC_OSSUPDH10  (0x1 << 10) // (PWMC) Output Selection Set for PWMH output of the channel 10
#define AT91C_PWMC_OSSUPDH11  (0x1 << 11) // (PWMC) Output Selection Set for PWMH output of the channel 11
#define AT91C_PWMC_OSSUPDH12  (0x1 << 12) // (PWMC) Output Selection Set for PWMH output of the channel 12
#define AT91C_PWMC_OSSUPDH13  (0x1 << 13) // (PWMC) Output Selection Set for PWMH output of the channel 13
#define AT91C_PWMC_OSSUPDH14  (0x1 << 14) // (PWMC) Output Selection Set for PWMH output of the channel 14
#define AT91C_PWMC_OSSUPDH15  (0x1 << 15) // (PWMC) Output Selection Set for PWMH output of the channel 15
#define AT91C_PWMC_OSSUPDL0   (0x1 << 16) // (PWMC) Output Selection Set for PWML output of the channel 0
#define AT91C_PWMC_OSSUPDL1   (0x1 << 17) // (PWMC) Output Selection Set for PWML output of the channel 1
#define AT91C_PWMC_OSSUPDL2   (0x1 << 18) // (PWMC) Output Selection Set for PWML output of the channel 2
#define AT91C_PWMC_OSSUPDL3   (0x1 << 19) // (PWMC) Output Selection Set for PWML output of the channel 3
#define AT91C_PWMC_OSSUPDL4   (0x1 << 20) // (PWMC) Output Selection Set for PWML output of the channel 4
#define AT91C_PWMC_OSSUPDL5   (0x1 << 21) // (PWMC) Output Selection Set for PWML output of the channel 5
#define AT91C_PWMC_OSSUPDL6   (0x1 << 22) // (PWMC) Output Selection Set for PWML output of the channel 6
#define AT91C_PWMC_OSSUPDL7   (0x1 << 23) // (PWMC) Output Selection Set for PWML output of the channel 7
#define AT91C_PWMC_OSSUPDL8   (0x1 << 24) // (PWMC) Output Selection Set for PWML output of the channel 8
#define AT91C_PWMC_OSSUPDL9   (0x1 << 25) // (PWMC) Output Selection Set for PWML output of the channel 9
#define AT91C_PWMC_OSSUPDL10  (0x1 << 26) // (PWMC) Output Selection Set for PWML output of the channel 10
#define AT91C_PWMC_OSSUPDL11  (0x1 << 27) // (PWMC) Output Selection Set for PWML output of the channel 11
#define AT91C_PWMC_OSSUPDL12  (0x1 << 28) // (PWMC) Output Selection Set for PWML output of the channel 12
#define AT91C_PWMC_OSSUPDL13  (0x1 << 29) // (PWMC) Output Selection Set for PWML output of the channel 13
#define AT91C_PWMC_OSSUPDL14  (0x1 << 30) // (PWMC) Output Selection Set for PWML output of the channel 14
#define AT91C_PWMC_OSSUPDL15  (0x1 << 31) // (PWMC) Output Selection Set for PWML output of the channel 15
// -------- PWMC_OSCUPD : (PWMC Offset: 0x58) Output Selection Clear for PWMH / PWML output of the channel x -------- 
#define AT91C_PWMC_OSCUPDH0   (0x1 <<  0) // (PWMC) Output Selection Clear for PWMH output of the channel 0
#define AT91C_PWMC_OSCUPDH1   (0x1 <<  1) // (PWMC) Output Selection Clear for PWMH output of the channel 1
#define AT91C_PWMC_OSCUPDH2   (0x1 <<  2) // (PWMC) Output Selection Clear for PWMH output of the channel 2
#define AT91C_PWMC_OSCUPDH3   (0x1 <<  3) // (PWMC) Output Selection Clear for PWMH output of the channel 3
#define AT91C_PWMC_OSCUPDH4   (0x1 <<  4) // (PWMC) Output Selection Clear for PWMH output of the channel 4
#define AT91C_PWMC_OSCUPDH5   (0x1 <<  5) // (PWMC) Output Selection Clear for PWMH output of the channel 5
#define AT91C_PWMC_OSCUPDH6   (0x1 <<  6) // (PWMC) Output Selection Clear for PWMH output of the channel 6
#define AT91C_PWMC_OSCUPDH7   (0x1 <<  7) // (PWMC) Output Selection Clear for PWMH output of the channel 7
#define AT91C_PWMC_OSCUPDH8   (0x1 <<  8) // (PWMC) Output Selection Clear for PWMH output of the channel 8
#define AT91C_PWMC_OSCUPDH9   (0x1 <<  9) // (PWMC) Output Selection Clear for PWMH output of the channel 9
#define AT91C_PWMC_OSCUPDH10  (0x1 << 10) // (PWMC) Output Selection Clear for PWMH output of the channel 10
#define AT91C_PWMC_OSCUPDH11  (0x1 << 11) // (PWMC) Output Selection Clear for PWMH output of the channel 11
#define AT91C_PWMC_OSCUPDH12  (0x1 << 12) // (PWMC) Output Selection Clear for PWMH output of the channel 12
#define AT91C_PWMC_OSCUPDH13  (0x1 << 13) // (PWMC) Output Selection Clear for PWMH output of the channel 13
#define AT91C_PWMC_OSCUPDH14  (0x1 << 14) // (PWMC) Output Selection Clear for PWMH output of the channel 14
#define AT91C_PWMC_OSCUPDH15  (0x1 << 15) // (PWMC) Output Selection Clear for PWMH output of the channel 15
#define AT91C_PWMC_OSCUPDL0   (0x1 << 16) // (PWMC) Output Selection Clear for PWML output of the channel 0
#define AT91C_PWMC_OSCUPDL1   (0x1 << 17) // (PWMC) Output Selection Clear for PWML output of the channel 1
#define AT91C_PWMC_OSCUPDL2   (0x1 << 18) // (PWMC) Output Selection Clear for PWML output of the channel 2
#define AT91C_PWMC_OSCUPDL3   (0x1 << 19) // (PWMC) Output Selection Clear for PWML output of the channel 3
#define AT91C_PWMC_OSCUPDL4   (0x1 << 20) // (PWMC) Output Selection Clear for PWML output of the channel 4
#define AT91C_PWMC_OSCUPDL5   (0x1 << 21) // (PWMC) Output Selection Clear for PWML output of the channel 5
#define AT91C_PWMC_OSCUPDL6   (0x1 << 22) // (PWMC) Output Selection Clear for PWML output of the channel 6
#define AT91C_PWMC_OSCUPDL7   (0x1 << 23) // (PWMC) Output Selection Clear for PWML output of the channel 7
#define AT91C_PWMC_OSCUPDL8   (0x1 << 24) // (PWMC) Output Selection Clear for PWML output of the channel 8
#define AT91C_PWMC_OSCUPDL9   (0x1 << 25) // (PWMC) Output Selection Clear for PWML output of the channel 9
#define AT91C_PWMC_OSCUPDL10  (0x1 << 26) // (PWMC) Output Selection Clear for PWML output of the channel 10
#define AT91C_PWMC_OSCUPDL11  (0x1 << 27) // (PWMC) Output Selection Clear for PWML output of the channel 11
#define AT91C_PWMC_OSCUPDL12  (0x1 << 28) // (PWMC) Output Selection Clear for PWML output of the channel 12
#define AT91C_PWMC_OSCUPDL13  (0x1 << 29) // (PWMC) Output Selection Clear for PWML output of the channel 13
#define AT91C_PWMC_OSCUPDL14  (0x1 << 30) // (PWMC) Output Selection Clear for PWML output of the channel 14
#define AT91C_PWMC_OSCUPDL15  (0x1 << 31) // (PWMC) Output Selection Clear for PWML output of the channel 15
// -------- PWMC_FMR : (PWMC Offset: 0x5c) PWM Fault Mode Register -------- 
#define AT91C_PWMC_FPOL0      (0x1 <<  0) // (PWMC) Fault Polarity on fault input 0
#define AT91C_PWMC_FPOL1      (0x1 <<  1) // (PWMC) Fault Polarity on fault input 1
#define AT91C_PWMC_FPOL2      (0x1 <<  2) // (PWMC) Fault Polarity on fault input 2
#define AT91C_PWMC_FPOL3      (0x1 <<  3) // (PWMC) Fault Polarity on fault input 3
#define AT91C_PWMC_FPOL4      (0x1 <<  4) // (PWMC) Fault Polarity on fault input 4
#define AT91C_PWMC_FPOL5      (0x1 <<  5) // (PWMC) Fault Polarity on fault input 5
#define AT91C_PWMC_FPOL6      (0x1 <<  6) // (PWMC) Fault Polarity on fault input 6
#define AT91C_PWMC_FPOL7      (0x1 <<  7) // (PWMC) Fault Polarity on fault input 7
#define AT91C_PWMC_FMOD0      (0x1 <<  8) // (PWMC) Fault Activation Mode on fault input 0
#define AT91C_PWMC_FMOD1      (0x1 <<  9) // (PWMC) Fault Activation Mode on fault input 1
#define AT91C_PWMC_FMOD2      (0x1 << 10) // (PWMC) Fault Activation Mode on fault input 2
#define AT91C_PWMC_FMOD3      (0x1 << 11) // (PWMC) Fault Activation Mode on fault input 3
#define AT91C_PWMC_FMOD4      (0x1 << 12) // (PWMC) Fault Activation Mode on fault input 4
#define AT91C_PWMC_FMOD5      (0x1 << 13) // (PWMC) Fault Activation Mode on fault input 5
#define AT91C_PWMC_FMOD6      (0x1 << 14) // (PWMC) Fault Activation Mode on fault input 6
#define AT91C_PWMC_FMOD7      (0x1 << 15) // (PWMC) Fault Activation Mode on fault input 7
#define AT91C_PWMC_FFIL00     (0x1 << 16) // (PWMC) Fault Filtering on fault input 0
#define AT91C_PWMC_FFIL01     (0x1 << 17) // (PWMC) Fault Filtering on fault input 1
#define AT91C_PWMC_FFIL02     (0x1 << 18) // (PWMC) Fault Filtering on fault input 2
#define AT91C_PWMC_FFIL03     (0x1 << 19) // (PWMC) Fault Filtering on fault input 3
#define AT91C_PWMC_FFIL04     (0x1 << 20) // (PWMC) Fault Filtering on fault input 4
#define AT91C_PWMC_FFIL05     (0x1 << 21) // (PWMC) Fault Filtering on fault input 5
#define AT91C_PWMC_FFIL06     (0x1 << 22) // (PWMC) Fault Filtering on fault input 6
#define AT91C_PWMC_FFIL07     (0x1 << 23) // (PWMC) Fault Filtering on fault input 7
// -------- PWMC_FSR : (PWMC Offset: 0x60) Fault Input x Value -------- 
#define AT91C_PWMC_FIV0       (0x1 <<  0) // (PWMC) Fault Input 0 Value
#define AT91C_PWMC_FIV1       (0x1 <<  1) // (PWMC) Fault Input 1 Value
#define AT91C_PWMC_FIV2       (0x1 <<  2) // (PWMC) Fault Input 2 Value
#define AT91C_PWMC_FIV3       (0x1 <<  3) // (PWMC) Fault Input 3 Value
#define AT91C_PWMC_FIV4       (0x1 <<  4) // (PWMC) Fault Input 4 Value
#define AT91C_PWMC_FIV5       (0x1 <<  5) // (PWMC) Fault Input 5 Value
#define AT91C_PWMC_FIV6       (0x1 <<  6) // (PWMC) Fault Input 6 Value
#define AT91C_PWMC_FIV7       (0x1 <<  7) // (PWMC) Fault Input 7 Value
#define AT91C_PWMC_FS0        (0x1 <<  8) // (PWMC) Fault 0 Status
#define AT91C_PWMC_FS1        (0x1 <<  9) // (PWMC) Fault 1 Status
#define AT91C_PWMC_FS2        (0x1 << 10) // (PWMC) Fault 2 Status
#define AT91C_PWMC_FS3        (0x1 << 11) // (PWMC) Fault 3 Status
#define AT91C_PWMC_FS4        (0x1 << 12) // (PWMC) Fault 4 Status
#define AT91C_PWMC_FS5        (0x1 << 13) // (PWMC) Fault 5 Status
#define AT91C_PWMC_FS6        (0x1 << 14) // (PWMC) Fault 6 Status
#define AT91C_PWMC_FS7        (0x1 << 15) // (PWMC) Fault 7 Status
// -------- PWMC_FCR : (PWMC Offset: 0x64) Fault y Clear -------- 
#define AT91C_PWMC_FCLR0      (0x1 <<  0) // (PWMC) Fault 0 Clear
#define AT91C_PWMC_FCLR1      (0x1 <<  1) // (PWMC) Fault 1 Clear
#define AT91C_PWMC_FCLR2      (0x1 <<  2) // (PWMC) Fault 2 Clear
#define AT91C_PWMC_FCLR3      (0x1 <<  3) // (PWMC) Fault 3 Clear
#define AT91C_PWMC_FCLR4      (0x1 <<  4) // (PWMC) Fault 4 Clear
#define AT91C_PWMC_FCLR5      (0x1 <<  5) // (PWMC) Fault 5 Clear
#define AT91C_PWMC_FCLR6      (0x1 <<  6) // (PWMC) Fault 6 Clear
#define AT91C_PWMC_FCLR7      (0x1 <<  7) // (PWMC) Fault 7 Clear
// -------- PWMC_FPV : (PWMC Offset: 0x68) PWM Fault Protection Value -------- 
#define AT91C_PWMC_FPVH0      (0x1 <<  0) // (PWMC) Fault Protection Value for PWMH output on channel 0
#define AT91C_PWMC_FPVH1      (0x1 <<  1) // (PWMC) Fault Protection Value for PWMH output on channel 1
#define AT91C_PWMC_FPVH2      (0x1 <<  2) // (PWMC) Fault Protection Value for PWMH output on channel 2
#define AT91C_PWMC_FPVH3      (0x1 <<  3) // (PWMC) Fault Protection Value for PWMH output on channel 3
#define AT91C_PWMC_FPVH4      (0x1 <<  4) // (PWMC) Fault Protection Value for PWMH output on channel 4
#define AT91C_PWMC_FPVH5      (0x1 <<  5) // (PWMC) Fault Protection Value for PWMH output on channel 5
#define AT91C_PWMC_FPVH6      (0x1 <<  6) // (PWMC) Fault Protection Value for PWMH output on channel 6
#define AT91C_PWMC_FPVH7      (0x1 <<  7) // (PWMC) Fault Protection Value for PWMH output on channel 7
#define AT91C_PWMC_FPVL0      (0x1 << 16) // (PWMC) Fault Protection Value for PWML output on channel 0
#define AT91C_PWMC_FPVL1      (0x1 << 17) // (PWMC) Fault Protection Value for PWML output on channel 1
#define AT91C_PWMC_FPVL2      (0x1 << 18) // (PWMC) Fault Protection Value for PWML output on channel 2
#define AT91C_PWMC_FPVL3      (0x1 << 19) // (PWMC) Fault Protection Value for PWML output on channel 3
#define AT91C_PWMC_FPVL4      (0x1 << 20) // (PWMC) Fault Protection Value for PWML output on channel 4
#define AT91C_PWMC_FPVL5      (0x1 << 21) // (PWMC) Fault Protection Value for PWML output on channel 5
#define AT91C_PWMC_FPVL6      (0x1 << 22) // (PWMC) Fault Protection Value for PWML output on channel 6
#define AT91C_PWMC_FPVL7      (0x1 << 23) // (PWMC) Fault Protection Value for PWML output on channel 7
// -------- PWMC_FPER1 : (PWMC Offset: 0x6c) PWM Fault Protection Enable Register 1 -------- 
#define AT91C_PWMC_FPE0       (0xFF <<  0) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 0
#define AT91C_PWMC_FPE1       (0xFF <<  8) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 1
#define AT91C_PWMC_FPE2       (0xFF << 16) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 2
#define AT91C_PWMC_FPE3       (0xFF << 24) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 3
// -------- PWMC_FPER2 : (PWMC Offset: 0x70) PWM Fault Protection Enable Register 2 -------- 
#define AT91C_PWMC_FPE4       (0xFF <<  0) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 4
#define AT91C_PWMC_FPE5       (0xFF <<  8) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 5
#define AT91C_PWMC_FPE6       (0xFF << 16) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 6
#define AT91C_PWMC_FPE7       (0xFF << 24) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 7
// -------- PWMC_FPER3 : (PWMC Offset: 0x74) PWM Fault Protection Enable Register 3 -------- 
#define AT91C_PWMC_FPE8       (0xFF <<  0) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 8
#define AT91C_PWMC_FPE9       (0xFF <<  8) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 9
#define AT91C_PWMC_FPE10      (0xFF << 16) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 10
#define AT91C_PWMC_FPE11      (0xFF << 24) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 11
// -------- PWMC_FPER4 : (PWMC Offset: 0x78) PWM Fault Protection Enable Register 4 -------- 
#define AT91C_PWMC_FPE12      (0xFF <<  0) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 12
#define AT91C_PWMC_FPE13      (0xFF <<  8) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 13
#define AT91C_PWMC_FPE14      (0xFF << 16) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 14
#define AT91C_PWMC_FPE15      (0xFF << 24) // (PWMC) Fault Protection Enable with Fault Input y for PWM channel 15
// -------- PWMC_EL0MR : (PWMC Offset: 0x7c) PWM Event Line 0 Mode Register -------- 
#define AT91C_PWMC_L0CSEL0    (0x1 <<  0) // (PWMC) Comparison 0 Selection
#define AT91C_PWMC_L0CSEL1    (0x1 <<  1) // (PWMC) Comparison 1 Selection
#define AT91C_PWMC_L0CSEL2    (0x1 <<  2) // (PWMC) Comparison 2 Selection
#define AT91C_PWMC_L0CSEL3    (0x1 <<  3) // (PWMC) Comparison 3 Selection
#define AT91C_PWMC_L0CSEL4    (0x1 <<  4) // (PWMC) Comparison 4 Selection
#define AT91C_PWMC_L0CSEL5    (0x1 <<  5) // (PWMC) Comparison 5 Selection
#define AT91C_PWMC_L0CSEL6    (0x1 <<  6) // (PWMC) Comparison 6 Selection
#define AT91C_PWMC_L0CSEL7    (0x1 <<  7) // (PWMC) Comparison 7 Selection
// -------- PWMC_EL1MR : (PWMC Offset: 0x80) PWM Event Line 1 Mode Register -------- 
#define AT91C_PWMC_L1CSEL0    (0x1 <<  0) // (PWMC) Comparison 0 Selection
#define AT91C_PWMC_L1CSEL1    (0x1 <<  1) // (PWMC) Comparison 1 Selection
#define AT91C_PWMC_L1CSEL2    (0x1 <<  2) // (PWMC) Comparison 2 Selection
#define AT91C_PWMC_L1CSEL3    (0x1 <<  3) // (PWMC) Comparison 3 Selection
#define AT91C_PWMC_L1CSEL4    (0x1 <<  4) // (PWMC) Comparison 4 Selection
#define AT91C_PWMC_L1CSEL5    (0x1 <<  5) // (PWMC) Comparison 5 Selection
#define AT91C_PWMC_L1CSEL6    (0x1 <<  6) // (PWMC) Comparison 6 Selection
#define AT91C_PWMC_L1CSEL7    (0x1 <<  7) // (PWMC) Comparison 7 Selection
// -------- PWMC_EL2MR : (PWMC Offset: 0x84) PWM Event line 2 Mode Register -------- 
#define AT91C_PWMC_L2CSEL0    (0x1 <<  0) // (PWMC) Comparison 0 Selection
#define AT91C_PWMC_L2CSEL1    (0x1 <<  1) // (PWMC) Comparison 1 Selection
#define AT91C_PWMC_L2CSEL2    (0x1 <<  2) // (PWMC) Comparison 2 Selection
#define AT91C_PWMC_L2CSEL3    (0x1 <<  3) // (PWMC) Comparison 3 Selection
#define AT91C_PWMC_L2CSEL4    (0x1 <<  4) // (PWMC) Comparison 4 Selection
#define AT91C_PWMC_L2CSEL5    (0x1 <<  5) // (PWMC) Comparison 5 Selection
#define AT91C_PWMC_L2CSEL6    (0x1 <<  6) // (PWMC) Comparison 6 Selection
#define AT91C_PWMC_L2CSEL7    (0x1 <<  7) // (PWMC) Comparison 7 Selection
// -------- PWMC_EL3MR : (PWMC Offset: 0x88) PWM Event line 3 Mode Register -------- 
#define AT91C_PWMC_L3CSEL0    (0x1 <<  0) // (PWMC) Comparison 0 Selection
#define AT91C_PWMC_L3CSEL1    (0x1 <<  1) // (PWMC) Comparison 1 Selection
#define AT91C_PWMC_L3CSEL2    (0x1 <<  2) // (PWMC) Comparison 2 Selection
#define AT91C_PWMC_L3CSEL3    (0x1 <<  3) // (PWMC) Comparison 3 Selection
#define AT91C_PWMC_L3CSEL4    (0x1 <<  4) // (PWMC) Comparison 4 Selection
#define AT91C_PWMC_L3CSEL5    (0x1 <<  5) // (PWMC) Comparison 5 Selection
#define AT91C_PWMC_L3CSEL6    (0x1 <<  6) // (PWMC) Comparison 6 Selection
#define AT91C_PWMC_L3CSEL7    (0x1 <<  7) // (PWMC) Comparison 7 Selection
// -------- PWMC_EL4MR : (PWMC Offset: 0x8c) PWM Event line 4 Mode Register -------- 
#define AT91C_PWMC_L4CSEL0    (0x1 <<  0) // (PWMC) Comparison 0 Selection
#define AT91C_PWMC_L4CSEL1    (0x1 <<  1) // (PWMC) Comparison 1 Selection
#define AT91C_PWMC_L4CSEL2    (0x1 <<  2) // (PWMC) Comparison 2 Selection
#define AT91C_PWMC_L4CSEL3    (0x1 <<  3) // (PWMC) Comparison 3 Selection
#define AT91C_PWMC_L4CSEL4    (0x1 <<  4) // (PWMC) Comparison 4 Selection
#define AT91C_PWMC_L4CSEL5    (0x1 <<  5) // (PWMC) Comparison 5 Selection
#define AT91C_PWMC_L4CSEL6    (0x1 <<  6) // (PWMC) Comparison 6 Selection
#define AT91C_PWMC_L4CSEL7    (0x1 <<  7) // (PWMC) Comparison 7 Selection
// -------- PWMC_EL5MR : (PWMC Offset: 0x90) PWM Event line 5 Mode Register -------- 
#define AT91C_PWMC_L5CSEL0    (0x1 <<  0) // (PWMC) Comparison 0 Selection
#define AT91C_PWMC_L5CSEL1    (0x1 <<  1) // (PWMC) Comparison 1 Selection
#define AT91C_PWMC_L5CSEL2    (0x1 <<  2) // (PWMC) Comparison 2 Selection
#define AT91C_PWMC_L5CSEL3    (0x1 <<  3) // (PWMC) Comparison 3 Selection
#define AT91C_PWMC_L5CSEL4    (0x1 <<  4) // (PWMC) Comparison 4 Selection
#define AT91C_PWMC_L5CSEL5    (0x1 <<  5) // (PWMC) Comparison 5 Selection
#define AT91C_PWMC_L5CSEL6    (0x1 <<  6) // (PWMC) Comparison 6 Selection
#define AT91C_PWMC_L5CSEL7    (0x1 <<  7) // (PWMC) Comparison 7 Selection
// -------- PWMC_EL6MR : (PWMC Offset: 0x94) PWM Event line 6 Mode Register -------- 
#define AT91C_PWMC_L6CSEL0    (0x1 <<  0) // (PWMC) Comparison 0 Selection
#define AT91C_PWMC_L6CSEL1    (0x1 <<  1) // (PWMC) Comparison 1 Selection
#define AT91C_PWMC_L6CSEL2    (0x1 <<  2) // (PWMC) Comparison 2 Selection
#define AT91C_PWMC_L6CSEL3    (0x1 <<  3) // (PWMC) Comparison 3 Selection
#define AT91C_PWMC_L6CSEL4    (0x1 <<  4) // (PWMC) Comparison 4 Selection
#define AT91C_PWMC_L6CSEL5    (0x1 <<  5) // (PWMC) Comparison 5 Selection
#define AT91C_PWMC_L6CSEL6    (0x1 <<  6) // (PWMC) Comparison 6 Selection
#define AT91C_PWMC_L6CSEL7    (0x1 <<  7) // (PWMC) Comparison 7 Selection
// -------- PWMC_EL7MR : (PWMC Offset: 0x98) PWM Event line 7 Mode Register -------- 
#define AT91C_PWMC_L7CSEL0    (0x1 <<  0) // (PWMC) Comparison 0 Selection
#define AT91C_PWMC_L7CSEL1    (0x1 <<  1) // (PWMC) Comparison 1 Selection
#define AT91C_PWMC_L7CSEL2    (0x1 <<  2) // (PWMC) Comparison 2 Selection
#define AT91C_PWMC_L7CSEL3    (0x1 <<  3) // (PWMC) Comparison 3 Selection
#define AT91C_PWMC_L7CSEL4    (0x1 <<  4) // (PWMC) Comparison 4 Selection
#define AT91C_PWMC_L7CSEL5    (0x1 <<  5) // (PWMC) Comparison 5 Selection
#define AT91C_PWMC_L7CSEL6    (0x1 <<  6) // (PWMC) Comparison 6 Selection
#define AT91C_PWMC_L7CSEL7    (0x1 <<  7) // (PWMC) Comparison 7 Selection
// -------- PWMC_WPCR : (PWMC Offset: 0xe4) PWM Write Protection Control Register -------- 
#define AT91C_PWMC_WPCMD      (0x3 <<  0) // (PWMC) Write Protection Command
#define AT91C_PWMC_WPRG0      (0x1 <<  2) // (PWMC) Write Protect Register Group 0
#define AT91C_PWMC_WPRG1      (0x1 <<  3) // (PWMC) Write Protect Register Group 1
#define AT91C_PWMC_WPRG2      (0x1 <<  4) // (PWMC) Write Protect Register Group 2
#define AT91C_PWMC_WPRG3      (0x1 <<  5) // (PWMC) Write Protect Register Group 3
#define AT91C_PWMC_WPRG4      (0x1 <<  6) // (PWMC) Write Protect Register Group 4
#define AT91C_PWMC_WPRG5      (0x1 <<  7) // (PWMC) Write Protect Register Group 5
#define AT91C_PWMC_WPKEY      (0xFFFFFF <<  8) // (PWMC) Protection Password
// -------- PWMC_WPVS : (PWMC Offset: 0xe8) Write Protection Status Register -------- 
#define AT91C_PWMC_WPSWS0     (0x1 <<  0) // (PWMC) Write Protect SW Group 0 Status 
#define AT91C_PWMC_WPSWS1     (0x1 <<  1) // (PWMC) Write Protect SW Group 1 Status 
#define AT91C_PWMC_WPSWS2     (0x1 <<  2) // (PWMC) Write Protect SW Group 2 Status 
#define AT91C_PWMC_WPSWS3     (0x1 <<  3) // (PWMC) Write Protect SW Group 3 Status 
#define AT91C_PWMC_WPSWS4     (0x1 <<  4) // (PWMC) Write Protect SW Group 4 Status 
#define AT91C_PWMC_WPSWS5     (0x1 <<  5) // (PWMC) Write Protect SW Group 5 Status 
#define AT91C_PWMC_WPVS       (0x1 <<  7) // (PWMC) Write Protection Enable
#define AT91C_PWMC_WPHWS0     (0x1 <<  8) // (PWMC) Write Protect HW Group 0 Status 
#define AT91C_PWMC_WPHWS1     (0x1 <<  9) // (PWMC) Write Protect HW Group 1 Status 
#define AT91C_PWMC_WPHWS2     (0x1 << 10) // (PWMC) Write Protect HW Group 2 Status 
#define AT91C_PWMC_WPHWS3     (0x1 << 11) // (PWMC) Write Protect HW Group 3 Status 
#define AT91C_PWMC_WPHWS4     (0x1 << 12) // (PWMC) Write Protect HW Group 4 Status 
#define AT91C_PWMC_WPHWS5     (0x1 << 13) // (PWMC) Write Protect HW Group 5 Status 
#define AT91C_PWMC_WPVSRC     (0xFFFF << 16) // (PWMC) Write Protection Violation Source
// -------- PWMC_CMP0V : (PWMC Offset: 0x130) PWM Comparison Value 0 Register -------- 
#define AT91C_PWMC_CV         (0xFFFFFF <<  0) // (PWMC) PWM Comparison Value 0.
#define AT91C_PWMC_CVM        (0x1 << 24) // (PWMC) Comparison Value 0 Mode.
// -------- PWMC_CMP0VUPD : (PWMC Offset: 0x134) PWM Comparison Value 0 Update Register -------- 
#define AT91C_PWMC_CVUPD      (0xFFFFFF <<  0) // (PWMC) PWM Comparison Value Update.
#define AT91C_PWMC_CVMUPD     (0x1 << 24) // (PWMC) Comparison Value Update Mode.
// -------- PWMC_CMP0M : (PWMC Offset: 0x138) PWM Comparison 0 Mode Register -------- 
#define AT91C_PWMC_CEN        (0x1 <<  0) // (PWMC) Comparison Enable.
#define AT91C_PWMC_CTR        (0xF <<  4) // (PWMC) PWM Comparison Trigger.
#define AT91C_PWMC_CPR        (0xF <<  8) // (PWMC) PWM Comparison Period.
#define AT91C_PWMC_CPRCNT     (0xF << 12) // (PWMC) PWM Comparison Period Counter.
#define AT91C_PWMC_CUPR       (0xF << 16) // (PWMC) PWM Comparison Update Period.
#define AT91C_PWMC_CUPRCNT    (0xF << 20) // (PWMC) PWM Comparison Update Period Counter.
// -------- PWMC_CMP0MUPD : (PWMC Offset: 0x13c) PWM Comparison 0 Mode Update Register -------- 
#define AT91C_PWMC_CENUPD     (0x1 <<  0) // (PWMC) Comparison Enable Update.
#define AT91C_PWMC_CTRUPD     (0xF <<  4) // (PWMC) PWM Comparison Trigger Update.
#define AT91C_PWMC_CPRUPD     (0xF <<  8) // (PWMC) PWM Comparison Period Update.
#define AT91C_PWMC_CUPRUPD    (0xF << 16) // (PWMC) PWM Comparison Update Period Update.
// -------- PWMC_CMP1V : (PWMC Offset: 0x140) PWM Comparison Value 1 Register -------- 
// -------- PWMC_CMP1VUPD : (PWMC Offset: 0x144) PWM Comparison Value 1 Update Register -------- 
// -------- PWMC_CMP1M : (PWMC Offset: 0x148) PWM Comparison 1 Mode Register -------- 
// -------- PWMC_CMP1MUPD : (PWMC Offset: 0x14c) PWM Comparison 1 Mode Update Register -------- 
// -------- PWMC_CMP2V : (PWMC Offset: 0x150) PWM Comparison Value 2 Register -------- 
// -------- PWMC_CMP2VUPD : (PWMC Offset: 0x154) PWM Comparison Value 2 Update Register -------- 
// -------- PWMC_CMP2M : (PWMC Offset: 0x158) PWM Comparison 2 Mode Register -------- 
// -------- PWMC_CMP2MUPD : (PWMC Offset: 0x15c) PWM Comparison 2 Mode Update Register -------- 
// -------- PWMC_CMP3V : (PWMC Offset: 0x160) PWM Comparison Value 3 Register -------- 
// -------- PWMC_CMP3VUPD : (PWMC Offset: 0x164) PWM Comparison Value 3 Update Register -------- 
// -------- PWMC_CMP3M : (PWMC Offset: 0x168) PWM Comparison 3 Mode Register -------- 
// -------- PWMC_CMP3MUPD : (PWMC Offset: 0x16c) PWM Comparison 3 Mode Update Register -------- 
// -------- PWMC_CMP4V : (PWMC Offset: 0x170) PWM Comparison Value 4 Register -------- 
// -------- PWMC_CMP4VUPD : (PWMC Offset: 0x174) PWM Comparison Value 4 Update Register -------- 
// -------- PWMC_CMP4M : (PWMC Offset: 0x178) PWM Comparison 4 Mode Register -------- 
// -------- PWMC_CMP4MUPD : (PWMC Offset: 0x17c) PWM Comparison 4 Mode Update Register -------- 
// -------- PWMC_CMP5V : (PWMC Offset: 0x180) PWM Comparison Value 5 Register -------- 
// -------- PWMC_CMP5VUPD : (PWMC Offset: 0x184) PWM Comparison Value 5 Update Register -------- 
// -------- PWMC_CMP5M : (PWMC Offset: 0x188) PWM Comparison 5 Mode Register -------- 
// -------- PWMC_CMP5MUPD : (PWMC Offset: 0x18c) PWM Comparison 5 Mode Update Register -------- 
// -------- PWMC_CMP6V : (PWMC Offset: 0x190) PWM Comparison Value 6 Register -------- 
// -------- PWMC_CMP6VUPD : (PWMC Offset: 0x194) PWM Comparison Value 6 Update Register -------- 
// -------- PWMC_CMP6M : (PWMC Offset: 0x198) PWM Comparison 6 Mode Register -------- 
// -------- PWMC_CMP6MUPD : (PWMC Offset: 0x19c) PWM Comparison 6 Mode Update Register -------- 
// -------- PWMC_CMP7V : (PWMC Offset: 0x1a0) PWM Comparison Value 7 Register -------- 
// -------- PWMC_CMP7VUPD : (PWMC Offset: 0x1a4) PWM Comparison Value 7 Update Register -------- 
// -------- PWMC_CMP7M : (PWMC Offset: 0x1a8) PWM Comparison 7 Mode Register -------- 
// -------- PWMC_CMP7MUPD : (PWMC Offset: 0x1ac) PWM Comparison 7 Mode Update Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Analog to Digital Convertor
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_ADC {
	AT91_REG	 ADC_CR; 	// ADC Control Register
	AT91_REG	 ADC_MR; 	// ADC Mode Register
	AT91_REG	 Reserved0[2]; 	// 
	AT91_REG	 ADC_CHER; 	// ADC Channel Enable Register
	AT91_REG	 ADC_CHDR; 	// ADC Channel Disable Register
	AT91_REG	 ADC_CHSR; 	// ADC Channel Status Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 ADC_LCDR; 	// ADC Last Converted Data Register
	AT91_REG	 ADC_IER; 	// ADC Interrupt Enable Register
	AT91_REG	 ADC_IDR; 	// ADC Interrupt Disable Register
	AT91_REG	 ADC_IMR; 	// ADC Interrupt Mask Register
	AT91_REG	 ADC_SR; 	// ADC Status Register
	AT91_REG	 Reserved2[2]; 	// 
	AT91_REG	 ADC_OVR; 	// unspecified
	AT91_REG	 ADC_CWR; 	// unspecified
	AT91_REG	 ADC_CWSR; 	// unspecified
	AT91_REG	 ADC_CGR; 	// Control gain register
	AT91_REG	 ADC_COR; 	// unspecified
	AT91_REG	 ADC_CDR0; 	// ADC Channel Data Register 0
	AT91_REG	 ADC_CDR1; 	// ADC Channel Data Register 1
	AT91_REG	 ADC_CDR2; 	// ADC Channel Data Register 2
	AT91_REG	 ADC_CDR3; 	// ADC Channel Data Register 3
	AT91_REG	 ADC_CDR4; 	// ADC Channel Data Register 4
	AT91_REG	 ADC_CDR5; 	// ADC Channel Data Register 5
	AT91_REG	 ADC_CDR6; 	// ADC Channel Data Register 6
	AT91_REG	 ADC_CDR7; 	// ADC Channel Data Register 7
	AT91_REG	 ADC_CDR8; 	// ADC Channel Data Register 8
	AT91_REG	 ADC_CDR9; 	// ADC Channel Data Register 9
	AT91_REG	 ADC_CDR10; 	// ADC Channel Data Register 10
	AT91_REG	 ADC_CDR11; 	// ADC Channel Data Register 11
	AT91_REG	 ADC_CDR12; 	// ADC Channel Data Register 12
	AT91_REG	 ADC_CDR13; 	// ADC Channel Data Register 13
	AT91_REG	 ADC_CDR14; 	// ADC Channel Data Register 14
	AT91_REG	 ADC_CDR15; 	// ADC Channel Data Register 15
	AT91_REG	 Reserved3[1]; 	// 
	AT91_REG	 ADC_ACR; 	// unspecified
	AT91_REG	 Reserved4[21]; 	// 
	AT91_REG	 ADC_ADDRSIZE; 	// ADC ADDRSIZE REGISTER 
	AT91_REG	 ADC_IPNAME1; 	// ADC IPNAME1 REGISTER 
	AT91_REG	 ADC_IPNAME2; 	// ADC IPNAME2 REGISTER 
	AT91_REG	 ADC_FEATURES; 	// ADC FEATURES REGISTER 
	AT91_REG	 ADC_VER; 	// ADC VERSION REGISTER
	AT91_REG	 ADC_RPR; 	// Receive Pointer Register
	AT91_REG	 ADC_RCR; 	// Receive Counter Register
	AT91_REG	 ADC_TPR; 	// Transmit Pointer Register
	AT91_REG	 ADC_TCR; 	// Transmit Counter Register
	AT91_REG	 ADC_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 ADC_RNCR; 	// Receive Next Counter Register
	AT91_REG	 ADC_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 ADC_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 ADC_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 ADC_PTSR; 	// PDC Transfer Status Register
} AT91S_ADC, *AT91PS_ADC;
#else
#define ADC_CR          (AT91_CAST(AT91_REG *) 	0x00000000) // (ADC_CR) ADC Control Register
#define ADC_MR          (AT91_CAST(AT91_REG *) 	0x00000004) // (ADC_MR) ADC Mode Register
#define ADC_CHER        (AT91_CAST(AT91_REG *) 	0x00000010) // (ADC_CHER) ADC Channel Enable Register
#define ADC_CHDR        (AT91_CAST(AT91_REG *) 	0x00000014) // (ADC_CHDR) ADC Channel Disable Register
#define ADC_CHSR        (AT91_CAST(AT91_REG *) 	0x00000018) // (ADC_CHSR) ADC Channel Status Register
#define ADC_LCDR        (AT91_CAST(AT91_REG *) 	0x00000020) // (ADC_LCDR) ADC Last Converted Data Register
#define ADC_IER         (AT91_CAST(AT91_REG *) 	0x00000024) // (ADC_IER) ADC Interrupt Enable Register
#define ADC_IDR         (AT91_CAST(AT91_REG *) 	0x00000028) // (ADC_IDR) ADC Interrupt Disable Register
#define ADC_IMR         (AT91_CAST(AT91_REG *) 	0x0000002C) // (ADC_IMR) ADC Interrupt Mask Register
#define ADC_SR          (AT91_CAST(AT91_REG *) 	0x00000030) // (ADC_SR) ADC Status Register
#define ADC_OVR         (AT91_CAST(AT91_REG *) 	0x0000003C) // (ADC_OVR) unspecified
#define ADC_CWR         (AT91_CAST(AT91_REG *) 	0x00000040) // (ADC_CWR) unspecified
#define ADC_CWSR        (AT91_CAST(AT91_REG *) 	0x00000044) // (ADC_CWSR) unspecified
#define ADC_CGR         (AT91_CAST(AT91_REG *) 	0x00000048) // (ADC_CGR) Control gain register
#define ADC_COR         (AT91_CAST(AT91_REG *) 	0x0000004C) // (ADC_COR) unspecified
#define ADC_CDR0        (AT91_CAST(AT91_REG *) 	0x00000050) // (ADC_CDR0) ADC Channel Data Register 0
#define ADC_CDR1        (AT91_CAST(AT91_REG *) 	0x00000054) // (ADC_CDR1) ADC Channel Data Register 1
#define ADC_CDR2        (AT91_CAST(AT91_REG *) 	0x00000058) // (ADC_CDR2) ADC Channel Data Register 2
#define ADC_CDR3        (AT91_CAST(AT91_REG *) 	0x0000005C) // (ADC_CDR3) ADC Channel Data Register 3
#define ADC_CDR4        (AT91_CAST(AT91_REG *) 	0x00000060) // (ADC_CDR4) ADC Channel Data Register 4
#define ADC_CDR5        (AT91_CAST(AT91_REG *) 	0x00000064) // (ADC_CDR5) ADC Channel Data Register 5
#define ADC_CDR6        (AT91_CAST(AT91_REG *) 	0x00000068) // (ADC_CDR6) ADC Channel Data Register 6
#define ADC_CDR7        (AT91_CAST(AT91_REG *) 	0x0000006C) // (ADC_CDR7) ADC Channel Data Register 7
#define ADC_CDR8        (AT91_CAST(AT91_REG *) 	0x00000070) // (ADC_CDR8) ADC Channel Data Register 8
#define ADC_CDR9        (AT91_CAST(AT91_REG *) 	0x00000074) // (ADC_CDR9) ADC Channel Data Register 9
#define ADC_CDR10       (AT91_CAST(AT91_REG *) 	0x00000078) // (ADC_CDR10) ADC Channel Data Register 10
#define ADC_CDR11       (AT91_CAST(AT91_REG *) 	0x0000007C) // (ADC_CDR11) ADC Channel Data Register 11
#define ADC_CDR12       (AT91_CAST(AT91_REG *) 	0x00000080) // (ADC_CDR12) ADC Channel Data Register 12
#define ADC_CDR13       (AT91_CAST(AT91_REG *) 	0x00000084) // (ADC_CDR13) ADC Channel Data Register 13
#define ADC_CDR14       (AT91_CAST(AT91_REG *) 	0x00000088) // (ADC_CDR14) ADC Channel Data Register 14
#define ADC_CDR15       (AT91_CAST(AT91_REG *) 	0x0000008C) // (ADC_CDR15) ADC Channel Data Register 15
#define ADC_ACR         (AT91_CAST(AT91_REG *) 	0x00000094) // (ADC_ACR) unspecified
#define ADC_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000EC) // (ADC_ADDRSIZE) ADC ADDRSIZE REGISTER 
#define ADC_IPNAME1     (AT91_CAST(AT91_REG *) 	0x000000F0) // (ADC_IPNAME1) ADC IPNAME1 REGISTER 
#define ADC_IPNAME2     (AT91_CAST(AT91_REG *) 	0x000000F4) // (ADC_IPNAME2) ADC IPNAME2 REGISTER 
#define ADC_FEATURES    (AT91_CAST(AT91_REG *) 	0x000000F8) // (ADC_FEATURES) ADC FEATURES REGISTER 
#define ADC_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (ADC_VER) ADC VERSION REGISTER

#endif
// -------- ADC_CR : (ADC Offset: 0x0) ADC Control Register -------- 
#define AT91C_ADC_SWRST       (0x1 <<  0) // (ADC) Software Reset
#define AT91C_ADC_START       (0x1 <<  1) // (ADC) Start Conversion
// -------- ADC_MR : (ADC Offset: 0x4) ADC Mode Register -------- 
#define AT91C_ADC_TRGEN       (0x1 <<  0) // (ADC) Trigger Enable
#define 	AT91C_ADC_TRGEN_DIS                  (0x0) // (ADC) Hradware triggers are disabled. Starting a conversion is only possible by software
#define 	AT91C_ADC_TRGEN_EN                   (0x1) // (ADC) Hardware trigger selected by TRGSEL field is enabled.
#define AT91C_ADC_TRGSEL      (0x7 <<  1) // (ADC) Trigger Selection
#define 	AT91C_ADC_TRGSEL_EXT                  (0x0 <<  1) // (ADC) Selected TRGSEL = External Trigger
#define 	AT91C_ADC_TRGSEL_TIOA0                (0x1 <<  1) // (ADC) Selected TRGSEL = TIAO0
#define 	AT91C_ADC_TRGSEL_TIOA1                (0x2 <<  1) // (ADC) Selected TRGSEL = TIAO1
#define 	AT91C_ADC_TRGSEL_TIOA2                (0x3 <<  1) // (ADC) Selected TRGSEL = TIAO2
#define 	AT91C_ADC_TRGSEL_PWM0_TRIG            (0x4 <<  1) // (ADC) Selected TRGSEL = PWM trigger
#define 	AT91C_ADC_TRGSEL_PWM1_TRIG            (0x5 <<  1) // (ADC) Selected TRGSEL = PWM Trigger
#define 	AT91C_ADC_TRGSEL_RESERVED             (0x6 <<  1) // (ADC) Selected TRGSEL = Reserved
#define AT91C_ADC_LOWRES      (0x1 <<  4) // (ADC) Resolution.
#define 	AT91C_ADC_LOWRES_10_BIT               (0x0 <<  4) // (ADC) 10-bit resolution
#define 	AT91C_ADC_LOWRES_8_BIT                (0x1 <<  4) // (ADC) 8-bit resolution
#define AT91C_ADC_SLEEP       (0x1 <<  5) // (ADC) Sleep Mode
#define 	AT91C_ADC_SLEEP_NORMAL_MODE          (0x0 <<  5) // (ADC) Normal Mode
#define 	AT91C_ADC_SLEEP_MODE                 (0x1 <<  5) // (ADC) Sleep Mode
#define AT91C_ADC_PRESCAL     (0x3F <<  8) // (ADC) Prescaler rate selection
#define AT91C_ADC_STARTUP     (0x1F << 16) // (ADC) Startup Time
#define AT91C_ADC_SHTIM       (0xF << 24) // (ADC) Sample & Hold Time
// -------- 	ADC_CHER : (ADC Offset: 0x10) ADC Channel Enable Register -------- 
#define AT91C_ADC_CH0         (0x1 <<  0) // (ADC) Channel 0
#define AT91C_ADC_CH1         (0x1 <<  1) // (ADC) Channel 1
#define AT91C_ADC_CH2         (0x1 <<  2) // (ADC) Channel 2
#define AT91C_ADC_CH3         (0x1 <<  3) // (ADC) Channel 3
#define AT91C_ADC_CH4         (0x1 <<  4) // (ADC) Channel 4
#define AT91C_ADC_CH5         (0x1 <<  5) // (ADC) Channel 5
#define AT91C_ADC_CH6         (0x1 <<  6) // (ADC) Channel 6
#define AT91C_ADC_CH7         (0x1 <<  7) // (ADC) Channel 7
#define AT91C_ADC_CH8         (0x1 <<  8) // (ADC) Channel 8
#define AT91C_ADC_CH9         (0x1 <<  9) // (ADC) Channel 9
#define AT91C_ADC_CH10        (0x1 << 10) // (ADC) Channel 10
#define AT91C_ADC_CH11        (0x1 << 11) // (ADC) Channel 11
#define AT91C_ADC_CH12        (0x1 << 12) // (ADC) Channel 12
#define AT91C_ADC_CH13        (0x1 << 13) // (ADC) Channel 13
#define AT91C_ADC_CH14        (0x1 << 14) // (ADC) Channel 14
#define AT91C_ADC_CH15        (0x1 << 15) // (ADC) Channel 15
// -------- 	ADC_CHDR : (ADC Offset: 0x14) ADC Channel Disable Register -------- 
// -------- 	ADC_CHSR : (ADC Offset: 0x18) ADC Channel Status Register -------- 
// -------- ADC_LCDR : (ADC Offset: 0x20) ADC Last Converted Data Register -------- 
#define AT91C_ADC_LDATA       (0x3FF <<  0) // (ADC) Last Data Converted
// -------- ADC_IER : (ADC Offset: 0x24) ADC Interrupt Enable Register -------- 
#define AT91C_ADC_EOC0        (0x1 <<  0) // (ADC) End of Conversion
#define AT91C_ADC_EOC1        (0x1 <<  1) // (ADC) End of Conversion
#define AT91C_ADC_EOC2        (0x1 <<  2) // (ADC) End of Conversion
#define AT91C_ADC_EOC3        (0x1 <<  3) // (ADC) End of Conversion
#define AT91C_ADC_EOC4        (0x1 <<  4) // (ADC) End of Conversion
#define AT91C_ADC_EOC5        (0x1 <<  5) // (ADC) End of Conversion
#define AT91C_ADC_EOC6        (0x1 <<  6) // (ADC) End of Conversion
#define AT91C_ADC_EOC7        (0x1 <<  7) // (ADC) End of Conversion
#define AT91C_ADC_EOC8        (0x1 <<  8) // (ADC) End of Conversion
#define AT91C_ADC_EOC9        (0x1 <<  9) // (ADC) End of Conversion
#define AT91C_ADC_EOC10       (0x1 << 10) // (ADC) End of Conversion
#define AT91C_ADC_EOC11       (0x1 << 11) // (ADC) End of Conversion
#define AT91C_ADC_EOC12       (0x1 << 12) // (ADC) End of Conversion
#define AT91C_ADC_EOC13       (0x1 << 13) // (ADC) End of Conversion
#define AT91C_ADC_EOC14       (0x1 << 14) // (ADC) End of Conversion
#define AT91C_ADC_EOC15       (0x1 << 15) // (ADC) End of Conversion
#define AT91C_ADC_DRDY        (0x1 << 24) // (ADC) Data Ready
#define AT91C_ADC_GOVRE       (0x1 << 25) // (ADC) General Overrun
#define AT91C_ADC_ENDRX       (0x1 << 27) // (ADC) End of Receiver Transfer
#define AT91C_ADC_RXBUFF      (0x1 << 28) // (ADC) RXBUFF Interrupt
// -------- ADC_IDR : (ADC Offset: 0x28) ADC Interrupt Disable Register -------- 
// -------- ADC_IMR : (ADC Offset: 0x2c) ADC Interrupt Mask Register -------- 
// -------- ADC_SR : (ADC Offset: 0x30) ADC Status Register -------- 
// -------- ADC_OVR : (ADC Offset: 0x3c)  -------- 
#define AT91C_ADC_OVRE2       (0x1 << 10) // (ADC) Overrun Error
#define AT91C_ADC_OVRE3       (0x1 << 11) // (ADC) Overrun Error
#define AT91C_ADC_OVRE4       (0x1 << 12) // (ADC) Overrun Error
#define AT91C_ADC_OVRE5       (0x1 << 13) // (ADC) Overrun Error
// -------- ADC_CWR : (ADC Offset: 0x40)  -------- 
// -------- ADC_CWSR : (ADC Offset: 0x44)  -------- 
// -------- ADC_CGR : (ADC Offset: 0x48)  -------- 
// -------- ADC_COR : (ADC Offset: 0x4c)  -------- 
// -------- ADC_CDR0 : (ADC Offset: 0x50) ADC Channel Data Register 0 -------- 
#define AT91C_ADC_DATA        (0x3FF <<  0) // (ADC) Converted Data
// -------- ADC_CDR1 : (ADC Offset: 0x54) ADC Channel Data Register 1 -------- 
// -------- ADC_CDR2 : (ADC Offset: 0x58) ADC Channel Data Register 2 -------- 
// -------- ADC_CDR3 : (ADC Offset: 0x5c) ADC Channel Data Register 3 -------- 
// -------- ADC_CDR4 : (ADC Offset: 0x60) ADC Channel Data Register 4 -------- 
// -------- ADC_CDR5 : (ADC Offset: 0x64) ADC Channel Data Register 5 -------- 
// -------- ADC_CDR6 : (ADC Offset: 0x68) ADC Channel Data Register 6 -------- 
// -------- ADC_CDR7 : (ADC Offset: 0x6c) ADC Channel Data Register 7 -------- 
// -------- ADC_CDR8 : (ADC Offset: 0x70) ADC Channel Data Register 8 -------- 
// -------- ADC_CDR9 : (ADC Offset: 0x74) ADC Channel Data Register 9 -------- 
// -------- ADC_CDR10 : (ADC Offset: 0x78) ADC Channel Data Register 10 -------- 
// -------- ADC_CDR11 : (ADC Offset: 0x7c) ADC Channel Data Register 11 -------- 
// -------- ADC_CDR12 : (ADC Offset: 0x80) ADC Channel Data Register 12 -------- 
// -------- ADC_CDR13 : (ADC Offset: 0x84) ADC Channel Data Register 13 -------- 
// -------- ADC_CDR14 : (ADC Offset: 0x88) ADC Channel Data Register 14 -------- 
// -------- ADC_CDR15 : (ADC Offset: 0x8c) ADC Channel Data Register 15 -------- 
// -------- ADC_VER : (ADC Offset: 0xfc) ADC VER -------- 
#define AT91C_ADC_VER         (0xF <<  0) // (ADC) ADC VER

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Digital to Analog Convertor
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_DAC {
	AT91_REG	 DAC_CR; 	// Control Register
	AT91_REG	 DAC_MR; 	// Mode Register
	AT91_REG	 Reserved0[2]; 	// 
	AT91_REG	 DAC_CHER; 	// Channel Enable Register
	AT91_REG	 DAC_CHDR; 	// Channel Disable Register
	AT91_REG	 DAC_CHSR; 	// Channel Status Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 DAC_CDR; 	// Coversion Data Register
	AT91_REG	 DAC_IER; 	// Interrupt Enable Register
	AT91_REG	 DAC_IDR; 	// Interrupt Disable Register
	AT91_REG	 DAC_IMR; 	// Interrupt Mask Register
	AT91_REG	 DAC_ISR; 	// Interrupt Status Register
	AT91_REG	 Reserved2[24]; 	// 
	AT91_REG	 DAC_ACR; 	// Analog Current Register
	AT91_REG	 Reserved3[19]; 	// 
	AT91_REG	 DAC_WPMR; 	// Write Protect Mode Register
	AT91_REG	 DAC_WPSR; 	// Write Protect Status Register
} AT91S_DAC, *AT91PS_DAC;
#else
#define DAC_CR          (AT91_CAST(AT91_REG *) 	0x00000000) // (DAC_CR) Control Register
#define DAC_MR          (AT91_CAST(AT91_REG *) 	0x00000004) // (DAC_MR) Mode Register
#define DAC_CHER        (AT91_CAST(AT91_REG *) 	0x00000010) // (DAC_CHER) Channel Enable Register
#define DAC_CHDR        (AT91_CAST(AT91_REG *) 	0x00000014) // (DAC_CHDR) Channel Disable Register
#define DAC_CHSR        (AT91_CAST(AT91_REG *) 	0x00000018) // (DAC_CHSR) Channel Status Register
#define DAC_CDR         (AT91_CAST(AT91_REG *) 	0x00000020) // (DAC_CDR) Coversion Data Register
#define DAC_IER         (AT91_CAST(AT91_REG *) 	0x00000024) // (DAC_IER) Interrupt Enable Register
#define DAC_IDR         (AT91_CAST(AT91_REG *) 	0x00000028) // (DAC_IDR) Interrupt Disable Register
#define DAC_IMR         (AT91_CAST(AT91_REG *) 	0x0000002C) // (DAC_IMR) Interrupt Mask Register
#define DAC_ISR         (AT91_CAST(AT91_REG *) 	0x00000030) // (DAC_ISR) Interrupt Status Register
#define DAC_ACR         (AT91_CAST(AT91_REG *) 	0x00000094) // (DAC_ACR) Analog Current Register
#define DAC_WPMR        (AT91_CAST(AT91_REG *) 	0x000000E4) // (DAC_WPMR) Write Protect Mode Register
#define DAC_WPSR        (AT91_CAST(AT91_REG *) 	0x000000E8) // (DAC_WPSR) Write Protect Status Register

#endif
// -------- DAC_CR : (DAC Offset: 0x0) Control Register -------- 
#define AT91C_DAC_SWRST       (0x1 <<  0) // (DAC) Software Reset
// -------- DAC_MR : (DAC Offset: 0x4) Mode Register -------- 
#define AT91C_DAC_TRGEN       (0x1 <<  0) // (DAC) Trigger Enable
#define AT91C_DAC_TRGSEL      (0x7 <<  1) // (DAC) Trigger Selection
#define 	AT91C_DAC_TRGSEL_EXTRG0               (0x0 <<  1) // (DAC) External Trigger 0
#define 	AT91C_DAC_TRGSEL_EXTRG1               (0x1 <<  1) // (DAC) External Trigger 1
#define 	AT91C_DAC_TRGSEL_EXTRG2               (0x2 <<  1) // (DAC) External Trigger 2
#define 	AT91C_DAC_TRGSEL_EXTRG3               (0x3 <<  1) // (DAC) External Trigger 3
#define 	AT91C_DAC_TRGSEL_EXTRG4               (0x4 <<  1) // (DAC) External Trigger 4
#define 	AT91C_DAC_TRGSEL_EXTRG5               (0x5 <<  1) // (DAC) External Trigger 5
#define 	AT91C_DAC_TRGSEL_EXTRG6               (0x6 <<  1) // (DAC) External Trigger 6
#define AT91C_DAC_WORD        (0x1 <<  4) // (DAC) Word Transfer
#define AT91C_DAC_SLEEP       (0x1 <<  5) // (DAC) Sleep Mode
#define AT91C_DAC_FASTW       (0x1 <<  6) // (DAC) Fast Wake up Mode
#define AT91C_DAC_REFRESH     (0xFF <<  8) // (DAC) Refresh period
#define AT91C_DAC_USER_SEL    (0x3 << 16) // (DAC) User Channel Selection
#define 	AT91C_DAC_USER_SEL_CH0                  (0x0 << 16) // (DAC) Channel 0
#define 	AT91C_DAC_USER_SEL_CH1                  (0x1 << 16) // (DAC) Channel 1
#define 	AT91C_DAC_USER_SEL_CH2                  (0x2 << 16) // (DAC) Channel 2
#define AT91C_DAC_TAG         (0x1 << 20) // (DAC) Tag selection mode
#define AT91C_DAC_MAXSPEED    (0x1 << 21) // (DAC) Max speed mode
#define AT91C_DAC_STARTUP     (0x3F << 24) // (DAC) Startup Time Selection
// -------- DAC_CHER : (DAC Offset: 0x10) Channel Enable Register -------- 
#define AT91C_DAC_CH0         (0x1 <<  0) // (DAC) Channel 0
#define AT91C_DAC_CH1         (0x1 <<  1) // (DAC) Channel 1
#define AT91C_DAC_CH2         (0x1 <<  2) // (DAC) Channel 2
// -------- DAC_CHDR : (DAC Offset: 0x14) Channel Disable Register -------- 
// -------- DAC_CHSR : (DAC Offset: 0x18) Channel Status Register -------- 
// -------- DAC_CDR : (DAC Offset: 0x20) Conversion Data Register -------- 
#define AT91C_DAC_DATA        (0x0 <<  0) // (DAC) Data to convert
// -------- DAC_IER : (DAC Offset: 0x24) DAC Interrupt Enable -------- 
#define AT91C_DAC_TXRDY       (0x1 <<  0) // (DAC) Transmission Ready Interrupt
#define AT91C_DAC_EOC         (0x1 <<  1) // (DAC) End of Conversion Interrupt
#define AT91C_DAC_TXDMAEND    (0x1 <<  2) // (DAC) End of DMA Interrupt
#define AT91C_DAC_TXBUFEMPT   (0x1 <<  3) // (DAC) Buffer Empty Interrupt
// -------- DAC_IDR : (DAC Offset: 0x28) DAC Interrupt Disable -------- 
// -------- DAC_IMR : (DAC Offset: 0x2c) DAC Interrupt Mask -------- 
// -------- DAC_ISR : (DAC Offset: 0x30) DAC Interrupt Status -------- 
// -------- DAC_ACR : (DAC Offset: 0x94) Analog Current Register -------- 
#define AT91C_DAC_IBCTL       (0x1FF <<  0) // (DAC) Bias current control
// -------- DAC_WPMR : (DAC Offset: 0xe4) Write Protect Mode Register -------- 
#define AT91C_DAC_WPEN        (0x1 <<  0) // (DAC) Write Protect Enable
#define AT91C_DAC_WPKEY       (0xFFFFFF <<  8) // (DAC) Write Protect KEY
// -------- DAC_WPSR : (DAC Offset: 0xe8) Write Protect Status Register -------- 
#define AT91C_DAC_WPROTERR    (0x1 <<  0) // (DAC) Write protection error
#define AT91C_DAC_WPROTADDR   (0xFF <<  8) // (DAC) Write protection error address

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR HDMA Channel structure
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_HDMA_CH {
	AT91_REG	 HDMA_SADDR; 	// HDMA Channel Source Address Register
	AT91_REG	 HDMA_DADDR; 	// HDMA Channel Destination Address Register
	AT91_REG	 HDMA_DSCR; 	// HDMA Channel Descriptor Address Register
	AT91_REG	 HDMA_CTRLA; 	// HDMA Channel Control A Register
	AT91_REG	 HDMA_CTRLB; 	// HDMA Channel Control B Register
	AT91_REG	 HDMA_CFG; 	// HDMA Channel Configuration Register
	AT91_REG	 HDMA_SPIP; 	// HDMA Channel Source Picture in Picture Configuration Register
	AT91_REG	 HDMA_DPIP; 	// HDMA Channel Destination Picture in Picture Configuration Register
	AT91_REG	 HDMA_BDSCR; 	// HDMA Reserved
	AT91_REG	 HDMA_CADDR; 	// HDMA Reserved
} AT91S_HDMA_CH, *AT91PS_HDMA_CH;
#else
#define HDMA_SADDR      (AT91_CAST(AT91_REG *) 	0x00000000) // (HDMA_SADDR) HDMA Channel Source Address Register
#define HDMA_DADDR      (AT91_CAST(AT91_REG *) 	0x00000004) // (HDMA_DADDR) HDMA Channel Destination Address Register
#define HDMA_DSCR       (AT91_CAST(AT91_REG *) 	0x00000008) // (HDMA_DSCR) HDMA Channel Descriptor Address Register
#define HDMA_CTRLA      (AT91_CAST(AT91_REG *) 	0x0000000C) // (HDMA_CTRLA) HDMA Channel Control A Register
#define HDMA_CTRLB      (AT91_CAST(AT91_REG *) 	0x00000010) // (HDMA_CTRLB) HDMA Channel Control B Register
#define HDMA_CFG        (AT91_CAST(AT91_REG *) 	0x00000014) // (HDMA_CFG) HDMA Channel Configuration Register
#define HDMA_SPIP       (AT91_CAST(AT91_REG *) 	0x00000018) // (HDMA_SPIP) HDMA Channel Source Picture in Picture Configuration Register
#define HDMA_DPIP       (AT91_CAST(AT91_REG *) 	0x0000001C) // (HDMA_DPIP) HDMA Channel Destination Picture in Picture Configuration Register
#define HDMA_BDSCR      (AT91_CAST(AT91_REG *) 	0x00000020) // (HDMA_BDSCR) HDMA Reserved
#define HDMA_CADDR      (AT91_CAST(AT91_REG *) 	0x00000024) // (HDMA_CADDR) HDMA Reserved

#endif
// -------- HDMA_SADDR : (HDMA_CH Offset: 0x0)  -------- 
#define AT91C_SADDR           (0x0 <<  0) // (HDMA_CH) 
// -------- HDMA_DADDR : (HDMA_CH Offset: 0x4)  -------- 
#define AT91C_DADDR           (0x0 <<  0) // (HDMA_CH) 
// -------- HDMA_DSCR : (HDMA_CH Offset: 0x8)  -------- 
#define AT91C_HDMA_DSCR_IF    (0x3 <<  0) // (HDMA_CH) Select AHB-Lite Interface for current channel
#define 	AT91C_HDMA_DSCR_IF_0                    (0x0) // (HDMA_CH) The Buffer Transfer descriptor is fetched via AHB-Lite Interface 0.
#define 	AT91C_HDMA_DSCR_IF_1                    (0x1) // (HDMA_CH) The Buffer Transfer descriptor is fetched via AHB-Lite Interface 1.
#define 	AT91C_HDMA_DSCR_IF_2                    (0x2) // (HDMA_CH) The Buffer Transfer descriptor is fetched via AHB-Lite Interface 2.
#define 	AT91C_HDMA_DSCR_IF_3                    (0x3) // (HDMA_CH) The Buffer Transfer descriptor is fetched via AHB-Lite Interface 3.
#define AT91C_HDMA_DSCR       (0x3FFFFFFF <<  2) // (HDMA_CH) Buffer Transfer descriptor address. This address is word aligned.
// -------- HDMA_CTRLA : (HDMA_CH Offset: 0xc)  -------- 
#define AT91C_HDMA_BTSIZE     (0xFFFF <<  0) // (HDMA_CH) Buffer Transfer Size.
#define AT91C_HDMA_SCSIZE     (0x7 << 16) // (HDMA_CH) Source Chunk Transfer Size.
#define 	AT91C_HDMA_SCSIZE_1                    (0x0 << 16) // (HDMA_CH) 1.
#define 	AT91C_HDMA_SCSIZE_4                    (0x1 << 16) // (HDMA_CH) 4.
#define 	AT91C_HDMA_SCSIZE_8                    (0x2 << 16) // (HDMA_CH) 8.
#define 	AT91C_HDMA_SCSIZE_16                   (0x3 << 16) // (HDMA_CH) 16.
#define 	AT91C_HDMA_SCSIZE_32                   (0x4 << 16) // (HDMA_CH) 32.
#define 	AT91C_HDMA_SCSIZE_64                   (0x5 << 16) // (HDMA_CH) 64.
#define 	AT91C_HDMA_SCSIZE_128                  (0x6 << 16) // (HDMA_CH) 128.
#define 	AT91C_HDMA_SCSIZE_256                  (0x7 << 16) // (HDMA_CH) 256.
#define AT91C_HDMA_DCSIZE     (0x7 << 20) // (HDMA_CH) Destination Chunk Transfer Size
#define 	AT91C_HDMA_DCSIZE_1                    (0x0 << 20) // (HDMA_CH) 1.
#define 	AT91C_HDMA_DCSIZE_4                    (0x1 << 20) // (HDMA_CH) 4.
#define 	AT91C_HDMA_DCSIZE_8                    (0x2 << 20) // (HDMA_CH) 8.
#define 	AT91C_HDMA_DCSIZE_16                   (0x3 << 20) // (HDMA_CH) 16.
#define 	AT91C_HDMA_DCSIZE_32                   (0x4 << 20) // (HDMA_CH) 32.
#define 	AT91C_HDMA_DCSIZE_64                   (0x5 << 20) // (HDMA_CH) 64.
#define 	AT91C_HDMA_DCSIZE_128                  (0x6 << 20) // (HDMA_CH) 128.
#define 	AT91C_HDMA_DCSIZE_256                  (0x7 << 20) // (HDMA_CH) 256.
#define AT91C_HDMA_SRC_WIDTH  (0x3 << 24) // (HDMA_CH) Source Single Transfer Size
#define 	AT91C_HDMA_SRC_WIDTH_BYTE                 (0x0 << 24) // (HDMA_CH) BYTE.
#define 	AT91C_HDMA_SRC_WIDTH_HALFWORD             (0x1 << 24) // (HDMA_CH) HALF-WORD.
#define 	AT91C_HDMA_SRC_WIDTH_WORD                 (0x2 << 24) // (HDMA_CH) WORD.
#define AT91C_HDMA_DST_WIDTH  (0x3 << 28) // (HDMA_CH) Destination Single Transfer Size
#define 	AT91C_HDMA_DST_WIDTH_BYTE                 (0x0 << 28) // (HDMA_CH) BYTE.
#define 	AT91C_HDMA_DST_WIDTH_HALFWORD             (0x1 << 28) // (HDMA_CH) HALF-WORD.
#define 	AT91C_HDMA_DST_WIDTH_WORD                 (0x2 << 28) // (HDMA_CH) WORD.
#define AT91C_HDMA_DONE       (0x1 << 31) // (HDMA_CH) 
// -------- HDMA_CTRLB : (HDMA_CH Offset: 0x10)  -------- 
#define AT91C_HDMA_SIF        (0x3 <<  0) // (HDMA_CH) Source Interface Selection Field.
#define 	AT91C_HDMA_SIF_0                    (0x0) // (HDMA_CH) The Source Transfer is done via AHB-Lite Interface 0.
#define 	AT91C_HDMA_SIF_1                    (0x1) // (HDMA_CH) The Source Transfer is done via AHB-Lite Interface 1.
#define 	AT91C_HDMA_SIF_2                    (0x2) // (HDMA_CH) The Source Transfer is done via AHB-Lite Interface 2.
#define 	AT91C_HDMA_SIF_3                    (0x3) // (HDMA_CH) The Source Transfer is done via AHB-Lite Interface 3.
#define AT91C_HDMA_DIF        (0x3 <<  4) // (HDMA_CH) Destination Interface Selection Field.
#define 	AT91C_HDMA_DIF_0                    (0x0 <<  4) // (HDMA_CH) The Destination Transfer is done via AHB-Lite Interface 0.
#define 	AT91C_HDMA_DIF_1                    (0x1 <<  4) // (HDMA_CH) The Destination Transfer is done via AHB-Lite Interface 1.
#define 	AT91C_HDMA_DIF_2                    (0x2 <<  4) // (HDMA_CH) The Destination Transfer is done via AHB-Lite Interface 2.
#define 	AT91C_HDMA_DIF_3                    (0x3 <<  4) // (HDMA_CH) The Destination Transfer is done via AHB-Lite Interface 3.
#define AT91C_HDMA_SRC_PIP    (0x1 <<  8) // (HDMA_CH) Source Picture-in-Picture Mode
#define 	AT91C_HDMA_SRC_PIP_DISABLE              (0x0 <<  8) // (HDMA_CH) Source Picture-in-Picture mode is disabled.
#define 	AT91C_HDMA_SRC_PIP_ENABLE               (0x1 <<  8) // (HDMA_CH) Source Picture-in-Picture mode is enabled.
#define AT91C_HDMA_DST_PIP    (0x1 << 12) // (HDMA_CH) Destination Picture-in-Picture Mode
#define 	AT91C_HDMA_DST_PIP_DISABLE              (0x0 << 12) // (HDMA_CH) Destination Picture-in-Picture mode is disabled.
#define 	AT91C_HDMA_DST_PIP_ENABLE               (0x1 << 12) // (HDMA_CH) Destination Picture-in-Picture mode is enabled.
#define AT91C_HDMA_SRC_DSCR   (0x1 << 16) // (HDMA_CH) Source Buffer Descriptor Fetch operation
#define 	AT91C_HDMA_SRC_DSCR_FETCH_FROM_MEM       (0x0 << 16) // (HDMA_CH) Source address is updated when the descriptor is fetched from the memory.
#define 	AT91C_HDMA_SRC_DSCR_FETCH_DISABLE        (0x1 << 16) // (HDMA_CH) Buffer Descriptor Fetch operation is disabled for the Source.
#define AT91C_HDMA_DST_DSCR   (0x1 << 20) // (HDMA_CH) Destination Buffer Descriptor operation
#define 	AT91C_HDMA_DST_DSCR_FETCH_FROM_MEM       (0x0 << 20) // (HDMA_CH) Destination address is updated when the descriptor is fetched from the memory.
#define 	AT91C_HDMA_DST_DSCR_FETCH_DISABLE        (0x1 << 20) // (HDMA_CH) Buffer Descriptor Fetch operation is disabled for the destination.
#define AT91C_HDMA_FC         (0x7 << 21) // (HDMA_CH) This field defines which devices controls the size of the buffer transfer, also referred as to the Flow Controller.
#define 	AT91C_HDMA_FC_MEM2MEM              (0x0 << 21) // (HDMA_CH) Memory-to-Memory (DMA Controller).
#define 	AT91C_HDMA_FC_MEM2PER              (0x1 << 21) // (HDMA_CH) Memory-to-Peripheral (DMA Controller).
#define 	AT91C_HDMA_FC_PER2MEM              (0x2 << 21) // (HDMA_CH) Peripheral-to-Memory (DMA Controller).
#define 	AT91C_HDMA_FC_PER2PER              (0x3 << 21) // (HDMA_CH) Peripheral-to-Peripheral (DMA Controller).
#define 	AT91C_HDMA_FC_PER2MEM_PER          (0x4 << 21) // (HDMA_CH) Peripheral-to-Memory (Peripheral).
#define 	AT91C_HDMA_FC_MEM2PER_PER          (0x5 << 21) // (HDMA_CH) Memory-to-Peripheral (Peripheral).
#define 	AT91C_HDMA_FC_PER2PER_PER          (0x6 << 21) // (HDMA_CH) Peripheral-to-Peripheral (Source Peripheral).
#define AT91C_HDMA_SRC_ADDRESS_MODE (0x3 << 24) // (HDMA_CH) Type of addressing mode
#define 	AT91C_HDMA_SRC_ADDRESS_MODE_INCR                 (0x0 << 24) // (HDMA_CH) Incrementing Mode.
#define 	AT91C_HDMA_SRC_ADDRESS_MODE_DECR                 (0x1 << 24) // (HDMA_CH) Decrementing Mode.
#define 	AT91C_HDMA_SRC_ADDRESS_MODE_FIXED                (0x2 << 24) // (HDMA_CH) Fixed Mode.
#define AT91C_HDMA_DST_ADDRESS_MODE (0x3 << 28) // (HDMA_CH) Type of addressing mode
#define 	AT91C_HDMA_DST_ADDRESS_MODE_INCR                 (0x0 << 28) // (HDMA_CH) Incrementing Mode.
#define 	AT91C_HDMA_DST_ADDRESS_MODE_DECR                 (0x1 << 28) // (HDMA_CH) Decrementing Mode.
#define 	AT91C_HDMA_DST_ADDRESS_MODE_FIXED                (0x2 << 28) // (HDMA_CH) Fixed Mode.
#define AT91C_HDMA_AUTO       (0x1 << 31) // (HDMA_CH) Automatic multiple buffer transfer enable
#define 	AT91C_HDMA_AUTO_DISABLE              (0x0 << 31) // (HDMA_CH) Automatic multiple buffer transfer is disabled.
#define 	AT91C_HDMA_AUTO_ENABLE               (0x1 << 31) // (HDMA_CH) Automatic multiple buffer transfer is enabled. This enables replay mode or contiguous mode when several buffers are transferred.
// -------- HDMA_CFG : (HDMA_CH Offset: 0x14)  -------- 
#define AT91C_HDMA_SRC_PER    (0xF <<  0) // (HDMA_CH) Channel Source Request is associated with peripheral identifier coded SRC_PER handshaking interface.
#define 	AT91C_HDMA_SRC_PER_0                    (0x0) // (HDMA_CH) HW Handshaking Interface number 0.
#define 	AT91C_HDMA_SRC_PER_1                    (0x1) // (HDMA_CH) HW Handshaking Interface number 1.
#define 	AT91C_HDMA_SRC_PER_2                    (0x2) // (HDMA_CH) HW Handshaking Interface number 2.
#define 	AT91C_HDMA_SRC_PER_3                    (0x3) // (HDMA_CH) HW Handshaking Interface number 3.
#define 	AT91C_HDMA_SRC_PER_4                    (0x4) // (HDMA_CH) HW Handshaking Interface number 4.
#define 	AT91C_HDMA_SRC_PER_5                    (0x5) // (HDMA_CH) HW Handshaking Interface number 5.
#define 	AT91C_HDMA_SRC_PER_6                    (0x6) // (HDMA_CH) HW Handshaking Interface number 6.
#define 	AT91C_HDMA_SRC_PER_7                    (0x7) // (HDMA_CH) HW Handshaking Interface number 7.
#define 	AT91C_HDMA_SRC_PER_8                    (0x8) // (HDMA_CH) HW Handshaking Interface number 8.
#define 	AT91C_HDMA_SRC_PER_9                    (0x9) // (HDMA_CH) HW Handshaking Interface number 9.
#define 	AT91C_HDMA_SRC_PER_10                   (0xA) // (HDMA_CH) HW Handshaking Interface number 10.
#define 	AT91C_HDMA_SRC_PER_11                   (0xB) // (HDMA_CH) HW Handshaking Interface number 11.
#define 	AT91C_HDMA_SRC_PER_12                   (0xC) // (HDMA_CH) HW Handshaking Interface number 12.
#define 	AT91C_HDMA_SRC_PER_13                   (0xD) // (HDMA_CH) HW Handshaking Interface number 13.
#define 	AT91C_HDMA_SRC_PER_14                   (0xE) // (HDMA_CH) HW Handshaking Interface number 14.
#define 	AT91C_HDMA_SRC_PER_15                   (0xF) // (HDMA_CH) HW Handshaking Interface number 15.
#define AT91C_HDMA_DST_PER    (0xF <<  4) // (HDMA_CH) Channel Destination Request is associated with peripheral identifier coded DST_PER handshaking interface.
#define 	AT91C_HDMA_DST_PER_0                    (0x0 <<  4) // (HDMA_CH) HW Handshaking Interface number 0.
#define 	AT91C_HDMA_DST_PER_1                    (0x1 <<  4) // (HDMA_CH) HW Handshaking Interface number 1.
#define 	AT91C_HDMA_DST_PER_2                    (0x2 <<  4) // (HDMA_CH) HW Handshaking Interface number 2.
#define 	AT91C_HDMA_DST_PER_3                    (0x3 <<  4) // (HDMA_CH) HW Handshaking Interface number 3.
#define 	AT91C_HDMA_DST_PER_4                    (0x4 <<  4) // (HDMA_CH) HW Handshaking Interface number 4.
#define 	AT91C_HDMA_DST_PER_5                    (0x5 <<  4) // (HDMA_CH) HW Handshaking Interface number 5.
#define 	AT91C_HDMA_DST_PER_6                    (0x6 <<  4) // (HDMA_CH) HW Handshaking Interface number 6.
#define 	AT91C_HDMA_DST_PER_7                    (0x7 <<  4) // (HDMA_CH) HW Handshaking Interface number 7.
#define 	AT91C_HDMA_DST_PER_8                    (0x8 <<  4) // (HDMA_CH) HW Handshaking Interface number 8.
#define 	AT91C_HDMA_DST_PER_9                    (0x9 <<  4) // (HDMA_CH) HW Handshaking Interface number 9.
#define 	AT91C_HDMA_DST_PER_10                   (0xA <<  4) // (HDMA_CH) HW Handshaking Interface number 10.
#define 	AT91C_HDMA_DST_PER_11                   (0xB <<  4) // (HDMA_CH) HW Handshaking Interface number 11.
#define 	AT91C_HDMA_DST_PER_12                   (0xC <<  4) // (HDMA_CH) HW Handshaking Interface number 12.
#define 	AT91C_HDMA_DST_PER_13                   (0xD <<  4) // (HDMA_CH) HW Handshaking Interface number 13.
#define 	AT91C_HDMA_DST_PER_14                   (0xE <<  4) // (HDMA_CH) HW Handshaking Interface number 14.
#define 	AT91C_HDMA_DST_PER_15                   (0xF <<  4) // (HDMA_CH) HW Handshaking Interface number 15.
#define AT91C_HDMA_SRC_REP    (0x1 <<  8) // (HDMA_CH) Source Replay Mode
#define 	AT91C_HDMA_SRC_REP_CONTIGUOUS_ADDR      (0x0 <<  8) // (HDMA_CH) When automatic mode is activated, source address is contiguous between two buffers.
#define 	AT91C_HDMA_SRC_REP_RELOAD_ADDR          (0x1 <<  8) // (HDMA_CH) When automatic mode is activated, the source address and the control register are reloaded from previous transfer..
#define AT91C_HDMA_SRC_H2SEL  (0x1 <<  9) // (HDMA_CH) Source Handshaking Mode
#define 	AT91C_HDMA_SRC_H2SEL_SW                   (0x0 <<  9) // (HDMA_CH) Software handshaking interface is used to trigger a transfer request.
#define 	AT91C_HDMA_SRC_H2SEL_HW                   (0x1 <<  9) // (HDMA_CH) Hardware handshaking interface is used to trigger a transfer request.
#define AT91C_HDMA_DST_REP    (0x1 << 12) // (HDMA_CH) Destination Replay Mode
#define 	AT91C_HDMA_DST_REP_CONTIGUOUS_ADDR      (0x0 << 12) // (HDMA_CH) When automatic mode is activated, destination address is contiguous between two buffers.
#define 	AT91C_HDMA_DST_REP_RELOAD_ADDR          (0x1 << 12) // (HDMA_CH) When automatic mode is activated, the destination address and the control register are reloaded from previous transfer..
#define AT91C_HDMA_DST_H2SEL  (0x1 << 13) // (HDMA_CH) Destination Handshaking Mode
#define 	AT91C_HDMA_DST_H2SEL_SW                   (0x0 << 13) // (HDMA_CH) Software handshaking interface is used to trigger a transfer request.
#define 	AT91C_HDMA_DST_H2SEL_HW                   (0x1 << 13) // (HDMA_CH) Hardware handshaking interface is used to trigger a transfer request.
#define AT91C_HDMA_SOD        (0x1 << 16) // (HDMA_CH) STOP ON DONE
#define 	AT91C_HDMA_SOD_DISABLE              (0x0 << 16) // (HDMA_CH) STOP ON DONE disabled, the descriptor fetch operation ignores DONE Field of CTRLA register.
#define 	AT91C_HDMA_SOD_ENABLE               (0x1 << 16) // (HDMA_CH) STOP ON DONE activated, the DMAC module is automatically disabled if DONE FIELD is set to 1.
#define AT91C_HDMA_LOCK_IF    (0x1 << 20) // (HDMA_CH) Interface Lock
#define 	AT91C_HDMA_LOCK_IF_DISABLE              (0x0 << 20) // (HDMA_CH) Interface Lock capability is disabled.
#define 	AT91C_HDMA_LOCK_IF_ENABLE               (0x1 << 20) // (HDMA_CH) Interface Lock capability is enabled.
#define AT91C_HDMA_LOCK_B     (0x1 << 21) // (HDMA_CH) AHB Bus Lock
#define 	AT91C_HDMA_LOCK_B_DISABLE              (0x0 << 21) // (HDMA_CH) AHB Bus Locking capability is disabled.
#define 	AT91C_HDMA_LOCK_B_ENABLE               (0x1 << 21) // (HDMA_CH) AHB Bus Locking capability is enabled.
#define AT91C_HDMA_LOCK_IF_L  (0x1 << 22) // (HDMA_CH) Master Interface Arbiter Lock
#define 	AT91C_HDMA_LOCK_IF_L_CHUNK                (0x0 << 22) // (HDMA_CH) The Master Interface Arbiter is locked by the channel x for a chunk transfer.
#define 	AT91C_HDMA_LOCK_IF_L_BUFFER               (0x1 << 22) // (HDMA_CH) The Master Interface Arbiter is locked by the channel x for a buffer transfer.
#define AT91C_HDMA_AHB_PROT   (0x7 << 24) // (HDMA_CH) AHB Prot
#define AT91C_HDMA_FIFOCFG    (0x3 << 28) // (HDMA_CH) FIFO Request Configuration
#define 	AT91C_HDMA_FIFOCFG_LARGESTBURST         (0x0 << 28) // (HDMA_CH) The largest defined length AHB burst is performed on the destination AHB interface.
#define 	AT91C_HDMA_FIFOCFG_HALFFIFO             (0x1 << 28) // (HDMA_CH) When half fifo size is available/filled a source/destination request is serviced.
#define 	AT91C_HDMA_FIFOCFG_ENOUGHSPACE          (0x2 << 28) // (HDMA_CH) When there is enough space/data available to perfom a single AHB access then the request is serviced.
// -------- HDMA_SPIP : (HDMA_CH Offset: 0x18)  -------- 
#define AT91C_SPIP_HOLE       (0xFFFF <<  0) // (HDMA_CH) This field indicates the value to add to the address when the programmable boundary has been reached.
#define AT91C_SPIP_BOUNDARY   (0x3FF << 16) // (HDMA_CH) This field indicates the number of source transfers to perform before the automatic address increment operation.
// -------- HDMA_DPIP : (HDMA_CH Offset: 0x1c)  -------- 
#define AT91C_DPIP_HOLE       (0xFFFF <<  0) // (HDMA_CH) This field indicates the value to add to the address when the programmable boundary has been reached.
#define AT91C_DPIP_BOUNDARY   (0x3FF << 16) // (HDMA_CH) This field indicates the number of source transfers to perform before the automatic address increment operation.
// -------- HDMA_BDSCR : (HDMA_CH Offset: 0x20)  -------- 
// -------- HDMA_CADDR : (HDMA_CH Offset: 0x24)  -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR HDMA controller
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_HDMA {
	AT91_REG	 HDMA_GCFG; 	// HDMA Global Configuration Register
	AT91_REG	 HDMA_EN; 	// HDMA Controller Enable Register
	AT91_REG	 HDMA_SREQ; 	// HDMA Software Single Request Register
	AT91_REG	 HDMA_CREQ; 	// HDMA Software Chunk Transfer Request Register
	AT91_REG	 HDMA_LAST; 	// HDMA Software Last Transfer Flag Register
	AT91_REG	 HDMA_SYNC; 	// HDMA Request Synchronization Register
	AT91_REG	 HDMA_EBCIER; 	// HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Interrupt Enable register
	AT91_REG	 HDMA_EBCIDR; 	// HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Interrupt Disable register
	AT91_REG	 HDMA_EBCIMR; 	// HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Mask Register
	AT91_REG	 HDMA_EBCISR; 	// HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Status Register
	AT91_REG	 HDMA_CHER; 	// HDMA Channel Handler Enable Register
	AT91_REG	 HDMA_CHDR; 	// HDMA Channel Handler Disable Register
	AT91_REG	 HDMA_CHSR; 	// HDMA Channel Handler Status Register
	AT91_REG	 HDMA_RSVD0; 	// HDMA Reserved
	AT91_REG	 HDMA_RSVD1; 	// HDMA Reserved
	AT91S_HDMA_CH	 HDMA_CH[4]; 	// HDMA Channel structure
	AT91_REG	 Reserved0[68]; 	// 
	AT91_REG	 HDMA_ADDRSIZE; 	// HDMA ADDRSIZE REGISTER 
	AT91_REG	 HDMA_IPNAME1; 	// HDMA IPNAME1 REGISTER 
	AT91_REG	 HDMA_IPNAME2; 	// HDMA IPNAME2 REGISTER 
	AT91_REG	 HDMA_FEATURES; 	// HDMA FEATURES REGISTER 
	AT91_REG	 HDMA_VER; 	// HDMA VERSION REGISTER 
} AT91S_HDMA, *AT91PS_HDMA;
#else
#define HDMA_GCFG       (AT91_CAST(AT91_REG *) 	0x00000000) // (HDMA_GCFG) HDMA Global Configuration Register
#define HDMA_EN         (AT91_CAST(AT91_REG *) 	0x00000004) // (HDMA_EN) HDMA Controller Enable Register
#define HDMA_SREQ       (AT91_CAST(AT91_REG *) 	0x00000008) // (HDMA_SREQ) HDMA Software Single Request Register
#define HDMA_CREQ       (AT91_CAST(AT91_REG *) 	0x0000000C) // (HDMA_CREQ) HDMA Software Chunk Transfer Request Register
#define HDMA_LAST       (AT91_CAST(AT91_REG *) 	0x00000010) // (HDMA_LAST) HDMA Software Last Transfer Flag Register
#define HDMA_SYNC       (AT91_CAST(AT91_REG *) 	0x00000014) // (HDMA_SYNC) HDMA Request Synchronization Register
#define HDMA_EBCIER     (AT91_CAST(AT91_REG *) 	0x00000018) // (HDMA_EBCIER) HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Interrupt Enable register
#define HDMA_EBCIDR     (AT91_CAST(AT91_REG *) 	0x0000001C) // (HDMA_EBCIDR) HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Interrupt Disable register
#define HDMA_EBCIMR     (AT91_CAST(AT91_REG *) 	0x00000020) // (HDMA_EBCIMR) HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Mask Register
#define HDMA_EBCISR     (AT91_CAST(AT91_REG *) 	0x00000024) // (HDMA_EBCISR) HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Status Register
#define HDMA_CHER       (AT91_CAST(AT91_REG *) 	0x00000028) // (HDMA_CHER) HDMA Channel Handler Enable Register
#define HDMA_CHDR       (AT91_CAST(AT91_REG *) 	0x0000002C) // (HDMA_CHDR) HDMA Channel Handler Disable Register
#define HDMA_CHSR       (AT91_CAST(AT91_REG *) 	0x00000030) // (HDMA_CHSR) HDMA Channel Handler Status Register
#define HDMA_RSVD0      (AT91_CAST(AT91_REG *) 	0x00000034) // (HDMA_RSVD0) HDMA Reserved
#define HDMA_RSVD1      (AT91_CAST(AT91_REG *) 	0x00000038) // (HDMA_RSVD1) HDMA Reserved
#define HDMA_ADDRSIZE   (AT91_CAST(AT91_REG *) 	0x000001EC) // (HDMA_ADDRSIZE) HDMA ADDRSIZE REGISTER 
#define HDMA_IPNAME1    (AT91_CAST(AT91_REG *) 	0x000001F0) // (HDMA_IPNAME1) HDMA IPNAME1 REGISTER 
#define HDMA_IPNAME2    (AT91_CAST(AT91_REG *) 	0x000001F4) // (HDMA_IPNAME2) HDMA IPNAME2 REGISTER 
#define HDMA_FEATURES   (AT91_CAST(AT91_REG *) 	0x000001F8) // (HDMA_FEATURES) HDMA FEATURES REGISTER 
#define HDMA_VER        (AT91_CAST(AT91_REG *) 	0x000001FC) // (HDMA_VER) HDMA VERSION REGISTER 

#endif
// -------- HDMA_GCFG : (HDMA Offset: 0x0)  -------- 
#define AT91C_HDMA_IF0_BIGEND (0x1 <<  0) // (HDMA) AHB-Lite Interface 0 endian mode.
#define 	AT91C_HDMA_IF0_BIGEND_IS_LITTLE_ENDIAN     (0x0) // (HDMA) AHB-Lite Interface 0 is little endian.
#define 	AT91C_HDMA_IF0_BIGEND_IS_BIG_ENDIAN        (0x1) // (HDMA) AHB-Lite Interface 0 is big endian.
#define AT91C_HDMA_IF1_BIGEND (0x1 <<  1) // (HDMA) AHB-Lite Interface 1 endian mode.
#define 	AT91C_HDMA_IF1_BIGEND_IS_LITTLE_ENDIAN     (0x0 <<  1) // (HDMA) AHB-Lite Interface 1 is little endian.
#define 	AT91C_HDMA_IF1_BIGEND_IS_BIG_ENDIAN        (0x1 <<  1) // (HDMA) AHB-Lite Interface 1 is big endian.
#define AT91C_HDMA_IF2_BIGEND (0x1 <<  2) // (HDMA) AHB-Lite Interface 2 endian mode.
#define 	AT91C_HDMA_IF2_BIGEND_IS_LITTLE_ENDIAN     (0x0 <<  2) // (HDMA) AHB-Lite Interface 2 is little endian.
#define 	AT91C_HDMA_IF2_BIGEND_IS_BIG_ENDIAN        (0x1 <<  2) // (HDMA) AHB-Lite Interface 2 is big endian.
#define AT91C_HDMA_IF3_BIGEND (0x1 <<  3) // (HDMA) AHB-Lite Interface 3 endian mode.
#define 	AT91C_HDMA_IF3_BIGEND_IS_LITTLE_ENDIAN     (0x0 <<  3) // (HDMA) AHB-Lite Interface 3 is little endian.
#define 	AT91C_HDMA_IF3_BIGEND_IS_BIG_ENDIAN        (0x1 <<  3) // (HDMA) AHB-Lite Interface 3 is big endian.
#define AT91C_HDMA_ARB_CFG    (0x1 <<  4) // (HDMA) Arbiter mode.
#define 	AT91C_HDMA_ARB_CFG_FIXED                (0x0 <<  4) // (HDMA) Fixed priority arbiter.
#define 	AT91C_HDMA_ARB_CFG_ROUND_ROBIN          (0x1 <<  4) // (HDMA) Modified round robin arbiter.
// -------- HDMA_EN : (HDMA Offset: 0x4)  -------- 
#define AT91C_HDMA_ENABLE     (0x1 <<  0) // (HDMA) 
#define 	AT91C_HDMA_ENABLE_DISABLE              (0x0) // (HDMA) Disables HDMA.
#define 	AT91C_HDMA_ENABLE_ENABLE               (0x1) // (HDMA) Enables HDMA.
// -------- HDMA_SREQ : (HDMA Offset: 0x8)  -------- 
#define AT91C_HDMA_SSREQ0     (0x1 <<  0) // (HDMA) Request a source single transfer on channel 0
#define 	AT91C_HDMA_SSREQ0_0                    (0x0) // (HDMA) No effect.
#define 	AT91C_HDMA_SSREQ0_1                    (0x1) // (HDMA) Request a source single transfer on channel 0.
#define AT91C_HDMA_DSREQ0     (0x1 <<  1) // (HDMA) Request a destination single transfer on channel 0
#define 	AT91C_HDMA_DSREQ0_0                    (0x0 <<  1) // (HDMA) No effect.
#define 	AT91C_HDMA_DSREQ0_1                    (0x1 <<  1) // (HDMA) Request a destination single transfer on channel 0.
#define AT91C_HDMA_SSREQ1     (0x1 <<  2) // (HDMA) Request a source single transfer on channel 1
#define 	AT91C_HDMA_SSREQ1_0                    (0x0 <<  2) // (HDMA) No effect.
#define 	AT91C_HDMA_SSREQ1_1                    (0x1 <<  2) // (HDMA) Request a source single transfer on channel 1.
#define AT91C_HDMA_DSREQ1     (0x1 <<  3) // (HDMA) Request a destination single transfer on channel 1
#define 	AT91C_HDMA_DSREQ1_0                    (0x0 <<  3) // (HDMA) No effect.
#define 	AT91C_HDMA_DSREQ1_1                    (0x1 <<  3) // (HDMA) Request a destination single transfer on channel 1.
#define AT91C_HDMA_SSREQ2     (0x1 <<  4) // (HDMA) Request a source single transfer on channel 2
#define 	AT91C_HDMA_SSREQ2_0                    (0x0 <<  4) // (HDMA) No effect.
#define 	AT91C_HDMA_SSREQ2_1                    (0x1 <<  4) // (HDMA) Request a source single transfer on channel 2.
#define AT91C_HDMA_DSREQ2     (0x1 <<  5) // (HDMA) Request a destination single transfer on channel 2
#define 	AT91C_HDMA_DSREQ2_0                    (0x0 <<  5) // (HDMA) No effect.
#define 	AT91C_HDMA_DSREQ2_1                    (0x1 <<  5) // (HDMA) Request a destination single transfer on channel 2.
#define AT91C_HDMA_SSREQ3     (0x1 <<  6) // (HDMA) Request a source single transfer on channel 3
#define 	AT91C_HDMA_SSREQ3_0                    (0x0 <<  6) // (HDMA) No effect.
#define 	AT91C_HDMA_SSREQ3_1                    (0x1 <<  6) // (HDMA) Request a source single transfer on channel 3.
#define AT91C_HDMA_DSREQ3     (0x1 <<  7) // (HDMA) Request a destination single transfer on channel 3
#define 	AT91C_HDMA_DSREQ3_0                    (0x0 <<  7) // (HDMA) No effect.
#define 	AT91C_HDMA_DSREQ3_1                    (0x1 <<  7) // (HDMA) Request a destination single transfer on channel 3.
#define AT91C_HDMA_SSREQ4     (0x1 <<  8) // (HDMA) Request a source single transfer on channel 4
#define 	AT91C_HDMA_SSREQ4_0                    (0x0 <<  8) // (HDMA) No effect.
#define 	AT91C_HDMA_SSREQ4_1                    (0x1 <<  8) // (HDMA) Request a source single transfer on channel 4.
#define AT91C_HDMA_DSREQ4     (0x1 <<  9) // (HDMA) Request a destination single transfer on channel 4
#define 	AT91C_HDMA_DSREQ4_0                    (0x0 <<  9) // (HDMA) No effect.
#define 	AT91C_HDMA_DSREQ4_1                    (0x1 <<  9) // (HDMA) Request a destination single transfer on channel 4.
#define AT91C_HDMA_SSREQ5     (0x1 << 10) // (HDMA) Request a source single transfer on channel 5
#define 	AT91C_HDMA_SSREQ5_0                    (0x0 << 10) // (HDMA) No effect.
#define 	AT91C_HDMA_SSREQ5_1                    (0x1 << 10) // (HDMA) Request a source single transfer on channel 5.
#define AT91C_HDMA_DSREQ6     (0x1 << 11) // (HDMA) Request a destination single transfer on channel 5
#define 	AT91C_HDMA_DSREQ6_0                    (0x0 << 11) // (HDMA) No effect.
#define 	AT91C_HDMA_DSREQ6_1                    (0x1 << 11) // (HDMA) Request a destination single transfer on channel 5.
#define AT91C_HDMA_SSREQ6     (0x1 << 12) // (HDMA) Request a source single transfer on channel 6
#define 	AT91C_HDMA_SSREQ6_0                    (0x0 << 12) // (HDMA) No effect.
#define 	AT91C_HDMA_SSREQ6_1                    (0x1 << 12) // (HDMA) Request a source single transfer on channel 6.
#define AT91C_HDMA_SSREQ7     (0x1 << 14) // (HDMA) Request a source single transfer on channel 7
#define 	AT91C_HDMA_SSREQ7_0                    (0x0 << 14) // (HDMA) No effect.
#define 	AT91C_HDMA_SSREQ7_1                    (0x1 << 14) // (HDMA) Request a source single transfer on channel 7.
#define AT91C_HDMA_DSREQ7     (0x1 << 15) // (HDMA) Request a destination single transfer on channel 7
#define 	AT91C_HDMA_DSREQ7_0                    (0x0 << 15) // (HDMA) No effect.
#define 	AT91C_HDMA_DSREQ7_1                    (0x1 << 15) // (HDMA) Request a destination single transfer on channel 7.
// -------- HDMA_CREQ : (HDMA Offset: 0xc)  -------- 
#define AT91C_HDMA_SCREQ0     (0x1 <<  0) // (HDMA) Request a source chunk transfer on channel 0
#define 	AT91C_HDMA_SCREQ0_0                    (0x0) // (HDMA) No effect.
#define 	AT91C_HDMA_SCREQ0_1                    (0x1) // (HDMA) Request a source chunk transfer on channel 0.
#define AT91C_HDMA_DCREQ0     (0x1 <<  1) // (HDMA) Request a destination chunk transfer on channel 0
#define 	AT91C_HDMA_DCREQ0_0                    (0x0 <<  1) // (HDMA) No effect.
#define 	AT91C_HDMA_DCREQ0_1                    (0x1 <<  1) // (HDMA) Request a destination chunk transfer on channel 0.
#define AT91C_HDMA_SCREQ1     (0x1 <<  2) // (HDMA) Request a source chunk transfer on channel 1
#define 	AT91C_HDMA_SCREQ1_0                    (0x0 <<  2) // (HDMA) No effect.
#define 	AT91C_HDMA_SCREQ1_1                    (0x1 <<  2) // (HDMA) Request a source chunk transfer on channel 1.
#define AT91C_HDMA_DCREQ1     (0x1 <<  3) // (HDMA) Request a destination chunk transfer on channel 1
#define 	AT91C_HDMA_DCREQ1_0                    (0x0 <<  3) // (HDMA) No effect.
#define 	AT91C_HDMA_DCREQ1_1                    (0x1 <<  3) // (HDMA) Request a destination chunk transfer on channel 1.
#define AT91C_HDMA_SCREQ2     (0x1 <<  4) // (HDMA) Request a source chunk transfer on channel 2
#define 	AT91C_HDMA_SCREQ2_0                    (0x0 <<  4) // (HDMA) No effect.
#define 	AT91C_HDMA_SCREQ2_1                    (0x1 <<  4) // (HDMA) Request a source chunk transfer on channel 2.
#define AT91C_HDMA_DCREQ2     (0x1 <<  5) // (HDMA) Request a destination chunk transfer on channel 2
#define 	AT91C_HDMA_DCREQ2_0                    (0x0 <<  5) // (HDMA) No effect.
#define 	AT91C_HDMA_DCREQ2_1                    (0x1 <<  5) // (HDMA) Request a destination chunk transfer on channel 2.
#define AT91C_HDMA_SCREQ3     (0x1 <<  6) // (HDMA) Request a source chunk transfer on channel 3
#define 	AT91C_HDMA_SCREQ3_0                    (0x0 <<  6) // (HDMA) No effect.
#define 	AT91C_HDMA_SCREQ3_1                    (0x1 <<  6) // (HDMA) Request a source chunk transfer on channel 3.
#define AT91C_HDMA_DCREQ3     (0x1 <<  7) // (HDMA) Request a destination chunk transfer on channel 3
#define 	AT91C_HDMA_DCREQ3_0                    (0x0 <<  7) // (HDMA) No effect.
#define 	AT91C_HDMA_DCREQ3_1                    (0x1 <<  7) // (HDMA) Request a destination chunk transfer on channel 3.
#define AT91C_HDMA_SCREQ4     (0x1 <<  8) // (HDMA) Request a source chunk transfer on channel 4
#define 	AT91C_HDMA_SCREQ4_0                    (0x0 <<  8) // (HDMA) No effect.
#define 	AT91C_HDMA_SCREQ4_1                    (0x1 <<  8) // (HDMA) Request a source chunk transfer on channel 4.
#define AT91C_HDMA_DCREQ4     (0x1 <<  9) // (HDMA) Request a destination chunk transfer on channel 4
#define 	AT91C_HDMA_DCREQ4_0                    (0x0 <<  9) // (HDMA) No effect.
#define 	AT91C_HDMA_DCREQ4_1                    (0x1 <<  9) // (HDMA) Request a destination chunk transfer on channel 4.
#define AT91C_HDMA_SCREQ5     (0x1 << 10) // (HDMA) Request a source chunk transfer on channel 5
#define 	AT91C_HDMA_SCREQ5_0                    (0x0 << 10) // (HDMA) No effect.
#define 	AT91C_HDMA_SCREQ5_1                    (0x1 << 10) // (HDMA) Request a source chunk transfer on channel 5.
#define AT91C_HDMA_DCREQ6     (0x1 << 11) // (HDMA) Request a destination chunk transfer on channel 5
#define 	AT91C_HDMA_DCREQ6_0                    (0x0 << 11) // (HDMA) No effect.
#define 	AT91C_HDMA_DCREQ6_1                    (0x1 << 11) // (HDMA) Request a destination chunk transfer on channel 5.
#define AT91C_HDMA_SCREQ6     (0x1 << 12) // (HDMA) Request a source chunk transfer on channel 6
#define 	AT91C_HDMA_SCREQ6_0                    (0x0 << 12) // (HDMA) No effect.
#define 	AT91C_HDMA_SCREQ6_1                    (0x1 << 12) // (HDMA) Request a source chunk transfer on channel 6.
#define AT91C_HDMA_SCREQ7     (0x1 << 14) // (HDMA) Request a source chunk transfer on channel 7
#define 	AT91C_HDMA_SCREQ7_0                    (0x0 << 14) // (HDMA) No effect.
#define 	AT91C_HDMA_SCREQ7_1                    (0x1 << 14) // (HDMA) Request a source chunk transfer on channel 7.
#define AT91C_HDMA_DCREQ7     (0x1 << 15) // (HDMA) Request a destination chunk transfer on channel 7
#define 	AT91C_HDMA_DCREQ7_0                    (0x0 << 15) // (HDMA) No effect.
#define 	AT91C_HDMA_DCREQ7_1                    (0x1 << 15) // (HDMA) Request a destination chunk transfer on channel 7.
// -------- HDMA_LAST : (HDMA Offset: 0x10)  -------- 
#define AT91C_HDMA_SLAST0     (0x1 <<  0) // (HDMA) Indicates that this source request is the last transfer of the buffer on channel 0
#define 	AT91C_HDMA_SLAST0_0                    (0x0) // (HDMA) No effect.
#define 	AT91C_HDMA_SLAST0_1                    (0x1) // (HDMA) Writing one to SLASTx prior to writing one to SSREQx or SCREQx indicates that this source request is the last transfer of the buffer on channel 0.
#define AT91C_HDMA_DLAST0     (0x1 <<  1) // (HDMA) Indicates that this destination request is the last transfer of the buffer on channel 0
#define 	AT91C_HDMA_DLAST0_0                    (0x0 <<  1) // (HDMA) No effect.
#define 	AT91C_HDMA_DLAST0_1                    (0x1 <<  1) // (HDMA) Writing one to DLASTx prior to writing one to DSREQx or DCREQx indicates that this destination request is the last transfer of the buffer on channel 0.
#define AT91C_HDMA_SLAST1     (0x1 <<  2) // (HDMA) Indicates that this source request is the last transfer of the buffer on channel 1
#define 	AT91C_HDMA_SLAST1_0                    (0x0 <<  2) // (HDMA) No effect.
#define 	AT91C_HDMA_SLAST1_1                    (0x1 <<  2) // (HDMA) Writing one to SLASTx prior to writing one to SSREQx or SCREQx indicates that this source request is the last transfer of the buffer on channel 1.
#define AT91C_HDMA_DLAST1     (0x1 <<  3) // (HDMA) Indicates that this destination request is the last transfer of the buffer on channel 1
#define 	AT91C_HDMA_DLAST1_0                    (0x0 <<  3) // (HDMA) No effect.
#define 	AT91C_HDMA_DLAST1_1                    (0x1 <<  3) // (HDMA) Writing one to DLASTx prior to writing one to DSREQx or DCREQx indicates that this destination request is the last transfer of the buffer on channel 1.
#define AT91C_HDMA_SLAST2     (0x1 <<  4) // (HDMA) Indicates that this source request is the last transfer of the buffer on channel 2
#define 	AT91C_HDMA_SLAST2_0                    (0x0 <<  4) // (HDMA) No effect.
#define 	AT91C_HDMA_SLAST2_1                    (0x1 <<  4) // (HDMA) Writing one to SLASTx prior to writing one to SSREQx or SCREQx indicates that this source request is the last transfer of the buffer on channel 2.
#define AT91C_HDMA_DLAST2     (0x1 <<  5) // (HDMA) Indicates that this destination request is the last transfer of the buffer on channel 2
#define 	AT91C_HDMA_DLAST2_0                    (0x0 <<  5) // (HDMA) No effect.
#define 	AT91C_HDMA_DLAST2_1                    (0x1 <<  5) // (HDMA) Writing one to DLASTx prior to writing one to DSREQx or DCREQx indicates that this destination request is the last transfer of the buffer on channel 2.
#define AT91C_HDMA_SLAST3     (0x1 <<  6) // (HDMA) Indicates that this source request is the last transfer of the buffer on channel 3
#define 	AT91C_HDMA_SLAST3_0                    (0x0 <<  6) // (HDMA) No effect.
#define 	AT91C_HDMA_SLAST3_1                    (0x1 <<  6) // (HDMA) Writing one to SLASTx prior to writing one to SSREQx or SCREQx indicates that this source request is the last transfer of the buffer on channel 3.
#define AT91C_HDMA_DLAST3     (0x1 <<  7) // (HDMA) Indicates that this destination request is the last transfer of the buffer on channel 3
#define 	AT91C_HDMA_DLAST3_0                    (0x0 <<  7) // (HDMA) No effect.
#define 	AT91C_HDMA_DLAST3_1                    (0x1 <<  7) // (HDMA) Writing one to DLASTx prior to writing one to DSREQx or DCREQx indicates that this destination request is the last transfer of the buffer on channel 3.
#define AT91C_HDMA_SLAST4     (0x1 <<  8) // (HDMA) Indicates that this source request is the last transfer of the buffer on channel 4
#define 	AT91C_HDMA_SLAST4_0                    (0x0 <<  8) // (HDMA) No effect.
#define 	AT91C_HDMA_SLAST4_1                    (0x1 <<  8) // (HDMA) Writing one to SLASTx prior to writing one to SSREQx or SCREQx indicates that this source request is the last transfer of the buffer on channel 4.
#define AT91C_HDMA_DLAST4     (0x1 <<  9) // (HDMA) Indicates that this destination request is the last transfer of the buffer on channel 4
#define 	AT91C_HDMA_DLAST4_0                    (0x0 <<  9) // (HDMA) No effect.
#define 	AT91C_HDMA_DLAST4_1                    (0x1 <<  9) // (HDMA) Writing one to DLASTx prior to writing one to DSREQx or DCREQx indicates that this destination request is the last transfer of the buffer on channel 4.
#define AT91C_HDMA_SLAST5     (0x1 << 10) // (HDMA) Indicates that this source request is the last transfer of the buffer on channel 5
#define 	AT91C_HDMA_SLAST5_0                    (0x0 << 10) // (HDMA) No effect.
#define 	AT91C_HDMA_SLAST5_1                    (0x1 << 10) // (HDMA) Writing one to SLASTx prior to writing one to SSREQx or SCREQx indicates that this source request is the last transfer of the buffer on channel 5.
#define AT91C_HDMA_DLAST6     (0x1 << 11) // (HDMA) Indicates that this destination request is the last transfer of the buffer on channel 5
#define 	AT91C_HDMA_DLAST6_0                    (0x0 << 11) // (HDMA) No effect.
#define 	AT91C_HDMA_DLAST6_1                    (0x1 << 11) // (HDMA) Writing one to DLASTx prior to writing one to DSREQx or DCREQx indicates that this destination request is the last transfer of the buffer on channel 5.
#define AT91C_HDMA_SLAST6     (0x1 << 12) // (HDMA) Indicates that this source request is the last transfer of the buffer on channel 6
#define 	AT91C_HDMA_SLAST6_0                    (0x0 << 12) // (HDMA) No effect.
#define 	AT91C_HDMA_SLAST6_1                    (0x1 << 12) // (HDMA) Writing one to SLASTx prior to writing one to SSREQx or SCREQx indicates that this source request is the last transfer of the buffer on channel 6.
#define AT91C_HDMA_SLAST7     (0x1 << 14) // (HDMA) Indicates that this source request is the last transfer of the buffer on channel 7
#define 	AT91C_HDMA_SLAST7_0                    (0x0 << 14) // (HDMA) No effect.
#define 	AT91C_HDMA_SLAST7_1                    (0x1 << 14) // (HDMA) Writing one to SLASTx prior to writing one to SSREQx or SCREQx indicates that this source request is the last transfer of the buffer on channel 7.
#define AT91C_HDMA_DLAST7     (0x1 << 15) // (HDMA) Indicates that this destination request is the last transfer of the buffer on channel 7
#define 	AT91C_HDMA_DLAST7_0                    (0x0 << 15) // (HDMA) No effect.
#define 	AT91C_HDMA_DLAST7_1                    (0x1 << 15) // (HDMA) Writing one to DLASTx prior to writing one to DSREQx or DCREQx indicates that this destination request is the last transfer of the buffer on channel 7.
// -------- HDMA_SYNC : (HDMA Offset: 0x14)  -------- 
#define AT91C_SYNC_REQ        (0xFFFF <<  0) // (HDMA) 
// -------- HDMA_EBCIER : (HDMA Offset: 0x18) Buffer Transfer Completed/Chained Buffer Transfer Completed/Access Error Interrupt Enable Register -------- 
#define AT91C_HDMA_BTC0       (0x1 <<  0) // (HDMA) Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_BTC1       (0x1 <<  1) // (HDMA) Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_BTC2       (0x1 <<  2) // (HDMA) Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_BTC3       (0x1 <<  3) // (HDMA) Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_BTC4       (0x1 <<  4) // (HDMA) Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_BTC5       (0x1 <<  5) // (HDMA) Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_BTC6       (0x1 <<  6) // (HDMA) Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_BTC7       (0x1 <<  7) // (HDMA) Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_CBTC0      (0x1 <<  8) // (HDMA) Chained Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_CBTC1      (0x1 <<  9) // (HDMA) Chained Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_CBTC2      (0x1 << 10) // (HDMA) Chained Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_CBTC3      (0x1 << 11) // (HDMA) Chained Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_CBTC4      (0x1 << 12) // (HDMA) Chained Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_CBTC5      (0x1 << 13) // (HDMA) Chained Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_CBTC6      (0x1 << 14) // (HDMA) Chained Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_CBTC7      (0x1 << 15) // (HDMA) Chained Buffer Transfer Completed Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_ERR0       (0x1 << 16) // (HDMA) Access HDMA_Error Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_ERR1       (0x1 << 17) // (HDMA) Access HDMA_Error Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_ERR2       (0x1 << 18) // (HDMA) Access HDMA_Error Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_ERR3       (0x1 << 19) // (HDMA) Access HDMA_Error Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_ERR4       (0x1 << 20) // (HDMA) Access HDMA_Error Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_ERR5       (0x1 << 21) // (HDMA) Access HDMA_Error Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_ERR6       (0x1 << 22) // (HDMA) Access HDMA_Error Interrupt Enable/Disable/Status Register
#define AT91C_HDMA_ERR7       (0x1 << 23) // (HDMA) Access HDMA_Error Interrupt Enable/Disable/Status Register
// -------- HDMA_EBCIDR : (HDMA Offset: 0x1c)  -------- 
// -------- HDMA_EBCIMR : (HDMA Offset: 0x20)  -------- 
// -------- HDMA_EBCISR : (HDMA Offset: 0x24)  -------- 
// -------- HDMA_CHER : (HDMA Offset: 0x28)  -------- 
#define AT91C_HDMA_ENA0       (0x1 <<  0) // (HDMA) When set, channel 0 enabled.
#define 	AT91C_HDMA_ENA0_0                    (0x0) // (HDMA) No effect.
#define 	AT91C_HDMA_ENA0_1                    (0x1) // (HDMA) Channel 0 enabled.
#define AT91C_HDMA_ENA1       (0x1 <<  1) // (HDMA) When set, channel 1 enabled.
#define 	AT91C_HDMA_ENA1_0                    (0x0 <<  1) // (HDMA) No effect.
#define 	AT91C_HDMA_ENA1_1                    (0x1 <<  1) // (HDMA) Channel 1 enabled.
#define AT91C_HDMA_ENA2       (0x1 <<  2) // (HDMA) When set, channel 2 enabled.
#define 	AT91C_HDMA_ENA2_0                    (0x0 <<  2) // (HDMA) No effect.
#define 	AT91C_HDMA_ENA2_1                    (0x1 <<  2) // (HDMA) Channel 2 enabled.
#define AT91C_HDMA_ENA3       (0x1 <<  3) // (HDMA) When set, channel 3 enabled.
#define 	AT91C_HDMA_ENA3_0                    (0x0 <<  3) // (HDMA) No effect.
#define 	AT91C_HDMA_ENA3_1                    (0x1 <<  3) // (HDMA) Channel 3 enabled.
#define AT91C_HDMA_ENA4       (0x1 <<  4) // (HDMA) When set, channel 4 enabled.
#define 	AT91C_HDMA_ENA4_0                    (0x0 <<  4) // (HDMA) No effect.
#define 	AT91C_HDMA_ENA4_1                    (0x1 <<  4) // (HDMA) Channel 4 enabled.
#define AT91C_HDMA_ENA5       (0x1 <<  5) // (HDMA) When set, channel 5 enabled.
#define 	AT91C_HDMA_ENA5_0                    (0x0 <<  5) // (HDMA) No effect.
#define 	AT91C_HDMA_ENA5_1                    (0x1 <<  5) // (HDMA) Channel 5 enabled.
#define AT91C_HDMA_ENA6       (0x1 <<  6) // (HDMA) When set, channel 6 enabled.
#define 	AT91C_HDMA_ENA6_0                    (0x0 <<  6) // (HDMA) No effect.
#define 	AT91C_HDMA_ENA6_1                    (0x1 <<  6) // (HDMA) Channel 6 enabled.
#define AT91C_HDMA_ENA7       (0x1 <<  7) // (HDMA) When set, channel 7 enabled.
#define 	AT91C_HDMA_ENA7_0                    (0x0 <<  7) // (HDMA) No effect.
#define 	AT91C_HDMA_ENA7_1                    (0x1 <<  7) // (HDMA) Channel 7 enabled.
#define AT91C_HDMA_SUSP0      (0x1 <<  8) // (HDMA) When set, channel 0 freezed and its current context.
#define 	AT91C_HDMA_SUSP0_0                    (0x0 <<  8) // (HDMA) No effect.
#define 	AT91C_HDMA_SUSP0_1                    (0x1 <<  8) // (HDMA) Channel 0 freezed.
#define AT91C_HDMA_SUSP1      (0x1 <<  9) // (HDMA) When set, channel 1 freezed and its current context.
#define 	AT91C_HDMA_SUSP1_0                    (0x0 <<  9) // (HDMA) No effect.
#define 	AT91C_HDMA_SUSP1_1                    (0x1 <<  9) // (HDMA) Channel 1 freezed.
#define AT91C_HDMA_SUSP2      (0x1 << 10) // (HDMA) When set, channel 2 freezed and its current context.
#define 	AT91C_HDMA_SUSP2_0                    (0x0 << 10) // (HDMA) No effect.
#define 	AT91C_HDMA_SUSP2_1                    (0x1 << 10) // (HDMA) Channel 2 freezed.
#define AT91C_HDMA_SUSP3      (0x1 << 11) // (HDMA) When set, channel 3 freezed and its current context.
#define 	AT91C_HDMA_SUSP3_0                    (0x0 << 11) // (HDMA) No effect.
#define 	AT91C_HDMA_SUSP3_1                    (0x1 << 11) // (HDMA) Channel 3 freezed.
#define AT91C_HDMA_SUSP4      (0x1 << 12) // (HDMA) When set, channel 4 freezed and its current context.
#define 	AT91C_HDMA_SUSP4_0                    (0x0 << 12) // (HDMA) No effect.
#define 	AT91C_HDMA_SUSP4_1                    (0x1 << 12) // (HDMA) Channel 4 freezed.
#define AT91C_HDMA_SUSP5      (0x1 << 13) // (HDMA) When set, channel 5 freezed and its current context.
#define 	AT91C_HDMA_SUSP5_0                    (0x0 << 13) // (HDMA) No effect.
#define 	AT91C_HDMA_SUSP5_1                    (0x1 << 13) // (HDMA) Channel 5 freezed.
#define AT91C_HDMA_SUSP6      (0x1 << 14) // (HDMA) When set, channel 6 freezed and its current context.
#define 	AT91C_HDMA_SUSP6_0                    (0x0 << 14) // (HDMA) No effect.
#define 	AT91C_HDMA_SUSP6_1                    (0x1 << 14) // (HDMA) Channel 6 freezed.
#define AT91C_HDMA_SUSP7      (0x1 << 15) // (HDMA) When set, channel 7 freezed and its current context.
#define 	AT91C_HDMA_SUSP7_0                    (0x0 << 15) // (HDMA) No effect.
#define 	AT91C_HDMA_SUSP7_1                    (0x1 << 15) // (HDMA) Channel 7 freezed.
#define AT91C_HDMA_KEEP0      (0x1 << 24) // (HDMA) When set, it resumes the channel 0 from an automatic stall state.
#define 	AT91C_HDMA_KEEP0_0                    (0x0 << 24) // (HDMA) No effect.
#define 	AT91C_HDMA_KEEP0_1                    (0x1 << 24) // (HDMA) Resumes the channel 0.
#define AT91C_HDMA_KEEP1      (0x1 << 25) // (HDMA) When set, it resumes the channel 1 from an automatic stall state.
#define 	AT91C_HDMA_KEEP1_0                    (0x0 << 25) // (HDMA) No effect.
#define 	AT91C_HDMA_KEEP1_1                    (0x1 << 25) // (HDMA) Resumes the channel 1.
#define AT91C_HDMA_KEEP2      (0x1 << 26) // (HDMA) When set, it resumes the channel 2 from an automatic stall state.
#define 	AT91C_HDMA_KEEP2_0                    (0x0 << 26) // (HDMA) No effect.
#define 	AT91C_HDMA_KEEP2_1                    (0x1 << 26) // (HDMA) Resumes the channel 2.
#define AT91C_HDMA_KEEP3      (0x1 << 27) // (HDMA) When set, it resumes the channel 3 from an automatic stall state.
#define 	AT91C_HDMA_KEEP3_0                    (0x0 << 27) // (HDMA) No effect.
#define 	AT91C_HDMA_KEEP3_1                    (0x1 << 27) // (HDMA) Resumes the channel 3.
#define AT91C_HDMA_KEEP4      (0x1 << 28) // (HDMA) When set, it resumes the channel 4 from an automatic stall state.
#define 	AT91C_HDMA_KEEP4_0                    (0x0 << 28) // (HDMA) No effect.
#define 	AT91C_HDMA_KEEP4_1                    (0x1 << 28) // (HDMA) Resumes the channel 4.
#define AT91C_HDMA_KEEP5      (0x1 << 29) // (HDMA) When set, it resumes the channel 5 from an automatic stall state.
#define 	AT91C_HDMA_KEEP5_0                    (0x0 << 29) // (HDMA) No effect.
#define 	AT91C_HDMA_KEEP5_1                    (0x1 << 29) // (HDMA) Resumes the channel 5.
#define AT91C_HDMA_KEEP6      (0x1 << 30) // (HDMA) When set, it resumes the channel 6 from an automatic stall state.
#define 	AT91C_HDMA_KEEP6_0                    (0x0 << 30) // (HDMA) No effect.
#define 	AT91C_HDMA_KEEP6_1                    (0x1 << 30) // (HDMA) Resumes the channel 6.
#define AT91C_HDMA_KEEP7      (0x1 << 31) // (HDMA) When set, it resumes the channel 7 from an automatic stall state.
#define 	AT91C_HDMA_KEEP7_0                    (0x0 << 31) // (HDMA) No effect.
#define 	AT91C_HDMA_KEEP7_1                    (0x1 << 31) // (HDMA) Resumes the channel 7.
// -------- HDMA_CHDR : (HDMA Offset: 0x2c)  -------- 
#define AT91C_HDMA_DIS0       (0x1 <<  0) // (HDMA) Write one to this field to disable the channel 0.
#define 	AT91C_HDMA_DIS0_0                    (0x0) // (HDMA) No effect.
#define 	AT91C_HDMA_DIS0_1                    (0x1) // (HDMA) Disables the channel 0.
#define AT91C_HDMA_DIS1       (0x1 <<  1) // (HDMA) Write one to this field to disable the channel 1.
#define 	AT91C_HDMA_DIS1_0                    (0x0 <<  1) // (HDMA) No effect.
#define 	AT91C_HDMA_DIS1_1                    (0x1 <<  1) // (HDMA) Disables the channel 1.
#define AT91C_HDMA_DIS2       (0x1 <<  2) // (HDMA) Write one to this field to disable the channel 2.
#define 	AT91C_HDMA_DIS2_0                    (0x0 <<  2) // (HDMA) No effect.
#define 	AT91C_HDMA_DIS2_1                    (0x1 <<  2) // (HDMA) Disables the channel 2.
#define AT91C_HDMA_DIS3       (0x1 <<  3) // (HDMA) Write one to this field to disable the channel 3.
#define 	AT91C_HDMA_DIS3_0                    (0x0 <<  3) // (HDMA) No effect.
#define 	AT91C_HDMA_DIS3_1                    (0x1 <<  3) // (HDMA) Disables the channel 3.
#define AT91C_HDMA_DIS4       (0x1 <<  4) // (HDMA) Write one to this field to disable the channel 4.
#define 	AT91C_HDMA_DIS4_0                    (0x0 <<  4) // (HDMA) No effect.
#define 	AT91C_HDMA_DIS4_1                    (0x1 <<  4) // (HDMA) Disables the channel 4.
#define AT91C_HDMA_DIS5       (0x1 <<  5) // (HDMA) Write one to this field to disable the channel 5.
#define 	AT91C_HDMA_DIS5_0                    (0x0 <<  5) // (HDMA) No effect.
#define 	AT91C_HDMA_DIS5_1                    (0x1 <<  5) // (HDMA) Disables the channel 5.
#define AT91C_HDMA_DIS6       (0x1 <<  6) // (HDMA) Write one to this field to disable the channel 6.
#define 	AT91C_HDMA_DIS6_0                    (0x0 <<  6) // (HDMA) No effect.
#define 	AT91C_HDMA_DIS6_1                    (0x1 <<  6) // (HDMA) Disables the channel 6.
#define AT91C_HDMA_DIS7       (0x1 <<  7) // (HDMA) Write one to this field to disable the channel 7.
#define 	AT91C_HDMA_DIS7_0                    (0x0 <<  7) // (HDMA) No effect.
#define 	AT91C_HDMA_DIS7_1                    (0x1 <<  7) // (HDMA) Disables the channel 7.
#define AT91C_HDMA_RES0       (0x1 <<  8) // (HDMA) Write one to this field to resume the channel 0 transfer restoring its context.
#define 	AT91C_HDMA_RES0_0                    (0x0 <<  8) // (HDMA) No effect.
#define 	AT91C_HDMA_RES0_1                    (0x1 <<  8) // (HDMA) Resumes the channel 0.
#define AT91C_HDMA_RES1       (0x1 <<  9) // (HDMA) Write one to this field to resume the channel 1 transfer restoring its context.
#define 	AT91C_HDMA_RES1_0                    (0x0 <<  9) // (HDMA) No effect.
#define 	AT91C_HDMA_RES1_1                    (0x1 <<  9) // (HDMA) Resumes the channel 1.
#define AT91C_HDMA_RES2       (0x1 << 10) // (HDMA) Write one to this field to resume the channel 2 transfer restoring its context.
#define 	AT91C_HDMA_RES2_0                    (0x0 << 10) // (HDMA) No effect.
#define 	AT91C_HDMA_RES2_1                    (0x1 << 10) // (HDMA) Resumes the channel 2.
#define AT91C_HDMA_RES3       (0x1 << 11) // (HDMA) Write one to this field to resume the channel 3 transfer restoring its context.
#define 	AT91C_HDMA_RES3_0                    (0x0 << 11) // (HDMA) No effect.
#define 	AT91C_HDMA_RES3_1                    (0x1 << 11) // (HDMA) Resumes the channel 3.
#define AT91C_HDMA_RES4       (0x1 << 12) // (HDMA) Write one to this field to resume the channel 4 transfer restoring its context.
#define 	AT91C_HDMA_RES4_0                    (0x0 << 12) // (HDMA) No effect.
#define 	AT91C_HDMA_RES4_1                    (0x1 << 12) // (HDMA) Resumes the channel 4.
#define AT91C_HDMA_RES5       (0x1 << 13) // (HDMA) Write one to this field to resume the channel 5 transfer restoring its context.
#define 	AT91C_HDMA_RES5_0                    (0x0 << 13) // (HDMA) No effect.
#define 	AT91C_HDMA_RES5_1                    (0x1 << 13) // (HDMA) Resumes the channel 5.
#define AT91C_HDMA_RES6       (0x1 << 14) // (HDMA) Write one to this field to resume the channel 6 transfer restoring its context.
#define 	AT91C_HDMA_RES6_0                    (0x0 << 14) // (HDMA) No effect.
#define 	AT91C_HDMA_RES6_1                    (0x1 << 14) // (HDMA) Resumes the channel 6.
#define AT91C_HDMA_RES7       (0x1 << 15) // (HDMA) Write one to this field to resume the channel 7 transfer restoring its context.
#define 	AT91C_HDMA_RES7_0                    (0x0 << 15) // (HDMA) No effect.
#define 	AT91C_HDMA_RES7_1                    (0x1 << 15) // (HDMA) Resumes the channel 7.
// -------- HDMA_CHSR : (HDMA Offset: 0x30)  -------- 
#define AT91C_HDMA_EMPT0      (0x1 << 16) // (HDMA) When set, channel 0 is empty.
#define 	AT91C_HDMA_EMPT0_0                    (0x0 << 16) // (HDMA) No effect.
#define 	AT91C_HDMA_EMPT0_1                    (0x1 << 16) // (HDMA) Channel 0 empty.
#define AT91C_HDMA_EMPT1      (0x1 << 17) // (HDMA) When set, channel 1 is empty.
#define 	AT91C_HDMA_EMPT1_0                    (0x0 << 17) // (HDMA) No effect.
#define 	AT91C_HDMA_EMPT1_1                    (0x1 << 17) // (HDMA) Channel 1 empty.
#define AT91C_HDMA_EMPT2      (0x1 << 18) // (HDMA) When set, channel 2 is empty.
#define 	AT91C_HDMA_EMPT2_0                    (0x0 << 18) // (HDMA) No effect.
#define 	AT91C_HDMA_EMPT2_1                    (0x1 << 18) // (HDMA) Channel 2 empty.
#define AT91C_HDMA_EMPT3      (0x1 << 19) // (HDMA) When set, channel 3 is empty.
#define 	AT91C_HDMA_EMPT3_0                    (0x0 << 19) // (HDMA) No effect.
#define 	AT91C_HDMA_EMPT3_1                    (0x1 << 19) // (HDMA) Channel 3 empty.
#define AT91C_HDMA_EMPT4      (0x1 << 20) // (HDMA) When set, channel 4 is empty.
#define 	AT91C_HDMA_EMPT4_0                    (0x0 << 20) // (HDMA) No effect.
#define 	AT91C_HDMA_EMPT4_1                    (0x1 << 20) // (HDMA) Channel 4 empty.
#define AT91C_HDMA_EMPT5      (0x1 << 21) // (HDMA) When set, channel 5 is empty.
#define 	AT91C_HDMA_EMPT5_0                    (0x0 << 21) // (HDMA) No effect.
#define 	AT91C_HDMA_EMPT5_1                    (0x1 << 21) // (HDMA) Channel 5 empty.
#define AT91C_HDMA_EMPT6      (0x1 << 22) // (HDMA) When set, channel 6 is empty.
#define 	AT91C_HDMA_EMPT6_0                    (0x0 << 22) // (HDMA) No effect.
#define 	AT91C_HDMA_EMPT6_1                    (0x1 << 22) // (HDMA) Channel 6 empty.
#define AT91C_HDMA_EMPT7      (0x1 << 23) // (HDMA) When set, channel 7 is empty.
#define 	AT91C_HDMA_EMPT7_0                    (0x0 << 23) // (HDMA) No effect.
#define 	AT91C_HDMA_EMPT7_1                    (0x1 << 23) // (HDMA) Channel 7 empty.
#define AT91C_HDMA_STAL0      (0x1 << 24) // (HDMA) When set, channel 0 is stalled.
#define 	AT91C_HDMA_STAL0_0                    (0x0 << 24) // (HDMA) No effect.
#define 	AT91C_HDMA_STAL0_1                    (0x1 << 24) // (HDMA) Channel 0 stalled.
#define AT91C_HDMA_STAL1      (0x1 << 25) // (HDMA) When set, channel 1 is stalled.
#define 	AT91C_HDMA_STAL1_0                    (0x0 << 25) // (HDMA) No effect.
#define 	AT91C_HDMA_STAL1_1                    (0x1 << 25) // (HDMA) Channel 1 stalled.
#define AT91C_HDMA_STAL2      (0x1 << 26) // (HDMA) When set, channel 2 is stalled.
#define 	AT91C_HDMA_STAL2_0                    (0x0 << 26) // (HDMA) No effect.
#define 	AT91C_HDMA_STAL2_1                    (0x1 << 26) // (HDMA) Channel 2 stalled.
#define AT91C_HDMA_STAL3      (0x1 << 27) // (HDMA) When set, channel 3 is stalled.
#define 	AT91C_HDMA_STAL3_0                    (0x0 << 27) // (HDMA) No effect.
#define 	AT91C_HDMA_STAL3_1                    (0x1 << 27) // (HDMA) Channel 3 stalled.
#define AT91C_HDMA_STAL4      (0x1 << 28) // (HDMA) When set, channel 4 is stalled.
#define 	AT91C_HDMA_STAL4_0                    (0x0 << 28) // (HDMA) No effect.
#define 	AT91C_HDMA_STAL4_1                    (0x1 << 28) // (HDMA) Channel 4 stalled.
#define AT91C_HDMA_STAL5      (0x1 << 29) // (HDMA) When set, channel 5 is stalled.
#define 	AT91C_HDMA_STAL5_0                    (0x0 << 29) // (HDMA) No effect.
#define 	AT91C_HDMA_STAL5_1                    (0x1 << 29) // (HDMA) Channel 5 stalled.
#define AT91C_HDMA_STAL6      (0x1 << 30) // (HDMA) When set, channel 6 is stalled.
#define 	AT91C_HDMA_STAL6_0                    (0x0 << 30) // (HDMA) No effect.
#define 	AT91C_HDMA_STAL6_1                    (0x1 << 30) // (HDMA) Channel 6 stalled.
#define AT91C_HDMA_STAL7      (0x1 << 31) // (HDMA) When set, channel 7 is stalled.
#define 	AT91C_HDMA_STAL7_0                    (0x0 << 31) // (HDMA) No effect.
#define 	AT91C_HDMA_STAL7_1                    (0x1 << 31) // (HDMA) Channel 7 stalled.
// -------- HDMA_RSVD : (HDMA Offset: 0x34)  -------- 
// -------- HDMA_RSVD : (HDMA Offset: 0x38)  -------- 
// -------- HDMA_VER : (HDMA Offset: 0x1fc)  -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR OTGHS Device DMA struct
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_OTGHS_DEVDMA {
	AT91_REG	 OTGHS_DEVDMANXTDSC; 	// OTGHS DMA Channel Next Descriptor Address
	AT91_REG	 OTGHS_DEVDMAADDRESS; 	// OTGHS DMA Channel Address Register
	AT91_REG	 OTGHS_DEVDMACONTROL; 	// OTGHS DMA Channel Control Register
	AT91_REG	 OTGHS_DEVDMASTATUS; 	// OTGHS DMA Channel Status Register
} AT91S_OTGHS_DEVDMA, *AT91PS_OTGHS_DEVDMA;
#else
#define OTGHS_DEVDMANXTDSC (AT91_CAST(AT91_REG *) 	0x00000000) // (OTGHS_DEVDMANXTDSC) OTGHS DMA Channel Next Descriptor Address
#define OTGHS_DEVDMAADDRESS (AT91_CAST(AT91_REG *) 	0x00000004) // (OTGHS_DEVDMAADDRESS) OTGHS DMA Channel Address Register
#define OTGHS_DEVDMACONTROL (AT91_CAST(AT91_REG *) 	0x00000008) // (OTGHS_DEVDMACONTROL) OTGHS DMA Channel Control Register
#define OTGHS_DEVDMASTATUS (AT91_CAST(AT91_REG *) 	0x0000000C) // (OTGHS_DEVDMASTATUS) OTGHS DMA Channel Status Register

#endif
// -------- OTGHS_DMANXTDSC : (OTGHS_DEVDMA Offset: 0x0) OTGHS DMA Next Descriptor Address Register -------- 
#define AT91C_OTGHS_NXT_DSC_ADD (0xFFFFFFF <<  4) // (OTGHS_DEVDMA) next Channel Descriptor
// -------- OTGHS_DMAADDRESS : (OTGHS_DEVDMA Offset: 0x4) OTGHS DMA Channel Address Register -------- 
#define AT91C_OTGHS_BUFF_ADD  (0x0 <<  0) // (OTGHS_DEVDMA) starting address of a DMA Channel transfer
// -------- OTGHS_DMACONTROL : (OTGHS_DEVDMA Offset: 0x8) OTGHS DMA Channel Control Register -------- 
#define AT91C_OTGHS_CHANN_ENB (0x1 <<  0) // (OTGHS_DEVDMA) Channel Enabled
#define AT91C_OTGHS_LDNXT_DSC (0x1 <<  1) // (OTGHS_DEVDMA) Load Next Channel Transfer Descriptor Enable
#define AT91C_OTGHS_END_TR_EN (0x1 <<  2) // (OTGHS_DEVDMA) Buffer Close Input Enable
#define AT91C_OTGHS_END_B_EN  (0x1 <<  3) // (OTGHS_DEVDMA) End of DMA Buffer Packet Validation
#define AT91C_OTGHS_END_TR_IT (0x1 <<  4) // (OTGHS_DEVDMA) End Of Transfer Interrupt Enable
#define AT91C_OTGHS_END_BUFFIT (0x1 <<  5) // (OTGHS_DEVDMA) End Of Channel Buffer Interrupt Enable
#define AT91C_OTGHS_DESC_LD_IT (0x1 <<  6) // (OTGHS_DEVDMA) Descriptor Loaded Interrupt Enable
#define AT91C_OTGHS_BURST_LCK (0x1 <<  7) // (OTGHS_DEVDMA) Burst Lock Enable
#define AT91C_OTGHS_BUFF_LENGTH (0xFFFF << 16) // (OTGHS_DEVDMA) Buffer Byte Length (write only)
// -------- OTGHS_DMASTATUS : (OTGHS_DEVDMA Offset: 0xc) OTGHS DMA Channelx Status Register -------- 
#define AT91C_OTGHS_CHANN_ACT (0x1 <<  1) // (OTGHS_DEVDMA) 
#define AT91C_OTGHS_END_TR_ST (0x1 <<  4) // (OTGHS_DEVDMA) 
#define AT91C_OTGHS_END_BF_ST (0x1 <<  5) // (OTGHS_DEVDMA) 
#define AT91C_OTGHS_DESC_LDST (0x1 <<  6) // (OTGHS_DEVDMA) 
#define AT91C_OTGHS_BUFF_COUNT (0xFFFF << 16) // (OTGHS_DEVDMA) 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR OTGHS HOST DMA struct
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_OTGHS_HSTDMA {
	AT91_REG	 OTGHS_HSTDMANXTDSC; 	// OTGHS DMA Channel Next Descriptor Address
	AT91_REG	 OTGHS_HSTDMAADDRESS; 	// OTGHS DMA Channel Address Register
	AT91_REG	 OTGHS_HSTDMACONTROL; 	// OTGHS DMA Channel Control Register
	AT91_REG	 OTGHS_HSTDMASTATUS; 	// OTGHS DMA Channel Status Register
} AT91S_OTGHS_HSTDMA, *AT91PS_OTGHS_HSTDMA;
#else
#define OTGHS_HSTDMANXTDSC (AT91_CAST(AT91_REG *) 	0x00000000) // (OTGHS_HSTDMANXTDSC) OTGHS DMA Channel Next Descriptor Address
#define OTGHS_HSTDMAADDRESS (AT91_CAST(AT91_REG *) 	0x00000004) // (OTGHS_HSTDMAADDRESS) OTGHS DMA Channel Address Register
#define OTGHS_HSTDMACONTROL (AT91_CAST(AT91_REG *) 	0x00000008) // (OTGHS_HSTDMACONTROL) OTGHS DMA Channel Control Register
#define OTGHS_HSTDMASTATUS (AT91_CAST(AT91_REG *) 	0x0000000C) // (OTGHS_HSTDMASTATUS) OTGHS DMA Channel Status Register

#endif
// -------- OTGHS_DMANXTDSC : (OTGHS_HSTDMA Offset: 0x0) OTGHS DMA Next Descriptor Address Register -------- 
// -------- OTGHS_DMAADDRESS : (OTGHS_HSTDMA Offset: 0x4) OTGHS DMA Channel Address Register -------- 
// -------- OTGHS_DMACONTROL : (OTGHS_HSTDMA Offset: 0x8) OTGHS DMA Channel Control Register -------- 
// -------- OTGHS_DMASTATUS : (OTGHS_HSTDMA Offset: 0xc) OTGHS DMA Channelx Status Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR OTGHS Enpoint FIFO data register
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_OTGHS_EPTFIFO {
	AT91_REG	 OTGHS_READEPT0[16384]; 	// FIFO Endpoint Data Register 0
	AT91_REG	 OTGHS_READEPT1[16384]; 	// FIFO Endpoint Data Register 1
	AT91_REG	 OTGHS_READEPT2[16384]; 	// FIFO Endpoint Data Register 2
	AT91_REG	 OTGHS_READEPT3[16384]; 	// FIFO Endpoint Data Register 3
	AT91_REG	 OTGHS_READEPT4[16384]; 	// FIFO Endpoint Data Register 4
	AT91_REG	 OTGHS_READEPT5[16384]; 	// FIFO Endpoint Data Register 5
	AT91_REG	 OTGHS_READEPT6[16384]; 	// FIFO Endpoint Data Register 6
	AT91_REG	 OTGHS_READEPT7[16384]; 	// FIFO Endpoint Data Register 7
	AT91_REG	 OTGHS_READEPT8[16384]; 	// FIFO Endpoint Data Register 8
	AT91_REG	 OTGHS_READEPT9[16384]; 	// FIFO Endpoint Data Register 9
	AT91_REG	 OTGHS_READEPTA[16384]; 	// FIFO Endpoint Data Register 10
	AT91_REG	 OTGHS_READEPTB[16384]; 	// FIFO Endpoint Data Register 11
	AT91_REG	 OTGHS_READEPTC[16384]; 	// FIFO Endpoint Data Register 12
	AT91_REG	 OTGHS_READEPTD[16384]; 	// FIFO Endpoint Data Register 13
	AT91_REG	 OTGHS_READEPTE[16384]; 	// FIFO Endpoint Data Register 14
	AT91_REG	 OTGHS_READEPTF[16384]; 	// FIFO Endpoint Data Register 15
} AT91S_OTGHS_EPTFIFO, *AT91PS_OTGHS_EPTFIFO;
#else
#define OTGHS_READEPT0  (AT91_CAST(AT91_REG *) 	0x00000000) // (OTGHS_READEPT0) FIFO Endpoint Data Register 0
#define OTGHS_READEPT1  (AT91_CAST(AT91_REG *) 	0x00010000) // (OTGHS_READEPT1) FIFO Endpoint Data Register 1
#define OTGHS_READEPT2  (AT91_CAST(AT91_REG *) 	0x00020000) // (OTGHS_READEPT2) FIFO Endpoint Data Register 2
#define OTGHS_READEPT3  (AT91_CAST(AT91_REG *) 	0x00030000) // (OTGHS_READEPT3) FIFO Endpoint Data Register 3
#define OTGHS_READEPT4  (AT91_CAST(AT91_REG *) 	0x00040000) // (OTGHS_READEPT4) FIFO Endpoint Data Register 4
#define OTGHS_READEPT5  (AT91_CAST(AT91_REG *) 	0x00050000) // (OTGHS_READEPT5) FIFO Endpoint Data Register 5
#define OTGHS_READEPT6  (AT91_CAST(AT91_REG *) 	0x00060000) // (OTGHS_READEPT6) FIFO Endpoint Data Register 6
#define OTGHS_READEPT7  (AT91_CAST(AT91_REG *) 	0x00070000) // (OTGHS_READEPT7) FIFO Endpoint Data Register 7
#define OTGHS_READEPT8  (AT91_CAST(AT91_REG *) 	0x00080000) // (OTGHS_READEPT8) FIFO Endpoint Data Register 8
#define OTGHS_READEPT9  (AT91_CAST(AT91_REG *) 	0x00090000) // (OTGHS_READEPT9) FIFO Endpoint Data Register 9
#define OTGHS_READEPTA  (AT91_CAST(AT91_REG *) 	0x000A0000) // (OTGHS_READEPTA) FIFO Endpoint Data Register 10
#define OTGHS_READEPTB  (AT91_CAST(AT91_REG *) 	0x000B0000) // (OTGHS_READEPTB) FIFO Endpoint Data Register 11
#define OTGHS_READEPTC  (AT91_CAST(AT91_REG *) 	0x000C0000) // (OTGHS_READEPTC) FIFO Endpoint Data Register 12
#define OTGHS_READEPTD  (AT91_CAST(AT91_REG *) 	0x000D0000) // (OTGHS_READEPTD) FIFO Endpoint Data Register 13
#define OTGHS_READEPTE  (AT91_CAST(AT91_REG *) 	0x000E0000) // (OTGHS_READEPTE) FIFO Endpoint Data Register 14
#define OTGHS_READEPTF  (AT91_CAST(AT91_REG *) 	0x000F0000) // (OTGHS_READEPTF) FIFO Endpoint Data Register 15

#endif

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR OTGHS Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_OTGHS {
	AT91_REG	 OTGHS_DEVCTRL; 	// [RW] OTGHS Device Control Register
	AT91_REG	 OTGHS_DEVISR; 	// [RO] OTGHS Device Interupt Statuts Register
	AT91_REG	 OTGHS_DEVICR; 	// [WO] OTGHS Device Interupt Clear Register
	AT91_REG	 OTGHS_DEVIFR; 	// [WO] OTGHS Device Interupt Force Register (for DEBUG/TEST only)
	AT91_REG	 OTGHS_DEVIMR; 	// [RO] OTGHS Device Interupt Mask Register
	AT91_REG	 OTGHS_DEVIDR; 	// [WO] OTGHS Device Interupt Disable Register
	AT91_REG	 OTGHS_DEVIER; 	// [WO] OTGHS Device Interupt Enable Register
	AT91_REG	 OTGHS_DEVEPT; 	// [RW] OTGHS Device Endpoint Enable Register
	AT91_REG	 OTGHS_DEVFNUM; 	// [RO] OTGHS Device Frame Number Register
	AT91_REG	 Reserved0[55]; 	// 
	AT91_REG	 OTGHS_DEVEPTCFG[9]; 	// [RW] OTGHS Device Endpoint Configuration Register[x]
	AT91_REG	 Reserved1[3]; 	// 
	AT91_REG	 OTGHS_DEVEPTISR[9]; 	// [RO] OTGHS Device Endpoint Interrupt Status Register[x]
	AT91_REG	 Reserved2[3]; 	// 
	AT91_REG	 OTGHS_DEVEPTICR[9]; 	// [WO] OTGHS Device Endpoint Clear Status Register[x]
	AT91_REG	 Reserved3[3]; 	// 
	AT91_REG	 OTGHS_DEVEPTIFR[9]; 	// [WO] OTGHS Device Endpoint Force Status Register[x] (for DEBUG/TEST only)
	AT91_REG	 Reserved4[3]; 	// 
	AT91_REG	 OTGHS_DEVEPTIMR[9]; 	// [RO] OTGHS Device Endpoint Control Mask Register[x]
	AT91_REG	 Reserved5[3]; 	// 
	AT91_REG	 OTGHS_DEVEPTIER[9]; 	// [WO] OTGHS Device Endpoint Control Enable Register[x]
	AT91_REG	 Reserved6[3]; 	// 
	AT91_REG	 OTGHS_DEVEPTIDR[9]; 	// [WO] OTGHS Device Endpoint Control Disable Register[x]
	AT91_REG	 Reserved7[47]; 	// 
	AT91S_OTGHS_DEVDMA	 OTGHS_DEVDMA[8]; 	// OTGHS DMA Device channel struct (NOT USE [0])
	AT91_REG	 Reserved8[32]; 	// 
	AT91_REG	 OTGHS_HSTCTRL; 	// [RW] OTGHS Host Control Register
	AT91_REG	 OTGHS_HSTISR; 	// [RO] OTGHS Host Interupt Register
	AT91_REG	 OTGHS_HSTICR; 	// [WO] OTGHS Host Interupt Clear Register
	AT91_REG	 OTGHS_HSTIFR; 	// [WO] OTGHS Host Interupt Force Register (for DEBUG/TEST only)
	AT91_REG	 OTGHS_HSTIMR; 	// [RO] OTGHS Host Interupt Mask Register
	AT91_REG	 OTGHS_HSTIDR; 	// [WO] OTGHS Host Interupt Disable Register
	AT91_REG	 OTGHS_HSTIER; 	// [WO] OTGHS Host Interupt Enable Register
	AT91_REG	 OTGHS_HSTPIP; 	// [RW] OTGHS Host Pipe Enable Reset Register
	AT91_REG	 OTGHS_HSTFNUM; 	// [RO] OTGHS Host Frame Number Register
	AT91_REG	 OTGHS_HSTADDR1; 	// [RW] OTGHS Host Address Register 1
	AT91_REG	 OTGHS_HSTADDR2; 	// [RW] OTGHS Host Address Register 2
	AT91_REG	 OTGHS_HSTADDR3; 	// [RW] OTGHS Host Address Register 3
	AT91_REG	 Reserved9[52]; 	// 
	AT91_REG	 OTGHS_HSTPIPCFG[9]; 	// [RW] OTGHS Host Pipe Configuration Register [x]
	AT91_REG	 Reserved10[3]; 	// 
	AT91_REG	 OTGHS_HSTPIPISR[9]; 	// [RO] OTGHS Host Pipe Status Register[x]
	AT91_REG	 Reserved11[3]; 	// 
	AT91_REG	 OTGHS_HSTPIPICR[9]; 	// [WO] OTGHS Host Pipe Clear Status Register[x]
	AT91_REG	 Reserved12[3]; 	// 
	AT91_REG	 OTGHS_HSTPIPIFR[9]; 	// [WO] OTGHS Host Pipe Force Status Register[x] (for DEBUG/TEST only)
	AT91_REG	 Reserved13[3]; 	// 
	AT91_REG	 OTGHS_HSTPIPIMR[9]; 	// [RO] OTGHS Host Pipe Control Register[x]
	AT91_REG	 Reserved14[3]; 	// 
	AT91_REG	 OTGHS_HSTPIPIER[9]; 	// [WO] OTGHS Host Pipe Control Set Register[x]
	AT91_REG	 Reserved15[3]; 	// 
	AT91_REG	 OTGHS_HSTPIPIDR[9]; 	// [WO] OTGHS Host Pipe Clear Control Register[x]
	AT91_REG	 Reserved16[3]; 	// 
	AT91_REG	 OTGHS_HSTPIPINRQ[9]; 	// [RW] OTGHS Host Pipe IN Request Register[x]
	AT91_REG	 Reserved17[3]; 	// 
	AT91_REG	 OTGHS_HSTPIPERR[9]; 	// [WO] OTGHS Host Pipe Error Register[x]
	AT91_REG	 Reserved18[23]; 	// 
	AT91S_OTGHS_HSTDMA	 OTGHS_HSTDMA[4]; 	// OTGHS DMA Host channel struct (NOT USE [0])
	AT91_REG	 Reserved19[48]; 	// 
	AT91_REG	 OTGHS_CTRL; 	// [RW] OTGHS General Control Register
	AT91_REG	 OTGHS_SR; 	// [RO] OTGHS General Status Register
	AT91_REG	 OTGHS_SCR; 	// [WO] OTGHS General Status Clear Register
	AT91_REG	 OTGHS_SFR; 	// [WO] OTGHS General Status Force Register (for DEBUG/TEST only)
	AT91_REG	 OTGHS_TSTA1; 	// [RW] OTGHS Arbiter Test 1 Register
	AT91_REG	 OTGHS_TSTA2; 	// [RW] OTGHS Arbiter Test 2 Register
	AT91_REG	 OTGHS_IPVERSION; 	// [RO] OTGHS Version Register
	AT91_REG	 OTGHS_IPFEATURES; 	// [RO] OTGHS Features Register
	AT91_REG	 OTGHS_RIPPADDRSIZE; 	// [RO] OTGHS PADDRSIZE Register
	AT91_REG	 OTGHS_RIPNAME1; 	// [RO] OTGHS Name1 Register
	AT91_REG	 OTGHS_RIPNAME2; 	// [RO] OTGHS Name2 Register
	AT91_REG	 OTGHS_FSM; 	// [RO] OTGHS A-Device/B-Device State
} AT91S_OTGHS, *AT91PS_OTGHS;
#else
#define OTGHS_DEVCTRL   (AT91_CAST(AT91_REG *) 	0x00000000) // (OTGHS_DEVCTRL) [RW] OTGHS Device Control Register
#define OTGHS_DEVISR    (AT91_CAST(AT91_REG *) 	0x00000004) // (OTGHS_DEVISR) [RO] OTGHS Device Interupt Statuts Register
#define OTGHS_DEVICR    (AT91_CAST(AT91_REG *) 	0x00000008) // (OTGHS_DEVICR) [WO] OTGHS Device Interupt Clear Register
#define OTGHS_DEVIFR    (AT91_CAST(AT91_REG *) 	0x0000000C) // (OTGHS_DEVIFR) [WO] OTGHS Device Interupt Force Register (for DEBUG/TEST only)
#define OTGHS_DEVIMR    (AT91_CAST(AT91_REG *) 	0x00000010) // (OTGHS_DEVIMR) [RO] OTGHS Device Interupt Mask Register
#define OTGHS_DEVIDR    (AT91_CAST(AT91_REG *) 	0x00000014) // (OTGHS_DEVIDR) [WO] OTGHS Device Interupt Disable Register
#define OTGHS_DEVIER    (AT91_CAST(AT91_REG *) 	0x00000018) // (OTGHS_DEVIER) [WO] OTGHS Device Interupt Enable Register
#define OTGHS_DEVEPT    (AT91_CAST(AT91_REG *) 	0x0000001C) // (OTGHS_DEVEPT) [RW] OTGHS Device Endpoint Enable Register
#define OTGHS_DEVFNUM   (AT91_CAST(AT91_REG *) 	0x00000020) // (OTGHS_DEVFNUM) [RO] OTGHS Device Frame Number Register
#define OTGHS_DEVEPTCFG (AT91_CAST(AT91_REG *) 	0x00000100) // (OTGHS_DEVEPTCFG) [RW] OTGHS Device Endpoint Configuration Register[x]
#define OTGHS_DEVEPTISR (AT91_CAST(AT91_REG *) 	0x00000130) // (OTGHS_DEVEPTISR) [RO] OTGHS Device Endpoint Interrupt Status Register[x]
#define OTGHS_DEVEPTICR (AT91_CAST(AT91_REG *) 	0x00000160) // (OTGHS_DEVEPTICR) [WO] OTGHS Device Endpoint Clear Status Register[x]
#define OTGHS_DEVEPTIFR (AT91_CAST(AT91_REG *) 	0x00000190) // (OTGHS_DEVEPTIFR) [WO] OTGHS Device Endpoint Force Status Register[x] (for DEBUG/TEST only)
#define OTGHS_DEVEPTIMR (AT91_CAST(AT91_REG *) 	0x000001C0) // (OTGHS_DEVEPTIMR) [RO] OTGHS Device Endpoint Control Mask Register[x]
#define OTGHS_DEVEPTIER (AT91_CAST(AT91_REG *) 	0x000001F0) // (OTGHS_DEVEPTIER) [WO] OTGHS Device Endpoint Control Enable Register[x]
#define OTGHS_DEVEPTIDR (AT91_CAST(AT91_REG *) 	0x00000220) // (OTGHS_DEVEPTIDR) [WO] OTGHS Device Endpoint Control Disable Register[x]
#define OTGHS_HSTCTRL   (AT91_CAST(AT91_REG *) 	0x00000400) // (OTGHS_HSTCTRL) [RW] OTGHS Host Control Register
#define OTGHS_HSTISR    (AT91_CAST(AT91_REG *) 	0x00000404) // (OTGHS_HSTISR) [RO] OTGHS Host Interupt Register
#define OTGHS_HSTICR    (AT91_CAST(AT91_REG *) 	0x00000408) // (OTGHS_HSTICR) [WO] OTGHS Host Interupt Clear Register
#define OTGHS_HSTIFR    (AT91_CAST(AT91_REG *) 	0x0000040C) // (OTGHS_HSTIFR) [WO] OTGHS Host Interupt Force Register (for DEBUG/TEST only)
#define OTGHS_HSTIMR    (AT91_CAST(AT91_REG *) 	0x00000410) // (OTGHS_HSTIMR) [RO] OTGHS Host Interupt Mask Register
#define OTGHS_HSTIDR    (AT91_CAST(AT91_REG *) 	0x00000414) // (OTGHS_HSTIDR) [WO] OTGHS Host Interupt Disable Register
#define OTGHS_HSTIER    (AT91_CAST(AT91_REG *) 	0x00000418) // (OTGHS_HSTIER) [WO] OTGHS Host Interupt Enable Register
#define OTGHS_HSTPIP    (AT91_CAST(AT91_REG *) 	0x0000041C) // (OTGHS_HSTPIP) [RW] OTGHS Host Pipe Enable Reset Register
#define OTGHS_HSTFNUM   (AT91_CAST(AT91_REG *) 	0x00000420) // (OTGHS_HSTFNUM) [RO] OTGHS Host Frame Number Register
#define OTGHS_HSTADDR1  (AT91_CAST(AT91_REG *) 	0x00000424) // (OTGHS_HSTADDR1) [RW] OTGHS Host Address Register 1
#define OTGHS_HSTADDR2  (AT91_CAST(AT91_REG *) 	0x00000428) // (OTGHS_HSTADDR2) [RW] OTGHS Host Address Register 2
#define OTGHS_HSTADDR3  (AT91_CAST(AT91_REG *) 	0x0000042C) // (OTGHS_HSTADDR3) [RW] OTGHS Host Address Register 3
#define OTGHS_HSTPIPCFG (AT91_CAST(AT91_REG *) 	0x00000500) // (OTGHS_HSTPIPCFG) [RW] OTGHS Host Pipe Configuration Register [x]
#define OTGHS_HSTPIPISR (AT91_CAST(AT91_REG *) 	0x00000530) // (OTGHS_HSTPIPISR) [RO] OTGHS Host Pipe Status Register[x]
#define OTGHS_HSTPIPICR (AT91_CAST(AT91_REG *) 	0x00000560) // (OTGHS_HSTPIPICR) [WO] OTGHS Host Pipe Clear Status Register[x]
#define OTGHS_HSTPIPIFR (AT91_CAST(AT91_REG *) 	0x00000590) // (OTGHS_HSTPIPIFR) [WO] OTGHS Host Pipe Force Status Register[x] (for DEBUG/TEST only)
#define OTGHS_HSTPIPIMR (AT91_CAST(AT91_REG *) 	0x000005C0) // (OTGHS_HSTPIPIMR) [RO] OTGHS Host Pipe Control Register[x]
#define OTGHS_HSTPIPIER (AT91_CAST(AT91_REG *) 	0x000005F0) // (OTGHS_HSTPIPIER) [WO] OTGHS Host Pipe Control Set Register[x]
#define OTGHS_HSTPIPIDR (AT91_CAST(AT91_REG *) 	0x00000620) // (OTGHS_HSTPIPIDR) [WO] OTGHS Host Pipe Clear Control Register[x]
#define OTGHS_HSTPIPINRQ (AT91_CAST(AT91_REG *) 	0x00000650) // (OTGHS_HSTPIPINRQ) [RW] OTGHS Host Pipe IN Request Register[x]
#define OTGHS_HSTPIPERR (AT91_CAST(AT91_REG *) 	0x00000680) // (OTGHS_HSTPIPERR) [WO] OTGHS Host Pipe Error Register[x]
#define OTGHS_CTRL      (AT91_CAST(AT91_REG *) 	0x00000800) // (OTGHS_CTRL) [RW] OTGHS General Control Register
#define OTGHS_SR        (AT91_CAST(AT91_REG *) 	0x00000804) // (OTGHS_SR) [RO] OTGHS General Status Register
#define OTGHS_SCR       (AT91_CAST(AT91_REG *) 	0x00000808) // (OTGHS_SCR) [WO] OTGHS General Status Clear Register
#define OTGHS_SFR       (AT91_CAST(AT91_REG *) 	0x0000080C) // (OTGHS_SFR) [WO] OTGHS General Status Force Register (for DEBUG/TEST only)
#define OTGHS_TSTA1     (AT91_CAST(AT91_REG *) 	0x00000810) // (OTGHS_TSTA1) [RW] OTGHS Arbiter Test 1 Register
#define OTGHS_TSTA2     (AT91_CAST(AT91_REG *) 	0x00000814) // (OTGHS_TSTA2) [RW] OTGHS Arbiter Test 2 Register
#define OTGHS_IPVERSION (AT91_CAST(AT91_REG *) 	0x00000818) // (OTGHS_IPVERSION) [RO] OTGHS Version Register
#define OTGHS_IPFEATURES (AT91_CAST(AT91_REG *) 	0x0000081C) // (OTGHS_IPFEATURES) [RO] OTGHS Features Register
#define OTGHS_RIPPADDRSIZE (AT91_CAST(AT91_REG *) 	0x00000820) // (OTGHS_RIPPADDRSIZE) [RO] OTGHS PADDRSIZE Register
#define OTGHS_RIPNAME1  (AT91_CAST(AT91_REG *) 	0x00000824) // (OTGHS_RIPNAME1) [RO] OTGHS Name1 Register
#define OTGHS_RIPNAME2  (AT91_CAST(AT91_REG *) 	0x00000828) // (OTGHS_RIPNAME2) [RO] OTGHS Name2 Register
#define OTGHS_FSM       (AT91_CAST(AT91_REG *) 	0x0000082C) // (OTGHS_FSM) [RO] OTGHS A-Device/B-Device State

#endif
// -------- OTGHS_DEVCTRL : (OTGHS Offset: 0x0) OTGHS Device Control Register -------- 
#define AT91C_OTGHS_UADD      (0x7F <<  0) // (OTGHS) USB Address Bits
#define AT91C_OTGHS_ADDEN     (0x1 <<  7) // (OTGHS) Address Enable Bit
#define AT91C_OTGHS_DETACH    (0x1 <<  8) // (OTGHS) Detach Bit
#define AT91C_OTGHS_RMWKUP    (0x1 <<  9) // (OTGHS) Remote Wake-up Bit
#define AT91C_OTGHS_SPDCONF   (0x3 << 10) // (OTGHS) Speed Configuration
#define 	AT91C_OTGHS_SPDCONF_NM                   (0x0 << 10) // (OTGHS) Normal Mode (automatic)
#define 	AT91C_OTGHS_SPDCONF_HS                   (0x2 << 10) // (OTGHS) Force High Speed only (for debug or test)
#define 	AT91C_OTGHS_SPDCONF_FS                   (0x3 << 10) // (OTGHS) Force Full Speed only (for debug or test)
#define AT91C_OTGHS_LS        (0x1 << 12) // (OTGHS) Low-speed mode
#define AT91C_OTGHS_TSTJ      (0x1 << 13) // (OTGHS) Test Mode Test_J
#define AT91C_OTGHS_TSTK      (0x1 << 14) // (OTGHS) Test Mode Test_K
#define AT91C_OTGHS_TSTPCKT   (0x1 << 15) // (OTGHS) Test Mode Test_Packet
#define AT91C_OTGHS_OPMODE2   (0x1 << 16) // (OTGHS) OP Mode 2
// -------- OTGHS_DEVISR : (OTGHS Offset: 0x4) OTGHS Device Interrupt Status Register -------- 
#define AT91C_OTGHS_SUSP      (0x1 <<  0) // (OTGHS) suspend Interrupt
#define AT91C_OTGHS_MSOF      (0x1 <<  1) // (OTGHS) 
#define AT91C_OTGHS_SOF       (0x1 <<  2) // (OTGHS) 
#define AT91C_OTGHS_EORST     (0x1 <<  3) // (OTGHS) 
#define AT91C_OTGHS_WAKEUP    (0x1 <<  4) // (OTGHS) 
#define AT91C_OTGHS_EORSM     (0x1 <<  5) // (OTGHS) 
#define AT91C_OTGHS_UPRSM     (0x1 <<  6) // (OTGHS) 
#define AT91C_OTGHS_VBUST     (0x1 <<  7) // (OTGHS) 
#define AT91C_OTGHS_VBUS      (0x1 <<  8) // (OTGHS) 
#define AT91C_OTGHS_SPEED     (0x1 <<  9) // (OTGHS) 
#define AT91C_OTGHS_EPOINT    (0x1 << 12) // (OTGHS) 
#define AT91C_OTGHS_EP1INT    (0x1 << 13) // (OTGHS) 
#define AT91C_OTGHS_EP2INT    (0x1 << 14) // (OTGHS) 
#define AT91C_OTGHS_EP3INT    (0x1 << 15) // (OTGHS) 
#define AT91C_OTGHS_EP4INT    (0x1 << 16) // (OTGHS) 
#define AT91C_OTGHS_EP5INT    (0x1 << 17) // (OTGHS) 
#define AT91C_OTGHS_EP6INT    (0x1 << 18) // (OTGHS) 
#define AT91C_OTGHS_DMA1INT   (0x1 << 25) // (OTGHS) 
#define AT91C_OTGHS_DMA2INT   (0x1 << 26) // (OTGHS) 
#define AT91C_OTGHS_DMA3INT   (0x1 << 27) // (OTGHS) 
#define AT91C_OTGHS_DMA4INT   (0x1 << 28) // (OTGHS) 
#define AT91C_OTGHS_DMA5INT   (0x1 << 29) // (OTGHS) 
#define AT91C_OTGHS_DMA6INT   (0x1 << 30) // (OTGHS) 
// -------- OTGHS_DEVICR : (OTGHS Offset: 0x8) OTGHS Device Interrupt Clear Register -------- 
// -------- OTGHS_DEVIFR : (OTGHS Offset: 0xc) OTGHS Device Interrupt Force Register -------- 
// -------- OTGHS_DEVIMR : (OTGHS Offset: 0x10) OTGHS Device Interrupt Mask Register -------- 
// -------- OTGHS_DEVIDR : (OTGHS Offset: 0x14) OTGHS Device Interrupt Disable Register -------- 
// -------- OTGHS_DEVIER : (OTGHS Offset: 0x18) OTGHS Device Interrupt Enable Register -------- 
// -------- OTGHS_DEVEPT : (OTGHS Offset: 0x1c) OTGHS Device Endpoint Enable/Reset Register -------- 
#define AT91C_OTGHS_EPEN0     (0x1 <<  0) // (OTGHS) 
#define AT91C_OTGHS_EPEN1     (0x1 <<  1) // (OTGHS) 
#define AT91C_OTGHS_EPEN2     (0x1 <<  2) // (OTGHS) 
#define AT91C_OTGHS_EPEN3     (0x1 <<  3) // (OTGHS) 
#define AT91C_OTGHS_EPEN4     (0x1 <<  4) // (OTGHS) 
#define AT91C_OTGHS_EPEN5     (0x1 <<  5) // (OTGHS) 
#define AT91C_OTGHS_EPEN6     (0x1 <<  6) // (OTGHS) 
#define AT91C_OTGHS_EPEN7     (0x1 <<  7) // (OTGHS) 
#define AT91C_OTGHS_EPEN8     (0x1 <<  8) // (OTGHS) 
#define AT91C_OTGHS_EPEN9     (0x1 <<  9) // (OTGHS) 
#define AT91C_OTGHS_EPRST0    (0x1 << 16) // (OTGHS) 
#define AT91C_OTGHS_EPRST1    (0x1 << 17) // (OTGHS) 
#define AT91C_OTGHS_EPRST2    (0x1 << 18) // (OTGHS) 
#define AT91C_OTGHS_EPRST3    (0x1 << 19) // (OTGHS) 
#define AT91C_OTGHS_EPRST4    (0x1 << 20) // (OTGHS) 
#define AT91C_OTGHS_EPRST5    (0x1 << 21) // (OTGHS) 
#define AT91C_OTGHS_EPRST6    (0x1 << 22) // (OTGHS) 
#define AT91C_OTGHS_EPRST7    (0x1 << 23) // (OTGHS) 
#define AT91C_OTGHS_EPRST8    (0x1 << 24) // (OTGHS) 
#define AT91C_OTGHS_EPRST9    (0x1 << 25) // (OTGHS) 
// -------- OTGHS_DEVFNUM : (OTGHS Offset: 0x20) OTGHS Device Frame Number Register -------- 
#define AT91C_OTGHS_MICRO_FRAME_NUM (0x7 <<  0) // (OTGHS) Micro Frame Number
#define AT91C_OTGHS_FRAME_NUMBER (0x7FF <<  3) // (OTGHS) Frame Number as defined in the Packet Field Formats
#define AT91C_OTGHS_FNUM_ERR  (0x1 << 15) // (OTGHS) Frame Number CRC Error
// -------- OTGHS_DEVEPTCFG : (OTGHS Offset: 0x100) OTGHS Device Endpoint Configuration Register -------- 
#define AT91C_OTGHS_ALLOC     (0x1 <<  1) // (OTGHS) Pipe allocation bit
#define AT91C_OTGHS_BK_NUMBER (0x3 <<  2) // (OTGHS) Number of Banks
#define 	AT91C_OTGHS_BK_NUMBER_1                    (0x0 <<  2) // (OTGHS) One Bank (Bank0)
#define 	AT91C_OTGHS_BK_NUMBER_2                    (0x1 <<  2) // (OTGHS) Double bank (Ping-Pong : Bank0 / Bank1)
#define 	AT91C_OTGHS_BK_NUMBER_3                    (0x2 <<  2) // (OTGHS) Triple Bank (Bank0 / Bank1 / Bank2)
#define AT91C_OTGHS_EPT_SIZE  (0x7 <<  4) // (OTGHS) Endpoint Size
#define 	AT91C_OTGHS_EPT_SIZE_8                    (0x0 <<  4) // (OTGHS)    8 bytes
#define 	AT91C_OTGHS_EPT_SIZE_16                   (0x1 <<  4) // (OTGHS)   16 bytes
#define 	AT91C_OTGHS_EPT_SIZE_32                   (0x2 <<  4) // (OTGHS)   32 bytes
#define 	AT91C_OTGHS_EPT_SIZE_64                   (0x3 <<  4) // (OTGHS)   64 bytes
#define 	AT91C_OTGHS_EPT_SIZE_128                  (0x4 <<  4) // (OTGHS)  128 bytes
#define 	AT91C_OTGHS_EPT_SIZE_256                  (0x5 <<  4) // (OTGHS)  256 bytes
#define 	AT91C_OTGHS_EPT_SIZE_512                  (0x6 <<  4) // (OTGHS)  512 bytes
#define 	AT91C_OTGHS_EPT_SIZE_1024                 (0x7 <<  4) // (OTGHS) 1024 bytes
#define AT91C_OTGHS_EPT_DIR   (0x1 <<  8) // (OTGHS) Endpoint Direction 0:OUT, 1:IN
#define 	AT91C_OTGHS_EPT_DIR_OUT                  (0x0 <<  8) // (OTGHS) Direction OUT
#define 	AT91C_OTGHS_EPT_DIR_IN                   (0x1 <<  8) // (OTGHS) Direction IN
#define AT91C_OTGHS_AUTOSW    (0x1 <<  9) // (OTGHS) Automatic Switch
#define AT91C_OTGHS_EPT_TYPE  (0x3 << 11) // (OTGHS) Endpoint Type
#define 	AT91C_OTGHS_EPT_TYPE_CTL_EPT              (0x0 << 11) // (OTGHS) Control endpoint
#define 	AT91C_OTGHS_EPT_TYPE_ISO_EPT              (0x1 << 11) // (OTGHS) Isochronous endpoint
#define 	AT91C_OTGHS_EPT_TYPE_BUL_EPT              (0x2 << 11) // (OTGHS) Bulk endpoint
#define 	AT91C_OTGHS_EPT_TYPE_INT_EPT              (0x3 << 11) // (OTGHS) Interrupt endpoint
#define AT91C_OTGHS_NBTRANS   (0x1 << 13) // (OTGHS) 
#define AT91C_OTGHS_DATASIZERDWR (0x3 << 30) // (OTGHS) 
// -------- OTGHS_DEVEPTISR : (OTGHS Offset: 0x130) OTGHS Device Endpoint Interrupt Status Register -------- 
#define AT91C_OTGHS_TXINI     (0x1 <<  0) // (OTGHS) 
#define AT91C_OTGHS_RXOUT     (0x1 <<  1) // (OTGHS) 
#define AT91C_OTGHS_RXSTP     (0x1 <<  2) // (OTGHS) 
#define AT91C_OTGHS_NAKOUT    (0x1 <<  3) // (OTGHS) 
#define AT91C_OTGHS_NAKIN     (0x1 <<  4) // (OTGHS) 
#define AT91C_OTGHS_OVERFL    (0x1 <<  5) // (OTGHS) 
#define AT91C_OTGHS_STALL     (0x1 <<  6) // (OTGHS) 
#define AT91C_OTGHS_SHRTPACK  (0x1 <<  7) // (OTGHS) 
#define AT91C_OTGHS_DTSEQ     (0x3 <<  8) // (OTGHS) 
#define AT91C_OTGHS_ERRTRANS  (0x1 << 10) // (OTGHS) 
#define AT91C_OTGHS_NBUSYBK   (0x3 << 12) // (OTGHS) 
#define AT91C_OTGHS_CURRBK    (0x3 << 14) // (OTGHS) 
#define AT91C_OTGHS_RWALL     (0x1 << 16) // (OTGHS) 
#define AT91C_OTGHS_CTRLDIR   (0x1 << 17) // (OTGHS) 
#define AT91C_OTGHS_CFGOK     (0x1 << 18) // (OTGHS) 
#define AT91C_OTGHS_BYCT      (0x3FF << 20) // (OTGHS) 
// -------- OTGHS_DEVEPTICR : (OTGHS Offset: 0x160) OTGHS Device Endpoint Interrupt Clear Register -------- 
// -------- OTGHS_DEVEPTIFR : (OTGHS Offset: 0x190) OTGHS Device Endpoint Interrupt FORCE register (DEBUG only) -------- 
// -------- OTGHS_DEVEPTIMR : (OTGHS Offset: 0x1c0) OTGHS Device Endpoint Interrupt Mask Register -------- 
#define AT91C_OTGHS_MADATA    (0x1 <<  8) // (OTGHS) 
#define AT91C_OTGHS_DATAX     (0x1 <<  9) // (OTGHS) 
#define AT91C_OTGHS_KILLBK    (0x1 << 13) // (OTGHS) 
#define AT91C_OTGHS_FIFOCON   (0x1 << 14) // (OTGHS) 
#define AT91C_OTGHS_EPDISHDMA (0x1 << 16) // (OTGHS) 
#define AT91C_OTGHS_NYETDIS   (0x1 << 17) // (OTGHS) 
#define AT91C_OTGHS_RSTDT     (0x1 << 18) // (OTGHS) 
#define AT91C_OTGHS_STALLRQ   (0x1 << 19) // (OTGHS) 
// -------- OTGHS_DEVEPTIER : (OTGHS Offset: 0x1f0) OTGHS Device Endpoint Interrupt Enable Register -------- 
// -------- OTGHS_DEVEPTIDR : (OTGHS Offset: 0x220) OTGHS Device Endpoint Interrupt disable Register -------- 
// -------- OTGHS_HSTCTRL : (OTGHS Offset: 0x400) OTGHS Host Control Register -------- 
#define AT91C_OTGHS_HADDR     (0x1 <<  0) // (OTGHS) 
#define AT91C_OTGHS_SOFHST    (0x1 <<  8) // (OTGHS) 
#define AT91C_OTGHS_RESET     (0x1 <<  9) // (OTGHS) 
#define AT91C_OTGHS_RESUME    (0x1 << 10) // (OTGHS) 
#define AT91C_OTGHS_SPDCONF_HST (0x3 << 12) // (OTGHS) 
#define 	AT91C_OTGHS_SPDCONF_HST_NM                   (0x0 << 12) // (OTGHS) Normal Mode (automatic)
#define 	AT91C_OTGHS_SPDCONF_HST_HS                   (0x2 << 12) // (OTGHS) Force High Speed only (for debug or test)
#define 	AT91C_OTGHS_SPDCONF_HST_FS                   (0x3 << 12) // (OTGHS) Force Full Speed only (for debug or test)
// -------- OTGHS_HSTISR : (OTGHS Offset: 0x404) OTGHS Host Interrupt Status Register -------- 
#define AT91C_OTGHS_DCONN     (0x1 <<  0) // (OTGHS) 
#define AT91C_OTGHS_DDIS      (0x1 <<  1) // (OTGHS) 
#define AT91C_OTGHS_RSTI      (0x1 <<  2) // (OTGHS) 
#define AT91C_OTGHS_RSMEDI    (0x1 <<  3) // (OTGHS) 
#define AT91C_OTGHS_RXRSMI    (0x1 <<  4) // (OTGHS) 
#define AT91C_OTGHS_HSOFI     (0x1 <<  5) // (OTGHS) 
#define AT91C_OTGHS_HWUPI     (0x1 <<  6) // (OTGHS) 
#define AT91C_OTGHS_P0INT     (0x1 <<  8) // (OTGHS) 
#define AT91C_OTGHS_P1INT     (0x1 <<  9) // (OTGHS) 
#define AT91C_OTGHS_P2INT     (0x1 << 10) // (OTGHS) 
#define AT91C_OTGHS_P3INT     (0x1 << 11) // (OTGHS) 
#define AT91C_OTGHS_P4INT     (0x1 << 12) // (OTGHS) 
#define AT91C_OTGHS_P5INT     (0x1 << 13) // (OTGHS) 
// -------- OTGHS_HSTICR : (OTGHS Offset: 0x408) OTGHS Host Interrupt Clear register -------- 
// -------- OTGHS_HSTIFR : (OTGHS Offset: 0x40c) OTGHS Host Interrupt Force Register (for DEBUG only) -------- 
// -------- OTGHS_HSTIMR : (OTGHS Offset: 0x410) OTGHS Host Interrupt Mask Register -------- 
// -------- OTGHS_HSTIDR : (OTGHS Offset: 0x414) OTGHS Host Interrupt Disable Register -------- 
// -------- OTGHS_HSTIER : (OTGHS Offset: 0x418) OTGHS Host Interrupt Enable Register -------- 
// -------- OTGHS_HSTPIP : (OTGHS Offset: 0x41c) OTGHS Host Pipe Enable/Reset Register -------- 
// -------- OTGHS_HSTFNUM : (OTGHS Offset: 0x420) OTGHS Host Frame Number Register -------- 
#define AT91C_OTGHS_MFNUM     (0x1 <<  0) // (OTGHS) 
#define AT91C_OTGHS_FNUM      (0x1 <<  3) // (OTGHS) 
#define AT91C_OTGHS_FLENHIGH  (0x1 << 16) // (OTGHS) 
// -------- OTGHS_HSTADDR1 : (OTGHS Offset: 0x424) USB Host Frame Number Register 1 -------- 
#define AT91C_OTGHS_UHADDR_P0 (0x7F <<  0) // (OTGHS) USB Host Address Pipe 0
#define AT91C_OTGHS_UHADDR_P1 (0x7F <<  8) // (OTGHS) USB Host Address Pipe 1
#define AT91C_OTGHS_UHADDR_P2 (0x7F << 16) // (OTGHS) USB Host Address Pipe 2
#define AT91C_OTGHS_UHADDR_P3 (0x7F << 24) // (OTGHS) USB Host Address Pipe 3
// -------- OTGHS_HSTADDR2 : (OTGHS Offset: 0x428) USB Host Frame Number Register 2 -------- 
#define AT91C_OTGHS_UHADDR_P4 (0x7F <<  0) // (OTGHS) USB Host Address Pipe 4
#define AT91C_OTGHS_UHADDR_P5 (0x7F <<  8) // (OTGHS) USB Host Address Pipe 5
#define AT91C_OTGHS_UHADDR_P6 (0x7F << 16) // (OTGHS) USB Host Address Pipe 6
#define AT91C_OTGHS_UHADDR_P7 (0x7F << 24) // (OTGHS) USB Host Address Pipe 7
// -------- OTGHS_HSTADDR3 : (OTGHS Offset: 0x42c) USB Host Frame Number Register 3 -------- 
#define AT91C_OTGHS_UHADDR_P8 (0x7F <<  0) // (OTGHS) USB Host Address Pipe 8
#define AT91C_OTGHS_UHADDR_P9 (0x7F <<  8) // (OTGHS) USB Host Address Pipe 9
// -------- OTGHS_HSTPIPCFG : (OTGHS Offset: 0x500) OTGHS Host Pipe Configuration Register -------- 
#define AT91C_OTGHS_PBK       (0x3 <<  2) // (OTGHS) Pipe bank bits
#define 	AT91C_OTGHS_PBK_1                    (0x0 <<  2) // (OTGHS) One Bank (Bank0)
#define 	AT91C_OTGHS_PBK_2                    (0x1 <<  2) // (OTGHS) Double bank (Ping-Pong : Bank0 / Bank1)
#define 	AT91C_OTGHS_PBK_3                    (0x2 <<  2) // (OTGHS) Triple Bank (Bank0 / Bank1 / Bank2)
#define AT91C_OTGHS_PSIZE     (0x7 <<  4) // (OTGHS) Pipe size
#define 	AT91C_OTGHS_PSIZE_8                    (0x0 <<  4) // (OTGHS)    8 bytes
#define 	AT91C_OTGHS_PSIZE_16                   (0x1 <<  4) // (OTGHS)   16 bytes
#define 	AT91C_OTGHS_PSIZE_32                   (0x2 <<  4) // (OTGHS)   32 bytes
#define 	AT91C_OTGHS_PSIZE_64                   (0x3 <<  4) // (OTGHS)   64 bytes
#define 	AT91C_OTGHS_PSIZE_128                  (0x4 <<  4) // (OTGHS)  128 bytes
#define 	AT91C_OTGHS_PSIZE_256                  (0x5 <<  4) // (OTGHS)  256 bytes
#define 	AT91C_OTGHS_PSIZE_512                  (0x6 <<  4) // (OTGHS)  512 bytes
#define 	AT91C_OTGHS_PSIZE_1024                 (0x7 <<  4) // (OTGHS) 1024 bytes
#define AT91C_OTGHS_PTOKEN    (0x3 <<  8) // (OTGHS) Pipe Token
#define 	AT91C_OTGHS_PTOKEN_SETUP                (0x0 <<  8) // (OTGHS) Token SETUP
#define 	AT91C_OTGHS_PTOKEN_IN                   (0x1 <<  8) // (OTGHS) Token IN
#define 	AT91C_OTGHS_PTOKEN_OUT                  (0x2 <<  8) // (OTGHS) Token OUT
#define AT91C_OTGHS_ISOSW     (0x1 << 11) // (OTGHS) 
#define AT91C_OTGHS_PTYPE     (0x3 << 12) // (OTGHS) Pipe Type
#define 	AT91C_OTGHS_PTYPE_CTL_PIP              (0x0 << 12) // (OTGHS) Control pipe
#define 	AT91C_OTGHS_PTYPE_ISO_PIP              (0x1 << 12) // (OTGHS) Isochronous pipe
#define 	AT91C_OTGHS_PTYPE_BUL_PIP              (0x2 << 12) // (OTGHS) Bulk pipe
#define 	AT91C_OTGHS_PTYPE_INT_PIP              (0x3 << 12) // (OTGHS) Interrupt pipe
#define AT91C_OTGHS_PEPNUM    (0xF << 16) // (OTGHS) Pipe Endpoint Number
#define AT91C_OTGHS_PINGEN    (0x1 << 20) // (OTGHS) Ping Enable
#define AT91C_OTGHS_INTFRQ    (0xFF << 24) // (OTGHS) Pipe Interrupt Request Frequency
#define AT91C_OTGHS_BINTERVAL (0xFF << 24) // (OTGHS) bInterval parameter for the Bulk-Out/Ping transaction
// -------- OTGHS_HSTPIPISR : (OTGHS Offset: 0x530) OTGHS Host Pipe Interrupt Status Register -------- 
#define AT91C_OTGHS_RXINI     (0x1 <<  0) // (OTGHS) 
#define AT91C_OTGHS_TXOUT     (0x1 <<  1) // (OTGHS) 
#define AT91C_OTGHS_UNDER     (0x1 <<  2) // (OTGHS) 
#define AT91C_OTGHS_TXSTPI    (0x1 <<  2) // (OTGHS) 
#define AT91C_OTGHS_PERR      (0x1 <<  3) // (OTGHS) 
#define AT91C_OTGHS_NAKEDI    (0x1 <<  4) // (OTGHS) 
#define AT91C_OTGHS_CRCERR    (0x1 <<  6) // (OTGHS) 
#define AT91C_OTGHS_RXSTALL   (0x1 <<  6) // (OTGHS) 
#define AT91C_OTGHS_SHRTPCK   (0x1 <<  7) // (OTGHS) 
#define AT91C_OTGHS_PBYCT     (0x7FF << 20) // (OTGHS) 
// -------- OTGHS_HSTPIPICR : (OTGHS Offset: 0x560) OTGHS Host Pipe Interrupt Clear Register -------- 
// -------- OTGHS_HSTPIPIFR : (OTGHS Offset: 0x590) OTGHS Host Pipe Interrupt Force Register (for DEBUG only) -------- 
// -------- OTGHS_HSTPIPIMR : (OTGHS Offset: 0x5c0) OTGHS Host Pipe Interrupt Mask Register -------- 
#define AT91C_OTGHS_PDISHDMA  (0x1 << 16) // (OTGHS) 
#define AT91C_OTGHS_FREEZE    (0x1 << 17) // (OTGHS) 
// -------- OTGHS_HSTPIPIER : (OTGHS Offset: 0x5f0) OTGHS Host Pipe Interrupt Enable Register -------- 
// -------- OTGHS_HSTPIPIDR : (OTGHS Offset: 0x620) OTGHS Host Pipe Interrupt Disable Register -------- 
// -------- OTGHS_HSTPIPINRQ : (OTGHS Offset: 0x650) OTGHS Host Pipe IN Request Register -------- 
#define AT91C_OTGHS_INRQ      (0xFF <<  0) // (OTGHS) IN Request number before freeze
#define AT91C_OTGHS_INMOD     (0x1 <<  8) // (OTGHS) IN request mode
// -------- OTGHS_HSTPIPERR : (OTGHS Offset: 0x680) OTGHS Host Pipe Error Register -------- 
#define AT91C_OTGHS_DATATGL   (0x1 <<  0) // (OTGHS) Data Toggle Error
#define AT91C_OTGHS_DATAPID   (0x1 <<  1) // (OTGHS) Data PID Error
#define AT91C_OTGHS_PID       (0x1 <<  2) // (OTGHS) PID Error
#define AT91C_OTGHS_TIMEOUT   (0x1 <<  3) // (OTGHS) Time-Out Error
#define AT91C_OTGHS_CRC16     (0x1 <<  4) // (OTGHS) CRC16 Error
#define AT91C_OTGHS_COUNTER   (0x3 <<  5) // (OTGHS) Error Counter
// -------- OTGHS_CTRL : (OTGHS Offset: 0x800) OTGHS Control Register -------- 
#define AT91C_OTGHS_IDT       (0x1 <<  0) // (OTGHS) ID Transition Interrupt Enable Bit
#define AT91C_OTGHS_VBUSTI    (0x1 <<  1) // (OTGHS) VBUS Transition Interrupt Enable Bit
#define AT91C_OTGHS_SRPT      (0x1 <<  2) // (OTGHS) SRP Interrupt Enable Bit
#define AT91C_OTGHS_VBERR     (0x1 <<  3) // (OTGHS) VBus Error Interrupt Enable Bit
#define AT91C_OTGHS_BCERR     (0x1 <<  4) // (OTGHS) B-Connection Error Interrupt Enable Bit
#define AT91C_OTGHS_ROLEEX    (0x1 <<  5) // (OTGHS) Role Exchange Interrupt Enable Bit
#define AT91C_OTGHS_HNPERR    (0x1 <<  6) // (OTGHS) HNP Error Interrupt Enable Bit
#define AT91C_OTGHS_STO       (0x1 <<  7) // (OTGHS) Suspend Time-out Error Interrupt Enable Bit
#define AT91C_OTGHS_VBUSHWC   (0x1 <<  8) // (OTGHS) VBus Hardware Control Bit
#define AT91C_OTGHS_SRPSEL    (0x1 <<  9) // (OTGHS) SRP Selection Bit (for host)
#define AT91C_OTGHS_SRPREQ    (0x1 << 10) // (OTGHS) SRP Request Bit (for device)
#define AT91C_OTGHS_HNPREQ    (0x1 << 11) // (OTGHS) HNP Request Bit
#define AT91C_OTGHS_OTGPADE   (0x1 << 12) // (OTGHS) OTG Pad Enable
#define AT91C_OTGHS_VBUSPO    (0x1 << 13) // (OTGHS) VBus Polarity control
#define AT91C_OTGHS_FRZCLKCTRL (0x1 << 14) // (OTGHS) Freeze USB Clock Bit
#define AT91C_OTGHS_USBECTRL  (0x1 << 15) // (OTGHS) USB macro Enable Bit
#define AT91C_OTGHS_TIMVALUE  (0x1 << 16) // (OTGHS) Value Bit
#define AT91C_OTGHS_TIMPAGE   (0x1 << 20) // (OTGHS) Timer page access Bit
#define AT91C_OTGHS_UNLOCKTIM (0x1 << 22) // (OTGHS) OTG Timers access lock
#define AT91C_OTGHS_UIDE      (0x1 << 24) // (OTGHS) UID pin enable
#define AT91C_OTGHS_UIMOD     (0x1 << 25) // (OTGHS) USB macro Mode bit
// -------- OTGHS_SR : (OTGHS Offset: 0x804) OTGHS General Status Register -------- 
#define AT91C_OTGHS_VBUSRQ    (0x1 <<  9) // (OTGHS) VBUS Request Bit
#define AT91C_OTGHS_ID        (0x1 << 10) // (OTGHS) ID pin
#define AT91C_OTGHS_VBUSSR    (0x1 << 11) // (OTGHS) VBus Flag
#define AT91C_OTGHS_SPEED_SR  (0x3 << 12) // (OTGHS) Speed Status
#define 	AT91C_OTGHS_SPEED_SR_FS                   (0x0 << 12) // (OTGHS) FULL-SPEED mode
#define 	AT91C_OTGHS_SPEED_SR_HS                   (0x1 << 12) // (OTGHS) HIGH-SPEED mode
#define 	AT91C_OTGHS_SPEED_SR_LS                   (0x2 << 12) // (OTGHS) LOW-SPEED mode
#define AT91C_OTGHS_CLKUSABLE (0x1 << 14) // (OTGHS) UTMI clock Status
// -------- OTGHS_SCR : (OTGHS Offset: 0x808) OTGHS General Status Clear Register -------- 
#define AT91C_OTGHS_SRP       (0x1 <<  2) // (OTGHS) SRP flag
// -------- OTGHS_SFR : (OTGHS Offset: 0x80c) OTGHS General Status Force Register TEST -------- 
// -------- OTGHS_TST_A1 : (OTGHS Offset: 0x810) OTGHS Test 1 SOF Counter Register -------- 
#define AT91C_OTGHS_COUNTERA  (0x7FFF <<  0) // (OTGHS) SOF Counter Max Value
#define AT91C_OTGHS_LOADCNTA  (0x1 << 15) // (OTGHS) SOF Counter Load
#define AT91C_OTGHS_COUNTERB  (0x3F << 16) // (OTGHS) SOF Counter Max Value
#define AT91C_OTGHS_LOADCNTB  (0x1 << 23) // (OTGHS) SOF Counter Load
#define AT91C_OTGHS_SOFCNTMAX (0x7F << 24) // (OTGHS) SOF Counter Max Value
#define AT91C_OTGHS_LOADSOFCNT (0x1 << 31) // (OTGHS) SOF Counter Load
// -------- OTGHS_TST_A2 : (OTGHS Offset: 0x814) OTGHS Test 2 Register -------- 
#define AT91C_OTGHS_FULLDETACHEN (0x1 <<  0) // (OTGHS) Full Detach Enable
#define AT91C_OTGHS_HSSERIALMODE (0x1 <<  1) // (OTGHS) High-Speed serial mode
#define AT91C_OTGHS_LOOPBCKMOD (0x1 <<  2) // (OTGHS) LoopBackMode
#define AT91C_OTGHS_DISGATECLK (0x1 <<  3) // (OTGHS) Disable Gated Clock
#define AT91C_OTGHS_FSUSPTO1  (0x1 <<  4) // (OTGHS) Force SuspendM To 1 
#define AT91C_OTGHS_BYPDPLL   (0x1 <<  5) // (OTGHS) Bypass the dpll for silicon test purpose only
#define AT91C_OTGHS_HSTHSDISCDIS (0x1 <<  6) // (OTGHS) Used in Host HS mode only
#define AT91C_OTGHS_FORCHSRST (0x1 <<  7) // (OTGHS) Stretch out the Hs Reset duration in host mode
#define AT91C_OTGHS_UTMIRESET (0x1 <<  8) // (OTGHS) In host mode, set and clear this bit to reset the UTMI
// -------- OTGHS_IPVERSION : (OTGHS Offset: 0x818) OTGHS Version Register -------- 
#define AT91C_OTGHS_VERSION_NUM (0xFFFF <<  0) // (OTGHS) Give the IP version
#define AT91C_OTGHS_METAL_FIX_NUM (0x7 << 16) // (OTGHS) Give the number of metal fixes
// -------- OTGHS_IPFEATURES : (OTGHS Offset: 0x81c) OTGHS Features Register -------- 
#define AT91C_OTGHS_EPT_NBR_MAX (0xF <<  0) // (OTGHS) Max Number of Endpoints
#define AT91C_OTGHS_DMA_CHANNEL_NBR (0x7 <<  4) // (OTGHS) Number of DMA Channels
#define AT91C_OTGHS_DMA_B_SIZ (0x1 <<  7) // (OTGHS) DMA Buffer Size
#define AT91C_OTGHS_DMA_FIFO_WORD_DEPTH (0xF <<  8) // (OTGHS) DMA FIFO Depth in words
#define AT91C_OTGHS_FIFO_MAX_SIZE (0x7 << 12) // (OTGHS) DPRAM size
#define AT91C_OTGHS_BW_DPRAM  (0x1 << 15) // (OTGHS) DPRAM byte write capability
#define AT91C_OTGHS_DATAB16_8 (0x1 << 16) // (OTGHS) UTMI DataBus16_8
#define AT91C_OTGHS_ISO_EPT_1 (0x1 << 17) // (OTGHS) Endpoint 1 High Bandwidth Isochronous Capability
#define AT91C_OTGHS_ISO_EPT_2 (0x1 << 18) // (OTGHS) Endpoint 2 High Bandwidth Isochronous Capability
#define AT91C_OTGHS_ISO_EPT_3 (0x1 << 19) // (OTGHS) Endpoint 3 High Bandwidth Isochronous Capability
#define AT91C_OTGHS_ISO_EPT_4 (0x1 << 20) // (OTGHS) Endpoint 4 High Bandwidth Isochronous Capability
#define AT91C_OTGHS_ISO_EPT_5 (0x1 << 21) // (OTGHS) Endpoint 5 High Bandwidth Isochronous Capability
#define AT91C_OTGHS_ISO_EPT_6 (0x1 << 22) // (OTGHS) Endpoint 6 High Bandwidth Isochronous Capability
#define AT91C_OTGHS_ISO_EPT_7 (0x1 << 23) // (OTGHS) Endpoint 7 High Bandwidth Isochronous Capability
#define AT91C_OTGHS_ISO_EPT_8 (0x1 << 24) // (OTGHS) Endpoint 8 High Bandwidth Isochronous Capability
#define AT91C_OTGHS_ISO_EPT_9 (0x1 << 25) // (OTGHS) Endpoint 9 High Bandwidth Isochronous Capability
// -------- OTGHS_RIPPADDRSIZE : (OTGHS Offset: 0x820) OTGHS PADDRSIZE Register -------- 
#define AT91C_OTGHS_IPPADDRSIZE (0x0 <<  0) // (OTGHS) 2^OTGHSDEV_PADDR_SIZE
// -------- OTGHS_RIPNAME1 : (OTGHS Offset: 0x824) OTGHS Name Register -------- 
#define AT91C_OTGHS_IPNAME1   (0x0 <<  0) // (OTGHS) ASCII string HUSB
// -------- OTGHS_RIPNAME2 : (OTGHS Offset: 0x828) OTGHS Name Register -------- 
#define AT91C_OTGHS_IPNAME2   (0x0 <<  0) // (OTGHS) ASCII string OTG
// -------- OTGHS_FSM : (OTGHS Offset: 0x82c) OTGHS FSM Register -------- 
#define AT91C_OTGHS_FSM_STATE (0xF <<  0) // (OTGHS) ASCII string OTG
#define 	AT91C_OTGHS_FSM_STATE_A_IDLE               (0x0) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_A_WAIT_VRISE         (0x1) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_A_WAIT_BCON          (0x2) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_A_HOST               (0x3) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_A_SUSPEND            (0x4) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_A_PERIPHERAL         (0x5) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_A_WAIT_FALL          (0x6) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_A_VBUS_ERR           (0x7) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_A_WAIT_DISCHARGE     (0x8) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_B_IDLE               (0x9) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_B_PERIPHERAL         (0xA) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_B_WAIT_BEGIN_HNP     (0xB) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_B_WAIT_DISCHARGE     (0xC) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_B_WAIT_ACON          (0xD) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_B_HOST               (0xE) // (OTGHS) 
#define 	AT91C_OTGHS_FSM_STATE_SRP_INIT             (0xF) // (OTGHS) 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR True Random Generator
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_TRNG {
	AT91_REG	 TRNG_CR; 	// Control Register
	AT91_REG	 Reserved0[3]; 	// 
	AT91_REG	 TRNG_IER; 	// Interrupt Enable Register
	AT91_REG	 TRNG_IDR; 	// Interrupt Disable Register
	AT91_REG	 TRNG_IMR; 	// Interrupt Mask Register
	AT91_REG	 TRNG_ISR; 	// Interrupt Status Register
	AT91_REG	 Reserved1[12]; 	// 
	AT91_REG	 TRNG_ODATA; 	// Output Data Register
	AT91_REG	 Reserved2[42]; 	// 
	AT91_REG	 TRNG_VERSION; 	// TRNG Version Register
} AT91S_TRNG, *AT91PS_TRNG;
#else
#define TRNG_CR         (AT91_CAST(AT91_REG *) 	0x00000000) // (TRNG_CR) Control Register
#define TRNG_IER        (AT91_CAST(AT91_REG *) 	0x00000010) // (TRNG_IER) Interrupt Enable Register
#define TRNG_IDR        (AT91_CAST(AT91_REG *) 	0x00000014) // (TRNG_IDR) Interrupt Disable Register
#define TRNG_IMR        (AT91_CAST(AT91_REG *) 	0x00000018) // (TRNG_IMR) Interrupt Mask Register
#define TRNG_ISR        (AT91_CAST(AT91_REG *) 	0x0000001C) // (TRNG_ISR) Interrupt Status Register
#define TRNG_ODATA      (AT91_CAST(AT91_REG *) 	0x00000050) // (TRNG_ODATA) Output Data Register
#define TRNG_VERSION    (AT91_CAST(AT91_REG *) 	0x000000FC) // (TRNG_VERSION) TRNG Version Register

#endif
// -------- TRNG_CR : (TRNG Offset: 0x0) Control Register -------- 
#define AT91C_TRNG_ENABLE     (0x1 <<  0) // (TRNG) Enable TRNG
// -------- TRNG_IER : (TRNG Offset: 0x10) Interrupt Enable Register -------- 
#define AT91C_TRNG_DATRDY     (0x1 <<  0) // (TRNG) DATRDY
// -------- TRNG_IDR : (TRNG Offset: 0x14) Interrupt Disable Register -------- 
// -------- TRNG_IMR : (TRNG Offset: 0x18) Interrupt Mask Register -------- 
// -------- TRNG_ISR : (TRNG Offset: 0x1c) Interrupt Status Register -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Ethernet MAC 10/100
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_EMAC {
	AT91_REG	 EMAC_NCR; 	// Network Control Register
	AT91_REG	 EMAC_NCFGR; 	// Network Configuration Register
	AT91_REG	 EMAC_NSR; 	// Network Status Register
	AT91_REG	 Reserved0[2]; 	// 
	AT91_REG	 EMAC_TSR; 	// Transmit Status Register
	AT91_REG	 EMAC_RBQP; 	// Receive Buffer Queue Pointer
	AT91_REG	 EMAC_TBQP; 	// Transmit Buffer Queue Pointer
	AT91_REG	 EMAC_RSR; 	// Receive Status Register
	AT91_REG	 EMAC_ISR; 	// Interrupt Status Register
	AT91_REG	 EMAC_IER; 	// Interrupt Enable Register
	AT91_REG	 EMAC_IDR; 	// Interrupt Disable Register
	AT91_REG	 EMAC_IMR; 	// Interrupt Mask Register
	AT91_REG	 EMAC_MAN; 	// PHY Maintenance Register
	AT91_REG	 EMAC_PTR; 	// Pause Time Register
	AT91_REG	 EMAC_PFR; 	// Pause Frames received Register
	AT91_REG	 EMAC_FTO; 	// Frames Transmitted OK Register
	AT91_REG	 EMAC_SCF; 	// Single Collision Frame Register
	AT91_REG	 EMAC_MCF; 	// Multiple Collision Frame Register
	AT91_REG	 EMAC_FRO; 	// Frames Received OK Register
	AT91_REG	 EMAC_FCSE; 	// Frame Check Sequence Error Register
	AT91_REG	 EMAC_ALE; 	// Alignment Error Register
	AT91_REG	 EMAC_DTF; 	// Deferred Transmission Frame Register
	AT91_REG	 EMAC_LCOL; 	// Late Collision Register
	AT91_REG	 EMAC_ECOL; 	// Excessive Collision Register
	AT91_REG	 EMAC_TUND; 	// Transmit Underrun Error Register
	AT91_REG	 EMAC_CSE; 	// Carrier Sense Error Register
	AT91_REG	 EMAC_RRE; 	// Receive Ressource Error Register
	AT91_REG	 EMAC_ROV; 	// Receive Overrun Errors Register
	AT91_REG	 EMAC_RSE; 	// Receive Symbol Errors Register
	AT91_REG	 EMAC_ELE; 	// Excessive Length Errors Register
	AT91_REG	 EMAC_RJA; 	// Receive Jabbers Register
	AT91_REG	 EMAC_USF; 	// Undersize Frames Register
	AT91_REG	 EMAC_STE; 	// SQE Test Error Register
	AT91_REG	 EMAC_RLE; 	// Receive Length Field Mismatch Register
	AT91_REG	 EMAC_TPF; 	// Transmitted Pause Frames Register
	AT91_REG	 EMAC_HRB; 	// Hash Address Bottom[31:0]
	AT91_REG	 EMAC_HRT; 	// Hash Address Top[63:32]
	AT91_REG	 EMAC_SA1L; 	// Specific Address 1 Bottom, First 4 bytes
	AT91_REG	 EMAC_SA1H; 	// Specific Address 1 Top, Last 2 bytes
	AT91_REG	 EMAC_SA2L; 	// Specific Address 2 Bottom, First 4 bytes
	AT91_REG	 EMAC_SA2H; 	// Specific Address 2 Top, Last 2 bytes
	AT91_REG	 EMAC_SA3L; 	// Specific Address 3 Bottom, First 4 bytes
	AT91_REG	 EMAC_SA3H; 	// Specific Address 3 Top, Last 2 bytes
	AT91_REG	 EMAC_SA4L; 	// Specific Address 4 Bottom, First 4 bytes
	AT91_REG	 EMAC_SA4H; 	// Specific Address 4 Top, Last 2 bytes
	AT91_REG	 EMAC_TID; 	// Type ID Checking Register
	AT91_REG	 EMAC_TPQ; 	// Transmit Pause Quantum Register
	AT91_REG	 EMAC_USRIO; 	// USER Input/Output Register
	AT91_REG	 EMAC_WOL; 	// Wake On LAN Register
	AT91_REG	 Reserved1[13]; 	// 
	AT91_REG	 EMAC_REV; 	// Revision Register
} AT91S_EMAC, *AT91PS_EMAC;
#else
#define EMAC_NCR        (AT91_CAST(AT91_REG *) 	0x00000000) // (EMAC_NCR) Network Control Register
#define EMAC_NCFGR      (AT91_CAST(AT91_REG *) 	0x00000004) // (EMAC_NCFGR) Network Configuration Register
#define EMAC_NSR        (AT91_CAST(AT91_REG *) 	0x00000008) // (EMAC_NSR) Network Status Register
#define EMAC_TSR        (AT91_CAST(AT91_REG *) 	0x00000014) // (EMAC_TSR) Transmit Status Register
#define EMAC_RBQP       (AT91_CAST(AT91_REG *) 	0x00000018) // (EMAC_RBQP) Receive Buffer Queue Pointer
#define EMAC_TBQP       (AT91_CAST(AT91_REG *) 	0x0000001C) // (EMAC_TBQP) Transmit Buffer Queue Pointer
#define EMAC_RSR        (AT91_CAST(AT91_REG *) 	0x00000020) // (EMAC_RSR) Receive Status Register
#define EMAC_ISR        (AT91_CAST(AT91_REG *) 	0x00000024) // (EMAC_ISR) Interrupt Status Register
#define EMAC_IER        (AT91_CAST(AT91_REG *) 	0x00000028) // (EMAC_IER) Interrupt Enable Register
#define EMAC_IDR        (AT91_CAST(AT91_REG *) 	0x0000002C) // (EMAC_IDR) Interrupt Disable Register
#define EMAC_IMR        (AT91_CAST(AT91_REG *) 	0x00000030) // (EMAC_IMR) Interrupt Mask Register
#define EMAC_MAN        (AT91_CAST(AT91_REG *) 	0x00000034) // (EMAC_MAN) PHY Maintenance Register
#define EMAC_PTR        (AT91_CAST(AT91_REG *) 	0x00000038) // (EMAC_PTR) Pause Time Register
#define EMAC_PFR        (AT91_CAST(AT91_REG *) 	0x0000003C) // (EMAC_PFR) Pause Frames received Register
#define EMAC_FTO        (AT91_CAST(AT91_REG *) 	0x00000040) // (EMAC_FTO) Frames Transmitted OK Register
#define EMAC_SCF        (AT91_CAST(AT91_REG *) 	0x00000044) // (EMAC_SCF) Single Collision Frame Register
#define EMAC_MCF        (AT91_CAST(AT91_REG *) 	0x00000048) // (EMAC_MCF) Multiple Collision Frame Register
#define EMAC_FRO        (AT91_CAST(AT91_REG *) 	0x0000004C) // (EMAC_FRO) Frames Received OK Register
#define EMAC_FCSE       (AT91_CAST(AT91_REG *) 	0x00000050) // (EMAC_FCSE) Frame Check Sequence Error Register
#define EMAC_ALE        (AT91_CAST(AT91_REG *) 	0x00000054) // (EMAC_ALE) Alignment Error Register
#define EMAC_DTF        (AT91_CAST(AT91_REG *) 	0x00000058) // (EMAC_DTF) Deferred Transmission Frame Register
#define EMAC_LCOL       (AT91_CAST(AT91_REG *) 	0x0000005C) // (EMAC_LCOL) Late Collision Register
#define EMAC_ECOL       (AT91_CAST(AT91_REG *) 	0x00000060) // (EMAC_ECOL) Excessive Collision Register
#define EMAC_TUND       (AT91_CAST(AT91_REG *) 	0x00000064) // (EMAC_TUND) Transmit Underrun Error Register
#define EMAC_CSE        (AT91_CAST(AT91_REG *) 	0x00000068) // (EMAC_CSE) Carrier Sense Error Register
#define EMAC_RRE        (AT91_CAST(AT91_REG *) 	0x0000006C) // (EMAC_RRE) Receive Ressource Error Register
#define EMAC_ROV        (AT91_CAST(AT91_REG *) 	0x00000070) // (EMAC_ROV) Receive Overrun Errors Register
#define EMAC_RSE        (AT91_CAST(AT91_REG *) 	0x00000074) // (EMAC_RSE) Receive Symbol Errors Register
#define EMAC_ELE        (AT91_CAST(AT91_REG *) 	0x00000078) // (EMAC_ELE) Excessive Length Errors Register
#define EMAC_RJA        (AT91_CAST(AT91_REG *) 	0x0000007C) // (EMAC_RJA) Receive Jabbers Register
#define EMAC_USF        (AT91_CAST(AT91_REG *) 	0x00000080) // (EMAC_USF) Undersize Frames Register
#define EMAC_STE        (AT91_CAST(AT91_REG *) 	0x00000084) // (EMAC_STE) SQE Test Error Register
#define EMAC_RLE        (AT91_CAST(AT91_REG *) 	0x00000088) // (EMAC_RLE) Receive Length Field Mismatch Register
#define EMAC_TPF        (AT91_CAST(AT91_REG *) 	0x0000008C) // (EMAC_TPF) Transmitted Pause Frames Register
#define EMAC_HRB        (AT91_CAST(AT91_REG *) 	0x00000090) // (EMAC_HRB) Hash Address Bottom[31:0]
#define EMAC_HRT        (AT91_CAST(AT91_REG *) 	0x00000094) // (EMAC_HRT) Hash Address Top[63:32]
#define EMAC_SA1L       (AT91_CAST(AT91_REG *) 	0x00000098) // (EMAC_SA1L) Specific Address 1 Bottom, First 4 bytes
#define EMAC_SA1H       (AT91_CAST(AT91_REG *) 	0x0000009C) // (EMAC_SA1H) Specific Address 1 Top, Last 2 bytes
#define EMAC_SA2L       (AT91_CAST(AT91_REG *) 	0x000000A0) // (EMAC_SA2L) Specific Address 2 Bottom, First 4 bytes
#define EMAC_SA2H       (AT91_CAST(AT91_REG *) 	0x000000A4) // (EMAC_SA2H) Specific Address 2 Top, Last 2 bytes
#define EMAC_SA3L       (AT91_CAST(AT91_REG *) 	0x000000A8) // (EMAC_SA3L) Specific Address 3 Bottom, First 4 bytes
#define EMAC_SA3H       (AT91_CAST(AT91_REG *) 	0x000000AC) // (EMAC_SA3H) Specific Address 3 Top, Last 2 bytes
#define EMAC_SA4L       (AT91_CAST(AT91_REG *) 	0x000000B0) // (EMAC_SA4L) Specific Address 4 Bottom, First 4 bytes
#define EMAC_SA4H       (AT91_CAST(AT91_REG *) 	0x000000B4) // (EMAC_SA4H) Specific Address 4 Top, Last 2 bytes
#define EMAC_TID        (AT91_CAST(AT91_REG *) 	0x000000B8) // (EMAC_TID) Type ID Checking Register
#define EMAC_TPQ        (AT91_CAST(AT91_REG *) 	0x000000BC) // (EMAC_TPQ) Transmit Pause Quantum Register
#define EMAC_USRIO      (AT91_CAST(AT91_REG *) 	0x000000C0) // (EMAC_USRIO) USER Input/Output Register
#define EMAC_WOL        (AT91_CAST(AT91_REG *) 	0x000000C4) // (EMAC_WOL) Wake On LAN Register
#define EMAC_REV        (AT91_CAST(AT91_REG *) 	0x000000FC) // (EMAC_REV) Revision Register

#endif
// -------- EMAC_NCR : (EMAC Offset: 0x0)  -------- 
#define AT91C_EMAC_LB         (0x1 <<  0) // (EMAC) Loopback. Optional. When set, loopback signal is at high level.
#define AT91C_EMAC_LLB        (0x1 <<  1) // (EMAC) Loopback local. 
#define AT91C_EMAC_RE         (0x1 <<  2) // (EMAC) Receive enable. 
#define AT91C_EMAC_TE         (0x1 <<  3) // (EMAC) Transmit enable. 
#define AT91C_EMAC_MPE        (0x1 <<  4) // (EMAC) Management port enable. 
#define AT91C_EMAC_CLRSTAT    (0x1 <<  5) // (EMAC) Clear statistics registers. 
#define AT91C_EMAC_INCSTAT    (0x1 <<  6) // (EMAC) Increment statistics registers. 
#define AT91C_EMAC_WESTAT     (0x1 <<  7) // (EMAC) Write enable for statistics registers. 
#define AT91C_EMAC_BP         (0x1 <<  8) // (EMAC) Back pressure. 
#define AT91C_EMAC_TSTART     (0x1 <<  9) // (EMAC) Start Transmission. 
#define AT91C_EMAC_THALT      (0x1 << 10) // (EMAC) Transmission Halt. 
#define AT91C_EMAC_TPFR       (0x1 << 11) // (EMAC) Transmit pause frame 
#define AT91C_EMAC_TZQ        (0x1 << 12) // (EMAC) Transmit zero quantum pause frame
// -------- EMAC_NCFGR : (EMAC Offset: 0x4) Network Configuration Register -------- 
#define AT91C_EMAC_SPD        (0x1 <<  0) // (EMAC) Speed. 
#define AT91C_EMAC_FD         (0x1 <<  1) // (EMAC) Full duplex. 
#define AT91C_EMAC_JFRAME     (0x1 <<  3) // (EMAC) Jumbo Frames. 
#define AT91C_EMAC_CAF        (0x1 <<  4) // (EMAC) Copy all frames. 
#define AT91C_EMAC_NBC        (0x1 <<  5) // (EMAC) No broadcast. 
#define AT91C_EMAC_MTI        (0x1 <<  6) // (EMAC) Multicast hash event enable
#define AT91C_EMAC_UNI        (0x1 <<  7) // (EMAC) Unicast hash enable. 
#define AT91C_EMAC_BIG        (0x1 <<  8) // (EMAC) Receive 1522 bytes. 
#define AT91C_EMAC_EAE        (0x1 <<  9) // (EMAC) External address match enable. 
#define AT91C_EMAC_CLK        (0x3 << 10) // (EMAC) 
#define 	AT91C_EMAC_CLK_HCLK_8               (0x0 << 10) // (EMAC) HCLK divided by 8
#define 	AT91C_EMAC_CLK_HCLK_16              (0x1 << 10) // (EMAC) HCLK divided by 16
#define 	AT91C_EMAC_CLK_HCLK_32              (0x2 << 10) // (EMAC) HCLK divided by 32
#define 	AT91C_EMAC_CLK_HCLK_64              (0x3 << 10) // (EMAC) HCLK divided by 64
#define AT91C_EMAC_RTY        (0x1 << 12) // (EMAC) 
#define AT91C_EMAC_PAE        (0x1 << 13) // (EMAC) 
#define AT91C_EMAC_RBOF       (0x3 << 14) // (EMAC) 
#define 	AT91C_EMAC_RBOF_OFFSET_0             (0x0 << 14) // (EMAC) no offset from start of receive buffer
#define 	AT91C_EMAC_RBOF_OFFSET_1             (0x1 << 14) // (EMAC) one byte offset from start of receive buffer
#define 	AT91C_EMAC_RBOF_OFFSET_2             (0x2 << 14) // (EMAC) two bytes offset from start of receive buffer
#define 	AT91C_EMAC_RBOF_OFFSET_3             (0x3 << 14) // (EMAC) three bytes offset from start of receive buffer
#define AT91C_EMAC_RLCE       (0x1 << 16) // (EMAC) Receive Length field Checking Enable
#define AT91C_EMAC_DRFCS      (0x1 << 17) // (EMAC) Discard Receive FCS
#define AT91C_EMAC_EFRHD      (0x1 << 18) // (EMAC) 
#define AT91C_EMAC_IRXFCS     (0x1 << 19) // (EMAC) Ignore RX FCS
// -------- EMAC_NSR : (EMAC Offset: 0x8) Network Status Register -------- 
#define AT91C_EMAC_LINKR      (0x1 <<  0) // (EMAC) 
#define AT91C_EMAC_MDIO       (0x1 <<  1) // (EMAC) 
#define AT91C_EMAC_IDLE       (0x1 <<  2) // (EMAC) 
// -------- EMAC_TSR : (EMAC Offset: 0x14) Transmit Status Register -------- 
#define AT91C_EMAC_UBR        (0x1 <<  0) // (EMAC) 
#define AT91C_EMAC_COL        (0x1 <<  1) // (EMAC) 
#define AT91C_EMAC_RLES       (0x1 <<  2) // (EMAC) 
#define AT91C_EMAC_TGO        (0x1 <<  3) // (EMAC) Transmit Go
#define AT91C_EMAC_BEX        (0x1 <<  4) // (EMAC) Buffers exhausted mid frame
#define AT91C_EMAC_COMP       (0x1 <<  5) // (EMAC) 
#define AT91C_EMAC_UND        (0x1 <<  6) // (EMAC) 
// -------- EMAC_RSR : (EMAC Offset: 0x20) Receive Status Register -------- 
#define AT91C_EMAC_BNA        (0x1 <<  0) // (EMAC) 
#define AT91C_EMAC_REC        (0x1 <<  1) // (EMAC) 
#define AT91C_EMAC_OVR        (0x1 <<  2) // (EMAC) 
// -------- EMAC_ISR : (EMAC Offset: 0x24) Interrupt Status Register -------- 
#define AT91C_EMAC_MFD        (0x1 <<  0) // (EMAC) 
#define AT91C_EMAC_RCOMP      (0x1 <<  1) // (EMAC) 
#define AT91C_EMAC_RXUBR      (0x1 <<  2) // (EMAC) 
#define AT91C_EMAC_TXUBR      (0x1 <<  3) // (EMAC) 
#define AT91C_EMAC_TUNDR      (0x1 <<  4) // (EMAC) 
#define AT91C_EMAC_RLEX       (0x1 <<  5) // (EMAC) 
#define AT91C_EMAC_TXERR      (0x1 <<  6) // (EMAC) 
#define AT91C_EMAC_TCOMP      (0x1 <<  7) // (EMAC) 
#define AT91C_EMAC_LINK       (0x1 <<  9) // (EMAC) 
#define AT91C_EMAC_ROVR       (0x1 << 10) // (EMAC) 
#define AT91C_EMAC_HRESP      (0x1 << 11) // (EMAC) 
#define AT91C_EMAC_PFRE       (0x1 << 12) // (EMAC) 
#define AT91C_EMAC_PTZ        (0x1 << 13) // (EMAC) 
#define AT91C_EMAC_WOLEV      (0x1 << 14) // (EMAC) 
// -------- EMAC_IER : (EMAC Offset: 0x28) Interrupt Enable Register -------- 
// -------- EMAC_IDR : (EMAC Offset: 0x2c) Interrupt Disable Register -------- 
// -------- EMAC_IMR : (EMAC Offset: 0x30) Interrupt Mask Register -------- 
// -------- EMAC_MAN : (EMAC Offset: 0x34) PHY Maintenance Register -------- 
#define AT91C_EMAC_DATA       (0xFFFF <<  0) // (EMAC) 
#define AT91C_EMAC_CODE       (0x3 << 16) // (EMAC) 
#define AT91C_EMAC_REGA       (0x1F << 18) // (EMAC) 
#define AT91C_EMAC_PHYA       (0x1F << 23) // (EMAC) 
#define AT91C_EMAC_RW         (0x3 << 28) // (EMAC) 
#define AT91C_EMAC_SOF        (0x3 << 30) // (EMAC) 
// -------- EMAC_USRIO : (EMAC Offset: 0xc0) USER Input Output Register -------- 
#define AT91C_EMAC_RMII       (0x1 <<  0) // (EMAC) Reduce MII
#define AT91C_EMAC_CLKEN      (0x1 <<  1) // (EMAC) Clock Enable
// -------- EMAC_WOL : (EMAC Offset: 0xc4) Wake On LAN Register -------- 
#define AT91C_EMAC_IP         (0xFFFF <<  0) // (EMAC) ARP request IP address
#define AT91C_EMAC_MAG        (0x1 << 16) // (EMAC) Magic packet event enable
#define AT91C_EMAC_ARP        (0x1 << 17) // (EMAC) ARP request event enable
#define AT91C_EMAC_SA1        (0x1 << 18) // (EMAC) Specific address register 1 event enable
// -------- EMAC_REV : (EMAC Offset: 0xfc) Revision Register -------- 
#define AT91C_EMAC_REVREF     (0xFFFF <<  0) // (EMAC) 
#define AT91C_EMAC_PARTREF    (0xFFFF << 16) // (EMAC) 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Control Area Network MailBox Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_CAN_MB {
	AT91_REG	 CAN_MB_MMR; 	// MailBox Mode Register
	AT91_REG	 CAN_MB_MAM; 	// MailBox Acceptance Mask Register
	AT91_REG	 CAN_MB_MID; 	// MailBox ID Register
	AT91_REG	 CAN_MB_MFID; 	// MailBox Family ID Register
	AT91_REG	 CAN_MB_MSR; 	// MailBox Status Register
	AT91_REG	 CAN_MB_MDL; 	// MailBox Data Low Register
	AT91_REG	 CAN_MB_MDH; 	// MailBox Data High Register
	AT91_REG	 CAN_MB_MCR; 	// MailBox Control Register
} AT91S_CAN_MB, *AT91PS_CAN_MB;
#else
#define CAN_MMR         (AT91_CAST(AT91_REG *) 	0x00000000) // (CAN_MMR) MailBox Mode Register
#define CAN_MAM         (AT91_CAST(AT91_REG *) 	0x00000004) // (CAN_MAM) MailBox Acceptance Mask Register
#define CAN_MID         (AT91_CAST(AT91_REG *) 	0x00000008) // (CAN_MID) MailBox ID Register
#define CAN_MFID        (AT91_CAST(AT91_REG *) 	0x0000000C) // (CAN_MFID) MailBox Family ID Register
#define CAN_MSR         (AT91_CAST(AT91_REG *) 	0x00000010) // (CAN_MSR) MailBox Status Register
#define CAN_MDL         (AT91_CAST(AT91_REG *) 	0x00000014) // (CAN_MDL) MailBox Data Low Register
#define CAN_MDH         (AT91_CAST(AT91_REG *) 	0x00000018) // (CAN_MDH) MailBox Data High Register
#define CAN_MCR         (AT91_CAST(AT91_REG *) 	0x0000001C) // (CAN_MCR) MailBox Control Register

#endif
// -------- CAN_MMR : (CAN_MB Offset: 0x0) CAN Message Mode Register -------- 
#define AT91C_CAN_MTIMEMARK   (0xFFFF <<  0) // (CAN_MB) Mailbox Timemark
#define AT91C_CAN_PRIOR       (0xF << 16) // (CAN_MB) Mailbox Priority
#define AT91C_CAN_MOT         (0x7 << 24) // (CAN_MB) Mailbox Object Type
#define 	AT91C_CAN_MOT_DIS                  (0x0 << 24) // (CAN_MB) 
#define 	AT91C_CAN_MOT_RX                   (0x1 << 24) // (CAN_MB) 
#define 	AT91C_CAN_MOT_RXOVERWRITE          (0x2 << 24) // (CAN_MB) 
#define 	AT91C_CAN_MOT_TX                   (0x3 << 24) // (CAN_MB) 
#define 	AT91C_CAN_MOT_CONSUMER             (0x4 << 24) // (CAN_MB) 
#define 	AT91C_CAN_MOT_PRODUCER             (0x5 << 24) // (CAN_MB) 
// -------- CAN_MAM : (CAN_MB Offset: 0x4) CAN Message Acceptance Mask Register -------- 
#define AT91C_CAN_MIDvB       (0x3FFFF <<  0) // (CAN_MB) Complementary bits for identifier in extended mode
#define AT91C_CAN_MIDvA       (0x7FF << 18) // (CAN_MB) Identifier for standard frame mode
#define AT91C_CAN_MIDE        (0x1 << 29) // (CAN_MB) Identifier Version
// -------- CAN_MID : (CAN_MB Offset: 0x8) CAN Message ID Register -------- 
// -------- CAN_MFID : (CAN_MB Offset: 0xc) CAN Message Family ID Register -------- 
// -------- CAN_MSR : (CAN_MB Offset: 0x10) CAN Message Status Register -------- 
#define AT91C_CAN_MTIMESTAMP  (0xFFFF <<  0) // (CAN_MB) Timer Value
#define AT91C_CAN_MDLC        (0xF << 16) // (CAN_MB) Mailbox Data Length Code
#define AT91C_CAN_MRTR        (0x1 << 20) // (CAN_MB) Mailbox Remote Transmission Request
#define AT91C_CAN_MABT        (0x1 << 22) // (CAN_MB) Mailbox Message Abort
#define AT91C_CAN_MRDY        (0x1 << 23) // (CAN_MB) Mailbox Ready
#define AT91C_CAN_MMI         (0x1 << 24) // (CAN_MB) Mailbox Message Ignored
// -------- CAN_MDL : (CAN_MB Offset: 0x14) CAN Message Data Low Register -------- 
// -------- CAN_MDH : (CAN_MB Offset: 0x18) CAN Message Data High Register -------- 
// -------- CAN_MCR : (CAN_MB Offset: 0x1c) CAN Message Control Register -------- 
#define AT91C_CAN_MACR        (0x1 << 22) // (CAN_MB) Abort Request for Mailbox
#define AT91C_CAN_MTCR        (0x1 << 23) // (CAN_MB) Mailbox Transfer Command

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Control Area Network Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_CAN {
	AT91_REG	 CAN_MR; 	// Mode Register
	AT91_REG	 CAN_IER; 	// Interrupt Enable Register
	AT91_REG	 CAN_IDR; 	// Interrupt Disable Register
	AT91_REG	 CAN_IMR; 	// Interrupt Mask Register
	AT91_REG	 CAN_SR; 	// Status Register
	AT91_REG	 CAN_BR; 	// Baudrate Register
	AT91_REG	 CAN_TIM; 	// Timer Register
	AT91_REG	 CAN_TIMESTP; 	// Time Stamp Register
	AT91_REG	 CAN_ECR; 	// Error Counter Register
	AT91_REG	 CAN_TCR; 	// Transfer Command Register
	AT91_REG	 CAN_ACR; 	// Abort Command Register
	AT91_REG	 Reserved0[52]; 	// 
	AT91_REG	 CAN_VR; 	// Version Register
	AT91_REG	 Reserved1[64]; 	// 
	AT91S_CAN_MB	 CAN_MB0; 	// CAN Mailbox 0
	AT91S_CAN_MB	 CAN_MB1; 	// CAN Mailbox 1
	AT91S_CAN_MB	 CAN_MB2; 	// CAN Mailbox 2
	AT91S_CAN_MB	 CAN_MB3; 	// CAN Mailbox 3
	AT91S_CAN_MB	 CAN_MB4; 	// CAN Mailbox 4
	AT91S_CAN_MB	 CAN_MB5; 	// CAN Mailbox 5
	AT91S_CAN_MB	 CAN_MB6; 	// CAN Mailbox 6
	AT91S_CAN_MB	 CAN_MB7; 	// CAN Mailbox 7
	AT91S_CAN_MB	 CAN_MB8; 	// CAN Mailbox 8
	AT91S_CAN_MB	 CAN_MB9; 	// CAN Mailbox 9
	AT91S_CAN_MB	 CAN_MB10; 	// CAN Mailbox 10
	AT91S_CAN_MB	 CAN_MB11; 	// CAN Mailbox 11
	AT91S_CAN_MB	 CAN_MB12; 	// CAN Mailbox 12
	AT91S_CAN_MB	 CAN_MB13; 	// CAN Mailbox 13
	AT91S_CAN_MB	 CAN_MB14; 	// CAN Mailbox 14
	AT91S_CAN_MB	 CAN_MB15; 	// CAN Mailbox 15
} AT91S_CAN, *AT91PS_CAN;
#else
#define CAN_MR          (AT91_CAST(AT91_REG *) 	0x00000000) // (CAN_MR) Mode Register
#define CAN_IER         (AT91_CAST(AT91_REG *) 	0x00000004) // (CAN_IER) Interrupt Enable Register
#define CAN_IDR         (AT91_CAST(AT91_REG *) 	0x00000008) // (CAN_IDR) Interrupt Disable Register
#define CAN_IMR         (AT91_CAST(AT91_REG *) 	0x0000000C) // (CAN_IMR) Interrupt Mask Register
#define CAN_SR          (AT91_CAST(AT91_REG *) 	0x00000010) // (CAN_SR) Status Register
#define CAN_BR          (AT91_CAST(AT91_REG *) 	0x00000014) // (CAN_BR) Baudrate Register
#define CAN_TIM         (AT91_CAST(AT91_REG *) 	0x00000018) // (CAN_TIM) Timer Register
#define CAN_TIMESTP     (AT91_CAST(AT91_REG *) 	0x0000001C) // (CAN_TIMESTP) Time Stamp Register
#define CAN_ECR         (AT91_CAST(AT91_REG *) 	0x00000020) // (CAN_ECR) Error Counter Register
#define CAN_TCR         (AT91_CAST(AT91_REG *) 	0x00000024) // (CAN_TCR) Transfer Command Register
#define CAN_ACR         (AT91_CAST(AT91_REG *) 	0x00000028) // (CAN_ACR) Abort Command Register
#define CAN_VR          (AT91_CAST(AT91_REG *) 	0x000000FC) // (CAN_VR) Version Register

#endif
// -------- CAN_MR : (CAN Offset: 0x0) CAN Mode Register -------- 
#define AT91C_CAN_CANEN       (0x1 <<  0) // (CAN) CAN Controller Enable
#define AT91C_CAN_LPM         (0x1 <<  1) // (CAN) Disable/Enable Low Power Mode
#define AT91C_CAN_ABM         (0x1 <<  2) // (CAN) Disable/Enable Autobaud/Listen Mode
#define AT91C_CAN_OVL         (0x1 <<  3) // (CAN) Disable/Enable Overload Frame
#define AT91C_CAN_TEOF        (0x1 <<  4) // (CAN) Time Stamp messages at each end of Frame
#define AT91C_CAN_TTM         (0x1 <<  5) // (CAN) Disable/Enable Time Trigger Mode
#define AT91C_CAN_TIMFRZ      (0x1 <<  6) // (CAN) Enable Timer Freeze
#define AT91C_CAN_DRPT        (0x1 <<  7) // (CAN) Disable Repeat
// -------- CAN_IER : (CAN Offset: 0x4) CAN Interrupt Enable Register -------- 
#define AT91C_CAN_MB0         (0x1 <<  0) // (CAN) Mailbox 0 Flag
#define AT91C_CAN_MB1         (0x1 <<  1) // (CAN) Mailbox 1 Flag
#define AT91C_CAN_MB2         (0x1 <<  2) // (CAN) Mailbox 2 Flag
#define AT91C_CAN_MB3         (0x1 <<  3) // (CAN) Mailbox 3 Flag
#define AT91C_CAN_MB4         (0x1 <<  4) // (CAN) Mailbox 4 Flag
#define AT91C_CAN_MB5         (0x1 <<  5) // (CAN) Mailbox 5 Flag
#define AT91C_CAN_MB6         (0x1 <<  6) // (CAN) Mailbox 6 Flag
#define AT91C_CAN_MB7         (0x1 <<  7) // (CAN) Mailbox 7 Flag
#define AT91C_CAN_MB8         (0x1 <<  8) // (CAN) Mailbox 8 Flag
#define AT91C_CAN_MB9         (0x1 <<  9) // (CAN) Mailbox 9 Flag
#define AT91C_CAN_MB10        (0x1 << 10) // (CAN) Mailbox 10 Flag
#define AT91C_CAN_MB11        (0x1 << 11) // (CAN) Mailbox 11 Flag
#define AT91C_CAN_MB12        (0x1 << 12) // (CAN) Mailbox 12 Flag
#define AT91C_CAN_MB13        (0x1 << 13) // (CAN) Mailbox 13 Flag
#define AT91C_CAN_MB14        (0x1 << 14) // (CAN) Mailbox 14 Flag
#define AT91C_CAN_MB15        (0x1 << 15) // (CAN) Mailbox 15 Flag
#define AT91C_CAN_ERRA        (0x1 << 16) // (CAN) Error Active Mode Flag
#define AT91C_CAN_WARN        (0x1 << 17) // (CAN) Warning Limit Flag
#define AT91C_CAN_ERRP        (0x1 << 18) // (CAN) Error Passive Mode Flag
#define AT91C_CAN_BOFF        (0x1 << 19) // (CAN) Bus Off Mode Flag
#define AT91C_CAN_SLEEP       (0x1 << 20) // (CAN) Sleep Flag
#define AT91C_CAN_WAKEUP      (0x1 << 21) // (CAN) Wakeup Flag
#define AT91C_CAN_TOVF        (0x1 << 22) // (CAN) Timer Overflow Flag
#define AT91C_CAN_TSTP        (0x1 << 23) // (CAN) Timestamp Flag
#define AT91C_CAN_CERR        (0x1 << 24) // (CAN) CRC Error
#define AT91C_CAN_SERR        (0x1 << 25) // (CAN) Stuffing Error
#define AT91C_CAN_AERR        (0x1 << 26) // (CAN) Acknowledgment Error
#define AT91C_CAN_FERR        (0x1 << 27) // (CAN) Form Error
#define AT91C_CAN_BERR        (0x1 << 28) // (CAN) Bit Error
// -------- CAN_IDR : (CAN Offset: 0x8) CAN Interrupt Disable Register -------- 
// -------- CAN_IMR : (CAN Offset: 0xc) CAN Interrupt Mask Register -------- 
// -------- CAN_SR : (CAN Offset: 0x10) CAN Status Register -------- 
#define AT91C_CAN_RBSY        (0x1 << 29) // (CAN) Receiver Busy
#define AT91C_CAN_TBSY        (0x1 << 30) // (CAN) Transmitter Busy
#define AT91C_CAN_OVLY        (0x1 << 31) // (CAN) Overload Busy
// -------- CAN_BR : (CAN Offset: 0x14) CAN Baudrate Register -------- 
#define AT91C_CAN_PHASE2      (0x7 <<  0) // (CAN) Phase 2 segment
#define AT91C_CAN_PHASE1      (0x7 <<  4) // (CAN) Phase 1 segment
#define AT91C_CAN_PROPAG      (0x7 <<  8) // (CAN) Programmation time segment
#define AT91C_CAN_SYNC        (0x3 << 12) // (CAN) Re-synchronization jump width segment
#define AT91C_CAN_BRP         (0x7F << 16) // (CAN) Baudrate Prescaler
#define AT91C_CAN_SMP         (0x1 << 24) // (CAN) Sampling mode
// -------- CAN_TIM : (CAN Offset: 0x18) CAN Timer Register -------- 
#define AT91C_CAN_TIMER       (0xFFFF <<  0) // (CAN) Timer field
// -------- CAN_TIMESTP : (CAN Offset: 0x1c) CAN Timestamp Register -------- 
// -------- CAN_ECR : (CAN Offset: 0x20) CAN Error Counter Register -------- 
#define AT91C_CAN_REC         (0xFF <<  0) // (CAN) Receive Error Counter
#define AT91C_CAN_TEC         (0xFF << 16) // (CAN) Transmit Error Counter
// -------- CAN_TCR : (CAN Offset: 0x24) CAN Transfer Command Register -------- 
#define AT91C_CAN_TIMRST      (0x1 << 31) // (CAN) Timer Reset Field
// -------- CAN_ACR : (CAN Offset: 0x28) CAN Abort Command Register -------- 

// *****************************************************************************
//               REGISTER ADDRESS DEFINITION FOR AT91SAM3X
// *****************************************************************************
// ========== Register definition for SYS peripheral ========== 
#define AT91C_SYS_GPBR  (AT91_CAST(AT91_REG *) 	0x400E1A90) // (SYS) General Purpose Registers
// ========== Register definition for EBI peripheral ========== 
#define AT91C_EBI_DUMMY (AT91_CAST(AT91_REG *) 	0x400E0000) // (EBI) Dummy register - Do not use
// ========== Register definition for HSMC4_CS0 peripheral ========== 
#define AT91C_CS0_MODE  (AT91_CAST(AT91_REG *) 	0x400E0080) // (HSMC4_CS0) Mode Register
#define AT91C_CS0_PULSE (AT91_CAST(AT91_REG *) 	0x400E0074) // (HSMC4_CS0) Pulse Register
#define AT91C_CS0_CYCLE (AT91_CAST(AT91_REG *) 	0x400E0078) // (HSMC4_CS0) Cycle Register
#define AT91C_CS0_TIMINGS (AT91_CAST(AT91_REG *) 	0x400E007C) // (HSMC4_CS0) Timmings Register
#define AT91C_CS0_SETUP (AT91_CAST(AT91_REG *) 	0x400E0070) // (HSMC4_CS0) Setup Register
// ========== Register definition for HSMC4_CS1 peripheral ========== 
#define AT91C_CS1_CYCLE (AT91_CAST(AT91_REG *) 	0x400E008C) // (HSMC4_CS1) Cycle Register
#define AT91C_CS1_PULSE (AT91_CAST(AT91_REG *) 	0x400E0088) // (HSMC4_CS1) Pulse Register
#define AT91C_CS1_MODE  (AT91_CAST(AT91_REG *) 	0x400E0094) // (HSMC4_CS1) Mode Register
#define AT91C_CS1_SETUP (AT91_CAST(AT91_REG *) 	0x400E0084) // (HSMC4_CS1) Setup Register
#define AT91C_CS1_TIMINGS (AT91_CAST(AT91_REG *) 	0x400E0090) // (HSMC4_CS1) Timmings Register
// ========== Register definition for HSMC4_CS2 peripheral ========== 
#define AT91C_CS2_PULSE (AT91_CAST(AT91_REG *) 	0x400E009C) // (HSMC4_CS2) Pulse Register
#define AT91C_CS2_TIMINGS (AT91_CAST(AT91_REG *) 	0x400E00A4) // (HSMC4_CS2) Timmings Register
#define AT91C_CS2_CYCLE (AT91_CAST(AT91_REG *) 	0x400E00A0) // (HSMC4_CS2) Cycle Register
#define AT91C_CS2_MODE  (AT91_CAST(AT91_REG *) 	0x400E00A8) // (HSMC4_CS2) Mode Register
#define AT91C_CS2_SETUP (AT91_CAST(AT91_REG *) 	0x400E0098) // (HSMC4_CS2) Setup Register
// ========== Register definition for HSMC4_CS3 peripheral ========== 
#define AT91C_CS3_MODE  (AT91_CAST(AT91_REG *) 	0x400E00BC) // (HSMC4_CS3) Mode Register
#define AT91C_CS3_TIMINGS (AT91_CAST(AT91_REG *) 	0x400E00B8) // (HSMC4_CS3) Timmings Register
#define AT91C_CS3_SETUP (AT91_CAST(AT91_REG *) 	0x400E00AC) // (HSMC4_CS3) Setup Register
#define AT91C_CS3_CYCLE (AT91_CAST(AT91_REG *) 	0x400E00B4) // (HSMC4_CS3) Cycle Register
#define AT91C_CS3_PULSE (AT91_CAST(AT91_REG *) 	0x400E00B0) // (HSMC4_CS3) Pulse Register
// ========== Register definition for HSMC4_CS4 peripheral ========== 
#define AT91C_CS4_TIMINGS (AT91_CAST(AT91_REG *) 	0x400E00CC) // (HSMC4_CS4) Timmings Register
#define AT91C_CS4_SETUP (AT91_CAST(AT91_REG *) 	0x400E00C0) // (HSMC4_CS4) Setup Register
#define AT91C_CS4_PULSE (AT91_CAST(AT91_REG *) 	0x400E00C4) // (HSMC4_CS4) Pulse Register
#define AT91C_CS4_MODE  (AT91_CAST(AT91_REG *) 	0x400E00D0) // (HSMC4_CS4) Mode Register
#define AT91C_CS4_CYCLE (AT91_CAST(AT91_REG *) 	0x400E00C8) // (HSMC4_CS4) Cycle Register
// ========== Register definition for HSMC4_CS5 peripheral ========== 
#define AT91C_CS5_MODE  (AT91_CAST(AT91_REG *) 	0x400E00E4) // (HSMC4_CS5) Mode Register
#define AT91C_CS5_CYCLE (AT91_CAST(AT91_REG *) 	0x400E00DC) // (HSMC4_CS5) Cycle Register
#define AT91C_CS5_SETUP (AT91_CAST(AT91_REG *) 	0x400E00D4) // (HSMC4_CS5) Setup Register
#define AT91C_CS5_TIMINGS (AT91_CAST(AT91_REG *) 	0x400E00E0) // (HSMC4_CS5) Timmings Register
#define AT91C_CS5_PULSE (AT91_CAST(AT91_REG *) 	0x400E00D8) // (HSMC4_CS5) Pulse Register
// ========== Register definition for HSMC4_CS6 peripheral ========== 
#define AT91C_CS6_SETUP (AT91_CAST(AT91_REG *) 	0x400E00E8) // (HSMC4_CS6) Setup Register
#define AT91C_CS6_CYCLE (AT91_CAST(AT91_REG *) 	0x400E00F0) // (HSMC4_CS6) Cycle Register
#define AT91C_CS6_TIMINGS (AT91_CAST(AT91_REG *) 	0x400E00F4) // (HSMC4_CS6) Timmings Register
#define AT91C_CS6_PULSE (AT91_CAST(AT91_REG *) 	0x400E00EC) // (HSMC4_CS6) Pulse Register
#define AT91C_CS6_MODE  (AT91_CAST(AT91_REG *) 	0x400E00F8) // (HSMC4_CS6) Mode Register
// ========== Register definition for HSMC4_NFC peripheral ========== 
#define AT91C_NFC_MODE  (AT91_CAST(AT91_REG *) 	0x400E010C) // (HSMC4_NFC) Mode Register
#define AT91C_NFC_CYCLE (AT91_CAST(AT91_REG *) 	0x400E0104) // (HSMC4_NFC) Cycle Register
#define AT91C_NFC_PULSE (AT91_CAST(AT91_REG *) 	0x400E0100) // (HSMC4_NFC) Pulse Register
#define AT91C_NFC_SETUP (AT91_CAST(AT91_REG *) 	0x400E00FC) // (HSMC4_NFC) Setup Register
#define AT91C_NFC_TIMINGS (AT91_CAST(AT91_REG *) 	0x400E0108) // (HSMC4_NFC) Timmings Register
// ========== Register definition for HSMC4 peripheral ========== 
#define AT91C_HSMC4_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400E01F0) // (HSMC4) Write Protection Status Register
#define AT91C_HSMC4_ECCPR6 (AT91_CAST(AT91_REG *) 	0x400E0048) // (HSMC4) ECC Parity register 6
#define AT91C_HSMC4_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400E01EC) // (HSMC4) Write Protection Status Register
#define AT91C_HSMC4_ECCPR11 (AT91_CAST(AT91_REG *) 	0x400E005C) // (HSMC4) ECC Parity register 11
#define AT91C_HSMC4_SR  (AT91_CAST(AT91_REG *) 	0x400E0008) // (HSMC4) Status Register
#define AT91C_HSMC4_IMR (AT91_CAST(AT91_REG *) 	0x400E0014) // (HSMC4) Interrupt Mask Register
#define AT91C_HSMC4_WPSR (AT91_CAST(AT91_REG *) 	0x400E01E8) // (HSMC4) Write Protection Status Register
#define AT91C_HSMC4_BANK (AT91_CAST(AT91_REG *) 	0x400E001C) // (HSMC4) Bank Register
#define AT91C_HSMC4_ECCPR8 (AT91_CAST(AT91_REG *) 	0x400E0050) // (HSMC4) ECC Parity register 8
#define AT91C_HSMC4_WPCR (AT91_CAST(AT91_REG *) 	0x400E01E4) // (HSMC4) Write Protection Control register
#define AT91C_HSMC4_ECCPR2 (AT91_CAST(AT91_REG *) 	0x400E0038) // (HSMC4) ECC Parity register 2
#define AT91C_HSMC4_ECCPR1 (AT91_CAST(AT91_REG *) 	0x400E0030) // (HSMC4) ECC Parity register 1
#define AT91C_HSMC4_ECCSR2 (AT91_CAST(AT91_REG *) 	0x400E0034) // (HSMC4) ECC Status register 2
#define AT91C_HSMC4_OCMS (AT91_CAST(AT91_REG *) 	0x400E0110) // (HSMC4) OCMS MODE register
#define AT91C_HSMC4_ECCPR9 (AT91_CAST(AT91_REG *) 	0x400E0054) // (HSMC4) ECC Parity register 9
#define AT91C_HSMC4_DUMMY (AT91_CAST(AT91_REG *) 	0x400E0200) // (HSMC4) This rtegister was created only ti have AHB constants
#define AT91C_HSMC4_ECCPR5 (AT91_CAST(AT91_REG *) 	0x400E0044) // (HSMC4) ECC Parity register 5
#define AT91C_HSMC4_ECCCR (AT91_CAST(AT91_REG *) 	0x400E0020) // (HSMC4) ECC reset register
#define AT91C_HSMC4_KEY2 (AT91_CAST(AT91_REG *) 	0x400E0118) // (HSMC4) KEY2 Register
#define AT91C_HSMC4_IER (AT91_CAST(AT91_REG *) 	0x400E000C) // (HSMC4) Interrupt Enable Register
#define AT91C_HSMC4_ECCSR1 (AT91_CAST(AT91_REG *) 	0x400E0028) // (HSMC4) ECC Status register 1
#define AT91C_HSMC4_IDR (AT91_CAST(AT91_REG *) 	0x400E0010) // (HSMC4) Interrupt Disable Register
#define AT91C_HSMC4_ECCPR0 (AT91_CAST(AT91_REG *) 	0x400E002C) // (HSMC4) ECC Parity register 0
#define AT91C_HSMC4_FEATURES (AT91_CAST(AT91_REG *) 	0x400E01F8) // (HSMC4) Write Protection Status Register
#define AT91C_HSMC4_ECCPR7 (AT91_CAST(AT91_REG *) 	0x400E004C) // (HSMC4) ECC Parity register 7
#define AT91C_HSMC4_ECCPR12 (AT91_CAST(AT91_REG *) 	0x400E0060) // (HSMC4) ECC Parity register 12
#define AT91C_HSMC4_ECCPR10 (AT91_CAST(AT91_REG *) 	0x400E0058) // (HSMC4) ECC Parity register 10
#define AT91C_HSMC4_KEY1 (AT91_CAST(AT91_REG *) 	0x400E0114) // (HSMC4) KEY1 Register
#define AT91C_HSMC4_VER (AT91_CAST(AT91_REG *) 	0x400E01FC) // (HSMC4) HSMC4 Version Register
#define AT91C_HSMC4_Eccpr15 (AT91_CAST(AT91_REG *) 	0x400E006C) // (HSMC4) ECC Parity register 15
#define AT91C_HSMC4_ECCPR4 (AT91_CAST(AT91_REG *) 	0x400E0040) // (HSMC4) ECC Parity register 4
#define AT91C_HSMC4_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400E01F4) // (HSMC4) Write Protection Status Register
#define AT91C_HSMC4_ECCCMD (AT91_CAST(AT91_REG *) 	0x400E0024) // (HSMC4) ECC Page size register
#define AT91C_HSMC4_ADDR (AT91_CAST(AT91_REG *) 	0x400E0018) // (HSMC4) Address Cycle Zero Register
#define AT91C_HSMC4_ECCPR3 (AT91_CAST(AT91_REG *) 	0x400E003C) // (HSMC4) ECC Parity register 3
#define AT91C_HSMC4_CFG (AT91_CAST(AT91_REG *) 	0x400E0000) // (HSMC4) Configuration Register
#define AT91C_HSMC4_CTRL (AT91_CAST(AT91_REG *) 	0x400E0004) // (HSMC4) Control Register
#define AT91C_HSMC4_ECCPR13 (AT91_CAST(AT91_REG *) 	0x400E0064) // (HSMC4) ECC Parity register 13
#define AT91C_HSMC4_ECCPR14 (AT91_CAST(AT91_REG *) 	0x400E0068) // (HSMC4) ECC Parity register 14
// ========== Register definition for MATRIX peripheral ========== 
#define AT91C_MATRIX_PRAS0 (AT91_CAST(AT91_REG *) 	0x400E0480) // (MATRIX)  PRAS0 : rom
#define AT91C_MATRIX_MCFG7 (AT91_CAST(AT91_REG *) 	0x400E041C) // (MATRIX)  Master Configuration Register 7 
#define AT91C_MATRIX_MCFG0 (AT91_CAST(AT91_REG *) 	0x400E0400) // (MATRIX)  Master Configuration Register 0 : rom
#define AT91C_MATRIX_PRBS4 (AT91_CAST(AT91_REG *) 	0x400E04A4) // (MATRIX)  PRBS4 : ebi
#define AT91C_MATRIX_MRCR (AT91_CAST(AT91_REG *) 	0x400E0500) // (MATRIX)  Master Remp Control Register 
#define AT91C_MATRIX_SCFG6 (AT91_CAST(AT91_REG *) 	0x400E0458) // (MATRIX)  Slave Configuration Register 6
#define AT91C_MATRIX_PRAS6 (AT91_CAST(AT91_REG *) 	0x400E04B0) // (MATRIX)  PRAS6
#define AT91C_MATRIX_PRAS7 (AT91_CAST(AT91_REG *) 	0x400E04B8) // (MATRIX)  PRAS7
#define AT91C_MATRIX_PRAS2 (AT91_CAST(AT91_REG *) 	0x400E0490) // (MATRIX)  PRAS2 : lcdc
#define AT91C_MATRIX_MCFG1 (AT91_CAST(AT91_REG *) 	0x400E0404) // (MATRIX)  Master Configuration Register 1 ; htcm
#define AT91C_MATRIX_SCFG0 (AT91_CAST(AT91_REG *) 	0x400E0440) // (MATRIX)  Slave Configuration Register 0 : rom
#define AT91C_MATRIX_SCFG5 (AT91_CAST(AT91_REG *) 	0x400E0454) // (MATRIX)  Slave Configuration Register 5 : bridge
#define AT91C_MATRIX_MCFG8 (AT91_CAST(AT91_REG *) 	0x400E0420) // (MATRIX)  Master Configuration Register 8 
#define AT91C_MATRIX_SCFG1 (AT91_CAST(AT91_REG *) 	0x400E0444) // (MATRIX)  Slave Configuration Register 1 : htcm
#define AT91C_MATRIX_MCFG4 (AT91_CAST(AT91_REG *) 	0x400E0410) // (MATRIX)  Master Configuration Register 4 : ebi
#define AT91C_MATRIX_PRBS7 (AT91_CAST(AT91_REG *) 	0x400E04BC) // (MATRIX)  PRBS7
#define AT91C_MATRIX_PRBS6 (AT91_CAST(AT91_REG *) 	0x400E04B4) // (MATRIX)  PRBS6
#define AT91C_MATRIX_PRBS5 (AT91_CAST(AT91_REG *) 	0x400E04AC) // (MATRIX)  PRBS5 : bridge
#define AT91C_MATRIX_SCFG7 (AT91_CAST(AT91_REG *) 	0x400E045C) // (MATRIX)  Slave Configuration Register 7
#define AT91C_MATRIX_MCFG3 (AT91_CAST(AT91_REG *) 	0x400E040C) // (MATRIX)  Master Configuration Register 3 : usb_dev_hs
#define AT91C_MATRIX_PRBS1 (AT91_CAST(AT91_REG *) 	0x400E048C) // (MATRIX)  PRBS1 : htcm
#define AT91C_MATRIX_PRAS1 (AT91_CAST(AT91_REG *) 	0x400E0488) // (MATRIX)  PRAS1 : htcm
#define AT91C_MATRIX_PRBS3 (AT91_CAST(AT91_REG *) 	0x400E049C) // (MATRIX)  PRBS3 : usb_dev_hs
#define AT91C_MATRIX_MCFG6 (AT91_CAST(AT91_REG *) 	0x400E0418) // (MATRIX)  Master Configuration Register 6 
#define AT91C_MATRIX_SCFG2 (AT91_CAST(AT91_REG *) 	0x400E0448) // (MATRIX)  Slave Configuration Register 2 : lcdc
#define AT91C_MATRIX_PRAS5 (AT91_CAST(AT91_REG *) 	0x400E04A8) // (MATRIX)  PRAS5 : bridge
#define AT91C_MATRIX_MCFG2 (AT91_CAST(AT91_REG *) 	0x400E0408) // (MATRIX)  Master Configuration Register 2 : lcdc
#define AT91C_MATRIX_SCFG4 (AT91_CAST(AT91_REG *) 	0x400E0450) // (MATRIX)  Slave Configuration Register 4 ; ebi
#define AT91C_MATRIX_PRAS3 (AT91_CAST(AT91_REG *) 	0x400E0498) // (MATRIX)  PRAS3 : usb_dev_hs
#define AT91C_MATRIX_MCFG5 (AT91_CAST(AT91_REG *) 	0x400E0414) // (MATRIX)  Master Configuration Register 5 : bridge
#define AT91C_MATRIX_PRAS4 (AT91_CAST(AT91_REG *) 	0x400E04A0) // (MATRIX)  PRAS4 : ebi
#define AT91C_MATRIX_PRBS0 (AT91_CAST(AT91_REG *) 	0x400E0484) // (MATRIX)  PRBS0 : rom
#define AT91C_MATRIX_SCFG3 (AT91_CAST(AT91_REG *) 	0x400E044C) // (MATRIX)  Slave Configuration Register 3 : usb_dev_hs
#define AT91C_MATRIX_PRBS2 (AT91_CAST(AT91_REG *) 	0x400E0494) // (MATRIX)  PRBS2 : lcdc
// ========== Register definition for CCFG peripheral ========== 
#define AT91C_CCFG_EBICSA (AT91_CAST(AT91_REG *) 	0x400E0520) // (CCFG)  EBI Chip Select Assignement Register
#define AT91C_CCFG_MATRIXVERSION (AT91_CAST(AT91_REG *) 	0x400E05FC) // (CCFG)  Version Register
#define AT91C_CCFG_TCMR (AT91_CAST(AT91_REG *) 	0x400E0514) // (CCFG)  TCM configuration
#define AT91C_CCFG_UDPHS (AT91_CAST(AT91_REG *) 	0x400E051C) // (CCFG)  USB Device HS configuration
// ========== Register definition for NVIC peripheral ========== 
#define AT91C_NVIC_MMAR (AT91_CAST(AT91_REG *) 	0xE000ED34) // (NVIC) Mem Manage Address Register
#define AT91C_NVIC_STIR (AT91_CAST(AT91_REG *) 	0xE000EF00) // (NVIC) Software Trigger Interrupt Register
#define AT91C_NVIC_MMFR2 (AT91_CAST(AT91_REG *) 	0xE000ED58) // (NVIC) Memory Model Feature register2
#define AT91C_NVIC_CPUID (AT91_CAST(AT91_REG *) 	0xE000ED00) // (NVIC) CPUID Base Register
#define AT91C_NVIC_DFSR (AT91_CAST(AT91_REG *) 	0xE000ED30) // (NVIC) Debug Fault Status Register
#define AT91C_NVIC_HAND4PR (AT91_CAST(AT91_REG *) 	0xE000ED18) // (NVIC) System Handlers 4-7 Priority Register
#define AT91C_NVIC_HFSR (AT91_CAST(AT91_REG *) 	0xE000ED2C) // (NVIC) Hard Fault Status Register
#define AT91C_NVIC_PID6 (AT91_CAST(AT91_REG *) 	0xE000EFD8) // (NVIC) Peripheral identification register
#define AT91C_NVIC_PFR0 (AT91_CAST(AT91_REG *) 	0xE000ED40) // (NVIC) Processor Feature register0
#define AT91C_NVIC_VTOFFR (AT91_CAST(AT91_REG *) 	0xE000ED08) // (NVIC) Vector Table Offset Register
#define AT91C_NVIC_ISPR (AT91_CAST(AT91_REG *) 	0xE000E200) // (NVIC) Set Pending Register
#define AT91C_NVIC_PID0 (AT91_CAST(AT91_REG *) 	0xE000EFE0) // (NVIC) Peripheral identification register b7:0
#define AT91C_NVIC_PID7 (AT91_CAST(AT91_REG *) 	0xE000EFDC) // (NVIC) Peripheral identification register
#define AT91C_NVIC_STICKRVR (AT91_CAST(AT91_REG *) 	0xE000E014) // (NVIC) SysTick Reload Value Register
#define AT91C_NVIC_PID2 (AT91_CAST(AT91_REG *) 	0xE000EFE8) // (NVIC) Peripheral identification register b23:16
#define AT91C_NVIC_ISAR0 (AT91_CAST(AT91_REG *) 	0xE000ED60) // (NVIC) ISA Feature register0
#define AT91C_NVIC_SCR  (AT91_CAST(AT91_REG *) 	0xE000ED10) // (NVIC) System Control Register
#define AT91C_NVIC_PID4 (AT91_CAST(AT91_REG *) 	0xE000EFD0) // (NVIC) Peripheral identification register
#define AT91C_NVIC_ISAR2 (AT91_CAST(AT91_REG *) 	0xE000ED68) // (NVIC) ISA Feature register2
#define AT91C_NVIC_ISER (AT91_CAST(AT91_REG *) 	0xE000E100) // (NVIC) Set Enable Register
#define AT91C_NVIC_IPR  (AT91_CAST(AT91_REG *) 	0xE000E400) // (NVIC) Interrupt Mask Register
#define AT91C_NVIC_AIRCR (AT91_CAST(AT91_REG *) 	0xE000ED0C) // (NVIC) Application Interrupt/Reset Control Reg
#define AT91C_NVIC_CID2 (AT91_CAST(AT91_REG *) 	0xE000EFF8) // (NVIC) Component identification register b23:16
#define AT91C_NVIC_ICPR (AT91_CAST(AT91_REG *) 	0xE000E280) // (NVIC) Clear Pending Register
#define AT91C_NVIC_CID3 (AT91_CAST(AT91_REG *) 	0xE000EFFC) // (NVIC) Component identification register b31:24
#define AT91C_NVIC_CFSR (AT91_CAST(AT91_REG *) 	0xE000ED28) // (NVIC) Configurable Fault Status Register
#define AT91C_NVIC_AFR0 (AT91_CAST(AT91_REG *) 	0xE000ED4C) // (NVIC) Auxiliary Feature register0
#define AT91C_NVIC_ICSR (AT91_CAST(AT91_REG *) 	0xE000ED04) // (NVIC) Interrupt Control State Register
#define AT91C_NVIC_CCR  (AT91_CAST(AT91_REG *) 	0xE000ED14) // (NVIC) Configuration Control Register
#define AT91C_NVIC_CID0 (AT91_CAST(AT91_REG *) 	0xE000EFF0) // (NVIC) Component identification register b7:0
#define AT91C_NVIC_ISAR1 (AT91_CAST(AT91_REG *) 	0xE000ED64) // (NVIC) ISA Feature register1
#define AT91C_NVIC_STICKCVR (AT91_CAST(AT91_REG *) 	0xE000E018) // (NVIC) SysTick Current Value Register
#define AT91C_NVIC_STICKCSR (AT91_CAST(AT91_REG *) 	0xE000E010) // (NVIC) SysTick Control and Status Register
#define AT91C_NVIC_CID1 (AT91_CAST(AT91_REG *) 	0xE000EFF4) // (NVIC) Component identification register b15:8
#define AT91C_NVIC_DFR0 (AT91_CAST(AT91_REG *) 	0xE000ED48) // (NVIC) Debug Feature register0
#define AT91C_NVIC_MMFR3 (AT91_CAST(AT91_REG *) 	0xE000ED5C) // (NVIC) Memory Model Feature register3
#define AT91C_NVIC_MMFR0 (AT91_CAST(AT91_REG *) 	0xE000ED50) // (NVIC) Memory Model Feature register0
#define AT91C_NVIC_STICKCALVR (AT91_CAST(AT91_REG *) 	0xE000E01C) // (NVIC) SysTick Calibration Value Register
#define AT91C_NVIC_PID1 (AT91_CAST(AT91_REG *) 	0xE000EFE4) // (NVIC) Peripheral identification register b15:8
#define AT91C_NVIC_HAND12PR (AT91_CAST(AT91_REG *) 	0xE000ED20) // (NVIC) System Handlers 12-15 Priority Register
#define AT91C_NVIC_MMFR1 (AT91_CAST(AT91_REG *) 	0xE000ED54) // (NVIC) Memory Model Feature register1
#define AT91C_NVIC_AFSR (AT91_CAST(AT91_REG *) 	0xE000ED3C) // (NVIC) Auxiliary Fault Status Register
#define AT91C_NVIC_HANDCSR (AT91_CAST(AT91_REG *) 	0xE000ED24) // (NVIC) System Handler Control and State Register
#define AT91C_NVIC_ISAR4 (AT91_CAST(AT91_REG *) 	0xE000ED70) // (NVIC) ISA Feature register4
#define AT91C_NVIC_ABR  (AT91_CAST(AT91_REG *) 	0xE000E300) // (NVIC) Active Bit Register
#define AT91C_NVIC_PFR1 (AT91_CAST(AT91_REG *) 	0xE000ED44) // (NVIC) Processor Feature register1
#define AT91C_NVIC_PID5 (AT91_CAST(AT91_REG *) 	0xE000EFD4) // (NVIC) Peripheral identification register
#define AT91C_NVIC_ICTR (AT91_CAST(AT91_REG *) 	0xE000E004) // (NVIC) Interrupt Control Type Register
#define AT91C_NVIC_ICER (AT91_CAST(AT91_REG *) 	0xE000E180) // (NVIC) Clear enable Register
#define AT91C_NVIC_PID3 (AT91_CAST(AT91_REG *) 	0xE000EFEC) // (NVIC) Peripheral identification register b31:24
#define AT91C_NVIC_ISAR3 (AT91_CAST(AT91_REG *) 	0xE000ED6C) // (NVIC) ISA Feature register3
#define AT91C_NVIC_HAND8PR (AT91_CAST(AT91_REG *) 	0xE000ED1C) // (NVIC) System Handlers 8-11 Priority Register
#define AT91C_NVIC_BFAR (AT91_CAST(AT91_REG *) 	0xE000ED38) // (NVIC) Bus Fault Address Register
// ========== Register definition for CM3 peripheral ========== 
#define AT91C_CM3_SHCSR (AT91_CAST(AT91_REG *) 	0xE000ED24) // (CM3) System Handler Control and State Register
#define AT91C_CM3_CCR   (AT91_CAST(AT91_REG *) 	0xE000ED14) // (CM3) Configuration Control Register
#define AT91C_CM3_ICSR  (AT91_CAST(AT91_REG *) 	0xE000ED04) // (CM3) Interrupt Control State Register
#define AT91C_CM3_CPUID (AT91_CAST(AT91_REG *) 	0xE000ED00) // (CM3) CPU ID Base Register
#define AT91C_CM3_SCR   (AT91_CAST(AT91_REG *) 	0xE000ED10) // (CM3) System Controller Register
#define AT91C_CM3_AIRCR (AT91_CAST(AT91_REG *) 	0xE000ED0C) // (CM3) Application Interrupt and Reset Control Register
#define AT91C_CM3_SHPR  (AT91_CAST(AT91_REG *) 	0xE000ED18) // (CM3) System Handler Priority Register
#define AT91C_CM3_VTOR  (AT91_CAST(AT91_REG *) 	0xE000ED08) // (CM3) Vector Table Offset Register
// ========== Register definition for CKGR peripheral ========== 
#define AT91C_CKGR_PLLAR (AT91_CAST(AT91_REG *) 	0x400E0628) // (CKGR) PLL Register
#define AT91C_CKGR_MOR  (AT91_CAST(AT91_REG *) 	0x400E0620) // (CKGR) Main Oscillator Register
#define AT91C_CKGR_MCFR (AT91_CAST(AT91_REG *) 	0x400E0624) // (CKGR) Main Clock  Frequency Register
#define AT91C_CKGR_UCKR (AT91_CAST(AT91_REG *) 	0x400E061C) // (CKGR) UTMI Clock Configuration Register
// ========== Register definition for SUPC peripheral ========== 
#define AT91C_SUPC_MR   (AT91_CAST(AT91_REG *) 	0x400E1A18) // (SUPC) Mode Register
#define AT91C_SUPC_SR   (AT91_CAST(AT91_REG *) 	0x400E1A24) // (SUPC) Status Register
#define AT91C_SUPC_WUMR (AT91_CAST(AT91_REG *) 	0x400E1A1C) // (SUPC) Wake Up Mode Register
#define AT91C_SUPC_BOMR (AT91_CAST(AT91_REG *) 	0x400E1A14) // (SUPC) Brown Out Mode Register
#define AT91C_SUPC_WUIR (AT91_CAST(AT91_REG *) 	0x400E1A20) // (SUPC) Wake Up Inputs Register
#define AT91C_SUPC_CR   (AT91_CAST(AT91_REG *) 	0x400E1A10) // (SUPC) Control Register
#define AT91C_SUPC_FWUTR (AT91_CAST(AT91_REG *) 	0x400E1A28) // (SUPC) Flash Wake-up Timer Register
// ========== Register definition for RSTC peripheral ========== 
#define AT91C_RSTC_RSR  (AT91_CAST(AT91_REG *) 	0x400E1A04) // (RSTC) Reset Status Register
#define AT91C_RSTC_RCR  (AT91_CAST(AT91_REG *) 	0x400E1A00) // (RSTC) Reset Control Register
#define AT91C_RSTC_RMR  (AT91_CAST(AT91_REG *) 	0x400E1A08) // (RSTC) Reset Mode Register
#define AT91C_RSTC_VER  (AT91_CAST(AT91_REG *) 	0x400E1AFC) // (RSTC) Version Register
// ========== Register definition for RTC peripheral ========== 
#define AT91C_RTC_IMR   (AT91_CAST(AT91_REG *) 	0x400E1A88) // (RTC) Interrupt Mask Register
#define AT91C_RTC_IER   (AT91_CAST(AT91_REG *) 	0x400E1A80) // (RTC) Interrupt Enable Register
#define AT91C_RTC_MR    (AT91_CAST(AT91_REG *) 	0x400E1A64) // (RTC) Mode Register
#define AT91C_RTC_VER   (AT91_CAST(AT91_REG *) 	0x400E1A8C) // (RTC) Valid Entry Register
#define AT91C_RTC_SCCR  (AT91_CAST(AT91_REG *) 	0x400E1A7C) // (RTC) Status Clear Command Register
#define AT91C_RTC_IDR   (AT91_CAST(AT91_REG *) 	0x400E1A84) // (RTC) Interrupt Disable Register
#define AT91C_RTC_CR    (AT91_CAST(AT91_REG *) 	0x400E1A60) // (RTC) Control Register
#define AT91C_RTC_TIMR  (AT91_CAST(AT91_REG *) 	0x400E1A68) // (RTC) Time Register
#define AT91C_RTC_TIMALR (AT91_CAST(AT91_REG *) 	0x400E1A70) // (RTC) Time Alarm Register
#define AT91C_RTC_SR    (AT91_CAST(AT91_REG *) 	0x400E1A78) // (RTC) Status Register
#define AT91C_RTC_CALR  (AT91_CAST(AT91_REG *) 	0x400E1A6C) // (RTC) Calendar Register
#define AT91C_RTC_CALALR (AT91_CAST(AT91_REG *) 	0x400E1A74) // (RTC) Calendar Alarm Register
// ========== Register definition for RTTC peripheral ========== 
#define AT91C_RTTC_RTAR (AT91_CAST(AT91_REG *) 	0x400E1A34) // (RTTC) Real-time Alarm Register
#define AT91C_RTTC_RTVR (AT91_CAST(AT91_REG *) 	0x400E1A38) // (RTTC) Real-time Value Register
#define AT91C_RTTC_RTSR (AT91_CAST(AT91_REG *) 	0x400E1A3C) // (RTTC) Real-time Status Register
#define AT91C_RTTC_RTMR (AT91_CAST(AT91_REG *) 	0x400E1A30) // (RTTC) Real-time Mode Register
// ========== Register definition for WDTC peripheral ========== 
#define AT91C_WDTC_WDSR (AT91_CAST(AT91_REG *) 	0x400E1A58) // (WDTC) Watchdog Status Register
#define AT91C_WDTC_WDCR (AT91_CAST(AT91_REG *) 	0x400E1A50) // (WDTC) Watchdog Control Register
#define AT91C_WDTC_WDMR (AT91_CAST(AT91_REG *) 	0x400E1A54) // (WDTC) Watchdog Mode Register
// ========== Register definition for PMC peripheral ========== 
#define AT91C_PMC_SCER  (AT91_CAST(AT91_REG *) 	0x400E0600) // (PMC) System Clock Enable Register
#define AT91C_PMC_PCER1 (AT91_CAST(AT91_REG *) 	0x400E0700) // (PMC) Peripheral Clock Enable Register 32:63 PERI_ID
#define AT91C_PMC_PCKR  (AT91_CAST(AT91_REG *) 	0x400E0640) // (PMC) Programmable Clock Register
#define AT91C_PMC_IDR   (AT91_CAST(AT91_REG *) 	0x400E0664) // (PMC) Interrupt Disable Register
#define AT91C_PMC_FSPR  (AT91_CAST(AT91_REG *) 	0x400E0674) // (PMC) Fast Startup Polarity Register
#define AT91C_PMC_PCDR1 (AT91_CAST(AT91_REG *) 	0x400E0704) // (PMC) Peripheral Clock Disable Register 32:63 PERI_ID
#define AT91C_PMC_PCSR  (AT91_CAST(AT91_REG *) 	0x400E0618) // (PMC) Peripheral Clock Status Register 0:31 PERI_ID
#define AT91C_PMC_MCFR  (AT91_CAST(AT91_REG *) 	0x400E0624) // (PMC) Main Clock  Frequency Register
#define AT91C_PMC_UCKR  (AT91_CAST(AT91_REG *) 	0x400E061C) // (PMC) UTMI Clock Configuration Register
#define AT91C_PMC_PCSR1 (AT91_CAST(AT91_REG *) 	0x400E0708) // (PMC) Peripheral Clock Status Register 32:63 PERI_ID
#define AT91C_PMC_PLLAR (AT91_CAST(AT91_REG *) 	0x400E0628) // (PMC) PLL Register
#define AT91C_PMC_IMR   (AT91_CAST(AT91_REG *) 	0x400E066C) // (PMC) Interrupt Mask Register
#define AT91C_PMC_SCDR  (AT91_CAST(AT91_REG *) 	0x400E0604) // (PMC) System Clock Disable Register
#define AT91C_PMC_SCSR  (AT91_CAST(AT91_REG *) 	0x400E0608) // (PMC) System Clock Status Register
#define AT91C_PMC_MOR   (AT91_CAST(AT91_REG *) 	0x400E0620) // (PMC) Main Oscillator Register
#define AT91C_PMC_FOCR  (AT91_CAST(AT91_REG *) 	0x400E0678) // (PMC) Fault Output Clear Register
#define AT91C_PMC_PCDR  (AT91_CAST(AT91_REG *) 	0x400E0614) // (PMC) Peripheral Clock Disable Register 0:31 PERI_ID
#define AT91C_PMC_MCKR  (AT91_CAST(AT91_REG *) 	0x400E0630) // (PMC) Master Clock Register
#define AT91C_PMC_SR    (AT91_CAST(AT91_REG *) 	0x400E0668) // (PMC) Status Register
#define AT91C_PMC_FSMR  (AT91_CAST(AT91_REG *) 	0x400E0670) // (PMC) Fast Startup Mode Register
#define AT91C_PMC_PCER  (AT91_CAST(AT91_REG *) 	0x400E0610) // (PMC) Peripheral Clock Enable Register 0:31 PERI_ID
#define AT91C_PMC_IER   (AT91_CAST(AT91_REG *) 	0x400E0660) // (PMC) Interrupt Enable Register
// ========== Register definition for EFC0 peripheral ========== 
#define AT91C_EFC0_FMR  (AT91_CAST(AT91_REG *) 	0x400E0A00) // (EFC0) EFC Flash Mode Register
#define AT91C_EFC0_FVR  (AT91_CAST(AT91_REG *) 	0x400E0A14) // (EFC0) EFC Flash Version Register
#define AT91C_EFC0_FSR  (AT91_CAST(AT91_REG *) 	0x400E0A08) // (EFC0) EFC Flash Status Register
#define AT91C_EFC0_FCR  (AT91_CAST(AT91_REG *) 	0x400E0A04) // (EFC0) EFC Flash Command Register
#define AT91C_EFC0_FRR  (AT91_CAST(AT91_REG *) 	0x400E0A0C) // (EFC0) EFC Flash Result Register
// ========== Register definition for EFC1 peripheral ========== 
#define AT91C_EFC1_FCR  (AT91_CAST(AT91_REG *) 	0x400E0C04) // (EFC1) EFC Flash Command Register
#define AT91C_EFC1_FVR  (AT91_CAST(AT91_REG *) 	0x400E0C14) // (EFC1) EFC Flash Version Register
#define AT91C_EFC1_FRR  (AT91_CAST(AT91_REG *) 	0x400E0C0C) // (EFC1) EFC Flash Result Register
#define AT91C_EFC1_FSR  (AT91_CAST(AT91_REG *) 	0x400E0C08) // (EFC1) EFC Flash Status Register
#define AT91C_EFC1_FMR  (AT91_CAST(AT91_REG *) 	0x400E0C00) // (EFC1) EFC Flash Mode Register
// ========== Register definition for PDC_DBGU peripheral ========== 
#define AT91C_DBGU_RNCR (AT91_CAST(AT91_REG *) 	0x400E0914) // (PDC_DBGU) Receive Next Counter Register
#define AT91C_DBGU_RPR  (AT91_CAST(AT91_REG *) 	0x400E0900) // (PDC_DBGU) Receive Pointer Register
#define AT91C_DBGU_TNCR (AT91_CAST(AT91_REG *) 	0x400E091C) // (PDC_DBGU) Transmit Next Counter Register
#define AT91C_DBGU_TNPR (AT91_CAST(AT91_REG *) 	0x400E0918) // (PDC_DBGU) Transmit Next Pointer Register
#define AT91C_DBGU_PTSR (AT91_CAST(AT91_REG *) 	0x400E0924) // (PDC_DBGU) PDC Transfer Status Register
#define AT91C_DBGU_PTCR (AT91_CAST(AT91_REG *) 	0x400E0920) // (PDC_DBGU) PDC Transfer Control Register
#define AT91C_DBGU_RCR  (AT91_CAST(AT91_REG *) 	0x400E0904) // (PDC_DBGU) Receive Counter Register
#define AT91C_DBGU_RNPR (AT91_CAST(AT91_REG *) 	0x400E0910) // (PDC_DBGU) Receive Next Pointer Register
#define AT91C_DBGU_TPR  (AT91_CAST(AT91_REG *) 	0x400E0908) // (PDC_DBGU) Transmit Pointer Register
#define AT91C_DBGU_TCR  (AT91_CAST(AT91_REG *) 	0x400E090C) // (PDC_DBGU) Transmit Counter Register
// ========== Register definition for DBGU peripheral ========== 
#define AT91C_DBGU_RHR  (AT91_CAST(AT91_REG *) 	0x400E0818) // (DBGU) Receiver Holding Register
#define AT91C_DBGU_IMR  (AT91_CAST(AT91_REG *) 	0x400E0810) // (DBGU) Interrupt Mask Register
#define AT91C_DBGU_CR   (AT91_CAST(AT91_REG *) 	0x400E0800) // (DBGU) Control Register
#define AT91C_DBGU_EXID (AT91_CAST(AT91_REG *) 	0x400E0844) // (DBGU) Chip ID Extension Register
#define AT91C_DBGU_BRGR (AT91_CAST(AT91_REG *) 	0x400E0820) // (DBGU) Baud Rate Generator Register
#define AT91C_DBGU_FNTR (AT91_CAST(AT91_REG *) 	0x400E0848) // (DBGU) Force NTRST Register
#define AT91C_DBGU_MR   (AT91_CAST(AT91_REG *) 	0x400E0804) // (DBGU) Mode Register
#define AT91C_DBGU_IDR  (AT91_CAST(AT91_REG *) 	0x400E080C) // (DBGU) Interrupt Disable Register
#define AT91C_DBGU_IER  (AT91_CAST(AT91_REG *) 	0x400E0808) // (DBGU) Interrupt Enable Register
#define AT91C_DBGU_CIDR (AT91_CAST(AT91_REG *) 	0x400E0840) // (DBGU) Chip ID Register
#define AT91C_DBGU_CSR  (AT91_CAST(AT91_REG *) 	0x400E0814) // (DBGU) Channel Status Register
#define AT91C_DBGU_THR  (AT91_CAST(AT91_REG *) 	0x400E081C) // (DBGU) Transmitter Holding Register
// ========== Register definition for SDRAMC peripheral ========== 
#define AT91C_SDRAMC_TR (AT91_CAST(AT91_REG *) 	0x400E0204) // (SDRAMC) SDRAM Controller Refresh Timer Register
#define AT91C_SDRAMC_CR (AT91_CAST(AT91_REG *) 	0x400E0208) // (SDRAMC) SDRAM Controller Configuration Register
#define AT91C_SDRAMC_IMR (AT91_CAST(AT91_REG *) 	0x400E021C) // (SDRAMC) SDRAM Controller Interrupt Mask Register
#define AT91C_SDRAMC_LPR (AT91_CAST(AT91_REG *) 	0x400E0210) // (SDRAMC) SDRAM Controller Low Power Register
#define AT91C_SDRAMC_IER (AT91_CAST(AT91_REG *) 	0x400E0214) // (SDRAMC) SDRAM Controller Interrupt Enable Register
#define AT91C_SDRAMC_MDR (AT91_CAST(AT91_REG *) 	0x400E0224) // (SDRAMC) SDRAM Memory Device Register
#define AT91C_SDRAMC_IDR (AT91_CAST(AT91_REG *) 	0x400E0218) // (SDRAMC) SDRAM Controller Interrupt Disable Register
#define AT91C_SDRAMC_HSR (AT91_CAST(AT91_REG *) 	0x400E020C) // (SDRAMC) SDRAM Controller High Speed Register
#define AT91C_SDRAMC_ISR (AT91_CAST(AT91_REG *) 	0x400E0220) // (SDRAMC) SDRAM Controller Interrupt Mask Register
#define AT91C_SDRAMC_MR (AT91_CAST(AT91_REG *) 	0x400E0200) // (SDRAMC) SDRAM Controller Mode Register
// ========== Register definition for PIOA peripheral ========== 
#define AT91C_PIOA_KIDR (AT91_CAST(AT91_REG *) 	0x400E0F34) // (PIOA) Keypad Controller Interrupt Disable Register
#define AT91C_PIOA_OWSR (AT91_CAST(AT91_REG *) 	0x400E0EA8) // (PIOA) Output Write Status Register
#define AT91C_PIOA_PSR  (AT91_CAST(AT91_REG *) 	0x400E0E08) // (PIOA) PIO Status Register
#define AT91C_PIOA_MDER (AT91_CAST(AT91_REG *) 	0x400E0E50) // (PIOA) Multi-driver Enable Register
#define AT91C_PIOA_ODR  (AT91_CAST(AT91_REG *) 	0x400E0E14) // (PIOA) Output Disable Registerr
#define AT91C_PIOA_IDR  (AT91_CAST(AT91_REG *) 	0x400E0E44) // (PIOA) Interrupt Disable Register
#define AT91C_PIOA_AIMER (AT91_CAST(AT91_REG *) 	0x400E0EB0) // (PIOA) Additional Interrupt Modes Enable Register
#define AT91C_PIOA_DIFSR (AT91_CAST(AT91_REG *) 	0x400E0E84) // (PIOA) Debouncing Input Filter Select Register
#define AT91C_PIOA_PDR  (AT91_CAST(AT91_REG *) 	0x400E0E04) // (PIOA) PIO Disable Register
#define AT91C_PIOA_REHLSR (AT91_CAST(AT91_REG *) 	0x400E0ED4) // (PIOA) Rising Edge/ High Level Select Register
#define AT91C_PIOA_PDSR (AT91_CAST(AT91_REG *) 	0x400E0E3C) // (PIOA) Pin Data Status Register
#define AT91C_PIOA_PPUDR (AT91_CAST(AT91_REG *) 	0x400E0E60) // (PIOA) Pull-up Disable Register
#define AT91C_PIOA_LSR  (AT91_CAST(AT91_REG *) 	0x400E0EC4) // (PIOA) Level Select Register
#define AT91C_PIOA_OWDR (AT91_CAST(AT91_REG *) 	0x400E0EA4) // (PIOA) Output Write Disable Register
#define AT91C_PIOA_FELLSR (AT91_CAST(AT91_REG *) 	0x400E0ED0) // (PIOA) Falling Edge/Low Level Select Register
#define AT91C_PIOA_IFER (AT91_CAST(AT91_REG *) 	0x400E0E20) // (PIOA) Input Filter Enable Register
#define AT91C_PIOA_ABSR (AT91_CAST(AT91_REG *) 	0x400E0E70) // (PIOA) Peripheral AB Select Register
#define AT91C_PIOA_KIMR (AT91_CAST(AT91_REG *) 	0x400E0F38) // (PIOA) Keypad Controller Interrupt Mask Register
#define AT91C_PIOA_KKPR (AT91_CAST(AT91_REG *) 	0x400E0F40) // (PIOA) Keypad Controller Key Press Register
#define AT91C_PIOA_FRLHSR (AT91_CAST(AT91_REG *) 	0x400E0ED8) // (PIOA) Fall/Rise - Low/High Status Register
#define AT91C_PIOA_AIMDR (AT91_CAST(AT91_REG *) 	0x400E0EB4) // (PIOA) Additional Interrupt Modes Disables Register
#define AT91C_PIOA_SCIFSR (AT91_CAST(AT91_REG *) 	0x400E0E80) // (PIOA) System Clock Glitch Input Filter Select Register
#define AT91C_PIOA_VER  (AT91_CAST(AT91_REG *) 	0x400E0EFC) // (PIOA) PIO VERSION REGISTER 
#define AT91C_PIOA_PER  (AT91_CAST(AT91_REG *) 	0x400E0E00) // (PIOA) PIO Enable Register
#define AT91C_PIOA_ELSR (AT91_CAST(AT91_REG *) 	0x400E0EC8) // (PIOA) Edge/Level Status Register
#define AT91C_PIOA_IMR  (AT91_CAST(AT91_REG *) 	0x400E0E48) // (PIOA) Interrupt Mask Register
#define AT91C_PIOA_PPUSR (AT91_CAST(AT91_REG *) 	0x400E0E68) // (PIOA) Pull-up Status Register
#define AT91C_PIOA_SCDR (AT91_CAST(AT91_REG *) 	0x400E0E8C) // (PIOA) Slow Clock Divider Debouncing Register
#define AT91C_PIOA_KSR  (AT91_CAST(AT91_REG *) 	0x400E0F3C) // (PIOA) Keypad Controller Status Register
#define AT91C_PIOA_IFDGSR (AT91_CAST(AT91_REG *) 	0x400E0E88) // (PIOA) Glitch or Debouncing Input Filter Clock Selection Status Register
#define AT91C_PIOA_ESR  (AT91_CAST(AT91_REG *) 	0x400E0EC0) // (PIOA) Edge Select Register
#define AT91C_PIOA_ODSR (AT91_CAST(AT91_REG *) 	0x400E0E38) // (PIOA) Output Data Status Register
#define AT91C_PIOA_IFDR (AT91_CAST(AT91_REG *) 	0x400E0E24) // (PIOA) Input Filter Disable Register
#define AT91C_PIOA_SODR (AT91_CAST(AT91_REG *) 	0x400E0E30) // (PIOA) Set Output Data Register
#define AT91C_PIOA_IER  (AT91_CAST(AT91_REG *) 	0x400E0E40) // (PIOA) Interrupt Enable Register
#define AT91C_PIOA_MDSR (AT91_CAST(AT91_REG *) 	0x400E0E58) // (PIOA) Multi-driver Status Register
#define AT91C_PIOA_ISR  (AT91_CAST(AT91_REG *) 	0x400E0E4C) // (PIOA) Interrupt Status Register
#define AT91C_PIOA_IFSR (AT91_CAST(AT91_REG *) 	0x400E0E28) // (PIOA) Input Filter Status Register
#define AT91C_PIOA_KER  (AT91_CAST(AT91_REG *) 	0x400E0F20) // (PIOA) Keypad Controller Enable Register
#define AT91C_PIOA_KKRR (AT91_CAST(AT91_REG *) 	0x400E0F44) // (PIOA) Keypad Controller Key Release Register
#define AT91C_PIOA_PPUER (AT91_CAST(AT91_REG *) 	0x400E0E64) // (PIOA) Pull-up Enable Register
#define AT91C_PIOA_LOCKSR (AT91_CAST(AT91_REG *) 	0x400E0EE0) // (PIOA) Lock Status Register
#define AT91C_PIOA_OWER (AT91_CAST(AT91_REG *) 	0x400E0EA0) // (PIOA) Output Write Enable Register
#define AT91C_PIOA_KIER (AT91_CAST(AT91_REG *) 	0x400E0F30) // (PIOA) Keypad Controller Interrupt Enable Register
#define AT91C_PIOA_MDDR (AT91_CAST(AT91_REG *) 	0x400E0E54) // (PIOA) Multi-driver Disable Register
#define AT91C_PIOA_KRCR (AT91_CAST(AT91_REG *) 	0x400E0F24) // (PIOA) Keypad Controller Row Column Register
#define AT91C_PIOA_CODR (AT91_CAST(AT91_REG *) 	0x400E0E34) // (PIOA) Clear Output Data Register
#define AT91C_PIOA_KDR  (AT91_CAST(AT91_REG *) 	0x400E0F28) // (PIOA) Keypad Controller Debouncing Register
#define AT91C_PIOA_AIMMR (AT91_CAST(AT91_REG *) 	0x400E0EB8) // (PIOA) Additional Interrupt Modes Mask Register
#define AT91C_PIOA_OER  (AT91_CAST(AT91_REG *) 	0x400E0E10) // (PIOA) Output Enable Register
#define AT91C_PIOA_OSR  (AT91_CAST(AT91_REG *) 	0x400E0E18) // (PIOA) Output Status Register
// ========== Register definition for PIOB peripheral ========== 
#define AT91C_PIOB_FELLSR (AT91_CAST(AT91_REG *) 	0x400E10D0) // (PIOB) Falling Edge/Low Level Select Register
#define AT91C_PIOB_FRLHSR (AT91_CAST(AT91_REG *) 	0x400E10D8) // (PIOB) Fall/Rise - Low/High Status Register
#define AT91C_PIOB_MDDR (AT91_CAST(AT91_REG *) 	0x400E1054) // (PIOB) Multi-driver Disable Register
#define AT91C_PIOB_IFDGSR (AT91_CAST(AT91_REG *) 	0x400E1088) // (PIOB) Glitch or Debouncing Input Filter Clock Selection Status Register
#define AT91C_PIOB_ABSR (AT91_CAST(AT91_REG *) 	0x400E1070) // (PIOB) Peripheral AB Select Register
#define AT91C_PIOB_KIMR (AT91_CAST(AT91_REG *) 	0x400E1138) // (PIOB) Keypad Controller Interrupt Mask Register
#define AT91C_PIOB_KRCR (AT91_CAST(AT91_REG *) 	0x400E1124) // (PIOB) Keypad Controller Row Column Register
#define AT91C_PIOB_ODSR (AT91_CAST(AT91_REG *) 	0x400E1038) // (PIOB) Output Data Status Register
#define AT91C_PIOB_OSR  (AT91_CAST(AT91_REG *) 	0x400E1018) // (PIOB) Output Status Register
#define AT91C_PIOB_IFER (AT91_CAST(AT91_REG *) 	0x400E1020) // (PIOB) Input Filter Enable Register
#define AT91C_PIOB_KKPR (AT91_CAST(AT91_REG *) 	0x400E1140) // (PIOB) Keypad Controller Key Press Register
#define AT91C_PIOB_MDSR (AT91_CAST(AT91_REG *) 	0x400E1058) // (PIOB) Multi-driver Status Register
#define AT91C_PIOB_IFDR (AT91_CAST(AT91_REG *) 	0x400E1024) // (PIOB) Input Filter Disable Register
#define AT91C_PIOB_MDER (AT91_CAST(AT91_REG *) 	0x400E1050) // (PIOB) Multi-driver Enable Register
#define AT91C_PIOB_SCDR (AT91_CAST(AT91_REG *) 	0x400E108C) // (PIOB) Slow Clock Divider Debouncing Register
#define AT91C_PIOB_SCIFSR (AT91_CAST(AT91_REG *) 	0x400E1080) // (PIOB) System Clock Glitch Input Filter Select Register
#define AT91C_PIOB_IER  (AT91_CAST(AT91_REG *) 	0x400E1040) // (PIOB) Interrupt Enable Register
#define AT91C_PIOB_KDR  (AT91_CAST(AT91_REG *) 	0x400E1128) // (PIOB) Keypad Controller Debouncing Register
#define AT91C_PIOB_OWDR (AT91_CAST(AT91_REG *) 	0x400E10A4) // (PIOB) Output Write Disable Register
#define AT91C_PIOB_IFSR (AT91_CAST(AT91_REG *) 	0x400E1028) // (PIOB) Input Filter Status Register
#define AT91C_PIOB_ISR  (AT91_CAST(AT91_REG *) 	0x400E104C) // (PIOB) Interrupt Status Register
#define AT91C_PIOB_PPUDR (AT91_CAST(AT91_REG *) 	0x400E1060) // (PIOB) Pull-up Disable Register
#define AT91C_PIOB_PDSR (AT91_CAST(AT91_REG *) 	0x400E103C) // (PIOB) Pin Data Status Register
#define AT91C_PIOB_KKRR (AT91_CAST(AT91_REG *) 	0x400E1144) // (PIOB) Keypad Controller Key Release Register
#define AT91C_PIOB_AIMDR (AT91_CAST(AT91_REG *) 	0x400E10B4) // (PIOB) Additional Interrupt Modes Disables Register
#define AT91C_PIOB_LSR  (AT91_CAST(AT91_REG *) 	0x400E10C4) // (PIOB) Level Select Register
#define AT91C_PIOB_PPUER (AT91_CAST(AT91_REG *) 	0x400E1064) // (PIOB) Pull-up Enable Register
#define AT91C_PIOB_AIMER (AT91_CAST(AT91_REG *) 	0x400E10B0) // (PIOB) Additional Interrupt Modes Enable Register
#define AT91C_PIOB_OER  (AT91_CAST(AT91_REG *) 	0x400E1010) // (PIOB) Output Enable Register
#define AT91C_PIOB_CODR (AT91_CAST(AT91_REG *) 	0x400E1034) // (PIOB) Clear Output Data Register
#define AT91C_PIOB_AIMMR (AT91_CAST(AT91_REG *) 	0x400E10B8) // (PIOB) Additional Interrupt Modes Mask Register
#define AT91C_PIOB_OWER (AT91_CAST(AT91_REG *) 	0x400E10A0) // (PIOB) Output Write Enable Register
#define AT91C_PIOB_VER  (AT91_CAST(AT91_REG *) 	0x400E10FC) // (PIOB) PIO VERSION REGISTER 
#define AT91C_PIOB_IMR  (AT91_CAST(AT91_REG *) 	0x400E1048) // (PIOB) Interrupt Mask Register
#define AT91C_PIOB_PPUSR (AT91_CAST(AT91_REG *) 	0x400E1068) // (PIOB) Pull-up Status Register
#define AT91C_PIOB_IDR  (AT91_CAST(AT91_REG *) 	0x400E1044) // (PIOB) Interrupt Disable Register
#define AT91C_PIOB_DIFSR (AT91_CAST(AT91_REG *) 	0x400E1084) // (PIOB) Debouncing Input Filter Select Register
#define AT91C_PIOB_KIDR (AT91_CAST(AT91_REG *) 	0x400E1134) // (PIOB) Keypad Controller Interrupt Disable Register
#define AT91C_PIOB_KSR  (AT91_CAST(AT91_REG *) 	0x400E113C) // (PIOB) Keypad Controller Status Register
#define AT91C_PIOB_REHLSR (AT91_CAST(AT91_REG *) 	0x400E10D4) // (PIOB) Rising Edge/ High Level Select Register
#define AT91C_PIOB_ESR  (AT91_CAST(AT91_REG *) 	0x400E10C0) // (PIOB) Edge Select Register
#define AT91C_PIOB_KIER (AT91_CAST(AT91_REG *) 	0x400E1130) // (PIOB) Keypad Controller Interrupt Enable Register
#define AT91C_PIOB_ELSR (AT91_CAST(AT91_REG *) 	0x400E10C8) // (PIOB) Edge/Level Status Register
#define AT91C_PIOB_SODR (AT91_CAST(AT91_REG *) 	0x400E1030) // (PIOB) Set Output Data Register
#define AT91C_PIOB_PSR  (AT91_CAST(AT91_REG *) 	0x400E1008) // (PIOB) PIO Status Register
#define AT91C_PIOB_KER  (AT91_CAST(AT91_REG *) 	0x400E1120) // (PIOB) Keypad Controller Enable Register
#define AT91C_PIOB_ODR  (AT91_CAST(AT91_REG *) 	0x400E1014) // (PIOB) Output Disable Registerr
#define AT91C_PIOB_OWSR (AT91_CAST(AT91_REG *) 	0x400E10A8) // (PIOB) Output Write Status Register
#define AT91C_PIOB_PDR  (AT91_CAST(AT91_REG *) 	0x400E1004) // (PIOB) PIO Disable Register
#define AT91C_PIOB_LOCKSR (AT91_CAST(AT91_REG *) 	0x400E10E0) // (PIOB) Lock Status Register
#define AT91C_PIOB_PER  (AT91_CAST(AT91_REG *) 	0x400E1000) // (PIOB) PIO Enable Register
// ========== Register definition for PIOC peripheral ========== 
#define AT91C_PIOC_VER  (AT91_CAST(AT91_REG *) 	0x400E12FC) // (PIOC) PIO VERSION REGISTER 
#define AT91C_PIOC_IMR  (AT91_CAST(AT91_REG *) 	0x400E1248) // (PIOC) Interrupt Mask Register
#define AT91C_PIOC_PSR  (AT91_CAST(AT91_REG *) 	0x400E1208) // (PIOC) PIO Status Register
#define AT91C_PIOC_OER  (AT91_CAST(AT91_REG *) 	0x400E1210) // (PIOC) Output Enable Register
#define AT91C_PIOC_LSR  (AT91_CAST(AT91_REG *) 	0x400E12C4) // (PIOC) Level Select Register
#define AT91C_PIOC_OSR  (AT91_CAST(AT91_REG *) 	0x400E1218) // (PIOC) Output Status Register
#define AT91C_PIOC_MDDR (AT91_CAST(AT91_REG *) 	0x400E1254) // (PIOC) Multi-driver Disable Register
#define AT91C_PIOC_KER  (AT91_CAST(AT91_REG *) 	0x400E1320) // (PIOC) Keypad Controller Enable Register
#define AT91C_PIOC_PPUSR (AT91_CAST(AT91_REG *) 	0x400E1268) // (PIOC) Pull-up Status Register
#define AT91C_PIOC_KKPR (AT91_CAST(AT91_REG *) 	0x400E1340) // (PIOC) Keypad Controller Key Press Register
#define AT91C_PIOC_ODSR (AT91_CAST(AT91_REG *) 	0x400E1238) // (PIOC) Output Data Status Register
#define AT91C_PIOC_SCDR (AT91_CAST(AT91_REG *) 	0x400E128C) // (PIOC) Slow Clock Divider Debouncing Register
#define AT91C_PIOC_AIMMR (AT91_CAST(AT91_REG *) 	0x400E12B8) // (PIOC) Additional Interrupt Modes Mask Register
#define AT91C_PIOC_AIMER (AT91_CAST(AT91_REG *) 	0x400E12B0) // (PIOC) Additional Interrupt Modes Enable Register
#define AT91C_PIOC_SCIFSR (AT91_CAST(AT91_REG *) 	0x400E1280) // (PIOC) System Clock Glitch Input Filter Select Register
#define AT91C_PIOC_LOCKSR (AT91_CAST(AT91_REG *) 	0x400E12E0) // (PIOC) Lock Status Register
#define AT91C_PIOC_IFER (AT91_CAST(AT91_REG *) 	0x400E1220) // (PIOC) Input Filter Enable Register
#define AT91C_PIOC_KRCR (AT91_CAST(AT91_REG *) 	0x400E1324) // (PIOC) Keypad Controller Row Column Register
#define AT91C_PIOC_ESR  (AT91_CAST(AT91_REG *) 	0x400E12C0) // (PIOC) Edge Select Register
#define AT91C_PIOC_PDR  (AT91_CAST(AT91_REG *) 	0x400E1204) // (PIOC) PIO Disable Register
#define AT91C_PIOC_KKRR (AT91_CAST(AT91_REG *) 	0x400E1344) // (PIOC) Keypad Controller Key Release Register
#define AT91C_PIOC_MDER (AT91_CAST(AT91_REG *) 	0x400E1250) // (PIOC) Multi-driver Enable Register
#define AT91C_PIOC_KIER (AT91_CAST(AT91_REG *) 	0x400E1330) // (PIOC) Keypad Controller Interrupt Enable Register
#define AT91C_PIOC_KIDR (AT91_CAST(AT91_REG *) 	0x400E1334) // (PIOC) Keypad Controller Interrupt Disable Register
#define AT91C_PIOC_DIFSR (AT91_CAST(AT91_REG *) 	0x400E1284) // (PIOC) Debouncing Input Filter Select Register
#define AT91C_PIOC_IER  (AT91_CAST(AT91_REG *) 	0x400E1240) // (PIOC) Interrupt Enable Register
#define AT91C_PIOC_AIMDR (AT91_CAST(AT91_REG *) 	0x400E12B4) // (PIOC) Additional Interrupt Modes Disables Register
#define AT91C_PIOC_OWDR (AT91_CAST(AT91_REG *) 	0x400E12A4) // (PIOC) Output Write Disable Register
#define AT91C_PIOC_IDR  (AT91_CAST(AT91_REG *) 	0x400E1244) // (PIOC) Interrupt Disable Register
#define AT91C_PIOC_PDSR (AT91_CAST(AT91_REG *) 	0x400E123C) // (PIOC) Pin Data Status Register
#define AT91C_PIOC_KDR  (AT91_CAST(AT91_REG *) 	0x400E1328) // (PIOC) Keypad Controller Debouncing Register
#define AT91C_PIOC_FELLSR (AT91_CAST(AT91_REG *) 	0x400E12D0) // (PIOC) Falling Edge/Low Level Select Register
#define AT91C_PIOC_PER  (AT91_CAST(AT91_REG *) 	0x400E1200) // (PIOC) PIO Enable Register
#define AT91C_PIOC_REHLSR (AT91_CAST(AT91_REG *) 	0x400E12D4) // (PIOC) Rising Edge/ High Level Select Register
#define AT91C_PIOC_FRLHSR (AT91_CAST(AT91_REG *) 	0x400E12D8) // (PIOC) Fall/Rise - Low/High Status Register
#define AT91C_PIOC_IFDR (AT91_CAST(AT91_REG *) 	0x400E1224) // (PIOC) Input Filter Disable Register
#define AT91C_PIOC_ODR  (AT91_CAST(AT91_REG *) 	0x400E1214) // (PIOC) Output Disable Registerr
#define AT91C_PIOC_IFDGSR (AT91_CAST(AT91_REG *) 	0x400E1288) // (PIOC) Glitch or Debouncing Input Filter Clock Selection Status Register
#define AT91C_PIOC_CODR (AT91_CAST(AT91_REG *) 	0x400E1234) // (PIOC) Clear Output Data Register
#define AT91C_PIOC_MDSR (AT91_CAST(AT91_REG *) 	0x400E1258) // (PIOC) Multi-driver Status Register
#define AT91C_PIOC_KIMR (AT91_CAST(AT91_REG *) 	0x400E1338) // (PIOC) Keypad Controller Interrupt Mask Register
#define AT91C_PIOC_IFSR (AT91_CAST(AT91_REG *) 	0x400E1228) // (PIOC) Input Filter Status Register
#define AT91C_PIOC_ELSR (AT91_CAST(AT91_REG *) 	0x400E12C8) // (PIOC) Edge/Level Status Register
#define AT91C_PIOC_PPUER (AT91_CAST(AT91_REG *) 	0x400E1264) // (PIOC) Pull-up Enable Register
#define AT91C_PIOC_OWSR (AT91_CAST(AT91_REG *) 	0x400E12A8) // (PIOC) Output Write Status Register
#define AT91C_PIOC_ISR  (AT91_CAST(AT91_REG *) 	0x400E124C) // (PIOC) Interrupt Status Register
#define AT91C_PIOC_OWER (AT91_CAST(AT91_REG *) 	0x400E12A0) // (PIOC) Output Write Enable Register
#define AT91C_PIOC_PPUDR (AT91_CAST(AT91_REG *) 	0x400E1260) // (PIOC) Pull-up Disable Register
#define AT91C_PIOC_KSR  (AT91_CAST(AT91_REG *) 	0x400E133C) // (PIOC) Keypad Controller Status Register
#define AT91C_PIOC_SODR (AT91_CAST(AT91_REG *) 	0x400E1230) // (PIOC) Set Output Data Register
#define AT91C_PIOC_ABSR (AT91_CAST(AT91_REG *) 	0x400E1270) // (PIOC) Peripheral AB Select Register
// ========== Register definition for PIOD peripheral ========== 
#define AT91C_PIOD_KKRR (AT91_CAST(AT91_REG *) 	0x400E1544) // (PIOD) Keypad Controller Key Release Register
#define AT91C_PIOD_OER  (AT91_CAST(AT91_REG *) 	0x400E1410) // (PIOD) Output Enable Register
#define AT91C_PIOD_VER  (AT91_CAST(AT91_REG *) 	0x400E14FC) // (PIOD) PIO VERSION REGISTER 
#define AT91C_PIOD_ODR  (AT91_CAST(AT91_REG *) 	0x400E1414) // (PIOD) Output Disable Registerr
#define AT91C_PIOD_IFDR (AT91_CAST(AT91_REG *) 	0x400E1424) // (PIOD) Input Filter Disable Register
#define AT91C_PIOD_KIMR (AT91_CAST(AT91_REG *) 	0x400E1538) // (PIOD) Keypad Controller Interrupt Mask Register
#define AT91C_PIOD_FRLHSR (AT91_CAST(AT91_REG *) 	0x400E14D8) // (PIOD) Fall/Rise - Low/High Status Register
#define AT91C_PIOD_PPUDR (AT91_CAST(AT91_REG *) 	0x400E1460) // (PIOD) Pull-up Disable Register
#define AT91C_PIOD_CODR (AT91_CAST(AT91_REG *) 	0x400E1434) // (PIOD) Clear Output Data Register
#define AT91C_PIOD_AIMER (AT91_CAST(AT91_REG *) 	0x400E14B0) // (PIOD) Additional Interrupt Modes Enable Register
#define AT91C_PIOD_DIFSR (AT91_CAST(AT91_REG *) 	0x400E1484) // (PIOD) Debouncing Input Filter Select Register
#define AT91C_PIOD_ISR  (AT91_CAST(AT91_REG *) 	0x400E144C) // (PIOD) Interrupt Status Register
#define AT91C_PIOD_KSR  (AT91_CAST(AT91_REG *) 	0x400E153C) // (PIOD) Keypad Controller Status Register
#define AT91C_PIOD_SCDR (AT91_CAST(AT91_REG *) 	0x400E148C) // (PIOD) Slow Clock Divider Debouncing Register
#define AT91C_PIOD_IMR  (AT91_CAST(AT91_REG *) 	0x400E1448) // (PIOD) Interrupt Mask Register
#define AT91C_PIOD_LOCKSR (AT91_CAST(AT91_REG *) 	0x400E14E0) // (PIOD) Lock Status Register
#define AT91C_PIOD_KDR  (AT91_CAST(AT91_REG *) 	0x400E1528) // (PIOD) Keypad Controller Debouncing Register
#define AT91C_PIOD_AIMDR (AT91_CAST(AT91_REG *) 	0x400E14B4) // (PIOD) Additional Interrupt Modes Disables Register
#define AT91C_PIOD_SODR (AT91_CAST(AT91_REG *) 	0x400E1430) // (PIOD) Set Output Data Register
#define AT91C_PIOD_PPUER (AT91_CAST(AT91_REG *) 	0x400E1464) // (PIOD) Pull-up Enable Register
#define AT91C_PIOD_KIER (AT91_CAST(AT91_REG *) 	0x400E1530) // (PIOD) Keypad Controller Interrupt Enable Register
#define AT91C_PIOD_IFER (AT91_CAST(AT91_REG *) 	0x400E1420) // (PIOD) Input Filter Enable Register
#define AT91C_PIOD_OSR  (AT91_CAST(AT91_REG *) 	0x400E1418) // (PIOD) Output Status Register
#define AT91C_PIOD_AIMMR (AT91_CAST(AT91_REG *) 	0x400E14B8) // (PIOD) Additional Interrupt Modes Mask Register
#define AT91C_PIOD_REHLSR (AT91_CAST(AT91_REG *) 	0x400E14D4) // (PIOD) Rising Edge/ High Level Select Register
#define AT91C_PIOD_OWDR (AT91_CAST(AT91_REG *) 	0x400E14A4) // (PIOD) Output Write Disable Register
#define AT91C_PIOD_PDSR (AT91_CAST(AT91_REG *) 	0x400E143C) // (PIOD) Pin Data Status Register
#define AT91C_PIOD_KRCR (AT91_CAST(AT91_REG *) 	0x400E1524) // (PIOD) Keypad Controller Row Column Register
#define AT91C_PIOD_ODSR (AT91_CAST(AT91_REG *) 	0x400E1438) // (PIOD) Output Data Status Register
#define AT91C_PIOD_PSR  (AT91_CAST(AT91_REG *) 	0x400E1408) // (PIOD) PIO Status Register
#define AT91C_PIOD_MDDR (AT91_CAST(AT91_REG *) 	0x400E1454) // (PIOD) Multi-driver Disable Register
#define AT91C_PIOD_OWSR (AT91_CAST(AT91_REG *) 	0x400E14A8) // (PIOD) Output Write Status Register
#define AT91C_PIOD_IDR  (AT91_CAST(AT91_REG *) 	0x400E1444) // (PIOD) Interrupt Disable Register
#define AT91C_PIOD_LSR  (AT91_CAST(AT91_REG *) 	0x400E14C4) // (PIOD) Level Select Register
#define AT91C_PIOD_PER  (AT91_CAST(AT91_REG *) 	0x400E1400) // (PIOD) PIO Enable Register
#define AT91C_PIOD_SCIFSR (AT91_CAST(AT91_REG *) 	0x400E1480) // (PIOD) System Clock Glitch Input Filter Select Register
#define AT91C_PIOD_ABSR (AT91_CAST(AT91_REG *) 	0x400E1470) // (PIOD) Peripheral AB Select Register
#define AT91C_PIOD_OWER (AT91_CAST(AT91_REG *) 	0x400E14A0) // (PIOD) Output Write Enable Register
#define AT91C_PIOD_FELLSR (AT91_CAST(AT91_REG *) 	0x400E14D0) // (PIOD) Falling Edge/Low Level Select Register
#define AT91C_PIOD_MDER (AT91_CAST(AT91_REG *) 	0x400E1450) // (PIOD) Multi-driver Enable Register
#define AT91C_PIOD_PDR  (AT91_CAST(AT91_REG *) 	0x400E1404) // (PIOD) PIO Disable Register
#define AT91C_PIOD_IFSR (AT91_CAST(AT91_REG *) 	0x400E1428) // (PIOD) Input Filter Status Register
#define AT91C_PIOD_KER  (AT91_CAST(AT91_REG *) 	0x400E1520) // (PIOD) Keypad Controller Enable Register
#define AT91C_PIOD_IER  (AT91_CAST(AT91_REG *) 	0x400E1440) // (PIOD) Interrupt Enable Register
#define AT91C_PIOD_MDSR (AT91_CAST(AT91_REG *) 	0x400E1458) // (PIOD) Multi-driver Status Register
#define AT91C_PIOD_PPUSR (AT91_CAST(AT91_REG *) 	0x400E1468) // (PIOD) Pull-up Status Register
#define AT91C_PIOD_ELSR (AT91_CAST(AT91_REG *) 	0x400E14C8) // (PIOD) Edge/Level Status Register
#define AT91C_PIOD_KIDR (AT91_CAST(AT91_REG *) 	0x400E1534) // (PIOD) Keypad Controller Interrupt Disable Register
#define AT91C_PIOD_ESR  (AT91_CAST(AT91_REG *) 	0x400E14C0) // (PIOD) Edge Select Register
#define AT91C_PIOD_KKPR (AT91_CAST(AT91_REG *) 	0x400E1540) // (PIOD) Keypad Controller Key Press Register
#define AT91C_PIOD_IFDGSR (AT91_CAST(AT91_REG *) 	0x400E1488) // (PIOD) Glitch or Debouncing Input Filter Clock Selection Status Register
// ========== Register definition for PIOE peripheral ========== 
#define AT91C_PIOE_IDR  (AT91_CAST(AT91_REG *) 	0x400E1644) // (PIOE) Interrupt Disable Register
#define AT91C_PIOE_ESR  (AT91_CAST(AT91_REG *) 	0x400E16C0) // (PIOE) Edge Select Register
#define AT91C_PIOE_PER  (AT91_CAST(AT91_REG *) 	0x400E1600) // (PIOE) PIO Enable Register
#define AT91C_PIOE_IFSR (AT91_CAST(AT91_REG *) 	0x400E1628) // (PIOE) Input Filter Status Register
#define AT91C_PIOE_KRCR (AT91_CAST(AT91_REG *) 	0x400E1724) // (PIOE) Keypad Controller Row Column Register
#define AT91C_PIOE_IMR  (AT91_CAST(AT91_REG *) 	0x400E1648) // (PIOE) Interrupt Mask Register
#define AT91C_PIOE_OER  (AT91_CAST(AT91_REG *) 	0x400E1610) // (PIOE) Output Enable Register
#define AT91C_PIOE_PPUSR (AT91_CAST(AT91_REG *) 	0x400E1668) // (PIOE) Pull-up Status Register
#define AT91C_PIOE_DIFSR (AT91_CAST(AT91_REG *) 	0x400E1684) // (PIOE) Debouncing Input Filter Select Register
#define AT91C_PIOE_IER  (AT91_CAST(AT91_REG *) 	0x400E1640) // (PIOE) Interrupt Enable Register
#define AT91C_PIOE_PDR  (AT91_CAST(AT91_REG *) 	0x400E1604) // (PIOE) PIO Disable Register
#define AT91C_PIOE_FELLSR (AT91_CAST(AT91_REG *) 	0x400E16D0) // (PIOE) Falling Edge/Low Level Select Register
#define AT91C_PIOE_LSR  (AT91_CAST(AT91_REG *) 	0x400E16C4) // (PIOE) Level Select Register
#define AT91C_PIOE_PPUDR (AT91_CAST(AT91_REG *) 	0x400E1660) // (PIOE) Pull-up Disable Register
#define AT91C_PIOE_KSR  (AT91_CAST(AT91_REG *) 	0x400E173C) // (PIOE) Keypad Controller Status Register
#define AT91C_PIOE_ABSR (AT91_CAST(AT91_REG *) 	0x400E1670) // (PIOE) Peripheral AB Select Register
#define AT91C_PIOE_PPUER (AT91_CAST(AT91_REG *) 	0x400E1664) // (PIOE) Pull-up Enable Register
#define AT91C_PIOE_MDSR (AT91_CAST(AT91_REG *) 	0x400E1658) // (PIOE) Multi-driver Status Register
#define AT91C_PIOE_MDER (AT91_CAST(AT91_REG *) 	0x400E1650) // (PIOE) Multi-driver Enable Register
#define AT91C_PIOE_AIMDR (AT91_CAST(AT91_REG *) 	0x400E16B4) // (PIOE) Additional Interrupt Modes Disables Register
#define AT91C_PIOE_KKPR (AT91_CAST(AT91_REG *) 	0x400E1740) // (PIOE) Keypad Controller Key Press Register
#define AT91C_PIOE_VER  (AT91_CAST(AT91_REG *) 	0x400E16FC) // (PIOE) PIO VERSION REGISTER 
#define AT91C_PIOE_KDR  (AT91_CAST(AT91_REG *) 	0x400E1728) // (PIOE) Keypad Controller Debouncing Register
#define AT91C_PIOE_AIMER (AT91_CAST(AT91_REG *) 	0x400E16B0) // (PIOE) Additional Interrupt Modes Enable Register
#define AT91C_PIOE_ISR  (AT91_CAST(AT91_REG *) 	0x400E164C) // (PIOE) Interrupt Status Register
#define AT91C_PIOE_LOCKSR (AT91_CAST(AT91_REG *) 	0x400E16E0) // (PIOE) Lock Status Register
#define AT91C_PIOE_IFER (AT91_CAST(AT91_REG *) 	0x400E1620) // (PIOE) Input Filter Enable Register
#define AT91C_PIOE_REHLSR (AT91_CAST(AT91_REG *) 	0x400E16D4) // (PIOE) Rising Edge/ High Level Select Register
#define AT91C_PIOE_PSR  (AT91_CAST(AT91_REG *) 	0x400E1608) // (PIOE) PIO Status Register
#define AT91C_PIOE_IFDR (AT91_CAST(AT91_REG *) 	0x400E1624) // (PIOE) Input Filter Disable Register
#define AT91C_PIOE_MDDR (AT91_CAST(AT91_REG *) 	0x400E1654) // (PIOE) Multi-driver Disable Register
#define AT91C_PIOE_IFDGSR (AT91_CAST(AT91_REG *) 	0x400E1688) // (PIOE) Glitch or Debouncing Input Filter Clock Selection Status Register
#define AT91C_PIOE_ELSR (AT91_CAST(AT91_REG *) 	0x400E16C8) // (PIOE) Edge/Level Status Register
#define AT91C_PIOE_OWDR (AT91_CAST(AT91_REG *) 	0x400E16A4) // (PIOE) Output Write Disable Register
#define AT91C_PIOE_ODR  (AT91_CAST(AT91_REG *) 	0x400E1614) // (PIOE) Output Disable Registerr
#define AT91C_PIOE_KKRR (AT91_CAST(AT91_REG *) 	0x400E1744) // (PIOE) Keypad Controller Key Release Register
#define AT91C_PIOE_ODSR (AT91_CAST(AT91_REG *) 	0x400E1638) // (PIOE) Output Data Status Register
#define AT91C_PIOE_AIMMR (AT91_CAST(AT91_REG *) 	0x400E16B8) // (PIOE) Additional Interrupt Modes Mask Register
#define AT91C_PIOE_PDSR (AT91_CAST(AT91_REG *) 	0x400E163C) // (PIOE) Pin Data Status Register
#define AT91C_PIOE_FRLHSR (AT91_CAST(AT91_REG *) 	0x400E16D8) // (PIOE) Fall/Rise - Low/High Status Register
#define AT91C_PIOE_KIMR (AT91_CAST(AT91_REG *) 	0x400E1738) // (PIOE) Keypad Controller Interrupt Mask Register
#define AT91C_PIOE_CODR (AT91_CAST(AT91_REG *) 	0x400E1634) // (PIOE) Clear Output Data Register
#define AT91C_PIOE_OWER (AT91_CAST(AT91_REG *) 	0x400E16A0) // (PIOE) Output Write Enable Register
#define AT91C_PIOE_KIDR (AT91_CAST(AT91_REG *) 	0x400E1734) // (PIOE) Keypad Controller Interrupt Disable Register
#define AT91C_PIOE_KER  (AT91_CAST(AT91_REG *) 	0x400E1720) // (PIOE) Keypad Controller Enable Register
#define AT91C_PIOE_KIER (AT91_CAST(AT91_REG *) 	0x400E1730) // (PIOE) Keypad Controller Interrupt Enable Register
#define AT91C_PIOE_OWSR (AT91_CAST(AT91_REG *) 	0x400E16A8) // (PIOE) Output Write Status Register
#define AT91C_PIOE_SCDR (AT91_CAST(AT91_REG *) 	0x400E168C) // (PIOE) Slow Clock Divider Debouncing Register
#define AT91C_PIOE_SODR (AT91_CAST(AT91_REG *) 	0x400E1630) // (PIOE) Set Output Data Register
#define AT91C_PIOE_OSR  (AT91_CAST(AT91_REG *) 	0x400E1618) // (PIOE) Output Status Register
#define AT91C_PIOE_SCIFSR (AT91_CAST(AT91_REG *) 	0x400E1680) // (PIOE) System Clock Glitch Input Filter Select Register
// ========== Register definition for PIOF peripheral ========== 
#define AT91C_PIOF_ODSR (AT91_CAST(AT91_REG *) 	0x400E1838) // (PIOF) Output Data Status Register
#define AT91C_PIOF_MDER (AT91_CAST(AT91_REG *) 	0x400E1850) // (PIOF) Multi-driver Enable Register
#define AT91C_PIOF_LSR  (AT91_CAST(AT91_REG *) 	0x400E18C4) // (PIOF) Level Select Register
#define AT91C_PIOF_MDDR (AT91_CAST(AT91_REG *) 	0x400E1854) // (PIOF) Multi-driver Disable Register
#define AT91C_PIOF_ELSR (AT91_CAST(AT91_REG *) 	0x400E18C8) // (PIOF) Edge/Level Status Register
#define AT91C_PIOF_SCDR (AT91_CAST(AT91_REG *) 	0x400E188C) // (PIOF) Slow Clock Divider Debouncing Register
#define AT91C_PIOF_OWER (AT91_CAST(AT91_REG *) 	0x400E18A0) // (PIOF) Output Write Enable Register
#define AT91C_PIOF_KKPR (AT91_CAST(AT91_REG *) 	0x400E1940) // (PIOF) Keypad Controller Key Press Register
#define AT91C_PIOF_KER  (AT91_CAST(AT91_REG *) 	0x400E1920) // (PIOF) Keypad Controller Enable Register
#define AT91C_PIOF_KIMR (AT91_CAST(AT91_REG *) 	0x400E1938) // (PIOF) Keypad Controller Interrupt Mask Register
#define AT91C_PIOF_DIFSR (AT91_CAST(AT91_REG *) 	0x400E1884) // (PIOF) Debouncing Input Filter Select Register
#define AT91C_PIOF_CODR (AT91_CAST(AT91_REG *) 	0x400E1834) // (PIOF) Clear Output Data Register
#define AT91C_PIOF_PER  (AT91_CAST(AT91_REG *) 	0x400E1800) // (PIOF) PIO Enable Register
#define AT91C_PIOF_PDR  (AT91_CAST(AT91_REG *) 	0x400E1804) // (PIOF) PIO Disable Register
#define AT91C_PIOF_KRCR (AT91_CAST(AT91_REG *) 	0x400E1924) // (PIOF) Keypad Controller Row Column Register
#define AT91C_PIOF_KIER (AT91_CAST(AT91_REG *) 	0x400E1930) // (PIOF) Keypad Controller Interrupt Enable Register
#define AT91C_PIOF_IFER (AT91_CAST(AT91_REG *) 	0x400E1820) // (PIOF) Input Filter Enable Register
#define AT91C_PIOF_VER  (AT91_CAST(AT91_REG *) 	0x400E18FC) // (PIOF) PIO VERSION REGISTER 
#define AT91C_PIOF_IMR  (AT91_CAST(AT91_REG *) 	0x400E1848) // (PIOF) Interrupt Mask Register
#define AT91C_PIOF_PSR  (AT91_CAST(AT91_REG *) 	0x400E1808) // (PIOF) PIO Status Register
#define AT91C_PIOF_ESR  (AT91_CAST(AT91_REG *) 	0x400E18C0) // (PIOF) Edge Select Register
#define AT91C_PIOF_OWDR (AT91_CAST(AT91_REG *) 	0x400E18A4) // (PIOF) Output Write Disable Register
#define AT91C_PIOF_OSR  (AT91_CAST(AT91_REG *) 	0x400E1818) // (PIOF) Output Status Register
#define AT91C_PIOF_IFDGSR (AT91_CAST(AT91_REG *) 	0x400E1888) // (PIOF) Glitch or Debouncing Input Filter Clock Selection Status Register
#define AT91C_PIOF_AIMER (AT91_CAST(AT91_REG *) 	0x400E18B0) // (PIOF) Additional Interrupt Modes Enable Register
#define AT91C_PIOF_KKRR (AT91_CAST(AT91_REG *) 	0x400E1944) // (PIOF) Keypad Controller Key Release Register
#define AT91C_PIOF_FELLSR (AT91_CAST(AT91_REG *) 	0x400E18D0) // (PIOF) Falling Edge/Low Level Select Register
#define AT91C_PIOF_KIDR (AT91_CAST(AT91_REG *) 	0x400E1934) // (PIOF) Keypad Controller Interrupt Disable Register
#define AT91C_PIOF_LOCKSR (AT91_CAST(AT91_REG *) 	0x400E18E0) // (PIOF) Lock Status Register
#define AT91C_PIOF_FRLHSR (AT91_CAST(AT91_REG *) 	0x400E18D8) // (PIOF) Fall/Rise - Low/High Status Register
#define AT91C_PIOF_SODR (AT91_CAST(AT91_REG *) 	0x400E1830) // (PIOF) Set Output Data Register
#define AT91C_PIOF_PDSR (AT91_CAST(AT91_REG *) 	0x400E183C) // (PIOF) Pin Data Status Register
#define AT91C_PIOF_KSR  (AT91_CAST(AT91_REG *) 	0x400E193C) // (PIOF) Keypad Controller Status Register
#define AT91C_PIOF_IFDR (AT91_CAST(AT91_REG *) 	0x400E1824) // (PIOF) Input Filter Disable Register
#define AT91C_PIOF_ODR  (AT91_CAST(AT91_REG *) 	0x400E1814) // (PIOF) Output Disable Registerr
#define AT91C_PIOF_PPUDR (AT91_CAST(AT91_REG *) 	0x400E1860) // (PIOF) Pull-up Disable Register
#define AT91C_PIOF_AIMDR (AT91_CAST(AT91_REG *) 	0x400E18B4) // (PIOF) Additional Interrupt Modes Disables Register
#define AT91C_PIOF_PPUER (AT91_CAST(AT91_REG *) 	0x400E1864) // (PIOF) Pull-up Enable Register
#define AT91C_PIOF_ABSR (AT91_CAST(AT91_REG *) 	0x400E1870) // (PIOF) Peripheral AB Select Register
#define AT91C_PIOF_MDSR (AT91_CAST(AT91_REG *) 	0x400E1858) // (PIOF) Multi-driver Status Register
#define AT91C_PIOF_REHLSR (AT91_CAST(AT91_REG *) 	0x400E18D4) // (PIOF) Rising Edge/ High Level Select Register
#define AT91C_PIOF_ISR  (AT91_CAST(AT91_REG *) 	0x400E184C) // (PIOF) Interrupt Status Register
#define AT91C_PIOF_IER  (AT91_CAST(AT91_REG *) 	0x400E1840) // (PIOF) Interrupt Enable Register
#define AT91C_PIOF_IDR  (AT91_CAST(AT91_REG *) 	0x400E1844) // (PIOF) Interrupt Disable Register
#define AT91C_PIOF_AIMMR (AT91_CAST(AT91_REG *) 	0x400E18B8) // (PIOF) Additional Interrupt Modes Mask Register
#define AT91C_PIOF_SCIFSR (AT91_CAST(AT91_REG *) 	0x400E1880) // (PIOF) System Clock Glitch Input Filter Select Register
#define AT91C_PIOF_KDR  (AT91_CAST(AT91_REG *) 	0x400E1928) // (PIOF) Keypad Controller Debouncing Register
#define AT91C_PIOF_OWSR (AT91_CAST(AT91_REG *) 	0x400E18A8) // (PIOF) Output Write Status Register
#define AT91C_PIOF_IFSR (AT91_CAST(AT91_REG *) 	0x400E1828) // (PIOF) Input Filter Status Register
#define AT91C_PIOF_PPUSR (AT91_CAST(AT91_REG *) 	0x400E1868) // (PIOF) Pull-up Status Register
#define AT91C_PIOF_OER  (AT91_CAST(AT91_REG *) 	0x400E1810) // (PIOF) Output Enable Register
// ========== Register definition for PDC_US0 peripheral ========== 
#define AT91C_US0_RPR   (AT91_CAST(AT91_REG *) 	0x40098100) // (PDC_US0) Receive Pointer Register
#define AT91C_US0_TPR   (AT91_CAST(AT91_REG *) 	0x40098108) // (PDC_US0) Transmit Pointer Register
#define AT91C_US0_TCR   (AT91_CAST(AT91_REG *) 	0x4009810C) // (PDC_US0) Transmit Counter Register
#define AT91C_US0_PTSR  (AT91_CAST(AT91_REG *) 	0x40098124) // (PDC_US0) PDC Transfer Status Register
#define AT91C_US0_PTCR  (AT91_CAST(AT91_REG *) 	0x40098120) // (PDC_US0) PDC Transfer Control Register
#define AT91C_US0_RNPR  (AT91_CAST(AT91_REG *) 	0x40098110) // (PDC_US0) Receive Next Pointer Register
#define AT91C_US0_TNCR  (AT91_CAST(AT91_REG *) 	0x4009811C) // (PDC_US0) Transmit Next Counter Register
#define AT91C_US0_RNCR  (AT91_CAST(AT91_REG *) 	0x40098114) // (PDC_US0) Receive Next Counter Register
#define AT91C_US0_TNPR  (AT91_CAST(AT91_REG *) 	0x40098118) // (PDC_US0) Transmit Next Pointer Register
#define AT91C_US0_RCR   (AT91_CAST(AT91_REG *) 	0x40098104) // (PDC_US0) Receive Counter Register
// ========== Register definition for US0 peripheral ========== 
#define AT91C_US0_MAN   (AT91_CAST(AT91_REG *) 	0x40098050) // (US0) Manchester Encoder Decoder Register
#define AT91C_US0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400980EC) // (US0) US ADDRSIZE REGISTER 
#define AT91C_US0_MR    (AT91_CAST(AT91_REG *) 	0x40098004) // (US0) Mode Register
#define AT91C_US0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400980F0) // (US0) US IPNAME1 REGISTER 
#define AT91C_US0_IF    (AT91_CAST(AT91_REG *) 	0x4009804C) // (US0) IRDA_FILTER Register
#define AT91C_US0_BRGR  (AT91_CAST(AT91_REG *) 	0x40098020) // (US0) Baud Rate Generator Register
#define AT91C_US0_FIDI  (AT91_CAST(AT91_REG *) 	0x40098040) // (US0) FI_DI_Ratio Register
#define AT91C_US0_IER   (AT91_CAST(AT91_REG *) 	0x40098008) // (US0) Interrupt Enable Register
#define AT91C_US0_RTOR  (AT91_CAST(AT91_REG *) 	0x40098024) // (US0) Receiver Time-out Register
#define AT91C_US0_CR    (AT91_CAST(AT91_REG *) 	0x40098000) // (US0) Control Register
#define AT91C_US0_THR   (AT91_CAST(AT91_REG *) 	0x4009801C) // (US0) Transmitter Holding Register
#define AT91C_US0_CSR   (AT91_CAST(AT91_REG *) 	0x40098014) // (US0) Channel Status Register
#define AT91C_US0_VER   (AT91_CAST(AT91_REG *) 	0x400980FC) // (US0) VERSION Register
#define AT91C_US0_FEATURES (AT91_CAST(AT91_REG *) 	0x400980F8) // (US0) US FEATURES REGISTER 
#define AT91C_US0_IDR   (AT91_CAST(AT91_REG *) 	0x4009800C) // (US0) Interrupt Disable Register
#define AT91C_US0_TTGR  (AT91_CAST(AT91_REG *) 	0x40098028) // (US0) Transmitter Time-guard Register
#define AT91C_US0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400980F4) // (US0) US IPNAME2 REGISTER 
#define AT91C_US0_RHR   (AT91_CAST(AT91_REG *) 	0x40098018) // (US0) Receiver Holding Register
#define AT91C_US0_NER   (AT91_CAST(AT91_REG *) 	0x40098044) // (US0) Nb Errors Register
#define AT91C_US0_IMR   (AT91_CAST(AT91_REG *) 	0x40098010) // (US0) Interrupt Mask Register
// ========== Register definition for PDC_US1 peripheral ========== 
#define AT91C_US1_TPR   (AT91_CAST(AT91_REG *) 	0x4009C108) // (PDC_US1) Transmit Pointer Register
#define AT91C_US1_PTCR  (AT91_CAST(AT91_REG *) 	0x4009C120) // (PDC_US1) PDC Transfer Control Register
#define AT91C_US1_TCR   (AT91_CAST(AT91_REG *) 	0x4009C10C) // (PDC_US1) Transmit Counter Register
#define AT91C_US1_RCR   (AT91_CAST(AT91_REG *) 	0x4009C104) // (PDC_US1) Receive Counter Register
#define AT91C_US1_RNCR  (AT91_CAST(AT91_REG *) 	0x4009C114) // (PDC_US1) Receive Next Counter Register
#define AT91C_US1_RNPR  (AT91_CAST(AT91_REG *) 	0x4009C110) // (PDC_US1) Receive Next Pointer Register
#define AT91C_US1_RPR   (AT91_CAST(AT91_REG *) 	0x4009C100) // (PDC_US1) Receive Pointer Register
#define AT91C_US1_PTSR  (AT91_CAST(AT91_REG *) 	0x4009C124) // (PDC_US1) PDC Transfer Status Register
#define AT91C_US1_TNCR  (AT91_CAST(AT91_REG *) 	0x4009C11C) // (PDC_US1) Transmit Next Counter Register
#define AT91C_US1_TNPR  (AT91_CAST(AT91_REG *) 	0x4009C118) // (PDC_US1) Transmit Next Pointer Register
// ========== Register definition for US1 peripheral ========== 
#define AT91C_US1_MAN   (AT91_CAST(AT91_REG *) 	0x4009C050) // (US1) Manchester Encoder Decoder Register
#define AT91C_US1_CSR   (AT91_CAST(AT91_REG *) 	0x4009C014) // (US1) Channel Status Register
#define AT91C_US1_BRGR  (AT91_CAST(AT91_REG *) 	0x4009C020) // (US1) Baud Rate Generator Register
#define AT91C_US1_IPNAME2 (AT91_CAST(AT91_REG *) 	0x4009C0F4) // (US1) US IPNAME2 REGISTER 
#define AT91C_US1_RTOR  (AT91_CAST(AT91_REG *) 	0x4009C024) // (US1) Receiver Time-out Register
#define AT91C_US1_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4009C0EC) // (US1) US ADDRSIZE REGISTER 
#define AT91C_US1_CR    (AT91_CAST(AT91_REG *) 	0x4009C000) // (US1) Control Register
#define AT91C_US1_IF    (AT91_CAST(AT91_REG *) 	0x4009C04C) // (US1) IRDA_FILTER Register
#define AT91C_US1_FEATURES (AT91_CAST(AT91_REG *) 	0x4009C0F8) // (US1) US FEATURES REGISTER 
#define AT91C_US1_VER   (AT91_CAST(AT91_REG *) 	0x4009C0FC) // (US1) VERSION Register
#define AT91C_US1_RHR   (AT91_CAST(AT91_REG *) 	0x4009C018) // (US1) Receiver Holding Register
#define AT91C_US1_TTGR  (AT91_CAST(AT91_REG *) 	0x4009C028) // (US1) Transmitter Time-guard Register
#define AT91C_US1_NER   (AT91_CAST(AT91_REG *) 	0x4009C044) // (US1) Nb Errors Register
#define AT91C_US1_IMR   (AT91_CAST(AT91_REG *) 	0x4009C010) // (US1) Interrupt Mask Register
#define AT91C_US1_THR   (AT91_CAST(AT91_REG *) 	0x4009C01C) // (US1) Transmitter Holding Register
#define AT91C_US1_IDR   (AT91_CAST(AT91_REG *) 	0x4009C00C) // (US1) Interrupt Disable Register
#define AT91C_US1_MR    (AT91_CAST(AT91_REG *) 	0x4009C004) // (US1) Mode Register
#define AT91C_US1_IER   (AT91_CAST(AT91_REG *) 	0x4009C008) // (US1) Interrupt Enable Register
#define AT91C_US1_FIDI  (AT91_CAST(AT91_REG *) 	0x4009C040) // (US1) FI_DI_Ratio Register
#define AT91C_US1_IPNAME1 (AT91_CAST(AT91_REG *) 	0x4009C0F0) // (US1) US IPNAME1 REGISTER 
// ========== Register definition for PDC_US2 peripheral ========== 
#define AT91C_US2_RCR   (AT91_CAST(AT91_REG *) 	0x400A0104) // (PDC_US2) Receive Counter Register
#define AT91C_US2_TNPR  (AT91_CAST(AT91_REG *) 	0x400A0118) // (PDC_US2) Transmit Next Pointer Register
#define AT91C_US2_TCR   (AT91_CAST(AT91_REG *) 	0x400A010C) // (PDC_US2) Transmit Counter Register
#define AT91C_US2_RNCR  (AT91_CAST(AT91_REG *) 	0x400A0114) // (PDC_US2) Receive Next Counter Register
#define AT91C_US2_TPR   (AT91_CAST(AT91_REG *) 	0x400A0108) // (PDC_US2) Transmit Pointer Register
#define AT91C_US2_PTSR  (AT91_CAST(AT91_REG *) 	0x400A0124) // (PDC_US2) PDC Transfer Status Register
#define AT91C_US2_RNPR  (AT91_CAST(AT91_REG *) 	0x400A0110) // (PDC_US2) Receive Next Pointer Register
#define AT91C_US2_TNCR  (AT91_CAST(AT91_REG *) 	0x400A011C) // (PDC_US2) Transmit Next Counter Register
#define AT91C_US2_PTCR  (AT91_CAST(AT91_REG *) 	0x400A0120) // (PDC_US2) PDC Transfer Control Register
#define AT91C_US2_RPR   (AT91_CAST(AT91_REG *) 	0x400A0100) // (PDC_US2) Receive Pointer Register
// ========== Register definition for US2 peripheral ========== 
#define AT91C_US2_IDR   (AT91_CAST(AT91_REG *) 	0x400A000C) // (US2) Interrupt Disable Register
#define AT91C_US2_BRGR  (AT91_CAST(AT91_REG *) 	0x400A0020) // (US2) Baud Rate Generator Register
#define AT91C_US2_CSR   (AT91_CAST(AT91_REG *) 	0x400A0014) // (US2) Channel Status Register
#define AT91C_US2_FEATURES (AT91_CAST(AT91_REG *) 	0x400A00F8) // (US2) US FEATURES REGISTER 
#define AT91C_US2_CR    (AT91_CAST(AT91_REG *) 	0x400A0000) // (US2) Control Register
#define AT91C_US2_IMR   (AT91_CAST(AT91_REG *) 	0x400A0010) // (US2) Interrupt Mask Register
#define AT91C_US2_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400A00EC) // (US2) US ADDRSIZE REGISTER 
#define AT91C_US2_IF    (AT91_CAST(AT91_REG *) 	0x400A004C) // (US2) IRDA_FILTER Register
#define AT91C_US2_RHR   (AT91_CAST(AT91_REG *) 	0x400A0018) // (US2) Receiver Holding Register
#define AT91C_US2_FIDI  (AT91_CAST(AT91_REG *) 	0x400A0040) // (US2) FI_DI_Ratio Register
#define AT91C_US2_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400A00F4) // (US2) US IPNAME2 REGISTER 
#define AT91C_US2_TTGR  (AT91_CAST(AT91_REG *) 	0x400A0028) // (US2) Transmitter Time-guard Register
#define AT91C_US2_VER   (AT91_CAST(AT91_REG *) 	0x400A00FC) // (US2) VERSION Register
#define AT91C_US2_RTOR  (AT91_CAST(AT91_REG *) 	0x400A0024) // (US2) Receiver Time-out Register
#define AT91C_US2_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400A00F0) // (US2) US IPNAME1 REGISTER 
#define AT91C_US2_MR    (AT91_CAST(AT91_REG *) 	0x400A0004) // (US2) Mode Register
#define AT91C_US2_MAN   (AT91_CAST(AT91_REG *) 	0x400A0050) // (US2) Manchester Encoder Decoder Register
#define AT91C_US2_THR   (AT91_CAST(AT91_REG *) 	0x400A001C) // (US2) Transmitter Holding Register
#define AT91C_US2_IER   (AT91_CAST(AT91_REG *) 	0x400A0008) // (US2) Interrupt Enable Register
#define AT91C_US2_NER   (AT91_CAST(AT91_REG *) 	0x400A0044) // (US2) Nb Errors Register
// ========== Register definition for PDC_US3 peripheral ========== 
#define AT91C_US3_TCR   (AT91_CAST(AT91_REG *) 	0x400A410C) // (PDC_US3) Transmit Counter Register
#define AT91C_US3_TNPR  (AT91_CAST(AT91_REG *) 	0x400A4118) // (PDC_US3) Transmit Next Pointer Register
#define AT91C_US3_TPR   (AT91_CAST(AT91_REG *) 	0x400A4108) // (PDC_US3) Transmit Pointer Register
#define AT91C_US3_RNPR  (AT91_CAST(AT91_REG *) 	0x400A4110) // (PDC_US3) Receive Next Pointer Register
#define AT91C_US3_RNCR  (AT91_CAST(AT91_REG *) 	0x400A4114) // (PDC_US3) Receive Next Counter Register
#define AT91C_US3_RCR   (AT91_CAST(AT91_REG *) 	0x400A4104) // (PDC_US3) Receive Counter Register
#define AT91C_US3_TNCR  (AT91_CAST(AT91_REG *) 	0x400A411C) // (PDC_US3) Transmit Next Counter Register
#define AT91C_US3_PTCR  (AT91_CAST(AT91_REG *) 	0x400A4120) // (PDC_US3) PDC Transfer Control Register
#define AT91C_US3_RPR   (AT91_CAST(AT91_REG *) 	0x400A4100) // (PDC_US3) Receive Pointer Register
#define AT91C_US3_PTSR  (AT91_CAST(AT91_REG *) 	0x400A4124) // (PDC_US3) PDC Transfer Status Register
// ========== Register definition for US3 peripheral ========== 
#define AT91C_US3_THR   (AT91_CAST(AT91_REG *) 	0x400A401C) // (US3) Transmitter Holding Register
#define AT91C_US3_IDR   (AT91_CAST(AT91_REG *) 	0x400A400C) // (US3) Interrupt Disable Register
#define AT91C_US3_TTGR  (AT91_CAST(AT91_REG *) 	0x400A4028) // (US3) Transmitter Time-guard Register
#define AT91C_US3_IMR   (AT91_CAST(AT91_REG *) 	0x400A4010) // (US3) Interrupt Mask Register
#define AT91C_US3_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400A40F4) // (US3) US IPNAME2 REGISTER 
#define AT91C_US3_BRGR  (AT91_CAST(AT91_REG *) 	0x400A4020) // (US3) Baud Rate Generator Register
#define AT91C_US3_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400A40EC) // (US3) US ADDRSIZE REGISTER 
#define AT91C_US3_MAN   (AT91_CAST(AT91_REG *) 	0x400A4050) // (US3) Manchester Encoder Decoder Register
#define AT91C_US3_RTOR  (AT91_CAST(AT91_REG *) 	0x400A4024) // (US3) Receiver Time-out Register
#define AT91C_US3_IF    (AT91_CAST(AT91_REG *) 	0x400A404C) // (US3) IRDA_FILTER Register
#define AT91C_US3_FIDI  (AT91_CAST(AT91_REG *) 	0x400A4040) // (US3) FI_DI_Ratio Register
#define AT91C_US3_MR    (AT91_CAST(AT91_REG *) 	0x400A4004) // (US3) Mode Register
#define AT91C_US3_FEATURES (AT91_CAST(AT91_REG *) 	0x400A40F8) // (US3) US FEATURES REGISTER 
#define AT91C_US3_CSR   (AT91_CAST(AT91_REG *) 	0x400A4014) // (US3) Channel Status Register
#define AT91C_US3_RHR   (AT91_CAST(AT91_REG *) 	0x400A4018) // (US3) Receiver Holding Register
#define AT91C_US3_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400A40F0) // (US3) US IPNAME1 REGISTER 
#define AT91C_US3_NER   (AT91_CAST(AT91_REG *) 	0x400A4044) // (US3) Nb Errors Register
#define AT91C_US3_IER   (AT91_CAST(AT91_REG *) 	0x400A4008) // (US3) Interrupt Enable Register
#define AT91C_US3_VER   (AT91_CAST(AT91_REG *) 	0x400A40FC) // (US3) VERSION Register
#define AT91C_US3_CR    (AT91_CAST(AT91_REG *) 	0x400A4000) // (US3) Control Register
// ========== Register definition for MCI peripheral ========== 
#define AT91C_MCI_DMA   (AT91_CAST(AT91_REG *) 	0x40000050) // (MCI) MCI DMA Configuration Register
#define AT91C_MCI_SDCR  (AT91_CAST(AT91_REG *) 	0x4000000C) // (MCI) MCI SD/SDIO Card Register
#define AT91C_MCI_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400000F0) // (MCI) MCI IPNAME1 REGISTER 
#define AT91C_MCI_CSTOR (AT91_CAST(AT91_REG *) 	0x4000001C) // (MCI) MCI Completion Signal Timeout Register
#define AT91C_MCI_RDR   (AT91_CAST(AT91_REG *) 	0x40000030) // (MCI) MCI Receive Data Register
#define AT91C_MCI_CMDR  (AT91_CAST(AT91_REG *) 	0x40000014) // (MCI) MCI Command Register
#define AT91C_MCI_IDR   (AT91_CAST(AT91_REG *) 	0x40000048) // (MCI) MCI Interrupt Disable Register
#define AT91C_MCI_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400000EC) // (MCI) MCI ADDRSIZE REGISTER 
#define AT91C_MCI_WPCR  (AT91_CAST(AT91_REG *) 	0x400000E4) // (MCI) MCI Write Protection Control Register
#define AT91C_MCI_RSPR  (AT91_CAST(AT91_REG *) 	0x40000020) // (MCI) MCI Response Register
#define AT91C_MCI_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400000F4) // (MCI) MCI IPNAME2 REGISTER 
#define AT91C_MCI_CR    (AT91_CAST(AT91_REG *) 	0x40000000) // (MCI) MCI Control Register
#define AT91C_MCI_IMR   (AT91_CAST(AT91_REG *) 	0x4000004C) // (MCI) MCI Interrupt Mask Register
#define AT91C_MCI_WPSR  (AT91_CAST(AT91_REG *) 	0x400000E8) // (MCI) MCI Write Protection Status Register
#define AT91C_MCI_DTOR  (AT91_CAST(AT91_REG *) 	0x40000008) // (MCI) MCI Data Timeout Register
#define AT91C_MCI_MR    (AT91_CAST(AT91_REG *) 	0x40000004) // (MCI) MCI Mode Register
#define AT91C_MCI_SR    (AT91_CAST(AT91_REG *) 	0x40000040) // (MCI) MCI Status Register
#define AT91C_MCI_IER   (AT91_CAST(AT91_REG *) 	0x40000044) // (MCI) MCI Interrupt Enable Register
#define AT91C_MCI_FEATURES (AT91_CAST(AT91_REG *) 	0x400000F8) // (MCI) MCI FEATURES REGISTER 
#define AT91C_MCI_BLKR  (AT91_CAST(AT91_REG *) 	0x40000018) // (MCI) MCI Block Register
#define AT91C_MCI_ARGR  (AT91_CAST(AT91_REG *) 	0x40000010) // (MCI) MCI Argument Register
#define AT91C_MCI_FIFO  (AT91_CAST(AT91_REG *) 	0x40000200) // (MCI) MCI FIFO Aperture Register
#define AT91C_MCI_TDR   (AT91_CAST(AT91_REG *) 	0x40000034) // (MCI) MCI Transmit Data Register
#define AT91C_MCI_CFG   (AT91_CAST(AT91_REG *) 	0x40000054) // (MCI) MCI Configuration Register
// ========== Register definition for PDC_TWI0 peripheral ========== 
#define AT91C_TWI0_TNCR (AT91_CAST(AT91_REG *) 	0x4008C11C) // (PDC_TWI0) Transmit Next Counter Register
#define AT91C_TWI0_TPR  (AT91_CAST(AT91_REG *) 	0x4008C108) // (PDC_TWI0) Transmit Pointer Register
#define AT91C_TWI0_RPR  (AT91_CAST(AT91_REG *) 	0x4008C100) // (PDC_TWI0) Receive Pointer Register
#define AT91C_TWI0_TCR  (AT91_CAST(AT91_REG *) 	0x4008C10C) // (PDC_TWI0) Transmit Counter Register
#define AT91C_TWI0_PTSR (AT91_CAST(AT91_REG *) 	0x4008C124) // (PDC_TWI0) PDC Transfer Status Register
#define AT91C_TWI0_RNPR (AT91_CAST(AT91_REG *) 	0x4008C110) // (PDC_TWI0) Receive Next Pointer Register
#define AT91C_TWI0_RCR  (AT91_CAST(AT91_REG *) 	0x4008C104) // (PDC_TWI0) Receive Counter Register
#define AT91C_TWI0_RNCR (AT91_CAST(AT91_REG *) 	0x4008C114) // (PDC_TWI0) Receive Next Counter Register
#define AT91C_TWI0_PTCR (AT91_CAST(AT91_REG *) 	0x4008C120) // (PDC_TWI0) PDC Transfer Control Register
#define AT91C_TWI0_TNPR (AT91_CAST(AT91_REG *) 	0x4008C118) // (PDC_TWI0) Transmit Next Pointer Register
// ========== Register definition for TWI0 peripheral ========== 
#define AT91C_TWI0_RHR  (AT91_CAST(AT91_REG *) 	0x4008C030) // (TWI0) Receive Holding Register
#define AT91C_TWI0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4008C0EC) // (TWI0) TWI ADDRSIZE REGISTER 
#define AT91C_TWI0_IER  (AT91_CAST(AT91_REG *) 	0x4008C024) // (TWI0) Interrupt Enable Register
#define AT91C_TWI0_CWGR (AT91_CAST(AT91_REG *) 	0x4008C010) // (TWI0) Clock Waveform Generator Register
#define AT91C_TWI0_SMR  (AT91_CAST(AT91_REG *) 	0x4008C008) // (TWI0) Slave Mode Register
#define AT91C_TWI0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x4008C0F4) // (TWI0) TWI IPNAME2 REGISTER 
#define AT91C_TWI0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x4008C0F0) // (TWI0) TWI IPNAME1 REGISTER 
#define AT91C_TWI0_IMR  (AT91_CAST(AT91_REG *) 	0x4008C02C) // (TWI0) Interrupt Mask Register
#define AT91C_TWI0_SR   (AT91_CAST(AT91_REG *) 	0x4008C020) // (TWI0) Status Register
#define AT91C_TWI0_MMR  (AT91_CAST(AT91_REG *) 	0x4008C004) // (TWI0) Master Mode Register
#define AT91C_TWI0_IADR (AT91_CAST(AT91_REG *) 	0x4008C00C) // (TWI0) Internal Address Register
#define AT91C_TWI0_FEATURES (AT91_CAST(AT91_REG *) 	0x4008C0F8) // (TWI0) TWI FEATURES REGISTER 
#define AT91C_TWI0_CR   (AT91_CAST(AT91_REG *) 	0x4008C000) // (TWI0) Control Register
#define AT91C_TWI0_THR  (AT91_CAST(AT91_REG *) 	0x4008C034) // (TWI0) Transmit Holding Register
#define AT91C_TWI0_IDR  (AT91_CAST(AT91_REG *) 	0x4008C028) // (TWI0) Interrupt Disable Register
#define AT91C_TWI0_VER  (AT91_CAST(AT91_REG *) 	0x4008C0FC) // (TWI0) Version Register
// ========== Register definition for PDC_TWI1 peripheral ========== 
#define AT91C_TWI1_RNCR (AT91_CAST(AT91_REG *) 	0x40090114) // (PDC_TWI1) Receive Next Counter Register
#define AT91C_TWI1_TNPR (AT91_CAST(AT91_REG *) 	0x40090118) // (PDC_TWI1) Transmit Next Pointer Register
#define AT91C_TWI1_TPR  (AT91_CAST(AT91_REG *) 	0x40090108) // (PDC_TWI1) Transmit Pointer Register
#define AT91C_TWI1_RCR  (AT91_CAST(AT91_REG *) 	0x40090104) // (PDC_TWI1) Receive Counter Register
#define AT91C_TWI1_RNPR (AT91_CAST(AT91_REG *) 	0x40090110) // (PDC_TWI1) Receive Next Pointer Register
#define AT91C_TWI1_TNCR (AT91_CAST(AT91_REG *) 	0x4009011C) // (PDC_TWI1) Transmit Next Counter Register
#define AT91C_TWI1_PTSR (AT91_CAST(AT91_REG *) 	0x40090124) // (PDC_TWI1) PDC Transfer Status Register
#define AT91C_TWI1_RPR  (AT91_CAST(AT91_REG *) 	0x40090100) // (PDC_TWI1) Receive Pointer Register
#define AT91C_TWI1_PTCR (AT91_CAST(AT91_REG *) 	0x40090120) // (PDC_TWI1) PDC Transfer Control Register
#define AT91C_TWI1_TCR  (AT91_CAST(AT91_REG *) 	0x4009010C) // (PDC_TWI1) Transmit Counter Register
// ========== Register definition for TWI1 peripheral ========== 
#define AT91C_TWI1_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400900F0) // (TWI1) TWI IPNAME1 REGISTER 
#define AT91C_TWI1_MMR  (AT91_CAST(AT91_REG *) 	0x40090004) // (TWI1) Master Mode Register
#define AT91C_TWI1_IER  (AT91_CAST(AT91_REG *) 	0x40090024) // (TWI1) Interrupt Enable Register
#define AT91C_TWI1_RHR  (AT91_CAST(AT91_REG *) 	0x40090030) // (TWI1) Receive Holding Register
#define AT91C_TWI1_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400900EC) // (TWI1) TWI ADDRSIZE REGISTER 
#define AT91C_TWI1_THR  (AT91_CAST(AT91_REG *) 	0x40090034) // (TWI1) Transmit Holding Register
#define AT91C_TWI1_IADR (AT91_CAST(AT91_REG *) 	0x4009000C) // (TWI1) Internal Address Register
#define AT91C_TWI1_CWGR (AT91_CAST(AT91_REG *) 	0x40090010) // (TWI1) Clock Waveform Generator Register
#define AT91C_TWI1_SMR  (AT91_CAST(AT91_REG *) 	0x40090008) // (TWI1) Slave Mode Register
#define AT91C_TWI1_IDR  (AT91_CAST(AT91_REG *) 	0x40090028) // (TWI1) Interrupt Disable Register
#define AT91C_TWI1_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400900F4) // (TWI1) TWI IPNAME2 REGISTER 
#define AT91C_TWI1_CR   (AT91_CAST(AT91_REG *) 	0x40090000) // (TWI1) Control Register
#define AT91C_TWI1_SR   (AT91_CAST(AT91_REG *) 	0x40090020) // (TWI1) Status Register
#define AT91C_TWI1_IMR  (AT91_CAST(AT91_REG *) 	0x4009002C) // (TWI1) Interrupt Mask Register
#define AT91C_TWI1_FEATURES (AT91_CAST(AT91_REG *) 	0x400900F8) // (TWI1) TWI FEATURES REGISTER 
#define AT91C_TWI1_VER  (AT91_CAST(AT91_REG *) 	0x400900FC) // (TWI1) Version Register
// ========== Register definition for SPI0 peripheral ========== 
#define AT91C_SPI0_RDR  (AT91_CAST(AT91_REG *) 	0x40008008) // (SPI0) Receive Data Register
#define AT91C_SPI0_CR   (AT91_CAST(AT91_REG *) 	0x40008000) // (SPI0) Control Register
#define AT91C_SPI0_IDR  (AT91_CAST(AT91_REG *) 	0x40008018) // (SPI0) Interrupt Disable Register
#define AT91C_SPI0_TDR  (AT91_CAST(AT91_REG *) 	0x4000800C) // (SPI0) Transmit Data Register
#define AT91C_SPI0_MR   (AT91_CAST(AT91_REG *) 	0x40008004) // (SPI0) Mode Register
#define AT91C_SPI0_IER  (AT91_CAST(AT91_REG *) 	0x40008014) // (SPI0) Interrupt Enable Register
#define AT91C_SPI0_IMR  (AT91_CAST(AT91_REG *) 	0x4000801C) // (SPI0) Interrupt Mask Register
#define AT91C_SPI0_CSR  (AT91_CAST(AT91_REG *) 	0x40008030) // (SPI0) Chip Select Register
#define AT91C_SPI0_SR   (AT91_CAST(AT91_REG *) 	0x40008010) // (SPI0) Status Register
// ========== Register definition for SPI1 peripheral ========== 
#define AT91C_SPI1_RDR  (AT91_CAST(AT91_REG *) 	0x4000C008) // (SPI1) Receive Data Register
#define AT91C_SPI1_IER  (AT91_CAST(AT91_REG *) 	0x4000C014) // (SPI1) Interrupt Enable Register
#define AT91C_SPI1_TDR  (AT91_CAST(AT91_REG *) 	0x4000C00C) // (SPI1) Transmit Data Register
#define AT91C_SPI1_MR   (AT91_CAST(AT91_REG *) 	0x4000C004) // (SPI1) Mode Register
#define AT91C_SPI1_SR   (AT91_CAST(AT91_REG *) 	0x4000C010) // (SPI1) Status Register
#define AT91C_SPI1_CR   (AT91_CAST(AT91_REG *) 	0x4000C000) // (SPI1) Control Register
#define AT91C_SPI1_IDR  (AT91_CAST(AT91_REG *) 	0x4000C018) // (SPI1) Interrupt Disable Register
#define AT91C_SPI1_IMR  (AT91_CAST(AT91_REG *) 	0x4000C01C) // (SPI1) Interrupt Mask Register
#define AT91C_SPI1_CSR  (AT91_CAST(AT91_REG *) 	0x4000C030) // (SPI1) Chip Select Register
// ========== Register definition for SSC peripheral ========== 
#define AT91C_SSC_FEATURES (AT91_CAST(AT91_REG *) 	0x400040F8) // (SSC) SSC FEATURES REGISTER 
#define AT91C_SSC_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400040F0) // (SSC) SSC IPNAME1 REGISTER 
#define AT91C_SSC_CR    (AT91_CAST(AT91_REG *) 	0x40004000) // (SSC) Control Register
#define AT91C_SSC_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400040EC) // (SSC) SSC ADDRSIZE REGISTER 
#define AT91C_SSC_RHR   (AT91_CAST(AT91_REG *) 	0x40004020) // (SSC) Receive Holding Register
#define AT91C_SSC_VER   (AT91_CAST(AT91_REG *) 	0x400040FC) // (SSC) Version Register
#define AT91C_SSC_TSHR  (AT91_CAST(AT91_REG *) 	0x40004034) // (SSC) Transmit Sync Holding Register
#define AT91C_SSC_RFMR  (AT91_CAST(AT91_REG *) 	0x40004014) // (SSC) Receive Frame Mode Register
#define AT91C_SSC_IDR   (AT91_CAST(AT91_REG *) 	0x40004048) // (SSC) Interrupt Disable Register
#define AT91C_SSC_TFMR  (AT91_CAST(AT91_REG *) 	0x4000401C) // (SSC) Transmit Frame Mode Register
#define AT91C_SSC_RSHR  (AT91_CAST(AT91_REG *) 	0x40004030) // (SSC) Receive Sync Holding Register
#define AT91C_SSC_TCMR  (AT91_CAST(AT91_REG *) 	0x40004018) // (SSC) Transmit Clock Mode Register
#define AT91C_SSC_RCMR  (AT91_CAST(AT91_REG *) 	0x40004010) // (SSC) Receive Clock ModeRegister
#define AT91C_SSC_SR    (AT91_CAST(AT91_REG *) 	0x40004040) // (SSC) Status Register
#define AT91C_SSC_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400040F4) // (SSC) SSC IPNAME2 REGISTER 
#define AT91C_SSC_THR   (AT91_CAST(AT91_REG *) 	0x40004024) // (SSC) Transmit Holding Register
#define AT91C_SSC_CMR   (AT91_CAST(AT91_REG *) 	0x40004004) // (SSC) Clock Mode Register
#define AT91C_SSC_IER   (AT91_CAST(AT91_REG *) 	0x40004044) // (SSC) Interrupt Enable Register
#define AT91C_SSC_IMR   (AT91_CAST(AT91_REG *) 	0x4000404C) // (SSC) Interrupt Mask Register
// ========== Register definition for TC0 peripheral ========== 
#define AT91C_TC0_IER   (AT91_CAST(AT91_REG *) 	0x40080024) // (TC0) Interrupt Enable Register
#define AT91C_TC0_CV    (AT91_CAST(AT91_REG *) 	0x40080010) // (TC0) Counter Value
#define AT91C_TC0_RA    (AT91_CAST(AT91_REG *) 	0x40080014) // (TC0) Register A
#define AT91C_TC0_RB    (AT91_CAST(AT91_REG *) 	0x40080018) // (TC0) Register B
#define AT91C_TC0_IDR   (AT91_CAST(AT91_REG *) 	0x40080028) // (TC0) Interrupt Disable Register
#define AT91C_TC0_SR    (AT91_CAST(AT91_REG *) 	0x40080020) // (TC0) Status Register
#define AT91C_TC0_IMR   (AT91_CAST(AT91_REG *) 	0x4008002C) // (TC0) Interrupt Mask Register
#define AT91C_TC0_CMR   (AT91_CAST(AT91_REG *) 	0x40080004) // (TC0) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC0_RC    (AT91_CAST(AT91_REG *) 	0x4008001C) // (TC0) Register C
#define AT91C_TC0_CCR   (AT91_CAST(AT91_REG *) 	0x40080000) // (TC0) Channel Control Register
// ========== Register definition for TCB0 peripheral ========== 
#define AT91C_TCB0_BCR  (AT91_CAST(AT91_REG *) 	0x400800C0) // (TCB0) TC Block Control Register
#define AT91C_TCB0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400800F4) // (TCB0) TC IPNAME2 REGISTER 
#define AT91C_TCB0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400800F0) // (TCB0) TC IPNAME1 REGISTER 
#define AT91C_TCB0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400800EC) // (TCB0) TC ADDRSIZE REGISTER 
#define AT91C_TCB0_FEATURES (AT91_CAST(AT91_REG *) 	0x400800F8) // (TCB0) TC FEATURES REGISTER 
#define AT91C_TCB0_BMR  (AT91_CAST(AT91_REG *) 	0x400800C4) // (TCB0) TC Block Mode Register
#define AT91C_TCB0_VER  (AT91_CAST(AT91_REG *) 	0x400800FC) // (TCB0)  Version Register
// ========== Register definition for TC1 peripheral ========== 
#define AT91C_TC1_SR    (AT91_CAST(AT91_REG *) 	0x40080060) // (TC1) Status Register
#define AT91C_TC1_RA    (AT91_CAST(AT91_REG *) 	0x40080054) // (TC1) Register A
#define AT91C_TC1_IER   (AT91_CAST(AT91_REG *) 	0x40080064) // (TC1) Interrupt Enable Register
#define AT91C_TC1_RB    (AT91_CAST(AT91_REG *) 	0x40080058) // (TC1) Register B
#define AT91C_TC1_IDR   (AT91_CAST(AT91_REG *) 	0x40080068) // (TC1) Interrupt Disable Register
#define AT91C_TC1_CCR   (AT91_CAST(AT91_REG *) 	0x40080040) // (TC1) Channel Control Register
#define AT91C_TC1_IMR   (AT91_CAST(AT91_REG *) 	0x4008006C) // (TC1) Interrupt Mask Register
#define AT91C_TC1_RC    (AT91_CAST(AT91_REG *) 	0x4008005C) // (TC1) Register C
#define AT91C_TC1_CMR   (AT91_CAST(AT91_REG *) 	0x40080044) // (TC1) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC1_CV    (AT91_CAST(AT91_REG *) 	0x40080050) // (TC1) Counter Value
// ========== Register definition for TCB1 peripheral ========== 
#define AT91C_TCB1_BCR  (AT91_CAST(AT91_REG *) 	0x40080100) // (TCB1) TC Block Control Register
#define AT91C_TCB1_VER  (AT91_CAST(AT91_REG *) 	0x4008013C) // (TCB1)  Version Register
#define AT91C_TCB1_FEATURES (AT91_CAST(AT91_REG *) 	0x40080138) // (TCB1) TC FEATURES REGISTER 
#define AT91C_TCB1_IPNAME2 (AT91_CAST(AT91_REG *) 	0x40080134) // (TCB1) TC IPNAME2 REGISTER 
#define AT91C_TCB1_BMR  (AT91_CAST(AT91_REG *) 	0x40080104) // (TCB1) TC Block Mode Register
#define AT91C_TCB1_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4008012C) // (TCB1) TC ADDRSIZE REGISTER 
#define AT91C_TCB1_IPNAME1 (AT91_CAST(AT91_REG *) 	0x40080130) // (TCB1) TC IPNAME1 REGISTER 
// ========== Register definition for TC2 peripheral ========== 
#define AT91C_TC2_RA    (AT91_CAST(AT91_REG *) 	0x40080094) // (TC2) Register A
#define AT91C_TC2_RB    (AT91_CAST(AT91_REG *) 	0x40080098) // (TC2) Register B
#define AT91C_TC2_CMR   (AT91_CAST(AT91_REG *) 	0x40080084) // (TC2) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC2_SR    (AT91_CAST(AT91_REG *) 	0x400800A0) // (TC2) Status Register
#define AT91C_TC2_CCR   (AT91_CAST(AT91_REG *) 	0x40080080) // (TC2) Channel Control Register
#define AT91C_TC2_IMR   (AT91_CAST(AT91_REG *) 	0x400800AC) // (TC2) Interrupt Mask Register
#define AT91C_TC2_CV    (AT91_CAST(AT91_REG *) 	0x40080090) // (TC2) Counter Value
#define AT91C_TC2_RC    (AT91_CAST(AT91_REG *) 	0x4008009C) // (TC2) Register C
#define AT91C_TC2_IER   (AT91_CAST(AT91_REG *) 	0x400800A4) // (TC2) Interrupt Enable Register
#define AT91C_TC2_IDR   (AT91_CAST(AT91_REG *) 	0x400800A8) // (TC2) Interrupt Disable Register
// ========== Register definition for TCB2 peripheral ========== 
#define AT91C_TCB2_FEATURES (AT91_CAST(AT91_REG *) 	0x40080178) // (TCB2) TC FEATURES REGISTER 
#define AT91C_TCB2_VER  (AT91_CAST(AT91_REG *) 	0x4008017C) // (TCB2)  Version Register
#define AT91C_TCB2_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4008016C) // (TCB2) TC ADDRSIZE REGISTER 
#define AT91C_TCB2_IPNAME1 (AT91_CAST(AT91_REG *) 	0x40080170) // (TCB2) TC IPNAME1 REGISTER 
#define AT91C_TCB2_IPNAME2 (AT91_CAST(AT91_REG *) 	0x40080174) // (TCB2) TC IPNAME2 REGISTER 
#define AT91C_TCB2_BMR  (AT91_CAST(AT91_REG *) 	0x40080144) // (TCB2) TC Block Mode Register
#define AT91C_TCB2_BCR  (AT91_CAST(AT91_REG *) 	0x40080140) // (TCB2) TC Block Control Register
// ========== Register definition for TC3 peripheral ========== 
#define AT91C_TC3_IMR   (AT91_CAST(AT91_REG *) 	0x4008402C) // (TC3) Interrupt Mask Register
#define AT91C_TC3_CV    (AT91_CAST(AT91_REG *) 	0x40084010) // (TC3) Counter Value
#define AT91C_TC3_CMR   (AT91_CAST(AT91_REG *) 	0x40084004) // (TC3) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC3_SR    (AT91_CAST(AT91_REG *) 	0x40084020) // (TC3) Status Register
#define AT91C_TC3_CCR   (AT91_CAST(AT91_REG *) 	0x40084000) // (TC3) Channel Control Register
#define AT91C_TC3_IER   (AT91_CAST(AT91_REG *) 	0x40084024) // (TC3) Interrupt Enable Register
#define AT91C_TC3_RB    (AT91_CAST(AT91_REG *) 	0x40084018) // (TC3) Register B
#define AT91C_TC3_IDR   (AT91_CAST(AT91_REG *) 	0x40084028) // (TC3) Interrupt Disable Register
#define AT91C_TC3_RC    (AT91_CAST(AT91_REG *) 	0x4008401C) // (TC3) Register C
#define AT91C_TC3_RA    (AT91_CAST(AT91_REG *) 	0x40084014) // (TC3) Register A
// ========== Register definition for TCB3 peripheral ========== 
#define AT91C_TCB3_FEATURES (AT91_CAST(AT91_REG *) 	0x400840F8) // (TCB3) TC FEATURES REGISTER 
#define AT91C_TCB3_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400840EC) // (TCB3) TC ADDRSIZE REGISTER 
#define AT91C_TCB3_BCR  (AT91_CAST(AT91_REG *) 	0x400840C0) // (TCB3) TC Block Control Register
#define AT91C_TCB3_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400840F0) // (TCB3) TC IPNAME1 REGISTER 
#define AT91C_TCB3_BMR  (AT91_CAST(AT91_REG *) 	0x400840C4) // (TCB3) TC Block Mode Register
#define AT91C_TCB3_VER  (AT91_CAST(AT91_REG *) 	0x400840FC) // (TCB3)  Version Register
#define AT91C_TCB3_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400840F4) // (TCB3) TC IPNAME2 REGISTER 
// ========== Register definition for TC4 peripheral ========== 
#define AT91C_TC4_RB    (AT91_CAST(AT91_REG *) 	0x40084058) // (TC4) Register B
#define AT91C_TC4_CMR   (AT91_CAST(AT91_REG *) 	0x40084044) // (TC4) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC4_RA    (AT91_CAST(AT91_REG *) 	0x40084054) // (TC4) Register A
#define AT91C_TC4_RC    (AT91_CAST(AT91_REG *) 	0x4008405C) // (TC4) Register C
#define AT91C_TC4_IMR   (AT91_CAST(AT91_REG *) 	0x4008406C) // (TC4) Interrupt Mask Register
#define AT91C_TC4_CCR   (AT91_CAST(AT91_REG *) 	0x40084040) // (TC4) Channel Control Register
#define AT91C_TC4_IDR   (AT91_CAST(AT91_REG *) 	0x40084068) // (TC4) Interrupt Disable Register
#define AT91C_TC4_CV    (AT91_CAST(AT91_REG *) 	0x40084050) // (TC4) Counter Value
#define AT91C_TC4_SR    (AT91_CAST(AT91_REG *) 	0x40084060) // (TC4) Status Register
#define AT91C_TC4_IER   (AT91_CAST(AT91_REG *) 	0x40084064) // (TC4) Interrupt Enable Register
// ========== Register definition for TCB4 peripheral ========== 
#define AT91C_TCB4_IPNAME2 (AT91_CAST(AT91_REG *) 	0x40084134) // (TCB4) TC IPNAME2 REGISTER 
#define AT91C_TCB4_IPNAME1 (AT91_CAST(AT91_REG *) 	0x40084130) // (TCB4) TC IPNAME1 REGISTER 
#define AT91C_TCB4_VER  (AT91_CAST(AT91_REG *) 	0x4008413C) // (TCB4)  Version Register
#define AT91C_TCB4_FEATURES (AT91_CAST(AT91_REG *) 	0x40084138) // (TCB4) TC FEATURES REGISTER 
#define AT91C_TCB4_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4008412C) // (TCB4) TC ADDRSIZE REGISTER 
#define AT91C_TCB4_BMR  (AT91_CAST(AT91_REG *) 	0x40084104) // (TCB4) TC Block Mode Register
#define AT91C_TCB4_BCR  (AT91_CAST(AT91_REG *) 	0x40084100) // (TCB4) TC Block Control Register
// ========== Register definition for TC5 peripheral ========== 
#define AT91C_TC5_IDR   (AT91_CAST(AT91_REG *) 	0x400840A8) // (TC5) Interrupt Disable Register
#define AT91C_TC5_RB    (AT91_CAST(AT91_REG *) 	0x40084098) // (TC5) Register B
#define AT91C_TC5_IMR   (AT91_CAST(AT91_REG *) 	0x400840AC) // (TC5) Interrupt Mask Register
#define AT91C_TC5_RA    (AT91_CAST(AT91_REG *) 	0x40084094) // (TC5) Register A
#define AT91C_TC5_CV    (AT91_CAST(AT91_REG *) 	0x40084090) // (TC5) Counter Value
#define AT91C_TC5_RC    (AT91_CAST(AT91_REG *) 	0x4008409C) // (TC5) Register C
#define AT91C_TC5_CMR   (AT91_CAST(AT91_REG *) 	0x40084084) // (TC5) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC5_CCR   (AT91_CAST(AT91_REG *) 	0x40084080) // (TC5) Channel Control Register
#define AT91C_TC5_IER   (AT91_CAST(AT91_REG *) 	0x400840A4) // (TC5) Interrupt Enable Register
#define AT91C_TC5_SR    (AT91_CAST(AT91_REG *) 	0x400840A0) // (TC5) Status Register
// ========== Register definition for TCB5 peripheral ========== 
#define AT91C_TCB5_IPNAME1 (AT91_CAST(AT91_REG *) 	0x40084170) // (TCB5) TC IPNAME1 REGISTER 
#define AT91C_TCB5_BMR  (AT91_CAST(AT91_REG *) 	0x40084144) // (TCB5) TC Block Mode Register
#define AT91C_TCB5_BCR  (AT91_CAST(AT91_REG *) 	0x40084140) // (TCB5) TC Block Control Register
#define AT91C_TCB5_IPNAME2 (AT91_CAST(AT91_REG *) 	0x40084174) // (TCB5) TC IPNAME2 REGISTER 
#define AT91C_TCB5_FEATURES (AT91_CAST(AT91_REG *) 	0x40084178) // (TCB5) TC FEATURES REGISTER 
#define AT91C_TCB5_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4008416C) // (TCB5) TC ADDRSIZE REGISTER 
#define AT91C_TCB5_VER  (AT91_CAST(AT91_REG *) 	0x4008417C) // (TCB5)  Version Register
// ========== Register definition for TC6 peripheral ========== 
#define AT91C_TC6_IDR   (AT91_CAST(AT91_REG *) 	0x40088028) // (TC6) Interrupt Disable Register
#define AT91C_TC6_RB    (AT91_CAST(AT91_REG *) 	0x40088018) // (TC6) Register B
#define AT91C_TC6_CV    (AT91_CAST(AT91_REG *) 	0x40088010) // (TC6) Counter Value
#define AT91C_TC6_CCR   (AT91_CAST(AT91_REG *) 	0x40088000) // (TC6) Channel Control Register
#define AT91C_TC6_IMR   (AT91_CAST(AT91_REG *) 	0x4008802C) // (TC6) Interrupt Mask Register
#define AT91C_TC6_RC    (AT91_CAST(AT91_REG *) 	0x4008801C) // (TC6) Register C
#define AT91C_TC6_IER   (AT91_CAST(AT91_REG *) 	0x40088024) // (TC6) Interrupt Enable Register
#define AT91C_TC6_SR    (AT91_CAST(AT91_REG *) 	0x40088020) // (TC6) Status Register
#define AT91C_TC6_CMR   (AT91_CAST(AT91_REG *) 	0x40088004) // (TC6) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC6_RA    (AT91_CAST(AT91_REG *) 	0x40088014) // (TC6) Register A
// ========== Register definition for TCB6 peripheral ========== 
#define AT91C_TCB6_BMR  (AT91_CAST(AT91_REG *) 	0x400880C4) // (TCB6) TC Block Mode Register
#define AT91C_TCB6_VER  (AT91_CAST(AT91_REG *) 	0x400880FC) // (TCB6)  Version Register
#define AT91C_TCB6_FEATURES (AT91_CAST(AT91_REG *) 	0x400880F8) // (TCB6) TC FEATURES REGISTER 
#define AT91C_TCB6_BCR  (AT91_CAST(AT91_REG *) 	0x400880C0) // (TCB6) TC Block Control Register
#define AT91C_TCB6_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400880F4) // (TCB6) TC IPNAME2 REGISTER 
#define AT91C_TCB6_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400880F0) // (TCB6) TC IPNAME1 REGISTER 
#define AT91C_TCB6_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400880EC) // (TCB6) TC ADDRSIZE REGISTER 
// ========== Register definition for TC7 peripheral ========== 
#define AT91C_TC7_SR    (AT91_CAST(AT91_REG *) 	0x40088060) // (TC7) Status Register
#define AT91C_TC7_RA    (AT91_CAST(AT91_REG *) 	0x40088054) // (TC7) Register A
#define AT91C_TC7_IDR   (AT91_CAST(AT91_REG *) 	0x40088068) // (TC7) Interrupt Disable Register
#define AT91C_TC7_IMR   (AT91_CAST(AT91_REG *) 	0x4008806C) // (TC7) Interrupt Mask Register
#define AT91C_TC7_CCR   (AT91_CAST(AT91_REG *) 	0x40088040) // (TC7) Channel Control Register
#define AT91C_TC7_IER   (AT91_CAST(AT91_REG *) 	0x40088064) // (TC7) Interrupt Enable Register
#define AT91C_TC7_RC    (AT91_CAST(AT91_REG *) 	0x4008805C) // (TC7) Register C
#define AT91C_TC7_CMR   (AT91_CAST(AT91_REG *) 	0x40088044) // (TC7) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC7_CV    (AT91_CAST(AT91_REG *) 	0x40088050) // (TC7) Counter Value
#define AT91C_TC7_RB    (AT91_CAST(AT91_REG *) 	0x40088058) // (TC7) Register B
// ========== Register definition for TCB7 peripheral ========== 
#define AT91C_TCB7_BMR  (AT91_CAST(AT91_REG *) 	0x40088104) // (TCB7) TC Block Mode Register
#define AT91C_TCB7_BCR  (AT91_CAST(AT91_REG *) 	0x40088100) // (TCB7) TC Block Control Register
#define AT91C_TCB7_IPNAME2 (AT91_CAST(AT91_REG *) 	0x40088134) // (TCB7) TC IPNAME2 REGISTER 
#define AT91C_TCB7_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4008812C) // (TCB7) TC ADDRSIZE REGISTER 
#define AT91C_TCB7_FEATURES (AT91_CAST(AT91_REG *) 	0x40088138) // (TCB7) TC FEATURES REGISTER 
#define AT91C_TCB7_IPNAME1 (AT91_CAST(AT91_REG *) 	0x40088130) // (TCB7) TC IPNAME1 REGISTER 
#define AT91C_TCB7_VER  (AT91_CAST(AT91_REG *) 	0x4008813C) // (TCB7)  Version Register
// ========== Register definition for TC8 peripheral ========== 
#define AT91C_TC8_CV    (AT91_CAST(AT91_REG *) 	0x40088090) // (TC8) Counter Value
#define AT91C_TC8_CMR   (AT91_CAST(AT91_REG *) 	0x40088084) // (TC8) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC8_IER   (AT91_CAST(AT91_REG *) 	0x400880A4) // (TC8) Interrupt Enable Register
#define AT91C_TC8_RA    (AT91_CAST(AT91_REG *) 	0x40088094) // (TC8) Register A
#define AT91C_TC8_RB    (AT91_CAST(AT91_REG *) 	0x40088098) // (TC8) Register B
#define AT91C_TC8_RC    (AT91_CAST(AT91_REG *) 	0x4008809C) // (TC8) Register C
#define AT91C_TC8_IMR   (AT91_CAST(AT91_REG *) 	0x400880AC) // (TC8) Interrupt Mask Register
#define AT91C_TC8_IDR   (AT91_CAST(AT91_REG *) 	0x400880A8) // (TC8) Interrupt Disable Register
#define AT91C_TC8_CCR   (AT91_CAST(AT91_REG *) 	0x40088080) // (TC8) Channel Control Register
#define AT91C_TC8_SR    (AT91_CAST(AT91_REG *) 	0x400880A0) // (TC8) Status Register
// ========== Register definition for TCB8 peripheral ========== 
#define AT91C_TCB8_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4008816C) // (TCB8) TC ADDRSIZE REGISTER 
#define AT91C_TCB8_BCR  (AT91_CAST(AT91_REG *) 	0x40088140) // (TCB8) TC Block Control Register
#define AT91C_TCB8_IPNAME1 (AT91_CAST(AT91_REG *) 	0x40088170) // (TCB8) TC IPNAME1 REGISTER 
#define AT91C_TCB8_FEATURES (AT91_CAST(AT91_REG *) 	0x40088178) // (TCB8) TC FEATURES REGISTER 
#define AT91C_TCB8_IPNAME2 (AT91_CAST(AT91_REG *) 	0x40088174) // (TCB8) TC IPNAME2 REGISTER 
#define AT91C_TCB8_VER  (AT91_CAST(AT91_REG *) 	0x4008817C) // (TCB8)  Version Register
#define AT91C_TCB8_BMR  (AT91_CAST(AT91_REG *) 	0x40088144) // (TCB8) TC Block Mode Register
// ========== Register definition for PWMC_CH0 peripheral ========== 
#define AT91C_PWMC_CH0_DTR (AT91_CAST(AT91_REG *) 	0x40094218) // (PWMC_CH0) Channel Dead Time Value Register
#define AT91C_PWMC_CH0_CCNTR (AT91_CAST(AT91_REG *) 	0x40094214) // (PWMC_CH0) Channel Counter Register
#define AT91C_PWMC_CH0_CDTYR (AT91_CAST(AT91_REG *) 	0x40094204) // (PWMC_CH0) Channel Duty Cycle Register
#define AT91C_PWMC_CH0_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x40094208) // (PWMC_CH0) Channel Duty Cycle Update Register
#define AT91C_PWMC_CH0_CMR (AT91_CAST(AT91_REG *) 	0x40094200) // (PWMC_CH0) Channel Mode Register
#define AT91C_PWMC_CH0_DTUPDR (AT91_CAST(AT91_REG *) 	0x4009421C) // (PWMC_CH0) Channel Dead Time Update Value Register
#define AT91C_PWMC_CH0_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x40094210) // (PWMC_CH0) Channel Period Update Register
#define AT91C_PWMC_CH0_CPRDR (AT91_CAST(AT91_REG *) 	0x4009420C) // (PWMC_CH0) Channel Period Register
// ========== Register definition for PWMC_CH1 peripheral ========== 
#define AT91C_PWMC_CH1_CPRDR (AT91_CAST(AT91_REG *) 	0x4009422C) // (PWMC_CH1) Channel Period Register
#define AT91C_PWMC_CH1_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x40094228) // (PWMC_CH1) Channel Duty Cycle Update Register
#define AT91C_PWMC_CH1_DTR (AT91_CAST(AT91_REG *) 	0x40094238) // (PWMC_CH1) Channel Dead Time Value Register
#define AT91C_PWMC_CH1_CCNTR (AT91_CAST(AT91_REG *) 	0x40094234) // (PWMC_CH1) Channel Counter Register
#define AT91C_PWMC_CH1_CMR (AT91_CAST(AT91_REG *) 	0x40094220) // (PWMC_CH1) Channel Mode Register
#define AT91C_PWMC_CH1_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x40094230) // (PWMC_CH1) Channel Period Update Register
#define AT91C_PWMC_CH1_CDTYR (AT91_CAST(AT91_REG *) 	0x40094224) // (PWMC_CH1) Channel Duty Cycle Register
#define AT91C_PWMC_CH1_DTUPDR (AT91_CAST(AT91_REG *) 	0x4009423C) // (PWMC_CH1) Channel Dead Time Update Value Register
// ========== Register definition for PWMC_CH2 peripheral ========== 
#define AT91C_PWMC_CH2_DTR (AT91_CAST(AT91_REG *) 	0x40094258) // (PWMC_CH2) Channel Dead Time Value Register
#define AT91C_PWMC_CH2_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x40094250) // (PWMC_CH2) Channel Period Update Register
#define AT91C_PWMC_CH2_CMR (AT91_CAST(AT91_REG *) 	0x40094240) // (PWMC_CH2) Channel Mode Register
#define AT91C_PWMC_CH2_CPRDR (AT91_CAST(AT91_REG *) 	0x4009424C) // (PWMC_CH2) Channel Period Register
#define AT91C_PWMC_CH2_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x40094248) // (PWMC_CH2) Channel Duty Cycle Update Register
#define AT91C_PWMC_CH2_DTUPDR (AT91_CAST(AT91_REG *) 	0x4009425C) // (PWMC_CH2) Channel Dead Time Update Value Register
#define AT91C_PWMC_CH2_CDTYR (AT91_CAST(AT91_REG *) 	0x40094244) // (PWMC_CH2) Channel Duty Cycle Register
#define AT91C_PWMC_CH2_CCNTR (AT91_CAST(AT91_REG *) 	0x40094254) // (PWMC_CH2) Channel Counter Register
// ========== Register definition for PWMC_CH3 peripheral ========== 
#define AT91C_PWMC_CH3_CCNTR (AT91_CAST(AT91_REG *) 	0x40094274) // (PWMC_CH3) Channel Counter Register
#define AT91C_PWMC_CH3_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x40094268) // (PWMC_CH3) Channel Duty Cycle Update Register
#define AT91C_PWMC_CH3_DTR (AT91_CAST(AT91_REG *) 	0x40094278) // (PWMC_CH3) Channel Dead Time Value Register
#define AT91C_PWMC_CH3_CPRDR (AT91_CAST(AT91_REG *) 	0x4009426C) // (PWMC_CH3) Channel Period Register
#define AT91C_PWMC_CH3_CDTYR (AT91_CAST(AT91_REG *) 	0x40094264) // (PWMC_CH3) Channel Duty Cycle Register
#define AT91C_PWMC_CH3_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x40094270) // (PWMC_CH3) Channel Period Update Register
#define AT91C_PWMC_CH3_CMR (AT91_CAST(AT91_REG *) 	0x40094260) // (PWMC_CH3) Channel Mode Register
#define AT91C_PWMC_CH3_DTUPDR (AT91_CAST(AT91_REG *) 	0x4009427C) // (PWMC_CH3) Channel Dead Time Update Value Register
// ========== Register definition for PWMC_CH4 peripheral ========== 
#define AT91C_PWMC_CH4_DTUPDR (AT91_CAST(AT91_REG *) 	0x4009429C) // (PWMC_CH4) Channel Dead Time Update Value Register
#define AT91C_PWMC_CH4_CMR (AT91_CAST(AT91_REG *) 	0x40094280) // (PWMC_CH4) Channel Mode Register
#define AT91C_PWMC_CH4_CPRDR (AT91_CAST(AT91_REG *) 	0x4009428C) // (PWMC_CH4) Channel Period Register
#define AT91C_PWMC_CH4_CDTYR (AT91_CAST(AT91_REG *) 	0x40094284) // (PWMC_CH4) Channel Duty Cycle Register
#define AT91C_PWMC_CH4_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x40094290) // (PWMC_CH4) Channel Period Update Register
#define AT91C_PWMC_CH4_DTR (AT91_CAST(AT91_REG *) 	0x40094298) // (PWMC_CH4) Channel Dead Time Value Register
#define AT91C_PWMC_CH4_CCNTR (AT91_CAST(AT91_REG *) 	0x40094294) // (PWMC_CH4) Channel Counter Register
#define AT91C_PWMC_CH4_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x40094288) // (PWMC_CH4) Channel Duty Cycle Update Register
// ========== Register definition for PWMC_CH5 peripheral ========== 
#define AT91C_PWMC_CH5_DTR (AT91_CAST(AT91_REG *) 	0x400942B8) // (PWMC_CH5) Channel Dead Time Value Register
#define AT91C_PWMC_CH5_CPRDR (AT91_CAST(AT91_REG *) 	0x400942AC) // (PWMC_CH5) Channel Period Register
#define AT91C_PWMC_CH5_CDTYR (AT91_CAST(AT91_REG *) 	0x400942A4) // (PWMC_CH5) Channel Duty Cycle Register
#define AT91C_PWMC_CH5_DTUPDR (AT91_CAST(AT91_REG *) 	0x400942BC) // (PWMC_CH5) Channel Dead Time Update Value Register
#define AT91C_PWMC_CH5_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x400942A8) // (PWMC_CH5) Channel Duty Cycle Update Register
#define AT91C_PWMC_CH5_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x400942B0) // (PWMC_CH5) Channel Period Update Register
#define AT91C_PWMC_CH5_CMR (AT91_CAST(AT91_REG *) 	0x400942A0) // (PWMC_CH5) Channel Mode Register
#define AT91C_PWMC_CH5_CCNTR (AT91_CAST(AT91_REG *) 	0x400942B4) // (PWMC_CH5) Channel Counter Register
// ========== Register definition for PWMC_CH6 peripheral ========== 
#define AT91C_PWMC_CH6_CPRDR (AT91_CAST(AT91_REG *) 	0x400942CC) // (PWMC_CH6) Channel Period Register
#define AT91C_PWMC_CH6_DTR (AT91_CAST(AT91_REG *) 	0x400942D8) // (PWMC_CH6) Channel Dead Time Value Register
#define AT91C_PWMC_CH6_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x400942D0) // (PWMC_CH6) Channel Period Update Register
#define AT91C_PWMC_CH6_CCNTR (AT91_CAST(AT91_REG *) 	0x400942D4) // (PWMC_CH6) Channel Counter Register
#define AT91C_PWMC_CH6_CDTYR (AT91_CAST(AT91_REG *) 	0x400942C4) // (PWMC_CH6) Channel Duty Cycle Register
#define AT91C_PWMC_CH6_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x400942C8) // (PWMC_CH6) Channel Duty Cycle Update Register
#define AT91C_PWMC_CH6_CMR (AT91_CAST(AT91_REG *) 	0x400942C0) // (PWMC_CH6) Channel Mode Register
#define AT91C_PWMC_CH6_DTUPDR (AT91_CAST(AT91_REG *) 	0x400942DC) // (PWMC_CH6) Channel Dead Time Update Value Register
// ========== Register definition for PWMC_CH7 peripheral ========== 
#define AT91C_PWMC_CH7_DTUPDR (AT91_CAST(AT91_REG *) 	0x400942FC) // (PWMC_CH7) Channel Dead Time Update Value Register
#define AT91C_PWMC_CH7_DTR (AT91_CAST(AT91_REG *) 	0x400942F8) // (PWMC_CH7) Channel Dead Time Value Register
#define AT91C_PWMC_CH7_CCNTR (AT91_CAST(AT91_REG *) 	0x400942F4) // (PWMC_CH7) Channel Counter Register
#define AT91C_PWMC_CH7_CMR (AT91_CAST(AT91_REG *) 	0x400942E0) // (PWMC_CH7) Channel Mode Register
#define AT91C_PWMC_CH7_CDTYR (AT91_CAST(AT91_REG *) 	0x400942E4) // (PWMC_CH7) Channel Duty Cycle Register
#define AT91C_PWMC_CH7_CPRDR (AT91_CAST(AT91_REG *) 	0x400942EC) // (PWMC_CH7) Channel Period Register
#define AT91C_PWMC_CH7_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x400942E8) // (PWMC_CH7) Channel Duty Cycle Update Register
#define AT91C_PWMC_CH7_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x400942F0) // (PWMC_CH7) Channel Period Update Register
// ========== Register definition for PDC_PWMC peripheral ========== 
#define AT91C_PWMC_TNPR (AT91_CAST(AT91_REG *) 	0x40094118) // (PDC_PWMC) Transmit Next Pointer Register
#define AT91C_PWMC_TPR  (AT91_CAST(AT91_REG *) 	0x40094108) // (PDC_PWMC) Transmit Pointer Register
#define AT91C_PWMC_RNCR (AT91_CAST(AT91_REG *) 	0x40094114) // (PDC_PWMC) Receive Next Counter Register
#define AT91C_PWMC_TNCR (AT91_CAST(AT91_REG *) 	0x4009411C) // (PDC_PWMC) Transmit Next Counter Register
#define AT91C_PWMC_RNPR (AT91_CAST(AT91_REG *) 	0x40094110) // (PDC_PWMC) Receive Next Pointer Register
#define AT91C_PWMC_TCR  (AT91_CAST(AT91_REG *) 	0x4009410C) // (PDC_PWMC) Transmit Counter Register
#define AT91C_PWMC_PTSR (AT91_CAST(AT91_REG *) 	0x40094124) // (PDC_PWMC) PDC Transfer Status Register
#define AT91C_PWMC_RCR  (AT91_CAST(AT91_REG *) 	0x40094104) // (PDC_PWMC) Receive Counter Register
#define AT91C_PWMC_RPR  (AT91_CAST(AT91_REG *) 	0x40094100) // (PDC_PWMC) Receive Pointer Register
#define AT91C_PWMC_PTCR (AT91_CAST(AT91_REG *) 	0x40094120) // (PDC_PWMC) PDC Transfer Control Register
// ========== Register definition for PWMC peripheral ========== 
#define AT91C_PWMC_EL5MR (AT91_CAST(AT91_REG *) 	0x40094090) // (PWMC) PWM Event Line 5 Mode Register
#define AT91C_PWMC_FPER3 (AT91_CAST(AT91_REG *) 	0x40094074) // (PWMC) PWM Fault Protection Enable Register 3
#define AT91C_PWMC_CMP6V (AT91_CAST(AT91_REG *) 	0x40094190) // (PWMC) PWM Comparison Value 6 Register
#define AT91C_PWMC_CMP5M (AT91_CAST(AT91_REG *) 	0x40094188) // (PWMC) PWM Comparison Mode 5 Register
#define AT91C_PWMC_CMP2V (AT91_CAST(AT91_REG *) 	0x40094150) // (PWMC) PWM Comparison Value 2 Register
#define AT91C_PWMC_CMP0VUPD (AT91_CAST(AT91_REG *) 	0x40094134) // (PWMC) PWM Comparison Value 0 Update Register
#define AT91C_PWMC_WPCR (AT91_CAST(AT91_REG *) 	0x400940E4) // (PWMC) PWM Write Protection Enable Register
#define AT91C_PWMC_CMP6M (AT91_CAST(AT91_REG *) 	0x40094198) // (PWMC) PWM Comparison Mode 6 Register
#define AT91C_PWMC_CMP2M (AT91_CAST(AT91_REG *) 	0x40094158) // (PWMC) PWM Comparison Mode 2 Register
#define AT91C_PWMC_CMP5VUPD (AT91_CAST(AT91_REG *) 	0x40094184) // (PWMC) PWM Comparison Value 5 Update Register
#define AT91C_PWMC_FMR  (AT91_CAST(AT91_REG *) 	0x4009405C) // (PWMC) PWM Fault Mode Register
#define AT91C_PWMC_UPCR (AT91_CAST(AT91_REG *) 	0x40094028) // (PWMC) PWM Update Control Register
#define AT91C_PWMC_CMP1VUPD (AT91_CAST(AT91_REG *) 	0x40094144) // (PWMC) PWM Comparison Value 1 Update Register
#define AT91C_PWMC_CMP4M (AT91_CAST(AT91_REG *) 	0x40094178) // (PWMC) PWM Comparison Mode 4 Register
#define AT91C_PWMC_CMP7M (AT91_CAST(AT91_REG *) 	0x400941A8) // (PWMC) PWM Comparison Mode 7 Register
#define AT91C_PWMC_CMP3M (AT91_CAST(AT91_REG *) 	0x40094168) // (PWMC) PWM Comparison Mode 3 Register
#define AT91C_PWMC_CMP6MUPD (AT91_CAST(AT91_REG *) 	0x4009419C) // (PWMC) PWM Comparison Mode 6 Update Register
#define AT91C_PWMC_IER1 (AT91_CAST(AT91_REG *) 	0x40094010) // (PWMC) PWMC Interrupt Enable Register 1
#define AT91C_PWMC_WPSR (AT91_CAST(AT91_REG *) 	0x400940E8) // (PWMC) PWM Write Protection Status Register
#define AT91C_PWMC_CMP2MUPD (AT91_CAST(AT91_REG *) 	0x4009415C) // (PWMC) PWM Comparison Mode 2 Update Register
#define AT91C_PWMC_CMP4VUPD (AT91_CAST(AT91_REG *) 	0x40094174) // (PWMC) PWM Comparison Value 4 Update Register
#define AT91C_PWMC_CMP3V (AT91_CAST(AT91_REG *) 	0x40094160) // (PWMC) PWM Comparison Value 3 Register
#define AT91C_PWMC_FPV  (AT91_CAST(AT91_REG *) 	0x40094068) // (PWMC) PWM Fault Protection Value Register
#define AT91C_PWMC_OSSUPD (AT91_CAST(AT91_REG *) 	0x40094054) // (PWMC) PWM Output Selection Set Update Register
#define AT91C_PWMC_CMP1M (AT91_CAST(AT91_REG *) 	0x40094148) // (PWMC) PWM Comparison Mode 1 Register
#define AT91C_PWMC_CMP4V (AT91_CAST(AT91_REG *) 	0x40094170) // (PWMC) PWM Comparison Value 4 Register
#define AT91C_PWMC_CMP6VUPD (AT91_CAST(AT91_REG *) 	0x40094194) // (PWMC) PWM Comparison Value 6 Update Register
#define AT91C_PWMC_EL6MR (AT91_CAST(AT91_REG *) 	0x40094094) // (PWMC) PWM Event Line 6 Mode Register
#define AT91C_PWMC_CMP0M (AT91_CAST(AT91_REG *) 	0x40094138) // (PWMC) PWM Comparison Mode 0 Register
#define AT91C_PWMC_EL7MR (AT91_CAST(AT91_REG *) 	0x40094098) // (PWMC) PWM Event Line 7 Mode Register
#define AT91C_PWMC_OSC  (AT91_CAST(AT91_REG *) 	0x40094050) // (PWMC) PWM Output Selection Clear Register
#define AT91C_PWMC_SR   (AT91_CAST(AT91_REG *) 	0x4009400C) // (PWMC) PWMC Status Register
#define AT91C_PWMC_EL0MR (AT91_CAST(AT91_REG *) 	0x4009407C) // (PWMC) PWM Event Line 0 Mode Register
#define AT91C_PWMC_CMP0V (AT91_CAST(AT91_REG *) 	0x40094130) // (PWMC) PWM Comparison Value 0 Register
#define AT91C_PWMC_IDR2 (AT91_CAST(AT91_REG *) 	0x40094038) // (PWMC) PWMC Interrupt Disable Register 2
#define AT91C_PWMC_IMR1 (AT91_CAST(AT91_REG *) 	0x40094018) // (PWMC) PWMC Interrupt Mask Register 1
#define AT91C_PWMC_OS   (AT91_CAST(AT91_REG *) 	0x40094048) // (PWMC) PWM Output Selection Register
#define AT91C_PWMC_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400940F0) // (PWMC) PWMC IPNAME1 REGISTER 
#define AT91C_PWMC_VER  (AT91_CAST(AT91_REG *) 	0x400940FC) // (PWMC) PWMC Version Register
#define AT91C_PWMC_ENA  (AT91_CAST(AT91_REG *) 	0x40094004) // (PWMC) PWMC Enable Register
#define AT91C_PWMC_FEATURES (AT91_CAST(AT91_REG *) 	0x400940F8) // (PWMC) PWMC FEATURES REGISTER 
#define AT91C_PWMC_CMP7VUPD (AT91_CAST(AT91_REG *) 	0x400941A4) // (PWMC) PWM Comparison Value 7 Update Register
#define AT91C_PWMC_SCUP (AT91_CAST(AT91_REG *) 	0x4009402C) // (PWMC) PWM Update Period Register
#define AT91C_PWMC_OOV  (AT91_CAST(AT91_REG *) 	0x40094044) // (PWMC) PWM Output Override Value Register
#define AT91C_PWMC_FPER4 (AT91_CAST(AT91_REG *) 	0x40094078) // (PWMC) PWM Fault Protection Enable Register 4
#define AT91C_PWMC_CMP7V (AT91_CAST(AT91_REG *) 	0x400941A0) // (PWMC) PWM Comparison Value 7 Register
#define AT91C_PWMC_IER2 (AT91_CAST(AT91_REG *) 	0x40094034) // (PWMC) PWMC Interrupt Enable Register 2
#define AT91C_PWMC_SYNC (AT91_CAST(AT91_REG *) 	0x40094020) // (PWMC) PWM Synchronized Channels Register
#define AT91C_PWMC_MR   (AT91_CAST(AT91_REG *) 	0x40094000) // (PWMC) PWMC Mode Register
#define AT91C_PWMC_FCR  (AT91_CAST(AT91_REG *) 	0x40094064) // (PWMC) PWM Fault Mode Clear Register
#define AT91C_PWMC_CMP7MUPD (AT91_CAST(AT91_REG *) 	0x400941AC) // (PWMC) PWM Comparison Mode 7 Update Register
#define AT91C_PWMC_CMP4MUPD (AT91_CAST(AT91_REG *) 	0x4009417C) // (PWMC) PWM Comparison Mode 4 Update Register
#define AT91C_PWMC_IMR2 (AT91_CAST(AT91_REG *) 	0x4009403C) // (PWMC) PWMC Interrupt Mask Register 2
#define AT91C_PWMC_FPER2 (AT91_CAST(AT91_REG *) 	0x40094070) // (PWMC) PWM Fault Protection Enable Register 2
#define AT91C_PWMC_CMP3VUPD (AT91_CAST(AT91_REG *) 	0x40094164) // (PWMC) PWM Comparison Value 3 Update Register
#define AT91C_PWMC_OSCUPD (AT91_CAST(AT91_REG *) 	0x40094058) // (PWMC) PWM Output Selection Clear Update Register
#define AT91C_PWMC_CMP0MUPD (AT91_CAST(AT91_REG *) 	0x4009413C) // (PWMC) PWM Comparison Mode 0 Update Register
#define AT91C_PWMC_FSR  (AT91_CAST(AT91_REG *) 	0x40094060) // (PWMC) PWM Fault Mode Status Register
#define AT91C_PWMC_EL4MR (AT91_CAST(AT91_REG *) 	0x4009408C) // (PWMC) PWM Event Line 4 Mode Register
#define AT91C_PWMC_SCUPUPD (AT91_CAST(AT91_REG *) 	0x40094030) // (PWMC) PWM Update Period Update Register
#define AT91C_PWMC_EL1MR (AT91_CAST(AT91_REG *) 	0x40094080) // (PWMC) PWM Event Line 1 Mode Register
#define AT91C_PWMC_FPER1 (AT91_CAST(AT91_REG *) 	0x4009406C) // (PWMC) PWM Fault Protection Enable Register 1
#define AT91C_PWMC_EL2MR (AT91_CAST(AT91_REG *) 	0x40094084) // (PWMC) PWM Event Line 2 Mode Register
#define AT91C_PWMC_CMP5V (AT91_CAST(AT91_REG *) 	0x40094180) // (PWMC) PWM Comparison Value 5 Register
#define AT91C_PWMC_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400940F4) // (PWMC) PWMC IPNAME2 REGISTER 
#define AT91C_PWMC_CMP3MUPD (AT91_CAST(AT91_REG *) 	0x4009416C) // (PWMC) PWM Comparison Mode 3 Update Register
#define AT91C_PWMC_OSS  (AT91_CAST(AT91_REG *) 	0x4009404C) // (PWMC) PWM Output Selection Set Register
#define AT91C_PWMC_EL3MR (AT91_CAST(AT91_REG *) 	0x40094088) // (PWMC) PWM Event Line 3 Mode Register
#define AT91C_PWMC_CMP1V (AT91_CAST(AT91_REG *) 	0x40094140) // (PWMC) PWM Comparison Value 1 Register
#define AT91C_PWMC_DIS  (AT91_CAST(AT91_REG *) 	0x40094008) // (PWMC) PWMC Disable Register
#define AT91C_PWMC_CMP5MUPD (AT91_CAST(AT91_REG *) 	0x4009418C) // (PWMC) PWM Comparison Mode 5 Update Register
#define AT91C_PWMC_CMP2VUPD (AT91_CAST(AT91_REG *) 	0x40094154) // (PWMC) PWM Comparison Value 2 Update Register
#define AT91C_PWMC_ISR2 (AT91_CAST(AT91_REG *) 	0x40094040) // (PWMC) PWMC Interrupt Status Register 2
#define AT91C_PWMC_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400940EC) // (PWMC) PWMC ADDRSIZE REGISTER 
#define AT91C_PWMC_IDR1 (AT91_CAST(AT91_REG *) 	0x40094014) // (PWMC) PWMC Interrupt Disable Register 1
#define AT91C_PWMC_ISR1 (AT91_CAST(AT91_REG *) 	0x4009401C) // (PWMC) PWMC Interrupt Status Register 1
#define AT91C_PWMC_CMP1MUPD (AT91_CAST(AT91_REG *) 	0x4009414C) // (PWMC) PWM Comparison Mode 1 Update Register
// ========== Register definition for PDC_ADCC peripheral ========== 
#define AT91C_ADCC_TNCR (AT91_CAST(AT91_REG *) 	0x400C011C) // (PDC_ADCC) Transmit Next Counter Register
#define AT91C_ADCC_PTCR (AT91_CAST(AT91_REG *) 	0x400C0120) // (PDC_ADCC) PDC Transfer Control Register
#define AT91C_ADCC_TPR  (AT91_CAST(AT91_REG *) 	0x400C0108) // (PDC_ADCC) Transmit Pointer Register
#define AT91C_ADCC_TNPR (AT91_CAST(AT91_REG *) 	0x400C0118) // (PDC_ADCC) Transmit Next Pointer Register
#define AT91C_ADCC_RCR  (AT91_CAST(AT91_REG *) 	0x400C0104) // (PDC_ADCC) Receive Counter Register
#define AT91C_ADCC_TCR  (AT91_CAST(AT91_REG *) 	0x400C010C) // (PDC_ADCC) Transmit Counter Register
#define AT91C_ADCC_RNCR (AT91_CAST(AT91_REG *) 	0x400C0114) // (PDC_ADCC) Receive Next Counter Register
#define AT91C_ADCC_PTSR (AT91_CAST(AT91_REG *) 	0x400C0124) // (PDC_ADCC) PDC Transfer Status Register
#define AT91C_ADCC_RPR  (AT91_CAST(AT91_REG *) 	0x400C0100) // (PDC_ADCC) Receive Pointer Register
#define AT91C_ADCC_RNPR (AT91_CAST(AT91_REG *) 	0x400C0110) // (PDC_ADCC) Receive Next Pointer Register
// ========== Register definition for ADCC peripheral ========== 
#define AT91C_ADCC_CDR4 (AT91_CAST(AT91_REG *) 	0x400C0060) // (ADCC) ADC Channel Data Register 4
#define AT91C_ADCC_CDR10 (AT91_CAST(AT91_REG *) 	0x400C0078) // (ADCC) ADC Channel Data Register 10
#define AT91C_ADCC_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400C00F0) // (ADCC) ADC IPNAME1 REGISTER 
#define AT91C_ADCC_IDR  (AT91_CAST(AT91_REG *) 	0x400C0028) // (ADCC) ADC Interrupt Disable Register
#define AT91C_ADCC_IER  (AT91_CAST(AT91_REG *) 	0x400C0024) // (ADCC) ADC Interrupt Enable Register
#define AT91C_ADCC_CDR2 (AT91_CAST(AT91_REG *) 	0x400C0058) // (ADCC) ADC Channel Data Register 2
#define AT91C_ADCC_ACR  (AT91_CAST(AT91_REG *) 	0x400C0094) // (ADCC) unspecified
#define AT91C_ADCC_CDR3 (AT91_CAST(AT91_REG *) 	0x400C005C) // (ADCC) ADC Channel Data Register 3
#define AT91C_ADCC_CDR12 (AT91_CAST(AT91_REG *) 	0x400C0080) // (ADCC) ADC Channel Data Register 12
#define AT91C_ADCC_FEATURES (AT91_CAST(AT91_REG *) 	0x400C00F8) // (ADCC) ADC FEATURES REGISTER 
#define AT91C_ADCC_CDR15 (AT91_CAST(AT91_REG *) 	0x400C008C) // (ADCC) ADC Channel Data Register 15
#define AT91C_ADCC_CDR7 (AT91_CAST(AT91_REG *) 	0x400C006C) // (ADCC) ADC Channel Data Register 7
#define AT91C_ADCC_CHDR (AT91_CAST(AT91_REG *) 	0x400C0014) // (ADCC) ADC Channel Disable Register
#define AT91C_ADCC_CDR0 (AT91_CAST(AT91_REG *) 	0x400C0050) // (ADCC) ADC Channel Data Register 0
#define AT91C_ADCC_CWR  (AT91_CAST(AT91_REG *) 	0x400C0040) // (ADCC) unspecified
#define AT91C_ADCC_CDR1 (AT91_CAST(AT91_REG *) 	0x400C0054) // (ADCC) ADC Channel Data Register 1
#define AT91C_ADCC_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400C00EC) // (ADCC) ADC ADDRSIZE REGISTER 
#define AT91C_ADCC_CDR5 (AT91_CAST(AT91_REG *) 	0x400C0064) // (ADCC) ADC Channel Data Register 5
#define AT91C_ADCC_IMR  (AT91_CAST(AT91_REG *) 	0x400C002C) // (ADCC) ADC Interrupt Mask Register
#define AT91C_ADCC_CDR9 (AT91_CAST(AT91_REG *) 	0x400C0074) // (ADCC) ADC Channel Data Register 9
#define AT91C_ADCC_CGR  (AT91_CAST(AT91_REG *) 	0x400C0048) // (ADCC) Control gain register
#define AT91C_ADCC_COR  (AT91_CAST(AT91_REG *) 	0x400C004C) // (ADCC) unspecified
#define AT91C_ADCC_MR   (AT91_CAST(AT91_REG *) 	0x400C0004) // (ADCC) ADC Mode Register
#define AT91C_ADCC_CDR14 (AT91_CAST(AT91_REG *) 	0x400C0088) // (ADCC) ADC Channel Data Register 14
#define AT91C_ADCC_VER  (AT91_CAST(AT91_REG *) 	0x400C00FC) // (ADCC) ADC VERSION REGISTER
#define AT91C_ADCC_CDR11 (AT91_CAST(AT91_REG *) 	0x400C007C) // (ADCC) ADC Channel Data Register 11
#define AT91C_ADCC_CR   (AT91_CAST(AT91_REG *) 	0x400C0000) // (ADCC) ADC Control Register
#define AT91C_ADCC_CWSR (AT91_CAST(AT91_REG *) 	0x400C0044) // (ADCC) unspecified
#define AT91C_ADCC_LCDR (AT91_CAST(AT91_REG *) 	0x400C0020) // (ADCC) ADC Last Converted Data Register
#define AT91C_ADCC_OVR  (AT91_CAST(AT91_REG *) 	0x400C003C) // (ADCC) unspecified
#define AT91C_ADCC_CDR8 (AT91_CAST(AT91_REG *) 	0x400C0070) // (ADCC) ADC Channel Data Register 8
#define AT91C_ADCC_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400C00F4) // (ADCC) ADC IPNAME2 REGISTER 
#define AT91C_ADCC_CHER (AT91_CAST(AT91_REG *) 	0x400C0010) // (ADCC) ADC Channel Enable Register
#define AT91C_ADCC_SR   (AT91_CAST(AT91_REG *) 	0x400C0030) // (ADCC) ADC Status Register
#define AT91C_ADCC_CDR13 (AT91_CAST(AT91_REG *) 	0x400C0084) // (ADCC) ADC Channel Data Register 13
#define AT91C_ADCC_CDR6 (AT91_CAST(AT91_REG *) 	0x400C0068) // (ADCC) ADC Channel Data Register 6
#define AT91C_ADCC_CHSR (AT91_CAST(AT91_REG *) 	0x400C0018) // (ADCC) ADC Channel Status Register
// ========== Register definition for PDC_DACC peripheral ========== 
#define AT91C_DACC_TNCR (AT91_CAST(AT91_REG *) 	0x400C811C) // (PDC_DACC) Transmit Next Counter Register
#define AT91C_DACC_TPR  (AT91_CAST(AT91_REG *) 	0x400C8108) // (PDC_DACC) Transmit Pointer Register
#define AT91C_DACC_TNPR (AT91_CAST(AT91_REG *) 	0x400C8118) // (PDC_DACC) Transmit Next Pointer Register
#define AT91C_DACC_RCR  (AT91_CAST(AT91_REG *) 	0x400C8104) // (PDC_DACC) Receive Counter Register
#define AT91C_DACC_RNPR (AT91_CAST(AT91_REG *) 	0x400C8110) // (PDC_DACC) Receive Next Pointer Register
#define AT91C_DACC_RPR  (AT91_CAST(AT91_REG *) 	0x400C8100) // (PDC_DACC) Receive Pointer Register
#define AT91C_DACC_RNCR (AT91_CAST(AT91_REG *) 	0x400C8114) // (PDC_DACC) Receive Next Counter Register
#define AT91C_DACC_PTSR (AT91_CAST(AT91_REG *) 	0x400C8124) // (PDC_DACC) PDC Transfer Status Register
#define AT91C_DACC_PTCR (AT91_CAST(AT91_REG *) 	0x400C8120) // (PDC_DACC) PDC Transfer Control Register
#define AT91C_DACC_TCR  (AT91_CAST(AT91_REG *) 	0x400C810C) // (PDC_DACC) Transmit Counter Register
// ========== Register definition for DACC peripheral ========== 
#define AT91C_DACC_ACR  (AT91_CAST(AT91_REG *) 	0x400C8094) // (DACC) Analog Current Register
#define AT91C_DACC_IER  (AT91_CAST(AT91_REG *) 	0x400C8024) // (DACC) Interrupt Enable Register
#define AT91C_DACC_CHSR (AT91_CAST(AT91_REG *) 	0x400C8018) // (DACC) Channel Status Register
#define AT91C_DACC_IDR  (AT91_CAST(AT91_REG *) 	0x400C8028) // (DACC) Interrupt Disable Register
#define AT91C_DACC_CDR  (AT91_CAST(AT91_REG *) 	0x400C8020) // (DACC) Coversion Data Register
#define AT91C_DACC_CHER (AT91_CAST(AT91_REG *) 	0x400C8010) // (DACC) Channel Enable Register
#define AT91C_DACC_WPMR (AT91_CAST(AT91_REG *) 	0x400C80E4) // (DACC) Write Protect Mode Register
#define AT91C_DACC_WPSR (AT91_CAST(AT91_REG *) 	0x400C80E8) // (DACC) Write Protect Status Register
#define AT91C_DACC_ISR  (AT91_CAST(AT91_REG *) 	0x400C8030) // (DACC) Interrupt Status Register
#define AT91C_DACC_CHDR (AT91_CAST(AT91_REG *) 	0x400C8014) // (DACC) Channel Disable Register
#define AT91C_DACC_IMR  (AT91_CAST(AT91_REG *) 	0x400C802C) // (DACC) Interrupt Mask Register
#define AT91C_DACC_CR   (AT91_CAST(AT91_REG *) 	0x400C8000) // (DACC) Control Register
#define AT91C_DACC_MR   (AT91_CAST(AT91_REG *) 	0x400C8004) // (DACC) Mode Register
// ========== Register definition for HDMA_CH_0 peripheral ========== 
#define AT91C_HDMA_CH_0_CFG (AT91_CAST(AT91_REG *) 	0x400C4050) // (HDMA_CH_0) HDMA Channel Configuration Register
#define AT91C_HDMA_CH_0_SPIP (AT91_CAST(AT91_REG *) 	0x400C4054) // (HDMA_CH_0) HDMA Channel Source Picture in Picture Configuration Register
#define AT91C_HDMA_CH_0_DPIP (AT91_CAST(AT91_REG *) 	0x400C4058) // (HDMA_CH_0) HDMA Channel Destination Picture in Picture Configuration Register
#define AT91C_HDMA_CH_0_CTRLB (AT91_CAST(AT91_REG *) 	0x400C404C) // (HDMA_CH_0) HDMA Channel Control B Register
#define AT91C_HDMA_CH_0_CTRLA (AT91_CAST(AT91_REG *) 	0x400C4048) // (HDMA_CH_0) HDMA Channel Control A Register
#define AT91C_HDMA_CH_0_DADDR (AT91_CAST(AT91_REG *) 	0x400C4040) // (HDMA_CH_0) HDMA Channel Destination Address Register
#define AT91C_HDMA_CH_0_DSCR (AT91_CAST(AT91_REG *) 	0x400C4044) // (HDMA_CH_0) HDMA Channel Descriptor Address Register
#define AT91C_HDMA_CH_0_CADDR (AT91_CAST(AT91_REG *) 	0x400C4060) // (HDMA_CH_0) HDMA Reserved
#define AT91C_HDMA_CH_0_BDSCR (AT91_CAST(AT91_REG *) 	0x400C405C) // (HDMA_CH_0) HDMA Reserved
#define AT91C_HDMA_CH_0_SADDR (AT91_CAST(AT91_REG *) 	0x400C403C) // (HDMA_CH_0) HDMA Channel Source Address Register
// ========== Register definition for HDMA_CH_1 peripheral ========== 
#define AT91C_HDMA_CH_1_CTRLB (AT91_CAST(AT91_REG *) 	0x400C4074) // (HDMA_CH_1) HDMA Channel Control B Register
#define AT91C_HDMA_CH_1_SPIP (AT91_CAST(AT91_REG *) 	0x400C407C) // (HDMA_CH_1) HDMA Channel Source Picture in Picture Configuration Register
#define AT91C_HDMA_CH_1_DSCR (AT91_CAST(AT91_REG *) 	0x400C406C) // (HDMA_CH_1) HDMA Channel Descriptor Address Register
#define AT91C_HDMA_CH_1_DADDR (AT91_CAST(AT91_REG *) 	0x400C4068) // (HDMA_CH_1) HDMA Channel Destination Address Register
#define AT91C_HDMA_CH_1_DPIP (AT91_CAST(AT91_REG *) 	0x400C4080) // (HDMA_CH_1) HDMA Channel Destination Picture in Picture Configuration Register
#define AT91C_HDMA_CH_1_CFG (AT91_CAST(AT91_REG *) 	0x400C4078) // (HDMA_CH_1) HDMA Channel Configuration Register
#define AT91C_HDMA_CH_1_BDSCR (AT91_CAST(AT91_REG *) 	0x400C4084) // (HDMA_CH_1) HDMA Reserved
#define AT91C_HDMA_CH_1_CADDR (AT91_CAST(AT91_REG *) 	0x400C4088) // (HDMA_CH_1) HDMA Reserved
#define AT91C_HDMA_CH_1_SADDR (AT91_CAST(AT91_REG *) 	0x400C4064) // (HDMA_CH_1) HDMA Channel Source Address Register
#define AT91C_HDMA_CH_1_CTRLA (AT91_CAST(AT91_REG *) 	0x400C4070) // (HDMA_CH_1) HDMA Channel Control A Register
// ========== Register definition for HDMA_CH_2 peripheral ========== 
#define AT91C_HDMA_CH_2_CTRLA (AT91_CAST(AT91_REG *) 	0x400C4098) // (HDMA_CH_2) HDMA Channel Control A Register
#define AT91C_HDMA_CH_2_DADDR (AT91_CAST(AT91_REG *) 	0x400C4090) // (HDMA_CH_2) HDMA Channel Destination Address Register
#define AT91C_HDMA_CH_2_CFG (AT91_CAST(AT91_REG *) 	0x400C40A0) // (HDMA_CH_2) HDMA Channel Configuration Register
#define AT91C_HDMA_CH_2_CTRLB (AT91_CAST(AT91_REG *) 	0x400C409C) // (HDMA_CH_2) HDMA Channel Control B Register
#define AT91C_HDMA_CH_2_CADDR (AT91_CAST(AT91_REG *) 	0x400C40B0) // (HDMA_CH_2) HDMA Reserved
#define AT91C_HDMA_CH_2_SPIP (AT91_CAST(AT91_REG *) 	0x400C40A4) // (HDMA_CH_2) HDMA Channel Source Picture in Picture Configuration Register
#define AT91C_HDMA_CH_2_BDSCR (AT91_CAST(AT91_REG *) 	0x400C40AC) // (HDMA_CH_2) HDMA Reserved
#define AT91C_HDMA_CH_2_DPIP (AT91_CAST(AT91_REG *) 	0x400C40A8) // (HDMA_CH_2) HDMA Channel Destination Picture in Picture Configuration Register
#define AT91C_HDMA_CH_2_SADDR (AT91_CAST(AT91_REG *) 	0x400C408C) // (HDMA_CH_2) HDMA Channel Source Address Register
#define AT91C_HDMA_CH_2_DSCR (AT91_CAST(AT91_REG *) 	0x400C4094) // (HDMA_CH_2) HDMA Channel Descriptor Address Register
// ========== Register definition for HDMA_CH_3 peripheral ========== 
#define AT91C_HDMA_CH_3_DADDR (AT91_CAST(AT91_REG *) 	0x400C40B8) // (HDMA_CH_3) HDMA Channel Destination Address Register
#define AT91C_HDMA_CH_3_BDSCR (AT91_CAST(AT91_REG *) 	0x400C40D4) // (HDMA_CH_3) HDMA Reserved
#define AT91C_HDMA_CH_3_SADDR (AT91_CAST(AT91_REG *) 	0x400C40B4) // (HDMA_CH_3) HDMA Channel Source Address Register
#define AT91C_HDMA_CH_3_SPIP (AT91_CAST(AT91_REG *) 	0x400C40CC) // (HDMA_CH_3) HDMA Channel Source Picture in Picture Configuration Register
#define AT91C_HDMA_CH_3_DSCR (AT91_CAST(AT91_REG *) 	0x400C40BC) // (HDMA_CH_3) HDMA Channel Descriptor Address Register
#define AT91C_HDMA_CH_3_CTRLB (AT91_CAST(AT91_REG *) 	0x400C40C4) // (HDMA_CH_3) HDMA Channel Control B Register
#define AT91C_HDMA_CH_3_CADDR (AT91_CAST(AT91_REG *) 	0x400C40D8) // (HDMA_CH_3) HDMA Reserved
#define AT91C_HDMA_CH_3_CTRLA (AT91_CAST(AT91_REG *) 	0x400C40C0) // (HDMA_CH_3) HDMA Channel Control A Register
#define AT91C_HDMA_CH_3_CFG (AT91_CAST(AT91_REG *) 	0x400C40C8) // (HDMA_CH_3) HDMA Channel Configuration Register
#define AT91C_HDMA_CH_3_DPIP (AT91_CAST(AT91_REG *) 	0x400C40D0) // (HDMA_CH_3) HDMA Channel Destination Picture in Picture Configuration Register
// ========== Register definition for HDMA_CH_4 peripheral ========== 
#define AT91C_HDMA_CH_4_DPIP (AT91_CAST(AT91_REG *) 	0x400C40F8) // (HDMA_CH_4) HDMA Channel Destination Picture in Picture Configuration Register
#define AT91C_HDMA_CH_4_DSCR (AT91_CAST(AT91_REG *) 	0x400C40E4) // (HDMA_CH_4) HDMA Channel Descriptor Address Register
#define AT91C_HDMA_CH_4_BDSCR (AT91_CAST(AT91_REG *) 	0x400C40FC) // (HDMA_CH_4) HDMA Reserved
#define AT91C_HDMA_CH_4_SADDR (AT91_CAST(AT91_REG *) 	0x400C40DC) // (HDMA_CH_4) HDMA Channel Source Address Register
#define AT91C_HDMA_CH_4_SPIP (AT91_CAST(AT91_REG *) 	0x400C40F4) // (HDMA_CH_4) HDMA Channel Source Picture in Picture Configuration Register
#define AT91C_HDMA_CH_4_CTRLA (AT91_CAST(AT91_REG *) 	0x400C40E8) // (HDMA_CH_4) HDMA Channel Control A Register
#define AT91C_HDMA_CH_4_CFG (AT91_CAST(AT91_REG *) 	0x400C40F0) // (HDMA_CH_4) HDMA Channel Configuration Register
#define AT91C_HDMA_CH_4_CADDR (AT91_CAST(AT91_REG *) 	0x400C4100) // (HDMA_CH_4) HDMA Reserved
#define AT91C_HDMA_CH_4_DADDR (AT91_CAST(AT91_REG *) 	0x400C40E0) // (HDMA_CH_4) HDMA Channel Destination Address Register
#define AT91C_HDMA_CH_4_CTRLB (AT91_CAST(AT91_REG *) 	0x400C40EC) // (HDMA_CH_4) HDMA Channel Control B Register
// ========== Register definition for HDMA_CH_5 peripheral ========== 
#define AT91C_HDMA_CH_5_CTRLB (AT91_CAST(AT91_REG *) 	0x400C4114) // (HDMA_CH_5) HDMA Channel Control B Register
#define AT91C_HDMA_CH_5_SADDR (AT91_CAST(AT91_REG *) 	0x400C4104) // (HDMA_CH_5) HDMA Channel Source Address Register
#define AT91C_HDMA_CH_5_CFG (AT91_CAST(AT91_REG *) 	0x400C4118) // (HDMA_CH_5) HDMA Channel Configuration Register
#define AT91C_HDMA_CH_5_BDSCR (AT91_CAST(AT91_REG *) 	0x400C4124) // (HDMA_CH_5) HDMA Reserved
#define AT91C_HDMA_CH_5_SPIP (AT91_CAST(AT91_REG *) 	0x400C411C) // (HDMA_CH_5) HDMA Channel Source Picture in Picture Configuration Register
#define AT91C_HDMA_CH_5_CTRLA (AT91_CAST(AT91_REG *) 	0x400C4110) // (HDMA_CH_5) HDMA Channel Control A Register
#define AT91C_HDMA_CH_5_CADDR (AT91_CAST(AT91_REG *) 	0x400C4128) // (HDMA_CH_5) HDMA Reserved
#define AT91C_HDMA_CH_5_DADDR (AT91_CAST(AT91_REG *) 	0x400C4108) // (HDMA_CH_5) HDMA Channel Destination Address Register
#define AT91C_HDMA_CH_5_DSCR (AT91_CAST(AT91_REG *) 	0x400C410C) // (HDMA_CH_5) HDMA Channel Descriptor Address Register
#define AT91C_HDMA_CH_5_DPIP (AT91_CAST(AT91_REG *) 	0x400C4120) // (HDMA_CH_5) HDMA Channel Destination Picture in Picture Configuration Register
// ========== Register definition for HDMA peripheral ========== 
#define AT91C_HDMA_CHDR (AT91_CAST(AT91_REG *) 	0x400C402C) // (HDMA) HDMA Channel Handler Disable Register
#define AT91C_HDMA_EBCIER (AT91_CAST(AT91_REG *) 	0x400C4018) // (HDMA) HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Interrupt Enable register
#define AT91C_HDMA_RSVD1 (AT91_CAST(AT91_REG *) 	0x400C4038) // (HDMA) HDMA Reserved
#define AT91C_HDMA_GCFG (AT91_CAST(AT91_REG *) 	0x400C4000) // (HDMA) HDMA Global Configuration Register
#define AT91C_HDMA_CREQ (AT91_CAST(AT91_REG *) 	0x400C400C) // (HDMA) HDMA Software Chunk Transfer Request Register
#define AT91C_HDMA_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400C41F0) // (HDMA) HDMA IPNAME1 REGISTER 
#define AT91C_HDMA_VER  (AT91_CAST(AT91_REG *) 	0x400C41FC) // (HDMA) HDMA VERSION REGISTER 
#define AT91C_HDMA_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400C41EC) // (HDMA) HDMA ADDRSIZE REGISTER 
#define AT91C_HDMA_EBCIDR (AT91_CAST(AT91_REG *) 	0x400C401C) // (HDMA) HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Interrupt Disable register
#define AT91C_HDMA_SYNC (AT91_CAST(AT91_REG *) 	0x400C4014) // (HDMA) HDMA Request Synchronization Register
#define AT91C_HDMA_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400C41F4) // (HDMA) HDMA IPNAME2 REGISTER 
#define AT91C_HDMA_EN   (AT91_CAST(AT91_REG *) 	0x400C4004) // (HDMA) HDMA Controller Enable Register
#define AT91C_HDMA_EBCIMR (AT91_CAST(AT91_REG *) 	0x400C4020) // (HDMA) HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Mask Register
#define AT91C_HDMA_LAST (AT91_CAST(AT91_REG *) 	0x400C4010) // (HDMA) HDMA Software Last Transfer Flag Register
#define AT91C_HDMA_CHSR (AT91_CAST(AT91_REG *) 	0x400C4030) // (HDMA) HDMA Channel Handler Status Register
#define AT91C_HDMA_SREQ (AT91_CAST(AT91_REG *) 	0x400C4008) // (HDMA) HDMA Software Single Request Register
#define AT91C_HDMA_FEATURES (AT91_CAST(AT91_REG *) 	0x400C41F8) // (HDMA) HDMA FEATURES REGISTER 
#define AT91C_HDMA_RSVD0 (AT91_CAST(AT91_REG *) 	0x400C4034) // (HDMA) HDMA Reserved
#define AT91C_HDMA_EBCISR (AT91_CAST(AT91_REG *) 	0x400C4024) // (HDMA) HDMA Error, Chained Buffer transfer completed and Buffer transfer completed Status Register
#define AT91C_HDMA_CHER (AT91_CAST(AT91_REG *) 	0x400C4028) // (HDMA) HDMA Channel Handler Enable Register
// ========== Register definition for OTGHS_DEVDMA_0 peripheral ========== 
#define AT91C_OTGHS_DEVDMA_0_DEVDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC300) // (OTGHS_DEVDMA_0) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_DEVDMA_0_DEVDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC304) // (OTGHS_DEVDMA_0) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_DEVDMA_0_DEVDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC30C) // (OTGHS_DEVDMA_0) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_DEVDMA_0_DEVDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC308) // (OTGHS_DEVDMA_0) OTGHS DMA Channel Control Register
// ========== Register definition for OTGHS_DEVDMA_1 peripheral ========== 
#define AT91C_OTGHS_DEVDMA_1_DEVDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC318) // (OTGHS_DEVDMA_1) OTGHS DMA Channel Control Register
#define AT91C_OTGHS_DEVDMA_1_DEVDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC310) // (OTGHS_DEVDMA_1) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_DEVDMA_1_DEVDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC31C) // (OTGHS_DEVDMA_1) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_DEVDMA_1_DEVDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC314) // (OTGHS_DEVDMA_1) OTGHS DMA Channel Address Register
// ========== Register definition for OTGHS_DEVDMA_2 peripheral ========== 
#define AT91C_OTGHS_DEVDMA_2_DEVDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC324) // (OTGHS_DEVDMA_2) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_DEVDMA_2_DEVDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC320) // (OTGHS_DEVDMA_2) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_DEVDMA_2_DEVDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC32C) // (OTGHS_DEVDMA_2) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_DEVDMA_2_DEVDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC328) // (OTGHS_DEVDMA_2) OTGHS DMA Channel Control Register
// ========== Register definition for OTGHS_DEVDMA_3 peripheral ========== 
#define AT91C_OTGHS_DEVDMA_3_DEVDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC33C) // (OTGHS_DEVDMA_3) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_DEVDMA_3_DEVDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC330) // (OTGHS_DEVDMA_3) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_DEVDMA_3_DEVDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC334) // (OTGHS_DEVDMA_3) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_DEVDMA_3_DEVDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC338) // (OTGHS_DEVDMA_3) OTGHS DMA Channel Control Register
// ========== Register definition for OTGHS_DEVDMA_4 peripheral ========== 
#define AT91C_OTGHS_DEVDMA_4_DEVDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC348) // (OTGHS_DEVDMA_4) OTGHS DMA Channel Control Register
#define AT91C_OTGHS_DEVDMA_4_DEVDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC344) // (OTGHS_DEVDMA_4) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_DEVDMA_4_DEVDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC340) // (OTGHS_DEVDMA_4) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_DEVDMA_4_DEVDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC34C) // (OTGHS_DEVDMA_4) OTGHS DMA Channel Status Register
// ========== Register definition for OTGHS_DEVDMA_5 peripheral ========== 
#define AT91C_OTGHS_DEVDMA_5_DEVDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC358) // (OTGHS_DEVDMA_5) OTGHS DMA Channel Control Register
#define AT91C_OTGHS_DEVDMA_5_DEVDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC35C) // (OTGHS_DEVDMA_5) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_DEVDMA_5_DEVDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC354) // (OTGHS_DEVDMA_5) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_DEVDMA_5_DEVDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC350) // (OTGHS_DEVDMA_5) OTGHS DMA Channel Next Descriptor Address
// ========== Register definition for OTGHS_DEVDMA_6 peripheral ========== 
#define AT91C_OTGHS_DEVDMA_6_DEVDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC36C) // (OTGHS_DEVDMA_6) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_DEVDMA_6_DEVDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC360) // (OTGHS_DEVDMA_6) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_DEVDMA_6_DEVDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC364) // (OTGHS_DEVDMA_6) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_DEVDMA_6_DEVDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC368) // (OTGHS_DEVDMA_6) OTGHS DMA Channel Control Register
// ========== Register definition for OTGHS_DEVDMA_7 peripheral ========== 
#define AT91C_OTGHS_DEVDMA_7_DEVDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC378) // (OTGHS_DEVDMA_7) OTGHS DMA Channel Control Register
#define AT91C_OTGHS_DEVDMA_7_DEVDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC37C) // (OTGHS_DEVDMA_7) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_DEVDMA_7_DEVDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC374) // (OTGHS_DEVDMA_7) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_DEVDMA_7_DEVDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC370) // (OTGHS_DEVDMA_7) OTGHS DMA Channel Next Descriptor Address
// ========== Register definition for OTGHS_HSTDMA_0 peripheral ========== 
#define AT91C_OTGHS_HSTDMA_0_HSTDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC70C) // (OTGHS_HSTDMA_0) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_HSTDMA_0_HSTDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC700) // (OTGHS_HSTDMA_0) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_HSTDMA_0_HSTDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC704) // (OTGHS_HSTDMA_0) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_HSTDMA_0_HSTDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC708) // (OTGHS_HSTDMA_0) OTGHS DMA Channel Control Register
// ========== Register definition for OTGHS_HSTDMA_1 peripheral ========== 
#define AT91C_OTGHS_HSTDMA_1_HSTDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC71C) // (OTGHS_HSTDMA_1) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_HSTDMA_1_HSTDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC710) // (OTGHS_HSTDMA_1) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_HSTDMA_1_HSTDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC718) // (OTGHS_HSTDMA_1) OTGHS DMA Channel Control Register
#define AT91C_OTGHS_HSTDMA_1_HSTDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC714) // (OTGHS_HSTDMA_1) OTGHS DMA Channel Address Register
// ========== Register definition for OTGHS_HSTDMA_2 peripheral ========== 
#define AT91C_OTGHS_HSTDMA_2_HSTDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC724) // (OTGHS_HSTDMA_2) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_HSTDMA_2_HSTDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC720) // (OTGHS_HSTDMA_2) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_HSTDMA_2_HSTDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC728) // (OTGHS_HSTDMA_2) OTGHS DMA Channel Control Register
#define AT91C_OTGHS_HSTDMA_2_HSTDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC72C) // (OTGHS_HSTDMA_2) OTGHS DMA Channel Status Register
// ========== Register definition for OTGHSHST_DMA_3 peripheral ========== 
#define AT91C_OTGHSHST_DMA_3_HSTDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC730) // (OTGHSHST_DMA_3) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHSHST_DMA_3_HSTDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC738) // (OTGHSHST_DMA_3) OTGHS DMA Channel Control Register
#define AT91C_OTGHSHST_DMA_3_HSTDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC73C) // (OTGHSHST_DMA_3) OTGHS DMA Channel Status Register
#define AT91C_OTGHSHST_DMA_3_HSTDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC734) // (OTGHSHST_DMA_3) OTGHS DMA Channel Address Register
// ========== Register definition for OTGHS_HSTDMA_4 peripheral ========== 
#define AT91C_OTGHS_HSTDMA_4_HSTDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC748) // (OTGHS_HSTDMA_4) OTGHS DMA Channel Control Register
#define AT91C_OTGHS_HSTDMA_4_HSTDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC740) // (OTGHS_HSTDMA_4) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_HSTDMA_4_HSTDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC74C) // (OTGHS_HSTDMA_4) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_HSTDMA_4_HSTDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC744) // (OTGHS_HSTDMA_4) OTGHS DMA Channel Address Register
// ========== Register definition for OTGHS_HSTDMA_5 peripheral ========== 
#define AT91C_OTGHS_HSTDMA_5_HSTDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC758) // (OTGHS_HSTDMA_5) OTGHS DMA Channel Control Register
#define AT91C_OTGHS_HSTDMA_5_HSTDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC75C) // (OTGHS_HSTDMA_5) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_HSTDMA_5_HSTDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC750) // (OTGHS_HSTDMA_5) OTGHS DMA Channel Next Descriptor Address
#define AT91C_OTGHS_HSTDMA_5_HSTDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC754) // (OTGHS_HSTDMA_5) OTGHS DMA Channel Address Register
// ========== Register definition for OTGHS_HSTDMA_6 peripheral ========== 
#define AT91C_OTGHS_HSTDMA_6_HSTDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC76C) // (OTGHS_HSTDMA_6) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_HSTDMA_6_HSTDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC764) // (OTGHS_HSTDMA_6) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_HSTDMA_6_HSTDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC768) // (OTGHS_HSTDMA_6) OTGHS DMA Channel Control Register
#define AT91C_OTGHS_HSTDMA_6_HSTDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC760) // (OTGHS_HSTDMA_6) OTGHS DMA Channel Next Descriptor Address
// ========== Register definition for OTGHS_HSTDMA_7 peripheral ========== 
#define AT91C_OTGHS_HSTDMA_7_HSTDMASTATUS (AT91_CAST(AT91_REG *) 	0x400AC77C) // (OTGHS_HSTDMA_7) OTGHS DMA Channel Status Register
#define AT91C_OTGHS_HSTDMA_7_HSTDMACONTROL (AT91_CAST(AT91_REG *) 	0x400AC778) // (OTGHS_HSTDMA_7) OTGHS DMA Channel Control Register
#define AT91C_OTGHS_HSTDMA_7_HSTDMAADDRESS (AT91_CAST(AT91_REG *) 	0x400AC774) // (OTGHS_HSTDMA_7) OTGHS DMA Channel Address Register
#define AT91C_OTGHS_HSTDMA_7_HSTDMANXTDSC (AT91_CAST(AT91_REG *) 	0x400AC770) // (OTGHS_HSTDMA_7) OTGHS DMA Channel Next Descriptor Address
// ========== Register definition for OTGHS_EPTFIFO peripheral ========== 
#define AT91C_OTGHS_EPTFIFO_READEPTA (AT91_CAST(AT91_REG *) 	0x20220000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 10
#define AT91C_OTGHS_EPTFIFO_READEPT6 (AT91_CAST(AT91_REG *) 	0x201E0000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 6
#define AT91C_OTGHS_EPTFIFO_READEPTB (AT91_CAST(AT91_REG *) 	0x20230000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 11
#define AT91C_OTGHS_EPTFIFO_READEPT7 (AT91_CAST(AT91_REG *) 	0x201F0000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 7
#define AT91C_OTGHS_EPTFIFO_READEPT5 (AT91_CAST(AT91_REG *) 	0x201D0000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 5
#define AT91C_OTGHS_EPTFIFO_READEPT2 (AT91_CAST(AT91_REG *) 	0x201A0000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 2
#define AT91C_OTGHS_EPTFIFO_READEPT1 (AT91_CAST(AT91_REG *) 	0x20190000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 1
#define AT91C_OTGHS_EPTFIFO_READEPT3 (AT91_CAST(AT91_REG *) 	0x201B0000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 3
#define AT91C_OTGHS_EPTFIFO_READEPTC (AT91_CAST(AT91_REG *) 	0x20240000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 12
#define AT91C_OTGHS_EPTFIFO_READEPT4 (AT91_CAST(AT91_REG *) 	0x201C0000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 4
#define AT91C_OTGHS_EPTFIFO_READEPT9 (AT91_CAST(AT91_REG *) 	0x20210000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 9
#define AT91C_OTGHS_EPTFIFO_READEPTD (AT91_CAST(AT91_REG *) 	0x20250000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 13
#define AT91C_OTGHS_EPTFIFO_READEPTF (AT91_CAST(AT91_REG *) 	0x20270000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 15
#define AT91C_OTGHS_EPTFIFO_READEPTE (AT91_CAST(AT91_REG *) 	0x20260000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 14
#define AT91C_OTGHS_EPTFIFO_READEPT8 (AT91_CAST(AT91_REG *) 	0x20200000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 8
#define AT91C_OTGHS_EPTFIFO_READEPT0 (AT91_CAST(AT91_REG *) 	0x20180000) // (OTGHS_EPTFIFO) FIFO Endpoint Data Register 0
// ========== Register definition for OTGHS peripheral ========== 
#define AT91C_OTGHS_FSM (AT91_CAST(AT91_REG *) 	0x400AC82C) // (OTGHS) [RO] OTGHS A-Device/B-Device State
#define AT91C_OTGHS_HSTPIPIDR (AT91_CAST(AT91_REG *) 	0x400AC620) // (OTGHS) [WO] OTGHS Host Pipe Clear Control Register[x]
#define AT91C_OTGHS_DEVIER (AT91_CAST(AT91_REG *) 	0x400AC018) // (OTGHS) [WO] OTGHS Device Interupt Enable Register
#define AT91C_OTGHS_DEVIFR (AT91_CAST(AT91_REG *) 	0x400AC00C) // (OTGHS) [WO] OTGHS Device Interupt Force Register (for DEBUG/TEST only)
#define AT91C_OTGHS_DEVEPTIDR (AT91_CAST(AT91_REG *) 	0x400AC220) // (OTGHS) [WO] OTGHS Device Endpoint Control Disable Register[x]
#define AT91C_OTGHS_RIPNAME2 (AT91_CAST(AT91_REG *) 	0x400AC828) // (OTGHS) [RO] OTGHS Name2 Register
#define AT91C_OTGHS_HSTPIP (AT91_CAST(AT91_REG *) 	0x400AC41C) // (OTGHS) [RW] OTGHS Host Pipe Enable Reset Register
#define AT91C_OTGHS_HSTPIPIFR (AT91_CAST(AT91_REG *) 	0x400AC590) // (OTGHS) [WO] OTGHS Host Pipe Force Status Register[x] (for DEBUG/TEST only)
#define AT91C_OTGHS_HSTIMR (AT91_CAST(AT91_REG *) 	0x400AC410) // (OTGHS) [RO] OTGHS Host Interupt Mask Register
#define AT91C_OTGHS_DEVEPT (AT91_CAST(AT91_REG *) 	0x400AC01C) // (OTGHS) [RW] OTGHS Device Endpoint Enable Register
#define AT91C_OTGHS_DEVEPTIFR (AT91_CAST(AT91_REG *) 	0x400AC190) // (OTGHS) [WO] OTGHS Device Endpoint Force Status Register[x] (for DEBUG/TEST only)
#define AT91C_OTGHS_HSTCTRL (AT91_CAST(AT91_REG *) 	0x400AC400) // (OTGHS) [RW] OTGHS Host Control Register
#define AT91C_OTGHS_SCR (AT91_CAST(AT91_REG *) 	0x400AC808) // (OTGHS) [WO] OTGHS General Status Clear Register
#define AT91C_OTGHS_HSTPIPISR (AT91_CAST(AT91_REG *) 	0x400AC530) // (OTGHS) [RO] OTGHS Host Pipe Status Register[x]
#define AT91C_OTGHS_HSTADDR2 (AT91_CAST(AT91_REG *) 	0x400AC428) // (OTGHS) [RW] OTGHS Host Address Register 2
#define AT91C_OTGHS_IPFEATURES (AT91_CAST(AT91_REG *) 	0x400AC81C) // (OTGHS) [RO] OTGHS Features Register
#define AT91C_OTGHS_SR  (AT91_CAST(AT91_REG *) 	0x400AC804) // (OTGHS) [RO] OTGHS General Status Register
#define AT91C_OTGHS_DEVEPTCFG (AT91_CAST(AT91_REG *) 	0x400AC100) // (OTGHS) [RW] OTGHS Device Endpoint Configuration Register[x]
#define AT91C_OTGHS_DEVEPTISR (AT91_CAST(AT91_REG *) 	0x400AC130) // (OTGHS) [RO] OTGHS Device Endpoint Interrupt Status Register[x]
#define AT91C_OTGHS_DEVIDR (AT91_CAST(AT91_REG *) 	0x400AC014) // (OTGHS) [WO] OTGHS Device Interupt Disable Register
#define AT91C_OTGHS_HSTFNUM (AT91_CAST(AT91_REG *) 	0x400AC420) // (OTGHS) [RO] OTGHS Host Frame Number Register
#define AT91C_OTGHS_DEVEPTIER (AT91_CAST(AT91_REG *) 	0x400AC1F0) // (OTGHS) [WO] OTGHS Device Endpoint Control Enable Register[x]
#define AT91C_OTGHS_TSTA1 (AT91_CAST(AT91_REG *) 	0x400AC810) // (OTGHS) [RW] OTGHS Arbiter Test 1 Register
#define AT91C_OTGHS_CTRL (AT91_CAST(AT91_REG *) 	0x400AC800) // (OTGHS) [RW] OTGHS General Control Register
#define AT91C_OTGHS_IPVERSION (AT91_CAST(AT91_REG *) 	0x400AC818) // (OTGHS) [RO] OTGHS Version Register
#define AT91C_OTGHS_HSTICR (AT91_CAST(AT91_REG *) 	0x400AC408) // (OTGHS) [WO] OTGHS Host Interupt Clear Register
#define AT91C_OTGHS_HSTADDR3 (AT91_CAST(AT91_REG *) 	0x400AC42C) // (OTGHS) [RW] OTGHS Host Address Register 3
#define AT91C_OTGHS_HSTPIPERR (AT91_CAST(AT91_REG *) 	0x400AC680) // (OTGHS) [WO] OTGHS Host Pipe Error Register[x]
#define AT91C_OTGHS_DEVFNUM (AT91_CAST(AT91_REG *) 	0x400AC020) // (OTGHS) [RO] OTGHS Device Frame Number Register
#define AT91C_OTGHS_HSTPIPIER (AT91_CAST(AT91_REG *) 	0x400AC5F0) // (OTGHS) [WO] OTGHS Host Pipe Control Set Register[x]
#define AT91C_OTGHS_HSTIFR (AT91_CAST(AT91_REG *) 	0x400AC40C) // (OTGHS) [WO] OTGHS Host Interupt Force Register (for DEBUG/TEST only)
#define AT91C_OTGHS_DEVEPTICR (AT91_CAST(AT91_REG *) 	0x400AC160) // (OTGHS) [WO] OTGHS Device Endpoint Clear Status Register[x]
#define AT91C_OTGHS_HSTIDR (AT91_CAST(AT91_REG *) 	0x400AC414) // (OTGHS) [WO] OTGHS Host Interupt Disable Register
#define AT91C_OTGHS_DEVISR (AT91_CAST(AT91_REG *) 	0x400AC004) // (OTGHS) [RO] OTGHS Device Interupt Statuts Register
#define AT91C_OTGHS_HSTISR (AT91_CAST(AT91_REG *) 	0x400AC404) // (OTGHS) [RO] OTGHS Host Interupt Register
#define AT91C_OTGHS_HSTPIPCFG (AT91_CAST(AT91_REG *) 	0x400AC500) // (OTGHS) [RW] OTGHS Host Pipe Configuration Register [x]
#define AT91C_OTGHS_HSTIER (AT91_CAST(AT91_REG *) 	0x400AC418) // (OTGHS) [WO] OTGHS Host Interupt Enable Register
#define AT91C_OTGHS_HSTPIPICR (AT91_CAST(AT91_REG *) 	0x400AC560) // (OTGHS) [WO] OTGHS Host Pipe Clear Status Register[x]
#define AT91C_OTGHS_HSTPIPINRQ (AT91_CAST(AT91_REG *) 	0x400AC650) // (OTGHS) [RW] OTGHS Host Pipe IN Request Register[x]
#define AT91C_OTGHS_DEVEPTIMR (AT91_CAST(AT91_REG *) 	0x400AC1C0) // (OTGHS) [RO] OTGHS Device Endpoint Control Mask Register[x]
#define AT91C_OTGHS_DEVIMR (AT91_CAST(AT91_REG *) 	0x400AC010) // (OTGHS) [RO] OTGHS Device Interupt Mask Register
#define AT91C_OTGHS_HSTPIPIMR (AT91_CAST(AT91_REG *) 	0x400AC5C0) // (OTGHS) [RO] OTGHS Host Pipe Control Register[x]
#define AT91C_OTGHS_RIPNAME1 (AT91_CAST(AT91_REG *) 	0x400AC824) // (OTGHS) [RO] OTGHS Name1 Register
#define AT91C_OTGHS_RIPPADDRSIZE (AT91_CAST(AT91_REG *) 	0x400AC820) // (OTGHS) [RO] OTGHS PADDRSIZE Register
#define AT91C_OTGHS_HSTADDR1 (AT91_CAST(AT91_REG *) 	0x400AC424) // (OTGHS) [RW] OTGHS Host Address Register 1
#define AT91C_OTGHS_SFR (AT91_CAST(AT91_REG *) 	0x400AC80C) // (OTGHS) [WO] OTGHS General Status Force Register (for DEBUG/TEST only)
#define AT91C_OTGHS_DEVCTRL (AT91_CAST(AT91_REG *) 	0x400AC000) // (OTGHS) [RW] OTGHS Device Control Register
#define AT91C_OTGHS_DEVICR (AT91_CAST(AT91_REG *) 	0x400AC008) // (OTGHS) [WO] OTGHS Device Interupt Clear Register
#define AT91C_OTGHS_TSTA2 (AT91_CAST(AT91_REG *) 	0x400AC814) // (OTGHS) [RW] OTGHS Arbiter Test 2 Register
// ========== Register definition for TRNG peripheral ========== 
#define AT91C_TRNG_VERSION (AT91_CAST(AT91_REG *) 	0x400BC0FC) // (TRNG) TRNG Version Register
#define AT91C_TRNG_IDR  (AT91_CAST(AT91_REG *) 	0x400BC014) // (TRNG) Interrupt Disable Register
#define AT91C_TRNG_CR   (AT91_CAST(AT91_REG *) 	0x400BC000) // (TRNG) Control Register
#define AT91C_TRNG_ODATA (AT91_CAST(AT91_REG *) 	0x400BC050) // (TRNG) Output Data Register
#define AT91C_TRNG_ISR  (AT91_CAST(AT91_REG *) 	0x400BC01C) // (TRNG) Interrupt Status Register
#define AT91C_TRNG_IER  (AT91_CAST(AT91_REG *) 	0x400BC010) // (TRNG) Interrupt Enable Register
#define AT91C_TRNG_IMR  (AT91_CAST(AT91_REG *) 	0x400BC018) // (TRNG) Interrupt Mask Register
// ========== Register definition for EMACB peripheral ========== 
#define AT91C_EMACB_STE (AT91_CAST(AT91_REG *) 	0x400B0084) // (EMACB) SQE Test Error Register
#define AT91C_EMACB_RSE (AT91_CAST(AT91_REG *) 	0x400B0074) // (EMACB) Receive Symbol Errors Register
#define AT91C_EMACB_ECOL (AT91_CAST(AT91_REG *) 	0x400B0060) // (EMACB) Excessive Collision Register
#define AT91C_EMACB_MAN (AT91_CAST(AT91_REG *) 	0x400B0034) // (EMACB) PHY Maintenance Register
#define AT91C_EMACB_SA3H (AT91_CAST(AT91_REG *) 	0x400B00AC) // (EMACB) Specific Address 3 Top, Last 2 bytes
#define AT91C_EMACB_SA1H (AT91_CAST(AT91_REG *) 	0x400B009C) // (EMACB) Specific Address 1 Top, Last 2 bytes
#define AT91C_EMACB_RJA (AT91_CAST(AT91_REG *) 	0x400B007C) // (EMACB) Receive Jabbers Register
#define AT91C_EMACB_TUND (AT91_CAST(AT91_REG *) 	0x400B0064) // (EMACB) Transmit Underrun Error Register
#define AT91C_EMACB_FCSE (AT91_CAST(AT91_REG *) 	0x400B0050) // (EMACB) Frame Check Sequence Error Register
#define AT91C_EMACB_IMR (AT91_CAST(AT91_REG *) 	0x400B0030) // (EMACB) Interrupt Mask Register
#define AT91C_EMACB_FRO (AT91_CAST(AT91_REG *) 	0x400B004C) // (EMACB) Frames Received OK Register
#define AT91C_EMACB_USRIO (AT91_CAST(AT91_REG *) 	0x400B00C0) // (EMACB) USER Input/Output Register
#define AT91C_EMACB_SCF (AT91_CAST(AT91_REG *) 	0x400B0044) // (EMACB) Single Collision Frame Register
#define AT91C_EMACB_SA1L (AT91_CAST(AT91_REG *) 	0x400B0098) // (EMACB) Specific Address 1 Bottom, First 4 bytes
#define AT91C_EMACB_DTF (AT91_CAST(AT91_REG *) 	0x400B0058) // (EMACB) Deferred Transmission Frame Register
#define AT91C_EMACB_IDR (AT91_CAST(AT91_REG *) 	0x400B002C) // (EMACB) Interrupt Disable Register
#define AT91C_EMACB_SA2H (AT91_CAST(AT91_REG *) 	0x400B00A4) // (EMACB) Specific Address 2 Top, Last 2 bytes
#define AT91C_EMACB_TID (AT91_CAST(AT91_REG *) 	0x400B00B8) // (EMACB) Type ID Checking Register
#define AT91C_EMACB_ROV (AT91_CAST(AT91_REG *) 	0x400B0070) // (EMACB) Receive Overrun Errors Register
#define AT91C_EMACB_TPQ (AT91_CAST(AT91_REG *) 	0x400B00BC) // (EMACB) Transmit Pause Quantum Register
#define AT91C_EMACB_MCF (AT91_CAST(AT91_REG *) 	0x400B0048) // (EMACB) Multiple Collision Frame Register
#define AT91C_EMACB_IER (AT91_CAST(AT91_REG *) 	0x400B0028) // (EMACB) Interrupt Enable Register
#define AT91C_EMACB_PFR (AT91_CAST(AT91_REG *) 	0x400B003C) // (EMACB) Pause Frames received Register
#define AT91C_EMACB_SA3L (AT91_CAST(AT91_REG *) 	0x400B00A8) // (EMACB) Specific Address 3 Bottom, First 4 bytes
#define AT91C_EMACB_TPF (AT91_CAST(AT91_REG *) 	0x400B008C) // (EMACB) Transmitted Pause Frames Register
#define AT91C_EMACB_USF (AT91_CAST(AT91_REG *) 	0x400B0080) // (EMACB) Undersize Frames Register
#define AT91C_EMACB_ISR (AT91_CAST(AT91_REG *) 	0x400B0024) // (EMACB) Interrupt Status Register
#define AT91C_EMACB_WOL (AT91_CAST(AT91_REG *) 	0x400B00C4) // (EMACB) Wake On LAN Register
#define AT91C_EMACB_ELE (AT91_CAST(AT91_REG *) 	0x400B0078) // (EMACB) Excessive Length Errors Register
#define AT91C_EMACB_TBQP (AT91_CAST(AT91_REG *) 	0x400B001C) // (EMACB) Transmit Buffer Queue Pointer
#define AT91C_EMACB_TSR (AT91_CAST(AT91_REG *) 	0x400B0014) // (EMACB) Transmit Status Register
#define AT91C_EMACB_SA2L (AT91_CAST(AT91_REG *) 	0x400B00A0) // (EMACB) Specific Address 2 Bottom, First 4 bytes
#define AT91C_EMACB_RSR (AT91_CAST(AT91_REG *) 	0x400B0020) // (EMACB) Receive Status Register
#define AT91C_EMACB_NCFGR (AT91_CAST(AT91_REG *) 	0x400B0004) // (EMACB) Network Configuration Register
#define AT91C_EMACB_NCR (AT91_CAST(AT91_REG *) 	0x400B0000) // (EMACB) Network Control Register
#define AT91C_EMACB_HRB (AT91_CAST(AT91_REG *) 	0x400B0090) // (EMACB) Hash Address Bottom[31:0]
#define AT91C_EMACB_CSE (AT91_CAST(AT91_REG *) 	0x400B0068) // (EMACB) Carrier Sense Error Register
#define AT91C_EMACB_RLE (AT91_CAST(AT91_REG *) 	0x400B0088) // (EMACB) Receive Length Field Mismatch Register
#define AT91C_EMACB_SA4H (AT91_CAST(AT91_REG *) 	0x400B00B4) // (EMACB) Specific Address 4 Top, Last 2 bytes
#define AT91C_EMACB_RRE (AT91_CAST(AT91_REG *) 	0x400B006C) // (EMACB) Receive Ressource Error Register
#define AT91C_EMACB_REV (AT91_CAST(AT91_REG *) 	0x400B00FC) // (EMACB) Revision Register
#define AT91C_EMACB_FTO (AT91_CAST(AT91_REG *) 	0x400B0040) // (EMACB) Frames Transmitted OK Register
#define AT91C_EMACB_LCOL (AT91_CAST(AT91_REG *) 	0x400B005C) // (EMACB) Late Collision Register
#define AT91C_EMACB_SA4L (AT91_CAST(AT91_REG *) 	0x400B00B0) // (EMACB) Specific Address 4 Bottom, First 4 bytes
#define AT91C_EMACB_RBQP (AT91_CAST(AT91_REG *) 	0x400B0018) // (EMACB) Receive Buffer Queue Pointer
#define AT91C_EMACB_ALE (AT91_CAST(AT91_REG *) 	0x400B0054) // (EMACB) Alignment Error Register
#define AT91C_EMACB_NSR (AT91_CAST(AT91_REG *) 	0x400B0008) // (EMACB) Network Status Register
#define AT91C_EMACB_HRT (AT91_CAST(AT91_REG *) 	0x400B0094) // (EMACB) Hash Address Top[63:32]
#define AT91C_EMACB_PTR (AT91_CAST(AT91_REG *) 	0x400B0038) // (EMACB) Pause Time Register
// ========== Register definition for CAN0_MB0 peripheral ========== 
#define AT91C_CAN0_MB0_MMR (AT91_CAST(AT91_REG *) 	0x400B4200) // (CAN0_MB0) MailBox Mode Register
#define AT91C_CAN0_MB0_MFID (AT91_CAST(AT91_REG *) 	0x400B420C) // (CAN0_MB0) MailBox Family ID Register
#define AT91C_CAN0_MB0_MDL (AT91_CAST(AT91_REG *) 	0x400B4214) // (CAN0_MB0) MailBox Data Low Register
#define AT91C_CAN0_MB0_MSR (AT91_CAST(AT91_REG *) 	0x400B4210) // (CAN0_MB0) MailBox Status Register
#define AT91C_CAN0_MB0_MAM (AT91_CAST(AT91_REG *) 	0x400B4204) // (CAN0_MB0) MailBox Acceptance Mask Register
#define AT91C_CAN0_MB0_MID (AT91_CAST(AT91_REG *) 	0x400B4208) // (CAN0_MB0) MailBox ID Register
#define AT91C_CAN0_MB0_MCR (AT91_CAST(AT91_REG *) 	0x400B421C) // (CAN0_MB0) MailBox Control Register
#define AT91C_CAN0_MB0_MDH (AT91_CAST(AT91_REG *) 	0x400B4218) // (CAN0_MB0) MailBox Data High Register
// ========== Register definition for CAN0_MB1 peripheral ========== 
#define AT91C_CAN0_MB1_MSR (AT91_CAST(AT91_REG *) 	0x400B4230) // (CAN0_MB1) MailBox Status Register
#define AT91C_CAN0_MB1_MAM (AT91_CAST(AT91_REG *) 	0x400B4224) // (CAN0_MB1) MailBox Acceptance Mask Register
#define AT91C_CAN0_MB1_MCR (AT91_CAST(AT91_REG *) 	0x400B423C) // (CAN0_MB1) MailBox Control Register
#define AT91C_CAN0_MB1_MFID (AT91_CAST(AT91_REG *) 	0x400B422C) // (CAN0_MB1) MailBox Family ID Register
#define AT91C_CAN0_MB1_MMR (AT91_CAST(AT91_REG *) 	0x400B4220) // (CAN0_MB1) MailBox Mode Register
#define AT91C_CAN0_MB1_MID (AT91_CAST(AT91_REG *) 	0x400B4228) // (CAN0_MB1) MailBox ID Register
#define AT91C_CAN0_MB1_MDL (AT91_CAST(AT91_REG *) 	0x400B4234) // (CAN0_MB1) MailBox Data Low Register
#define AT91C_CAN0_MB1_MDH (AT91_CAST(AT91_REG *) 	0x400B4238) // (CAN0_MB1) MailBox Data High Register
// ========== Register definition for CAN0_MB2 peripheral ========== 
#define AT91C_CAN0_MB2_MID (AT91_CAST(AT91_REG *) 	0x400B4248) // (CAN0_MB2) MailBox ID Register
#define AT91C_CAN0_MB2_MDH (AT91_CAST(AT91_REG *) 	0x400B4258) // (CAN0_MB2) MailBox Data High Register
#define AT91C_CAN0_MB2_MAM (AT91_CAST(AT91_REG *) 	0x400B4244) // (CAN0_MB2) MailBox Acceptance Mask Register
#define AT91C_CAN0_MB2_MMR (AT91_CAST(AT91_REG *) 	0x400B4240) // (CAN0_MB2) MailBox Mode Register
#define AT91C_CAN0_MB2_MSR (AT91_CAST(AT91_REG *) 	0x400B4250) // (CAN0_MB2) MailBox Status Register
#define AT91C_CAN0_MB2_MDL (AT91_CAST(AT91_REG *) 	0x400B4254) // (CAN0_MB2) MailBox Data Low Register
#define AT91C_CAN0_MB2_MFID (AT91_CAST(AT91_REG *) 	0x400B424C) // (CAN0_MB2) MailBox Family ID Register
#define AT91C_CAN0_MB2_MCR (AT91_CAST(AT91_REG *) 	0x400B425C) // (CAN0_MB2) MailBox Control Register
// ========== Register definition for CAN0_MB3 peripheral ========== 
#define AT91C_CAN0_MB3_MSR (AT91_CAST(AT91_REG *) 	0x400B4270) // (CAN0_MB3) MailBox Status Register
#define AT91C_CAN0_MB3_MDH (AT91_CAST(AT91_REG *) 	0x400B4278) // (CAN0_MB3) MailBox Data High Register
#define AT91C_CAN0_MB3_MMR (AT91_CAST(AT91_REG *) 	0x400B4260) // (CAN0_MB3) MailBox Mode Register
#define AT91C_CAN0_MB3_MFID (AT91_CAST(AT91_REG *) 	0x400B426C) // (CAN0_MB3) MailBox Family ID Register
#define AT91C_CAN0_MB3_MID (AT91_CAST(AT91_REG *) 	0x400B4268) // (CAN0_MB3) MailBox ID Register
#define AT91C_CAN0_MB3_MDL (AT91_CAST(AT91_REG *) 	0x400B4274) // (CAN0_MB3) MailBox Data Low Register
#define AT91C_CAN0_MB3_MAM (AT91_CAST(AT91_REG *) 	0x400B4264) // (CAN0_MB3) MailBox Acceptance Mask Register
#define AT91C_CAN0_MB3_MCR (AT91_CAST(AT91_REG *) 	0x400B427C) // (CAN0_MB3) MailBox Control Register
// ========== Register definition for CAN0_MB4 peripheral ========== 
#define AT91C_CAN0_MB4_MDL (AT91_CAST(AT91_REG *) 	0x400B4294) // (CAN0_MB4) MailBox Data Low Register
#define AT91C_CAN0_MB4_MID (AT91_CAST(AT91_REG *) 	0x400B4288) // (CAN0_MB4) MailBox ID Register
#define AT91C_CAN0_MB4_MAM (AT91_CAST(AT91_REG *) 	0x400B4284) // (CAN0_MB4) MailBox Acceptance Mask Register
#define AT91C_CAN0_MB4_MFID (AT91_CAST(AT91_REG *) 	0x400B428C) // (CAN0_MB4) MailBox Family ID Register
#define AT91C_CAN0_MB4_MMR (AT91_CAST(AT91_REG *) 	0x400B4280) // (CAN0_MB4) MailBox Mode Register
#define AT91C_CAN0_MB4_MDH (AT91_CAST(AT91_REG *) 	0x400B4298) // (CAN0_MB4) MailBox Data High Register
#define AT91C_CAN0_MB4_MCR (AT91_CAST(AT91_REG *) 	0x400B429C) // (CAN0_MB4) MailBox Control Register
#define AT91C_CAN0_MB4_MSR (AT91_CAST(AT91_REG *) 	0x400B4290) // (CAN0_MB4) MailBox Status Register
// ========== Register definition for CAN0_MB5 peripheral ========== 
#define AT91C_CAN0_MB5_MDH (AT91_CAST(AT91_REG *) 	0x400B42B8) // (CAN0_MB5) MailBox Data High Register
#define AT91C_CAN0_MB5_MAM (AT91_CAST(AT91_REG *) 	0x400B42A4) // (CAN0_MB5) MailBox Acceptance Mask Register
#define AT91C_CAN0_MB5_MMR (AT91_CAST(AT91_REG *) 	0x400B42A0) // (CAN0_MB5) MailBox Mode Register
#define AT91C_CAN0_MB5_MCR (AT91_CAST(AT91_REG *) 	0x400B42BC) // (CAN0_MB5) MailBox Control Register
#define AT91C_CAN0_MB5_MSR (AT91_CAST(AT91_REG *) 	0x400B42B0) // (CAN0_MB5) MailBox Status Register
#define AT91C_CAN0_MB5_MID (AT91_CAST(AT91_REG *) 	0x400B42A8) // (CAN0_MB5) MailBox ID Register
#define AT91C_CAN0_MB5_MFID (AT91_CAST(AT91_REG *) 	0x400B42AC) // (CAN0_MB5) MailBox Family ID Register
#define AT91C_CAN0_MB5_MDL (AT91_CAST(AT91_REG *) 	0x400B42B4) // (CAN0_MB5) MailBox Data Low Register
// ========== Register definition for CAN0_MB6 peripheral ========== 
#define AT91C_CAN0_MB6_MDH (AT91_CAST(AT91_REG *) 	0x400B42D8) // (CAN0_MB6) MailBox Data High Register
#define AT91C_CAN0_MB6_MID (AT91_CAST(AT91_REG *) 	0x400B42C8) // (CAN0_MB6) MailBox ID Register
#define AT91C_CAN0_MB6_MFID (AT91_CAST(AT91_REG *) 	0x400B42CC) // (CAN0_MB6) MailBox Family ID Register
#define AT91C_CAN0_MB6_MCR (AT91_CAST(AT91_REG *) 	0x400B42DC) // (CAN0_MB6) MailBox Control Register
#define AT91C_CAN0_MB6_MSR (AT91_CAST(AT91_REG *) 	0x400B42D0) // (CAN0_MB6) MailBox Status Register
#define AT91C_CAN0_MB6_MMR (AT91_CAST(AT91_REG *) 	0x400B42C0) // (CAN0_MB6) MailBox Mode Register
#define AT91C_CAN0_MB6_MAM (AT91_CAST(AT91_REG *) 	0x400B42C4) // (CAN0_MB6) MailBox Acceptance Mask Register
#define AT91C_CAN0_MB6_MDL (AT91_CAST(AT91_REG *) 	0x400B42D4) // (CAN0_MB6) MailBox Data Low Register
// ========== Register definition for CAN0_MB7 peripheral ========== 
#define AT91C_CAN0_MB7_MMR (AT91_CAST(AT91_REG *) 	0x400B42E0) // (CAN0_MB7) MailBox Mode Register
#define AT91C_CAN0_MB7_MAM (AT91_CAST(AT91_REG *) 	0x400B42E4) // (CAN0_MB7) MailBox Acceptance Mask Register
#define AT91C_CAN0_MB7_MDH (AT91_CAST(AT91_REG *) 	0x400B42F8) // (CAN0_MB7) MailBox Data High Register
#define AT91C_CAN0_MB7_MCR (AT91_CAST(AT91_REG *) 	0x400B42FC) // (CAN0_MB7) MailBox Control Register
#define AT91C_CAN0_MB7_MSR (AT91_CAST(AT91_REG *) 	0x400B42F0) // (CAN0_MB7) MailBox Status Register
#define AT91C_CAN0_MB7_MFID (AT91_CAST(AT91_REG *) 	0x400B42EC) // (CAN0_MB7) MailBox Family ID Register
#define AT91C_CAN0_MB7_MDL (AT91_CAST(AT91_REG *) 	0x400B42F4) // (CAN0_MB7) MailBox Data Low Register
#define AT91C_CAN0_MB7_MID (AT91_CAST(AT91_REG *) 	0x400B42E8) // (CAN0_MB7) MailBox ID Register
// ========== Register definition for CAN0 peripheral ========== 
#define AT91C_CAN0_IDR  (AT91_CAST(AT91_REG *) 	0x400B4008) // (CAN0) Interrupt Disable Register
#define AT91C_CAN0_TIM  (AT91_CAST(AT91_REG *) 	0x400B4018) // (CAN0) Timer Register
#define AT91C_CAN0_IMR  (AT91_CAST(AT91_REG *) 	0x400B400C) // (CAN0) Interrupt Mask Register
#define AT91C_CAN0_VR   (AT91_CAST(AT91_REG *) 	0x400B40FC) // (CAN0) Version Register
#define AT91C_CAN0_ECR  (AT91_CAST(AT91_REG *) 	0x400B4020) // (CAN0) Error Counter Register
#define AT91C_CAN0_TCR  (AT91_CAST(AT91_REG *) 	0x400B4024) // (CAN0) Transfer Command Register
#define AT91C_CAN0_BR   (AT91_CAST(AT91_REG *) 	0x400B4014) // (CAN0) Baudrate Register
#define AT91C_CAN0_TIMESTP (AT91_CAST(AT91_REG *) 	0x400B401C) // (CAN0) Time Stamp Register
#define AT91C_CAN0_IER  (AT91_CAST(AT91_REG *) 	0x400B4004) // (CAN0) Interrupt Enable Register
#define AT91C_CAN0_ACR  (AT91_CAST(AT91_REG *) 	0x400B4028) // (CAN0) Abort Command Register
#define AT91C_CAN0_SR   (AT91_CAST(AT91_REG *) 	0x400B4010) // (CAN0) Status Register
#define AT91C_CAN0_MR   (AT91_CAST(AT91_REG *) 	0x400B4000) // (CAN0) Mode Register
// ========== Register definition for CAN1_MB0 peripheral ========== 
#define AT91C_CAN1_MB0_MID (AT91_CAST(AT91_REG *) 	0x400B8208) // (CAN1_MB0) MailBox ID Register
#define AT91C_CAN1_MB0_MSR (AT91_CAST(AT91_REG *) 	0x400B8210) // (CAN1_MB0) MailBox Status Register
#define AT91C_CAN1_MB0_MMR (AT91_CAST(AT91_REG *) 	0x400B8200) // (CAN1_MB0) MailBox Mode Register
#define AT91C_CAN1_MB0_MCR (AT91_CAST(AT91_REG *) 	0x400B821C) // (CAN1_MB0) MailBox Control Register
#define AT91C_CAN1_MB0_MDL (AT91_CAST(AT91_REG *) 	0x400B8214) // (CAN1_MB0) MailBox Data Low Register
#define AT91C_CAN1_MB0_MAM (AT91_CAST(AT91_REG *) 	0x400B8204) // (CAN1_MB0) MailBox Acceptance Mask Register
#define AT91C_CAN1_MB0_MFID (AT91_CAST(AT91_REG *) 	0x400B820C) // (CAN1_MB0) MailBox Family ID Register
#define AT91C_CAN1_MB0_MDH (AT91_CAST(AT91_REG *) 	0x400B8218) // (CAN1_MB0) MailBox Data High Register
// ========== Register definition for CAN1_MB1 peripheral ========== 
#define AT91C_CAN1_MB1_MCR (AT91_CAST(AT91_REG *) 	0x400B823C) // (CAN1_MB1) MailBox Control Register
#define AT91C_CAN1_MB1_MAM (AT91_CAST(AT91_REG *) 	0x400B8224) // (CAN1_MB1) MailBox Acceptance Mask Register
#define AT91C_CAN1_MB1_MSR (AT91_CAST(AT91_REG *) 	0x400B8230) // (CAN1_MB1) MailBox Status Register
#define AT91C_CAN1_MB1_MFID (AT91_CAST(AT91_REG *) 	0x400B822C) // (CAN1_MB1) MailBox Family ID Register
#define AT91C_CAN1_MB1_MDH (AT91_CAST(AT91_REG *) 	0x400B8238) // (CAN1_MB1) MailBox Data High Register
#define AT91C_CAN1_MB1_MID (AT91_CAST(AT91_REG *) 	0x400B8228) // (CAN1_MB1) MailBox ID Register
#define AT91C_CAN1_MB1_MMR (AT91_CAST(AT91_REG *) 	0x400B8220) // (CAN1_MB1) MailBox Mode Register
#define AT91C_CAN1_MB1_MDL (AT91_CAST(AT91_REG *) 	0x400B8234) // (CAN1_MB1) MailBox Data Low Register
// ========== Register definition for CAN1_MB2 peripheral ========== 
#define AT91C_CAN1_MB2_MDL (AT91_CAST(AT91_REG *) 	0x400B8254) // (CAN1_MB2) MailBox Data Low Register
#define AT91C_CAN1_MB2_MSR (AT91_CAST(AT91_REG *) 	0x400B8250) // (CAN1_MB2) MailBox Status Register
#define AT91C_CAN1_MB2_MDH (AT91_CAST(AT91_REG *) 	0x400B8258) // (CAN1_MB2) MailBox Data High Register
#define AT91C_CAN1_MB2_MFID (AT91_CAST(AT91_REG *) 	0x400B824C) // (CAN1_MB2) MailBox Family ID Register
#define AT91C_CAN1_MB2_MAM (AT91_CAST(AT91_REG *) 	0x400B8244) // (CAN1_MB2) MailBox Acceptance Mask Register
#define AT91C_CAN1_MB2_MCR (AT91_CAST(AT91_REG *) 	0x400B825C) // (CAN1_MB2) MailBox Control Register
#define AT91C_CAN1_MB2_MMR (AT91_CAST(AT91_REG *) 	0x400B8240) // (CAN1_MB2) MailBox Mode Register
#define AT91C_CAN1_MB2_MID (AT91_CAST(AT91_REG *) 	0x400B8248) // (CAN1_MB2) MailBox ID Register
// ========== Register definition for CAN1_MB3 peripheral ========== 
#define AT91C_CAN1_MB3_MDH (AT91_CAST(AT91_REG *) 	0x400B8278) // (CAN1_MB3) MailBox Data High Register
#define AT91C_CAN1_MB3_MMR (AT91_CAST(AT91_REG *) 	0x400B8260) // (CAN1_MB3) MailBox Mode Register
#define AT91C_CAN1_MB3_MAM (AT91_CAST(AT91_REG *) 	0x400B8264) // (CAN1_MB3) MailBox Acceptance Mask Register
#define AT91C_CAN1_MB3_MSR (AT91_CAST(AT91_REG *) 	0x400B8270) // (CAN1_MB3) MailBox Status Register
#define AT91C_CAN1_MB3_MID (AT91_CAST(AT91_REG *) 	0x400B8268) // (CAN1_MB3) MailBox ID Register
#define AT91C_CAN1_MB3_MDL (AT91_CAST(AT91_REG *) 	0x400B8274) // (CAN1_MB3) MailBox Data Low Register
#define AT91C_CAN1_MB3_MCR (AT91_CAST(AT91_REG *) 	0x400B827C) // (CAN1_MB3) MailBox Control Register
#define AT91C_CAN1_MB3_MFID (AT91_CAST(AT91_REG *) 	0x400B826C) // (CAN1_MB3) MailBox Family ID Register
// ========== Register definition for CAN1_MB4 peripheral ========== 
#define AT91C_CAN1_MB4_MDL (AT91_CAST(AT91_REG *) 	0x400B8294) // (CAN1_MB4) MailBox Data Low Register
#define AT91C_CAN1_MB4_MMR (AT91_CAST(AT91_REG *) 	0x400B8280) // (CAN1_MB4) MailBox Mode Register
#define AT91C_CAN1_MB4_MCR (AT91_CAST(AT91_REG *) 	0x400B829C) // (CAN1_MB4) MailBox Control Register
#define AT91C_CAN1_MB4_MDH (AT91_CAST(AT91_REG *) 	0x400B8298) // (CAN1_MB4) MailBox Data High Register
#define AT91C_CAN1_MB4_MAM (AT91_CAST(AT91_REG *) 	0x400B8284) // (CAN1_MB4) MailBox Acceptance Mask Register
#define AT91C_CAN1_MB4_MFID (AT91_CAST(AT91_REG *) 	0x400B828C) // (CAN1_MB4) MailBox Family ID Register
#define AT91C_CAN1_MB4_MSR (AT91_CAST(AT91_REG *) 	0x400B8290) // (CAN1_MB4) MailBox Status Register
#define AT91C_CAN1_MB4_MID (AT91_CAST(AT91_REG *) 	0x400B8288) // (CAN1_MB4) MailBox ID Register
// ========== Register definition for CAN1_MB5 peripheral ========== 
#define AT91C_CAN1_MB5_MSR (AT91_CAST(AT91_REG *) 	0x400B82B0) // (CAN1_MB5) MailBox Status Register
#define AT91C_CAN1_MB5_MAM (AT91_CAST(AT91_REG *) 	0x400B82A4) // (CAN1_MB5) MailBox Acceptance Mask Register
#define AT91C_CAN1_MB5_MDH (AT91_CAST(AT91_REG *) 	0x400B82B8) // (CAN1_MB5) MailBox Data High Register
#define AT91C_CAN1_MB5_MDL (AT91_CAST(AT91_REG *) 	0x400B82B4) // (CAN1_MB5) MailBox Data Low Register
#define AT91C_CAN1_MB5_MMR (AT91_CAST(AT91_REG *) 	0x400B82A0) // (CAN1_MB5) MailBox Mode Register
#define AT91C_CAN1_MB5_MCR (AT91_CAST(AT91_REG *) 	0x400B82BC) // (CAN1_MB5) MailBox Control Register
#define AT91C_CAN1_MB5_MID (AT91_CAST(AT91_REG *) 	0x400B82A8) // (CAN1_MB5) MailBox ID Register
#define AT91C_CAN1_MB5_MFID (AT91_CAST(AT91_REG *) 	0x400B82AC) // (CAN1_MB5) MailBox Family ID Register
// ========== Register definition for CAN1_MB6 peripheral ========== 
#define AT91C_CAN1_MB6_MID (AT91_CAST(AT91_REG *) 	0x400B82C8) // (CAN1_MB6) MailBox ID Register
#define AT91C_CAN1_MB6_MDL (AT91_CAST(AT91_REG *) 	0x400B82D4) // (CAN1_MB6) MailBox Data Low Register
#define AT91C_CAN1_MB6_MSR (AT91_CAST(AT91_REG *) 	0x400B82D0) // (CAN1_MB6) MailBox Status Register
#define AT91C_CAN1_MB6_MDH (AT91_CAST(AT91_REG *) 	0x400B82D8) // (CAN1_MB6) MailBox Data High Register
#define AT91C_CAN1_MB6_MFID (AT91_CAST(AT91_REG *) 	0x400B82CC) // (CAN1_MB6) MailBox Family ID Register
#define AT91C_CAN1_MB6_MAM (AT91_CAST(AT91_REG *) 	0x400B82C4) // (CAN1_MB6) MailBox Acceptance Mask Register
#define AT91C_CAN1_MB6_MCR (AT91_CAST(AT91_REG *) 	0x400B82DC) // (CAN1_MB6) MailBox Control Register
#define AT91C_CAN1_MB6_MMR (AT91_CAST(AT91_REG *) 	0x400B82C0) // (CAN1_MB6) MailBox Mode Register
// ========== Register definition for CAN1_MB7 peripheral ========== 
#define AT91C_CAN1_MB7_MID (AT91_CAST(AT91_REG *) 	0x400B82E8) // (CAN1_MB7) MailBox ID Register
#define AT91C_CAN1_MB7_MMR (AT91_CAST(AT91_REG *) 	0x400B82E0) // (CAN1_MB7) MailBox Mode Register
#define AT91C_CAN1_MB7_MSR (AT91_CAST(AT91_REG *) 	0x400B82F0) // (CAN1_MB7) MailBox Status Register
#define AT91C_CAN1_MB7_MFID (AT91_CAST(AT91_REG *) 	0x400B82EC) // (CAN1_MB7) MailBox Family ID Register
#define AT91C_CAN1_MB7_MDL (AT91_CAST(AT91_REG *) 	0x400B82F4) // (CAN1_MB7) MailBox Data Low Register
#define AT91C_CAN1_MB7_MDH (AT91_CAST(AT91_REG *) 	0x400B82F8) // (CAN1_MB7) MailBox Data High Register
#define AT91C_CAN1_MB7_MCR (AT91_CAST(AT91_REG *) 	0x400B82FC) // (CAN1_MB7) MailBox Control Register
#define AT91C_CAN1_MB7_MAM (AT91_CAST(AT91_REG *) 	0x400B82E4) // (CAN1_MB7) MailBox Acceptance Mask Register
// ========== Register definition for CAN1 peripheral ========== 
#define AT91C_CAN1_TIMESTP (AT91_CAST(AT91_REG *) 	0x400B801C) // (CAN1) Time Stamp Register
#define AT91C_CAN1_TCR  (AT91_CAST(AT91_REG *) 	0x400B8024) // (CAN1) Transfer Command Register
#define AT91C_CAN1_TIM  (AT91_CAST(AT91_REG *) 	0x400B8018) // (CAN1) Timer Register
#define AT91C_CAN1_VR   (AT91_CAST(AT91_REG *) 	0x400B80FC) // (CAN1) Version Register
#define AT91C_CAN1_ACR  (AT91_CAST(AT91_REG *) 	0x400B8028) // (CAN1) Abort Command Register
#define AT91C_CAN1_MR   (AT91_CAST(AT91_REG *) 	0x400B8000) // (CAN1) Mode Register
#define AT91C_CAN1_IER  (AT91_CAST(AT91_REG *) 	0x400B8004) // (CAN1) Interrupt Enable Register
#define AT91C_CAN1_ECR  (AT91_CAST(AT91_REG *) 	0x400B8020) // (CAN1) Error Counter Register
#define AT91C_CAN1_IMR  (AT91_CAST(AT91_REG *) 	0x400B800C) // (CAN1) Interrupt Mask Register
#define AT91C_CAN1_BR   (AT91_CAST(AT91_REG *) 	0x400B8014) // (CAN1) Baudrate Register
#define AT91C_CAN1_IDR  (AT91_CAST(AT91_REG *) 	0x400B8008) // (CAN1) Interrupt Disable Register
#define AT91C_CAN1_SR   (AT91_CAST(AT91_REG *) 	0x400B8010) // (CAN1) Status Register

// *****************************************************************************
//               PIO DEFINITIONS FOR AT91SAM3X
// *****************************************************************************
#define AT91C_PIO_PA0        (1 <<  0) // Pin Controlled by PA0
#define AT91C_PA0_CANTX0   (AT91C_PIO_PA0) //  CAN0 Output
#define AT91C_PA0_PWML3    (AT91C_PIO_PA0) //  PWM Waveform Output Low Channel 3
#define AT91C_PIO_PA1        (1 <<  1) // Pin Controlled by PA1
#define AT91C_PA1_CANRX0   (AT91C_PIO_PA1) //  CAN0 Input
#define AT91C_PA1_PCK0     (AT91C_PIO_PA1) //  Programmable Clock Output 0
#define AT91C_PIO_PA10       (1 << 10) // Pin Controlled by PA10
#define AT91C_PA10_RXD0     (AT91C_PIO_PA10) //  USART0 Receive Data
#define AT91C_PA10_DACTRG   (AT91C_PIO_PA10) //  DAC Trigger
#define AT91C_PIO_PA11       (1 << 11) // Pin Controlled by PA11
#define AT91C_PA11_TXD0     (AT91C_PIO_PA11) //  USART0 Transmit Data
#define AT91C_PA11_ADCTRG   (AT91C_PIO_PA11) //  ADC Trigger
#define AT91C_PIO_PA12       (1 << 12) // Pin Controlled by PA12
#define AT91C_PA12_RXD1     (AT91C_PIO_PA12) //  USART1 Receive Data
#define AT91C_PA12_PWML1    (AT91C_PIO_PA12) //  PWM Waveform Output Low Channel 1
#define AT91C_PIO_PA13       (1 << 13) // Pin Controlled by PA13
#define AT91C_PA13_TXD1     (AT91C_PIO_PA13) //  USART1 Transmit Data
#define AT91C_PA13_PWMH2    (AT91C_PIO_PA13) //  PWM Waveform Output High Channel 2
#define AT91C_PIO_PA14       (1 << 14) // Pin Controlled by PA14
#define AT91C_PA14_RTS1     (AT91C_PIO_PA14) //  USART1 Request To Send
#define AT91C_PA14_SSC_TK   (AT91C_PIO_PA14) //  SSC Transmit Clock
#define AT91C_PIO_PA15       (1 << 15) // Pin Controlled by PA15
#define AT91C_PA15_CTS1     (AT91C_PIO_PA15) //  USART1 Clear To Send
#define AT91C_PA15_SSC_TF   (AT91C_PIO_PA15) //  SSC Transmit Frame Sync
#define AT91C_PIO_PA16       (1 << 16) // Pin Controlled by PA16
#define AT91C_PA16_SCK1     (AT91C_PIO_PA16) //  USART1 Serial Clock
#define AT91C_PA16_SSC_TD   (AT91C_PIO_PA16) //  SSC Transmit Data
#define AT91C_PIO_PA17       (1 << 17) // Pin Controlled by PA17
#define AT91C_PA17_TWD0     (AT91C_PIO_PA17) //  TWI0 Two-wire Serial Data
#define AT91C_PA17_SCK0     (AT91C_PIO_PA17) //  USART0 Serial Clock
#define AT91C_PIO_PA18       (1 << 18) // Pin Controlled by PA18
#define AT91C_PA18_TWCK0    (AT91C_PIO_PA18) //  TWI0 Two-Wire Serial Clock
#define AT91C_PA18_A20      (AT91C_PIO_PA18) //  EBI Address Bus 20
#define AT91C_PIO_PA19       (1 << 19) // Pin Controlled by PA19
#define AT91C_PA19_MCI_CK   (AT91C_PIO_PA19) //  Multimedia Card Clock
#define AT91C_PA19_PWMH1    (AT91C_PIO_PA19) //  PWM Waveform Output High Channel 1
#define AT91C_PIO_PA2        (1 <<  2) // Pin Controlled by PA2
#define AT91C_PA2_TIOA1    (AT91C_PIO_PA2) //  TC Channel 1 I/O Line A
#define AT91C_PA2_NANDRDY  (AT91C_PIO_PA2) //  NAND Ready
#define AT91C_PIO_PA20       (1 << 20) // Pin Controlled by PA20
#define AT91C_PA20_MCI_CDA  (AT91C_PIO_PA20) //  Multimedia Card Slot A Command
#define AT91C_PA20_PWML2    (AT91C_PIO_PA20) //  PWM Waveform Output Low Channel 2
#define AT91C_PIO_PA21       (1 << 21) // Pin Controlled by PA21
#define AT91C_PA21_MCI_DA0  (AT91C_PIO_PA21) //  Multimedia Card Slot A Data 0
#define AT91C_PA21_PWML0    (AT91C_PIO_PA21) //  PWM Waveform Output Low Channel 0
#define AT91C_PIO_PA22       (1 << 22) // Pin Controlled by PA22
#define AT91C_PA22_MCI_DA1  (AT91C_PIO_PA22) //  Multimedia Card Slot A Data 1
#define AT91C_PA22_TCLK3    (AT91C_PIO_PA22) //  TC Channel 3 External Clock Input
#define AT91C_PIO_PA23       (1 << 23) // Pin Controlled by PA23
#define AT91C_PA23_MCI_DA2  (AT91C_PIO_PA23) //  Multimedia Card Slot A Data 2
#define AT91C_PA23_TCLK4    (AT91C_PIO_PA23) //  TC Channel 4 External Clock Input
#define AT91C_PIO_PA24       (1 << 24) // Pin Controlled by PA24
#define AT91C_PA24_MCI_DA3  (AT91C_PIO_PA24) //  Multimedia Card Slot A Data 3
#define AT91C_PA24_PCK1     (AT91C_PIO_PA24) //  Programmable Clock Output 1
#define AT91C_PIO_PA25       (1 << 25) // Pin Controlled by PA25
#define AT91C_PA25_SPI0_MISO (AT91C_PIO_PA25) //  SPI0 Master In Slave Out
#define AT91C_PA25_A18      (AT91C_PIO_PA25) //  EBI Address Bus 18
#define AT91C_PIO_PA26       (1 << 26) // Pin Controlled by PA26
#define AT91C_PA26_SPI0_MOSI (AT91C_PIO_PA26) //  SPI0 Master Out Slave In
#define AT91C_PA26_A19      (AT91C_PIO_PA26) //  EBI Address Bus 19
#define AT91C_PIO_PA27       (1 << 27) // Pin Controlled by PA27
#define AT91C_PA27_SPI0_SPCK (AT91C_PIO_PA27) //  SPI0 Serial Clock
#define AT91C_PA27_A20      (AT91C_PIO_PA27) //  EBI Address Bus 20
#define AT91C_PIO_PA28       (1 << 28) // Pin Controlled by PA28
#define AT91C_PA28_SPI0_NPCS0 (AT91C_PIO_PA28) //  SPI0 Peripheral Chip Select 0
#define AT91C_PA28_PCK2     (AT91C_PIO_PA28) //  Programmable Clock Output 2
#define AT91C_PIO_PA29       (1 << 29) // Pin Controlled by PA29
#define AT91C_PA29_SPI0_NPCS1 (AT91C_PIO_PA29) //  SPI0 Peripheral Chip Select 1
#define AT91C_PA29_NRD      (AT91C_PIO_PA29) //  SMC Read Signal
#define AT91C_PIO_PA3        (1 <<  3) // Pin Controlled by PA3
#define AT91C_PA3_TIOB1    (AT91C_PIO_PA3) //  TC Channel 1 I/O Line B
#define AT91C_PA3_PWMFI1   (AT91C_PIO_PA3) //  PWM Fault Input Channel 1
#define AT91C_PIO_PA30       (1 << 30) // Pin Controlled by PA30
#define AT91C_PA30_SPI0_NPCS2 (AT91C_PIO_PA30) //  SPI0 Peripheral Chip Select 2
#define AT91C_PA30_PCK1     (AT91C_PIO_PA30) //  Programmable Clock Output 1
#define AT91C_PIO_PA31       (1 << 31) // Pin Controlled by PA31
#define AT91C_PA31_SPI0_NPCS3 (AT91C_PIO_PA31) //  SPI0 Peripheral Chip Select 3
#define AT91C_PA31_PCK2     (AT91C_PIO_PA31) //  Programmable Clock Output 2
#define AT91C_PIO_PA4        (1 <<  4) // Pin Controlled by PA4
#define AT91C_PA4_TCLK1    (AT91C_PIO_PA4) //  TC Channel 1 External Clock Input
#define AT91C_PA4_NWAIT    (AT91C_PIO_PA4) //  EBI External Wait Signal
#define AT91C_PIO_PA5        (1 <<  5) // Pin Controlled by PA5
#define AT91C_PA5_TIOA2    (AT91C_PIO_PA5) //  TC Channel 2 I/O Line A
#define AT91C_PA5_PWMFI0   (AT91C_PIO_PA5) //  PWM Fault Input Channel 0
#define AT91C_PIO_PA6        (1 <<  6) // Pin Controlled by PA6
#define AT91C_PA6_TIOB2    (AT91C_PIO_PA6) //  TC Channel 2 I/O Line B
#define AT91C_PA6_NCS0     (AT91C_PIO_PA6) //  SMC Chip Select Line 0
#define AT91C_PIO_PA7        (1 <<  7) // Pin Controlled by PA7
#define AT91C_PA7_TCLK2    (AT91C_PIO_PA7) //  TC Channel 2 External Clock Input
#define AT91C_PA7_NCS1     (AT91C_PIO_PA7) //  SMC Chip Select Line 1
#define AT91C_PIO_PA8        (1 <<  8) // Pin Controlled by PA8
#define AT91C_PA8_DRXD     (AT91C_PIO_PA8) //  Debug Unit (DBGU) Receive Data
#define AT91C_PA8_PWMH0    (AT91C_PIO_PA8) //  PWM Waveform Output High Channel 0
#define AT91C_PIO_PA9        (1 <<  9) // Pin Controlled by PA9
#define AT91C_PA9_DTXD     (AT91C_PIO_PA9) //  Debug Unit (DBGU) Transmit Data
#define AT91C_PA9_PWMH3    (AT91C_PIO_PA9) //  PWM Waveform Output High Channel 3
#define AT91C_PIO_PB0        (1 <<  0) // Pin Controlled by PB0
#define AT91C_PB0_ETXCK_EREFCK (AT91C_PIO_PB0) //  EMAC Transmit Clock / EMAC Reference Clock
#define AT91C_PIO_PB1        (1 <<  1) // Pin Controlled by PB1
#define AT91C_PB1_ETXEN    (AT91C_PIO_PB1) //  EMAC Transmit Enable
#define AT91C_PIO_PB10       (1 << 10) // Pin Controlled by PB10
#define AT91C_PB10_VBOF     (AT91C_PIO_PB10) //  
#define AT91C_PB10_A18      (AT91C_PIO_PB10) //  EBI Address Bus 18
#define AT91C_PIO_PB11       (1 << 11) // Pin Controlled by PB11
#define AT91C_PB11_ID       (AT91C_PIO_PB11) //  
#define AT91C_PB11_A19      (AT91C_PIO_PB11) //  EBI Address Bus 19
#define AT91C_PIO_PB12       (1 << 12) // Pin Controlled by PB12
#define AT91C_PB12_TWD1     (AT91C_PIO_PB12) //  TWI1 Two-wire Serial Data
#define AT91C_PB12_PWMH0    (AT91C_PIO_PB12) //  PWM Waveform Output High Channel 0
#define AT91C_PIO_PB13       (1 << 13) // Pin Controlled by PB13
#define AT91C_PB13_TWCK1    (AT91C_PIO_PB13) //  TWI1 Two-Wire Serial Clock
#define AT91C_PB13_PWMH1    (AT91C_PIO_PB13) //  PWM Waveform Output High Channel 1
#define AT91C_PIO_PB14       (1 << 14) // Pin Controlled by PB14
#define AT91C_PB14_CANTX1   (AT91C_PIO_PB14) //  CAN1 Output
#define AT91C_PB14_PWMH2    (AT91C_PIO_PB14) //  PWM Waveform Output High Channel 2
#define AT91C_PIO_PB15       (1 << 15) // Pin Controlled by PB15
#define AT91C_PB15_CANRX1   (AT91C_PIO_PB15) //  CAN1 Input
#define AT91C_PB15_PWMH3    (AT91C_PIO_PB15) //  PWM Waveform Output High Channel 3
#define AT91C_PIO_PB16       (1 << 16) // Pin Controlled by PB16
#define AT91C_PB16_TCLK5    (AT91C_PIO_PB16) //  TC Channel 5 External Clock Input
#define AT91C_PB16_PWML0    (AT91C_PIO_PB16) //  PWM Waveform Output Low Channel 0
#define AT91C_PIO_PB17       (1 << 17) // Pin Controlled by PB17
#define AT91C_PB17_SSC_RF   (AT91C_PIO_PB17) //  SSC Receive Frame Sync
#define AT91C_PB17_PWML1    (AT91C_PIO_PB17) //  PWM Waveform Output Low Channel 1
#define AT91C_PIO_PB18       (1 << 18) // Pin Controlled by PB18
#define AT91C_PB18_SSC_RD   (AT91C_PIO_PB18) //  SSC Receive Data
#define AT91C_PB18_PWML2    (AT91C_PIO_PB18) //  PWM Waveform Output Low Channel 2
#define AT91C_PIO_PB19       (1 << 19) // Pin Controlled by PB19
#define AT91C_PB19_SSC_RK   (AT91C_PIO_PB19) //  SSC Receive Clock
#define AT91C_PB19_PWML3    (AT91C_PIO_PB19) //  PWM Waveform Output Low Channel 3
#define AT91C_PIO_PB2        (1 <<  2) // Pin Controlled by PB2
#define AT91C_PB2_ETX0     (AT91C_PIO_PB2) //  EMAC Transmit Data 0
#define AT91C_PIO_PB20       (1 << 20) // Pin Controlled by PB20
#define AT91C_PB20_TXD2     (AT91C_PIO_PB20) //  USART2 Transmit Data
#define AT91C_PB20_SPI0_NPCS1 (AT91C_PIO_PB20) //  SPI0 Peripheral Chip Select 1
#define AT91C_PIO_PB21       (1 << 21) // Pin Controlled by PB21
#define AT91C_PB21_RXD2     (AT91C_PIO_PB21) //  USART2 Receive Data
#define AT91C_PB21_SPI0_NPCS2 (AT91C_PIO_PB21) //  SPI0 Peripheral Chip Select 2
#define AT91C_PIO_PB22       (1 << 22) // Pin Controlled by PB22
#define AT91C_PB22_RTS2     (AT91C_PIO_PB22) //  USART2 Request To Send
#define AT91C_PB22_PCK0     (AT91C_PIO_PB22) //  Programmable Clock Output 0
#define AT91C_PIO_PB23       (1 << 23) // Pin Controlled by PB23
#define AT91C_PB23_CTS2     (AT91C_PIO_PB23) //  USART2 Clear To Send
#define AT91C_PB23_SPI0_NPCS3 (AT91C_PIO_PB23) //  SPI0 Peripheral Chip Select 3
#define AT91C_PIO_PB24       (1 << 24) // Pin Controlled by PB24
#define AT91C_PB24_SCK2     (AT91C_PIO_PB24) //  USART2 Serial Clock
#define AT91C_PB24_NCS2     (AT91C_PIO_PB24) //  SMC Chip Select Line 2
#define AT91C_PIO_PB25       (1 << 25) // Pin Controlled by PB25
#define AT91C_PB25_RTS0     (AT91C_PIO_PB25) //  USART0 Request To Send
#define AT91C_PB25_TIOA0    (AT91C_PIO_PB25) //  TC Channel 0 I/O Line A
#define AT91C_PIO_PB26       (1 << 26) // Pin Controlled by PB26
#define AT91C_PB26_CTS0     (AT91C_PIO_PB26) //  USART0 Clear To Send
#define AT91C_PB26_TCLK0    (AT91C_PIO_PB26) //  TC Channel 0 External Clock Input
#define AT91C_PIO_PB27       (1 << 27) // Pin Controlled by PB27
#define AT91C_PB27_NCS3     (AT91C_PIO_PB27) //  SMC Chip Select Line 3
#define AT91C_PB27_TIOB0    (AT91C_PIO_PB27) //  TC Channel 0 I/O Line B
#define AT91C_PIO_PB28       (1 << 28) // Pin Controlled by PB28
#define AT91C_PIO_PB29       (1 << 29) // Pin Controlled by PB29
#define AT91C_PIO_PB3        (1 <<  3) // Pin Controlled by PB3
#define AT91C_PB3_ETX1     (AT91C_PIO_PB3) //  EMAC Transmit Data 1
#define AT91C_PIO_PB30       (1 << 30) // Pin Controlled by PB30
#define AT91C_PIO_PB31       (1 << 31) // Pin Controlled by PB31
#define AT91C_PIO_PB4        (1 <<  4) // Pin Controlled by PB4
#define AT91C_PB4_ECRS     (AT91C_PIO_PB4) //  EMAC Carrier Sense and Data Valid
#define AT91C_PIO_PB5        (1 <<  5) // Pin Controlled by PB5
#define AT91C_PB5_ERX0     (AT91C_PIO_PB5) //  EMAC Receive Data 0
#define AT91C_PIO_PB6        (1 <<  6) // Pin Controlled by PB6
#define AT91C_PB6_ERX1     (AT91C_PIO_PB6) //  EMAC Receive Data 1
#define AT91C_PB6_PWML4    (AT91C_PIO_PB6) //  PWM Waveform Output Low Channel 4
#define AT91C_PIO_PB7        (1 <<  7) // Pin Controlled by PB7
#define AT91C_PB7_ERXER    (AT91C_PIO_PB7) //  EMAC Receive Error
#define AT91C_PB7_PWML5    (AT91C_PIO_PB7) //  PWM Waveform Output Low Channel 5
#define AT91C_PIO_PB8        (1 <<  8) // Pin Controlled by PB8
#define AT91C_PB8_EMDC     (AT91C_PIO_PB8) //  EMAC Management Data Clock
#define AT91C_PB8_PWML6    (AT91C_PIO_PB8) //  PWM Waveform Output Low Channel 6
#define AT91C_PIO_PB9        (1 <<  9) // Pin Controlled by PB9
#define AT91C_PB9_EMDIO    (AT91C_PIO_PB9) //  EMAC Management Data Input/Output
#define AT91C_PB9_PWML7    (AT91C_PIO_PB9) //  PWM Waveform Output Low Channel 7
#define AT91C_PIO_PC0        (1 <<  0) // Pin Controlled by PC0
#define AT91C_PIO_PC1        (1 <<  1) // Pin Controlled by PC1
#define AT91C_PIO_PC10       (1 << 10) // Pin Controlled by PC10
#define AT91C_PC10_D8       (AT91C_PIO_PC10) //  EBI Data Bus 8
#define AT91C_PC10_ERXDV    (AT91C_PIO_PC10) //  EMAC Receive Data Valid
#define AT91C_PIO_PC11       (1 << 11) // Pin Controlled by PC11
#define AT91C_PC11_D9       (AT91C_PIO_PC11) //  EBI Data Bus 9
#define AT91C_PC11_ERX2     (AT91C_PIO_PC11) //  EMAC Receive Data 2
#define AT91C_PIO_PC12       (1 << 12) // Pin Controlled by PC12
#define AT91C_PC12_D10      (AT91C_PIO_PC12) //  EBI Data Bus 10
#define AT91C_PC12_ERX3     (AT91C_PIO_PC12) //  EMAC Receive Data 3
#define AT91C_PIO_PC13       (1 << 13) // Pin Controlled by PC13
#define AT91C_PC13_D11      (AT91C_PIO_PC13) //  EBI Data Bus 11
#define AT91C_PC13_ECOL     (AT91C_PIO_PC13) //  EMAC Collision Detected
#define AT91C_PIO_PC14       (1 << 14) // Pin Controlled by PC14
#define AT91C_PC14_D12      (AT91C_PIO_PC14) //  EBI Data Bus 12
#define AT91C_PC14_ERXCK    (AT91C_PIO_PC14) //  EMAC Receive Clock
#define AT91C_PIO_PC15       (1 << 15) // Pin Controlled by PC15
#define AT91C_PC15_D13      (AT91C_PIO_PC15) //  EBI Data Bus 13
#define AT91C_PC15_ETX2     (AT91C_PIO_PC15) //  EMAC Transmit Data 2
#define AT91C_PIO_PC16       (1 << 16) // Pin Controlled by PC16
#define AT91C_PC16_D14      (AT91C_PIO_PC16) //  EBI Data Bus 14
#define AT91C_PC16_ETX3     (AT91C_PIO_PC16) //  EMAC Transmit Data 3
#define AT91C_PIO_PC17       (1 << 17) // Pin Controlled by PC17
#define AT91C_PC17_D15      (AT91C_PIO_PC17) //  EBI Data Bus 15
#define AT91C_PC17_ETXER    (AT91C_PIO_PC17) //  EMAC Transmikt Coding Error
#define AT91C_PIO_PC18       (1 << 18) // Pin Controlled by PC18
#define AT91C_PC18_NWR0_NWE (AT91C_PIO_PC18) //  SMC Write Signal 0 / SMC Write Enable
#define AT91C_PC18_PWMH6    (AT91C_PIO_PC18) //  PWM Waveform Output High Channel 6
#define AT91C_PIO_PC19       (1 << 19) // Pin Controlled by PC19
#define AT91C_PC19_NANDOE   (AT91C_PIO_PC19) //  NAND Flash Output Enable
#define AT91C_PC19_PWMH5    (AT91C_PIO_PC19) //  PWM Waveform Output High Channel 5
#define AT91C_PIO_PC2        (1 <<  2) // Pin Controlled by PC2
#define AT91C_PC2_D0       (AT91C_PIO_PC2) //  EBI Data Bus 0
#define AT91C_PC2_PWML0    (AT91C_PIO_PC2) //  PWM Waveform Output Low Channel 0
#define AT91C_PIO_PC20       (1 << 20) // Pin Controlled by PC20
#define AT91C_PC20_NANDWE   (AT91C_PIO_PC20) //  NAND Flash Write Enable
#define AT91C_PC20_PWMH4    (AT91C_PIO_PC20) //  PWM Waveform Output High Channel 4
#define AT91C_PIO_PC21       (1 << 21) // Pin Controlled by PC21
#define AT91C_PC21_A0_NBS0  (AT91C_PIO_PC21) //  EBI Address Bus 0 / SMC Byte Mask 0
#define AT91C_PC21_PWML4    (AT91C_PIO_PC21) //  PWM Waveform Output Low Channel 4
#define AT91C_PIO_PC22       (1 << 22) // Pin Controlled by PC22
#define AT91C_PC22_A1_NBS2  (AT91C_PIO_PC22) //  EBI Address Bus 1 / SMC Byte Mask 2
#define AT91C_PC22_PWML5    (AT91C_PIO_PC22) //  PWM Waveform Output Low Channel 5
#define AT91C_PIO_PC23       (1 << 23) // Pin Controlled by PC23
#define AT91C_PC23_A2       (AT91C_PIO_PC23) //  EBI Address Bus 2
#define AT91C_PC23_PWML6    (AT91C_PIO_PC23) //  PWM Waveform Output Low Channel 6
#define AT91C_PIO_PC24       (1 << 24) // Pin Controlled by PC24
#define AT91C_PC24_A3       (AT91C_PIO_PC24) //  EBI Address Bus 3
#define AT91C_PC24_PWML7    (AT91C_PIO_PC24) //  PWM Waveform Output Low Channel 7
#define AT91C_PIO_PC25       (1 << 25) // Pin Controlled by PC25
#define AT91C_PC25_A4       (AT91C_PIO_PC25) //  EBI Address Bus 4
#define AT91C_PC25_TIOA6    (AT91C_PIO_PC25) //  TC Channel 6 I/O Line A
#define AT91C_PIO_PC26       (1 << 26) // Pin Controlled by PC26
#define AT91C_PC26_A5       (AT91C_PIO_PC26) //  EBI Address Bus 5
#define AT91C_PC26_TIOB6    (AT91C_PIO_PC26) //  TC Channel 6 I/O Line B
#define AT91C_PIO_PC27       (1 << 27) // Pin Controlled by PC27
#define AT91C_PC27_A6       (AT91C_PIO_PC27) //  EBI Address Bus 6
#define AT91C_PC27_TCLK6    (AT91C_PIO_PC27) //  TC Channel 6 External Clock Input
#define AT91C_PIO_PC28       (1 << 28) // Pin Controlled by PC28
#define AT91C_PC28_A7       (AT91C_PIO_PC28) //  EBI Address Bus 7
#define AT91C_PC28_TIOA7    (AT91C_PIO_PC28) //  TC Channel 7 I/O Line A
#define AT91C_PIO_PC29       (1 << 29) // Pin Controlled by PC29
#define AT91C_PC29_A8       (AT91C_PIO_PC29) //  EBI Address Bus 8
#define AT91C_PC29_TIOB7    (AT91C_PIO_PC29) //  TC Channel 7 I/O Line B
#define AT91C_PIO_PC3        (1 <<  3) // Pin Controlled by PC3
#define AT91C_PC3_D1       (AT91C_PIO_PC3) //  EBI Data Bus 1
#define AT91C_PC3_PWMH0    (AT91C_PIO_PC3) //  PWM Waveform Output High Channel 0
#define AT91C_PIO_PC30       (1 << 30) // Pin Controlled by PC30
#define AT91C_PC30_A9       (AT91C_PIO_PC30) //  EBI Address Bus 9
#define AT91C_PC30_TCLK7    (AT91C_PIO_PC30) //  TC Channel 7 External Clock Input
#define AT91C_PIO_PC4        (1 <<  4) // Pin Controlled by PC4
#define AT91C_PC4_D2       (AT91C_PIO_PC4) //  EBI Data Bus 2
#define AT91C_PC4_PWML1    (AT91C_PIO_PC4) //  PWM Waveform Output Low Channel 1
#define AT91C_PIO_PC5        (1 <<  5) // Pin Controlled by PC5
#define AT91C_PC5_D3       (AT91C_PIO_PC5) //  EBI Data Bus 3
#define AT91C_PC5_PWMH1    (AT91C_PIO_PC5) //  PWM Waveform Output High Channel 1
#define AT91C_PIO_PC6        (1 <<  6) // Pin Controlled by PC6
#define AT91C_PC6_D4       (AT91C_PIO_PC6) //  EBI Data Bus 4
#define AT91C_PC6_PWML2    (AT91C_PIO_PC6) //  PWM Waveform Output Low Channel 2
#define AT91C_PIO_PC7        (1 <<  7) // Pin Controlled by PC7
#define AT91C_PC7_D5       (AT91C_PIO_PC7) //  EBI Data Bus 5
#define AT91C_PC7_PWMH2    (AT91C_PIO_PC7) //  PWM Waveform Output High Channel 2
#define AT91C_PIO_PC8        (1 <<  8) // Pin Controlled by PC8
#define AT91C_PC8_D6       (AT91C_PIO_PC8) //  EBI Data Bus 6
#define AT91C_PC8_PWML3    (AT91C_PIO_PC8) //  PWM Waveform Output Low Channel 3
#define AT91C_PIO_PC9        (1 <<  9) // Pin Controlled by PC9
#define AT91C_PC9_D7       (AT91C_PIO_PC9) //  EBI Data Bus 7
#define AT91C_PC9_PWMH3    (AT91C_PIO_PC9) //  PWM Waveform Output High Channel 3
#define AT91C_PIO_PD0        (1 <<  0) // Pin Controlled by PD0
#define AT91C_PD0_A10      (AT91C_PIO_PD0) //  EBI Address Bus 10
#define AT91C_PD0_MCI_DA4  (AT91C_PIO_PD0) //  Multimedia Card Slot A Data 4
#define AT91C_PIO_PD1        (1 <<  1) // Pin Controlled by PD1
#define AT91C_PD1_A11      (AT91C_PIO_PD1) //  EBI Address Bus 11
#define AT91C_PD1_MCI_DA5  (AT91C_PIO_PD1) //  Multimedia Card Slot A Data 5
#define AT91C_PIO_PD10       (1 << 10) // Pin Controlled by PD10
#define AT91C_PD10_NWR1_NBS1 (AT91C_PIO_PD10) //  SMC Write Signal 1 / SMC Byte Mask 1
#define AT91C_PIO_PD11       (1 << 11) // Pin Controlled by PD11
#define AT91C_PD11_SDA10    (AT91C_PIO_PD11) //  SDRAM Address 10 Line
#define AT91C_PIO_PD12       (1 << 12) // Pin Controlled by PD12
#define AT91C_PD12_SDCS     (AT91C_PIO_PD12) //  SDRAM Controller Chip Select Line
#define AT91C_PIO_PD13       (1 << 13) // Pin Controlled by PD13
#define AT91C_PD13_SDCKE    (AT91C_PIO_PD13) //  SDRAM Clock Enable
#define AT91C_PIO_PD14       (1 << 14) // Pin Controlled by PD14
#define AT91C_PD14_SDWE     (AT91C_PIO_PD14) //  SDRAM Write Enable
#define AT91C_PIO_PD15       (1 << 15) // Pin Controlled by PD15
#define AT91C_PD15_RAS      (AT91C_PIO_PD15) //  SDRAM Row Signal
#define AT91C_PIO_PD16       (1 << 16) // Pin Controlled by PD16
#define AT91C_PD16_CAS      (AT91C_PIO_PD16) //  SDRAM Column Signal
#define AT91C_PIO_PD17       (1 << 17) // Pin Controlled by PD17
#define AT91C_PD17_A5       (AT91C_PIO_PD17) //  EBI Address Bus 5
#define AT91C_PIO_PD18       (1 << 18) // Pin Controlled by PD18
#define AT91C_PD18_A6       (AT91C_PIO_PD18) //  EBI Address Bus 6
#define AT91C_PIO_PD19       (1 << 19) // Pin Controlled by PD19
#define AT91C_PD19_A7       (AT91C_PIO_PD19) //  EBI Address Bus 7
#define AT91C_PIO_PD2        (1 <<  2) // Pin Controlled by PD2
#define AT91C_PD2_A12      (AT91C_PIO_PD2) //  EBI Address Bus 12
#define AT91C_PD2_MCI_DA6  (AT91C_PIO_PD2) //  Multimedia Card Slot A Data 6
#define AT91C_PIO_PD20       (1 << 20) // Pin Controlled by PD20
#define AT91C_PD20_A8       (AT91C_PIO_PD20) //  EBI Address Bus 8
#define AT91C_PIO_PD21       (1 << 21) // Pin Controlled by PD21
#define AT91C_PD21_A9       (AT91C_PIO_PD21) //  EBI Address Bus 9
#define AT91C_PIO_PD22       (1 << 22) // Pin Controlled by PD22
#define AT91C_PD22_A10      (AT91C_PIO_PD22) //  EBI Address Bus 10
#define AT91C_PIO_PD23       (1 << 23) // Pin Controlled by PD23
#define AT91C_PD23_A11      (AT91C_PIO_PD23) //  EBI Address Bus 11
#define AT91C_PIO_PD24       (1 << 24) // Pin Controlled by PD24
#define AT91C_PD24_A12      (AT91C_PIO_PD24) //  EBI Address Bus 12
#define AT91C_PIO_PD25       (1 << 25) // Pin Controlled by PD25
#define AT91C_PD25_A13      (AT91C_PIO_PD25) //  EBI Address Bus 13
#define AT91C_PIO_PD26       (1 << 26) // Pin Controlled by PD26
#define AT91C_PD26_A14      (AT91C_PIO_PD26) //  EBI Address Bus 14
#define AT91C_PIO_PD27       (1 << 27) // Pin Controlled by PD27
#define AT91C_PD27_A15      (AT91C_PIO_PD27) //  EBI Address Bus 15
#define AT91C_PIO_PD28       (1 << 28) // Pin Controlled by PD28
#define AT91C_PD28_A16_BA0  (AT91C_PIO_PD28) //  EBI Address Bus 16 / SDRAM Bank Select 0
#define AT91C_PIO_PD29       (1 << 29) // Pin Controlled by PD29
#define AT91C_PD29_A17_BA1  (AT91C_PIO_PD29) //  EBI Address Bus 17 / SDRAM Bank Select 1
#define AT91C_PIO_PD3        (1 <<  3) // Pin Controlled by PD3
#define AT91C_PD3_A13      (AT91C_PIO_PD3) //  EBI Address Bus 13
#define AT91C_PD3_MCI_DA7  (AT91C_PIO_PD3) //  Multimedia Card Slot A Data 7
#define AT91C_PIO_PD30       (1 << 30) // Pin Controlled by PD30
#define AT91C_PD30_A18      (AT91C_PIO_PD30) //  EBI Address Bus 18
#define AT91C_PIO_PD4        (1 <<  4) // Pin Controlled by PD4
#define AT91C_PD4_A14      (AT91C_PIO_PD4) //  EBI Address Bus 14
#define AT91C_PD4_TXD3     (AT91C_PIO_PD4) //  USART3 Transmit Data
#define AT91C_PIO_PD5        (1 <<  5) // Pin Controlled by PD5
#define AT91C_PD5_A15      (AT91C_PIO_PD5) //  EBI Address Bus 15
#define AT91C_PD5_RXD3     (AT91C_PIO_PD5) //  USART3 Receive Data
#define AT91C_PIO_PD6        (1 <<  6) // Pin Controlled by PD6
#define AT91C_PD6_A16_BA0  (AT91C_PIO_PD6) //  EBI Address Bus 16 / SDRAM Bank Select 0
#define AT91C_PD6_PWMFI2   (AT91C_PIO_PD6) //  PWM Fault Input Channel 2
#define AT91C_PIO_PD7        (1 <<  7) // Pin Controlled by PD7
#define AT91C_PD7_A17_BA1  (AT91C_PIO_PD7) //  EBI Address Bus 17 / SDRAM Bank Select 1
#define AT91C_PD7_TIOA8    (AT91C_PIO_PD7) //  TC Channel 8 I/O Line A
#define AT91C_PIO_PD8        (1 <<  8) // Pin Controlled by PD8
#define AT91C_PD8_A21_NANDALE (AT91C_PIO_PD8) //  EBI Address Bus 21 / ???
#define AT91C_PD8_TIOB8    (AT91C_PIO_PD8) //  TC Channel 8 I/O Line B
#define AT91C_PIO_PD9        (1 <<  9) // Pin Controlled by PD9
#define AT91C_PD9_A22_NANDCLE (AT91C_PIO_PD9) //  EBI Address Bus 22 / ???
#define AT91C_PD9_TCLK8    (AT91C_PIO_PD9) //  TC Channel 8 External Clock Input
#define AT91C_PIO_PE0        (1 <<  0) // Pin Controlled by PE0
#define AT91C_PE0_A19      (AT91C_PIO_PE0) //  EBI Address Bus 19
#define AT91C_PIO_PE1        (1 <<  1) // Pin Controlled by PE1
#define AT91C_PE1_A20      (AT91C_PIO_PE1) //  EBI Address Bus 20
#define AT91C_PIO_PE10       (1 << 10) // Pin Controlled by PE10
#define AT91C_PE10_TIOB3    (AT91C_PIO_PE10) //  TC Channel 3 I/O Line B
#define AT91C_PIO_PE11       (1 << 11) // Pin Controlled by PE11
#define AT91C_PE11_TIOA4    (AT91C_PIO_PE11) //  TC Channel 4 I/O Line A
#define AT91C_PIO_PE12       (1 << 12) // Pin Controlled by PE12
#define AT91C_PE12_TIOB4    (AT91C_PIO_PE12) //  TC Channel 4 I/O Line B
#define AT91C_PIO_PE13       (1 << 13) // Pin Controlled by PE13
#define AT91C_PE13_TIOA5    (AT91C_PIO_PE13) //  TC Channel 5 I/O Line A
#define AT91C_PIO_PE14       (1 << 14) // Pin Controlled by PE14
#define AT91C_PE14_TIOB5    (AT91C_PIO_PE14) //  TC Channel 5 I/O Line B
#define AT91C_PIO_PE15       (1 << 15) // Pin Controlled by PE15
#define AT91C_PE15_PWMH0    (AT91C_PIO_PE15) //  PWM Waveform Output High Channel 0
#define AT91C_PIO_PE16       (1 << 16) // Pin Controlled by PE16
#define AT91C_PE16_PWMH1    (AT91C_PIO_PE16) //  PWM Waveform Output High Channel 1
#define AT91C_PE16_SCK3     (AT91C_PIO_PE16) //  USART3 Serial Clock
#define AT91C_PIO_PE17       (1 << 17) // Pin Controlled by PE17
#define AT91C_PE17_PWML2    (AT91C_PIO_PE17) //  PWM Waveform Output Low Channel 2
#define AT91C_PIO_PE18       (1 << 18) // Pin Controlled by PE18
#define AT91C_PE18_PWML0    (AT91C_PIO_PE18) //  PWM Waveform Output Low Channel 0
#define AT91C_PE18_NCS6     (AT91C_PIO_PE18) //  SMC Chip Select Line 6
#define AT91C_PIO_PE19       (1 << 19) // Pin Controlled by PE19
#define AT91C_PE19_PWML4    (AT91C_PIO_PE19) //  PWM Waveform Output Low Channel 4
#define AT91C_PIO_PE2        (1 <<  2) // Pin Controlled by PE2
#define AT91C_PE2_A21_NANDALE (AT91C_PIO_PE2) //  EBI Address Bus 21 / ???
#define AT91C_PIO_PE20       (1 << 20) // Pin Controlled by PE20
#define AT91C_PE20_PWMH4    (AT91C_PIO_PE20) //  PWM Waveform Output High Channel 4
#define AT91C_PE20_MCI_CDB  (AT91C_PIO_PE20) //  Multimedia Card Slot B Command
#define AT91C_PIO_PE21       (1 << 21) // Pin Controlled by PE21
#define AT91C_PE21_PWML5    (AT91C_PIO_PE21) //  PWM Waveform Output Low Channel 5
#define AT91C_PIO_PE22       (1 << 22) // Pin Controlled by PE22
#define AT91C_PE22_PWMH5    (AT91C_PIO_PE22) //  PWM Waveform Output High Channel 5
#define AT91C_PE22_MCI_DB0  (AT91C_PIO_PE22) //  Multimedia Card Slot B Data 0
#define AT91C_PIO_PE23       (1 << 23) // Pin Controlled by PE23
#define AT91C_PE23_PWML6    (AT91C_PIO_PE23) //  PWM Waveform Output Low Channel 6
#define AT91C_PIO_PE24       (1 << 24) // Pin Controlled by PE24
#define AT91C_PE24_PWMH6    (AT91C_PIO_PE24) //  PWM Waveform Output High Channel 6
#define AT91C_PE24_MCI_DB1  (AT91C_PIO_PE24) //  Multimedia Card Slot B Data 1
#define AT91C_PIO_PE25       (1 << 25) // Pin Controlled by PE25
#define AT91C_PE25_PWML7    (AT91C_PIO_PE25) //  PWM Waveform Output Low Channel 7
#define AT91C_PIO_PE26       (1 << 26) // Pin Controlled by PE26
#define AT91C_PE26_PWMH7    (AT91C_PIO_PE26) //  PWM Waveform Output High Channel 7
#define AT91C_PE26_MCI_DB2  (AT91C_PIO_PE26) //  Multimedia Card Slot B Data 2
#define AT91C_PIO_PE27       (1 << 27) // Pin Controlled by PE27
#define AT91C_PE27_NCS7     (AT91C_PIO_PE27) //  SMC Chip Select Line 7
#define AT91C_PE27_MCI_DB3  (AT91C_PIO_PE27) //  Multimedia Card Slot B Data 3
#define AT91C_PIO_PE28       (1 << 28) // Pin Controlled by PE28
#define AT91C_PE28_SPI1_MISO (AT91C_PIO_PE28) //  SPI1 Master In Slave Out
#define AT91C_PIO_PE29       (1 << 29) // Pin Controlled by PE29
#define AT91C_PE29_SPI1_MOSI (AT91C_PIO_PE29) //  SPI1 Master Out Slave In
#define AT91C_PIO_PE3        (1 <<  3) // Pin Controlled by PE3
#define AT91C_PE3_A22_NANDCLE (AT91C_PIO_PE3) //  EBI Address Bus 22 / ???
#define AT91C_PIO_PE30       (1 << 30) // Pin Controlled by PE30
#define AT91C_PE30_SPI1_SPCK (AT91C_PIO_PE30) //  SPI1 Serial Clock
#define AT91C_PIO_PE31       (1 << 31) // Pin Controlled by PE31
#define AT91C_PE31_SPI1_NPCS0 (AT91C_PIO_PE31) //  SPI1 Peripheral Chip Select 0
#define AT91C_PIO_PE4        (1 <<  4) // Pin Controlled by PE4
#define AT91C_PE4_A23      (AT91C_PIO_PE4) //  EBI Address Bus 23
#define AT91C_PIO_PE5        (1 <<  5) // Pin Controlled by PE5
#define AT91C_PE5_NCS4     (AT91C_PIO_PE5) //  SMC Chip Select Line 4
#define AT91C_PIO_PE6        (1 <<  6) // Pin Controlled by PE6
#define AT91C_PE6_NCS5     (AT91C_PIO_PE6) //  SMC Chip Select Line 5
#define AT91C_PIO_PE7        (1 <<  7) // Pin Controlled by PE7
#define AT91C_PIO_PE8        (1 <<  8) // Pin Controlled by PE8
#define AT91C_PIO_PE9        (1 <<  9) // Pin Controlled by PE9
#define AT91C_PE9_TIOA3    (AT91C_PIO_PE9) //  TC Channel 3 I/O Line A
#define AT91C_PIO_PF0        (1 <<  0) // Pin Controlled by PF0
#define AT91C_PF0_SPI1_NPCS1 (AT91C_PIO_PF0) //  SPI1 Peripheral Chip Select 1
#define AT91C_PIO_PF1        (1 <<  1) // Pin Controlled by PF1
#define AT91C_PF1_SPI1_NPCS2 (AT91C_PIO_PF1) //  SPI1 Peripheral Chip Select 2
#define AT91C_PIO_PF2        (1 <<  2) // Pin Controlled by PF2
#define AT91C_PF2_SPI1_NPCS3 (AT91C_PIO_PF2) //  SPI1 Peripheral Chip Select 3
#define AT91C_PIO_PF3        (1 <<  3) // Pin Controlled by PF3
#define AT91C_PF3_PWMH3    (AT91C_PIO_PF3) //  PWM Waveform Output High Channel 3
#define AT91C_PIO_PF4        (1 <<  4) // Pin Controlled by PF4
#define AT91C_PF4_CTS3     (AT91C_PIO_PF4) //  USART3 Clear To Send
#define AT91C_PIO_PF5        (1 <<  5) // Pin Controlled by PF5
#define AT91C_PF5_RTS3     (AT91C_PIO_PF5) //  USART3 Request To Send

// *****************************************************************************
//               PERIPHERAL ID DEFINITIONS FOR AT91SAM3X
// *****************************************************************************
#define AT91C_ID_SUPC   ( 0) // Supply Controller
#define AT91C_ID_RSTC   ( 1) // Reset Controller
#define AT91C_ID_RTC    ( 2) // Real Time Clock
#define AT91C_ID_RTTC   ( 3) // Real Time Timer
#define AT91C_ID_WDTC   ( 4) // Watchdog Timer
#define AT91C_ID_PMC    ( 5) // Power Management Contoller
#define AT91C_ID_EFC0   ( 6) // Enhanced Flash Controller 0
#define AT91C_ID_EFC1   ( 7) // Enhanced Flash Controller 1
#define AT91C_ID_DBGU   ( 8) // Debug Unit
#define AT91C_ID_SMC    ( 9) // Static Memory Controller
#define AT91C_ID_SDRAMC (10) // Synchronous Dynamic RAM Controller
#define AT91C_ID_PIOA   (11) // Parallel I/O Controller A
#define AT91C_ID_PIOB   (12) // Parallel I/O Controller B
#define AT91C_ID_PIOC   (13) // Parallel I/O Controller C
#define AT91C_ID_PIOD   (14) // Parallel I/O Controller D
#define AT91C_ID_PIOE   (15) // Parallel I/O Controller E
#define AT91C_ID_PIOF   (16) // Parallel I/O Controller F
#define AT91C_ID_US0    (17) // USART 0
#define AT91C_ID_US1    (18) // USART 1
#define AT91C_ID_US2    (19) // USART 2
#define AT91C_ID_US3    (20) // USART 3
#define AT91C_ID_MCI    (21) // Multimedia Card Interface
#define AT91C_ID_TWI0   (22) // Two-Wire Interface 0
#define AT91C_ID_TWI1   (23) // Two-Wire Interface 1
#define AT91C_ID_SPI0   (24) // Serial Peripheral Interface 0
#define AT91C_ID_SPI1   (25) // Serial Peripheral Interface 1
#define AT91C_ID_SSC    (26) // Serial Synchronous Controller
#define AT91C_ID_TC0    (27) // Timer Counter 0
#define AT91C_ID_TC1    (28) // Timer Counter 1
#define AT91C_ID_TC2    (29) // Timer Counter 2
#define AT91C_ID_TC3    (30) // Timer Counter 3
#define AT91C_ID_TC4    (31) // Timer Counter 4
#define AT91C_ID_TC5    (32) // Timer Counter 5
#define AT91C_ID_TC6    (33) // Timer Counter 6
#define AT91C_ID_TC7    (34) // Timer Counter 7
#define AT91C_ID_TC8    (35) // Timer Counter 8
#define AT91C_ID_PWMC   (36) // Pulse Width Modulation Controller
#define AT91C_ID_ADCC   (37) // ADC Controller
#define AT91C_ID_DACC   (38) // DAC Controller
#define AT91C_ID_HDMA   (39) // HDMA Controller
#define AT91C_ID_OTGHS  (40) // USB OTG High Speed Controller
#define AT91C_ID_TRNG   (41) // True Random Number Generator
#define AT91C_ID_EMACB  (42) // Ethernet MAC Controller
#define AT91C_ID_CAN0   (43) // CAN Controller 0
#define AT91C_ID_CAN1   (44) // CAN Controller 1
#define AT91C_ALL_INT   (0xFFFFFFFF) // ALL VALID INTERRUPTS

// *****************************************************************************
//               BASE ADDRESS DEFINITIONS FOR AT91SAM3X
// *****************************************************************************
#define AT91C_BASE_SYS       (AT91_CAST(AT91PS_SYS) 	0x400E0000) // (SYS) Base Address
#define AT91C_BASE_EBI       (AT91_CAST(AT91PS_EBI) 	0x400E0000) // (EBI) Base Address
#define AT91C_BASE_HSMC4_CS0 (AT91_CAST(AT91PS_HSMC4_CS) 	0x400E0070) // (HSMC4_CS0) Base Address
#define AT91C_BASE_HSMC4_CS1 (AT91_CAST(AT91PS_HSMC4_CS) 	0x400E0084) // (HSMC4_CS1) Base Address
#define AT91C_BASE_HSMC4_CS2 (AT91_CAST(AT91PS_HSMC4_CS) 	0x400E0098) // (HSMC4_CS2) Base Address
#define AT91C_BASE_HSMC4_CS3 (AT91_CAST(AT91PS_HSMC4_CS) 	0x400E00AC) // (HSMC4_CS3) Base Address
#define AT91C_BASE_HSMC4_CS4 (AT91_CAST(AT91PS_HSMC4_CS) 	0x400E00C0) // (HSMC4_CS4) Base Address
#define AT91C_BASE_HSMC4_CS5 (AT91_CAST(AT91PS_HSMC4_CS) 	0x400E00D4) // (HSMC4_CS5) Base Address
#define AT91C_BASE_HSMC4_CS6 (AT91_CAST(AT91PS_HSMC4_CS) 	0x400E00E8) // (HSMC4_CS6) Base Address
#define AT91C_BASE_HSMC4_NFC (AT91_CAST(AT91PS_HSMC4_CS) 	0x400E00FC) // (HSMC4_NFC) Base Address
#define AT91C_BASE_HSMC4     (AT91_CAST(AT91PS_HSMC4) 	0x400E0000) // (HSMC4) Base Address
#define AT91C_BASE_MATRIX    (AT91_CAST(AT91PS_MATRIX) 	0x400E0400) // (MATRIX) Base Address
#define AT91C_BASE_CCFG      (AT91_CAST(AT91PS_CCFG) 	0x400E0510) // (CCFG) Base Address
#define AT91C_BASE_NVIC      (AT91_CAST(AT91PS_NVIC) 	0xE000E000) // (NVIC) Base Address
#define AT91C_BASE_CM3       (AT91_CAST(AT91PS_CM3) 	0xE000ED00) // (CM3) Base Address
#define AT91C_BASE_CKGR      (AT91_CAST(AT91PS_CKGR) 	0x400E061C) // (CKGR) Base Address
#define AT91C_BASE_SUPC      (AT91_CAST(AT91PS_SUPC) 	0x400E1A10) // (SUPC) Base Address
#define AT91C_BASE_RSTC      (AT91_CAST(AT91PS_RSTC) 	0x400E1A00) // (RSTC) Base Address
#define AT91C_BASE_RTC       (AT91_CAST(AT91PS_RTC) 	0x400E1A60) // (RTC) Base Address
#define AT91C_BASE_RTTC      (AT91_CAST(AT91PS_RTTC) 	0x400E1A30) // (RTTC) Base Address
#define AT91C_BASE_WDTC      (AT91_CAST(AT91PS_WDTC) 	0x400E1A50) // (WDTC) Base Address
#define AT91C_BASE_PMC       (AT91_CAST(AT91PS_PMC) 	0x400E0600) // (PMC) Base Address
#define AT91C_BASE_EFC0      (AT91_CAST(AT91PS_EFC) 	0x400E0A00) // (EFC0) Base Address
#define AT91C_BASE_EFC1      (AT91_CAST(AT91PS_EFC) 	0x400E0C00) // (EFC1) Base Address
#define AT91C_BASE_PDC_DBGU  (AT91_CAST(AT91PS_PDC) 	0x400E0900) // (PDC_DBGU) Base Address
#define AT91C_BASE_DBGU      (AT91_CAST(AT91PS_DBGU) 	0x400E0800) // (DBGU) Base Address
#define AT91C_BASE_SDRAMC    (AT91_CAST(AT91PS_SDRAMC) 	0x400E0200) // (SDRAMC) Base Address
#define AT91C_BASE_PIOA      (AT91_CAST(AT91PS_PIO) 	0x400E0E00) // (PIOA) Base Address
#define AT91C_BASE_PIOB      (AT91_CAST(AT91PS_PIO) 	0x400E1000) // (PIOB) Base Address
#define AT91C_BASE_PIOC      (AT91_CAST(AT91PS_PIO) 	0x400E1200) // (PIOC) Base Address
#define AT91C_BASE_PIOD      (AT91_CAST(AT91PS_PIO) 	0x400E1400) // (PIOD) Base Address
#define AT91C_BASE_PIOE      (AT91_CAST(AT91PS_PIO) 	0x400E1600) // (PIOE) Base Address
#define AT91C_BASE_PIOF      (AT91_CAST(AT91PS_PIO) 	0x400E1800) // (PIOF) Base Address
#define AT91C_BASE_PDC_US0   (AT91_CAST(AT91PS_PDC) 	0x40098100) // (PDC_US0) Base Address
#define AT91C_BASE_US0       (AT91_CAST(AT91PS_USART) 	0x40098000) // (US0) Base Address
#define AT91C_BASE_PDC_US1   (AT91_CAST(AT91PS_PDC) 	0x4009C100) // (PDC_US1) Base Address
#define AT91C_BASE_US1       (AT91_CAST(AT91PS_USART) 	0x4009C000) // (US1) Base Address
#define AT91C_BASE_PDC_US2   (AT91_CAST(AT91PS_PDC) 	0x400A0100) // (PDC_US2) Base Address
#define AT91C_BASE_US2       (AT91_CAST(AT91PS_USART) 	0x400A0000) // (US2) Base Address
#define AT91C_BASE_PDC_US3   (AT91_CAST(AT91PS_PDC) 	0x400A4100) // (PDC_US3) Base Address
#define AT91C_BASE_US3       (AT91_CAST(AT91PS_USART) 	0x400A4000) // (US3) Base Address
#define AT91C_BASE_MCI       (AT91_CAST(AT91PS_MCI) 	0x40000000) // (MCI) Base Address
#define AT91C_BASE_PDC_TWI0  (AT91_CAST(AT91PS_PDC) 	0x4008C100) // (PDC_TWI0) Base Address
#define AT91C_BASE_TWI0      (AT91_CAST(AT91PS_TWI) 	0x4008C000) // (TWI0) Base Address
#define AT91C_BASE_PDC_TWI1  (AT91_CAST(AT91PS_PDC) 	0x40090100) // (PDC_TWI1) Base Address
#define AT91C_BASE_TWI1      (AT91_CAST(AT91PS_TWI) 	0x40090000) // (TWI1) Base Address
#define AT91C_BASE_SPI0      (AT91_CAST(AT91PS_SPI) 	0x40008000) // (SPI0) Base Address
#define AT91C_BASE_SPI1      (AT91_CAST(AT91PS_SPI) 	0x4000C000) // (SPI1) Base Address
#define AT91C_BASE_SSC       (AT91_CAST(AT91PS_SSC) 	0x40004000) // (SSC) Base Address
#define AT91C_BASE_TC0       (AT91_CAST(AT91PS_TC) 	0x40080000) // (TC0) Base Address
#define AT91C_BASE_TCB0      (AT91_CAST(AT91PS_TCB) 	0x40080000) // (TCB0) Base Address
#define AT91C_BASE_TC1       (AT91_CAST(AT91PS_TC) 	0x40080040) // (TC1) Base Address
#define AT91C_BASE_TCB1      (AT91_CAST(AT91PS_TCB) 	0x40080040) // (TCB1) Base Address
#define AT91C_BASE_TC2       (AT91_CAST(AT91PS_TC) 	0x40080080) // (TC2) Base Address
#define AT91C_BASE_TCB2      (AT91_CAST(AT91PS_TCB) 	0x40080080) // (TCB2) Base Address
#define AT91C_BASE_TC3       (AT91_CAST(AT91PS_TC) 	0x40084000) // (TC3) Base Address
#define AT91C_BASE_TCB3      (AT91_CAST(AT91PS_TCB) 	0x40084000) // (TCB3) Base Address
#define AT91C_BASE_TC4       (AT91_CAST(AT91PS_TC) 	0x40084040) // (TC4) Base Address
#define AT91C_BASE_TCB4      (AT91_CAST(AT91PS_TCB) 	0x40084040) // (TCB4) Base Address
#define AT91C_BASE_TC5       (AT91_CAST(AT91PS_TC) 	0x40084080) // (TC5) Base Address
#define AT91C_BASE_TCB5      (AT91_CAST(AT91PS_TCB) 	0x40084080) // (TCB5) Base Address
#define AT91C_BASE_TC6       (AT91_CAST(AT91PS_TC) 	0x40088000) // (TC6) Base Address
#define AT91C_BASE_TCB6      (AT91_CAST(AT91PS_TCB) 	0x40088000) // (TCB6) Base Address
#define AT91C_BASE_TC7       (AT91_CAST(AT91PS_TC) 	0x40088040) // (TC7) Base Address
#define AT91C_BASE_TCB7      (AT91_CAST(AT91PS_TCB) 	0x40088040) // (TCB7) Base Address
#define AT91C_BASE_TC8       (AT91_CAST(AT91PS_TC) 	0x40088080) // (TC8) Base Address
#define AT91C_BASE_TCB8      (AT91_CAST(AT91PS_TCB) 	0x40088080) // (TCB8) Base Address
#define AT91C_BASE_PWMC_CH0  (AT91_CAST(AT91PS_PWMC_CH) 	0x40094200) // (PWMC_CH0) Base Address
#define AT91C_BASE_PWMC_CH1  (AT91_CAST(AT91PS_PWMC_CH) 	0x40094220) // (PWMC_CH1) Base Address
#define AT91C_BASE_PWMC_CH2  (AT91_CAST(AT91PS_PWMC_CH) 	0x40094240) // (PWMC_CH2) Base Address
#define AT91C_BASE_PWMC_CH3  (AT91_CAST(AT91PS_PWMC_CH) 	0x40094260) // (PWMC_CH3) Base Address
#define AT91C_BASE_PWMC_CH4  (AT91_CAST(AT91PS_PWMC_CH) 	0x40094280) // (PWMC_CH4) Base Address
#define AT91C_BASE_PWMC_CH5  (AT91_CAST(AT91PS_PWMC_CH) 	0x400942A0) // (PWMC_CH5) Base Address
#define AT91C_BASE_PWMC_CH6  (AT91_CAST(AT91PS_PWMC_CH) 	0x400942C0) // (PWMC_CH6) Base Address
#define AT91C_BASE_PWMC_CH7  (AT91_CAST(AT91PS_PWMC_CH) 	0x400942E0) // (PWMC_CH7) Base Address
#define AT91C_BASE_PDC_PWMC  (AT91_CAST(AT91PS_PDC) 	0x40094100) // (PDC_PWMC) Base Address
#define AT91C_BASE_PWMC      (AT91_CAST(AT91PS_PWMC) 	0x40094000) // (PWMC) Base Address
#define AT91C_BASE_PDC_ADCC  (AT91_CAST(AT91PS_PDC) 	0x400C0100) // (PDC_ADCC) Base Address
#define AT91C_BASE_ADCC      (AT91_CAST(AT91PS_ADC) 	0x400C0000) // (ADCC) Base Address
#define AT91C_BASE_PDC_DACC  (AT91_CAST(AT91PS_PDC) 	0x400C8100) // (PDC_DACC) Base Address
#define AT91C_BASE_DACC      (AT91_CAST(AT91PS_DAC) 	0x400C8000) // (DACC) Base Address
#define AT91C_BASE_HDMA_CH_0 (AT91_CAST(AT91PS_HDMA_CH) 	0x400C403C) // (HDMA_CH_0) Base Address
#define AT91C_BASE_HDMA_CH_1 (AT91_CAST(AT91PS_HDMA_CH) 	0x400C4064) // (HDMA_CH_1) Base Address
#define AT91C_BASE_HDMA_CH_2 (AT91_CAST(AT91PS_HDMA_CH) 	0x400C408C) // (HDMA_CH_2) Base Address
#define AT91C_BASE_HDMA_CH_3 (AT91_CAST(AT91PS_HDMA_CH) 	0x400C40B4) // (HDMA_CH_3) Base Address
#define AT91C_BASE_HDMA_CH_4 (AT91_CAST(AT91PS_HDMA_CH) 	0x400C40DC) // (HDMA_CH_4) Base Address
#define AT91C_BASE_HDMA_CH_5 (AT91_CAST(AT91PS_HDMA_CH) 	0x400C4104) // (HDMA_CH_5) Base Address
#define AT91C_BASE_HDMA      (AT91_CAST(AT91PS_HDMA) 	0x400C4000) // (HDMA) Base Address
#define AT91C_BASE_OTGHS_DEVDMA_0 (AT91_CAST(AT91PS_OTGHS_DEVDMA) 	0x400AC300) // (OTGHS_DEVDMA_0) Base Address
#define AT91C_BASE_OTGHS_DEVDMA_1 (AT91_CAST(AT91PS_OTGHS_DEVDMA) 	0x400AC310) // (OTGHS_DEVDMA_1) Base Address
#define AT91C_BASE_OTGHS_DEVDMA_2 (AT91_CAST(AT91PS_OTGHS_DEVDMA) 	0x400AC320) // (OTGHS_DEVDMA_2) Base Address
#define AT91C_BASE_OTGHS_DEVDMA_3 (AT91_CAST(AT91PS_OTGHS_DEVDMA) 	0x400AC330) // (OTGHS_DEVDMA_3) Base Address
#define AT91C_BASE_OTGHS_DEVDMA_4 (AT91_CAST(AT91PS_OTGHS_DEVDMA) 	0x400AC340) // (OTGHS_DEVDMA_4) Base Address
#define AT91C_BASE_OTGHS_DEVDMA_5 (AT91_CAST(AT91PS_OTGHS_DEVDMA) 	0x400AC350) // (OTGHS_DEVDMA_5) Base Address
#define AT91C_BASE_OTGHS_DEVDMA_6 (AT91_CAST(AT91PS_OTGHS_DEVDMA) 	0x400AC360) // (OTGHS_DEVDMA_6) Base Address
#define AT91C_BASE_OTGHS_DEVDMA_7 (AT91_CAST(AT91PS_OTGHS_DEVDMA) 	0x400AC370) // (OTGHS_DEVDMA_7) Base Address
#define AT91C_BASE_OTGHS_HSTDMA_0 (AT91_CAST(AT91PS_OTGHS_HSTDMA) 	0x400AC700) // (OTGHS_HSTDMA_0) Base Address
#define AT91C_BASE_OTGHS_HSTDMA_1 (AT91_CAST(AT91PS_OTGHS_HSTDMA) 	0x400AC710) // (OTGHS_HSTDMA_1) Base Address
#define AT91C_BASE_OTGHS_HSTDMA_2 (AT91_CAST(AT91PS_OTGHS_HSTDMA) 	0x400AC720) // (OTGHS_HSTDMA_2) Base Address
#define AT91C_BASE_OTGHSHST_DMA_3 (AT91_CAST(AT91PS_OTGHS_HSTDMA) 	0x400AC730) // (OTGHSHST_DMA_3) Base Address
#define AT91C_BASE_OTGHS_HSTDMA_4 (AT91_CAST(AT91PS_OTGHS_HSTDMA) 	0x400AC740) // (OTGHS_HSTDMA_4) Base Address
#define AT91C_BASE_OTGHS_HSTDMA_5 (AT91_CAST(AT91PS_OTGHS_HSTDMA) 	0x400AC750) // (OTGHS_HSTDMA_5) Base Address
#define AT91C_BASE_OTGHS_HSTDMA_6 (AT91_CAST(AT91PS_OTGHS_HSTDMA) 	0x400AC760) // (OTGHS_HSTDMA_6) Base Address
#define AT91C_BASE_OTGHS_HSTDMA_7 (AT91_CAST(AT91PS_OTGHS_HSTDMA) 	0x400AC770) // (OTGHS_HSTDMA_7) Base Address
#define AT91C_BASE_OTGHS_EPTFIFO (AT91_CAST(AT91PS_OTGHS_EPTFIFO) 	0x20180000) // (OTGHS_EPTFIFO) Base Address
#define AT91C_BASE_OTGHS     (AT91_CAST(AT91PS_OTGHS) 	0x400AC000) // (OTGHS) Base Address
#define AT91C_BASE_TRNG      (AT91_CAST(AT91PS_TRNG) 	0x400BC000) // (TRNG) Base Address
#define AT91C_BASE_EMACB     (AT91_CAST(AT91PS_EMAC) 	0x400B0000) // (EMACB) Base Address
#define AT91C_BASE_CAN0_MB0  (AT91_CAST(AT91PS_CAN_MB) 	0x400B4200) // (CAN0_MB0) Base Address
#define AT91C_BASE_CAN0_MB1  (AT91_CAST(AT91PS_CAN_MB) 	0x400B4220) // (CAN0_MB1) Base Address
#define AT91C_BASE_CAN0_MB2  (AT91_CAST(AT91PS_CAN_MB) 	0x400B4240) // (CAN0_MB2) Base Address
#define AT91C_BASE_CAN0_MB3  (AT91_CAST(AT91PS_CAN_MB) 	0x400B4260) // (CAN0_MB3) Base Address
#define AT91C_BASE_CAN0_MB4  (AT91_CAST(AT91PS_CAN_MB) 	0x400B4280) // (CAN0_MB4) Base Address
#define AT91C_BASE_CAN0_MB5  (AT91_CAST(AT91PS_CAN_MB) 	0x400B42A0) // (CAN0_MB5) Base Address
#define AT91C_BASE_CAN0_MB6  (AT91_CAST(AT91PS_CAN_MB) 	0x400B42C0) // (CAN0_MB6) Base Address
#define AT91C_BASE_CAN0_MB7  (AT91_CAST(AT91PS_CAN_MB) 	0x400B42E0) // (CAN0_MB7) Base Address
#define AT91C_BASE_CAN0      (AT91_CAST(AT91PS_CAN) 	0x400B4000) // (CAN0) Base Address
#define AT91C_BASE_CAN1_MB0  (AT91_CAST(AT91PS_CAN_MB) 	0x400B8200) // (CAN1_MB0) Base Address
#define AT91C_BASE_CAN1_MB1  (AT91_CAST(AT91PS_CAN_MB) 	0x400B8220) // (CAN1_MB1) Base Address
#define AT91C_BASE_CAN1_MB2  (AT91_CAST(AT91PS_CAN_MB) 	0x400B8240) // (CAN1_MB2) Base Address
#define AT91C_BASE_CAN1_MB3  (AT91_CAST(AT91PS_CAN_MB) 	0x400B8260) // (CAN1_MB3) Base Address
#define AT91C_BASE_CAN1_MB4  (AT91_CAST(AT91PS_CAN_MB) 	0x400B8280) // (CAN1_MB4) Base Address
#define AT91C_BASE_CAN1_MB5  (AT91_CAST(AT91PS_CAN_MB) 	0x400B82A0) // (CAN1_MB5) Base Address
#define AT91C_BASE_CAN1_MB6  (AT91_CAST(AT91PS_CAN_MB) 	0x400B82C0) // (CAN1_MB6) Base Address
#define AT91C_BASE_CAN1_MB7  (AT91_CAST(AT91PS_CAN_MB) 	0x400B82E0) // (CAN1_MB7) Base Address
#define AT91C_BASE_CAN1      (AT91_CAST(AT91PS_CAN) 	0x400B8000) // (CAN1) Base Address

// *****************************************************************************
//               MEMORY MAPPING DEFINITIONS FOR AT91SAM3X
// *****************************************************************************
// IFLASH0
#define AT91C_IFLASH0	 (0x00080000) // Maximum IFLASH Area : 256Kbyte base address
#define AT91C_IFLASH0_SIZE	 (0x00040000) // Maximum IFLASH Area : 256Kbyte size in byte (256 Kbytes)
#define AT91C_IFLASH0_PAGE_SIZE	 (256) // Maximum IFLASH Area : 256Kbyte Page Size: 256 bytes
#define AT91C_IFLASH0_LOCK_REGION_SIZE	 (8192) // Maximum IFLASH Area : 256Kbyte Lock Region Size: 8 Kbytes
#define AT91C_IFLASH0_NB_OF_PAGES	 (1024) // Maximum IFLASH Area : 256Kbyte Number of Pages: 1024 bytes
#define AT91C_IFLASH0_NB_OF_LOCK_BITS	 (32) // Maximum IFLASH Area : 256Kbyte Number of Lock Bits: 32 bytes
// IFLASH1
#define AT91C_IFLASH1	 (0x01000000) // Maximum IFLASH Area : 256Kbyte base address
#define AT91C_IFLASH1_SIZE	 (0x00040000) // Maximum IFLASH Area : 256Kbyte size in byte (256 Kbytes)
#define AT91C_IFLASH1_PAGE_SIZE	 (256) // Maximum IFLASH Area : 256Kbyte Page Size: 256 bytes
#define AT91C_IFLASH1_LOCK_REGION_SIZE	 (8192) // Maximum IFLASH Area : 256Kbyte Lock Region Size: 8 Kbytes
#define AT91C_IFLASH1_NB_OF_PAGES	 (1024) // Maximum IFLASH Area : 256Kbyte Number of Pages: 1024 bytes
#define AT91C_IFLASH1_NB_OF_LOCK_BITS	 (32) // Maximum IFLASH Area : 256Kbyte Number of Lock Bits: 32 bytes
// IROM
#define AT91C_IROM 	 (0x00100000) // Internal ROM base address
#define AT91C_IROM_SIZE	 (0x00020000) // Internal ROM size in byte (128 Kbytes)
// IRAM0
#define AT91C_IRAM0	 (0x20000000) // Maximum Internal SRAM base address
#define AT91C_IRAM0_SIZE	 (0x00008000) // Maximum Internal SRAM size in byte (32 Kbytes)
// IRAM1
#define AT91C_IRAM1	 (0x20080000) // Maximum Internal SRAM base address
#define AT91C_IRAM1_SIZE	 (0x00008000) // Maximum Internal SRAM size in byte (32 Kbytes)
// NFC
#define AT91C_NFC  	 (0x20100000) //  base address
#define AT91C_NFC_SIZE	 (0x00008000) //  size in byte (32 Kbytes)
// OTG
#define AT91C_OTG  	 (0x20180000) //  base address
#define AT91C_OTG_SIZE	 (0x00008000) //  size in byte (32 Kbytes)
// EBI_CS0
#define AT91C_EBI_CS0	 (0x60000000) // EBI Chip Select 0 base address
#define AT91C_EBI_CS0_SIZE	 (0x10000000) // EBI Chip Select 0 size in byte (262144 Kbytes)
// EBI_CS1
#define AT91C_EBI_CS1	 (0x61000000) // EBI Chip Select 1 base address
#define AT91C_EBI_CS1_SIZE	 (0x10000000) // EBI Chip Select 1 size in byte (262144 Kbytes)
// EBI_CS2
#define AT91C_EBI_CS2	 (0x62000000) // EBI Chip Select 2 base address
#define AT91C_EBI_CS2_SIZE	 (0x10000000) // EBI Chip Select 2 size in byte (262144 Kbytes)
// EBI_CS3
#define AT91C_EBI_CS3	 (0x63000000) // EBI Chip Select 3 base address
#define AT91C_EBI_CS3_SIZE	 (0x10000000) // EBI Chip Select 3 size in byte (262144 Kbytes)
// EBI_SM
#define AT91C_EBI_SM	 (0x63000000) // NANDFLASH on EBI Chip Select 3 base address
#define AT91C_EBI_SM_SIZE	 (0x10000000) // NANDFLASH on EBI Chip Select 3 size in byte (262144 Kbytes)
// EBI_CS4
#define AT91C_EBI_CS4	 (0x64000000) // EBI Chip Select 4 base address
#define AT91C_EBI_CS4_SIZE	 (0x10000000) // EBI Chip Select 4 size in byte (262144 Kbytes)
// EBI_CF0
#define AT91C_EBI_CF0	 (0x64000000) // CompactFlash 0 on EBI Chip Select 4 base address
#define AT91C_EBI_CF0_SIZE	 (0x10000000) // CompactFlash 0 on EBI Chip Select 4 size in byte (262144 Kbytes)
// EBI_CS5
#define AT91C_EBI_CS5	 (0x65000000) // EBI Chip Select 5 base address
#define AT91C_EBI_CS5_SIZE	 (0x10000000) // EBI Chip Select 5 size in byte (262144 Kbytes)
// EBI_CF1
#define AT91C_EBI_CF1	 (0x65000000) // CompactFlash 1 on EBIChip Select 5 base address
#define AT91C_EBI_CF1_SIZE	 (0x10000000) // CompactFlash 1 on EBIChip Select 5 size in byte (262144 Kbytes)
// EBI_CS6
#define AT91C_EBI_CS6	 (0x66000000) // EBI Chip Select 6 base address
#define AT91C_EBI_CS6_SIZE	 (0x10000000) // EBI Chip Select 6 size in byte (262144 Kbytes)
// EBI_SDRAM
#define AT91C_EBI_SDRAM	 (0x70000000) // SDRAM on EBI base address
#define AT91C_EBI_SDRAM_SIZE	 (0x10000000) // SDRAM on EBI size in byte (262144 Kbytes)

#endif
