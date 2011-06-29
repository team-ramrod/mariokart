#ifndef __DFM_VARLOC_H_
#define __DFM_VARLOC_H

#include "dfm_fatfs.h"
#include "dfm_config.h"

// relocation variables that size is bigger to space start from RELOC_VAR_MEM_BASE
#ifdef VAR_RELOCATION

  #if defined(__ICCARM__) 

    #define RLOC_OBJ __no_init
    #define _AT(addr) @ (addr)

  #elif defined(__CC_ARM)

    #define RLOC_OBJ
    #define _AT(addr) __attribute__ ((at(_addr)))

  #elif defined(__GNUC__)
    
    #define RLOC_OBJ 
    #define _AT(addr) 
  #else
    #error "Unsupported tool chain"
  #endif

#else
  #define RLOC_OBJ 
  #define _AT(addr) 
#endif

#if defined(VAR_RELOCATION) && !defined(RELOC_VAR_MEM_BASE)
  #error "Enable variables relocation, but not give RELOC_VAR_MEM_BASE"
#endif

#define FATFS_MEDIA_OBJ_ADDR      RELOC_VAR_MEM_BASE
#define FATFS_SDCARD_OBJ_ADDR     (FATFS_MEDIA_OBJ_ADDR + sizeof(Media) * MAX_LUNS)
#define FATFS_NANDFLASH_OBJ_ADDR  (FATFS_SDCARD_OBJ_ADDR + sizeof(FATFS))
#define NANDFLASH_TRANS_TAB_ADDR  (FATFS_NANDFLASH_OBJ_ADDR + sizeof(FATFS))
#define ACTIVESLIDE_INFOHEAD_ADDR (NANDFLASH_TRANS_TAB_ADDR + sizeof(struct TranslatedNandFlash))
#define FILE_BUFFER_ADDR          (ACTIVESLIDE_INFOHEAD_ADDR + sizeof(SlideINFOHeader))

#define MSDD_LUN_OBJ_ADDR         (FILE_BUFFER_ADDR + FILE_BUF_SIZE)
#define MSDD_BUF_OBJ_ADDR         (MSDD_LUN_OBJ_ADDR + sizeof(MSDLun) * MAX_LUNS)
#define RELOC_VAR_MEM_END         (MSDD_BUF_OBJ_ADDR + MSD_BUFFER_SIZE)
#define RELOC_VAR_MEM_SIZE        (RELOC_VAR_MEM_END - RELOC_VAR_MEM_BASE)

#endif // end of _DFM_VARLOC_H_
