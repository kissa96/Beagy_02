

/*
* Generated StateMachine source code
*/
#include <stdio.h>
#include "StateMachine.h"


/* Definitions imports from model */
uint8_t UserVariable;

/* Built-in variables */
#ifdef _USE_ADC
uint8_t vPotmeter;
#endif
/**
* @brief Trace function send trace log on stdout as default on UART
* Format: $e:<event>,s:<state>
*/	
static void _trace(event_t event, state_t state){
	static event_t e = evNone;
	static state_t s = _init;
	if(event != e || state != s){
        // not send trace log if event just restored to default evNone and no state changes
        if(!(event==evNone && state == s)){
        	printf("$e:%s,s:%s\n", (event == evNone) ? "" : trace_event_labels[event], trace_state_labels[state]);
		}
		s = state;
		e = event;
	}
}

// States
static state_t vStateMachine = _init;


/**
* @brief State Machine
*/	
void StateMachine_SM(event_t event){
				
	switch(vStateMachine){
		case _init:
			vStateMachine = Red;
			LED1_Off();	// initial do action
			LED2_Off();	// initial do action
			LED3_On();	// initial do action
		break;
		case Red:
			// do actions of Red
			LED1_Off();
			LED2_Off();
			LED3_On();

			if(evTick==event){ 
				LED1_Off();	// transition action Red to Yellow
				LED2_On();	// transition action Red to Yellow
				LED3_On();	// transition action Red to Yellow
				UserVariable = 1;	// transition action Red to Yellow
				vStateMachine = Yellow; // set new state
			}
			break;
		case Yellow:
			if((UserVariable == 1) && evTick==event){ 
				vStateMachine = Green; // set new state
			}
			if((UserVariable == 0) && evTick==event){ 
				vStateMachine = Red; // set new state
			}
			break;
		case Green:
			// do actions of Green
			LED1_On();
			LED2_Off();
			LED3_Off();

			if(evTick==event){ 
				LED1_Off();	// transition action Green to Yellow
				LED2_On();	// transition action Green to Yellow
				LED3_Off();	// transition action Green to Yellow
				UserVariable = 0;	// transition action Green to Yellow
				vStateMachine = Yellow; // set new state
			}
			break;
		default:
			break;
	} // end of switch
#ifdef _USE_TRACE
	//Trace
	_trace(event, vStateMachine);
#endif
}
