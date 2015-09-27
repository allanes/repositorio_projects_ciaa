#include "consigna_5a.h"

#define UMBRALSUPERIOR 800
#define UMBRALINFERIOR 200

void Timer_ISR(void){

}

int main(void)
{
	InicializarADC();
	InicializarLEDS();


	//necesito los leds rojo y verde
	int rgb = getRGB();
	int rojo = getRGBRojo();
	int verde = getRGBVerde();
	int azul = getRGBAzul();

	uint16_t resultado = 0;


/*	if (resultado > UMBRALSUPERIOR){
		PrenderLED(rgb,rojo);
	}else{
		if (resultado < UMBRALINFERIOR){
			PrenderLED(rgb,verde);
		}else{
		ApagarLED(rgb);
		}
	}*/
	do{
	resultado = LeerADC();

/*	if (resultado > UMBRALSUPERIOR) 	PrenderLED(rgb,rojo);
	else if (resultado < UMBRALINFERIOR) 	PrenderLED(rgb,verde);
	else	 ApagarLED(rgb);
	}while(1);*/

	return 0;
}
