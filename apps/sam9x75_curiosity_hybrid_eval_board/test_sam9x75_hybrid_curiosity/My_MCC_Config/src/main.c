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


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************





// LED wave pattern using PIT delay
void FlashLedsPattern(void)
{
    for (int cycle = 0; cycle < 10; ++cycle)
    {
        USER_LED1_On(); USER_LED2_On(); USER_LED3_On(); USER_LED4_On();
        USER_LED5_On(); USER_LED6_On(); USER_LED7_On(); USER_LED8_On();
        LED_RED_On(); LED_GREEN_On(); LED_BLUE_On();

        PIT_DelayMs(250); // Delay for 250ms

        USER_LED1_Off(); USER_LED2_Off(); USER_LED3_Off(); USER_LED4_Off();
        USER_LED5_Off(); USER_LED6_Off(); USER_LED7_Off(); USER_LED8_Off();
        LED_RED_Off(); LED_GREEN_Off(); LED_BLUE_Off();

        PIT_DelayMs(250); // Delay for 250ms
    }
}

void FlashLedsOtherPattern(uint32_t pattern)
{
    // Example: alternate LEDs with the pattern bits for cycles
    for (int cycle = 0; cycle < 10; ++cycle)
    {
        if (pattern & 0x01) USER_LED1_On(); else USER_LED1_Off();
        if (pattern & 0x02) USER_LED2_On(); else USER_LED2_Off();
        if (pattern & 0x03) USER_LED3_On(); else USER_LED3_Off();
        if (pattern & 0x04) USER_LED4_On(); else USER_LED4_Off();
        if (pattern & 0x5) USER_LED5_On(); else USER_LED5_Off();
        if (pattern & 0x6) USER_LED6_On(); else USER_LED6_Off();
        if (pattern & 0x7) USER_LED7_On(); else USER_LED7_Off();
        if (pattern & 0x8) USER_LED8_On(); else USER_LED8_Off();
         PIT_DelayMs(250);
    

        // Off all LEDs after each cycle
        USER_LED1_Off(); USER_LED2_Off(); USER_LED3_Off(); USER_LED4_Off();
        USER_LED5_Off(); USER_LED6_Off(); USER_LED7_Off(); USER_LED8_Off();

         PIT_DelayMs(250);
    }
}



int main(void)
{
    SYS_Initialize(NULL);

    // Initialize PIT timer period for delays (default 250ms)
    PIT_TimerPeriodSet(250); // Set period in ms, adapt for your API
    printf("\r\nEnter pattern (0: wave, 1-8 for other patterns):\n");

    while (true)
    {
        SYS_Tasks();
        unsigned int  userInput=0;

        scanf(" %d", &userInput);
        if (userInput == 0)
        {
          printf("\r\n Flashing wave pattern...\n");
          FlashLedsPattern();
        }
        else
        {
          printf("\r\n Flashing alt pattern...\n");
          FlashLedsOtherPattern(userInput);
        }
        printf("\r\n Pattern done. Enter next pattern:\n");
    }
    return EXIT_FAILURE;
}

/*******************************************************************************
 End of File
*/

