#include "teclas.h"

void InicializarBotones(){
	//mapeo sin glitch (hay que hacer antirrebote por separado)
//	Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); //mapea 1.0 a GPIO0[4] (pulsador 1)
//	Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); //mapea 1.1 a GPIO0[8] (pulsador 1)
//	Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); //mapea 1.2 a GPIO0[9] (pulsador 1)
//	Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); //mapea 1.6 a GPIO1[9] (pulsador 1)

	//mapeo con glitch (no hace falta hacer antirrebote)
	Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI,FUNC0); //mapea 1.0 a GPIO0[4] (pulsador 1)
	Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI,FUNC0); //mapea 1.1 a GPIO0[8] (pulsador 1)
	Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI,FUNC0); //mapea 1.2 a GPIO0[9] (pulsador 1)
	Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI,FUNC0); //mapea 1.6 a GPIO1[9] (pulsador 1)

	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1<<4), 0); //pongo como entrada
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1<<8), 0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, (1<<9), 0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, (1<<9), 0);
}

int EscanearTeclas(){
	int lectura;
		lectura = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 4);
		if (!lectura) return 1;
		lectura = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 8);
		if (!lectura) return 2;
		lectura = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 9);
		if (!lectura) return 3;
		lectura = Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 1, 9);
		if (!lectura) return 4;
	return 0;
}


