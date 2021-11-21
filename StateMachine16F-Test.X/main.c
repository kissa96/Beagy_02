/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F18857
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include "mcc_generated_files/mcc.h"
#include "sm/StateMachine.h"
/*
                         Main application
 */

#define _BUTTONSAFETOUT_MS     150

// event variable
event_t Event = evNone;
// millisecond based timer variable
static uint32_t Timer = 0;
// timeout variable

// Timer0 interrupt callback
// Timer0 set to 100ms interval
void timerCallback()
{
    Timer++;
    
#ifdef _USE_TIMERTICK
    static uint32_t sec = 0;
    if(Timer-sec > 1000){
        sec = Timer;
        Event = evTick;
    }
#endif
    // user defined events..
}

// S1 button IOC interrupt callback
void S1EventCallback()
{
    static uint32_t t = 0;    
    if(Timer - t > _BUTTONSAFETOUT_MS)
    {
        t = Timer;
        Event = evS1Pressed;
    }           
}
// S2 button IOC interrupt callback
void S2EventCallback(){    
    // Create evS2Pressed event based on evS1Pressed...
}

// Read potentiometer percentage
uint8_t getPotValue()
{
    return ((uint32_t)(ADCC_GetSingleConversion(1) + 1)*100)>>10;
}

// User defined events
/*
void eventTemplate_ISRCallback()
{
    event = evUserTrigger;
}
*/


void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // set interrupt callbacks
    TMR0_SetInterruptHandler(timerCallback);    
    IOCAF7_SetInterruptHandler(S1EventCallback);
    IOCAF6_SetInterruptHandler(S2EventCallback);

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

#ifdef _USE_TRACE    
    // clear stdout
    puts("$");
    // init trace
    puts("$init");
#endif
    // temporary event variable
    event_t e = evNone;
    while (1)
    {
#ifdef _USE_ADC
        // get ADC value channel 1
        vPotmeter = getPotValue();
#endif        
        // get global event 
        e = Event;
        Event = evNone;
        StateMachine_SM(e);
        e = evNone;
    }
}
/**
 End of File
*/