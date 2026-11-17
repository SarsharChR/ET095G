#include "mbed.h"

// LED 1 TO 4
BusOut leds(LED1, LED2, LED3, LED4);

// joystick
BusIn jy(p13, p15, p16, p12, p14);

int main() {
     while(true) {
         // LEFT --> LED 1
        if(jy[0] == 1){
            leds[0] =! leds[0];
            wait(0.2);
            
        }
        // UP --> LED2
        if( jy[1] == 1){
            leds[1] =! leds[1];
            wait(0.2);
            
        }
        //RIGHT --> LED 3
        if (jy[2] == 1){
            leds[2] =! leds[2];
            wait(0.2);
            
        }
        //DOWN --> LED 4
        if (jy[3] == 1){
            leds[3] =! leds[3];
            wait(0.2);
        } 
        // CENTER --> CLEAR ALL 4 LEDS
        if (jy[4] == 1){
            leds[0] = 0;
            leds[1] = 0;
            leds[2] = 0;
            leds[3] = 0;
           
        }
    }
}
