#ifndef __USART2_H
#define __USART2_H


#include "stdio.h"	
#include "sys.h" 
#include "stm32f10x.h"

#define USART3_REC_LEN  			1000  	//�����������ֽ��� 200
#define EN_USART3_RX 			1		//ʹ�ܣ�1��/��ֹ��0������1����
	  	
extern u8  USART3_RX_BUF[USART3_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART3_RX_STA;         		//����״̬���	


void uart3_init(u32 bound);

#endif
