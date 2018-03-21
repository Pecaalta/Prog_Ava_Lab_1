#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <ctime>
using namespace std;

class Fecha {
  private:
    int dia;
    int mes;
    int anio;
  public:
    int getdia();
    int getmes();
    int getanio();
    Fecha(int dia, int mes, int anio);
    ~Fecha();
};

#endif
