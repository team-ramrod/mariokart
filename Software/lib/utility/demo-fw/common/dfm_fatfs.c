#include "dfm_fatfs.h"
#include "dfm_init.h"
//#include <memories/MEDSdcard.h>
//#include <utility/trace.h>
//#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <irq/irq.h>
#include <board.h>
#include <board_memories.h>
#include <string.h>
#include <utility/assert.h>
#include <utility/math.h>
#include <utility/bmp.h>
#include <lcd/color.h>
#include <lcd/lcdd.h>
#include <lcd/draw.h>
#include <tsd/tsd.h>
#include <usb/common/core/USBConfigurationDescriptor.h>
#include <usb/device/core/USBD.h>
#include <usb/device/massstorage/MSDDriver.h>
#include <usb/device/massstorage/MSDLun.h>
#include <usb/device/core/USBDCallbacks.h>
#include <memories/MEDSdcard.h>
#include <components/hx8347/hx8347.h>
#include <systick/systick.h>
#include <flash/flashd.h>

#if defined(PINS_NANDFLASH)
#include <memories/MEDNandFlash.h>
#include <memories/nandflash/RawNandFlash.h>
#include <memories/nandflash/TranslatedNandFlash.h>
#endif

#include "fatfs_config.h"

#include <hx8347/hx8347.h>

#include "dfm_dispboxmgr.h"
#include "dfm_config.h"
#include "dfm_cmd.h"
#include "dfm_varloc.h"

/// Available medias.
RLOC_OBJ Media medias[MAX_LUNS] _AT(FATFS_MEDIA_OBJ_ADDR);

#if defined(PINS_NANDFLASH)
/// Pins used to access to nandflash.
const Pin gpPinsNf[] = {PINS_NANDFLASH};
/// Nandflash device structure.
RLOC_OBJ struct TranslatedNandFlash gTranslatedNf _AT(NANDFLASH_TRANS_TAB_ADDR);
/// Address for transferring command bytes to the nandflash.
unsigned int gNFCmdBytesAddr = BOARD_NF_COMMAND_ADDR;
/// Address for transferring address bytes to the nandflash.
unsigned int gNFAddrBytesAddr = BOARD_NF_ADDRESS_ADDR;
/// Address for transferring data bytes to the nandflash.
unsigned int gNFDataBytesAddr = BOARD_NF_DATA_ADDR;
/// Nandflash chip enable pin.
const Pin gNFCePin = BOARD_NF_CE_PIN;
/// Nandflash ready/busy pin.
const Pin gNFRbPin = BOARD_NF_RB_PIN;
#endif

//---------------------------------------------------------------------
/// enable fatfs on SDCard
//---------------------------------------------------------------------
int Fatfs_Init_Share()
{
  TRACE_DEBUG("\n\r FatFs max media is %u (MAX_LUNS)!", numMedias);
  numMedias = MAX_LUNS;
  
  return 0;
}

DFM_INIT(7, Fatfs_Init_Share);

////////////////////////////
/// enable fatfs on SDCard /
////////////////////////////

#if defined(DFM_FATFS_SDCARD)
//used to mount fatfs on sdcard
RLOC_OBJ static FATFS fs_sdcard _AT(FATFS_SDCARD_OBJ_ADDR);
//------------------------------------------------------------------------------
///  Init sdcard for FatFS
///  \return 0 succeed, other value failure
//-----------------------------------------------------------------------------
int FatFs_SDCard_Init()
{
  FRESULT res;
  
  if(MEDSdcard_Detect(&medias[DRV_MMC], MCI_ID)) {
    
    if (!MEDSdcard_Initialize(&medias[DRV_MMC], MCI_ID)) {
      // Initialize sdcard failed
      TRACE_ERROR("-E- SD Init fail\n\r");
      return -1;
    }
    
    // Mount disk
    printf("-I- Mount disk %d \n\r", DRV_MMC);
    
    memset(&fs_sdcard, 0, sizeof(FATFS));
    res = f_mount(DRV_MMC, &fs_sdcard);
    if( res != FR_OK ) {
      TRACE_ERROR("-E- f_mount pb: 0x%X\n\r", res);
      return -1;
    }
    
    DIR dir;
    // Test if the disk is formated
    res = f_opendir (&dir,SDCARD_ROOT_DIRECTORY);
    if(res == FR_OK ){
      
      TRACE_INFO("-I- The disk is already formated. \n\r");
      TRACE_INFO("-I- Display files contained on the SDcard :\n\r");
      //FF_ScanDir(SDCARD_ROOT_DIRECTORY);
    }
    else {
      TRACE_ERROR("-I- The disk is not formated. Exit! \n\r");
      return -1;
    }
      
    return 0;
  }
  
  //no sdcard detected in MCI slot
  return -1;
}

//Init SDCard in level 6
//lvl6_init(FatFs_SDCard_Init);
//_define_init_lvl("6", FatFs_SDCard_Init, 6);
DFM_INIT(6, FatFs_SDCard_Init);

#endif //end of DFM_FATFS_SDCARD

///////////////////////////////
/// enable fatfs on nandflash /
///////////////////////////////
#if defined(DFM_FATFS_NANDFLASH)
//used to mount fatfs on nand flash
RLOC_OBJ static FATFS fs_nandflash _AT(FATFS_NANDFLASH_OBJ_ADDR);

//------------------------------------------------------------------------------
///  Init Nandflash for FatFS
///  \return 0 succeed, other value failure
//-----------------------------------------------------------------------------
int FatFs_NandFlash_Init()
{
  unsigned int delay = 0;
  unsigned char nfBusWidth = 16, nfRc;
  unsigned short nfBaseBlock = 0;
  struct RawNandFlash *pRaw = (struct RawNandFlash*)&gTranslatedNf;
  struct NandFlashModel *pModel = (struct NandFlashModel*)&gTranslatedNf;
  unsigned int nfMamagedSize;
  
  // Configure SMC for NandFlash
  BOARD_ConfigureNandFlash(nfBusWidth);
  // Configure PIO for Nand Flash
  PIO_Configure(gpPinsNf, PIO_LISTSIZE(gpPinsNf));
  
  // Nand Flash Initialize (ALL flash mapped)
  nfRc = RawNandFlash_Initialize(pRaw,
                                 0,
                                 gNFCmdBytesAddr,
                                 gNFAddrBytesAddr,
                                 gNFDataBytesAddr,
                                 gNFCePin,
                                 gNFRbPin);
  if (nfRc) {
    printf("Nand not found\n\r");
    return -1;
  }
  else {
    printf("NF\tNb Blocks %d\n\r",
           NandFlashModel_GetDeviceSizeInBlocks(pModel));
    printf("\tBlock Size %uK\n\r",
           (unsigned int)NandFlashModel_GetBlockSizeInBytes(pModel)/1024);
    printf("\tPage Size %d\n\r",
           NandFlashModel_GetPageDataSize(pModel));
    nfBaseBlock =
      NF_RESERVE_SIZE / NandFlashModel_GetBlockSizeInBytes(pModel);
  }
  printf("NF disk will use area from %dM(B%d)\n\r",
         NF_RESERVE_SIZE/1024/1024, nfBaseBlock);
#if 0
  printf("!! Erase the NF Disk? (y/n):");
  //updateDelay = INPUT_DELAY;
  //updateView = 0;
  while(1) {
    if(DBGU_IsRxReady()) {
      char key = DBGU_GetChar();
      DBGU_PutChar(key);
      if (key == 'y') {
        if (nfRc == 0) {
          unsigned int block;
          printf(" Erase from %d ... ", nfBaseBlock);
          for (block = nfBaseBlock;
               block < NandFlashModel_GetDeviceSizeInBlocks(pModel);
               block ++) {
                 RawNandFlash_EraseBlock(pRaw, block);
               }
          printf("OK");
        }
      }
      printf("\n\r");
      break;
    }
    
    if (++ delay > 0x800000) {
      printf("n\n\r");
      break;
    }
  }
#endif

  nfMamagedSize = ((NandFlashModel_GetDeviceSizeInMBytes(pModel) - NF_RESERVE_SIZE/1024/1024) > NF_MANAGED_SIZE/1024/1024) ? \
    NF_MANAGED_SIZE/1024/1024 : (NandFlashModel_GetDeviceSizeInMBytes(pModel) - NF_RESERVE_SIZE/1024/1024);
    if (TranslatedNandFlash_Initialize(&gTranslatedNf,
                                       0,
                                       gNFCmdBytesAddr,
                                       gNFAddrBytesAddr,
                                       gNFDataBytesAddr,
                                       gNFCePin,
                                       gNFRbPin,
                                       nfBaseBlock, nfMamagedSize * 1024 * 1024/NandFlashModel_GetBlockSizeInBytes(pModel))) {
                                         printf("Nand init error\n\r");
                                         return -1;
                                       }
    // Check the data bus width of the NandFlash
    nfBusWidth =
      NandFlashModel_GetDataBusWidth(pModel);
    BOARD_ConfigureNandFlash(nfBusWidth);
    
    // Media initialize
    MEDNandFlash_Initialize(&medias[DRV_NAND], &gTranslatedNf);
    
    // Initialize LUN
    //    LUN_Init(&(luns[DRV_NAND]), &(medias[DRV_NAND]),
    //             msdBuffer, MSD_BUFFER_SIZE,
    //             0, 0, 0, 0,
    //             0);
    //printf("\n\r Init Nandflash is temp ignored!");
//     ++numMedias;
    
    FRESULT res;
    // Mount Disk
    printf("-I- Mount disk 1\n\r");
    memset(&fs_nandflash, 0, sizeof(FATFS));  // Clear file system object
    res = f_mount(DRV_NAND, &fs_nandflash);
    if( res != FR_OK ) {
      printf("-E- f_mount pb: 0x%X\n\r", res);
      //return 0;
    }
    
    DIR dir;
    // Test if the disk is formated
    res = f_opendir (&dir,NAND_ROOT_DIRECTORY);
    if(res == FR_OK ){
      
      // erase NAND to re-format it ?
      printf("-I- The disk is already formated.\n\r");
      
      // Display the file tree
      printf("-I- Display files contained on the NAND :\n\r");
      //FF_ScanDir(NAND_ROOT_DIRECTORY);
#if 0
      printf("-I- Erase the NAND to re-format disk ? (y/n)!\n\r");
      
      unsigned char key = DBGU_GetChar();
      if( (key == 'y') ||  (key == 'Y'))
      {
        TranslatedNandFlash_EraseAll(&gTranslatedNf ,NandEraseDATA);
        res = FR_NO_FILESYSTEM;
      }
#endif
    } else {
      TRACE_ERROR("  Open fatfs on nand flash fail!\n\r");
      return -1;
    }
    
    
    return 0;
}

//Init nandflash In level 6
DFM_INIT(6, FatFs_NandFlash_Init);

#endif //end of DFM_FATFS_NANDFLASH


//------------------------------------------------------------------------------
/// Configures the EBI for NandFlash access according to MCK.
/// \param mck  working MCK
//------------------------------------------------------------------------------
void ConfigureNandFlashEBI(unsigned int mck)
{
    AT91PS_HSMC4_CS pSMC = AT91C_BASE_HSMC4_CS1;

    if (mck <= 48000000) {
        pSMC->HSMC4_SETUP = 0
                        | ((0 <<  0) & AT91C_HSMC4_NWE_SETUP)
                        | ((1 <<  8) & AT91C_HSMC4_NCS_WR_SETUP)
                        | ((0 << 16) & AT91C_HSMC4_NRD_SETUP)
                        | ((1 << 24) & AT91C_HSMC4_NCS_RD_SETUP);

        pSMC->HSMC4_PULSE = 0
                        | ((2 <<  0) & AT91C_HSMC4_NWE_PULSE)
                        | ((3 <<  8) & AT91C_HSMC4_NCS_WR_PULSE)
                        | ((3 << 16) & AT91C_HSMC4_NRD_PULSE)
                        | ((4 << 24) & AT91C_HSMC4_NCS_RD_PULSE);

        pSMC->HSMC4_CYCLE = 0
                      | ((4 <<  0) & AT91C_HSMC4_NWE_CYCLE)
                      | ((7 << 16) & AT91C_HSMC4_NRD_CYCLE);

        pSMC->HSMC4_TIMINGS = 0
                        | ((1 <<  0) & AT91C_HSMC4_TCLR) // CLE to REN
                        | ((2 <<  4) & AT91C_HSMC4_TADL) // ALE to Data
                        | ((1 <<  8) & AT91C_HSMC4_TAR)  // ALE to REN
                        | ((1 << 16) & AT91C_HSMC4_TRR)  // Ready to REN
                        | ((2 << 24) & AT91C_HSMC4_TWB)  // WEN to REN
                        |  (7 << 28)
                        | (AT91C_HSMC4_NFSEL)            // Nand Flash Timing
                        ;
    }
    else if (mck <= 84000000) {
        pSMC->HSMC4_SETUP = 0
                        | ((0 <<  0) & AT91C_HSMC4_NWE_SETUP)
                        | ((1 <<  8) & AT91C_HSMC4_NCS_WR_SETUP)
                        | ((0 << 16) & AT91C_HSMC4_NRD_SETUP)
                        | ((1 << 24) & AT91C_HSMC4_NCS_RD_SETUP);

        pSMC->HSMC4_PULSE = 0
                        | ((2 <<  0) & AT91C_HSMC4_NWE_PULSE)
                        | ((3 <<  8) & AT91C_HSMC4_NCS_WR_PULSE)
                        | ((3 << 16) & AT91C_HSMC4_NRD_PULSE)
                        | ((4 << 24) & AT91C_HSMC4_NCS_RD_PULSE);

        pSMC->HSMC4_CYCLE = 0
                      | ((4 <<  0) & AT91C_HSMC4_NWE_CYCLE)
                      | ((7 << 16) & AT91C_HSMC4_NRD_CYCLE);

        pSMC->HSMC4_TIMINGS = 0
                        | ((2 <<  0) & AT91C_HSMC4_TCLR) // CLE to REN
                        | ((4 <<  4) & AT91C_HSMC4_TADL) // ALE to Data
                        | ((2 <<  8) & AT91C_HSMC4_TAR)  // ALE to REN
                        | ((2 << 16) & AT91C_HSMC4_TRR)  // Ready to REN
                        | ((4 << 24) & AT91C_HSMC4_TWB)  // WEN to REN
                        |  (7 << 28)
                        | (AT91C_HSMC4_NFSEL)            // Nand Flash Timing
                        ;
    }
    else {
        pSMC->HSMC4_SETUP = 0
                        | ((1 <<  0) & AT91C_HSMC4_NWE_SETUP)
                        | ((2 <<  8) & AT91C_HSMC4_NCS_WR_SETUP)
                        | ((1 << 16) & AT91C_HSMC4_NRD_SETUP)
                        | ((2 << 24) & AT91C_HSMC4_NCS_RD_SETUP);

        pSMC->HSMC4_PULSE = 0
                        | ((3 <<  0) & AT91C_HSMC4_NWE_PULSE)
                        | ((4 <<  8) & AT91C_HSMC4_NCS_WR_PULSE)
                        | ((4 << 16) & AT91C_HSMC4_NRD_PULSE)
                        | ((4 << 24) & AT91C_HSMC4_NCS_RD_PULSE);

        pSMC->HSMC4_CYCLE = 0
                      | ((6  <<  0) & AT91C_HSMC4_NWE_CYCLE)
                      | ((9  << 16) & AT91C_HSMC4_NRD_CYCLE);

        pSMC->HSMC4_TIMINGS = 0
                        | ((3 <<  0) & AT91C_HSMC4_TCLR) // CLE to REN
                        | ((4 <<  4) & AT91C_HSMC4_TADL) // ALE to Data
                        | ((2 <<  8) & AT91C_HSMC4_TAR)  // ALE to REN
                        | ((2 << 16) & AT91C_HSMC4_TRR)  // Ready to REN
                        | ((4 << 24) & AT91C_HSMC4_TWB)  // WEN to REN
                        |  (7 << 28)
                        | (AT91C_HSMC4_NFSEL)            // Nand Flash Timing
                        ;
    }
}

