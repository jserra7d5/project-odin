#ifndef PROP_H
#define PROP_H

#include <cstdint>

class Prop {
        public:
            Prop(int _motor_pin);

            void SetThrottle(double throttle);

        private:
            int motor_pin;

            // DShot encoding and sending
            void SendDShotCommand(uint16_t command);
            uint16_t EncodeDShotCommand(double throttle);

};

#endif