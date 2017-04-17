#include "stm32f4xx.h"
#include "stdbool.h"
#include "string.h"
#include "system_timetick.h"

#include "uart_dma_timeout.h"

extern bool b_UART_DMA_Timeout;
extern uint8_t rcv_message[BUFF_SIZE];
//char parse_message[BUFF_SIZE];

void init_main(void);

uint16_t string2num(char *str)
{
	uint16_t result, result_temp, i, j, str_len;
	str_len = strlen(str);
	for(i = 0; i < str_len; i++)
	{
		result_temp = str[i] - 0x30;
		for(j = 0; j < str_len - i - 1; j++)
		{
			result_temp *= 10;
		}
		result += result_temp;
	}
	return result;
}

int main(void)
{
	/* Enable SysTick at 10ms interrupt */
	SysTick_Config(SystemCoreClock/100);

	init_main();

	while(1)
	{
		if(tick_count == 100)
		{
			tick_count = 0;
			//while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
			//USART_SendData(UART4,(uint8_t)65);
		}	
		else
		{
			if(b_UART_DMA_Timeout)
			{
				if(!strcmp((char*) rcv_message, "[PD12_TOGGLE]"))
				{
					GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
					UART4_DMA_Send("[DONE]", strlen("[DONE]"));
				}
			}
		}
	}
}

void init_main(void)
{
  GPIO_InitTypeDef GPIO_InitStructure; 
   
	/* Enable GPIOD clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  /* Configure PD12 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	UART_DMA_Timeout_Init();
}
