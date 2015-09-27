#ifndef UART_H_
#define UART_H_

#include "stdint.h"
#include "chip.h"

void configurar_UART(void);
char recibir_UART(void);
void enviar_UART(char data_e);

#endif /* GENERADORDS_H_ */
