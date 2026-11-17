#include "mbed.h"

// LED 1 TO 4
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

// joystick
DigitalIn left(p13);
DigitalIn up(p15);
DigitalIn right(p16);
DigitalIn down(p12);
DigitalIn center(p14);

int main() {
     while(true) {
         // LEFT --> LED 1
        if(left == 1){
            led1 =! led1;
            wait(0.2);
            
        }
        // UP --> LED2
        if( up == 1){
            led2 =! led2;
            wait(0.2);
            
        }
        //RIGHT --> LED 3
        if (right ==1){
            led3 =! led3;
            wait(0.2);
            
        }
        //DOWN --> LED 4
        if (down == 1){
            led4 =! led4;
            wait(0.2);
        } 
        // CENTER --> CLEAR ALL 4 LEDS
        if (center == 1){
            led1 = 0;
            led2 = 0;
            led3 = 0;
            led4 = 0;
        }
    }
}
