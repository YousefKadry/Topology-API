#include "API.h"
#include "json.hpp"

using json = nlohmann::json;

API::API()
{

}

bool API::readJSON(string FileName)
{
    ifstream file(FileName +".json");

        try
        {
            json jf = json::parse(file);
            Topology topo;
            vector<Component> comps_list;
            topo.set_id(jf["id"]);
            for (int i = 0; i < jf["components"].size(); i++) {
                Component comp;
                comp.set_id(jf["components"][i]["id"]);
                comp.set_type(jf["components"][i]["type"]);

                if (comp.get_type() == "resistor") {
                    Resistance *res=new Resistance();
                    res->set_name("resistance");
                    json r = jf["components"][i]["resistance"];
                    res->set_def(r["default"]);
                    res->set_min(r["min"]);
                    res->set_max(r["max"]);
                    json net = jf["components"][i]["netlist"];
                    comp.set_device(res);
                    comp.set_netlist(net);
                    comps_list.push_back(comp);
                }
                else if (comp.get_type() == "nmos" || comp.get_type() == "pmos") {
                    Transistor* t = new Transistor();;
                    t->set_name("m(l)");
                    json res = jf["components"][i]["m(l)"];
                    t->set_def(res["default"]);
                    t->set_min(res["min"]);
                    t->set_max(res["max"]);
                    json net = jf["components"][i]["netlist"];
                    comp.set_device(t);
                    comp.set_netlist(net);
                    comps_list.push_back(comp);
                }

            }
            topo.set_comp_list(comps_list);
            topo_list.push_back(topo);

        }
        catch (const std::exception&)
        {
            return false;
        }
        return true;
}

bool API::writeJSON(string topo_id)
{
    string jsonName;
        cout << "Please, enter json file name you want to create : ";
        cin >> jsonName;
        if (jsonName == "") {
            return false;
        }
        cout << endl;
        json j;
        ofstream o(jsonName+".json");

        Topology topo;
        for (int i = 0; i < topo_list.size(); i++) {
            if (topo_list[i].get_id() == topo_id) {
                topo = topo_list[i];
                break;
            }
        }
        if (topo.get_id() == "") {

            return false;
        }

        o << "{" << endl;

        string id = " \"id\": \"" + topo.get_id() + "\",";
        o << id << endl;
        o << "\"components\" :[";
        vector<Component>comps_list = topo.get_comp_list();
        for (int i = 0; i < topo.get_comp_list().size(); i++) {
            o << "{";
            o << "\"type\":";
            if (comps_list[i].get_type() == "resistor") {
                o << "\"resistor\",";
                o << "\"id\":" << "\"" << comps_list[i].get_id() << "\"," << endl;
                o << "\"resistance\" : {";
                o << "\"default\" :" << comps_list[i].get_device()->get_def() << ",";
                o << "\"min\" :" << comps_list[i].get_device()->get_min() << ",";
                o << "\"max\" :" << comps_list[i].get_device()->get_max();
                o << "},";
                ///////Netlist;
                o << "\"netlist\": {";
                unordered_map<string, string> netL = comps_list[i].get_netlist();

                int count = 0;
                for (auto it = netL.begin(); it != netL.end(); it++)
                {
                    count++;
                    // Accessing the key
                    o << "\"" << it->first << " \" : \""
                        // Accessing the value

                        << it->second << "\"";
                    if (count != 2)
                        o << ",";

                }


                if (i != comps_list.size() - 1)
                    o << "}},";
                else
                    o << "}}";
            }
            else if (comps_list[i].get_type() == "nmos" || comps_list[i].get_type() == "pmos") {
                o << "\"" << comps_list[i].get_type() << "\",";
                o << "\"id\":" << "\"" << comps_list[i].get_id() << "\"," << endl;
                o << "\"m(l)\" : {";
                o << "\"default\" :" << comps_list[i].get_device()->get_def() << ",";
                o << "\"min\" :" << comps_list[i].get_device()->get_min() << ",";
                o << "\"max\" :" << comps_list[i].get_device()->get_max();
                o << "},";
                ///////Netlist;
                o << "\"netlist\": {";
                unordered_map<string, string> netL = comps_list[i].get_netlist();

                int count = 0;
                for (auto it = netL.begin(); it != netL.end(); it++)
                {
                    count++;
                    // Accessing the key
                    o << "\"" << it->first << " \" : \""
                        // Accessing the value

                        << it->second << "\"";
                    if (count != 3)
                        o << ",";

                }

                if (i != comps_list.size() - 1)
                    o << "}},";
                else
                    o << "}}";
            }

        }


        o << "]" << endl;
        o << "}" << endl;

        return true;
}

bool API::deleteTopology(string topo_id)
{

        for (int i = 0; i < topo_list.size(); i++) {
            if (topo_list[i].get_id() == topo_id) {

                topo_list[i] = topo_list[topo_list.size() - 1];
                topo_list.pop_back();
                return true;
            }

        }
        return false;
}

vector<Topology> API::queryTopologies()
{
    return topo_list;
}

vector<Device*> API::queryDevices(string topo_id)
{
    string is_found = "not found";
        Topology topo;
        vector<Device*> devices_list;
        int list_len = topo_list.size();
        for (int i = 0; i < list_len; i++) {
            if (topo_list[i].get_id() == topo_id) {
                topo = topo_list[i];
                is_found = "found";
                break;
            }
        }
        if (is_found == "not found")
            return vector<Device*>();
        int componentsSize = topo.get_comp_list().size();
        vector<Component> comps = topo.get_comp_list();
        for (int i = 0; i < componentsSize; i++) {

            devices_list.push_back(comps[i].get_device());


        }
        return devices_list;
}

vector<Device*> API::queryDevicesWithNetlistNode(string topo_id, string netlistNodeId)
{
    bool found = false;
        Topology topo;
        vector<Device*> devices_list;

        for (int i = 0; i < topo_list.size(); i++) {
            if (topo_list[i].get_id() == topo_id) {
                topo = topo_list[i];
                found = true;
                break;
            }
        }
        if (!found)
            return vector<Device*>();
        int comps_Size = topo.get_comp_list().size();
        vector<Component> comps_list = topo.get_comp_list();
        for (int i = 0; i < comps_Size; i++) {
            unordered_map<string, string>netlist = comps_list[i].get_netlist();
            bool connected = false;
            for (auto it : netlist) {
                if (it.second == netlistNodeId) {
                    connected = true;
                    break;
                }
            }
            if (connected) {

                devices_list.push_back(comps_list[i].get_device());

            }

        }


        return devices_list;
}

API::~API(){}
