#include <main.h>

#include "../Inc/user_main.h"

/* private defines -----------------------------------------------------------*/
#define MAIN_TASK_FREQ  10
#define SUB_TASK_FREQ   10


static USER_TYPEDEF USRM;

void mainTask(uint32_t delay)
{
    osDelay(1);
}

void subTask(uint32_t delay)
{
    osDelay(1);
}

void StartDefaultTask(void const * argument)
{
    USRM.tick_main = osKernelSysTick();
    while(1)
    {
        mainTask(MAIN_TASK_FREQ);
        osDelayUntil(&USRM.tick_main, MAIN_TASK_FREQ);
    }
}

void StartSubTask(void const * argument)
{
    USRM.tick_sub = osKernelSysTick();
    while(1)
    {
        subTask(SUB_TASK_FREQ);
        osDelayUntil(&USRM.tick_sub, SUB_TASK_FREQ);
    }
}