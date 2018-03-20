#include "DtEntrenamiento.h"

bool DtEntrenamiento::getenRambla(){
  return this->enRambla;
};
void DtEntrenamiento::setenRambla(bool enRambla){
  this->enRambla = enRambla;
};
DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno, bool enRambla):DtClase(id, nombre, turno){
  this->enRambla = enRambla;
};
DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno):DtClase(id, nombre, turno){
  this->enRambla = false;
};
DtEntrenamiento::~DtEntrenamiento(){};
