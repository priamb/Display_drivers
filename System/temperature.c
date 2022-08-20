
#include"temperature.h"

extern SPI_HandleTypeDef hspi1;

// ------------------- Function ----------------
float get_temperature(void){
	float Temp = 0;
	uint8_t buffer[2];
	HAL_GPIO_WritePin(SS_PORT,SS_PIN,GPIO_PIN_RESET);
	HAL_SPI_Receive(&hspi1,buffer,2,50);
	HAL_GPIO_WritePin(SS_PORT,SS_PIN,GPIO_PIN_SET);
	int value = buffer[0];
	value <<= 8;
	value |= buffer[1];

	if (value & 0x4)
	{
		SCI_send_string("No sensor detected!");
	}

	value >>= 3;

	Temp = 0.25 * (float)value;
	HAL_Delay(200);
	char* str = NULL;
	asprintf(&str, "%.2f - ", (float)Temp);
	SCI_send_string(str);
	free(str);

	return Temp;
}

