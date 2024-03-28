/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build NVIC.h for stm32f103c8t6
**
** ###################################################################
*/
/* Prevention from multiple including the same memory map */
#ifndef NVIC_H_  /* Check if memory map has not been already included */
#define NVIC_H_ 

/* MACRO */
/* void NVIC_EnableInterrupt(ID) */
	#define ID_USART1 37
	#define ID_USART2 38
	#define ID_USART3 39
	#define ID_SPI1 35
	#define ID_SPI2 36
	#define ID_SPI3 51
	#define ID_EXTI0 6
	#define ID_EXTI1 7
	#define ID_EXTI2 8
	#define ID_EXTI3 9
	#define ID_EXTI4 10
	#define ID_TIM2 28
	#define ID_TIM3 29
	#define ID_TIM4 30
	#define ID_TIM5 50
	#define ID_TIM6 54
	#define ID_TIM7 55

/* ----------------------------------------------------------------------------
   -- Define register
   ---------------------------------------------------------------------------- */
/* NVIC */
typedef struct {
  volatile unsigned int NVIC_ISER0;
  volatile unsigned int NVIC_ISER1;
  volatile unsigned int NVIC_ISER2;
  unsigned char dummy[120];
  volatile unsigned int NVIC_ICER0;
  volatile unsigned int NVIC_ICER1;
  volatile unsigned int NVIC_ICER2;
  unsigned char dummy1[120];
  volatile unsigned int NVIC_ISPR0;
  volatile unsigned int NVIC_ISPR1;
  volatile unsigned int NVIC_ISPR2;
  unsigned char dummy2[120];
  volatile unsigned int NVIC_ICPR0;
  volatile unsigned int NVIC_ICPR1;
  volatile unsigned int NVIC_ICPR2;
  unsigned char dummy3[120];
  volatile unsigned int NVIC_IAPR0;
  volatile unsigned int NVIC_IAPR1;
  volatile unsigned int NVIC_IAPR2;
  unsigned char dummy4[248];
  volatile unsigned int NVIC_IPR0;
  volatile unsigned int NVIC_IPR1;
  volatile unsigned int NVIC_IPR2;
  volatile unsigned int NVIC_IPR3;
  volatile unsigned int NVIC_IPR4;
  volatile unsigned int NVIC_IPR5;
  volatile unsigned int NVIC_IPR6;
  volatile unsigned int NVIC_IPR7;
  volatile unsigned int NVIC_IPR8;
  volatile unsigned int NVIC_IPR9;
  volatile unsigned int NVIC_IPR10;
  volatile unsigned int NVIC_IPR11;
  volatile unsigned int NVIC_IPR12;
  volatile unsigned int NVIC_IPR13;
  volatile unsigned int NVIC_IPR14;
  volatile unsigned int NVIC_IPR15;
  volatile unsigned int NVIC_IPR16;
  volatile unsigned int NVIC_IPR17;
  volatile unsigned int NVIC_IPR18;
  volatile unsigned int NVIC_IPR19;
  volatile unsigned int NVIC_IPR20;
  unsigned char dummy5[2784];
  volatile unsigned int NVIC_STIR;
} NVIC_Type;
#define NVIC_BASE_ADDRESS 0xE000E100
#define NVIC		((NVIC_Type*)NVIC_BASE_ADDRESS)

/* ----------------------------------------------------------------------------
   -- Fucntion for NVIC
   ---------------------------------------------------------------------------- */
void NVIC_EnableInterrupt(volatile unsigned int p_ID);    /* Using Enable ID module interrupt in NVIC */

#endif  /* #if !defined(NVIC_H_) */

