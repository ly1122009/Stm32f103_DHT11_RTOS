/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build AFIO.h for stm32f103c8t6
**
** ###################################################################
*/
/* Prevention from multiple including the same memory map */
#ifndef AFIO_H_  /* Check if memory map has not been already included */
#define AFIO_H_ 

/* ----------------------------------------------------------------------------
   -- Define register
   ---------------------------------------------------------------------------- */
/* AFIO */
typedef struct {
  volatile unsigned int AFIO_EVCR;
  volatile unsigned int AFIO_MAPR;
  volatile unsigned int AFIO_EXTICR1;
  volatile unsigned int AFIO_EXTICR2;
  volatile unsigned int AFIO_EXTICR3;
  volatile unsigned int AFIO_EXTICR4;
  unsigned char dummy[8];
  volatile unsigned int AFIO_MAPR2;	
} AFIO_type;
#define AFIO_BASE_ADDRESS 0x40010000
#define AFIO		((AFIO_type*)AFIO_BASE_ADDRESS)

#endif
