#include "mbed.h"
#include "C12832.h"

// LCD 
C12832 lcd(p5, p7, p6, p8, p11);


AnalogIn pm(A5);

int main() {
    lcd.cls(); //clear screen
    lcd.locate(0, 0);
    lcd.printf("Voltmeter");

    while (true) {
        float v = pm.read() * 3.3f; // voltage

        lcd.locate(0, 12);
        lcd.printf("Voltage:  %.3f ", v); // Display the changing voltage value

        wait_ms(200);
    }
}
