#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Fecha.h"
#include "DtSocio.h"

class Inscripcion {
  private:
    Fecha* fecha;
    DtSocio* cliente;
  public:
    DtSocio* getcliente();
	int getCI();
    Fecha* getFecha();
    void setFecha(Fecha* fecha);
    void setcliente(DtSocio* cliente);
    Inscripcion(Fecha* fecha,DtSocio* cliente);
    ~Inscripcion();
};

#endif
