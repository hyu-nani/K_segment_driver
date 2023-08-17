#ifndef __SUPPORT_H
#define __SUPPORT_H

#ifdef __cplusplus
extern "C" {
#endif

/* Private defines -----------------------------------------------------------*/
#define LED_NUM             44

/* Private structures --------------------------------------------------------*/

typedef enum
{
    CFALSE = 0x00,
    CTRUE,
} CBOOL;

typedef enum 
{
    LED_OFF = 0x00,
    LED_ON,
    LED_MAX,
} LED_STATE_TypeDef;

typedef struct
{
    CBOOL buf[LED_NUM];
} LED_HANDLE_Struct;

#ifdef __cplusplus
}
#endif
#endif /* __SUPPORT_H */