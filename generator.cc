#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
  :G4VUserPrimaryGeneratorAction(),
   fParticleGun(0)
{
    fParticleGun = new G4ParticleGun(1);
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName="e-";
    G4ParticleDefinition *particle = particleTable->FindParticle(particleName);

    G4ThreeVector pos(0.,0.,-1.*cm);
    G4ThreeVector mom(0.,0.,1.);

    fParticleGun->SetParticlePosition(pos); 
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleEnergy(6.*MeV);
    fParticleGun->SetParticleDefinition(particle);
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
