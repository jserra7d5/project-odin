#include "prop.h"
#include <Arduino.h>

Prop::Prop(int _motor_pin) : motor_pin(_motor_pin) {
    pinMode(motor_pin, OUTPUT);
    analogWriteFrequency(motor_pin, 600000);
    analogWriteResolution(16);
    analogWrite(motor_pin, 0);
};

void Prop::SetThrottle(double throttle) {
    // first take out our possible edge cases
    if (throttle < 0.0) throttle = 0.0;
    if (throttle > 1.0) throttle = 1.0;

    uint16_t command = EncodeDShotCommand(throttle);
    SendDShotCommand(command);
};

// Converts throttle to a 16-bit DShot600 command
uint16_t Prop::EncodeDShotCommand(double throttle) {
    uint16_t value = static_cast<uint16_t>(throttle * 2000) + 48; // add 48 because the first 48 bits is reserved for ???

    // adding CRC checksum
    uint16_t checksum = 0;
    uint16_t temp = value;
    for (int i = 0; i < 3; i++) {
        checksum ^= temp;
        temp >>= 4;
    }
    checksum &= 0x07;
    return (value << 3) | checksum;
}

// Sends the encoded command via PWM
void Prop::SendDShotCommand(uint16_t command) {
    uint16_t bitMask = 0x8000;
    for (int i = 0; i < 16; ++i) {
        if (command & bitMask) {
            // '1' bit: High for 2/3 of the cycle
            analogWrite(motor_pin, 43790);
        } else {
            // '0' bit: High for 1/3 of the cycle
            analogWrite(motor_pin, 21845);
        }
        delayMicroseconds(2);
        bitMask >>= 1;
    }
    analogWrite(motor_pin, 0);
}
