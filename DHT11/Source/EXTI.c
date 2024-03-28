/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build EXTI.c for stm32f103c8t6
**
** ###################################################################
*/
#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"
#include "AFIO.h"



/* MACRO */
#define PIN_0    0
#define PIN_1    1
#define PIN_2    2
#define PIN_3    3
#define PIN_4    4
#define PIN_5    5
#define PIN_6    6
#define PIN_7    7
#define PIN_8    8
#define PIN_9    9
#define PIN_10   10
#define PIN_11    11
#define PIN_12    12
#define PIN_13    13
#define PIN_14    14
#define PIN_15    15

	/* EXTI_CongfigInterruptFalling */
	/* EXTI_CongfigInterruptRising */
		#define PORT_A 0
		#define PORT_B 1
		#define PORT_C 2
		#define PORT_D 3
		#define PORT_E 4
		#define PORT_F 5
		#define PORT_G 6
		#define AFIOEN 0
		#define AFIOEN_ENABLE 1
		#define EXTI0  0
		#define EXTI4  0
		#define EXTI8  0
		#define EXTI12  0
		#define UNLOCK_MASK 1
		#define FALLING_TRIGGER 1
		#define RISING_TRIGGER 1
		
	/* EXTI_CheckFlagInterrupt */
	/* EXTI_ClearFlagInterrupt */
		#define PENDING_BIT_1 1
	
/* ----------------------------------------------------------------------------
   -- Fucntion for EXTI
   ---------------------------------------------------------------------------- */
void EXTI_congfigInterruptRising(GPIO_Type*GPIOx, volatile unsigned int p_pin){    /* Congfig EXTI Rising for p_pin */
	
	/* Decleare varialbe */
	volatile unsigned int NumberEXIT_Port = PORT_A;
	
	/* Assign value to variable NumberEXIT_Port */
	if( GPIOx == GPIO_A )
	{
		NumberEXIT_Port = PORT_A; 
	}
	else if (GPIOx == GPIO_B)
	{
		NumberEXIT_Port = PORT_B; 		
	}
	else if (GPIOx == GPIO_C)
	{
		NumberEXIT_Port = PORT_C; 
	}
	else if (GPIOx == GPIO_D)
	{
		NumberEXIT_Port = PORT_D; 		
	}
	else if (GPIOx == GPIO_E)
	{
		NumberEXIT_Port = PORT_E; 		
	}
	else if (GPIOx == GPIO_F)
	{
		NumberEXIT_Port = PORT_F; 		
	}
	else if (GPIOx == GPIO_G)
	{
		NumberEXIT_Port = PORT_G; 		
	}
	else
	{
		return;
	}	
	
	/* GPIO Input */
	GPIO_Input_Init(GPIOx,p_pin);
	
	/* Enable Clock AFIO */
	RCC_reg -> RCC_APB2ENR |= (AFIOEN_ENABLE << AFIOEN);  /* Enable Clock AFIO */
	
	/* Select port and Pin */
	if ( p_pin == PIN_0 || ( p_pin > PIN_0 && p_pin <= PIN_3))
	{
		AFIO -> AFIO_EXTICR1 &= ~(15u << EXTI0);  /* Clear Select EXTI */
		AFIO -> AFIO_EXTICR1 |= (NumberEXIT_Port << EXTI0);  /* Select EXTI PA (0-3) */
	}
	else if ( p_pin >= PIN_4 && p_pin <= PIN_7 )
	{
		AFIO -> AFIO_EXTICR2 &= ~(15u << EXTI4);  /* Clear Select EXTI */
		AFIO -> AFIO_EXTICR2 |= (NumberEXIT_Port << EXTI4);  /* Select EXTI PA (4-7) */
	}
		else if ( p_pin >= PIN_8 && p_pin <= PIN_11 )
	{
		AFIO -> AFIO_EXTICR3 &= ~(15u << EXTI8);  /* Clear Select EXTI */
		AFIO -> AFIO_EXTICR3 |= (NumberEXIT_Port << EXTI8);  /* Select EXTI PA (8-11) */
	}
		else if ( p_pin >= PIN_12 && p_pin <= PIN_15 )
	{
		AFIO -> AFIO_EXTICR4 &= ~(15u << EXTI12);  /* Clear Select EXTI */
		AFIO -> AFIO_EXTICR4 |= (NumberEXIT_Port << EXTI12);  /* Select EXTI PA (12-15) */
	}
	else
	{
		return;
	}
	
	/* EXTI */
	/* Unlock mask */
	EXTI -> EXTI_IMR |= (UNLOCK_MASK << p_pin);  /* unlock mask line pin */
	
	/* Rising trigger select */
	EXTI -> EXTI_FTSR &= ~(FALLING_TRIGGER << p_pin);  /* Clear Falling edge line pin */
	EXTI -> EXTI_RTSR |= (RISING_TRIGGER << p_pin);  /* Set Rising edge line pin */
}

void EXTI_congfigInterruptFalling(GPIO_Type*GPIOx, volatile unsigned int p_pin){    /* Congfig EXTI Falling for p_pin */
	
	/* Decleare varialbe */
	volatile unsigned int NumberEXIT_Port = PORT_A;
	
	/* Assign value to variable NumberEXIT_Port */
	if( GPIOx == GPIO_A )
	{
		NumberEXIT_Port = PORT_A; 
	}
	else if (GPIOx == GPIO_B)
	{
		NumberEXIT_Port = PORT_B; 		
	}
	else if (GPIOx == GPIO_C)
	{
		NumberEXIT_Port = PORT_C; 
	}
	else if (GPIOx == GPIO_D)
	{
		NumberEXIT_Port = PORT_D; 		
	}
	else if (GPIOx == GPIO_E)
	{
		NumberEXIT_Port = PORT_E; 		
	}
	else if (GPIOx == GPIO_F)
	{
		NumberEXIT_Port = PORT_F; 		
	}
	else if (GPIOx == GPIO_G)
	{
		NumberEXIT_Port = PORT_G; 		
	}
	else
	{
		return;
	}	
	/* GPIO Input */
	GPIO_Input_Init_Floating(GPIOx,p_pin);
	
	/* Enable Clock AFIO */
	RCC_reg -> RCC_APB2ENR |= (AFIOEN_ENABLE << AFIOEN);  /* Enable Clock AFIO */
	
	/* AFIO */
	/* Select port and Pin */
	if ( p_pin == PIN_0 || ( p_pin > PIN_0 && p_pin <= PIN_3))
	{
		AFIO -> AFIO_EXTICR1 &= ~(15u << EXTI0);  /* Clear Select EXTI */
		AFIO -> AFIO_EXTICR1 |= (NumberEXIT_Port << EXTI0);  /* Select EXTI PA (0-3) */
	}
	else if ( p_pin >= PIN_4 && p_pin <= PIN_7 )
	{
		AFIO -> AFIO_EXTICR2 &= ~(15u << EXTI4);  /* Clear Select EXTI */
		AFIO -> AFIO_EXTICR2 |= (NumberEXIT_Port << EXTI4);  /* Select EXTI PA (4-7) */
	}
		else if ( p_pin >= PIN_8 && p_pin <= PIN_11 )
	{
		AFIO -> AFIO_EXTICR3 &= ~(15u << EXTI8);  /* Clear Select EXTI */
		AFIO -> AFIO_EXTICR3 |= (NumberEXIT_Port << EXTI8);  /* Select EXTI PA (8-11) */
	}
		else if ( p_pin >= PIN_12 && p_pin <= PIN_15 )
	{
		AFIO -> AFIO_EXTICR4 &= ~(15u << EXTI12);  /* Clear Select EXTI */
		AFIO -> AFIO_EXTICR4 |= (NumberEXIT_Port << EXTI12);  /* Select EXTI PA (12-15) */
	}
	else
	{
		return;
	}
	
	/* EXTI */
	/* Unlock mask */
	EXTI -> EXTI_IMR |= (UNLOCK_MASK << p_pin);  /* unlock mask line pin */
	
	/* Falling trigger select */
	EXTI -> EXTI_FTSR |= (FALLING_TRIGGER << p_pin);  /* Set Falling edge line pin */
	EXTI -> EXTI_RTSR &= ~(RISING_TRIGGER << p_pin);  /* Clear Rising edge line pin */
			
}

unsigned int EXTI_checkFlagInterrupt(volatile unsigned int p_pin){    /* Check flag interrupt for p_pin */
	
	/* Check flag interrupt */
	return EXTI -> EXTI_PR & (PENDING_BIT_1 << p_pin);
	
}

void EXTI_clearFlagInterrupt(volatile unsigned int p_pin){    /* Clear flag interrupt for p_pin */
	
	/* Clear flag */
	EXTI -> EXTI_PR |= (PENDING_BIT_1 << p_pin);  /* Write 1 to clear flag */
	
}



