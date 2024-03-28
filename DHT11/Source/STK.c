/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build Systick.c for stm32f103c8t6
**
** ###################################################################
*/
#include "STK.h"

/* MACRO */
#define VALUE_INIT 0

/* STK_CongfigSystick */
#define CLKSOURCE 2
#define CLKSOURCE_AHB 1 
#define TICKINT 1
#define TICKINT_COUNTDOWNTOZERO 1
#define CURRENT 0
#define CLEAR_CURRENT_VAL 1
#define CONST_FIX_LOAD 71999

/* STK_EnableSystick */
#define ENABLE_STK 0
#define ENABLE 1

/* STK_CheckFlag */
#define COUNTFLAG 16
#define CHECK_FLAG 1

/* STK_ClearFlag */
#define CLEAR_FLAG 1

/* Variable using to count Tick */
volatile unsigned int count_Tick = VALUE_INIT;

/* ----------------------------------------------------------------------------
   -- Fucntion for EXTI
   ---------------------------------------------------------------------------- */
void STK_InitSystick_ms(volatile unsigned int p_SourceClock){    /* Using set time count */
	STK -> STK_CTRL |= (CLKSOURCE_AHB << CLKSOURCE);  /* Select source clock Processor clock (AHB) */
	STK -> STK_CTRL |= (TICKINT_COUNTDOWNTOZERO << TICKINT);  /* using exception when count down to zero */
	
	/* Congfig Reload value */
	STK -> STK_LOAD = (p_SourceClock);  /* 71999u ~ 1ms */
	
	/* Clear current value to zero */
	STK -> STK_VAL |= (CLEAR_CURRENT_VAL << CURRENT);  /* Write any value to clear */
}

void STK_InitSystick_10us(volatile unsigned int p_SourceClock){
	STK -> STK_CTRL |= (CLKSOURCE_AHB << CLKSOURCE);  /* Select source clock Processor clock (AHB) */
	STK -> STK_CTRL |= (TICKINT_COUNTDOWNTOZERO << TICKINT);  /* using exception when count down to zero */
	
	/* Congfig Reload value */
	STK -> STK_LOAD = (p_SourceClock / 100);  /* 71999u ~ 1ms */
	
	/* Clear current value to zero */
	STK -> STK_VAL |= (CLEAR_CURRENT_VAL << CURRENT);  /* Write any value to clear */
}

void STK_EnableSystick(void){    /* Using enable STK */
		/* Enable STK */
	STK -> STK_CTRL |= (ENABLE << ENABLE_STK);  /* Enable STK */
}

unsigned int STK_CheckFlag(void){    /* Using disable STK */
	return STK -> STK_CTRL & (CHECK_FLAG << COUNTFLAG); /* Check flag */
}	

void STK_ClearFlag(void){    /* Using clear flag STK */
	STK -> STK_CTRL |= (CLEAR_FLAG << COUNTFLAG);  /* Clear flag */
}

void STK_DisableSystick(void){    /* Using enable STK */
		/* Disable STK */
	STK -> STK_CTRL &= ~(ENABLE << ENABLE_STK);  /* Enable STK */	
}

void STK_Delay_ms(volatile unsigned int p_ms){
	STK_EnableSystick();
	/* Wait for dalay finish */
	while(count_Tick < p_ms){}
	count_Tick = VALUE_INIT;
	STK_DisableSystick();
}

/* Delay micro second */
void STK_Delay_10us(volatile unsigned int p_us){
	STK_EnableSystick();
	/* Wait for dalay finish */
	while(count_Tick < p_us){}
	count_Tick = VALUE_INIT;
	STK_DisableSystick();
}  

void SysTick_Handler(void){  /* Function STK in startup file*/
	if(STK_CheckFlag())
	{
		count_Tick++;
		STK_ClearFlag();
	}
}



