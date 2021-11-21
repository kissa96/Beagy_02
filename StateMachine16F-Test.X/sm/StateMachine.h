
#ifndef StateMachine_H
#define StateMachine_H

#include <stdint.h>
#include <stdbool.h>
#include "events.h"
#include "actions.h"

/* Definitions imports from model */
#define _USE_TRACE
#define _USE_ADC
//#define _USE_TIMERTICK
/*User defined variables*/
extern uint16_t vUserVaraible;

/* Built-in variables */
#ifdef _USE_ADC
extern uint8_t vPotmeter;
#endif

/* events and states enums */
typedef enum {
	/* predefined */
	_init
	/* states */
	,State1
	,State2
	,State3
	,State4
}state_t;

/* trace state names */
const char* const trace_state_labels [] = {
	/* predefined */
	"_init"
	/* states */
	,"State1"
	,"State2"
	,"State3"
	,"State4"
};


/* functions */

void StateMachine_SM (event_t event);


#endif //StateMachine_H
