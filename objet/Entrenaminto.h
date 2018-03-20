#ifndef ENTRENAMINTO_H
#define ENTRENAMINTO_H

#include "Clase.h"

class Entrenaminto:public Clase {
  private:
    bool enRambla;
  public:
    void setEnRambla(bool enRambla);
    bool getEnRambla();
    int cupo();

    Entrenaminto(int id, string nombre, Turno turno);
    Entrenaminto(int id, string nombre, Turno turno, bool enRambla);
    ~Entrenaminto();

};

#endif
