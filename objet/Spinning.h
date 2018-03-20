#ifndef SPINNING_H
#define SPINNING_H

#include "Clase.h"

class Spinning:public Clase {
  private:
    int cantBicicletas;
  public:
    int getCantBicicletas();
    void setCantBicicletas(int cantBicicletas);
    int cupo();
    Spinning(int id, string nombre, Turno turno);
    Spinning(int id, string nombre, Turno turno, int cantBicicletas);
    ~Spinning();
};

#endif
