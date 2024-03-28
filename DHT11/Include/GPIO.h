/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build GPIO.h for stm32f103c8t6
**
** ###################################################################
*/
/* Prevention from multiple including the same memory map */
#ifndef GPIO_H_  /* Check if memory map has not been already included */
#define GPIO_H_ 

/* MACRO */
/* GPIO_Output_Init */
/* GPIO_Input_Init */
/* GPIO_SetHighPIN */
/* GPIO_SetLowPIN */
/* GPIO_SetTogglePIN */
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
/* GPIO */
typedef struct {
	volatile unsigned int GPIO_CRL;
	volatile unsigned int GPIO_CRH;
	volatile unsigned int GPIO_IDR;
	volatile unsigned int GPIO_ODR;
	volatile unsigned int GPIO_BSRR;
	volatile unsigned int GPIO_BRR;
	volatile unsigned int GPIO_LCKR;
} GPIO_Type;
#define GPIOA_BASE_ADDRESS 0X40010800
#define GPIO_A					((GPIO_Type*)GPIOA_BASE_ADDRESS)
#define GPIOB_BASE_ADDRESS 0x40010C00
#define GPIO_B					((GPIO_Type*)GPIOB_BASE_ADDRESS)
#define GPIO_C_BASE_ADDRESS 0x40011000
#define GPIO_C					((GPIO_Type*)GPIO_C_BASE_ADDRESS)
#define GPIO_D_BASE_ADDRESS 0x40011400
#define GPIO_D					((GPIO_Type*)GPIO_D_BASE_ADDRESS)
#define GPIO_E_BASE_ADDRESS 0x40011800
#define GPIO_E					((GPIO_Type*)GPIO_E_BASE_ADDRESS)
#define GPIO_F_BASE_ADDRESS 0x40011C00
#define GPIO_F					((GPIO_Type*)GPIO_F_BASE_ADDRESS)
#define GPIO_G_BASE_ADDRESS 0x40012000
#define GPIO_G					((GPIO_Type*)GPIO_G_BASE_ADDRESS)

/* ----------------------------------------------------------------------------
   -- Fucntion for GPIO
   ---------------------------------------------------------------------------- */
void GPIO_Output_Init(GPIO_Type*GPIOx, volatile unsigned int p_pin);    /* Init and congfig Output PIN for GPIO */
void GPIO_Input_Init(GPIO_Type*GPIOx, volatile unsigned int p_pin);    /* Init and congfig Input PIN for GPIO */
void GPIO_Input_Init_Floating(GPIO_Type*GPIOx, volatile unsigned int p_pin);   /* Set floating mode in input state */
void GPIO_SetHighPIN(GPIO_Type*GPIOx, volatile unsigned int p_pin);    /* Set ON for p_pin PIN */
void GPIO_SetLowPIN(GPIO_Type*GPIOx, volatile unsigned int p_pin);     /* Set OFF for p_pin PIN */
void GPIO_SetTogglePIN(GPIO_Type*GPIOx, volatile unsigned int p_pin);  /* Toggle for p_pin PIN */
unsigned int GPIO_ReadPIN(GPIO_Type*GPIOx, volatile unsigned int p_pin);    /* Read data of a pin */

#endif
