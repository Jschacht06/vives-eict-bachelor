#include "stm32l476xx.h"
#include "stdbool.h"
#include "buttons.h"

// Knoppen als input initialiseren.
void InitButtons(void)
{
	// Clock voor GPIOA inschakelen.
	RCC->AHB2ENR = RCC->AHB2ENR | RCC_AHB2ENR_GPIOAEN;
	
	// Clock voor GPIOB inschakelen.
	RCC->AHB2ENR = RCC->AHB2ENR | RCC_AHB2ENR_GPIOBEN;
	
	// Clock voor GPIOC inschakelen.
	RCC->AHB2ENR = RCC->AHB2ENR | RCC_AHB2ENR_GPIOCEN;	
	
	// Alle pinnen met drukknoppen verbonden, op input zetten.
	GPIOA->MODER = GPIOA->MODER & ~GPIO_MODER_MODER1;
	GPIOA->MODER = GPIOA->MODER & ~GPIO_MODER_MODER4;	
	GPIOB->MODER = GPIOB->MODER & ~GPIO_MODER_MODER0;
	GPIOC->MODER = GPIOC->MODER & ~GPIO_MODER_MODER1;
	GPIOC->MODER = GPIOC->MODER & ~GPIO_MODER_MODER13;
}

bool SW1Active(void)
{
	// SW1 actief?
	if((GPIOA->IDR & GPIO_IDR_ID1) != GPIO_IDR_ID1)
			return true;
	else
			return false;
}		
	
bool SW2Active(void)
{
	// SW2 actief?
	if((GPIOA->IDR & GPIO_IDR_ID4) != GPIO_IDR_ID4)
			return true;
	else
			return false;
}

bool SW3Active(void)
{
	// SW3 actief?
	if((GPIOB->IDR & GPIO_IDR_ID0) != GPIO_IDR_ID0)
			return true;
	else
			return false;
}

bool SW4Active(void)
{
	// SW4 actief?
	if((GPIOC->IDR & GPIO_IDR_ID1) != GPIO_IDR_ID1)
			return true;
	else
			return false;
}

bool UserButtonActive(void)
{
	// User button actief?
	if((GPIOC->IDR & GPIO_IDR_ID13) != GPIO_IDR_ID13)
			return true;
	else
			return false;
}
