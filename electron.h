// Clive Marvelous, last updated 6/4/24

#ifndef ELECTRON_H
#define ELECTRON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <memory>

#include "fourMomentum.h"
#include "lepton.h"

using std::string;

// Electron derived class
class electron : public lepton
{
protected:
  std::vector<double> energy_deposited_in_calorimeter;
  static int electron_count;

  // Validation function
  void validate_energy_deposit(double& EM_1, double& EM_2, double& HAD_1, double& HAD_2, double E) 
  {
    double total_energy = EM_1 + EM_2 + HAD_1 + HAD_2;
    // Ensure total_energy = energy of electron
    if(total_energy != E) 
    {
        // Adjust the values
        double scale = E/total_energy;
        EM_1 *= scale;
        EM_2 *= scale;
        HAD_1 *= scale;
        HAD_2 *= scale;
    }
  }

public:
  // Constructor and destructor
  electron() : lepton("electron", -1, ParticleType::PARTICLE, 0, 0, 0, 0), energy_deposited_in_calorimeter(4) {std::cout<<"Electron constructor called"<<std::endl;}
  electron(ParticleType particle_type_in, double E, double px, double py, double pz, double EM_1, double EM_2, double HAD_1, double HAD_2) :
    lepton("electron", -1, particle_type_in, E, px, py, pz)
    {
      std::cout<<"Electron constructor called"<<std::endl;
      // Check for antiparticle
      if(particle_type == ParticleType::ANTIPARTICLE)
      {
        lepton_name = "antielectron";
        charge = 1;
      }
      
      // Validate and store energy deposit values into vector
      validate_energy_deposit(EM_1, EM_2, HAD_1, HAD_2, E);
      energy_deposited_in_calorimeter = {EM_1, EM_2, HAD_1, HAD_2};
    }
  ~electron() {std::cout<<"Electron destructor called"<<std::endl;}
  
  // Copy constructor and assignment
  electron(const electron&); 
  electron& operator=(const electron&); 

  // Move constructor and assignment
  electron(electron&&); 
  electron& operator=(electron&&);
  
  // Getter functions 
  const double get_EM1() const {return energy_deposited_in_calorimeter.at(0);}
  const double get_EM2() const {return energy_deposited_in_calorimeter.at(1);}
  const double get_HAD1() const {return energy_deposited_in_calorimeter.at(2);}
  const double get_HAD2() const {return energy_deposited_in_calorimeter.at(3);}
  static int get_electron_count() {return electron_count;}

  // Setter functions
  void set_energy_deposit(double EM_1, double EM_2, double HAD_1, double HAD_2) 
  {
    validate_energy_deposit(EM_1, EM_2, HAD_1, HAD_2, four_momentum->get_E());
    energy_deposited_in_calorimeter = {EM_1, EM_2, HAD_1, HAD_2};
  }
  void set_particle_type(ParticleType particle_type_in) override
  {
    lepton::set_particle_type(particle_type_in);
    lepton_name = (particle_type == ParticleType::ANTIPARTICLE) ? "antielectron" : "electron";
    charge = (particle_type == ParticleType::ANTIPARTICLE) ? 1 : -1;
  }

  // Print data function
  void print_data() override;
};

#endif