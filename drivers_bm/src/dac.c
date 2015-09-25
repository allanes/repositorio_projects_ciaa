#include "dac.h"
#include "timer.h"

void InicializarDAC(void){
	Chip_SCU_DAC_Analog_Config();
	Chip_DAC_Init(LPC_DAC);
	Chip_DAC_UpdateValue(LPC_DAC, 0);
	Chip_DAC_ConfigDAConverterControl (LPC_DAC, DAC_DMA_ENA);
}

void setDAC(uint16_t valor_adc){
	Chip_DAC_UpdateValue(LPC_DAC, valor_adc); //hace cast de int16 a int32
}
