#include "action.hh"
#include "generator.hh"


MyActionInitialization::MyActionInitialization()
 : G4VUserActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::BuildForMaster() const
{}

void MyActionInitialization::Build() const
{
  SetUserAction(new MyPrimaryGenerator);  
} 