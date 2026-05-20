#include "keypad.h"
#include "main.h"

// Toestand van de knoppen opvragen. Eén bit per knop. Dus 12 bit nodig...
uint16_t GetKeys(void)
{
	// Om onderstaande te kunnen gebruiken, moeten alle pinnen (7 in totaal) reeds
	// ingesteld zijn als input. Daarenboven moeten de kolompinnen (3 in totaal) 
	// ook de pull-up optie hebben ingeschakeld. Doe dat in STM32CubeMX bij de aanvang
	// van het project.
	//
	// De pinout is te vinden op: https://learn.adafruit.com/matrix-keypad/pinouts.
	//
	// Manier van werken: 
	// Maak de kolommen input met pull-up. Maak rijen standaard input zonder pull-up. 
	// Loop één voor één de rijen af en maak die op dat moment laag als output. Zet ze 
	// daarna weer als input zodat de rijen elkaar niet kunnen tegenwerken (er geen 
	// 'kortsluitstromen' zouden vloeien).
	
	// Nieuwe struct aanmaken om de rijen telkens van mode te wisselen.
	GPIO_InitTypeDef GPIO_ReInit = {0};

	// Variabele die de toestand van de knoppen bevat.
	uint16_t keys = 0;

	// Rij 1 als output zetten en laag maken.
	GPIO_ReInit.Pin = R1_Pin;
	GPIO_ReInit.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_ReInit.Pull = GPIO_NOPULL;
	GPIO_ReInit.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(R1_GPIO_Port, &GPIO_ReInit);
	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	
	// Knop 1 inlezen.
	if(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin) == GPIO_PIN_RESET)
		keys |= 0x0001;
	
	// Knop 2 inlezen.
	if(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin) == GPIO_PIN_RESET)
		keys |= 0x0002;
	
	// Knop 3 inlezen.
	if(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin) == GPIO_PIN_RESET)
		keys |= 0x0004;
	
	// Rij 1 als input zetten.
	GPIO_ReInit.Pin = R1_Pin;
	GPIO_ReInit.Mode = GPIO_MODE_INPUT;
	GPIO_ReInit.Pull = GPIO_NOPULL;
	GPIO_ReInit.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(R1_GPIO_Port, &GPIO_ReInit);
	
	
	// Rij 2 als output zetten en laag maken.
	GPIO_ReInit.Pin = R2_Pin;
	GPIO_ReInit.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_ReInit.Pull = GPIO_NOPULL;
	GPIO_ReInit.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(R2_GPIO_Port, &GPIO_ReInit);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
			
	// Knop 4 inlezen.
	if(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin) == GPIO_PIN_RESET)
		keys |= 0x0008;
	
	// Knop 5 inlezen.
	if(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin) == GPIO_PIN_RESET)
		keys |= 0x0010;
	
	// Knop 6 inlezen.
	if(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin) == GPIO_PIN_RESET)
		keys |= 0x0020;
	
	// Rij 2 als input zetten.
	GPIO_ReInit.Pin = R2_Pin;
	GPIO_ReInit.Mode = GPIO_MODE_INPUT;
	GPIO_ReInit.Pull = GPIO_NOPULL;
	GPIO_ReInit.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(R2_GPIO_Port, &GPIO_ReInit);
	
	
	// Rij 3 als output zetten en laag maken.
	GPIO_ReInit.Pin = R3_Pin;
	GPIO_ReInit.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_ReInit.Pull = GPIO_NOPULL;
	GPIO_ReInit.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(R3_GPIO_Port, &GPIO_ReInit);
	HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
			
	// Knop 7 inlezen.
	if(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin) == GPIO_PIN_RESET)
		keys |= 0x0040;
	
	// Knop 8 inlezen.
	if(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin) == GPIO_PIN_RESET)
		keys |= 0x0080;
	
	// Knop 9 inlezen.
	if(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin) == GPIO_PIN_RESET)
		keys |= 0x0100;
	
	// Rij 3 als input zetten.
	GPIO_ReInit.Pin = R3_Pin;
	GPIO_ReInit.Mode = GPIO_MODE_INPUT;
	GPIO_ReInit.Pull = GPIO_NOPULL;
	GPIO_ReInit.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(R3_GPIO_Port, &GPIO_ReInit);
	
	
	// Rij 4 als output zetten en laag maken.
	GPIO_ReInit.Pin = R4_Pin;
	GPIO_ReInit.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_ReInit.Pull = GPIO_NOPULL;
	GPIO_ReInit.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(R4_GPIO_Port, &GPIO_ReInit);
	HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);
			
	// Knop 10 inlezen.
	if(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin) == GPIO_PIN_RESET)
		keys |= 0x0200;
	
	// Knop 11 inlezen.
	if(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin) == GPIO_PIN_RESET)
		keys |= 0x0400;
	
	// Knop 12 inlezen.
	if(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin) == GPIO_PIN_RESET)
		keys |= 0x0800;
	
	// Rij 4 als input zetten.
	GPIO_ReInit.Pin = R4_Pin;
	GPIO_ReInit.Mode = GPIO_MODE_INPUT;
	GPIO_ReInit.Pull = GPIO_NOPULL;
	GPIO_ReInit.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(R4_GPIO_Port, &GPIO_ReInit);
	
	return keys;
}
