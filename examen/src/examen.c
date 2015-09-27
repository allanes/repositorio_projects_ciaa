#include "examen.h"
/*************************************ENUNCIADO*********************************/
/**Diseñe e implemente un Firmware sobre EDU-CIAA que permita adquirir una señal analógica
 entre 0 y 3.3V a una frec de muestreo de 10 Hz. La señal debera reproducirse por el
 conversor DA.
 Tec1: Excursion salida ++
 Tec2: Excursion salida --
 Tec1: Excursion salida 0
 *******************************************************************************/

//*********Parametros para el ejercicio**********************
int periodo = 100; //1Hz = 100ms
#define LED getAmarillo()
float Voutmax = 2; //valor en Voltios
char mensaje_tecla_1[] = "Disminuyo la ganancia\n\r";
char mensaje_tecla_2[] = "Aumento la ganancia\n\r";
char mensaje_tecla_3[] = "MUTE\n\r";
int largo_mensaje_1 = 23;
int largo_mensaje_2 = 21;
int largo_mensaje_3 = 6;
//***********************************************************
uint16_t valor_dac;
uint16_t valor_adc;
int tecla, comp, togglefuncion = 0;

void Timer_ISR(void){
	ReiniciarTimer();
	ToggleLED(LED);

	valor_adc = LeerADC();
	valor_dac = (uint16_t) valor_adc * Voutmax;
	setDAC(valor_dac);
}

int main(void)
{
	InicializarADC();
	InicializarTimer(periodo);
	InicializarDAC();
	InicializarLEDS();
	InicializarBotones();
	configurar_UART();

	do{
		if (togglefuncion) FuncionTeclas1();
		else FuncionTeclas0();
	}while(1);

	return 0;
}

int FuncionTeclas0(void){
	tecla = EscanearTeclas();
	if (comp == tecla) return 0;
	comp = tecla;
	ToggleLED(getVerde());
	switch (tecla){
	case 1:
		if (Voutmax - 3.0 != 0 ) Voutmax+=0.1;
		EnviarMensaje(1);
		break;
	case 2:
		if (Voutmax != 0) Voutmax-=0.1;
//		EnviarMensaje(2);
		break;
	case 3:
		Voutmax = 0;
//		EnviarMensaje(3);
		break;
	case 4:
		togglefuncion = 1;
		break;
	default: break;
	}
	return 1;
}

int FuncionTeclas1(void){
	tecla = EscanearTeclas();
	if (comp == tecla) return 0;
	comp = tecla;
	switch (tecla){
	case 1:
			periodo+=   100;
			setPeriodo(periodo);
			break;
	case 2:
		if (periodo != 100){
			periodo-= 100;
			setPeriodo(periodo);
		}
			break;
	case 3:
		Voutmax = 0;
		break;
	case 4:
		togglefuncion = 0;
		break;
	default: break;
	}
	return 1;
}

void EnviarMensaje(int numero_tecla){
	int i=0,j,n, condicion=1;
	char mensaje[] = "";
	switch (tecla){
	case 1:
		for(n=0;largo_mensaje_1 - 1;n++) mensaje[n] = mensaje_tecla_1[n];
		break;
	case 2:
		for(n=0;largo_mensaje_2 - 1;n++) mensaje[n] = mensaje_tecla_2[n];
		break;
	case 3:
		for(n=0;largo_mensaje_3 - 1;n++) mensaje[n] = mensaje_tecla_3[n];
		break;
	}
	do{
		if (i== largo_mensaje_1 - 1 | i==largo_mensaje_2 - 1 | i==largo_mensaje_3 - 1){
		condicion = 0;
		}

		enviar_UART(mensaje[i]);
		for(j=0;j<1000000;j++);
//		recibir_UART();
		//for(j=0;j<1000000;j++);

		i++;
	}while(condicion);
}
