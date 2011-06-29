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
// File Name           : AT91SAM3s4.h
// Object              : AT91SAM3s4 definitions
// Generated           : AT91 SW Application Group  07/29/2009 (17:36:55)
// 
// CVS Reference       : /AT91SAM3s4.pl/1.24/Wed Jul 29 14:55:09 2009//
// CVS Reference       : /ACC_SAM3s4.pl/1.3/Mon Mar  2 10:12:03 2009//
// CVS Reference       : /ADC_SAM3XE.pl/1.5/Tue Jan 27 13:39:00 2009//
// CVS Reference       : /CORTEX_M3_MPU.pl/1.3/Fri Oct 17 13:27:48 2008//
// CVS Reference       : /CORTEX_M3.pl/1.1/Mon Sep 15 15:22:06 2008//
// CVS Reference       : /CORTEX_M3_NVIC.pl/1.8/Fri Jun 19 12:00:55 2009//
// CVS Reference       : /DAC_SAM3s4.pl/1.2/Thu Apr 23 09:43:07 2009//
// CVS Reference       : /DBGU_SAM3UE256.pl/1.3/Tue May  5 11:28:09 2009//
// CVS Reference       : /EFC2_SAM3UE256.pl/1.3/Mon Mar  2 10:12:06 2009//
// CVS Reference       : /HCBDMA_sam3s256.pl/1.1/Fri Mar 13 09:02:46 2009//
// CVS Reference       : /HECC_6143A.pl/1.1/Wed Feb  9 17:16:57 2005//
// CVS Reference       : /HMATRIX2_SAM3UE256.pl/1.5/Fri Jun 26 07:25:14 2009//
// CVS Reference       : /SFR_SAM3s4.pl/1.3/Wed Jan 14 15:06:20 2009//
// CVS Reference       : /MCI_6101F.pl/1.3/Fri Jan 23 09:15:32 2009//
// CVS Reference       : /PDC_6074C.pl/1.2/Thu Feb  3 09:02:11 2005//
// CVS Reference       : /PIO3_SAM3s4.pl/1.1/Tue Feb 17 08:07:35 2009//
// CVS Reference       : /PITC_6079A.pl/1.2/Thu Nov  4 13:56:22 2004//
// CVS Reference       : /PMC_SAM3s4.pl/1.8/Thu Apr 23 09:43:12 2009//
// CVS Reference       : /PWM_SAM3s4.pl/1.1/Wed Feb 25 13:18:50 2009//
// CVS Reference       : /RSTC_6098A.pl/1.4/Fri Oct 17 13:27:55 2008//
// CVS Reference       : /RTC_1245D.pl/1.3/Fri Sep 17 14:01:31 2004//
// CVS Reference       : /RTTC_6081A.pl/1.2/Thu Nov  4 13:57:22 2004//
// CVS Reference       : /HSDRAMC1_6100A.pl/1.2/Mon Aug  9 10:52:25 2004//
// CVS Reference       : /SHDWC_6122A.pl/1.3/Wed Oct  6 14:16:58 2004//
// CVS Reference       : /HSMC3_SAM3s4.pl/1.1/Fri Mar 13 09:20:27 2009//
// CVS Reference       : /SPI2.pl/1.6/Mon Jul  6 07:40:56 2009//
// CVS Reference       : /SSC_SAM3s4.pl/1.1/Thu Apr  9 10:54:32 2009//
// CVS Reference       : /SUPC_SAM3UE256.pl/1.2/Tue May  5 11:29:05 2009//
// CVS Reference       : /SYS_SAM3s4.pl/1.4/Mon Mar  9 10:43:41 2009//
// CVS Reference       : /TC_6082A.pl/1.8/Fri Oct 17 13:27:58 2008//
// CVS Reference       : /TWI_6061B.pl/1.3/Fri Oct 17 13:27:59 2008//
// CVS Reference       : /UDP_sam3s256.pl/1.1/Fri Mar 13 09:03:58 2009//
// CVS Reference       : /US_6089J.pl/1.4/Tue Jul  7 12:01:26 2009//
// CVS Reference       : /WDTC_6080A.pl/1.3/Thu Nov  4 13:58:52 2004//
//  ----------------------------------------------------------------------------

#ifndef AT91SAM3s4_H
#define AT91SAM3s4_H

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
	AT91_REG	 HSMC3_SETUP0; 	//  Setup Register for CS 0
	AT91_REG	 HSMC3_PULSE0; 	//  Pulse Register for CS 0
	AT91_REG	 HSMC3_CYCLE0; 	//  Cycle Register for CS 0
	AT91_REG	 HSMC3_CTRL0; 	//  Control Register for CS 0
	AT91_REG	 HSMC3_SETUP1; 	//  Setup Register for CS 1
	AT91_REG	 HSMC3_PULSE1; 	//  Pulse Register for CS 1
	AT91_REG	 HSMC3_CYCLE1; 	//  Cycle Register for CS 1
	AT91_REG	 HSMC3_CTRL1; 	//  Control Register for CS 1
	AT91_REG	 HSMC3_SETUP2; 	//  Setup Register for CS 2
	AT91_REG	 HSMC3_PULSE2; 	//  Pulse Register for CS 2
	AT91_REG	 HSMC3_CYCLE2; 	//  Cycle Register for CS 2
	AT91_REG	 HSMC3_CTRL2; 	//  Control Register for CS 2
	AT91_REG	 HSMC3_SETUP3; 	//  Setup Register for CS 3
	AT91_REG	 HSMC3_PULSE3; 	//  Pulse Register for CS 3
	AT91_REG	 HSMC3_CYCLE3; 	//  Cycle Register for CS 3
	AT91_REG	 HSMC3_CTRL3; 	//  Control Register for CS 3
	AT91_REG	 HSMC3_SETUP4; 	//  Setup Register for CS 4
	AT91_REG	 HSMC3_PULSE4; 	//  Pulse Register for CS 4
	AT91_REG	 HSMC3_CYCLE4; 	//  Cycle Register for CS 4
	AT91_REG	 HSMC3_CTRL4; 	//  Control Register for CS 4
	AT91_REG	 HSMC3_SETUP5; 	//  Setup Register for CS 5
	AT91_REG	 HSMC3_PULSE5; 	//  Pulse Register for CS 5
	AT91_REG	 HSMC3_CYCLE5; 	//  Cycle Register for CS 5
	AT91_REG	 HSMC3_CTRL5; 	//  Control Register for CS 5
	AT91_REG	 HSMC3_SETUP6; 	//  Setup Register for CS 6
	AT91_REG	 HSMC3_PULSE6; 	//  Pulse Register for CS 6
	AT91_REG	 HSMC3_CYCLE6; 	//  Cycle Register for CS 6
	AT91_REG	 HSMC3_CTRL6; 	//  Control Register for CS 6
	AT91_REG	 HSMC3_SETUP7; 	//  Setup Register for CS 7
	AT91_REG	 HSMC3_PULSE7; 	//  Pulse Register for CS 7
	AT91_REG	 HSMC3_CYCLE7; 	//  Cycle Register for CS 7
	AT91_REG	 HSMC3_CTRL7; 	//  Control Register for CS 7
	AT91_REG	 Reserved0[16]; 	// 
	AT91_REG	 HSMC3_DELAY1; 	// SMC Delay Control Register
	AT91_REG	 HSMC3_DELAY2; 	// SMC Delay Control Register
	AT91_REG	 HSMC3_DELAY3; 	// SMC Delay Control Register
	AT91_REG	 HSMC3_DELAY4; 	// SMC Delay Control Register
	AT91_REG	 HSMC3_DELAY5; 	// SMC Delay Control Register
	AT91_REG	 HSMC3_DELAY6; 	// SMC Delay Control Register
	AT91_REG	 HSMC3_DELAY7; 	// SMC Delay Control Register
	AT91_REG	 HSMC3_DELAY8; 	// SMC Delay Control Register
	AT91_REG	 Reserved1[3]; 	// 
	AT91_REG	 HSMC3_ADDRSIZE; 	// HSMC3 ADDRSIZE REGISTER 
	AT91_REG	 HSMC3_IPNAME1; 	// HSMC3 IPNAME1 REGISTER 
	AT91_REG	 HSMC3_IPNAME2; 	// HSMC3 IPNAME2 REGISTER 
	AT91_REG	 HSMC3_FEATURES; 	// HSMC3 FEATURES REGISTER 
	AT91_REG	 HSMC3_VER; 	// HSMC3 VERSION REGISTER
	AT91_REG	 Reserved2[64]; 	// 
	AT91_REG	 HMATRIX_MCFG0; 	//  Master Configuration Register 0 : ARM I and D
	AT91_REG	 HMATRIX_MCFG1; 	//  Master Configuration Register 1 : ARM S
	AT91_REG	 HMATRIX_MCFG2; 	//  Master Configuration Register 2
	AT91_REG	 HMATRIX_MCFG3; 	//  Master Configuration Register 3
	AT91_REG	 HMATRIX_MCFG4; 	//  Master Configuration Register 4
	AT91_REG	 HMATRIX_MCFG5; 	//  Master Configuration Register 5
	AT91_REG	 HMATRIX_MCFG6; 	//  Master Configuration Register 6
	AT91_REG	 HMATRIX_MCFG7; 	//  Master Configuration Register 7
	AT91_REG	 Reserved3[8]; 	// 
	AT91_REG	 HMATRIX_SCFG0; 	//  Slave Configuration Register 0
	AT91_REG	 HMATRIX_SCFG1; 	//  Slave Configuration Register 1
	AT91_REG	 HMATRIX_SCFG2; 	//  Slave Configuration Register 2
	AT91_REG	 HMATRIX_SCFG3; 	//  Slave Configuration Register 3
	AT91_REG	 HMATRIX_SCFG4; 	//  Slave Configuration Register 4
	AT91_REG	 HMATRIX_SCFG5; 	//  Slave Configuration Register 5
	AT91_REG	 HMATRIX_SCFG6; 	//  Slave Configuration Register 6
	AT91_REG	 HMATRIX_SCFG7; 	//  Slave Configuration Register 5
	AT91_REG	 HMATRIX_SCFG8; 	//  Slave Configuration Register 8
	AT91_REG	 HMATRIX_SCFG9; 	//  Slave Configuration Register 9
	AT91_REG	 Reserved4[42]; 	// 
	AT91_REG	 HMATRIX_SFR0 ; 	//  Special Function Register 0
	AT91_REG	 HMATRIX_SFR1 ; 	//  Special Function Register 1
	AT91_REG	 HMATRIX_SFR2 ; 	//  Special Function Register 2
	AT91_REG	 HMATRIX_SFR3 ; 	//  Special Function Register 3
	AT91_REG	 HMATRIX_SFR4 ; 	//  Special Function Register 4
	AT91_REG	 HMATRIX_SFR5 ; 	//  Special Function Register 5
	AT91_REG	 HMATRIX_SFR6 ; 	//  Special Function Register 6
	AT91_REG	 HMATRIX_SFR7 ; 	//  Special Function Register 7
	AT91_REG	 HMATRIX_SFR8 ; 	//  Special Function Register 8
	AT91_REG	 HMATRIX_SFR9 ; 	//  Special Function Register 9
	AT91_REG	 HMATRIX_SFR10; 	//  Special Function Register 10
	AT91_REG	 HMATRIX_SFR11; 	//  Special Function Register 11
	AT91_REG	 HMATRIX_SFR12; 	//  Special Function Register 12
	AT91_REG	 HMATRIX_SFR13; 	//  Special Function Register 13
	AT91_REG	 HMATRIX_SFR14; 	//  Special Function Register 14
	AT91_REG	 HMATRIX_SFR15; 	//  Special Function Register 15
	AT91_REG	 Reserved5[39]; 	// 
	AT91_REG	 HMATRIX_ADDRSIZE; 	// HMATRIX2 ADDRSIZE REGISTER 
	AT91_REG	 HMATRIX_IPNAME1; 	// HMATRIX2 IPNAME1 REGISTER 
	AT91_REG	 HMATRIX_IPNAME2; 	// HMATRIX2 IPNAME2 REGISTER 
	AT91_REG	 HMATRIX_FEATURES; 	// HMATRIX2 FEATURES REGISTER 
	AT91_REG	 HMATRIX_VER; 	// HMATRIX2 VERSION REGISTER 
	AT91_REG	 PMC_SCER; 	// System Clock Enable Register
	AT91_REG	 PMC_SCDR; 	// System Clock Disable Register
	AT91_REG	 PMC_SCSR; 	// System Clock Status Register
	AT91_REG	 Reserved6[1]; 	// 
	AT91_REG	 PMC_PCER; 	// Peripheral Clock Enable Register 0:31 PERI_ID
	AT91_REG	 PMC_PCDR; 	// Peripheral Clock Disable Register 0:31 PERI_ID
	AT91_REG	 PMC_PCSR; 	// Peripheral Clock Status Register 0:31 PERI_ID
	AT91_REG	 PMC_UCKR; 	// UTMI Clock Configuration Register
	AT91_REG	 PMC_MOR; 	// Main Oscillator Register
	AT91_REG	 PMC_MCFR; 	// Main Clock  Frequency Register
	AT91_REG	 PMC_PLLAR; 	// PLL Register
	AT91_REG	 PMC_PLLBR; 	// PLL B Register
	AT91_REG	 PMC_MCKR; 	// Master Clock Register
	AT91_REG	 Reserved7[1]; 	// 
	AT91_REG	 PMC_UDPR; 	// USB DEV Clock Configuration Register
	AT91_REG	 Reserved8[1]; 	// 
	AT91_REG	 PMC_PCKR[8]; 	// Programmable Clock Register
	AT91_REG	 PMC_IER; 	// Interrupt Enable Register
	AT91_REG	 PMC_IDR; 	// Interrupt Disable Register
	AT91_REG	 PMC_SR; 	// Status Register
	AT91_REG	 PMC_IMR; 	// Interrupt Mask Register
	AT91_REG	 PMC_FSMR; 	// Fast Startup Mode Register
	AT91_REG	 PMC_FSPR; 	// Fast Startup Polarity Register
	AT91_REG	 PMC_FOCR; 	// Fault Output Clear Register
	AT91_REG	 Reserved9[28]; 	// 
	AT91_REG	 PMC_ADDRSIZE; 	// PMC ADDRSIZE REGISTER 
	AT91_REG	 PMC_IPNAME1; 	// PMC IPNAME1 REGISTER 
	AT91_REG	 PMC_IPNAME2; 	// PMC IPNAME2 REGISTER 
	AT91_REG	 PMC_FEATURES; 	// PMC FEATURES REGISTER 
	AT91_REG	 PMC_VER; 	// APMC VERSION REGISTER
	AT91_REG	 PMC_PCER1; 	// Peripheral Clock Enable Register 32:63 PERI_ID
	AT91_REG	 PMC_PCDR1; 	// Peripheral Clock Disable Register 32:63 PERI_ID
	AT91_REG	 PMC_PCSR1; 	// Peripheral Clock Status Register 32:63 PERI_ID
	AT91_REG	 PMC_PCR; 	// Peripheral Control Register
	AT91_REG	 Reserved10[60]; 	// 
	AT91_REG	 DBGU0_CR; 	// Control Register
	AT91_REG	 DBGU0_MR; 	// Mode Register
	AT91_REG	 DBGU0_IER; 	// Interrupt Enable Register
	AT91_REG	 DBGU0_IDR; 	// Interrupt Disable Register
	AT91_REG	 DBGU0_IMR; 	// Interrupt Mask Register
	AT91_REG	 DBGU0_CSR; 	// Channel Status Register
	AT91_REG	 DBGU0_RHR; 	// Receiver Holding Register
	AT91_REG	 DBGU0_THR; 	// Transmitter Holding Register
	AT91_REG	 DBGU0_BRGR; 	// Baud Rate Generator Register
	AT91_REG	 Reserved11[9]; 	// 
	AT91_REG	 DBGU0_FNTR; 	// Force NTRST Register
	AT91_REG	 Reserved12[40]; 	// 
	AT91_REG	 DBGU0_ADDRSIZE; 	// DBGU ADDRSIZE REGISTER 
	AT91_REG	 DBGU0_IPNAME1; 	// DBGU IPNAME1 REGISTER 
	AT91_REG	 DBGU0_IPNAME2; 	// DBGU IPNAME2 REGISTER 
	AT91_REG	 DBGU0_FEATURES; 	// DBGU FEATURES REGISTER 
	AT91_REG	 DBGU0_VER; 	// DBGU VERSION REGISTER 
	AT91_REG	 DBGU0_RPR; 	// Receive Pointer Register
	AT91_REG	 DBGU0_RCR; 	// Receive Counter Register
	AT91_REG	 DBGU0_TPR; 	// Transmit Pointer Register
	AT91_REG	 DBGU0_TCR; 	// Transmit Counter Register
	AT91_REG	 DBGU0_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 DBGU0_RNCR; 	// Receive Next Counter Register
	AT91_REG	 DBGU0_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 DBGU0_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 DBGU0_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 DBGU0_PTSR; 	// PDC Transfer Status Register
	AT91_REG	 Reserved13[6]; 	// 
	AT91_REG	 DBGU0_CIDR; 	// Chip ID Register
	AT91_REG	 DBGU0_EXID; 	// Chip ID Extension Register
	AT91_REG	 Reserved14[46]; 	// 
	AT91_REG	 DBGU1_CR; 	// Control Register
	AT91_REG	 DBGU1_MR; 	// Mode Register
	AT91_REG	 DBGU1_IER; 	// Interrupt Enable Register
	AT91_REG	 DBGU1_IDR; 	// Interrupt Disable Register
	AT91_REG	 DBGU1_IMR; 	// Interrupt Mask Register
	AT91_REG	 DBGU1_CSR; 	// Channel Status Register
	AT91_REG	 DBGU1_RHR; 	// Receiver Holding Register
	AT91_REG	 DBGU1_THR; 	// Transmitter Holding Register
	AT91_REG	 DBGU1_BRGR; 	// Baud Rate Generator Register
	AT91_REG	 Reserved15[9]; 	// 
	AT91_REG	 DBGU1_FNTR; 	// Force NTRST Register
	AT91_REG	 Reserved16[40]; 	// 
	AT91_REG	 DBGU1_ADDRSIZE; 	// DBGU ADDRSIZE REGISTER 
	AT91_REG	 DBGU1_IPNAME1; 	// DBGU IPNAME1 REGISTER 
	AT91_REG	 DBGU1_IPNAME2; 	// DBGU IPNAME2 REGISTER 
	AT91_REG	 DBGU1_FEATURES; 	// DBGU FEATURES REGISTER 
	AT91_REG	 DBGU1_VER; 	// DBGU VERSION REGISTER 
	AT91_REG	 DBGU1_RPR; 	// Receive Pointer Register
	AT91_REG	 DBGU1_RCR; 	// Receive Counter Register
	AT91_REG	 DBGU1_TPR; 	// Transmit Pointer Register
	AT91_REG	 DBGU1_TCR; 	// Transmit Counter Register
	AT91_REG	 DBGU1_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 DBGU1_RNCR; 	// Receive Next Counter Register
	AT91_REG	 DBGU1_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 DBGU1_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 DBGU1_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 DBGU1_PTSR; 	// PDC Transfer Status Register
	AT91_REG	 Reserved17[6]; 	// 
	AT91_REG	 DBGU1_CIDR; 	// Chip ID Register
	AT91_REG	 DBGU1_EXID; 	// Chip ID Extension Register
	AT91_REG	 Reserved18[46]; 	// 
	AT91_REG	 EFC0_FMR; 	// EFC Flash Mode Register
	AT91_REG	 EFC0_FCR; 	// EFC Flash Command Register
	AT91_REG	 EFC0_FSR; 	// EFC Flash Status Register
	AT91_REG	 EFC0_FRR; 	// EFC Flash Result Register
	AT91_REG	 Reserved19[1]; 	// 
	AT91_REG	 EFC0_FVR; 	// EFC Flash Version Register
	AT91_REG	 Reserved20[250]; 	// 
	AT91_REG	 PIOA_PER; 	// PIO Enable Register
	AT91_REG	 PIOA_PDR; 	// PIO Disable Register
	AT91_REG	 PIOA_PSR; 	// PIO Status Register
	AT91_REG	 Reserved21[1]; 	// 
	AT91_REG	 PIOA_OER; 	// Output Enable Register
	AT91_REG	 PIOA_ODR; 	// Output Disable Registerr
	AT91_REG	 PIOA_OSR; 	// Output Status Register
	AT91_REG	 Reserved22[1]; 	// 
	AT91_REG	 PIOA_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIOA_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIOA_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved23[1]; 	// 
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
	AT91_REG	 Reserved24[1]; 	// 
	AT91_REG	 PIOA_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIOA_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIOA_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved25[1]; 	// 
	AT91_REG	 PIOA_SP1; 	// Select B Register
	AT91_REG	 PIOA_SP2; 	// Select B Register
	AT91_REG	 PIOA_ABSR; 	// AB Select Status Register
	AT91_REG	 Reserved26[5]; 	// 
	AT91_REG	 PIOA_PPDDR; 	// Pull-down Disable Register
	AT91_REG	 PIOA_PPDER; 	// Pull-down Enable Register
	AT91_REG	 PIOA_PPDSR; 	// Pull-down Status Register
	AT91_REG	 Reserved27[1]; 	// 
	AT91_REG	 PIOA_OWER; 	// Output Write Enable Register
	AT91_REG	 PIOA_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIOA_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved28[16]; 	// 
	AT91_REG	 PIOA_ADDRSIZE; 	// PIO ADDRSIZE REGISTER 
	AT91_REG	 PIOA_IPNAME1; 	// PIO IPNAME1 REGISTER 
	AT91_REG	 PIOA_IPNAME2; 	// PIO IPNAME2 REGISTER 
	AT91_REG	 PIOA_FEATURES; 	// PIO FEATURES REGISTER 
	AT91_REG	 PIOA_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 PIOA_SLEW1; 	// PIO SLEWRATE1 REGISTER 
	AT91_REG	 PIOA_SLEW2; 	// PIO SLEWRATE2 REGISTER 
	AT91_REG	 Reserved29[18]; 	// 
	AT91_REG	 PIOA_SENMR; 	// Sensor Mode Register
	AT91_REG	 PIOA_SENIER; 	// Sensor Interrupt Enable Register
	AT91_REG	 PIOA_SENIDR; 	// Sensor Interrupt Disable Register
	AT91_REG	 PIOA_SENIMR; 	// Sensor Interrupt Mask Register
	AT91_REG	 PIOA_SENISR; 	// Sensor Interrupt Status Register
	AT91_REG	 PIOA_SENDATA; 	// Sensor Data Register
	AT91_REG	 PIOA_RPR; 	// Receive Pointer Register
	AT91_REG	 PIOA_RCR; 	// Receive Counter Register
	AT91_REG	 PIOA_TPR; 	// Transmit Pointer Register
	AT91_REG	 PIOA_TCR; 	// Transmit Counter Register
	AT91_REG	 PIOA_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 PIOA_RNCR; 	// Receive Next Counter Register
	AT91_REG	 PIOA_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 PIOA_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 PIOA_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 PIOA_PTSR; 	// PDC Transfer Status Register
	AT91_REG	 Reserved30[28]; 	// 
	AT91_REG	 PIOB_PER; 	// PIO Enable Register
	AT91_REG	 PIOB_PDR; 	// PIO Disable Register
	AT91_REG	 PIOB_PSR; 	// PIO Status Register
	AT91_REG	 Reserved31[1]; 	// 
	AT91_REG	 PIOB_OER; 	// Output Enable Register
	AT91_REG	 PIOB_ODR; 	// Output Disable Registerr
	AT91_REG	 PIOB_OSR; 	// Output Status Register
	AT91_REG	 Reserved32[1]; 	// 
	AT91_REG	 PIOB_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIOB_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIOB_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved33[1]; 	// 
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
	AT91_REG	 Reserved34[1]; 	// 
	AT91_REG	 PIOB_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIOB_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIOB_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved35[1]; 	// 
	AT91_REG	 PIOB_SP1; 	// Select B Register
	AT91_REG	 PIOB_SP2; 	// Select B Register
	AT91_REG	 PIOB_ABSR; 	// AB Select Status Register
	AT91_REG	 Reserved36[5]; 	// 
	AT91_REG	 PIOB_PPDDR; 	// Pull-down Disable Register
	AT91_REG	 PIOB_PPDER; 	// Pull-down Enable Register
	AT91_REG	 PIOB_PPDSR; 	// Pull-down Status Register
	AT91_REG	 Reserved37[1]; 	// 
	AT91_REG	 PIOB_OWER; 	// Output Write Enable Register
	AT91_REG	 PIOB_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIOB_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved38[16]; 	// 
	AT91_REG	 PIOB_ADDRSIZE; 	// PIO ADDRSIZE REGISTER 
	AT91_REG	 PIOB_IPNAME1; 	// PIO IPNAME1 REGISTER 
	AT91_REG	 PIOB_IPNAME2; 	// PIO IPNAME2 REGISTER 
	AT91_REG	 PIOB_FEATURES; 	// PIO FEATURES REGISTER 
	AT91_REG	 PIOB_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 PIOB_SLEW1; 	// PIO SLEWRATE1 REGISTER 
	AT91_REG	 PIOB_SLEW2; 	// PIO SLEWRATE2 REGISTER 
	AT91_REG	 Reserved39[18]; 	// 
	AT91_REG	 PIOB_SENMR; 	// Sensor Mode Register
	AT91_REG	 PIOB_SENIER; 	// Sensor Interrupt Enable Register
	AT91_REG	 PIOB_SENIDR; 	// Sensor Interrupt Disable Register
	AT91_REG	 PIOB_SENIMR; 	// Sensor Interrupt Mask Register
	AT91_REG	 PIOB_SENISR; 	// Sensor Interrupt Status Register
	AT91_REG	 PIOB_SENDATA; 	// Sensor Data Register
	AT91_REG	 PIOB_RPR; 	// Receive Pointer Register
	AT91_REG	 PIOB_RCR; 	// Receive Counter Register
	AT91_REG	 PIOB_TPR; 	// Transmit Pointer Register
	AT91_REG	 PIOB_TCR; 	// Transmit Counter Register
	AT91_REG	 PIOB_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 PIOB_RNCR; 	// Receive Next Counter Register
	AT91_REG	 PIOB_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 PIOB_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 PIOB_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 PIOB_PTSR; 	// PDC Transfer Status Register
	AT91_REG	 Reserved40[28]; 	// 
	AT91_REG	 PIOC_PER; 	// PIO Enable Register
	AT91_REG	 PIOC_PDR; 	// PIO Disable Register
	AT91_REG	 PIOC_PSR; 	// PIO Status Register
	AT91_REG	 Reserved41[1]; 	// 
	AT91_REG	 PIOC_OER; 	// Output Enable Register
	AT91_REG	 PIOC_ODR; 	// Output Disable Registerr
	AT91_REG	 PIOC_OSR; 	// Output Status Register
	AT91_REG	 Reserved42[1]; 	// 
	AT91_REG	 PIOC_IFER; 	// Input Filter Enable Register
	AT91_REG	 PIOC_IFDR; 	// Input Filter Disable Register
	AT91_REG	 PIOC_IFSR; 	// Input Filter Status Register
	AT91_REG	 Reserved43[1]; 	// 
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
	AT91_REG	 Reserved44[1]; 	// 
	AT91_REG	 PIOC_PPUDR; 	// Pull-up Disable Register
	AT91_REG	 PIOC_PPUER; 	// Pull-up Enable Register
	AT91_REG	 PIOC_PPUSR; 	// Pull-up Status Register
	AT91_REG	 Reserved45[1]; 	// 
	AT91_REG	 PIOC_SP1; 	// Select B Register
	AT91_REG	 PIOC_SP2; 	// Select B Register
	AT91_REG	 PIOC_ABSR; 	// AB Select Status Register
	AT91_REG	 Reserved46[5]; 	// 
	AT91_REG	 PIOC_PPDDR; 	// Pull-down Disable Register
	AT91_REG	 PIOC_PPDER; 	// Pull-down Enable Register
	AT91_REG	 PIOC_PPDSR; 	// Pull-down Status Register
	AT91_REG	 Reserved47[1]; 	// 
	AT91_REG	 PIOC_OWER; 	// Output Write Enable Register
	AT91_REG	 PIOC_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIOC_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved48[16]; 	// 
	AT91_REG	 PIOC_ADDRSIZE; 	// PIO ADDRSIZE REGISTER 
	AT91_REG	 PIOC_IPNAME1; 	// PIO IPNAME1 REGISTER 
	AT91_REG	 PIOC_IPNAME2; 	// PIO IPNAME2 REGISTER 
	AT91_REG	 PIOC_FEATURES; 	// PIO FEATURES REGISTER 
	AT91_REG	 PIOC_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 PIOC_SLEW1; 	// PIO SLEWRATE1 REGISTER 
	AT91_REG	 PIOC_SLEW2; 	// PIO SLEWRATE2 REGISTER 
	AT91_REG	 Reserved49[18]; 	// 
	AT91_REG	 PIOC_SENMR; 	// Sensor Mode Register
	AT91_REG	 PIOC_SENIER; 	// Sensor Interrupt Enable Register
	AT91_REG	 PIOC_SENIDR; 	// Sensor Interrupt Disable Register
	AT91_REG	 PIOC_SENIMR; 	// Sensor Interrupt Mask Register
	AT91_REG	 PIOC_SENISR; 	// Sensor Interrupt Status Register
	AT91_REG	 PIOC_SENDATA; 	// Sensor Data Register
	AT91_REG	 PIOC_RPR; 	// Receive Pointer Register
	AT91_REG	 PIOC_RCR; 	// Receive Counter Register
	AT91_REG	 PIOC_TPR; 	// Transmit Pointer Register
	AT91_REG	 PIOC_TCR; 	// Transmit Counter Register
	AT91_REG	 PIOC_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 PIOC_RNCR; 	// Receive Next Counter Register
	AT91_REG	 PIOC_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 PIOC_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 PIOC_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 PIOC_PTSR; 	// PDC Transfer Status Register
	AT91_REG	 Reserved50[28]; 	// 
	AT91_REG	 RSTC_RCR; 	// Reset Control Register
	AT91_REG	 RSTC_RSR; 	// Reset Status Register
	AT91_REG	 RSTC_RMR; 	// Reset Mode Register
	AT91_REG	 Reserved51[1]; 	// 
	AT91_REG	 SUPC_CR; 	// Control Register
	AT91_REG	 SUPC_BOMR; 	// Brown Out Mode Register
	AT91_REG	 SUPC_MR; 	// Mode Register
	AT91_REG	 SUPC_WUMR; 	// Wake Up Mode Register
	AT91_REG	 SUPC_WUIR; 	// Wake Up Inputs Register
	AT91_REG	 SUPC_SR; 	// Status Register
	AT91_REG	 SUPC_FWUTR; 	// Flash Wake-up Timer Register
	AT91_REG	 Reserved52[1]; 	// 
	AT91_REG	 RTTC_RTMR; 	// Real-time Mode Register
	AT91_REG	 RTTC_RTAR; 	// Real-time Alarm Register
	AT91_REG	 RTTC_RTVR; 	// Real-time Value Register
	AT91_REG	 RTTC_RTSR; 	// Real-time Status Register
	AT91_REG	 Reserved53[4]; 	// 
	AT91_REG	 WDTC_WDCR; 	// Watchdog Control Register
	AT91_REG	 WDTC_WDMR; 	// Watchdog Mode Register
	AT91_REG	 WDTC_WDSR; 	// Watchdog Status Register
	AT91_REG	 Reserved54[1]; 	// 
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
	AT91_REG	 SYS_GPBR[8]; 	// General Purpose Register
	AT91_REG	 Reserved55[19]; 	// 
	AT91_REG	 RSTC_VER; 	// Version Register
} AT91S_SYS, *AT91PS_SYS;
#else
#define GPBR            (AT91_CAST(AT91_REG *) 	0x00001490) // (GPBR) General Purpose Register

#endif
// -------- GPBR : (SYS Offset: 0x1490) GPBR General Purpose Register -------- 
#define AT91C_GPBR_GPRV       (0x0 <<  0) // (SYS) General Purpose Register Value

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Static Memory Controller Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_SMC {
	AT91_REG	 SMC_SETUP0; 	//  Setup Register for CS 0
	AT91_REG	 SMC_PULSE0; 	//  Pulse Register for CS 0
	AT91_REG	 SMC_CYCLE0; 	//  Cycle Register for CS 0
	AT91_REG	 SMC_CTRL0; 	//  Control Register for CS 0
	AT91_REG	 SMC_SETUP1; 	//  Setup Register for CS 1
	AT91_REG	 SMC_PULSE1; 	//  Pulse Register for CS 1
	AT91_REG	 SMC_CYCLE1; 	//  Cycle Register for CS 1
	AT91_REG	 SMC_CTRL1; 	//  Control Register for CS 1
	AT91_REG	 SMC_SETUP2; 	//  Setup Register for CS 2
	AT91_REG	 SMC_PULSE2; 	//  Pulse Register for CS 2
	AT91_REG	 SMC_CYCLE2; 	//  Cycle Register for CS 2
	AT91_REG	 SMC_CTRL2; 	//  Control Register for CS 2
	AT91_REG	 SMC_SETUP3; 	//  Setup Register for CS 3
	AT91_REG	 SMC_PULSE3; 	//  Pulse Register for CS 3
	AT91_REG	 SMC_CYCLE3; 	//  Cycle Register for CS 3
	AT91_REG	 SMC_CTRL3; 	//  Control Register for CS 3
	AT91_REG	 SMC_SETUP4; 	//  Setup Register for CS 4
	AT91_REG	 SMC_PULSE4; 	//  Pulse Register for CS 4
	AT91_REG	 SMC_CYCLE4; 	//  Cycle Register for CS 4
	AT91_REG	 SMC_CTRL4; 	//  Control Register for CS 4
	AT91_REG	 SMC_SETUP5; 	//  Setup Register for CS 5
	AT91_REG	 SMC_PULSE5; 	//  Pulse Register for CS 5
	AT91_REG	 SMC_CYCLE5; 	//  Cycle Register for CS 5
	AT91_REG	 SMC_CTRL5; 	//  Control Register for CS 5
	AT91_REG	 SMC_SETUP6; 	//  Setup Register for CS 6
	AT91_REG	 SMC_PULSE6; 	//  Pulse Register for CS 6
	AT91_REG	 SMC_CYCLE6; 	//  Cycle Register for CS 6
	AT91_REG	 SMC_CTRL6; 	//  Control Register for CS 6
	AT91_REG	 SMC_SETUP7; 	//  Setup Register for CS 7
	AT91_REG	 SMC_PULSE7; 	//  Pulse Register for CS 7
	AT91_REG	 SMC_CYCLE7; 	//  Cycle Register for CS 7
	AT91_REG	 SMC_CTRL7; 	//  Control Register for CS 7
	AT91_REG	 Reserved0[16]; 	// 
	AT91_REG	 SMC_DELAY1; 	// SMC Delay Control Register
	AT91_REG	 SMC_DELAY2; 	// SMC Delay Control Register
	AT91_REG	 SMC_DELAY3; 	// SMC Delay Control Register
	AT91_REG	 SMC_DELAY4; 	// SMC Delay Control Register
	AT91_REG	 SMC_DELAY5; 	// SMC Delay Control Register
	AT91_REG	 SMC_DELAY6; 	// SMC Delay Control Register
	AT91_REG	 SMC_DELAY7; 	// SMC Delay Control Register
	AT91_REG	 SMC_DELAY8; 	// SMC Delay Control Register
	AT91_REG	 Reserved1[3]; 	// 
	AT91_REG	 SMC_ADDRSIZE; 	// HSMC3 ADDRSIZE REGISTER 
	AT91_REG	 SMC_IPNAME1; 	// HSMC3 IPNAME1 REGISTER 
	AT91_REG	 SMC_IPNAME2; 	// HSMC3 IPNAME2 REGISTER 
	AT91_REG	 SMC_FEATURES; 	// HSMC3 FEATURES REGISTER 
	AT91_REG	 SMC_VER; 	// HSMC3 VERSION REGISTER
} AT91S_SMC, *AT91PS_SMC;
#else
#define SETUP0          (AT91_CAST(AT91_REG *) 	0x00000000) // (SETUP0)  Setup Register for CS 0
#define PULSE0          (AT91_CAST(AT91_REG *) 	0x00000004) // (PULSE0)  Pulse Register for CS 0
#define CYCLE0          (AT91_CAST(AT91_REG *) 	0x00000008) // (CYCLE0)  Cycle Register for CS 0
#define CTRL0           (AT91_CAST(AT91_REG *) 	0x0000000C) // (CTRL0)  Control Register for CS 0
#define SETUP1          (AT91_CAST(AT91_REG *) 	0x00000010) // (SETUP1)  Setup Register for CS 1
#define PULSE1          (AT91_CAST(AT91_REG *) 	0x00000014) // (PULSE1)  Pulse Register for CS 1
#define CYCLE1          (AT91_CAST(AT91_REG *) 	0x00000018) // (CYCLE1)  Cycle Register for CS 1
#define CTRL1           (AT91_CAST(AT91_REG *) 	0x0000001C) // (CTRL1)  Control Register for CS 1
#define SETUP2          (AT91_CAST(AT91_REG *) 	0x00000020) // (SETUP2)  Setup Register for CS 2
#define PULSE2          (AT91_CAST(AT91_REG *) 	0x00000024) // (PULSE2)  Pulse Register for CS 2
#define CYCLE2          (AT91_CAST(AT91_REG *) 	0x00000028) // (CYCLE2)  Cycle Register for CS 2
#define CTRL2           (AT91_CAST(AT91_REG *) 	0x0000002C) // (CTRL2)  Control Register for CS 2
#define SETUP3          (AT91_CAST(AT91_REG *) 	0x00000030) // (SETUP3)  Setup Register for CS 3
#define PULSE3          (AT91_CAST(AT91_REG *) 	0x00000034) // (PULSE3)  Pulse Register for CS 3
#define CYCLE3          (AT91_CAST(AT91_REG *) 	0x00000038) // (CYCLE3)  Cycle Register for CS 3
#define CTRL3           (AT91_CAST(AT91_REG *) 	0x0000003C) // (CTRL3)  Control Register for CS 3
#define SETUP4          (AT91_CAST(AT91_REG *) 	0x00000040) // (SETUP4)  Setup Register for CS 4
#define PULSE4          (AT91_CAST(AT91_REG *) 	0x00000044) // (PULSE4)  Pulse Register for CS 4
#define CYCLE4          (AT91_CAST(AT91_REG *) 	0x00000048) // (CYCLE4)  Cycle Register for CS 4
#define CTRL4           (AT91_CAST(AT91_REG *) 	0x0000004C) // (CTRL4)  Control Register for CS 4
#define SETUP5          (AT91_CAST(AT91_REG *) 	0x00000050) // (SETUP5)  Setup Register for CS 5
#define PULSE5          (AT91_CAST(AT91_REG *) 	0x00000054) // (PULSE5)  Pulse Register for CS 5
#define CYCLE5          (AT91_CAST(AT91_REG *) 	0x00000058) // (CYCLE5)  Cycle Register for CS 5
#define CTRL5           (AT91_CAST(AT91_REG *) 	0x0000005C) // (CTRL5)  Control Register for CS 5
#define SETUP6          (AT91_CAST(AT91_REG *) 	0x00000060) // (SETUP6)  Setup Register for CS 6
#define PULSE6          (AT91_CAST(AT91_REG *) 	0x00000064) // (PULSE6)  Pulse Register for CS 6
#define CYCLE6          (AT91_CAST(AT91_REG *) 	0x00000068) // (CYCLE6)  Cycle Register for CS 6
#define CTRL6           (AT91_CAST(AT91_REG *) 	0x0000006C) // (CTRL6)  Control Register for CS 6
#define SETUP7          (AT91_CAST(AT91_REG *) 	0x00000070) // (SETUP7)  Setup Register for CS 7
#define PULSE7          (AT91_CAST(AT91_REG *) 	0x00000074) // (PULSE7)  Pulse Register for CS 7
#define CYCLE7          (AT91_CAST(AT91_REG *) 	0x00000078) // (CYCLE7)  Cycle Register for CS 7
#define CTRL7           (AT91_CAST(AT91_REG *) 	0x0000007C) // (CTRL7)  Control Register for CS 7
#define DELAY1          (AT91_CAST(AT91_REG *) 	0x000000C0) // (DELAY1) SMC Delay Control Register
#define DELAY2          (AT91_CAST(AT91_REG *) 	0x000000C4) // (DELAY2) SMC Delay Control Register
#define DELAY3          (AT91_CAST(AT91_REG *) 	0x000000C8) // (DELAY3) SMC Delay Control Register
#define DELAY4          (AT91_CAST(AT91_REG *) 	0x000000CC) // (DELAY4) SMC Delay Control Register
#define DELAY5          (AT91_CAST(AT91_REG *) 	0x000000D0) // (DELAY5) SMC Delay Control Register
#define DELAY6          (AT91_CAST(AT91_REG *) 	0x000000D4) // (DELAY6) SMC Delay Control Register
#define DELAY7          (AT91_CAST(AT91_REG *) 	0x000000D8) // (DELAY7) SMC Delay Control Register
#define DELAY8          (AT91_CAST(AT91_REG *) 	0x000000DC) // (DELAY8) SMC Delay Control Register
#define HSMC3_ADDRSIZE  (AT91_CAST(AT91_REG *) 	0x000000EC) // (HSMC3_ADDRSIZE) HSMC3 ADDRSIZE REGISTER 
#define HSMC3_IPNAME1   (AT91_CAST(AT91_REG *) 	0x000000F0) // (HSMC3_IPNAME1) HSMC3 IPNAME1 REGISTER 
#define HSMC3_IPNAME2   (AT91_CAST(AT91_REG *) 	0x000000F4) // (HSMC3_IPNAME2) HSMC3 IPNAME2 REGISTER 
#define HSMC3_FEATURES  (AT91_CAST(AT91_REG *) 	0x000000F8) // (HSMC3_FEATURES) HSMC3 FEATURES REGISTER 
#define HSMC3_VER       (AT91_CAST(AT91_REG *) 	0x000000FC) // (HSMC3_VER) HSMC3 VERSION REGISTER

#endif
// -------- SMC_SETUP : (SMC Offset: 0x0) Setup Register for CS x -------- 
#define AT91C_SMC_NWESETUP    (0x3F <<  0) // (SMC) NWE Setup Length
#define AT91C_SMC_NCSSETUPWR  (0x3F <<  8) // (SMC) NCS Setup Length in WRite Access
#define AT91C_SMC_NRDSETUP    (0x3F << 16) // (SMC) NRD Setup Length
#define AT91C_SMC_NCSSETUPRD  (0x3F << 24) // (SMC) NCS Setup Length in ReaD Access
// -------- SMC_PULSE : (SMC Offset: 0x4) Pulse Register for CS x -------- 
#define AT91C_SMC_NWEPULSE    (0x7F <<  0) // (SMC) NWE Pulse Length
#define AT91C_SMC_NCSPULSEWR  (0x7F <<  8) // (SMC) NCS Pulse Length in WRite Access
#define AT91C_SMC_NRDPULSE    (0x7F << 16) // (SMC) NRD Pulse Length
#define AT91C_SMC_NCSPULSERD  (0x7F << 24) // (SMC) NCS Pulse Length in ReaD Access
// -------- SMC_CYC : (SMC Offset: 0x8) Cycle Register for CS x -------- 
#define AT91C_SMC_NWECYCLE    (0x1FF <<  0) // (SMC) Total Write Cycle Length
#define AT91C_SMC_NRDCYCLE    (0x1FF << 16) // (SMC) Total Read Cycle Length
// -------- SMC_CTRL : (SMC Offset: 0xc) Control Register for CS x -------- 
#define AT91C_SMC_READMODE    (0x1 <<  0) // (SMC) Read Mode
#define AT91C_SMC_WRITEMODE   (0x1 <<  1) // (SMC) Write Mode
#define AT91C_SMC_NWAITM      (0x3 <<  5) // (SMC) NWAIT Mode
#define 	AT91C_SMC_NWAITM_NWAIT_DISABLE        (0x0 <<  5) // (SMC) External NWAIT disabled.
#define 	AT91C_SMC_NWAITM_NWAIT_ENABLE_FROZEN  (0x2 <<  5) // (SMC) External NWAIT enabled in frozen mode.
#define 	AT91C_SMC_NWAITM_NWAIT_ENABLE_READY   (0x3 <<  5) // (SMC) External NWAIT enabled in ready mode.
#define AT91C_SMC_BAT         (0x1 <<  8) // (SMC) Byte Access Type
#define 	AT91C_SMC_BAT_BYTE_SELECT          (0x0 <<  8) // (SMC) Write controled by ncs, nbs0, nbs1, nbs2, nbs3. Read controled by ncs, nrd, nbs0, nbs1, nbs2, nbs3.
#define 	AT91C_SMC_BAT_BYTE_WRITE           (0x1 <<  8) // (SMC) Write controled by ncs, nwe0, nwe1, nwe2, nwe3. Read controled by ncs and nrd.
#define AT91C_SMC_DBW         (0x3 << 12) // (SMC) Data Bus Width
#define 	AT91C_SMC_DBW_WIDTH_EIGTH_BITS     (0x0 << 12) // (SMC) 8 bits.
#define 	AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS   (0x1 << 12) // (SMC) 16 bits.
#define 	AT91C_SMC_DBW_WIDTH_THIRTY_TWO_BITS (0x2 << 12) // (SMC) 32 bits.
#define AT91C_SMC_TDF         (0xF << 16) // (SMC) Data Float Time.
#define AT91C_SMC_TDFEN       (0x1 << 20) // (SMC) TDF Enabled.
#define AT91C_SMC_PMEN        (0x1 << 24) // (SMC) Page Mode Enabled.
#define AT91C_SMC_PS          (0x3 << 28) // (SMC) Page Size
#define 	AT91C_SMC_PS_SIZE_FOUR_BYTES      (0x0 << 28) // (SMC) 4 bytes.
#define 	AT91C_SMC_PS_SIZE_EIGHT_BYTES     (0x1 << 28) // (SMC) 8 bytes.
#define 	AT91C_SMC_PS_SIZE_SIXTEEN_BYTES   (0x2 << 28) // (SMC) 16 bytes.
#define 	AT91C_SMC_PS_SIZE_THIRTY_TWO_BYTES (0x3 << 28) // (SMC) 32 bytes.
// -------- SMC_SETUP : (SMC Offset: 0x10) Setup Register for CS x -------- 
// -------- SMC_PULSE : (SMC Offset: 0x14) Pulse Register for CS x -------- 
// -------- SMC_CYC : (SMC Offset: 0x18) Cycle Register for CS x -------- 
// -------- SMC_CTRL : (SMC Offset: 0x1c) Control Register for CS x -------- 
// -------- SMC_SETUP : (SMC Offset: 0x20) Setup Register for CS x -------- 
// -------- SMC_PULSE : (SMC Offset: 0x24) Pulse Register for CS x -------- 
// -------- SMC_CYC : (SMC Offset: 0x28) Cycle Register for CS x -------- 
// -------- SMC_CTRL : (SMC Offset: 0x2c) Control Register for CS x -------- 
// -------- SMC_SETUP : (SMC Offset: 0x30) Setup Register for CS x -------- 
// -------- SMC_PULSE : (SMC Offset: 0x34) Pulse Register for CS x -------- 
// -------- SMC_CYC : (SMC Offset: 0x38) Cycle Register for CS x -------- 
// -------- SMC_CTRL : (SMC Offset: 0x3c) Control Register for CS x -------- 
// -------- SMC_SETUP : (SMC Offset: 0x40) Setup Register for CS x -------- 
// -------- SMC_PULSE : (SMC Offset: 0x44) Pulse Register for CS x -------- 
// -------- SMC_CYC : (SMC Offset: 0x48) Cycle Register for CS x -------- 
// -------- SMC_CTRL : (SMC Offset: 0x4c) Control Register for CS x -------- 
// -------- SMC_SETUP : (SMC Offset: 0x50) Setup Register for CS x -------- 
// -------- SMC_PULSE : (SMC Offset: 0x54) Pulse Register for CS x -------- 
// -------- SMC_CYC : (SMC Offset: 0x58) Cycle Register for CS x -------- 
// -------- SMC_CTRL : (SMC Offset: 0x5c) Control Register for CS x -------- 
// -------- SMC_SETUP : (SMC Offset: 0x60) Setup Register for CS x -------- 
// -------- SMC_PULSE : (SMC Offset: 0x64) Pulse Register for CS x -------- 
// -------- SMC_CYC : (SMC Offset: 0x68) Cycle Register for CS x -------- 
// -------- SMC_CTRL : (SMC Offset: 0x6c) Control Register for CS x -------- 
// -------- SMC_SETUP : (SMC Offset: 0x70) Setup Register for CS x -------- 
// -------- SMC_PULSE : (SMC Offset: 0x74) Pulse Register for CS x -------- 
// -------- SMC_CYC : (SMC Offset: 0x78) Cycle Register for CS x -------- 
// -------- SMC_CTRL : (SMC Offset: 0x7c) Control Register for CS x -------- 

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR AHB Matrix2 Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_HMATRIX2 {
	AT91_REG	 HMATRIX2_MCFG0; 	//  Master Configuration Register 0 : ARM I and D
	AT91_REG	 HMATRIX2_MCFG1; 	//  Master Configuration Register 1 : ARM S
	AT91_REG	 HMATRIX2_MCFG2; 	//  Master Configuration Register 2
	AT91_REG	 HMATRIX2_MCFG3; 	//  Master Configuration Register 3
	AT91_REG	 HMATRIX2_MCFG4; 	//  Master Configuration Register 4
	AT91_REG	 HMATRIX2_MCFG5; 	//  Master Configuration Register 5
	AT91_REG	 HMATRIX2_MCFG6; 	//  Master Configuration Register 6
	AT91_REG	 HMATRIX2_MCFG7; 	//  Master Configuration Register 7
	AT91_REG	 Reserved0[8]; 	// 
	AT91_REG	 HMATRIX2_SCFG0; 	//  Slave Configuration Register 0
	AT91_REG	 HMATRIX2_SCFG1; 	//  Slave Configuration Register 1
	AT91_REG	 HMATRIX2_SCFG2; 	//  Slave Configuration Register 2
	AT91_REG	 HMATRIX2_SCFG3; 	//  Slave Configuration Register 3
	AT91_REG	 HMATRIX2_SCFG4; 	//  Slave Configuration Register 4
	AT91_REG	 HMATRIX2_SCFG5; 	//  Slave Configuration Register 5
	AT91_REG	 HMATRIX2_SCFG6; 	//  Slave Configuration Register 6
	AT91_REG	 HMATRIX2_SCFG7; 	//  Slave Configuration Register 5
	AT91_REG	 HMATRIX2_SCFG8; 	//  Slave Configuration Register 8
	AT91_REG	 HMATRIX2_SCFG9; 	//  Slave Configuration Register 9
	AT91_REG	 Reserved1[42]; 	// 
	AT91_REG	 HMATRIX2_SFR0 ; 	//  Special Function Register 0
	AT91_REG	 HMATRIX2_SFR1 ; 	//  Special Function Register 1
	AT91_REG	 HMATRIX2_SFR2 ; 	//  Special Function Register 2
	AT91_REG	 HMATRIX2_SFR3 ; 	//  Special Function Register 3
	AT91_REG	 HMATRIX2_SFR4 ; 	//  Special Function Register 4
	AT91_REG	 HMATRIX2_SFR5 ; 	//  Special Function Register 5
	AT91_REG	 HMATRIX2_SFR6 ; 	//  Special Function Register 6
	AT91_REG	 HMATRIX2_SFR7 ; 	//  Special Function Register 7
	AT91_REG	 HMATRIX2_SFR8 ; 	//  Special Function Register 8
	AT91_REG	 HMATRIX2_SFR9 ; 	//  Special Function Register 9
	AT91_REG	 HMATRIX2_SFR10; 	//  Special Function Register 10
	AT91_REG	 HMATRIX2_SFR11; 	//  Special Function Register 11
	AT91_REG	 HMATRIX2_SFR12; 	//  Special Function Register 12
	AT91_REG	 HMATRIX2_SFR13; 	//  Special Function Register 13
	AT91_REG	 HMATRIX2_SFR14; 	//  Special Function Register 14
	AT91_REG	 HMATRIX2_SFR15; 	//  Special Function Register 15
	AT91_REG	 Reserved2[39]; 	// 
	AT91_REG	 HMATRIX2_ADDRSIZE; 	// HMATRIX2 ADDRSIZE REGISTER 
	AT91_REG	 HMATRIX2_IPNAME1; 	// HMATRIX2 IPNAME1 REGISTER 
	AT91_REG	 HMATRIX2_IPNAME2; 	// HMATRIX2 IPNAME2 REGISTER 
	AT91_REG	 HMATRIX2_FEATURES; 	// HMATRIX2 FEATURES REGISTER 
	AT91_REG	 HMATRIX2_VER; 	// HMATRIX2 VERSION REGISTER 
} AT91S_HMATRIX2, *AT91PS_HMATRIX2;
#else
#define MATRIX_MCFG0    (AT91_CAST(AT91_REG *) 	0x00000000) // (MATRIX_MCFG0)  Master Configuration Register 0 : ARM I and D
#define MATRIX_MCFG1    (AT91_CAST(AT91_REG *) 	0x00000004) // (MATRIX_MCFG1)  Master Configuration Register 1 : ARM S
#define MATRIX_MCFG2    (AT91_CAST(AT91_REG *) 	0x00000008) // (MATRIX_MCFG2)  Master Configuration Register 2
#define MATRIX_MCFG3    (AT91_CAST(AT91_REG *) 	0x0000000C) // (MATRIX_MCFG3)  Master Configuration Register 3
#define MATRIX_MCFG4    (AT91_CAST(AT91_REG *) 	0x00000010) // (MATRIX_MCFG4)  Master Configuration Register 4
#define MATRIX_MCFG5    (AT91_CAST(AT91_REG *) 	0x00000014) // (MATRIX_MCFG5)  Master Configuration Register 5
#define MATRIX_MCFG6    (AT91_CAST(AT91_REG *) 	0x00000018) // (MATRIX_MCFG6)  Master Configuration Register 6
#define MATRIX_MCFG7    (AT91_CAST(AT91_REG *) 	0x0000001C) // (MATRIX_MCFG7)  Master Configuration Register 7
#define MATRIX_SCFG0    (AT91_CAST(AT91_REG *) 	0x00000040) // (MATRIX_SCFG0)  Slave Configuration Register 0
#define MATRIX_SCFG1    (AT91_CAST(AT91_REG *) 	0x00000044) // (MATRIX_SCFG1)  Slave Configuration Register 1
#define MATRIX_SCFG2    (AT91_CAST(AT91_REG *) 	0x00000048) // (MATRIX_SCFG2)  Slave Configuration Register 2
#define MATRIX_SCFG3    (AT91_CAST(AT91_REG *) 	0x0000004C) // (MATRIX_SCFG3)  Slave Configuration Register 3
#define MATRIX_SCFG4    (AT91_CAST(AT91_REG *) 	0x00000050) // (MATRIX_SCFG4)  Slave Configuration Register 4
#define MATRIX_SCFG5    (AT91_CAST(AT91_REG *) 	0x00000054) // (MATRIX_SCFG5)  Slave Configuration Register 5
#define MATRIX_SCFG6    (AT91_CAST(AT91_REG *) 	0x00000058) // (MATRIX_SCFG6)  Slave Configuration Register 6
#define MATRIX_SCFG7    (AT91_CAST(AT91_REG *) 	0x0000005C) // (MATRIX_SCFG7)  Slave Configuration Register 5
#define MATRIX_SCFG8    (AT91_CAST(AT91_REG *) 	0x00000060) // (MATRIX_SCFG8)  Slave Configuration Register 8
#define MATRIX_SCFG9    (AT91_CAST(AT91_REG *) 	0x00000064) // (MATRIX_SCFG9)  Slave Configuration Register 9
#define MATRIX_SFR0     (AT91_CAST(AT91_REG *) 	0x00000110) // (MATRIX_SFR0 )  Special Function Register 0
#define MATRIX_SFR1     (AT91_CAST(AT91_REG *) 	0x00000114) // (MATRIX_SFR1 )  Special Function Register 1
#define MATRIX_SFR2     (AT91_CAST(AT91_REG *) 	0x00000118) // (MATRIX_SFR2 )  Special Function Register 2
#define MATRIX_SFR3     (AT91_CAST(AT91_REG *) 	0x0000011C) // (MATRIX_SFR3 )  Special Function Register 3
#define MATRIX_SFR4     (AT91_CAST(AT91_REG *) 	0x00000120) // (MATRIX_SFR4 )  Special Function Register 4
#define MATRIX_SFR5     (AT91_CAST(AT91_REG *) 	0x00000124) // (MATRIX_SFR5 )  Special Function Register 5
#define MATRIX_SFR6     (AT91_CAST(AT91_REG *) 	0x00000128) // (MATRIX_SFR6 )  Special Function Register 6
#define MATRIX_SFR7     (AT91_CAST(AT91_REG *) 	0x0000012C) // (MATRIX_SFR7 )  Special Function Register 7
#define MATRIX_SFR8     (AT91_CAST(AT91_REG *) 	0x00000130) // (MATRIX_SFR8 )  Special Function Register 8
#define MATRIX_SFR9     (AT91_CAST(AT91_REG *) 	0x00000134) // (MATRIX_SFR9 )  Special Function Register 9
#define MATRIX_SFR10    (AT91_CAST(AT91_REG *) 	0x00000138) // (MATRIX_SFR10)  Special Function Register 10
#define MATRIX_SFR11    (AT91_CAST(AT91_REG *) 	0x0000013C) // (MATRIX_SFR11)  Special Function Register 11
#define MATRIX_SFR12    (AT91_CAST(AT91_REG *) 	0x00000140) // (MATRIX_SFR12)  Special Function Register 12
#define MATRIX_SFR13    (AT91_CAST(AT91_REG *) 	0x00000144) // (MATRIX_SFR13)  Special Function Register 13
#define MATRIX_SFR14    (AT91_CAST(AT91_REG *) 	0x00000148) // (MATRIX_SFR14)  Special Function Register 14
#define MATRIX_SFR15    (AT91_CAST(AT91_REG *) 	0x0000014C) // (MATRIX_SFR15)  Special Function Register 15
#define HMATRIX2_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x000001EC) // (HMATRIX2_ADDRSIZE) HMATRIX2 ADDRSIZE REGISTER 
#define HMATRIX2_IPNAME1 (AT91_CAST(AT91_REG *) 	0x000001F0) // (HMATRIX2_IPNAME1) HMATRIX2 IPNAME1 REGISTER 
#define HMATRIX2_IPNAME2 (AT91_CAST(AT91_REG *) 	0x000001F4) // (HMATRIX2_IPNAME2) HMATRIX2 IPNAME2 REGISTER 
#define HMATRIX2_FEATURES (AT91_CAST(AT91_REG *) 	0x000001F8) // (HMATRIX2_FEATURES) HMATRIX2 FEATURES REGISTER 
#define HMATRIX2_VER    (AT91_CAST(AT91_REG *) 	0x000001FC) // (HMATRIX2_VER) HMATRIX2 VERSION REGISTER 

#endif
// -------- MATRIX_MCFG0 : (HMATRIX2 Offset: 0x0) Master Configuration Register ARM bus I and D -------- 
#define AT91C_MATRIX_ULBT     (0x7 <<  0) // (HMATRIX2) Undefined Length Burst Type
#define 	AT91C_MATRIX_ULBT_INFINIT_LENGTH       (0x0) // (HMATRIX2) infinite length burst
#define 	AT91C_MATRIX_ULBT_SINGLE_ACCESS        (0x1) // (HMATRIX2) Single Access
#define 	AT91C_MATRIX_ULBT_4_BEAT               (0x2) // (HMATRIX2) 4 Beat Burst
#define 	AT91C_MATRIX_ULBT_8_BEAT               (0x3) // (HMATRIX2) 8 Beat Burst
#define 	AT91C_MATRIX_ULBT_16_BEAT              (0x4) // (HMATRIX2) 16 Beat Burst
#define 	AT91C_MATRIX_ULBT_32_BEAT              (0x5) // (HMATRIX2) 32 Beat Burst
#define 	AT91C_MATRIX_ULBT_64_BEAT              (0x6) // (HMATRIX2) 64 Beat Burst
#define 	AT91C_MATRIX_ULBT_128_BEAT             (0x7) // (HMATRIX2) 128 Beat Burst
// -------- MATRIX_MCFG1 : (HMATRIX2 Offset: 0x4) Master Configuration Register ARM bus S -------- 
// -------- MATRIX_MCFG2 : (HMATRIX2 Offset: 0x8) Master Configuration Register -------- 
// -------- MATRIX_MCFG3 : (HMATRIX2 Offset: 0xc) Master Configuration Register -------- 
// -------- MATRIX_MCFG4 : (HMATRIX2 Offset: 0x10) Master Configuration Register -------- 
// -------- MATRIX_MCFG5 : (HMATRIX2 Offset: 0x14) Master Configuration Register -------- 
// -------- MATRIX_MCFG6 : (HMATRIX2 Offset: 0x18) Master Configuration Register -------- 
// -------- MATRIX_MCFG7 : (HMATRIX2 Offset: 0x1c) Master Configuration Register -------- 
// -------- MATRIX_SCFG0 : (HMATRIX2 Offset: 0x40) Slave Configuration Register 0 -------- 
#define AT91C_MATRIX_SLOT_CYCLE (0xFF <<  0) // (HMATRIX2) Maximum Number of Allowed Cycles for a Burst
#define AT91C_MATRIX_DEFMSTR_TYPE (0x3 << 16) // (HMATRIX2) Default Master Type
#define 	AT91C_MATRIX_DEFMSTR_TYPE_NO_DEFMSTR           (0x0 << 16) // (HMATRIX2) No Default Master. At the end of current slave access, if no other master request is pending, the slave is deconnected from all masters. This results in having a one cycle latency for the first transfer of a burst.
#define 	AT91C_MATRIX_DEFMSTR_TYPE_LAST_DEFMSTR         (0x1 << 16) // (HMATRIX2) Last Default Master. At the end of current slave access, if no other master request is pending, the slave stay connected with the last master having accessed it. This results in not having the one cycle latency when the last master re-trying access on the slave.
#define 	AT91C_MATRIX_DEFMSTR_TYPE_FIXED_DEFMSTR        (0x2 << 16) // (HMATRIX2) Fixed Default Master. At the end of current slave access, if no other master request is pending, the slave connects with fixed which number is in FIXED_DEFMSTR field. This results in not having the one cycle latency when the fixed master re-trying access on the slave.
#define AT91C_MATRIX_FIXED_DEFMSTR_SCFG0 (0x7 << 18) // (HMATRIX2) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG0_ARMS                 (0x1 << 18) // (HMATRIX2) ARMS is Default Master
// -------- MATRIX_SCFG1 : (HMATRIX2 Offset: 0x44) Slave Configuration Register 1 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR_SCFG1 (0x7 << 18) // (HMATRIX2) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG1_ARMS                 (0x1 << 18) // (HMATRIX2) ARMS is Default Master
// -------- MATRIX_SCFG2 : (HMATRIX2 Offset: 0x48) Slave Configuration Register 2 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR_SCFG2 (0x7 << 18) // (HMATRIX2) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG2_ARMS                 (0x1 << 18) // (HMATRIX2) ARMS is Default Master
// -------- MATRIX_SCFG3 : (HMATRIX2 Offset: 0x4c) Slave Configuration Register 3 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR_SCFG3 (0x7 << 18) // (HMATRIX2) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG3_ARMC                 (0x0 << 18) // (HMATRIX2) ARMC is Default Master
// -------- MATRIX_SCFG4 : (HMATRIX2 Offset: 0x50) Slave Configuration Register 4 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR_SCFG4 (0x7 << 18) // (HMATRIX2) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG4_ARMC                 (0x0 << 18) // (HMATRIX2) ARMC is Default Master
// -------- MATRIX_SCFG5 : (HMATRIX2 Offset: 0x54) Slave Configuration Register 5 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR_SCFG5 (0x7 << 18) // (HMATRIX2) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG5_ARMS                 (0x1 << 18) // (HMATRIX2) ARMS is Default Master
// -------- MATRIX_SCFG6 : (HMATRIX2 Offset: 0x58) Slave Configuration Register 6 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR_SCFG6 (0x7 << 18) // (HMATRIX2) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG6_ARMS                 (0x1 << 18) // (HMATRIX2) ARMS is Default Master
// -------- MATRIX_SCFG7 : (HMATRIX2 Offset: 0x5c) Slave Configuration Register 7 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR_SCFG7 (0x7 << 18) // (HMATRIX2) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG7_ARMS                 (0x1 << 18) // (HMATRIX2) ARMS is Default Master
// -------- MATRIX_SCFG8 : (HMATRIX2 Offset: 0x60) Slave Configuration Register 8 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR_SCFG8 (0x7 << 18) // (HMATRIX2) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG8_ARMS                 (0x1 << 18) // (HMATRIX2) ARMS is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG8_HDMA                 (0x4 << 18) // (HMATRIX2) HDMA is Default Master
// -------- MATRIX_SCFG9 : (HMATRIX2 Offset: 0x64) Slave Configuration Register 9 -------- 
#define AT91C_MATRIX_FIXED_DEFMSTR_SCFG9 (0x7 << 18) // (HMATRIX2) Fixed Index of Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG9_ARMS                 (0x1 << 18) // (HMATRIX2) ARMS is Default Master
#define 	AT91C_MATRIX_FIXED_DEFMSTR_SCFG9_HDMA                 (0x4 << 18) // (HMATRIX2) HDMA is Default Master
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x110) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x114) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x118) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x11c) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x120) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x124) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x128) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x12c) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x130) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x134) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x138) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x13c) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x140) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x144) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x148) Special Function Register 0 -------- 
// -------- MATRIX_SFR0 : (HMATRIX2 Offset: 0x14c) Special Function Register 0 -------- 
// -------- HMATRIX2_VER : (HMATRIX2 Offset: 0x1fc)  VERSION  Register -------- 
#define AT91C_HMATRIX2_VER    (0xF <<  0) // (HMATRIX2)  VERSION  Register

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR AHB CCFG Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_CCFG {
	AT91_REG	 CCFG_RAM0; 	//  RAM0 configuration
	AT91_REG	 CCFG_ROM; 	//  ROM  configuration
	AT91_REG	 CCFG_FLASH0; 	//  FLASH0 configuration
	AT91_REG	 CCFG_EBICSA; 	//  EBI Chip Select Assignement Register
	AT91_REG	 CCFG_BRIDGE; 	//  BRIDGE configuration
} AT91S_CCFG, *AT91PS_CCFG;
#else
#define CCFG_RAM0       (AT91_CAST(AT91_REG *) 	0x00000000) // (CCFG_RAM0)  RAM0 configuration
#define CCFG_ROM        (AT91_CAST(AT91_REG *) 	0x00000004) // (CCFG_ROM)  ROM  configuration
#define CCFG_FLASH0     (AT91_CAST(AT91_REG *) 	0x00000008) // (CCFG_FLASH0)  FLASH0 configuration
#define CCFG_EBICSA     (AT91_CAST(AT91_REG *) 	0x0000000C) // (CCFG_EBICSA)  EBI Chip Select Assignement Register
#define CCFG_BRIDGE     (AT91_CAST(AT91_REG *) 	0x00000010) // (CCFG_BRIDGE)  BRIDGE configuration

#endif
// -------- CCFG_RAM0 : (CCFG Offset: 0x0) RAM0 Configuration -------- 
// -------- CCFG_ROM : (CCFG Offset: 0x4) ROM configuration -------- 
// -------- CCFG_FLASH0 : (CCFG Offset: 0x8) FLASH0 configuration -------- 
// -------- CCFG_EBICSA : (CCFG Offset: 0xc) EBI Chip Select Assignement Register -------- 
#define AT91C_EBI_CS0A        (0x1 <<  0) // (CCFG) Chip Select 0 Assignment
#define 	AT91C_EBI_CS0A_SMC                  (0x0) // (CCFG) Chip Select 0 is only assigned to the Static Memory Controller and NCS0 behaves as defined by the SMC.
#define 	AT91C_EBI_CS0A_SM                   (0x1) // (CCFG) Chip Select 0 is assigned to the Static Memory Controller and the SmartMedia Logic is activated.
#define AT91C_EBI_CS1A        (0x1 <<  1) // (CCFG) Chip Select 1 Assignment
#define 	AT91C_EBI_CS1A_SMC                  (0x0 <<  1) // (CCFG) Chip Select 1 is only assigned to the Static Memory Controller and NCS1 behaves as defined by the SMC.
#define 	AT91C_EBI_CS1A_SM                   (0x1 <<  1) // (CCFG) Chip Select 1 is assigned to the Static Memory Controller and the SmartMedia Logic is activated.
#define AT91C_EBI_CS2A        (0x1 <<  2) // (CCFG) Chip Select 2 Assignment
#define 	AT91C_EBI_CS2A_SMC                  (0x0 <<  2) // (CCFG) Chip Select 2 is only assigned to the Static Memory Controller and NCS2 behaves as defined by the SMC.
#define 	AT91C_EBI_CS2A_SM                   (0x1 <<  2) // (CCFG) Chip Select 2 is assigned to the Static Memory Controller and the SmartMedia Logic is activated.
#define AT91C_EBI_CS3A        (0x1 <<  3) // (CCFG) Chip Select 3 Assignment
#define 	AT91C_EBI_CS3A_SMC                  (0x0 <<  3) // (CCFG) Chip Select 3 is only assigned to the Static Memory Controller and NCS3 behaves as defined by the SMC.
#define 	AT91C_EBI_CS3A_SM                   (0x1 <<  3) // (CCFG) Chip Select 3 is assigned to the Static Memory Controller and the SmartMedia Logic is activated.
// -------- CCFG_BRIDGE : (CCFG Offset: 0x10) BRIDGE configuration -------- 

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
//              SOFTWARE API DEFINITION  FOR NESTED vector Interrupt Controller
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_MPU {
	AT91_REG	 MPU_TYPE; 	// MPU Type Register
	AT91_REG	 MPU_CTRL; 	// MPU Control Register
	AT91_REG	 MPU_REG_NB; 	// MPU Region Number Register
	AT91_REG	 MPU_REG_BASE_ADDR; 	// MPU Region Base Address Register
	AT91_REG	 MPU_ATTR_SIZE; 	// MPU  Attribute and Size Register
	AT91_REG	 MPU_REG_BASE_ADDR1; 	// MPU Region Base Address Register alias 1
	AT91_REG	 MPU_ATTR_SIZE1; 	// MPU  Attribute and Size Register alias 1
	AT91_REG	 MPU_REG_BASE_ADDR2; 	// MPU Region Base Address Register alias 2
	AT91_REG	 MPU_ATTR_SIZE2; 	// MPU  Attribute and Size Register alias 2
	AT91_REG	 MPU_REG_BASE_ADDR3; 	// MPU Region Base Address Register alias 3
	AT91_REG	 MPU_ATTR_SIZE3; 	// MPU  Attribute and Size Register alias 3
} AT91S_MPU, *AT91PS_MPU;
#else
#define MPU_TYPE        (AT91_CAST(AT91_REG *) 	0x00000000) // (MPU_TYPE) MPU Type Register
#define MPU_CTRL        (AT91_CAST(AT91_REG *) 	0x00000004) // (MPU_CTRL) MPU Control Register
#define MPU_REG_NB      (AT91_CAST(AT91_REG *) 	0x00000008) // (MPU_REG_NB) MPU Region Number Register
#define MPU_REG_BASE_ADDR (AT91_CAST(AT91_REG *) 	0x0000000C) // (MPU_REG_BASE_ADDR) MPU Region Base Address Register
#define MPU_ATTR_SIZE   (AT91_CAST(AT91_REG *) 	0x00000010) // (MPU_ATTR_SIZE) MPU  Attribute and Size Register
#define MPU_REG_BASE_ADDR1 (AT91_CAST(AT91_REG *) 	0x00000014) // (MPU_REG_BASE_ADDR1) MPU Region Base Address Register alias 1
#define MPU_ATTR_SIZE1  (AT91_CAST(AT91_REG *) 	0x00000018) // (MPU_ATTR_SIZE1) MPU  Attribute and Size Register alias 1
#define MPU_REG_BASE_ADDR2 (AT91_CAST(AT91_REG *) 	0x0000001C) // (MPU_REG_BASE_ADDR2) MPU Region Base Address Register alias 2
#define MPU_ATTR_SIZE2  (AT91_CAST(AT91_REG *) 	0x00000020) // (MPU_ATTR_SIZE2) MPU  Attribute and Size Register alias 2
#define MPU_REG_BASE_ADDR3 (AT91_CAST(AT91_REG *) 	0x00000024) // (MPU_REG_BASE_ADDR3) MPU Region Base Address Register alias 3
#define MPU_ATTR_SIZE3  (AT91_CAST(AT91_REG *) 	0x00000028) // (MPU_ATTR_SIZE3) MPU  Attribute and Size Register alias 3

#endif
// -------- MPU_TYPE : (MPU Offset: 0x0)  -------- 
#define AT91C_MPU_SEPARATE    (0x1 <<  0) // (MPU) 
#define AT91C_MPU_DREGION     (0xFF <<  8) // (MPU) 
#define AT91C_MPU_IREGION     (0xFF << 16) // (MPU) 
// -------- MPU_CTRL : (MPU Offset: 0x4)  -------- 
#define AT91C_MPU_ENABLE      (0x1 <<  0) // (MPU) 
#define AT91C_MPU_HFNMIENA    (0x1 <<  1) // (MPU) 
#define AT91C_MPU_PRIVDEFENA  (0x1 <<  2) // (MPU) 
// -------- MPU_REG_NB : (MPU Offset: 0x8)  -------- 
#define AT91C_MPU_REGION      (0xFF <<  0) // (MPU) 
// -------- MPU_REG_BASE_ADDR : (MPU Offset: 0xc)  -------- 
#define AT91C_MPU_REG         (0xF <<  0) // (MPU) 
#define AT91C_MPU_VALID       (0x1 <<  4) // (MPU) 
#define AT91C_MPU_ADDR        (0x3FFFFFF <<  5) // (MPU) 
// -------- MPU_ATTR_SIZE : (MPU Offset: 0x10)  -------- 
#define AT91C_MPU_ENA         (0x1 <<  0) // (MPU) 
#define AT91C_MPU_SIZE        (0xF <<  1) // (MPU) 
#define AT91C_MPU_SRD         (0xFF <<  8) // (MPU) 
#define AT91C_MPU_B           (0x1 << 16) // (MPU) 
#define AT91C_MPU_C           (0x1 << 17) // (MPU) 
#define AT91C_MPU_S           (0x1 << 18) // (MPU) 
#define AT91C_MPU_TEX         (0x7 << 19) // (MPU) 
#define AT91C_MPU_AP          (0x7 << 24) // (MPU) 
#define AT91C_MPU_XN          (0x7 << 28) // (MPU) 

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
	AT91_REG	 Reserved0[9]; 	// 
	AT91_REG	 DBGU_FNTR; 	// Force NTRST Register
	AT91_REG	 Reserved1[40]; 	// 
	AT91_REG	 DBGU_ADDRSIZE; 	// DBGU ADDRSIZE REGISTER 
	AT91_REG	 DBGU_IPNAME1; 	// DBGU IPNAME1 REGISTER 
	AT91_REG	 DBGU_IPNAME2; 	// DBGU IPNAME2 REGISTER 
	AT91_REG	 DBGU_FEATURES; 	// DBGU FEATURES REGISTER 
	AT91_REG	 DBGU_VER; 	// DBGU VERSION REGISTER 
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
	AT91_REG	 Reserved2[6]; 	// 
	AT91_REG	 DBGU_CIDR; 	// Chip ID Register
	AT91_REG	 DBGU_EXID; 	// Chip ID Extension Register
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
#define DBGU_FNTR       (AT91_CAST(AT91_REG *) 	0x00000048) // (DBGU_FNTR) Force NTRST Register
#define DBGU_ADDRSIZE   (AT91_CAST(AT91_REG *) 	0x000000EC) // (DBGU_ADDRSIZE) DBGU ADDRSIZE REGISTER 
#define DBGU_IPNAME1    (AT91_CAST(AT91_REG *) 	0x000000F0) // (DBGU_IPNAME1) DBGU IPNAME1 REGISTER 
#define DBGU_IPNAME2    (AT91_CAST(AT91_REG *) 	0x000000F4) // (DBGU_IPNAME2) DBGU IPNAME2 REGISTER 
#define DBGU_FEATURES   (AT91_CAST(AT91_REG *) 	0x000000F8) // (DBGU_FEATURES) DBGU FEATURES REGISTER 
#define DBGU_VER        (AT91_CAST(AT91_REG *) 	0x000000FC) // (DBGU_VER) DBGU VERSION REGISTER 
#define DBGU_CIDR       (AT91_CAST(AT91_REG *) 	0x00000140) // (DBGU_CIDR) Chip ID Register
#define DBGU_EXID       (AT91_CAST(AT91_REG *) 	0x00000144) // (DBGU_EXID) Chip ID Extension Register

#endif
// -------- DBGU_CR : (DBGU Offset: 0x0) Debug Unit Control Register -------- 
#define AT91C_DBGU_RSTRX      (0x1 <<  2) // (DBGU) Reset Receiver
#define AT91C_DBGU_RSTTX      (0x1 <<  3) // (DBGU) Reset Transmitter
#define AT91C_DBGU_RXEN       (0x1 <<  4) // (DBGU) Receiver Enable
#define AT91C_DBGU_RXDIS      (0x1 <<  5) // (DBGU) Receiver Disable
#define AT91C_DBGU_TXEN       (0x1 <<  6) // (DBGU) Transmitter Enable
#define AT91C_DBGU_TXDIS      (0x1 <<  7) // (DBGU) Transmitter Disable
#define AT91C_DBGU_RSTSTA     (0x1 <<  8) // (DBGU) Reset Status Bits
// -------- DBGU_MR : (DBGU Offset: 0x4) Debug Unit Mode Register -------- 
#define AT91C_DBGU_PAR        (0x7 <<  9) // (DBGU) Parity type
#define 	AT91C_DBGU_PAR_EVEN                 (0x0 <<  9) // (DBGU) Even Parity
#define 	AT91C_DBGU_PAR_ODD                  (0x1 <<  9) // (DBGU) Odd Parity
#define 	AT91C_DBGU_PAR_SPACE                (0x2 <<  9) // (DBGU) Parity forced to 0 (Space)
#define 	AT91C_DBGU_PAR_MARK                 (0x3 <<  9) // (DBGU) Parity forced to 1 (Mark)
#define 	AT91C_DBGU_PAR_NONE                 (0x4 <<  9) // (DBGU) No Parity
#define AT91C_DBGU_CHMODE     (0x3 << 14) // (DBGU) Channel Mode
#define 	AT91C_DBGU_CHMODE_NORMAL               (0x0 << 14) // (DBGU) Normal Mode: The debug unit channel operates as an RX/TX debug unit.
#define 	AT91C_DBGU_CHMODE_AUTO                 (0x1 << 14) // (DBGU) Automatic Echo: Receiver Data Input is connected to the TXD pin.
#define 	AT91C_DBGU_CHMODE_LOCAL                (0x2 << 14) // (DBGU) Local Loopback: Transmitter Output Signal is connected to Receiver Input Signal.
#define 	AT91C_DBGU_CHMODE_REMOTE               (0x3 << 14) // (DBGU) Remote Loopback: RXD pin is internally connected to TXD pin.
// -------- DBGU_IER : (DBGU Offset: 0x8) Debug Unit Interrupt Enable Register -------- 
#define AT91C_DBGU_RXRDY      (0x1 <<  0) // (DBGU) RXRDY Interrupt
#define AT91C_DBGU_TXRDY      (0x1 <<  1) // (DBGU) TXRDY Interrupt
#define AT91C_DBGU_ENDRX      (0x1 <<  3) // (DBGU) End of Receive Transfer Interrupt
#define AT91C_DBGU_ENDTX      (0x1 <<  4) // (DBGU) End of Transmit Interrupt
#define AT91C_DBGU_OVRE       (0x1 <<  5) // (DBGU) Overrun Interrupt
#define AT91C_DBGU_FRAME      (0x1 <<  6) // (DBGU) Framing Error Interrupt
#define AT91C_DBGU_PARE       (0x1 <<  7) // (DBGU) Parity Error Interrupt
#define AT91C_DBGU_TXEMPTY    (0x1 <<  9) // (DBGU) TXEMPTY Interrupt
#define AT91C_DBGU_TXBUFE     (0x1 << 11) // (DBGU) TXBUFE Interrupt
#define AT91C_DBGU_RXBUFF     (0x1 << 12) // (DBGU) RXBUFF Interrupt
#define AT91C_DBGU_COMM_TX    (0x1 << 30) // (DBGU) COMM_TX Interrupt
#define AT91C_DBGU_COMM_RX    (0x1 << 31) // (DBGU) COMM_RX Interrupt
// -------- DBGU_IDR : (DBGU Offset: 0xc) Debug Unit Interrupt Disable Register -------- 
// -------- DBGU_IMR : (DBGU Offset: 0x10) Debug Unit Interrupt Mask Register -------- 
// -------- DBGU_CSR : (DBGU Offset: 0x14) Debug Unit Channel Status Register -------- 
// -------- DBGU_FNTR : (DBGU Offset: 0x48) Debug Unit FORCE_NTRST Register -------- 
#define AT91C_DBGU_FORCE_NTRST (0x1 <<  0) // (DBGU) Force NTRST in JTAG

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
	AT91_REG	 PIO_SP1; 	// Select B Register
	AT91_REG	 PIO_SP2; 	// Select B Register
	AT91_REG	 PIO_ABSR; 	// AB Select Status Register
	AT91_REG	 Reserved5[5]; 	// 
	AT91_REG	 PIO_PPDDR; 	// Pull-down Disable Register
	AT91_REG	 PIO_PPDER; 	// Pull-down Enable Register
	AT91_REG	 PIO_PPDSR; 	// Pull-down Status Register
	AT91_REG	 Reserved6[1]; 	// 
	AT91_REG	 PIO_OWER; 	// Output Write Enable Register
	AT91_REG	 PIO_OWDR; 	// Output Write Disable Register
	AT91_REG	 PIO_OWSR; 	// Output Write Status Register
	AT91_REG	 Reserved7[16]; 	// 
	AT91_REG	 PIO_ADDRSIZE; 	// PIO ADDRSIZE REGISTER 
	AT91_REG	 PIO_IPNAME1; 	// PIO IPNAME1 REGISTER 
	AT91_REG	 PIO_IPNAME2; 	// PIO IPNAME2 REGISTER 
	AT91_REG	 PIO_FEATURES; 	// PIO FEATURES REGISTER 
	AT91_REG	 PIO_VER; 	// PIO VERSION REGISTER 
	AT91_REG	 PIO_SLEW1; 	// PIO SLEWRATE1 REGISTER 
	AT91_REG	 PIO_SLEW2; 	// PIO SLEWRATE2 REGISTER 
	AT91_REG	 Reserved8[18]; 	// 
	AT91_REG	 PIO_SENMR; 	// Sensor Mode Register
	AT91_REG	 PIO_SENIER; 	// Sensor Interrupt Enable Register
	AT91_REG	 PIO_SENIDR; 	// Sensor Interrupt Disable Register
	AT91_REG	 PIO_SENIMR; 	// Sensor Interrupt Mask Register
	AT91_REG	 PIO_SENISR; 	// Sensor Interrupt Status Register
	AT91_REG	 PIO_SENDATA; 	// Sensor Data Register
	AT91_REG	 PIOA_RPR; 	// Receive Pointer Register
	AT91_REG	 PIOA_RCR; 	// Receive Counter Register
	AT91_REG	 PIOA_TPR; 	// Transmit Pointer Register
	AT91_REG	 PIOA_TCR; 	// Transmit Counter Register
	AT91_REG	 PIOA_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 PIOA_RNCR; 	// Receive Next Counter Register
	AT91_REG	 PIOA_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 PIOA_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 PIOA_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 PIOA_PTSR; 	// PDC Transfer Status Register
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
#define PIO_SP1         (AT91_CAST(AT91_REG *) 	0x00000070) // (PIO_SP1) Select B Register
#define PIO_SP2         (AT91_CAST(AT91_REG *) 	0x00000074) // (PIO_SP2) Select B Register
#define PIO_ABSR        (AT91_CAST(AT91_REG *) 	0x00000078) // (PIO_ABSR) AB Select Status Register
#define PIO_PPDDR       (AT91_CAST(AT91_REG *) 	0x00000090) // (PIO_PPDDR) Pull-down Disable Register
#define PIO_PPDER       (AT91_CAST(AT91_REG *) 	0x00000094) // (PIO_PPDER) Pull-down Enable Register
#define PIO_PPDSR       (AT91_CAST(AT91_REG *) 	0x00000098) // (PIO_PPDSR) Pull-down Status Register
#define PIO_OWER        (AT91_CAST(AT91_REG *) 	0x000000A0) // (PIO_OWER) Output Write Enable Register
#define PIO_OWDR        (AT91_CAST(AT91_REG *) 	0x000000A4) // (PIO_OWDR) Output Write Disable Register
#define PIO_OWSR        (AT91_CAST(AT91_REG *) 	0x000000A8) // (PIO_OWSR) Output Write Status Register
#define PIO_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000EC) // (PIO_ADDRSIZE) PIO ADDRSIZE REGISTER 
#define PIO_IPNAME1     (AT91_CAST(AT91_REG *) 	0x000000F0) // (PIO_IPNAME1) PIO IPNAME1 REGISTER 
#define PIO_IPNAME2     (AT91_CAST(AT91_REG *) 	0x000000F4) // (PIO_IPNAME2) PIO IPNAME2 REGISTER 
#define PIO_FEATURES    (AT91_CAST(AT91_REG *) 	0x000000F8) // (PIO_FEATURES) PIO FEATURES REGISTER 
#define PIO_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (PIO_VER) PIO VERSION REGISTER 
#define PIO_SLEW1       (AT91_CAST(AT91_REG *) 	0x00000100) // (PIO_SLEW1) PIO SLEWRATE1 REGISTER 
#define PIO_SLEW2       (AT91_CAST(AT91_REG *) 	0x00000104) // (PIO_SLEW2) PIO SLEWRATE2 REGISTER 
#define PIO_SENMR       (AT91_CAST(AT91_REG *) 	0x00000150) // (PIO_SENMR) Sensor Mode Register
#define PIO_SENIER      (AT91_CAST(AT91_REG *) 	0x00000154) // (PIO_SENIER) Sensor Interrupt Enable Register
#define PIO_SENIDR      (AT91_CAST(AT91_REG *) 	0x00000158) // (PIO_SENIDR) Sensor Interrupt Disable Register
#define PIO_SENIMR      (AT91_CAST(AT91_REG *) 	0x0000015C) // (PIO_SENIMR) Sensor Interrupt Mask Register
#define PIO_SENISR      (AT91_CAST(AT91_REG *) 	0x00000160) // (PIO_SENISR) Sensor Interrupt Status Register
#define PIO_SENDATA     (AT91_CAST(AT91_REG *) 	0x00000164) // (PIO_SENDATA) Sensor Data Register

#endif

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
	AT91_REG	 PMC_PLLBR; 	// PLL B Register
	AT91_REG	 PMC_MCKR; 	// Master Clock Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 PMC_UDPR; 	// USB DEV Clock Configuration Register
	AT91_REG	 Reserved2[1]; 	// 
	AT91_REG	 PMC_PCKR[8]; 	// Programmable Clock Register
	AT91_REG	 PMC_IER; 	// Interrupt Enable Register
	AT91_REG	 PMC_IDR; 	// Interrupt Disable Register
	AT91_REG	 PMC_SR; 	// Status Register
	AT91_REG	 PMC_IMR; 	// Interrupt Mask Register
	AT91_REG	 PMC_FSMR; 	// Fast Startup Mode Register
	AT91_REG	 PMC_FSPR; 	// Fast Startup Polarity Register
	AT91_REG	 PMC_FOCR; 	// Fault Output Clear Register
	AT91_REG	 Reserved3[28]; 	// 
	AT91_REG	 PMC_ADDRSIZE; 	// PMC ADDRSIZE REGISTER 
	AT91_REG	 PMC_IPNAME1; 	// PMC IPNAME1 REGISTER 
	AT91_REG	 PMC_IPNAME2; 	// PMC IPNAME2 REGISTER 
	AT91_REG	 PMC_FEATURES; 	// PMC FEATURES REGISTER 
	AT91_REG	 PMC_VER; 	// APMC VERSION REGISTER
	AT91_REG	 PMC_PCER1; 	// Peripheral Clock Enable Register 32:63 PERI_ID
	AT91_REG	 PMC_PCDR1; 	// Peripheral Clock Disable Register 32:63 PERI_ID
	AT91_REG	 PMC_PCSR1; 	// Peripheral Clock Status Register 32:63 PERI_ID
	AT91_REG	 PMC_PCR; 	// Peripheral Control Register
} AT91S_PMC, *AT91PS_PMC;
#else
#define PMC_SCER        (AT91_CAST(AT91_REG *) 	0x00000000) // (PMC_SCER) System Clock Enable Register
#define PMC_SCDR        (AT91_CAST(AT91_REG *) 	0x00000004) // (PMC_SCDR) System Clock Disable Register
#define PMC_SCSR        (AT91_CAST(AT91_REG *) 	0x00000008) // (PMC_SCSR) System Clock Status Register
#define PMC_PCER        (AT91_CAST(AT91_REG *) 	0x00000010) // (PMC_PCER) Peripheral Clock Enable Register 0:31 PERI_ID
#define PMC_PCDR        (AT91_CAST(AT91_REG *) 	0x00000014) // (PMC_PCDR) Peripheral Clock Disable Register 0:31 PERI_ID
#define PMC_PCSR        (AT91_CAST(AT91_REG *) 	0x00000018) // (PMC_PCSR) Peripheral Clock Status Register 0:31 PERI_ID
#define CKGR_UCKR       (AT91_CAST(AT91_REG *) 	0x0000001C) // (CKGR_UCKR) UTMI Clock Configuration Register
#define CKGR_MOR        (AT91_CAST(AT91_REG *) 	0x00000020) // (CKGR_MOR) Main Oscillator Register
#define CKGR_MCFR       (AT91_CAST(AT91_REG *) 	0x00000024) // (CKGR_MCFR) Main Clock  Frequency Register
#define CKGR_PLLAR      (AT91_CAST(AT91_REG *) 	0x00000028) // (CKGR_PLLAR) PLL Register
#define CKGR_PLLBR      (AT91_CAST(AT91_REG *) 	0x0000002C) // (CKGR_PLLBR) PLL B Register
#define PMC_MCKR        (AT91_CAST(AT91_REG *) 	0x00000030) // (PMC_MCKR) Master Clock Register
#define PMC_UDPR        (AT91_CAST(AT91_REG *) 	0x00000038) // (PMC_UDPR) USB DEV Clock Configuration Register
#define PMC_PCKR        (AT91_CAST(AT91_REG *) 	0x00000040) // (PMC_PCKR) Programmable Clock Register
#define PMC_IER         (AT91_CAST(AT91_REG *) 	0x00000060) // (PMC_IER) Interrupt Enable Register
#define PMC_IDR         (AT91_CAST(AT91_REG *) 	0x00000064) // (PMC_IDR) Interrupt Disable Register
#define PMC_SR          (AT91_CAST(AT91_REG *) 	0x00000068) // (PMC_SR) Status Register
#define PMC_IMR         (AT91_CAST(AT91_REG *) 	0x0000006C) // (PMC_IMR) Interrupt Mask Register
#define PMC_FSMR        (AT91_CAST(AT91_REG *) 	0x00000070) // (PMC_FSMR) Fast Startup Mode Register
#define PMC_FSPR        (AT91_CAST(AT91_REG *) 	0x00000074) // (PMC_FSPR) Fast Startup Polarity Register
#define PMC_FOCR        (AT91_CAST(AT91_REG *) 	0x00000078) // (PMC_FOCR) Fault Output Clear Register
#define PMC_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000EC) // (PMC_ADDRSIZE) PMC ADDRSIZE REGISTER 
#define PMC_IPNAME1     (AT91_CAST(AT91_REG *) 	0x000000F0) // (PMC_IPNAME1) PMC IPNAME1 REGISTER 
#define PMC_IPNAME2     (AT91_CAST(AT91_REG *) 	0x000000F4) // (PMC_IPNAME2) PMC IPNAME2 REGISTER 
#define PMC_FEATURES    (AT91_CAST(AT91_REG *) 	0x000000F8) // (PMC_FEATURES) PMC FEATURES REGISTER 
#define PMC_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (PMC_VER) APMC VERSION REGISTER
#define PMC_PCER1       (AT91_CAST(AT91_REG *) 	0x00000100) // (PMC_PCER1) Peripheral Clock Enable Register 32:63 PERI_ID
#define PMC_PCDR1       (AT91_CAST(AT91_REG *) 	0x00000104) // (PMC_PCDR1) Peripheral Clock Disable Register 32:63 PERI_ID
#define PMC_PCSR1       (AT91_CAST(AT91_REG *) 	0x00000108) // (PMC_PCSR1) Peripheral Clock Status Register 32:63 PERI_ID
#define PMC_PCR         (AT91_CAST(AT91_REG *) 	0x0000010C) // (PMC_PCR) Peripheral Control Register

#endif
// -------- PMC_SCER : (PMC Offset: 0x0) System Clock Enable Register -------- 
#define AT91C_PMC_PCK         (0x1 <<  0) // (PMC) Processor Clock
#define AT91C_PMC_UDP         (0x1 <<  7) // (PMC) USB Device Port Clock
#define AT91C_PMC_PCK0        (0x1 <<  8) // (PMC) Programmable Clock Output
#define AT91C_PMC_PCK1        (0x1 <<  9) // (PMC) Programmable Clock Output
#define AT91C_PMC_PCK2        (0x1 << 10) // (PMC) Programmable Clock Output
// -------- PMC_SCDR : (PMC Offset: 0x4) System Clock Disable Register -------- 
// -------- PMC_SCSR : (PMC Offset: 0x8) System Clock Status Register -------- 
// -------- CKGR_UCKR : (PMC Offset: 0x1c) UTMI Clock Configuration Register -------- 
#define AT91C_CKGR_UPLLEN     (0x1 << 16) // (PMC) UTMI PLL Enable
#define 	AT91C_CKGR_UPLLEN_DISABLED             (0x0 << 16) // (PMC) The UTMI PLL is disabled
#define 	AT91C_CKGR_UPLLEN_ENABLED              (0x1 << 16) // (PMC) The UTMI PLL is enabled
#define AT91C_CKGR_UPLLCOUNT  (0xF << 20) // (PMC) UTMI Oscillator Start-up Time
#define AT91C_CKGR_BIASEN     (0x1 << 24) // (PMC) UTMI BIAS Enable
#define 	AT91C_CKGR_BIASEN_DISABLED             (0x0 << 24) // (PMC) The UTMI BIAS is disabled
#define 	AT91C_CKGR_BIASEN_ENABLED              (0x1 << 24) // (PMC) The UTMI BIAS is enabled
#define AT91C_CKGR_BIASCOUNT  (0xF << 28) // (PMC) UTMI BIAS Start-up Time
// -------- CKGR_MOR : (PMC Offset: 0x20) Main Oscillator Register -------- 
#define AT91C_CKGR_MOSCXTEN   (0x1 <<  0) // (PMC) Main Crystal Oscillator Enable
#define AT91C_CKGR_MOSCXTBY   (0x1 <<  1) // (PMC) Main Crystal Oscillator Bypass
#define AT91C_CKGR_WAITMODE   (0x1 <<  2) // (PMC) Main Crystal Oscillator Bypass
#define AT91C_CKGR_MOSCRCEN   (0x1 <<  3) // (PMC) Main On-Chip RC Oscillator Enable
#define AT91C_CKGR_MOSCRCF    (0x7 <<  4) // (PMC) Main On-Chip RC Oscillator Frequency Selection
#define AT91C_CKGR_MOSCXTST   (0xFF <<  8) // (PMC) Main Crystal Oscillator Start-up Time
#define AT91C_CKGR_KEY        (0xFF << 16) // (PMC) Clock Generator Controller Writing Protection Key
#define AT91C_CKGR_MOSCSEL    (0x1 << 24) // (PMC) Main Oscillator Selection
#define AT91C_CKGR_CFDEN      (0x1 << 25) // (PMC) Clock Failure Detector Enable
// -------- CKGR_MCFR : (PMC Offset: 0x24) Main Clock Frequency Register -------- 
#define AT91C_CKGR_MAINF      (0xFFFF <<  0) // (PMC) Main Clock Frequency
#define AT91C_CKGR_MAINRDY    (0x1 << 16) // (PMC) Main Clock Ready
// -------- CKGR_PLLAR : (PMC Offset: 0x28) PLL A Register -------- 
#define AT91C_CKGR_DIVA       (0xFF <<  0) // (PMC) Divider Selected
#define 	AT91C_CKGR_DIVA_0                    (0x0) // (PMC) Divider output is 0
#define 	AT91C_CKGR_DIVA_BYPASS               (0x1) // (PMC) Divider is bypassed
#define AT91C_CKGR_PLLACOUNT  (0x3F <<  8) // (PMC) PLLA Counter
#define AT91C_CKGR_STMODE     (0x3 << 14) // (PMC) Start Mode
#define 	AT91C_CKGR_STMODE_0                    (0x0 << 14) // (PMC) Fast startup
#define 	AT91C_CKGR_STMODE_1                    (0x1 << 14) // (PMC) Reserved
#define 	AT91C_CKGR_STMODE_2                    (0x2 << 14) // (PMC) Normal startup
#define 	AT91C_CKGR_STMODE_3                    (0x3 << 14) // (PMC) Reserved
#define AT91C_CKGR_MULA       (0x7FF << 16) // (PMC) PLL Multiplier
#define AT91C_CKGR_SRC        (0x1 << 29) // (PMC) 
// -------- CKGR_PLLBR : (PMC Offset: 0x2c) PLL B Register -------- 
#define AT91C_CKGR_DIVB       (0xFF <<  0) // (PMC) Divider B Selected
#define 	AT91C_CKGR_DIVB_0                    (0x0) // (PMC) Divider B output is 0
#define 	AT91C_CKGR_DIVB_BYPASS               (0x1) // (PMC) Divider B is bypassed
#define AT91C_CKGR_PLLBCOUNT  (0x3F <<  8) // (PMC) PLL B Counter
#define AT91C_CKGR_OUTB       (0x3 << 14) // (PMC) PLL B Output Frequency Range
#define 	AT91C_CKGR_OUTB_0                    (0x0 << 14) // (PMC) Please refer to the PLLB datasheet
#define 	AT91C_CKGR_OUTB_1                    (0x1 << 14) // (PMC) Please refer to the PLLB datasheet
#define 	AT91C_CKGR_OUTB_2                    (0x2 << 14) // (PMC) Please refer to the PLLB datasheet
#define 	AT91C_CKGR_OUTB_3                    (0x3 << 14) // (PMC) Please refer to the PLLB datasheet
#define AT91C_CKGR_MULB       (0x7FF << 16) // (PMC) PLL B Multiplier
// -------- PMC_MCKR : (PMC Offset: 0x30) Master Clock Register -------- 
#define AT91C_PMC_CSS         (0x7 <<  0) // (PMC) Programmable Clock Selection
#define 	AT91C_PMC_CSS_SLOW_CLK             (0x0) // (PMC) Slow Clock is selected
#define 	AT91C_PMC_CSS_MAIN_CLK             (0x1) // (PMC) Main Clock is selected
#define 	AT91C_PMC_CSS_PLLA_CLK             (0x2) // (PMC) Clock from PLL A is selected
#define 	AT91C_PMC_CSS_PLLB_CLK             (0x3) // (PMC) Clock from PLL B is selected
#define 	AT91C_PMC_CSS_SYS_CLK              (0x4) // (PMC) System clock is selected
#define AT91C_PMC_PRES        (0xF <<  4) // (PMC) Programmable Clock Prescaler
#define 	AT91C_PMC_PRES_CLK                  (0x0 <<  4) // (PMC) Selected clock
#define 	AT91C_PMC_PRES_CLK_2                (0x1 <<  4) // (PMC) Selected clock divided by 2
#define 	AT91C_PMC_PRES_CLK_4                (0x2 <<  4) // (PMC) Selected clock divided by 4
#define 	AT91C_PMC_PRES_CLK_8                (0x3 <<  4) // (PMC) Selected clock divided by 8
#define 	AT91C_PMC_PRES_CLK_16               (0x4 <<  4) // (PMC) Selected clock divided by 16
#define 	AT91C_PMC_PRES_CLK_32               (0x5 <<  4) // (PMC) Selected clock divided by 32
#define 	AT91C_PMC_PRES_CLK_64               (0x6 <<  4) // (PMC) Selected clock divided by 64
#define 	AT91C_PMC_PRES_CLK_3                (0x7 <<  4) // (PMC) Selected clock divided by 3
#define 	AT91C_PMC_PRES_CLK_1_5              (0x8 <<  4) // (PMC) Selected clock divided by 1.5
// -------- PMC_UDPR : (PMC Offset: 0x38) USB DEV Clock Configuration Register -------- 
#define AT91C_PMC_UDP_CLK_SEL (0x1 <<  0) // (PMC) UDP Clock Selection
#define 	AT91C_PMC_UDP_CLK_SEL_PLLA                 (0x0) // (PMC) PLL A is the selected clock source for UDP DEV
#define 	AT91C_PMC_UDP_CLK_SEL_PLLB                 (0x1) // (PMC) PLL B is the selected clock source for UDP DEV
#define AT91C_PMC_UDP_DIV     (0xF <<  8) // (PMC) UDP Clock Divider
#define 	AT91C_PMC_UDP_DIV_DIV                  (0x0 <<  8) // (PMC) Selected clock
#define 	AT91C_PMC_UDP_DIV_DIV_2                (0x1 <<  8) // (PMC) Selected clock divided by 2
// -------- PMC_PCKR : (PMC Offset: 0x40) Programmable Clock Register -------- 
// -------- PMC_IER : (PMC Offset: 0x60) PMC Interrupt Enable Register -------- 
#define AT91C_PMC_MOSCXTS     (0x1 <<  0) // (PMC) Main Crystal Oscillator Status/Enable/Disable/Mask
#define AT91C_PMC_LOCKA       (0x1 <<  1) // (PMC) PLL A Status/Enable/Disable/Mask
#define AT91C_PMC_LOCKB       (0x1 <<  2) // (PMC) PLL B Status/Enable/Disable/Mask
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
#define AT91C_                (0x0 <<  7) // (PMC) 
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
// -------- PMC_PCR : (PMC Offset: 0x10c) Peripheral Control Register -------- 
#define AT91C_PMC_PID         (0x3F <<  0) // (PMC) Peripheral Identifier
#define AT91C_PMC_CMD         (0x1 << 12) // (PMC) Read / Write Command
#define AT91C_PMC_DIV         (0x3 << 16) // (PMC) Peripheral clock Divider
#define AT91C_PMC_EN          (0x1 << 28) // (PMC) Peripheral Clock Enable

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Clock Generator Controler
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_CKGR {
	AT91_REG	 CKGR_UCKR; 	// UTMI Clock Configuration Register
	AT91_REG	 CKGR_MOR; 	// Main Oscillator Register
	AT91_REG	 CKGR_MCFR; 	// Main Clock  Frequency Register
	AT91_REG	 CKGR_PLLAR; 	// PLL Register
	AT91_REG	 CKGR_PLLBR; 	// PLL B Register
} AT91S_CKGR, *AT91PS_CKGR;
#else

#endif
// -------- CKGR_UCKR : (CKGR Offset: 0x0) UTMI Clock Configuration Register -------- 
// -------- CKGR_MOR : (CKGR Offset: 0x4) Main Oscillator Register -------- 
// -------- CKGR_MCFR : (CKGR Offset: 0x8) Main Clock Frequency Register -------- 
// -------- CKGR_PLLAR : (CKGR Offset: 0xc) PLL A Register -------- 
// -------- CKGR_PLLBR : (CKGR Offset: 0x10) PLL B Register -------- 

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
	AT91_REG	 DAC_ADDRSIZE; 	// DAC ADDRSIZE REGISTER 
	AT91_REG	 DAC_IPNAME1; 	// DAC IPNAME1 REGISTER 
	AT91_REG	 DAC_IPNAME2; 	// DAC IPNAME2 REGISTER 
	AT91_REG	 DAC_FEATURES; 	// DAC FEATURES REGISTER 
	AT91_REG	 DAC_VER; 	// DAC VERSION REGISTER
	AT91_REG	 DAC_RPR; 	// Receive Pointer Register
	AT91_REG	 DAC_RCR; 	// Receive Counter Register
	AT91_REG	 DAC_TPR; 	// Transmit Pointer Register
	AT91_REG	 DAC_TCR; 	// Transmit Counter Register
	AT91_REG	 DAC_RNPR; 	// Receive Next Pointer Register
	AT91_REG	 DAC_RNCR; 	// Receive Next Counter Register
	AT91_REG	 DAC_TNPR; 	// Transmit Next Pointer Register
	AT91_REG	 DAC_TNCR; 	// Transmit Next Counter Register
	AT91_REG	 DAC_PTCR; 	// PDC Transfer Control Register
	AT91_REG	 DAC_PTSR; 	// PDC Transfer Status Register
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
#define DAC_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000EC) // (DAC_ADDRSIZE) DAC ADDRSIZE REGISTER 
#define DAC_IPNAME1     (AT91_CAST(AT91_REG *) 	0x000000F0) // (DAC_IPNAME1) DAC IPNAME1 REGISTER 
#define DAC_IPNAME2     (AT91_CAST(AT91_REG *) 	0x000000F4) // (DAC_IPNAME2) DAC IPNAME2 REGISTER 
#define DAC_FEATURES    (AT91_CAST(AT91_REG *) 	0x000000F8) // (DAC_FEATURES) DAC FEATURES REGISTER 
#define DAC_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (DAC_VER) DAC VERSION REGISTER

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
//              SOFTWARE API DEFINITION  FOR Digital to Analog Convertor
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_ACC {
	AT91_REG	 ACC_CR; 	// Control Register
	AT91_REG	 ACC_MR; 	// Mode Register
	AT91_REG	 Reserved0[7]; 	// 
	AT91_REG	 ACC_IER; 	// Interrupt Enable Register
	AT91_REG	 ACC_IDR; 	// Interrupt Disable Register
	AT91_REG	 ACC_IMR; 	// Interrupt Mask Register
	AT91_REG	 ACC_ISR; 	// Interrupt Status Register
	AT91_REG	 Reserved1[24]; 	// 
	AT91_REG	 ACC_ACR; 	// Analog Control Register
	AT91_REG	 Reserved2[19]; 	// 
	AT91_REG	 ACC_MODE; 	// Write Protection Mode Register
	AT91_REG	 ACC_STATUS; 	// Write Protection Status
	AT91_REG	 ACC_ADDRSIZE; 	// ACC ADDRSIZE REGISTER 
	AT91_REG	 ACC_IPNAME1; 	// ACC IPNAME1 REGISTER 
	AT91_REG	 ACC_IPNAME2; 	// ACC IPNAME2 REGISTER 
	AT91_REG	 ACC_FEATURES; 	// ACC FEATURES REGISTER 
	AT91_REG	 ACC_VER; 	// ACC VERSION REGISTER
} AT91S_ACC, *AT91PS_ACC;
#else
#define ACC_CR          (AT91_CAST(AT91_REG *) 	0x00000000) // (ACC_CR) Control Register
#define ACC_MR          (AT91_CAST(AT91_REG *) 	0x00000004) // (ACC_MR) Mode Register
#define ACC_IER         (AT91_CAST(AT91_REG *) 	0x00000024) // (ACC_IER) Interrupt Enable Register
#define ACC_IDR         (AT91_CAST(AT91_REG *) 	0x00000028) // (ACC_IDR) Interrupt Disable Register
#define ACC_IMR         (AT91_CAST(AT91_REG *) 	0x0000002C) // (ACC_IMR) Interrupt Mask Register
#define ACC_ISR         (AT91_CAST(AT91_REG *) 	0x00000030) // (ACC_ISR) Interrupt Status Register
#define ACC_ACR         (AT91_CAST(AT91_REG *) 	0x00000094) // (ACC_ACR) Analog Control Register
#define ACC_WPROT_MODE  (AT91_CAST(AT91_REG *) 	0x000000E4) // (ACC_WPROT_MODE) Write Protection Mode Register
#define ACC_WPROT_STATUS (AT91_CAST(AT91_REG *) 	0x000000E8) // (ACC_WPROT_STATUS) Write Protection Status
#define ACC_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000EC) // (ACC_ADDRSIZE) ACC ADDRSIZE REGISTER 
#define ACC_IPNAME1     (AT91_CAST(AT91_REG *) 	0x000000F0) // (ACC_IPNAME1) ACC IPNAME1 REGISTER 
#define ACC_IPNAME2     (AT91_CAST(AT91_REG *) 	0x000000F4) // (ACC_IPNAME2) ACC IPNAME2 REGISTER 
#define ACC_FEATURES    (AT91_CAST(AT91_REG *) 	0x000000F8) // (ACC_FEATURES) ACC FEATURES REGISTER 
#define ACC_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (ACC_VER) ACC VERSION REGISTER

#endif
// -------- ACC_IER : (ACC Offset: 0x24) Data Ready for Conversion Interrupt Enable -------- 
#define AT91C_ACC_DATRDY      (0x1 <<  0) // (ACC) Data Ready for Conversion
// -------- ACC_IDR : (ACC Offset: 0x28) Data Ready for Conversion Interrupt Disable -------- 
// -------- ACC_IMR : (ACC Offset: 0x2c) Data Ready for Conversion Interrupt Mask -------- 
// -------- ACC_ISR : (ACC Offset: 0x30) Status Register -------- 
// -------- ACC_VER : (ACC Offset: 0xfc) ACC VER -------- 
#define AT91C_ACC_VER         (0xF <<  0) // (ACC) ACC VER

// *****************************************************************************
//              SOFTWARE API DEFINITION  FOR Context Based Direct Memory Access Controller Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_HCBDMA {
	AT91_REG	 HCBDMA_CBDSCR; 	// CB DMA Descriptor Base Register
	AT91_REG	 HCBDMA_CBNXTEN; 	// CB DMA Next Descriptor Enable Register
	AT91_REG	 HCBDMA_CBEN; 	// CB DMA Enable Register
	AT91_REG	 HCBDMA_CBDIS; 	// CB DMA Disable Register
	AT91_REG	 HCBDMA_CBSR; 	// CB DMA Status Register
	AT91_REG	 HCBDMA_CBIER; 	// CB DMA Interrupt Enable Register
	AT91_REG	 HCBDMA_CBIDR; 	// CB DMA Interrupt Disable Register
	AT91_REG	 HCBDMA_CBIMR; 	// CB DMA Interrupt mask Register
	AT91_REG	 HCBDMA_CBISR; 	// CB DMA Interrupt Status Register
	AT91_REG	 HCBDMA_CBDLIER; 	// CB DMA Loaded Interrupt Enable Register
	AT91_REG	 HCBDMA_CBDLIDR; 	// CB DMA Loaded Interrupt Disable Register
	AT91_REG	 HCBDMA_CBDLIMR; 	// CB DMA Loaded Interrupt mask Register
	AT91_REG	 HCBDMA_CBDLISR; 	// CB DMA Loaded Interrupt Status Register
	AT91_REG	 HCBDMA_CBCRCCR; 	// CB DMA CRC Control Resgister
	AT91_REG	 HCBDMA_CBCRCMR; 	// CB DMA CRC Mode Resgister
	AT91_REG	 HCBDMA_CBCRCSR; 	// CB DMA CRC Status Resgister
	AT91_REG	 HCBDMA_CBCRCIER; 	// CB DMA CRC Interrupt Enable Resgister
	AT91_REG	 HCBDMA_CBCRCIDR; 	// CB DMA CRC Interrupt Disable Resgister
	AT91_REG	 HCBDMA_CBCRCIMR; 	// CB DMA CRC Interrupt Mask Resgister
	AT91_REG	 HCBDMA_CBCRCISR; 	// CB DMA CRC Interrupt Status Resgister
	AT91_REG	 Reserved0[39]; 	// 
	AT91_REG	 HCBDMA_ADDRSIZE; 	// HCBDMA ADDRSIZE REGISTER 
	AT91_REG	 HCBDMA_IPNAME1; 	// HCBDMA IPNAME1 REGISTER 
	AT91_REG	 HCBDMA_IPNAME2; 	// HCBDMA IPNAME2 REGISTER 
	AT91_REG	 HCBDMA_FEATURES; 	// HCBDMA FEATURES REGISTER 
	AT91_REG	 HCBDMA_VER; 	// HCBDMA VERSION REGISTER
} AT91S_HCBDMA, *AT91PS_HCBDMA;
#else
#define HCBDMA_CBDSCR   (AT91_CAST(AT91_REG *) 	0x00000000) // (HCBDMA_CBDSCR) CB DMA Descriptor Base Register
#define HCBDMA_CBNXTEN  (AT91_CAST(AT91_REG *) 	0x00000004) // (HCBDMA_CBNXTEN) CB DMA Next Descriptor Enable Register
#define HCBDMA_CBEN     (AT91_CAST(AT91_REG *) 	0x00000008) // (HCBDMA_CBEN) CB DMA Enable Register
#define HCBDMA_CBDIS    (AT91_CAST(AT91_REG *) 	0x0000000C) // (HCBDMA_CBDIS) CB DMA Disable Register
#define HCBDMA_CBSR     (AT91_CAST(AT91_REG *) 	0x00000010) // (HCBDMA_CBSR) CB DMA Status Register
#define HCBDMA_CBIER    (AT91_CAST(AT91_REG *) 	0x00000014) // (HCBDMA_CBIER) CB DMA Interrupt Enable Register
#define HCBDMA_CBIDR    (AT91_CAST(AT91_REG *) 	0x00000018) // (HCBDMA_CBIDR) CB DMA Interrupt Disable Register
#define HCBDMA_CBIMR    (AT91_CAST(AT91_REG *) 	0x0000001C) // (HCBDMA_CBIMR) CB DMA Interrupt mask Register
#define HCBDMA_CBISR    (AT91_CAST(AT91_REG *) 	0x00000020) // (HCBDMA_CBISR) CB DMA Interrupt Status Register
#define HCBDMA_CBDLIER  (AT91_CAST(AT91_REG *) 	0x00000024) // (HCBDMA_CBDLIER) CB DMA Loaded Interrupt Enable Register
#define HCBDMA_CBDLIDR  (AT91_CAST(AT91_REG *) 	0x00000028) // (HCBDMA_CBDLIDR) CB DMA Loaded Interrupt Disable Register
#define HCBDMA_CBDLIMR  (AT91_CAST(AT91_REG *) 	0x0000002C) // (HCBDMA_CBDLIMR) CB DMA Loaded Interrupt mask Register
#define HCBDMA_CBDLISR  (AT91_CAST(AT91_REG *) 	0x00000030) // (HCBDMA_CBDLISR) CB DMA Loaded Interrupt Status Register
#define HCBDMA_CBCRCCR  (AT91_CAST(AT91_REG *) 	0x00000034) // (HCBDMA_CBCRCCR) CB DMA CRC Control Resgister
#define HCBDMA_CBCRCMR  (AT91_CAST(AT91_REG *) 	0x00000038) // (HCBDMA_CBCRCMR) CB DMA CRC Mode Resgister
#define HCBDMA_CBCRCSR  (AT91_CAST(AT91_REG *) 	0x0000003C) // (HCBDMA_CBCRCSR) CB DMA CRC Status Resgister
#define HCBDMA_CBCRCIER (AT91_CAST(AT91_REG *) 	0x00000040) // (HCBDMA_CBCRCIER) CB DMA CRC Interrupt Enable Resgister
#define HCBDMA_CBCRCIDR (AT91_CAST(AT91_REG *) 	0x00000044) // (HCBDMA_CBCRCIDR) CB DMA CRC Interrupt Disable Resgister
#define HCBDMA_CBCRCIMR (AT91_CAST(AT91_REG *) 	0x00000048) // (HCBDMA_CBCRCIMR) CB DMA CRC Interrupt Mask Resgister
#define HCBDMA_CBCRCISR (AT91_CAST(AT91_REG *) 	0x0000004C) // (HCBDMA_CBCRCISR) CB DMA CRC Interrupt Status Resgister
#define HCBDMA_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x000000EC) // (HCBDMA_ADDRSIZE) HCBDMA ADDRSIZE REGISTER 
#define HCBDMA_IPNAME1  (AT91_CAST(AT91_REG *) 	0x000000F0) // (HCBDMA_IPNAME1) HCBDMA IPNAME1 REGISTER 
#define HCBDMA_IPNAME2  (AT91_CAST(AT91_REG *) 	0x000000F4) // (HCBDMA_IPNAME2) HCBDMA IPNAME2 REGISTER 
#define HCBDMA_FEATURES (AT91_CAST(AT91_REG *) 	0x000000F8) // (HCBDMA_FEATURES) HCBDMA FEATURES REGISTER 
#define HCBDMA_VER      (AT91_CAST(AT91_REG *) 	0x000000FC) // (HCBDMA_VER) HCBDMA VERSION REGISTER

#endif
// -------- HCBDMA_CBDSCR : (HCBDMA Offset: 0x0) CB DMA Descriptor Base Register -------- 
#define AT91C_HCBDMA_DSCR     (0x0 <<  0) // (HCBDMA) Descriptor Base Address
// -------- HCBDMA_CBNXTEN : (HCBDMA Offset: 0x4) Next Descriptor Enable Register -------- 
#define AT91C_HCBDMA_NXTID0   (0x1 <<  0) // (HCBDMA) Next Descriptor Identifier for the Channel 0
#define AT91C_HCBDMA_NXTID1   (0x1 <<  1) // (HCBDMA) Next Descriptor Identifier for the Channel 1
#define AT91C_HCBDMA_NXTID2   (0x1 <<  2) // (HCBDMA) Next Descriptor Identifier for the Channel 2
#define AT91C_HCBDMA_NXTID3   (0x1 <<  3) // (HCBDMA) Next Descriptor Identifier for the Channel 3
#define AT91C_HCBDMA_NXTID4   (0x1 <<  4) // (HCBDMA) Next Descriptor Identifier for the Channel 4
#define AT91C_HCBDMA_NXTID5   (0x1 <<  5) // (HCBDMA) Next Descriptor Identifier for the Channel 5
#define AT91C_HCBDMA_NXTID6   (0x1 <<  6) // (HCBDMA) Next Descriptor Identifier for the Channel 6
#define AT91C_HCBDMA_NXTID7   (0x1 <<  7) // (HCBDMA) Next Descriptor Identifier for the Channel 7
#define AT91C_HCBDMA_NXTID8   (0x1 <<  8) // (HCBDMA) Next Descriptor Identifier for the Channel 8
#define AT91C_HCBDMA_NXTID9   (0x1 <<  9) // (HCBDMA) Next Descriptor Identifier for the Channel 9
#define AT91C_HCBDMA_NXTID10  (0x1 << 10) // (HCBDMA) Next Descriptor Identifier for the Channel 10
#define AT91C_HCBDMA_NXTID11  (0x1 << 11) // (HCBDMA) Next Descriptor Identifier for the Channel 11
#define AT91C_HCBDMA_NXTID12  (0x1 << 12) // (HCBDMA) Next Descriptor Identifier for the Channel 12
#define AT91C_HCBDMA_NXTID13  (0x1 << 13) // (HCBDMA) Next Descriptor Identifier for the Channel 13
#define AT91C_HCBDMA_NXTID14  (0x1 << 14) // (HCBDMA) Next Descriptor Identifier for the Channel 14
#define AT91C_HCBDMA_NXTID15  (0x1 << 15) // (HCBDMA) Next Descriptor Identifier for the Channel 15
#define AT91C_HCBDMA_NXTID16  (0x1 << 16) // (HCBDMA) Next Descriptor Identifier for the Channel 16
#define AT91C_HCBDMA_NXTID17  (0x1 << 17) // (HCBDMA) Next Descriptor Identifier for the Channel 17
#define AT91C_HCBDMA_NXTID18  (0x1 << 18) // (HCBDMA) Next Descriptor Identifier for the Channel 18
#define AT91C_HCBDMA_NXTID19  (0x1 << 19) // (HCBDMA) Next Descriptor Identifier for the Channel 19
#define AT91C_HCBDMA_NXTID20  (0x1 << 20) // (HCBDMA) Next Descriptor Identifier for the Channel 20
#define AT91C_HCBDMA_NXTID21  (0x1 << 21) // (HCBDMA) Next Descriptor Identifier for the Channel 21
#define AT91C_HCBDMA_NXTID22  (0x1 << 22) // (HCBDMA) Next Descriptor Identifier for the Channel 22
#define AT91C_HCBDMA_NXTID23  (0x1 << 23) // (HCBDMA) Next Descriptor Identifier for the Channel 23
#define AT91C_HCBDMA_NXTID24  (0x1 << 24) // (HCBDMA) Next Descriptor Identifier for the Channel 24
#define AT91C_HCBDMA_NXTID25  (0x1 << 25) // (HCBDMA) Next Descriptor Identifier for the Channel 25
#define AT91C_HCBDMA_NXTID26  (0x1 << 26) // (HCBDMA) Next Descriptor Identifier for the Channel 26
#define AT91C_HCBDMA_NXTID27  (0x1 << 27) // (HCBDMA) Next Descriptor Identifier for the Channel 27
#define AT91C_HCBDMA_NXTID28  (0x1 << 28) // (HCBDMA) Next Descriptor Identifier for the Channel 28
#define AT91C_HCBDMA_NXTID29  (0x1 << 29) // (HCBDMA) Next Descriptor Identifier for the Channel 29
#define AT91C_HCBDMA_NXTID30  (0x1 << 30) // (HCBDMA) Next Descriptor Identifier for the Channel 30
#define AT91C_HCBDMA_NXTID31  (0x1 << 31) // (HCBDMA) Next Descriptor Identifier for the Channel 31
// -------- HCBDMA_CBEN : (HCBDMA Offset: 0x8) CB DMA Enable Register -------- 
#define AT91C_HCBDMA_CBEN0    (0x1 <<  0) // (HCBDMA) Enable for the Channel 0
#define AT91C_HCBDMA_CBEN1    (0x1 <<  1) // (HCBDMA) Enable for the Channel 1
#define AT91C_HCBDMA_CBEN2    (0x1 <<  2) // (HCBDMA) Enable for the Channel 2
#define AT91C_HCBDMA_CBEN3    (0x1 <<  3) // (HCBDMA) Enable for the Channel 3
#define AT91C_HCBDMA_CBEN4    (0x1 <<  4) // (HCBDMA) Enable for the Channel 4
#define AT91C_HCBDMA_CBEN5    (0x1 <<  5) // (HCBDMA) Enable for the Channel 5
#define AT91C_HCBDMA_CBEN6    (0x1 <<  6) // (HCBDMA) Enable for the Channel 6
#define AT91C_HCBDMA_CBEN7    (0x1 <<  7) // (HCBDMA) Enable for the Channel 7
#define AT91C_HCBDMA_CBEN8    (0x1 <<  8) // (HCBDMA) Enable for the Channel 8
#define AT91C_HCBDMA_CBEN9    (0x1 <<  9) // (HCBDMA) Enable for the Channel 9
#define AT91C_HCBDMA_CBEN10   (0x1 << 10) // (HCBDMA) Enable for the Channel 10
#define AT91C_HCBDMA_CBEN11   (0x1 << 11) // (HCBDMA) Enable for the Channel 11
#define AT91C_HCBDMA_CBEN12   (0x1 << 12) // (HCBDMA) Enable for the Channel 12
#define AT91C_HCBDMA_CBEN13   (0x1 << 13) // (HCBDMA) Enable for the Channel 13
#define AT91C_HCBDMA_CBEN14   (0x1 << 14) // (HCBDMA) Enable for the Channel 14
#define AT91C_HCBDMA_CBEN15   (0x1 << 15) // (HCBDMA) Enable for the Channel 15
#define AT91C_HCBDMA_CBEN16   (0x1 << 16) // (HCBDMA) Enable for the Channel 16
#define AT91C_HCBDMA_CBEN17   (0x1 << 17) // (HCBDMA) Enable for the Channel 17
#define AT91C_HCBDMA_CBEN18   (0x1 << 18) // (HCBDMA) Enable for the Channel 18
#define AT91C_HCBDMA_CBEN19   (0x1 << 19) // (HCBDMA) Enable for the Channel 19
#define AT91C_HCBDMA_CBEN20   (0x1 << 20) // (HCBDMA) Enable for the Channel 20
#define AT91C_HCBDMA_CBEN21   (0x1 << 21) // (HCBDMA) Enable for the Channel 21
#define AT91C_HCBDMA_CBEN22   (0x1 << 22) // (HCBDMA) Enable for the Channel 22
#define AT91C_HCBDMA_CBEN23   (0x1 << 23) // (HCBDMA) Enable for the Channel 23
#define AT91C_HCBDMA_CBEN24   (0x1 << 24) // (HCBDMA) Enable for the Channel 24
#define AT91C_HCBDMA_CBEN25   (0x1 << 25) // (HCBDMA) Enable for the Channel 25
#define AT91C_HCBDMA_CBEN26   (0x1 << 26) // (HCBDMA) Enable for the Channel 26
#define AT91C_HCBDMA_CBEN27   (0x1 << 27) // (HCBDMA) Enable for the Channel 27
#define AT91C_HCBDMA_CBEN28   (0x1 << 28) // (HCBDMA) Enable for the Channel 28
#define AT91C_HCBDMA_CBEN29   (0x1 << 29) // (HCBDMA) Enable for the Channel 29
#define AT91C_HCBDMA_CBEN30   (0x1 << 30) // (HCBDMA) Enable for the Channel 30
#define AT91C_HCBDMA_CBEN31   (0x1 << 31) // (HCBDMA) Enable for the Channel 31
// -------- HCBDMA_CBDIS : (HCBDMA Offset: 0xc) CB DMA Disable Register -------- 
#define AT91C_HCBDMA_CBDIS0   (0x1 <<  0) // (HCBDMA) Disable for the Channel 0
#define AT91C_HCBDMA_CBDIS1   (0x1 <<  1) // (HCBDMA) Disable for the Channel 1
#define AT91C_HCBDMA_CBDIS2   (0x1 <<  2) // (HCBDMA) Disable for the Channel 2
#define AT91C_HCBDMA_CBDIS3   (0x1 <<  3) // (HCBDMA) Disable for the Channel 3
#define AT91C_HCBDMA_CBDIS4   (0x1 <<  4) // (HCBDMA) Disable for the Channel 4
#define AT91C_HCBDMA_CBDIS5   (0x1 <<  5) // (HCBDMA) Disable for the Channel 5
#define AT91C_HCBDMA_CBDIS6   (0x1 <<  6) // (HCBDMA) Disable for the Channel 6
#define AT91C_HCBDMA_CBDIS7   (0x1 <<  7) // (HCBDMA) Disable for the Channel 7
#define AT91C_HCBDMA_CBDIS8   (0x1 <<  8) // (HCBDMA) Disable for the Channel 8
#define AT91C_HCBDMA_CBDIS9   (0x1 <<  9) // (HCBDMA) Disable for the Channel 9
#define AT91C_HCBDMA_CBDIS10  (0x1 << 10) // (HCBDMA) Disable for the Channel 10
#define AT91C_HCBDMA_CBDIS11  (0x1 << 11) // (HCBDMA) Disable for the Channel 11
#define AT91C_HCBDMA_CBDIS12  (0x1 << 12) // (HCBDMA) Disable for the Channel 12
#define AT91C_HCBDMA_CBDIS13  (0x1 << 13) // (HCBDMA) Disable for the Channel 13
#define AT91C_HCBDMA_CBDIS14  (0x1 << 14) // (HCBDMA) Disable for the Channel 14
#define AT91C_HCBDMA_CBDIS15  (0x1 << 15) // (HCBDMA) Disable for the Channel 15
#define AT91C_HCBDMA_CBDIS16  (0x1 << 16) // (HCBDMA) Disable for the Channel 16
#define AT91C_HCBDMA_CBDIS17  (0x1 << 17) // (HCBDMA) Disable for the Channel 17
#define AT91C_HCBDMA_CBDIS18  (0x1 << 18) // (HCBDMA) Disable for the Channel 18
#define AT91C_HCBDMA_CBDIS19  (0x1 << 19) // (HCBDMA) Disable for the Channel 19
#define AT91C_HCBDMA_CBDIS20  (0x1 << 20) // (HCBDMA) Disable for the Channel 20
#define AT91C_HCBDMA_CBDIS21  (0x1 << 21) // (HCBDMA) Disable for the Channel 21
#define AT91C_HCBDMA_CBDIS22  (0x1 << 22) // (HCBDMA) Disable for the Channel 22
#define AT91C_HCBDMA_CBDIS23  (0x1 << 23) // (HCBDMA) Disable for the Channel 23
#define AT91C_HCBDMA_CBDIS24  (0x1 << 24) // (HCBDMA) Disable for the Channel 24
#define AT91C_HCBDMA_CBDIS25  (0x1 << 25) // (HCBDMA) Disable for the Channel 25
#define AT91C_HCBDMA_CBDIS26  (0x1 << 26) // (HCBDMA) Disable for the Channel 26
#define AT91C_HCBDMA_CBDIS27  (0x1 << 27) // (HCBDMA) Disable for the Channel 27
#define AT91C_HCBDMA_CBDIS28  (0x1 << 28) // (HCBDMA) Disable for the Channel 28
#define AT91C_HCBDMA_CBDIS29  (0x1 << 29) // (HCBDMA) Disable for the Channel 29
#define AT91C_HCBDMA_CBDIS30  (0x1 << 30) // (HCBDMA) Disable for the Channel 30
#define AT91C_HCBDMA_CBDIS31  (0x1 << 31) // (HCBDMA) Disable for the Channel 31
// -------- HCBDMA_CBSR : (HCBDMA Offset: 0x10) CB DMA Status Register -------- 
#define AT91C_HCBDMA_CBSR0    (0x1 <<  0) // (HCBDMA) Status for the Channel 0
#define AT91C_HCBDMA_CBSR1    (0x1 <<  1) // (HCBDMA) Status for the Channel 1
#define AT91C_HCBDMA_CBSR2    (0x1 <<  2) // (HCBDMA) Status for the Channel 2
#define AT91C_HCBDMA_CBSR3    (0x1 <<  3) // (HCBDMA) Status for the Channel 3
#define AT91C_HCBDMA_CBSR4    (0x1 <<  4) // (HCBDMA) Status for the Channel 4
#define AT91C_HCBDMA_CBSR5    (0x1 <<  5) // (HCBDMA) Status for the Channel 5
#define AT91C_HCBDMA_CBSR6    (0x1 <<  6) // (HCBDMA) Status for the Channel 6
#define AT91C_HCBDMA_CBSR7    (0x1 <<  7) // (HCBDMA) Status for the Channel 7
#define AT91C_HCBDMA_CBSR8    (0x1 <<  8) // (HCBDMA) Status for the Channel 8
#define AT91C_HCBDMA_CBSR9    (0x1 <<  9) // (HCBDMA) Status for the Channel 9
#define AT91C_HCBDMA_CBSR10   (0x1 << 10) // (HCBDMA) Status for the Channel 10
#define AT91C_HCBDMA_CBSR11   (0x1 << 11) // (HCBDMA) Status for the Channel 11
#define AT91C_HCBDMA_CBSR12   (0x1 << 12) // (HCBDMA) Status for the Channel 12
#define AT91C_HCBDMA_CBSR13   (0x1 << 13) // (HCBDMA) Status for the Channel 13
#define AT91C_HCBDMA_CBSR14   (0x1 << 14) // (HCBDMA) Status for the Channel 14
#define AT91C_HCBDMA_CBSR15   (0x1 << 15) // (HCBDMA) Status for the Channel 15
#define AT91C_HCBDMA_CBSR16   (0x1 << 16) // (HCBDMA) Status for the Channel 16
#define AT91C_HCBDMA_CBSR17   (0x1 << 17) // (HCBDMA) Status for the Channel 17
#define AT91C_HCBDMA_CBSR18   (0x1 << 18) // (HCBDMA) Status for the Channel 18
#define AT91C_HCBDMA_CBSR19   (0x1 << 19) // (HCBDMA) Status for the Channel 19
#define AT91C_HCBDMA_CBSR20   (0x1 << 20) // (HCBDMA) Status for the Channel 20
#define AT91C_HCBDMA_CBSR21   (0x1 << 21) // (HCBDMA) Status for the Channel 21
#define AT91C_HCBDMA_CBSR22   (0x1 << 22) // (HCBDMA) Status for the Channel 22
#define AT91C_HCBDMA_CBSR23   (0x1 << 23) // (HCBDMA) Status for the Channel 23
#define AT91C_HCBDMA_CBSR24   (0x1 << 24) // (HCBDMA) Status for the Channel 24
#define AT91C_HCBDMA_CBSR25   (0x1 << 25) // (HCBDMA) Status for the Channel 25
#define AT91C_HCBDMA_CBSR26   (0x1 << 26) // (HCBDMA) Status for the Channel 26
#define AT91C_HCBDMA_CBSR27   (0x1 << 27) // (HCBDMA) Status for the Channel 27
#define AT91C_HCBDMA_CBSR28   (0x1 << 28) // (HCBDMA) Status for the Channel 28
#define AT91C_HCBDMA_CBSR29   (0x1 << 29) // (HCBDMA) Status for the Channel 29
#define AT91C_HCBDMA_CBSR30   (0x1 << 30) // (HCBDMA) Status for the Channel 30
#define AT91C_HCBDMA_CBSR31   (0x1 << 31) // (HCBDMA) Status for the Channel 31
// -------- HCBDMA_CBIER : (HCBDMA Offset: 0x14) CB DMA Interrupt Enable Register -------- 
#define AT91C_HCBDMA_CBIER0   (0x1 <<  0) // (HCBDMA) Interrupt enable for the Channel 0
#define AT91C_HCBDMA_CBIER1   (0x1 <<  1) // (HCBDMA) Interrupt enable for the Channel 1
#define AT91C_HCBDMA_CBIER2   (0x1 <<  2) // (HCBDMA) Interrupt enable for the Channel 2
#define AT91C_HCBDMA_CBIER3   (0x1 <<  3) // (HCBDMA) Interrupt enable for the Channel 3
#define AT91C_HCBDMA_CBIER4   (0x1 <<  4) // (HCBDMA) Interrupt enable for the Channel 4
#define AT91C_HCBDMA_CBIER5   (0x1 <<  5) // (HCBDMA) Interrupt enable for the Channel 5
#define AT91C_HCBDMA_CBIER6   (0x1 <<  6) // (HCBDMA) Interrupt enable for the Channel 6
#define AT91C_HCBDMA_CBIER7   (0x1 <<  7) // (HCBDMA) Interrupt enable for the Channel 7
#define AT91C_HCBDMA_CBIER8   (0x1 <<  8) // (HCBDMA) Interrupt enable for the Channel 8
#define AT91C_HCBDMA_CBIER9   (0x1 <<  9) // (HCBDMA) Interrupt enable for the Channel 9
#define AT91C_HCBDMA_CBIER10  (0x1 << 10) // (HCBDMA) Interrupt enable for the Channel 10
#define AT91C_HCBDMA_CBIER11  (0x1 << 11) // (HCBDMA) Interrupt enable for the Channel 11
#define AT91C_HCBDMA_CBIER12  (0x1 << 12) // (HCBDMA) Interrupt enable for the Channel 12
#define AT91C_HCBDMA_CBIER13  (0x1 << 13) // (HCBDMA) Interrupt enable for the Channel 13
#define AT91C_HCBDMA_CBIER14  (0x1 << 14) // (HCBDMA) Interrupt enable for the Channel 14
#define AT91C_HCBDMA_CBIER15  (0x1 << 15) // (HCBDMA) Interrupt enable for the Channel 15
#define AT91C_HCBDMA_CBIER16  (0x1 << 16) // (HCBDMA) Interrupt enable for the Channel 16
#define AT91C_HCBDMA_CBIER17  (0x1 << 17) // (HCBDMA) Interrupt enable for the Channel 17
#define AT91C_HCBDMA_CBIER18  (0x1 << 18) // (HCBDMA) Interrupt enable for the Channel 18
#define AT91C_HCBDMA_CBIER19  (0x1 << 19) // (HCBDMA) Interrupt enable for the Channel 19
#define AT91C_HCBDMA_CBIER20  (0x1 << 20) // (HCBDMA) Interrupt enable for the Channel 20
#define AT91C_HCBDMA_CBIER21  (0x1 << 21) // (HCBDMA) Interrupt enable for the Channel 21
#define AT91C_HCBDMA_CBIER22  (0x1 << 22) // (HCBDMA) Interrupt enable for the Channel 22
#define AT91C_HCBDMA_CBIER23  (0x1 << 23) // (HCBDMA) Interrupt enable for the Channel 23
#define AT91C_HCBDMA_CBIER24  (0x1 << 24) // (HCBDMA) Interrupt enable for the Channel 24
#define AT91C_HCBDMA_CBIER25  (0x1 << 25) // (HCBDMA) Interrupt enable for the Channel 25
#define AT91C_HCBDMA_CBIER26  (0x1 << 26) // (HCBDMA) Interrupt enable for the Channel 26
#define AT91C_HCBDMA_CBIER27  (0x1 << 27) // (HCBDMA) Interrupt enable for the Channel 27
#define AT91C_HCBDMA_CBIER28  (0x1 << 28) // (HCBDMA) Interrupt enable for the Channel 28
#define AT91C_HCBDMA_CBIER29  (0x1 << 29) // (HCBDMA) Interrupt enable for the Channel 29
#define AT91C_HCBDMA_CBIER30  (0x1 << 30) // (HCBDMA) Interrupt enable for the Channel 30
#define AT91C_HCBDMA_CBIER31  (0x1 << 31) // (HCBDMA) Interrupt enable for the Channel 31
// -------- HCBDMA_CBIDR : (HCBDMA Offset: 0x18) CB DMA Interrupt Disable Register -------- 
#define AT91C_HCBDMA_CBIDR0   (0x1 <<  0) // (HCBDMA) Interrupt disable for the Channel 0
#define AT91C_HCBDMA_CBIDR1   (0x1 <<  1) // (HCBDMA) Interrupt disable for the Channel 1
#define AT91C_HCBDMA_CBIDR2   (0x1 <<  2) // (HCBDMA) Interrupt disable for the Channel 2
#define AT91C_HCBDMA_CBIDR3   (0x1 <<  3) // (HCBDMA) Interrupt disable for the Channel 3
#define AT91C_HCBDMA_CBIDR4   (0x1 <<  4) // (HCBDMA) Interrupt disable for the Channel 4
#define AT91C_HCBDMA_CBIDR5   (0x1 <<  5) // (HCBDMA) Interrupt disable for the Channel 5
#define AT91C_HCBDMA_CBIDR6   (0x1 <<  6) // (HCBDMA) Interrupt disable for the Channel 6
#define AT91C_HCBDMA_CBIDR7   (0x1 <<  7) // (HCBDMA) Interrupt disable for the Channel 7
#define AT91C_HCBDMA_CBIDR8   (0x1 <<  8) // (HCBDMA) Interrupt disable for the Channel 8
#define AT91C_HCBDMA_CBIDR9   (0x1 <<  9) // (HCBDMA) Interrupt disable for the Channel 9
#define AT91C_HCBDMA_CBIDR10  (0x1 << 10) // (HCBDMA) Interrupt disable for the Channel 10
#define AT91C_HCBDMA_CBIDR11  (0x1 << 11) // (HCBDMA) Interrupt disable for the Channel 11
#define AT91C_HCBDMA_CBIDR12  (0x1 << 12) // (HCBDMA) Interrupt disable for the Channel 12
#define AT91C_HCBDMA_CBIDR13  (0x1 << 13) // (HCBDMA) Interrupt disable for the Channel 13
#define AT91C_HCBDMA_CBIDR14  (0x1 << 14) // (HCBDMA) Interrupt disable for the Channel 14
#define AT91C_HCBDMA_CBIDR15  (0x1 << 15) // (HCBDMA) Interrupt disable for the Channel 15
#define AT91C_HCBDMA_CBIDR16  (0x1 << 16) // (HCBDMA) Interrupt disable for the Channel 16
#define AT91C_HCBDMA_CBIDR17  (0x1 << 17) // (HCBDMA) Interrupt disable for the Channel 17
#define AT91C_HCBDMA_CBIDR18  (0x1 << 18) // (HCBDMA) Interrupt disable for the Channel 18
#define AT91C_HCBDMA_CBIDR19  (0x1 << 19) // (HCBDMA) Interrupt disable for the Channel 19
#define AT91C_HCBDMA_CBIDR20  (0x1 << 20) // (HCBDMA) Interrupt disable for the Channel 20
#define AT91C_HCBDMA_CBIDR21  (0x1 << 21) // (HCBDMA) Interrupt disable for the Channel 21
#define AT91C_HCBDMA_CBIDR22  (0x1 << 22) // (HCBDMA) Interrupt disable for the Channel 22
#define AT91C_HCBDMA_CBIDR23  (0x1 << 23) // (HCBDMA) Interrupt disable for the Channel 23
#define AT91C_HCBDMA_CBIDR24  (0x1 << 24) // (HCBDMA) Interrupt disable for the Channel 24
#define AT91C_HCBDMA_CBIDR25  (0x1 << 25) // (HCBDMA) Interrupt disable for the Channel 25
#define AT91C_HCBDMA_CBIDR26  (0x1 << 26) // (HCBDMA) Interrupt disable for the Channel 26
#define AT91C_HCBDMA_CBIDR27  (0x1 << 27) // (HCBDMA) Interrupt disable for the Channel 27
#define AT91C_HCBDMA_CBIDR28  (0x1 << 28) // (HCBDMA) Interrupt disable for the Channel 28
#define AT91C_HCBDMA_CBIDR29  (0x1 << 29) // (HCBDMA) Interrupt disable for the Channel 29
#define AT91C_HCBDMA_CBIDR30  (0x1 << 30) // (HCBDMA) Interrupt disable for the Channel 30
#define AT91C_HCBDMA_CBIDR31  (0x1 << 31) // (HCBDMA) Interrupt disable for the Channel 31
// -------- HCBDMA_CBIMR : (HCBDMA Offset: 0x1c) CB DMA Interrupt Mask Register -------- 
#define AT91C_HCBDMA_CBIMR0   (0x1 <<  0) // (HCBDMA) Interrupt mask for the Channel 0
#define AT91C_HCBDMA_CBIMR1   (0x1 <<  1) // (HCBDMA) Interrupt mask for the Channel 1
#define AT91C_HCBDMA_CBIMR2   (0x1 <<  2) // (HCBDMA) Interrupt mask for the Channel 2
#define AT91C_HCBDMA_CBIMR3   (0x1 <<  3) // (HCBDMA) Interrupt mask for the Channel 3
#define AT91C_HCBDMA_CBIMR4   (0x1 <<  4) // (HCBDMA) Interrupt mask for the Channel 4
#define AT91C_HCBDMA_CBIMR5   (0x1 <<  5) // (HCBDMA) Interrupt mask for the Channel 5
#define AT91C_HCBDMA_CBIMR6   (0x1 <<  6) // (HCBDMA) Interrupt mask for the Channel 6
#define AT91C_HCBDMA_CBIMR7   (0x1 <<  7) // (HCBDMA) Interrupt mask for the Channel 7
#define AT91C_HCBDMA_CBIMR8   (0x1 <<  8) // (HCBDMA) Interrupt mask for the Channel 8
#define AT91C_HCBDMA_CBIMR9   (0x1 <<  9) // (HCBDMA) Interrupt mask for the Channel 9
#define AT91C_HCBDMA_CBIMR10  (0x1 << 10) // (HCBDMA) Interrupt mask for the Channel 10
#define AT91C_HCBDMA_CBIMR11  (0x1 << 11) // (HCBDMA) Interrupt mask for the Channel 11
#define AT91C_HCBDMA_CBIMR12  (0x1 << 12) // (HCBDMA) Interrupt mask for the Channel 12
#define AT91C_HCBDMA_CBIMR13  (0x1 << 13) // (HCBDMA) Interrupt mask for the Channel 13
#define AT91C_HCBDMA_CBIMR14  (0x1 << 14) // (HCBDMA) Interrupt mask for the Channel 14
#define AT91C_HCBDMA_CBIMR15  (0x1 << 15) // (HCBDMA) Interrupt mask for the Channel 15
#define AT91C_HCBDMA_CBIMR16  (0x1 << 16) // (HCBDMA) Interrupt mask for the Channel 16
#define AT91C_HCBDMA_CBIMR17  (0x1 << 17) // (HCBDMA) Interrupt mask for the Channel 17
#define AT91C_HCBDMA_CBIMR18  (0x1 << 18) // (HCBDMA) Interrupt mask for the Channel 18
#define AT91C_HCBDMA_CBIMR19  (0x1 << 19) // (HCBDMA) Interrupt mask for the Channel 19
#define AT91C_HCBDMA_CBIMR20  (0x1 << 20) // (HCBDMA) Interrupt mask for the Channel 20
#define AT91C_HCBDMA_CBIMR21  (0x1 << 21) // (HCBDMA) Interrupt mask for the Channel 21
#define AT91C_HCBDMA_CBIMR22  (0x1 << 22) // (HCBDMA) Interrupt mask for the Channel 22
#define AT91C_HCBDMA_CBIMR23  (0x1 << 23) // (HCBDMA) Interrupt mask for the Channel 23
#define AT91C_HCBDMA_CBIMR24  (0x1 << 24) // (HCBDMA) Interrupt mask for the Channel 24
#define AT91C_HCBDMA_CBIMR25  (0x1 << 25) // (HCBDMA) Interrupt mask for the Channel 25
#define AT91C_HCBDMA_CBIMR26  (0x1 << 26) // (HCBDMA) Interrupt mask for the Channel 26
#define AT91C_HCBDMA_CBIMR27  (0x1 << 27) // (HCBDMA) Interrupt mask for the Channel 27
#define AT91C_HCBDMA_CBIMR28  (0x1 << 28) // (HCBDMA) Interrupt mask for the Channel 28
#define AT91C_HCBDMA_CBIMR29  (0x1 << 29) // (HCBDMA) Interrupt mask for the Channel 29
#define AT91C_HCBDMA_CBIMR30  (0x1 << 30) // (HCBDMA) Interrupt mask for the Channel 30
#define AT91C_HCBDMA_CBIMR31  (0x1 << 31) // (HCBDMA) Interrupt mask for the Channel 31
// -------- HCBDMA_CBISR : (HCBDMA Offset: 0x20) CB DMA Interrupt Satus Register -------- 
#define AT91C_HCBDMA_CBISR0   (0x1 <<  0) // (HCBDMA) Interrupt status for the Channel 0
#define AT91C_HCBDMA_CBISR1   (0x1 <<  1) // (HCBDMA) Interrupt status for the Channel 1
#define AT91C_HCBDMA_CBISR2   (0x1 <<  2) // (HCBDMA) Interrupt status for the Channel 2
#define AT91C_HCBDMA_CBISR3   (0x1 <<  3) // (HCBDMA) Interrupt status for the Channel 3
#define AT91C_HCBDMA_CBISR4   (0x1 <<  4) // (HCBDMA) Interrupt status for the Channel 4
#define AT91C_HCBDMA_CBISR5   (0x1 <<  5) // (HCBDMA) Interrupt status for the Channel 5
#define AT91C_HCBDMA_CBISR6   (0x1 <<  6) // (HCBDMA) Interrupt status for the Channel 6
#define AT91C_HCBDMA_CBISR7   (0x1 <<  7) // (HCBDMA) Interrupt status for the Channel 7
#define AT91C_HCBDMA_CBISR8   (0x1 <<  8) // (HCBDMA) Interrupt status for the Channel 8
#define AT91C_HCBDMA_CBISR9   (0x1 <<  9) // (HCBDMA) Interrupt status for the Channel 9
#define AT91C_HCBDMA_CBISR10  (0x1 << 10) // (HCBDMA) Interrupt status for the Channel 10
#define AT91C_HCBDMA_CBISR11  (0x1 << 11) // (HCBDMA) Interrupt status for the Channel 11
#define AT91C_HCBDMA_CBISR12  (0x1 << 12) // (HCBDMA) Interrupt status for the Channel 12
#define AT91C_HCBDMA_CBISR13  (0x1 << 13) // (HCBDMA) Interrupt status for the Channel 13
#define AT91C_HCBDMA_CBISR14  (0x1 << 14) // (HCBDMA) Interrupt status for the Channel 14
#define AT91C_HCBDMA_CBISR15  (0x1 << 15) // (HCBDMA) Interrupt status for the Channel 15
#define AT91C_HCBDMA_CBISR16  (0x1 << 16) // (HCBDMA) Interrupt status for the Channel 16
#define AT91C_HCBDMA_CBISR17  (0x1 << 17) // (HCBDMA) Interrupt status for the Channel 17
#define AT91C_HCBDMA_CBISR18  (0x1 << 18) // (HCBDMA) Interrupt status for the Channel 18
#define AT91C_HCBDMA_CBISR19  (0x1 << 19) // (HCBDMA) Interrupt status for the Channel 19
#define AT91C_HCBDMA_CBISR20  (0x1 << 20) // (HCBDMA) Interrupt status for the Channel 20
#define AT91C_HCBDMA_CBISR21  (0x1 << 21) // (HCBDMA) Interrupt status for the Channel 21
#define AT91C_HCBDMA_CBISR22  (0x1 << 22) // (HCBDMA) Interrupt status for the Channel 22
#define AT91C_HCBDMA_CBISR23  (0x1 << 23) // (HCBDMA) Interrupt status for the Channel 23
#define AT91C_HCBDMA_CBISR24  (0x1 << 24) // (HCBDMA) Interrupt status for the Channel 24
#define AT91C_HCBDMA_CBISR25  (0x1 << 25) // (HCBDMA) Interrupt status for the Channel 25
#define AT91C_HCBDMA_CBISR26  (0x1 << 26) // (HCBDMA) Interrupt status for the Channel 26
#define AT91C_HCBDMA_CBISR27  (0x1 << 27) // (HCBDMA) Interrupt status for the Channel 27
#define AT91C_HCBDMA_CBISR28  (0x1 << 28) // (HCBDMA) Interrupt status for the Channel 28
#define AT91C_HCBDMA_CBISR29  (0x1 << 29) // (HCBDMA) Interrupt status for the Channel 29
#define AT91C_HCBDMA_CBISR30  (0x1 << 30) // (HCBDMA) Interrupt status for the Channel 30
#define AT91C_HCBDMA_CBISR31  (0x1 << 31) // (HCBDMA) Interrupt status for the Channel 31
// -------- HCBDMA_CBDLIER : (HCBDMA Offset: 0x24) CB DMA Loaded Interrupt Enable Register -------- 
#define AT91C_HCBDMA_CBDLIER0 (0x1 <<  0) // (HCBDMA) Interrupt enable for the Channel 0
#define AT91C_HCBDMA_CBDLIER1 (0x1 <<  1) // (HCBDMA) Interrupt enable for the Channel 1
#define AT91C_HCBDMA_CBDLIER2 (0x1 <<  2) // (HCBDMA) Interrupt enable for the Channel 2
#define AT91C_HCBDMA_CBDLIER3 (0x1 <<  3) // (HCBDMA) Interrupt enable for the Channel 3
#define AT91C_HCBDMA_CBDLIER4 (0x1 <<  4) // (HCBDMA) Interrupt enable for the Channel 4
#define AT91C_HCBDMA_CBDLIER5 (0x1 <<  5) // (HCBDMA) Interrupt enable for the Channel 5
#define AT91C_HCBDMA_CBDLIER6 (0x1 <<  6) // (HCBDMA) Interrupt enable for the Channel 6
#define AT91C_HCBDMA_CBDLIER7 (0x1 <<  7) // (HCBDMA) Interrupt enable for the Channel 7
#define AT91C_HCBDMA_CBDLIER8 (0x1 <<  8) // (HCBDMA) Interrupt enable for the Channel 8
#define AT91C_HCBDMA_CBDLIER9 (0x1 <<  9) // (HCBDMA) Interrupt enable for the Channel 9
#define AT91C_HCBDMA_CBDLIER10 (0x1 << 10) // (HCBDMA) Interrupt enable for the Channel 10
#define AT91C_HCBDMA_CBDLIER11 (0x1 << 11) // (HCBDMA) Interrupt enable for the Channel 11
#define AT91C_HCBDMA_CBDLIER12 (0x1 << 12) // (HCBDMA) Interrupt enable for the Channel 12
#define AT91C_HCBDMA_CBDLIER13 (0x1 << 13) // (HCBDMA) Interrupt enable for the Channel 13
#define AT91C_HCBDMA_CBDLIER14 (0x1 << 14) // (HCBDMA) Interrupt enable for the Channel 14
#define AT91C_HCBDMA_CBDLIER15 (0x1 << 15) // (HCBDMA) Interrupt enable for the Channel 15
#define AT91C_HCBDMA_CBDLIER16 (0x1 << 16) // (HCBDMA) Interrupt enable for the Channel 16
#define AT91C_HCBDMA_CBDLIER17 (0x1 << 17) // (HCBDMA) Interrupt enable for the Channel 17
#define AT91C_HCBDMA_CBDLIER18 (0x1 << 18) // (HCBDMA) Interrupt enable for the Channel 18
#define AT91C_HCBDMA_CBDLIER19 (0x1 << 19) // (HCBDMA) Interrupt enable for the Channel 19
#define AT91C_HCBDMA_CBDLIER20 (0x1 << 20) // (HCBDMA) Interrupt enable for the Channel 20
#define AT91C_HCBDMA_CBDLIER21 (0x1 << 21) // (HCBDMA) Interrupt enable for the Channel 21
#define AT91C_HCBDMA_CBDLIER22 (0x1 << 22) // (HCBDMA) Interrupt enable for the Channel 22
#define AT91C_HCBDMA_CBDLIER23 (0x1 << 23) // (HCBDMA) Interrupt enable for the Channel 23
#define AT91C_HCBDMA_CBDLIER24 (0x1 << 24) // (HCBDMA) Interrupt enable for the Channel 24
#define AT91C_HCBDMA_CBDLIER25 (0x1 << 25) // (HCBDMA) Interrupt enable for the Channel 25
#define AT91C_HCBDMA_CBDLIER26 (0x1 << 26) // (HCBDMA) Interrupt enable for the Channel 26
#define AT91C_HCBDMA_CBDLIER27 (0x1 << 27) // (HCBDMA) Interrupt enable for the Channel 27
#define AT91C_HCBDMA_CBDLIER28 (0x1 << 28) // (HCBDMA) Interrupt enable for the Channel 28
#define AT91C_HCBDMA_CBDLIER29 (0x1 << 29) // (HCBDMA) Interrupt enable for the Channel 29
#define AT91C_HCBDMA_CBDLIER30 (0x1 << 30) // (HCBDMA) Interrupt enable for the Channel 30
#define AT91C_HCBDMA_CBDLIER31 (0x1 << 31) // (HCBDMA) Interrupt enable for the Channel 31
// -------- HCBDMA_CBDLIDR : (HCBDMA Offset: 0x28) CB DMA Interrupt Disable Register -------- 
#define AT91C_HCBDMA_CBDLIDR0 (0x1 <<  0) // (HCBDMA) Interrupt disable for the Channel 0
#define AT91C_HCBDMA_CBDLIDR1 (0x1 <<  1) // (HCBDMA) Interrupt disable for the Channel 1
#define AT91C_HCBDMA_CBDLIDR2 (0x1 <<  2) // (HCBDMA) Interrupt disable for the Channel 2
#define AT91C_HCBDMA_CBDLIDR3 (0x1 <<  3) // (HCBDMA) Interrupt disable for the Channel 3
#define AT91C_HCBDMA_CBDLIDR4 (0x1 <<  4) // (HCBDMA) Interrupt disable for the Channel 4
#define AT91C_HCBDMA_CBDLIDR5 (0x1 <<  5) // (HCBDMA) Interrupt disable for the Channel 5
#define AT91C_HCBDMA_CBDLIDR6 (0x1 <<  6) // (HCBDMA) Interrupt disable for the Channel 6
#define AT91C_HCBDMA_CBDLIDR7 (0x1 <<  7) // (HCBDMA) Interrupt disable for the Channel 7
#define AT91C_HCBDMA_CBDLIDR8 (0x1 <<  8) // (HCBDMA) Interrupt disable for the Channel 8
#define AT91C_HCBDMA_CBDLIDR9 (0x1 <<  9) // (HCBDMA) Interrupt disable for the Channel 9
#define AT91C_HCBDMA_CBDLIDR10 (0x1 << 10) // (HCBDMA) Interrupt disable for the Channel 10
#define AT91C_HCBDMA_CBDLIDR11 (0x1 << 11) // (HCBDMA) Interrupt disable for the Channel 11
#define AT91C_HCBDMA_CBDLIDR12 (0x1 << 12) // (HCBDMA) Interrupt disable for the Channel 12
#define AT91C_HCBDMA_CBDLIDR13 (0x1 << 13) // (HCBDMA) Interrupt disable for the Channel 13
#define AT91C_HCBDMA_CBDLIDR14 (0x1 << 14) // (HCBDMA) Interrupt disable for the Channel 14
#define AT91C_HCBDMA_CBDLIDR15 (0x1 << 15) // (HCBDMA) Interrupt disable for the Channel 15
#define AT91C_HCBDMA_CBDLIDR16 (0x1 << 16) // (HCBDMA) Interrupt disable for the Channel 16
#define AT91C_HCBDMA_CBDLIDR17 (0x1 << 17) // (HCBDMA) Interrupt disable for the Channel 17
#define AT91C_HCBDMA_CBDLIDR18 (0x1 << 18) // (HCBDMA) Interrupt disable for the Channel 18
#define AT91C_HCBDMA_CBDLIDR19 (0x1 << 19) // (HCBDMA) Interrupt disable for the Channel 19
#define AT91C_HCBDMA_CBDLIDR20 (0x1 << 20) // (HCBDMA) Interrupt disable for the Channel 20
#define AT91C_HCBDMA_CBDLIDR21 (0x1 << 21) // (HCBDMA) Interrupt disable for the Channel 21
#define AT91C_HCBDMA_CBDLIDR22 (0x1 << 22) // (HCBDMA) Interrupt disable for the Channel 22
#define AT91C_HCBDMA_CBDLIDR23 (0x1 << 23) // (HCBDMA) Interrupt disable for the Channel 23
#define AT91C_HCBDMA_CBDLIDR24 (0x1 << 24) // (HCBDMA) Interrupt disable for the Channel 24
#define AT91C_HCBDMA_CBDLIDR25 (0x1 << 25) // (HCBDMA) Interrupt disable for the Channel 25
#define AT91C_HCBDMA_CBDLIDR26 (0x1 << 26) // (HCBDMA) Interrupt disable for the Channel 26
#define AT91C_HCBDMA_CBDLIDR27 (0x1 << 27) // (HCBDMA) Interrupt disable for the Channel 27
#define AT91C_HCBDMA_CBDLIDR28 (0x1 << 28) // (HCBDMA) Interrupt disable for the Channel 28
#define AT91C_HCBDMA_CBDLIDR29 (0x1 << 29) // (HCBDMA) Interrupt disable for the Channel 29
#define AT91C_HCBDMA_CBDLIDR30 (0x1 << 30) // (HCBDMA) Interrupt disable for the Channel 30
#define AT91C_HCBDMA_CBDLIDR31 (0x1 << 31) // (HCBDMA) Interrupt disable for the Channel 31
// -------- HCBDMA_CBDLIMR : (HCBDMA Offset: 0x2c) CB DMA Interrupt Mask Register -------- 
#define AT91C_HCBDMA_CBDLIMR0 (0x1 <<  0) // (HCBDMA) Interrupt mask for the Channel 0
#define AT91C_HCBDMA_CBDLIMR1 (0x1 <<  1) // (HCBDMA) Interrupt mask for the Channel 1
#define AT91C_HCBDMA_CBDLIMR2 (0x1 <<  2) // (HCBDMA) Interrupt mask for the Channel 2
#define AT91C_HCBDMA_CBDLIMR3 (0x1 <<  3) // (HCBDMA) Interrupt mask for the Channel 3
#define AT91C_HCBDMA_CBDLIMR4 (0x1 <<  4) // (HCBDMA) Interrupt mask for the Channel 4
#define AT91C_HCBDMA_CBDLIMR5 (0x1 <<  5) // (HCBDMA) Interrupt mask for the Channel 5
#define AT91C_HCBDMA_CBDLIMR6 (0x1 <<  6) // (HCBDMA) Interrupt mask for the Channel 6
#define AT91C_HCBDMA_CBDLIMR7 (0x1 <<  7) // (HCBDMA) Interrupt mask for the Channel 7
#define AT91C_HCBDMA_CBDLIMR8 (0x1 <<  8) // (HCBDMA) Interrupt mask for the Channel 8
#define AT91C_HCBDMA_CBDLIMR9 (0x1 <<  9) // (HCBDMA) Interrupt mask for the Channel 9
#define AT91C_HCBDMA_CBDLIMR10 (0x1 << 10) // (HCBDMA) Interrupt mask for the Channel 10
#define AT91C_HCBDMA_CBDLIMR11 (0x1 << 11) // (HCBDMA) Interrupt mask for the Channel 11
#define AT91C_HCBDMA_CBDLIMR12 (0x1 << 12) // (HCBDMA) Interrupt mask for the Channel 12
#define AT91C_HCBDMA_CBDLIMR13 (0x1 << 13) // (HCBDMA) Interrupt mask for the Channel 13
#define AT91C_HCBDMA_CBDLIMR14 (0x1 << 14) // (HCBDMA) Interrupt mask for the Channel 14
#define AT91C_HCBDMA_CBDLIMR15 (0x1 << 15) // (HCBDMA) Interrupt mask for the Channel 15
#define AT91C_HCBDMA_CBDLIMR16 (0x1 << 16) // (HCBDMA) Interrupt mask for the Channel 16
#define AT91C_HCBDMA_CBDLIMR17 (0x1 << 17) // (HCBDMA) Interrupt mask for the Channel 17
#define AT91C_HCBDMA_CBDLIMR18 (0x1 << 18) // (HCBDMA) Interrupt mask for the Channel 18
#define AT91C_HCBDMA_CBDLIMR19 (0x1 << 19) // (HCBDMA) Interrupt mask for the Channel 19
#define AT91C_HCBDMA_CBDLIMR20 (0x1 << 20) // (HCBDMA) Interrupt mask for the Channel 20
#define AT91C_HCBDMA_CBDLIMR21 (0x1 << 21) // (HCBDMA) Interrupt mask for the Channel 21
#define AT91C_HCBDMA_CBDLIMR22 (0x1 << 22) // (HCBDMA) Interrupt mask for the Channel 22
#define AT91C_HCBDMA_CBDLIMR23 (0x1 << 23) // (HCBDMA) Interrupt mask for the Channel 23
#define AT91C_HCBDMA_CBDLIMR24 (0x1 << 24) // (HCBDMA) Interrupt mask for the Channel 24
#define AT91C_HCBDMA_CBDLIMR25 (0x1 << 25) // (HCBDMA) Interrupt mask for the Channel 25
#define AT91C_HCBDMA_CBDLIMR26 (0x1 << 26) // (HCBDMA) Interrupt mask for the Channel 26
#define AT91C_HCBDMA_CBDLIMR27 (0x1 << 27) // (HCBDMA) Interrupt mask for the Channel 27
#define AT91C_HCBDMA_CBDLIMR28 (0x1 << 28) // (HCBDMA) Interrupt mask for the Channel 28
#define AT91C_HCBDMA_CBDLIMR29 (0x1 << 29) // (HCBDMA) Interrupt mask for the Channel 29
#define AT91C_HCBDMA_CBDLIMR30 (0x1 << 30) // (HCBDMA) Interrupt mask for the Channel 30
#define AT91C_HCBDMA_CBDLIMR31 (0x1 << 31) // (HCBDMA) Interrupt mask for the Channel 31
// -------- HCBDMA_CBDLISR : (HCBDMA Offset: 0x30) CB DMA Interrupt Satus Register -------- 
#define AT91C_HCBDMA_CBDLISR0 (0x1 <<  0) // (HCBDMA) Interrupt status for the Channel 0
#define AT91C_HCBDMA_CBDLISR1 (0x1 <<  1) // (HCBDMA) Interrupt status for the Channel 1
#define AT91C_HCBDMA_CBDLISR2 (0x1 <<  2) // (HCBDMA) Interrupt status for the Channel 2
#define AT91C_HCBDMA_CBDLISR3 (0x1 <<  3) // (HCBDMA) Interrupt status for the Channel 3
#define AT91C_HCBDMA_CBDLISR4 (0x1 <<  4) // (HCBDMA) Interrupt status for the Channel 4
#define AT91C_HCBDMA_CBDLISR5 (0x1 <<  5) // (HCBDMA) Interrupt status for the Channel 5
#define AT91C_HCBDMA_CBDLISR6 (0x1 <<  6) // (HCBDMA) Interrupt status for the Channel 6
#define AT91C_HCBDMA_CBDLISR7 (0x1 <<  7) // (HCBDMA) Interrupt status for the Channel 7
#define AT91C_HCBDMA_CBDLISR8 (0x1 <<  8) // (HCBDMA) Interrupt status for the Channel 8
#define AT91C_HCBDMA_CBDLISR9 (0x1 <<  9) // (HCBDMA) Interrupt status for the Channel 9
#define AT91C_HCBDMA_CBDLISR10 (0x1 << 10) // (HCBDMA) Interrupt status for the Channel 10
#define AT91C_HCBDMA_CBDLISR11 (0x1 << 11) // (HCBDMA) Interrupt status for the Channel 11
#define AT91C_HCBDMA_CBDLISR12 (0x1 << 12) // (HCBDMA) Interrupt status for the Channel 12
#define AT91C_HCBDMA_CBDLISR13 (0x1 << 13) // (HCBDMA) Interrupt status for the Channel 13
#define AT91C_HCBDMA_CBDLISR14 (0x1 << 14) // (HCBDMA) Interrupt status for the Channel 14
#define AT91C_HCBDMA_CBDLISR15 (0x1 << 15) // (HCBDMA) Interrupt status for the Channel 15
#define AT91C_HCBDMA_CBDLISR16 (0x1 << 16) // (HCBDMA) Interrupt status for the Channel 16
#define AT91C_HCBDMA_CBDLISR17 (0x1 << 17) // (HCBDMA) Interrupt status for the Channel 17
#define AT91C_HCBDMA_CBDLISR18 (0x1 << 18) // (HCBDMA) Interrupt status for the Channel 18
#define AT91C_HCBDMA_CBDLISR19 (0x1 << 19) // (HCBDMA) Interrupt status for the Channel 19
#define AT91C_HCBDMA_CBDLISR20 (0x1 << 20) // (HCBDMA) Interrupt status for the Channel 20
#define AT91C_HCBDMA_CBDLISR21 (0x1 << 21) // (HCBDMA) Interrupt status for the Channel 21
#define AT91C_HCBDMA_CBDLISR22 (0x1 << 22) // (HCBDMA) Interrupt status for the Channel 22
#define AT91C_HCBDMA_CBDLISR23 (0x1 << 23) // (HCBDMA) Interrupt status for the Channel 23
#define AT91C_HCBDMA_CBDLISR24 (0x1 << 24) // (HCBDMA) Interrupt status for the Channel 24
#define AT91C_HCBDMA_CBDLISR25 (0x1 << 25) // (HCBDMA) Interrupt status for the Channel 25
#define AT91C_HCBDMA_CBDLISR26 (0x1 << 26) // (HCBDMA) Interrupt status for the Channel 26
#define AT91C_HCBDMA_CBDLISR27 (0x1 << 27) // (HCBDMA) Interrupt status for the Channel 27
#define AT91C_HCBDMA_CBDLISR28 (0x1 << 28) // (HCBDMA) Interrupt status for the Channel 28
#define AT91C_HCBDMA_CBDLISR29 (0x1 << 29) // (HCBDMA) Interrupt status for the Channel 29
#define AT91C_HCBDMA_CBDLISR30 (0x1 << 30) // (HCBDMA) Interrupt status for the Channel 30
#define AT91C_HCBDMA_CBDLISR31 (0x1 << 31) // (HCBDMA) Interrupt status for the Channel 31
// -------- HCBDMA_CBCRCCR : (HCBDMA Offset: 0x34) CB DMA CRC Control Resgister -------- 
#define AT91C_CRC_START       (0x1 <<  0) // (HCBDMA) CRC compuration initialization
// -------- HCBDMA_CBCRCMR : (HCBDMA Offset: 0x38) CB DMA CRC Mode Resgister -------- 
#define AT91C_CRC_ENABLE      (0x1 <<  0) // (HCBDMA) CRC Enable
#define AT91C_CRC_COMPARE     (0x1 <<  1) // (HCBDMA) CRC Compare
#define AT91C_CRC_PTYPE       (0x3 <<  2) // (HCBDMA) Primitive polynomial type
#define 	AT91C_CRC_PTYPE_CCIT802_3            (0x0 <<  2) // (HCBDMA) 
#define 	AT91C_CRC_PTYPE_CASTAGNOLI           (0x1 <<  2) // (HCBDMA) 
#define 	AT91C_CRC_PTYPE_CCIT_16              (0x2 <<  2) // (HCBDMA) 
#define AT91C_CRC_DIVIDER     (0xF <<  4) // (HCBDMA) Request Divider
#define AT91C_CRC_ID          (0x1F <<  8) // (HCBDMA) CRC channel Identifier
#define 	AT91C_CRC_ID_CHANNEL_0            (0x0 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_1            (0x1 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_2            (0x2 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_3            (0x3 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_4            (0x4 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_5            (0x5 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_6            (0x6 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_7            (0x7 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_8            (0x8 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_9            (0x9 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_10           (0xA <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_11           (0xB <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_12           (0xC <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_13           (0xD <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_14           (0xE <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_15           (0xF <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_16           (0x10 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_17           (0x11 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_18           (0x12 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_19           (0x13 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_20           (0x14 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_21           (0x15 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_22           (0x16 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_23           (0x17 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_24           (0x18 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_25           (0x19 <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_26           (0x1A <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_27           (0x1B <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_28           (0x1C <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_29           (0x1D <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_30           (0x1E <<  8) // (HCBDMA) 
#define 	AT91C_CRC_ID_CHANNEL_31           (0x1F <<  8) // (HCBDMA) 
// -------- HCBDMA_CBCRCSR : (HCBDMA Offset: 0x3c) CB DMA CRC Status Resgister -------- 
#define AT91C_HCBDMA_CRCSR    (0x0 <<  0) // (HCBDMA) CRC Status Resgister
// -------- HCBDMA_CBCRCIER : (HCBDMA Offset: 0x40) CB DMA CRC Interrupt Enable Resgister -------- 
#define AT91C_CRC_ERRIER      (0x1 <<  0) // (HCBDMA) CRC Error Interrupt Enable
// -------- HCBDMA_CBCRCIDR : (HCBDMA Offset: 0x44) CB DMA CRC Interrupt Enable Resgister -------- 
#define AT91C_CRC_ERRIDR      (0x1 <<  0) // (HCBDMA) CRC Error Interrupt Disable
// -------- HCBDMA_CBCRCIMR : (HCBDMA Offset: 0x48) CB DMA CRC Interrupt Mask Resgister -------- 
#define AT91C_CRC_ERRIMR      (0x1 <<  0) // (HCBDMA) CRC Error Interrupt Mask
// -------- HCBDMA_CBCRCISR : (HCBDMA Offset: 0x4c) CB DMA CRC Interrupt Status Resgister -------- 
#define AT91C_CRC_ERRISR      (0x1 <<  0) // (HCBDMA) CRC Error Interrupt Status

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
#define AT91C_US_RSTRX        (0x1 <<  2) // (USART) Reset Receiver
#define AT91C_US_RSTTX        (0x1 <<  3) // (USART) Reset Transmitter
#define AT91C_US_RXEN         (0x1 <<  4) // (USART) Receiver Enable
#define AT91C_US_RXDIS        (0x1 <<  5) // (USART) Receiver Disable
#define AT91C_US_TXEN         (0x1 <<  6) // (USART) Transmitter Enable
#define AT91C_US_TXDIS        (0x1 <<  7) // (USART) Transmitter Disable
#define AT91C_US_RSTSTA       (0x1 <<  8) // (USART) Reset Status Bits
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
#define AT91C_US_PAR          (0x7 <<  9) // (USART) Parity type
#define 	AT91C_US_PAR_EVEN                 (0x0 <<  9) // (USART) Even Parity
#define 	AT91C_US_PAR_ODD                  (0x1 <<  9) // (USART) Odd Parity
#define 	AT91C_US_PAR_SPACE                (0x2 <<  9) // (USART) Parity forced to 0 (Space)
#define 	AT91C_US_PAR_MARK                 (0x3 <<  9) // (USART) Parity forced to 1 (Mark)
#define 	AT91C_US_PAR_NONE                 (0x4 <<  9) // (USART) No Parity
#define 	AT91C_US_PAR_MULTI_DROP           (0x6 <<  9) // (USART) Multi-drop mode
#define AT91C_US_NBSTOP       (0x3 << 12) // (USART) Number of Stop bits
#define 	AT91C_US_NBSTOP_1_BIT                (0x0 << 12) // (USART) 1 stop bit
#define 	AT91C_US_NBSTOP_15_BIT               (0x1 << 12) // (USART) Asynchronous (SYNC=0) 2 stop bits Synchronous (SYNC=1) 2 stop bits
#define 	AT91C_US_NBSTOP_2_BIT                (0x2 << 12) // (USART) 2 stop bits
#define AT91C_US_CHMODE       (0x3 << 14) // (USART) Channel Mode
#define 	AT91C_US_CHMODE_NORMAL               (0x0 << 14) // (USART) Normal Mode: The USART channel operates as an RX/TX USART.
#define 	AT91C_US_CHMODE_AUTO                 (0x1 << 14) // (USART) Automatic Echo: Receiver Data Input is connected to the TXD pin.
#define 	AT91C_US_CHMODE_LOCAL                (0x2 << 14) // (USART) Local Loopback: Transmitter Output Signal is connected to Receiver Input Signal.
#define 	AT91C_US_CHMODE_REMOTE               (0x3 << 14) // (USART) Remote Loopback: RXD pin is internally connected to TXD pin.
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
#define AT91C_US_RXRDY        (0x1 <<  0) // (USART) RXRDY Interrupt
#define AT91C_US_TXRDY        (0x1 <<  1) // (USART) TXRDY Interrupt
#define AT91C_US_RXBRK        (0x1 <<  2) // (USART) Break Received/End of Break
#define AT91C_US_ENDRX        (0x1 <<  3) // (USART) End of Receive Transfer Interrupt
#define AT91C_US_ENDTX        (0x1 <<  4) // (USART) End of Transmit Interrupt
#define AT91C_US_OVRE         (0x1 <<  5) // (USART) Overrun Interrupt
#define AT91C_US_FRAME        (0x1 <<  6) // (USART) Framing Error Interrupt
#define AT91C_US_PARE         (0x1 <<  7) // (USART) Parity Error Interrupt
#define AT91C_US_TIMEOUT      (0x1 <<  8) // (USART) Receiver Time-out
#define AT91C_US_TXEMPTY      (0x1 <<  9) // (USART) TXEMPTY Interrupt
#define AT91C_US_ITERATION    (0x1 << 10) // (USART) Max number of Repetitions Reached
#define AT91C_US_TXBUFE       (0x1 << 11) // (USART) TXBUFE Interrupt
#define AT91C_US_RXBUFF       (0x1 << 12) // (USART) RXBUFF Interrupt
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
	AT91_REG	 Reserved3[40]; 	// 
	AT91_REG	 SSC_ADDRSIZE; 	// SSC ADDRSIZE REGISTER 
	AT91_REG	 SSC_NAME; 	// SSC NAME REGISTER 
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
#define SSC_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000F0) // (SSC_ADDRSIZE) SSC ADDRSIZE REGISTER 
#define SSC_NAME        (AT91_CAST(AT91_REG *) 	0x000000F4) // (SSC_NAME) SSC NAME REGISTER 
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
	AT91_REG	 Reserved1[5]; 	// 
	AT91_REG	 PWMC_STEP; 	// PWM Stepper Config Register
	AT91_REG	 Reserved2[12]; 	// 
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
	AT91_REG	 Reserved3[2]; 	// 
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
	AT91_REG	 Reserved4[20]; 	// 
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
#define PWMC_STEP       (AT91_CAST(AT91_REG *) 	0x000000B0) // (PWMC_STEP) PWM Stepper Config Register
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
	AT91_REG	 Reserved1[43]; 	// 
	AT91_REG	 SPI_ADDRSIZE; 	// SPI ADDRSIZE REGISTER 
	AT91_REG	 SPI_IPNAME1; 	// SPI IPNAME1 REGISTER 
	AT91_REG	 SPI_IPNAME2; 	// SPI IPNAME2 REGISTER 
	AT91_REG	 SPI_FEATURES; 	// SPI FEATURES REGISTER 
	AT91_REG	 SPI_VER; 	// Version Register
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
#define SPI_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000EC) // (SPI_ADDRSIZE) SPI ADDRSIZE REGISTER 
#define SPI_IPNAME1     (AT91_CAST(AT91_REG *) 	0x000000F0) // (SPI_IPNAME1) SPI IPNAME1 REGISTER 
#define SPI_IPNAME2     (AT91_CAST(AT91_REG *) 	0x000000F4) // (SPI_IPNAME2) SPI IPNAME2 REGISTER 
#define SPI_FEATURES    (AT91_CAST(AT91_REG *) 	0x000000F8) // (SPI_FEATURES) SPI FEATURES REGISTER 
#define SPI_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (SPI_VER) Version Register

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
#define AT91C_SPI_CSNAAT      (0x1 <<  2) // (SPI) Chip Select Not Active After Transfer (Ignored if CSAAT = 1)
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
//              SOFTWARE API DEFINITION  FOR USB Device Interface
// *****************************************************************************
#ifndef __ASSEMBLY__
typedef struct _AT91S_UDP {
	AT91_REG	 UDP_NUM; 	// Frame Number Register
	AT91_REG	 UDP_GLBSTATE; 	// Global State Register
	AT91_REG	 UDP_FADDR; 	// Function Address Register
	AT91_REG	 Reserved0[1]; 	// 
	AT91_REG	 UDP_IER; 	// Interrupt Enable Register
	AT91_REG	 UDP_IDR; 	// Interrupt Disable Register
	AT91_REG	 UDP_IMR; 	// Interrupt Mask Register
	AT91_REG	 UDP_ISR; 	// Interrupt Status Register
	AT91_REG	 UDP_ICR; 	// Interrupt Clear Register
	AT91_REG	 Reserved1[1]; 	// 
	AT91_REG	 UDP_RSTEP; 	// Reset Endpoint Register
	AT91_REG	 Reserved2[1]; 	// 
	AT91_REG	 UDP_CSR[8]; 	// Endpoint Control and Status Register
	AT91_REG	 UDP_FDR[8]; 	// Endpoint FIFO Data Register
	AT91_REG	 Reserved3[1]; 	// 
	AT91_REG	 UDP_TXVC; 	// Transceiver Control Register
	AT91_REG	 Reserved4[29]; 	// 
	AT91_REG	 UDP_ADDRSIZE; 	// UDP ADDRSIZE REGISTER 
	AT91_REG	 UDP_IPNAME1; 	// UDP IPNAME1 REGISTER 
	AT91_REG	 UDP_IPNAME2; 	// UDP IPNAME2 REGISTER 
	AT91_REG	 UDP_FEATURES; 	// UDP FEATURES REGISTER 
	AT91_REG	 UDP_VER; 	// UDP VERSION REGISTER
} AT91S_UDP, *AT91PS_UDP;
#else
#define UDP_FRM_NUM     (AT91_CAST(AT91_REG *) 	0x00000000) // (UDP_FRM_NUM) Frame Number Register
#define UDP_GLBSTATE    (AT91_CAST(AT91_REG *) 	0x00000004) // (UDP_GLBSTATE) Global State Register
#define UDP_FADDR       (AT91_CAST(AT91_REG *) 	0x00000008) // (UDP_FADDR) Function Address Register
#define UDP_IER         (AT91_CAST(AT91_REG *) 	0x00000010) // (UDP_IER) Interrupt Enable Register
#define UDP_IDR         (AT91_CAST(AT91_REG *) 	0x00000014) // (UDP_IDR) Interrupt Disable Register
#define UDP_IMR         (AT91_CAST(AT91_REG *) 	0x00000018) // (UDP_IMR) Interrupt Mask Register
#define UDP_ISR         (AT91_CAST(AT91_REG *) 	0x0000001C) // (UDP_ISR) Interrupt Status Register
#define UDP_ICR         (AT91_CAST(AT91_REG *) 	0x00000020) // (UDP_ICR) Interrupt Clear Register
#define UDP_RSTEP       (AT91_CAST(AT91_REG *) 	0x00000028) // (UDP_RSTEP) Reset Endpoint Register
#define UDP_CSR         (AT91_CAST(AT91_REG *) 	0x00000030) // (UDP_CSR) Endpoint Control and Status Register
#define UDP_FDR         (AT91_CAST(AT91_REG *) 	0x00000050) // (UDP_FDR) Endpoint FIFO Data Register
#define UDP_TXVC        (AT91_CAST(AT91_REG *) 	0x00000074) // (UDP_TXVC) Transceiver Control Register
#define UDP_ADDRSIZE    (AT91_CAST(AT91_REG *) 	0x000000EC) // (UDP_ADDRSIZE) UDP ADDRSIZE REGISTER 
#define UDP_IPNAME1     (AT91_CAST(AT91_REG *) 	0x000000F0) // (UDP_IPNAME1) UDP IPNAME1 REGISTER 
#define UDP_IPNAME2     (AT91_CAST(AT91_REG *) 	0x000000F4) // (UDP_IPNAME2) UDP IPNAME2 REGISTER 
#define UDP_FEATURES    (AT91_CAST(AT91_REG *) 	0x000000F8) // (UDP_FEATURES) UDP FEATURES REGISTER 
#define UDP_VER         (AT91_CAST(AT91_REG *) 	0x000000FC) // (UDP_VER) UDP VERSION REGISTER

#endif
// -------- UDP_FRM_NUM : (UDP Offset: 0x0) USB Frame Number Register -------- 
#define AT91C_UDP_FRM_NUM     (0x7FF <<  0) // (UDP) Frame Number as Defined in the Packet Field Formats
#define AT91C_UDP_FRM_ERR     (0x1 << 16) // (UDP) Frame Error
#define AT91C_UDP_FRM_OK      (0x1 << 17) // (UDP) Frame OK
// -------- UDP_GLB_STATE : (UDP Offset: 0x4) USB Global State Register -------- 
#define AT91C_UDP_FADDEN      (0x1 <<  0) // (UDP) Function Address Enable
#define AT91C_UDP_CONFG       (0x1 <<  1) // (UDP) Configured
#define AT91C_UDP_ESR         (0x1 <<  2) // (UDP) Enable Send Resume
#define AT91C_UDP_RSMINPR     (0x1 <<  3) // (UDP) A Resume Has Been Sent to the Host
#define AT91C_UDP_RMWUPE      (0x1 <<  4) // (UDP) Remote Wake Up Enable
// -------- UDP_FADDR : (UDP Offset: 0x8) USB Function Address Register -------- 
#define AT91C_UDP_FADD        (0xFF <<  0) // (UDP) Function Address Value
#define AT91C_UDP_FEN         (0x1 <<  8) // (UDP) Function Enable
// -------- UDP_IER : (UDP Offset: 0x10) USB Interrupt Enable Register -------- 
#define AT91C_UDP_EPINT0      (0x1 <<  0) // (UDP) Endpoint 0 Interrupt
#define AT91C_UDP_EPINT1      (0x1 <<  1) // (UDP) Endpoint 0 Interrupt
#define AT91C_UDP_EPINT2      (0x1 <<  2) // (UDP) Endpoint 2 Interrupt
#define AT91C_UDP_EPINT3      (0x1 <<  3) // (UDP) Endpoint 3 Interrupt
#define AT91C_UDP_EPINT4      (0x1 <<  4) // (UDP) Endpoint 4 Interrupt
#define AT91C_UDP_EPINT5      (0x1 <<  5) // (UDP) Endpoint 5 Interrupt
#define AT91C_UDP_EPINT6      (0x1 <<  6) // (UDP) Endpoint 6 Interrupt
#define AT91C_UDP_EPINT7      (0x1 <<  7) // (UDP) Endpoint 7 Interrupt
#define AT91C_UDP_RXSUSP      (0x1 <<  8) // (UDP) USB Suspend Interrupt
#define AT91C_UDP_RXRSM       (0x1 <<  9) // (UDP) USB Resume Interrupt
#define AT91C_UDP_EXTRSM      (0x1 << 10) // (UDP) USB External Resume Interrupt
#define AT91C_UDP_SOFINT      (0x1 << 11) // (UDP) USB Start Of frame Interrupt
#define AT91C_UDP_WAKEUP      (0x1 << 13) // (UDP) USB Resume Interrupt
// -------- UDP_IDR : (UDP Offset: 0x14) USB Interrupt Disable Register -------- 
// -------- UDP_IMR : (UDP Offset: 0x18) USB Interrupt Mask Register -------- 
// -------- UDP_ISR : (UDP Offset: 0x1c) USB Interrupt Status Register -------- 
#define AT91C_UDP_ENDBUSRES   (0x1 << 12) // (UDP) USB End Of Bus Reset Interrupt
// -------- UDP_ICR : (UDP Offset: 0x20) USB Interrupt Clear Register -------- 
// -------- UDP_RST_EP : (UDP Offset: 0x28) USB Reset Endpoint Register -------- 
#define AT91C_UDP_EP0         (0x1 <<  0) // (UDP) Reset Endpoint 0
#define AT91C_UDP_EP1         (0x1 <<  1) // (UDP) Reset Endpoint 1
#define AT91C_UDP_EP2         (0x1 <<  2) // (UDP) Reset Endpoint 2
#define AT91C_UDP_EP3         (0x1 <<  3) // (UDP) Reset Endpoint 3
#define AT91C_UDP_EP4         (0x1 <<  4) // (UDP) Reset Endpoint 4
#define AT91C_UDP_EP5         (0x1 <<  5) // (UDP) Reset Endpoint 5
#define AT91C_UDP_EP6         (0x1 <<  6) // (UDP) Reset Endpoint 6
#define AT91C_UDP_EP7         (0x1 <<  7) // (UDP) Reset Endpoint 7
// -------- UDP_CSR : (UDP Offset: 0x30) USB Endpoint Control and Status Register -------- 
#define AT91C_UDP_TXCOMP      (0x1 <<  0) // (UDP) Generates an IN packet with data previously written in the DPR
#define AT91C_UDP_RX_DATA_BK0 (0x1 <<  1) // (UDP) Receive Data Bank 0
#define AT91C_UDP_RXSETUP     (0x1 <<  2) // (UDP) Sends STALL to the Host (Control endpoints)
#define AT91C_UDP_ISOERROR    (0x1 <<  3) // (UDP) Isochronous error (Isochronous endpoints)
#define AT91C_UDP_STALLSENT   (0x1 <<  3) // (UDP) Stall sent (Control, bulk, interrupt endpoints)
#define AT91C_UDP_TXPKTRDY    (0x1 <<  4) // (UDP) Transmit Packet Ready
#define AT91C_UDP_FORCESTALL  (0x1 <<  5) // (UDP) Force Stall (used by Control, Bulk and Isochronous endpoints).
#define AT91C_UDP_RX_DATA_BK1 (0x1 <<  6) // (UDP) Receive Data Bank 1 (only used by endpoints with ping-pong attributes).
#define AT91C_UDP_DIR         (0x1 <<  7) // (UDP) Transfer Direction
#define AT91C_UDP_EPTYPE      (0x7 <<  8) // (UDP) Endpoint type
#define 	AT91C_UDP_EPTYPE_CTRL                 (0x0 <<  8) // (UDP) Control
#define 	AT91C_UDP_EPTYPE_ISO_OUT              (0x1 <<  8) // (UDP) Isochronous OUT
#define 	AT91C_UDP_EPTYPE_BULK_OUT             (0x2 <<  8) // (UDP) Bulk OUT
#define 	AT91C_UDP_EPTYPE_INT_OUT              (0x3 <<  8) // (UDP) Interrupt OUT
#define 	AT91C_UDP_EPTYPE_ISO_IN               (0x5 <<  8) // (UDP) Isochronous IN
#define 	AT91C_UDP_EPTYPE_BULK_IN              (0x6 <<  8) // (UDP) Bulk IN
#define 	AT91C_UDP_EPTYPE_INT_IN               (0x7 <<  8) // (UDP) Interrupt IN
#define AT91C_UDP_DTGLE       (0x1 << 11) // (UDP) Data Toggle
#define AT91C_UDP_EPEDS       (0x1 << 15) // (UDP) Endpoint Enable Disable
#define AT91C_UDP_RXBYTECNT   (0x7FF << 16) // (UDP) Number Of Bytes Available in the FIFO
// -------- UDP_TXVC : (UDP Offset: 0x74) Transceiver Control Register -------- 
#define AT91C_UDP_TXVDIS      (0x1 <<  8) // (UDP) 
#define AT91C_UDP_PUON        (0x1 <<  9) // (UDP) Pull-up ON

// *****************************************************************************
//               REGISTER ADDRESS DEFINITION FOR AT91SAM3s4
// *****************************************************************************
// ========== Register definition for SYS peripheral ========== 
#define AT91C_SYS_GPBR  (AT91_CAST(AT91_REG *) 	0x400E1490) // (SYS) General Purpose Register
// ========== Register definition for SMC peripheral ========== 
#define AT91C_SMC_DELAY2 (AT91_CAST(AT91_REG *) 	0x400E00C4) // (SMC) SMC Delay Control Register
#define AT91C_SMC_CYCLE4 (AT91_CAST(AT91_REG *) 	0x400E0048) // (SMC)  Cycle Register for CS 4
#define AT91C_SMC_CTRL5 (AT91_CAST(AT91_REG *) 	0x400E005C) // (SMC)  Control Register for CS 5
#define AT91C_SMC_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400E00F4) // (SMC) HSMC3 IPNAME2 REGISTER 
#define AT91C_SMC_DELAY5 (AT91_CAST(AT91_REG *) 	0x400E00D0) // (SMC) SMC Delay Control Register
#define AT91C_SMC_DELAY4 (AT91_CAST(AT91_REG *) 	0x400E00CC) // (SMC) SMC Delay Control Register
#define AT91C_SMC_CYCLE0 (AT91_CAST(AT91_REG *) 	0x400E0008) // (SMC)  Cycle Register for CS 0
#define AT91C_SMC_PULSE1 (AT91_CAST(AT91_REG *) 	0x400E0014) // (SMC)  Pulse Register for CS 1
#define AT91C_SMC_DELAY6 (AT91_CAST(AT91_REG *) 	0x400E00D4) // (SMC) SMC Delay Control Register
#define AT91C_SMC_FEATURES (AT91_CAST(AT91_REG *) 	0x400E00F8) // (SMC) HSMC3 FEATURES REGISTER 
#define AT91C_SMC_DELAY3 (AT91_CAST(AT91_REG *) 	0x400E00C8) // (SMC) SMC Delay Control Register
#define AT91C_SMC_CTRL1 (AT91_CAST(AT91_REG *) 	0x400E001C) // (SMC)  Control Register for CS 1
#define AT91C_SMC_PULSE7 (AT91_CAST(AT91_REG *) 	0x400E0074) // (SMC)  Pulse Register for CS 7
#define AT91C_SMC_CTRL7 (AT91_CAST(AT91_REG *) 	0x400E007C) // (SMC)  Control Register for CS 7
#define AT91C_SMC_VER   (AT91_CAST(AT91_REG *) 	0x400E00FC) // (SMC) HSMC3 VERSION REGISTER
#define AT91C_SMC_SETUP5 (AT91_CAST(AT91_REG *) 	0x400E0050) // (SMC)  Setup Register for CS 5
#define AT91C_SMC_CYCLE3 (AT91_CAST(AT91_REG *) 	0x400E0038) // (SMC)  Cycle Register for CS 3
#define AT91C_SMC_SETUP3 (AT91_CAST(AT91_REG *) 	0x400E0030) // (SMC)  Setup Register for CS 3
#define AT91C_SMC_DELAY1 (AT91_CAST(AT91_REG *) 	0x400E00C0) // (SMC) SMC Delay Control Register
#define AT91C_SMC_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400E00EC) // (SMC) HSMC3 ADDRSIZE REGISTER 
#define AT91C_SMC_PULSE3 (AT91_CAST(AT91_REG *) 	0x400E0034) // (SMC)  Pulse Register for CS 3
#define AT91C_SMC_PULSE5 (AT91_CAST(AT91_REG *) 	0x400E0054) // (SMC)  Pulse Register for CS 5
#define AT91C_SMC_PULSE4 (AT91_CAST(AT91_REG *) 	0x400E0044) // (SMC)  Pulse Register for CS 4
#define AT91C_SMC_SETUP2 (AT91_CAST(AT91_REG *) 	0x400E0020) // (SMC)  Setup Register for CS 2
#define AT91C_SMC_DELAY8 (AT91_CAST(AT91_REG *) 	0x400E00DC) // (SMC) SMC Delay Control Register
#define AT91C_SMC_CYCLE7 (AT91_CAST(AT91_REG *) 	0x400E0078) // (SMC)  Cycle Register for CS 7
#define AT91C_SMC_CTRL0 (AT91_CAST(AT91_REG *) 	0x400E000C) // (SMC)  Control Register for CS 0
#define AT91C_SMC_CYCLE2 (AT91_CAST(AT91_REG *) 	0x400E0028) // (SMC)  Cycle Register for CS 2
#define AT91C_SMC_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400E00F0) // (SMC) HSMC3 IPNAME1 REGISTER 
#define AT91C_SMC_SETUP1 (AT91_CAST(AT91_REG *) 	0x400E0010) // (SMC)  Setup Register for CS 1
#define AT91C_SMC_CTRL2 (AT91_CAST(AT91_REG *) 	0x400E002C) // (SMC)  Control Register for CS 2
#define AT91C_SMC_CTRL4 (AT91_CAST(AT91_REG *) 	0x400E004C) // (SMC)  Control Register for CS 4
#define AT91C_SMC_SETUP6 (AT91_CAST(AT91_REG *) 	0x400E0060) // (SMC)  Setup Register for CS 6
#define AT91C_SMC_CYCLE5 (AT91_CAST(AT91_REG *) 	0x400E0058) // (SMC)  Cycle Register for CS 5
#define AT91C_SMC_CTRL6 (AT91_CAST(AT91_REG *) 	0x400E006C) // (SMC)  Control Register for CS 6
#define AT91C_SMC_SETUP4 (AT91_CAST(AT91_REG *) 	0x400E0040) // (SMC)  Setup Register for CS 4
#define AT91C_SMC_PULSE2 (AT91_CAST(AT91_REG *) 	0x400E0024) // (SMC)  Pulse Register for CS 2
#define AT91C_SMC_DELAY7 (AT91_CAST(AT91_REG *) 	0x400E00D8) // (SMC) SMC Delay Control Register
#define AT91C_SMC_SETUP7 (AT91_CAST(AT91_REG *) 	0x400E0070) // (SMC)  Setup Register for CS 7
#define AT91C_SMC_CYCLE1 (AT91_CAST(AT91_REG *) 	0x400E0018) // (SMC)  Cycle Register for CS 1
#define AT91C_SMC_CTRL3 (AT91_CAST(AT91_REG *) 	0x400E003C) // (SMC)  Control Register for CS 3
#define AT91C_SMC_SETUP0 (AT91_CAST(AT91_REG *) 	0x400E0000) // (SMC)  Setup Register for CS 0
#define AT91C_SMC_PULSE0 (AT91_CAST(AT91_REG *) 	0x400E0004) // (SMC)  Pulse Register for CS 0
#define AT91C_SMC_PULSE6 (AT91_CAST(AT91_REG *) 	0x400E0064) // (SMC)  Pulse Register for CS 6
#define AT91C_SMC_CYCLE6 (AT91_CAST(AT91_REG *) 	0x400E0068) // (SMC)  Cycle Register for CS 6
// ========== Register definition for MATRIX peripheral ========== 
#define AT91C_MATRIX_SFR2  (AT91_CAST(AT91_REG *) 	0x400E0318) // (MATRIX)  Special Function Register 2
#define AT91C_MATRIX_SFR3  (AT91_CAST(AT91_REG *) 	0x400E031C) // (MATRIX)  Special Function Register 3
#define AT91C_MATRIX_SCFG8 (AT91_CAST(AT91_REG *) 	0x400E0260) // (MATRIX)  Slave Configuration Register 8
#define AT91C_MATRIX_MCFG2 (AT91_CAST(AT91_REG *) 	0x400E0208) // (MATRIX)  Master Configuration Register 2
#define AT91C_MATRIX_MCFG7 (AT91_CAST(AT91_REG *) 	0x400E021C) // (MATRIX)  Master Configuration Register 7
#define AT91C_MATRIX_SCFG3 (AT91_CAST(AT91_REG *) 	0x400E024C) // (MATRIX)  Slave Configuration Register 3
#define AT91C_MATRIX_SCFG0 (AT91_CAST(AT91_REG *) 	0x400E0240) // (MATRIX)  Slave Configuration Register 0
#define AT91C_MATRIX_SFR12 (AT91_CAST(AT91_REG *) 	0x400E0340) // (MATRIX)  Special Function Register 12
#define AT91C_MATRIX_SCFG1 (AT91_CAST(AT91_REG *) 	0x400E0244) // (MATRIX)  Slave Configuration Register 1
#define AT91C_MATRIX_SFR8  (AT91_CAST(AT91_REG *) 	0x400E0330) // (MATRIX)  Special Function Register 8
#define AT91C_MATRIX_VER (AT91_CAST(AT91_REG *) 	0x400E03FC) // (MATRIX) HMATRIX2 VERSION REGISTER 
#define AT91C_MATRIX_SFR13 (AT91_CAST(AT91_REG *) 	0x400E0344) // (MATRIX)  Special Function Register 13
#define AT91C_MATRIX_SFR5  (AT91_CAST(AT91_REG *) 	0x400E0324) // (MATRIX)  Special Function Register 5
#define AT91C_MATRIX_MCFG0 (AT91_CAST(AT91_REG *) 	0x400E0200) // (MATRIX)  Master Configuration Register 0 : ARM I and D
#define AT91C_MATRIX_SCFG6 (AT91_CAST(AT91_REG *) 	0x400E0258) // (MATRIX)  Slave Configuration Register 6
#define AT91C_MATRIX_SFR14 (AT91_CAST(AT91_REG *) 	0x400E0348) // (MATRIX)  Special Function Register 14
#define AT91C_MATRIX_SFR1  (AT91_CAST(AT91_REG *) 	0x400E0314) // (MATRIX)  Special Function Register 1
#define AT91C_MATRIX_SFR15 (AT91_CAST(AT91_REG *) 	0x400E034C) // (MATRIX)  Special Function Register 15
#define AT91C_MATRIX_SFR6  (AT91_CAST(AT91_REG *) 	0x400E0328) // (MATRIX)  Special Function Register 6
#define AT91C_MATRIX_SFR11 (AT91_CAST(AT91_REG *) 	0x400E033C) // (MATRIX)  Special Function Register 11
#define AT91C_MATRIX_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400E03F4) // (MATRIX) HMATRIX2 IPNAME2 REGISTER 
#define AT91C_MATRIX_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400E03EC) // (MATRIX) HMATRIX2 ADDRSIZE REGISTER 
#define AT91C_MATRIX_MCFG5 (AT91_CAST(AT91_REG *) 	0x400E0214) // (MATRIX)  Master Configuration Register 5
#define AT91C_MATRIX_SFR9  (AT91_CAST(AT91_REG *) 	0x400E0334) // (MATRIX)  Special Function Register 9
#define AT91C_MATRIX_MCFG3 (AT91_CAST(AT91_REG *) 	0x400E020C) // (MATRIX)  Master Configuration Register 3
#define AT91C_MATRIX_SCFG4 (AT91_CAST(AT91_REG *) 	0x400E0250) // (MATRIX)  Slave Configuration Register 4
#define AT91C_MATRIX_MCFG1 (AT91_CAST(AT91_REG *) 	0x400E0204) // (MATRIX)  Master Configuration Register 1 : ARM S
#define AT91C_MATRIX_SCFG7 (AT91_CAST(AT91_REG *) 	0x400E025C) // (MATRIX)  Slave Configuration Register 5
#define AT91C_MATRIX_SFR10 (AT91_CAST(AT91_REG *) 	0x400E0338) // (MATRIX)  Special Function Register 10
#define AT91C_MATRIX_SCFG2 (AT91_CAST(AT91_REG *) 	0x400E0248) // (MATRIX)  Slave Configuration Register 2
#define AT91C_MATRIX_SFR7  (AT91_CAST(AT91_REG *) 	0x400E032C) // (MATRIX)  Special Function Register 7
#define AT91C_MATRIX_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400E03F0) // (MATRIX) HMATRIX2 IPNAME1 REGISTER 
#define AT91C_MATRIX_MCFG4 (AT91_CAST(AT91_REG *) 	0x400E0210) // (MATRIX)  Master Configuration Register 4
#define AT91C_MATRIX_SFR0  (AT91_CAST(AT91_REG *) 	0x400E0310) // (MATRIX)  Special Function Register 0
#define AT91C_MATRIX_FEATURES (AT91_CAST(AT91_REG *) 	0x400E03F8) // (MATRIX) HMATRIX2 FEATURES REGISTER 
#define AT91C_MATRIX_SCFG5 (AT91_CAST(AT91_REG *) 	0x400E0254) // (MATRIX)  Slave Configuration Register 5
#define AT91C_MATRIX_MCFG6 (AT91_CAST(AT91_REG *) 	0x400E0218) // (MATRIX)  Master Configuration Register 6
#define AT91C_MATRIX_SCFG9 (AT91_CAST(AT91_REG *) 	0x400E0264) // (MATRIX)  Slave Configuration Register 9
#define AT91C_MATRIX_SFR4  (AT91_CAST(AT91_REG *) 	0x400E0320) // (MATRIX)  Special Function Register 4
// ========== Register definition for CCFG peripheral ========== 
#define AT91C_CCFG_FLASH0 (AT91_CAST(AT91_REG *) 	0x400E0318) // (CCFG)  FLASH0 configuration
#define AT91C_CCFG_RAM0 (AT91_CAST(AT91_REG *) 	0x400E0310) // (CCFG)  RAM0 configuration
#define AT91C_CCFG_ROM  (AT91_CAST(AT91_REG *) 	0x400E0314) // (CCFG)  ROM  configuration
#define AT91C_CCFG_EBICSA (AT91_CAST(AT91_REG *) 	0x400E031C) // (CCFG)  EBI Chip Select Assignement Register
#define AT91C_CCFG_BRIDGE (AT91_CAST(AT91_REG *) 	0x400E0320) // (CCFG)  BRIDGE configuration
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
// ========== Register definition for MPU peripheral ========== 
#define AT91C_MPU_REG_BASE_ADDR3 (AT91_CAST(AT91_REG *) 	0xE000EDB4) // (MPU) MPU Region Base Address Register alias 3
#define AT91C_MPU_REG_NB (AT91_CAST(AT91_REG *) 	0xE000ED98) // (MPU) MPU Region Number Register
#define AT91C_MPU_ATTR_SIZE1 (AT91_CAST(AT91_REG *) 	0xE000EDA8) // (MPU) MPU  Attribute and Size Register alias 1
#define AT91C_MPU_REG_BASE_ADDR1 (AT91_CAST(AT91_REG *) 	0xE000EDA4) // (MPU) MPU Region Base Address Register alias 1
#define AT91C_MPU_ATTR_SIZE3 (AT91_CAST(AT91_REG *) 	0xE000EDB8) // (MPU) MPU  Attribute and Size Register alias 3
#define AT91C_MPU_CTRL  (AT91_CAST(AT91_REG *) 	0xE000ED94) // (MPU) MPU Control Register
#define AT91C_MPU_ATTR_SIZE2 (AT91_CAST(AT91_REG *) 	0xE000EDB0) // (MPU) MPU  Attribute and Size Register alias 2
#define AT91C_MPU_REG_BASE_ADDR (AT91_CAST(AT91_REG *) 	0xE000ED9C) // (MPU) MPU Region Base Address Register
#define AT91C_MPU_REG_BASE_ADDR2 (AT91_CAST(AT91_REG *) 	0xE000EDAC) // (MPU) MPU Region Base Address Register alias 2
#define AT91C_MPU_ATTR_SIZE (AT91_CAST(AT91_REG *) 	0xE000EDA0) // (MPU) MPU  Attribute and Size Register
#define AT91C_MPU_TYPE  (AT91_CAST(AT91_REG *) 	0xE000ED90) // (MPU) MPU Type Register
// ========== Register definition for CM3 peripheral ========== 
#define AT91C_CM3_SHCSR (AT91_CAST(AT91_REG *) 	0xE000ED24) // (CM3) System Handler Control and State Register
#define AT91C_CM3_CCR   (AT91_CAST(AT91_REG *) 	0xE000ED14) // (CM3) Configuration Control Register
#define AT91C_CM3_ICSR  (AT91_CAST(AT91_REG *) 	0xE000ED04) // (CM3) Interrupt Control State Register
#define AT91C_CM3_CPUID (AT91_CAST(AT91_REG *) 	0xE000ED00) // (CM3) CPU ID Base Register
#define AT91C_CM3_SCR   (AT91_CAST(AT91_REG *) 	0xE000ED10) // (CM3) System Controller Register
#define AT91C_CM3_AIRCR (AT91_CAST(AT91_REG *) 	0xE000ED0C) // (CM3) Application Interrupt and Reset Control Register
#define AT91C_CM3_SHPR  (AT91_CAST(AT91_REG *) 	0xE000ED18) // (CM3) System Handler Priority Register
#define AT91C_CM3_VTOR  (AT91_CAST(AT91_REG *) 	0xE000ED08) // (CM3) Vector Table Offset Register
// ========== Register definition for PDC_DBGU0 peripheral ========== 
#define AT91C_DBGU0_TPR (AT91_CAST(AT91_REG *) 	0x400E0708) // (PDC_DBGU0) Transmit Pointer Register
#define AT91C_DBGU0_PTCR (AT91_CAST(AT91_REG *) 	0x400E0720) // (PDC_DBGU0) PDC Transfer Control Register
#define AT91C_DBGU0_TNCR (AT91_CAST(AT91_REG *) 	0x400E071C) // (PDC_DBGU0) Transmit Next Counter Register
#define AT91C_DBGU0_PTSR (AT91_CAST(AT91_REG *) 	0x400E0724) // (PDC_DBGU0) PDC Transfer Status Register
#define AT91C_DBGU0_RNCR (AT91_CAST(AT91_REG *) 	0x400E0714) // (PDC_DBGU0) Receive Next Counter Register
#define AT91C_DBGU0_RPR (AT91_CAST(AT91_REG *) 	0x400E0700) // (PDC_DBGU0) Receive Pointer Register
#define AT91C_DBGU0_TCR (AT91_CAST(AT91_REG *) 	0x400E070C) // (PDC_DBGU0) Transmit Counter Register
#define AT91C_DBGU0_RNPR (AT91_CAST(AT91_REG *) 	0x400E0710) // (PDC_DBGU0) Receive Next Pointer Register
#define AT91C_DBGU0_TNPR (AT91_CAST(AT91_REG *) 	0x400E0718) // (PDC_DBGU0) Transmit Next Pointer Register
#define AT91C_DBGU0_RCR (AT91_CAST(AT91_REG *) 	0x400E0704) // (PDC_DBGU0) Receive Counter Register
// ========== Register definition for DBGU0 peripheral ========== 
#define AT91C_DBGU0_CR  (AT91_CAST(AT91_REG *) 	0x400E0600) // (DBGU0) Control Register
#define AT91C_DBGU0_IDR (AT91_CAST(AT91_REG *) 	0x400E060C) // (DBGU0) Interrupt Disable Register
#define AT91C_DBGU0_CIDR (AT91_CAST(AT91_REG *) 	0x400E0740) // (DBGU0) Chip ID Register
#define AT91C_DBGU0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400E06F4) // (DBGU0) DBGU IPNAME2 REGISTER 
#define AT91C_DBGU0_FEATURES (AT91_CAST(AT91_REG *) 	0x400E06F8) // (DBGU0) DBGU FEATURES REGISTER 
#define AT91C_DBGU0_FNTR (AT91_CAST(AT91_REG *) 	0x400E0648) // (DBGU0) Force NTRST Register
#define AT91C_DBGU0_RHR (AT91_CAST(AT91_REG *) 	0x400E0618) // (DBGU0) Receiver Holding Register
#define AT91C_DBGU0_THR (AT91_CAST(AT91_REG *) 	0x400E061C) // (DBGU0) Transmitter Holding Register
#define AT91C_DBGU0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400E06EC) // (DBGU0) DBGU ADDRSIZE REGISTER 
#define AT91C_DBGU0_MR  (AT91_CAST(AT91_REG *) 	0x400E0604) // (DBGU0) Mode Register
#define AT91C_DBGU0_IER (AT91_CAST(AT91_REG *) 	0x400E0608) // (DBGU0) Interrupt Enable Register
#define AT91C_DBGU0_BRGR (AT91_CAST(AT91_REG *) 	0x400E0620) // (DBGU0) Baud Rate Generator Register
#define AT91C_DBGU0_CSR (AT91_CAST(AT91_REG *) 	0x400E0614) // (DBGU0) Channel Status Register
#define AT91C_DBGU0_VER (AT91_CAST(AT91_REG *) 	0x400E06FC) // (DBGU0) DBGU VERSION REGISTER 
#define AT91C_DBGU0_IMR (AT91_CAST(AT91_REG *) 	0x400E0610) // (DBGU0) Interrupt Mask Register
#define AT91C_DBGU0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400E06F0) // (DBGU0) DBGU IPNAME1 REGISTER 
#define AT91C_DBGU0_EXID (AT91_CAST(AT91_REG *) 	0x400E0744) // (DBGU0) Chip ID Extension Register
// ========== Register definition for PDC_DBGU1 peripheral ========== 
#define AT91C_DBGU1_RNCR (AT91_CAST(AT91_REG *) 	0x400E0914) // (PDC_DBGU1) Receive Next Counter Register
#define AT91C_DBGU1_RPR (AT91_CAST(AT91_REG *) 	0x400E0900) // (PDC_DBGU1) Receive Pointer Register
#define AT91C_DBGU1_TNCR (AT91_CAST(AT91_REG *) 	0x400E091C) // (PDC_DBGU1) Transmit Next Counter Register
#define AT91C_DBGU1_TNPR (AT91_CAST(AT91_REG *) 	0x400E0918) // (PDC_DBGU1) Transmit Next Pointer Register
#define AT91C_DBGU1_PTSR (AT91_CAST(AT91_REG *) 	0x400E0924) // (PDC_DBGU1) PDC Transfer Status Register
#define AT91C_DBGU1_PTCR (AT91_CAST(AT91_REG *) 	0x400E0920) // (PDC_DBGU1) PDC Transfer Control Register
#define AT91C_DBGU1_RCR (AT91_CAST(AT91_REG *) 	0x400E0904) // (PDC_DBGU1) Receive Counter Register
#define AT91C_DBGU1_RNPR (AT91_CAST(AT91_REG *) 	0x400E0910) // (PDC_DBGU1) Receive Next Pointer Register
#define AT91C_DBGU1_TPR (AT91_CAST(AT91_REG *) 	0x400E0908) // (PDC_DBGU1) Transmit Pointer Register
#define AT91C_DBGU1_TCR (AT91_CAST(AT91_REG *) 	0x400E090C) // (PDC_DBGU1) Transmit Counter Register
// ========== Register definition for DBGU1 peripheral ========== 
#define AT91C_DBGU1_RHR (AT91_CAST(AT91_REG *) 	0x400E0818) // (DBGU1) Receiver Holding Register
#define AT91C_DBGU1_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400E08F0) // (DBGU1) DBGU IPNAME1 REGISTER 
#define AT91C_DBGU1_CIDR (AT91_CAST(AT91_REG *) 	0x400E0940) // (DBGU1) Chip ID Register
#define AT91C_DBGU1_CR  (AT91_CAST(AT91_REG *) 	0x400E0800) // (DBGU1) Control Register
#define AT91C_DBGU1_VER (AT91_CAST(AT91_REG *) 	0x400E08FC) // (DBGU1) DBGU VERSION REGISTER 
#define AT91C_DBGU1_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400E08F4) // (DBGU1) DBGU IPNAME2 REGISTER 
#define AT91C_DBGU1_BRGR (AT91_CAST(AT91_REG *) 	0x400E0820) // (DBGU1) Baud Rate Generator Register
#define AT91C_DBGU1_FNTR (AT91_CAST(AT91_REG *) 	0x400E0848) // (DBGU1) Force NTRST Register
#define AT91C_DBGU1_MR  (AT91_CAST(AT91_REG *) 	0x400E0804) // (DBGU1) Mode Register
#define AT91C_DBGU1_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400E08EC) // (DBGU1) DBGU ADDRSIZE REGISTER 
#define AT91C_DBGU1_CSR (AT91_CAST(AT91_REG *) 	0x400E0814) // (DBGU1) Channel Status Register
#define AT91C_DBGU1_IMR (AT91_CAST(AT91_REG *) 	0x400E0810) // (DBGU1) Interrupt Mask Register
#define AT91C_DBGU1_EXID (AT91_CAST(AT91_REG *) 	0x400E0944) // (DBGU1) Chip ID Extension Register
#define AT91C_DBGU1_IDR (AT91_CAST(AT91_REG *) 	0x400E080C) // (DBGU1) Interrupt Disable Register
#define AT91C_DBGU1_FEATURES (AT91_CAST(AT91_REG *) 	0x400E08F8) // (DBGU1) DBGU FEATURES REGISTER 
#define AT91C_DBGU1_IER (AT91_CAST(AT91_REG *) 	0x400E0808) // (DBGU1) Interrupt Enable Register
#define AT91C_DBGU1_THR (AT91_CAST(AT91_REG *) 	0x400E081C) // (DBGU1) Transmitter Holding Register
// ========== Register definition for PIOA peripheral ========== 
#define AT91C_PIOA_SENIDR (AT91_CAST(AT91_REG *) 	0x400E0F58) // (PIOA) Sensor Interrupt Disable Register
#define AT91C_PIOA_OWSR (AT91_CAST(AT91_REG *) 	0x400E0EA8) // (PIOA) Output Write Status Register
#define AT91C_PIOA_PSR  (AT91_CAST(AT91_REG *) 	0x400E0E08) // (PIOA) PIO Status Register
#define AT91C_PIOA_MDER (AT91_CAST(AT91_REG *) 	0x400E0E50) // (PIOA) Multi-driver Enable Register
#define AT91C_PIOA_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400E0EF0) // (PIOA) PIO IPNAME1 REGISTER 
#define AT91C_PIOA_FEATURES (AT91_CAST(AT91_REG *) 	0x400E0EF8) // (PIOA) PIO FEATURES REGISTER 
#define AT91C_PIOA_SP2  (AT91_CAST(AT91_REG *) 	0x400E0E74) // (PIOA) Select B Register
#define AT91C_PIOA_ODR  (AT91_CAST(AT91_REG *) 	0x400E0E14) // (PIOA) Output Disable Registerr
#define AT91C_PIOA_IDR  (AT91_CAST(AT91_REG *) 	0x400E0E44) // (PIOA) Interrupt Disable Register
#define AT91C_PIOA_PDR  (AT91_CAST(AT91_REG *) 	0x400E0E04) // (PIOA) PIO Disable Register
#define AT91C_PIOA_PDSR (AT91_CAST(AT91_REG *) 	0x400E0E3C) // (PIOA) Pin Data Status Register
#define AT91C_PIOA_PPDER (AT91_CAST(AT91_REG *) 	0x400E0E94) // (PIOA) Pull-down Enable Register
#define AT91C_PIOA_SENIER (AT91_CAST(AT91_REG *) 	0x400E0F54) // (PIOA) Sensor Interrupt Enable Register
#define AT91C_PIOA_SLEW2 (AT91_CAST(AT91_REG *) 	0x400E0F04) // (PIOA) PIO SLEWRATE2 REGISTER 
#define AT91C_PIOA_SENMR (AT91_CAST(AT91_REG *) 	0x400E0F50) // (PIOA) Sensor Mode Register
#define AT91C_PIOA_PPUDR (AT91_CAST(AT91_REG *) 	0x400E0E60) // (PIOA) Pull-up Disable Register
#define AT91C_PIOA_OWDR (AT91_CAST(AT91_REG *) 	0x400E0EA4) // (PIOA) Output Write Disable Register
#define AT91C_PIOA_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400E0EEC) // (PIOA) PIO ADDRSIZE REGISTER 
#define AT91C_PIOA_IFER (AT91_CAST(AT91_REG *) 	0x400E0E20) // (PIOA) Input Filter Enable Register
#define AT91C_PIOA_PPDSR (AT91_CAST(AT91_REG *) 	0x400E0E98) // (PIOA) Pull-down Status Register
#define AT91C_PIOA_SP1  (AT91_CAST(AT91_REG *) 	0x400E0E70) // (PIOA) Select B Register
#define AT91C_PIOA_SENIMR (AT91_CAST(AT91_REG *) 	0x400E0F5C) // (PIOA) Sensor Interrupt Mask Register
#define AT91C_PIOA_SENDATA (AT91_CAST(AT91_REG *) 	0x400E0F64) // (PIOA) Sensor Data Register
#define AT91C_PIOA_VER  (AT91_CAST(AT91_REG *) 	0x400E0EFC) // (PIOA) PIO VERSION REGISTER 
#define AT91C_PIOA_PER  (AT91_CAST(AT91_REG *) 	0x400E0E00) // (PIOA) PIO Enable Register
#define AT91C_PIOA_IMR  (AT91_CAST(AT91_REG *) 	0x400E0E48) // (PIOA) Interrupt Mask Register
#define AT91C_PIOA_PPUSR (AT91_CAST(AT91_REG *) 	0x400E0E68) // (PIOA) Pull-up Status Register
#define AT91C_PIOA_ODSR (AT91_CAST(AT91_REG *) 	0x400E0E38) // (PIOA) Output Data Status Register
#define AT91C_PIOA_SENISR (AT91_CAST(AT91_REG *) 	0x400E0F60) // (PIOA) Sensor Interrupt Status Register
#define AT91C_PIOA_IFDR (AT91_CAST(AT91_REG *) 	0x400E0E24) // (PIOA) Input Filter Disable Register
#define AT91C_PIOA_SODR (AT91_CAST(AT91_REG *) 	0x400E0E30) // (PIOA) Set Output Data Register
#define AT91C_PIOA_SLEW1 (AT91_CAST(AT91_REG *) 	0x400E0F00) // (PIOA) PIO SLEWRATE1 REGISTER 
#define AT91C_PIOA_IER  (AT91_CAST(AT91_REG *) 	0x400E0E40) // (PIOA) Interrupt Enable Register
#define AT91C_PIOA_MDSR (AT91_CAST(AT91_REG *) 	0x400E0E58) // (PIOA) Multi-driver Status Register
#define AT91C_PIOA_ISR  (AT91_CAST(AT91_REG *) 	0x400E0E4C) // (PIOA) Interrupt Status Register
#define AT91C_PIOA_IFSR (AT91_CAST(AT91_REG *) 	0x400E0E28) // (PIOA) Input Filter Status Register
#define AT91C_PIOA_PPDDR (AT91_CAST(AT91_REG *) 	0x400E0E90) // (PIOA) Pull-down Disable Register
#define AT91C_PIOA_PPUER (AT91_CAST(AT91_REG *) 	0x400E0E64) // (PIOA) Pull-up Enable Register
#define AT91C_PIOA_OWER (AT91_CAST(AT91_REG *) 	0x400E0EA0) // (PIOA) Output Write Enable Register
#define AT91C_PIOA_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400E0EF4) // (PIOA) PIO IPNAME2 REGISTER 
#define AT91C_PIOA_MDDR (AT91_CAST(AT91_REG *) 	0x400E0E54) // (PIOA) Multi-driver Disable Register
#define AT91C_PIOA_CODR (AT91_CAST(AT91_REG *) 	0x400E0E34) // (PIOA) Clear Output Data Register
#define AT91C_PIOA_OER  (AT91_CAST(AT91_REG *) 	0x400E0E10) // (PIOA) Output Enable Register
#define AT91C_PIOA_OSR  (AT91_CAST(AT91_REG *) 	0x400E0E18) // (PIOA) Output Status Register
#define AT91C_PIOA_ABSR (AT91_CAST(AT91_REG *) 	0x400E0E78) // (PIOA) AB Select Status Register
// ========== Register definition for PDC_PIOA peripheral ========== 
#define AT91C_PIOA_RPR  (AT91_CAST(AT91_REG *) 	0x400E0F68) // (PDC_PIOA) Receive Pointer Register
#define AT91C_PIOA_TPR  (AT91_CAST(AT91_REG *) 	0x400E0F70) // (PDC_PIOA) Transmit Pointer Register
#define AT91C_PIOA_RCR  (AT91_CAST(AT91_REG *) 	0x400E0F6C) // (PDC_PIOA) Receive Counter Register
#define AT91C_PIOA_PTSR (AT91_CAST(AT91_REG *) 	0x400E0F8C) // (PDC_PIOA) PDC Transfer Status Register
#define AT91C_PIOA_TCR  (AT91_CAST(AT91_REG *) 	0x400E0F74) // (PDC_PIOA) Transmit Counter Register
#define AT91C_PIOA_PTCR (AT91_CAST(AT91_REG *) 	0x400E0F88) // (PDC_PIOA) PDC Transfer Control Register
#define AT91C_PIOA_RNPR (AT91_CAST(AT91_REG *) 	0x400E0F78) // (PDC_PIOA) Receive Next Pointer Register
#define AT91C_PIOA_TNCR (AT91_CAST(AT91_REG *) 	0x400E0F84) // (PDC_PIOA) Transmit Next Counter Register
#define AT91C_PIOA_RNCR (AT91_CAST(AT91_REG *) 	0x400E0F7C) // (PDC_PIOA) Receive Next Counter Register
#define AT91C_PIOA_TNPR (AT91_CAST(AT91_REG *) 	0x400E0F80) // (PDC_PIOA) Transmit Next Pointer Register
// ========== Register definition for PIOB peripheral ========== 
#define AT91C_PIOB_MDDR (AT91_CAST(AT91_REG *) 	0x400E1054) // (PIOB) Multi-driver Disable Register
#define AT91C_PIOB_ABSR (AT91_CAST(AT91_REG *) 	0x400E1078) // (PIOB) AB Select Status Register
#define AT91C_PIOB_SP1  (AT91_CAST(AT91_REG *) 	0x400E1070) // (PIOB) Select B Register
#define AT91C_PIOB_ODSR (AT91_CAST(AT91_REG *) 	0x400E1038) // (PIOB) Output Data Status Register
#define AT91C_PIOB_SLEW1 (AT91_CAST(AT91_REG *) 	0x400E1100) // (PIOB) PIO SLEWRATE1 REGISTER 
#define AT91C_PIOB_SENISR (AT91_CAST(AT91_REG *) 	0x400E1160) // (PIOB) Sensor Interrupt Status Register
#define AT91C_PIOB_OSR  (AT91_CAST(AT91_REG *) 	0x400E1018) // (PIOB) Output Status Register
#define AT91C_PIOB_IFER (AT91_CAST(AT91_REG *) 	0x400E1020) // (PIOB) Input Filter Enable Register
#define AT91C_PIOB_SENDATA (AT91_CAST(AT91_REG *) 	0x400E1164) // (PIOB) Sensor Data Register
#define AT91C_PIOB_MDSR (AT91_CAST(AT91_REG *) 	0x400E1058) // (PIOB) Multi-driver Status Register
#define AT91C_PIOB_IFDR (AT91_CAST(AT91_REG *) 	0x400E1024) // (PIOB) Input Filter Disable Register
#define AT91C_PIOB_MDER (AT91_CAST(AT91_REG *) 	0x400E1050) // (PIOB) Multi-driver Enable Register
#define AT91C_PIOB_SENIDR (AT91_CAST(AT91_REG *) 	0x400E1158) // (PIOB) Sensor Interrupt Disable Register
#define AT91C_PIOB_IER  (AT91_CAST(AT91_REG *) 	0x400E1040) // (PIOB) Interrupt Enable Register
#define AT91C_PIOB_OWDR (AT91_CAST(AT91_REG *) 	0x400E10A4) // (PIOB) Output Write Disable Register
#define AT91C_PIOB_IFSR (AT91_CAST(AT91_REG *) 	0x400E1028) // (PIOB) Input Filter Status Register
#define AT91C_PIOB_ISR  (AT91_CAST(AT91_REG *) 	0x400E104C) // (PIOB) Interrupt Status Register
#define AT91C_PIOB_PPUDR (AT91_CAST(AT91_REG *) 	0x400E1060) // (PIOB) Pull-up Disable Register
#define AT91C_PIOB_PDSR (AT91_CAST(AT91_REG *) 	0x400E103C) // (PIOB) Pin Data Status Register
#define AT91C_PIOB_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400E10F4) // (PIOB) PIO IPNAME2 REGISTER 
#define AT91C_PIOB_PPUER (AT91_CAST(AT91_REG *) 	0x400E1064) // (PIOB) Pull-up Enable Register
#define AT91C_PIOB_SLEW2 (AT91_CAST(AT91_REG *) 	0x400E1104) // (PIOB) PIO SLEWRATE2 REGISTER 
#define AT91C_PIOB_OER  (AT91_CAST(AT91_REG *) 	0x400E1010) // (PIOB) Output Enable Register
#define AT91C_PIOB_CODR (AT91_CAST(AT91_REG *) 	0x400E1034) // (PIOB) Clear Output Data Register
#define AT91C_PIOB_PPDDR (AT91_CAST(AT91_REG *) 	0x400E1090) // (PIOB) Pull-down Disable Register
#define AT91C_PIOB_OWER (AT91_CAST(AT91_REG *) 	0x400E10A0) // (PIOB) Output Write Enable Register
#define AT91C_PIOB_VER  (AT91_CAST(AT91_REG *) 	0x400E10FC) // (PIOB) PIO VERSION REGISTER 
#define AT91C_PIOB_PPDER (AT91_CAST(AT91_REG *) 	0x400E1094) // (PIOB) Pull-down Enable Register
#define AT91C_PIOB_IMR  (AT91_CAST(AT91_REG *) 	0x400E1048) // (PIOB) Interrupt Mask Register
#define AT91C_PIOB_PPUSR (AT91_CAST(AT91_REG *) 	0x400E1068) // (PIOB) Pull-up Status Register
#define AT91C_PIOB_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400E10F0) // (PIOB) PIO IPNAME1 REGISTER 
#define AT91C_PIOB_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400E10EC) // (PIOB) PIO ADDRSIZE REGISTER 
#define AT91C_PIOB_SP2  (AT91_CAST(AT91_REG *) 	0x400E1074) // (PIOB) Select B Register
#define AT91C_PIOB_IDR  (AT91_CAST(AT91_REG *) 	0x400E1044) // (PIOB) Interrupt Disable Register
#define AT91C_PIOB_SENMR (AT91_CAST(AT91_REG *) 	0x400E1150) // (PIOB) Sensor Mode Register
#define AT91C_PIOB_SODR (AT91_CAST(AT91_REG *) 	0x400E1030) // (PIOB) Set Output Data Register
#define AT91C_PIOB_PPDSR (AT91_CAST(AT91_REG *) 	0x400E1098) // (PIOB) Pull-down Status Register
#define AT91C_PIOB_PSR  (AT91_CAST(AT91_REG *) 	0x400E1008) // (PIOB) PIO Status Register
#define AT91C_PIOB_ODR  (AT91_CAST(AT91_REG *) 	0x400E1014) // (PIOB) Output Disable Registerr
#define AT91C_PIOB_OWSR (AT91_CAST(AT91_REG *) 	0x400E10A8) // (PIOB) Output Write Status Register
#define AT91C_PIOB_FEATURES (AT91_CAST(AT91_REG *) 	0x400E10F8) // (PIOB) PIO FEATURES REGISTER 
#define AT91C_PIOB_PDR  (AT91_CAST(AT91_REG *) 	0x400E1004) // (PIOB) PIO Disable Register
#define AT91C_PIOB_SENIMR (AT91_CAST(AT91_REG *) 	0x400E115C) // (PIOB) Sensor Interrupt Mask Register
#define AT91C_PIOB_SENIER (AT91_CAST(AT91_REG *) 	0x400E1154) // (PIOB) Sensor Interrupt Enable Register
#define AT91C_PIOB_PER  (AT91_CAST(AT91_REG *) 	0x400E1000) // (PIOB) PIO Enable Register
// ========== Register definition for PIOC peripheral ========== 
#define AT91C_PIOC_VER  (AT91_CAST(AT91_REG *) 	0x400E12FC) // (PIOC) PIO VERSION REGISTER 
#define AT91C_PIOC_IMR  (AT91_CAST(AT91_REG *) 	0x400E1248) // (PIOC) Interrupt Mask Register
#define AT91C_PIOC_PSR  (AT91_CAST(AT91_REG *) 	0x400E1208) // (PIOC) PIO Status Register
#define AT91C_PIOC_PPDSR (AT91_CAST(AT91_REG *) 	0x400E1298) // (PIOC) Pull-down Status Register
#define AT91C_PIOC_OER  (AT91_CAST(AT91_REG *) 	0x400E1210) // (PIOC) Output Enable Register
#define AT91C_PIOC_OSR  (AT91_CAST(AT91_REG *) 	0x400E1218) // (PIOC) Output Status Register
#define AT91C_PIOC_MDDR (AT91_CAST(AT91_REG *) 	0x400E1254) // (PIOC) Multi-driver Disable Register
#define AT91C_PIOC_PPUSR (AT91_CAST(AT91_REG *) 	0x400E1268) // (PIOC) Pull-up Status Register
#define AT91C_PIOC_ODSR (AT91_CAST(AT91_REG *) 	0x400E1238) // (PIOC) Output Data Status Register
#define AT91C_PIOC_SLEW2 (AT91_CAST(AT91_REG *) 	0x400E1304) // (PIOC) PIO SLEWRATE2 REGISTER 
#define AT91C_PIOC_SENMR (AT91_CAST(AT91_REG *) 	0x400E1350) // (PIOC) Sensor Mode Register
#define AT91C_PIOC_IFER (AT91_CAST(AT91_REG *) 	0x400E1220) // (PIOC) Input Filter Enable Register
#define AT91C_PIOC_PDR  (AT91_CAST(AT91_REG *) 	0x400E1204) // (PIOC) PIO Disable Register
#define AT91C_PIOC_MDER (AT91_CAST(AT91_REG *) 	0x400E1250) // (PIOC) Multi-driver Enable Register
#define AT91C_PIOC_SP2  (AT91_CAST(AT91_REG *) 	0x400E1274) // (PIOC) Select B Register
#define AT91C_PIOC_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400E12F0) // (PIOC) PIO IPNAME1 REGISTER 
#define AT91C_PIOC_IER  (AT91_CAST(AT91_REG *) 	0x400E1240) // (PIOC) Interrupt Enable Register
#define AT91C_PIOC_OWDR (AT91_CAST(AT91_REG *) 	0x400E12A4) // (PIOC) Output Write Disable Register
#define AT91C_PIOC_IDR  (AT91_CAST(AT91_REG *) 	0x400E1244) // (PIOC) Interrupt Disable Register
#define AT91C_PIOC_PDSR (AT91_CAST(AT91_REG *) 	0x400E123C) // (PIOC) Pin Data Status Register
#define AT91C_PIOC_SENIDR (AT91_CAST(AT91_REG *) 	0x400E1358) // (PIOC) Sensor Interrupt Disable Register
#define AT91C_PIOC_SENISR (AT91_CAST(AT91_REG *) 	0x400E1360) // (PIOC) Sensor Interrupt Status Register
#define AT91C_PIOC_PER  (AT91_CAST(AT91_REG *) 	0x400E1200) // (PIOC) PIO Enable Register
#define AT91C_PIOC_SENDATA (AT91_CAST(AT91_REG *) 	0x400E1364) // (PIOC) Sensor Data Register
#define AT91C_PIOC_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400E12F4) // (PIOC) PIO IPNAME2 REGISTER 
#define AT91C_PIOC_PPDDR (AT91_CAST(AT91_REG *) 	0x400E1290) // (PIOC) Pull-down Disable Register
#define AT91C_PIOC_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400E12EC) // (PIOC) PIO ADDRSIZE REGISTER 
#define AT91C_PIOC_IFDR (AT91_CAST(AT91_REG *) 	0x400E1224) // (PIOC) Input Filter Disable Register
#define AT91C_PIOC_ODR  (AT91_CAST(AT91_REG *) 	0x400E1214) // (PIOC) Output Disable Registerr
#define AT91C_PIOC_CODR (AT91_CAST(AT91_REG *) 	0x400E1234) // (PIOC) Clear Output Data Register
#define AT91C_PIOC_MDSR (AT91_CAST(AT91_REG *) 	0x400E1258) // (PIOC) Multi-driver Status Register
#define AT91C_PIOC_FEATURES (AT91_CAST(AT91_REG *) 	0x400E12F8) // (PIOC) PIO FEATURES REGISTER 
#define AT91C_PIOC_IFSR (AT91_CAST(AT91_REG *) 	0x400E1228) // (PIOC) Input Filter Status Register
#define AT91C_PIOC_PPUER (AT91_CAST(AT91_REG *) 	0x400E1264) // (PIOC) Pull-up Enable Register
#define AT91C_PIOC_PPDER (AT91_CAST(AT91_REG *) 	0x400E1294) // (PIOC) Pull-down Enable Register
#define AT91C_PIOC_OWSR (AT91_CAST(AT91_REG *) 	0x400E12A8) // (PIOC) Output Write Status Register
#define AT91C_PIOC_ISR  (AT91_CAST(AT91_REG *) 	0x400E124C) // (PIOC) Interrupt Status Register
#define AT91C_PIOC_OWER (AT91_CAST(AT91_REG *) 	0x400E12A0) // (PIOC) Output Write Enable Register
#define AT91C_PIOC_PPUDR (AT91_CAST(AT91_REG *) 	0x400E1260) // (PIOC) Pull-up Disable Register
#define AT91C_PIOC_SENIMR (AT91_CAST(AT91_REG *) 	0x400E135C) // (PIOC) Sensor Interrupt Mask Register
#define AT91C_PIOC_SLEW1 (AT91_CAST(AT91_REG *) 	0x400E1300) // (PIOC) PIO SLEWRATE1 REGISTER 
#define AT91C_PIOC_SENIER (AT91_CAST(AT91_REG *) 	0x400E1354) // (PIOC) Sensor Interrupt Enable Register
#define AT91C_PIOC_SODR (AT91_CAST(AT91_REG *) 	0x400E1230) // (PIOC) Set Output Data Register
#define AT91C_PIOC_SP1  (AT91_CAST(AT91_REG *) 	0x400E1270) // (PIOC) Select B Register
#define AT91C_PIOC_ABSR (AT91_CAST(AT91_REG *) 	0x400E1278) // (PIOC) AB Select Status Register
// ========== Register definition for PMC peripheral ========== 
#define AT91C_PMC_PLLAR (AT91_CAST(AT91_REG *) 	0x400E0428) // (PMC) PLL Register
#define AT91C_PMC_UCKR  (AT91_CAST(AT91_REG *) 	0x400E041C) // (PMC) UTMI Clock Configuration Register
#define AT91C_PMC_FSMR  (AT91_CAST(AT91_REG *) 	0x400E0470) // (PMC) Fast Startup Mode Register
#define AT91C_PMC_MCKR  (AT91_CAST(AT91_REG *) 	0x400E0430) // (PMC) Master Clock Register
#define AT91C_PMC_SCER  (AT91_CAST(AT91_REG *) 	0x400E0400) // (PMC) System Clock Enable Register
#define AT91C_PMC_PCSR  (AT91_CAST(AT91_REG *) 	0x400E0418) // (PMC) Peripheral Clock Status Register 0:31 PERI_ID
#define AT91C_PMC_MCFR  (AT91_CAST(AT91_REG *) 	0x400E0424) // (PMC) Main Clock  Frequency Register
#define AT91C_PMC_PCER1 (AT91_CAST(AT91_REG *) 	0x400E0500) // (PMC) Peripheral Clock Enable Register 32:63 PERI_ID
#define AT91C_PMC_FOCR  (AT91_CAST(AT91_REG *) 	0x400E0478) // (PMC) Fault Output Clear Register
#define AT91C_PMC_PCSR1 (AT91_CAST(AT91_REG *) 	0x400E0508) // (PMC) Peripheral Clock Status Register 32:63 PERI_ID
#define AT91C_PMC_FSPR  (AT91_CAST(AT91_REG *) 	0x400E0474) // (PMC) Fast Startup Polarity Register
#define AT91C_PMC_SCSR  (AT91_CAST(AT91_REG *) 	0x400E0408) // (PMC) System Clock Status Register
#define AT91C_PMC_IDR   (AT91_CAST(AT91_REG *) 	0x400E0464) // (PMC) Interrupt Disable Register
#define AT91C_PMC_UDPR  (AT91_CAST(AT91_REG *) 	0x400E0438) // (PMC) USB DEV Clock Configuration Register
#define AT91C_PMC_PCDR1 (AT91_CAST(AT91_REG *) 	0x400E0504) // (PMC) Peripheral Clock Disable Register 32:63 PERI_ID
#define AT91C_PMC_VER   (AT91_CAST(AT91_REG *) 	0x400E04FC) // (PMC) APMC VERSION REGISTER
#define AT91C_PMC_IMR   (AT91_CAST(AT91_REG *) 	0x400E046C) // (PMC) Interrupt Mask Register
#define AT91C_PMC_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400E04F4) // (PMC) PMC IPNAME2 REGISTER 
#define AT91C_PMC_SCDR  (AT91_CAST(AT91_REG *) 	0x400E0404) // (PMC) System Clock Disable Register
#define AT91C_PMC_PCKR  (AT91_CAST(AT91_REG *) 	0x400E0440) // (PMC) Programmable Clock Register
#define AT91C_PMC_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400E04EC) // (PMC) PMC ADDRSIZE REGISTER 
#define AT91C_PMC_PCDR  (AT91_CAST(AT91_REG *) 	0x400E0414) // (PMC) Peripheral Clock Disable Register 0:31 PERI_ID
#define AT91C_PMC_MOR   (AT91_CAST(AT91_REG *) 	0x400E0420) // (PMC) Main Oscillator Register
#define AT91C_PMC_SR    (AT91_CAST(AT91_REG *) 	0x400E0468) // (PMC) Status Register
#define AT91C_PMC_IER   (AT91_CAST(AT91_REG *) 	0x400E0460) // (PMC) Interrupt Enable Register
#define AT91C_PMC_PLLBR (AT91_CAST(AT91_REG *) 	0x400E042C) // (PMC) PLL B Register
#define AT91C_PMC_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400E04F0) // (PMC) PMC IPNAME1 REGISTER 
#define AT91C_PMC_PCER  (AT91_CAST(AT91_REG *) 	0x400E0410) // (PMC) Peripheral Clock Enable Register 0:31 PERI_ID
#define AT91C_PMC_FEATURES (AT91_CAST(AT91_REG *) 	0x400E04F8) // (PMC) PMC FEATURES REGISTER 
#define AT91C_PMC_PCR   (AT91_CAST(AT91_REG *) 	0x400E050C) // (PMC) Peripheral Control Register
// ========== Register definition for CKGR peripheral ========== 
#define AT91C_CKGR_PLLAR (AT91_CAST(AT91_REG *) 	0x400E0428) // (CKGR) PLL Register
#define AT91C_CKGR_UCKR (AT91_CAST(AT91_REG *) 	0x400E041C) // (CKGR) UTMI Clock Configuration Register
#define AT91C_CKGR_MOR  (AT91_CAST(AT91_REG *) 	0x400E0420) // (CKGR) Main Oscillator Register
#define AT91C_CKGR_MCFR (AT91_CAST(AT91_REG *) 	0x400E0424) // (CKGR) Main Clock  Frequency Register
#define AT91C_CKGR_PLLBR (AT91_CAST(AT91_REG *) 	0x400E042C) // (CKGR) PLL B Register
// ========== Register definition for RSTC peripheral ========== 
#define AT91C_RSTC_RSR  (AT91_CAST(AT91_REG *) 	0x400E1404) // (RSTC) Reset Status Register
#define AT91C_RSTC_RCR  (AT91_CAST(AT91_REG *) 	0x400E1400) // (RSTC) Reset Control Register
#define AT91C_RSTC_RMR  (AT91_CAST(AT91_REG *) 	0x400E1408) // (RSTC) Reset Mode Register
#define AT91C_RSTC_VER  (AT91_CAST(AT91_REG *) 	0x400E14FC) // (RSTC) Version Register
// ========== Register definition for SUPC peripheral ========== 
#define AT91C_SUPC_FWUTR (AT91_CAST(AT91_REG *) 	0x400E1428) // (SUPC) Flash Wake-up Timer Register
#define AT91C_SUPC_SR   (AT91_CAST(AT91_REG *) 	0x400E1424) // (SUPC) Status Register
#define AT91C_SUPC_BOMR (AT91_CAST(AT91_REG *) 	0x400E1414) // (SUPC) Brown Out Mode Register
#define AT91C_SUPC_WUMR (AT91_CAST(AT91_REG *) 	0x400E141C) // (SUPC) Wake Up Mode Register
#define AT91C_SUPC_WUIR (AT91_CAST(AT91_REG *) 	0x400E1420) // (SUPC) Wake Up Inputs Register
#define AT91C_SUPC_CR   (AT91_CAST(AT91_REG *) 	0x400E1410) // (SUPC) Control Register
#define AT91C_SUPC_MR   (AT91_CAST(AT91_REG *) 	0x400E1418) // (SUPC) Mode Register
// ========== Register definition for RTTC peripheral ========== 
#define AT91C_RTTC_RTSR (AT91_CAST(AT91_REG *) 	0x400E143C) // (RTTC) Real-time Status Register
#define AT91C_RTTC_RTVR (AT91_CAST(AT91_REG *) 	0x400E1438) // (RTTC) Real-time Value Register
#define AT91C_RTTC_RTMR (AT91_CAST(AT91_REG *) 	0x400E1430) // (RTTC) Real-time Mode Register
#define AT91C_RTTC_RTAR (AT91_CAST(AT91_REG *) 	0x400E1434) // (RTTC) Real-time Alarm Register
// ========== Register definition for WDTC peripheral ========== 
#define AT91C_WDTC_WDCR (AT91_CAST(AT91_REG *) 	0x400E1450) // (WDTC) Watchdog Control Register
#define AT91C_WDTC_WDMR (AT91_CAST(AT91_REG *) 	0x400E1454) // (WDTC) Watchdog Mode Register
#define AT91C_WDTC_WDSR (AT91_CAST(AT91_REG *) 	0x400E1458) // (WDTC) Watchdog Status Register
// ========== Register definition for RTC peripheral ========== 
#define AT91C_RTC_VER   (AT91_CAST(AT91_REG *) 	0x400E148C) // (RTC) Valid Entry Register
#define AT91C_RTC_TIMR  (AT91_CAST(AT91_REG *) 	0x400E1468) // (RTC) Time Register
#define AT91C_RTC_CALALR (AT91_CAST(AT91_REG *) 	0x400E1474) // (RTC) Calendar Alarm Register
#define AT91C_RTC_IER   (AT91_CAST(AT91_REG *) 	0x400E1480) // (RTC) Interrupt Enable Register
#define AT91C_RTC_MR    (AT91_CAST(AT91_REG *) 	0x400E1464) // (RTC) Mode Register
#define AT91C_RTC_CALR  (AT91_CAST(AT91_REG *) 	0x400E146C) // (RTC) Calendar Register
#define AT91C_RTC_TIMALR (AT91_CAST(AT91_REG *) 	0x400E1470) // (RTC) Time Alarm Register
#define AT91C_RTC_SCCR  (AT91_CAST(AT91_REG *) 	0x400E147C) // (RTC) Status Clear Command Register
#define AT91C_RTC_CR    (AT91_CAST(AT91_REG *) 	0x400E1460) // (RTC) Control Register
#define AT91C_RTC_IDR   (AT91_CAST(AT91_REG *) 	0x400E1484) // (RTC) Interrupt Disable Register
#define AT91C_RTC_IMR   (AT91_CAST(AT91_REG *) 	0x400E1488) // (RTC) Interrupt Mask Register
#define AT91C_RTC_SR    (AT91_CAST(AT91_REG *) 	0x400E1478) // (RTC) Status Register
// ========== Register definition for ADC0 peripheral ========== 
#define AT91C_ADC0_CDR2 (AT91_CAST(AT91_REG *) 	0x40038058) // (ADC0) ADC Channel Data Register 2
#define AT91C_ADC0_CGR  (AT91_CAST(AT91_REG *) 	0x40038048) // (ADC0) Control gain register
#define AT91C_ADC0_CDR7 (AT91_CAST(AT91_REG *) 	0x4003806C) // (ADC0) ADC Channel Data Register 7
#define AT91C_ADC0_IDR  (AT91_CAST(AT91_REG *) 	0x40038028) // (ADC0) ADC Interrupt Disable Register
#define AT91C_ADC0_CR   (AT91_CAST(AT91_REG *) 	0x40038000) // (ADC0) ADC Control Register
#define AT91C_ADC0_FEATURES (AT91_CAST(AT91_REG *) 	0x400380F8) // (ADC0) ADC FEATURES REGISTER 
#define AT91C_ADC0_CWR  (AT91_CAST(AT91_REG *) 	0x40038040) // (ADC0) unspecified
#define AT91C_ADC0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400380F0) // (ADC0) ADC IPNAME1 REGISTER 
#define AT91C_ADC0_CDR9 (AT91_CAST(AT91_REG *) 	0x40038074) // (ADC0) ADC Channel Data Register 9
#define AT91C_ADC0_CDR3 (AT91_CAST(AT91_REG *) 	0x4003805C) // (ADC0) ADC Channel Data Register 3
#define AT91C_ADC0_SR   (AT91_CAST(AT91_REG *) 	0x40038030) // (ADC0) ADC Status Register
#define AT91C_ADC0_CHER (AT91_CAST(AT91_REG *) 	0x40038010) // (ADC0) ADC Channel Enable Register
#define AT91C_ADC0_CDR1 (AT91_CAST(AT91_REG *) 	0x40038054) // (ADC0) ADC Channel Data Register 1
#define AT91C_ADC0_CDR6 (AT91_CAST(AT91_REG *) 	0x40038068) // (ADC0) ADC Channel Data Register 6
#define AT91C_ADC0_MR   (AT91_CAST(AT91_REG *) 	0x40038004) // (ADC0) ADC Mode Register
#define AT91C_ADC0_CWSR (AT91_CAST(AT91_REG *) 	0x40038044) // (ADC0) unspecified
#define AT91C_ADC0_VER  (AT91_CAST(AT91_REG *) 	0x400380FC) // (ADC0) ADC VERSION REGISTER
#define AT91C_ADC0_COR  (AT91_CAST(AT91_REG *) 	0x4003804C) // (ADC0) unspecified
#define AT91C_ADC0_CDR8 (AT91_CAST(AT91_REG *) 	0x40038070) // (ADC0) ADC Channel Data Register 8
#define AT91C_ADC0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400380F4) // (ADC0) ADC IPNAME2 REGISTER 
#define AT91C_ADC0_CDR0 (AT91_CAST(AT91_REG *) 	0x40038050) // (ADC0) ADC Channel Data Register 0
#define AT91C_ADC0_LCDR (AT91_CAST(AT91_REG *) 	0x40038020) // (ADC0) ADC Last Converted Data Register
#define AT91C_ADC0_CDR12 (AT91_CAST(AT91_REG *) 	0x40038080) // (ADC0) ADC Channel Data Register 12
#define AT91C_ADC0_CHDR (AT91_CAST(AT91_REG *) 	0x40038014) // (ADC0) ADC Channel Disable Register
#define AT91C_ADC0_OVR  (AT91_CAST(AT91_REG *) 	0x4003803C) // (ADC0) unspecified
#define AT91C_ADC0_CDR15 (AT91_CAST(AT91_REG *) 	0x4003808C) // (ADC0) ADC Channel Data Register 15
#define AT91C_ADC0_CDR11 (AT91_CAST(AT91_REG *) 	0x4003807C) // (ADC0) ADC Channel Data Register 11
#define AT91C_ADC0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400380EC) // (ADC0) ADC ADDRSIZE REGISTER 
#define AT91C_ADC0_CDR13 (AT91_CAST(AT91_REG *) 	0x40038084) // (ADC0) ADC Channel Data Register 13
#define AT91C_ADC0_ACR  (AT91_CAST(AT91_REG *) 	0x40038094) // (ADC0) unspecified
#define AT91C_ADC0_CDR5 (AT91_CAST(AT91_REG *) 	0x40038064) // (ADC0) ADC Channel Data Register 5
#define AT91C_ADC0_CDR14 (AT91_CAST(AT91_REG *) 	0x40038088) // (ADC0) ADC Channel Data Register 14
#define AT91C_ADC0_IMR  (AT91_CAST(AT91_REG *) 	0x4003802C) // (ADC0) ADC Interrupt Mask Register
#define AT91C_ADC0_CHSR (AT91_CAST(AT91_REG *) 	0x40038018) // (ADC0) ADC Channel Status Register
#define AT91C_ADC0_CDR10 (AT91_CAST(AT91_REG *) 	0x40038078) // (ADC0) ADC Channel Data Register 10
#define AT91C_ADC0_IER  (AT91_CAST(AT91_REG *) 	0x40038024) // (ADC0) ADC Interrupt Enable Register
#define AT91C_ADC0_CDR4 (AT91_CAST(AT91_REG *) 	0x40038060) // (ADC0) ADC Channel Data Register 4
// ========== Register definition for DAC0 peripheral ========== 
#define AT91C_DAC0_FEATURES (AT91_CAST(AT91_REG *) 	0x4003C0F8) // (DAC0) DAC FEATURES REGISTER 
#define AT91C_DAC0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4003C0EC) // (DAC0) DAC ADDRSIZE REGISTER 
#define AT91C_DAC0_WPMR (AT91_CAST(AT91_REG *) 	0x4003C0E4) // (DAC0) Write Protect Mode Register
#define AT91C_DAC0_CHDR (AT91_CAST(AT91_REG *) 	0x4003C014) // (DAC0) Channel Disable Register
#define AT91C_DAC0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x4003C0F0) // (DAC0) DAC IPNAME1 REGISTER 
#define AT91C_DAC0_IDR  (AT91_CAST(AT91_REG *) 	0x4003C028) // (DAC0) Interrupt Disable Register
#define AT91C_DAC0_CR   (AT91_CAST(AT91_REG *) 	0x4003C000) // (DAC0) Control Register
#define AT91C_DAC0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x4003C0F4) // (DAC0) DAC IPNAME2 REGISTER 
#define AT91C_DAC0_IMR  (AT91_CAST(AT91_REG *) 	0x4003C02C) // (DAC0) Interrupt Mask Register
#define AT91C_DAC0_CHSR (AT91_CAST(AT91_REG *) 	0x4003C018) // (DAC0) Channel Status Register
#define AT91C_DAC0_ACR  (AT91_CAST(AT91_REG *) 	0x4003C094) // (DAC0) Analog Current Register
#define AT91C_DAC0_WPSR (AT91_CAST(AT91_REG *) 	0x4003C0E8) // (DAC0) Write Protect Status Register
#define AT91C_DAC0_CHER (AT91_CAST(AT91_REG *) 	0x4003C010) // (DAC0) Channel Enable Register
#define AT91C_DAC0_CDR  (AT91_CAST(AT91_REG *) 	0x4003C020) // (DAC0) Coversion Data Register
#define AT91C_DAC0_IER  (AT91_CAST(AT91_REG *) 	0x4003C024) // (DAC0) Interrupt Enable Register
#define AT91C_DAC0_ISR  (AT91_CAST(AT91_REG *) 	0x4003C030) // (DAC0) Interrupt Status Register
#define AT91C_DAC0_VER  (AT91_CAST(AT91_REG *) 	0x4003C0FC) // (DAC0) DAC VERSION REGISTER
#define AT91C_DAC0_MR   (AT91_CAST(AT91_REG *) 	0x4003C004) // (DAC0) Mode Register
// ========== Register definition for ACC0 peripheral ========== 
#define AT91C_ACC0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400400F0) // (ACC0) ACC IPNAME1 REGISTER 
#define AT91C_ACC0_MR   (AT91_CAST(AT91_REG *) 	0x40040004) // (ACC0) Mode Register
#define AT91C_ACC0_FEATURES (AT91_CAST(AT91_REG *) 	0x400400F8) // (ACC0) ACC FEATURES REGISTER 
#define AT91C_ACC0_IMR  (AT91_CAST(AT91_REG *) 	0x4004002C) // (ACC0) Interrupt Mask Register
#define AT91C_ACC0_ACR  (AT91_CAST(AT91_REG *) 	0x40040094) // (ACC0) Analog Control Register
#define AT91C_ACC0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400400EC) // (ACC0) ACC ADDRSIZE REGISTER 
#define AT91C_ACC0_IER  (AT91_CAST(AT91_REG *) 	0x40040024) // (ACC0) Interrupt Enable Register
#define AT91C_ACC0_ISR  (AT91_CAST(AT91_REG *) 	0x40040030) // (ACC0) Interrupt Status Register
#define AT91C_ACC0_IDR  (AT91_CAST(AT91_REG *) 	0x40040028) // (ACC0) Interrupt Disable Register
#define AT91C_ACC0_MODE (AT91_CAST(AT91_REG *) 	0x400400E4) // (ACC0) Write Protection Mode Register
#define AT91C_ACC0_VER  (AT91_CAST(AT91_REG *) 	0x400400FC) // (ACC0) ACC VERSION REGISTER
#define AT91C_ACC0_CR   (AT91_CAST(AT91_REG *) 	0x40040000) // (ACC0) Control Register
#define AT91C_ACC0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400400F4) // (ACC0) ACC IPNAME2 REGISTER 
#define AT91C_ACC0_STATUS (AT91_CAST(AT91_REG *) 	0x400400E8) // (ACC0) Write Protection Status
// ========== Register definition for HCBDMA peripheral ========== 
#define AT91C_HCBDMA_CBIMR (AT91_CAST(AT91_REG *) 	0x4004401C) // (HCBDMA) CB DMA Interrupt mask Register
#define AT91C_HCBDMA_CBCRCCR (AT91_CAST(AT91_REG *) 	0x40044034) // (HCBDMA) CB DMA CRC Control Resgister
#define AT91C_HCBDMA_CBSR (AT91_CAST(AT91_REG *) 	0x40044010) // (HCBDMA) CB DMA Status Register
#define AT91C_HCBDMA_CBCRCISR (AT91_CAST(AT91_REG *) 	0x4004404C) // (HCBDMA) CB DMA CRC Interrupt Status Resgister
#define AT91C_HCBDMA_CBCRCSR (AT91_CAST(AT91_REG *) 	0x4004403C) // (HCBDMA) CB DMA CRC Status Resgister
#define AT91C_HCBDMA_CBIDR (AT91_CAST(AT91_REG *) 	0x40044018) // (HCBDMA) CB DMA Interrupt Disable Register
#define AT91C_HCBDMA_CBCRCIDR (AT91_CAST(AT91_REG *) 	0x40044044) // (HCBDMA) CB DMA CRC Interrupt Disable Resgister
#define AT91C_HCBDMA_CBDLIER (AT91_CAST(AT91_REG *) 	0x40044024) // (HCBDMA) CB DMA Loaded Interrupt Enable Register
#define AT91C_HCBDMA_CBEN (AT91_CAST(AT91_REG *) 	0x40044008) // (HCBDMA) CB DMA Enable Register
#define AT91C_HCBDMA_FEATURES (AT91_CAST(AT91_REG *) 	0x400440F8) // (HCBDMA) HCBDMA FEATURES REGISTER 
#define AT91C_HCBDMA_CBDSCR (AT91_CAST(AT91_REG *) 	0x40044000) // (HCBDMA) CB DMA Descriptor Base Register
#define AT91C_HCBDMA_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400440EC) // (HCBDMA) HCBDMA ADDRSIZE REGISTER 
#define AT91C_HCBDMA_CBDLISR (AT91_CAST(AT91_REG *) 	0x40044030) // (HCBDMA) CB DMA Loaded Interrupt Status Register
#define AT91C_HCBDMA_CBDLIDR (AT91_CAST(AT91_REG *) 	0x40044028) // (HCBDMA) CB DMA Loaded Interrupt Disable Register
#define AT91C_HCBDMA_CBCRCIMR (AT91_CAST(AT91_REG *) 	0x40044048) // (HCBDMA) CB DMA CRC Interrupt Mask Resgister
#define AT91C_HCBDMA_VER (AT91_CAST(AT91_REG *) 	0x400440FC) // (HCBDMA) HCBDMA VERSION REGISTER
#define AT91C_HCBDMA_CBCRCIER (AT91_CAST(AT91_REG *) 	0x40044040) // (HCBDMA) CB DMA CRC Interrupt Enable Resgister
#define AT91C_HCBDMA_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400440F4) // (HCBDMA) HCBDMA IPNAME2 REGISTER 
#define AT91C_HCBDMA_CBIER (AT91_CAST(AT91_REG *) 	0x40044014) // (HCBDMA) CB DMA Interrupt Enable Register
#define AT91C_HCBDMA_CBISR (AT91_CAST(AT91_REG *) 	0x40044020) // (HCBDMA) CB DMA Interrupt Status Register
#define AT91C_HCBDMA_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400440F0) // (HCBDMA) HCBDMA IPNAME1 REGISTER 
#define AT91C_HCBDMA_CBDIS (AT91_CAST(AT91_REG *) 	0x4004400C) // (HCBDMA) CB DMA Disable Register
#define AT91C_HCBDMA_CBNXTEN (AT91_CAST(AT91_REG *) 	0x40044004) // (HCBDMA) CB DMA Next Descriptor Enable Register
#define AT91C_HCBDMA_CBDLIMR (AT91_CAST(AT91_REG *) 	0x4004402C) // (HCBDMA) CB DMA Loaded Interrupt mask Register
#define AT91C_HCBDMA_CBCRCMR (AT91_CAST(AT91_REG *) 	0x40044038) // (HCBDMA) CB DMA CRC Mode Resgister
// ========== Register definition for TC0 peripheral ========== 
#define AT91C_TC0_SR    (AT91_CAST(AT91_REG *) 	0x40010020) // (TC0) Status Register
#define AT91C_TC0_CCR   (AT91_CAST(AT91_REG *) 	0x40010000) // (TC0) Channel Control Register
#define AT91C_TC0_CMR   (AT91_CAST(AT91_REG *) 	0x40010004) // (TC0) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC0_IER   (AT91_CAST(AT91_REG *) 	0x40010024) // (TC0) Interrupt Enable Register
#define AT91C_TC0_CV    (AT91_CAST(AT91_REG *) 	0x40010010) // (TC0) Counter Value
#define AT91C_TC0_RB    (AT91_CAST(AT91_REG *) 	0x40010018) // (TC0) Register B
#define AT91C_TC0_IDR   (AT91_CAST(AT91_REG *) 	0x40010028) // (TC0) Interrupt Disable Register
#define AT91C_TC0_RA    (AT91_CAST(AT91_REG *) 	0x40010014) // (TC0) Register A
#define AT91C_TC0_RC    (AT91_CAST(AT91_REG *) 	0x4001001C) // (TC0) Register C
#define AT91C_TC0_IMR   (AT91_CAST(AT91_REG *) 	0x4001002C) // (TC0) Interrupt Mask Register
// ========== Register definition for TC1 peripheral ========== 
#define AT91C_TC1_SR    (AT91_CAST(AT91_REG *) 	0x40010060) // (TC1) Status Register
#define AT91C_TC1_CV    (AT91_CAST(AT91_REG *) 	0x40010050) // (TC1) Counter Value
#define AT91C_TC1_RA    (AT91_CAST(AT91_REG *) 	0x40010054) // (TC1) Register A
#define AT91C_TC1_IER   (AT91_CAST(AT91_REG *) 	0x40010064) // (TC1) Interrupt Enable Register
#define AT91C_TC1_RB    (AT91_CAST(AT91_REG *) 	0x40010058) // (TC1) Register B
#define AT91C_TC1_RC    (AT91_CAST(AT91_REG *) 	0x4001005C) // (TC1) Register C
#define AT91C_TC1_CCR   (AT91_CAST(AT91_REG *) 	0x40010040) // (TC1) Channel Control Register
#define AT91C_TC1_IMR   (AT91_CAST(AT91_REG *) 	0x4001006C) // (TC1) Interrupt Mask Register
#define AT91C_TC1_IDR   (AT91_CAST(AT91_REG *) 	0x40010068) // (TC1) Interrupt Disable Register
#define AT91C_TC1_CMR   (AT91_CAST(AT91_REG *) 	0x40010044) // (TC1) Channel Mode Register (Capture Mode / Waveform Mode)
// ========== Register definition for TC2 peripheral ========== 
#define AT91C_TC2_SR    (AT91_CAST(AT91_REG *) 	0x400100A0) // (TC2) Status Register
#define AT91C_TC2_IER   (AT91_CAST(AT91_REG *) 	0x400100A4) // (TC2) Interrupt Enable Register
#define AT91C_TC2_CCR   (AT91_CAST(AT91_REG *) 	0x40010080) // (TC2) Channel Control Register
#define AT91C_TC2_IDR   (AT91_CAST(AT91_REG *) 	0x400100A8) // (TC2) Interrupt Disable Register
#define AT91C_TC2_RA    (AT91_CAST(AT91_REG *) 	0x40010094) // (TC2) Register A
#define AT91C_TC2_RB    (AT91_CAST(AT91_REG *) 	0x40010098) // (TC2) Register B
#define AT91C_TC2_IMR   (AT91_CAST(AT91_REG *) 	0x400100AC) // (TC2) Interrupt Mask Register
#define AT91C_TC2_CV    (AT91_CAST(AT91_REG *) 	0x40010090) // (TC2) Counter Value
#define AT91C_TC2_RC    (AT91_CAST(AT91_REG *) 	0x4001009C) // (TC2) Register C
#define AT91C_TC2_CMR   (AT91_CAST(AT91_REG *) 	0x40010084) // (TC2) Channel Mode Register (Capture Mode / Waveform Mode)
// ========== Register definition for TC3 peripheral ========== 
#define AT91C_TC3_IDR   (AT91_CAST(AT91_REG *) 	0x40014028) // (TC3) Interrupt Disable Register
#define AT91C_TC3_IER   (AT91_CAST(AT91_REG *) 	0x40014024) // (TC3) Interrupt Enable Register
#define AT91C_TC3_SR    (AT91_CAST(AT91_REG *) 	0x40014020) // (TC3) Status Register
#define AT91C_TC3_CV    (AT91_CAST(AT91_REG *) 	0x40014010) // (TC3) Counter Value
#define AT91C_TC3_CMR   (AT91_CAST(AT91_REG *) 	0x40014004) // (TC3) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC3_RC    (AT91_CAST(AT91_REG *) 	0x4001401C) // (TC3) Register C
#define AT91C_TC3_RA    (AT91_CAST(AT91_REG *) 	0x40014014) // (TC3) Register A
#define AT91C_TC3_IMR   (AT91_CAST(AT91_REG *) 	0x4001402C) // (TC3) Interrupt Mask Register
#define AT91C_TC3_RB    (AT91_CAST(AT91_REG *) 	0x40014018) // (TC3) Register B
#define AT91C_TC3_CCR   (AT91_CAST(AT91_REG *) 	0x40014000) // (TC3) Channel Control Register
// ========== Register definition for TC4 peripheral ========== 
#define AT91C_TC4_CV    (AT91_CAST(AT91_REG *) 	0x40014050) // (TC4) Counter Value
#define AT91C_TC4_CMR   (AT91_CAST(AT91_REG *) 	0x40014044) // (TC4) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC4_RA    (AT91_CAST(AT91_REG *) 	0x40014054) // (TC4) Register A
#define AT91C_TC4_IMR   (AT91_CAST(AT91_REG *) 	0x4001406C) // (TC4) Interrupt Mask Register
#define AT91C_TC4_RC    (AT91_CAST(AT91_REG *) 	0x4001405C) // (TC4) Register C
#define AT91C_TC4_SR    (AT91_CAST(AT91_REG *) 	0x40014060) // (TC4) Status Register
#define AT91C_TC4_RB    (AT91_CAST(AT91_REG *) 	0x40014058) // (TC4) Register B
#define AT91C_TC4_IDR   (AT91_CAST(AT91_REG *) 	0x40014068) // (TC4) Interrupt Disable Register
#define AT91C_TC4_IER   (AT91_CAST(AT91_REG *) 	0x40014064) // (TC4) Interrupt Enable Register
#define AT91C_TC4_CCR   (AT91_CAST(AT91_REG *) 	0x40014040) // (TC4) Channel Control Register
// ========== Register definition for TC5 peripheral ========== 
#define AT91C_TC5_CV    (AT91_CAST(AT91_REG *) 	0x40014090) // (TC5) Counter Value
#define AT91C_TC5_IER   (AT91_CAST(AT91_REG *) 	0x400140A4) // (TC5) Interrupt Enable Register
#define AT91C_TC5_CMR   (AT91_CAST(AT91_REG *) 	0x40014084) // (TC5) Channel Mode Register (Capture Mode / Waveform Mode)
#define AT91C_TC5_IMR   (AT91_CAST(AT91_REG *) 	0x400140AC) // (TC5) Interrupt Mask Register
#define AT91C_TC5_RA    (AT91_CAST(AT91_REG *) 	0x40014094) // (TC5) Register A
#define AT91C_TC5_RB    (AT91_CAST(AT91_REG *) 	0x40014098) // (TC5) Register B
#define AT91C_TC5_RC    (AT91_CAST(AT91_REG *) 	0x4001409C) // (TC5) Register C
#define AT91C_TC5_SR    (AT91_CAST(AT91_REG *) 	0x400140A0) // (TC5) Status Register
#define AT91C_TC5_CCR   (AT91_CAST(AT91_REG *) 	0x40014080) // (TC5) Channel Control Register
#define AT91C_TC5_IDR   (AT91_CAST(AT91_REG *) 	0x400140A8) // (TC5) Interrupt Disable Register
// ========== Register definition for TCB0 peripheral ========== 
#define AT91C_TCB0_BCR  (AT91_CAST(AT91_REG *) 	0x400100C0) // (TCB0) TC Block Control Register
#define AT91C_TCB0_VER  (AT91_CAST(AT91_REG *) 	0x400100FC) // (TCB0)  Version Register
#define AT91C_TCB0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400100EC) // (TCB0) TC ADDRSIZE REGISTER 
#define AT91C_TCB0_FEATURES (AT91_CAST(AT91_REG *) 	0x400100F8) // (TCB0) TC FEATURES REGISTER 
#define AT91C_TCB0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400100F4) // (TCB0) TC IPNAME2 REGISTER 
#define AT91C_TCB0_BMR  (AT91_CAST(AT91_REG *) 	0x400100C4) // (TCB0) TC Block Mode Register
#define AT91C_TCB0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400100F0) // (TCB0) TC IPNAME1 REGISTER 
// ========== Register definition for TCB1 peripheral ========== 
#define AT91C_TCB1_IPNAME1 (AT91_CAST(AT91_REG *) 	0x40010130) // (TCB1) TC IPNAME1 REGISTER 
#define AT91C_TCB1_IPNAME2 (AT91_CAST(AT91_REG *) 	0x40010134) // (TCB1) TC IPNAME2 REGISTER 
#define AT91C_TCB1_BCR  (AT91_CAST(AT91_REG *) 	0x40010100) // (TCB1) TC Block Control Register
#define AT91C_TCB1_VER  (AT91_CAST(AT91_REG *) 	0x4001013C) // (TCB1)  Version Register
#define AT91C_TCB1_FEATURES (AT91_CAST(AT91_REG *) 	0x40010138) // (TCB1) TC FEATURES REGISTER 
#define AT91C_TCB1_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4001012C) // (TCB1) TC ADDRSIZE REGISTER 
#define AT91C_TCB1_BMR  (AT91_CAST(AT91_REG *) 	0x40010104) // (TCB1) TC Block Mode Register
// ========== Register definition for TCB2 peripheral ========== 
#define AT91C_TCB2_VER  (AT91_CAST(AT91_REG *) 	0x4001017C) // (TCB2)  Version Register
#define AT91C_TCB2_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4001016C) // (TCB2) TC ADDRSIZE REGISTER 
#define AT91C_TCB2_FEATURES (AT91_CAST(AT91_REG *) 	0x40010178) // (TCB2) TC FEATURES REGISTER 
#define AT91C_TCB2_BCR  (AT91_CAST(AT91_REG *) 	0x40010140) // (TCB2) TC Block Control Register
#define AT91C_TCB2_IPNAME2 (AT91_CAST(AT91_REG *) 	0x40010174) // (TCB2) TC IPNAME2 REGISTER 
#define AT91C_TCB2_BMR  (AT91_CAST(AT91_REG *) 	0x40010144) // (TCB2) TC Block Mode Register
#define AT91C_TCB2_IPNAME1 (AT91_CAST(AT91_REG *) 	0x40010170) // (TCB2) TC IPNAME1 REGISTER 
// ========== Register definition for TCB3 peripheral ========== 
#define AT91C_TCB3_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400140F4) // (TCB3) TC IPNAME2 REGISTER 
#define AT91C_TCB3_BMR  (AT91_CAST(AT91_REG *) 	0x400140C4) // (TCB3) TC Block Mode Register
#define AT91C_TCB3_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400140F0) // (TCB3) TC IPNAME1 REGISTER 
#define AT91C_TCB3_FEATURES (AT91_CAST(AT91_REG *) 	0x400140F8) // (TCB3) TC FEATURES REGISTER 
#define AT91C_TCB3_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400140EC) // (TCB3) TC ADDRSIZE REGISTER 
#define AT91C_TCB3_VER  (AT91_CAST(AT91_REG *) 	0x400140FC) // (TCB3)  Version Register
#define AT91C_TCB3_BCR  (AT91_CAST(AT91_REG *) 	0x400140C0) // (TCB3) TC Block Control Register
// ========== Register definition for TCB4 peripheral ========== 
#define AT91C_TCB4_BMR  (AT91_CAST(AT91_REG *) 	0x40014104) // (TCB4) TC Block Mode Register
#define AT91C_TCB4_BCR  (AT91_CAST(AT91_REG *) 	0x40014100) // (TCB4) TC Block Control Register
#define AT91C_TCB4_IPNAME2 (AT91_CAST(AT91_REG *) 	0x40014134) // (TCB4) TC IPNAME2 REGISTER 
#define AT91C_TCB4_FEATURES (AT91_CAST(AT91_REG *) 	0x40014138) // (TCB4) TC FEATURES REGISTER 
#define AT91C_TCB4_IPNAME1 (AT91_CAST(AT91_REG *) 	0x40014130) // (TCB4) TC IPNAME1 REGISTER 
#define AT91C_TCB4_VER  (AT91_CAST(AT91_REG *) 	0x4001413C) // (TCB4)  Version Register
#define AT91C_TCB4_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4001412C) // (TCB4) TC ADDRSIZE REGISTER 
// ========== Register definition for TCB5 peripheral ========== 
#define AT91C_TCB5_VER  (AT91_CAST(AT91_REG *) 	0x4001417C) // (TCB5)  Version Register
#define AT91C_TCB5_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4001416C) // (TCB5) TC ADDRSIZE REGISTER 
#define AT91C_TCB5_BMR  (AT91_CAST(AT91_REG *) 	0x40014144) // (TCB5) TC Block Mode Register
#define AT91C_TCB5_FEATURES (AT91_CAST(AT91_REG *) 	0x40014178) // (TCB5) TC FEATURES REGISTER 
#define AT91C_TCB5_IPNAME2 (AT91_CAST(AT91_REG *) 	0x40014174) // (TCB5) TC IPNAME2 REGISTER 
#define AT91C_TCB5_IPNAME1 (AT91_CAST(AT91_REG *) 	0x40014170) // (TCB5) TC IPNAME1 REGISTER 
#define AT91C_TCB5_BCR  (AT91_CAST(AT91_REG *) 	0x40014140) // (TCB5) TC Block Control Register
// ========== Register definition for EFC0 peripheral ========== 
#define AT91C_EFC0_FMR  (AT91_CAST(AT91_REG *) 	0x400E0A00) // (EFC0) EFC Flash Mode Register
#define AT91C_EFC0_FVR  (AT91_CAST(AT91_REG *) 	0x400E0A14) // (EFC0) EFC Flash Version Register
#define AT91C_EFC0_FSR  (AT91_CAST(AT91_REG *) 	0x400E0A08) // (EFC0) EFC Flash Status Register
#define AT91C_EFC0_FCR  (AT91_CAST(AT91_REG *) 	0x400E0A04) // (EFC0) EFC Flash Command Register
#define AT91C_EFC0_FRR  (AT91_CAST(AT91_REG *) 	0x400E0A0C) // (EFC0) EFC Flash Result Register
// ========== Register definition for MCI0 peripheral ========== 
#define AT91C_MCI0_DMA  (AT91_CAST(AT91_REG *) 	0x40000050) // (MCI0) MCI DMA Configuration Register
#define AT91C_MCI0_SDCR (AT91_CAST(AT91_REG *) 	0x4000000C) // (MCI0) MCI SD/SDIO Card Register
#define AT91C_MCI0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400000F0) // (MCI0) MCI IPNAME1 REGISTER 
#define AT91C_MCI0_CSTOR (AT91_CAST(AT91_REG *) 	0x4000001C) // (MCI0) MCI Completion Signal Timeout Register
#define AT91C_MCI0_RDR  (AT91_CAST(AT91_REG *) 	0x40000030) // (MCI0) MCI Receive Data Register
#define AT91C_MCI0_CMDR (AT91_CAST(AT91_REG *) 	0x40000014) // (MCI0) MCI Command Register
#define AT91C_MCI0_IDR  (AT91_CAST(AT91_REG *) 	0x40000048) // (MCI0) MCI Interrupt Disable Register
#define AT91C_MCI0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400000EC) // (MCI0) MCI ADDRSIZE REGISTER 
#define AT91C_MCI0_WPCR (AT91_CAST(AT91_REG *) 	0x400000E4) // (MCI0) MCI Write Protection Control Register
#define AT91C_MCI0_RSPR (AT91_CAST(AT91_REG *) 	0x40000020) // (MCI0) MCI Response Register
#define AT91C_MCI0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400000F4) // (MCI0) MCI IPNAME2 REGISTER 
#define AT91C_MCI0_CR   (AT91_CAST(AT91_REG *) 	0x40000000) // (MCI0) MCI Control Register
#define AT91C_MCI0_IMR  (AT91_CAST(AT91_REG *) 	0x4000004C) // (MCI0) MCI Interrupt Mask Register
#define AT91C_MCI0_WPSR (AT91_CAST(AT91_REG *) 	0x400000E8) // (MCI0) MCI Write Protection Status Register
#define AT91C_MCI0_DTOR (AT91_CAST(AT91_REG *) 	0x40000008) // (MCI0) MCI Data Timeout Register
#define AT91C_MCI0_MR   (AT91_CAST(AT91_REG *) 	0x40000004) // (MCI0) MCI Mode Register
#define AT91C_MCI0_SR   (AT91_CAST(AT91_REG *) 	0x40000040) // (MCI0) MCI Status Register
#define AT91C_MCI0_IER  (AT91_CAST(AT91_REG *) 	0x40000044) // (MCI0) MCI Interrupt Enable Register
#define AT91C_MCI0_VER  (AT91_CAST(AT91_REG *) 	0x400000FC) // (MCI0) MCI VERSION REGISTER 
#define AT91C_MCI0_FEATURES (AT91_CAST(AT91_REG *) 	0x400000F8) // (MCI0) MCI FEATURES REGISTER 
#define AT91C_MCI0_BLKR (AT91_CAST(AT91_REG *) 	0x40000018) // (MCI0) MCI Block Register
#define AT91C_MCI0_ARGR (AT91_CAST(AT91_REG *) 	0x40000010) // (MCI0) MCI Argument Register
#define AT91C_MCI0_FIFO (AT91_CAST(AT91_REG *) 	0x40000200) // (MCI0) MCI FIFO Aperture Register
#define AT91C_MCI0_TDR  (AT91_CAST(AT91_REG *) 	0x40000034) // (MCI0) MCI Transmit Data Register
#define AT91C_MCI0_CFG  (AT91_CAST(AT91_REG *) 	0x40000054) // (MCI0) MCI Configuration Register
// ========== Register definition for PDC_TWI0 peripheral ========== 
#define AT91C_TWI0_PTSR (AT91_CAST(AT91_REG *) 	0x40018124) // (PDC_TWI0) PDC Transfer Status Register
#define AT91C_TWI0_TPR  (AT91_CAST(AT91_REG *) 	0x40018108) // (PDC_TWI0) Transmit Pointer Register
#define AT91C_TWI0_RPR  (AT91_CAST(AT91_REG *) 	0x40018100) // (PDC_TWI0) Receive Pointer Register
#define AT91C_TWI0_TNPR (AT91_CAST(AT91_REG *) 	0x40018118) // (PDC_TWI0) Transmit Next Pointer Register
#define AT91C_TWI0_PTCR (AT91_CAST(AT91_REG *) 	0x40018120) // (PDC_TWI0) PDC Transfer Control Register
#define AT91C_TWI0_RCR  (AT91_CAST(AT91_REG *) 	0x40018104) // (PDC_TWI0) Receive Counter Register
#define AT91C_TWI0_RNCR (AT91_CAST(AT91_REG *) 	0x40018114) // (PDC_TWI0) Receive Next Counter Register
#define AT91C_TWI0_RNPR (AT91_CAST(AT91_REG *) 	0x40018110) // (PDC_TWI0) Receive Next Pointer Register
#define AT91C_TWI0_TNCR (AT91_CAST(AT91_REG *) 	0x4001811C) // (PDC_TWI0) Transmit Next Counter Register
#define AT91C_TWI0_TCR  (AT91_CAST(AT91_REG *) 	0x4001810C) // (PDC_TWI0) Transmit Counter Register
// ========== Register definition for PDC_TWI1 peripheral ========== 
#define AT91C_TWI1_TPR  (AT91_CAST(AT91_REG *) 	0x4001C108) // (PDC_TWI1) Transmit Pointer Register
#define AT91C_TWI1_RNCR (AT91_CAST(AT91_REG *) 	0x4001C114) // (PDC_TWI1) Receive Next Counter Register
#define AT91C_TWI1_TNCR (AT91_CAST(AT91_REG *) 	0x4001C11C) // (PDC_TWI1) Transmit Next Counter Register
#define AT91C_TWI1_TCR  (AT91_CAST(AT91_REG *) 	0x4001C10C) // (PDC_TWI1) Transmit Counter Register
#define AT91C_TWI1_TNPR (AT91_CAST(AT91_REG *) 	0x4001C118) // (PDC_TWI1) Transmit Next Pointer Register
#define AT91C_TWI1_PTCR (AT91_CAST(AT91_REG *) 	0x4001C120) // (PDC_TWI1) PDC Transfer Control Register
#define AT91C_TWI1_RNPR (AT91_CAST(AT91_REG *) 	0x4001C110) // (PDC_TWI1) Receive Next Pointer Register
#define AT91C_TWI1_PTSR (AT91_CAST(AT91_REG *) 	0x4001C124) // (PDC_TWI1) PDC Transfer Status Register
#define AT91C_TWI1_RPR  (AT91_CAST(AT91_REG *) 	0x4001C100) // (PDC_TWI1) Receive Pointer Register
#define AT91C_TWI1_RCR  (AT91_CAST(AT91_REG *) 	0x4001C104) // (PDC_TWI1) Receive Counter Register
// ========== Register definition for TWI0 peripheral ========== 
#define AT91C_TWI0_IMR  (AT91_CAST(AT91_REG *) 	0x4001802C) // (TWI0) Interrupt Mask Register
#define AT91C_TWI0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400180F0) // (TWI0) TWI IPNAME1 REGISTER 
#define AT91C_TWI0_CR   (AT91_CAST(AT91_REG *) 	0x40018000) // (TWI0) Control Register
#define AT91C_TWI0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400180F4) // (TWI0) TWI IPNAME2 REGISTER 
#define AT91C_TWI0_CWGR (AT91_CAST(AT91_REG *) 	0x40018010) // (TWI0) Clock Waveform Generator Register
#define AT91C_TWI0_SMR  (AT91_CAST(AT91_REG *) 	0x40018008) // (TWI0) Slave Mode Register
#define AT91C_TWI0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400180EC) // (TWI0) TWI ADDRSIZE REGISTER 
#define AT91C_TWI0_SR   (AT91_CAST(AT91_REG *) 	0x40018020) // (TWI0) Status Register
#define AT91C_TWI0_IER  (AT91_CAST(AT91_REG *) 	0x40018024) // (TWI0) Interrupt Enable Register
#define AT91C_TWI0_VER  (AT91_CAST(AT91_REG *) 	0x400180FC) // (TWI0) Version Register
#define AT91C_TWI0_RHR  (AT91_CAST(AT91_REG *) 	0x40018030) // (TWI0) Receive Holding Register
#define AT91C_TWI0_IADR (AT91_CAST(AT91_REG *) 	0x4001800C) // (TWI0) Internal Address Register
#define AT91C_TWI0_IDR  (AT91_CAST(AT91_REG *) 	0x40018028) // (TWI0) Interrupt Disable Register
#define AT91C_TWI0_THR  (AT91_CAST(AT91_REG *) 	0x40018034) // (TWI0) Transmit Holding Register
#define AT91C_TWI0_FEATURES (AT91_CAST(AT91_REG *) 	0x400180F8) // (TWI0) TWI FEATURES REGISTER 
#define AT91C_TWI0_MMR  (AT91_CAST(AT91_REG *) 	0x40018004) // (TWI0) Master Mode Register
// ========== Register definition for TWI1 peripheral ========== 
#define AT91C_TWI1_CR   (AT91_CAST(AT91_REG *) 	0x4001C000) // (TWI1) Control Register
#define AT91C_TWI1_VER  (AT91_CAST(AT91_REG *) 	0x4001C0FC) // (TWI1) Version Register
#define AT91C_TWI1_IMR  (AT91_CAST(AT91_REG *) 	0x4001C02C) // (TWI1) Interrupt Mask Register
#define AT91C_TWI1_IADR (AT91_CAST(AT91_REG *) 	0x4001C00C) // (TWI1) Internal Address Register
#define AT91C_TWI1_THR  (AT91_CAST(AT91_REG *) 	0x4001C034) // (TWI1) Transmit Holding Register
#define AT91C_TWI1_IPNAME2 (AT91_CAST(AT91_REG *) 	0x4001C0F4) // (TWI1) TWI IPNAME2 REGISTER 
#define AT91C_TWI1_FEATURES (AT91_CAST(AT91_REG *) 	0x4001C0F8) // (TWI1) TWI FEATURES REGISTER 
#define AT91C_TWI1_SMR  (AT91_CAST(AT91_REG *) 	0x4001C008) // (TWI1) Slave Mode Register
#define AT91C_TWI1_IDR  (AT91_CAST(AT91_REG *) 	0x4001C028) // (TWI1) Interrupt Disable Register
#define AT91C_TWI1_SR   (AT91_CAST(AT91_REG *) 	0x4001C020) // (TWI1) Status Register
#define AT91C_TWI1_IPNAME1 (AT91_CAST(AT91_REG *) 	0x4001C0F0) // (TWI1) TWI IPNAME1 REGISTER 
#define AT91C_TWI1_IER  (AT91_CAST(AT91_REG *) 	0x4001C024) // (TWI1) Interrupt Enable Register
#define AT91C_TWI1_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x4001C0EC) // (TWI1) TWI ADDRSIZE REGISTER 
#define AT91C_TWI1_CWGR (AT91_CAST(AT91_REG *) 	0x4001C010) // (TWI1) Clock Waveform Generator Register
#define AT91C_TWI1_MMR  (AT91_CAST(AT91_REG *) 	0x4001C004) // (TWI1) Master Mode Register
#define AT91C_TWI1_RHR  (AT91_CAST(AT91_REG *) 	0x4001C030) // (TWI1) Receive Holding Register
// ========== Register definition for PDC_US0 peripheral ========== 
#define AT91C_US0_RNCR  (AT91_CAST(AT91_REG *) 	0x40024114) // (PDC_US0) Receive Next Counter Register
#define AT91C_US0_PTCR  (AT91_CAST(AT91_REG *) 	0x40024120) // (PDC_US0) PDC Transfer Control Register
#define AT91C_US0_TCR   (AT91_CAST(AT91_REG *) 	0x4002410C) // (PDC_US0) Transmit Counter Register
#define AT91C_US0_RPR   (AT91_CAST(AT91_REG *) 	0x40024100) // (PDC_US0) Receive Pointer Register
#define AT91C_US0_RNPR  (AT91_CAST(AT91_REG *) 	0x40024110) // (PDC_US0) Receive Next Pointer Register
#define AT91C_US0_TNCR  (AT91_CAST(AT91_REG *) 	0x4002411C) // (PDC_US0) Transmit Next Counter Register
#define AT91C_US0_PTSR  (AT91_CAST(AT91_REG *) 	0x40024124) // (PDC_US0) PDC Transfer Status Register
#define AT91C_US0_RCR   (AT91_CAST(AT91_REG *) 	0x40024104) // (PDC_US0) Receive Counter Register
#define AT91C_US0_TNPR  (AT91_CAST(AT91_REG *) 	0x40024118) // (PDC_US0) Transmit Next Pointer Register
#define AT91C_US0_TPR   (AT91_CAST(AT91_REG *) 	0x40024108) // (PDC_US0) Transmit Pointer Register
// ========== Register definition for US0 peripheral ========== 
#define AT91C_US0_MAN   (AT91_CAST(AT91_REG *) 	0x40024050) // (US0) Manchester Encoder Decoder Register
#define AT91C_US0_IER   (AT91_CAST(AT91_REG *) 	0x40024008) // (US0) Interrupt Enable Register
#define AT91C_US0_NER   (AT91_CAST(AT91_REG *) 	0x40024044) // (US0) Nb Errors Register
#define AT91C_US0_BRGR  (AT91_CAST(AT91_REG *) 	0x40024020) // (US0) Baud Rate Generator Register
#define AT91C_US0_VER   (AT91_CAST(AT91_REG *) 	0x400240FC) // (US0) VERSION Register
#define AT91C_US0_IF    (AT91_CAST(AT91_REG *) 	0x4002404C) // (US0) IRDA_FILTER Register
#define AT91C_US0_RHR   (AT91_CAST(AT91_REG *) 	0x40024018) // (US0) Receiver Holding Register
#define AT91C_US0_CSR   (AT91_CAST(AT91_REG *) 	0x40024014) // (US0) Channel Status Register
#define AT91C_US0_FEATURES (AT91_CAST(AT91_REG *) 	0x400240F8) // (US0) US FEATURES REGISTER 
#define AT91C_US0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400240EC) // (US0) US ADDRSIZE REGISTER 
#define AT91C_US0_IMR   (AT91_CAST(AT91_REG *) 	0x40024010) // (US0) Interrupt Mask Register
#define AT91C_US0_THR   (AT91_CAST(AT91_REG *) 	0x4002401C) // (US0) Transmitter Holding Register
#define AT91C_US0_FIDI  (AT91_CAST(AT91_REG *) 	0x40024040) // (US0) FI_DI_Ratio Register
#define AT91C_US0_MR    (AT91_CAST(AT91_REG *) 	0x40024004) // (US0) Mode Register
#define AT91C_US0_RTOR  (AT91_CAST(AT91_REG *) 	0x40024024) // (US0) Receiver Time-out Register
#define AT91C_US0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400240F0) // (US0) US IPNAME1 REGISTER 
#define AT91C_US0_IDR   (AT91_CAST(AT91_REG *) 	0x4002400C) // (US0) Interrupt Disable Register
#define AT91C_US0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400240F4) // (US0) US IPNAME2 REGISTER 
#define AT91C_US0_CR    (AT91_CAST(AT91_REG *) 	0x40024000) // (US0) Control Register
#define AT91C_US0_TTGR  (AT91_CAST(AT91_REG *) 	0x40024028) // (US0) Transmitter Time-guard Register
// ========== Register definition for PDC_US1 peripheral ========== 
#define AT91C_US1_TNPR  (AT91_CAST(AT91_REG *) 	0x40028118) // (PDC_US1) Transmit Next Pointer Register
#define AT91C_US1_RPR   (AT91_CAST(AT91_REG *) 	0x40028100) // (PDC_US1) Receive Pointer Register
#define AT91C_US1_TCR   (AT91_CAST(AT91_REG *) 	0x4002810C) // (PDC_US1) Transmit Counter Register
#define AT91C_US1_RCR   (AT91_CAST(AT91_REG *) 	0x40028104) // (PDC_US1) Receive Counter Register
#define AT91C_US1_TPR   (AT91_CAST(AT91_REG *) 	0x40028108) // (PDC_US1) Transmit Pointer Register
#define AT91C_US1_RNPR  (AT91_CAST(AT91_REG *) 	0x40028110) // (PDC_US1) Receive Next Pointer Register
#define AT91C_US1_TNCR  (AT91_CAST(AT91_REG *) 	0x4002811C) // (PDC_US1) Transmit Next Counter Register
#define AT91C_US1_PTCR  (AT91_CAST(AT91_REG *) 	0x40028120) // (PDC_US1) PDC Transfer Control Register
#define AT91C_US1_RNCR  (AT91_CAST(AT91_REG *) 	0x40028114) // (PDC_US1) Receive Next Counter Register
#define AT91C_US1_PTSR  (AT91_CAST(AT91_REG *) 	0x40028124) // (PDC_US1) PDC Transfer Status Register
// ========== Register definition for US1 peripheral ========== 
#define AT91C_US1_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400280EC) // (US1) US ADDRSIZE REGISTER 
#define AT91C_US1_IDR   (AT91_CAST(AT91_REG *) 	0x4002800C) // (US1) Interrupt Disable Register
#define AT91C_US1_FEATURES (AT91_CAST(AT91_REG *) 	0x400280F8) // (US1) US FEATURES REGISTER 
#define AT91C_US1_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400280F4) // (US1) US IPNAME2 REGISTER 
#define AT91C_US1_MAN   (AT91_CAST(AT91_REG *) 	0x40028050) // (US1) Manchester Encoder Decoder Register
#define AT91C_US1_CR    (AT91_CAST(AT91_REG *) 	0x40028000) // (US1) Control Register
#define AT91C_US1_TTGR  (AT91_CAST(AT91_REG *) 	0x40028028) // (US1) Transmitter Time-guard Register
#define AT91C_US1_IF    (AT91_CAST(AT91_REG *) 	0x4002804C) // (US1) IRDA_FILTER Register
#define AT91C_US1_FIDI  (AT91_CAST(AT91_REG *) 	0x40028040) // (US1) FI_DI_Ratio Register
#define AT91C_US1_THR   (AT91_CAST(AT91_REG *) 	0x4002801C) // (US1) Transmitter Holding Register
#define AT91C_US1_VER   (AT91_CAST(AT91_REG *) 	0x400280FC) // (US1) VERSION Register
#define AT91C_US1_MR    (AT91_CAST(AT91_REG *) 	0x40028004) // (US1) Mode Register
#define AT91C_US1_CSR   (AT91_CAST(AT91_REG *) 	0x40028014) // (US1) Channel Status Register
#define AT91C_US1_IER   (AT91_CAST(AT91_REG *) 	0x40028008) // (US1) Interrupt Enable Register
#define AT91C_US1_NER   (AT91_CAST(AT91_REG *) 	0x40028044) // (US1) Nb Errors Register
#define AT91C_US1_RHR   (AT91_CAST(AT91_REG *) 	0x40028018) // (US1) Receiver Holding Register
#define AT91C_US1_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400280F0) // (US1) US IPNAME1 REGISTER 
#define AT91C_US1_IMR   (AT91_CAST(AT91_REG *) 	0x40028010) // (US1) Interrupt Mask Register
#define AT91C_US1_BRGR  (AT91_CAST(AT91_REG *) 	0x40028020) // (US1) Baud Rate Generator Register
#define AT91C_US1_RTOR  (AT91_CAST(AT91_REG *) 	0x40028024) // (US1) Receiver Time-out Register
// ========== Register definition for PDC_SSC0 peripheral ========== 
#define AT91C_SSC0_RNCR (AT91_CAST(AT91_REG *) 	0x40004114) // (PDC_SSC0) Receive Next Counter Register
#define AT91C_SSC0_TPR  (AT91_CAST(AT91_REG *) 	0x40004108) // (PDC_SSC0) Transmit Pointer Register
#define AT91C_SSC0_TCR  (AT91_CAST(AT91_REG *) 	0x4000410C) // (PDC_SSC0) Transmit Counter Register
#define AT91C_SSC0_PTCR (AT91_CAST(AT91_REG *) 	0x40004120) // (PDC_SSC0) PDC Transfer Control Register
#define AT91C_SSC0_TNPR (AT91_CAST(AT91_REG *) 	0x40004118) // (PDC_SSC0) Transmit Next Pointer Register
#define AT91C_SSC0_RPR  (AT91_CAST(AT91_REG *) 	0x40004100) // (PDC_SSC0) Receive Pointer Register
#define AT91C_SSC0_TNCR (AT91_CAST(AT91_REG *) 	0x4000411C) // (PDC_SSC0) Transmit Next Counter Register
#define AT91C_SSC0_RNPR (AT91_CAST(AT91_REG *) 	0x40004110) // (PDC_SSC0) Receive Next Pointer Register
#define AT91C_SSC0_RCR  (AT91_CAST(AT91_REG *) 	0x40004104) // (PDC_SSC0) Receive Counter Register
#define AT91C_SSC0_PTSR (AT91_CAST(AT91_REG *) 	0x40004124) // (PDC_SSC0) PDC Transfer Status Register
// ========== Register definition for SSC0 peripheral ========== 
#define AT91C_SSC0_FEATURES (AT91_CAST(AT91_REG *) 	0x400040F8) // (SSC0) SSC FEATURES REGISTER 
#define AT91C_SSC0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400040F0) // (SSC0) SSC ADDRSIZE REGISTER 
#define AT91C_SSC0_CR   (AT91_CAST(AT91_REG *) 	0x40004000) // (SSC0) Control Register
#define AT91C_SSC0_RHR  (AT91_CAST(AT91_REG *) 	0x40004020) // (SSC0) Receive Holding Register
#define AT91C_SSC0_VER  (AT91_CAST(AT91_REG *) 	0x400040FC) // (SSC0) Version Register
#define AT91C_SSC0_TSHR (AT91_CAST(AT91_REG *) 	0x40004034) // (SSC0) Transmit Sync Holding Register
#define AT91C_SSC0_RFMR (AT91_CAST(AT91_REG *) 	0x40004014) // (SSC0) Receive Frame Mode Register
#define AT91C_SSC0_IDR  (AT91_CAST(AT91_REG *) 	0x40004048) // (SSC0) Interrupt Disable Register
#define AT91C_SSC0_TFMR (AT91_CAST(AT91_REG *) 	0x4000401C) // (SSC0) Transmit Frame Mode Register
#define AT91C_SSC0_RSHR (AT91_CAST(AT91_REG *) 	0x40004030) // (SSC0) Receive Sync Holding Register
#define AT91C_SSC0_TCMR (AT91_CAST(AT91_REG *) 	0x40004018) // (SSC0) Transmit Clock Mode Register
#define AT91C_SSC0_RCMR (AT91_CAST(AT91_REG *) 	0x40004010) // (SSC0) Receive Clock ModeRegister
#define AT91C_SSC0_SR   (AT91_CAST(AT91_REG *) 	0x40004040) // (SSC0) Status Register
#define AT91C_SSC0_NAME (AT91_CAST(AT91_REG *) 	0x400040F4) // (SSC0) SSC NAME REGISTER 
#define AT91C_SSC0_THR  (AT91_CAST(AT91_REG *) 	0x40004024) // (SSC0) Transmit Holding Register
#define AT91C_SSC0_CMR  (AT91_CAST(AT91_REG *) 	0x40004004) // (SSC0) Clock Mode Register
#define AT91C_SSC0_IER  (AT91_CAST(AT91_REG *) 	0x40004044) // (SSC0) Interrupt Enable Register
#define AT91C_SSC0_IMR  (AT91_CAST(AT91_REG *) 	0x4000404C) // (SSC0) Interrupt Mask Register
// ========== Register definition for PDC_PWMC peripheral ========== 
#define AT91C_PWMC_TNCR (AT91_CAST(AT91_REG *) 	0x4002011C) // (PDC_PWMC) Transmit Next Counter Register
#define AT91C_PWMC_RCR  (AT91_CAST(AT91_REG *) 	0x40020104) // (PDC_PWMC) Receive Counter Register
#define AT91C_PWMC_TCR  (AT91_CAST(AT91_REG *) 	0x4002010C) // (PDC_PWMC) Transmit Counter Register
#define AT91C_PWMC_RNCR (AT91_CAST(AT91_REG *) 	0x40020114) // (PDC_PWMC) Receive Next Counter Register
#define AT91C_PWMC_PTSR (AT91_CAST(AT91_REG *) 	0x40020124) // (PDC_PWMC) PDC Transfer Status Register
#define AT91C_PWMC_RNPR (AT91_CAST(AT91_REG *) 	0x40020110) // (PDC_PWMC) Receive Next Pointer Register
#define AT91C_PWMC_TNPR (AT91_CAST(AT91_REG *) 	0x40020118) // (PDC_PWMC) Transmit Next Pointer Register
#define AT91C_PWMC_PTCR (AT91_CAST(AT91_REG *) 	0x40020120) // (PDC_PWMC) PDC Transfer Control Register
#define AT91C_PWMC_RPR  (AT91_CAST(AT91_REG *) 	0x40020100) // (PDC_PWMC) Receive Pointer Register
#define AT91C_PWMC_TPR  (AT91_CAST(AT91_REG *) 	0x40020108) // (PDC_PWMC) Transmit Pointer Register
// ========== Register definition for PWMC_CH0 peripheral ========== 
#define AT91C_PWMC_CH0_CMR (AT91_CAST(AT91_REG *) 	0x40020200) // (PWMC_CH0) Channel Mode Register
#define AT91C_PWMC_CH0_DTUPDR (AT91_CAST(AT91_REG *) 	0x4002021C) // (PWMC_CH0) Channel Dead Time Update Value Register
#define AT91C_PWMC_CH0_CPRDR (AT91_CAST(AT91_REG *) 	0x4002020C) // (PWMC_CH0) Channel Period Register
#define AT91C_PWMC_CH0_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x40020210) // (PWMC_CH0) Channel Period Update Register
#define AT91C_PWMC_CH0_CDTYR (AT91_CAST(AT91_REG *) 	0x40020204) // (PWMC_CH0) Channel Duty Cycle Register
#define AT91C_PWMC_CH0_DTR (AT91_CAST(AT91_REG *) 	0x40020218) // (PWMC_CH0) Channel Dead Time Value Register
#define AT91C_PWMC_CH0_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x40020208) // (PWMC_CH0) Channel Duty Cycle Update Register
#define AT91C_PWMC_CH0_CCNTR (AT91_CAST(AT91_REG *) 	0x40020214) // (PWMC_CH0) Channel Counter Register
// ========== Register definition for PWMC_CH1 peripheral ========== 
#define AT91C_PWMC_CH1_DTUPDR (AT91_CAST(AT91_REG *) 	0x4002023C) // (PWMC_CH1) Channel Dead Time Update Value Register
#define AT91C_PWMC_CH1_DTR (AT91_CAST(AT91_REG *) 	0x40020238) // (PWMC_CH1) Channel Dead Time Value Register
#define AT91C_PWMC_CH1_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x40020228) // (PWMC_CH1) Channel Duty Cycle Update Register
#define AT91C_PWMC_CH1_CDTYR (AT91_CAST(AT91_REG *) 	0x40020224) // (PWMC_CH1) Channel Duty Cycle Register
#define AT91C_PWMC_CH1_CCNTR (AT91_CAST(AT91_REG *) 	0x40020234) // (PWMC_CH1) Channel Counter Register
#define AT91C_PWMC_CH1_CPRDR (AT91_CAST(AT91_REG *) 	0x4002022C) // (PWMC_CH1) Channel Period Register
#define AT91C_PWMC_CH1_CMR (AT91_CAST(AT91_REG *) 	0x40020220) // (PWMC_CH1) Channel Mode Register
#define AT91C_PWMC_CH1_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x40020230) // (PWMC_CH1) Channel Period Update Register
// ========== Register definition for PWMC_CH2 peripheral ========== 
#define AT91C_PWMC_CH2_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x40020250) // (PWMC_CH2) Channel Period Update Register
#define AT91C_PWMC_CH2_CDTYR (AT91_CAST(AT91_REG *) 	0x40020244) // (PWMC_CH2) Channel Duty Cycle Register
#define AT91C_PWMC_CH2_CCNTR (AT91_CAST(AT91_REG *) 	0x40020254) // (PWMC_CH2) Channel Counter Register
#define AT91C_PWMC_CH2_CMR (AT91_CAST(AT91_REG *) 	0x40020240) // (PWMC_CH2) Channel Mode Register
#define AT91C_PWMC_CH2_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x40020248) // (PWMC_CH2) Channel Duty Cycle Update Register
#define AT91C_PWMC_CH2_DTUPDR (AT91_CAST(AT91_REG *) 	0x4002025C) // (PWMC_CH2) Channel Dead Time Update Value Register
#define AT91C_PWMC_CH2_DTR (AT91_CAST(AT91_REG *) 	0x40020258) // (PWMC_CH2) Channel Dead Time Value Register
#define AT91C_PWMC_CH2_CPRDR (AT91_CAST(AT91_REG *) 	0x4002024C) // (PWMC_CH2) Channel Period Register
// ========== Register definition for PWMC_CH3 peripheral ========== 
#define AT91C_PWMC_CH3_CPRDR (AT91_CAST(AT91_REG *) 	0x4002026C) // (PWMC_CH3) Channel Period Register
#define AT91C_PWMC_CH3_DTUPDR (AT91_CAST(AT91_REG *) 	0x4002027C) // (PWMC_CH3) Channel Dead Time Update Value Register
#define AT91C_PWMC_CH3_DTR (AT91_CAST(AT91_REG *) 	0x40020278) // (PWMC_CH3) Channel Dead Time Value Register
#define AT91C_PWMC_CH3_CDTYR (AT91_CAST(AT91_REG *) 	0x40020264) // (PWMC_CH3) Channel Duty Cycle Register
#define AT91C_PWMC_CH3_CMR (AT91_CAST(AT91_REG *) 	0x40020260) // (PWMC_CH3) Channel Mode Register
#define AT91C_PWMC_CH3_CCNTR (AT91_CAST(AT91_REG *) 	0x40020274) // (PWMC_CH3) Channel Counter Register
#define AT91C_PWMC_CH3_CPRDUPDR (AT91_CAST(AT91_REG *) 	0x40020270) // (PWMC_CH3) Channel Period Update Register
#define AT91C_PWMC_CH3_CDTYUPDR (AT91_CAST(AT91_REG *) 	0x40020268) // (PWMC_CH3) Channel Duty Cycle Update Register
// ========== Register definition for PWMC peripheral ========== 
#define AT91C_PWMC_CMP6M (AT91_CAST(AT91_REG *) 	0x40020198) // (PWMC) PWM Comparison Mode 6 Register
#define AT91C_PWMC_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400200EC) // (PWMC) PWMC ADDRSIZE REGISTER 
#define AT91C_PWMC_CMP5V (AT91_CAST(AT91_REG *) 	0x40020180) // (PWMC) PWM Comparison Value 5 Register
#define AT91C_PWMC_FMR  (AT91_CAST(AT91_REG *) 	0x4002005C) // (PWMC) PWM Fault Mode Register
#define AT91C_PWMC_IER2 (AT91_CAST(AT91_REG *) 	0x40020034) // (PWMC) PWMC Interrupt Enable Register 2
#define AT91C_PWMC_EL5MR (AT91_CAST(AT91_REG *) 	0x40020090) // (PWMC) PWM Event Line 5 Mode Register
#define AT91C_PWMC_CMP0VUPD (AT91_CAST(AT91_REG *) 	0x40020134) // (PWMC) PWM Comparison Value 0 Update Register
#define AT91C_PWMC_FPER1 (AT91_CAST(AT91_REG *) 	0x4002006C) // (PWMC) PWM Fault Protection Enable Register 1
#define AT91C_PWMC_SCUPUPD (AT91_CAST(AT91_REG *) 	0x40020030) // (PWMC) PWM Update Period Update Register
#define AT91C_PWMC_DIS  (AT91_CAST(AT91_REG *) 	0x40020008) // (PWMC) PWMC Disable Register
#define AT91C_PWMC_CMP1M (AT91_CAST(AT91_REG *) 	0x40020148) // (PWMC) PWM Comparison Mode 1 Register
#define AT91C_PWMC_CMP2V (AT91_CAST(AT91_REG *) 	0x40020150) // (PWMC) PWM Comparison Value 2 Register
#define AT91C_PWMC_WPCR (AT91_CAST(AT91_REG *) 	0x400200E4) // (PWMC) PWM Write Protection Enable Register
#define AT91C_PWMC_CMP5MUPD (AT91_CAST(AT91_REG *) 	0x4002018C) // (PWMC) PWM Comparison Mode 5 Update Register
#define AT91C_PWMC_FPV  (AT91_CAST(AT91_REG *) 	0x40020068) // (PWMC) PWM Fault Protection Value Register
#define AT91C_PWMC_UPCR (AT91_CAST(AT91_REG *) 	0x40020028) // (PWMC) PWM Update Control Register
#define AT91C_PWMC_CMP4MUPD (AT91_CAST(AT91_REG *) 	0x4002017C) // (PWMC) PWM Comparison Mode 4 Update Register
#define AT91C_PWMC_EL6MR (AT91_CAST(AT91_REG *) 	0x40020094) // (PWMC) PWM Event Line 6 Mode Register
#define AT91C_PWMC_OS   (AT91_CAST(AT91_REG *) 	0x40020048) // (PWMC) PWM Output Selection Register
#define AT91C_PWMC_OSSUPD (AT91_CAST(AT91_REG *) 	0x40020054) // (PWMC) PWM Output Selection Set Update Register
#define AT91C_PWMC_FSR  (AT91_CAST(AT91_REG *) 	0x40020060) // (PWMC) PWM Fault Mode Status Register
#define AT91C_PWMC_CMP2M (AT91_CAST(AT91_REG *) 	0x40020158) // (PWMC) PWM Comparison Mode 2 Register
#define AT91C_PWMC_EL2MR (AT91_CAST(AT91_REG *) 	0x40020084) // (PWMC) PWM Event Line 2 Mode Register
#define AT91C_PWMC_FPER3 (AT91_CAST(AT91_REG *) 	0x40020074) // (PWMC) PWM Fault Protection Enable Register 3
#define AT91C_PWMC_CMP4M (AT91_CAST(AT91_REG *) 	0x40020178) // (PWMC) PWM Comparison Mode 4 Register
#define AT91C_PWMC_ISR2 (AT91_CAST(AT91_REG *) 	0x40020040) // (PWMC) PWMC Interrupt Status Register 2
#define AT91C_PWMC_CMP6VUPD (AT91_CAST(AT91_REG *) 	0x40020194) // (PWMC) PWM Comparison Value 6 Update Register
#define AT91C_PWMC_CMP5VUPD (AT91_CAST(AT91_REG *) 	0x40020184) // (PWMC) PWM Comparison Value 5 Update Register
#define AT91C_PWMC_EL7MR (AT91_CAST(AT91_REG *) 	0x40020098) // (PWMC) PWM Event Line 7 Mode Register
#define AT91C_PWMC_OSC  (AT91_CAST(AT91_REG *) 	0x40020050) // (PWMC) PWM Output Selection Clear Register
#define AT91C_PWMC_CMP3MUPD (AT91_CAST(AT91_REG *) 	0x4002016C) // (PWMC) PWM Comparison Mode 3 Update Register
#define AT91C_PWMC_CMP2MUPD (AT91_CAST(AT91_REG *) 	0x4002015C) // (PWMC) PWM Comparison Mode 2 Update Register
#define AT91C_PWMC_CMP0M (AT91_CAST(AT91_REG *) 	0x40020138) // (PWMC) PWM Comparison Mode 0 Register
#define AT91C_PWMC_EL1MR (AT91_CAST(AT91_REG *) 	0x40020080) // (PWMC) PWM Event Line 1 Mode Register
#define AT91C_PWMC_CMP0MUPD (AT91_CAST(AT91_REG *) 	0x4002013C) // (PWMC) PWM Comparison Mode 0 Update Register
#define AT91C_PWMC_WPSR (AT91_CAST(AT91_REG *) 	0x400200E8) // (PWMC) PWM Write Protection Status Register
#define AT91C_PWMC_CMP1MUPD (AT91_CAST(AT91_REG *) 	0x4002014C) // (PWMC) PWM Comparison Mode 1 Update Register
#define AT91C_PWMC_IMR2 (AT91_CAST(AT91_REG *) 	0x4002003C) // (PWMC) PWMC Interrupt Mask Register 2
#define AT91C_PWMC_CMP3V (AT91_CAST(AT91_REG *) 	0x40020160) // (PWMC) PWM Comparison Value 3 Register
#define AT91C_PWMC_CMP3VUPD (AT91_CAST(AT91_REG *) 	0x40020164) // (PWMC) PWM Comparison Value 3 Update Register
#define AT91C_PWMC_CMP3M (AT91_CAST(AT91_REG *) 	0x40020168) // (PWMC) PWM Comparison Mode 3 Register
#define AT91C_PWMC_FPER4 (AT91_CAST(AT91_REG *) 	0x40020078) // (PWMC) PWM Fault Protection Enable Register 4
#define AT91C_PWMC_OSCUPD (AT91_CAST(AT91_REG *) 	0x40020058) // (PWMC) PWM Output Selection Clear Update Register
#define AT91C_PWMC_CMP0V (AT91_CAST(AT91_REG *) 	0x40020130) // (PWMC) PWM Comparison Value 0 Register
#define AT91C_PWMC_OOV  (AT91_CAST(AT91_REG *) 	0x40020044) // (PWMC) PWM Output Override Value Register
#define AT91C_PWMC_ENA  (AT91_CAST(AT91_REG *) 	0x40020004) // (PWMC) PWMC Enable Register
#define AT91C_PWMC_CMP6MUPD (AT91_CAST(AT91_REG *) 	0x4002019C) // (PWMC) PWM Comparison Mode 6 Update Register
#define AT91C_PWMC_SYNC (AT91_CAST(AT91_REG *) 	0x40020020) // (PWMC) PWM Synchronized Channels Register
#define AT91C_PWMC_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400200F0) // (PWMC) PWMC IPNAME1 REGISTER 
#define AT91C_PWMC_IDR2 (AT91_CAST(AT91_REG *) 	0x40020038) // (PWMC) PWMC Interrupt Disable Register 2
#define AT91C_PWMC_SR   (AT91_CAST(AT91_REG *) 	0x4002000C) // (PWMC) PWMC Status Register
#define AT91C_PWMC_FPER2 (AT91_CAST(AT91_REG *) 	0x40020070) // (PWMC) PWM Fault Protection Enable Register 2
#define AT91C_PWMC_EL3MR (AT91_CAST(AT91_REG *) 	0x40020088) // (PWMC) PWM Event Line 3 Mode Register
#define AT91C_PWMC_IMR1 (AT91_CAST(AT91_REG *) 	0x40020018) // (PWMC) PWMC Interrupt Mask Register 1
#define AT91C_PWMC_EL0MR (AT91_CAST(AT91_REG *) 	0x4002007C) // (PWMC) PWM Event Line 0 Mode Register
#define AT91C_PWMC_STEP (AT91_CAST(AT91_REG *) 	0x400200B0) // (PWMC) PWM Stepper Config Register
#define AT91C_PWMC_FCR  (AT91_CAST(AT91_REG *) 	0x40020064) // (PWMC) PWM Fault Mode Clear Register
#define AT91C_PWMC_CMP7MUPD (AT91_CAST(AT91_REG *) 	0x400201AC) // (PWMC) PWM Comparison Mode 7 Update Register
#define AT91C_PWMC_ISR1 (AT91_CAST(AT91_REG *) 	0x4002001C) // (PWMC) PWMC Interrupt Status Register 1
#define AT91C_PWMC_CMP4VUPD (AT91_CAST(AT91_REG *) 	0x40020174) // (PWMC) PWM Comparison Value 4 Update Register
#define AT91C_PWMC_VER  (AT91_CAST(AT91_REG *) 	0x400200FC) // (PWMC) PWMC Version Register
#define AT91C_PWMC_CMP5M (AT91_CAST(AT91_REG *) 	0x40020188) // (PWMC) PWM Comparison Mode 5 Register
#define AT91C_PWMC_IER1 (AT91_CAST(AT91_REG *) 	0x40020010) // (PWMC) PWMC Interrupt Enable Register 1
#define AT91C_PWMC_MR   (AT91_CAST(AT91_REG *) 	0x40020000) // (PWMC) PWMC Mode Register
#define AT91C_PWMC_OSS  (AT91_CAST(AT91_REG *) 	0x4002004C) // (PWMC) PWM Output Selection Set Register
#define AT91C_PWMC_CMP7V (AT91_CAST(AT91_REG *) 	0x400201A0) // (PWMC) PWM Comparison Value 7 Register
#define AT91C_PWMC_FEATURES (AT91_CAST(AT91_REG *) 	0x400200F8) // (PWMC) PWMC FEATURES REGISTER 
#define AT91C_PWMC_CMP4V (AT91_CAST(AT91_REG *) 	0x40020170) // (PWMC) PWM Comparison Value 4 Register
#define AT91C_PWMC_CMP7M (AT91_CAST(AT91_REG *) 	0x400201A8) // (PWMC) PWM Comparison Mode 7 Register
#define AT91C_PWMC_EL4MR (AT91_CAST(AT91_REG *) 	0x4002008C) // (PWMC) PWM Event Line 4 Mode Register
#define AT91C_PWMC_CMP2VUPD (AT91_CAST(AT91_REG *) 	0x40020154) // (PWMC) PWM Comparison Value 2 Update Register
#define AT91C_PWMC_CMP6V (AT91_CAST(AT91_REG *) 	0x40020190) // (PWMC) PWM Comparison Value 6 Register
#define AT91C_PWMC_CMP1V (AT91_CAST(AT91_REG *) 	0x40020140) // (PWMC) PWM Comparison Value 1 Register
#define AT91C_PWMC_IDR1 (AT91_CAST(AT91_REG *) 	0x40020014) // (PWMC) PWMC Interrupt Disable Register 1
#define AT91C_PWMC_SCUP (AT91_CAST(AT91_REG *) 	0x4002002C) // (PWMC) PWM Update Period Register
#define AT91C_PWMC_CMP1VUPD (AT91_CAST(AT91_REG *) 	0x40020144) // (PWMC) PWM Comparison Value 1 Update Register
#define AT91C_PWMC_CMP7VUPD (AT91_CAST(AT91_REG *) 	0x400201A4) // (PWMC) PWM Comparison Value 7 Update Register
#define AT91C_PWMC_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400200F4) // (PWMC) PWMC IPNAME2 REGISTER 
// ========== Register definition for SPI0 peripheral ========== 
#define AT91C_SPI0_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400080EC) // (SPI0) SPI ADDRSIZE REGISTER 
#define AT91C_SPI0_RDR  (AT91_CAST(AT91_REG *) 	0x40008008) // (SPI0) Receive Data Register
#define AT91C_SPI0_FEATURES (AT91_CAST(AT91_REG *) 	0x400080F8) // (SPI0) SPI FEATURES REGISTER 
#define AT91C_SPI0_CR   (AT91_CAST(AT91_REG *) 	0x40008000) // (SPI0) Control Register
#define AT91C_SPI0_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400080F0) // (SPI0) SPI IPNAME1 REGISTER 
#define AT91C_SPI0_VER  (AT91_CAST(AT91_REG *) 	0x400080FC) // (SPI0) Version Register
#define AT91C_SPI0_IDR  (AT91_CAST(AT91_REG *) 	0x40008018) // (SPI0) Interrupt Disable Register
#define AT91C_SPI0_TDR  (AT91_CAST(AT91_REG *) 	0x4000800C) // (SPI0) Transmit Data Register
#define AT91C_SPI0_MR   (AT91_CAST(AT91_REG *) 	0x40008004) // (SPI0) Mode Register
#define AT91C_SPI0_IER  (AT91_CAST(AT91_REG *) 	0x40008014) // (SPI0) Interrupt Enable Register
#define AT91C_SPI0_IMR  (AT91_CAST(AT91_REG *) 	0x4000801C) // (SPI0) Interrupt Mask Register
#define AT91C_SPI0_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400080F4) // (SPI0) SPI IPNAME2 REGISTER 
#define AT91C_SPI0_CSR  (AT91_CAST(AT91_REG *) 	0x40008030) // (SPI0) Chip Select Register
#define AT91C_SPI0_SR   (AT91_CAST(AT91_REG *) 	0x40008010) // (SPI0) Status Register
// ========== Register definition for UDP peripheral ========== 
#define AT91C_UDP_RSTEP (AT91_CAST(AT91_REG *) 	0x40034028) // (UDP) Reset Endpoint Register
#define AT91C_UDP_CSR   (AT91_CAST(AT91_REG *) 	0x40034030) // (UDP) Endpoint Control and Status Register
#define AT91C_UDP_IMR   (AT91_CAST(AT91_REG *) 	0x40034018) // (UDP) Interrupt Mask Register
#define AT91C_UDP_FDR   (AT91_CAST(AT91_REG *) 	0x40034050) // (UDP) Endpoint FIFO Data Register
#define AT91C_UDP_ISR   (AT91_CAST(AT91_REG *) 	0x4003401C) // (UDP) Interrupt Status Register
#define AT91C_UDP_IPNAME2 (AT91_CAST(AT91_REG *) 	0x400340F4) // (UDP) UDP IPNAME2 REGISTER 
#define AT91C_UDP_ICR   (AT91_CAST(AT91_REG *) 	0x40034020) // (UDP) Interrupt Clear Register
#define AT91C_UDP_VER   (AT91_CAST(AT91_REG *) 	0x400340FC) // (UDP) UDP VERSION REGISTER
#define AT91C_UDP_IER   (AT91_CAST(AT91_REG *) 	0x40034010) // (UDP) Interrupt Enable Register
#define AT91C_UDP_FEATURES (AT91_CAST(AT91_REG *) 	0x400340F8) // (UDP) UDP FEATURES REGISTER 
#define AT91C_UDP_IPNAME1 (AT91_CAST(AT91_REG *) 	0x400340F0) // (UDP) UDP IPNAME1 REGISTER 
#define AT91C_UDP_GLBSTATE (AT91_CAST(AT91_REG *) 	0x40034004) // (UDP) Global State Register
#define AT91C_UDP_ADDRSIZE (AT91_CAST(AT91_REG *) 	0x400340EC) // (UDP) UDP ADDRSIZE REGISTER 
#define AT91C_UDP_NUM   (AT91_CAST(AT91_REG *) 	0x40034000) // (UDP) Frame Number Register
#define AT91C_UDP_IDR   (AT91_CAST(AT91_REG *) 	0x40034014) // (UDP) Interrupt Disable Register
#define AT91C_UDP_TXVC  (AT91_CAST(AT91_REG *) 	0x40034074) // (UDP) Transceiver Control Register
#define AT91C_UDP_FADDR (AT91_CAST(AT91_REG *) 	0x40034008) // (UDP) Function Address Register

// *****************************************************************************
//               PIO DEFINITIONS FOR AT91SAM3s4
// *****************************************************************************
#define AT91C_PIO_PA0        (1 <<  0) // Pin Controlled by PA0
#define AT91C_PA0_PWMH0    (AT91C_PIO_PA0) //  
#define AT91C_PA0_TIOA0    (AT91C_PIO_PA0) //  
#define AT91C_PA0_A17      (AT91C_PIO_PA0) //  
#define AT91C_PIO_PA1        (1 <<  1) // Pin Controlled by PA1
#define AT91C_PA1_PWMH1    (AT91C_PIO_PA1) //  
#define AT91C_PA1_TIOB0    (AT91C_PIO_PA1) //  
#define AT91C_PA1_A18      (AT91C_PIO_PA1) //  
#define AT91C_PIO_PA10       (1 << 10) // Pin Controlled by PA10
#define AT91C_PA10_UTXD0    (AT91C_PIO_PA10) //  
#define AT91C_PA10_SPI0_NPCS2 (AT91C_PIO_PA10) //  
#define AT91C_PIO_PA11       (1 << 11) // Pin Controlled by PA11
#define AT91C_PA11_SPI0_NPCS0 (AT91C_PIO_PA11) //  
#define AT91C_PA11_PWMH0    (AT91C_PIO_PA11) //  
#define AT91C_PIO_PA12       (1 << 12) // Pin Controlled by PA12
#define AT91C_PA12_SPI0_MISO (AT91C_PIO_PA12) //  
#define AT91C_PA12_PWMH1    (AT91C_PIO_PA12) //  
#define AT91C_PIO_PA13       (1 << 13) // Pin Controlled by PA13
#define AT91C_PA13_SPI0_MOSI (AT91C_PIO_PA13) //  
#define AT91C_PA13_PWMH2    (AT91C_PIO_PA13) //  
#define AT91C_PIO_PA14       (1 << 14) // Pin Controlled by PA14
#define AT91C_PA14_SPI0_SPCK (AT91C_PIO_PA14) //  
#define AT91C_PA14_PWMH3    (AT91C_PIO_PA14) //  
#define AT91C_PIO_PA15       (1 << 15) // Pin Controlled by PA15
#define AT91C_PA15_TF       (AT91C_PIO_PA15) //  
#define AT91C_PA15_TIOA1    (AT91C_PIO_PA15) //  
#define AT91C_PA15_PWML3    (AT91C_PIO_PA15) //  
#define AT91C_PIO_PA16       (1 << 16) // Pin Controlled by PA16
#define AT91C_PA16_TK       (AT91C_PIO_PA16) //  
#define AT91C_PA16_TIOB1    (AT91C_PIO_PA16) //  
#define AT91C_PA16_PWML2    (AT91C_PIO_PA16) //  
#define AT91C_PIO_PA17       (1 << 17) // Pin Controlled by PA17
#define AT91C_PA17_TD       (AT91C_PIO_PA17) //  
#define AT91C_PA17_PCK1     (AT91C_PIO_PA17) //  
#define AT91C_PA17_PWMH3    (AT91C_PIO_PA17) //  
#define AT91C_PIO_PA18       (1 << 18) // Pin Controlled by PA18
#define AT91C_PA18_RD       (AT91C_PIO_PA18) //  
#define AT91C_PA18_PCK2     (AT91C_PIO_PA18) //  
#define AT91C_PA18_A14      (AT91C_PIO_PA18) //  
#define AT91C_PIO_PA19       (1 << 19) // Pin Controlled by PA19
#define AT91C_PA19_RK       (AT91C_PIO_PA19) //  
#define AT91C_PA19_PWML0    (AT91C_PIO_PA19) //  
#define AT91C_PA19_A15      (AT91C_PIO_PA19) //  
#define AT91C_PIO_PA2        (1 <<  2) // Pin Controlled by PA2
#define AT91C_PA2_PWMH2    (AT91C_PIO_PA2) //  
#define AT91C_PA2_SCK0     (AT91C_PIO_PA2) //  
#define AT91C_PA2_DATRG    (AT91C_PIO_PA2) //  
#define AT91C_PIO_PA20       (1 << 20) // Pin Controlled by PA20
#define AT91C_PA20_RF       (AT91C_PIO_PA20) //  
#define AT91C_PA20_PWML1    (AT91C_PIO_PA20) //  
#define AT91C_PA20_A16      (AT91C_PIO_PA20) //  
#define AT91C_PIO_PA21       (1 << 21) // Pin Controlled by PA21
#define AT91C_PA21_RXD1     (AT91C_PIO_PA21) //  
#define AT91C_PA21_PCK1     (AT91C_PIO_PA21) //  
#define AT91C_PIO_PA22       (1 << 22) // Pin Controlled by PA22
#define AT91C_PA22_TXD1     (AT91C_PIO_PA22) //  
#define AT91C_PA22_SPI0_NPCS3 (AT91C_PIO_PA22) //  
#define AT91C_PA22_NCS2     (AT91C_PIO_PA22) //  
#define AT91C_PIO_PA23       (1 << 23) // Pin Controlled by PA23
#define AT91C_PA23_SCK1     (AT91C_PIO_PA23) //  
#define AT91C_PA23_PWMH0    (AT91C_PIO_PA23) //  
#define AT91C_PA23_A19      (AT91C_PIO_PA23) //  
#define AT91C_PIO_PA24       (1 << 24) // Pin Controlled by PA24
#define AT91C_PA24_RTS1     (AT91C_PIO_PA24) //  
#define AT91C_PA24_PWMH1    (AT91C_PIO_PA24) //  
#define AT91C_PA24_A20      (AT91C_PIO_PA24) //  
#define AT91C_PIO_PA25       (1 << 25) // Pin Controlled by PA25
#define AT91C_PA25_CTS1     (AT91C_PIO_PA25) //  
#define AT91C_PA25_PWMH2    (AT91C_PIO_PA25) //  
#define AT91C_PA25_A23      (AT91C_PIO_PA25) //  
#define AT91C_PIO_PA26       (1 << 26) // Pin Controlled by PA26
#define AT91C_PA26_DCD1     (AT91C_PIO_PA26) //  
#define AT91C_PA26_TIOA2    (AT91C_PIO_PA26) //  
#define AT91C_PA26_MCI0_DA2 (AT91C_PIO_PA26) //  
#define AT91C_PIO_PA27       (1 << 27) // Pin Controlled by PA27
#define AT91C_PA27_DTR1     (AT91C_PIO_PA27) //  
#define AT91C_PA27_TIOB2    (AT91C_PIO_PA27) //  
#define AT91C_PA27_MCI0_DA3 (AT91C_PIO_PA27) //  
#define AT91C_PIO_PA28       (1 << 28) // Pin Controlled by PA28
#define AT91C_PA28_DSR1     (AT91C_PIO_PA28) //  
#define AT91C_PA28_TCLK1    (AT91C_PIO_PA28) //  
#define AT91C_PA28_MCI0_CDA (AT91C_PIO_PA28) //  
#define AT91C_PIO_PA29       (1 << 29) // Pin Controlled by PA29
#define AT91C_PA29_RI1      (AT91C_PIO_PA29) //  
#define AT91C_PA29_TCLK2    (AT91C_PIO_PA29) //  
#define AT91C_PA29_MCI0_CK  (AT91C_PIO_PA29) //  
#define AT91C_PIO_PA3        (1 <<  3) // Pin Controlled by PA3
#define AT91C_PA3_TWD0     (AT91C_PIO_PA3) //  
#define AT91C_PA3_SPI0_NPCS3 (AT91C_PIO_PA3) //  
#define AT91C_PIO_PA30       (1 << 30) // Pin Controlled by PA30
#define AT91C_PA30_PWML2    (AT91C_PIO_PA30) //  
#define AT91C_PA30_SPI0_NPCS2 (AT91C_PIO_PA30) //  
#define AT91C_PA30_MCI0_DA0 (AT91C_PIO_PA30) //  
#define AT91C_PIO_PA31       (1 << 31) // Pin Controlled by PA31
#define AT91C_PA31_SPI0_NPCS1 (AT91C_PIO_PA31) //  
#define AT91C_PA31_PCK2     (AT91C_PIO_PA31) //  
#define AT91C_PA31_MCI0_DA1 (AT91C_PIO_PA31) //  
#define AT91C_PIO_PA4        (1 <<  4) // Pin Controlled by PA4
#define AT91C_PA4_TWCK0    (AT91C_PIO_PA4) //  
#define AT91C_PA4_TCLK0    (AT91C_PIO_PA4) //  
#define AT91C_PIO_PA5        (1 <<  5) // Pin Controlled by PA5
#define AT91C_PA5_RXD0     (AT91C_PIO_PA5) //  
#define AT91C_PA5_SPI0_NPCS3 (AT91C_PIO_PA5) //  
#define AT91C_PIO_PA6        (1 <<  6) // Pin Controlled by PA6
#define AT91C_PA6_TXD0     (AT91C_PIO_PA6) //  
#define AT91C_PA6_PCK0     (AT91C_PIO_PA6) //  
#define AT91C_PIO_PA7        (1 <<  7) // Pin Controlled by PA7
#define AT91C_PA7_RTS0     (AT91C_PIO_PA7) //  
#define AT91C_PA7_PWMH3    (AT91C_PIO_PA7) //  
#define AT91C_PIO_PA8        (1 <<  8) // Pin Controlled by PA8
#define AT91C_PA8_CTS0     (AT91C_PIO_PA8) //  
#define AT91C_PA8_ADTRG    (AT91C_PIO_PA8) //  
#define AT91C_PIO_PA9        (1 <<  9) // Pin Controlled by PA9
#define AT91C_PA9_URXD0    (AT91C_PIO_PA9) //  
#define AT91C_PA9_SPI0_NPCS1 (AT91C_PIO_PA9) //  
#define AT91C_PA9_PWMFI0   (AT91C_PIO_PA9) //  
#define AT91C_PIO_PB0        (1 <<  0) // Pin Controlled by PB0
#define AT91C_PB0_PWMH0    (AT91C_PIO_PB0) //  
#define AT91C_PIO_PB1        (1 <<  1) // Pin Controlled by PB1
#define AT91C_PB1_PWMH1    (AT91C_PIO_PB1) //  
#define AT91C_PIO_PB10       (1 << 10) // Pin Controlled by PB10
#define AT91C_PIO_PB11       (1 << 11) // Pin Controlled by PB11
#define AT91C_PIO_PB12       (1 << 12) // Pin Controlled by PB12
#define AT91C_PB12_PWML1    (AT91C_PIO_PB12) //  
#define AT91C_PIO_PB13       (1 << 13) // Pin Controlled by PB13
#define AT91C_PB13_PWML2    (AT91C_PIO_PB13) //  
#define AT91C_PB13_PCK0     (AT91C_PIO_PB13) //  
#define AT91C_PIO_PB14       (1 << 14) // Pin Controlled by PB14
#define AT91C_PB14_SPI0_NPCS1 (AT91C_PIO_PB14) //  
#define AT91C_PB14_PWMH3    (AT91C_PIO_PB14) //  
#define AT91C_PIO_PB2        (1 <<  2) // Pin Controlled by PB2
#define AT91C_PB2_URXD1    (AT91C_PIO_PB2) //  
#define AT91C_PB2_SPI0_NPCS2 (AT91C_PIO_PB2) //  
#define AT91C_PIO_PB3        (1 <<  3) // Pin Controlled by PB3
#define AT91C_PB3_UTXD1    (AT91C_PIO_PB3) //  
#define AT91C_PB3_PCK2     (AT91C_PIO_PB3) //  
#define AT91C_PIO_PB4        (1 <<  4) // Pin Controlled by PB4
#define AT91C_PB4_TWD1     (AT91C_PIO_PB4) //  
#define AT91C_PB4_PWMH2    (AT91C_PIO_PB4) //  
#define AT91C_PIO_PB5        (1 <<  5) // Pin Controlled by PB5
#define AT91C_PB5_TWCK1    (AT91C_PIO_PB5) //  
#define AT91C_PB5_PWML0    (AT91C_PIO_PB5) //  
#define AT91C_PIO_PB6        (1 <<  6) // Pin Controlled by PB6
#define AT91C_PIO_PB7        (1 <<  7) // Pin Controlled by PB7
#define AT91C_PIO_PB8        (1 <<  8) // Pin Controlled by PB8
#define AT91C_PIO_PB9        (1 <<  9) // Pin Controlled by PB9
#define AT91C_PIO_PC0        (1 <<  0) // Pin Controlled by PC0
#define AT91C_PC0_D0       (AT91C_PIO_PC0) //  
#define AT91C_PC0_PWML0    (AT91C_PIO_PC0) //  
#define AT91C_PIO_PC1        (1 <<  1) // Pin Controlled by PC1
#define AT91C_PC1_D1       (AT91C_PIO_PC1) //  
#define AT91C_PC1_PWML1    (AT91C_PIO_PC1) //  
#define AT91C_PIO_PC10       (1 << 10) // Pin Controlled by PC10
#define AT91C_PC10_NANDWE   (AT91C_PIO_PC10) //  
#define AT91C_PIO_PC11       (1 << 11) // Pin Controlled by PC11
#define AT91C_PC11_NRD      (AT91C_PIO_PC11) //  
#define AT91C_PIO_PC12       (1 << 12) // Pin Controlled by PC12
#define AT91C_PC12_NCS3     (AT91C_PIO_PC12) //  
#define AT91C_PIO_PC13       (1 << 13) // Pin Controlled by PC13
#define AT91C_PC13_NWAIT    (AT91C_PIO_PC13) //  
#define AT91C_PC13_PWML0    (AT91C_PIO_PC13) //  
#define AT91C_PIO_PC14       (1 << 14) // Pin Controlled by PC14
#define AT91C_PC14_NCS0     (AT91C_PIO_PC14) //  
#define AT91C_PIO_PC15       (1 << 15) // Pin Controlled by PC15
#define AT91C_PC15_NCS1     (AT91C_PIO_PC15) //  
#define AT91C_PC15_PWML1    (AT91C_PIO_PC15) //  
#define AT91C_PIO_PC16       (1 << 16) // Pin Controlled by PC16
#define AT91C_PC16_A21_NANDALE (AT91C_PIO_PC16) //  
#define AT91C_PIO_PC17       (1 << 17) // Pin Controlled by PC17
#define AT91C_PC17_A22_NANDCLE (AT91C_PIO_PC17) //  
#define AT91C_PIO_PC18       (1 << 18) // Pin Controlled by PC18
#define AT91C_PC18_A0_NBS0  (AT91C_PIO_PC18) //  
#define AT91C_PC18_PWMH0    (AT91C_PIO_PC18) //  
#define AT91C_PIO_PC19       (1 << 19) // Pin Controlled by PC19
#define AT91C_PC19_A1       (AT91C_PIO_PC19) //  
#define AT91C_PC19_PWMH1    (AT91C_PIO_PC19) //  
#define AT91C_PIO_PC2        (1 <<  2) // Pin Controlled by PC2
#define AT91C_PC2_D2       (AT91C_PIO_PC2) //  
#define AT91C_PC2_PWML2    (AT91C_PIO_PC2) //  
#define AT91C_PIO_PC20       (1 << 20) // Pin Controlled by PC20
#define AT91C_PC20_A2       (AT91C_PIO_PC20) //  
#define AT91C_PC20_PWMH2    (AT91C_PIO_PC20) //  
#define AT91C_PIO_PC21       (1 << 21) // Pin Controlled by PC21
#define AT91C_PC21_A3       (AT91C_PIO_PC21) //  
#define AT91C_PC21_PWMH3    (AT91C_PIO_PC21) //  
#define AT91C_PIO_PC22       (1 << 22) // Pin Controlled by PC22
#define AT91C_PC22_A4       (AT91C_PIO_PC22) //  
#define AT91C_PC22_PWML3    (AT91C_PIO_PC22) //  
#define AT91C_PIO_PC23       (1 << 23) // Pin Controlled by PC23
#define AT91C_PC23_A5       (AT91C_PIO_PC23) //  
#define AT91C_PC23_TIOA3    (AT91C_PIO_PC23) //  
#define AT91C_PIO_PC24       (1 << 24) // Pin Controlled by PC24
#define AT91C_PC24_A6       (AT91C_PIO_PC24) //  
#define AT91C_PC24_TIOB3    (AT91C_PIO_PC24) //  
#define AT91C_PIO_PC25       (1 << 25) // Pin Controlled by PC25
#define AT91C_PC25_A7       (AT91C_PIO_PC25) //  
#define AT91C_PC25_TCLK3    (AT91C_PIO_PC25) //  
#define AT91C_PIO_PC26       (1 << 26) // Pin Controlled by PC26
#define AT91C_PC26_A8       (AT91C_PIO_PC26) //  
#define AT91C_PC26_TIOA4    (AT91C_PIO_PC26) //  
#define AT91C_PIO_PC27       (1 << 27) // Pin Controlled by PC27
#define AT91C_PC27_A9       (AT91C_PIO_PC27) //  
#define AT91C_PC27_TIOB4    (AT91C_PIO_PC27) //  
#define AT91C_PIO_PC28       (1 << 28) // Pin Controlled by PC28
#define AT91C_PC28_A10      (AT91C_PIO_PC28) //  
#define AT91C_PC28_TCLK4    (AT91C_PIO_PC28) //  
#define AT91C_PIO_PC29       (1 << 29) // Pin Controlled by PC29
#define AT91C_PC29_A11      (AT91C_PIO_PC29) //  
#define AT91C_PC29_TIOA5    (AT91C_PIO_PC29) //  
#define AT91C_PIO_PC3        (1 <<  3) // Pin Controlled by PC3
#define AT91C_PC3_D3       (AT91C_PIO_PC3) //  
#define AT91C_PC3_PWML3    (AT91C_PIO_PC3) //  
#define AT91C_PIO_PC30       (1 << 30) // Pin Controlled by PC30
#define AT91C_PC30_A12      (AT91C_PIO_PC30) //  
#define AT91C_PC30_TIOB5    (AT91C_PIO_PC30) //  
#define AT91C_PIO_PC31       (1 << 31) // Pin Controlled by PC31
#define AT91C_PC31_A13      (AT91C_PIO_PC31) //  
#define AT91C_PC31_TCLK5    (AT91C_PIO_PC31) //  
#define AT91C_PIO_PC4        (1 <<  4) // Pin Controlled by PC4
#define AT91C_PC4_D4       (AT91C_PIO_PC4) //  
#define AT91C_PC4_SPI0_NPCS1 (AT91C_PIO_PC4) //  
#define AT91C_PIO_PC5        (1 <<  5) // Pin Controlled by PC5
#define AT91C_PC5_D5       (AT91C_PIO_PC5) //  
#define AT91C_PIO_PC6        (1 <<  6) // Pin Controlled by PC6
#define AT91C_PC6_D6       (AT91C_PIO_PC6) //  
#define AT91C_PIO_PC7        (1 <<  7) // Pin Controlled by PC7
#define AT91C_PC7_D7       (AT91C_PIO_PC7) //  
#define AT91C_PIO_PC8        (1 <<  8) // Pin Controlled by PC8
#define AT91C_PC8_NWR0_NWE (AT91C_PIO_PC8) //  
#define AT91C_PIO_PC9        (1 <<  9) // Pin Controlled by PC9
#define AT91C_PC9_NANDOE   (AT91C_PIO_PC9) //  

// *****************************************************************************
//               PERIPHERAL ID DEFINITIONS FOR AT91SAM3s4
// *****************************************************************************
#define AT91C_ID_SUPC   ( 0) // SUPPLY CONTROLLER
#define AT91C_ID_RSTC   ( 1) // RESET CONTROLLER
#define AT91C_ID_RTC    ( 2) // REAL TIME CLOCK
#define AT91C_ID_RTT    ( 3) // REAL TIME TIMER
#define AT91C_ID_WDG    ( 4) // WATCHDOG TIMER
#define AT91C_ID_PMC    ( 5) // PMC
#define AT91C_ID_EFC0   ( 6) // EFC0
#define AT91C_ID_DBGU0  ( 8) // DBGU0
#define AT91C_ID_DBGU1  ( 9) // DBGU1
#define AT91C_ID_HSMC3  (10) // HSMC3
#define AT91C_ID_PIOA   (11) // Parallel IO Controller A
#define AT91C_ID_PIOB   (12) // Parallel IO Controller B
#define AT91C_ID_PIOC   (13) // Parallel IO Controller C
#define AT91C_ID_US0    (14) // USART 0
#define AT91C_ID_US1    (15) // USART 1
#define AT91C_ID_MCI0   (18) // Multimedia Card Interface
#define AT91C_ID_TWI0   (19) // TWI 0
#define AT91C_ID_TWI1   (20) // TWI 1
#define AT91C_ID_SPI0   (21) // Serial Peripheral Interface
#define AT91C_ID_SSC0   (22) // Serial Synchronous Controller 0
#define AT91C_ID_TC0    (23) // Timer Counter 0
#define AT91C_ID_TC1    (24) // Timer Counter 1
#define AT91C_ID_TC2    (25) // Timer Counter 2
#define AT91C_ID_TC3    (26) // Timer Counter 0
#define AT91C_ID_TC4    (27) // Timer Counter 1
#define AT91C_ID_TC5    (28) // Timer Counter 2
#define AT91C_ID_ADC0   (29) // ADC controller0
#define AT91C_ID_DAC0   (30) // Digital to Analog Converter
#define AT91C_ID_PWMC   (31) // Pulse Width Modulation Controller
#define AT91C_ID_HCBDMA (32) // Context Based Direct Memory Access Controller Interface
#define AT91C_ID_ACC0   (33) // Analog Comparator Controller
#define AT91C_ID_UDP    (34) // USB Device
#define AT91C_ALL_INT   (0xFFFFFFFF) // ALL VALID INTERRUPTS

// *****************************************************************************
//               BASE ADDRESS DEFINITIONS FOR AT91SAM3s4
// *****************************************************************************
#define AT91C_BASE_SYS       (AT91_CAST(AT91PS_SYS) 	0x400E0000) // (SYS) Base Address
#define AT91C_BASE_SMC       (AT91_CAST(AT91PS_SMC) 	0x400E0000) // (SMC) Base Address
#define AT91C_BASE_MATRIX    (AT91_CAST(AT91PS_HMATRIX2) 	0x400E0200) // (MATRIX) Base Address
#define AT91C_BASE_CCFG      (AT91_CAST(AT91PS_CCFG) 	0x400E0310) // (CCFG) Base Address
#define AT91C_BASE_NVIC      (AT91_CAST(AT91PS_NVIC) 	0xE000E000) // (NVIC) Base Address
#define AT91C_BASE_MPU       (AT91_CAST(AT91PS_MPU) 	0xE000ED90) // (MPU) Base Address
#define AT91C_BASE_CM3       (AT91_CAST(AT91PS_CM3) 	0xE000ED00) // (CM3) Base Address
#define AT91C_BASE_PDC_DBGU0 (AT91_CAST(AT91PS_PDC) 	0x400E0700) // (PDC_DBGU0) Base Address
#define AT91C_BASE_DBGU0     (AT91_CAST(AT91PS_DBGU) 	0x400E0600) // (DBGU0) Base Address
#define AT91C_BASE_PDC_DBGU1 (AT91_CAST(AT91PS_PDC) 	0x400E0900) // (PDC_DBGU1) Base Address
#define AT91C_BASE_DBGU1     (AT91_CAST(AT91PS_DBGU) 	0x400E0800) // (DBGU1) Base Address
#define AT91C_BASE_PIOA      (AT91_CAST(AT91PS_PIO) 	0x400E0E00) // (PIOA) Base Address
#define AT91C_BASE_PDC_PIOA  (AT91_CAST(AT91PS_PDC) 	0x400E0F68) // (PDC_PIOA) Base Address
#define AT91C_BASE_PIOB      (AT91_CAST(AT91PS_PIO) 	0x400E1000) // (PIOB) Base Address
#define AT91C_BASE_PIOC      (AT91_CAST(AT91PS_PIO) 	0x400E1200) // (PIOC) Base Address
#define AT91C_BASE_PMC       (AT91_CAST(AT91PS_PMC) 	0x400E0400) // (PMC) Base Address
#define AT91C_BASE_CKGR      (AT91_CAST(AT91PS_CKGR) 	0x400E041C) // (CKGR) Base Address
#define AT91C_BASE_RSTC      (AT91_CAST(AT91PS_RSTC) 	0x400E1400) // (RSTC) Base Address
#define AT91C_BASE_SUPC      (AT91_CAST(AT91PS_SUPC) 	0x400E1410) // (SUPC) Base Address
#define AT91C_BASE_RTTC      (AT91_CAST(AT91PS_RTTC) 	0x400E1430) // (RTTC) Base Address
#define AT91C_BASE_WDTC      (AT91_CAST(AT91PS_WDTC) 	0x400E1450) // (WDTC) Base Address
#define AT91C_BASE_RTC       (AT91_CAST(AT91PS_RTC) 	0x400E1460) // (RTC) Base Address
#define AT91C_BASE_ADC0      (AT91_CAST(AT91PS_ADC) 	0x40038000) // (ADC0) Base Address
#define AT91C_BASE_DAC0      (AT91_CAST(AT91PS_DAC) 	0x4003C000) // (DAC0) Base Address
#define AT91C_BASE_ACC0      (AT91_CAST(AT91PS_ACC) 	0x40040000) // (ACC0) Base Address
#define AT91C_BASE_HCBDMA    (AT91_CAST(AT91PS_HCBDMA) 	0x40044000) // (HCBDMA) Base Address
#define AT91C_BASE_TC0       (AT91_CAST(AT91PS_TC) 	0x40010000) // (TC0) Base Address
#define AT91C_BASE_TC1       (AT91_CAST(AT91PS_TC) 	0x40010040) // (TC1) Base Address
#define AT91C_BASE_TC2       (AT91_CAST(AT91PS_TC) 	0x40010080) // (TC2) Base Address
#define AT91C_BASE_TC3       (AT91_CAST(AT91PS_TC) 	0x40014000) // (TC3) Base Address
#define AT91C_BASE_TC4       (AT91_CAST(AT91PS_TC) 	0x40014040) // (TC4) Base Address
#define AT91C_BASE_TC5       (AT91_CAST(AT91PS_TC) 	0x40014080) // (TC5) Base Address
#define AT91C_BASE_TCB0      (AT91_CAST(AT91PS_TCB) 	0x40010000) // (TCB0) Base Address
#define AT91C_BASE_TCB1      (AT91_CAST(AT91PS_TCB) 	0x40010040) // (TCB1) Base Address
#define AT91C_BASE_TCB2      (AT91_CAST(AT91PS_TCB) 	0x40010080) // (TCB2) Base Address
#define AT91C_BASE_TCB3      (AT91_CAST(AT91PS_TCB) 	0x40014000) // (TCB3) Base Address
#define AT91C_BASE_TCB4      (AT91_CAST(AT91PS_TCB) 	0x40014040) // (TCB4) Base Address
#define AT91C_BASE_TCB5      (AT91_CAST(AT91PS_TCB) 	0x40014080) // (TCB5) Base Address
#define AT91C_BASE_EFC0      (AT91_CAST(AT91PS_EFC) 	0x400E0A00) // (EFC0) Base Address
#define AT91C_BASE_MCI0      (AT91_CAST(AT91PS_MCI) 	0x40000000) // (MCI0) Base Address
#define AT91C_BASE_PDC_TWI0  (AT91_CAST(AT91PS_PDC) 	0x40018100) // (PDC_TWI0) Base Address
#define AT91C_BASE_PDC_TWI1  (AT91_CAST(AT91PS_PDC) 	0x4001C100) // (PDC_TWI1) Base Address
#define AT91C_BASE_TWI0      (AT91_CAST(AT91PS_TWI) 	0x40018000) // (TWI0) Base Address
#define AT91C_BASE_TWI1      (AT91_CAST(AT91PS_TWI) 	0x4001C000) // (TWI1) Base Address
#define AT91C_BASE_PDC_US0   (AT91_CAST(AT91PS_PDC) 	0x40024100) // (PDC_US0) Base Address
#define AT91C_BASE_US0       (AT91_CAST(AT91PS_USART) 	0x40024000) // (US0) Base Address
#define AT91C_BASE_PDC_US1   (AT91_CAST(AT91PS_PDC) 	0x40028100) // (PDC_US1) Base Address
#define AT91C_BASE_US1       (AT91_CAST(AT91PS_USART) 	0x40028000) // (US1) Base Address
#define AT91C_BASE_PDC_SSC0  (AT91_CAST(AT91PS_PDC) 	0x40004100) // (PDC_SSC0) Base Address
#define AT91C_BASE_SSC0      (AT91_CAST(AT91PS_SSC) 	0x40004000) // (SSC0) Base Address
#define AT91C_BASE_PDC_PWMC  (AT91_CAST(AT91PS_PDC) 	0x40020100) // (PDC_PWMC) Base Address
#define AT91C_BASE_PWMC_CH0  (AT91_CAST(AT91PS_PWMC_CH) 	0x40020200) // (PWMC_CH0) Base Address
#define AT91C_BASE_PWMC_CH1  (AT91_CAST(AT91PS_PWMC_CH) 	0x40020220) // (PWMC_CH1) Base Address
#define AT91C_BASE_PWMC_CH2  (AT91_CAST(AT91PS_PWMC_CH) 	0x40020240) // (PWMC_CH2) Base Address
#define AT91C_BASE_PWMC_CH3  (AT91_CAST(AT91PS_PWMC_CH) 	0x40020260) // (PWMC_CH3) Base Address
#define AT91C_BASE_PWMC      (AT91_CAST(AT91PS_PWMC) 	0x40020000) // (PWMC) Base Address
#define AT91C_BASE_SPI0      (AT91_CAST(AT91PS_SPI) 	0x40008000) // (SPI0) Base Address
#define AT91C_BASE_UDP       (AT91_CAST(AT91PS_UDP) 	0x40034000) // (UDP) Base Address

// *****************************************************************************
//               MEMORY MAPPING DEFINITIONS FOR AT91SAM3s4
// *****************************************************************************
// IRAM
#define AT91C_IRAM 	 (0x20000000) // Maximum Internal SRAM base address
#define AT91C_IRAM_SIZE	 (0x0000C000) // Maximum Internal SRAM size in byte (48 Kbytes)
// IROM
#define AT91C_IROM 	 (0x00800000) // Internal ROM base address
#define AT91C_IROM_SIZE	 (0x00008000) // Internal ROM size in byte (32 Kbytes)
// EBI_CS0
#define AT91C_EBI_CS0	 (0x60000000) // EBI Chip Select 0 base address
#define AT91C_EBI_CS0_SIZE	 (0x01000000) // EBI Chip Select 0 size in byte (16384 Kbytes)
// EBI_SM0
#define AT91C_EBI_SM0	 (0x60000000) // NANDFLASH on EBI Chip Select 0 base address
#define AT91C_EBI_SM0_SIZE	 (0x01000000) // NANDFLASH on EBI Chip Select 0 size in byte (16384 Kbytes)
// EBI_CS1
#define AT91C_EBI_CS1	 (0x61000000) // EBI Chip Select 1 base address
#define AT91C_EBI_CS1_SIZE	 (0x01000000) // EBI Chip Select 1 size in byte (16384 Kbytes)
// EBI_SM1
#define AT91C_EBI_SM1	 (0x61000000) // NANDFLASH on EBI Chip Select 1 base address
#define AT91C_EBI_SM1_SIZE	 (0x01000000) // NANDFLASH on EBI Chip Select 1 size in byte (16384 Kbytes)
// EBI_CS2
#define AT91C_EBI_CS2	 (0x62000000) // EBI Chip Select 2 base address
#define AT91C_EBI_CS2_SIZE	 (0x01000000) // EBI Chip Select 2 size in byte (16384 Kbytes)
// EBI_SM2
#define AT91C_EBI_SM2	 (0x62000000) // NANDFLASH on EBI Chip Select 2 base address
#define AT91C_EBI_SM2_SIZE	 (0x01000000) // NANDFLASH on EBI Chip Select 2 size in byte (16384 Kbytes)
// EBI_CS3
#define AT91C_EBI_CS3	 (0x63000000) // EBI Chip Select 3 base address
#define AT91C_EBI_CS3_SIZE	 (0x01000000) // EBI Chip Select 3 size in byte (16384 Kbytes)
// EBI_SM3
#define AT91C_EBI_SM3	 (0x63000000) // NANDFLASH on EBI Chip Select 3 base address
#define AT91C_EBI_SM3_SIZE	 (0x01000000) // NANDFLASH on EBI Chip Select 3 size in byte (16384 Kbytes)
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
// EBI_SDRAM
#define AT91C_EBI_SDRAM	 (0x66000000) // SDRAM on EBI Chip Select 1 base address
#define AT91C_EBI_SDRAM_SIZE	 (0x10000000) // SDRAM on EBI Chip Select 1 size in byte (262144 Kbytes)
// EBI_SDRAM_16BIT
#define AT91C_EBI_SDRAM_16BIT	 (0x67000000) // SDRAM on EBI Chip Select 1 base address
#define AT91C_EBI_SDRAM_16BIT_SIZE	 (0x02000000) // SDRAM on EBI Chip Select 1 size in byte (32768 Kbytes)
// EBI_SDRAM_32BIT
#define AT91C_EBI_SDRAM_32BIT	 (0x68000000) // SDRAM on EBI Chip Select 1 base address
#define AT91C_EBI_SDRAM_32BIT_SIZE	 (0x04000000) // SDRAM on EBI Chip Select 1 size in byte (65536 Kbytes)

#endif
