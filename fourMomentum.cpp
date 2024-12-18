// Clive Marvelous, last updated 6/4/24

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "fourMomentum.h"

// Friend functions
fourMomentum operator+(const fourMomentum& vector1, const fourMomentum& vector2)
{
  double energy_result{vector1.energy + vector2.energy};
  double px_result{vector1.x_momentum + vector2.x_momentum};
  double py_result{vector1.y_momentum + vector2.y_momentum};
  double pz_result{vector1.z_momentum + vector2.z_momentum};
  fourMomentum result{energy_result, px_result, py_result, pz_result};
  return result;
}

// Print function
void fourMomentum::print_data()
{
  std::cout.precision(4); // Set precision for floating point numbers
  std::cout<<"Energy: "<<energy<<" MeV"<<std::endl;
  std::cout<<"Momentum (px): "<<x_momentum<<" MeV/c"<<std::endl;
  std::cout<<"Momentum (py): "<<y_momentum<<" MeV/c"<<std::endl;
  std::cout<<"Momentum (pz): "<<z_momentum<<" MeV/c"<<std::endl;
  return;
}

