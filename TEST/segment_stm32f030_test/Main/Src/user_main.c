#include <main.h>

#include "../Inc/user_main.h"
#define MAIN_TASK   10
#define SUB_TASK    10

static USER_TYPEDEF USRM;

void mainTask(uint32_t delay)
{

}

void subTask(uint32_t delay)
{

}

void StartDefaultTask(void const * argument)
{

    while(1)
    {
        mainTask(MAIN_TASK);
        osDelayUntil(&USRM.tick_main, MAIN_TASK);
    }
}

void StartSubTask(void const * argument)
{
    while(1)
    {
        subTask(SUB_TASK);
        osDelayUntil(&USRM.tick_sub, SUB_TASK);
    }
}