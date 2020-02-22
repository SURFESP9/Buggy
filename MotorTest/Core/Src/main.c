/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <math.h>
#include "Motors_And_Encoders.h"

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Reset_Encoders(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  

  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_0);

  /* System interrupt init*/

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  Configure_Encoder_Left();
  Configure_Motor_Left();
  Configure_Encoder_Right();
  Configure_Motor_Right();
  Reset_Encoders();
  Set_DutyCycle_Motor_Left(50);
  Set_DutyCycle_Motor_Right(50);
  LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_8);
  LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_9);
  LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_10);
  LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_10);
  LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_12);

/*
  LL_mDelay(3000);//Initial delay
  Set_DutyCycle_Motor_Left(75);
  Set_DutyCycle_Motor_Right(75);
  LL_mDelay(800);// Move forward
  Set_DutyCycle_Motor_Left(50);
  Set_DutyCycle_Motor_Right(50);
  LL_mDelay(300);// Pause
  Set_DutyCycle_Motor_Left(75);
  Set_DutyCycle_Motor_Right(25);
  LL_mDelay(360);// Turn right
  Set_DutyCycle_Motor_Left(50);
  Set_DutyCycle_Motor_Right(50);
  LL_mDelay(300);// Pause
  Set_DutyCycle_Motor_Left(75);
  Set_DutyCycle_Motor_Right(75);
  LL_mDelay(660);// Move forward
  Set_DutyCycle_Motor_Left(50);
  Set_DutyCycle_Motor_Right(50);
  LL_mDelay(300);// Pause
  Set_DutyCycle_Motor_Left(75);
  Set_DutyCycle_Motor_Right(25);
  LL_mDelay(360);// Turn right
  Set_DutyCycle_Motor_Left(50);
  Set_DutyCycle_Motor_Right(50);
  LL_mDelay(300);// Pause
  Set_DutyCycle_Motor_Left(75);
  Set_DutyCycle_Motor_Right(75);
  LL_mDelay(660);// Move forward
  Set_DutyCycle_Motor_Left(50);
  Set_DutyCycle_Motor_Right(50);
  LL_mDelay(300);// Pause
  Set_DutyCycle_Motor_Left(75);
  Set_DutyCycle_Motor_Right(25);
  LL_mDelay(360);// Turn right
  Set_DutyCycle_Motor_Left(50);
  Set_DutyCycle_Motor_Right(50);
  LL_mDelay(300);// Pause
  Set_DutyCycle_Motor_Left(75);
  Set_DutyCycle_Motor_Right(75);
  LL_mDelay(660);// Move forward

  Set_DutyCycle_Motor_Left(50);
  Set_DutyCycle_Motor_Right(50);// STOP
  LL_mDelay(300);// Pause
  Set_DutyCycle_Motor_Left(75);
  Set_DutyCycle_Motor_Right(25);
  LL_mDelay(640);// Turn around

  Set_DutyCycle_Motor_Left(50);
  Set_DutyCycle_Motor_Right(50);
  LL_mDelay(300);// Pause
   Set_DutyCycle_Motor_Left(75);
   Set_DutyCycle_Motor_Right(75);
   LL_mDelay(600);// Move forward
   Set_DutyCycle_Motor_Left(50);
   Set_DutyCycle_Motor_Right(50);
   LL_mDelay(300);// Pause
   Set_DutyCycle_Motor_Left(25);
   Set_DutyCycle_Motor_Right(75);
   LL_mDelay(355);// Turn right
   Set_DutyCycle_Motor_Left(50);
   Set_DutyCycle_Motor_Right(50);
   LL_mDelay(300);// Pause
   Set_DutyCycle_Motor_Left(75);
   Set_DutyCycle_Motor_Right(75);
   LL_mDelay(660);// Move forward
   Set_DutyCycle_Motor_Left(50);
   Set_DutyCycle_Motor_Right(50);
   LL_mDelay(300);// Pause
   Set_DutyCycle_Motor_Left(25);
   Set_DutyCycle_Motor_Right(75);
   LL_mDelay(355);// Turn right
   Set_DutyCycle_Motor_Left(50);
   Set_DutyCycle_Motor_Right(50);
   LL_mDelay(300);// Pause
   Set_DutyCycle_Motor_Left(75);
   Set_DutyCycle_Motor_Right(75);
   LL_mDelay(660);// Move forward
   Set_DutyCycle_Motor_Left(50);
   Set_DutyCycle_Motor_Right(50);
   LL_mDelay(300);// Pause
   Set_DutyCycle_Motor_Left(25);
   Set_DutyCycle_Motor_Right(75);
   LL_mDelay(355);// Turn right
   Set_DutyCycle_Motor_Left(50);
   Set_DutyCycle_Motor_Right(50);
   LL_mDelay(300);// Pause
   Set_DutyCycle_Motor_Left(75);
   Set_DutyCycle_Motor_Right(75);
   LL_mDelay(660);// Move forward
   Set_DutyCycle_Motor_Left(50);
   Set_DutyCycle_Motor_Right(50);// STOP
   */
  int left = 0;
  int right = 0;
  int l1 = 0;
  int l2 = 0;
  int r1 =0;
  int r2 = 0;

  /* USER CODE END 2 */
 
 

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  Set_DutyCycle_Motor_Left(75);
	  Set_DutyCycle_Motor_Right(75);

	  l1 = Get_Encoder_Left();
	  r1 = Get_Encoder_Right();

	  LL_mDelay(1000);
	  l2 = Get_Encoder_Left();
	  r2 = Get_Encoder_Right();

	  left = (int)((l2-l1)*1.95);
	  right = (int)((r2-r1)*1.95);

	  char strL[5];
	  char strR[5];

	  sprintf(strL, "%d", left);
	  sprintf(strR, "%d", right);


	  LL_USART_TransmitData8(USART2, 'R');
	  LL_mDelay(10);
	  LL_USART_TransmitData8(USART2, ':');
	  LL_mDelay(10);
	  for(int i = 0; i < 5; i++){
		  LL_USART_TransmitData8(USART2, strL[i]);
		  LL_mDelay(10);
	  }
  	  LL_USART_TransmitData8(USART2, 'L');
  	  LL_mDelay(10);
  	  LL_USART_TransmitData8(USART2, ':');
  	  LL_mDelay(10);
  	  for(int i = 0; i < 5; i++){
  		  LL_USART_TransmitData8(USART2, strR[i]);
  		  LL_mDelay(10);
  	  }

	  LL_mDelay(10);
	  LL_USART_TransmitData8(USART2, 0xA);
	  LL_mDelay(10);



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);

   if(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_2)
  {
  Error_Handler();  
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE2);
  LL_RCC_HSE_EnableBypass();
  LL_RCC_HSE_Enable();

   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {
    
  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_8, 336, LL_RCC_PLLP_DIV_4);
  LL_RCC_PLL_Enable();

   /* Wait till PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {
    
  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {
  
  }
  LL_Init1msTick(84000000);
  LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
  LL_SetSystemCoreClock(84000000);
  LL_RCC_SetTIMPrescaler(LL_RCC_TIM_PRESCALER_TWICE);
}

/* USER CODE BEGIN 4 */
void Reset_Encoders(void){
	NVIC_DisableIRQ(TIM2_IRQn);
	NVIC_DisableIRQ(TIM5_IRQn);

	LL_TIM_SetCounter(TIM2, 0);
	LL_TIM_SetCounter(TIM5, 0);

	NVIC_EnableIRQ(TIM2_IRQn);
	NVIC_EnableIRQ(TIM5_IRQn);
}


//**************Handlers and Callbacks*********************//
void TIM5_IRQHandler(void)
{
  /* Check whether CC1 interrupt is pending */
  if(LL_TIM_IsActiveFlag_CC1(TIM5) == 1)
  {
    /* Clear the update interrupt flag*/
    LL_TIM_ClearFlag_CC1(TIM5);
  }
}

void TIM2_IRQHandler(void)
{
  /* Check whether CC1 interrupt is pending */
  if(LL_TIM_IsActiveFlag_CC1(TIM2) == 1)
  {
    /* Clear the update interrupt flag*/
    LL_TIM_ClearFlag_CC1(TIM2);
  }
}

void EXTI15_10_IRQHandler(void){
	static volatile bool onoff;
	LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_13);
}

void SysTick_Callback(void){
	//use this as a 1 ms interrupt
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
