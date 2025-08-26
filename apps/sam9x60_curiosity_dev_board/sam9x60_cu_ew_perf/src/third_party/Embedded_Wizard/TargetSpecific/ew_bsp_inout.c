/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software
* components. It is provided as an example software which is intended to be
* modified and extended according to particular requirements.
*
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability
* and non-infringement of any third party IPR or other rights which may result
* from the use or the inability to use the software.
*
********************************************************************************
*
* DESCRIPTION:
*   This file is part of the interface (glue layer) between an Embedded Wizard
*   generated UI application and the board support package (BSP) of a dedicated
*   target.
*   Please note: The implementation of this module is partially based on
*   examples that are provided within the STM32 cube firmware. In case you want
*   to adapt this module to your custom specific hardware, please adapt the
*   hardware initialization code according your needs or integrate the generated
*   initialization code created by using the tool CubeMX.
*   This template provides access to some LEDs and buttons of the board.
*
*******************************************************************************/

#include "ewconfig.h"
#include "ew_bsp_inout.h"
#include "definitions.h"

//static void EwBspInOutUserButtonHandler( PIO_PIN pin, uintptr_t context );
static TButtonCallback ButtonCallback = 0;

/*******************************************************************************
* FUNCTION:
*   EwBspInOutInitButton
*
* DESCRIPTION:
*   Configures one hardware button of the board used for demo applications.
*
* ARGUMENTS:
*   aButtonCallback - The button callback.
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspInOutInitButton( TButtonCallback aButtonCallback )
{
  //PIO_PinInterruptCallbackRegister( PIO_PIN_PC9, EwBspInOutUserButtonHandler, (uintptr_t)NULL);
  //PIO_PinInterruptEnable( PIO_PIN_PC9 );
    
  ButtonCallback = aButtonCallback;
}


/*******************************************************************************
* FUNCTION:
*   EwBspInOutInitLed
*
* DESCRIPTION:
*   Configures one LED of the board used for demo applications.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspInOutInitLed( void )
{
}


/*******************************************************************************
* FUNCTION:
*   EwBspInOutLedOn
*
* DESCRIPTION:
*   Switch LED on (used for demo applications).
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspInOutLedOn( void )
{
  LED_BLUE_On();
}


/*******************************************************************************
* FUNCTION:
*   EwBspInOutLedOff
*
* DESCRIPTION:
*   Switch LED off (used for demo applications).
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspInOutLedOff( void )
{
  LED_BLUE_Off();    
}


/*******************************************************************************
* FUNCTION:
*   EwBspInOutEventHandler
*
* DESCRIPTION:
*   The function EwBspInOutEventHandler is called from the touch screen driver
*   in case of an input event.
*
* ARGUMENTS:
*   aEventId - An optional target specific event ID.
*
* RETURN VALUE:
*   None.
*
*******************************************************************************/
void EwBspInOutEventHandler( int aEventId )
{
}


/*static void EwBspInOutUserButtonHandler( PIO_PIN pin, uintptr_t context )
{
  int isButtonPresssed = 0; 
    
  if( SW1_Get() == 0 )
    isButtonPresssed = 1;
 
  if ( ButtonCallback )
    ButtonCallback( isButtonPresssed );
}  */

/* msy */
