/*
  © 2022 Microchip Technology Inc. and its subsidiaries

  Subject to your compliance with these terms, you may use Microchip software
  and any derivatives exclusively with Microchip products. You're responsible
  for complying with 3rd party license terms applicable to your use of 3rd party
  software (including open source software) that may accompany Microchip software.
  SOFTWARE IS "AS IS." NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
  APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
  MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP
  BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS,
  DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER
  CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
  FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S TOTAL LIABILITY
  ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT EXCEED AMOUNT OF FEES, IF ANY,
  YOU PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*/

#ifndef PAC193X_H
#define PAC193X_H

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

// PAC193x generic library version
#define PAC193X_LIBVER "1.2"

/**
    Section: Included Files
*/
#include <string.h>
#include <stdio.h>
///////////////////////////////////////////////////////////////////////////////
/*
 * Target platform adaptation data types and services
 */ 
 
#include "driver/i2c/drv_i2c.h"         // I2C driver support 
#include "osal/osal.h"                  // MUTEX support
    
typedef OSAL_MUTEX_HANDLE_TYPE  PAC193X_MUTEX;
typedef DRV_I2C_TRANSFER_HANDLE PAC193X_I2C_TRANSFER_HANDLE;    // uintptr_t
typedef DRV_HANDLE              PAC193X_I2C_HANDLE;             // uintptr_t
typedef DRV_I2C_TRANSFER_SETUP  PAC193X_I2C_TRANSFER_SETUP;    

#define I2C_EVENT_CALLBACK_SUPPORTED
//#define I2C_EVENT_CALLBACK_UNSUPPORTED

#if defined(I2C_EVENT_CALLBACK_SUPPORTED) && defined(I2C_EVENT_CALLBACK_UNSUPPORTED)
#error "Cannot define both I2C_EVENT_CALLBACK_SUPPORTED and I2C_EVENT_CALLBACK_UNSUPPORTED!!!"
#endif
#if !defined(I2C_EVENT_CALLBACK_SUPPORTED) && !defined(I2C_EVENT_CALLBACK_UNSUPPORTED)
#error "Define I2C_EVENT_CALLBACK_SUPPORTED or I2C_EVENT_CALLBACK_UNSUPPORTED!!!"
#endif

#define PAC193X_I2C_INTENT_READWRITE        DRV_IO_INTENT_READWRITE
#define PAC193X_I2C_HANDLE_INVALID          DRV_HANDLE_INVALID
#define PAC193X_I2C_TRANSFER_HANDLE_INVALID DRV_I2C_TRANSFER_HANDLE_INVALID

typedef enum
{
    /* Transfer request is pending */
    PAC193X_I2C_TRANSFER_EVENT_PENDING = DRV_I2C_TRANSFER_EVENT_PENDING,

    /* All data from or to the buffer was transferred successfully. */
    PAC193X_I2C_TRANSFER_EVENT_COMPLETE = DRV_I2C_TRANSFER_EVENT_COMPLETE,

    /* Transfer Handle given is expired. It means transfer
    is completed but with or without error is not known. */
    PAC193X_I2C_TRANSFER_EVENT_HANDLE_EXPIRED = DRV_I2C_TRANSFER_EVENT_HANDLE_EXPIRED,

    /* There was an error while processing the buffer transfer request. */
    PAC193X_I2C_TRANSFER_EVENT_ERROR = DRV_I2C_TRANSFER_EVENT_ERROR,

    PAC193X_I2C_TRANSFER_EVENT_HANDLE_INVALID = DRV_I2C_TRANSFER_EVENT_HANDLE_INVALID

} PAC193X_I2C_TRANSFER_EVENT;

typedef void ( PAC193X_I2C_TRANSFER_EVENT_HANDLER )( PAC193X_I2C_TRANSFER_EVENT event, PAC193X_I2C_TRANSFER_HANDLE transferHandle, uintptr_t context );
typedef void ( *PAC193X_P_I2C_TRANSFER_EVENT_HANDLER )( PAC193X_I2C_TRANSFER_EVENT event, PAC193X_I2C_TRANSFER_HANDLE transferHandle, uintptr_t context );

///////////////////////////////////////////////////////////////////////////////

/*
 * Target platform independent 
 */

//#define BIG_ENDIAN_ARCHITECTURE

//PAC193x maximum transmission and reception data byte-count
#define PAC193X_I2C_TX_MAXSIZE    3
#define PAC193X_I2C_RX_MAXSIZE    7
    
#define PAC193X_MAX_CH_COUNT      4
#define PAC193X_VBUS_FSR_MV      32000
#define PAC193X_VSENSE_FSR_MV      100
#define PAC193X_VPOWER_FSR_W       3.2
#define PAC193X_VPOWER_FSR_MW     3200

#define ENERGY_UNIT_CONVERSION  (float)1/3600  //convert from 1Ws to 1Wh
    
/*
 * PAC193x register address
 */

#define PAC193X_CLIENT_ADDRESS              0x10

#define PAC193X_REFRESH_CMD_ADDR            0x00
#define PAC193X_CTRL_ADDR                   0x01
#define PAC193X_ACC_COUNT_ADDR              0x02
#define PAC193X_VPOWER1_ACC_ADDR            0x03
#define PAC193X_VPOWER2_ACC_ADDR            0x04
#define PAC193X_VPOWER3_ACC_ADDR            0X05
#define PAC193X_VPOWER4_ACC_ADDR            0X06
#define PAC193X_VBUS1_ADDR                  0x07
#define PAC193X_VBUS2_ADDR                  0x08
#define PAC193X_VBUS3_ADDR                  0x09
#define PAC193X_VBUS4_ADDR                  0x0A
#define PAC193X_VSENSE1_ADDR                0x0B
#define PAC193X_VSENSE2_ADDR                0x0C
#define PAC193X_VSENSE3_ADDR                0X0D
#define PAC193X_VSENSE4_ADDR                0X0E
#define PAC193X_VBUS1_AVG_ADDR              0X0F
#define PAC193X_VBUS2_AVG_ADDR              0X10
#define PAC193X_VBUS3_AVG_ADDR              0X11
#define PAC193X_VBUS4_AVG_ADDR              0X12
#define PAC193X_VSENSE1_AVG_ADDR            0X13
#define PAC193X_VSENSE2_AVG_ADDR            0X14
#define PAC193X_VSENSE3_AVG_ADDR            0X15
#define PAC193X_VSENSE4_AVG_ADDR            0X16
#define PAC193X_VPOWER1_ADDR                0X17
#define PAC193X_VPOWER2_ADDR                0X18
#define PAC193X_VPOWER3_ADDR                0X19
#define PAC193X_VPOWER4_ADDR                0X1A
#define PAC193X_CHANNEL_DIS_ADDR            0X1C
#define PAC193X_NEG_PWR_ADDR                0X1D
#define PAC193X_REFRESH_G_CMD_ADDR          0x1E
#define PAC193X_REFRESH_V_CMD_ADDR          0x1F
#define PAC193X_SLOW_ADDR                   0X20
#define PAC193X_CTRL_ACT_ADDR               0X21
#define PAC193X_CHANNEL_DIS_ACT_ADDR        0X22
#define PAC193X_NEG_PWR_ACT_ADDR            0X23
#define PAC193X_CTRL_LAT_ADDR               0X24
#define PAC193X_CHANNEL_DIS_LAT_ADDR        0X25
#define PAC193X_NEG_PWR_LAT_ADDR            0x26

#define PAC193X_PRODUCT_ID_ADDR             0xFD
#define PAC193X_MANUFACTURER_ID_ADDR        0xFE
#define PAC193X_REVISION_ID_ADDR            0xFF
    
/*
 * DEVICE REGISTER SIZES (bytes)
 */
#define PAC193X_ACC_COUNT_SZ       3
#define PAC193X_VACCN_SZ           6
#define PAC193X_VPOWERN_SZ         4
#define PAC193X_IDREG_SZ           1
#define PAC193X_CTRL_SZ            1
#define PAC193X_VBUS_VSENSE_SZ     2
#define PAC193X_CH_DIS_SZ          1
#define PAC193X_NEG_PWR_SZ         1
#define PAC193X_SLOW_SZ            1

#define SMBUS_BYTECNT   1   //the extra byte for SMBUS block read protocol    
    
/*
 * PAC193x library error codes
 */    
#define PAC193X_NO_ERR                                0
#define PAC193X_SUCCESS                               0
#define PAC193X_BUSY                                  1
#define PAC193X_MUTEX_INVALID                         2
#define PAC193X_MUTEX_FAIL                            3
#define PAC193X_INVALID_PARAMETER                     4
#define PAC193X_I2C_INVALID_PARAM                     5
#define PAC193X_INVALID_DEVICE                        6
#define PAC193X_ERR_NO_SINGLE_SHOT_MODE               7
#define PAC193X_ERR_SINGLE_SHOT_MODE                  8
#define PAC193X_ALREADY_CACHED                        9
#define PAC193X_INVALID_INPUT_VALUE                   10
#define PAC193X_INVALID_SHUNT_VALUE                   11
#define PAC193X_REQUEST_FAIL                          100  
    
/* 
 * PAC1934 library interface
 */

typedef enum _PAC193X_procState{
    Uninitialized = 0,
    Idle = 1,
    Sync = 2,
    GetDeviceIDReq            = 10,
    RefreshReq                = 20,
    RefreshGReq               = 21,
    RefreshVReq               = 22,
    GetCtrlRegisterReq        = 30,
    SetCtrlRegisterReq        = 31,
    GetChDisRegisterReq       = 32,
    SetChDisRegisterReq       = 33,
    GetNegPWRRegisterReq      = 34,
    SetNegPWRRegisterReq      = 35,
    GetSlowRegisterReq        = 36,
    SetSlowRegisterReq        = 37,
    GetAccCountReq            = 40,
    GetVACCnRegisterReq       = 50,
    GetVACCnValueReq          = 51,
    GetEnergyReq              = 52,
    GetTimedEnergyReq         = 53,
    GetVBUSnRegisterReq       = 70,
    GetVBUSnValueReq          = 71,
    GetVSENSEnRegisterReq     = 72,
    GetVSENSEnValueReq        = 73,
    GetISENSEnValueReq        = 74,
    GetVBUSnAVGRegisterReq    = 80,
    GetVBUSnAVGValueReq       = 81,
    GetVSENSEnAVGRegisterReq  = 82,
    GetVSENSEnAVGValueReq     = 83,
    GetISENSEnAVGValueReq     = 84,
    GetVPOWERnRegisterReq     = 90,
    GetVPOWERnValueReq        = 91,
} PAC193X_procState;

typedef struct _PAC193X_DEVICE_INIT{
    uint16_t i2cAddress;                    //i2c client address of the PAC193x device
    bool syncMode;                          //if TRUE, the library function calls will be blocking calls
    PAC193X_I2C_HANDLE i2cHandle;
    uint32_t rsense[PAC193X_MAX_CH_COUNT];  //array of sense resistor values, expressed in micro-Ohm units, one value for each channel.
} PAC193X_DEVICE_INIT;

typedef enum {
    PAC193X_EVENT_NO_EVENT          = 0,
    PAC193X_EVENT_REQUEST_COMPLETE  = 1,
    PAC193X_EVENT_TRANSFER_ERROR    = 2,
    PAC193X_EVENT_UNKNOWN_ERROR     = 3,    // unidentified i2c communication error encountered
    PAC193X_EVENT_REQUEST_ERROR     = 4,
    PAC193X_EVENT_REQUEST_PENDING   = 5,
    PAC193X_EVENT_TIMEOUT           = 6
}PAC193X_EVENT, *PAC193X_PEVENT;

//This is the prototype for the user "callback function" that the library can execute 
//upon receiving one of the events of PAC193X_EVENT type.
typedef void ( *PAC193X_EVENT_HANDLER )( PAC193X_EVENT event, uintptr_t context );

typedef struct _PAC193X_deviceID {
    uint8_t product;        // PRODUCT_ID register value
    uint8_t manufacturer;   // MANUFACTURER_ID register value
    uint8_t revision;       // REVISION_ID register value
 } PAC193X_deviceID, *PAC193X_PdeviceID;
 
#if defined(BIG_ENDIAN_ARCHITECTURE)
 typedef struct _PAC193X_CTRL_REGISTER{
    unsigned char SAMPLE_RATE : 1;
    unsigned char SLEEP       : 1;
    unsigned char SINGLE_SHOT : 1;
    unsigned char ALRT_PIN    : 1;
    unsigned char ALERT_CC    : 1;
    unsigned char OVF_ALERT   : 1;
    unsigned char OVF_STATUS  : 2;
} PAC193X_CTRL_REGISTER, *PAC193X_PCTRL_REGISTER; 

typedef struct _PAC193X_CHANNEL_DIS_SMBUS_REGISTER {
    unsigned char CH1_OFF     : 1;
    unsigned char CH2_OFF     : 1;
    unsigned char CH3_OFF     : 1;
    unsigned char CH4_OFF     : 1;
    unsigned char TIMEOUT     : 1;
    unsigned char BYTE_COUNT  : 1;
    unsigned char NO_SKIP     : 1;
    unsigned char             : 1;
} PAC193X_CHANNEL_DIS_SMBUS_REGISTER, *PAC193X_PCHANNEL_DIS_SMBUS_REGISTER;

typedef struct _PAC193X_NEG_PWR_REGISTER {    
    unsigned char CH1_BIDI : 1;
    unsigned char CH2_BIDI : 1;
    unsigned char CH3_BIDI : 1;
    unsigned char CH4_BIDI : 1; 
    unsigned char CH1_BIDV : 1;
    unsigned char CH2_BIDV : 1;
    unsigned char CH3_BIDV : 1;
    unsigned char CH4_BIDV : 1;
} PAC193X_NEG_PWR_REGISTER, *PAC193X_PNEG_PWR_REGISTER;

typedef struct _PAC193X_SLOW_REGISTER {
    unsigned char Slow          : 1;
    unsigned char SlowLowHigh   : 1;
    unsigned char SlowHighLow   : 1;
    unsigned char RefreshRise   : 1;
    unsigned char RefreshVRise  : 1;
    unsigned char RefreshFall   : 1;
    unsigned char RefreshVFall  : 1;
    unsigned char POR           : 1;
} PAC193X_SLOW_REGISTER, *PAC193X_PSLOW_REGISTER;
#else
typedef struct _PAC193X_CTRL_REGISTER{
    unsigned char OVF_STATUS  : 1;
    unsigned char OVF_ALERT   : 1;
    unsigned char ALERT_CC    : 1;
    unsigned char ALRT_PIN    : 1;
    unsigned char SINGLE_SHOT : 1;
    unsigned char SLEEP       : 1;
    unsigned char SAMPLE_RATE : 2;
} PAC193X_CTRL_REGISTER, *PAC193X_PCTRL_REGISTER; 

typedef struct _PAC193X_CHANNEL_DIS_SMBUS_REGISTER {
    unsigned char             : 1;
    unsigned char NO_SKIP     : 1;
    unsigned char BYTE_COUNT  : 1;
    unsigned char TIMEOUT     : 1;
    unsigned char CH4_OFF     : 1;
    unsigned char CH3_OFF     : 1;
    unsigned char CH2_OFF     : 1;
    unsigned char CH1_OFF     : 1;
} PAC193X_CHANNEL_DIS_SMBUS_REGISTER, *PAC193X_PCHANNEL_DIS_SMBUS_REGISTER;

typedef struct _PAC193X_NEG_PWR_REGISTER {    
    unsigned char CH4_BIDV : 1;
    unsigned char CH3_BIDV : 1;
    unsigned char CH2_BIDV : 1;
    unsigned char CH1_BIDV : 1; 
    unsigned char CH4_BIDI : 1;
    unsigned char CH3_BIDI : 1;
    unsigned char CH2_BIDI : 1;
    unsigned char CH1_BIDI : 1;
} PAC193X_NEG_PWR_REGISTER, *PAC193X_PNEG_PWR_REGISTER;

typedef struct _PAC193X_SLOW_REGISTER {
    unsigned char POR           : 1;
    unsigned char RefreshVFall  : 1;
    unsigned char RefreshFall   : 1;
    unsigned char RefreshVRise  : 1;
    unsigned char RefreshRise   : 1;
    unsigned char SlowHighLow   : 1;
    unsigned char SlowLowHigh   : 1;
    unsigned char Slow          : 1;
} PAC193X_SLOW_REGISTER, *PAC193X_PSLOW_REGISTER;
#endif
/* !!! WARNING !!!
 * The device context structure is initialized by PAC193x_Device_Initialize() function call
 */ 

typedef struct _PAC193X_DEVICE_CONTEXT
{
    // mutexProcState mutex helps to avoid concurrent processingState changes 
    // from "Idle" to a request processing state or from a request processing state back to "Idle"/"Sync".
    // (e.g. avoid new device request until the current one is completed)
    PAC193X_MUTEX mutexProcState;

    volatile PAC193X_procState processingState;
    volatile PAC193X_EVENT deviceEventStatus;   //to be reset every time a new request is initiated 
    
    uint16_t i2cAddress;
    PAC193X_I2C_HANDLE i2cHandle;
    PAC193X_I2C_TRANSFER_HANDLE transferHandle;
    PAC193X_I2C_TRANSFER_HANDLE transferHandle_ctrl;
    PAC193X_I2C_TRANSFER_HANDLE transferHandle_negPwr;

    PAC193X_EVENT_HANDLER userCallback;
    uintptr_t             userContext;
    bool syncMode;  // if TRUE, the library functions will be blocking functions
    
    uint8_t i2cTxBuffer[PAC193X_I2C_TX_MAXSIZE];
    uint8_t i2cTxBuffer_ctrl[PAC193X_I2C_TX_MAXSIZE];
    uint8_t i2cTxBuffer_negPwr[PAC193X_I2C_TX_MAXSIZE];
    uint8_t i2cRxBuffer[PAC193X_I2C_RX_MAXSIZE + SMBUS_BYTECNT];
    uint8_t i2cRxBuffer_ctrl[PAC193X_CTRL_SZ + SMBUS_BYTECNT];
    uint8_t i2cRxBuffer_negPwr[PAC193X_NEG_PWR_SZ + SMBUS_BYTECNT];

    //copy the requested data in the user buffer;     
    void *outData;
    uint8_t channelNo;
    uint32_t time;
    
    uint8_t HwChannels;
        
    // Sense resistor values, expressed in micro-Ohm units.
    uint32_t rsense[PAC193X_MAX_CH_COUNT];
    
    // cached BYTE_COUNT flag from the CHANNEL DIS and SMBUS register,
    // kept in sync by PAC193x_SetChannelDisSMBus_reg() and PAC193x_GetChannelDisSMBus_reg()
    bool ENABLE_BYTE_COUNT_FLAG;

    //cached channel scale values
    //"sign" depends on negPwr configuration
    //the cache must be marked "Invalid" by any "Refresh/V/G" or by "PAC193x_SetNegPwr_reg()"
    float IsenseLSB[PAC193X_MAX_CH_COUNT];            //Isense LSB unit;
    float VPowerLSB[PAC193X_MAX_CH_COUNT];            //VPower LSB unit;
    uint8_t  IsSignedPower[PAC193X_MAX_CH_COUNT];     //IsSignedPower;
    uint8_t  IsSignedVbus[PAC193X_MAX_CH_COUNT];      //Vbus is signed
    uint8_t  IsSignedVsense[PAC193X_MAX_CH_COUNT];    //Vsense is signed

    //cached sample rate
    uint16_t sampleRate;
    
    //cached device registers   
    PAC193X_deviceID deviceID;                        //updated by the PAC193x_GetDeviceID() function call
    PAC193X_CTRL_REGISTER ctrl_LAT;                   //updated by the PAC193x_GetCtrl_reg() function call
    PAC193X_NEG_PWR_REGISTER negPwr_LAT;              //updated by the PAC193x_GetNegPwr_reg() function call
    
    //cached validity flags
    bool deviceID_cached;
    bool ctrl_LAT_cached;
    bool negPwr_LAT_cached;
        
} PAC193X_DEVICE_CONTEXT, *PAC193X_PDEVICE_CONTEXT;

/* 
 * PAC193x library interface
 */


/**
    @Summary
        Set the user call-back function.
    @Description
        This routine registers the user function that PAC193x library will call back 
        every time the library generates a processing event of the PAC193X_EVENT type.
        For instance, the user call-back function can be useful to flag the completion of the 
        library service request or the error occurrence. 
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        userCallback - The pointer to the call-back function. 
    @Param
        userContext - Pointer to a variable of user defined datatype that the called-back function will
                      receive as parameter.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_SetUserCallback(pPACdevice, appCallback, (uintptr_t)&user_data);
        </code>
*/
int16_t PAC193x_SetUserCallback(
    const PAC193X_PDEVICE_CONTEXT pdevice,
    const PAC193X_EVENT_HANDLER userCallback,
    const uintptr_t userContext
);


/**
    @Summary
        Library processing timeout function.
    @Description
        This routine can be called from user application or can be registered as a timer callback  
        function in order to drop the pending library request and reset the processing state to "Idle". 
    @Preconditions
        None
    @Param
        deviceContext - pointer to PAC193x device context data.
    @Returns
        Nothing.
    @Example
        <code>
            PAC193x_Timeout((uintptr_t)pPACdevice);
        </code>
*/
void PAC193x_Timeout(
    const uintptr_t deviceContext
);


/**
    @Summary
        Provides the latest library event.
    @Description
        Provides the latest library event as recorded in the device context.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        pevent - pointer to event variable.
     @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetEventStatus(pPACdevice, &event);
        </code>
*/
int16_t PAC193x_GetEventStatus(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_PEVENT pevent);


/**
    @Summary
        Initializes the PAC193x instance.
    @Description
        This routine initializes the PAC193X_DEVICE_CONTEXT device context data and
        the PAC193x device to the default configuration,
        or to the configuration selected by the user in the MPLAB Harmony GUI.
        It also reads the device ID registers and caches their values in the device context data. 
        NOTE: 1ms delay must be allowed between the PAC193x_Device_Initialize() function call and
        the following function calls. 
    @Preconditions
        The user must assure that I2C Driver initialization has been performed.
        All deviceInit parameters must contain valid values. 
    @Param
        pdevice - Reference to the memory storage of PAC193x device context data.
    @Param
        deviceInit - Structure that contains the i2c Address, sync mode, i2c handle, rsense.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_Device_Initialize(pPACdevice, deviceInit);
        </code>
*/
int16_t PAC193x_Device_Initialize(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_DEVICE_INIT deviceInit);


/**
    @Summary
        Tests if the PAC193x instance was initialized.
    @Description
        Tests if the PAC193x instance was initialized.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Returns
        True if the PAC193x instance was initialized and false if it was not initialized.
        False if pdevice is NULL.
    @Example
        <code>
            errorCode = PAC193x_Device_IsInitialized(pPACdevice);
        </code>
*/
bool PAC193x_Device_IsInitialized(PAC193X_PDEVICE_CONTEXT pdevice);


/**
    @Summary
        Gets the identification values for the PAC193x.
    @Description
        This method gets the content of the ID registers: 
        PRODUCT_ID, MANUFACTURER_ID and REVISION_ID.
        The function caches the ID values in the device context data.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        pdeviceID - content of the ID registers
    @Return
        The error code. 
            - If the function returns PAC193X_ALREADY_CACHED, the device ID data
              is already available and copied in the pdeviceID parameter.
            - If the function returns PAC193X_SUCCESS, the data request has been 
              successfully initiated in async mode or successfully completed in 
              sync mode.
    @Example
        <code>
            errorCode = PAC193x_GetDeviceID(pPACdevice);
        <code>
*/
int16_t PAC193x_GetDeviceID(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_PdeviceID pdeviceID);


/**
    @Summary
        Executes a device 'REFRESH' command.
    @Description
        This method executes the device 'REFRESH' command. 
        The accumulator registers (power products, sample count) and the 
        Vbus, Vsense measurements are latched into the device readable registers,  
        the accumulators are reset and the configuration changes are applied. 
        The latched data is stable and can be read after 1ms.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_Refresh(pPACdevice);
        <code>
*/
int16_t PAC193x_Refresh(PAC193X_PDEVICE_CONTEXT pdevice);


/**
    @Summary
        Executes a 'REFRESH_G' command.
    @Description
        This method executes the device 'REFRESH_G' command, using i2c 
        General Call command. In this case, for all PAC193x devices connected at the
        same i2c bus, the accumulator registers (power products, sample count) and the 
        Vbus, Vsense measurements are latched into the devices readable registers,  
        the accumulators are reset and the configuration changes are applied. 
        The latched data is stable and can be read after 1ms.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_RefreshG(pPACdevice);
        <code>
*/
int16_t PAC193x_RefreshG(PAC193X_PDEVICE_CONTEXT pdevice);


/**
    @Summary
        Executes a device 'REFRESH_V' command.
    @Description
        This method executes the device 'REFRESH_V' command. 
        The accumulator registers (power products, sample count) and the 
        Vbus, Vsense measurements are latched into the device readable registers,  
        and the configuration changes are applied but the accumulators are not reset. 
        The latched data is stable and can be read after 1ms.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_RefreshV(pPACdevice);
        <code>
*/
int16_t PAC193x_RefreshV(PAC193X_PDEVICE_CONTEXT pdevice);


/**
    @Summary
        Gets the CTRL register value.
    @Description
        This method gets the currently set, the currently active or the latched active control register value,
        depending on the reg_select mode.
        If CTRL_LAT is selected, the function caches the register value in the device context data.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        reg_select - 1- CTRL, 2- CTRL_ACT, 3- CTRL_LAT
    @Param
        pCtrl_reg - The control register value:
                        Bits 7-6:   Sample Rate
                        Bit 5:      Sleep Mode
                        Bit 4:      Single Shot Mode
                        Bit 3:      Alert Pin
                        Bit 2:      Alert CC
                        Bit 1:      Overflow Alert
                        Bit 0:      Overflow
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetCtrl_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC193x_GetCtrl_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC193X_PCTRL_REGISTER pCtrl_reg);


/**
    @Summary
        Sets the CTRL register value.
    @Description
        This method sets the current control register value. Followed by the REFRESH, 
        REFRESH_V or REFRESH_G command, the new value of register will be activated.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        Ctrl_reg - the control register value to be set (8 bit value):
                        Bits 7-6:   Sample Rate
                        Bit 5:      Sleep Mode
                        Bit 4:      Single Shot Mode
                        Bit 3:      Alert Pin
                        Bit 2:      Alert CC
                        Bit 1:      Overflow Alert
                        Bit 0:      Overflow
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_SetCtrl_reg(pPACdevice, reg_value);
        <code>
*/
int16_t PAC193x_SetCtrl_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_CTRL_REGISTER Ctrl_reg);


/**
    @Summary
        Gets the current accumulator count.
    @Description
        This method provides the count of power product samples that have been summed
        in the accumulator. 
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        pregister_val - The accumulator count register value.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetAccumulatorCount(pPACdevice, &reg_value);
        <code>
*/
int16_t PAC193x_GetAccumulatorCount(PAC193X_PDEVICE_CONTEXT pdevice, uint32_t* pregister_val);


/**
    @Summary
        Gets the current register accumulated Vpower.
    @Description
        This method gets the register value of the accumulator sum of Vpower samples.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the user variable that receives the accumulator register value.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVACCn_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC193x_GetVACCn_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint64_t* pregister_val);


/**
    @Summary
        Computes the accumulated Vpower, expressed in mW.
    @Description
        This method provides the calculated real value of the accumulated sum of Vpower samples.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the Vpower real accumulated value of the selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVACCn_mW(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC193x_GetVACCn_mW(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the accumulated energy value.
    @Description
        This method computes the energy value for the power product
        samples accumulated in the VACCn register.
        The value unit is milli-Watt-hour.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The energy value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
        
    @Example
        <code>
            errorCode = PAC193x_GetEnergy_mWh(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC193x_GetEnergy_mWh(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the accumulated energy value, considering the user measured time interval of power accumulation.
    @Description
        This method gets the calculated energy value that corresponds to the accumulated power
        in the measured time interval lapsed between the accumulator reset and the last refresh command.
        The value unit is milli-Watt-hour.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - The energy value for selected channel.
    @Param 
        time - the accumulation time to provide the energy measurement
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetTimedEnergy_mWh(pPACdevice, 1, &value, time);
        <code>
*/
int16_t PAC193x_GetTimedEnergy_mWh(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue, uint32_t time);


/**
    @Summary
        Gets the current Vbus register value.
    @Description
        This method provides the register value of the latched bus voltage sample.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the bus voltage register value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVBUSn_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC193x_GetVBUSn_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Gets the current real Vbus value.
    @Description
        This method computes the value of the latched bus voltage sample, expressed in milli-Volts.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the bus voltage calculated value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVBUSn_mV(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC193x_GetVBUSn_mV(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current Vsense register value.
    @Description
        This method gets the most recent register value of the sense voltage samples.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the register value of current sense voltage for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVSENSEn_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC193x_GetVSENSEn_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Gets the current real Vsense value.
    @Description
        This method gets the most recent calculated real value of the sense voltage samples.
        The value unit is milli-Volt.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the calculated value of current sense voltage for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVSENSEn_mV(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC193x_GetVSENSEn_mV(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current Isense value.
    @Description
        This method computes the value of the current flowing through the 
        sense resistor, expressed in mA.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the calculated value of sense current for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetISENSEn_mA(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC193x_GetISENSEn_mA(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current Vbus average register value.
    @Description
        This method gets the most recent register value of a rolling average of 
        the 8 most recent bus voltage measurements
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the bus voltage average register value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVBUSn_AVG_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC193x_GetVBUSn_AVG_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Gets the current real Vbus average value.
    @Description
        This method gets the most recent calculated real value of a rolling average of 
        the 8 most recent bus voltage measurements.
        The unit value is milli-Volt.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the bus voltage calculated average value for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVBUSn_AVG_mV(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC193x_GetVBUSn_AVG_mV(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the current Vsense average register value.
    @Description
        This method gets the most recent register value of a rolling average of 
        the 8 most recent sense voltage measurements.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the register value of current sense voltage average for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVSENSEn_AVG_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC193x_GetVSENSEn_AVG_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val);


/**
    @Summary
        Gets the current real Vsense average value.
    @Description
        This method gets the most recent calculated real value of a rolling average of 
        the 8 most recent sense voltage measurements.
        The value unit is milli-Volt.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the calculated value of current sense voltage average for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVSENSEn_AVG_mV(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC193x_GetVSENSEn_AVG_mV(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Returns the current average Isense value.
    @Description
        This method returns the most recent calculated amperage value considering the rolling average of 
        the 8 most recent sense voltage measurements.
        The value unit is milli-Amp.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the calculated value of sense amperage average for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetISENSEn_AVG_mA(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC193x_GetISENSEn_AVG_mA(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Returns the current Vpower register value.
    @Description
        This method returns the register value of the proportional power for each channel.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pregister_val - the register value of power for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVPOWERn_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC193x_GetVPOWERn_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint32_t* pregister_val);


/**
    @Summary
        Returns the current real Vpower value.
    @Description
        This method provides the power value sample latched in VPOWER register, expressed in mW.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data
    @Param
        channelNo - the channel index. Accepted values are 1, 2, 3 or 4.
    @Param
        pvalue - the calculated value of power for selected channel.
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetVPOWERn_mW(pPACdevice, 1, &value);
        <code>
*/
int16_t PAC193x_GetVPOWERn_mW(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue);


/**
    @Summary
        Gets the CHANNEL_DIS and SMBus register value.
    @Description
        This method gets the currently set CHANNEL_DIS and SMBus register value.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        pSMBus_reg - The CHANNEL_DIS and SMBus register value:
                        Bit 7: CH1_OFF
                        Bit 6: CH2_OFF
                        Bit 5: CH3_OFF
                        Bit 4: CH4_OFF
                        Bit 3: SMBus Timeout
                        Bit 2: SMBus Byte Count
                        Bit 1: No Skip
                        Bit 0: Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetChannelDisSMBus_reg(pPACdevice, &reg_value);
        <code>
*/
int16_t PAC193x_GetChannelDisSMBus_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_PCHANNEL_DIS_SMBUS_REGISTER pChDisSMBus_reg);


/**
    @Summary
        Sets the CHANNEL_DIS and SMBus register value.
    @Description
        This method sets the current CHANNEL_DIS and SMBus register value.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        SMBus_reg - The CHANNEL_DIS and SMBus register value to be set:
                        Bit 7: CH1_OFF
                        Bit 6: CH2_OFF
                        Bit 5: CH3_OFF
                        Bit 4: CH4_OFF
                        Bit 3: SMBus Timeout
                        Bit 2: SMBus Byte Count
                        Bit 1: No Skip
                        Bit 0: Unimplemented
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_SetChannelDisSMBus_reg(pPACdevice, reg_value);
        <code>
*/
int16_t PAC193x_SetChannelDisSMBus_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_CHANNEL_DIS_SMBUS_REGISTER ChDisSMBus_reg);


/**
    @Summary
        Gets the NEG_PWR register value.
    @Description
        This method gets the currently set, the currently active or the latched active NEG_PWR register value,
        depending on the reg_select mode.
        If NEG_PWR_LAT is selected, the function caches the register value in the device context data.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        reg_select - 1- NEG_PWR, 2- NEG_PWR_ACT, 3- NEG_PWR_LAT
    @Param
        pNegPwrFsr_reg - The NEG_PWR register value:
                        Bit 7: CH1 Bidirectional current measurement
                        Bit 6: CH2 Bidirectional current measurement
                        Bit 5: CH3 Bidirectional current measurement
                        Bit 4: CH4 Bidirectional current measurement
                        Bit 3: CH1 Bidirectional voltage measurement
                        Bit 2: CH2 Bidirectional voltage measurement
                        Bit 1: CH3 Bidirectional voltage measurement
                        Bit 0: CH4 Bidirectional voltage measurement
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetNegPwr_reg(pPACdevice, 1, &reg_value);
        <code>
*/
int16_t PAC193x_GetNegPwr_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC193X_PNEG_PWR_REGISTER pNegPwr_reg);


/**
    @Summary
        Sets the NEG_PWR register value.
    @Description
        This method sets the current NEG_PWR register value. Followed by the REFRESH, 
        REFRESH_V or REFRESH_G command, the new value of register will be activated.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        NegPwrFsr_reg - the NEG_PWR register value to be set (8 bit value):
                        Bit 7: CH1 Bidirectional current measurement
                        Bit 6: CH2 Bidirectional current measurement
                        Bit 5: CH3 Bidirectional current measurement
                        Bit 4: CH4 Bidirectional current measurement
                        Bit 3: CH1 Bidirectional voltage measurement
                        Bit 2: CH2 Bidirectional voltage measurement
                        Bit 1: CH3 Bidirectional voltage measurement
                        Bit 0: CH4 Bidirectional voltage measurement
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_SetNegPwr_reg(pPACdevice, reg_value);
        <code>
*/
int16_t PAC193x_SetNegPwr_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_NEG_PWR_REGISTER NegPwr_reg);


/**
    @Summary
        Gets the SLOW register value.
    @Description
        This method gets the currently set SLOW register value.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        pSlow_reg - The SLOW register value:
                    Bit 7: Slow Pin
                    Bit 6: Low to High transition
                    Bit 5: High to Low transition
                    Bit 4: REFRESH Rising Edge
                    Bit 3: REFRESH_V Rising Edge
                    Bit 2: REFRESH Falling Edge
                    Bit 1: REFRESH_V Falling Edge
                    Bit 0: Power On Reset bit
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_GetSlow_reg(pPACdevice, &reg_value);
        <code>
*/
int16_t PAC193x_GetSlow_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_PSLOW_REGISTER pSlow_reg);


/**
    @Summary
        Sets the SLOW Settings register value.
    @Description
        This method sets the current SLOW register value.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Param
        Slow_reg - The SLOW register value to be set:
                    Bit 7: Slow Pin
                    Bit 6: Low to High transition
                    Bit 5: High to Low transition
                    Bit 4: REFRESH Rising Edge
                    Bit 3: REFRESH_V Rising Edge
                    Bit 2: REFRESH Falling Edge
                    Bit 1: REFRESH_V Falling Edge
                    Bit 0: Power On Reset bit
    @Returns
        The error code. For execution success, the method returns PAC193X_SUCCESS value.
    @Example
        <code>
            errorCode = PAC193x_SetSlow_reg(pPACdevice, reg_value);
        <code>
*/
int16_t PAC193x_SetSlow_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_SLOW_REGISTER Slow_reg);


/**
    @Summary
        Tests if the PAC193x instance is busy.
    @Description
        Tests if the PAC193x instance is busy.
    @Preconditions
        None
    @Param
        pdevice - PAC193x device context data.
    @Returns
        True if the PAC193x instance is busy and false if it not busy.
        True if pdevice is NULL.
    @Example
        <code>
            errorCode = PAC193x_Device_IsBusy(pPACdevice);
        </code>
*/
bool PAC193x_Device_IsBusy(PAC193X_PDEVICE_CONTEXT pdevice);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	// _PAC193X_H

/**
  End of File
*/
