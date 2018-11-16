#include "config.h"
#include "globals.h"
#include "functions.h"
#include "led.h"
#include "serial.h"
#include "TimerOne.h"









void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    
    // make the LED pins as output
    pinMode(WHITE,OUTPUT);
    pinMode(RED,OUTPUT); 
    pinMode(GREEN,OUTPUT);
    pinMode(BLUE,OUTPUT);
    pinMode(TABLE1,OUTPUT);
    pinMode(TABLE2,OUTPUT);
    
    // PIR Interrupt
    attachInterrupt(digitalPinToInterrupt(PIR), motiondetect, RISING);
    
    // start timer1 with 1s interrupt
    Timer1.initialize(1000000);  // initialize timer1, and set a 1 second period
    Timer1.attachInterrupt(oneSecCallback);
}

void loop() {
    
    // pir mode
    if(!flagManualMode) {  // if PIR mode is activated
        if(flagPIRraised) {
            if(digitalRead(PIR)) {
                flagPIRhigh=1;
                // turn on the Table LEDS
                
                // set intensity data from LDR values
                table1 = 150;   // replace with data calculated from LDR value
                table2 = 150;   // replace with data calculated from LDR value
                
                flagTableShutdown=0;
            }
            else {
                flagPIRhigh=0;
                flagPIRraised=0;
                // reset the clock
                s=0; m=0; h=0;
            }
        }


        // dim the table lights
        if(table1 > 0 && flagTableShutdown == 1 ){
            table1--;
        }
        if(table2>0 && flagTableShutdown == 1) {
            table2--;
        }
        delay(100);
    }

    // Manual Mode
    else {

    }


    
    tableLED(table1, table2);
}







void motiondetect() {
    flagPIRraised=1;  
}





void oneSecCallback() {
    // time will only tick when no motion is detected and the lights are already on
    
    if(flagPIRhigh==0 && flagManualMode==0 && (table1>0 || table2>0)) {
        s++;
        if(s==60) {
            m++;
            s=0;
        }
        if(m==60) {
            h++;
            m=0;
        }

        Serial.print(h);
        Serial.print(":");
        Serial.print(m);
        Serial.print(":");
        Serial.println(s);
    
    }


    if(s==30 && m==0 && h==0) {
        flagTableShutdown=1;
    }
        
    
}

