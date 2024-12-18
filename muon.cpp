// Clive Marvelous, last updated 6/4/24

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

using std::string;

#include "fourMomentum.h"
#include "lepton.h"
#include "muon.h"

// Muon copy constructor and assignment
muon::muon(const muon& m) : lepton{m}, 
  isolated{m.isolated} {std::cout<<"Muon copy constructor called"<<std::endl;}
muon & muon::operator=(const muon& m)
{
  std::cout<<"Muon copy assignment called"<<std::endl;
  if(&m != this)
  {
    lepton::operator=(m); // Call lepton copy assignment
    isolated = m.isolated;
  }
  return *this;
}

// Muon move constructor and assignment
muon::muon(muon&& m) : lepton{std::move(m)}, isolated{m.isolated} 
  {
    std::cout<<"Muon move constructor called"<<std::endl;
    m.isolated = false;
  }
muon & muon::operator=(muon&& m)  
{
  std::cout<<"Muon move assignment called"<<std::endl;
  if(this != &m) 
  {
    lepton::operator=(std::move(m)); // Call lepton move assignment
    isolated = m.isolated;
    m.isolated = false;
  }
    return *this;
}

// Muon print function
void muon::print_data() 
{
  std::cout<<"Class: Muon"<<std::endl;
  lepton::print_shared_data();

  // Muon-specific information
  if(isolated) std::cout<<lepton_name<<" is isolated"<<std::endl;
  else std::cout<<lepton_name<<" is not isolated"<<std::endl;
  std::cout<<std::endl;
}
// End of muon class and associated member functions
