#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "objet/Fecha.h"
#include "objet/DtSocio.h"
#include "objet/DtClase.h"
#include "objet/DtSpinning.h"
#include "objet/DtEntrenamiento.h"
#include "datos.h"
#include "objet/Socio.h"
#include "objet/Clase.h"
#include "objet/Spinning.h"
#include "objet/Entrenaminto.h"
#include "objet/Inscripcion.h"

#define MAX_SOCIOS 50
#define MAX_CLASES 50

void InicializaSocio();
void InicializaClases();
void ImprimeSocio();
void ImprimeClases();
void agregarSocio(string ci, string nombre);
void agregarClase(DtSpinning& clase);
void agregarClase(DtEntrenamiento& clase);
void agregarInscripcion(string ciSocio, int idClase, Fecha fecha);
void borrarInscripcion(string ciSocio, int idClase);
DtSocio** obtenerInfoSociosPorClase (int idClase, int cantSocios);
DtClase& obtenerClase(int idClase);

#endif
