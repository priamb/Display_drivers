#include "screen.h"


int current_screen = 1; // TRENUTEN ZASLON
int new_screen = 0;  // NOV ZASLON
int previous_screen = 0; // PREJŠNJI ZASLON


void menu(void)
{
	if (current_screen != new_screen) {
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
				new_screen = 4;
			}
			if (action == 6) { // TIPKA 190°C
				new_screen = 4;
			}
			if (action == 7) { // TIPKA 200°C
				new_screen = 4;
			}
			if (action == 8) { // TIPKA 210°C
				new_screen = 4;
			}
			if (action == 9) { // TIPKA 220°C
				new_screen = 4;
			}
			if (action == 10) { // TIPKA 230°C
				new_screen = 4;
			}
			break;

		case 3: // ZASLON Z POLJUBNIM NASTAVLJANJEM TEMPERATURE
			if (action == 0) {
				return;
			}
			if (action == 3) { //TIPKA OK
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
			if (action == 0) {
				HAL_Delay(5000);
				new_screen = 6;
			}
			//če je temperatura enaka designatedTemperature me da na zaslon 6
			break;

		case 6: // ZASLON ZA OBVEŠČANJE SPAJKANJA
			if (action == 0) {
				HAL_Delay(5000);
				new_screen = 7;
			}
			//ko temperatura doseže designatedTemperature počakaj 15s nato na zaslon 7
			break;

		case 7: // ZASLON ZA OBVEŠČANJE KONČANEGA SPAJKANJA
			if (action == 0) {
				return;
			}
			if (action == 3) { // TIPKA OK
				new_screen = 8;
			}

			break;

		case 8: // ZASLON ZA OBVEŠČANJE KONČANEGA SPAJKANJA
			if (action == 0) {
				HAL_Delay(5000);
				new_screen = 1;
			}
			//when bed temperature enaka 150°C vrne na zaslon 1

			break;
	}
}
