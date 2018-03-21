#include "DtEntrenamiento.h"

bool DtEntrenamiento::getenRambla(){
  return this->enRambla;
};
void DtEntrenamiento::setenRambla(bool enRambla){
  this->enRambla = enRambla;
};
DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno, bool enRambla):DtClase(id, nombre, turno){
  this->enRambla = enRambla;
};
DtEntrenamiento::DtEntrenamiento(int id, string nombre, Turno turno):DtClase(id, nombre, turno){
  this->enRambla = false;
};
DtEntrenamiento::~DtEntrenamiento(){};

ostream& operator<<(ostream& os,  DtEntrenamiento& dt)  {
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
	os << "En rambla: " << (dt.getenRambla()?"Si":"No") << endl;
    os << endl;

    return os;
}
ostream& operator<<(ostream& os,  DtEntrenamiento* dt)  {
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
	os << "En rambla: " << (dt->getenRambla()?"Si":"No") << endl;
    os << endl;
    
    return os;
}
	
