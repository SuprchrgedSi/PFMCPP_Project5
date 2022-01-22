#pragma once

struct StandingDesk;
struct StandingDeskWrapper
{
    StandingDeskWrapper (StandingDesk* ptr);
    ~StandingDeskWrapper();
    StandingDesk* ptrToStandingDesk;
};

struct GuitarAmp;
struct GuitarAmpWrapper
{
    GuitarAmpWrapper (GuitarAmp* ptr);
    ~GuitarAmpWrapper();
    GuitarAmp* ptrToGuitarAmp;
};

struct PowerStrip;
struct PowerStripWrapper
{
    PowerStripWrapper (PowerStrip* ptr);
    ~PowerStripWrapper();
    PowerStrip* ptrToPowerStrip;
};

struct HomeOffice;
struct HomeOfficeWrapper
{
    HomeOfficeWrapper (HomeOffice* ptr);
    ~HomeOfficeWrapper();
    HomeOffice* ptrToHomeOffice;
};

struct GuitarRack;
struct GuitarRackWrapper
{
    GuitarRackWrapper (GuitarRack* ptr);
    ~GuitarRackWrapper();
    GuitarRack* ptrToGuitarRack;
};
