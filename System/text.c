#include "gui/text.h"

void showText(struct Text text){
    UG_SetForecolor(text.foreground);
    UG_SetBackcolor(text.background);
    UG_PutString(10, 10, text.text);
}