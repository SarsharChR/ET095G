#include "mbed.h"
#include "C12832.h"
#include "LM75B.h"

C12832 lcd(p5, p7, p6, p8, p11);
LM75B   tmp(p28, p27);

int main() {
    const float Tmin = 20.0f;
    const float Tmax = 40.0f;

    const int ax = 20;                 // x position of the Y-axis
    const int yTop = 0;
    const int yBot = lcd.height() - 1; // 31 (bottom pixel row)
    int x = ax + 1;

    while (true) {
        // If it reach the right edge, clear and start again
        if (x > 127) {
            lcd.cls();
            x = ax + 1;
        }

        lcd.line(ax, yTop, ax, yBot, 1);       // Y-axis
        lcd.line(ax, yBot, 127, yBot, 1);      // X-axis

        
        lcd.locate(1, 2);
        lcd.printf("%2.0f", Tmax);
        lcd.locate(1, yBot - 8);
        lcd.printf("%2.0f", Tmin);

        float t = tmp.temp();

        // Map temperature to a Y coordinate
        int y = (int)((Tmax - t) * (yBot - yTop) / (Tmax - Tmin));

        
        if (y < yTop) y = yTop;
        if (y > yBot - 1) y = yBot - 1; // avoid drawing exactly on the X-axis

        // Plot a single pixel
        lcd.pixel(x, y, 1);

        // Display current temperature
        lcd.locate(60, 0);
        lcd.printf("T=%.1fC ", t);


        x++;
        wait(1.0f);
    }
}
