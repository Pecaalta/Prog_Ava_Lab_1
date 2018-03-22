#include "DtSpinning.h"

/*
void DtSpinning::setcantBicicletas(){
  this->cantBicicletas = cantBicicletas;//controlar limites
}
*/
int DtSpinning::getcantBicicletas(){
  return cantBicicletas;
}

DtSpinning::DtSpinning(int id, string nombre, Turno turno,int cantBicicletas):DtClase(id, nombre, turno){
	if(cantBicicletas < 50)
		this->cantBicicletas = cantBicicletas;
	else
		throw invalid_argument("Limite de biciciletas superado");

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
