#ifndef TIMER_H_
#define TIMER_H_

#include "stdint.h"
#include "chip.h"

void InicializarTimer(int tiempo);
void setPeriodo(int periodo);
void ReiniciarTimer(void);

#endif /* TIMER_H_ */
