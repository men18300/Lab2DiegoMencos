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
}



//*****************************************************************************
//Ciclo Principal
//*****************************************************************************

void main(void) {
    setup();
  //  delay(5000);
    while (1) {
        //PORTD=contador;
    }


    return;
}

//*****************************************************************************
//Configuraci?n
//****************************************************************************

void setup(void) {
    ANSEL = 0;
    ANSELH = 0;
    TRISB = 0b00000011;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    INTCONbits.GIE = 1; //Habilitamos las interrupciones
    INTCONbits.PEIE = 1;
    INTCONbits.RBIE = 1; //
    INTCONbits.RBIF = 0;
    IOCBbits.IOCB0 = 1;
    IOCBbits.IOCB1 = 1;

    contador = 0;

}

void delay(unsigned char n) {
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
        }
    }
}
