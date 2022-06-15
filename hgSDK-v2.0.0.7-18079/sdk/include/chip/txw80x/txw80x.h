#ifndef _TXW80X_DEF_H_
#define _TXW80X_DEF_H_

#ifdef __cplusplus
 extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "typesdef.h"

/* -------------------------  Interrupt Number Definition  ------------------------ */

enum IRQn
{
/******  Peripheral Interrupt Numbers *********************************************************/
    USB20DMA_IRQn               = 0,
    USB20MC_IRQn                = 1,
    UART0_IRQn                  = 2,
    UART1_IRQn                  = 3,
    UART2_IRQn                  = 4,
    QSPI_IRQn                   = 5,
    SPI0_IRQn                   = 6,
    SPI1_IRQn                   = 7,
    SPI2_IRQn                   = 8,
    SPI3_IRQn                   = 9,
    TIM0_IRQn                   = 10,
    TIM1_IRQn                   = 11,
    TIM2_IRQn                   = 12,
    TIM3_IRQn                   = 13,
    TIM4_IRQn                   = 14,
//    TIM5_IRQn                   = 15,
//    TIM6_IRQn                   = 16,
//    TIM7_IRQn                   = 17,
    SUPTMR0_IRQn                = 15,
    SUPTMR1_IRQn                = 16,
    SUPTMR2_IRQn                = 17,
    SDIO_IRQn                   = 18,
    SDIO_RST_IRQn               = 19,
    SDHOST_IRQn                 = 20,
    LMAC_IRQn                   = 21,
    GMAC_IRQn                   = 22,
    M2M0_IRQn                   = 23,
    M2M1_IRQn                   = 24,
    CORET_IRQn                  = 25, //CPU TIMER
    SYSAES_IRQn                 = 26, 
    CRC_IRQn                    = 27,
    ADKEY_IRQn                  = 28,
    PD_TMR_IRQn                 = 29,
    WKPND_IRQn                  = 30,
    PDWKPND_IRQn                = 31,
    LVD_IRQn                    = 32,
    WDT_IRQn                    = 33,
    SYS_ERR_IRQn                = 34,
    IIS0_IRQn                   = 35,
    IIS1_IRQn                   = 36,
    GPIOA_IRQn                  = 37,
    GPIOB_IRQn                  = 38,
    DVP_IRQn                    = 39,
    JPG_IRQn                    = 40,
    STMR0_IRQn                  = 41,
    STMR1_IRQn                  = 42,
    STMR2_IRQn                  = 43,
    STMR3_IRQn                  = 44,
    PDM_IRQn                    = 45,
    GPIOC_IRQn                  = 46,
    UART4_IRQn                  = 47,
    GFSK_IRQn                   = 48,
    CMP_IRQn                    = 49,
    UART5_IRQn                  = 50,
    SPI5_IRQn                   = 51,
    SPI6_IRQn                   = 52,
    ADKEY1_IRQn                 = 53,
    LED_IRQn                    = 54,
    SUPTMR3_IRQn                = 55,
    SUPTMR4_IRQn                = 56,
    SUPTMR5_IRQn                = 57,
    USB20PHY_IRQn               = 58,
    TK_IRQn                     = 59,
    LEDTMR0_IRQn                = 60,
    LEDTMR1_IRQn                = 61,
    LEDTMR2_IRQn                = 62,
    LEDTMR3_IRQn                = 63,
    IRQ_NUM,
} IRQn_Type;

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* --------  Configuration of the CK803 Processor and Core Peripherals  ------- */
#define __CK803_REV               0x0000U   /* Core revision r0p0 */
#define __MPU_PRESENT             0         /* MGU present or not */
#define __VIC_PRIO_BITS           2         /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0         /* Set to 1 if different SysTick Config is used */

#include "csi_core.h"                     /* Processor and core peripherals */
#include "stdint.h"

////////

/** @addtogroup Peripheral_registers_structures
  * @{
  */

/**
  * @brief Serial Peripheral Interface
  */
typedef struct {
    __IO uint32_t CON0;
    __IO uint32_t CON1;
    __IO uint32_t CMD_DATA;
    __IO uint32_t BAUD;
    __IO uint32_t TDMALEN;
    __IO uint32_t RDMALEN;
    __IO uint32_t TDMACNT;
    __IO uint32_t RDMACNT;
    __IO uint32_t TSTADR;
    __IO uint32_t RSTADR;
    __IO uint32_t STA;
    __IO uint32_t SLAVESTA;
} SPI_I2C_TypeDef;

/**
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
    
typedef struct {
    __IO uint32_t CON;
    __IO uint32_t BAUD;
    __IO uint32_t DATA;
    __IO uint32_t STA;
    __IO uint32_t TSTADR;
    __IO uint32_t RSTADR;
    __IO uint32_t TDMALEN;
    __IO uint32_t RDMALEN;
    __IO uint32_t TDMACNT;
    __IO uint32_t RDMACNT;
    __IO uint32_t DMACON;
    __IO uint32_t DMASTA;
    __IO uint32_t RS485_CON;
    __IO uint32_t RS485_DET;
    __IO uint32_t RS485_TAT;
    __IO uint32_t TOCON;
} UART_TypeDef;


/**
  * @brief Serial Peripheral Interface
  */
/**
  * @brief WDT
  */

typedef struct
{
    __IO uint32 WDTCON;
    __IO uint32 WDTKEY;
} WDT_TypeDef;

/**
  * @brief RTC
  */

/**
  * @brief ADKEY
  */
#if 0
typedef struct
{
    __IO uint32 ADKEY_CON;
    __IO uint32 ADKEY_BAUD;
    __IO uint32 ADKEY_DATA;
} ADKEY_TypeDef;
#endif
/**
  * @brief USB1.1
  */
typedef struct
{
    /* SIE common reg : 0x0 ~ 0xf */
    __IO uint8_t  SIEM_FADDR;
    __IO uint8_t  SIEM_POWER;
    __IO uint8_t  SIEM_INTRTX1;
    __IO uint8_t  SIEM_INTRTX2;
    __IO uint8_t  SIEM_INTRRX1;
    __IO uint8_t  SIEM_INTRRX2;
    __IO uint8_t  SIEM_INTRUSB;
    __IO uint8_t  SIEM_INTRTX1E;
    __IO uint8_t  SIEM_INTRTX2E;
    __IO uint8_t  SIEM_INTRRX1E;
    __IO uint8_t  SIEM_INTRRX2E;
    __IO uint8_t  SIEM_INTRUSBE;
    __IO uint8_t  SIEM_FRAMENUM1;
    __IO uint8_t  SIEM_FRAMENUM2;
    __IO uint8_t  SIEM_INDEX;
    __IO uint8_t  SIEM_DEVCTL;

    /* SIE indexed reg : 0x10 ~ 0x1f */
    __IO uint8_t  SIEM_TXMAXP;
    __IO uint8_t  SIEM_TXCSR1;
    __IO uint8_t  SIEM_TXCSR2;
    __IO uint8_t  SIEM_RXMAXP;
    __IO uint8_t  SIEM_RXCSR1;
    __IO uint8_t  SIEM_RXCSR2;
    __IO uint8_t  SIEM_RXCOUNT1;
    __IO uint8_t  SIEM_RXCOUNT2;
    __IO uint8_t  SIEM_TXTYPE;
    __IO uint8_t  SIEM_TXINTERVAL;
    __IO uint8_t  SIEM_RXTYPE;
    __IO uint8_t  SIEM_RXINTERVAL;
         uint8_t  SIEreserved0[3];
    __IO uint8_t  SIEM_FIFOSIZE;

    /* SIE common reg : 0x20 ~ 0x2f */
    __IO uint8_t  SIEM_FIFO0;
         uint8_t  SIEreserved1[3];
    __IO uint8_t  SIEM_FIFO1;
         uint8_t  SIEreserved2[3];
    __IO uint8_t  SIEM_FIFO2;
         uint8_t  SIEreserved3[3+4];

         uint8_t  rsv0[0x200-0x30];

    /* DMA common reg */
    __IO uint32 DMA_INT;         ///0x200
    __IO uint32 DMA1_CTL;
    __IO uint32 DMA1_ADDR;
    __IO uint32 DMA1_CNT;
         uint32 rsv1;
    __IO uint32 DMA2_CTL;
    __IO uint32 DMA2_ADDR;
    __IO uint32 DMA2_CNT;
         uint32 rsv2;
    __IO uint32 DMA3_CTL;
    __IO uint32 DMA3_ADDR;
    __IO uint32 DMA3_CNT;
         uint32 rsv3;
    __IO uint32 DMA4_CTL;
    __IO uint32 DMA4_ADDR;
    __IO uint32 DMA4_CNT;

         uint32 rsv4[0x100/4 - 16];

    /* CPU common reg */
    __IO uint32 UCFG0;         ///0x300
    __IO uint32 UCFG1;
    __IO uint32 UCFG2;
    __IO uint32 UCFG3;

    //jx6001b.new_usb.20181217
    __IO uint32 EP_STATUS;
    __IO uint32 EP_KICK;
    __IO uint32 EP_CTL;    
         uint32 rsv5;    
    __IO uint32 EP0_TXSTARTADR;
    __IO uint32 EP0_RXSTARTADR;
    __IO uint32 EP0_TXLEN;
         uint32 rsv6;    
    __IO uint32 EP1_TXSTARTADR;
    __IO uint32 EP1_RXSTARTADR;
    __IO uint32 EP1_TXLEN;
    __IO uint32 EP1_RXLEN;
    
    __IO uint32 EP2_TXSTARTADR;
    __IO uint32 EP2_RXSTARTADR;
    __IO uint32 EP2_TXLEN;
    __IO uint32 EP2_RXLEN;
          
    __I  uint32 EP0_TXADR;
    __I  uint32 EP0_RXADR;
          
    __I  uint32 EP1_TXADR;
    __I  uint32 EP1_RXADR;
          
    __I  uint32 EP2_TXADR;
    __I  uint32 EP2_RXADR;
    
} USB_TypeDef;

#define T_REG_FADDR              0x00
#define T_REG_POWER              0x01
#define T_REG_INTRTX1            0x02
#define T_REG_INTRTX2            0x03
#define T_REG_INTRRX1            0x04
#define T_REG_INTRRX2            0x05
#define T_REG_INTRUSB            0x06
#define T_REG_INTRTX1E           0x07
#define T_REG_INTRTX2E           0x08
#define T_REG_INTRRX1E           0x09
#define T_REG_INTRRX2E           0x0A
#define T_REG_INTRUSBE           0x0B
#define T_REG_FRAME1             0x0C
#define T_REG_FRAME2             0x0D
#define T_REG_INDEX              0x0E
#define T_REG_DEVCTL             0x0F

#define T_TXMAXP                 0x10
#define T_TXCSR1_CSR0            0x11
#define T_CSR02                  0x12
#define T_TXCSR2                 0x12
#define T_RXMAXP                 0x13
#define T_RXCSR1                 0x14
#define T_RXCSR2                 0x15
#define T_RXCOUNT1_RXCOUNT0      0x16
#define T_RXCOUNT2               0x17
#define T_TXTYPE                 0x18
#define T_NAKLIMIT0              0x19
#define T_TXINTERVAL             0x19
#define T_RXTYPE                 0x1a
#define T_RXINTERVAL             0x1b

#define T_FIFOSIZE               0x1F

#define T_FIFO0                  0x20
#define T_FIFO1                  0x24
#define T_FIFO2                  0x28
#define T_FIFO3                  0x2c
#define T_FIFO4                  0x30


/**
  * @brief USB2.0
  */
typedef struct
{
	/* SIE common reg : 0x0 ~ 0xf */
	__IO uint8_t  SIEM_FADDR;
	__IO uint8_t  SIEM_POWER;
	__IO uint8_t  SIEM_INTRTX1;
	__IO uint8_t  SIEM_INTRTX2;
	__IO uint8_t  SIEM_INTRRX1;
	__IO uint8_t  SIEM_INTRRX2;
	__IO uint8_t  SIEM_INTRTX1E;
	__IO uint8_t  SIEM_INTRTX2E;
	__IO uint8_t  SIEM_INTRRX1E;
	__IO uint8_t  SIEM_INTRRX2E;
	__IO uint8_t  SIEM_INTRUSB;
	__IO uint8_t  SIEM_INTRUSBE;
	__IO uint8_t  SIEM_FRAMENUM1;
	__IO uint8_t  SIEM_FRAMENUM2;
	__IO uint8_t  SIEM_INDEX;
	__IO uint8_t  SIEM_TESTMODE;

	/* SIE indexed reg : 0x10 ~ 0x1f */
	__IO uint8_t  SIEM_TXMAXP;
	__IO uint8_t  SIEM_TXMAXP_H;
	__IO uint8_t  SIEM_TXCSR1;
	__IO uint8_t  SIEM_TXCSR2;
	__IO uint8_t  SIEM_RXMAXP;
	__IO uint8_t  SIEM_RXMAXP_H;
	__IO uint8_t  SIEM_RXCSR1;
	__IO uint8_t  SIEM_RXCSR2;
	__IO uint8_t  SIEM_RXCOUNT1;
	__IO uint8_t  SIEM_RXCOUNT2;
	__IO uint8_t  SIEM_TXTYPE;
	__IO uint8_t  SIEM_TXINTERVAL;
	__IO uint8_t  SIEM_RXTYPE;
	__IO uint8_t  SIEM_RXINTERVAL;
		 uint8_t  SIEreserved0[1];
	__IO uint8_t  SIEM_FIFOSIZE;

	/* SIE common reg : 0x20 ~ 0x2f */
	__IO uint8_t  SIEM_FIFO0;
		 uint8_t  SIEreserved1[3];
	__IO uint8_t  SIEM_FIFO1;
		 uint8_t  SIEreserved2[3];
	__IO uint8_t  SIEM_FIFO2;
		 uint8_t  SIEreserved3[3+4];

		 uint8_t  rsv0[0x200-0x30];

	__IO uint32_t DMA_INT;				 //0x200
	__IO uint32_t DMA1_CTL;
	__IO uint32_t DMA1_ADDR;
	__IO uint32_t DMA1_CNT;
		 uint32_t rsv_usb1;
	__IO uint32_t DMA2_CTL;
	__IO uint32_t DMA2_ADDR;
	__IO uint32_t DMA2_CNT;
		 uint32_t rsv[0x70/4 - 8]; 
	__IO uint32_t FIFO_BASE;			 //0x270
	__I  uint32_t ERR_PKT_CNT;			 //0x274, CRC5/CRC16 FAIL COUNTER
		 uint32_t rsv1[0x90/4 - 2];
	
	__IO uint32_t RQPKTCOUNT_EP1;		 //0x300

} USB20_TypeDef;


#define T_USB20_REG_FADDR              0x00
#define T_USB20_REG_POWER              0x01
#define T_USB20_REG_INTRTX1            0x02
#define T_USB20_REG_INTRTX2            0x03
#define T_USB20_REG_INTRRX1            0x04
#define T_USB20_REG_INTRRX2            0x05
#define T_USB20_REG_INTRTX1E           0x06
#define T_USB20_REG_INTRTX2E           0x07
#define T_USB20_REG_INTRRX1E           0x08
#define T_USB20_REG_INTRRX2E           0x09
#define T_USB20_REG_INTRUSB            0x0A
#define T_USB20_REG_INTRUSBE           0x0B
#define T_USB20_REG_FRAME1             0x0C
#define T_USB20_REG_FRAME2             0x0D
#define T_USB20_REG_INDEX              0x0E
#define T_USB20_REG_TESTMODE           0x0F

#define T_USB20_TXMAXP0                0x10
#define T_USB20_TXMAXP1                0x11
#define T_USB20_TXCSRL_CSR0L           0x12
#define T_USB20_TXCSRH_CSR0H           0x13
#define T_USB20_RXMAXP0                0x14
#define T_USB20_RXMAXP1                0x15
#define T_USB20_RXCSRL                 0x16
#define T_USB20_RXCSRH                 0x17
#define T_USB20_RXCOUNT1_RXCOUNT0      0x18
#define T_USB20_RXCOUNT2               0x19
//#define T_USB20_TXTYPE                 0x18
//#define T_USB20_NAKLIMIT0              0x19
//#define T_USB20_TXINTERVAL             0x19
//#define T_USB20_RXTYPE                 0x1a
//#define T_USB20_RXINTERVAL             0x1b

#define T_USB20_FIFOSIZE               0x1F

#define T_USB20_FIFO0                  0x20
#define T_USB20_FIFO1                  0x24
#define T_USB20_FIFO2                  0x28
#define T_USB20_FIFO3                  0x2c
#define T_USB20_FIFO4                  0x30

#define T_USB20_DEVCTL                 0x60
#define T_USB20_MISC                   0x61
#define T_USB20_SOFT_RST               0x7F


/**
  * @brief RFADCDIG
  */
#if 0
typedef struct
{
    __IO uint32_t RFADCDIGCON;
} RFADCDIG_TypeDef;
#endif
/**
  * @brief TIMERs
  */
typedef struct {
    __IO uint32_t TMR_CON;
    __IO uint32_t TMR_EN;
    __IO uint32_t TMR_IE;
    __IO uint32_t TMR_CNT;
    __IO uint32_t TMR_FLG;
    __IO uint32_t TMR_CLR;
    __IO uint32_t TMR_CAP1;
    __IO uint32_t TMR_CAP2;
    __IO uint32_t TMR_CAP3;
    __IO uint32_t TMR_CAP4;
} TIMER_TypeDef;

typedef struct {
    __IO uint32_t TMR_CON;
    __IO uint32_t TMR_EN;
    __IO uint32_t TMR_IE;
    __IO uint32_t TMR_CNT;
    __IO uint32_t TMR_FLG;
    __IO uint32_t TMR_CLR;
    __IO uint32_t TMR_CAP1;
    __IO uint32_t TMR_CAP2;
    __IO uint32_t TMR_CAP3;
    __IO uint32_t TMR_CAP4;
    __IO uint32_t TMR_DCTL;
    __IO uint32_t TMR_DADR;
    __IO uint32_t TMR_DLEN;
    __IO uint32_t TMR_DCNT;
    __IO uint32_t TMR_IR_BCNT;
} IR_TIMER_TypeDef;


typedef struct {
    __IO uint32_t TMR_ALLCON;
} TIMER_ALL_TypeDef;

/**
  * @brief CRC
  */

typedef struct {
    __IO uint32 CRC_CFG;                        // 0x0c
    __IO uint32 CRC_INIT;                       // 0x04
    __IO uint32 CRC_INV;                        // 0x08
    __IO uint32 CRC_POLY;                       // 0x0c
    __IO uint32 CRC_KST;                        // 0x10
    __IO uint32 CRC_STA;                        // 0x14
         uint32 RESERVED0;
    __IO uint32 DMA_ADDR;                       // 0x1c
    __IO uint32 DMA_LEN;                        // 0x20
    __IO uint32 CRC_OUT;                        // 0x24
} CRC_TypeDef;

/**
  * @brief PMU
  */
#if 0
typedef struct
{
    __IO uint32 LVD_CON;
    __IO uint32 LVD_CON1;
    __IO uint32 LVD_CON2;
         uint32 RESERVED0;
    __IO uint32 PMUCON0;
    __IO uint32 PMUCON1;
    __IO uint32 PMUCON2;
    __IO uint32 PMUCON3;
    __IO uint32 PMUCON4;
    __IO uint32 PMUCON5;
    __IO uint32 RFCON0;
    __IO uint32 RFCON1;
    __IO uint32 PMUCON6;
    __IO uint32 PMUCON7;
    __IO uint32 PMUCON8;
         uint32 RESERVED1[(0x50-0x38-4)/4];
    __IO uint32 PNDCLR;
         uint32 RESERVED10[(0x80-0x50-4)/4];
    __IO uint32 TMRCON;
    __IO uint32 TMRPR;
    __IO uint32 TMRRPT;
    __IO uint32 TMRTRIM;
         uint32 RESERVED2[4];
    __IO uint32 WKCON;
         uint32 RESERVED3[3];
    __IO uint32 PMUSEC_CON;
    __IO uint32 PMUSEC_DAT;
    __IO uint32 PMUSEC_ADR;
    __IO uint32 PMUSEC_KEY;
    __IO uint32 CMPCON;
} PMU_TypeDef;
#endif

/**
  * @brief SYS_CTRL
  */
#if 0
typedef struct
{
    __IO uint32 SYS_KEY;
    __IO uint32 SYS_CON0;
    __IO uint32 SYS_CON1;
    __IO uint32 SYS_CON2;
    __IO uint32 SYS_CON3;
    __IO uint32 SYS_CON4;
    __IO uint32 SYS_CON5;
    __IO uint32 SYS_CON6;
    __IO uint32 SYS_CON7;
    __IO uint32 SYS_CON8;
    __IO uint32 SYS_CON9;
    __IO uint32 SYS_CON10;
    __IO uint32 SYS_CON11;
    __IO uint32 SYS_CON12;
    __IO uint32 SYS_CON13;
    __IO uint32 SYS_CON14;
    __IO uint32 SYS_CON15;
    __IO uint32 CLK_CON0;
    __IO uint32 CLK_CON1;
    __IO uint32 CLK_CON2;
    __IO uint32 CLK_CON3;
    __IO uint32 CLK_CON4;
    __IO uint32 CLK_CON5;
    __IO uint32 CHIP_ID;
    __IO uint32 CLK_CON6;
    __IO uint32 CLK_CON7;
    __IO uint32 SRAM0_PD_CON;
    __IO uint32 AIP_CON0;
    __IO uint32 AIP_CON1;
    __IO uint32 IO_MAP;
    __IO uint32 EFUSE_CON;
    __IO uint32 SYS_ERR0;
    __IO uint32 SYS_ERR1;
    __IO uint32 HOSC_MNT;
    __IO uint32 WK_CTRL;
    __IO uint32 LP_CTRL;
    __IO uint32 MBIST_CTRL;
    __IO uint32 MPE0;
    __IO uint32 MPE1;
    __IO uint32 MPE2;
    __IO uint32 MPE3;
    __IO uint32 MPE4;
    __IO uint32 MPE5;
    __IO uint32 MPE0_PND;
    __IO uint32 MPE1_PND;
    __IO uint32 MPE2_PND;
    __IO uint32 MPE3_PND;
    __IO uint32 MPE4_PND;
    __IO uint32 MPE5_PND;
    __IO uint32 MODE_REG;
    __IO uint32 MBIST_MISR0;
    __IO uint32 MBIST_MISR1;
    __IO uint32 MBIST_MISR2;
    __IO uint32 MBIST_MISR3;
    __IO uint32 MBIST_MISR4;
    __IO uint32 MBIST_MISR5;
    __IO uint32 MBIST_MISR6;
    __IO uint32 MBIST_MISR7;
    __IO uint32 USB20_PHY_CFG0;
    __IO uint32 USB20_PHY_CFG1;
    __IO uint32 USB20_PHY_CFG2;
    __IO uint32 USB20_PHY_CFG3;
    __IO uint32 USB20_PHY_DBG0;
    __IO uint32 USB20_PHY_DBG1;    
} SYSCTRL_TypeDef;
#endif                 
//#define     SYSCTRL_REG_OPT(expression)       {SYSCTRL->SYS_KEY = 0x3fac87e4; expression; SYSCTRL->SYS_KEY = 0;}

/**
  * @brief SDIO slave Interface
  */
typedef struct
{
    __IO uint32 DATA_PORT;
    __IO uint32 INT_ID;
    __IO uint32 CIS_FUNC0_ADDR;
    __IO uint32 CIS_FUNC1_ADDR;
    __IO uint32 CSA_ADDR;
    __IO uint32 READ_ADDR;
    __IO uint32 WRITE_ADDR;
    __IO uint32 AHB_TRANS_CNT;
    __IO uint32 SDIO_TRANS_CNT;
    __IO uint32 CIA;
    __IO uint32 PROGRAM;
    __IO uint32 INT_STATUS;
    __IO uint32 INT_ENABLE;
    __IO uint32 OCR;
    __IO uint32 CLK_WK;
    __IO uint32 AHB_BURST_SIZE;
    __IO uint32 AHB_SOFT_RESET;
    __IO uint32 SDIO_TRANS_ADDR;      /* RO: SDIO host cmd address */
    __IO uint32 USER_FUNC0;           /* RW: user define register, RO for host */
    __IO uint32 USER_FUNC1;           /* RW: user define register, RO for host */
    __IO uint32 USER_FUNC2;           /* RW: user define register, RO for host */
    __IO uint32 MIX_FUNC3;            /* RW: user define register, RO for host */
    __IO uint32 DMA_CNT_CTRL;         /* RW: user define register, -- for host */
    __IO uint32 DMA_FINISH_CNT;       /* RW: user define register, -- for host */
    __I  uint32 FN1_BLOCK_SIZE;       /* RW: user define register, -- for host */
    __I  uint32 FN1_BLOCK_NUM;        /* RO: user define register, -- for host */
} SDIO_SLAVE_TypeDef;

/**
  * @brief SDIO host Interface
  */
typedef struct
{
    __IO uint32 MAX_CURRENT;
         uint32 RSV3;
    __IO uint16 FE_AUTOCMD12ES;//Force event for AutoCmd12 Error Status
    __IO uint16 FE_ERR_INT_STA;//Force event for Error Int Status
    __IO uint8  ADMA_ERR_STA;
         uint8  RSV4;
         uint8  RSV5;
         uint8  RSV6;
    __IO uint32 ADMA_ADDR_L;
    __IO uint32 ADMA_ADDR_H;
    __IO uint32 BOOT_DATA_TO;
    __IO uint8  DBG_SEL;
         uint8  RSV7[0xF0-0x65];
    __IO uint8  SPI_INT_SUPPORT;
         uint8  RSV8;
         uint8  RSV9;
         uint8  RSV10;
} SDIO_HOSintT_TypeDef;

/**
  * @brief GPIO controller
  */
#if 0  
typedef struct {
    __IO uint32_t MODE;
    __IO uint32_t OTYPE;
    __IO uint32_t OSPEEDL;
    __IO uint32_t OSPEEDH;
    __IO uint32_t PUPL;
    __IO uint32_t PUPH;
    __IO uint32_t PUDL;
    __IO uint32_t PUDH;
    __IO uint32_t IDAT;
    __IO uint32_t ODAT;
    __IO uint32_t BSR;
    __IO uint32_t LCK;
    __IO uint32_t AFRL;
    __IO uint32_t AFRH;
    __IO uint32_t TGL;
    __IO uint32_t IMK;
    __IO uint32_t HY;
    __IO uint32_t SRL;
    __IO uint32_t SRH;
    __IO uint32_t DEBEN;
    __IO uint32_t AIOEN;
    __IO uint32_t PND;
    __IO uint32_t PNDCLR;
} GPIO_TypeDef;
#endif




/**
  * @brief MJPEG
  */
typedef struct 
{
	__IO uint32 DQT[32];
	__IO uint32 DHT[103];	
	__IO uint32 RES0;
	__IO uint32 CSR0;
	__IO uint32 CSR1;
	__IO uint32 CSR2;
	__IO uint32 CSR3;
	__IO uint32 CSR4;
	__IO uint32 CSR5;
	__IO uint32 CSR6;
	__IO uint32 RES1;
	__IO uint32 DMA_CON;	
	__IO uint32 DMA_STA;
	__IO uint32 DMA_INTE;
	__IO uint32 DMA_TADR0;
	__IO uint32 DMA_TADR1;
	__IO uint32 DMA_DLEN;		
}JPG_TypeDef;


/**
  * @brief MJPEG_HUFF
  */

typedef struct 
{
	__IO uint32 HTABLE[192];	
}JPGHUFF_TypeDef;

/**
  * @brief Ethernet GMAC controller (IP modify)
  */
typedef struct {
    __IO uint32 CSR0;
    __IO uint32 CSR1;
    __IO uint32 CSR2;
    __IO uint32 CSR3;
    __IO uint32 CSR4;
    __IO uint32 CSR5;
    __IO uint32 CSR6;
    __IO uint32 CSR7;
    __IO uint32 RESERVED;
    __IO uint32 CSR9;
    __IO uint32 CSR10;
    __IO uint32 CSR11;
} GMAC_TypeDef;

typedef struct
{
    __IO uint32 DmaTestRegH;
} DMAC_TypeDef;


/** 
  * @brief  TX4101_RFDIGITAL
  */
typedef struct
{
    __IO uint32 RFSYS_REG0;
    __IO uint32 RFSYS_REG1;
    __IO uint32 RFSYS_REG2;
    __IO uint32 RFSYS_REG3;
    __IO uint32 RFSYS_REG4;
    __IO uint32 RFSYS_REG5;
    __IO uint32 RFSYS_REG6;
    __IO uint32 RFSYS_REG7;
    __IO uint32 RFSYS_REG8;
    __IO uint32 RFSYS_REG9;
    __IO uint32 RFSYS_REG10;
    __IO uint32 RFIDLE_REG0;
    __IO uint32 RFTXRX_REG0;
    __IO uint32 RFTXRX_REG1;
    __IO uint32 RFTXAGC_REG0;
    __IO uint32 RFTXAGC_REG1;
    __IO uint32 RFTXAGC_REG2;
    __IO uint32 RFRXAGC_REG0;
    __IO uint32 RFRXAGC_REG1;
    __IO uint32 RFOUT_REG0;
    __IO uint32 RFIDLEOVLAP0;
    __IO uint32 RFIDLEDIS0;
    __IO uint32 RFIDLEIDLE0;
    __IO uint32 RFTXRXOVLAP0;
    __IO uint32 RFTXRXDIS0;
    __IO uint32 RFTXRXIDLE0;
    __IO uint32 RFTXRXTX0;
    __IO uint32 RFTXRXRX0;
    __IO uint32 RFTXRXOVLAP1;
    __IO uint32 RFTXRXDIS1;
    __IO uint32 RFTXRXIDLE1;
    __IO uint32 RFTXRXTX1;
    __IO uint32 RFTXRXRX1;
    __IO uint32 RFTXAGCOVLAP0;
    __IO uint32 RFTXAGCOVDFT0;
    __IO uint32 RFTXAGCAGC00;
    __IO uint32 RFTXAGCAGC01;
    __IO uint32 RFTXAGCAGC02;
    __IO uint32 RFTXAGCAGC03;
    __IO uint32 RFTXAGCOVLAP1;
    __IO uint32 RFTXAGCOVDFT1;
    __IO uint32 RFTXAGCAGC10;
    __IO uint32 RFTXAGCAGC11;
    __IO uint32 RFTXAGCAGC12;
    __IO uint32 RFTXAGCAGC13;
    __IO uint32 RFTXAGCOVLAP2;
    __IO uint32 RFTXAGCOVDFT2;
    __IO uint32 RFTXAGCAGC20;
    __IO uint32 RFTXAGCAGC21;
    __IO uint32 RFTXAGCAGC22;
    __IO uint32 RFTXAGCAGC23;
    __IO uint32 RFRXAGCOVLAP0;
    __IO uint32 RFRXAGCOVDFT0;
    __IO uint32 RFRXAGCAGC00;
    __IO uint32 RFRXAGCAGC01;
    __IO uint32 RFRXAGCAGC02;
    __IO uint32 RFRXAGCAGC03;
    __IO uint32 RFRXAGCAGC04;
    __IO uint32 RFRXAGCAGC05;
    __IO uint32 RFRXAGCAGC06;
    __IO uint32 RFRXAGCAGC07;
    __IO uint32 RFRXAGCOVLAP1;
    __IO uint32 RFRXAGCOVDFT1;
    __IO uint32 RFRXAGCAGC10;
    __IO uint32 RFRXAGCAGC11;
    __IO uint32 RFRXAGCAGC12;
    __IO uint32 RFRXAGCAGC13;
    __IO uint32 RFRXAGCAGC14;
    __IO uint32 RFRXAGCAGC15;
    __IO uint32 RFRXAGCAGC16;
    __IO uint32 RFRXAGCAGC17;
    __IO uint32 RFIDLEEN_REG0;
    __IO uint32 RFTXRXEN_REG0;
    __IO uint32 RFTXRXEN_REG1;
    __IO uint32 RFTXAGCEN_REG0;
    __IO uint32 RFTXAGCEN_REG1;
    __IO uint32 RFTXAGCEN_REG2;
    __IO uint32 RFRXAGCEN_REG0;
    __IO uint32 RFRXAGCEN_REG1;
    __IO uint32 RFAGC_REG;
    __IO uint32 RFIDLERD_REG0;
    __IO uint32 RFTXRXRD_REG0;
    __IO uint32 RFTXRXRD_REG1;
    __IO uint32 RFTXAGCRD_REG0;
    __IO uint32 RFTXAGCRD_REG1;
    __IO uint32 RFTXAGCRD_REG2;
    __IO uint32 RFRXAGCRD_REG0;
    __IO uint32 RFRXAGCRD_REG1;
    __IO uint32 RCCAL_CON;
    __IO uint32 RCSEL_CON;
} RFDIG_TypeDef;




/** 
  * @brief  ZH_RFSPI  
  */

/**
  * @brief RF Digital Calibration
  */
#if 0  
typedef struct
{
    __IO uint32 RFDCOCCON0;
    __IO uint32 RFDCOCCON1;
    __IO uint32 RFDCOCCON2;
    __IO uint32 RFDCOCCON3;
    __IO uint32 RFDCOCCON4;
    __IO uint32 RFPWRCON0;
    __IO uint32 RFPWRCON1;
    __IO uint32 XOSCDFMCON0;
    __IO uint32 XOSCDFMCON1;
    __IO uint32 XOSCDFMCON2;
    __IO uint32 RXIQIMBEST0;
    __IO uint32 RXIQIMBEST1;
    __IO uint32 RXIQIMBEST2;
    __IO uint32 TXPWRIDX;
    __IO uint32 TXDC01;
    __IO uint32 TXDC23;
    __IO uint32 TXDC45;
    __IO uint32 TXDC67;
    __IO uint32 TXIMB0;
    __IO uint32 TXIMB1;
    __IO uint32 TXIMB2;
    __IO uint32 TXIMB3;
    __IO uint32 TXIMB4;
    __IO uint32 TXIMB5;
    __IO uint32 TXIMB6;
    __IO uint32 TXIMB7;
    __IO uint32 RXPWRIDX;
    __IO uint32 RX20MDC01;
    __IO uint32 RX20MDC23;
    __IO uint32 RX20MDC45;
    __IO uint32 RX20MDC67;
    __IO uint32 RX20MIMB0;
    __IO uint32 RX20MIMB1;
    __IO uint32 RX20MIMB2;
    __IO uint32 RX20MIMB3;
    __IO uint32 RX20MIMB4;
    __IO uint32 RX20MIMB5;
    __IO uint32 RX20MIMB6;
    __IO uint32 RX20MIMB7;
    __IO uint32 RXFBDC01;
    __IO uint32 RXFBDC23;
    __IO uint32 RXFBIMB0;
    __IO uint32 RXFBIMB1;
    __IO uint32 RXFBIMB2;
    __IO uint32 RXFBIMB3;
    __IO uint32 TXDIGPWR01;
    __IO uint32 TXDIGPWR23;
    __IO uint32 TXDIGPWR45;
    __IO uint32 TXDIGPWR67;
    __IO uint32 DBGPATH_CFG0;
    __IO uint32 DBGPATH_CFG1;
    __IO uint32 SOFT_RFIF_CON;
} RFDIGCAL_TypeDef;
#endif
typedef struct
{
    __IO uint32 DMA_CON;
    __IO uint32 DMA_SAIE;
    __IO uint32 DMA_DATA;
    __IO uint32 DMA_SADR;
    __IO uint32 DMA_TADR;
    __IO uint32 DMA_DLEN;
} M2M_DMA_TypeDef;


typedef struct
{
    __IO uint32 TDMA_CTRL;
    __IO uint32 TDMA_STATUS;
    __IO uint32 TDMA_STADDR;
    __IO uint32 TDMA_LEN;
    __I  uint32 TDMA_REM;
    __IO uint32 TDMA_TRLEN;    
    __I  uint32 TDMA_TRADDR;        
} TDMA_TypeDef;


typedef struct 
{
    __IO uint32 TXADDR;
    __IO uint32 TXLEN;
}TxSubframe;


typedef struct 
{
    __I  uint32 RXADDR;
    __I  uint32 RXFCSLEN;
}RxSubframe;

typedef struct 
{
    __IO  uint32 CONFIG;        //0x00
    __IO  uint32 DEV_RDINSTR_CONFIG;    //0x04
    __IO  uint32 DEV_WRINSTR_CONFIG;    //0x08
    __IO  uint32 DEV_DELAY;        //0x0c
    __IO  uint32 READ_DATA_CAPTURE;   //0x10
    __IO  uint32 DEV_SIZE_CONFIG;    //0x14
    __IO  uint32 SRAM_PARTITION;      //0x18
    __IO  uint32 IND_AHB_TRIGGER;     //0x1c
    __IO  uint32 PERIPH_CFG;          //0x20
    __IO  uint32 REMAP_ADD;       //0x24
    __IO  uint32 MODE_BIT;           //0x28
    __IO  uint32 SRAM_FILL_LEVEL;     //0x2c
    __IO  uint32 TX_THRESH;       //0x30
    __IO  uint32 RX_THRESH;       //0x34
    __IO  uint32 WRITE_COMP_CTRL;       //0x38
    __IO  uint32 MAX_NO_OF_POLLS;       //0x3c
    __IO  uint32 INT_STATUS;       //0x40
    __IO  uint32 INT_MASK;           //0x44
          uint32 RESERVED0[2];    
    __IO  uint32 WRITE_PROT_L;       //0x50
    __IO  uint32 WRITE_PROT_U;       //0x54
    __IO  uint32 WRITE_PROT_CTRL;       //0x58
          uint32 RESERVED1[1];    
    __IO  uint32 IND_RD_XFER_CTRL;    //0x60
    __IO  uint32 IND_RD_XFER_WMARK;   //0x64
    __IO  uint32 IND_RD_XFER_START_ADD;       //0x68
    __IO  uint32 IND_RD_XFER_NUM_BYTES;       //0x6c
    __IO  uint32 IND_WR_XFER_CTRL;        //0x70
    __IO  uint32 IND_WR_XFER_WMARK;       //0x74
    __IO  uint32 IND_WR_XFER_START_ADD;       //0x78
    __IO  uint32 IND_WR_XFER_NUM_BYTES;       //0x7c
    __IO  uint32 IND_AHB_TRIGGER_RANGE;       //0x80
          uint32 RESERVED2[3];    
    __IO  uint32 FLASH_CMD_CTRL;        //0x90
    __IO  uint32 FLASH_CMD_ADD;        //0x94
          uint32 RESERVED3[2];    
    __IO  uint32 FLASH_CMD_RDATA_L;        //0xa0
    __IO  uint32 FLASH_CMD_RDATA_U;        //0xa4
    __IO  uint32 FLASH_CMD_WDATA_L;        //0xa8
    __IO  uint32 FLASH_CMD_WDATA_U;        //0xac
    __IO  uint32 FLASH_STATUS;           //0xb0
          uint32 RESERVED4[(0xfc-0xb0)/4-1];    
    __IO  uint32 MODULE_ID;           //0xfc
} QSPI_TypeDef;

typedef struct
{	
   __IO uint32 MACADDRL          ;
    __IO uint32 MACADDRH          ;
    __IO uint32 HT_CAP            ;
    __IO uint32 GRPMACADDRL            ;
    __IO uint32 GRPMACADDRH            ;
         uint32 LMAC_RVD0[3]      ;
	__IO uint32 SYNCCTL           ;
    __IO uint32 TSF_L             ;
    __IO uint32 TSF_H             ;
    __IO uint32 BEACONPERIOD      ;
    __IO uint32 TBTTTIMER         ;
    __IO uint32 BEACONCFG         ;
         uint32 LMAC_RVD1[2]      ;
    __IO uint32 SCANCTL           ;
    __IO uint32 MINCHANNELTIME    ;
    __IO uint32 MAXCHANNELTIME    ;
         uint32 LMAC_RVD2[1]      ;
    __IO uint32 PROBEDELAY        ;
         uint32 LMAC_RVD3[3]      ;
    __IO uint32 LMACCTL0          ;
    __IO uint32 LMACCTL1          ;
    __IO uint32 LMACCTL2          ;
    __IO uint32 LMACCTL3          ;
    __IO uint32 LMACCTL4          ;
    __IO uint32 LMACCTL5          ;
    __IO uint32 TXFRAME_ERRCODE   ;
    __IO uint32 RXFRAME_ERRCODE   ;
    __IO uint32 LMACIP            ;
    __IO uint32 LMACIE            ;
    __IO uint32 LMACINFO0         ;
    __IO uint32 LMACINFO1         ;
    __IO uint32 LMACINFO2         ;
    __IO uint32 LMACINFO3         ;
    __IO uint32 LMACINFO4         ;
    __IO uint32 LMACINFO5         ;
    __IO uint32 RFENCTL0          ;
    __IO uint32 RFENCTL1          ;
    __IO uint32 RFENCTL2          ;
    __IO uint32 PHYDLYCTL         ;
    __IO uint32 RFPHYIFIOCFG0     ;
    __IO uint32 RFPHYIFIOCFG1     ;
         uint32 LMAC_RVD4[2]      ;
    __IO uint32 STAVALIDCTL       ;
         uint32 LMAC_RVD5[2]      ;
    __IO uint32 MEMBERINFO        ;
         uint32 LMAC_RVD6[20]     ;
    __IO uint32 TXRXBUFDBG        ;
    __IO uint32 TXBUFSTATUS       ;
         uint32 LMAC_RVD7[1]      ;
    __IO uint32 TXBUFVALIDNUM     ;
    __IO uint32 TXBUFNINFO0       ;
    __IO uint32 TXBUFNINFO1       ;
    __IO uint32 TXBUFNINFO2       ;
    __IO uint32 TXBUFNINFO3       ;
         uint32 LMAC_RVD8[3]      ;
    __IO uint32 RXDSIG0           ;
    __IO uint32 RXDSIG1           ;
    __IO uint32 RXLSIG            ;
    __IO uint32 RXHTSIG0          ;
    __IO uint32 RXHTSIG1          ;
    __IO uint32 RXVEC2            ;
    __IO uint32 RXINFO0           ;
    __IO uint32 RXINFO1           ;
    __IO uint32 RXINFO2           ;
    __IO uint32 RXINFO3           ;
    __IO uint32 RXINFO4           ;
    __IO uint32 RXINFO5           ;
    __IO uint32 RXINFO6           ;
    __IO uint32 EDCATXTH0         ;
    __IO uint32 EDCATXTH1         ;
    __IO uint32 EDCATXTH2         ;
    __IO uint32 EDCATXTH3         ;
    __IO uint32 EDCAACBK          ;
    __IO uint32 EDCAACBE          ;
    __IO uint32 EDCAACVI          ;
    __IO uint32 EDCAACVO          ;
    __IO uint32 RXDURATION        ;
    __IO uint32 RXBASSN           ;
    __IO uint32 RXBABITMAP0       ;
    __IO uint32 RXBABITMAP1       ;
    __IO uint32 RXHTCINFO         ;
    __IO uint32 RXSEQINFO         ;
    __IO uint32 ACBKBACKOFFINFO   ;
    __IO uint32 ACBEBACKOFFINFO   ;
    __IO uint32 ACVIBACKOFFINFO   ;
    __IO uint32 ACVOBACKOFFINFO   ;
         uint32 LMAC_RVD9[1]      ;
    __IO uint32 ACPRBSSEED        ;
    __IO uint32 EDCAINFO0         ;
    __IO uint32 EDCAINFO1         ;
    __IO uint32 EDCAINFO2         ;
    __IO uint32 EDCAINFO3         ;
    __IO uint32 EDCAINFO4         ;
    __IO uint32 EDCAINFO5         ;
    __IO uint32 EDCAINFO6         ;
    __IO uint32 EDCAINFO7         ;
    __IO uint32 TXFAILBITMAP0     ;
    __IO uint32 ACKENCTL0         ;
    __IO uint32 ACKENCTL1         ;
         uint32 LMAC_RVD10[1]     ;
    __IO uint32 PWRCTL            ;
    __IO uint32 DTIMPERIOD        ;
    __IO uint32 DTIMCOUNT         ;
    __IO uint32 STAPSINFO         ;
         uint32 LMAC_RVD11[5]     ;
    __IO uint32 STABUFINFO0       ;
    __IO uint32 STABUFINFO1       ;
         uint32 LMAC_RVD12[2]     ;
    __IO uint32 STATIMMODE        ;
    __IO uint32 STANONTIMLOSTINFO ;
         uint32 LMAC_RVD13[1]     ;
    __IO uint32 LMACDBG           ;
    __IO uint32 LMACDBGINFO       ;
    __IO uint32 LMACDBGTXVEC1     ;
    __IO uint32 LMACDBGTXDSIG0    ;
    __IO uint32 LMACDBGTXLSIG     ;
    __IO uint32 LMACDBGTXHTSIG0   ;
    __IO uint32 LMACDBGTXHTSIG1   ;
//         uint32 LMAC_RVD14[5]     ;
    __IO uint32 LMACDBGDMACTL   ;
    __IO uint32 LMACDBGDMASA   ;
    __IO uint32 LMACDBGDMAINFO   ;
    __IO uint32 LMACDBGDMAMSK0   ;
    __IO uint32 LMACDBGDMAMSK1   ;

    __IO uint32 RXLOCALMIC0       ;
    __IO uint32 RXLOCALMIC1       ;
    __IO uint32 RXLOCALMIC2       ;
    __IO uint32 RXLOCALMIC3       ;
    __IO uint32 RXCCMPHDR0        ;
    __IO uint32 RXCCMPHDR1        ;
    __IO uint32 RXMIC0            ;
    __IO uint32 RXMIC1            ;
    __IO uint32 RXMIC2            ;
    __IO uint32 RXMIC3            ;
    __IO uint32 RXTMPKEY0         ;
    __IO uint32 RXTMPKEY1         ;
    __IO uint32 RXTMPKEY2         ;
    __IO uint32 RXTMPKEY3         ;
    __IO uint32 RXTMPKEY4         ;
    __IO uint32 RXTMPKEY5         ;
    __IO uint32 RXTMPKEY6         ;
    __IO uint32 RXTMPKEY7         ;
    __IO uint32 RXBN0             ;
    __IO uint32 RXBN1             ;
    __IO uint32 RXBN2             ;
    __IO uint32 RXBN3             ;
    __IO uint32 RXAAD0            ;
    __IO uint32 RXAAD1            ;
    __IO uint32 RXAAD2            ;
    __IO uint32 RXAAD3            ;
    __IO uint32 RXAAD4            ;
    __IO uint32 RXAAD5            ;
    __IO uint32 RXAAD6            ;
    __IO uint32 RXAAD7            ;
    __IO uint32 RXSN0             ;
    __IO uint32 RXSN1             ;
    __IO uint32 RXSN2             ;
    __IO uint32 RXSN3             ;
         uint32 LMAC_RVD15[2]     ;
    __IO uint32 PHYDMACTL         ;
    __IO uint32 PHYDMAINFO        ;
    __IO uint32 PHYTXDMASA        ;
    __IO uint32 PHYTXDMALEN       ;
    __IO uint32 PHYRXDMASA        ;
    __IO uint32 PHYRXDMALEN       ;
         uint32 LMAC_RVD16[1]     ;
    __IO uint32 LMACRXBUFSA0      ;
    __IO uint32 LMACRXBUFSA1      ;
    __IO uint32 LMACRXBUFLIMIT    ;
    __IO uint32 LMACDMACTL        ;
    __IO uint32 LMACDMAINFO       ;
    __IO uint32 LMACRXLENSA0      ;
    __IO uint32 LMACRXLENSA1      ;
    __IO uint32 LMACRXLENSA2      ;
    __IO uint32 LMACRXLENSA3      ;
    __IO uint32 LMACRXLENSA4      ;
    __IO uint32 LMACRXLENSA5      ;
    __IO uint32 LMACRXLENSA6      ;
    __IO uint32 LMACRXLENSA7      ;
    __IO uint32 LMACRXLENSA8      ;
    __IO uint32 LMACRXLENSA9      ;
    __IO uint32 LMACRXLENSA10     ;
    __IO uint32 LMACRXLENSA11     ;
    __IO uint32 LMACRXLENSA12     ;
    __IO uint32 LMACRXLENSA13     ;
    __IO uint32 LMACRXLENSA14     ;
    __IO uint32 LMACRXLENSA15     ;
    __IO uint32 LMACRXLENSA16     ;
    __IO uint32 LMACRXLENSA17     ;
    __IO uint32 LMACRXLENSA18     ;
    __IO uint32 LMACRXLENSA19     ;
    __IO uint32 LMACRXLENSA20     ;
    __IO uint32 LMACRXLENSA21     ;
    __IO uint32 LMACRXLENSA22     ;
    __IO uint32 LMACRXLENSA23     ;
    __IO uint32 LMACRXLENSA24     ;
    __IO uint32 LMACRXLENSA25     ;
    __IO uint32 LMACRXLENSA26     ;
    __IO uint32 LMACRXLENSA27     ;
    __IO uint32 LMACRXLENSA28     ;
    __IO uint32 LMACRXLENSA29     ;
    __IO uint32 LMACRXLENSA30     ;
    __IO uint32 LMACRXLENSA31     ;
    __IO uint32 LMACRXLENSA32     ;
    __IO uint32 LMACRXLENSA33     ;
    __IO uint32 LMACRXLENSA34     ;
    __IO uint32 LMACRXLENSA35     ;
    __IO uint32 LMACRXLENSA36     ;
    __IO uint32 LMACRXLENSA37     ;
    __IO uint32 LMACRXLENSA38     ;
    __IO uint32 LMACRXLENSA39     ;
    __IO uint32 LMACRXLENSA40     ;
    __IO uint32 LMACRXLENSA41     ;
    __IO uint32 LMACRXLENSA42     ;
    __IO uint32 LMACRXLENSA43     ;
    __IO uint32 LMACRXLENSA44     ;
    __IO uint32 LMACRXLENSA45     ;
    __IO uint32 LMACRXLENSA46     ;
    __IO uint32 LMACRXLENSA47     ;
    __IO uint32 LMACRXLENSA48     ;
    __IO uint32 LMACRXLENSA49     ;
    __IO uint32 LMACRXLENSA50     ;
    __IO uint32 LMACRXLENSA51     ;
    __IO uint32 LMACRXLENSA52     ;
    __IO uint32 LMACRXLENSA53     ;
    __IO uint32 LMACRXLENSA54     ;
    __IO uint32 LMACRXLENSA55     ;
    __IO uint32 LMACRXLENSA56     ;
    __IO uint32 LMACRXLENSA57     ;
    __IO uint32 LMACRXLENSA58     ;
    __IO uint32 LMACRXLENSA59     ;
    __IO uint32 LMACRXLENSA60     ;
    __IO uint32 LMACRXLENSA61     ;
    __IO uint32 LMACRXLENSA62     ;
    __IO uint32 LMACRXLENSA63     ;
    __IO uint32 LMACTXLENSA0      ;
    __IO uint32 LMACTXLENSA1      ;
    __IO uint32 LMACTXLENSA2      ;
    __IO uint32 LMACTXLENSA3      ;
    __IO uint32 LMACTXLENSA4      ;
    __IO uint32 LMACTXLENSA5      ;
    __IO uint32 LMACTXLENSA6      ;
    __IO uint32 LMACTXLENSA7      ;
    __IO uint32 LMACTXLENSA8      ;
    __IO uint32 LMACTXLENSA9      ;
    __IO uint32 LMACTXLENSA10     ;
    __IO uint32 LMACTXLENSA11     ;
    __IO uint32 LMACTXLENSA12     ;
    __IO uint32 LMACTXLENSA13     ;
    __IO uint32 LMACTXLENSA14     ;
    __IO uint32 LMACTXLENSA15     ;
         uint32 LMAC_RVD17[48]    ;
    __IO uint32 WAVEDMAENDPOS     ;
    __IO uint32 WAVEDMACTL        ;
    __IO uint32 WAVEDMAINFO       ;
    __IO uint32 WAVEDMAWRSA       ;
    __IO uint32 WAVEDMAWRLEN      ;
    __IO uint32 WAVEDMARDSA       ;
    __IO uint32 WAVEDMARDLEN      ;
         uint32 LMAC_RVD18[61]    ;
    __IO uint32 RXCTLBUF0         ;
    __IO uint32 RXCTLBUF1         ;
    __IO uint32 RXCTLBUF2         ;
    __IO uint32 RXCTLBUF3         ;
    __IO uint32 RXCTLBUF4         ;
    __IO uint32 RXCTLBUF5         ;
    __IO uint32 RXCTLBUF6         ;
    __IO uint32 RXCTLBUF7         ;
    __IO uint32 RXCTLBUF8         ;
    __IO uint32 RXCTLBUF9         ;
         uint32 LMAC_RVD19[6]     ;
    __IO uint32 TXBEACON0         ;
    __IO uint32 TXBEACON1         ;
    __IO uint32 TXBEACON2         ;
    __IO uint32 TXBEACON3         ;
    __IO uint32 TXBEACON4         ;
    __IO uint32 TXBEACON5         ;
    __IO uint32 TXBEACON6         ;
    __IO uint32 TXBEACON7         ;
    __IO uint32 TXBEACON8         ;
    __IO uint32 TXBEACON9         ;
    __IO uint32 TXBEACON10        ;
    __IO uint32 TXBEACON11        ;
    __IO uint32 TXBEACON12        ;
    __IO uint32 TXBEACON13        ;
    __IO uint32 TXBEACON14        ;
    __IO uint32 TXBEACON15        ;
         uint32 LMAC_RVD20[80]    ;
    __IO uint32 CCADBGCTL         ;
    __IO uint32 CCAINFO0          ;
    __IO uint32 CCAINFO1          ;
         uint32 LMAC_RVD21[29]    ;
    __IO uint32 STA0INFO0         ;
    __IO uint32 STA0INFO1         ;
    __IO uint32 STA0INFO2         ;
    __IO uint32 STA1INFO0         ;
    __IO uint32 STA1INFO1         ;
    __IO uint32 STA1INFO2         ;
    __IO uint32 STA2INFO0         ;
    __IO uint32 STA2INFO1         ;
    __IO uint32 STA2INFO2         ;
    __IO uint32 STA3INFO0         ;
    __IO uint32 STA3INFO1         ;
    __IO uint32 STA3INFO2         ;
    __IO uint32 STA4INFO0         ;
    __IO uint32 STA4INFO1         ;
    __IO uint32 STA4INFO2         ;
    __IO uint32 STA5INFO0         ;
    __IO uint32 STA5INFO1         ;
    __IO uint32 STA5INFO2         ;
    __IO uint32 STA6INFO0         ;
    __IO uint32 STA6INFO1         ;
    __IO uint32 STA6INFO2         ;
    __IO uint32 STA7INFO0         ;
    __IO uint32 STA7INFO1         ;
    __IO uint32 STA7INFO2         ;
    __IO uint32 GRPCASTINFO0      ;
    __IO uint32 GRPCASTINFO1      ;
    __IO uint32 GRPCASTINFO2      ;
    __IO uint32 BRDCASTINFO0      ;
    __IO uint32 BRDCASTINFO1      ;
    __IO uint32 BRDCASTINFO2      ;
         uint32 LMAC_RVD22[130]   ;
    __IO uint32 TXCCMPHDR0        ;
    __IO uint32 TXCCMPHDR1        ;
    __IO uint32 TXMIC0            ;
    __IO uint32 TXMIC1            ;
    __IO uint32 TXMIC2            ;
    __IO uint32 TXMIC3            ;
    __IO uint32 TXTMPKEY0         ;
    __IO uint32 TXTMPKEY1         ;
    __IO uint32 TXTMPKEY2         ;
    __IO uint32 TXTMPKEY3         ;
    __IO uint32 TXTMPKEY4         ;
    __IO uint32 TXTMPKEY5         ;
    __IO uint32 TXTMPKEY6         ;
    __IO uint32 TXTMPKEY7         ;
    __IO uint32 TXBN0             ;
    __IO uint32 TXBN1             ;
    __IO uint32 TXBN2             ;
    __IO uint32 TXBN3             ;
    __IO uint32 TXAAD0            ;
    __IO uint32 TXAAD1            ;
    __IO uint32 TXAAD2            ;
    __IO uint32 TXAAD3            ;
    __IO uint32 TXAAD4            ;
    __IO uint32 TXAAD5            ;
    __IO uint32 TXAAD6            ;
    __IO uint32 TXAAD7            ;
    __IO uint32 TXSN0             ;
    __IO uint32 TXSN1             ;
    __IO uint32 TXSN2             ;
    __IO uint32 TXSN3             ;
    __IO uint32 STA0KEYID         ;
    __IO uint32 STA1KEYID         ;
    __IO uint32 STA2KEYID         ;
    __IO uint32 STA3KEYID         ;
    __IO uint32 STA4KEYID         ;
    __IO uint32 STA5KEYID         ;
    __IO uint32 STA6KEYID         ;
    __IO uint32 STA7KEYID         ;
         uint32 LMAC_RVD23[26]    ;
    __IO uint32 INITTMPKEY0       ;
    __IO uint32 INITTMPKEY1       ;
    __IO uint32 INITTMPKEY2       ;
    __IO uint32 INITTMPKEY3       ;
    __IO uint32 INITTMPKEY4       ;
    __IO uint32 INITTMPKEY5       ;
    __IO uint32 INITTMPKEY6       ;
    __IO uint32 INITTMPKEY7       ;
         uint32 LMAC_RVD24[184]   ;
    __IO uint32 LMAC_USR0         ;
    __IO uint32 LMAC_USR1         ;
    __IO uint32 LMAC_USR2         ;
    __IO uint32 LMAC_USR3         ;
    __IO uint32 LMAC_USR4         ;
    __IO uint32 LMAC_USR5         ;
    __IO uint32 LMAC_USR6         ;
    __IO uint32 LMAC_USR7         ;
} LMAC_TypeDef;


/**
  * @brief CIPHER ENGINE & AES
  */

typedef struct
{
    __IO uint32 KEY[8];
    __IO uint32 IV[2];
    __IO uint32 PN[2];
    __IO uint32 AAD[8];
    __IO uint32 ENC_DATA_LEN;
    __IO uint32 ENC_SADDR;
    __IO uint32 ENC_DADDR;
         uint32 RESERVED0;
    __IO uint32 CIPHER_CTRL[2];
    __IO uint32 CIPHER_STATUS;
         uint32 RESERVED1;
    __I  uint32 MIC[4];    
} CE_TypeDef;
#if 0
struct REG48BIT {
    __IO uint32 REGL;
    __IO uint32 REGH;
};

typedef struct _MODEM_TypeDef
{
    __IO uint32 PHY_CTL;           
    __IO uint32 PHY_TXCTL;         
    __IO uint32 PHY_SYNC_TIME_TH;  
    __IO uint32 CCA_START_DET_TH;  
    __IO uint32 CCA_MID_DET_TH;    
    __IO uint32 CCA_ED_TH;         
    __IO uint32 PHY_RXCTL0;        
    __IO uint32 PHY_RXCTL1;        
    __IO uint32 PHY_RXCTL2;        
    __IO uint32 PHY_RXCTL3;        
    __IO uint32 PHY_RXCTL4;        
    __IO uint32 PHY_RXCTL5;        
    __IO uint32 PHY_RXCTL6;        
    __IO uint32 PHY_RXCTL7;        
    __IO uint32 PHY_RXCTL8;  
	__IO uint32 PHY_RXCTL9;      
    __I  uint32 MODEM_RVD0[112]    ;
    __I  uint32 PHYPSDUCRC;        
    __I  uint32 PHY_TXCRC;         
    __I  uint32 ERR_CODE;          
    __I  uint32 PHY_EST_INIT_DC;   
    __I  uint32 FO_DSSS_EST;       
    __I  uint32 FO_STF_EST;        
    __I  uint32 FO_LTF_PRI20_EST;  
    __I  uint32 FO_LTF_SEC20_EST;  
    __I  uint32 FO_LTF_SEC40_EST;  
    __I  uint32 PHY_STS_SYNC_POS;  
    __I  uint32 PHY_LTF_SYNC_POS;  
    __I  uint32 HTLTFNBIND;        
    __I  uint32 PHY_TXINFO;        
    __I  uint32 PHY_RXINFO0;       
    __I  uint32 PHY_RXINFO1;       
    __I  uint32 PHY_RXINFO2;       
    __I  uint32 PHY_RXINFO3;       
    __I  uint32 PHY_RXINFO4;       
    __I  uint32 MODEM_RVD1[46]    ;


    __IO  uint32 INCGAINTH_3_0;
    __IO  uint32 INCGAINTH_4;
    __IO  uint32 REDGAINTH_3_0;
    __IO  uint32 REDGAINTH_4;
    __IO  uint32 MCSNGAINTH_3_0    ;
    __IO  uint32 MCSNGAINTH_4;
    __IO  uint32 MCS0RXGAIN_3_0    ;
    __IO  uint32 MCS0RXGAIN_5_4;
    __IO  uint32 MCSNRXGAIN_3_0;
    __IO  uint32 MCSNRXGAIN_5_4;
    __IO  uint32 MCS0RXGAINIDX;
    __IO  uint32 MCSNRXGAINIDX; 
    __I   uint32 PHY_RXPWRINFO     ; 
    __I   uint32 MODEM_RVD2[51]    ;


	  __IO  uint32 DPD_AN_GAIN4[9];    
	  __IO  uint32 DPD_AN_GAIN5[9];
	  __IO  uint32 DPD_AN_GAIN6[9];
	  __IO  uint32 DPD_AN_GAIN7[9];
	  __IO  uint32 TX_GAIN0;
	  __IO  uint32 TX_GAIN1;
	  
	  __I   uint32 MODEM_RVD3[26]    ; //55  
	  
    __I   uint32 PHY_STATE_INFO0;   
    __I   uint32 PHY_STATE_INFO1;   
    __IO  uint32 Retreg;            
    __IO  uint32 PHY_UNUSED;     
} MODEM_TypeDef;

typedef struct
{
    __IO uint32 EFUSE_CON;
    __IO uint32 EFUSE_TIME_CON0;
    __IO uint32 EFUSE_TIME_CON1;
    __IO uint32 EFUSE_TIME_CON2;
    __IO uint32 EFUSE_STATUS;
    __IO uint32 EFUSE_ADDR_CNT;
    __IO uint32 EFUSE_DATA;
} EFUSE_TypeDef;
#endif
/**
  * @brief SYS_AES
  */

typedef struct
{
    __IO uint32 KEY[8];
    __IO uint32 SADDR;
    __IO uint32 DADDR;
    __IO uint32 BLOCK_NUM;
         uint32 RESERVED0[5];
    __IO uint32 AES_CTRL;
    __IO uint32 AES_STAT;
} SYS_AES_TypeDef;

typedef struct
{
    __IO uint32_t DBGPATH_CFG;
    __IO uint32_t TXCALIB_CFG0;
    __IO uint32_t TXCALIB_CFG1;
    __IO uint32_t DBG_COUNTER;
    __IO uint32_t TX_POWER_INDEX;
    __IO uint32_t RX_POWER_INDEX;
    __IO uint32_t DPD_POWER_INDEX;    
    __IO uint32_t RFENCTL0;
    __IO uint32_t RFENCTL1;    
    __IO uint32_t RFENCTL2;        
    __IO uint32_t DBGOUT_CTL0  ;    
    __IO uint32_t DBGOUT_CTL1  ;    
    __IO uint32_t MIPICTL0     ;    
    __IO uint32_t MIPIWDATA0   ;    
    __IO uint32_t MIPICTL1     ;    
    __IO uint32_t MIPIWDATA1   ;    
    __IO uint32_t MIPICTL2     ;    
    __IO uint32_t MIPIWDATA2   ;    
    __IO uint32_t MIPICTL3     ;    
    __IO uint32_t MIPIWDATA3   ;    
    __IO uint32_t reserved0     ;    
    __IO uint32_t reserved1     ;    
    __IO uint32_t reserved2     ;    
    __IO uint32_t reserved3     ;    
    __IO uint32_t reserved4     ;    
    __IO uint32_t reserved5     ;    
    __IO uint32_t reserved6     ;    
    __IO uint32_t reserved7     ;    
    __IO uint32_t RFSPIWDATA   ;          
} DBGPATH_TypeDef;


/**
  * @brief SYS_MNT
  */
#if 0
typedef struct
{
    __IO uint32 CHx_LMT_L;
    __IO uint32 CHx_LMT_H;
    __IO uint32 CHx_ERR_ADR;
} SYS_MNT_CH_TypeDef;

typedef struct
{
    __IO uint32 CTRL;
    __IO uint32 PND;
    __IO uint32 CLR;
    __IO uint32 RD;
    __IO uint32 WR;
    __IO uint32 CPU_PC0;
    __IO uint32 CPU_PC1;
    __IO uint32 CPU_PC2;
    __IO uint32 CPU_PC3;    
    
    SYS_MNT_CH_TypeDef SYS_MNT_CH[2];
} SYS_MNT_TypeDef;
#endif

typedef struct
{
    __IO uint32 CFG;
    __IO uint32 BAUD;
    __IO uint32 CPTR;
    __IO uint32 DPTR;
    __IO uint32 DCNT;
    __IO uint32 DBG_STA;
} SDHOST_TypeDef;


typedef struct
{
    __IO uint32 CON;
    __IO uint32 BIT_SET;
    __IO uint32 BAUD;
    __IO uint32 WS_CON;
    __IO uint32 PED;
    __IO uint32 PED_ENA;
    __O  uint32 PED_CLR;
    __IO uint32 DMACON;
    __IO uint32 TSTADR;
    __IO uint32 RSTADR;
    __IO uint32 TDMALEN;
    __IO uint32 RDMALEN;
    __IO uint32 TDMACNT;
    __IO uint32 RDMACNT;
    __I  uint32 STA;
} IIS_TypeDef;

typedef struct
{
    __IO uint32 CON;
    __IO uint32 DMACON;
    __IO uint32 DMASTADR;
    __IO uint32 DMALEN;
    __IO uint32 DMACNT;
    __IO uint32 STA;
} PDM_TypeDef;


typedef struct
{
    __IO uint32 MAX2829_CON;
    __IO uint32 MAX2829_TXGAIN0;
    __IO uint32 MAX2829_TXGAIN1;
    __IO uint32 MAX2829_RXGAIN0;
    __IO uint32 MAX2829_RXGAIN1;
}MAX2829_TypeDef;
/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */
#define FLASH_BASE                  ((uint32_t)0x08000000) /*!< FLASH base address in the alias region */
#define SRAM_BASE                   ((uint32_t)0x20000000) /*!< SRAM base address in the alias region */
#define PERIPH_BASE                 ((uint32_t)0x40000000) /*!< Peripheral base address in the alias region */

/*!< Peripheral memory map */
#define APB0_BASE                PERIPH_BASE
#define APB1_BASE               (PERIPH_BASE + 0x10000)
#define AHB_BASE                (PERIPH_BASE + 0x20000)

#define QSPI_BASE               (APB0_BASE + 0x0000)
#define HG_UART0_BASE           (APB0_BASE + 0x4000)
#define HG_UART1_BASE           (APB0_BASE + 0x4100)
#define HG_UART4_BASE           (APB0_BASE + 0x4b20)
#define HG_UART5_BASE           (APB0_BASE + 0x4b2c)
#define SPI0_BASE               (APB0_BASE + 0x4400)
#define SPI1_BASE               (APB0_BASE + 0x4500)
#define SPI2_BASE               (APB0_BASE + 0x4600)
#define SPI3_BASE               (APB0_BASE + 0x4700)
#define SPI5_BASE               (APB0_BASE + 0x4b38)
#define SPI6_BASE               (APB0_BASE + 0x4b44)
#define HG_LED_BASE             (APB0_BASE + 0x4b50)
#define IIC1_BASE               (APB0_BASE + 0x4500)
#define IIC2_BASE               (APB0_BASE + 0x4600)
#define IIC3_BASE               (APB0_BASE + 0x4700)
#define HG_IIS0_BASE            (APB0_BASE + 0x4900)
#define HG_IIS1_BASE            (APB0_BASE + 0x4a00)
#define HG_PDM_BASE             (APB0_BASE + 0x4b00)
#define JPG_BASE                (APB0_BASE + 0x5000)
#define DVP_BASE                (APB0_BASE + 0x5300)
#define MJPEG_HUFF_BASE         (APB0_BASE + 0x5c00)
#define MJPEG_HUFF_MASK         (0         + 0xfc00)
#define TK_BASE                 (APB0_BASE + 0x6000)


#define COMP_BASE               (APB0_BASE + 0x9000)
#define EFUSE_BASE              (APB0_BASE + 0xa000)

#define HG_SYSAES_BASE          (APB1_BASE + 0x2000)
#define RFADCDIG_BASE           (APB1_BASE + 0x4000)
#define WDT_BASE                (APB1_BASE + 0x5000)
#define TIMER_ALL_BASE          (APB1_BASE + 0x5128)
#define TIMER0_BASE             (APB1_BASE + 0x5100)
#define TIMER1_BASE             (APB1_BASE + 0x5200)
#define TIMER2_BASE             (APB1_BASE + 0x5300)
#define TIMER3_BASE             (APB1_BASE + 0x5400)
#define TIMER4_BASE             (APB1_BASE + 0x5500)
//#define TIMER5_BASE             (APB1_BASE + 0x5600)
//#define TIMER6_BASE             (APB1_BASE + 0x5700)
//#define TIMER7_BASE             (APB1_BASE + 0x5800)
#define SUPTMR_BASE             (APB1_BASE + 0x5600)


#define HG_CRC32_BASE           (APB1_BASE + 0x7000)
#define PMU_BASE                (APB1_BASE + 0x8000)
#define LVD_BASE                (APB1_BASE + 0x8000)
#define RFDIG_BASE              (APB1_BASE + 0x9000)
#define ADKEY_BASE              (APB1_BASE + 0xa000)
#define ADKEY1_BASE             (APB1_BASE + 0xa00c)
#define ZH_RFSPI_BASE           (APB1_BASE + 0xb000)
#define RFDIGCAL_BASE           (APB1_BASE + 0xd000)

#define HG_SYSCTRL_BASE         (AHB_BASE + 0x0000)
#define HG_GPIOA_BASE           (AHB_BASE + 0x0a00)
#define HG_GPIOB_BASE           (AHB_BASE + 0x0b00)
#define HG_GPIOC_BASE           (AHB_BASE + 0x0c00)
#define M2M_DMA_BASE            (AHB_BASE + 0x1200)
#define SYS_MNT_BASE            (AHB_BASE + 0x1300)
#define SDHOST_BASE             (AHB_BASE + 0x1400)
#define LED_TIMER0_BASE         (PMU_BASE + 0x000d0)
#define LED_TIMER1_BASE         (PMU_BASE + 0x000d4)
#define LED_TIMER2_BASE         (PMU_BASE + 0x000d8)
#define LED_TIMER3_BASE         (PMU_BASE + 0x000dc)
#define HG_SUPTMR_COMM_BASE     (SUPTMR_BASE       )
#define HG_SUPTMR0_BASE         (SUPTMR_BASE + 0x1c)
#define HG_SUPTMR1_BASE         (SUPTMR_BASE + 0x2c)
#define HG_SUPTMR2_BASE         (SUPTMR_BASE + 0x3c)
#define HG_SUPTMR3_BASE         (SUPTMR_BASE + 0x4c)
#define HG_SUPTMR4_BASE         (SUPTMR_BASE + 0x5c)
#define HG_SUPTMR5_BASE         (SUPTMR_BASE + 0x6c)

#define HG_SDIO20_SLAVE_BASE    (AHB_BASE + 0x20000)
#define MODEM_BASE              (AHB_BASE + 0x40000)
#define LMAC_BASE               (AHB_BASE + 0x42000)
#define HG_GMAC_BASE            (PERIPH_BASE + 0x71000)
#define HG_USB20_DEVICE_BASE    (PERIPH_BASE + 0x80000)

typedef enum {
    HG_AHB_PT_ALL,
    HG_AHB_PT_GPIOA_DEBUNCE,
    HG_AHB_PT_GPIOB_DEBUNCE,
    HG_AHB_PT_GPIOC_DEBUNCE,
    HG_AHB_PT_M2M_DMA,
    HG_AHB_PT_SYS_MNT,
    HG_AHB_PT_SDMMC,
    HG_AHB_PT_SDIO,
    HG_AHB_PT_MODEM,
    HG_AHB_PT_LMAC,
    HG_AHB_PT_GMAC,
    HG_AHB_PT_USB20,

    HG_APB0_PT_ALL,
    HG_APB0_PT_QSPI,
    HG_APB0_PT_UART0,
    HG_APB0_PT_UART1,
    HG_APB0_PT_UART4,
    HG_APB0_PT_UART5,
    HG_APB0_PT_SPI0,
    HG_APB0_PT_SPI1,
    HG_APB0_PT_SPI2,
    HG_APB0_PT_SPI3,
    HG_APB0_PT_SPI5,
    HG_APB0_PT_SPI6,
    HG_APB0_PT_LED,
    HG_APB0_PT_IIC0,
    HG_APB0_PT_IIC1,
    HG_APB0_PT_IIC2,
    HG_APB0_PT_IIC3,
    HG_APB0_PT_IIS0,
    HG_APB0_PT_IIS1,
    HG_APB0_PT_PDM,
    HG_APB0_PT_JPEG,
    HG_APB0_PT_DVP,
    HG_APB0_PT_CMP,
    HG_APB0_PT_EFUSE,

    HG_APB1_PT_ALL,
    HG_APB1_PT_AES,
    HG_APB1_PT_WDT,
    HG_APB1_PT_TMR0,
    HG_APB1_PT_TMR1,
    HG_APB1_PT_TMR2,
    HG_APB1_PT_TMR3,
    HG_APB1_PT_STMR,
    HG_APB1_PT_SUPTMR,
    HG_APB1_PT_CRC,
    HG_APB1_PT_PMU,
    HG_APB1_PT_LVD,
    HG_APB1_PT_ADKEY,
    
} HG_Peripheral_Type;
    

/**
  * @}
  */

enum phy_rf_mode {
    INT_PHY_EXT_RF_MODE = 1, //for ext-rf case
    PHY_RF_NORMAL_MODE  = 2, //tx4001 ic normal case
    INT_RF_EXT_PHY_MODE = 3, //for transceiver case
};

#define EFUSE_OFFSET       3

#define OSC_CLK     32000000UL


#ifdef __cplusplus
}
#endif

#endif

