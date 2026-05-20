#include "stm32l476xx.h"
#include "ad.h"

// AD-module initialiseren
void InitAd(void)
{
	// Poort A 0 als analoge ingang (potentiometer op het Nucleo Extension Shield).
	GPIOA->MODER |= GPIO_MODER_MODER0;
	
	// Analog switch juist zetten.
	GPIOA->ASCR |= GPIO_ASCR_ASC0;
	
	// AD-module van klok voorzien.
	RCC->AHB2ENR |= RCC_AHB2ENR_ADCEN;
	
	// ADC uitschakelen (optioneel na reset).
	ADC1->CR &= ~ADC_CR_ADEN;
	
	// Clock source instellen (HCLK/4).
	ADC123_COMMON->CCR |= ADC_CCR_CKMODE;
	
	// Deep-power-down uitschakelen.
	ADC1->CR &= ~ADC_CR_DEEPPWD;
	
	// AD voltage regulator inschakelen.
	ADC1->CR |= ADC_CR_ADVREGEN;
	
	// Single ended meten. Niet differentieel meten dus, maar ten opzichte van massa... (optioneel na reset).
	ADC1->DIFSEL = 0;
	
	// Right alignment (optioneel na reset).
	ADC1->CFGR &= ~ADC_CFGR_ALIGN;
	
	// Tragere sample rate kiezen (voor hoogimpedante analoge bronnen).
	ADC1->SMPR1 |= ADC_SMPR1_SMP0;
	
	// Single conversion (optioneel na reset).
	ADC1->CFGR &= ~ADC_CFGR_CONT;
	
	// Regular channel sequence length = 1 (optioneel na reset).
	ADC1->SQR1 &= ~ADC_SQR1_L;
	
	// Channel select (PA0 = IN5).
	ADC1->SQR1 |= ADC_SQR1_SQ1_2 | ADC_SQR1_SQ1_0;
	
	// ADC ready vlag wissen.
	ADC1->ISR |= ADC_ISR_ADRDY;
	
	// ADC inschakelen.
	ADC1->CR |= ADC_CR_ADEN;
	while ((ADC1->ISR & ADC_ISR_ADRDY) == 0);
}

// De blokkerende versie van de AD-conversie.
uint16_t GetAdValue(void)
{
	uint32_t temp = 0;
	
	ADC1->CR |= ADC_CR_ADSTART; 								// Start de AD-omzetting.	
	while ((ADC1->ISR & ADC_ISR_EOS) == 0);			// Wachten op einde sequentie (sequentie bestaat hier uit één conversie).	
	ADC1->ISR |= ADC_ISR_EOS;										// Vlag wissen.
	temp = ADC1->DR;
	
	return (uint16_t)temp;
}
