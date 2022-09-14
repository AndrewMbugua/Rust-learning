#include "main.h"
#include "stm32f1xx_hal.h"  //This header contains all the functions prototypes
                            //for the HAL module driver.

void SystemClock_Config(void);   //Initizing System Clock 8Mhz
void Error_Handler(void);        //Error Handler- We are not going to use it.
static void MX_GPIO_Init(void);  //GPIO Initialization function

int main(void)
{

  HAL_Init();           			//Initialize the Hal Libraries

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();			        //Calling GPIO initializing functions

  /* USER CODE BEGIN WHILE */
  while (1)
  {
    HAL_GPIO_TogglePin(Led_GPIO_Port,Led_Pin);               //Toggle Gpio
    HAL_Delay(1000);					                     //Delay 1 second
  }

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Initializes the CPU, AHB and APB busses clocks
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;   //Using internal 8Mhz oscillator
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

    /**Initializes the CPU, AHB and APB busses clocks
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure the Systick interrupt time
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();                                //Enable GPIO Clock

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Led_GPIO_Port, Led_Pin, GPIO_PIN_RESET);   //Initialize the GPIO Pin Output Level

  /*Configure GPIO pin : Led_Pin */
  GPIO_InitStruct.Pin = Led_Pin;                    //Pin name we give in StmCubeMx Configuration
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;       //Pin Mode Push Pull
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;      //GPIO speed frequency Low
  HAL_GPIO_Init(Led_GPIO_Port, &GPIO_InitStruct);   //Pass the setting perimeters for initialization

}
