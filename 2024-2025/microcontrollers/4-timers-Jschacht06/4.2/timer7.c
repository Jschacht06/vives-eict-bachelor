#include "stm32f091xc.h"
#include "timer7.h"

void InitTimer7(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;	// clock voorzien voor de timer
	
	TIM7->PSC = 47999;									// Als je een klok wil op 1000 Hz:
																			// 48 000 000 / (47 999 + 1) = 1000 Hz
	TIM7->ARR = 50;										// Als je iedere 125 ms een interrupt wil... 
																			// 125 stappen van 1 ms.		
	
	TIM7->DIER |= TIM_DIER_UIE;					// Interrupt enable voor timer 7	
	TIM7->CR1 |= TIM_CR1_CEN;						// counter enable
	
	//TIM7->CR1 |= TIM_CR1_OPM;					// one pulse mode kiezen, 
																			// dan stopt de timer na ??n overflow.
	
	NVIC_SetPriority(TIM7_IRQn, 0);
	NVIC_EnableIRQ(TIM7_IRQn);
}

//void StartTimer7(void)
//{
//	// Volgorde van (groot) belang.		
//	TIM7->CNT = 0;											// Timer resetten	
//	TIM7->EGR |= TIM_EGR_UG;						// registers updaten (in one pulse mode zorgt dit voor het uitzetten van CEN).
//	TIM7->CR1 |= TIM_CR1_CEN;						// counter enable	
//	TIM7->SR &= ~TIM_SR_UIF;						// Interruptvlag resetten	
//	TIM7->DIER |= TIM_DIER_UIE;					// Interrupt enable voor timer 7.
//}

//void StopTimer7(void)
//{	
//	TIM7->DIER &= ~TIM_DIER_UIE;				// Interrupt disable voor timer 7.
//	TIM7->SR &= ~TIM_SR_UIF;						// Interruptvlag resetten
//	TIM7->CR1 &= ~TIM_CR1_CEN;					// counter disable
//}
