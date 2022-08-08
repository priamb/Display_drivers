#include <stdio.h>
#include "slider.h"
#include "SCI.h"

slider_t slider;

void sliderInit(void){
	slider.x = 7;
	slider.y = 70;
	slider.w = 300;
	slider.h = 40;
	slider.value = 0.0;
	slider.max = 250.0;
}

void showSlider(slider_t slider){
    LCD_FillRect(slider.x, slider.y, slider.w, slider.h, 0xFFFF);
    LCD_FillRect(slider.x+1, slider.y+2, (uint32_t)((float)slider.w*(slider.value/slider.max))-2, slider.h-4, 0x0000);
    UG_SetForecolor(0xFFFF);
    UG_SetBackcolor(0x0000);
    char str[80];
    snprintf(str, 80, "%d", (int)slider.value);
    UG_PutString(155, 90, str);
}

float checkIfValueChanged(slider_t slider, int x, int y){
    if (x >= slider.x && x <= slider.x+slider.w && y >= slider.y && y <= slider.y+slider.h){
        // get the inner coordinates of the slider
        int innerX = x - slider.x;
        // get the percentage of the slider
        float percentage = (float)innerX / (float)slider.w;
        // get the value of the slider
        int value = (int)(percentage * slider.max);
        // return the value of the slider
        char str[80];
        snprintf(str, 80, "%d - ", (int)value);
        SCI_send_string(str);
        return value;
    }
    return -1.0;
}



