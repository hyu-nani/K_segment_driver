#ifndef __SUPPORT_H
#define __SUPPORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    CFALSE = 0,
    CTRUE,
} CBOOL;

typedef enum {
    NONE = 0,
    LED_WS2812,
    LED_SK6812,
    MODULE_MAX,
} LED_moduleList;

//void set_module(void);

#ifdef __cplusplus
}
#endif

#endif