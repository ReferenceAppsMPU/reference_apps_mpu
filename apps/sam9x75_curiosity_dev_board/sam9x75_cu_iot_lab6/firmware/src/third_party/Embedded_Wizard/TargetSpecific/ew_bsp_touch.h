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

#ifndef EW_BSP_TOUCH_H
#define EW_BSP_TOUCH_H


#ifdef __cplusplus
  extern "C"
  {
#endif


/* flag to indicate begin of a touch cycle for a certain finger (event down) */
#define EW_BSP_TOUCH_DOWN              0x4

/* flag to indicate movement within a touch cycle for a certain finger (event move) */
#define EW_BSP_TOUCH_MOVE               0x1

/* flag to indicate end of a touch cycle for a certain finger (event up) */
#define EW_BSP_TOUCH_UP                 0x5


/******************************************************************************
* TYPE:
*   XTouchEvent
*
* DESCRIPTION:
*   The structure XTouchEvent describes the touch position and touch state of a
*   single finger.
*
* ELEMENTS:
*   XPos           - Horizontal position of the touch event.
*   YPos           - Vertical position of the touch event.
*   Finger         - Number of the finger (0...9).
*   State          - State within the touch cycle (down - move - up).
*
******************************************************************************/
typedef struct
{
  int   XPos;
  int   YPos;
  int   Finger;
  int   State;
} XTouchEvent;


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
int EwBspTouchInit
(
  int               aGuiWidth,
  int               aGuiHeight,
  XDisplayInfo*     aDisplayInfo
);


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
void EwBspTouchDone
(
  void
);


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
int EwBspTouchGetEvents
(
  XTouchEvent**               aTouchEvent
);


/*******************************************************************************
* FUNCTION:
*   EwBspTouchEventHandler
*
* DESCRIPTION:
*   The function EwBspTouchEventHandler is called from the touch screen driver
*   in case of a touch event.
*
* ARGUMENTS:
*   aEventId - An optional target specific event ID.
*
* RETURN VALUE:
*   None.
*
*******************************************************************************/
void EwBspTouchEventHandler(XTouchEvent* aTouchEvent);


#ifdef __cplusplus
  }
#endif

#endif /* EW_BSP_TOUCH_H */


/* msy */
