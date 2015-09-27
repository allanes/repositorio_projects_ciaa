#include "consigna_4_1b.h"

//parametro definido por el ejercicio:
int Voutmax = 1; //valor en Voltios
int periodo = 500; //valor en milisegundos,debe ser multiplo de 100

int cuenta = 0;
int valor_dac = 0;
int tecla, comp;

void Timer_ISR(void){
	Chip_RIT_ClearInt(LPC_RITIMER);
	valor_dac = Voutmax * 3 * cuenta; //es Vout * 1024 / (3,3 * 100)
	Chip_DAC_UpdateValue(LPC_DAC, valor_dac); //lo pongo aca para que no actualice tan rapido un puerto analogico
	ApagarLEDS();
	cuenta++;
}

int main(void)
{
	InicializarDAC();
	InicializarTimer(periodo/100);
	InicializarLEDS();
	InicializarBotones();

	do{
		if (cuenta>99){
			cuenta = 0;
			PrenderLEDS();
		}
		funcionTeclas();
	}while(1);

	return 0;
}

int funcionTeclas(void){
	tecla = EscanearTeclas();
	if (comp == tecla) return 0;
	comp = tecla;
	switch (tecla){
	case 1:
		if (Voutmax != 3) Voutmax++;
		break;
	case 2:
		if (Voutmax != 0) Voutmax--;
		break;
	case 3:
		periodo+=   100;
		setPeriodo(periodo/100);
		break;
	case 4:
		if (periodo != 100){
			periodo-= 100;
			setPeriodo(periodo/100);
		}
		break;
	default: break;
	}
	return 1;
}

void InicializarTodo(){

}
