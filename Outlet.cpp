#include <iostream>
#include "Outlet.h"

int Outlet::numOutlets = 0;

Outlet::Outlet() : 
plugInstalled(false)
{ 
    outletNum = ++numOutlets;
    std::cout << "Outlet" << std::endl; 
}

Outlet::~Outlet()
{
    std::cout << "Outlet object destroyed." << std::endl;
}

void Outlet::tripGFCI()
{
    std::cout << "Outlet " << outletNum << " has tripped." << std::endl;
    currentPower = 0.0;
    GFCIState = "tripped";
}

float Outlet::getCurrentPower() 
{
    std::cout << "Outlet " << outletNum << " is supplying " << currentPower << " watts of power" << std::endl;
    return currentPower; 
}

bool Outlet::isPlugInstalled() 
{ 
    if (plugInstalled) { std::cout << "Outlet " << outletNum << " has a plug installed. " << std::endl; }
    else               { std::cout << "Outlet " << outletNum << " does not have a plug installed. " << std::endl; }
    
    return plugInstalled; 
}

void Outlet::confirmPlugInstalled()
{
    if (this->isPlugInstalled()) 
        std::cout << "After running insertPlug function, the isPlugInstalled function verifies plug is installed." << std::endl;
}
