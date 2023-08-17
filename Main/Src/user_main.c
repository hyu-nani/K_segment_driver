#include <main.h>
#include "../Inc/user_main.h"

/**
 * brief : initialize code
 * note  :
 * param :
 * return:
*/
void initTask(void)
{
    showLED();
    allStateLED(GPIO_PIN_RESET);
}

/**
 * brief : main code 
 * note  :
 * param :
 * return:
*/
void mainTask(void)
{
    insertStateLED(1, GPIO_PIN_SET);
    showLED();
}