#ifndef DTENTRENAMIENTO_H
#define DTENTRENAMIENTO_H

#include "DtClase.h"

class DtEntrenamiento:public DtClase {
  private:
  	bool enRambla;
  public:
    bool getenRambla();
    //void setenRambla(bool enRambla);
    
    DtEntrenamiento(int id, string nombre, Turno turno, bool enRambla);
    DtEntrenamiento(int id, string nombre, Turno turno);
    ~DtEntrenamiento();
    
    friend ostream& operator<<(ostream& os,  DtEntrenamiento& dt);
    friend ostream& operator<<(ostream& os,  DtEntrenamiento* dt);
};


#endif
