/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
#include <temp_hum_13_click.h>
#include <peripheral/flexcom/twi/master/plib_flexcom7_twi_master.h>
#include <definitions.h>
/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

void APP_FLEXCOMTWICallback(uintptr_t context );
int32_t temp_hum_13_click_get_temp(void);
int32_t temp_hum_13_click_get_humidity ( void);
void temp_hum_13_click_cfg(void);
volatile APP_TEMP_HUM_13_CLICK_STATUS transferStatus = APP_TRANSFER_STATUS_ERROR; 
/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */
static uint8_t temphum13_crc ( uint16_t input_value );

void APP_FLEXCOMTWICallback(uintptr_t context )
{

    if(FLEXCOM7_TWI_ErrorGet() == FLEXCOM_TWI_ERROR_NONE)
    {
        transferStatus = APP_TRANSFER_STATUS_SUCCESS;
    }
    else
    {
       transferStatus = APP_TRANSFER_STATUS_ERROR;
    }
}
/* This function will return temperature in Fahrenheit */
int32_t temp_hum_13_click_get_temp(void)
{
   float retval_temperature;
    uint16_t aux_temperature;
    uint8_t aux_buffer[3];
    uint8_t aux_command;

    aux_command = TEMPHUM13_CMD_TRIG_TEMP_MEAS_HOLD;
    while (FLEXCOM7_TWI_IsBusy() == true);

    if(FLEXCOM7_TWI_WriteRead(TEMPHUM13_DEVICE_ADDRESS, &aux_command, 1,  (uint8_t *)aux_buffer, 3) == true)
    {
        /* Wait for the I2C transfer to complete */
        while (FLEXCOM7_TWI_IsBusy() == true){;}

        /* Transfer complete. Check if the transfer was successful */
        if (FLEXCOM7_TWI_ErrorGet() == FLEXCOM_TWI_ERROR_NONE) 
        {
            aux_temperature = aux_buffer[ 0 ];
            aux_temperature <<= 8;
            aux_temperature |= aux_buffer[ 1 ];

            if ( aux_buffer[ 2 ] == temphum13_crc( aux_temperature ) )
            {
                aux_temperature &= 0xFFFC;

                retval_temperature = (float)( aux_temperature );
                retval_temperature /= 65536;
                retval_temperature *= 175.72;
                retval_temperature -= 46.85;
                retval_temperature = (uint16_t)((retval_temperature* 1.8) + 32);         
                return (int32_t)retval_temperature;
            }
        }
    }
    return 77;
}

void temp_hum_13_click_cfg(void)
{
    
    /* Register the FLEXCOM TWI Callback with transfer status as context */
    FLEXCOM7_TWI_CallbackRegister( APP_FLEXCOMTWICallback, (uintptr_t)&transferStatus );
            
}

int32_t temp_hum_13_click_get_humidity ( void )
{
     float retval_humidity;
    uint16_t aux_humidity;
    uint8_t aux_buffer[ 3 ];
    uint8_t aux_command;

    aux_command = TEMPHUM13_CMD_TRIG_HUMI_MEAS_HOLD;
    while (FLEXCOM7_TWI_IsBusy() == true);

    if(FLEXCOM7_TWI_WriteRead(TEMPHUM13_DEVICE_ADDRESS, &aux_command, 1,  (uint8_t *)aux_buffer, 3) == true)
    {
        /* Wait for the I2C transfer to complete */
        while (FLEXCOM7_TWI_IsBusy() == true){;}
        /* Transfer complete. Check if the transfer was successful */
        if (FLEXCOM7_TWI_ErrorGet() == FLEXCOM_TWI_ERROR_NONE) 
        {
            aux_humidity = aux_buffer[ 0 ];
            aux_humidity <<= 8;
            aux_humidity |= aux_buffer[ 1 ];
            if ( aux_buffer[ 2 ] == temphum13_crc( aux_humidity ) )
            {
                aux_humidity &= 0xFFFC;
                retval_humidity = ( float )( aux_humidity );
                retval_humidity /= 65536;
                retval_humidity *= 125.0;
                retval_humidity -= 6.0;     
                return (int32_t)retval_humidity;
            }
        }
    }
    return 50;
}

static uint8_t temphum13_crc ( uint16_t input_value )
{
    char crc[ 8 ];
    uint8_t i;
    char do_invert;
    uint8_t ret_val;
    uint16_t aux_mask;
    char bit_string[ 16 ];
    
    aux_mask = 0x8000;
    
    for ( i = 0; i < 16; i ++ )
    {
        if ( ( ( input_value & aux_mask ) != 0x0000 ) )
        {
            bit_string[ i ] = '1';
        }
        else
        {
            bit_string[ i ] = '0';
        }
        
        aux_mask >>= 1;
    }

    for ( i = 0; i < 8; ++ i )
    {
        crc[ i ] = 0;
    }

    for ( i = 0; i < 16; ++ i )
    {
        do_invert = ( '1' == bit_string[ i ] ) ^ crc[ 7 ];

        crc[ 7 ] = crc[ 6 ];
        crc[ 6 ] = crc[ 5 ];
        crc[ 5 ] = crc[ 4 ] ^ do_invert;
        crc[ 4 ] = crc[ 3 ] ^ do_invert;
        crc[ 3 ] = crc[ 2 ];
        crc[ 2 ] = crc[ 1 ];
        crc[ 1 ] = crc[ 0 ];
        crc[ 0 ] = do_invert;
    }

    ret_val = 0x00;
    aux_mask = 0x0001;
    
    for ( i = 0; i < 8; i ++ )
    {
        if ( ( ( crc[ i ] & 0x01 ) == 0x01 ) )
        {
            ret_val |= aux_mask;
        }
        aux_mask <<= 1;
    }
    
    return ret_val;
}


/* *****************************************************************************
 End of File
 */
