#include "Clase.h"

int Clase::getId() {
	return this->id;
};

string Clase::getNombre() {
	return this->nombre;
};

Turno Clase::getTurno() {
	return this->turno;
};

void Clase::setId(int id) {
	this->id = id;
};

void Clase::setNombre(string nombre) {
	this->nombre = nombre;
};

void Clase::setTurno(Turno turno) {
	this->turno = turno;
};

ostream& operator<<(ostream& os,  Clase& dt)  {
	os << endl;
	os << "\t  Id Clase: " << dt.getId()  << endl ;
	os << "\t  Nombre: " << dt.getNombre() << endl;
	os << "\t  Turno: ";
	switch (dt.getTurno()) {
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
	if ( dt.getType() == "Spinning")
		os << "\t  Cantidad de de bicicletas: " << dt.getCantBicicletas() << endl;
	else
		os << "\t  En rambla: " <<  (dt.getEnRambla()?"Si":"no")  << endl;
	os << endl;

	return os;
};

ostream& operator<<(ostream& os,  Clase* dt)  {
	os << endl;
	os << "\t  Id Clase: " << dt->getId()  << endl ;
	os << "\t  Nombre: " << dt->getNombre() << endl;
	os << "\t  Turno: ";
	switch (dt->getTurno()) {
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
	if ( dt->getType() == "Spinning")
		os << "\t  Cantidad de de bicicletas: " << dt->getCantBicicletas() << endl;
	else
		os << "\t  En rambla: " <<  (dt->getEnRambla()?"Si":"no")  << endl;
	os << endl;
	
	return os;
};

Clase::Clase(int id, string nombre, Turno turno) {
	this->id = id;
	this->nombre = nombre;
	this->turno = turno;
};

Clase::~Clase() {};
