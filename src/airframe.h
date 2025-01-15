#ifndef AIRFRAME_H
#define AIRFRAME_H

#include "prop.h"
#include "Config.h"

class Airframe {
    public:
        Airframe();

        void periodic();

    private:
        Prop front_left;
        Prop front_right;
        Prop rear_left;
        Prop rear_right;
};

#endif