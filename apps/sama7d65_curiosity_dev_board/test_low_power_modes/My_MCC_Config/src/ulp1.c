/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ulp1.c

  Description:
    This file contains the "ulp1" ultra low power mode 1 function for a project.
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
// ****************************************************************************
// *****************************************************************************
#include <app.h> 

void really_enter_ulp1_sram(void);
static void exit_selfrefresh_ddr (void);
static void enter_selfrefresh_ddr (void);
static void configure_wkup_rtc_interrupt(void);
static void configure_wkup_rtc_interrupt(void)
{
  struct tm time;


  __disable_irq();
  /*  Clear Interrupt*/
  SHDWC_REGS->SHDW_SR;
  SHDWC_REGS->SHDW_ISR;

  SYSCWP_REGS->SYSCWP_SYSC_WPMR = SYSCWP_SYSC_WPMR_WPKEY_PASSWD | SYSCWP_SYSC_WPMR_WPEN_0 ;
  SHDWC_REGS->SHDW_MR = SHDW_MR_RTCWKEN_1_Val;
  
  /* Set RTC alarm for fast wakeup */
  PMC_REGS->PMC_WPMR = PMC_WPMR_WPEN_0 | PMC_WPMR_WPKEY_PASSWD;
  PMC_REGS->PMC_FSMR = PMC_FSMR_RTCAL_1; 

  __enable_irq();

  /* configure RTC alarm */
  RTC_TimeGet(&time);
  time.tm_sec += 15;
  time.tm_sec = time.tm_sec % 60;

  RTC_AlarmSet(&time, RTC_ALARM_MASK_SS);
 // RTC_InterruptEnable(RTC_INT_ALARM);
}
void enter_ulp1_mode(void);
__attribute__((__section__(".ramdata_section"))) int tmp1_stack[256];
void  enter_ulp1_mode(void)
{
    /* Configure wakeup interrupt*/
    configure_wkup_rtc_interrupt();

    /* set up new stack in sram since ddr will be unavailable */
    uint32_t sp = (uint32_t)&tmp1_stack[256];
    asm("mov r3, %0" : : "r"(sp));
    asm("mov r0, sp");
    asm("mov sp, r3");
    asm("push {r0}");

    /* broken up like this so we can use stack variables */
    really_enter_ulp1_sram();


    /* use original ddr based stack */
    asm("pop {r0}");
    asm("mov sp, r0");
}

__attribute__((__section__(".ramcode_section"))) void really_enter_ulp1_sram(void)
{
    struct clock_cfg {
        uint32_t scsr;
        uint32_t mckr;
        uint32_t mor;
        uint32_t pcr[200];
        uint32_t pll_sys_backup;
        uint32_t pll_ddr_backup;
    } clock_cfg;
    clock_cfg.scsr = PMC_REGS->PMC_SCSR;
    
    clock_cfg.mckr = PMC_REGS->PMC_MCR;
    clock_cfg.mor = PMC_REGS->CKGR_MOR;

    /*1. Set SDRAM Self-refresh Mode */
    enter_selfrefresh_ddr();

    /* 2. Clear all pending events */
    asm("wfe");
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    
    
    /* 3. Enable RTC interrupt*/
    RTC_REGS->RTC_IER = (uint32_t)RTC_INT_ALARM;
    
    /* 4. Suspend USB ports 0, 1 and 2.*/
    SFR_REGS->SFR_WPMR = SFR_WPMR_WPKEY_PASSWD | SFR_WPMR_WPEN_0;
    SFR_REGS->SFR_OHCIICR = ( SFR_OHCIICR_SUSPEND0_1 | SFR_OHCIICR_SUSPEND1_1 | SFR_OHCIICR_SUSPEND2_1 );

    /*5. Disable all GCLK peripheral clocks. */
    for( int i=0; i < 200; i++ )
    {
      /* Write PID, CMD = 0 (read access) */
      PMC_REGS->PMC_PCR = PMC_PCR_PID(i);
      /* Read back the register */
      clock_cfg.pcr[i]= PMC_REGS->PMC_PCR;
    }
    for( int i=0; i < 200; i++ )
    {
      unsigned int pcr=clock_cfg.pcr[i];
  
      /* Clear peripheral clock enable ONLY */
      pcr &= ~PMC_PCR_EN_Msk;
    
      /* Clear Generic clock enable ONLY */
      pcr &= ~PMC_PCR_GCLKEN_Msk;

      /* Prepare write command */
      pcr &= ~PMC_PCR_PID_Msk;       /* Clear old PID */
      pcr |= PMC_PCR_PID(i);       /* Restore PID */
      pcr |= PMC_PCR_CMD_1;          /* Write mode */

      /* Write back */
      PMC_REGS->PMC_PCR = pcr;
    }

    /* 6. Disable PMC protection. */
    PMC_REGS->PMC_WPMR = PMC_WPMR_WPKEY_PASSWD;

    /* 7. Switch MCK0 to MAINCK  aand  8. Set MDIV = 1 for MCK0 */
    // Clear the current CSS and MDIV fields, then apply MAIN_CLK and MDIV(1)
    PMC_REGS->PMC_CPU_CKR = (PMC_REGS->PMC_CPU_CKR & ~(PMC_CPU_CKR_CSS_Msk | PMC_CPU_CKR_MDIV_Msk))
                       | PMC_CPU_CKR_CSS_MAIN_CLK
                       | PMC_CPU_CKR_MDIV(1);
    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) == 0U);

    /* 9 &10. Switch MCK1..MCK9 to MAINCK and MDIV=1 */
    for (uint32_t mck_id = 1; mck_id <= 9; mck_id++)
    {
       PMC_REGS->PMC_MCR = PMC_MCR_CMD_1
                          | PMC_MCR_ID(mck_id)
                          | PMC_MCR_CSS_MAINCK
                          | PMC_MCR_DIV(1)
                          | PMC_MCR_EN_Msk;

        while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) == 0U);
    }

    /*  11. Turn off all eight PLLs */
    for(int pll_id = 0; pll_id <= 8; pll_id++ )
    {
       PMC_REGS->PMC_PLL_UPDT = PMC_PLL_UPDT_ID(pll_id) | PMC_PLL_UPDT_UPDATE(1);
       PMC_REGS->PMC_PLL_CTRL0 = PMC_REGS->PMC_PLL_CTRL0 & ~PMC_PLL_CTRL0_ENPLL_1;
       PMC_REGS->PMC_PLL_UPDT = PMC_PLL_UPDT_ID(pll_id) | PMC_PLL_UPDT_UPDATE_Msk;
    }

    /* 12. Turn on the Main RC */
    PMC_REGS->CKGR_MOR |= CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCRCEN_Msk;
    while ((PMC_REGS->PMC_SR & PMC_SR_MOSCRCS_Msk) == 0U);

    /* 13. Switch MAINCK to Main RC */
    PMC_REGS->CKGR_MOR = (PMC_REGS->CKGR_MOR) | CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCRCEN(1);
    //Wait the Main RC to stabilize
    while (!(PMC_REGS->PMC_SR & PMC_SR_MOSCRCS(1)));

    /* 14. Turn off the Main Crystal Oscillator */
    PMC_REGS->CKGR_MOR = ((PMC_REGS->CKGR_MOR) | CKGR_MOR_KEY_PASSWD) & ~CKGR_MOR_MOSCXTEN(1);

    /*15. Disable SHDWC / SYSC write protection */
    SYSCWP_REGS->SYSCWP_SYSC_WPMR = SYSCWP_SYSC_WPMR_WPKEY_PASSWD;  
    SHDWC_REGS->SHDW_CR = SHDW_CR_KEY_PASSWD;

    /* 16. Configure wake-up event - Done in step3 */
   

    /* 17. Enter ULP1 mode */
    PMC_REGS->CKGR_MOR |= CKGR_MOR_ULP1_1 | CKGR_MOR_KEY_PASSWD;


    /* Exit ULP1 after 15 seconds */
    PMC_REGS->CKGR_MOR = clock_cfg.mor |  CKGR_MOR_KEY_PASSWD | CKGR_MOR_KEY_Msk;
    if (clock_cfg.mor & CKGR_MOR_MOSCSEL_Msk)
        while (!(PMC_REGS->PMC_SR & PMC_SR_MOSCXTS_Msk));

    /* wait for pll lock */
    while (!(PMC_REGS->PMC_SR & PMC_SR_PLL_INT_Msk));

    /* switch master clock to pll */
    PMC_REGS->PMC_MCR = clock_cfg.mckr;
    while (!(PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk));

    PMC_REGS->PMC_SCER = clock_cfg.scsr;
    /* 1. Start up the Main Crystal Oscillator */
    PMC_REGS->CKGR_MOR |= CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCXTEN_Msk;    
    while (!(PMC_REGS->PMC_SR & PMC_SR_MOSCXTS_Msk));

    /* 2. Switch MAINCK to Main Crystal Oscillator */
    PMC_REGS->CKGR_MOR |= (CKGR_MOR_KEY_PASSWD | CKGR_MOR_MOSCSEL_Msk);    
    while (!(PMC_REGS->PMC_SR & PMC_SR_MOSCSELS_Msk));

    /* 3 & 4. Switch MCK0 to MAINCK and set MDIV to 1 */
    PMC_REGS->PMC_CPU_CKR = (PMC_REGS->PMC_CPU_CKR & ~(PMC_CPU_CKR_CSS_Msk | PMC_CPU_CKR_MDIV_Msk))
                       | PMC_CPU_CKR_CSS_MAIN_CLK  | PMC_CPU_CKR_MDIV(1);
    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) == 0U);

    /* 5. Start up CPUPLL (PLL ID 0) */
    PMC_REGS->PMC_PLL_UPDT = PMC_PLL_UPDT_ID(0);
    PMC_REGS->PMC_PLL_CTRL0 |= PMC_PLL_CTRL0_ENPLL_Msk;
    
    PMC_REGS->PMC_PLL_UPDT = PMC_PLL_UPDT_ID(0) | PMC_PLL_UPDT_UPDATE_Msk;
    while (!(PMC_REGS->PMC_PLL_ISR0 & (PMC_PLL_ISR0_LOCK0_Msk)));

    /* 6. Switch MCK0 to CPUPLL with MDIV set to 3 */
    PMC_REGS->PMC_CPU_CKR = (PMC_REGS->PMC_CPU_CKR & ~(PMC_CPU_CKR_CSS_Msk | PMC_CPU_CKR_MDIV_Msk))
                  | PMC_CPU_CKR_CSS_CPUPLLCK   | PMC_CPU_CKR_MDIV(3);
                       
    while (!(PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk));

    /* 7. Start up SYSPLL (400 MHz) (PLL ID 1) */
    PMC_REGS->PMC_PLL_UPDT = PMC_PLL_UPDT_ID(1);
    
    PMC_REGS->PMC_PLL_CTRL1 = /* 400MHz MULT */ 0;
    PMC_REGS->PMC_PLL_CTRL0 = PMC_PLL_CTRL0_ENPLL_Msk | /* 400MHz DIV */ 0;
    
    PMC_REGS->PMC_PLL_UPDT = PMC_PLL_UPDT_ID(1) | PMC_PLL_UPDT_UPDATE_Msk; // PLL_ID_SYSPLL is 1
    while (!(PMC_REGS->PMC_PLL_ISR0 & PMC_PLL_ISR0_LOCK1_Msk));

    /* 8. Switch MCK1 to SYSPLL with MDIV set to 2 */
    PMC_REGS->PMC_MCR = PMC_MCR_CMD_1
                          | PMC_MCR_ID(1)
                          | PMC_MCR_CSS_SYSPLL
                          | PMC_MCR_DIV(2)
                          | PMC_MCR_EN_Msk;

    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) == 0U);

    /* 9. Switch MCK4 to SYSPLL with MDIV set to 1 */
    PMC_REGS->PMC_MCR = PMC_MCR_CMD_1
                          | PMC_MCR_ID(4)
                          | PMC_MCR_CSS_SYSPLL
                          | PMC_MCR_DIV(1)
                          | PMC_MCR_EN_Msk;

    while ((PMC_REGS->PMC_SR & PMC_SR_MCKRDY_Msk) == 0U);

    /* 10. Start up DDRPLL (533 MHz) (PLL ID 2) */
    PMC_REGS->PMC_PLL_UPDT = PMC_PLL_UPDT_ID(2);
    
    PMC_REGS->PMC_PLL_CTRL1 = /* 533MHz MULT */ 0;
    PMC_REGS->PMC_PLL_CTRL0 = PMC_PLL_CTRL0_ENPLL_Msk | /* 533MHz DIV */ 0;
    
    PMC_REGS->PMC_PLL_UPDT = PMC_PLL_UPDT_ID(2) | PMC_PLL_UPDT_UPDATE_Msk; //PLL_ID_DDRPLL is 2
    while (!(PMC_REGS->PMC_PLL_ISR0 & PMC_PLL_ISR0_LOCK2_Msk)); //1 << PLL_ID_DDRPLL


    /* Restore Peripheral and Generic Clock*/
    for(int i=0; i<200; i++)
    {
      clock_cfg.pcr[i] |= PMC_PCR_CMD_1;          /* Write mode */
      PMC_REGS->PMC_PCR =  clock_cfg.pcr[i];
    }
    exit_selfrefresh_ddr();

    asm("cpsie if");
}

__attribute__((__section__(".ramcode_section")))  static void enter_selfrefresh_ddr(void)
{

  /* DSB */
  __DSB();

  /* Blocks AXI ports from taking anymore transactions */
  DDRUMCTL_REGS->UDDRC_PCTRL_0 = 0; /* disable port */
  DDRUMCTL_REGS->UDDRC_PCTRL_1 = 0; /* disable port */
  DDRUMCTL_REGS->UDDRC_PCTRL_2 = 0; /* disable port */  
  DDRUMCTL_REGS->UDDRC_PCTRL_3 = 0; /* disable port */
  DDRUMCTL_REGS->UDDRC_PCTRL_4 = 0; /* disable port */

  /* Waits until all AXI ports are idle */
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

  /* Causes system to move to Self Refresh state */
  DDRUMCTL_REGS->UDDRC_PWRCTL |= UDDRC_PWRCTL_SELFREF_SW_Msk;

  /* Waits until Self Refresh state is entered */
  while ((DDRUMCTL_REGS->UDDRC_STAT & UDDRC_STAT_SELFREF_TYPE_Msk) !=
         (0x2 << UDDRC_STAT_SELFREF_TYPE_Pos));

  /* Bypass the DLLs */
  DDRPUBL_REGS->DDR3PHY_PIR |= DDR3PHY_PIR_DLLBYP_Msk;

  /* Enable power-down of the data IO's receiver */
  DDRPUBL_REGS->DDR3PHY_DXCCR  |= DDR3PHY_DXCCR_DXPDR_Msk;
  /* Enable power-down of the ADDR/CMD IO's driver */
  DDRPUBL_REGS->DDR3PHY_ACIOCR |= (DDR3PHY_ACIOCR_ACPDD_Msk | DDR3PHY_ACIOCR_CKPDD(1) | DDR3PHY_ACIOCR_CSPDD(1));
  /* Enable power-down of the ODT IO's driver */
  DDRPUBL_REGS->DDR3PHY_DSGCR  |= DDR3PHY_DSGCR_ODTPDD(1);

}

__attribute__((__section__(".ramcode_section")))  static void exit_selfrefresh_ddr (void)
{

  /* Disable power-down of the data IO's receiver */
  DDRPUBL_REGS->DDR3PHY_DXCCR  &= ~DDR3PHY_DXCCR_DXPDR_Msk;  
  /* Disable power-down of the ADDR/CMD IO's driver */
  DDRPUBL_REGS->DDR3PHY_ACIOCR &= ~(DDR3PHY_ACIOCR_ACPDD_Msk | DDR3PHY_ACIOCR_CKPDD(1) | DDR3PHY_ACIOCR_CSPDD(1));
  /* Disable power-down of the ODT IO's driver */
  DDRPUBL_REGS->DDR3PHY_DSGCR  &= ~DDR3PHY_DSGCR_ODTPDD(1);

  /* Release bypass of DLLs */
  DDRPUBL_REGS->DDR3PHY_PIR &= ~DDR3PHY_PIR_DLLBYP_Msk;

  /* Wait for DLL lock then reset ITMs */
  DDRUMCTL_REGS->UDDRC_SWCTL = 0; 
  DDRUMCTL_REGS->UDDRC_DFIMISC &= ~UDDRC_DFIMISC_DFI_INIT_COMPLETE_EN_Msk;
  DDRUMCTL_REGS->UDDRC_SWCTL = UDDRC_SWCTL_SW_DONE_Msk;
  while (DDRUMCTL_REGS->UDDRC_SWSTAT != UDDRC_SWSTAT_SW_DONE_ACK_Msk);
  
  /*DLL SRST is mandatory in top of DLL lock and ITM SRST */
  DDRPUBL_REGS->DDR3PHY_PIR = DDR3PHY_PIR_INIT_Msk | DDR3PHY_PIR_DLLSRST_Msk | DDR3PHY_PIR_DLLLOCK_Msk | DDR3PHY_PIR_ITMSRST_Msk;
  while ((DDRPUBL_REGS->DDR3PHY_PGSR & DDR3PHY_PGSR_IDONE_Msk) != DDR3PHY_PGSR_IDONE_Msk);

  DDRUMCTL_REGS->UDDRC_SWCTL = 0;  // Enable quasi-dynamic register programming outside reset.
  DDRUMCTL_REGS->UDDRC_DFIMISC |=  UDDRC_DFIMISC_DFI_INIT_COMPLETE_EN_Msk;
  DDRUMCTL_REGS->UDDRC_SWCTL = UDDRC_SWCTL_SW_DONE_Msk;
  while (DDRUMCTL_REGS->UDDRC_SWSTAT != UDDRC_SWSTAT_SW_DONE_ACK_Msk);

  /*Trigger self-refresh exit*/
  DDRUMCTL_REGS->UDDRC_PWRCTL &= ~UDDRC_PWRCTL_SELFREF_SW_Msk;

  /* Waits until Self Refresh state is exited */
  while ((DDRUMCTL_REGS->UDDRC_STAT & UDDRC_STAT_OPERATING_MODE_Msk) != (0x1 << UDDRC_STAT_OPERATING_MODE_Pos));

  /* AXI ports no longer block from taking transactions */
  DDRUMCTL_REGS->UDDRC_PCTRL_0 = 1; // enable port
  DDRUMCTL_REGS->UDDRC_PCTRL_1 = 1; // enable port
  DDRUMCTL_REGS->UDDRC_PCTRL_2 = 1; // enable port
  DDRUMCTL_REGS->UDDRC_PCTRL_3 = 1; // enable port
  DDRUMCTL_REGS->UDDRC_PCTRL_4 = 1; // enable port

  /* DSB */
  __DSB();

}

