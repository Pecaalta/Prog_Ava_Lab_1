#include "Fecha.h"

int Fecha::getdia(){
  return this->dia;
};
int Fecha::getmes(){
  return this->mes;
};
int Fecha::getanio(){
  return this->anio;
};
Fecha::Fecha(int dia, int mes, int anio){
	if(dia>31 or dia<1) 		throw invalid_argument("Dia invalido");
	else if(mes>12 or mes<1) 	throw invalid_argument("Mes invalido");
	else if(anio<1900) 			throw invalid_argument("Anio invalido");
	else{
		this->dia = dia;
		this->mes = mes;
		this->anio = anio;
	}
};

Fecha::~Fecha(){};
