#ifndef DTSPINNING_H
#define DTSPINNING_H

#include "DtClase.h"
#include <stdexcept>
using namespace std;

class DtSpinning: public DtClase {
private:
	int cantBicicletas;
public:
	//void setcantBicicletas();
	int getcantBicicletas();
	string getType();
	DtSpinning(int id, string nombre, Turno turno, int cantBicicletas);
	~DtSpinning();
};


#endif
