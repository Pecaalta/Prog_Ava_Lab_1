#ifndef DTSPINNING_H
#define DTSPINNING_H

#include "DtClase.h"

class DtSpinning:public DtClase {
  private:
    int cantBicicletas;
  public:
    int getcantBicicletas();
    void setcantBicicletas();
    DtSpinning(int id, string nombre, Turno turno,int cantBicicletas);
    ~DtSpinning();
};


#endif
