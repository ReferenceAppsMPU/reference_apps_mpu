/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    idle.c

  Description:
    This file contains the "idle" low power mode function for a project. 
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2021 Microchip Technology Inc. and its subsidiaries.
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
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <app.h> 

void enter_idle_mode(void)
{
  /* disbale PIT since we don't want it as a wake-up source */
  PIT64B0_TimerStop();
  
  /*Configure WKPU interrupt(connected to pin A8 / WKPU0) as the wake-up source*/
  configure_wkup0_interrupt();


  /* The processor is placed in Wait-For-Interrupt (WFI) state(CPU clock will be diasbled when WFI instruction is executed)
    Press "WKPU switch on the curiosity board to exit the Idle Mode" */
  asm("dsb" ::: "memory");
  asm("wfi" ::: "memory");

  printf("Leaving Idle Mode\n\r \n\r");
  
  /* enable PIT */
  PIT64B0_TimerStart();


}