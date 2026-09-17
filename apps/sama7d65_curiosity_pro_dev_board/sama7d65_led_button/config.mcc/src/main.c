/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

#define SWITCH_PRESSED_STATE            0   // Active LOW switch
#define LED_On()                        LED_GREEN_On()
#define LED_Off()                       LED_GREEN_Off()

void controlLED(PIO_PIN pin, uintptr_t context)
{
    if(USER_BUTTON_Get() == SWITCH_PRESSED_STATE)
    {
        /* Turn ON LED */ 
        LED_On();
    }
    else
    {
        /* Turn OFF LED */
        LED_Off();
    }
}
// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    PIO_PinInterruptCallbackRegister(PIO_PIN_PC10,controlLED,NULL);
    PIO_PortInterruptEnable(PIO_PORT_C,0x400);
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

