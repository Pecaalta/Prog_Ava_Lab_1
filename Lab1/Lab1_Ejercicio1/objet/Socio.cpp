#include "Socio.h"

string Socio::getCI(){
  return this->CI;
}
string Socio::getNombre(){
  return this->nombre;
}
void Socio::setCI(){
  this->CI = CI;
}
void Socio::setNombre(){
  this->nombre = nombre;
}
Socio::Socio(string ci, string nombre){
  this->CI = ci;
  this->nombre = nombre;
};
Socio::~Socio(){};
