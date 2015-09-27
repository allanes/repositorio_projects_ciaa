#include "consigna_4_1a.h"

//parametro definido por el ejercicio:
int Voutmax = 3; //valor en Voltios
int periodo = 100; //valor en milisegundos,debe ser multiplo de 100

int cuenta = 0;
int valor_dac = 0;

void Timer_ISR(void){
	Chip_RIT_ClearInt(LPC_RITIMER);
	Chip_DAC_UpdateValue(LPC_DAC, valor_dac); //lo pongo aca para que no actualice tan rapido un puerto analogico
	ApagarLEDS();
	cuenta++;
}

int main(void)
{
	InicializarDAC();
	InicializarTimer(periodo/100);
	InicializarLEDS();
	do{
		if (cuenta>99){
			cuenta = 0;
			Chip_DAC_UpdateValue(LPC_DAC, 0);
			PrenderLEDS();
		}
		valor_dac = Voutmax * 3 * cuenta; //es Vout * 1024 / (3,3 * 100)
	}while(1);

	return 0;
}

