
#include "PI.h"

float Kp = 50; // nastavitev P dela povečaš hitrejši odziv, pomanjšaš počasnejši odziv
float Ki = 0.02; // nastavitev I dela povečaš hitrejši odziv, pomanjšaš počasnejši odziv



int PI(float set_temp, float temp){
	static float napaka;
	napaka = set_temp - temp;
	static float napakaInt = 0;
	bool sample = 0;
	int tickstart;

	if(sample == 0){
		sample = 1;
		tickstart = HAL_GetTick();
	}

	if(tickstart + 300 < HAL_GetTick()){
		sample = 0;
		if(napaka < 10){
			napakaInt += napaka * Ki;
		}
		if(napaka < 0){
			napakaInt = 0;
		}
	}

	return (int)(((napaka * Kp) + napakaInt) - set_temp);
}


