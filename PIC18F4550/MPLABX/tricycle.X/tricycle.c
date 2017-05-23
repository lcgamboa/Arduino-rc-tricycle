#include<xc.h>
#include"serial.h"
#include"servo.h"
#include"atraso.h"

unsigned char centro = 90;

void setup() {
    serial_init();//default 9600
    TRISCbits.RC7=1;
    servo_init();
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;
    PORTDbits.RD1 = 0;
    PORTDbits.RD2 = 0;
    servo_pos(centro);
}

void loop() {
    switch (serial_rx(0)) {
        case 'd':
            servo_pos(180);
            break;
        case 'a':
            servo_pos(0);
            break;
        case 'q':
            servo_pos(centro);
            break;
        case 'w':
            PORTDbits.RD1 = 1;
            PORTDbits.RD2 = 0;
            break;
        case 's':
            PORTDbits.RD1 = 0;
            PORTDbits.RD2 = 1;
            break;
        case 'r':
            PORTDbits.RD1 = 0;
            PORTDbits.RD2 = 0;
            break;
    }
    

}

