#pragma once
#include "LeakedObjectDetector.h"
#include "PowerAmp.h"

struct GuitarAmp
{
    double preampGain;
    int numChannels;
    float maxOutPower;
    double trebleGain = 0.5;
    double reverbLevel;

    PowerAmp powerAmp;

    GuitarAmp();
    ~GuitarAmp();
    void turnOnAmp();
    double amplifyGuitar(double inputVoltage = 0.0);
    double adjustReverbAmount(double reverbGain = 1.0);
    int switchChannel(int currentChannel, int newChannel = 0);
    void adjustGainForTargetOutput(double inputVoltage = 0.0, double targetOutput = 0.0);

    JUCE_LEAK_DETECTOR(GuitarAmp)
};
