// Clive Marvelous, last updated 6/4/24

#ifndef NEUTRINO_H
#define NEUTRINO_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

using std::string;

#include "fourMomentum.h"
#include "lepton.h"

// Neutrino derived class
class neutrino : public lepton
{
protected:
  Flavour flavour;
  bool hasInteracted; // true if neutrino interacted with detector
  static int neutrino_count;

public:
  neutrino() : lepton("neutrino", 0, ParticleType::PARTICLE, 0, 0, 0, 0), hasInteracted{false} {std::cout<<"Neutrino constructor called"<<std::endl;}
  neutrino(ParticleType particle_type_in, Flavour flavour_in, bool interaction, double E, double px, double py, double pz) :
    lepton("neutrino", 0, particle_type_in, E, px, py, pz), hasInteracted{interaction}, flavour{flavour_in}
    {
      std::cout<<"Neutrino constructor called"<<std::endl;

      // Update name
      switch(flavour)
      {
        case Flavour::ELECTRON:
          lepton_name = (particle_type == ParticleType::ANTIPARTICLE) ? "electron antineutrino" : "electron neutrino";
          break;
        case Flavour::MUON:
          lepton_name = (particle_type == ParticleType::ANTIPARTICLE) ? "muon antineutrino" : "muon neutrino";
          break;
        case Flavour::TAU:
          lepton_name = (particle_type == ParticleType::ANTIPARTICLE) ? "tau antineutrino" : "tau neutrino";
          break;
      }
    }
  ~neutrino() {std::cout<<"Neutrino destructor called"<<std::endl;}

  // Copy constructor and assignment
  neutrino(const neutrino&); 
  neutrino& operator=(const neutrino&); 

  // Move constructor and assignment
  neutrino(neutrino&&); 
  neutrino& operator=(neutrino&&);
  
  // Getter functions 
  const string get_interaction() const {return hasInteracted ? "has interacted" : "has not interacted";}
  static int get_neutrino_count() {return neutrino_count;}

  // Setter functions
  void set_interaction(bool interaction) {hasInteracted=interaction;}
  void set_particle_type(ParticleType particle_type_in) override
  {
    lepton::set_particle_type(particle_type_in);
    // Update name
    switch(flavour)
    {
      case Flavour::ELECTRON:
        lepton_name = (particle_type == ParticleType::ANTIPARTICLE) ? "electron antineutrino" : "electron neutrino";
        break;
      case Flavour::MUON:
        lepton_name = (particle_type == ParticleType::ANTIPARTICLE) ? "muon antineutrino" : "muon neutrino";
        break;
      case Flavour::TAU:
        lepton_name = (particle_type == ParticleType::ANTIPARTICLE) ? "tau antineutrino" : "tau neutrino";
        break;
    }
  }
  


  // Print data function
  void print_data() override;

};

#endif