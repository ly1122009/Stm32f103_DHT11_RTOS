/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build RCC.c for stm32f103c8t6
**
** ###################################################################
*/
#include "RCC.h"

/* MACRO */
#define APB1_DIV_1         0
#define APB2_DIV_1         0

/* RCC_ClockHSI */
/* RCC_ClockHSE */
#define SW	           0
#define SW_HSE		   1
#define HSION		   0
#define HSION_ENABLE   1
#define HSEON		   16
#define HSEON_ENABLE   1

/* RCC_ClockPLL_HSI */
#define PLLON	           24
#define PLLON_ENALBE	   1
#define PLLSRC             16
#define PLLSRC_HSE         1
#define PLLMUL             18
#define CONST_PLLMUL       2
#define SW_PLL             2

/* RCC_ClockPLL_HSE */
#define PLLXTPRE           17
#define PLLXTPRE_DIV_2     1

/* RCC_CongfigAHBPrescaler */
#define HPRE               4

/* RCC_CongfigAPBPrescaler1 */
#define PPRE1               8

/* RCC_CongfigAPBPrescaler2 */
#define PPRE2               11

/* RCC_EnableAndCongfigAPB2 */
#define ENABLE_MODULE       1

/* ----------------------------------------------------------------------------
   -- Fucntion for RCC
   ---------------------------------------------------------------------------- */
void RCC_ClockHSI(void)  /* Using clock HSI (8Mhz) */
{
	/* Clock RCC - HSI */
	/* Congfig SW */
	RCC_reg -> RCC_CFCR &= ~(3u << SW);  /* Clear bit */
	RCC_reg -> RCC_CFCR |= (SW_HSE << SW);  /* Switch sang HSE truoc */
	
	/* Congfig HSI */
	RCC_reg -> RCC_CR |= (HSION_ENABLE << HSION); /* enable HSI clock */

	/* Congfig SW */
	RCC_reg -> RCC_CFCR &= ~(3u << SW);  /* Switch sang HSI lai */
}

void RCC_ClockHSE(void)	/* Using clock HSE (8MHz) */
{
	/* Clock RCC - HSE */
	/* Congfig SW */
	RCC_reg -> RCC_CFCR &= ~(3u << SW);  /* SW sang HSI */
	
	/* Congfig HSE */
	RCC_reg -> RCC_CR |= (HSEON_ENABLE << HSEON);  /* Enable clock HSE */
	
	/* SW -> HSE */
	RCC_reg -> RCC_CFCR |= (SW_HSE << SW);  /* SW sang HSE */
}

void RCC_ClockPLL_HSI(volatile unsigned int p_PLLMUL)  /* Using PLL clock (Value Clock) = (PLLMUL) * 4  (Max = 72Mhz) */
{
	/* Clock RCC: HSI -> PLL */
	
	/* Congfig SW */
	RCC_reg -> RCC_CFCR &= ~(3u << SW_HSE);  /* Clear bit */
	
	/* Congfig HSI */
	RCC_reg -> RCC_CR |= (HSION_ENABLE << HSION); /* enable HSI clock */

	/* Congfig PLL */
	/* Disable PLL */
	RCC_reg -> RCC_CR &= ~(PLLON_ENALBE << PLLON);  /* Disable PLL */
	
	/* Select PLL source */
	RCC_reg -> RCC_CFCR &= ~(PLLSRC_HSE << PLLSRC);  /* Select (HSI clock / 2) */
		
	/* Congfig PLLMUL = 13 */
	RCC_reg -> RCC_CFCR &= ~(15u << PLLMUL);  /* Clear PLLMUL */
	RCC_reg -> RCC_CFCR |= ((p_PLLMUL - CONST_PLLMUL) << PLLMUL);  /* Congfig PLLMUL = 13 */	/* PLLMUL = (2 -> 16) */
														
	/* Enable PLL */
	RCC_reg -> RCC_CR |= (PLLON_ENALBE << PLLON);  /* Enable PLL */
		
	/* Congfig SW */
	RCC_reg -> RCC_CFCR |= (SW_PLL << SW_HSE);  /* Switch sang PLL */
}

void RCC_ClockPLL_HSE(volatile unsigned int p_HSE_Div, volatile unsigned int p_PLLMUL)  /* Using PLL clock (Value Clock) = (PLLMUL) * (8 / HSE_Div)   */
{
	/* Clock RCC: HSE -> PLL */
	/* Congfig SW */
	RCC_reg -> RCC_CFCR &= ~(3u << SW);  /* Clear bit */
	RCC_reg -> RCC_CFCR |= (SW_HSE << SW);  /* Switch to HSE */
	
	/* Congfig HSE */
	RCC_reg -> RCC_CR |= (HSION_ENABLE << HSEON); /* enable HSE clock */

	/* Congfig PLL */
	/* Disable PLL */
	RCC_reg -> RCC_CR &= ~(PLLON_ENALBE << PLLON);  /* Disable PLL */
	
	/* Select PLL source */
	if( p_HSE_Div == 2 )
	{
		RCC_reg -> RCC_CFCR |= (PLLXTPRE_DIV_2 << PLLXTPRE);  /* Set (HSE / 2) is clock source */
	}
	else if ( p_HSE_Div == 1 )
	{
		RCC_reg -> RCC_CFCR &= ~(PLLXTPRE_DIV_2 << PLLXTPRE);  /* Set (HSE / 1) is clock source */
	}
	else 
	{
		return;
	}
	RCC_reg -> RCC_CFCR |= (PLLSRC_HSE << PLLSRC);  /* Select (HSE clock) */
	
	/* Congfig PLLMUL = 13 */
	RCC_reg -> RCC_CFCR &= ~(15u << PLLMUL);  /* Clear PLLMUL */
	RCC_reg -> RCC_CFCR |= ((p_PLLMUL - CONST_PLLMUL) << PLLMUL);    /* PLLMUL = (2 -> 16) */
	
	/* Enable PLL */
	RCC_reg -> RCC_CR |= (PLLON_ENALBE << PLLON);  /* Enable PLL */
		
	/* Congfig SW */
	RCC_reg -> RCC_CFCR &= ~(3u << SW); /* Clear SW */
	RCC_reg -> RCC_CFCR |= (SW_PLL << SW);  /* Switch sang PLL */
}  

void RCC_CongfigAHBPrescaler(volatile unsigned int p_AHB_DIV)  /* Using congfig number div of AHB Prescaler */
{
	/* Congfig AHB Prescaler */
	if (p_AHB_DIV == 1 )
	{
		RCC_reg -> RCC_CFCR &= ~(15u << HPRE);  /* Set div 1 */
	}
	else 
	{
		RCC_reg -> RCC_CFCR |= (p_AHB_DIV << HPRE);  /* Set AHB_DIV */
	}
}

void RCC_CongfigAPBPrescaler1(volatile unsigned int p_APB1_DIV)  /* Using congfig number div of AHB Prescaler 1 */  /* 1 , 2 , 4 , 8 */
{
	/* Congfig APB1 Prescaler */
	if (p_APB1_DIV == APB1_DIV_1)
	{
		RCC_reg -> RCC_CFCR &= ~(7u << PPRE1);  /* Set div 1 */
	}
	else 
	{
		RCC_reg -> RCC_CFCR |= (p_APB1_DIV << PPRE1);  /* Set AHB_DIV */
	}
}

void RCC_CongfigAPBPrescaler2(volatile unsigned int p_APB2_DIV)  /* Using congfig number div of AHB Prescaler 2 */  /* 1 , 2 , 4 , 8 */
{
	/* Congfig AHB Prescaler */
	if (p_APB2_DIV == APB2_DIV_1 )
	{
		RCC_reg -> RCC_CFCR &= ~(7u << PPRE2);  /* Set div 1 */
	}
	else 
	{
		RCC_reg -> RCC_CFCR |= (p_APB2_DIV << PPRE2);  /* Set AHB_DIV */
	}
}

void RCC_EnableAndCongfigAPB2(volatile unsigned int p_APB2_DIV, volatile unsigned int p_Modune_APB2){
	
	/* Set Div APB2 prescaler */
	RCC_CongfigAPBPrescaler2(p_APB2_DIV);
	
	/* Enable Modune APB2 */
	RCC_reg -> RCC_APB2ENR |= ( ENABLE_MODULE << p_Modune_APB2 );
}

void RCC_EnableAndCongfigAPB1(volatile unsigned int p_APB1_DIV, volatile unsigned int p_Modune_APB1){
	/* Set Div APB1 prescaler */
	RCC_CongfigAPBPrescaler1(p_APB1_DIV);
	
	/* Enable Modune APB1 */
	RCC_reg -> RCC_APB1ENR |= ( ENABLE_MODULE << p_Modune_APB1 );
}



