#include "topology.h"

Topology::Topology(){}
Topology::Topology(string topology_id, vector<Component> components_list)
{
    this->topology_id = topology_id;
    this->components_list = components_list;
}

void Topology::set_id(string topology_id)
{
    this->topology_id = topology_id;
}

void Topology::set_comp_list(vector<Component> components_list)
{
    this->components_list = components_list;
}

void Topology::add_component(Component comp)
{
    this->components_list.push_back(comp);
}

string Topology::get_id()
{
    return this->topology_id;
}

vector<Component> Topology:: get_comp_list()
{
    return components_list;
}

void Topology::print_topo()
{
    cout << "Topology's ID: " << this->get_id()<<endl;
        for (int i = 0; i < components_list.size(); i++) {
            components_list[i].print_comps();
            cout << endl<<endl;
}
}

Topology::~Topology(){}
