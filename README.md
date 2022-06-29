# geant4_radiotherapy
radiotherapy simulation using geant4 based on Varian Clinac iX

this repo shows how to do radiotherapy with simulation of Varian Clinac iX 

guide : build the file using cmake in child folder "build" then insert gdml files in that build folder 

gdml files link = https://drive.google.com/drive/folders/1ZF7K4e0xKozYbh1DCWeVq6l2pX51TpY_?usp=sharing

how to use :

./sim "<gdml files>" "<macro files>" 

if you want to record log file :

./sim "<gdml files>" "<macro files>" | tee "<logfile>"

what need to be improved : 

1. use biasing technique
2. do filtering in sampling the data
3. improve the scoring technique so it can detect which voxel in which volume (furthermore able to generate DVH for the therapy)
