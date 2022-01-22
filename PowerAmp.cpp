#include <iostream>
#include "PowerAmp.h"

PowerAmp::PowerAmp() :
gain(1.0),
outputImpedance(8),
powerState("off")
{ 
    std::cout << "PowerAmp" << std::endl; 
}



PowerAmp::~PowerAmp()
{
    std::cout << "PowerAmp object destroyed." << std::endl;
}
void 

PowerAmp::changeGain(double gainAdjustment) 
{ 
    gain *= gainAdjustment; 
    std::cout << "The new power amp gain is " << gain << "." << std::endl;
}

void 

PowerAmp::enableAmpStandby() 
{ 
    std::cout << "The power amp is now in standby." << std::endl;
    powerState = "standby"; 
    
    if (waitUntilWarm(155.2)) 
        std::cout << "The amp is ready for full power." << std::endl;

}

int 

PowerAmp::selectImpedance(int impedance) 
{ 
    if (impedance != outputImpedance)
    {
        std::cout << "The user has selected an impedance of " << impedance << "." << std::endl;
        outputImpedance = impedance;
    }
    return impedance;
}

bool 

PowerAmp::waitUntilWarm(double targetTemp)
{
    double currentTemp = 72;
    while (currentTemp < targetTemp)
    {
        std::cout << "Amp temp is " << currentTemp << ". Checking again in 10 seconds." << std::endl;
        currentTemp += 25.3; 
    }
    return true;
}

void 

PowerAmp::reportTopology()
{
     std::cout << "The power amp has a " << this->ampTopology << " configuration." << std::endl;
}
