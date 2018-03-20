#ifndef DTCLASE_H
#define DTCLASE_H

#include "datos.h"

#include <string>
using namespace std;

class DtClase {
  int id;
  string nombre;
  Turno turno;
  public:
    void setid(int id);
    void setnombre(string nombre);
    void setturno(Turno turno);
    int getid();
    string getnombre();
    Turno getturno();
    friend ostream& operator<<(ostream& os, const DtClase& dt); 
    DtClase(int id, string nombre, Turno turno);
    ~DtClase();
};


#endif
