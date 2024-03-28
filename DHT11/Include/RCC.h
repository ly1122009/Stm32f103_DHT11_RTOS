/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build RCC.h for stm32f103c8t6
**
** ###################################################################
*/
/* Prevention from multiple including the same memory map */
#ifndef RCC_H_  /* Check if memory map has not been already included */
#define RCC_H_ 

/* MACRO */
/* RCC_ClockPLL_HSE(p_HSE_Div) */
	#define HSE_DIV_2    2
	#define HSE_NO_DIV   1

/* void RCC_CongfigAHBPrescaler(AHB_DIV) */
	#define AHB_1 0
	#define AHB_2 8
	#define AHB_4 9
	#define AHB_8 10
	#define AHB_16 11
	#define AHB_64 12
	#define AHB_128 13
	#define AHB_256 14
	#define AHB_512 15

	/* void RCC_CongfigAHBPrescaler1(AHB1_DIV) */
	#define APB1_1 0
	#define APB1_2 4
	#define APB1_4 5
	#define APB1_8 6
	#define APB1_16 7

	/* void RCC_CongfigAHBPrescaler1(AHB1_DIV) */
	#define APB2_1 0
	#define APB2_2 4
	#define APB2_4 5
	#define APB2_8 6
	#define APB2_16 7

	/* void RCC_EnableAndCongfigAPB2(volatile unsigned int APB2_DIV, volatile unsigned int Modune_APB2); */
		/* Modune_APB2 */
		#define APB2_PORTA 2
		#define APB2_PORTB 3
		#define APB2_PORTC 4
		#define APB2_PORTD 5
		#define APB2_PORTE 6
		#define APB2_PORTF 7
		#define APB2_PORTG 8
		#define APB2_TIM1 11
		#define APB2_USART1 14
		#define APB2_SPI1 12

		/* APB2_DIV */
		#define APB2_DIV1 0
		#define APB2_DIV2 4
		#define APB2_DIV4 5
		#define APB2_DIV8 6
		#define APB2_DIV16 7
		
	/* void RCC_EnableAndCongfigAPB1(volatile unsigned int APB1_DIV, volatile unsigned int Modune_APB1); */
		/* Modune_APB1 */
		#define APB1_TIM2 0
		#define APB1_TIM3 1
		#define APB1_TIM4 2
		#define APB1_TIM5 3
		#define APB1_USART2 17
		#define APB1_USART3 18
		#define APB1_USART4 19
		#define APB1_USART5 20
		#define APB1_SPI3 15
		#define APB1_SPI2 14

		/* APB1_DIV */
		#define APB1_DIV1 0
		#define APB1_DIV2 4
		#define APB1_DIV4 5
		#define APB1_DIV8 6
		#define APB1_DIV16 7
		#define APB2_USART1 14

	/* RCC_EnableAndCongfigAPB2(APB2_Module, APB2_DIV)*/
		/* Modune_APB1 */
		#define APB2_USART1 14
		/* APB1_DIV */
		#define APB1_DIV1 0
		#define APB1_DIV2 4
		#define APB1_DIV4 5
		#define APB1_DIV8 6
		#define APB1_DIV16 7
			
/* ----------------------------------------------------------------------------
   -- Define register
   ---------------------------------------------------------------------------- */
/* RCC */
typedef struct 
{
	volatile unsigned int RCC_CR;
	volatile unsigned int RCC_CFCR;
	volatile unsigned int RCC_CIR;
	volatile unsigned int RCC_APB2RSTR;
	volatile unsigned int RCC_APB1RSTR;
	volatile unsigned int RCC_AHBENR;
	volatile unsigned int RCC_APB2ENR;
	volatile unsigned int RCC_APB1ENR;
	volatile unsigned int RCC_BDCR;
	volatile unsigned int RCC_CRS;
} RCC_REG;

#define RCC_BASE_ADDRESS 0x40021000
#define RCC_reg          ((RCC_REG * )RCC_BASE_ADDRESS)

/* ----------------------------------------------------------------------------
   -- Fucntion for RCC
   ---------------------------------------------------------------------------- */
/* RCC */
void RCC_ClockHSI(void);  /* Using source clock HSI (8Mhz) */
void RCC_ClockHSE(void);	/* Using source clock HSE (8MHz) */
void RCC_ClockPLL_HSI(volatile unsigned int p_PLLMUL);    /* Using congfig PLL for HSI source */
													/* Using PLL clock (Value Clock) = (PLLMUL) * 4  (Max = 72Mhz) */	 /* PLLMUL = (2 -> 16) */

void RCC_ClockPLL_HSE(volatile unsigned int p_HSE_Div, volatile unsigned int p_PLLMUL);  /* Using congfig PLL for HSI source */
																			 /* Using PLL clock (Value Clock) = (PLLMUL) * (8 / HSE_Div)   */   /* PLLMUL = (2 -> 16) */ 

void RCC_CongfigAHBPrescaler(volatile unsigned int p_AHB_DIV);  /* Using congfig AHB */
														  /* Using congfig number div of AHB Prescaler */  /* 2 , 4 , 8 , 16, 64, 128, 256, 512 */

void RCC_CongfigAPBPrescaler1(volatile unsigned int p_AHB1_DIV);  /* Using congfig number div of AHB Prescaler 1 */  /* 1 , 2 , 4 , 8 */
void RCC_CongfigAPBPrescaler2(volatile unsigned int p_AHB2_DIV);  /* Using congfig number div of AHB Prescaler 2 */  /* 1,  2 , 4 , 8 */
void RCC_EnableAndCongfigAPB2(volatile unsigned int p_APB2_DIV, volatile unsigned int p_Module_APB2); /* Using enable and congfig APB2 */
																						  /* not exceed 72 Mhz */

void RCC_EnableAndCongfigAPB1(volatile unsigned int p_APB1_DIV, volatile unsigned int p_Module_APB1); /* Using enable and congfig APB1 */
																						  /* not exceed 36 Mhz */

#endif

