#include "stm32l4xx_hal.h"

#if !defined(PMODSSD_DEFINED)
	#define PMODSSD_DEFINED
	
	enum Display {left, right, none};
	
	void SetSegments(uint8_t data, enum Display display);
#endif
