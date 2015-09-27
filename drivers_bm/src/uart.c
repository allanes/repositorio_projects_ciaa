#include "uart.h"

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
#else
#endif


char data_e, data_r;

void configurar_UART(void)
{

	Chip_SCU_PinMux(7,1,MD_PDN,FUNC6);
	Chip_SCU_PinMux(7,2,MD_PLN|MD_EZI|MD_ZI, FUNC6);
	Chip_UART_Init(LPC_USART2);
	Chip_UART_SetBaud(LPC_USART2, 9600);
	Chip_UART_SetupFIFOS(LPC_USART2, UART_FCR_FIFO_EN | UART_FCR_TRG_LEV0);
	Chip_UART_TXEnable(LPC_USART2);
}

char recibir_UART(void)
{
	Chip_UART_ReadByte(LPC_USART2);
	return data_r;
}
void enviar_UART(char data_e)
{
	Chip_UART_SendByte(LPC_USART2, data_e);
}
