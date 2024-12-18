// Clive Marvelous, last updated 6/4/24

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

using std::string;

#include "fourMomentum.h"
#include "lepton.h"
#include "tau.h"

// Tau print function
void tau::print_data() 
{
  std::cout<<"Class: Tau"<<std::endl;
  lepton::print_shared_data();

  // Tau-specific information
  std::cout<<"Decay mode: ";
  switch(decay_mode)
  {
    case DecayMode::HADRONIC:
      std::cout<<"Hadronic"<<std::endl;
      break;
    case DecayMode::LEPTONIC:
      std::cout<<"Leptonic"<<std::endl;
      break;
  }
  if(decay_mode == DecayMode::LEPTONIC)
  {
    std::cout<<"Decay products: "<<decay_products[0]->get_name();
    std::cout<<", "<<decay_products[1]->get_name();
    std::cout<<", "<<decay_products[2]->get_name()<<std::endl;
  }
  std::cout<<std::endl;
}
// End of tau class and associated member functions
