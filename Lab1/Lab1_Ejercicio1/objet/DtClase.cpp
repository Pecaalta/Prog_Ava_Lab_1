
#include "DtClase.h"

/*
void DtClase::setid(int id){
	this->id = id;
};

void DtClase::setnombre(string nombre){
	this->nombre = nombre;
};

void DtClase::setturno(Turno turno){
	this->turno = turno;
};

*/
int DtClase::getid() {
	return this->id;
};

string DtClase::getnombre() {
	return this->nombre;
};

Turno DtClase::getturno() {
	return this->turno;
};

ostream& operator<<(ostream& os,  DtClase& dt)  {
	os << endl;
	os << "\t  Id Clasesssssss: " << dt.getid()  << endl ;
	os << "\t  Tipo: " << dt.getType()  << endl ;
	os << "\t  Nombre: " << dt.getnombre() << endl;
	os << "\t  Turno: ";
	switch (dt.getturno()) {
	case Manana:
		os << "Ma" << (char)164 << "ana";
		break;
	case Tarde:
		os << "Tarde";
		break;
	case Noche:
		os << "Noche";
		break;
	}
	os << endl;
	if ( dt.getType() == "DtSpinning")
		os << "\t  Cantidad de de bicicletas: " << dt.getcantBicicletas() << endl;
	else
		os << "\t  En rambla: " << (dt.getenRambla()?"Si":"no") << endl;
	os << endl;
	return os;
};

ostream& operator<<(ostream& os,  DtClase* dt)  {
	os << endl;
	os << "\t  Id Clase: " << dt->getid()  << endl ;
	os << "\t  Nombre: " << dt->getnombre() << endl;
	os << "\t  Turno: ";
	switch (dt->getturno()) {
	case Manana:
		os << "Ma" << (char)164 << "ana";
		break;
	case Tarde:
		os << "Tarde";
		break;
	case Noche:
		os << "Noche";
		break;
	}
	os << endl;
	if ( dt->getType() == "DtSpinning")
		os << "\t  Cantidad de de bicicletas: " << dt->getcantBicicletas() << endl;
	else
		os << "\t  En rambla: " <<  (dt->getenRambla()?"Si":"no")  << endl;
	os << endl;
	return os;
};

DtClase::DtClase(int id, string nombre, Turno turno) {
	this->id = id;
	this->nombre = nombre;
	this->turno = turno;
};

DtClase::~DtClase() {};

