#ifndef __FLASH_H
#define __FLASH_H

#ifdef __cplusplus
extern "C" {
#endif
//STM32G031x4/x6/x8 devices feature up to 64 Kbytes of embedded Flash memory available for storing code and data.

#define flash_page_00 0x08000000 /* 2K memory */
#define flash_page_01 0x08000800 /* 2K memory */
#define flash_page_02 0x08001000 /* 2K memory */
#define flash_page_03 0x08001800 /* 2K memory */
#define flash_page_04 0x08002000 /* 2K memory */
#define flash_page_05 0x08002800 /* 2K memory */
#define flash_page_06 0x08003000 /* 2K memory */
#define flash_page_07 0x08003800 /* 2K memory */
#define flash_page_08 0x08004000 /* 2K memory */
#define flash_page_09 0x08004800 /* 2K memory */
#define flash_page_10 0x08005000 /* 2K memory */
#define flash_page_11 0x08005800 /* 2K memory */
#define flash_page_12 0x08006000 /* 2K memory */
#define flash_page_13 0x08006800 /* 2K memory */
#define flash_page_14 0x08007000 /* 2K memory */
#define flash_page_15 0x08007800 /* 2K memory */
#define flash_page_16 0x08008000 /* 2K memory */
#define flash_page_17 0x08008800 /* 2K memory */
#define flash_page_18 0x08009000 /* 2K memory */
#define flash_page_19 0x08009800 /* 2K memory */
#define flash_page_20 0x0800A000 /* 2K memory */
#define flash_page_21 0x0800A800 /* 2K memory */
#define flash_page_22 0x0800B000 /* 2K memory */
#define flash_page_23 0x0800B800 /* 2K memory */
#define flash_page_24 0x0800C000 /* 2K memory */
#define flash_page_25 0x0800C800 /* 2K memory */
#define flash_page_26 0x0800D000 /* 2K memory */
#define flash_page_27 0x0800D800 /* 2K memory */
#define flash_page_28 0x0800E000 /* 2K memory */
#define flash_page_29 0x0800E800 /* 2K memory */
#define flash_page_30 0x0800F000 /* 2K memory */
#define flash_page_31 0x0800F800 /* 2K memory */

#define system_memory_adr       0x1FFF0000  /* 8K memory */
#define OTP_area_adr            0x1FFF7000  /* 1K memory */
#define engineering_byte_adr    0x1FFF7500  /* 768 memory */
#define option_byte_adr         0x1FFF7800  /* 128 memory */

/* function */
HAL_StatusTypeDef FLASH_erasePage(uint32_t pageAddress);

#ifdef __cplusplus
}
#endif

#endif