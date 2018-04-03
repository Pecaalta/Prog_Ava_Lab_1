#include "DtSpinning.h"

/*
void DtSpinning::setcantBicicletas(){
  this->cantBicicletas = cantBicicletas;//controlar limites
}
*/
int DtSpinning::getcantBicicletas() {
	return cantBicicletas;
};
string DtSpinning::getType(){
	return "DtSpinning";
}

DtSpinning::DtSpinning(int id, string nombre, Turno turno, int cantBicicletas): DtClase(id, nombre, turno) {
	if (cantBicicletas < 50) {
		this->cantBicicletas = cantBicicletas;
	} else {
		throw invalid_argument("Limite de biciciletas superado");
	}
};

DtSpinning::~DtSpinning() {}


