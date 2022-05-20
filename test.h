#ifndef TEST_H
#define TEST_H
#include <string>
#include <vector>
#include "topology.h"
#include "API.h"
#include "device.h"

class Test
{
private:
    API app;
public:
    Test();
    void Testing_Query1();
    void Testing_Query2();
    void Testing_Query3();
    void Testing_Query4();
    void Testing_Query5();
    void Testing_Query6();
    ~Test();

};

#endif // TEST_H
