#include <iostream>
#include <string>

using namespace std;

#include "objet/datos.h"

#include "objet/Fecha.h"
#include "objet/DtSocio.h"
#include "objet/DtClase.h"
#include "objet/DtSpinning.h"
#include "objet/DtEntrenamiento.h"

#include "objet/Clase.h"
#include "objet/Socio.h"
#include "objet/Inscripcion.h"
#include "objet/Spinning.h"
#include "objet/Entrenaminto.h"

#include "Funciones.h"



int main(int argc, char** argv) {

	InicializaSocio();
	InicializaClases();
	agregarSocio("52","mauro");
	agregarSocio("53","leandro");
	
	Turno t = Manana;
	DtSpinning p(5,"mauro",t,20);
	agregarClase(p);
	ImprimeClases();
}
