#include <iostream>
#include <cmath>
#include "StandingDesk.h"

StandingDesk::StandingDesk(float startSittingHeight, float startStandingHeight) :
unladenWeight(10.5f),
sittingHeight(startSittingHeight),
standingHeight(startStandingHeight),
deskHeight(sittingHeight),
currentConfig("sitting"),
drawerLocation("in")
{ 
    
    std::cout << "StandingDesk" << std::endl; 
}
StandingDesk::~StandingDesk()
{
    std::cout << "StandingDesk object destroyed." << std::endl;
}

std::string StandingDesk::slideDrawer()
{ 
    if (drawerLocation == "in") { drawerLocation = "out";}
    else                        { drawerLocation = "in";}
    
    std::cout << "The drawer has been slid " << drawerLocation << "." << std::endl;
    return drawerLocation;
}

void StandingDesk::changeHeight(float heightChange)
{
    std::cout << "The current desk height is " << deskHeight << " inches." << std::endl;
    deskHeight += heightChange;
    std::cout << "The new desk height is " << deskHeight << " inches." << std::endl;
}

double StandingDesk::rollDesk(double xDistance, double yDistance)
{
    return std::pow((std::pow(xDistance, 2) + std::pow(yDistance, 2)), 0.5);
}

int StandingDesk::maxOutHeight(float incrementSize)
{
    int numSteps = 0;
    while (deskHeight < maxHeight)
    {
        if (maxHeight - deskHeight <= incrementSize)
        {
            deskHeight = maxHeight;
            std:: cout << "Increased desk height by " << maxHeight - deskHeight << " inches.  Desk is now at max height of " << maxHeight  << " inches." << std::endl;
            ++numSteps;
            break;
        }
        std:: cout << "Increased desk height by " << incrementSize << " inches.  New height is " << (deskHeight += incrementSize) << " inches." << std:: endl;
        ++numSteps;
    }
    return numSteps;
}

void StandingDesk::getDrawerPosition()
{
    std::cout << "The desk drawer is currently " << this->drawerLocation << "." << std::endl;
}

void StandingDesk::reportRollDistance(double xDistance, double yDistance)
{
    std::cout << "The desk rolled " << this->rollDesk(xDistance, yDistance) << " feet." << std::endl;
}
