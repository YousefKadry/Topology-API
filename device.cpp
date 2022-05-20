#include "device.h"

Device::Device(){}

Device::Device(string name, int def, int min, int max)
{
    this->name = name;
    this->def = def;
    this->min = min;
    this->max = max;
}
void Device::set_name(string name)
{
    this->name = name;
}

void Device::set_def(int def)
{
    this->def = def;
}

void Device::set_min(int min)
{
    this->min = min;
}

void Device::set_max(int max)
{
    this->max = max;
}

string Device::get_name()
{
    return this->name;
}

int Device::get_def()
{
    return this->def;
}

int Device::get_min()
{
    return this->min;
}
int Device::get_max()
{
    return this->max;
}

void Device::print_dev()
{
    cout << "Device Details : " << endl;
    cout << "Default: " << this->get_def() << "---max: " << this->get_max() << " ---min:" << this->get_min() << endl;
}

Device::~Device(){}
