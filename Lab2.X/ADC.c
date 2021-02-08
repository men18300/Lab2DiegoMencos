#include "ADC.h"


void ADC(void) {

    TRISA = 1;
    PORTA = 0;
    ANSEL = 1;
    //ANSELH = 1;
    ADCON0bits.ADON = 1; //ADC esta habilitado
    ADCON0bits.GO_nDONE = 1; //
    ADCON0bits.CHS = 0b0000; //Seleccionamos canal AN0
    ADCON0bits.ADCS = 0b01; // Clock Fosc/8
    ADCON1bits.ADFM = 0; //Justificado hacia la izquierda
    ADCON1bits.VCFG1 = 0; //Voltaje de referencia a VSS
    ADCON1bits.VCFG0 = 0; //Voltaje de referencia a VDD

    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
   // PIR1bits.ADIF = 0;


}
