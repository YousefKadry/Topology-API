#ifndef API_H
#define API_H
#include "component.h"
#include "resistance.h"
#include "transistor.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include "topology.h"
#include "vector"
#include <fstream>



class API
{
private:

    vector<Topology> topo_list;

public:
    API();
    bool readJSON(string FileName);
    bool writeJSON(string topo_id);
    bool deleteTopology(string topo_id);
    vector<Topology> queryTopologies();
    vector<Device*> queryDevices(string topo_id);
    vector<Device*> queryDevicesWithNetlistNode(string topo_id, string netlistNodeId);

    ~API();


};

#endif // API_H
