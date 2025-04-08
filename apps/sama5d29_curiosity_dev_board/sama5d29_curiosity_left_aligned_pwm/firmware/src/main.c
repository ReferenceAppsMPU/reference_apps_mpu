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

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes

/***************************************
 * Check PWM outputs on pins(pad)
 * Channel 2 PWMH - B7(PB5)
***************************************/

/* Duty cycle increment value */
#define DUTY_INCREMENT (10U)

/* Save PWM period */
static uint16_t period;

static uint16_t g_user_Input = 0U; // Holds the menu selected by user



// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    
    printf("Application Start\r\n");
    
    /* Read the period */
    period = PWM_ChannelPeriodGet(PWM_CHANNEL_1);

    /* Start all synchronous channels by starting channel 1*/
    PWM_ChannelsStart(PWM_CHANNEL_1_MASK);
    
    //PWM_ChannelsStart(PWM_CHANNEL_1_MASK);
    uint8_t user_dutycycle_input = 0U; 
    uint8_t user_deadtime_input = 0U;
            
    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        printf("\r\nDuty-cycle (Range - 1%% to 100%%): ");

        /* Read user input */
        if (scanf("%hhd", &user_dutycycle_input) != 1) {
            printf("Error reading duty cycle input.\n");
            while (getchar() != '\n');
            continue;
        }

                
        printf("\r\nDead-Time (Range - 0 to %d): ", period);

        /* Read user input */
        if (scanf("%hhd", &user_deadtime_input) != 1) {
            printf("Error reading dead-time input.\n");
            while (getchar() != '\n');
            continue;
        }
           
       
        if(user_dutycycle_input != g_user_Input)
        {
            g_user_Input = (uint16_t) ((float)period * ((float)user_dutycycle_input/100.00));
                  
            /* PWM duty cycle */
            PWM_ChannelDutySet(PWM_CHANNEL_1, g_user_Input);
            
            /* Dead time */
            PWM_ChannelDeadTimeSet(PWM_CHANNEL_1,user_deadtime_input, user_deadtime_input);
            
                      
            printf("\r\nDuty cycle count is %d", (uint16_t) PWM_REGS->PWM_CH_NUM[1].PWM_CDTY);
            
            printf("\r\n-------------------------------------------------------");
            
        }   
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/
