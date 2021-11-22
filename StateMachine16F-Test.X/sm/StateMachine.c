

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
static state_t vStateMachine_Working_ShallowHistoryPseudostate2;


/**
* @brief State Machine
*/	
void StateMachine_SM(event_t event){
				
	switch(vStateMachine){
		case _init:
			vStateMachine = Working;
		break;
		//ShallowHistoryPseudostate
		case Working_ShallowHistoryPseudostate2:
			vStateMachine = vStateMachine_Working_ShallowHistoryPseudostate2;
			break;
		case Working:
			// has substates
			vStateMachine = Red;
			if(evS2Pressed==event){ 
				vStateMachine = Service; // set new state
			}
			break;
		case Service:
			// has substates
			vStateMachine = YellowOn;
			if(evS2Pressed==event){ 
				vStateMachine = Working_ShallowHistoryPseudostate2; // set new state
			}
			break;
		case Red:
			// do actions of Red
			LED1_Off();
			LED2_Off();
			LED3_On();

			// Container
			if(evS2Pressed==event){
				vStateMachine = Service;


				// save state into ShallowHistoryPseudostate
				vStateMachine_Working_ShallowHistoryPseudostate2 = Red;
			}
			if((vPotmeter<50) && evTick==event){ 
				vStateMachine = PotDelay; // set new state
			}
			if((vPotmeter >= 50) && evTick==event){ 
				vStateMachine = RedYellow; // set new state
			}
			break;
		case PotDelay:
			// Container
			if(evS2Pressed==event){
				vStateMachine = Service;


				// save state into ShallowHistoryPseudostate
				vStateMachine_Working_ShallowHistoryPseudostate2 = PotDelay;
			}
			if(evS1Pressed==event){ 
				vStateMachine = RedYellow; // set new state
			}
			break;
		case RedYellow:
			// do actions of RedYellow
			LED1_Off();
			LED2_On();
			LED3_On();

			// Container
			if(evS2Pressed==event){
				vStateMachine = Service;


				// save state into ShallowHistoryPseudostate
				vStateMachine_Working_ShallowHistoryPseudostate2 = RedYellow;
			}
			if(evTick==event){ 
				vStateMachine = Green; // set new state
			}
			break;
		case Green:
			// do actions of Green
			LED1_On();
			LED2_Off();
			LED3_Off();

			// Container
			if(evS2Pressed==event){
				vStateMachine = Service;


				// save state into ShallowHistoryPseudostate
				vStateMachine_Working_ShallowHistoryPseudostate2 = Green;
			}
			if(evTick==event){ 
				vStateMachine = Yellow; // set new state
			}
			break;
		case Yellow:
			// do actions of Yellow
			LED1_Off();
			LED2_On();
			LED3_Off();

			// Container
			if(evS2Pressed==event){
				vStateMachine = Service;


				// save state into ShallowHistoryPseudostate
				vStateMachine_Working_ShallowHistoryPseudostate2 = Yellow;
			}
			if(evTick==event){ 
				vStateMachine = Red; // set new state
			}
			break;
		case YellowOn:
			// do actions of YellowOn
			LED1_Off();
			LED2_On();
			LED3_Off();

			// Container
			if(evS2Pressed==event){

				vStateMachine = Working_ShallowHistoryPseudostate2;

			}
			if(evTick==event){ 
				vStateMachine = Dummy1; // set new state
			}
			break;
		case Dummy1:
			// Container
			if(evS2Pressed==event){

				vStateMachine = Working_ShallowHistoryPseudostate2;

			}
			if(evTick==event){ 
				vStateMachine = YellowOff; // set new state
			}
			break;
		case YellowOff:
			// do actions of YellowOff
			LED1_Off();
			LED2_Off();
			LED3_Off();

			// Container
			if(evS2Pressed==event){

				vStateMachine = Working_ShallowHistoryPseudostate2;

			}
			if(evTick==event){ 
				vStateMachine = Dummy2; // set new state
			}
			break;
		case Dummy2:
			// Container
			if(evS2Pressed==event){

				vStateMachine = Working_ShallowHistoryPseudostate2;

			}
			if(evTick==event){ 
				vStateMachine = YellowOn; // set new state
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
