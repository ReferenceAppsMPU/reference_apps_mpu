/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ulp0.c

  Description:
    This file contains the "bsr" Backup self refresh low power mode  function for 
    a project.
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

void enter_bsr_mode(void)
{
  /* Save somthing in backup registers */ 
  SYSCWP_REGS->SYSCWP_SYSC_WPMR= SYSCWP_SYSC_WPMR_WPKEY_PASSWD;
  
  GPBR_REGS->GPBR_FCLR = GPBR_FCLR_FCLR(1);     // Full Clear SYS_GPBRx
  
  printf("\n\r  =========== WRITE GPBR ================\n\r");
  /* Write Backup Register  */
  GPBR_REGS->SYS_GPBR[0] = 0xDEADBEEF;
  GPBR_REGS->SYS_GPBR[1] = 0xDEADBEEF;
  
  /* Write random data to ddr */
  volatile unsigned int *pt_ddrbank_32b = (volatile unsigned int *)(0x60001000);
  for( int ddr_reg = 0; ddr_reg < 32; ddr_reg++)
  {
    *pt_ddrbank_32b = ( 0xA1000000 );
    pt_ddrbank_32b++;
  }

  /*Configure WKPU interrupt(connected to pin A8 / WKPU0) as the wake-up source*/
  configure_wkup0_interrupt();

  /* Enter Selfrefresh */
  enter_selfrefresh_ddr_io_powerdown();
 
  
  printf( " BSR Entering \n\r");

  /* Disable SYSC write protection */
  SYSCWP_REGS->SYSCWP_SYSC_WPMR = SYSCWP_SYSC_WPMR_WPKEY_PASSWD;  
  
  /* Clear SHDC control Register */
  SHDWC_REGS->SHDW_CR = SHDW_CR_KEY_PASSWD;

  /* Enter Backup Self Refresh mode  */
  SHDWC_REGS->SHDW_CR = SHDW_CR_KEY_PASSWD | SHDW_CR_SHDW_1 | SHDW_CR_LPMEN_1;

  /* Exit backup self refresh mode*/ 
  while(1);
  /*check backup register  and Calib data at Power up */ 
}

void enter_selfrefresh_ddr_io_powerdown(void)
{

    /* 1. Save the first eight 32-bit SDRAM words in the backup SRAM */
    volatile unsigned int * pt_regbank_32b = (volatile unsigned int *)(REGBANK_BASE);
    volatile unsigned int *pt_ddrbank_32b1 = (volatile unsigned int *)(0x60000000);
    for(int i=0; i<=4; i++)
    {
      *pt_regbank_32b = *pt_ddrbank_32b1;
      pt_regbank_32b++;
      pt_ddrbank_32b1++;
    }

    /* 2. save current calibation data in the backup SRAM*/
    *pt_regbank_32b = DDRPUBL_REGS->DDR3PHY_ZQ0SR0 & 0x0FFFFFFF;
    printf(" DDR Calib Data 0x%X @ 0x%X \n\r",  *pt_regbank_32b, pt_regbank_32b);


    /* 3.Set the static values for DDR_CLK and DDR_CLKN to 0,0 when the pair is disabled*/
    DDRPUBL_REGS->DDR3PHY_PGCR &= ~DDR3PHY_PGCR_CKDV(0);

    /* 4. DSB */
    __DSB();

    /* 5. Disable all UDDRC ports */
    DDRUMCTL_REGS->UDDRC_PCTRL_0 = 0; /* disable port */
    DDRUMCTL_REGS->UDDRC_PCTRL_1 = 0; /* disable port */
    DDRUMCTL_REGS->UDDRC_PCTRL_2 = 0; /* disable port */
    DDRUMCTL_REGS->UDDRC_PCTRL_3 = 0; /* disable port */ 
    DDRUMCTL_REGS->UDDRC_PCTRL_4 = 0; /* disable port */

    // Waits until all AXI ports are idle
    while (DDRUMCTL_REGS->UDDRC_PSTAT &
         UDDRC_PSTAT_RD_PORT_BUSY_0_Msk &
         UDDRC_PSTAT_WR_PORT_BUSY_0_Msk &
         UDDRC_PSTAT_RD_PORT_BUSY_1_Msk &
         UDDRC_PSTAT_WR_PORT_BUSY_1_Msk &
         UDDRC_PSTAT_RD_PORT_BUSY_2_Msk &
         UDDRC_PSTAT_WR_PORT_BUSY_2_Msk &
         UDDRC_PSTAT_RD_PORT_BUSY_3_Msk &
         UDDRC_PSTAT_WR_PORT_BUSY_3_Msk &
         UDDRC_PSTAT_RD_PORT_BUSY_4_Msk &
         UDDRC_PSTAT_WR_PORT_BUSY_4_Msk);

    /* 6. Enter self‑refresh */
    DDRUMCTL_REGS->UDDRC_PWRCTL |= UDDRC_PWRCTL_SELFREF_SW_Msk;

    /* Waits until Self Refresh state is entered */
    while ((DDRUMCTL_REGS->UDDRC_STAT & UDDRC_STAT_SELFREF_TYPE_Msk) !=
         (0x2 << UDDRC_STAT_SELFREF_TYPE_Pos));

    /* 7. Power down DDR3PHY data receivers */
    DDRPUBL_REGS->DDR3PHY_PIR |= DDR3PHY_PIR_DLLBYP_Msk;
    DDRPUBL_REGS->DDR3PHY_DXCCR  |= DDR3PHY_DXCCR_DXPDR_Msk;

    /* 8–9. Power down clock, CS, address, ODT drivers */
    DDRPUBL_REGS->DDR3PHY_ACIOCR |= (DDR3PHY_ACIOCR_ACPDD_Msk | DDR3PHY_ACIOCR_CKPDD(1) | DDR3PHY_ACIOCR_CSPDD(1));
    DDRPUBL_REGS->DDR3PHY_DSGCR  |= DDR3PHY_DSGCR_ODTPDD(1);

    /* 10. Set SDRAM I/Os to retention */
    SFRBU_REGS->SFRBU_DDRPWR = SFRBU_DDRPWR_RETENTION(1);
    while ((SFRBU_REGS->SFRBU_DDRPWR & SFRBU_DDRPWR_Msk) != SFRBU_DDRPWR_RETENTION(1));

}

void test_bsr_mode(void)
{
  /*Read Backup Register to test the Backup Mode */
  printf("\n\r SYS_GPBR[0]= 0x%x  SYS_GPBR[1]= 0x%x \n ",GPBR_REGS->SYS_GPBR[0], GPBR_REGS->SYS_GPBR[1]);
  volatile unsigned int *pt_regbank_32b = (volatile unsigned int *)(0xE0001414);
  printf(" DDR Calib Data 0x%X @ 0x%X \n\r",  *pt_regbank_32b, pt_regbank_32b);
  /* verfiry_ddr_bank_after_refresh */
  volatile unsigned int *pt_ddrbank_32b = (volatile unsigned int *)(0x60001000);
  printf( "Validating DDR data after Backup with SR wakeup \n\r");
  for( int ddr_reg = 0; ddr_reg < 32; ddr_reg++)
  {
    if( *pt_ddrbank_32b != ( 0xA1000000 ) )
    {
      printf( "Expected -> 0x%X, Actual -> 0x%X \n\r", ( 0xA1000000 + ddr_reg ), *pt_ddrbank_32b );
    }
    else if(ddr_reg==31)
    { 
       printf( "DDR Verified successfully");
    };
  }
  
}
