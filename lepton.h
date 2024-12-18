// Clive Marvelous, last updated 6/4/24

#ifndef LEPTON_H
#define LEPTON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <memory>

using std::string;

#include "fourMomentum.h"

enum class ParticleType
{
  PARTICLE,
  ANTIPARTICLE
};
enum class Flavour
{
  ELECTRON,
  MUON,
  TAU,
  NONE
};
enum class DecayMode 
{
  HADRONIC,
  LEPTONIC
};

// Beginning of lepton class 
class lepton
{
protected:
  

  string lepton_name; 
  int charge;
  std::shared_ptr<fourMomentum> four_momentum;
  ParticleType particle_type;

  // Print function
  void print_shared_data();

  // Validation functions
  double validate_energy(double energy_in) 
  {
    if(energy_in<0) throw std::invalid_argument("Energy cannot be negative.");
    return energy_in;
  }
  int validate_charge(int charge_in) 
  {
    if(charge_in != 1 && charge_in != -1 && charge_in != 0) throw std::invalid_argument("Charge must be either +1, 0 or -1.");
    return charge_in;
  }

public:
  // Constructor and destructor
  lepton() : lepton_name{"lepton"}, charge{}, four_momentum{std::make_shared<fourMomentum>()}, 
    particle_type{ParticleType::PARTICLE} {std::cout<<"Lepton constructor called"<<std::endl;}

  lepton(string name, int charge_in, ParticleType particle_type_in, double E, double px, double py, double pz) : 
    lepton_name{name}, charge{validate_charge(charge_in)}, four_momentum{std::make_shared<fourMomentum>(validate_energy(E), px, py, pz)},
    particle_type{particle_type_in} {std::cout<<"Lepton constructor called"<<std::endl;}

  virtual ~lepton() {std::cout<<"Lepton destructor called"<<std::endl;}

  // Copy constructor and assignment
  lepton(const lepton&);
  lepton& operator=(const lepton&);

  // Move constructor and assignment
  lepton(lepton&&);
  lepton& operator=(lepton&&);

  // Getter functions 
  const string get_name() const {return lepton_name;}
  const int get_charge() const {return charge;}
  const double get_E() const {return four_momentum->get_E();}
  const double get_px() const {return four_momentum->get_px();}
  const double get_py() const {return four_momentum->get_py();}
  const double get_pz() const {return four_momentum->get_pz();}
  const string get_particle_type() const {return (particle_type == ParticleType::PARTICLE) ? "Particle" : "Antiparticle";}
  virtual void get_decay_products() {std::cout<<"Decay products not available"<<std::endl;}

  // Setter functions
  void set_name(string name_in) {lepton_name=name_in;}
  void set_charge(int charge_in) {charge=validate_charge(charge_in);}
  void set_E(double E) {four_momentum->set_E(validate_energy(E));}
  void set_px(double px) {four_momentum->set_px(px);}
  void set_py(double py) {four_momentum->set_py(py);}
  void set_pz(double pz) {four_momentum->set_pz(pz);}
  virtual void set_particle_type(ParticleType particle_type_in) {particle_type=particle_type_in;}
  virtual void set_decay(DecayMode decay_mode_in, Flavour product_flavour_in) {std::cout<<"Decay products not available"<<std::endl;};

  // Friend functions
  friend fourMomentum sum(const lepton& l1, const lepton& l2);
  friend double dotProduct(const lepton& l1, const lepton& l2);

  // Print function
  virtual void print_data();
};



#endif