#include "mbed.h"

AnalogOut ao(p18);

int main(){
    while(1){
          for(int i = 0; i < 100; i++) {

            // angle from 0 to 2*pi
            float angle = 2 * 3.14 * (float)i / 100.0;

            // 0.5 is offset, 0.303 is amplitude for about 2V p-p
            float out = 0.5f + 0.303f * sin(angle);

            ao = out;

            wait_us(100);   // 100 us → 100 samples → 100 Hz
        }
    }
}
