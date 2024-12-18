// Clive Marvelous, last updated 6/4/24

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "fourMomentum.h"
#include "lepton.h"

using std::string;

// Lepton copy constructor and assignment
lepton::lepton(const lepton& l) : lepton_name{l.lepton_name}, 
  charge{l.charge}, four_momentum{std::make_shared<fourMomentum>(*l.four_momentum)}, particle_type{l.particle_type} {}
lepton & lepton::operator=(const lepton& l)
{
  // Check for self-assignment
  if(&l != this) 
  { 
    lepton_name = l.lepton_name;
    charge = l.charge; 
    four_momentum = std::make_shared<fourMomentum>(*l.four_momentum);
    particle_type = l.particle_type;
  }
  return *this;
}

// Lepton move constructor and assignment
lepton::lepton(lepton&& l) : lepton_name{std::move(l.lepton_name)}, 
  charge{l.charge}, four_momentum{std::move(l.four_momentum)}, particle_type{l.particle_type} {l.charge = 0;}
lepton & lepton::operator=(lepton&& l)
{
  if(&l != this) // Prevent self-move
  {
    lepton_name = std::move(l.lepton_name);
    charge = l.charge;
    l.charge = 0;
    four_momentum = std::move(l.four_momentum);
    particle_type = l.particle_type;
  }
  return *this;
}

// Lepton print function
void lepton::print_data()
{
  std::cout<<"Class: Lepton"<<std::endl;
  print_shared_data();
  return;
}
void lepton::print_shared_data()
{
  std::cout<<"Name: "<<lepton_name<<std::endl;
  std::cout<<"Charge: "<<charge<<std::endl;

  // Check for nullptr
  if(four_momentum == nullptr) 
  {
    std::cout<<"Four momentum data not found"<<std::endl;
    return;
  }

  std::cout.precision(3);
  std::cout<<"Energy: "<<four_momentum->get_E()<<" MeV"<<std::endl;
  std::cout<<"Momentum (px): "<<four_momentum->get_px()<<" MeV/c"<<std::endl;
  std::cout<<"Momentum (py): "<<four_momentum->get_py()<<" MeV/c"<<std::endl;
  std::cout<<"Momentum (pz): "<<four_momentum->get_pz()<<" MeV/c"<<std::endl;
  return;
}

// Friend sum function
fourMomentum sum(const lepton& l1, const lepton& l2) {return (*l1.four_momentum) + (*l2.four_momentum);}

// Friend dot product function
// Dot product function
double dotProduct(const lepton& l1, const lepton& l2)
{
  // Calculation
  double result_E{l1.four_momentum->get_E()*l2.four_momentum->get_E()};
  double result_px{l1.four_momentum->get_px()*l2.four_momentum->get_px()};
  double result_py{l1.four_momentum->get_py()*l2.four_momentum->get_py()};
  double result_pz{l1.four_momentum->get_pz()*l2.four_momentum->get_pz()};
  return result_E - (result_px + result_py + result_pz);
}


// End of lepton class and associated member functions
