#ifndef DTSPINNING_H
#define DTSPINNING_H

#include "DtClase.h"
#include <stdexcept>
using namespace std;

class DtSpinning:public DtClase {
  private:
    int cantBicicletas;
  public:
    //void setcantBicicletas();
    int getcantBicicletas();
    DtSpinning(int id, string nombre, Turno turno,int cantBicicletas);
    friend ostream& operator<<(ostream& os,  DtSpinning& dt);
    friend ostream& operator<<(ostream& os,  DtSpinning* dt);
    ~DtSpinning();
};


#endif
