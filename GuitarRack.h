#pragma once
#include "LeakedObjectDetector.h"
#include "GuitarAmp.h"
#include "PowerStrip.h"

struct GuitarRack
{
    GuitarAmp guitarAmp;
    PowerStrip powerStrip;

    GuitarRack();
    ~GuitarRack();
    void startupGuitarRack();
    double playDistorted(double inputVoltage);
    void reportAmpOutput(double inputVoltage);

    JUCE_LEAK_DETECTOR(GuitarRack)
};
