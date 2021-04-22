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
unsigned long start;

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
    myScreen.setFontSize(myScreen.fontMax());
    myScreen.gText(60, 40, "Temperature: ");
    myScreen.gText(60, 60, "Humidity: ");
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
    int dangerlvl = 70;
    float tempArr[10];
    float humiArr[10];
    float co2Arr[10];
    float coArr[10];
    
    float temp = 0;
    float humi = 0;
    float co2 = 0;
    float co = 0;

    
    for (int i=0; i < 10; i++) {
//        SERIAL.println("Program running: "+String(time/1000)+ " seconds.");
        scd30.getCarbonDioxideConcentration(result);
        tempArr[i] = result[1];
        humiArr[i] = result[2];
        co2Arr[i] = result[0];
        coArr[i] = analogRead(A14); //CO reading and process analogRead needed
        //        if (COValue > dangerlvl) { //Will add in the pin for sound element and finalize the danger level for CO alarm trigger [70ppm]
//            analogWrite();  
//        }
        SERIAL.print("Carbon Dioxide Concentration is: ");
        SERIAL.print(result[0]);
        SERIAL.println(" ppm");
        SERIAL.print("Carbon Monoxide Concentration is: ");
        SERIAL.print(coArr[i]);
        SERIAL.println(" ppm");
        SERIAL.print("Temperature = ");
        SERIAL.print(result[1]);
        SERIAL.println(" ℃");
        SERIAL.print("Humidity = ");
        SERIAL.print(result[2]);
        SERIAL.println(" %");
        SERIAL.println(" ");

//        SERIAL.println(tempArr[i]);
//        SERIAL.println(humiArr[i]);
//        SERIAL.println(co2Arr[i]);
        //SERIAL.println(coArr[i]);
        delay(2500);
    }
    unsigned long time = millis();


    for (int i=0; i < 10; i++) {
        temp += tempArr[i];
        humi += humiArr[i];
        co2 += co2Arr[i];
        co += coArr[i];

//        co = co/10; //process needed
    }
    temp = temp/10;
    humi = humi/10;
    co2 = co2/10;
    co = co/10;
//    SERIAL.println(temp);
//    SERIAL.println(humi);
//    SERIAL.println(co2);
    // String processing for readings, resolutions etc.

    //push button between temperature units 

//    myScreen.setFontSolid(false);
//    myScreen.setFontSize(1);
    myScreen.setFontSize(myScreen.fontMax());
    myScreen.gText(60, 40, "Temperature: " + String(temp) + " C");
    myScreen.gText(60, 60, "Humidity: " + String(humi) + " %");
    myScreen.gText(60, 80, "CO2: " + String(co2) + " ppm");
    myScreen.gText(60, 100, "CO: " + String(co) + " ppm");
    myScreen.gText(60, 120, "Time since last update: " + String((time-start)/1000) + " seconds.");
    
    delay(275000);
    start = time;
    myScreen.clear();

}
