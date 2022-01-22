#pragma once
#include "LeakedObjectDetector.h"
#include "Outlet.h"

struct PowerStrip
{
    int numOutlets;
    float maxSurgeProtection;
    int wireGauge = 18;
    int numPopulatedOutlets;

    Outlet outlet1;
    Outlet outlet2;
    Outlet outlet3;

    PowerStrip();
    ~PowerStrip();
    int insertPlug(int outletNum);
    float getPowerStripPower();
    void enablePower();
    void disablePower();
    void cyclePower(int numCycles);

    JUCE_LEAK_DETECTOR(PowerStrip)
};
