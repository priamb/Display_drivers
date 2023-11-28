/*
 * periodic_services.c
 *
 *  Created on: Apr 11, 2022
 *      Author: uporabnik
 */




// ----------- Include other modules (for private) -------------

#include "periodic_services.h"
#include "stm32g4xx_ll_tim.h"
#include "LED.h"
#include "kbd.h"
#include "temperature.h"




// ---------------------- Private definitions ------------------

typedef struct
{

    TIM_TypeDef*   TIMx;

} periodic_services_handle_t;




// In sedaj na podlagi zgoraj definiranega tipa definiramo še globalno strukturno spremenljivko "TIM".

periodic_services_handle_t periodic_services;




void PSERV_init(void)
{
    periodic_services.TIMx = TIM6;

    LL_TIM_EnableCounter(periodic_services.TIMx);
}



void PSERV_enable(void)
{
    //LL_TIM_EnableUpdateEvent(periodic_services.TIMx);
    LL_TIM_EnableIT_UPDATE(periodic_services.TIMx);
}



void PSERV_disable(void)
{
    //LL_TIM_DisableUpdateEvent(periodic_services.TIMx);
    LL_TIM_DisableIT_UPDATE(periodic_services.TIMx);
}



void PSERV_run_services_Callback(void)
{
	get_temperature();
}
