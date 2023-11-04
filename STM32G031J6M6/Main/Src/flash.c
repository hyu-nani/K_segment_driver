#include "../Inc/flash.h"

HAL_StatusTypeDef FLASH_erasePage(uint32_t page)
{
    HAL_FLASH_Unlock();
    HAL_FLASH_Lock();
    return CTRUE;
}