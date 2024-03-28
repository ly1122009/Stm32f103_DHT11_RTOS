/*
* Filename: DHT11.c
* Content: Source code for DHT11 module
*/
#include "DHT11.h"
#include "GPIO.h"
#include "STK.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* void DHT11_Start */
#define DELAY_START_18MS 1800
#define DELAY_START_20US 2

/* int DHT11_check_response */
#define FALSE 0
#define TRUE 	1
#define DELAY_RESPONSE_40US 4
#define DELAY_RESPONSE_80US 8

/* char DHT_readData */
#define VALUE_INIT 0
#define SIZE_OF_A_FRAME 8
#define DELAY_40US 4

/* Send bit start */
void DHT11_Start(GPIO_Type*GPIOx, volatile unsigned int p_Pin)
{
	/* Init GPIO for DHT11 and set high */
	GPIO_Output_Init(GPIOx, p_Pin);
	//GPIO_SetHighPIN(GPIOx, p_Pin);
	
	/* Set start bit */
	GPIO_SetLowPIN(GPIOx, p_Pin);	
	
	/* Delay 18ms */
	STK_Delay_10us(DELAY_START_18MS);
	
	/* Stop send */
	GPIO_SetHighPIN(GPIOx, p_Pin);
	
	/* Delay 20us */
	STK_Delay_10us(DELAY_START_20US);
	
	/* Set input */
	GPIO_Input_Init_Floating(GPIOx, p_Pin);
}

/* Check response from DHT11 */
DHT11_Result_t DHT11_check_response(GPIO_Type*GPIOx, volatile unsigned int p_Pin)
{
	/* Variable check response from DHT11 */
	volatile unsigned int response_check = FALSE;
	
	/* Delay 40us */
	STK_Delay_10us(DELAY_RESPONSE_40US);
	
	/* Check response from DHT11 at 40us */
	if( !GPIO_ReadPIN(GPIOx, p_Pin) )
	{
		/* If bit 0, continue check after 80us. */
		STK_Delay_10us(DELAY_RESPONSE_80US);
		
		/* Check bit if bit at 40us diff vs at 120us. It mean DHT11 ACK */
		if( GPIO_ReadPIN(GPIOx, p_Pin) )
		{
			response_check = TRUE;
		}
		else 
		{
			response_check = FALSE;
		}
	}
	/* wait for DHT11 Start send data */
	while( GPIO_ReadPIN(GPIOx, p_Pin) );
	if (response_check == TRUE)
		return DHT11_Result_Ok;
	else
		return DHT11_Result_Error;
}

/* Read data receive */
char DHT11_readData(GPIO_Type*GPIOx, volatile unsigned int p_Pin)
{
	unsigned int Temp = VALUE_INIT;
	unsigned int Temp_for = VALUE_INIT;
	for(Temp_for = VALUE_INIT; Temp_for < SIZE_OF_A_FRAME; Temp_for++)
	{
		/* Wait for bit is high */
		while( !(GPIO_ReadPIN(GPIOx, p_Pin)));
		
		/* Delay 40us */
		STK_Delay_10us(DELAY_40US);
		
		if( !(GPIO_ReadPIN(GPIOx, p_Pin) ))
		{
			/* if bit is low, write 0 */
			Temp &= ~(1u <<((7 - Temp_for)));
		}
		else 
		{
			/* if bit is high, write 1 */
			Temp |= (1u << (7 - Temp_for));
		}
		/* Wait bit reset */
		while(GPIO_ReadPIN(GPIOx, p_Pin));  
	}
	return Temp;
}



