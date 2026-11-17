#include "mbed.h"

AnalogOut ao(p18);

int main(){
    while(1){
        // Triangle wave - going up
            for(int i = 0; i < 100; i++) {

           // Make a value that goes from -1 to +1
            float tri = (2.0f * i / 100.0f) - 1.0f;

            // Add offset (0.5) and scale (0.303) to get about 2V p-p
            float out = 0.5f + tri * 0.303f;

            ao = out;

            wait_us(100);
        }

        // Triangle wave - going down
            for(int i = 100; i > 0; i--) {

          
            float tri = (2.0f * i / 100.0f) - 1.0f;

            
            float out = 0.5f + tri * 0.303f;

            ao = out;

            wait_us(100);
        }
    }
}
