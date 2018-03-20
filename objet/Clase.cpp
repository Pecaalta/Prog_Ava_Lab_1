#include "Clase.h"

int Clase::getId(){
  return this->id;
}
string Clase::getNombre(){
  return this->nombre;
}
Turno Clase::getTurno(){
  return this->turno;
}
void Clase::setId(int id){
  this->id = id;
}
void Clase::setNombre(string nombre){
  this->nombre = nombre;
}
void Clase::setTurno(Turno turno){
  this->turno = turno;
}

Clase::Clase(int id, string nombre, Turno turno){
  this->id = id;
  this->nombre = nombre;
  this->turno = turno;
};
Clase::~Clase(){};
