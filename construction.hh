#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh" 

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
    private:
    G4VPhysicalVolume *fWorld;

    public:

    MyDetectorConstruction(G4VPhysicalVolume *setWorld = 0)
    {   
        fWorld = setWorld;
    }

    virtual G4VPhysicalVolume *Construct()
    {
        return fWorld;
    }
};

#endif