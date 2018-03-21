#include "Inscripcion.h"

Fecha* Inscripcion::getFecha(){
  return this->fecha;
}
void Inscripcion::setFecha(Fecha* fecha){
  this->fecha = fecha;
}
Inscripcion::Inscripcion(Fecha* fecha){
    this->fecha = fecha;
};
Inscripcion::~Inscripcion(){};
