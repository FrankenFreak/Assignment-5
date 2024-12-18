// Clive Marvelous, last updated 6/4/24

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

using std::string;

#include "fourMomentum.h"
#include "lepton.h"
#include "neutrino.h"

// Neutrino copy constructor and assignment
neutrino::neutrino(const neutrino& n) : lepton{n}, 
  hasInteracted{n.hasInteracted}, flavour{n.flavour} {std::cout<<"Neutrino copy constructor called"<<std::endl;}
neutrino & neutrino::operator=(const neutrino& n)
{
  std::cout<<"Neutrino copy assignment called"<<std::endl;
  if(&n != this)
  {
    lepton::operator=(n); // Call lepton copy assignment
    hasInteracted = n.hasInteracted;
    flavour = n.flavour;
  }
  return *this;
}

// Neutrino move constructor and assignment
neutrino::neutrino(neutrino&& n) : lepton{std::move(n)}, hasInteracted{n.hasInteracted}, flavour{std::move(n.flavour)}
  {
    std::cout<<"Neutrino move constructor called"<<std::endl;
    n.hasInteracted = false;
  }
neutrino & neutrino::operator=(neutrino&& n)  
{
  std::cout<<"Neutrino move assignment called"<<std::endl;
  if(this != &n) 
  {
    lepton::operator=(std::move(n)); // Call lepton move assignment
    hasInteracted = n.hasInteracted;
    n.hasInteracted = false;
    flavour = std::move(n.flavour);
  }
    return *this;
}

// Neutrino print function
void neutrino::print_data() 
{
  std::cout<<"Class: Neutrino"<<std::endl;
  lepton::print_shared_data();

  // Tau-specific information
  if(hasInteracted) std::cout<<lepton_name<<" has interacted with detector"<<std::endl;
  else std::cout<<lepton_name<<" has not interacted with detector"<<std::endl;
  std::cout<<std::endl;
}
// End of neutrino class and associated member functions
