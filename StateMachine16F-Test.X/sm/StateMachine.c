

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
// history
static state_t vStateMachine_Working_ShallowHistoryPseudostate1;


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
            UserVariable = 8;
		break;
		//ShallowHistoryPseudostate
		case Working_ShallowHistoryPseudostate1:
			vStateMachine = vStateMachine_Working_ShallowHistoryPseudostate1;
			break;
		case Working:
			if(evTick==event){ 
				vStateMachine = Working_ShallowHistoryPseudostate1; // set new state
			}
			break;
		case Red:
			// do actions of Red
			LED1_Off();
			LED2_Off();
			LED3_On();

			// Container
			if(evTick==event){

				vStateMachine = Working_ShallowHistoryPseudostate1;

				// save state into ShallowHistoryPseudostate
				vStateMachine_Working_ShallowHistoryPseudostate1 = Red;
			}
			if((vPotmeter >= 50) && evTimeout==event){ 
				UserVariable = 1;	// transition action Red to RedYellow
				vStateMachine = RedYellow; // set new state
			}
			if((vPotmeter<50) && evTimeout==event){ 
				vStateMachine = PotDelay; // set new state
			}
			break;
		case PotDelay:
			// Container
			if(evTick==event){

				vStateMachine = Working_ShallowHistoryPseudostate1;

				// save state into ShallowHistoryPseudostate
				vStateMachine_Working_ShallowHistoryPseudostate1 = PotDelay;
			}
			if(evS1Pressed==event){ 
				UserVariable = 1;	// transition action PotDelay to RedYellow
				vStateMachine = RedYellow; // set new state
			}
			break;
		case RedYellow:
			// do actions of RedYellow
			LED1_Off();
			LED2_On();
			LED3_On();

			// Container
			if(evTick==event){

				vStateMachine = Working_ShallowHistoryPseudostate1;

				// save state into ShallowHistoryPseudostate
				vStateMachine_Working_ShallowHistoryPseudostate1 = RedYellow;
			}
			if(evTimeout==event){ 
				UserVariable = 5;	// transition action RedYellow to Green
				vStateMachine = Green; // set new state
			}
			break;
		case Green:
			// do actions of Green
			LED1_On();
			LED2_Off();
			LED3_Off();

			// Container
			if(evTick==event){

				vStateMachine = Working_ShallowHistoryPseudostate1;

				// save state into ShallowHistoryPseudostate
				vStateMachine_Working_ShallowHistoryPseudostate1 = Green;
			}
			if(evTimeout==event){ 
				UserVariable = 1;	// transition action Green to Yellow
				vStateMachine = Yellow; // set new state
			}
			break;
		case Yellow:
			// do actions of Yellow
			LED1_Off();
			LED2_On();
			LED3_Off();

			// Container
			if(evTick==event){

				vStateMachine = Working_ShallowHistoryPseudostate1;

				// save state into ShallowHistoryPseudostate
				vStateMachine_Working_ShallowHistoryPseudostate1 = Yellow;
			}
			if(evTimeout==event){ 
				UserVariable = 8;	// transition action Yellow to Red
				vStateMachine = Red; // set new state
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
