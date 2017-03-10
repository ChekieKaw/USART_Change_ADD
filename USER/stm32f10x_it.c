/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h" 
#include "TIM5_INT.h"
#include "math.h"
#include "usart2.h"
#include "usart3.h"

u8 time_flag=0;
u16 distance3;
u16 distance2;
	u8 j=0;

void USART3_IRQHandler(void)                	//串口3中断服务程序
{		


	//接收中断	.
	 if(USART_GetITStatus(USART3,USART_IT_RXNE)==SET)
	    {
		 
			USART3_RX_BUF[j] =USART_ReceiveData(USART3);//(USART1->DR);	//读取接收到的数据
			USART_ClearFlag(USART3,USART_FLAG_RXNE);	
			 j++;
			 if(j==2) 
      {
         j=0;
         distance3=USART3_RX_BUF[0]*256+USART3_RX_BUF[1];

      }
			
		
	 
	 }
	

}

void USART2_IRQHandler(void)                	//串口3中断服务程序
{		


	//接收中断	.
	 if(USART_GetITStatus(USART2,USART_IT_RXNE)==SET)
	    {
		 
			USART2_RX_BUF[j] =USART_ReceiveData(USART2);//(USART1->DR);	//读取接收到的数据
			USART_ClearFlag(USART2,USART_FLAG_RXNE);	
			 j++;
			 if(j==2) 
      {
         j=0;
         distance2=USART2_RX_BUF[0]*256+USART2_RX_BUF[1];

      }
			
		
	 
	 }
 }	



//void TIM8_UP_IRQHandler(void) 
//{  
//	TIM_ClearITPendingBit(TIM8,TIM_FLAG_Update); //清中断
//}

//    TIM8_BRK_IRQHandler        ; TIM8 Break
//     TIM8_UP_IRQHandler         ; TIM8 Update
//     TIM8_TRG_COM_IRQHandler    ; TIM8 Trigger and Commutation
//     TIM8_CC_IRQHandler         ; TIM8 Capture Compare  

void TIM5_IRQHandler(void)
{
	//此处放置读取数据的函数
	TIM5->SR = ~TIM_FLAG_Update;
	time_flag=1;//数据位置1 
}


 
void NMI_Handler(void)
{
}
 
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}
 
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

 
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}
 
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}
 
void SVC_Handler(void)
{
}
 
void DebugMon_Handler(void)
{
}
 
void PendSV_Handler(void)
{
}
 
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
