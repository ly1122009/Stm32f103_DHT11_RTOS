/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build TIMER.h for stm32f103c8t6
**
** ###################################################################
*/
/* Prevention from multiple including the same memory map */
#ifndef TIMER_H /* Check if memory map has not been already included */
#define TIMER_H

/* MACRO */
/*void TIMER_Congfig*/
	/* ModeCountUpOrDown */
		#define TIMER_Congfig_Mode_Count_Up 0
		#define TIMER_Congfig_Mode_Count_Down 1

/* ----------------------------------------------------------------------------
   -- Define register
   ---------------------------------------------------------------------------- */
/* ADVANCED CONTROL TIMER (TIM1) */
typedef struct {
	volatile unsigned int TIM_CR1;
	volatile unsigned int TIM_CR2;
	volatile unsigned int TIM_SMCR;
	volatile unsigned int TIM_DIER;
	volatile unsigned int TIM_SR;
	volatile unsigned int TIM_EGR;
	volatile unsigned int TIM_CCMR1;
	volatile unsigned int TIM_CCMR2;
	volatile unsigned int TIM_CCER;
	volatile unsigned int TIM_CNT;
	volatile unsigned int TIM_PSC;
	volatile unsigned int TIM_ARR;
	volatile unsigned int TIM_RCR;
	volatile unsigned int TIM_CCR1;
	volatile unsigned int TIM_CCR2;
	volatile unsigned int TIM_CCR3;
	volatile unsigned int TIM_CCR4;
	volatile unsigned int TIM_BDTR;
	volatile unsigned int TIM_DCR;
	volatile unsigned int TIM_DMAR;
} TIMER1_Type;
#define TIM1_BASE_ADDRESS 0x40012C00
#define TIM1		((TIMER1_Type*)TIM1_BASE_ADDRESS)

/* GENERAL PURPOSE TIMER  (TIM2 - TIM5) */
typedef struct {
	volatile unsigned int TIM_CR1;
	volatile unsigned int TIM_CR2;
	volatile unsigned int TIM_SMCR;
	volatile unsigned int TIM_DIER;
	volatile unsigned int TIM_SR;
	volatile unsigned int TIM_EGR;
	volatile unsigned int TIM_CCMR1;
	volatile unsigned int TIM_CCMR2;
	volatile unsigned int TIM_CCER;
	volatile unsigned int TIM_CNT;
	volatile unsigned int TIM_PSC;
	volatile unsigned int TIM_ARR;
	volatile unsigned int dummy;
	volatile unsigned int TIM_CCR1;
	volatile unsigned int TIM_CCR2;
	volatile unsigned int TIM_CCR3;
	volatile unsigned int TIM_CCR4;
	volatile unsigned int dummy1;
	volatile unsigned int TIM_DCR;
	volatile unsigned int TIM_DMAR;
} TIMER_Type;
#define TIM2_BASE_ADDRESS 0x40000000
#define TIM2		((TIMER_Type*)TIM2_BASE_ADDRESS)
#define TIM3_BASE_ADDRESS 0x40000400
#define TIM3		((TIMER_Type*)TIM3_BASE_ADDRESS)
#define TIM4_BASE_ADDRESS 0x40000800
#define TIM4		((TIMER_Type*)TIM4_BASE_ADDRESS)
#define TIM5_BASE_ADDRESS 0x40000C00
#define TIM5		((TIMER_Type*)TIM5_BASE_ADDRESS)

/* ----------------------------------------------------------------------------
   -- Fucntion for TIMER
   ---------------------------------------------------------------------------- */
void TIMER_Congfig(TIMER_Type*TIMERx, volatile unsigned int p_ModeCountUpOrDown, volatile unsigned int p_Clock_Hz);    /* Using Init and Congfig TIMMER */
																										   /* p_Clock_Hz: Using 8Mhz enter 8 , Using 72Mhz enter 72 */
void TIMER_Enable(TIMER_Type*TIMERx);    /* Using enable TIMER */

   
#endif 

