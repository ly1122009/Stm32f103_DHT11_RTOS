/*
* Title: Scheduling the task receive and transfer a data frame using UART
* Filename: main.h
* Content: main source include file
*/
#ifndef _MAIN_H_
#define _MAIN_H_

/* Include the library  */
#include "RCC.h"
#include "GPIO.h"
#include "AFIO.h"
#include "NVIC.h"
#include "STK.h"
#include "TIMER.h"
#include "USART.h"
#include "EXTI.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DHT11.h"

/* Include the library */
#include "FreeRTOS.h"
#include "task.h"

/* Define time delay */
#define DELAY_1SECOND 1000
#define DELAY_2SECOND 2000

/* Define the pin of LED */
#define LED_PC13 13

/* Stack Depth of task */
#define STACKDEPTH_UNIT 200

/* Priority of Task */
#define PRIORITY_REALTIME 0

/* Toggle Led PC13 */
static void toggle_led_PC13(void* p_ptrVoid);

/* Receive data from DHT11 */
static void Rec_DHT11(void* p_ptrVoid);

/* While true */
#define TRUE 1

/* Define trash Value */
#define VALUE_VOID 0 

/* Define Baudrate value and Value Clock using */
#define BAUDRATE_14400 14400
#define CLOCK_8MHZ 8000

/* Define MAX dataframe */
#define MAXDATAFRAME 3

/* Define Data PIN DHT11 */
#define PIN_DHT11 PIN_7

/* Define delay */
#define DELAY_80US 8
#define DELAY_1S   10000

/* Variable save data int */
volatile static unsigned char Data_Int_RH = 'a';
volatile static unsigned char Data_Int_T = VALUE_VOID;

/* EXTI1 interupt function */
void EXTI1_IRQHandler(void);

#endif /* _MAIN_H_ */

