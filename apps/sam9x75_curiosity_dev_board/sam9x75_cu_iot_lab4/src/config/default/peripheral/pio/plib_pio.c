/*******************************************************************************
  SYS PORTS Static Functions for PORTS System Service

  Company:
    Microchip Technology Inc.

  File Name:
    plib_pio.c

  Summary:
    PIO function implementations for the PIO PLIB.

  Description:
    The PIO PLIB provides a simple interface to manage peripheral
    input-output controller.

*******************************************************************************/

//DOM-IGNORE-BEGIN
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
//DOM-IGNORE-END

#include "plib_pio.h"
#include "interrupts.h"


#define PIO_MAX_NUM_OF_CHANNELS     5U

/* Array to store callback objects of each configured interrupt */
static volatile PIO_PIN_CALLBACK_OBJ portPinCbObj[0 + 0 + 1 + 0 + 0];

/* Array to store number of interrupts in each PORT Channel + previous interrupt count */
static volatile uint8_t portNumCb[PIO_MAX_NUM_OF_CHANNELS + 1] = {0U, 0U, 0U, 1U, 1U, 1U};
 void PIO_Interrupt_Handler ( PIO_PORT port );

/******************************************************************************
  Function:
    PIO_Initialize ( void )

  Summary:
    Initialize the PIO library.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_Initialize ( void )
{

    /************************ PIO A Initialization ************************/
    /* PORTA PIO Disable and Peripheral Enable*/
    ((pio_registers_t*)PIO_PORT_A)->PIO_PDR = 0x3c000e00U;
    ((pio_registers_t*)PIO_PORT_A)->PIO_PER = ~0x3c000e00U;
    ((pio_registers_t*)PIO_PORT_A)->PIO_MDDR = 0xFFFFFFFFU;
    /* PORTA Pull Up Enable/Disable as per MHC selection */
    ((pio_registers_t*)PIO_PORT_A)->PIO_PUDR = 0xFFFFFFFFU;
    /* PORTA Pull Down Enable/Disable as per MHC selection */
    ((pio_registers_t*)PIO_PORT_A)->PIO_PPDDR = 0xFFFFFFFFU;
    /* PORTA Output Write Enable */
    ((pio_registers_t*)PIO_PORT_A)->PIO_OWER = PIO_OWER_Msk;
    /* PORTA Output Direction Enable */
    ((pio_registers_t*)PIO_PORT_A)->PIO_OER = 0x21a000U;
    ((pio_registers_t*)PIO_PORT_A)->PIO_ODR = ~0x21a000U;
    /* Initialize PORTA pin state */
    ((pio_registers_t*)PIO_PORT_A)->PIO_ODSR = 0x21a000U;
    /* PORTA Slew rate control */
    ((pio_registers_t*)PIO_PORT_A)->PIO_SLEWR = 0x0U;
    /* PORTA drive control */
    ((pio_registers_t*)PIO_PORT_A)->PIO_DRIVER = 0x0U;

    /************************ PIO B Initialization ************************/
    ((pio_registers_t*)PIO_PORT_B)->PIO_PER = 0xFFFFFFFFU;
    ((pio_registers_t*)PIO_PORT_B)->PIO_MDDR = 0xFFFFFFFFU;
    /* PORTB Pull Up Enable/Disable as per MHC selection */
    ((pio_registers_t*)PIO_PORT_B)->PIO_PUDR = 0xFFFFFFFFU;
    /* PORTB Pull Down Enable/Disable as per MHC selection */
    ((pio_registers_t*)PIO_PORT_B)->PIO_PPDDR = 0xFFFFFFFFU;
    /* PORTB Output Write Enable */
    ((pio_registers_t*)PIO_PORT_B)->PIO_OWER = PIO_OWER_Msk;
    /* PORTB Output Direction Enable */
    ((pio_registers_t*)PIO_PORT_B)->PIO_OER = 0x0U;
    ((pio_registers_t*)PIO_PORT_B)->PIO_ODR = ~0x0U;
    /* Initialize PORTB pin state */
    ((pio_registers_t*)PIO_PORT_B)->PIO_ODSR = 0x0U;
    /* PORTB Slew rate control */
    ((pio_registers_t*)PIO_PORT_B)->PIO_SLEWR = 0x0U;
    /* PORTB drive control */
    ((pio_registers_t*)PIO_PORT_B)->PIO_DRIVER = 0x0U;

    /************************ PIO C Initialization ************************/
    /* PORTC Peripheral Function Selection */
    ((pio_registers_t*)PIO_PORT_C)->PIO_ABCDSR[0]= 0x0U;
    ((pio_registers_t*)PIO_PORT_C)->PIO_ABCDSR[1]= 0x3U;
    /* PORTC PIO Disable and Peripheral Enable*/
    ((pio_registers_t*)PIO_PORT_C)->PIO_PDR = 0x3U;
    ((pio_registers_t*)PIO_PORT_C)->PIO_PER = ~0x3U;
    ((pio_registers_t*)PIO_PORT_C)->PIO_MDDR = 0xFFFFFFFFU;
    /* PORTC Pull Up Enable/Disable as per MHC selection */
    ((pio_registers_t*)PIO_PORT_C)->PIO_PUDR = ~0x20200U;
    ((pio_registers_t*)PIO_PORT_C)->PIO_PUER = 0x20200U;
    /* PORTC Pull Down Enable/Disable as per MHC selection */
    ((pio_registers_t*)PIO_PORT_C)->PIO_PPDDR = 0xFFFFFFFFU;
    /* PORTC Output Write Enable */
    ((pio_registers_t*)PIO_PORT_C)->PIO_OWER = PIO_OWER_Msk;
    /* PORTC Output Direction Enable */
    ((pio_registers_t*)PIO_PORT_C)->PIO_OER = 0x384000U;
    ((pio_registers_t*)PIO_PORT_C)->PIO_ODR = ~0x384000U;
    /* Initialize PORTC pin state */
    ((pio_registers_t*)PIO_PORT_C)->PIO_ODSR = 0x0U;
    /* PORTC Additional interrupt mode Enable */
    ((pio_registers_t*)PIO_PORT_C)->PIO_AIMER = 0x20000U;
    /* PORTC Interrupt Status Clear */
    ((pio_registers_t*)PIO_PORT_C)->PIO_ISR;
    /* PORTC system level interrupt will be enabled by NVIC Manager */
    /* PORTC module level Interrupt for every pin has to be enabled by user
       by calling PIO_PinInterruptEnable() API dynamically as and when needed*/
    /* PORTC Slew rate control */
    ((pio_registers_t*)PIO_PORT_C)->PIO_SLEWR = 0x0U;
    /* PORTC drive control */
    ((pio_registers_t*)PIO_PORT_C)->PIO_DRIVER = 0x0U;

    /************************ PIO D Initialization ************************/
    ((pio_registers_t*)PIO_PORT_D)->PIO_PER = 0xFFFFFFFFU;
    ((pio_registers_t*)PIO_PORT_D)->PIO_MDDR = 0xFFFFFFFFU;
    /* PORTD Pull Up Enable/Disable as per MHC selection */
    ((pio_registers_t*)PIO_PORT_D)->PIO_PUDR = 0xFFFFFFFFU;
    /* PORTD Pull Down Enable/Disable as per MHC selection */
    ((pio_registers_t*)PIO_PORT_D)->PIO_PPDDR = 0xFFFFFFFFU;
    /* PORTD Output Write Enable */
    ((pio_registers_t*)PIO_PORT_D)->PIO_OWER = PIO_OWER_Msk;
    /* PORTD Output Direction Enable */
    ((pio_registers_t*)PIO_PORT_D)->PIO_OER = 0x0U;
    ((pio_registers_t*)PIO_PORT_D)->PIO_ODR = ~0x0U;
    /* Initialize PORTD pin state */
    ((pio_registers_t*)PIO_PORT_D)->PIO_ODSR = 0x0U;
    /* PORTD Slew rate control */
    ((pio_registers_t*)PIO_PORT_D)->PIO_SLEWR = 0x0U;
    /* PORTD drive control */
    ((pio_registers_t*)PIO_PORT_D)->PIO_DRIVER = 0x0U;

    uint32_t i;
    /* Initialize Interrupt Pin data structures */
    portPinCbObj[0 + 0].pin = PIO_PIN_PC17;
    
    for(i=0U; i<1U; i++)
    {
        portPinCbObj[i].callback = NULL;
    }
}

// *****************************************************************************
// *****************************************************************************
// Section: PIO APIs which operates on multiple pins of a port
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    uint32_t PIO_PortRead ( PIO_PORT port )

  Summary:
    Read all the I/O lines of the selected port.

  Description:
    This function reads the live data values on all the I/O lines of the
    selected port.  Bit values returned in each position indicate corresponding
    pin levels.
    1 = Pin is high.
    0 = Pin is low.

    This function reads the value regardless of pin configuration, whether it is
    set as as an input, driven by the PIO Controller, or driven by a peripheral.

  Remarks:
    If the port has less than 32-bits, unimplemented pins will read as
    low (0).
    Implemented pins are Right aligned in the 32-bit return value.
*/
uint32_t PIO_PortRead(PIO_PORT port)
{
    return ((pio_registers_t*)port)->PIO_PDSR;
}

// *****************************************************************************
/* Function:
    void PIO_PortWrite (PIO_PORT port, uint32_t mask, uint32_t value);

  Summary:
    Write the value on the masked I/O lines of the selected port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortWrite(PIO_PORT port, uint32_t mask, uint32_t value)
{
    ((pio_registers_t*)port)->PIO_ODSR = (((pio_registers_t*)port)->PIO_ODSR & (~mask)) | (mask & value);
}

// *****************************************************************************
/* Function:
    uint32_t PIO_PortLatchRead ( PIO_PORT port )

  Summary:
    Read the latched value on all the I/O lines of the selected port.

  Remarks:
    See plib_pio.h for more details.
*/
uint32_t PIO_PortLatchRead(PIO_PORT port)
{
    return (((pio_registers_t*)port)->PIO_ODSR);
}

// *****************************************************************************
/* Function:
    void PIO_PortSet ( PIO_PORT port, uint32_t mask )

  Summary:
    Set the selected IO pins of a port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortSet(PIO_PORT port, uint32_t mask)
{
    ((pio_registers_t*)port)->PIO_SODR = mask;
}

// *****************************************************************************
/* Function:
    void PIO_PortClear ( PIO_PORT port, uint32_t mask )

  Summary:
    Clear the selected IO pins of a port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortClear(PIO_PORT port, uint32_t mask)
{
    ((pio_registers_t*)port)->PIO_CODR = mask;
}

// *****************************************************************************
/* Function:
    void PIO_PortToggle ( PIO_PORT port, uint32_t mask )

  Summary:
    Toggles the selected IO pins of a port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortToggle(PIO_PORT port, uint32_t mask)
{
    /* Write into Clr and Set registers */
    ((pio_registers_t*)port)->PIO_ODSR^= mask;
}

// *****************************************************************************
/* Function:
    void PIO_PortInputEnable ( PIO_PORT port, uint32_t mask )

  Summary:
    Enables selected IO pins of a port as input.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortInputEnable(PIO_PORT port, uint32_t mask)
{
    ((pio_registers_t*)port)->PIO_ODR = mask;
}

// *****************************************************************************
/* Function:
    void PIO_PortOutputEnable ( PIO_PORT port, uint32_t mask )

  Summary:
    Enables selected IO pins of a port as output(s).

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortOutputEnable(PIO_PORT port, uint32_t mask)
{
    ((pio_registers_t*)port)->PIO_OER = mask;
}

// *****************************************************************************
/* Function:
    void PIO_PortInterruptEnable(PIO_PORT port, uint32_t mask)

  Summary:
    Enables IO interrupt on selected IO pins of a port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortInterruptEnable(PIO_PORT port, uint32_t mask)
{
    ((pio_registers_t*)port)->PIO_IER = mask;
}

// *****************************************************************************
/* Function:
    void PIO_PortInterruptDisable(PIO_PORT port, uint32_t mask)

  Summary:
    Disables IO interrupt on selected IO pins of a port.

  Remarks:
    See plib_pio.h for more details.
*/
void PIO_PortInterruptDisable(PIO_PORT port, uint32_t mask)
{
    ((pio_registers_t*)port)->PIO_IDR = mask;
}

// *****************************************************************************
// *****************************************************************************
// Section: PIO APIs which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    bool PIO_PinInterruptCallbackRegister(
        PIO_PIN pin,
        const PIO_PIN_CALLBACK callback,
        uintptr_t context
    );

  Summary:
    Allows application to register callback for configured pin.

  Remarks:
    See plib_pio.h for more details.
*/
bool PIO_PinInterruptCallbackRegister(
    PIO_PIN pin,
    const PIO_PIN_CALLBACK callback,
    uintptr_t context
)
{
    uint8_t i;
    uint8_t portIndex;

    portIndex = (uint8_t)pin >> 5U;

    for(i = portNumCb[portIndex]; i < portNumCb[portIndex +1U]; i++)
    {
        if (portPinCbObj[i].pin == pin)
        {
            portPinCbObj[i].callback = callback;
            portPinCbObj[i].context  = context;
            return true;
        }
    }
    return false;
}
// *****************************************************************************
// *****************************************************************************
// Section: Local Function Implementation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PIO_Interrupt_Handler ( PIO_PORT port )

  Summary:
    Interrupt handler for a selected port.

  Description:
    This function defines the Interrupt handler for a selected port.

  Remarks:
    It is an internal function used by the library, user should not call it.
*/
void __attribute__((used)) PIO_Interrupt_Handler ( PIO_PORT port )
{
    uint32_t status;
    uint32_t i, portIndex;
    PIO_PIN pin;
    uintptr_t context;

    status  = ((pio_registers_t*)port)->PIO_ISR;
    status &= ((pio_registers_t*)port)->PIO_IMR;

    /* get the index of the port channel: PIO_PORT_A--> 0, PIO_PORT_B--> 1 ... */
    portIndex = (port - PIOA_BASE_ADDRESS) >> 9U;

    /* Check pending events and call callback if registered */
    for(i = portNumCb[portIndex]; i < portNumCb[portIndex +1U]; i++)
    {
        pin = portPinCbObj[i].pin;

        if((portPinCbObj[i].callback != NULL) && ((status & (1UL << (pin & 0x1FU))) != 0U))
        {
            context = portPinCbObj[i].context;
            portPinCbObj[i].callback (pin, context);
        }
    }

}
// *****************************************************************************
// *****************************************************************************
// Section: Interrupt Service Routine (ISR) Implementation(s)
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PIOC_InterruptHandler (void)

  Summary:
    Interrupt handler for PORTC.

  Description:
    This function defines the Interrupt service routine for PORTC.
    This is the function which by default gets into Interrupt Vector Table.

  Remarks:
    User should not call this function.
*/
void __attribute__((used)) PIOC_InterruptHandler(void)
{
    /* Local PIO Interrupt Handler */
    PIO_Interrupt_Handler(PIO_PORT_C);
}






/*******************************************************************************
 End of File
*/
