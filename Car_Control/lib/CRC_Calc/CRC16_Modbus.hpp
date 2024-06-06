#ifndef CRC16_MODBUS
#define CRC16_MODBUS
#include <Arduino.h>

extern uint8_t crc16_data[];
extern uint16_t IRAM_ATTR crc16tablefast(uint8_t *ptr, uint16_t len);

#endif