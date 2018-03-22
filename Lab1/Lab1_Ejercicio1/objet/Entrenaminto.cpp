#include "Entrenaminto.h"


void Entrenaminto::setEnRambla(bool enRambla){
  this->enRambla = enRambla;
  /*
  20->20=> s->s
  20->10=> s->n-
  10->20=> n->s-
  10->10=> n->s
  */
  	if (this->enRambla and !enRambla){
  		this->enRambla = enRambla;
  		if (enRambla){
		  	Inscripcion** arr = new Inscripcion*[20];
		    for (int i = 0; i < 10; i++){
		    	if (this->Inscriptos[i] == NULL) 
					arr[i] = NULL;
		    	else{
			    	arr[i] = this->Inscriptos[i];
			    	delete this->Inscriptos[i];
				}
			}
			delete this->Inscriptos;
		    for (int i = 10; i < 20; i++)
		    	arr[i] = NULL;
		    this->Inscriptos = arr;
		}else{
	  		throw invalid_argument("El grupo es demasiado grande");
		}
  	}
}
bool Entrenaminto::getEnRambla(){
  return this->enRambla;
}


int Entrenaminto::cupo(){
	return this->enRambla? 20 : 10 ;
};
bool Entrenaminto::searchInscripcion(int ciSocio){
  for (int i = 0; i < (this->enRambla? 20 : 10); i++)
    if (this->Inscriptos[i] != NULL)
      if (this->Inscriptos[i]->getCI() == ciSocio) return true;
  return false;

}
void Entrenaminto::addInscripcion(Inscripcion* Nueva_Inscripto){
  bool cant = false;
  for (int i = 0; i < (this->enRambla? 20 : 10); i++)
    if (this->Inscriptos[i] == NULL){
    	cant = true;
      	this->Inscriptos[i] = Nueva_Inscripto;
      	break;
	}
	if (!cant)
		throw invalid_argument("Cupos llenos");
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
	for (int i = cant; i < cantSocios ; i++) 
		ret[i] = new DtSocio(0," ");
	return ret;
}
bool Entrenaminto::deleteInscripcion(int ciSocio){
  	for (int i = 0; i < (this->enRambla? 20 : 10); i++)
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
  	int largo = this->enRambla? 20 : 10;
	Inscripcion** arr = new Inscripcion*[largo];
    this->Inscriptos = arr;
    for (int i = 0; i < largo; i++)
    	this->Inscriptos[i] = NULL;
};
Entrenaminto::~Entrenaminto(){};




