#include "timer.h"

void InicializarTimer(int tiempo){
	Chip_RIT_Init(LPC_RITIMER);
	Chip_RIT_ClearInt(LPC_RITIMER);
	NVIC_EnableIRQ(RITIMER_IRQn); //habilito interr
	Chip_RIT_SetTimerInterval(LPC_RITIMER, tiempo); //seteo tiempo
}

void setPeriodo(int periodo){
	Chip_RIT_SetTimerInterval(LPC_RITIMER, periodo); //seteo tiempo
}
