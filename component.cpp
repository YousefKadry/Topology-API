#include "component.h"

Component::Component(){}

Component::Component(string type, string id, unordered_map<string,string> netlist, Device* device)
{
    this->type = type;
    this->id = id;
    this->netlist = netlist;
    this->device = device;

}

void Component::set_type(string type)
{
    this->type = type;
}

void Component::set_id(string id)
{
    this->id = id;
}

void Component::set_netlist(unordered_map<string,string> netlist)
{
    this->netlist = netlist;
}

void Component::set_device(Device* device)
{
    this->device = device;
}

string Component::get_type()
{
    return this->type;
}

string Component::get_id()
{
    return this->id;
}

unordered_map<string,string> Component::get_netlist()
{
    return this->netlist;
}

Device* Component::get_device()
{
    return this->device;
}

void Component::print_comps()
{
    cout << "Component: " << endl;
        this->device->print_dev();
        cout << "Netlist: " << endl;
        for (auto it : this->netlist) {
            cout << it.first << " : " << it.second << endl;
        }
}

Component::~Component(){}
