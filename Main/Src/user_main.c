#include <main.h>
#include "../Inc/user_main.h"

void initTask(void)
{
    showLED();
    allStateLED(GPIO_PIN_RESET);
}

void mainTask(void)
{
    insertStateLED(1, GPIO_PIN_SET);
    showLED();
}