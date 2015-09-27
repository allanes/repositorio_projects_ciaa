#include "consigna_2.h"

#define VERDE 0
#define ROJO 1
#define AMARILLO 2
#define RGB 3

int main(void)
{
	InicializarLEDS();
	InicializarBotones();

	//gets:
	int verde = getVerde();
	int rojo = getRojo();
	int amarillo = getAmarillo();
	int rgb = getRGB();
	int rgb_blanco = getRGBBlanco();
	int rgb_cian = getRGBCian();
	int rgb_magenta = getRGBMagenta();
	int rgb_amarillo = getRGBAmarillo();

	do{

		int tecla = EscanearTeclas();

		switch (tecla){
		case 1: ParpadearLED(rgb, rgb_magenta); break;
		case 2: ParpadearLED(rojo, 0); break;
		case 3: ParpadearLED(amarillo, 0); break;
		case 4: ParpadearLED(verde, 0); break;
		default: break;
		}

	}while(1);

	return 0;
}

