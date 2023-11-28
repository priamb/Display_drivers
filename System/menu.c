#include "PI.h"
#include "screen.h"
#include "slider.h"
#include "temperature.h"
#include "izhod.h"

int current_screen = 1; // TRENUTEN ZASLON
int new_screen = 0;  // NOV ZASLON
int previous_screen = 0; // PREJŠNJI ZASLON

extern int32_t temperature;
extern slider_t slider;

void menu(void)
{
	if (current_screen != new_screen) { // if stavek za vračilo na prejšni zaslon
		previous_screen = current_screen;
		current_screen = new_screen;
		drawScreen(current_screen);
	}

	int action = checkPressed(current_screen);

	switch (current_screen) {
		case 0: // INFORMACIJSKI ZASLON
			if (action == 0) {
				HAL_Delay(10000);
				new_screen = 1;
			}

			break;

		case 1: // ZASLON ZA NAČIN NASTAVLJANJA TEMPERATURE
			if (action == 0) {
				return;
			}
			if (action == 1) { // TIPKA SHRANJENE MERE
				new_screen = 2;
			}
			if (action == 2) { // TIPKA PO MERI
				new_screen = 3;
			}
			break;

		case 2: // ZASLON Z PREDPOSTAVLJENIMI TEMPERATURAMI
			if (action == 0) {
				return;
			}
			if (action == 5) { // TIPKA 180°C
				temperature = 180;
				new_screen = 4;
			}
			if (action == 6) { // TIPKA 190°C
				temperature = 190;
				new_screen = 4;
			}
			if (action == 7) { // TIPKA 200°C
				temperature = 200;
				new_screen = 4;
			}
			if (action == 8) { // TIPKA 210°C
				temperature = 210;
				new_screen = 4;
			}
			if (action == 9) { // TIPKA 220°C
				temperature = 220;
				new_screen = 4;
			}
			if (action == 10) { // TIPKA 230°C
				temperature = 230;
				new_screen = 4;
			}
			break;

		case 3: // ZASLON Z POLJUBNIM NASTAVLJANJEM TEMPERATURE
			if (action == 0) {
				return;
			}
			if (action == 3) { //TIPKA OK
				temperature = slider.value;
				new_screen = 4;
			}
			if (action == 4) { //TIPKA BACK
				new_screen = 1;
			}
			break;

		case 4: // ZASLON ZA POSTAVITEV PCB NA HOT PLATE
			if (action == 0) {
				return;
			}
			if (action == 3) { // TIPKA OK
				new_screen = 5;
			}
			if (action == 4) {  // TIPKA BACK
				new_screen = previous_screen;

			}
			break;

		case 5: // ZASLON ZA OBVEŠČANJE PREDGRETJA
			update_temperature();

			int temp_predgretje = 100; //nastavitev temperature za predgretje
			static bool sample_predgretje = 0;
			static int tickstart_predgretje;

			izhod(PI(temp_predgretje, get_current_temperature())); //ob vsakem ciklu zračuna vrednost napake in prilagodi PWM

			if(sample_predgretje == 0){
					sample_predgretje = 1;
					tickstart_predgretje = HAL_GetTick();
				}

				if(tickstart_predgretje + 90000 < HAL_GetTick()){
					sample_predgretje = 0;
					new_screen = 6;

				}

			if (action == 0) {
				return;
			}

			break;

		case 6: // ZASLON ZA OBVEŠČANJE SPAJKANJA
			update_temperature();
			izhod (PI(temperature, get_current_temperature())); //ob vsakem ciklu zračuna vrednost napake in prilagodi PWM

			static bool sample_spajkanje = 0;
			static int tickstart_spajkanje;

			if(temperature - 5 <= get_current_temperature() && temperature + 5 >= get_current_temperature()){ //začne šteti čas spajkanja ko trenutna temperatura doseže +- 5 stopinj željene temperature
				if(sample_spajkanje == 0){
					sample_spajkanje = 1;
					tickstart_spajkanje = HAL_GetTick();
				}

				if(tickstart_spajkanje + 7000 < HAL_GetTick()){
					sample_spajkanje = 0;
					izhod (0);
					new_screen = 7;

				}
			}

			if (action == 0) {
				return;
			}

			break;

		case 7: // ZASLON ZA OBVEŠČANJE KONČANEGA SPAJKANJA
			update_temperature();
			if (action == 0) {
				return;
			}
			if (action == 3) { // TIPKA OK
				new_screen = 8;
			}

			break;

		case 8: // ZASLON ZA OBVEŠČANJE HLAJENJA
			update_temperature();

			if ((long)get_current_temperature() < 60 ) {
				new_screen = 1;
			}

			if (action == 0) {
				return;
			}


			break;
	}
}
