#ifndef __SPI_H
#define __SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include <main.h>
  
typedef struct 
{
    uint32_t runTime;
    uint32_t defaultDelay;

    struct
    {
        uint16_t head;
        uint16_t tail;
    }ringBuffer;
    
}SPI_HANDLE_TYPEDEF_STRUCT;

void casCade_Proc(uint16_t delay);

#ifdef __cplusplus
}
#endif

#endif 