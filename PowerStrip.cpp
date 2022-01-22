#include <iostream>
#include "PowerStrip.h"

PowerStrip::PowerStrip() : 
numOutlets(3),
maxSurgeProtection(2400.f),
numPopulatedOutlets(0)
{
    std::cout << "PowerStrip" << std::endl; 
    outlet1.outletNum = 1;    
    outlet2.outletNum = 2;    
    outlet3.outletNum = 3;
}

PowerStrip::~PowerStrip()
{
    std::cout << "PowerStrip object destroyed." << std::endl;
}

int PowerStrip::insertPlug(int outletNum) 
{
    if (outlet1.outletNum == outletNum) outlet1.plugInstalled = true;
    else if (outlet2.outletNum == outletNum) outlet2.plugInstalled = true;
    else if (outlet3.outletNum == outletNum) outlet3.plugInstalled = true;
    else 
    {
        std::cout << "There is no outlet number " << outletNum << " in power strip";
        return 0;
    }
    std::cout << "Outlet " << outletNum << " now has a plug installed. " << std::endl;
    return outletNum;
}

float PowerStrip::getPowerStripPower()
{
    float totalPower = outlet1.getCurrentPower() + outlet2.getCurrentPower() + outlet3.getCurrentPower();

    std::cout << "The power strip is supplying " << totalPower << "" << " watts of power" << std::endl;

    return totalPower;
}

void PowerStrip::disablePower()
{
    std::cout << "The power strip is now disabled." << std::endl;
    outlet1.GFCIState = "off";
    outlet2.GFCIState = "off";
    outlet3.GFCIState = "off";
}

void PowerStrip::enablePower()
{
    std::cout << "The power strip is now enabled." << std::endl;
    outlet1.GFCIState = "on";
    outlet2.GFCIState = "on";
    outlet3.GFCIState = "on";
}

void PowerStrip::cyclePower(int numCycles)
{
    for (int i = 0; i < numCycles; ++i)
    {
        if (outlet1.GFCIState == "off") 
        {
            enablePower();
        }
        else
        {
            disablePower();
            enablePower();
        }
    }
    
}
