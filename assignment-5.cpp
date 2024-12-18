// PHYS 30762 Programming in C++
// Assignment 5
// Practice inheritance in C++ classes
// See slides for guidance
// Author: Clive Marvelous (10916086)
// Date: 12/4/24

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <memory>

using std::string;

#include "fourMomentum.h"
#include "lepton.h"
#include "electron.h"
#include "muon.h"
#include "neutrino.h"
#include "tau.h"

// Main program
int main()
{
  
  std::vector<std::unique_ptr<lepton>> lepton_data;
  lepton_data.push_back(std::make_unique<electron>(ParticleType::PARTICLE, 5110, 900, 800, 700, 1, 1, 1, 1));
  lepton_data.push_back(std::make_unique<electron>(ParticleType::PARTICLE, 2110, 900, 800, 700, 1, 1, 1, 1));
  lepton_data.push_back(std::make_unique<muon>(ParticleType::PARTICLE, true, 1110, 900, 800, 700));
  lepton_data.push_back(std::make_unique<muon>(ParticleType::PARTICLE, true, 2110, 900, 800, 700));
  lepton_data.push_back(std::make_unique<muon>(ParticleType::PARTICLE, false, 3110, 900, 800, 700));
  lepton_data.push_back(std::make_unique<muon>(ParticleType::PARTICLE, false, 4110, 900, 800, 700));
  lepton_data.push_back(std::make_unique<electron>(ParticleType::ANTIPARTICLE, 2110, 900, 800, 700, 1, 1, 1, 1));
  lepton_data.push_back(std::make_unique<muon>(ParticleType::ANTIPARTICLE, false, 4110, 900, 800, 700));
  lepton_data.push_back(std::make_unique<neutrino>(ParticleType::PARTICLE, Flavour::MUON, true, 4110, 900, 800, 700));
  lepton_data.push_back(std::make_unique<neutrino>(ParticleType::PARTICLE, Flavour::ELECTRON, false, 2210, 900, 800, 700));
  lepton_data.push_back(std::make_unique<tau>(ParticleType::PARTICLE, DecayMode::LEPTONIC, Flavour::MUON, 5110, 900, 800, 700));
  lepton_data.push_back(std::make_unique<tau>(ParticleType::ANTIPARTICLE, DecayMode::LEPTONIC, Flavour::ELECTRON, 5110, 900, 800, 700));

  // Print out the data of all the leptons
  for(const auto& lepton_it : lepton_data) lepton_it->print_data();

  // Sum four momentums of two electrons
  fourMomentum sum_electrons = sum(*lepton_data[0], *lepton_data[1]);
  std::cout<<"Sum of four momentums:"<<std::endl;
  sum_electrons.print_data();

  // Dot product of antielectron and antimuon
  double dot_product = dotProduct(*lepton_data[6], *lepton_data[7]);
  std::cout<<std::endl;
  std::cout<<"Dot product of antielectron and antimuon: "<<dot_product<<std::endl;
  std::cout<<std::endl;

  // Challenge mark: Move electron
  std::unique_ptr<electron> new_electron = std::make_unique<electron>(ParticleType::PARTICLE, 7110, 100, 200, 300, 1.5, 2.5, 3.5, 4.5);
  std::cout<<std::endl;
  std::cout<<"New Electron Data: "<<std::endl;
  new_electron->print_data();
  std::cout<<std::endl;
  std::unique_ptr<electron> move_electron = std::move(new_electron);
  std::cout<<"Moved Electron Data: "<<std::endl;
  move_electron->print_data();
  std::cout<<std::endl;

  // Challenge mark: shared ptr
  std::shared_ptr<tau> tau_shared_1 = std::make_shared<tau>(ParticleType::PARTICLE, DecayMode::LEPTONIC, Flavour::ELECTRON, 6000, 300, 400, 500);
  std::shared_ptr<tau> tau_shared_2 = tau_shared_1; 
  std::shared_ptr<tau> tau_shared_3 = tau_shared_1; 

  std::cout<<std::endl;
  std::cout<<"tau_shared_1: "<<std::endl;
  tau_shared_1->print_data();
  std::cout<<"tau_shared_2: "<<std::endl;
  tau_shared_2->print_data();
  std::cout<<"tau_shared_3: "<<std::endl;
  tau_shared_3->print_data();
  std::cout<<std::endl;
  
 
  return 0;
}
