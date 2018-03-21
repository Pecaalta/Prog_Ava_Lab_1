#include "Spinning.h"

int Spinning::getCantBicicletas(){
  return this->cantBicicletas;
}
void Spinning::setCantBicicletas(int cantBicicletas){
  this->cantBicicletas = cantBicicletas;
}


int Spinning::cupo(){
	return this->cantBicicletas;
};
bool Spinning::searchInscripcion(int ciSocio){
	for (int i = 0; i < this->cantBicicletas; i++){
		if (this->Inscriptos[i] != NULL){
			if (this->Inscriptos[i]->getCI() == ciSocio) 
				return true;
		}
	}
  	return false;
}
void Spinning::addInscripcion(Inscripcion* Nueva_Inscripto){
  	for (int i = 0; i < this->cantBicicletas; i++)
	    if (this->Inscriptos[i] == NULL){
	      	this->Inscriptos[i] = Nueva_Inscripto;
	      	break;
		}
}
DtSocio** Spinning::getCantSocios(int cantSocios){
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

bool Spinning::deleteInscripcion(int ciSocio){
  	for (int i = 0; i < 10; i++)
   		if (this->Inscriptos[i] != NULL)
      		if (this->Inscriptos[i]->getCI() == ciSocio) {
      			this->Inscriptos[i]->~Inscripcion();
      			this->Inscriptos[i] = NULL;
      			return true;
	  		};
	return false;
}



Spinning::Spinning(int id, string nombre, Turno turno, int cantBicicletas):Clase(id, nombre, turno){
  if (cantBicicletas < 50){
    this->cantBicicletas = cantBicicletas;
    
	Inscripcion** arr = new Inscripcion*[cantBicicletas];
    this->Inscriptos = arr;
    for (int i = 0; i < cantBicicletas; i++)
    	this->Inscriptos[i] = NULL;
  }
  else
    throw invalid_argument("Exede limite de bisicletas");
};
Spinning::~Spinning(){};
