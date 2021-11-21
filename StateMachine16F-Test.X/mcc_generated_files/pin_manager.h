/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.80.0
        Device            :  PIC16F18857
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set POT aliases
#define POT_TRIS                 TRISAbits.TRISA1
#define POT_LAT                  LATAbits.LATA1
#define POT_PORT                 PORTAbits.RA1
#define POT_WPU                  WPUAbits.WPUA1
#define POT_OD                   ODCONAbits.ODCA1
#define POT_ANS                  ANSELAbits.ANSA1
#define POT_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define POT_GetValue()           PORTAbits.RA1
#define POT_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define POT_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define POT_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define POT_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define POT_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define POT_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set S2 aliases
#define S2_TRIS                 TRISAbits.TRISA6
#define S2_LAT                  LATAbits.LATA6
#define S2_PORT                 PORTAbits.RA6
#define S2_WPU                  WPUAbits.WPUA6
#define S2_OD                   ODCONAbits.ODCA6
#define S2_ANS                  ANSELAbits.ANSA6
#define S2_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define S2_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define S2_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define S2_GetValue()           PORTAbits.RA6
#define S2_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define S2_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define S2_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define S2_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define S2_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define S2_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define S2_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define S2_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set S1 aliases
#define S1_TRIS                 TRISAbits.TRISA7
#define S1_LAT                  LATAbits.LATA7
#define S1_PORT                 PORTAbits.RA7
#define S1_WPU                  WPUAbits.WPUA7
#define S1_OD                   ODCONAbits.ODCA7
#define S1_ANS                  ANSELAbits.ANSA7
#define S1_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define S1_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define S1_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define S1_GetValue()           PORTAbits.RA7
#define S1_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define S1_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define S1_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define S1_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define S1_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define S1_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define S1_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define S1_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISCbits.TRISC4
#define LED1_LAT                  LATCbits.LATC4
#define LED1_PORT                 PORTCbits.RC4
#define LED1_WPU                  WPUCbits.WPUC4
#define LED1_OD                   ODCONCbits.ODCC4
#define LED1_ANS                  ANSELCbits.ANSC4
#define LED1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define LED1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define LED1_GetValue()           PORTCbits.RC4
#define LED1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define LED1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define LED1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define LED1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define LED1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define LED1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISCbits.TRISC5
#define LED2_LAT                  LATCbits.LATC5
#define LED2_PORT                 PORTCbits.RC5
#define LED2_WPU                  WPUCbits.WPUC5
#define LED2_OD                   ODCONCbits.ODCC5
#define LED2_ANS                  ANSELCbits.ANSC5
#define LED2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED2_GetValue()           PORTCbits.RC5
#define LED2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LED2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LED2_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISCbits.TRISC6
#define LED3_LAT                  LATCbits.LATC6
#define LED3_PORT                 PORTCbits.RC6
#define LED3_WPU                  WPUCbits.WPUC6
#define LED3_OD                   ODCONCbits.ODCC6
#define LED3_ANS                  ANSELCbits.ANSC6
#define LED3_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define LED3_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define LED3_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define LED3_GetValue()           PORTCbits.RC6
#define LED3_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define LED3_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define LED3_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define LED3_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define LED3_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define LED3_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISCbits.TRISC7
#define LED4_LAT                  LATCbits.LATC7
#define LED4_PORT                 PORTCbits.RC7
#define LED4_WPU                  WPUCbits.WPUC7
#define LED4_OD                   ODCONCbits.ODCC7
#define LED4_ANS                  ANSELCbits.ANSC7
#define LED4_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED4_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED4_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED4_GetValue()           PORTCbits.RC7
#define LED4_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED4_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED4_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED4_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LED4_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LED4_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF6 pin functionality
 * @Example
    IOCAF6_ISR();
 */
void IOCAF6_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF6 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF6 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF6_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF6_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF6 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF6_SetInterruptHandler() method.
    This handler is called every time the IOCAF6 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF6_SetInterruptHandler(IOCAF6_InterruptHandler);

*/
extern void (*IOCAF6_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF6 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF6_SetInterruptHandler() method.
    This handler is called every time the IOCAF6 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF6_SetInterruptHandler(IOCAF6_DefaultInterruptHandler);

*/
void IOCAF6_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF7 pin functionality
 * @Example
    IOCAF7_ISR();
 */
void IOCAF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF7_SetInterruptHandler() method.
    This handler is called every time the IOCAF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF7_SetInterruptHandler(IOCAF7_InterruptHandler);

*/
extern void (*IOCAF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF7_SetInterruptHandler() method.
    This handler is called every time the IOCAF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF7_SetInterruptHandler(IOCAF7_DefaultInterruptHandler);

*/
void IOCAF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/