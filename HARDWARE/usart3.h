#ifndef __USART3_H
#define __USART3_H


#include "stdio.h"	
#include "sys.h" 
#include "stm32f10x.h"

#define USART2_REC_LEN  			1000  	//�����������ֽ��� 200
#define EN_USART2_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
	  	
extern u8  USART2_RX_BUF[USART2_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART2_RX_STA;         		//����״̬���	


void uart2_init(u32 bound);

#endif
