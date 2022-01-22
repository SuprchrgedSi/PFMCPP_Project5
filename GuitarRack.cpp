#include <iostream>
#include "GuitarRack.h"


GuitarRack::GuitarRack()
{
    std::cout << "GuitarRack" << std::endl;
    startupGuitarRack();
}

GuitarRack::~GuitarRack()
{
    std::cout << "GuitarRack destroyed." << std::endl;
}

void GuitarRack::startupGuitarRack()
{
    std::cout << "Plugging in amplifier." << std::endl;
    powerStrip.insertPlug(2);
    std::cout << "Turning on power strip." << std::endl;
    powerStrip.enablePower();
    std::cout << "Warming up amplifier" << std::endl;
    guitarAmp.turnOnAmp();
}

double GuitarRack::playDistorted(double inputVoltage)
{
    std::cout << "Selecting Lead channel." << std::endl;
    guitarAmp.switchChannel(1, 2);
    std::cout << "Setting power amp gain." << std::endl;
    guitarAmp.adjustGainForTargetOutput(inputVoltage, 5.3);
    return guitarAmp.amplifyGuitar(inputVoltage);
}

void GuitarRack::reportAmpOutput(double inputVoltage)
{
    std::cout << "Amp output is " << this->guitarAmp.amplifyGuitar(inputVoltage) << std::endl;
}
