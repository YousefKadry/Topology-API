#ifndef RESISTANCE_H
#define RESISTANCE_H
#include "device.h"


class Resistance: public Device
{

private:

public:
    Resistance();
    Resistance(string name, int def, int min, int max);
    ~Resistance();
};

#endif // RESISTANCE_H
