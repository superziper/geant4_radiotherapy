#include "G4RunManagerFactory.hh"

#include "G4UImanager.hh"

#include "construction.hh"
#include "action.hh"
#include "QGSP_BIC_HP.hh" 

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "G4GDMLParser.hh"

#include "G4ScoringManager.hh"

int main(int argc, char** argv)
{   
    G4cout << G4endl;
    G4cout << "Usage: sim <gdml_file> <macro_file>" << G4endl;
    G4cout << G4endl;

    G4UIExecutive* ui = nullptr;

    if (argc < 2)
    {
        G4cout << "Error! Mandatory input file is not specified!" << G4endl;
        G4cout << G4endl;
        return -1;
    }
    
    G4GDMLParser parser;

    parser.SetOverlapCheck(true);
    parser.Read(argv[1]);
    G4ScoringManager * scManager = G4ScoringManager::GetScoringManager();
    scManager->SetVerboseLevel(1);

    G4Random::setTheEngine(new CLHEP::RanecuEngine());
    G4long seed = time(NULL);
    G4Random::setTheSeed(seed);

    auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);

    runManager->SetUserInitialization(new MyDetectorConstruction(
                                        parser.GetWorldVolume()));
    G4VUserPhysicsList* physics = new QGSP_BIC_HP;
    runManager->SetUserInitialization(physics);
    runManager->SetUserInitialization(new MyActionInitialization());

    G4VisManager* visManager = new G4VisExecutive;

    visManager->Initialize();

    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    if ( argc > 2 ) {
    G4String command = "/control/execute ";
    G4String fileName = argv[2];
    UImanager->ApplyCommand(command+fileName);
    }

    else {
    ui = new G4UIExecutive(argc, argv);
    UImanager->ApplyCommand("/control/execute vis.mac");
    ui->SessionStart();
    delete ui;
    }

    delete visManager;
    delete runManager;
    return 0;
}
