#include "SEGcodigo.h"

void SEGcodigo(uint8_t unidad, uint8_t contador) {

    if (unidad == 0) {
        hexa2 = contador % 16;
        resultado=numeros[hexa2];
    } else if (unidad == 1) {
        hexa1 = contador / 16;
        resultado=numeros[hexa1];
    }

}
