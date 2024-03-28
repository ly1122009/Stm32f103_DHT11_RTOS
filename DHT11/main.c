/*
* Title: Scheduling the task receive and transfer a data frame using UART 
* Filename: main.c
* Content: main source code program
*/
#include "main.h"

int main(){
	/* Init RCC */
	/* Clock 8Mhz */
	RCC_ClockHSE();
	RCC_CongfigAHBPrescaler(AHB_1);
	RCC_EnableAndCongfigAPB1(APB1_1,APB1_USART2);
	RCC_EnableAndCongfigAPB2(APB2_1,APB2_PORTA);    
	   
	/* Test */
	RCC_EnableAndCongfigAPB2(APB2_1,APB2_PORTC);
	GPIO_Output_Init(GPIO_C,PIN_13);
		
	/* Init USART - PA2: Tx, PA3: Rx */
	USART_InitRxTxPORT_USART2();
	USART_Congfig(USART2,BAUDRATE_14400,CLOCK_8MHZ,USART_Congfig_Bitdata_8,USART_Congfig_Parity_NoParity,USART_Congfig_StopBit_1);
	
	/* Init EXTI */
	NVIC_EnableInterrupt(ID_EXTI1);
	EXTI_congfigInterruptFalling(GPIO_A,PIN_1);

	/* Init Systick */
	STK_InitSystick_10us(CLOCK_8MHZ);
	
	/* Enable USART2 */
	USART_Enable(USART2);
	
	STK_Delay_10us(DELAY_1S);

	/* DHT11 */
	DHT11_Start(GPIO_A, PIN_7);
	if (DHT11_check_response(GPIO_A, PIN_7) == DHT11_Result_Error)
	{	// Init fails
		while(TRUE);
	}

	/* Create two task toggle led */
	xTaskCreate(toggle_led_PC13,"Toggle led PC13", STACKDEPTH_UNIT, NULL, PRIORITY_REALTIME, NULL);
	xTaskCreate(Rec_DHT11,"Receive data from DHT11", STACKDEPTH_UNIT, NULL, PRIORITY_REALTIME, NULL);

	/* Start operation of Task */
	vTaskStartScheduler();
}

/* EXTI1 interupt function */
void EXTI1_IRQHandler(void){
	if(EXTI_checkFlagInterrupt(PIN_1))
	{
		/* Clear flag EXTI 1 */
		EXTI_clearFlagInterrupt(PIN_1);
		GPIO_SetTogglePIN(GPIO_C, PIN_13);
	}
}

/* Toggle led PC13 */
static void toggletoggle_led_PC13_led_1(void* p_ptrVoid){
	while(TRUE)
	{
		// Blink led
		GPIO_SetTogglePIN(GPIO_C,LED_PC13);
		vTaskDelay(DELAY_1SECOND);
	}
}

/* Receive data from DHT11 */
static void Rec_DHT11(void* p_ptrVoid){
	while(TRUE)
	{
		// Receive data from DHT11
		DHT11_Data_t.DHT11_RH_L = DHT11_readData(GPIO_A, PIN_7);
		DHT11_Data_t.DHT11_RH_H = DHT11_readData(GPIO_A, PIN_7);
		DHT11_Data_t.DHT11_T_L = DHT11_readData(GPIO_A, PIN_7);
		DHT11_Data_t.DHT11_T_H = DHT11_readData(GPIO_A, PIN_7);
		vTaskDelay(DELAY_2SECOND);
	}
}


