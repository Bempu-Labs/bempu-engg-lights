void tableLED(uint8_t t1, uint8_t t2) {
    analogWrite(TABLE1, t1);
    analogWrite(TABLE2, t2);
}


void rgbLED(uint8_t w, uint8_t r, uint8_t g, uint8_t b) {
    analogWrite(WHITE, w);
    analogWrite(RED, r);
    analogWrite(GREEN, g);
    analogWrite(BLUE, b);
}