#ifndef __USER_MAIN_H
#define __USER_MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <main.h>

enum 
{
    CFALSE,
    CTRUE,
}CBOOL;

#include "../Inc/flash.h"
#include "../Inc/SPI.h"

void mainTask(uint16_t delay);
void initTask(void);
void subTask(uint16_t delay);

#ifdef __cplusplus
}
#endif

#endif