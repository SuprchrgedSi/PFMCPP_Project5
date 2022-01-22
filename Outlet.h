#pragma once
#include "LeakedObjectDetector.h"

struct Outlet
{
    static int numOutlets;
    
    int outletNum;
    float currentPower = 3.1f;
    std::string GFCIState = "normal";
    std::string connectorFormat = "US";
    bool plugInstalled;

    Outlet();
    ~Outlet();
    void tripGFCI();
    float getCurrentPower();
    bool isPlugInstalled();
    void confirmPlugInstalled();

    JUCE_LEAK_DETECTOR(Outlet)

};
