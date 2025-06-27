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
#include "PAC193x.h"

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

#define PAC193X_I2C_ADDR1   0x10
#define PAC193X_I2C_ADDR2   0x11

/* mikroE RST/P19 = RE9 on EXPLORER16/32 + PIC32MX795F512L PIM*/
//#define SENSOR_RESET_PIN GPIO_PIN_RE9    // reset pin active low
#define SENSOR_RESET_PIN PIO_PIN_PC31
#define SENSOR_RESET_TIME   1000        // time to hold reset pin active
#define SENSOR_POST_RESET_TIME 20       // wait time after sensor reset

#define APP_SENSOR_I2C_CLOCK_SPEED      100000  //  100khz

#define PDB_RSENSE_MICRO_CH1  47000    //micro-ohms
#define PDB_RSENSE_MICRO_CH2  47000    //micro-ohms
#define PDB_RSENSE_MICRO_CH3  47000    //micro-ohms
#define PDB_RSENSE_MICRO_CH4  47000    //micro-ohms

#define CHANNEL_NO_1    1
#define CHANNEL_NO_2    2
#define CHANNEL_NO_3    3
#define CHANNEL_NO_4    4

#define CHANNEL_COUNT 4U

PAC193X_DEVICE_INIT deviceInit;
bool isSensorInitDone = false;
uint32_t rsense[PAC193X_MAX_CH_COUNT] = {PDB_RSENSE_MICRO_CH1, PDB_RSENSE_MICRO_CH2, PDB_RSENSE_MICRO_CH3, PDB_RSENSE_MICRO_CH4};
uint8_t i;

float vbus_mVolts[CHANNEL_COUNT], energy_mWh[CHANNEL_COUNT], power_mW[CHANNEL_COUNT], current_mA[CHANNEL_COUNT];

PAC193X_DEVICE_CONTEXT sensorContext;

int16_t errorCode;

void PAC1934_Initialize(void) 
{
    //int16_t errorCode;
    errorCode = 0;
    DRV_HANDLE i2cHandle;
    DRV_I2C_TRANSFER_SETUP i2cSetup;    
    /* reset the PAC193x devices by PWRDN toggle */
    /* use mikroE RST signal to drive PWRDN pin */
    PIO_PinOutputEnable(SENSOR_RESET_PIN);                     // configure RST: PA07/PA06/PB06 as output
    PIO_PinClear(SENSOR_RESET_PIN);                            // drive RST low
//    SYS_TIME_HANDLE timer = SYS_TIME_HANDLE_INVALID;
//    /* Wait interval before starting a new data sampling cycle */
//    SYS_TIME_DelayMS(SENSOR_RESET_TIME, &timer);   // keep PWRDN for a little while
//    while (SYS_TIME_DelayIsComplete(timer) == false);
//                     
//    PIO_PinSet(SENSOR_RESET_PIN);                              // drive RST high
//    SYS_TIME_DelayMS(SENSOR_POST_RESET_TIME, &timer);   // The first measurement data may be requested by a
//                                                                // REFRESH or REFRESH_V command 20 ms after the
//                                                                // PWRDN pin is pulled high.
//    while (SYS_TIME_DelayIsComplete(timer) == false);
    printf("PAC193x device HW RESET done. \r\n");

    
    i2cHandle = DRV_I2C_Open(DRV_I2C_INDEX_0, DRV_IO_INTENT_READWRITE);
    if (i2cHandle != DRV_HANDLE_INVALID)
    {   
        i2cSetup.clockSpeed = APP_SENSOR_I2C_CLOCK_SPEED;
        /* Setup I2C transfer speed to interface with Sensor */  
        if( false == DRV_I2C_TransferSetup(i2cHandle, &i2cSetup) ){ 
            printf("I2C Transfer Setup failed. \r\n");     
        }
    }
    else{
        printf("I2C Driver Open failed. Abort library initialization. \r\n");
        return;
    }
    
    /* Initialize the PAC device instance */
    deviceInit.i2cHandle = i2cHandle;
    deviceInit.i2cAddress = PAC193X_I2C_ADDR1;
    deviceInit.syncMode = false;    //use the async mode
    for(i = 0; i < PAC193X_MAX_CH_COUNT; i++){
        deviceInit.rsense[i] = rsense[i];
    }
    
    errorCode = PAC193x_Device_Initialize(&sensorContext, deviceInit);
    if((errorCode != PAC193X_SUCCESS))
    {
        isSensorInitDone = false;
        printf("PAC193x device initialization error \r\n");
    }else{
        isSensorInitDone = true;
        printf("PAC193x device initialization done. \r\n");
    }
    
}

void PAC1934_Read( void )
{
    long delaycount = 0;
   
    
    if( isSensorInitDone == true)
        
    {
        while( PAC193x_Device_IsBusy(&sensorContext) );

        PAC193x_RefreshV( &sensorContext );


        while(delaycount != 4000000) // This delay is mandatory after the refresh command 
        {
            delaycount++;
        }

        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetVBUSn_mV(&sensorContext, CHANNEL_NO_1, &vbus_mVolts[0]);


        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetVPOWERn_mW(&sensorContext, CHANNEL_NO_1, &power_mW[0]);


        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetEnergy_mWh(&sensorContext, CHANNEL_NO_1, &energy_mWh[0]);


        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetISENSEn_AVG_mA(&sensorContext, CHANNEL_NO_1, &current_mA[0]);


        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetVBUSn_mV(&sensorContext, CHANNEL_NO_2, &vbus_mVolts[1]);

        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetVPOWERn_mW(&sensorContext, CHANNEL_NO_2, &power_mW[1]);


        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetEnergy_mWh(&sensorContext, CHANNEL_NO_2, &energy_mWh[1]);


        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetISENSEn_AVG_mA(&sensorContext, CHANNEL_NO_2, &current_mA[1]);


        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetVBUSn_mV(&sensorContext, CHANNEL_NO_3, &vbus_mVolts[2]);

        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetVPOWERn_mW(&sensorContext, CHANNEL_NO_3, &power_mW[2]);

        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetEnergy_mWh(&sensorContext, CHANNEL_NO_3, &energy_mWh[2]);

        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetISENSEn_AVG_mA(&sensorContext, CHANNEL_NO_3, &current_mA[2]);


        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetVBUSn_mV(&sensorContext, CHANNEL_NO_4, &vbus_mVolts[3]);


        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetVPOWERn_mW(&sensorContext, CHANNEL_NO_4, &power_mW[3]);


        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetEnergy_mWh(&sensorContext, CHANNEL_NO_4, &energy_mWh[3]);

        while(PAC193x_Device_IsBusy(&sensorContext));

        PAC193x_GetISENSEn_AVG_mA(&sensorContext, CHANNEL_NO_4, &current_mA[3]);


        printf("\r\n------------------------------------------------------------------------------------------------------");
        printf("\r\nVDD_3V3    -> VBUS1(mV): %4.3f, POWER1(mW): %3.3f, ENERGY1(mWh): %3.3f, CURRENT1(mA): %3.3f", (float)vbus_mVolts[0], (float)(power_mW[0] ), (float)(energy_mWh[0] ), (float)(current_mA[0]));
        printf("\r\nVDD_IODDR  -> VBUS2(mV): %4.3f, POWER2(mW): %3.3f, ENERGY2(mWh): %3.3f, CURRENT2(mA): %3.3f", (float)vbus_mVolts[1], (float)(power_mW[1] ), (float)(energy_mWh[1] ), (float)(current_mA[1]));
        printf("\r\nVDD_CORE   -> VBUS3(mV): %4.3f, POWER3(mW): %3.3f, ENERGY3(mWh): %3.3f, CURRENT3(mA): %3.3f", (float)vbus_mVolts[2], (float)(power_mW[2] ), (float)(energy_mWh[2] ), (float)(current_mA[2]));
        printf("\r\nVDD_CPU    -> VBUS4(mV): %4.3f, POWER4(mW): %3.3f, ENERGY1(mWh): %3.3f, CURRENT1(mA): %3.3f", (float)vbus_mVolts[0], (float)(power_mW[0] ), (float)(energy_mWh[0] ), (float)(current_mA[0]));

    }
    
}




int main ( void )
{
    
    
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    printf("sama7d65_cu_pac1934_demo\r\n");
    
    PAC1934_Initialize(); 
        
    
    while ( true )
    {

      unsigned long onesecdelaycount = 0;
        
      PAC1934_Read();
      
      while(onesecdelaycount != 100000000) // This delay change the printing speed in terminal 
        {
            onesecdelaycount++;
        }
        
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

