#include <iostream>
#include "GuitarAmp.h"

GuitarAmp::GuitarAmp() : 
preampGain(0.25),
numChannels(2),
maxOutPower(100.f),
reverbLevel(0.25)
{
    std::cout << "GuitarAmp" << std::endl; 
}

GuitarAmp::~GuitarAmp()
{
    std::cout << "GuitarAmp object destroyed." << std::endl;
}

void GuitarAmp::turnOnAmp()
{
    powerAmp.enableAmpStandby();
}

double GuitarAmp::amplifyGuitar(double inputVoltage) 
{ 
    return inputVoltage * preampGain * powerAmp.gain;
}

double GuitarAmp::adjustReverbAmount(double reverbGain)
{
    reverbLevel *= reverbGain;
    return reverbLevel;
}

int GuitarAmp::switchChannel(int currentChannel, int newChannel)
{
    if (currentChannel == newChannel) 
    {
        std::cout << "The amp is now in channel " << newChannel << "." << std::endl;
        return currentChannel;
    }

    return newChannel;
}

void GuitarAmp::adjustGainForTargetOutput(double inputVoltage, double targetOutput)
{
    while (amplifyGuitar(inputVoltage) <  targetOutput)
    {
        powerAmp.gain *= 1.5;
    }
    std::cout << "Corrected output gain is " << powerAmp.gain << "." << std::endl;
}
