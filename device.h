#ifndef DEVICE_H
#define DEVICE_H
#include <iostream>
#include <string>
using namespace std;


class Device
{

private:

    string name;
    int def, min, max;
public:
    Device();
    Device(string name, int def, int min, int max);
    void set_name(string name);
    void set_def(int def);
    void set_min(int min);
    void set_max(int max);
    string get_name();
    int get_def();
    int get_min();
    int get_max();
    void print_dev();
    ~Device();
};

#endif // DEVICE_H
