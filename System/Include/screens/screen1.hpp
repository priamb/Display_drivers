#pragma once
#include "gui/widget.hpp"
#include "gui/button.hpp"

class Screen1: Widget{
    public: 
    Button* btns[4];
    Screen1(){
        const char* text = &"Button 1"[0];
        this->btns[0] = new Button(10, 10, 100, 50, text);
        text = &"Button 2"[0];
        this->btns[1] = new Button(10, 60, 100, 50, text);
        text = &"Button 3"[0];
        this->btns[2] = new Button(10, 120, 100, 50, text);
        text = &"Button 4"[0];
        this->btns[3] = new Button(10, 180, 100, 50, text);
    }
    
    void show(){
        for (int i = 0; i < 4; i++){
            this->btns[i]->show();
        }
    }
};
