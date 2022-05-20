#ifndef TRANSISTOR_H
#define TRANSISTOR_H
#include "device.h"

class Transistor: public Device
{
public:
    Transistor();
    Transistor(string name, int def, int min, int max);
    ~Transistor();
};

#endif // TRANSISTOR_H
