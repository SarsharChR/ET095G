#include "mbed.h"

// RGB LED pins (PWM)
PwmOut red(p23), green(p24), blue(p25);

int main() {

    // Set PWM period 
    red.period(0.01);     
    green.period(0.01);
    blue.period(0.01);

    while(1) {
        for (float i = 0.0; i <= 1.0; i += 0.01) {

            // Make white light: all three LEDs get same intensity
            red = i;
            green = i;
            blue = i;

            wait_ms(20);   // 20 ms wait
        }

      
        for (float i = 1.0; i >= 0.0; i -= 0.01) {

            red = i;
            green = i;
            blue = i;

            wait_ms(20);   // 20 ms wait
        }
    }
}
