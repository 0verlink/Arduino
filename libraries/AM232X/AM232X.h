#ifndef AM232X_H
#define AM232X_H
//
//    FILE: AM232X.h
//  AUTHOR: Rob Tillaart
// PURPOSE: AM232X library for Arduino .
// VERSION: 0.1.1
// HISTORY: See AM232X.cpp
//     URL:
//
// Released to the public domain
//

#include "Wire.h"
#include "Arduino.h"

#define AM232X_LIB_VERSION          "0.1.1"

#define AM232X_OK                    0
#define AM232X_MISSING_BYTES        -10
#define AM232X_ERROR_CONNECT        -11
#define AM232X_ERROR_FUNCTION       -12
#define AM232X_ERROR_ADDRESS        -13
#define AM232X_ERROR_REGISTER       -14
#define AM232X_ERROR_CRC_1          -15
#define AM232X_ERROR_CRC_2          -16
#define AM232X_ERROR_WRITE_DISABLED -17
/*
from datasheet
0x80: not support function code 
0x81: Read an illegal address 
0x82: write data beyond the scope
0x83: CRC checksum error 
0x84: Write disabled
*/

#define AM232X_ADDRESS        0x5C

class AM232X
{
public:
  AM232X();

  int read();
  int getModel();
  int getVersion();
  uint32_t getDeviceID();

  int getStatus();
  int getUserRegisterA();
  int getUserRegisterB();

  int setUserRegisterA(int value);
  int setUserRegisterB(int value);

  float humidity;
  float temperature;

private:
  uint8_t _deviceAddress;
  int _model;
  int _version;
  uint32_t _deviceID;

  uint8_t bits[8];
  int _readRegister(uint8_t reg, uint8_t cnt);
  int _writeRegister(uint8_t reg, uint8_t cnt, int32_t value);

  uint16_t crc16(uint8_t *ptr, uint8_t len);
};

#endif
// END OF FILE