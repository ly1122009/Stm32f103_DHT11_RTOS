/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build NVIC.c for stm32f103c8t6
**
** ###################################################################
*/
#include "NVIC.h"

/* MACRO */
/* NVIC_EnableInterrupt */
#define INDEX_NUMBER_0 0
#define INDEX_NUMBER_1 1
#define INDEX_NUMBER_2 2
#define POSITION_REG_NUMBER_0 0
#define CONST_NVIC     32
#define ENABLE_INTERRUPT 1

/* ----------------------------------------------------------------------------
   -- Fucntion for NVIC 
   ---------------------------------------------------------------------------- */
void NVIC_EnableInterrupt(volatile unsigned int p_ID){     /* Using Enable ID module interrupt in NVIC */
		
		/* declare variable */
	volatile unsigned int Index = INDEX_NUMBER_0;
	volatile unsigned int Position_Reg = POSITION_REG_NUMBER_0;
		
	Index = p_ID / CONST_NVIC;
	Position_Reg = p_ID % CONST_NVIC;
	
	/* Enable Interrupt */
	if(Index == INDEX_NUMBER_0)
	{
		NVIC -> NVIC_ISER0 |= (ENABLE_INTERRUPT << Position_Reg);  /* Enable interrupt line 0 */
	}
	else if (Index == INDEX_NUMBER_1)
	{
		NVIC -> NVIC_ISER1 |= (ENABLE_INTERRUPT << Position_Reg);  /* Enable interrupt line 1 */
	}
	else if (Index == INDEX_NUMBER_2)
	{
		NVIC -> NVIC_ISER2 |= (ENABLE_INTERRUPT << Position_Reg);  /* Enable interrupt line 2 */
	}
	else
	{
	}
}
