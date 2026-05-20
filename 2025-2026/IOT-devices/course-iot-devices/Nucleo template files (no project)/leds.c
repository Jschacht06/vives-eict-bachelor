#include "stm32l476xx.h"
#include "stdbool.h"
#include "leds.h"

void InitLeds(void)
{
	// Clock voor GPIOA inschakelen.
	RCC->AHB2ENR = RCC->AHB2ENR | RCC_AHB2ENR_GPIOAEN;
	
	// Clock voor GPIOB inschakelen.
	RCC->AHB2ENR = RCC->AHB2ENR | RCC_AHB2ENR_GPIOBEN;
	
	// Clock voor GPIOC inschakelen.
	RCC->AHB2ENR = RCC->AHB2ENR | RCC_AHB2ENR_GPIOCEN;	
	
	// LED1 tot LED8 op output zetten.
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER0) | GPIO_MODER_MODER0_0;
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER3) | GPIO_MODER_MODER3_0;
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER5) | GPIO_MODER_MODER5_0;
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER4) | GPIO_MODER_MODER4_0;
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER10) | GPIO_MODER_MODER10_0;
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER8) | GPIO_MODER_MODER8_0;
	GPIOC->MODER = (GPIOC->MODER & ~GPIO_MODER_MODER7) | GPIO_MODER_MODER7_0;
	GPIOB->MODER = (GPIOB->MODER & ~GPIO_MODER_MODER6) | GPIO_MODER_MODER6_0;
	
	// User LED op output zetten.
	GPIOA->MODER = (GPIOA->MODER & ~GPIO_MODER_MODER5) | GPIO_MODER_MODER5_0;
}

// Functie om de data van één byte op de 8 LED's te plaatsen
void ByteToLeds(unsigned char data)
{
	if(data & 0x01)
		GPIOC->ODR = GPIOC->ODR | GPIO_ODR_OD0;		// inschakelen
	else
		GPIOC->ODR = GPIOC->ODR & ~GPIO_ODR_OD0;	// uitschakelen

	if(data & 0x02)
		GPIOB->ODR = GPIOB->ODR | GPIO_ODR_OD3;		// inschakelen
	else
		GPIOB->ODR = GPIOB->ODR & ~GPIO_ODR_OD3;	// uitschakelen

	if(data & 0x04)
		GPIOB->ODR = GPIOB->ODR | GPIO_ODR_OD5;		// inschakelen
	else
		GPIOB->ODR = GPIOB->ODR & ~GPIO_ODR_OD5;	// uitschakelen

	if(data & 0x08)
		GPIOB->ODR = GPIOB->ODR | GPIO_ODR_OD4;		// inschakelen
	else
		GPIOB->ODR = GPIOB->ODR & ~GPIO_ODR_OD4;	// uitschakelen

	if(data & 0x10)
		GPIOB->ODR = GPIOB->ODR | GPIO_ODR_OD10;	// inschakelen
	else
		GPIOB->ODR = GPIOB->ODR & ~GPIO_ODR_OD10;	// uitschakelen

	if(data & 0x20)
		GPIOA->ODR = GPIOA->ODR | GPIO_ODR_OD8;		// inschakelen
	else
		GPIOA->ODR = GPIOA->ODR & ~GPIO_ODR_OD8;	// uitschakelen

	if(data & 0x40)
		GPIOC->ODR = GPIOC->ODR | GPIO_ODR_OD7;		// inschakelen
	else
		GPIOC->ODR = GPIOC->ODR & ~GPIO_ODR_OD7;	// uitschakelen

	if(data & 0x80)
		GPIOB->ODR = GPIOB->ODR | GPIO_ODR_OD6;		// inschakelen
	else
		GPIOB->ODR = GPIOB->ODR & ~GPIO_ODR_OD6;	// uitschakelen
}

void ToggleLed(uint8_t ledNumber)
{
	switch(ledNumber)
	{
		case 1:
			GPIOC->ODR = GPIOC->ODR ^ GPIO_ODR_OD0;
			break;
		
		case 2:
			GPIOB->ODR = GPIOB->ODR ^ GPIO_ODR_OD3;
			break;
		
		case 3:
			GPIOB->ODR = GPIOB->ODR ^ GPIO_ODR_OD5;
			break;
		
		case 4:
			GPIOB->ODR = GPIOB->ODR ^ GPIO_ODR_OD4;
			break;
		
		case 5:
			GPIOB->ODR = GPIOB->ODR ^ GPIO_ODR_OD10;
			break;
		
		case 6:
			GPIOA->ODR = GPIOA->ODR ^ GPIO_ODR_OD8;
			break;
		
		case 7:
			GPIOC->ODR = GPIOC->ODR ^ GPIO_ODR_OD7;
			break;
		
		case 8:
			GPIOB->ODR = GPIOB->ODR ^ GPIO_ODR_OD6;
			break;
		
		default:
			break;
	}
}

void ByteToLevel(uint8_t level)
{
    if(level<16)
        ByteToLeds(0);
    else if(level < 48)
        ByteToLeds(1);
    else if(level < 80)
        ByteToLeds(3);
    else if(level < 112)
        ByteToLeds(7);
    else if(level < 144)
        ByteToLeds(15);
    else if(level < 176)
        ByteToLeds(0x1F);
    else if(level < 208)
        ByteToLeds(0x3F);
    else if(level < 240)
        ByteToLeds(0x7F);
    else
        ByteToLeds(255);
}

void SetUserLed(bool onOff)
{
	if(onOff)
		GPIOA->ODR = GPIOA->ODR | GPIO_ODR_OD5;		// inschakelen
	else
		GPIOA->ODR = GPIOA->ODR & ~GPIO_ODR_OD5;	// uitschakelen
}
