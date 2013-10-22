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

#include "led.h"
#include "delay.h"
#include "sys.h"
//#include "key.h"
#include "usart.h"
//#include "exti.h"
//#include "wdg.h"
//#include "timer.h"
//#include "pwm.h"
#include "oled.h"

int main(void)
{		
 	u8 t=0;	    	
 	Stm32_Clock_Init(9); //ÏµÍ³Ê±ÖÓÉèÖÃ
	delay_init(72);	     //ÑÓÊ±³õÊ¼»¯
	uart_init(72,9600);  //´®¿Ú³õÊ¼»¯ 
	LED_Init();		  	 //³õÊ¼»¯ÓëLEDÁ¬½ÓµÄÓ²¼þ½Ó¿Ú
												   
	OLED_Init();			//³õÊ¼»¯Òº¾§      
 	OLED_ShowString(0,0, "0.96' OLED TEST");  
 	OLED_ShowString(0,16,"ATOM@ALIENTEK");  
 	OLED_ShowString(0,32,"2010/06/3");  

 	OLED_ShowString(0,48,"ASCII:");  
 	OLED_ShowString(63,48,"CODE:");  
	OLED_Refresh_Gram();	 
	t=' ';  
	while(1) 
	{		
		OLED_ShowChar(48,48,t,16,1);//ÏÔÊ¾ASCII×Ö·û	   
		OLED_Refresh_Gram();
		t++;
		if(t>'~')t=' ';
		OLED_ShowNum(103,48,t,3,16);//ÏÔÊ¾ASCII×Ö·ûµÄÂëÖµ 
		delay_ms(300);
		//LED0=!LED0;
	}	  
}

