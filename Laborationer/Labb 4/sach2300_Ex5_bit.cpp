#include "mbed.h"
#include "C12832.h"

// joystick
DigitalIn up(p15);
DigitalIn down(p12);
DigitalIn left(p13);
DigitalIn right(p16);
DigitalIn center(p14);

//LCD
C12832 lcd(p5, p7, p6, p8, p11);

static char circle_array[] = {
    0x1E, 0x00,  // 00011110 00000000
    0x33, 0x00,  // 00110011 00000000
    0x40, 0x80,  // 01000000 10000000
    0xC0, 0xC0,  // 11000000 11000000
    0x80, 0x40,  // 10000000 01000000
    0x80, 0x40,  // 10000000 01000000
    0xC0, 0xC0,  // 11000000 11000000
    0x40, 0x80,  // 01000000 10000000
    0x33, 0x00,  // 00110011 00000000
    0x1E, 0x00   // 00011110 00000000
};

Bitmap Circle = {
    10,  // XSize
    10,  // YSize
    2,   // Bytes in each line  
    circle_array,
};

// Initial position 
int x = 0;
int y = 0;

int main() {
    while (1) {
        
        lcd.cls();
        lcd.locate(x, y);
        lcd.print_bm(Circle, x, y); 
        lcd.copy_to_lcd();

        // Read joystick input
        if (down == 1) {  
            y = y + 1;
        }
        if (up == 1) {  
            y = y - 1;
        }
        if (right == 1) {  
            x = x + 1;
        }
        if (left == 1) {  
            x = x -1;
        }
        //stay in area
        if(x < 0){x = 0;}
        if ( x > 115){x = 115;}
        if(y > 20){ y = 20;}
        if(y < 0 ){ y = 0;}

        // delay 
        wait_ms(50);
    }
}

