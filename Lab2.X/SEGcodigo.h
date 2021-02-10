
#ifndef SEGcodigo_H
#define	SEGcodigo_H


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdio.h>

int numeros[16] = {0b11000000, 0b11111001, 0b10100100, 0b10110000, 0b10010010,
    0b10000010, 0b10111000, 0b11111000, 0b10010000, 0b10001000, 0b10001000, 0b10000011, 0b11000110,
    0b10100001, 0b10000110, 0b10001110};
uint8_t resultado; //entero de 8 bits sin signo
uint8_t hexa2; //entero de 8 bits sin signo
uint8_t hexa1; //entero de 8 bits sin signo

void SEGcodigo(uint8_t unidad, uint8_t contador);



#endif	/* XC_HEADER_TEMPLATE_H */

