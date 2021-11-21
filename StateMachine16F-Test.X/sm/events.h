#ifndef _EVENTS_H_
#define _EVENTS_H_

typedef enum {
//predefined events
	evNone 
	,evTick 
	,evS1Pressed 
	,evS2Pressed 
	,evTimeout 
//user defined events
}event_t;

const char* const trace_event_labels [] = {
//predefined events
	"evNone" 
	,"evTick" 
	,"evS1Pressed" 
	,"evS2Pressed" 
	,"evTimeout" 
//user defined events
};


#endif /* _EVENTS_H_ */
