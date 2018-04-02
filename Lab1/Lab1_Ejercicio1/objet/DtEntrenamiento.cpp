#include "DtEntrenamiento.h"

/*
void DtEntrenamiento::setenRambla(bool enRambla){
  this->enRambla = enRambla;
};
*/
bool DtEntrenamiento::getenRambla() {
	return this->enRambla;
};

DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno, bool enRambla): DtClase(id, nombre, turno) {
	this->enRambla = enRambla;
};

DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno): DtClase(id, nombre, turno) {
	this->enRambla = false;
};

DtEntrenamiento::~DtEntrenamiento() {};

ostream& operator<<(ostream& os,  DtEntrenamiento& dt)  {
	os << endl;
	os << "\t  Id Clase: " << dt.getid()  << endl ;
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
	os << "\t  En rambla: " << (dt.getenRambla() ? "Si" : "No") << endl;
	os << endl;

	return os;
};

ostream& operator<<(ostream& os,  DtEntrenamiento* dt)  {
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
	os << "\t  En rambla: " << (dt->getenRambla() ? "Si" : "No") << endl;
	os << endl;

	return os;
};

