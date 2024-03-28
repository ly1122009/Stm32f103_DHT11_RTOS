/*
** ###################################################################
**     Processor:           STM32F103C8T6
**     Compiler:            Keil ARM C/C++ Compiler
**     Version:             rev. 1.0, 25/01/2024 - 19:58:27
**
**     Abstract:
**         Build USART.h for stm32f103c8t6
**
** ###################################################################
*/
/* Prevention from multiple including the same memory map */
#ifndef USART_H_H  /* Check if memory map has not been already included */
#define USART_H_H 

/* MACRO */
/* USART */	
	/* void USART_Congfig(USART_Type*USARTx, BaudRate, ClockSource, BitData,Parity ,StopBit)*/
		/* Bit data */
		#define USART_Congfig_Bitdata_8 0
		#define USART_Congfig_Bitdata_9 1
		/* Parity */
		#define USART_Congfig_Parity_NoParity 0
		#define USART_Congfig_Parity_Even 		1
		#define USART_Congfig_Parity_Odd 			2
		/* Stop bit */ /* Stop bit 0,5 and 1,5 are not available for UART4 and UART5 */
		#define USART_Congfig_StopBit_1 			0
		#define USART_Congfig_StopBit_05 			1
		#define USART_Congfig_StopBit_2 			2
		#define USART_Congfig_StopBit_15 			3
		
	/* void USART_Congfig_IT(Use_Interrupt_For)*/
		#define USART_Congfig_IT_Use_Interrupt_For_Receiver 1
		#define USART_Congfig_IT_Use_Interrupt_For_Transmitter 2
		#define USART_Congfig_IT_Use_Interrupt_For_Both_Receiver_Transmitter 3
	
	/* unsigned int USART_CheckFlagInterrupt(CheckBitReceiverOrTransmitter) */
		#define USART_CheckFlagInterrupt_CheckBitReceiverOrTransmitter_Receiver 1
		#define USART_CheckFlagInterrupt_CheckBitReceiverOrTransmitter_Transmitter 2
	
	/* void USART_ClearFlagInterrupt(Flag_Receiver_Or_Transmitter) */
		#define USART_ClearFlagInterrupt_Flag_Receiver 1
		#define USART_ClearFlagInterrupt_Flag_Transmitter 2
		#define USART_ClearFlagInterrupt_Flag_Both_Transmitter_And_Receiver 3

/* ----------------------------------------------------------------------------
   -- Define register
   ---------------------------------------------------------------------------- */
/* USART */
typedef struct {
  volatile unsigned int SR;
  volatile unsigned int DR;
  volatile unsigned int BRR;
  volatile unsigned int CR1;
  volatile unsigned int CR2;
  volatile unsigned int CR3;
  volatile unsigned int GTPR;
} USART_Type;
#define USART1_BASE_ADDRESS 0x40013800
#define USART1		((USART_Type*)USART1_BASE_ADDRESS)
#define USART2_BASE_ADDRESS 0x40004400
#define USART2		((USART_Type*)USART2_BASE_ADDRESS)
#define USART3_BASE_ADDRESS 0x40004800
#define USART3		((USART_Type*)USART3_BASE_ADDRESS)
#define UART4_BASE_ADDRESS 0x40004C00
#define UART4		((USART_Type*)UART4_BASE_ADDRESS)
#define UART5_BASE_ADDRESS 0x40004C00
#define UART5		((USART_Type*)UART5_BASE_ADDRESS)

/* ----------------------------------------------------------------------------
   -- Fucntion for USART
   ---------------------------------------------------------------------------- */
/* USART */
/* Init USART */
void USART_InitRxTxPORT_USART2(void);  /* Using init GPIO Tx Rx in USART2 */
void USART_Congfig(USART_Type*USARTx, volatile unsigned int p_BaudRate, volatile unsigned int p_ClockSource, volatile unsigned int p_BitData, volatile unsigned int p_Parity, volatile unsigned int p_StopBit);    /* Using Init and Congfig USART without Interrupt */
void USART_Congfig_IT(USART_Type*USARTx,volatile unsigned int p_Use_Interrupt_For ,volatile unsigned int p_BaudRate, volatile unsigned int p_ClockSource, volatile unsigned int p_BitData, volatile unsigned int p_Parity, volatile unsigned int p_StopBit);    /* Using Init and Congfig USART with Interrupt */   
void USART_Enable(USART_Type*USARTx); /* Using Enable USARTx */
void USART_Disable(USART_Type*USARTx); /* Using Disable USARTx */

/* Check data */
unsigned int USART_CheckFlagInterrupt(USART_Type*USARTx, volatile unsigned int p_CheckBitReceiverOrTransmitter);    /* Using check Flag USART interrupt */
void USART_ClearFlagInterrupt(USART_Type*USARTx, volatile unsigned int p_Flag_Receiver_Or_Transmitter);    /* Clear Flag USART interrupt */

/* Operation */
void USART_Sendchar(USART_Type*USARTx , volatile unsigned char p_Char_Send);    /* Send char datatype by USART */
void USART_SendString(USART_Type*USARTx , volatile unsigned char p_String_Send[]);    /* Send string datatype by USART */
void USART_ReceiverChar(USART_Type*USARTx, volatile unsigned char *p_Char_Receiver);    /* Receive char datatype by USART */
void USART_ReceiverString(USART_Type*USARTx, volatile unsigned char p_Char_String[], volatile unsigned int p_Strlen_String);  /* Receive string datatype by USART */
																												/* p_Strlen_String: is length of string to receive */
#endif 

