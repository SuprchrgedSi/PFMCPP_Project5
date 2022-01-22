#include <iostream>
#include "HomeOffice.h"

HomeOffice::HomeOffice()
{
    std::cout << "HomeOffice" << std::endl;
    turnOnAndConfigure(28.3f, 47.3f, "sitting");
}

HomeOffice::~HomeOffice()
{
    std::cout << "HomeOffice destroyed." << std::endl;
}

void HomeOffice::turnOnAndConfigure(float sittingHeight,float standingHeight,  std::string startingConfig)
{
    std::cout << "Plugging in desk." << std::endl;
    powerStrip.insertPlug(1);
    std::cout << "Turning on power strip." << std::endl;
    powerStrip.enablePower();
    std::cout << "Setting standing desk." << std::endl;
    standingDesk.sittingHeight = sittingHeight;
    standingDesk.standingHeight = standingHeight;
    if (startingConfig == "standing") 
    {
        standingDesk.deskHeight = standingHeight;
        standingDesk.currentConfig = startingConfig;
    }
    else 
    {
        standingDesk.deskHeight = sittingHeight;
        standingDesk.currentConfig = "sitting";
    }
    std::cout << "Desk is in " << startingConfig << " configuration at " << standingDesk.deskHeight << " inches." << std::endl;
}

std::string HomeOffice::switchConfiguration()
{
    if (standingDesk.currentConfig == "standing")
    {
        standingDesk.currentConfig = "sitting";
        standingDesk.deskHeight = standingDesk.sittingHeight;
    }
    else 
    {
        standingDesk.currentConfig = "standing";
        standingDesk.deskHeight = standingDesk.standingHeight;
    }

    std::cout << "Desk is in " << standingDesk.currentConfig << " configuration at " << standingDesk.deskHeight << " inches." << std::endl;

    return standingDesk.currentConfig;
}

void HomeOffice::reportNumOutlets()
{
    std::cout << "The powerstrip has " << this->powerStrip.numOutlets << " outlets." << std::endl;
}
