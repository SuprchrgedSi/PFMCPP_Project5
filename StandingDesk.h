#pragma once
#include "LeakedObjectDetector.h"

struct StandingDesk
{
    float unladenWeight;
    float sittingHeight;
    float standingHeight;
    float deskHeight;
    std::string currentConfig;
    double maxSupportedWeight = 276.3;
    float maxHeight = 48.f;
    double width = 48.0;
    std::string compositionMaterial = "glass";
    std::string drawerLocation;

    StandingDesk(float sittingHeight, float standingHeight);
    ~StandingDesk();
    std::string slideDrawer();
    void changeHeight(float heightChange = 1.f);
    double rollDesk(double xDistance = 0.5, double yDistance = 0.5);
    int maxOutHeight(float incrementSize);
    void getDrawerPosition();
    void reportRollDistance(double xDistance, double yDistance);

    JUCE_LEAK_DETECTOR(StandingDesk)
};
