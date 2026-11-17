#include "mbed.h"
#include "LM75B.h"

// LM75B connected to the I2C pins on the mbed
LM75B tempSensor(p28, p27);


int main() {

    // Check that the sensor is responding
    if (!tempSensor.open()) {
        printf("Could not find device.\n");
    }

    else{
    printf("LM75 detected, reading temperature...\n");

    while (1) {

        // get temperature in Celsius
        float tC = tempSensor.temp();

        // show the value
        printf("Current temperature: %.2f C\n", tC);

        // slow down the updates
        wait(1.0);
    }
    }
}
