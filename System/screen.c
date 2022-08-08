
#include "screens/screen.h"
#include "text.h"
#include "button.h"
#include "slider.h"

bool pressed = false;
short x = 0, y = 0;

int checkPressed(int id)
{
    bool screenTouched = XPT2046_touch_get_coordinates_if_pressed(&x, &y);
    if (screenTouched && !pressed)
    {
        pressed = true;
    }

    if (!screenTouched && pressed)
    {
        pressed = false;
        UG_FillCircle(x, y, 5, C_RED);
        checkAllSliders(id, x, y);
        return checkAllButtonsPressed(id, x, y);
    }

    if (pressed)
    {
        // in na to mesto pritiska narišemo krogec s pomočjo uGUI funkcij.
        //UG_FillCircle(x, y, 2, C_GREEN);

        // Izpišemo lokacijo še preko SCI vmesnika.
        //printf("x = %d\n", x);
        //printf("y = %d\n", y);
        pressed = true;
    }
    HAL_Delay(30);
    return false;
	}

int checkSlider(slider_t slider, int x, int y){
    float new_val = checkIfValueChanged(slider, x, y);

    if (new_val >= 0.0){
            slider.value = new_val;
            char str[80];
            snprintf(str, 80, "%d\n", (int)slider.value);
            SCI_send_string(str);
            showSlider(slider);
            return 1;
    }

    return 0;
}

int checkAllSliders(int id, int x, int y) {
	switch (id) {
		case 3:
			checkSlider(slider, x, y);
			return 1;
			break;

		default:
			return 0;
			break;
	}
}


int checkButtonPressed(button_t button, int x, int y)
{
	return (button.x <= x && x <= button.x + button.w && button.y <= y && y <= button.y + button.h);
}

int checkAllButtonsPressed(int id, int x, int y)
{
    switch (id) {
    	case 0:
    		break;

    	case 1:
    	    if (checkButtonPressed(button_SHRANJENE_MERE, x, y)) {
    	    	return button_SHRANJENE_MERE.action;
    	    }
    	    if (checkButtonPressed(button_PO_MERI, x, y)) {
    	    	return button_PO_MERI.action;
    	    }

    	    return 0;

    	   	break;

    	case 2:
    		if (checkButtonPressed(button_180, x, y)) {
    			return button_180.action;
    		    	    }
    		if (checkButtonPressed(button_190, x, y)) {
    			return button_190.action;
    		}
    		if (checkButtonPressed(button_200, x, y)) {
    			return button_200.action;
    		}
    		if (checkButtonPressed(button_210, x, y)) {
    			return button_210.action;
    		}
    		if (checkButtonPressed(button_220, x, y)) {
    			return button_220.action;
    		}
    		if (checkButtonPressed(button_230, x, y)) {
    			return button_230.action;
    		}

    		return 0;

    		break;

    	case 3:
    	    if (checkButtonPressed(button_BACK, x, y)) {
    	    	return button_BACK.action;
    	    }
    	    if (checkButtonPressed(button_OK, x, y)) {
    	    	return button_OK.action;
    	    }
    	    return 0;

    	   	break;

    	case 4:
    	    if (checkButtonPressed(button_BACK, x, y)) {
    	    	return button_BACK.action;
    	    }
    	    if (checkButtonPressed(button_OK, x, y)) {
    	    	return button_OK.action;
    	    }

    	    return 0;

    	   	break;

    	case 5:
    		break;

    	case 6:
    		break;

    	case 7:
    	    if (checkButtonPressed(button_OK, x, y)) {
    	    	return button_OK.action;
    	    }
    	    return 0;

    	   	break;

    	case 8:
    		break;

    }

    return 0;
}

void drawScreen(int id)
{
	LCD_ClearScreen();

    switch (id)
    {

    case 0:
        showText(text_IME_PROJEKTA);
        showText(text_IME_AVTORJA);
        showText(text_PROJEKT);
        break;

    case 1:
    	showButton(button_SHRANJENE_MERE);
    	showButton(button_PO_MERI);
        break;

    case 2:
    	showButton(button_180);
    	showButton(button_190);
    	showButton(button_200);
    	showButton(button_210);
    	showButton(button_220);
    	showButton(button_230);
        break;

    case 3:
    	showText(text_NAVODILA6);
    	showButton(button_BACK);
    	showButton(button_OK);
    	//showDesignatedTemperature
    	showSlider(slider);
        break;

    case 4:
    	showButton(button_BACK);
    	showButton(button_OK);
    	showText(text_NAVODILA1);
        break;

    case 5:
    	//showTemperature
    	showText(text_NAVODILA2);
        break;

    case 6:
    	//showTemperature
    	showText(text_NAVODILA3);
        break;

    case 7:
    	showText(text_NAVODILA4);
    	showButton(button_OK);
        break;

    case 8:
    	//showTemperature
    	showText(text_NAVODILA5);
        break;

    }
}
