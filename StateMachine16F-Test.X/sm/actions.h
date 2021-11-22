#ifndef _ACTIONS_H_
#define _ACTIONS_H_

#include "events.h"

extern event_t Event;

void triggerEvent(event_t event);

void LED1_On();
void LED1_Off();

void LED2_On();
void LED2_Off();

void LED3_On();
void LED3_Off();

void LED4_On();
void LED4_Off();

/* User defined functions*/
void setTimeout(uint32_t val);

#endif /* _ACTIONS_H_ */