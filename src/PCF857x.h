#ifndef PCF857x_h
#define PCF857x_h

#include "Arduino.h"
#include <Wire.h>

class PCF857x {
    public:
        virtual int read() = 0;
        virtual int read(uint8_t pin) = 0;

        virtual void write(int value) = 0;
        virtual void write(uint8_t pin, int value) = 0;

        virtual void toggle() = 0;
        virtual void toggle(uint8_t pin) = 0;

        virtual void shiftLeft(uint8_t n  = 1) = 0;
        virtual void shiftRight(uint8_t n = 1) = 0;

        virtual  void rotateLeft(uint8_t n  = 1) = 0;
        virtual  void rotateRight(uint8_t n = 1) = 0;

    protected:
        uint8_t i2cRead();
        void i2cWrite(uint8_t data);

        TwoWire* wire;
        uint8_t address;
};

#endif // ifndef PCF857x_h