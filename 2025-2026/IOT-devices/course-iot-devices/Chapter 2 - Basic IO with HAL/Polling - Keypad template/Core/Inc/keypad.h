#include "stm32l4xx_hal.h"

#if !defined(KEYPAD_DEFINED)
	#define KEYPAD_DEFINED
	
	#define NUMBER_OF_KEYS 12
	
	uint16_t GetKeys(void);
#endif
