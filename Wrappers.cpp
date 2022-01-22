#include "Wrappers.h"
#include "StandingDesk.h"
#include "GuitarAmp.h"
#include "PowerStrip.h"
#include "HomeOffice.h"
#include "GuitarRack.h"

StandingDeskWrapper::StandingDeskWrapper(StandingDesk* ptr) : ptrToStandingDesk(ptr) {}
StandingDeskWrapper::~StandingDeskWrapper() { delete ptrToStandingDesk; }

GuitarAmpWrapper::GuitarAmpWrapper(GuitarAmp* ptr) : ptrToGuitarAmp(ptr) {}
GuitarAmpWrapper::~GuitarAmpWrapper(){ delete ptrToGuitarAmp; }

PowerStripWrapper::PowerStripWrapper(PowerStrip* ptr) : ptrToPowerStrip(ptr) {}
PowerStripWrapper::~PowerStripWrapper(){ delete ptrToPowerStrip; }

HomeOfficeWrapper::HomeOfficeWrapper(HomeOffice* ptr) : ptrToHomeOffice(ptr) {}
HomeOfficeWrapper::~HomeOfficeWrapper() { delete ptrToHomeOffice; }

GuitarRackWrapper::GuitarRackWrapper(GuitarRack* ptr) : ptrToGuitarRack(ptr) {}
GuitarRackWrapper::~GuitarRackWrapper() { delete ptrToGuitarRack; }
