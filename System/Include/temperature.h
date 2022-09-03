
#ifndef INCLUDE_TEMPERATURE_H_
#define INCLUDE_TEMPERATURE_H_

#define _GNU_SOURCE

#include "main.h"
#include "timing_utils.h"
#include "SCI.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

#define SS_PORT GPIOF
#define SS_PIN  GPIO_PIN_9

void get_temperature(void);
void update_temperature(void);
float get_current_temperature(void);

#endif /* INCLUDE_TEMPERATURE_H_ */
