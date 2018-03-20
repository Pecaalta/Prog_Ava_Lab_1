#include "DtSpinning.h"

void DtSpinning::setcantBicicletas(){
  this->cantBicicletas = cantBicicletas;//controlar limites
}
DtSpinning::DtSpinning(int id, string nombre, Turno turno,int cantBicicletas):DtClase(id, nombre, turno){
  this->cantBicicletas = cantBicicletas;//controlar limites
}
int DtSpinning::getcantBicicletas(){
  return cantBicicletas;
}
