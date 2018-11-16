uint8_t white, red, green, blue, table1, table2;    // LED Status variables
uint16_t light;                                     // holds LDR value
uint16_t lightThreshold;                            // Threshold for LDR

// clock
uint8_t s, m, h;

// flags
uint8_t flagPIRraised;
uint8_t flagPIRhigh;
uint8_t flagTableShutdown;
uint8_t flagMapLDR=1;
uint8_t flagManualMode;
