#ifndef TOPOLOGY_H
#define TOPOLOGY_H
#include <iostream>
#include <string>
#include "device.h"
#include "component.h"
#include "vector"

class Topology
{
private:

    string topology_id;
    vector<Component> components_list;
public:
    Topology();
    Topology(string topology_id, vector<Component> components_list);
    void set_id(string topology_id);
    void set_comp_list(vector<Component> components_list);
    void add_component(Component comp);
    vector<Component> get_comp_list();
    string get_id();
    void print_topo();
    ~Topology();
};

#endif // TOPOLOGY_H
