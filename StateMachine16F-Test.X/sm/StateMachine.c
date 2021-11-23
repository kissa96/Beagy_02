

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
    asm("nop");
	switch(vStateMachine){
		case _init:
			vStateMachine = State0;
		break;
		case Red:
			// do actions of Red
			LED1_Off();
			LED2_Off();
			LED3_On();

			if((vPotmeter >= 50) && evTimeout==event){ 
				vStateMachine = RedYellow; // set new state
			}
			if((vPotmeter<50) && evTimeout==event){ 
				vStateMachine = PotDelay; // set new state
			}
			break;
		case Yellow:
			// do actions of Yellow
			LED1_Off();
			LED2_On();
			LED3_Off();

			if(evTimeout==event){ 
				setTimeout(8000);	// transition action Yellow to Red
				vStateMachine = Red; // set new state
			}
			break;
		case PotDelay:
			if(evS1Pressed==event){ 
				setTimeout(1000);	// transition action PotDelay to RedYellow
				vStateMachine = RedYellow; // set new state
			}
			break;
		case Green:
			// do actions of Green
			LED1_On();
			LED2_Off();
			LED3_Off();

			if(evTimeout==event){ 
				setTimeout(1000);	// transition action Green to Yellow
				vStateMachine = Yellow; // set new state
			}
			break;
		case RedYellow:
			// do actions of RedYellow
			LED1_Off();
			LED2_On();
			LED3_On();

			if(evTimeout==event){ 
				setTimeout(5000);	// transition action RedYellow to Green
				vStateMachine = Green; // set new state
			}
			break;
		case State0:
                asm("nop");
				setTimeout(8000);	// transition action State0 to Red
				vStateMachine = Red; // set new state
			break;
		default:
			break;
	} // end of switch
#ifdef _USE_TRACE
	//Trace
	_trace(event, vStateMachine);
#endif
}
