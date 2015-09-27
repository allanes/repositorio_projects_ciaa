#include "consigna_3a.h"

int cuenta = 0;

//gets



void Timer_ISR(void){
		Chip_RIT_ClearInt(LPC_RITIMER);
		cuenta++;
		ApagarLEDS();

		if (cuenta>9) cuenta = 0;
		switch(cuenta){
		case 0: PrenderLED(getRGB(), getRGBBlanco());break;
		case 1: PrenderLED(getAmarillo(), 0);break;
		case 2: PrenderLED(getRojo(), 0);break;
		case 3: PrenderLED(getVerde(), 0);break;
		case 4: PrenderLED(getRGB(), getRGBAzul());break;
		case 5: PrenderLED(getRGB(), getRGBMagenta());break;
		case 6: PrenderLED(getRGB(), getRGBRojo());break;
		case 7: PrenderLED(getRGB(), getRGBAmarillo());break;
		case 8: PrenderLED(getRGB(), getRGBVerde());break;
		case 9: PrenderLED(getRGB(), getRGBCian());break;
		default: break;
		}
}

int main(void)
{
	InicializarTimer(400); //le paso el periodo de interrupcion en [ms]
	InicializarLEDS();

	int verde = getVerde();
	int rojo = getRojo();
	int amarillo = getAmarillo();
	int rgb = getRGB();
	int rgb_blanco = getRGBBlanco();
	int rgb_cian = getRGBCian();
	int rgb_magenta = getRGBMagenta();
	int rgb_amarillo = getRGBAmarillo();
	int rgb_azul = getRGBAzul();
	int rgb_verde = getRGBVerde();
	int rgb_rojo = getRGBRojo();

	while(1);

	return 0;
}

