#include <iostream>
#include <string>
using namespace std;

#include "objet/datos.h"

#include "objet/Fecha.h"
#include "objet/DtSocio.h"
#include "objet/DtClase.h"
#include "objet/DtSpinning.h"
#include "objet/DtEntrenamiento.h"


#include "objet/Socio.h"
#include "objet/Inscripcion.h"

#include "objet/Clase.h"
#include "objet/Spinning.h"
#include "objet/Entrenaminto.h"

ostream& operator << (ostream& os, DtClase cl){
	printf("sada");/*
  cout << "Id Clase: " << cl->getid() << "\n";
  cout << "Nombre:   " << cl->getnombre() << "\n";
  cout << "Turno:    " << cl->getturno() << "\n";
*/
} 

int main(int argc, char** argv) {
  Turno t = Manana;
  DtClase* en = new DtClase(0, "mauro", t);
  cout<< en;
}
