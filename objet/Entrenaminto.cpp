#include "Entrenaminto.h"


void Entrenaminto::setEnRambla(bool enRambla){
  this->enRambla = enRambla;
}
bool Entrenaminto::getEnRambla(){
  return this->enRambla;
}
int Entrenaminto::cupo(){
	return enRambla? 20 : 10 ;
};

Entrenaminto::Entrenaminto(int id, string nombre, Turno turno):Clase(id, nombre, turno){
  this->enRambla = false;
};
Entrenaminto::Entrenaminto(int id, string nombre, Turno turno, bool enRambla):Clase(id, nombre, turno){
  this->enRambla = enRambla;
};
Entrenaminto::~Entrenaminto(){};
