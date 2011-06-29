#ifndef __DFM_CONFIG_H__
#define __DFM_CONFIG_H__

//enable fatfs on SDCard
#define DFM_FATFS_SDCARD

//enable fatfs on Nandflash
#define DFM_FATFS_NANDFLASH

//enable fatfs on SDRAM
//#define DFM_FATFS_SDRAM

//enable LCD and touchscreen
#define USE_LCD_TSD

//define file buffer size, used to read bitmap data
//note: this config make var relocated to PSRAM,so size is ok.
#define FILE_BUF_SIZE 0x40000U

//enable interrupt chain management
#define USE_IT_CHAIN_MGR

//LCD controller
#define LCDC_HX8347

#ifndef LCDSLIDEIMAGEFILE
#define LCDSLIDEIMAGEFILE "sam3demo.bin"
#define LCDSLIDEVIMAGEFILE "SamDEMOV.bin"
#endif

//enable variable relocation
#define VAR_RELOCATION

//variable relocation memory base
#define RELOC_VAR_MEM_BASE BOARD_EBI_PSRAM

#endif // end of __DFM_CONFIG_H__

