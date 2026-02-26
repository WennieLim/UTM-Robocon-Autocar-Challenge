/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
	char receive;

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void Forward(){
	//Motor(Left Wheel)//
      htim3.Instance->CCR1=10000;//Enable Motor 1,Left wheel
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);//Set Input 1 of Motor 1
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);//Set Input 2 of Motor 1
	//Motor(Right Wheel)//
      htim2.Instance->CCR1=10000;//Enable Motor 2,Right wheel
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);//Set Input 1 of Motor 2
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);//Set Input 2 of Motor 2
				    }

void Backward(){
	//Motor(Left Wheel)//
	   htim3.Instance->CCR1=10000;//Enable Motor 1,Left wheel
	   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);//Set Input 1 of Motor 1
	   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);//Set Input 2 of Motor 1
	 //Motor(Right Wheel)//
	   htim2.Instance->CCR1=10000;//Enable Motor 2,Right wheel
	   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);//Set Input 1 of Motor 2
	   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);//Set Input 2 of Motor 2
					}

void turnLeft(){
	//Motor(Left Wheel)//
	  htim3.Instance->CCR1=10000;//Enable Motor 1,Left wheel
  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);//Set Input 1 of Motor 1
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);//Set Input 2 of Motor 1
    //Motor(Right Wheel)//
	  htim2.Instance->CCR1=15000;//Enable Motor 2,Right wheel
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);//Set Input 1 of Motor 2
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);//Set Input 2 of Motor 2
                }

void turnRight(){
	//Motor(Left Wheel)//
	  htim3.Instance->CCR1=10000;//Enable Motor 1,Left wheel
  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);//Set Input 1 of Motor 1
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);//Set Input 2 of Motor 1
    //Motor(Right Wheel)//
	  htim2.Instance->CCR1=15000;//Enable Motor 2,Right wheel
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);//Set Input 1 of Motor 2
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);//Set Input 2 of Motor 2
                }

void stop(){
	//Motor(Left Wheel)//
	htim3.Instance->CCR1=7000;//Enable Motor 1,Left wheel
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);//Set Input 1 of Motor 1
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);//Set Input 2 of Motor 1
	//Motor(Right Wheel)//
	htim2.Instance->CCR1=10000;//Enable Motor 2,Right wheel
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);//Set Input 1 of Motor 2
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);//Set Input 2 of Motor 2
}
void bigturnLeft(){
	//Motor(Left Wheel)//
	  htim3.Instance->CCR1=15000;//Enable Motor 1,Left wheel
  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);//Set Input 1 of Motor 1
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);//Set Input 2 of Motor 1
    //Motor(Right Wheel)//
	  htim2.Instance->CCR1=15000;//Enable Motor 2,Right wheel
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);//Set Input 1 of Motor 2
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);//Set Input 2 of Motor 2
	//HalDelay
	  HAL_Delay(250);
					}

void bigturnRight(){
	//Motor(Left Wheel)//
	  htim3.Instance->CCR1=15000;//Enable Motor 1,Left wheel
  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);//Set Input 1 of Motor 1
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);//Set Input 2 of Motor 1
    //Motor(Right Wheel)//
	  htim2.Instance->CCR1=15000;//Enable Motor 2,Right wheel
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);//Set Input 1 of Motor 2
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);//Set Input 2 of Motor 2
	//HalDelay
	  HAL_Delay(250);
 	 	 	 	   }







/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  int y=1;
  int sensor1;
  int sensor2;
  int sensor3;
  int sensor4;
	HAL_UART_Receive_IT(&huart1,&receive,1);
   HAL_TIM_Base_Start(&htim3);
   HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
   HAL_TIM_Base_Start(&htim2);
   HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0)==0){
		  y=0;
	  }
	  if (y==0){
	//Motor(Left Wheel)//
	  htim3.Instance->CCR1=8000;//Enable Motor 1,Left wheel
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);//Set Input 1 of Motor 1
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);//Set Input 2 of Motor 1
	//Motor(Right Wheel)//
      htim2.Instance->CCR1=8000;//Enable Motor 2,Right wheel
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);//Set Input 1 of Motor 2
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);//Set Input 2 of Motor 2
		  				    }


	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 72-1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 20000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 72-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 20000;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA1 PA2 PA4 PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB5 PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PA12 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef*huart){
	//input prompt

	HAL_UART_Transmit(&huart1, (uint8_t*)"Enter F/B/L/R:", 14, 100);

	if(receive=='F'){
			Forward();
			HAL_UART_Transmit(&huart1, (uint8_t*)"Forward", 7, 100);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
		}
		else if(receive=='G'){
			Backward();
			HAL_UART_Transmit(&huart1, (uint8_t*)"Backward", 8, 100);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8);

		}
		else if(receive=='R'){
			turnLeft();
			HAL_UART_Transmit(&huart1, (uint8_t*)"turnRight", 8, 100);
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
		}
		else if(receive=='L'){
			turnRight();
			HAL_UART_Transmit(&huart1, (uint8_t*)"turnLeft", 8,100);
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
		}
		else if(receive=='S'){
			stop();
			HAL_UART_Transmit(&huart1, (uint8_t*)"stop", 4,100);
		}
		else if(receive=='P'){
		    bigturnLeft();
			HAL_UART_Transmit(&huart1, (uint32_t*)"bigturnLeft", 11, 100);
		}
		else if(receive=='Q'){
			bigturnRight();
			HAL_UART_Transmit(&huart1, (uint8_t*)"bigturnRight", 12, 100);
		}
		else{
			HAL_UART_Transmit(&huart1, (uint8_t*)"Error", 5, 100);
		}


	HAL_UART_Receive_IT(&huart1,&receive,1);
	}



/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
