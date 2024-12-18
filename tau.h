// Clive Marvelous, last updated 6/4/24

#ifndef TAU_H
#define TAU_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

using std::string;

#include "fourMomentum.h"
#include "lepton.h"
#include "electron.h"
#include "muon.h"
#include "neutrino.h"

// Tau derived class
class tau : public lepton
{
protected:
  DecayMode decay_mode; // Decay flag
  Flavour product_flavour;

  // Smart pointers for decay products
  std::vector<std::unique_ptr<lepton>> decay_products;
  

public:
  // Constructor and destructor
  tau() : lepton("tau", -1, ParticleType::PARTICLE, 0, 0, 0, 0), decay_mode{DecayMode::HADRONIC}, product_flavour{Flavour::NONE} {std::cout<<"Tau constructor called"<<std::endl;}
  tau(ParticleType particle_type_in, DecayMode decay_mode_in, Flavour product_flavour_in, double E, double px, double py, double pz) :
    lepton("tau", -1, particle_type_in, E, px, py, pz), decay_mode{decay_mode_in}, product_flavour{product_flavour_in}
    {
      // Check for antiparticle
      if(particle_type == ParticleType::ANTIPARTICLE)
      {
        lepton_name = "antitau";
        charge = 1;
      }
      
      // Decay products
      if(decay_mode == DecayMode::LEPTONIC)
      {
        // Declare decay objects
        decay_products.push_back(std::make_unique<neutrino>(particle_type, Flavour::TAU, false, 0, 0, 0, 0));
        ParticleType anti_particle_type = (particle_type == ParticleType::PARTICLE) ? ParticleType::ANTIPARTICLE : ParticleType::PARTICLE;
        
        switch(product_flavour)
        {
          case Flavour::ELECTRON:
            decay_products.push_back(std::make_unique<electron>(particle_type, 0, 0, 0, 0, 0, 0, 0, 0));
            decay_products.push_back(std::make_unique<neutrino>(anti_particle_type, product_flavour, false, 0, 0, 0, 0));
            break;
          case Flavour::MUON:
            decay_products.push_back(std::make_unique<muon>(particle_type, true, 0, 0, 0, 0));
            decay_products.push_back(std::make_unique<neutrino>(anti_particle_type, product_flavour, false, 0, 0, 0, 0));
            break;
          case Flavour::TAU:
            break;
          case Flavour::NONE:
            break;
        }
      }
      std::cout<<"Tau constructor called"<<std::endl;
    }
  ~tau() {std::cout<<"Tau destructor called"<<std::endl;}
  
  // Getter functions 
  const string get_decay_mode() const {return (decay_mode == DecayMode::HADRONIC) ? "Hadronic" : "Leptonic";}
  void get_decay_products() override
  {
    if(decay_mode == DecayMode::LEPTONIC && decay_products.size() >= 3) 
    {
      std::cout<<"Decay Products:"<<std::endl;
      decay_products[0]->print_data(); // Print tau neutrino data
      decay_products[1]->print_data(); // Print lepton product data
      decay_products[2]->print_data(); // Print lepton neutrino data
    } 
    else std::cout<<"Decay products data not available"<<std::endl;
  }
  
  // Setter functions
  void set_decay(DecayMode decay_mode_in, Flavour product_flavour_in) override
  {
    decay_mode = decay_mode_in;
    product_flavour = product_flavour_in;

    // Clear existing decay products
    decay_products.clear();

    // Decay products
    if(decay_mode == DecayMode::LEPTONIC)
    {
      // Declare decay objects
      decay_products.push_back(std::make_unique<neutrino>(particle_type, Flavour::TAU, false, 0, 0, 0, 0));
      ParticleType anti_particle_type = (particle_type == ParticleType::PARTICLE) ? ParticleType::ANTIPARTICLE : ParticleType::PARTICLE;
        
      switch(product_flavour)
      {
        case Flavour::ELECTRON:
          decay_products.push_back(std::make_unique<electron>(particle_type, 0, 0, 0, 0, 0, 0, 0, 0));
          decay_products.push_back(std::make_unique<neutrino>(anti_particle_type, product_flavour, false, 0, 0, 0, 0));
          break;
        case Flavour::MUON:
          decay_products.push_back(std::make_unique<muon>(particle_type, true, 0, 0, 0, 0));
          decay_products.push_back(std::make_unique<neutrino>(anti_particle_type, product_flavour, false, 0, 0, 0, 0));
          break;
        case Flavour::TAU:
          break;
        case Flavour::NONE:
          break;
      }
    }
  }
  
  void set_particle_type(ParticleType particle_type_in) override
  {
    lepton::set_particle_type(particle_type_in);
    lepton_name = (particle_type == ParticleType::ANTIPARTICLE) ? "antitau" : "tau";
    charge = (particle_type == ParticleType::ANTIPARTICLE) ? 1 : -1;
    this->set_decay(decay_mode, product_flavour);
  }
  
  
  // Print data function
  void print_data() override;

};

#endif