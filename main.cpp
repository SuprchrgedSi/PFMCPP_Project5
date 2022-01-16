/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() 
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}


#include <iostream>
#include <cmath>
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
    };

    PowerAmp powerAmp;

    GuitarAmp();
    ~GuitarAmp();
    void turnOnAmp();
    double amplifyGuitar(double inputVoltage = 0.0);
    double adjustReverbAmount(double reverbGain = 1.0);
    int switchChannel(int currentChannel, int newChannel = 0);
    void adjustGainForTargetOutput(double inputVoltage = 0.0, double targetOutput = 0.0);
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
    std::cout << "Warming up amplifier";
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
    StandingDesk standingDesk {36.f, 48.f};
    PowerStrip powerStrip;
    GuitarAmp guitarAmp;

    std::cout << "The desk drawer is currently " << standingDesk.drawerLocation << "." << std::endl;
    standingDesk.slideDrawer();
    standingDesk.changeHeight(5.1f);
    std::cout << "The desk rolled " << standingDesk.rollDesk(1.5, 3.7) << " feet." << std::endl;

    std::cout << "-----------------------" << std::endl;
    
    powerStrip.enablePower();
    powerStrip.outlet1.tripGFCI();
    powerStrip.outlet2.currentPower = 1.3f;
    powerStrip.insertPlug(3);

    if (powerStrip.outlet3.isPlugInstalled())
    {
        std::cout << "After running insertPlug function, the isPlugInstalled function verifies plug is installed." << std::endl;
    }

    powerStrip.getPowerStripPower();
    powerStrip.cyclePower(3);
    
    std::cout << "-----------------------" << std::endl;

    guitarAmp.turnOnAmp();
    guitarAmp.powerAmp.changeGain(0.5);
    guitarAmp.powerAmp.selectImpedance(4);
    guitarAmp.amplifyGuitar(0.01);
    guitarAmp.adjustReverbAmount(0.3);
    guitarAmp.switchChannel(2);
    guitarAmp.adjustGainForTargetOutput(0.01, 10.1);

    std::cout << "-----------------------" << std::endl;

    HomeOffice homeOffice;
    homeOffice.switchConfiguration();

    GuitarRack guitarRack;
    std::cout << "Getting amp set for distortion." << std::endl;
    guitarRack.playDistorted(0.1);
    std::cout << "Amplifying guitar." << std::endl;
    for (double i = 0.3; i < 0.7; i += 0.1)
    {
        std::cout << "Amp output is " << guitarRack.guitarAmp.amplifyGuitar(i) << std::endl;
    }
    
    std::cout << "-----------------------" << std::endl;


    std::cout << "good to go!" << std::endl;
}
