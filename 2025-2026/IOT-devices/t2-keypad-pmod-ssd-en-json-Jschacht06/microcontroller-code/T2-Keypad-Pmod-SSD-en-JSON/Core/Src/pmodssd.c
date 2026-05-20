#include "pmodssd.h"
#include "main.h"

void SetSegments(uint8_t data, enum Display display)
{
	// Data maskeren zodat die niet hoger dan 15 kan zijn.
	data &= 0x0F;
	
	// Segmenten aansturen.
	switch(data)
	{
		case 0:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
			break;
		
		case 1:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
			break;
		
		case 2:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 3:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 4:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 5:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 6:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 7:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
			break;
		
		case 8:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 9:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 10:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 11:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 12:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 13:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 14:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
		
		case 15:
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
			break;
	}
	
	// Linker of rechter display aansturen. Of alles uitdoven.
	if(display == left)
		HAL_GPIO_WritePin(CAT_GPIO_Port, CAT_Pin, GPIO_PIN_SET);
	else
		if(display == right)
			HAL_GPIO_WritePin(CAT_GPIO_Port, CAT_Pin, GPIO_PIN_RESET);
		else
		{
			HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_RESET);
		}
			
}
