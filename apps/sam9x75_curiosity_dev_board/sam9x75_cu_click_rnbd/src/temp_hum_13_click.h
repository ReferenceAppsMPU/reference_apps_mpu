/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _TEMP_HUM_13_CLICK_H    /* Guard against multiple inclusion */
#define _TEMP_HUM_13_CLICK_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

#include <definitions.h>

typedef enum
{
    APP_TRANSFER_STATUS_IN_PROGRESS,
    APP_TRANSFER_STATUS_SUCCESS,
    APP_TRANSFER_STATUS_ERROR,
    APP_TRANSFER_STATUS_IDLE,
}APP_TEMP_HUM_13_CLICK_STATUS;

    
#define APP_ACK_DATA_LENGTH            (3)

#define  TEMPHUM13_OK                         0x00
#define  TEMPHUM13_INIT_ERROR                 0xFF
/** \} */

/**
 * \defgroup slave_addr Slave Address
 * \{
 */
#define  TEMPHUM13_DEVICE_ADDRESS             0x40
/** \} */

/**
 * \defgroup commands Commands
 * \{
 */
#define  TEMPHUM13_CMD_TRIG_TEMP_MEAS_HOLD    0xE3
#define  TEMPHUM13_CMD_TRIG_HUMI_MEAS_HOLD    0xE5
#define  TEMPHUM13_CMD_TRIG_TEMP_MEAS_NOHOLD  0xF3
#define  TEMPHUM13_CMD_TRIG_HUMI_MEAS_NOHOLD  0xF5
#define  TEMPHUM13_CMD_WRITE_USER_REG         0xE6
#define  TEMPHUM13_CMD_READ_USER_REG          0xE7
#define  TEMPHUM13_CMD_SOFT_RESET             0xFE
/** \} */


/**
 * \defgroup heater_switch Heater Switch
 * \{
 */
#define  TEMPHUM13_HEATER_ENABLE              0x01
#define  TEMPHUM13_HEATER_DISABLE             0x00
/** \} */

/**
 * \defgroup resolution Resolution
 * \{
 */
#define  TEMPHUM13_RESOLUTION_8               0x01
#define  TEMPHUM13_RESOLUTION_10              0x80
#define  TEMPHUM13_RESOLUTION_11              0x81
#define  TEMPHUM13_RESOLUTION_12              0x00
/** \} */

/**
 * \defgroup otp OTP
 * \{
 */
#define  TEMPHUM13_OTP_DISABLE                0x01
#define  TEMPHUM13_OTP_ENABLE                 0x00
/** \} */
    

   // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */
extern void APP_FLEXCOMTWICallback(uintptr_t context );
extern int32_t temp_hum_13_click_get_temp(void);
extern int32_t temp_hum_13_click_get_humidity ( void);
extern void temp_hum_13_click_cfg(void);


    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _TEMP_HUM_11_CLICK_H */

/* *****************************************************************************
 End of File
 */
