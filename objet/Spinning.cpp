#include "Spinning.h"

#include <iostream>
#include <string>
#include <stdexcept>

int Spinning::getCantBicicletas(){
  return this->cantBicicletas;
}
void Spinning::setCantBicicletas(int cantBicicletas){
  this->cantBicicletas = cantBicicletas;
}
Spinning::Spinning(int id, string nombre, Turno turno):Clase(id, nombre, turno){
    this->cantBicicletas = 0;
};
int Spinning::cupo(){
	return this->cantBicicletas;
};

Spinning::Spinning(int id, string nombre, Turno turno, int cantBicicletas):Clase(id, nombre, turno){
  if (cantBicicletas < 50)
    this->cantBicicletas = cantBicicletas;
  else
    throw invalid_argument("Exede limite de bisicletas");
};
Spinning::~Spinning(){};
