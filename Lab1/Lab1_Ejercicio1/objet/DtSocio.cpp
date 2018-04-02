#include "DtSocio.h"

/*
void DtSocio::setCI(int CI){
  this->CI = CI;
};

void DtSocio::setnombre(string nombre){
  this->nombre = nombre;
};
*/
int DtSocio::getCI() {
	return this->CI;
};

string DtSocio::getnombre() {
	return this->nombre;
};

DtSocio::DtSocio(int CI, string nombre) {
	this->CI = CI;
	this->nombre = nombre;
};

DtSocio::~DtSocio() {};
