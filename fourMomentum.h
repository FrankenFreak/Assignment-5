// Clive Marvelous, last updated 6/4/24

#ifndef FOUR_MOMENTUM_H
#define FOUR_MOMENTUM_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

using std::string;

// Beginning of 4-momentum class (Taking c=1)
class fourMomentum
{
private: 
  double energy, x_momentum, y_momentum, z_momentum;
  
public: 
  // Constructor and destructor 
  fourMomentum() : energy{}, x_momentum{}, y_momentum{}, z_momentum{} {}
  fourMomentum(double E, double px, double py, double pz) : 
    energy{E}, x_momentum{px}, y_momentum{py}, z_momentum{pz} {}
  ~fourMomentum() {std::cout<<"Destroying 4-momentum"<<std::endl;} 

  // Getter functions to individual elements of 4-momentum
  const double get_E() const {return energy;}
  const double get_px() const {return x_momentum;}
  const double get_py() const {return y_momentum;}
  const double get_pz() const {return z_momentum;}

  // Setter functions to change values of 4-momentum
  void set_E(double E) {energy=E;}
  void set_px(double px) {x_momentum=px;}
  void set_py(double py) {y_momentum=py;}
  void set_pz(double pz) {z_momentum=pz;}

  // Friend function
  friend fourMomentum operator+(const fourMomentum& vector1, const fourMomentum& vector2);

  // Print function
  void print_data();
};



#endif