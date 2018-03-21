#ifndef SPINNING_H
#define SPINNING_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "Inscripcion.h"
#include "Clase.h"

class Spinning:public Clase {
  private:
    int cantBicicletas;
    Inscripcion** Inscriptos;
  public:
    int getCantBicicletas();
    void setCantBicicletas(int cantBicicletas);
    
	DtSocio** getCantSocios(int cantSocios);
    int cupo();
    bool searchInscripcion(int ciSocio);
    void addInscripcion(Inscripcion* Nueva_Inscripto);
  	bool deleteInscripcion(int ciSocio);
    
    Spinning(int id, string nombre, Turno turno, int cantBicicletas);
    ~Spinning();
};

#endif
