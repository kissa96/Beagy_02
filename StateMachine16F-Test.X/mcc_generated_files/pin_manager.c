/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC16F18857
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB             :  MPLAB X 5.30

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "pin_manager.h"




void (*IOCAF6_InterruptHandler)(void);
void (*IOCAF7_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISA = 0xFF;
    TRISB = 0xFF;
    TRISC = 0x0E;

    /**
    ANSELx registers
    */
    ANSELC = 0xFD;
    ANSELB = 0xFF;
    ANSELA = 0x3F;

    /**
    WPUx registers
    */
    WPUE = 0x00;
    WPUB = 0x00;
    WPUA = 0x00;
    WPUC = 0x00;

    /**
    ODx registers
    */
    ODCONA = 0x00;
    ODCONB = 0x00;
    ODCONC = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLE = 0x00;


    /**
    IOCx registers 
    */
    //interrupt on change for group IOCAF - flag
    IOCAFbits.IOCAF6 = 0;
    //interrupt on change for group IOCAF - flag
    IOCAFbits.IOCAF7 = 0;
    //interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN6 = 1;
    //interrupt on change for group IOCAN - negative
    IOCANbits.IOCAN7 = 1;
    //interrupt on change for group IOCAP - positive
    IOCAPbits.IOCAP6 = 0;
    //interrupt on change for group IOCAP - positive
    IOCAPbits.IOCAP7 = 0;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCAF6_SetInterruptHandler(IOCAF6_DefaultInterruptHandler);
    IOCAF7_SetInterruptHandler(IOCAF7_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    PIE0bits.IOCIE = 1; 
    
	
    RC0PPS = 0x10;   //RC0->EUSART:TX;    
    RXPPS = 0x11;   //RC1->EUSART:RX;    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCAF6
    if(IOCAFbits.IOCAF6 == 1)
    {
        IOCAF6_ISR();  
    }	
	// interrupt on change for pin IOCAF7
    if(IOCAFbits.IOCAF7 == 1)
    {
        IOCAF7_ISR();  
    }	
}

/**
   IOCAF6 Interrupt Service Routine
*/
void IOCAF6_ISR(void) {

    // Add custom IOCAF6 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF6_InterruptHandler)
    {
        IOCAF6_InterruptHandler();
    }
    IOCAFbits.IOCAF6 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF6 at application runtime
*/
void IOCAF6_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCAF6_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF6
*/
void IOCAF6_DefaultInterruptHandler(void){
    // add your IOCAF6 interrupt custom code
    // or set custom function using IOCAF6_SetInterruptHandler()
}

/**
   IOCAF7 Interrupt Service Routine
*/
void IOCAF7_ISR(void) {

    // Add custom IOCAF7 code

    // Call the interrupt handler for the callback registered at runtime
    if(IOCAF7_InterruptHandler)
    {
        IOCAF7_InterruptHandler();
    }
    IOCAFbits.IOCAF7 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF7 at application runtime
*/
void IOCAF7_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCAF7_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF7
*/
void IOCAF7_DefaultInterruptHandler(void){
    // add your IOCAF7 interrupt custom code
    // or set custom function using IOCAF7_SetInterruptHandler()
}

/**
 End of File
*/