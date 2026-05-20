// Basiscode voor het starten van eender welk project op een Nucleo-L476RG met Nucleo Extension Shield V2.
//
// OPM: via 'Options for Target -> C/C++' zet je de compiler op C11, optimizations op default en warnings op AC5-like.
// 
// Versie: 20252026

// Includes.
#include "stm32l476xx.h"
#include "stdio.h"
#include "stdbool.h"
#include "leds.h"
#include "buttons.h"
#include "usart2.h"
#include "ad.h"
#include "main.h"

// Functie prototypes.
void SystemClock_Config(void);
void InitIo(void);
void WaitForMs(uint32_t timespan);

// Variabelen aanmaken. 
// OPM: het keyword 'static', zorgt ervoor dat de variabele enkel binnen dit bestand gebruikt kan worden.
static uint8_t count = 0;
static uint16_t adValue = 0;
static volatile uint32_t ticks = 0;
static char text[101];

// Entry point.
int main(void)
{
	// Initialisaties.
	
	SystemClock_Config();
	InitIo();	
	InitButtons();
	InitLeds();
	InitUsart2(9600);
	InitAd();
	
	// Laten weten dat we opgestart zijn, via de USART2 (USB).
	StringToUsart2("Reboot\r\n");
	
	// Oneindige lus starten.
	while (1)
	{		
		// Nucleo Extension Shield knoppen en LED's testen.
		if(SW1Active() || SW2Active() || SW3Active() || SW4Active())
			ByteToLeds(255);
		else
		{
			// User button en AD-conversie testen.
			if(UserButtonActive())
			{		
				adValue = GetAdValue();
				ByteToLevel(adValue >> 4);
				sprintf(text, "AD-value: %d.\r\n", adValue);
				StringToUsart2(text);
				WaitForMs(50);
			}
			else
			{
				// Gewoon optellen indien geen knop bediend wordt.
				WaitForMs(100);
				count++;
				ByteToLeds(count);
			}
		}
	}
	
	return 0;
}

// Functie om extra IO's te initialiseren.
void InitIo(void)
{

}

// Handler die iedere 1ms afloopt. Ingesteld met SystemCoreClockUpdate() en SysTick_Config().
void SysTick_Handler(void)
{
	ticks++;
}

// Wachtfunctie via de SysTick.
void WaitForMs(uint32_t timespan)
{
	uint32_t startTime = ticks;
	
	while(ticks < startTime + timespan);
}

// Klokken instellen. Deze functie niet wijzigen, tenzij je goed weet wat je doet.
void SystemClock_Config(void)
{	
	// 80 MHz instellen via HSI.
	
	// HSI 16 MHz inschakelen.
	RCC->CR  |= RCC_CR_HSION;
	while((RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY);
	
	// Hoofd PLL uitschakelen (optioneel na reset).
	RCC->CR &= ~RCC_CR_PLLON;
	
	// PLL source op HSI16 zetten.
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSI;
	
	// M-deler op /1 zetten (16MHz).
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLM;
	
	// N-vermenigvuldiger op x 10 (160 MHz).
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLN;
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_3 | RCC_PLLCFGR_PLLN_1;
	
	// R-deler op /2 zetten (80 MHz) (optioneel na reset).
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLR;
	
	// Q-deler op /2 zetten (80 MHz) (optioneenl na reset).
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLQ;
	
	// P-deler op /7 zetten (160/7 MHz).
	RCC->PLLCFGR &= ~RCC_PLLCFGR_PLLP;
	
	// Hoofd PLL inschakelen.
	RCC->CR |= RCC_CR_PLLON;
	
	// PLL R-uitgang inschakelen.
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN;	
	
//	// PLL Q-uitgang inschakelen.
//	RCC->PLLCFGR |= RCC_PLLCFGR_PLLQEN;	
//	
//	// PLL P-uitgang inschakelen.
//	RCC->PLLCFGR |= RCC_PLLCFGR_PLLPEN;	
	
	// Wachten op PLL tot die klaar is.
	while((RCC->CR & RCC_CR_PLLRDY) != RCC_CR_PLLRDY);
	
	// Indien je op 80MHz wil werken, 4 Wait States introduceren bij het lezen van FLASH.
	// Meer info in Reference Manual (RM0351) bij paragraaf 3.3.3 Read Access Latency...
	FLASH->ACR |= FLASH_ACR_LATENCY_4WS;
	while((FLASH->ACR & FLASH_ACR_LATENCY_4WS) != FLASH_ACR_LATENCY_4WS);

	// System clock op PLL zetten (SWS is de status en wordt geüpdatet door hardware).
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);	// Wachten to effectief PLL in actie is getreden.
	
	// Nieuwe waarde van de core frequentie opslaan in SystemCoreClock variabele.
	// Zie 'system_stm32l4xx.c' voor meer uitleg.
	SystemCoreClockUpdate();					

	// Interrupt genereren. Zie core_cm0.h, om na ieder 1ms een interrupt 
	// te hebben op SysTick_Handler()...
	SysTick_Config(SYSCLK_FREQ/1000);																		
}

// Versie: 20252026