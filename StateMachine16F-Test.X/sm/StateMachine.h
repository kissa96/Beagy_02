
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
	,Working
	/* history pseudostate */
	,Working_ShallowHistoryPseudostate2
	,Service
	,Red
	,PotDelay
	,RedYellow
	,Green
	,Yellow
	,YellowOn
	,Dummy1
	,YellowOff
	,Dummy2
}state_t;

/* trace state names */
const char* const trace_state_labels [] = {
	/* predefined */
	"_init"
	/* states */
	,"Working"
	/* history pseudostate */
	,"Working_ShallowHistoryPseudostate2"
	,"Service"
	,"Red"
	,"PotDelay"
	,"RedYellow"
	,"Green"
	,"Yellow"
	,"YellowOn"
	,"Dummy1"
	,"YellowOff"
	,"Dummy2"
};


/* functions */

void StateMachine_SM (event_t event);


#endif //StateMachine_H
