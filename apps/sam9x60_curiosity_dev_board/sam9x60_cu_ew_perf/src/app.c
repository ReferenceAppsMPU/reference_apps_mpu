/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "definitions.h"
#include "ewconfig.h"
#include "ewmain.h"
#include "ew_bsp_console.h"
//-SL: added manually
#include "ewrte.h"
//-SL: moved
#include "ew_bsp_display.h"

#include "ew_bsp_touch.h"
#include "system/input/sys_input.h"
//-SL: don't need anymore
//#include "peripheral/uart/plib_uart0.h"
#include "gfx/driver/gfx_driver.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
 gfxIOCTLArg_LayerValue ioctlArg;
 gfxIOCTLArg_LayerIRQCallback layer_callback;
 XTouchEvent aTouchEvent;
 SYS_INP_InputListener appInputListener;
 char initialization[] = "**** Init done ****\r\n";
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;
extern void LCDC_InterruptHandler(void);
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************
static void touchDownHandler(const SYS_INP_TouchStateEvent* const evt)
{
	aTouchEvent.State= EW_BSP_TOUCH_DOWN;
    aTouchEvent.XPos  = evt->x;
    aTouchEvent.YPos   = evt->y;
    aTouchEvent.Finger = evt->index;
    EwBspTouchEventHandler(&aTouchEvent);
}

static void touchUpHandler(const SYS_INP_TouchStateEvent* const evt)
{
    aTouchEvent.State= EW_BSP_TOUCH_UP;
    aTouchEvent.XPos  = evt->x;
    aTouchEvent.YPos   = evt->y;
    aTouchEvent.Finger = evt->index;
    EwBspTouchEventHandler(&aTouchEvent);
}

static void touchMoveHandler(const SYS_INP_TouchMoveEvent* const evt)
{
    aTouchEvent.State= EW_BSP_TOUCH_MOVE;
    aTouchEvent.XPos  = evt->x;
    aTouchEvent.YPos   = evt->y;
    aTouchEvent.Finger = evt->index;
    EwBspTouchEventHandler(&aTouchEvent);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app_ewi.h.
 */

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
void  app_display_update(unsigned int aAddress);

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
    Maintains state machine of APP.
 
 */
void APP_Initialize ( void )
{   
    /* Initialize Max touch handler */
	appInputListener.handleTouchDown = &touchDownHandler;
	appInputListener.handleTouchUp = &touchUpHandler;
	appInputListener.handleTouchMove = &touchMoveHandler;
	SYS_INP_AddListener(&appInputListener);

    ioctlArg.layer.id =0;
    ioctlArg.value.v_bool = true;
    ioctlArg.value.v_colormode = GFX_COLOR_MODE_RGBA_8888;
    layer_callback.layer.id =0;
    layer_callback.callback = (void*)&LCDC_InterruptHandler;
    /* Update display driver */
    DRV_LCDC_IOCTL(GFX_IOCTL_SET_LAYER_LOCK,&ioctlArg);
    DRV_LCDC_IOCTL(GFX_IOCTL_SET_LAYER_COLOR_MODE, &ioctlArg);
    DRV_LCDC_IOCTL(GFX_IOCTL_SET_IRQ_CALLBACK,&layer_callback);
    DRV_LCDC_IOCTL(GFX_IOCTL_SET_LAYER_UNLOCK,&ioctlArg);

    /* Embedded Wizard Initializations */
    EwBspConsoleInit();
    
    EwInit();
    EwPrintSystemInfo();

    DBGU_Write((void*)&initialization, sizeof(initialization));
    while(!DBGU_TransmitComplete());
}

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

 */


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app_ewi.h.
 */

void APP_Tasks ( void )
{
    /* Check the application's current state. */
    if ( appData.state == APP_STATE_INIT)
    {
        EwProcess();
    }
}

void  app_display_update(unsigned int aAddress)
{
    ioctlArg.value.v_pointer =(void*)(aAddress-1);
    /* Update display buffer */
    DRV_LCDC_IOCTL(GFX_IOCTL_SET_LAYER_LOCK,&ioctlArg);
    DRV_LCDC_IOCTL(GFX_IOCTL_SET_LAYER_BASE_ADDRESS, &ioctlArg);
    DRV_LCDC_IOCTL(GFX_IOCTL_SET_LAYER_ENABLED, &ioctlArg);
    DRV_LCDC_IOCTL(GFX_IOCTL_SET_LAYER_UNLOCK,&ioctlArg);
}

uint32_t RTOS_AppGetRuntimeCounterValue(void);
uint32_t RTOS_AppGetRuntimeCounterValue(void)
{
    return SYS_TIME_Counter64Get();
}
/*******************************************************************************
 End of File
 */
