/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build EXTI.h for stm32f103c8t6
**
** ###################################################################
*/
/* Prevention from multiple including the same memory map */
#ifndef _EXTI_H_  /* Check if memory map has not been already included */
#define _EXTI_H_ 

#include "GPIO.h"

/* MACRO */
/* EXTI_congfigInterruptRising */
/* EXTI_congfigInterruptFalling */
/* EXTI_checkFlagInterrupt */
/* EXTI_clearFlagInterrupt */
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

/* ----------------------------------------------------------------------------
   -- Define register
   ---------------------------------------------------------------------------- */
/* EXTI */
typedef struct {
  volatile unsigned int EXTI_IMR;
  volatile unsigned int EXTI_EMR;
  volatile unsigned int EXTI_RTSR;
  volatile unsigned int EXTI_FTSR;
  volatile unsigned int EXTI_SWIER;
  volatile unsigned int EXTI_PR;	
} EXTI_type;
#define EXTI_BASE_ADDRESS 0x40010400
#define EXTI		((EXTI_type*)EXTI_BASE_ADDRESS)

/* ----------------------------------------------------------------------------
   -- Fucntion for EXTI
   ---------------------------------------------------------------------------- */
void EXTI_congfigInterruptRising(GPIO_Type*GPIOx, volatile unsigned int p_pin);    /* Congfig EXTI Rising for p_pin */
void EXTI_congfigInterruptFalling(GPIO_Type*GPIOx, volatile unsigned int p_pin);    /* Congfig EXTI Falling for p_pin */
unsigned int EXTI_checkFlagInterrupt(volatile unsigned int p_pin);    /* Check flag interrupt for p_pin */
void EXTI_clearFlagInterrupt(volatile unsigned int p_pin);    /* Clear flag interrupt for p_pin */

#endif  /* #if !defined(EXTI_H_) */

