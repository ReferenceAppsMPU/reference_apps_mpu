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
*   This template is responsible to initialize the touch driver of the display
*   hardware and to receive the touch events for the UI application.
*   Important: This file is intended to be used as a template. Please adapt the
*   implementation according your particular hardware.
*
*******************************************************************************/

#include "configuration.h"
#include "definitions.h"
#include "ewrte.h"

#include "ewconfig.h"
#include "ew_bsp_display.h"
#include "ew_bsp_touch.h"

#define NO_OF_FINGERS                  5

/* additional touch flag to indicate idle state */
#define MAX_TOUCH_EVENTS               50

static int  noOfEvents     = 0;

static int  TouchAreaMinX  = 0; /* raw touch value of the leftmost position on the touch screen */
static int  TouchAreaMinY  = 0; /* raw touch value of the topmost position on the touch screen */
static int  TouchAreaMaxX  = 0; /* raw touch value of the rightmost position on the touch screen */
static int  TouchAreaMaxY  = 0; /* raw touch value of the bottommost position on the touch screen */
static int  DisplayWidth   = 0; /* width of the display */
static int  DisplayHeight  = 0; /* height of the display */
static int  IsInitalized   = 0;

static XTouchEvent TouchEvent[MAX_TOUCH_EVENTS]={0};

/*******************************************************************************
* FUNCTION:
*   EwBspTouchInit
*
* DESCRIPTION:
*   Initalizes the touch driver interface. The provided display information is
*   used to configure the touch driver interface so that a proper mapping of
*   touch coordinates to GUI coordinates can be done.
*
* ARGUMENTS:
*   aGuiWidth,
*   aGuiHeight   - Size of the GUI in pixel.
*   aDisplayInfo - Display info data structure.
*
* RETURN VALUE:
*   Returns 1 if successful, 0 otherwise.
*
*******************************************************************************/
int EwBspTouchInit( int aGuiWidth, int aGuiHeight, XDisplayInfo* aDisplayInfo )
{
  EW_UNUSED_ARG( aGuiWidth );
  EW_UNUSED_ARG( aGuiHeight );
  
  /* check display info structure */
  if ( !aDisplayInfo )
  {
    EwPrint( "EwBspTouchInit: Invalid DisplayInfo!\n" );
    return 0;
  }

  /* take physical size of display from provided display info structure */
  DisplayWidth   = aDisplayInfo->DisplayWidth;
  DisplayHeight  = aDisplayInfo->DisplayHeight;
  
  /* take touch calibration values */
  TouchAreaMinX = EW_TOUCH_AREA_MIN_X;
  TouchAreaMinY = EW_TOUCH_AREA_MIN_Y;
  TouchAreaMaxX = EW_TOUCH_AREA_MAX_X;
  TouchAreaMaxY = EW_TOUCH_AREA_MAX_Y;

  /* check touch calibration and configuration to avoid division by zero */
  if (( TouchAreaMaxX == TouchAreaMinX ) || ( TouchAreaMaxY == TouchAreaMinY ))
  {
    EwPrint( "EwBspTouchInit: Invalid touch area!\n" );
    return 0;
  }
  
  IsInitalized = 1;
  
  return 1;
}


/*******************************************************************************
* FUNCTION:
*   EwBspTouchDone
*
* DESCRIPTION:
*   Terminates the touch driver.
*
* ARGUMENTS:
*   None
*
* RETURN VALUE:
*   None
*
*******************************************************************************/
void EwBspTouchDone( void )
{
  IsInitalized = 0;
}


/*******************************************************************************
* FUNCTION:
*   EwBspTouchGetEvents
*
* DESCRIPTION:
*   The function EwBspTouchGetEvents reads the current touch positions from the
*   touch driver and returns the current touch position and touch status of the
*   different fingers. The returned number of touch events indicates the number
*   of XTouchEvent that contain position and status information.
*   The orientation of the touch positions is adjusted to match GUI coordinates.
*   If the hardware supports only single touch, the finger number is always 0.
*
* ARGUMENTS:
*   aTouchEvent - Pointer to return array of XTouchEvent.
*
* RETURN VALUE:
*   Returns the number of detected touch events, otherwise 0.
*
*******************************************************************************/
int EwBspTouchGetEvents( XTouchEvent** aTouchEvent )
{
  uint32_t no_of_events = noOfEvents;

  if ( !IsInitalized )
    return 0;  
  
  noOfEvents = 0;
  
  /* return the prepared touch events and the number of prepared touch events */
  if ( aTouchEvent )
    *aTouchEvent = TouchEvent;
    
  return no_of_events;

}

void EwBspTouchEventHandler(XTouchEvent* aTouchEvent)
{
  int touchX; 
  int touchY; 
  int x; 
  int y; 

  /* apply swapping of raw touch coordinates if required */
  #if ( EW_TOUCH_SWAP_XY )

    touchX = aTouchEvent->YPos;;
    touchY = aTouchEvent->XPos;;

  #else

    touchX = aTouchEvent->XPos;;
    touchY = aTouchEvent->YPos;;

  #endif

  /* convert raw touch coordinates into display coordinates */
  touchX = (( touchX - TouchAreaMinX ) * DisplayWidth ) / ( TouchAreaMaxX - TouchAreaMinX );
  touchY = (( touchY - TouchAreaMinY ) * DisplayHeight ) / ( TouchAreaMaxY - TouchAreaMinY );

  /* check for valid display coordinates */
  if (( touchX < 0 ) || ( touchX > DisplayWidth ) ||
      ( touchY < 0 ) || ( touchY > DisplayHeight ))
    return;  
  
  /* convert display coordinates into GUI coordinates */
  #if ( EW_SURFACE_ROTATION == 90 )

    x = touchY;
    y = DisplayWidth - touchX;

  #elif ( EW_SURFACE_ROTATION == 270 )

    x = DisplayHeight - touchY;
    y = touchX;

  #elif ( EW_SURFACE_ROTATION == 180 )

    x = DisplayWidth - touchX;
    y = DisplayHeight - touchY;

  #else

    x = touchX;
    y = touchY;

  #endif  
  
  if ( noOfEvents < MAX_TOUCH_EVENTS )
  {
    TouchEvent[noOfEvents].XPos   = x;
    TouchEvent[noOfEvents].YPos   = y;
    TouchEvent[noOfEvents].State  = aTouchEvent->State;
    TouchEvent[noOfEvents].Finger  = aTouchEvent->Finger;
    noOfEvents++;
  }
}
/* mli, msy */
