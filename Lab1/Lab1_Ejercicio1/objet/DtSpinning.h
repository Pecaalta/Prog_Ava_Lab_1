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
    friend ostream& operator<<(ostream& os,  DtSpinning& dt);
    friend ostream& operator<<(ostream& os,  DtSpinning* dt);
    ~DtSpinning();
};


#endif
