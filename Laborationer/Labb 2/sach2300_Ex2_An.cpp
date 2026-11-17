#include "mbed.h"

// read potentiometer on p19
AnalogIn pot(p19);
// serial to pc
Serial pc(USBTX, USBRX);

int main() {

    while(1) {
        float sum = 0.0;
        // read 20 samples
        for(int i = 0; i < 20; i++) {
            sum = sum + pot.read();   // analog value 0.0 - 1.0
            wait_ms(10);              // small delay between reads
        }
        // get average
        float avg = sum / 20;
        // convert to voltage (0 to 3.3V)
        float voltage = avg * 3.3;
        // print the result
        pc.printf("Voltage: %.2f V\n", voltage);
        wait(1);   // print every 1 second
    }
}
