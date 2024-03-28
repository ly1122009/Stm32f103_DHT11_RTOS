/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build GPIO.c for stm32f103c8t6
**
** ###################################################################
*/
#include "GPIO.h"
#include "RCC.h"


/* MACRO */
/* GPIO_Output_Init */
/* GPIO_Input_Init */
	#define RCC_IO_PORT_A 2
	#define RCC_IO_PORT_B 3
	#define RCC_IO_PORT_C 4
	#define RCC_IO_PORT_D 5
	#define RCC_IO_PORT_E 6
	#define RCC_IO_PORT_F 7
	#define RCC_IO_PORT_G 8
	#define PIN_MAX_CRL 8
	#define PIN_MAX_CRH 15
	#define CONST_MUL   4
	#define CONST_INPUT 2
	
/* ----------------------------------------------------------------------------
   -- Fucntion for GPIO
   ---------------------------------------------------------------------------- */
void GPIO_Output_Init(GPIO_Type*GPIOx , volatile unsigned int p_pin)    /* Init and congfig Output PIN for GPIO */
{	
	/* Declare var */
	volatile unsigned int *GPIOx_CRH;
	volatile unsigned int *GPIOx_CRL;

	/* Enable RCC_APB2ENR */
	if( GPIOx == GPIO_A )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_A;
		GPIOx_CRH = (volatile unsigned int *)GPIO_A;
	  RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_A);
	}
	else if ( GPIOx == GPIO_B )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_B;
		GPIOx_CRH = (volatile unsigned int *)GPIO_B;
		RCC_reg -> RCC_APB2ENR |= (1<< RCC_IO_PORT_B);
	}
	else if ( GPIOx == GPIO_C )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_C;
		GPIOx_CRH = (volatile unsigned int *)GPIO_C;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_C);
	}
	else if ( GPIOx == GPIO_D )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_D;
		GPIOx_CRH = (volatile unsigned int *)GPIO_D;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_D);
	}
	else if ( GPIOx == GPIO_E )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_E;
		GPIOx_CRH = (volatile unsigned int *)GPIO_E;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_E);
	}
	else if ( GPIOx == GPIO_F )
	{
	 	GPIOx_CRL = (volatile unsigned int *)GPIO_F;
		GPIOx_CRH = (volatile unsigned int *)GPIO_F;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_F);
	}
	else if ( GPIOx == GPIO_G )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_G;
		GPIOx_CRH = (volatile unsigned int *)GPIO_G;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_G);
	}
	else
	{
		return;
	}
	/* Clear state input or output of PIN */
    if( p_pin < PIN_MAX_CRL )    /* Setting output for CRL */
	{
		GPIOx_CRL = &GPIOx -> GPIO_CRL;
		*GPIOx_CRL &= ~(15u << (CONST_MUL * p_pin));    /* Clear state */
	}
	else if (p_pin >= PIN_MAX_CRL && p_pin <= PIN_MAX_CRH)    /* Setting output for CRH */
	{
		GPIOx_CRH = &GPIOx -> GPIO_CRH;
		*GPIOx_CRH &= ~(15u<< (CONST_MUL * (p_pin - PIN_MAX_CRL) )); /* Clear state */
	}
	else
	{
		return;
	}	
	
	/* Init GPIO_CRH, GPIO_CRL */
    if( p_pin < PIN_MAX_CRL )    /* Setting output for CRL */
	{
		GPIOx_CRL = &GPIOx -> GPIO_CRL;
		*GPIOx_CRL |= (3u<< (CONST_MUL * p_pin) ); /* Setting Output */
	}
	else if (p_pin >= PIN_MAX_CRL && p_pin <= PIN_MAX_CRH)    /* Setting output for CRH */
	{
		GPIOx_CRH = &GPIOx -> GPIO_CRH;
		*GPIOx_CRH |= (3u<< (CONST_MUL * (p_pin - PIN_MAX_CRL) )); /* Setting output */
	}
	else
	{
		return;
	}	
}

void GPIO_Input_Init(GPIO_Type*GPIOx , volatile unsigned int p_pin)    /* Init and congfig Input PIN for GPIO */
{	
	/* Declare var */
	volatile unsigned int *GPIOx_CRH;
	volatile unsigned int *GPIOx_CRL;
  volatile unsigned int *GPIOx_ODR;
	
	/* Enable RCC_APB2ENR */
	if( GPIOx == GPIO_A )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_A;
		GPIOx_CRH = (volatile unsigned int *)GPIO_A;
		GPIOx_ODR = (volatile unsigned int *)GPIO_A;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_A);
	}
	else if ( GPIOx == GPIO_B )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_B;
		GPIOx_CRH = (volatile unsigned int *)GPIO_B;
		GPIOx_ODR = (volatile unsigned int *)GPIO_B;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_B);
	}
	else if ( GPIOx == GPIO_C )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_C;
		GPIOx_CRH = (volatile unsigned int *)GPIO_C;
		GPIOx_ODR = (volatile unsigned int *)GPIO_C;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_C);
	}
	else if ( GPIOx == GPIO_D )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_D;
		GPIOx_CRH = (volatile unsigned int *)GPIO_D;
		GPIOx_ODR = (volatile unsigned int *)GPIO_D;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_D);
	}
	else if ( GPIOx == GPIO_E )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_E;
		GPIOx_CRH = (volatile unsigned int *)GPIO_E;
		GPIOx_ODR = (volatile unsigned int *)GPIO_E;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_E);
	}
	else if ( GPIOx == GPIO_F )
	{
	 	GPIOx_CRL = (volatile unsigned int *)GPIO_F;
		GPIOx_CRH = (volatile unsigned int *)GPIO_F;
		GPIOx_ODR = (volatile unsigned int *)GPIO_F;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_F);
	}
	else if ( GPIOx == GPIO_G )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_G;
		GPIOx_CRH = (volatile unsigned int *)GPIO_G;
		GPIOx_ODR = (volatile unsigned int *)GPIO_G;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_G);
	}
	else
	{
		return;
	}
	
	/* Clear state input or output of PIN */
    if( p_pin < PIN_MAX_CRL )    /* Setting output for CRL */
	{
		GPIOx_CRL = &GPIOx -> GPIO_CRL;
		*GPIOx_CRL &= ~(15u << (CONST_MUL * p_pin));    /* Clear state */
	}
	else if (p_pin >= PIN_MAX_CRL && p_pin <= PIN_MAX_CRH)    /* Setting output for CRH */
	{
		GPIOx_CRH = &GPIOx -> GPIO_CRH;
		*GPIOx_CRH &= ~(15u<< (CONST_MUL * (p_pin - PIN_MAX_CRL) )); /* Clear state */
	}
	else
	{
		return;
	}	
	
	/* Init GPIO_CRH, GPIO_CRL */
    if( p_pin < PIN_MAX_CRL )    /* Setting input for CRL */
	{
		GPIOx_CRL = &GPIOx -> GPIO_CRL;
		GPIOx_ODR = &GPIOx -> GPIO_ODR;
		*GPIOx_ODR &= ~(1u << p_pin); /* Set bit 0 - pulldown */
		*GPIOx_CRL &= ~(3u << ((CONST_MUL * p_pin) + CONST_INPUT) ); /* Clear bit */
		*GPIOx_CRL |= (2u << ((CONST_MUL * p_pin) + CONST_INPUT) ); /* Setting Input - pulldown */
		
	}
	else if (p_pin >= PIN_MAX_CRL && p_pin <= PIN_MAX_CRH)    /* Setting input for CRH */
	{
		GPIOx_CRH = &GPIOx -> GPIO_CRH;
		GPIOx_ODR = &GPIOx -> GPIO_ODR;
		*GPIOx_ODR &= ~(1u << p_pin); /* Set bit 0 - pulldown */
		*GPIOx_CRH &= ~(3u << ((CONST_MUL * p_pin) + CONST_INPUT) ); /* Clear bit */
		*GPIOx_CRH |= (2u << ((CONST_MUL * (p_pin - PIN_MAX_CRL)) + CONST_INPUT)); /* Setting Input - pulldown */
	}
	else
	{
		return;
	}	
}

/* Set floating mode in input state */
void GPIO_Input_Init_Floating(GPIO_Type*GPIOx, volatile unsigned int p_pin)
{
		/* Declare var */
	volatile unsigned int *GPIOx_CRH;
	volatile unsigned int *GPIOx_CRL;
	
		/* Enable RCC_APB2ENR */
	if( GPIOx == GPIO_A )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_A;
		GPIOx_CRH = (volatile unsigned int *)GPIO_A;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_A);
	}
	else if ( GPIOx == GPIO_B )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_B;
		GPIOx_CRH = (volatile unsigned int *)GPIO_B;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_B);
	}
	else if ( GPIOx == GPIO_C )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_C;
		GPIOx_CRH = (volatile unsigned int *)GPIO_C;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_C);
	}
	else if ( GPIOx == GPIO_D )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_D;
		GPIOx_CRH = (volatile unsigned int *)GPIO_D;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_D);
	}
	else if ( GPIOx == GPIO_E )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_E;
		GPIOx_CRH = (volatile unsigned int *)GPIO_E;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_E);
	}
	else if ( GPIOx == GPIO_F )
	{
	 	GPIOx_CRL = (volatile unsigned int *)GPIO_F;
		GPIOx_CRH = (volatile unsigned int *)GPIO_F;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_F);
	}
	else if ( GPIOx == GPIO_G )
	{
		GPIOx_CRL = (volatile unsigned int *)GPIO_G;
		GPIOx_CRH = (volatile unsigned int *)GPIO_G;
		RCC_reg -> RCC_APB2ENR |= (1 << RCC_IO_PORT_G);
	}
	else
	{
		return;
	}
		/* Init GPIO_CRH, GPIO_CRL */
    if( p_pin < PIN_MAX_CRL )    /* Setting input for CRL */
	{
		GPIOx_CRL = &GPIOx -> GPIO_CRL;
		*GPIOx_CRL &= ~(3u << ((CONST_MUL * p_pin) + CONST_INPUT) ); /* Clear bit */
		*GPIOx_CRL |= (1u << ((CONST_MUL * p_pin) + CONST_INPUT) ); /* Setting floating input */
	}
	else if (p_pin >= PIN_MAX_CRL && p_pin <= PIN_MAX_CRH)    /* Setting input for CRH */
	{
		GPIOx_CRH = &GPIOx -> GPIO_CRH;
		*GPIOx_CRH &= ~(3u << ((CONST_MUL * p_pin) + CONST_INPUT) ); /* Clear bit */
		*GPIOx_CRH |= (1u << ((CONST_MUL * (p_pin - PIN_MAX_CRL)) + CONST_INPUT)); /* Setting floating input */
	}
	else
	{
		return;
	}	
}

void GPIO_SetHighPIN(GPIO_Type*GPIOx, volatile unsigned int p_pin){    /* Set ON for p_pin PIN */
	GPIOx -> GPIO_ODR |= (1u << p_pin);
}

void GPIO_SetLowPIN(GPIO_Type*GPIOx, volatile unsigned int p_pin){    /* Set OFF for p_pin PIN */
	GPIOx -> GPIO_ODR &= ~(1u << p_pin);
}

void GPIO_SetTogglePIN(GPIO_Type*GPIOx, volatile unsigned int p_pin){    /* Toggle for p_pin PIN */
	GPIOx -> GPIO_ODR ^= (1u << p_pin);
}

/* Function receive response DHT11 */
unsigned int GPIO_ReadPIN(GPIO_Type*GPIOx, volatile unsigned int p_pin){
	return ((GPIOx -> GPIO_IDR) & (1u << p_pin));
}



