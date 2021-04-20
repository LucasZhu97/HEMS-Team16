#include "SCD30.h"
#if defined(ENERGIA) // LaunchPad MSP430, Stellaris and Tiva, Experimeter Board FR5739 specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif

#include "SPI.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Screen_K35_SPI.h"
Screen_K35_SPI myScreen;

#define ROWS 128 // max 128
#define COLS 128 // max 128
#if defined(ARDUINO_ARCH_AVR)
    #pragma message("Defined architecture for ARDUINO_ARCH_AVR.")
    #define SERIAL Serial
#elif defined(ARDUINO_ARCH_SAM)
    #pragma message("Defined architecture for ARDUINO_ARCH_SAM.")
    #define SERIAL SerialUSB
#elif defined(ARDUINO_ARCH_SAMD)
    #pragma message("Defined architecture for ARDUINO_ARCH_SAMD.")
    #define SERIAL SerialUSB
#elif defined(ARDUINO_ARCH_STM32F4)
    #pragma message("Defined architecture for ARDUINO_ARCH_STM32F4.")
    #define SERIAL SerialUSB
#else
    #pragma message("Not found any architecture.")
    #define SERIAL Serial
#endif
uint16_t colours[16];


void setup() {

//    pinMode(StopButton, INPUT_PULLUP);
//    pinMode(NewGameButton, INPUT);
    Wire.begin();
    SERIAL.begin(115200);
    SERIAL.println("SCD30 Raw Data");
    scd30.initialize();
    myScreen.begin();

    
    delay(10);
    myScreen.setPenSolid(true);
    
    // 0-7 dying: cold colours
    // from green to blue to black
    colours[ 0] = myScreen.calculateColour(  0, 255,   0);
    colours[ 1] = myScreen.calculateColour(  0, 204,  51);
    colours[ 2] = myScreen.calculateColour(  0, 153, 102);
    colours[ 3] = myScreen.calculateColour(  0, 102, 153);
    colours[ 4] = myScreen.calculateColour(  0,  51, 204);
    colours[ 5] = myScreen.calculateColour(  0,   0, 255);
    colours[ 6] = myScreen.calculateColour(  0,   0, 127);
    colours[ 7] = myScreen.calculateColour(  0,   0,   0);
    
    
    // 8-15 living: hot colours
    // from red to orange to yellow
    colours[ 8] = myScreen.calculateColour(255,   0,   0);
    colours[ 9] = myScreen.calculateColour(255,  43,   0);
    colours[10] = myScreen.calculateColour(255,  85,   0);
    colours[11] = myScreen.calculateColour(255, 127,   0);
    colours[12] = myScreen.calculateColour(255, 171,   0);
    colours[13] = myScreen.calculateColour(255, 213,   0);
    colours[14] = myScreen.calculateColour(255, 255,   0);
    colours[15] = myScreen.calculateColour(255, 255, 255);
    myScreen.setFontSolid(false);
    myScreen.setFontSize(1);
    myScreen.gText(60, 40, "Temperature: ");
    myScreen.gText(60, 60, "Humidity:   %");
    myScreen.gText(60, 80, "CO2: ");
    myScreen.gText(60, 100, "CO: ");
}

void loop() {
  // put your main code here, to run repeatedly: 
    float result[3] = {0};
    myScreen.setFontSolid(false);
    myScreen.setFontSize(1);
    char res[10];
    int COValue = 0;
    int dangerlvl = 100;

    if (scd30.isAvailable()) {
        scd30.getCarbonDioxideConcentration(result);
        COValue = analogRead(A3);
        SERIAL.print("Carbon Dioxide Concentration is: ");
        SERIAL.print(result[0]);
        SERIAL.println(" ppm");
        SERIAL.print("Carbon Monoxide Concentration is: ");
        SERIAL.print(COValue);
        SERIAL.println(" ppm");
        SERIAL.println(" ");
        SERIAL.print("Temperature = ");
        SERIAL.print(result[1]);
        SERIAL.println(" ℃");
        SERIAL.println(" ");
        SERIAL.print("Humidity = ");
        SERIAL.print(result[2]);
        SERIAL.println(" %");

        SERIAL.println(" ");
        SERIAL.println(" ");
        SERIAL.println(" ");
//        ftoa(result[0], res, 2);
//        String temp = "Temperature:" + res;
        myScreen.gText(60, 40, "Temperature: " + String(result[0]) + "C");
        myScreen.gText(60, 60, "Humidity: " + String(result[2]) + "%");
        myScreen.gText(60, 80, "CO2: " + String(result[0]) + "ppm");
        myScreen.gText(60, 100, "CO: " + String(COValue) + "ppm");
        if (COValue > dangerlvl) {
            analogWrite();  
        }
    }

    delay(2000);
}
