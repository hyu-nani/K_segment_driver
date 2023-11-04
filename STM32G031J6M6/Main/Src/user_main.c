#include "../Inc/user_main.h"


void mainTask(uint16_t delay)
{
    casCade_Proc(delay);
}

void initTask(void)
{

}

void subTask(uint16_t delay)
{

}

/* USER CODE BEGIN Header_startMainTask */
/**
  * @brief  Function implementing the mainTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_startMainTask */
void startMainTask(void *argument)
{
    /* USER CODE BEGIN 5 */
    initTask();
    /* Infinite loop */
    for(;;)
    {
        mainTask(10);
        osDelay(1);
    }
    /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_startSubTask */
/**
* @brief Function implementing the subTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startSubTask */
void startSubTask(void *argument)
{
    /* USER CODE BEGIN startSubTask */
    /* Infinite loop */
    for(;;)
    {
        subTask(10);
        osDelay(1);
    }
    /* USER CODE END startSubTask */
}