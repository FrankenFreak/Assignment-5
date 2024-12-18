// Clive Marvelous, last updated 6/4/24

#ifndef MUON_H
#define MUON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

using std::string;

#include "fourMomentum.h"
#include "lepton.h"

// Muon derived class
class muon : public lepton
{
protected:
  bool isolated; // true if muon is isolated from other particles
  static int muon_count;

public:
  muon() : lepton("muon", -1, ParticleType::PARTICLE, 0, 0, 0, 0), isolated{} {std::cout<<"Muon constructor called"<<std::endl;}
  muon(ParticleType particle_type_in, bool isolation_info, double E, double px, double py, double pz) :
    lepton("muon", -1, particle_type_in, E, px, py, pz), isolated{isolation_info}
    {
      std::cout<<"Muon constructor called"<<std::endl;
      // Check for antiparticle
      lepton_name = (particle_type == ParticleType::ANTIPARTICLE) ? "antimuon" : "muon";
      charge = (particle_type == ParticleType::ANTIPARTICLE) ? 1 : -1;
    }
  ~muon() {std::cout<<"Muon destructor called"<<std::endl;};

  // Copy constructor and assignment
  muon(const muon&); 
  muon& operator=(const muon&); 

  // Move constructor and assignment
  muon(muon&&); 
  muon& operator=(muon&&);
  
  // Getter functions 
  const string get_isolation() const {return isolated ? "True" : "False";}
  static int get_muon_count() {return muon_count;}

  // Setter functions
  void set_isolation(bool isolation_info) {isolated=isolation_info;}
  void set_particle_type(ParticleType particle_type_in) override 
  {
    lepton::set_particle_type(particle_type_in);
    lepton_name = (particle_type == ParticleType::ANTIPARTICLE) ? "antimuon" : "muon";
    charge = (particle_type == ParticleType::ANTIPARTICLE) ? 1 : -1;
  }


  // Print data function
  void print_data() override;
};

#endif