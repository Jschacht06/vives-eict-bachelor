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
#include "stdlib.h"
#include "string.h"
#include "leds.h"
#include "buttons.h"
#include "usart1.h"
#include "usart2.h"
#include "ad.h"
#include "stdio.h"
#include "circularBuffer.h"
#include "esp32c3.h"
#include "wifi.h"
#include <ctype.h> 
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
ADC_HandleTypeDef hadc1;

IWDG_HandleTypeDef hiwdg;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
// Timer handle voor PWM (TIM2)
static uint8_t buttonsValue = 0, index = 0;
static uint16_t adValue = 0;
static volatile uint32_t ticks = 0;

static bool userButtonHelp = false, sw1Help = false, sw2Help = false, sw3Help = false, sw4Help = false;	
volatile bool timerTicked = false;
static bool timeBasedPublishing = false;
static char text[CHAR_ARRAY_BUFFER_LENGTH];
static char receivedText[CHAR_ARRAY_BUFFER_LENGTH];
static char httpParameters[CHAR_ARRAY_BUFFER_LENGTH];
static volatile enum UsartState usart1State =	idle;

extern volatile CircularBuffer circularBuffer;
extern enum CircularBufferActionResult circularBufferActionResult;
static uint8_t leds = 0, numberOfReceivedBytes = 0;

static volatile uint8_t receivedUsart1Data = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_IWDG_Init(void);
static void MX_TIM2_Init(void);
void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
/* USER CODE BEGIN PFP */

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
  HAL_Init();

  /* USER CODE BEGIN Init */
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();
  MX_USART1_UART_Init();
  MX_IWDG_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	printf("Reboot\r\n");	
	printf("User button = start/stop pushing to Firebase.\r\n");
	
	if(InitCircularBuffer(&circularBuffer) != INIT_SUCCEEDED)
		printf("Initialization of CircularBuffer failed!\r\n");
	
	HAL_Delay(1000);
	
	HAL_UART_Receive_IT(&huart1, (uint8_t*)&receivedUsart1Data, 1);
	
	// Start PWM op TIM2 Channel 2 (PB3 - LED2)
	if (HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2) != HAL_OK)
    {
        printf("Fout: Kon PWM TIM2 CH2 niet starten!\r\n");
    }
    else
    {
        printf("PWM TIM2 CH2 gestart.\r\n");
    }
	
	// WiFi & MQTT Setup
	StringToUsart1("AT\r\n");
	while(!LookForString1(&circularBuffer, "OK\r\n"));
	
	StringToUsart1("AT+RST\r\n");
	while(!LookForString1(&circularBuffer, "ready\r\n"));
	
	StringToUsart1("AT+GMR\r\n");
	while(!LookForString1(&circularBuffer, "OK\r\n"));
	
	ConnectToWiFiNetwork(WIFI_SSID, WIFI_PWD);
	
	ConnectToMqttBroker(MQTT_BROKER_ADDRESS, MQTT_PORT, MQTT_USER, MQTT_PWD, MQTT_CLIENT_ID);
	
	SubscribeToMqttTopic(MQTT_SUB_TOPIC);
	
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		HAL_IWDG_Refresh(&hiwdg);
		
		adValue = (uint8_t)(GetAdValue(&hadc1) >> 4);
			
		buttonsValue = 0;
		if(SW1Active()) buttonsValue |= 0x01;
		if(SW2Active()) buttonsValue |= 0x02;
		if(SW3Active()) buttonsValue |= 0x04;
		if(SW4Active()) buttonsValue |= 0x08;
		if(UserButtonActive()) buttonsValue |= 0x10;
		
		ByteToLeds(leds);

		// HTTP/HTTPS logic (behoud van functionaliteit)
		if(SW1Active() && sw1Help == false) {
			sw1Help = true;
			sprintf(httpParameters, "apikey=%s", HTTP_APIKEY);
			HttpRequest(HTTP_HOST, HTTP_URL_GET, 80, GET, httpParameters);
		}		
		if(!SW1Active()) sw1Help = false;
		
		if(SW2Active() && sw2Help == false) {
			sw2Help = true;
			sprintf(httpParameters, "apikey=%s&ad=%d", HTTP_APIKEY, adValue);
			HttpRequest(HTTP_HOST, HTTP_URL_POST, 80, POST, httpParameters);
		}		
		if(!SW2Active()) sw2Help = false;
		
		if(SW3Active() && sw3Help == false) {
			sw3Help = true;
			sprintf(httpParameters, "auth=%s", HTTPS_DATABASE_SECRET);
			HttpsRequest(HTTPS_HOST, HTTPS_URL_GET, 443, GET, httpParameters);
		}		
		if(!SW3Active()) sw3Help = false;
		
		if(SW4Active() && sw4Help == false) {
			sw4Help = true;
			sprintf(httpParameters, "{\"advalue\":%d}", adValue);
			sprintf(text, "%s?auth=%s", HTTPS_URL_PATCH, HTTPS_DATABASE_SECRET);
			HttpsRequest(HTTPS_HOST, text, 443, PATCH, httpParameters);
		}		
		if(!SW4Active()) sw4Help = false;
		
		if(UserButtonActive() && userButtonHelp == false) {
			userButtonHelp = true;
			timeBasedPublishing = !timeBasedPublishing;
		}		
		if(!UserButtonActive()) userButtonHelp = false;		
		
		if(timeBasedPublishing && timerTicked) {
			timerTicked = false;
			sprintf(text, "%d", adValue); 
			MqttPublish(MQTT_PUB_TOPIC, text);	
		}

		// Buffer handling (De kern voor de LED Dimmer!)
		while(circularBuffer.numberOfStringsInBuffer > 0)
		{		
			circularBufferActionResult = PopStringFromCircularBuffer(&circularBuffer, receivedText);
			if(circularBufferActionResult == READ_STRING_SUCCEEDED)
			{				
				// HTTP(S) response
				if(strncmp("+IPD,", receivedText, 5) == 0)
				{				
					while(!LookForString1(&circularBuffer, "\r\n"));
					while(circularBuffer.numberOfStringsInBuffer == 0);
					circularBufferActionResult = PopStringFromCircularBuffer(&circularBuffer, receivedText);
					leds = (uint8_t)atoi(receivedText);
					ByteToLeds(leds);
				}
				
				// MQTT: Labo 5.2
				sprintf(text, "+MQTTSUBRECV:0,\"%s\",", MQTT_SUB_TOPIC);
				index = strlen(text);

				if(strncmp(text, receivedText, index) == 0)
				{
					char *lastComma = strrchr(receivedText, ',');
					
					if (lastComma != NULL)
					{
						char *dataStart = lastComma + 1;
						bool isValidNumber = true;

						// Validatie: Is het een getal?
						if (*dataStart == '\r' || *dataStart == '\n' || *dataStart == '\0') 
							isValidNumber = false;
						else {
							for (int i = 0; dataStart[i] != '\r' && dataStart[i] != '\n' && dataStart[i] != '\0'; i++) {
								if (!isdigit((unsigned char)dataStart[i])) {
									isValidNumber = false;
									break;
								}
							}
						}

						if (isValidNumber)
						{
							int receivedVal = atoi(dataStart);
							
							if (receivedVal >= 0 && receivedVal <= 100)
							{
								// Schaal 0-100 naar 0-1000
								uint32_t pulseValue = receivedVal * 10;
								__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, pulseValue);
								printf("MQTT Dimmer (PB3): %d%% (Pulse=%lu)\r\n", receivedVal, pulseValue);
							}
							else
							{
								// Fout: Buiten bereik -> LED uit
								__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
								printf("Fout: Waarde %d buiten bereik. LED uit.\r\n", receivedVal);
							}
						}
						else
						{
							// Fout: Geen getal -> LED uit
							__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
							printf("Fout: Ongeldige data. LED uit.\r\n");
						}
					}
				}
			}
		}
		HAL_Delay(10);
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
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  hadc1.Init.OversamplingMode = DISABLE;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_2CYCLES_5;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief IWDG Initialization Function
  * @param None
  * @retval None
  */
static void MX_IWDG_Init(void)
{

  /* USER CODE BEGIN IWDG_Init 0 */

  /* USER CODE END IWDG_Init 0 */

  /* USER CODE BEGIN IWDG_Init 1 */

  /* USER CODE END IWDG_Init 1 */
  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_256;
  hiwdg.Init.Window = 4095;
  hiwdg.Init.Reload = 1249;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN IWDG_Init 2 */

  /* USER CODE END IWDG_Init 2 */

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
  htim2.Init.Prescaler = 79;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 999;
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
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

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
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT;
  huart1.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_RXOVERRUNDISABLE_INIT;
  huart2.AdvancedInit.OverrunDisable = UART_ADVFEATURE_OVERRUN_DISABLE;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED1_Pin|LED7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, UserLED_Pin|LED6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  // LED2 is eruit, want die is nu TIM2 CH2
  HAL_GPIO_WritePin(GPIOB, LED5_Pin|LED4_Pin|LED3_Pin|LED8_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : UserButton_Pin SW4_Pin */
  GPIO_InitStruct.Pin = UserButton_Pin|SW4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_Pin LED7_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : SW1_Pin SW2_Pin */
  GPIO_InitStruct.Pin = SW1_Pin|SW2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : UserLED_Pin LED6_Pin */
  GPIO_InitStruct.Pin = UserLED_Pin|LED6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : SW3_Pin */
  GPIO_InitStruct.Pin = SW3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SW3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED5_Pin LED4_Pin LED3_Pin LED8_Pin */
  GPIO_InitStruct.Pin = LED5_Pin|LED4_Pin|LED3_Pin|LED8_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	if(UartHandle->Instance == USART1)
	{		
		HAL_UART_Transmit(&huart2, (uint8_t *)&receivedUsart1Data, 1, 0);
		
		if(usart1State == busyReceiving)
		{
			if(!IsCircularBufferFull(&circularBuffer))
			{
				PushCharToCircularBuffer(&circularBuffer, receivedUsart1Data);
				if(receivedUsart1Data == '\n') usart1State = idle;
			}
		}
		else
		{
			if(usart1State == idle)
			{
				if(!IsCircularBufferFull(&circularBuffer))
				{
					usart1State = busyReceiving;
					PushCharToCircularBuffer(&circularBuffer, receivedUsart1Data);
					
					if(receivedUsart1Data == '\n') usart1State = idle;
					else
					{					
						if(receivedUsart1Data == '>')
						{							
							PushCharToCircularBuffer(&circularBuffer, '\r');
							PushCharToCircularBuffer(&circularBuffer, '\n');
							usart1State = idle;
						}
					}
				}
			}				
		}		
		HAL_UART_Receive_IT(&huart1, (uint8_t*)&receivedUsart1Data, 1);
	}
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
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  * where the assert_param error has occurred.
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