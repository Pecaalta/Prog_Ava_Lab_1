#include <iostream>
#include <string>
#include <stdexcept>

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
void heder(string texto){
	int spacio = (62-texto.size())/2;
	cout << endl;
	cout << "   " << (char)201;
	for (int i = 0 ;i<62;i++){
		cout << (char)205;
	}
	cout << (char)187 << endl;
	
	cout <<  "   " << (char)186;
	for (int i = 0 ;i<spacio;i++){
		cout << " ";
	}
	cout << texto;
	if(spacio*2 != (62-texto.size()))
		cout << " ";
	for (int i = 0 ;i<spacio;i++){
		cout << " ";
	}
	cout << (char)186 << endl;
	
	cout <<  "   " << (char)200;
	for (int i = 0 ;i<62;i++){
		cout << (char)205;
	}
	cout << (char)188 << endl;
	cout << endl;
}

int tipoClase(){
	int opcion;
	system("cls");
	heder("Tipo de Clase");
	cout << "  Tipo de clase: " << endl;
	cout << "\t 1 Entrenaminto" << endl;
	cout << "\t 2 Spining" << endl;
	cout << endl ;
	cout << "\t >" ;
	fflush(stdin);
	cin >> opcion;
	fflush(stdin);
	return opcion;
}
DtEntrenamiento* nuevoEntrenamiento(){
	string nombre,opcion; 
	int id;
	Turno t;
	bool enrambla, continuar = false;
	system("cls");
	heder("Nueva Clase");
	cout << "  id> "; 
	cin >> id;
	fflush(stdin);
	
	cout << "  Nombre > ";
	fflush(stdin); 
	getline(cin, nombre);
	fflush(stdin);  
				
	while(!continuar){
		cout << "  Turno: ";
		cout << endl;
		cout << "\t  1 mañana " << endl;
		cout << "\t  2 tarde " << endl;
		cout << "\t  3 noche " << endl;
		cout << "  > ";
		getline(cin, opcion);
		fflush(stdin);  
		if (opcion == "1")	{
			t = Manana;
			continuar = true;
		}
		else if (opcion == "2")	{
			t = Tarde;
			continuar = true;
		}
		else if (opcion == "3")	{
			t = Noche;
			continuar = true;
		}else
			cout << "  Opcion incorrecta";
	}
	continuar = false;
	while(!continuar){
		cout << "  En Ruta (si/no)> ";
		fflush(stdin);  
		getline(cin, opcion);
		fflush(stdin);  
		if (opcion == "si" or opcion == "Si" or opcion == "SI" or opcion == "s" or opcion == "S"){
			continuar = true;
			enrambla = true;
		}
		else if (opcion == "no" or opcion == "No" or opcion == "NO" or opcion == "n" or opcion == "N"){
			continuar = true;
			enrambla = false;
		}
		else
			cout << "  Opcion incorrecta";
			cout << endl;
	}
	
	DtEntrenamiento* p = new DtEntrenamiento(id,nombre,t,enrambla);
	return p;
}
DtSpinning* nuevaSpinning(){
	string nombre,opcion; 
	int id,cantbicis;
	Turno t;
	bool enrambla, continuar = false;
	
	cout << "  id> "; 
	cin >> id;
	fflush(stdin);
	
	cout << "  Nombre > ";
	fflush(stdin); 
	getline(cin, nombre);
	fflush(stdin); 
	
	cout << "  Canteidad de Bisicletas > ";
	fflush(stdin);  
	cin >> cantbicis;
	fflush(stdin); 

	DtSpinning *p = new DtSpinning(id,nombre,t,cantbicis);
	return p;
	
};
void nuevoSocio(){
	system("cls");
	heder("Nueva Socio");
	string nombre,ci;
	bool continuar = false;
	
	cout << "  C.I. > ";
	cin >> ci;
	fflush(stdin);  
	
	cout << "  Nombre > ";
	cin >> nombre;
	fflush(stdin);  
	
	agregarSocio(ci,nombre);
		
};
void Inscripcion(){
	int d,m,a, idclase;
	string ci,opcion;
	bool continuar = false;
	
	while(!continuar){
		system("cls");
		heder("Inscripciones");
		cout << "\t  1 Inscribirse " << endl;
		cout << "\t  2 Borrar Inscripciones " << endl;
		cout << endl;
		cout << "  > ";
		getline(cin, opcion);
		fflush(stdin);  
		if (opcion == "1")	{
			cout << endl;
			cout << "\t  Fecha (dd/mm/aaaa) > " << endl;
			cin >> d;
			cout << "/";
			cin >> m;
			cout << "/";
			cin >> a;
			cout << endl;
			Fecha f(d,m,a);
			cout << "\t  C.I > ";
			getline(cin, ci);
			fflush(stdin);  
			cout << "\t  ID del curso > ";
			cin >> idclase;
			agregarInscripcion(ci,idclase,f);
			continuar = true;
		}
		else if (opcion == "2")	{
			cout << "\t  C.I > ";
			getline(cin, ci);
			fflush(stdin);  
			cout << "\t  ID del curso > ";
			cin >> idclase;
			borrarInscripcion(ci,idclase);
			continuar = true;
		}else
			cout << "  Opcion incorrecta";
	}
	
};
void Listada_de_Clase(){
	system("cls");
	heder("Nuestras Clases");
	ImprimeClases();
	heder("Lista de Inscriptos");
	
	DtSocio** dts = obtenerInfoSociosPorClase(0,5);
	for(int i = 0 ; i<5;i++){
		cout << "ci - " << dts[i]->getCI() << endl;
		cout << "nombre - " << dts[i]->getnombre() << endl;
		cout << "  __________________________________________________________________  " << endl;
	}
	system("pause");

};
void ListadoClase(){
	system("cls");
	heder("Nuestras Clases");
	ImprimeClases();
	system("pause");
};
void ListadoSocios(){
	system("cls");
	heder("Nuestras Socios");
	ImprimeSocio();
	system("pause");
};

void home(){
	int opcion = 1;
	do{
		system("cls");
		heder("Inicio");
		cout << "\t 1 Nuevo socio" << endl;
		cout << "\t 2 Nueva clase" << endl;
		cout << "\t 3 Menu inscripciones" << endl;
		cout << "\t 4 Todas nuestras clases" << endl;
		cout << "\t 5 Todos nuestros Socios" << endl;
		cout << "\t 6 Lista de clase" << endl;
		cout << "\t 7 Salir" << endl;
		cout << endl;
		if (opcion>7 or opcion<0)
			cout << "\t Opcion no valida " << endl;
		else
			cout << endl;
		
		cout << "\t > ";
		cin >> opcion;
		switch(opcion){
			case 1:
				nuevoSocio();
				break;
			case 2:
				if (tipoClase() == 1){
					DtEntrenamiento* p = nuevoEntrenamiento();
					agregarClase(*p);
				}else{
					DtSpinning* p = nuevaSpinning();
					agregarClase(*p);
				}
				break;
			case 3:
				Inscripcion();
				break;
			case 4:
				ListadoClase();
				break;
			case 5:
				ListadoSocios();
				break;
			case 6:
				Listada_de_Clase();
				break;
		}
	}while(opcion!=7);
};


int main(int argc, char** argv) {
	try{
		system("MODE CON: COLS=70 LINES=20");
		system("title Primer Laboratorio");
		system("color 0f");
		InicializaSocio();
		InicializaClases();

		home();
	}catch(std::invalid_argument &a){
		system("color 4f");
		system("cls");
		heder(a.what());
		cout << "  "; // Imprime error
		system("pause");
	}

	
}
