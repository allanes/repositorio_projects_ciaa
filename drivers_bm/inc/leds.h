#include "stdint.h"
#include "chip.h"

int getVerde();
int getRojo();
int getAmarillo();
int getRGB();
int getRGBBlanco();
int getRGBCian();
int getRGBMagenta();
int getRGBAmarillo();

void InicializarLEDS(void);

int PrenderLED(int LED, int COLOR);
int ApagarLED(int LED);
void ParpadearLED(int LED, int COLOR);

void PrenderLEDS(void);
void ApagarLEDS(void);
