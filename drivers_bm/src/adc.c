#include "adc.h"

void InicializarADC(void){
	Chip_SCU_ADC_Channel_Config(0, 1);

	ADC_CLOCK_SETUP_T config_reloj;
	config_reloj.adcRate = ADC_MAX_SAMPLE_RATE;
	config_reloj.bitsAccuracy = ADC_10BITS;
	config_reloj.burstMode = FALSE;

	Chip_ADC_Init(LPC_ADC0, &config_reloj );

	Chip_ADC_EnableChannel(LPC_ADC0, ADC_CH1,ENABLE);
}

uint16_t LeerADC(){
	uint16_t valorADC;

	Chip_ADC_SetStartMode(LPC_ADC0, ADC_START_NOW, 0);
	while(!Chip_ADC_ReadStatus(LPC_ADC0, ADC_CH1, ADC_DR_DONE_STAT));
	Chip_ADC_ReadValue(LPC_ADC0, ADC_CH1, &valorADC);
	return valorADC;
}
