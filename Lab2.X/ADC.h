

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC_H
#define	ADC_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void ADC();
void setup(void);

void setup(void){
    ADCON0bits.ADON=1 //ADC esta habilitado
    ADCON0bits.GO_nDONE=0; //
    ADCON0bits.CHS=0b0000;//Seleccionamos canal AN0
    ADCON0bits.ADCS=0b01;// Clock Fosc/8
    ADCON1bits.ADFM=1; //Justificado hacia la derecha
    ADCON1bits.VCFG1=0;//Voltaje de referencia a VSS
    ADCON1bits.VCFG0=0;//Voltaje de referencia a VDD
    
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    kk
    
}


#endif	/* ADC_H */

