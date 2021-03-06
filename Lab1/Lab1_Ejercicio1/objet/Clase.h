#ifndef CLASE_H
#define CLASE_H

#include <string>
using namespace std;

#include "../datos.h"
#include "Inscripcion.h"

class Clase {
private:
    int id;
    string nombre;
    Turno turno;
public:
    int getId();
    string getNombre();
    Turno getTurno();
    void setId(int id);
    void setNombre(string nombre);
    void setTurno(Turno turno);
	
	virtual int getCantBicicletas() { return 0; };
	virtual bool getEnRambla(){ return 0; };
	virtual string getType()=0;
    virtual int cupo() = 0;
    virtual bool searchInscripcion(int ciSocio) = 0;
    virtual void addInscripcion(Inscripcion* Nueva_Inscripto) = 0;
    virtual DtSocio** getCantSocios(int cantSocios) = 0;
    virtual bool deleteInscripcion(int ciSocio) = 0;

	friend ostream& operator<<(ostream& os,  Clase& dt);
	friend ostream& operator<<(ostream& os,  Clase* dt);
    Clase(int id, string nombre, Turno turno);
    ~Clase();
};

#endif
