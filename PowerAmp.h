#pragma once
#include "LeakedObjectDetector.h"

struct PowerAmp
{
    double gain;
    std::string ampTopology = "Class AB";
    int outputImpedance;
    int numOutputs = 1;
    std::string powerState;

    PowerAmp();
    ~PowerAmp();
    void changeGain(double gainAdjustment);
    void enableAmpStandby();
    int selectImpedance(int impedance = 8);
    void turnOnStandby();
    bool waitUntilWarm(double targetTemp);
    void reportTopology();
    
    JUCE_LEAK_DETECTOR(PowerAmp)
};
