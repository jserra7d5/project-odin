#include "airframe.h"
#include "util.h"

Airframe::Airframe() 
    : front_left(C_FRONT_LEFT_MOTOR_PIN),
    front_right(C_FRONT_RIGHT_MOTOR_PIN),
    rear_left(C_REAR_LEFT_MOTOR_PIN),
    rear_right(C_REAR_RIGHT_MOTOR_PIN) {};

void Airframe::periodic() {
    double controller_throttle = 0.0; // dynamic later
    double adjusted_throttle = ApplyDeadband(controller_throttle, C_THROTTLE_DEADBAND);

    front_left.SetThrottle(adjusted_throttle);
    front_right.SetThrottle(adjusted_throttle);
    rear_left.SetThrottle(adjusted_throttle);
    rear_right.SetThrottle(adjusted_throttle);
};
