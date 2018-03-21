#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Fecha.h"

class Inscripcion {
  private:
    Fecha* fecha;
  public:
    Fecha* getFecha();
    void setFecha(Fecha* fecha);
    Inscripcion(Fecha* fecha);
    ~Inscripcion();
};

#endif
