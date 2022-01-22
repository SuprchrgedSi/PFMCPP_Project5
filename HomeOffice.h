#pragma once
#include "LeakedObjectDetector.h"
#include "StandingDesk.h"
#include "PowerStrip.h"

struct HomeOffice
{
    StandingDesk standingDesk{36.f, 48.f};
    PowerStrip powerStrip;

    HomeOffice();
    ~HomeOffice();
    void turnOnAndConfigure(float standingHeight, float sittingHeight, std::string startingConfig);
    std::string switchConfiguration();
    void reportNumOutlets();

    JUCE_LEAK_DETECTOR(HomeOffice)
};
