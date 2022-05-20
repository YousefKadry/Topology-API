#include "test.h"


Test::Test()
{

}

void Test::Testing_Query1()
{
    bool TrueReturned = true;
    bool FalseReturned = false;
    string fileName = "topology";
    string fileName1 = "topo1";
    string fileName2 = "topo2";
    string fileName3 = "topo3";
    bool x;
    try
    {
     x = app.readJSON(fileName);

        cout << "PASSED" << endl;
    }
    catch (const std::exception&) {
        cout << "DIDN'T PASS" << endl;
    }
    try
    {
        x = app.readJSON(fileName1);

        cout << "PASSED" << endl;
    }
    catch (const std::exception&) {
        cout << "DIDN'T PASS" << endl;
    }

    try
    {
        x = app.readJSON(fileName2);

        cout << "PASSED" << endl;
    }
    catch (const std::exception&) {
        cout << "DIDN'T PASS" << endl;
    }
    try
    {
        x = app.readJSON(fileName3);
        if(x==FalseReturned)
            cout << "PASS" << endl;
    }
    catch (const std::exception&) {
        cout << "DIDN'T PASS" << endl;
    }
}


void Test::Testing_Query2()
{
    bool x;
    bool FalseReturned = false;
    bool TrueReturned = true;
    try
    {
        string fileName = "";

        x = app.writeJSON(fileName);
        if (x == FalseReturned)
            cout << "PASSED" << endl;
    }
    catch (const std::exception&) {
        cout << "DIDN'T PASS" << endl;
    }
    try
    {
        string fileName = "top1";

        x = app.writeJSON(fileName);
        if (x == TrueReturned)
            cout << "PASSED" << endl;
    }
    catch (const std::exception&) {
        cout << "DIDN'T PASS" << endl;
    }
}

void Test::Testing_Query3()
{
    //The tests are done in sequence
    vector<Topology> Test;
    Test = app.queryTopologies();
    if (Test.size() != 0) {
        cout << "PASSED" << endl;
    }
    else {
        cout << "DIDN'T PASS";
    }



}

void Test::Testing_Query4()
{
    bool x = true;
    app.deleteTopology("top2");
    vector<Topology>TopologyList = app.queryTopologies();
    for (int i = 0; i < TopologyList.size(); i++) {
        if (TopologyList[i].get_id() == "top2") {
            x = false;
        }
    }
    if (x) {
        cout << "PASSED" << endl;
    }
    else {
        cout << "DIDN'T PASS";
    }

}

void Test::Testing_Query5()
{
    vector<Device*>test = app.queryDevices("top1");

    if (test.size()!=2&&test[0]->get_name() != "resistance" && test[0]->get_max() != 1000 && test[0]->get_min() != 10 && test[0]->get_def() != 100 && test[1]->get_name() != "m(l)" && test[1]->get_max() != 2 && test[1]->get_min() != 1 && test[1]->get_def() != 1.5) {
        cout << "DIDN'T PASS" << endl;
    }
    else {
        cout << "PASSED" << endl;
    }

}

void Test::Testing_Query6()
{
    vector<Device*>test = app.queryDevicesWithNetlistNode("top1","n1");

    if (test.size() != 2 && test[0]->get_name() != "resistance" && test[0]->get_max() != 1000 && test[0]->get_min() != 10 && test[0]->get_def() != 100 && test[1]->get_name() != "m(l)" && test[1]->get_max() != 2 && test[1]->get_min() != 1 && test[1]->get_def() != 1.5) {
        cout << "DIDN'T PASS" << endl;
    }
    else {
        cout << "PASSED" << endl;
    }

}

Test::~Test(){}
