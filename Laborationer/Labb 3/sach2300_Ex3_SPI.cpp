#include "mbed.h"

SPI spi(p5, p6, p7);   // MOSI, MISO, SCK

int main() {
    spi.format(8, 3);       // 8 bits, mode 3
    spi.frequency(1000000); // 1 MHz

    while(1) {
        spi.write(0x52);    // send 01010010
        wait_ms(100);
    }
}
