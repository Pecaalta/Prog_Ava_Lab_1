#ifndef ENTRENAMINTO_H
#define ENTRENAMINTO_H

#include "Clase.h"
#include "Inscripcion.h"

class Entrenaminto: public Clase {
private:
	bool enRambla;
	Inscripcion** Inscriptos;
public:
	void setEnRambla(bool enRambla);
	bool getEnRambla();
	string getType();
	int cupo();
	bool searchInscripcion(int ciSocio);
	void addInscripcion(Inscripcion* Nueva_Inscripto);
	DtSocio** getCantSocios(int cantSocios);
	bool deleteInscripcion(int ciSocio);


	Entrenaminto(int id, string nombre, Turno turno);
	Entrenaminto(int id, string nombre, Turno turno, bool enRambla);
	~Entrenaminto();

};

#endif
