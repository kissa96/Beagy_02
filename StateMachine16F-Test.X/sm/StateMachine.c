

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
			vStateMachine = State1;
			LED1_Off();	// initial entry action
			LED2_Off();	// initial entry action
			LED3_On();	// initial entry action
		break;
		case State1:
			if(evTick==event){ 
				vStateMachine = Pseudo; // set new state
			}
			break;
		case State2:
			if(evTick==event){ 
				vStateMachine = State3; // set new state
				LED1_On();	// entry action of State3
				LED2_Off();	// entry action of State3
				LED3_Off();	// entry action of State3
			}
			break;
		case State3:
			if(evTick==event){ 
				vStateMachine = State4; // set new state
				LED1_Off();	// entry action of State4
				LED2_On();	// entry action of State4
				LED3_Off();	// entry action of State4
			}
			break;
		case State4:
			if(evTick==event){ 
				vStateMachine = State1; // set new state
				LED1_Off();	// entry action of State1
				LED2_Off();	// entry action of State1
				LED3_On();	// entry action of State1
			}
			break;
		case StatePot:
			if(evS1Pressed==event){ 
				vStateMachine = State2; // set new state
				LED1_Off();	// entry action of State2
				LED2_On();	// entry action of State2
				LED3_On();	// entry action of State2
			}
			break;
		case Pseudo:
			if((vPotmeter>=50) && true){ 
				vStateMachine = State2; // set new state
				LED1_Off();	// entry action of State2
				LED2_On();	// entry action of State2
				LED3_On();	// entry action of State2
			}
			if((vPotmeter<50) && true){ 
				vStateMachine = StatePot; // set new state
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
