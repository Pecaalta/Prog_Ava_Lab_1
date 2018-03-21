#ifndef CLASE_H
#define CLASE_H

#include <string>
using namespace std;

#include "datos.h"

class Clase {
  private:
    int id;
    string nombre;
    Turno turno;
  public:
    virtual int cupo()=0;
    int getId();
    string getNombre();
    Turno getTurno();
    void setId(int id);
    void setNombre(string nombre);
    void setTurno(Turno turno);
    Clase(int id, string nombre, Turno turno);
    ~Clase();
};

#endif
