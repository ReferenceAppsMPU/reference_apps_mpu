/**
 * \file rnbd_example.c
 * \brief This file contains the APIs required to communicate with the RNBD driver library to 
 *        create, and open a basic Transparent EUSART demonstration.
 */  
/*
    (c) 2023 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "app_rnbd.h"
#include "rnbd/rnbd_interface.h"
#include "rnbd.h"
#include "definitions.h"                // SYS function prototypes

/** MACRO used to configure the application used buffer sizes.
 *  This is used by the application for communication buffers.
 */
#define MAX_BUFFER_SIZE                 (100)

/**< Status Buffer instance passed to RNBD drive used for Asynchronous Message Handling (see *asyncBuffer in rnbd.c) */
static char statusBuffer[MAX_BUFFER_SIZE];
static bool RNBDIsInitialized = false;

/**
 * \ingroup RN_Example
 * \brief Example Implementation of Transparent UART
 *        This can be connected to a Smart BLE 'Terminal' 
 *        application for simple data exchange demonstration.
 * * For more details, refer RNBD user guide.
 * \return Connected Status
 * \retval true - Connected.
 * \retval false - Not Connected
 */ 
//static bool RNBD_Example_TransparentUart(void);
/**
 * \ingroup RNBD_Example_Run
 * \brief This 'Runs' the example applications While(1) loop
 *
 * * For more details, refer RNBD user guide.
 * \param none
 * \return void
 */  
const char DevName[]="SAM9X75 THERMOSTAT";
bool APP_RNBD_Tasks(void)
{
    static char buffer[100];
    static int i=6;
    double temperature=25.6;
    
    if (RNBDIsInitialized)
    {
        while(RNBD_DataReady())
        {
            buffer[i] =RNBD_Read();
           // UART_CDC_write(buffer[i]);
            i++;
        }
        if(i==100){i=6;}

        if(strncmp(&buffer[i-6],"status",6) == 0)
        {
            sprintf(buffer,"\n+----------------------+\r\n| Temperature   |\r\n|  %.2f Deg C   |\r\n+----------------------+\r\n",temperature);
            RNBD_SendCmd(buffer,89);
            i=6;
        }
        return true;
    }
    else
    {
        return (false);     // ^ Held if Successful; Return failure if reaching this.
    }
}

void APP_RNBD_Initialize(void)
{
    RNBD_EnterCmdMode();
    RNBD_SetName(DevName,strlen(DevName));
    RNBD_RebootCmd();
    RNBD_EnterDataMode();
    RNBDIsInitialized = RNBD_SetAsyncMessageHandler(statusBuffer, (uint8_t)sizeof(statusBuffer));
}


/* static bool RNBD_Example_TransparentUart(void)
{
    bool isStreamOpen,isOTABegin;
   isStreamOpen = RNBD_IsConnected();
   isOTABegin = RNBD_IsOTABegin();

   if (true == isStreamOpen && false == isOTABegin)
   {
       while (RNBD_DataReady())
       {
           UART_CDC_write(RNBD_Read());
       }
       
       while (UART_CDC_DataReady()!=0U)
       {
           RNBD.Write(UART_CDC_Read());
       }
       
   }
   else
    {
        
        while (RNBD_DataReady())
       {
           UART_CDC_write(RNBD_Read());
       }
        
       
        while (UART_CDC_DataReady()!=0U)
        {
            RNBD.Write(UART_CDC_Read());
        }
       
 
    }

    return isStreamOpen;
} */


