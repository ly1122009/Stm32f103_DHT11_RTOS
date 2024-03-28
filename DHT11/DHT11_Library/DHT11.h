/*
* Title: Scheduling the task receive and transfer a data frame using UART
* Filename: DHT11.h
* Content: Lirary for DHT11 module 
*/
#ifndef _DHT11_H_
#define _DHT11_H_

#include "GPIO.h"

/* I3G4250D Result enumerations */
typedef enum {
	DHT11_Result_Ok,   /*!< Everything OK */
	DHT11_Result_Error /*!< Error occurred */
} DHT11_Result_t;

/* Public function */
/** 
* This function using SPI1 (PA5 = SCK, PA6 = MISO, PA7 = MOSI, PE3 = CS) 
* @brief  Send bit Start 
* @param  GPIOx: GPIOA or GPIOB or GPIOC or GPIOD or GPIOE or GPIOF 
* @param  p_Pin: The number of pin 
*/
void DHT11_Start(GPIO_Type*GPIOx, volatile unsigned int p_Pin);

/** 
* This function using SPI1 (PA5 = SCK, PA6 = MISO, PA7 = MOSI, PE3 = CS) 
* @brief  Check response from DHT11
* @param  GPIOx: GPIOA or GPIOB or GPIOC or GPIOD or GPIOE or GPIOF 
* @param  p_Pin: The number of pin 
* @retval DHT11_Result_Ok: the process is successful
* @retval DHT11_Result_Error: the process fails. pls reset processor and try again.
*/
DHT11_Result_t DHT11_check_response(GPIO_Type*GPIOx, volatile unsigned int p_Pin);

/** 
* This function using SPI1 (PA5 = SCK, PA6 = MISO, PA7 = MOSI, PE3 = CS) 
* @brief   Read data receive from DHT11
* @param  GPIOx: GPIOA or GPIOB or GPIOC or GPIOD or GPIOE or GPIOF 
* @param  p_Pin: The number of pin 
* @retval the data value of 2 byte humidity and 2 byte temperature
*/
char DHT11_readData(GPIO_Type*GPIOx, volatile unsigned int p_Pin);


#endif

