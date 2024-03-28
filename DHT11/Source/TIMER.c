/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build TIMER.c for stm32f103c8t6
**
** ###################################################################
*/
#include "TIMER.h"

/* MACRO */
/* TIMER_Congfig */
#define CONST_TIMER_ARR 125
#define CONST_TIMER_PSC 7
#define DIR 4 
#define UG  0
#define UG_UPDATE 1

/* TIMER_Enable */
#define CEN 0
#define CEN_ENABLE 1

/* ----------------------------------------------------------------------------
   -- Fucntion for EXTI
   ---------------------------------------------------------------------------- */
void TIMER_Congfig(TIMER_Type*TIMERx , volatile unsigned int p_ModeCountUpOrDown, volatile unsigned int p_Clock_Hz)    /* Using Init and Congfig TIMMER */    
{
	/* Congfig TIMx */
	TIMERx -> TIM_CR1 |= (p_ModeCountUpOrDown << DIR);  /* Congfig Countdown */
	if( p_ModeCountUpOrDown == TIMER_Congfig_Mode_Count_Up)
	{
		TIMERx -> TIM_CR1 &= ~(p_ModeCountUpOrDown << DIR);  /* Congfig Countdown */
	}
	else if ( p_ModeCountUpOrDown == TIMER_Congfig_Mode_Count_Down)
	{
		TIMERx -> TIM_CR1 |= (p_ModeCountUpOrDown << DIR);  /* Congfig Countdown */
	}
	else
	{
	}
	TIMERx -> TIM_ARR = (( (p_Clock_Hz) * CONST_TIMER_ARR) - 1) ;   /* Set value count down is 1000 -> it's mean 1ms */
	TIMERx -> TIM_PSC = CONST_TIMER_PSC;  /* Set Prescaler value DIV = 80 ( it's mean 8MHz / 8 = 1Mhz ) */
	TIMERx -> TIM_EGR |= (UG_UPDATE << UG);  /* Generation and update register when CNT == 0 */
}

void TIMER_Enable(TIMER_Type*TIMERx){    /* Using enable TIMER */
	/* Enable Counter */
	TIMERx -> TIM_CR1 |= (CEN_ENABLE << CEN); 
}
