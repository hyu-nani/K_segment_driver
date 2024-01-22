#ifndef __SPI_H
#define __SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#define POP_BUF_SIZE 32

typedef struct {
    uint8_t ringBuf[POP_BUF_SIZE];
} HANDLE_TYPEDEF_SPI;

#ifdef __cplusplus
}
#endif

#endif 