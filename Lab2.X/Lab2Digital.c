/*
 * File:   main.c
 * Author: Diego Gerardo Mencos Caal
 * Carne: 18300
 * Curso: Digital 2
 *
 * Created on 25 de enero de 2021, 12:01 PM
 */

//******************************************************************************
//Librer?as
//******************************************************************************
#include <xc.h>
#include <stdint.h> 
#include <stdio.h>
#include "ADC.h"


// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)


//******************************************************************************
//Variables
//******************************************************************************
#define incrementar PORTBbits.RB0
#define decrementar PORTBbits.RB1
uint8_t contador; //entero de 8 bits sin signo
int numeros[16]={0b00111111,0b00000111,0b01001111,0b01100110,0b01101101,
0b01111101,0b01000111,0b01111111,0b01101111,0b01110111,0b01111100,0b00111001,
0b01011110,0b01111001,0b01110001};
uint8_t hexa1; //entero de 8 bits sin signo
uint8_t hexa2; //entero de 8 bits sin signo


//*****************************************************************************
//Prototipos de funciones
//******************************************************************************
void setup(void);
void delay(unsigned char n);
void __interrupt() isr(void);

//******************************************************************************
//Interrupciones
//******************************************************************************

void __interrupt() isr(void) {
    if (INTCONbits.RBIF == 1) {
        if (incrementar == 1) {
            PORTD++;

        } else if (decrementar == 1) {
            PORTD--;

        }
        INTCONbits.RBIF = 0;
    }
    if (PIR1bits.ADIF == 1) {
        contador = ADRESH;
        PORTC = contador;
        PIR1bits.ADIF = 0;
        delay(2000);
        PIR1bits.ADIF = 0;
        ADCON0bits.GO = 1;
        // delay(2000);

    }
}



//*****************************************************************************
//Ciclo Principal
//*****************************************************************************

void main(void) {
    setup();
    delay(5000);
    ADC(0, 0);
    ADCON0bits.GO_nDONE = 1;

    while (1) {
      //  PORTEbits.RE0 = 0;
      //  hexa1=contador/10;
      //  display=
        
        delay(5000);
    }


    return;
}

//*****************************************************************************
//Configuraci?n
//****************************************************************************

void setup(void) {
    
    
    ANSEL = 0;
    ANSELH = 0;
    TRISA = 0;
    PORTA = 0;
    TRISB = 0b00000011;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    TRISE = 0;
    PORTE = 0;
    INTCONbits.GIE = 1; //Habilitamos las interrupciones
    INTCONbits.PEIE = 1;
    INTCONbits.RBIE = 1; //
    INTCONbits.RBIF = 0;
    IOCBbits.IOCB0 = 1; //Interrupt on change del B0
    IOCBbits.IOCB1 = 1; //iNTERUPTN ON CHANGE DEL B1



    //  TRISAbits.TRISA0 = 1;
    //  ANSELbits.ANS0 = 1;

    //  ADCON0bits.ADON = 1; //ADC esta habilitado
    //  ADCON0bits.CHS = 0b0000; //Seleccionamos canal AN0
    //  ADCON0bits.ADCS = 0b10; // Clock Fosc/32
    //  ADCON1bits.ADFM = 0; //Justificado hacia la izquierda
    //  ADCON1bits.VCFG1 = 0; //Voltaje de referencia a VSS
    //  ADCON1bits.VCFG0 = 0; //Voltaje de referencia a VDD
    //  PIE1bits.ADIE = 1;
    //  PIR1bits.ADIF = 0;

    contador = 0;

}

void delay(unsigned char n) {
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
        }
    }
}
