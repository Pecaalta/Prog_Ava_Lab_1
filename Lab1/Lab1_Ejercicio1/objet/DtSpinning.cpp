#include "DtSpinning.h"

void DtSpinning::setcantBicicletas(){
  this->cantBicicletas = cantBicicletas;//controlar limites
}
DtSpinning::DtSpinning(int id, string nombre, Turno turno,int cantBicicletas):DtClase(id, nombre, turno){
  this->cantBicicletas = cantBicicletas;//controlar limites
}
int DtSpinning::getcantBicicletas(){
  return cantBicicletas;
}

DtSpinning::~DtSpinning(){}


ostream& operator<<(ostream& os,  DtSpinning& dt)  {
    os << endl;
	os << "Id Clase: " << dt.getid()  << endl ;
	os << "Nombre: " << dt.getnombre() << endl;
	os << "Turno: ";
	switch(dt.getturno()){
		case Manana:
			os << "Maniana";
		break;
		case Tarde:
			os << "Tarde";
		break;
		case Noche:
			os << "Noche";
		break;
	}
    os << endl;
	os << "Cantidad de de bicicletas: " << dt.getcantBicicletas() << endl;
    os << endl;

    return os;
}

ostream& operator<<(ostream& os,  DtSpinning* dt)  {
    os << endl;
	os << "Id Clase: " << dt->getid()  << endl ;
	os << "Nombre: " << dt->getnombre() << endl;
	os << "Turno: ";
	switch(dt->getturno()){
		case Manana:
			os << "Maniana";
		break;
		case Tarde:
			os << "Tarde";
		break;
		case Noche:
			os << "Noche";
		break;
	}
    os << endl;
	os << "Cantidad de de bicicletas: " << dt->getcantBicicletas() << endl;
    os << endl;
    
    return os;
}

