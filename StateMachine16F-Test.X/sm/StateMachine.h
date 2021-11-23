
#ifndef StateMachine_H
#define StateMachine_H

#include <stdint.h>
#include <stdbool.h>
#include "events.h"
#include "actions.h"

/* Definitions imports from model */
#define _USE_TRACE
#define _USE_ADC
#define _USE_TIMERTICK
/*User defined variables*/
extern uint8_t UserVariable;

/* Built-in variables */
#ifdef _USE_ADC
extern uint8_t vPotmeter;
#endif

/* events and states enums */
typedef enum {
	/* predefined */
	_init
	/* states */
	,Red
	,Yellow
	,PotDelay
	,Green
	,RedYellow
	,State0
}state_t;

/* trace state names */
const char* const trace_state_labels [] = {
	/* predefined */
	"_init"
	/* states */
	,"Red"
	,"Yellow"
	,"PotDelay"
	,"Green"
	,"RedYellow"
	,"State0"
};


/* functions */

void StateMachine_SM (event_t event);


#endif //StateMachine_H
