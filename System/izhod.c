#include "tim.h"

void izhod(int moc_gretja){ // omejitev vrednosti PI napake med 0 in 10000
	if(moc_gretja > 10000){
		moc_gretja = 10000;
	}else if(moc_gretja < 0){
		moc_gretja = 0;
	}
	TIM2 -> CCR1 = moc_gretja; // vpis moči gretja v register za prilagotidev duty cycla
}


