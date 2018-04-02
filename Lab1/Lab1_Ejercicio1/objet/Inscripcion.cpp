#include "Inscripcion.h"

DtSocio* Inscripcion::getcliente() {
	return this->cliente;
};

int Inscripcion::getCI() {
	return this->cliente->getCI();
};

Fecha* Inscripcion::getFecha() {
	return this->fecha;
};

void Inscripcion::setFecha(Fecha* fecha) {
	this->fecha = fecha;
};

void Inscripcion::setcliente(DtSocio* cliente) {
	this->cliente = cliente;
};

Inscripcion::Inscripcion(Fecha* fecha, DtSocio* cliente) {
	this->fecha = fecha;
	this->cliente = cliente;
};

Inscripcion::~Inscripcion() {
	this->cliente->~DtSocio();
	this->fecha->~Fecha();

};
