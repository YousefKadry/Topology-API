#ifndef COMPONENT_H
#define COMPONENT_H
#include <iostream>
#include <string>
#include <unordered_map>
#include "device.h"
using namespace std;

class Component
{

private:

    string type, id;
    Device* device;
    unordered_map<string, string> netlist;


public:
    Component();
    Component(string type, string id, unordered_map<string,string> netlist, Device* device);
    void set_type(string type);
    void set_id(string id);
    void set_netlist(unordered_map<string,string> netlist);
    void set_device(Device* device);
    string get_type();
    string get_id();
    unordered_map<string,string> get_netlist();
    Device* get_device();
    void print_comps();

    ~Component();
};

#endif // COMPONENT_H
