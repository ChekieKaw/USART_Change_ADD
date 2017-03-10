#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "usart2.h"
#include "TIM5_INT.h"
#include "stm32f10x_it.h"
#include "NVIC_CONFIG.h"
#include "math.h"
#include "dog.h"
#include "led.h"

void change_address (u16 OLD_ADD, u16 NEW_ADD);


int main()
{
	delay_init();
	LED_Init();
	LED0 =1;
	LED1=0;
	delay_ms(3000);
	
		
	  Init_Tim5_Int();
		Init_Nvic();
		uart_init(115200);
		uart3_init(9600);
	
		
	LED0 =0;
	LED1=1;
	delay_ms(3000);
	
	LED0=1;
	LED1=0;//程序自检
	delay_ms(3000);
	LED0=0;
	LED0=0;
	delay_ms(3000);
	change_address(0xe8,0xd0);
	
	while(1)
	{
		LED1=1;
		LED0=1;
		delay_ms(500);
		LED1=0;
		LED0=0;
		delay_ms (500);//双闪指示灯，表示修改程序已经完成
	}
		
	
	}

	

void change_address (u16 OLD_ADD, u16 NEW_ADD)
		{
			
			delay_ms(1000);
			USART_SendData(USART3, 0x00);//请求地址0xe8
				while((USART3->SR&0X40)==0);//循环发送,直到发送完毕
				USART_SendData(USART3, OLD_ADD);//请求地址0xe8
				while((USART3->SR&0X40)==0);//循环发送,直到发送完毕
				USART_SendData(USART3, 0x02);//寄存器0x02
				while ((USART3->SR&0x40)==0);//循环发送,直到发送完毕
				USART_SendData(USART3,0x9a);//发送0x9a
				while ((USART3->SR&0x40)==0);//循环发送,直到发送完毕
				LED1=1;
				delay_ms(2);//延时1ms
				LED1=0;
				
				USART_SendData(USART3, OLD_ADD);
				while((USART3->SR&0X40)==0);//循环发送,直到发送完毕
				USART_SendData(USART3, 0x02);
				while ((USART3->SR&0x40)==0);
				USART_SendData(USART3,0x92);
				while ((USART3->SR&0x40)==0);
				LED1=1;
				delay_ms(2);
				LED1=0;
				
				USART_SendData(USART3, OLD_ADD);
				while((USART3->SR&0X40)==0);//循环发送,直到发送完毕
				USART_SendData(USART3, 0x02);
				while ((USART3->SR&0x40)==0);
				USART_SendData(USART3,0x9e);
				while ((USART3->SR&0x40)==0);
				LED1=1;
				delay_ms(2);
				LED1=0;
				
				USART_SendData(USART3, OLD_ADD);
				while((USART3->SR&0X40)==0);//循环发送,直到发送完毕
				USART_SendData(USART3, 0x02);
				while ((USART3->SR&0x40)==0);
				USART_SendData(USART3,NEW_ADD);
				while ((USART3->SR&0x40)==0);
				LED1=1;
				delay_ms(200);
				LED1=0;
			
		}
	
	
	




