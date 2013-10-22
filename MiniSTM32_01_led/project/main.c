/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : main.c
* Author             : David JIANG
* Date First Issued  : 2007.9.17
* Description        : Main program body
********************************************************************************
* History:
* 2007.9.17: V1.0
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/


/*************************************************/
/* main.c                                                                          */
/*                                                                                    */
/* modified by Qibo Zhang (Michael) China                               */
/* for GNU compiler                                                             */
/*                                                                                    */
/* E-Mail: sudazqb@163.com                                                */
/* MSN  : zhangqibo_1985@hotmail.com                                 */
/* 2007-12-19                                                                   */
/************************************************/ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_lib.h"
/* Local includes ------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
int main(void)
{		 			  
	Stm32_Clock_Init(9);
	delay_init(72);
	LED_Init();
	while(1)
	{ 
		LED0=0;
		LED1=1;
		delay_ms(300);
		LED0=1;
		LED1=0;
		delay_ms(300);
	}	 
}

