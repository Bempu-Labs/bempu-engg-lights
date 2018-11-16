uint8_t header;


void serialEvent() {
    uint8_t value, tmp;
    if(!header) {
        header=Serial.read();
        

        if(header=='L'){
            flagMapLDR=1;   // 1 for ON
            Serial.println("LDR mapping is tuned on");
            header = 0;
        }

        else if(header=='l'){
            flagMapLDR=0;   // 0 for OFF
            Serial.println("LDR mapping is tuned off");
            header = 0;
        }
        
        else if(header=='M'){
            flagManualMode=1;   // 1 for ON
            Serial.println("Manual mode activated");
            header = 0;
        }

        else if(header=='m'){
            flagManualMode=0;   // 1 for ON
            Serial.println("PIR mode activated");
            header = 0;
        }

        else if(header=='d'){
            light = analogRead(LDR);
            Serial.print("LDR Value: ");
            Serial.println(light);
            header=0;
        }

        else if(header=='w'){
            Serial.print("Enter intencity of White LED strip (0-255): ");
        }

        else if(header=='g'){
            Serial.print("Enter intencity of Green LED strip (0-255): ");
        }

        else if(header=='b'){
            Serial.print("Enter intencity of Blue LED strip (0-255): ");
        }

        else if(header=='t'){
            Serial.print("Enter intencity of Tuhin's LED (0-255): ");
        }

        else if(header=='s'){
            Serial.print("Enter intencity of Sourabh's LED (0-255): ");
        }

        else if(header=='h'){
            Serial.println();
            Serial.println();
            Serial.println();
            Serial.println();
            Serial.println("*************  Welcome to console Healp *************");
            Serial.println("M  :  Activates manual Mode");
            Serial.println("m  :  Activates PIR Mode");
            Serial.println("L  :  Turns on LDR mapping to light intencity");
            Serial.println("l  :  Turns off LDR mapping to light intencity");
            Serial.println("w  :  Sets intencity of white LED strip");
            Serial.println("g  :  Sets intencity of green LED strip");
            Serial.println("b  :  Sets intencity of blue LED strip");
            Serial.println("t  :  Sets intencity of Tuhin's LED");
            Serial.println("s  :  Sets intencity of Sourabh's LED");
            Serial.println("h  :  Shows this menu");
            Serial.println();
            Serial.println();
            Serial.println();
            Serial.println();
            header=0;
        } 
        
    }

    else {
        value=Serial.parseInt();
        if(header=='w'){
            Serial.println(value);
            white=value;    
        }

        else if(header=='r'){
            red=value;
            Serial.println(value);
        }

        else if(header=='g'){
            green=value;
            Serial.println(value);
        }

        else if(header=='b'){
            blue=value;
            Serial.println(value);
        }

        else if(header=='t'){
            table1=value;
            Serial.println(value);
        }
        
        else if(header=='s'){
            table2=value;
            Serial.println(value);
        }
              
        
        rgbLED(white, red, green, blue);
        tableLED(table1, table2);
        header=0;
    }
}