/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    backup.c


  Description:
    This file contains the "backup" backup power mode function for a project.
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

void enter_backup_mode(void)
{
  /*Configure WKPU interrupt(connected to pin A8 / WKPU0) as the wake-up source*/
  configure_wkup0_interrupt();

  /*Write Backup Register to test the Backup Mode */
  /* Write enable*/
  SYSCWP_REGS->SYSCWP_SYSC_WPMR = SYSCWP_SYSC_WPMR_WPKEY_PASSWD;
  /*  Full Clear SYS_GPBRx */
  GPBR_REGS->GPBR_FCLR = GPBR_FCLR_FCLR(1);    
  
  printf("\n\r  =========== WRITE GPBR ================\n\r");
  /*Write Backup Register to test the Backup Mode */
  GPBR_REGS->SYS_GPBR[0] = 0x01234567;
  GPBR_REGS->SYS_GPBR[1] = 0x01234567;
  /* Check Backup once */
  for(int i = 0; i<2 ; i++)
  {
    if(GPBR_REGS->SYS_GPBR[i] != 0x01234567)
    {
      printf("  =========== ERROR READING GPBR ================\n\r");
    }
  }
  /*enter Backup mode*/ 
  SHDWC_REGS->SHDW_CR = SHDW_CR_KEY_PASSWD | SHDW_CR_SHDW_1 ;

  // exit backup mode
  while(1);
  // check backup register after ROMBOOT

}

void test_backup_mode(void)
{
   /*Read Backup Register to test the Backup Mode */
  printf("\n\r SYS_GPBR[0]= 0x%x  SYS_GPBR[1]= 0x%x \n ",GPBR_REGS->SYS_GPBR[0], GPBR_REGS->SYS_GPBR[1]);
}
