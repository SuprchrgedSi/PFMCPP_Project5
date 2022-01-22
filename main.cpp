/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
         
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */

#include <iostream>
#include <cmath>
#include "StandingDesk.h"
#include "GuitarAmp.h"
#include "PowerStrip.h"
#include "HomeOffice.h"
#include "GuitarRack.h"
#include "Wrappers.h"


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    StandingDeskWrapper standingDeskWrapper(new StandingDesk{36.f, 48.f});
    PowerStripWrapper powerStripWrapper(new PowerStrip());
    GuitarAmpWrapper guitarAmpWrapper(new GuitarAmp());

    std::cout << "The desk drawer is currently " << standingDeskWrapper.ptrToStandingDesk->drawerLocation << "." << std::endl;
    standingDeskWrapper.ptrToStandingDesk->getDrawerPosition();
    standingDeskWrapper.ptrToStandingDesk->slideDrawer();

    standingDeskWrapper.ptrToStandingDesk->changeHeight(5.1f);
    std::cout << "The desk rolled " << standingDeskWrapper.ptrToStandingDesk->rollDesk(1.5, 3.7) << " feet." << std::endl;
    standingDeskWrapper.ptrToStandingDesk->reportRollDistance(1.5, 3.7);

    std::cout << "-----------------------" << std::endl;
    
    powerStripWrapper.ptrToPowerStrip->enablePower();
    powerStripWrapper.ptrToPowerStrip->outlet1.tripGFCI();
    powerStripWrapper.ptrToPowerStrip->outlet2.currentPower = 1.3f;
    std::cout << "Outlet 2 is supplying " << powerStripWrapper.ptrToPowerStrip->outlet2.currentPower << " watts of power." <<std::endl;
    powerStripWrapper.ptrToPowerStrip->outlet2.getCurrentPower();
    powerStripWrapper.ptrToPowerStrip->insertPlug(3);

    if (powerStripWrapper.ptrToPowerStrip->outlet3.isPlugInstalled())
    {
        std::cout << "After running insertPlug function, the isPlugInstalled function verifies plug is installed." << std::endl;
    }

    powerStripWrapper.ptrToPowerStrip->outlet3.confirmPlugInstalled();

    powerStripWrapper.ptrToPowerStrip->getPowerStripPower();
    powerStripWrapper.ptrToPowerStrip->cyclePower(3);
    
    std::cout << "-----------------------" << std::endl;

    guitarAmpWrapper.ptrToGuitarAmp->turnOnAmp();
    guitarAmpWrapper.ptrToGuitarAmp->powerAmp.changeGain(0.5);
    guitarAmpWrapper.ptrToGuitarAmp->powerAmp.selectImpedance(4);
    guitarAmpWrapper.ptrToGuitarAmp->amplifyGuitar(0.01);
    guitarAmpWrapper.ptrToGuitarAmp->adjustReverbAmount(0.3);
    guitarAmpWrapper.ptrToGuitarAmp->switchChannel(2);
    guitarAmpWrapper.ptrToGuitarAmp->adjustGainForTargetOutput(0.01, 10.1);
    std::cout << "The power amp has a " << guitarAmpWrapper.ptrToGuitarAmp->powerAmp.ampTopology << " configuration." << std::endl;
    guitarAmpWrapper.ptrToGuitarAmp->powerAmp.reportTopology();

    std::cout << "-----------------------" << std::endl;

    HomeOfficeWrapper homeOfficeWrapper(new HomeOffice());
    std::cout << "The powerstrip has " << homeOfficeWrapper.ptrToHomeOffice->powerStrip.numOutlets << " outlets." << std::endl;
    homeOfficeWrapper.ptrToHomeOffice->reportNumOutlets();
    homeOfficeWrapper.ptrToHomeOffice->switchConfiguration();

    GuitarRackWrapper guitarRackWrapper(new GuitarRack());
    std::cout << "Getting amp set for distortion." << std::endl;
    guitarRackWrapper.ptrToGuitarRack->playDistorted(0.1);
    std::cout << "Amplifying guitar." << std::endl;
    for (double i = 0.3; i < 0.7; i += 0.1)
    {
        std::cout << "Amp output is " << guitarRackWrapper.ptrToGuitarRack->guitarAmp.amplifyGuitar(i) << std::endl;
        guitarRackWrapper.ptrToGuitarRack->reportAmpOutput(i);
    }
    
    std::cout << "-----------------------" << std::endl;


    std::cout << "good to go!" << std::endl;
}
