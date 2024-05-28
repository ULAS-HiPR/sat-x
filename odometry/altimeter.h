#ifndef __BMP3XX_H__
#define __BMP3XX_H__

#include "bmp3.h"
#include "wiringPiI2C.h"

#define BMP3XX_DEFAULT_ADDRESS (0x77) ///< The default I2C address

class Adafruit_BMP3XX {
public:
  Adafruit_BMP3XX();

    // change this to wiring pi i2c
  bool begin_I2C(uint8_t addr = BMP3XX_DEFAULT_ADDRESS,
                 );
  uint8_t chipID(void);
  float readTemperature(void);
  float readPressure(void);
  float readAltitude(float seaLevel);

  bool setTemperatureOversampling(uint8_t os);
  bool setPressureOversampling(uint8_t os);
  bool setIIRFilterCoeff(uint8_t fs);
  bool setOutputDataRate(uint8_t odr);

  /// Perform a reading in blocking mode
  bool performReading(void);

  /// Temperature (Celsius) assigned after calling performReading()
  double temperature;
  /// Pressure (Pascals) assigned after calling performReading()
  double pressure;

private:
// change stuff here, what? who knows
  Adafruit_I2CDevice *i2c_dev = NULL; ///< Pointer to I2C bus interface

  bool _init(void);

  bool _filterEnabled, _tempOSEnabled, _presOSEnabled, _ODREnabled;
  uint8_t _i2caddr;
  int32_t _sensorID;
  int8_t _cs;
  unsigned long _meas_end;


  struct bmp3_dev the_sensor;
};

#endif