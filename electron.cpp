// Clive Marvelous, last updated 6/4/24

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

using std::string;

#include "fourMomentum.h"
#include "lepton.h"
#include "electron.h"

// Initialise electron count
int electron::electron_count = 0;

// Electron copy constructor and assignment
electron::electron(const electron& e) : lepton{e}, 
  energy_deposited_in_calorimeter{e.energy_deposited_in_calorimeter}
  {std::cout<<"Electron copy constructor called"<<std::endl;}
electron & electron::operator=(const electron& e)
{
  std::cout<<"Electron copy assignment called"<<std::endl;
  if(&e != this)
  {
    lepton::operator=(e); // Call lepton copy assignment
    energy_deposited_in_calorimeter = e.energy_deposited_in_calorimeter;
  }
  return *this;
}

// Electron move constructor and assignment
electron::electron(electron&& e) : lepton{std::move(e)}, 
  energy_deposited_in_calorimeter{std::move(e.energy_deposited_in_calorimeter)}
  {std::cout<<"Electron move constructor called"<<std::endl;}
electron & electron::operator=(electron&& e)  
{
  std::cout<<"Electron move assignment called"<<std::endl;
  if(this != &e) 
  {
    lepton::operator=(std::move(e)); // Call lepton move assignment
    energy_deposited_in_calorimeter = std::move(e.energy_deposited_in_calorimeter); 
  }
    return *this;
}

// Electron print function
void electron::print_data() 
{
  std::cout<<"Class: Electron"<<std::endl;
  lepton::print_shared_data();

  // Electron-specific information
  std::cout<<"Deposited Energies in Calorimeter:"<<std::endl;
  std::cout<<"EM1: "<<energy_deposited_in_calorimeter.at(0)<<" MeV"<<std::endl;
  std::cout<<"EM2: "<<energy_deposited_in_calorimeter.at(1)<<" MeV"<<std::endl;
  std::cout<<"HAD1: "<<energy_deposited_in_calorimeter.at(2)<<" MeV"<<std::endl;
  std::cout<<"HAD2: "<<energy_deposited_in_calorimeter.at(3)<<" MeV"<<std::endl;
  std::cout<<std::endl;
}
// End of electron class and associated member functions
