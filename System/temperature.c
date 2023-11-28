#include"temperature.h"

extern SPI_HandleTypeDef hspi1;

static float current;

// ------------------- Function ----------------
void get_temperature(void){
	uint8_t buffer[2];
	HAL_GPIO_WritePin(SS_PORT,SS_PIN,GPIO_PIN_RESET); // začne SPI komunikacijo
	HAL_SPI_Receive(&hspi1,buffer,2,50);			  // prejme podatke iz slava
	HAL_GPIO_WritePin(SS_PORT,SS_PIN,GPIO_PIN_SET);   // konča SPI komunikacijo
	int value = buffer[0];
	value <<= 8;
	value |= buffer[1];

	if (value & 0x4)
	{
		SCI_send_string("No sensor detected!");
	}

	value >>= 3;

	current = 0.25 * (float)value;

}

float get_current_temperature(void)
{
	char str[80];
	snprintf(str, 80, "%.2f - %d\n", (float)current, (int)current);
	SCI_send_string(str);
	return current;
}

void update_temperature(void){
	char str[80];
	snprintf(str, 80, "[%ld%cC]", (long)current, 0xF8);
    UG_SetForecolor(0xFFFF);
    UG_SetBackcolor(0x0000);
    UG_PutString(140, 100, str);
}

