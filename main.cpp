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
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */

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

struct StandingDeskWrapper
{
    StandingDeskWrapper (StandingDesk* ptr) : ptrToStandingDesk(ptr){}
    ~StandingDeskWrapper()
    {
        delete ptrToStandingDesk;
    }
    StandingDesk* ptrToStandingDesk;
};

/*
 copied UDT 2:
 */
struct GuitarAmp
{
    double preampGain;
    int numChannels;
    float maxOutPower;
    double trebleGain = 0.5;
    double reverbLevel;

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

GuitarAmp::PowerAmp::PowerAmp() :
gain(1.0),
outputImpedance(8),
powerState("off")
{ 
    std::cout << "PowerAmp" << std::endl; 
}

GuitarAmp::PowerAmp::~PowerAmp()
{
    std::cout << "PowerAmp object destroyed." << std::endl;
}
void GuitarAmp::PowerAmp::changeGain(double gainAdjustment) 
{ 
    gain *= gainAdjustment; 
    std::cout << "The new power amp gain is " << gain << "." << std::endl;
}

void GuitarAmp::PowerAmp::enableAmpStandby() 
{ 
    std::cout << "The power amp is now in standby." << std::endl;
    powerState = "standby"; 
    
    if (waitUntilWarm(155.2)) 
        std::cout << "The amp is ready for full power." << std::endl;

}

int GuitarAmp::PowerAmp::selectImpedance(int impedance) 
{ 
    if (impedance != outputImpedance)
    {
        std::cout << "The user has selected an impedance of " << impedance << "." << std::endl;
        outputImpedance = impedance;
    }
    return impedance;
}

bool GuitarAmp::PowerAmp::waitUntilWarm(double targetTemp)
{
    double currentTemp = 72;
    while (currentTemp < targetTemp)
    {
        std::cout << "Amp temp is " << currentTemp << ". Checking again in 10 seconds." << std::endl;
        currentTemp += 25.3; 
    }
    return true;
}

void GuitarAmp::PowerAmp::reportTopology()
{
     std::cout << "The power amp has a " << this->ampTopology << " configuration." << std::endl;
}


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

struct GuitarAmpWrapper
{
    GuitarAmpWrapper (GuitarAmp* ptr) : ptrToGuitarAmp(ptr){}
    ~GuitarAmpWrapper()
    {
        delete ptrToGuitarAmp;
    }
    GuitarAmp* ptrToGuitarAmp;
};

/*
 copied UDT 3:
 */
struct PowerStrip
{
    int numOutlets;
    float maxSurgeProtection;
    int wireGauge = 18;
    int numPopulatedOutlets;

    struct Outlet
    {
        static int numOutlets;
        
        int outletNum;
        float currentPower = 3.1f;
        std::string GFCIState = "normal";
        std::string connectorFormat = "US";
        bool plugInstalled;

        Outlet();
        ~Outlet();
        void tripGFCI();
        float getCurrentPower();
        bool isPlugInstalled();
        void confirmPlugInstalled();

        JUCE_LEAK_DETECTOR(Outlet)

    };

    Outlet outlet1;
    Outlet outlet2;
    Outlet outlet3;

    PowerStrip();
    ~PowerStrip();
    int insertPlug(int outletNum);
    float getPowerStripPower();
    void enablePower();
    void disablePower();
    void cyclePower(int numCycles);

    JUCE_LEAK_DETECTOR(PowerStrip)
};

int PowerStrip::Outlet::numOutlets = 0;

PowerStrip::Outlet::Outlet() : 
plugInstalled(false)
{ 
    outletNum = ++numOutlets;
    std::cout << "Outlet" << std::endl; 
}

PowerStrip::Outlet::~Outlet()
{
    std::cout << "Outlet object destroyed." << std::endl;
}

void PowerStrip::Outlet::tripGFCI()
{
    std::cout << "Outlet " << outletNum << " has tripped." << std::endl;
    currentPower = 0.0;
    GFCIState = "tripped";
}

float PowerStrip::Outlet::getCurrentPower() 
{
    std::cout << "Outlet " << outletNum << " is supplying " << currentPower << " watts of power" << std::endl;
    return currentPower; 
}

bool PowerStrip::Outlet::isPlugInstalled() 
{ 
    if (plugInstalled) { std::cout << "Outlet " << outletNum << " has a plug installed. " << std::endl; }
    else               { std::cout << "Outlet " << outletNum << " does not have a plug installed. " << std::endl; }
    
    return plugInstalled; 
}

void PowerStrip::Outlet::confirmPlugInstalled()
{
    if (this->isPlugInstalled()) 
        std::cout << "After running insertPlug function, the isPlugInstalled function verifies plug is installed." << std::endl;
}

PowerStrip::PowerStrip() : 
numOutlets(3),
maxSurgeProtection(2400.f),
numPopulatedOutlets(0)
{
    std::cout << "PowerStrip" << std::endl; 
    outlet1.outletNum = 1;    
    outlet2.outletNum = 2;    
    outlet3.outletNum = 3;
}

PowerStrip::~PowerStrip()
{
    std::cout << "PowerStrip object destroyed." << std::endl;
}

int PowerStrip::insertPlug(int outletNum) 
{
    if (outlet1.outletNum == outletNum) outlet1.plugInstalled = true;
    else if (outlet2.outletNum == outletNum) outlet2.plugInstalled = true;
    else if (outlet3.outletNum == outletNum) outlet3.plugInstalled = true;
    else 
    {
        std::cout << "There is no outlet number " << outletNum << " in power strip";
        return 0;
    }
    std::cout << "Outlet " << outletNum << " now has a plug installed. " << std::endl;
    return outletNum;
}

float PowerStrip::getPowerStripPower()
{
    float totalPower = outlet1.getCurrentPower() + outlet2.getCurrentPower() + outlet3.getCurrentPower();

    std::cout << "The power strip is supplying " << totalPower << "" << " watts of power" << std::endl;

    return totalPower;
}

void PowerStrip::disablePower()
{
    std::cout << "The power strip is now disabled." << std::endl;
    outlet1.GFCIState = "off";
    outlet2.GFCIState = "off";
    outlet3.GFCIState = "off";
}

void PowerStrip::enablePower()
{
    std::cout << "The power strip is now enabled." << std::endl;
    outlet1.GFCIState = "on";
    outlet2.GFCIState = "on";
    outlet3.GFCIState = "on";
}

void PowerStrip::cyclePower(int numCycles)
{
    for (int i = 0; i < numCycles; ++i)
    {
        if (outlet1.GFCIState == "off") 
        {
            enablePower();
        }
        else
        {
            disablePower();
            enablePower();
        }
    }
    
}

struct PowerStripWrapper
{
    PowerStripWrapper (PowerStrip* ptr) : ptrToPowerStrip(ptr){}
    ~PowerStripWrapper()
    {
        delete ptrToPowerStrip;
    }
    PowerStrip* ptrToPowerStrip;
};

/*
 new UDT 4:
 with 2 member functions
 */
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

// JUCE_LEAK_DETECTOR(HomeOffice)

struct HomeOfficeWrapper
{
    HomeOfficeWrapper (HomeOffice* ptr) : ptrToHomeOffice(ptr){}
    ~HomeOfficeWrapper()
    {
        delete ptrToHomeOffice;
    }
    HomeOffice* ptrToHomeOffice;
};

/*
 new UDT 5:
 with 2 member functions
 */
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

// JUCE_LEAK_DETECTOR(GuitarRack)

struct GuitarRackWrapper
{
    GuitarRackWrapper (GuitarRack* ptr) : ptrToGuitarRack(ptr){}
    ~GuitarRackWrapper()
    {
        delete ptrToGuitarRack;
    }
    GuitarRack* ptrToGuitarRack;
};

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
