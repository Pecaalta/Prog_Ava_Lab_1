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
	agregarSocio("1","mauro");
	agregarSocio("2","leandro");
	agregarSocio("3","maia");
	
	Turno t = Manana;
	DtEntrenamiento p(0,"programacion",t,true);
	
	agregarClase(p);
	Fecha f(20,10,2000);
	agregarInscripcion("1",0,f);
	agregarInscripcion("2",0,f);
	agregarInscripcion("3",0,f);
	DtSocio** dts = obtenerInfoSociosPorClase(0,5);
	borrarInscripcion("3",0);
	for(int i = 0 ; i<5;i++){
		cout << "**********************" << endl;
		cout << "ci - " << dts[i]->getCI() << endl;
		cout << "nombre - " << dts[i]->getnombre() << endl;
		cout << "**********************" << endl;
	}
	
	//ImprimeClases();
	
}
