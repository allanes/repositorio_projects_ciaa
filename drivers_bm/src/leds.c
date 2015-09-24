#include "leds.h"

#define VERDE 0
#define ROJO 1
#define AMARILLO 2
#define RGB 3
#define RGBBLANCO 4
#define RGBCIAN 5
#define RGBMAGENTA 6
#define RGBAMARILLO 7
#define RGBAZUL 8
#define RGBVERDE 9
#define RGBROJO 10

int getVerde(){return VERDE;}
int getRojo(){return ROJO;}
int getAmarillo(){return AMARILLO;}
int getRGB(){return RGB;}
int getRGBBlanco(){return RGBBLANCO;}
int getRGBCian(){return RGBCIAN;}
int getRGBMagenta(){return RGBMAGENTA;}
int getRGBAmarillo(){return RGBAMARILLO;}
int getRGBAzul(){return RGBAZUL;}
int getRGBVerde(){return RGBVERDE;}
int getRGBRojo(){return RGBROJO;}


void InicializarLEDS(){
	Chip_GPIO_Init(LPC_GPIO_PORT);
	//Mapeo los ledsa los GPIOX.X y habilito pullup
	Chip_SCU_PinMux(2,0,MD_PUP,FUNC4); //mapea 2.0 a GPIO5[0] (RGB, R)
	Chip_SCU_PinMux(2,1,MD_PUP,FUNC4); //mapea 2.0 a GPIO5[1] (RGB, G)
	Chip_SCU_PinMux(2,2,MD_PUP,FUNC4); //mapea 2.0 a GPIO5[2] (RGB, B)
	Chip_SCU_PinMux(2,10,MD_PUP,FUNC0); //mapea 2.0 a GPIO0[14] (LED Amarillo)
	Chip_SCU_PinMux(2,11,MD_PUP,FUNC0); //mapea 2.0 a GPIO1[11] (LED Rojo)
	Chip_SCU_PinMux(2,12,MD_PUP,FUNC0); //mapea 2.0 a GPIO1[12] (LED Verde)
	//Direcciono los GPIOX.X
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1<<0), 1); // !1 es SALIDA, LPC_GPIO_PORT
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1<<1), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 5, (1<<2), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1<<14), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1<<11), 1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1<<12), 1);
	//Pongo en bajo las salidas GPIOX.X
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 0);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 1);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 2);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 14);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 11);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 12);

}

int PrenderLED(int LED, int COLOR){
	switch (LED) {
	case VERDE:
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 12);
	  break;
	case AMARILLO:
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 14);
	  break;
	case ROJO:
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 11);
		  break;
	case RGB:
		switch(COLOR){
		case RGBROJO:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0);
			break;
		case RGBVERDE:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
			break;
		case RGBAZUL:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
			break;
		case RGBBLANCO:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
			break;
		case RGBMAGENTA:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
			break;
		case RGBAMARILLO:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
			break;
		case RGBCIAN:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
			break;
		default: return 0;
		}
		  break;
	default: return 0;
	  break;
	}
	return 1;
}

int ApagarLED(int LED){
	switch (LED) {
		case VERDE: //VERDE
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 12);
		  break;
		case AMARILLO: //AMARILLO
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 11);
		  break;
		case ROJO: //ROJO
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 14);
		  break;
		case RGB:
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 0);
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 1);
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 2);
		  break;
		default: return 0;
		  break;
		}
	return 1;
}

void ParpadearLED(int LED, int COLOR){
	int i,x;
	do{
		i=0;
		PrenderLED(LED, COLOR);
		for(i=0;i<5000000;i++){x=0;}
		ApagarLED(LED);
		for(i=0;i<5000000;i++){x=0;}
		x=1;
	}while (x==1);

}

void ApagarLEDS(){
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 12); //VERDE
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 14); //ROJO
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 1, 11); //AMARILLO
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 0); //R,G,B
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 1);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 5, 2);
}

void PrenderLEDS(void){
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 12); //VERDE
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 0, 14); //ROJO
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 1, 11); //AMARILLO
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 0); //R,G,B
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 1);
	Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT, 5, 2);
}
/*==================[end of file]============================================*/

