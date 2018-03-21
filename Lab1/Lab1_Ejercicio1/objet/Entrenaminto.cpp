#include "Entrenaminto.h"


void Entrenaminto::setEnRambla(bool enRambla){
  this->enRambla = enRambla;
}
bool Entrenaminto::getEnRambla(){
  return this->enRambla;
}



int Entrenaminto::cupo(){
	return enRambla? 20 : 10 ;
};
bool Entrenaminto::searchInscripcion(int ciSocio){
  for (int i = 0; i < 10; i++)
    if (this->Inscriptos[i] != NULL)
      if (this->Inscriptos[i]->getCI() == ciSocio) return true;
  return false;

}
void Entrenaminto::addInscripcion(Inscripcion* Nueva_Inscripto){
  for (int i = 0; i < 10; i++)
    if (this->Inscriptos[i] == NULL){
      	this->Inscriptos[i] = Nueva_Inscripto;
      	break;
	}
}
DtSocio** Entrenaminto::getCantSocios(int cantSocios){
	DtSocio* *ret = new DtSocio*[cantSocios];
	int cant = 0;
	for (int i = 0; i < cantSocios; i++){
		if (this->Inscriptos[i] != NULL){
			ret[i] = this->Inscriptos[i]->getcliente();
			cant++;
		}
	}
	for (int i = cant; i < cantSocios ; i++) ret[i] = new DtSocio(0," Bacante");
	return ret;
}

bool Entrenaminto::deleteInscripcion(int ciSocio){
  	for (int i = 0; i < 10; i++)
   		if (this->Inscriptos[i] != NULL)
      		if (this->Inscriptos[i]->getCI() == ciSocio) {
      			this->Inscriptos[i]->~Inscripcion();
      			this->Inscriptos[i] = NULL;
      			return true;
	  		};
	return false;
}







    
Entrenaminto::Entrenaminto(int id, string nombre, Turno turno):Clase(id, nombre, turno){
  	this->enRambla = false;
	Inscripcion** arr = new Inscripcion*[10];
    this->Inscriptos = arr;
    for (int i = 0; i < 10; i++)
    	this->Inscriptos[i] = NULL;
};
Entrenaminto::Entrenaminto(int id, string nombre, Turno turno, bool enRambla):Clase(id, nombre, turno){
  	this->enRambla = enRambla;
	Inscripcion** arr = new Inscripcion*[10];
    this->Inscriptos = arr;
    for (int i = 0; i < 10; i++)
    	this->Inscriptos[i] = NULL;
};
Entrenaminto::~Entrenaminto(){};




