#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
using namespace std;

#include "Funciones.h"
#include "objet/DtSpinning.h"
#include "objet/DtEntrenamiento.h"
int ancho = 80;

#ifdef linux


	#include <sys/ioctl.h>

  	string ASCII[] = {"\u2550","\u2551","\u2554","\u2557","\u255D","\u255A"};
	
	void vaciar(){
		system("clear");
	}
	void FormatearVentana(){
		printf("\033]0;%s\007", "Primer Laboratorio");
		struct winsize X;
		ioctl(0, TIOCGWINSZ, &X);
		ancho  = X.ws_col; 
	}
#endif
#if  defined(WIN32) || defined(_WIN32)
 	char ASCII[]  = {(char)205,(char)186,(char)201,(char)187,(char)188,(char)200};
	
	void vaciar(){
		 system("cls");
	}
	void FormatearVentana(){
		system("MODE CON: COLS=80 LINES=20");
		system("title Primer Laboratorio");
		system("color 0f");
	}
#endif

void pausar(){
	cout << "Precione enter para continuar...";
	cin.clear();
  	cin.ignore(); 	
	getchar();
}
int toInt(string texto){
	int ret = 0, aux = 0, pow = 1;
	for(int i = texto.size()-1; i >= 0;i--){
		aux = ((int)texto[i] - 48);
		if(aux <= 9 and aux >= 0 ){
			ret += pow * aux;
			pow *= 10;
		}else{
			return -1;
		}
	}
	return ret;
}

void Cabeza(string texto){
	int anchoImprimible = (ancho-10);
	int spacio = (anchoImprimible-texto.size())/2;
	int var1 = (spacio*2);
	int var2 = anchoImprimible-texto.size();
	string tab = "    ";
	cout << endl;
	cout << tab << ASCII[2];
	for (int i = 0 ;i<anchoImprimible;i++){
		cout << ASCII[0];
	}
	cout << ASCII[3] << endl;

	cout <<  tab << ASCII[1];
	for (int i = 0 ;i<spacio;i++){
		cout << " ";
	}
	cout << texto;
	if( var1 != var2)
		cout << " ";
	for (int i = 0 ;i<spacio;i++){
		cout << " ";
	}
	cout << ASCII[1] << endl;

	cout <<  tab << ASCII[5];
	for (int i = 0 ;i<anchoImprimible;i++){
		cout << ASCII[0];
	}
	cout << ASCII[4] << endl;
	cout << endl;
	}
void Pis(){
	int anchoImprimible = (ancho-18);
	cout << "    ";
	for (int i = 0 ;i<anchoImprimible;i++){
		cout << "-";
	}
	cout << endl << "   ";
	pausar();
}

int TipoClase(){
	string s_opcion = "1";
	do{
		vaciar();
		Cabeza("Tipo de Clase");
		cout << "\t  Tipo de clase: " << endl;
		cout << "\t   1 Entrenaminto" << endl;
		cout << "\t   2 Spining" << endl;
		cout << endl;
		if (s_opcion != "1"){
			cout << "\t  Opcion Invalida " << endl;
		}else{
			cout << endl;
		}
		cout << "\t  > ";
		fflush(stdin);
		cin >> s_opcion;
	}while(s_opcion != "1" and s_opcion != "2");

	fflush(stdin);
	return toInt(s_opcion);
}
DtEntrenamiento* NuevoEntrenamiento(){
	string nombre,opcion, varcin;
	int id = 1;
	Turno t;
	bool enrambla, continuar = false;
	vaciar();
	Cabeza("Nueva Clase");
	do{
		if (id!=1) cout << "\t  No es un numero "<< endl;
		cout << "\t  ID > ";
		cin >> opcion;
		fflush(stdin);
		id = toInt(opcion);
	}while(id==-1);

	cout << "\t  Nombre > ";
	fflush(stdin);
	cin >> nombre;

	while(!continuar){
		cout << "\t  Turno: ";
		cout << endl;
		cout << "\t   1 Ma" << (char)164 << "ana " << endl;
		cout << "\t   2 Tarde " << endl;
		cout << "\t   3 Noche " << endl;
		cout << endl;
		cout << "\t    > ";
		fflush(stdin);
		cin >> opcion;
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
			cout << "\t  Opcion incorrecta";
	}
	continuar = false;
	while(!continuar){
		cout << "\t  En Ruta si(1)/no(2)> ";
		fflush(stdin);
		cin >> opcion;
		if (opcion == "si" or opcion == "Si" or opcion == "SI" or opcion == "s" or opcion == "S" or opcion == "1"){
			continuar = true;
			enrambla = true;
		}
		else if (opcion == "no" or opcion == "No" or opcion == "NO" or opcion == "n" or opcion == "N" or opcion == "2"){
			continuar = true;
			enrambla = false;
		}else{
			cout << "\t  Opcion incorrecta";
			cout << endl;
		}
	}

	return new DtEntrenamiento(id,nombre,t,enrambla);
}
DtSpinning* NuevaSpinning(){
	string nombre,opcion;
	int id = 1,cantbicis;
	Turno t;
	bool continuar = false;
	vaciar();
	Cabeza("Nueva Clase");
	do{
		if (id!=1) cout << "\t  No es un numero "<< endl;
		cout << "\t  ID > ";
		cin >> opcion;
		fflush(stdin);
		id = toInt(opcion);
	}while(id==-1);

	cout << "\t  Nombre > ";
	fflush(stdin);
	getline(cin, nombre);
	fflush(stdin);

	while(!continuar){
		cout << "\t  Turno: ";
		cout << endl;
		cout << "\t   1 Ma" << (char)164 << "ana " << endl;
		cout << "\t   2 Tarde " << endl;
		cout << "\t   3 Noche " << endl;
		cout << "\t  > ";
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
			cout << "\t  Opcion incorrecta";
	}

	cout << "\t  Canteidad de Bisicletas > ";
	fflush(stdin);
	cin >> cantbicis;
	fflush(stdin);

	return new DtSpinning(id,nombre,t,cantbicis);

};
void NuevoSocio(){
	vaciar();
	Cabeza("Nueva Socio");
	string nombre,ci;

	cout << "\t  C.I. > ";
	cin >> ci;
	fflush(stdin);

	cout << "\t  Nombre > ";
	cin >> nombre;
	fflush(stdin);

	agregarSocio(ci,nombre);

};
void Inscripcion(){
	int d,m,a, idclase;
	string ci,opcion,aux;
	bool continuar = false;

	d = m = a = 1;
	while(!continuar){
		vaciar();
		Cabeza("Inscripciones");
		cout << "\t  1 Inscribirse " << endl;
		cout << "\t  2 Borrar Inscripciones " << endl;
		cout << endl;
		cout << "\t  > ";
		getline(cin, opcion);
		fflush(stdin);
		if (opcion == "1")	{
			vaciar();
			Cabeza("Nueva Inscripcion");
			cout << endl;
			cout << "\t  Fecha: " << endl;

			do{
				if (d!=1) cout << "\t  No es un numero "<< endl;
				cout << "\t   Dia \t\t> ";
				cin >> aux;
				fflush(stdin);
				d = toInt(aux);
			}while(d==-1);

			do{
				if (m!=1) cout << "\t  No es un numero "<< endl;
				cout << "\t   Mes \t\t> ";
				cin >> aux;
				fflush(stdin);
				m = toInt(aux);
			}while(m==-1);

			do{
				if (a!=1) cout << "\t  No es un numero "<< endl;
				cout << "\t   A" << (char)164 << "o \t\t> ";
				cin >> aux;
				fflush(stdin);
				a = toInt(aux);
			}while(a==-1);
			Fecha f(d,m,a);

			cout << "\t  ID del curso \t> ";
			cin >> idclase;
			fflush(stdin);
			cout << "\t  C.I \t\t> ";
			getline(cin, ci);
			fflush(stdin);
			agregarInscripcion(ci,idclase,f);
			continuar = true;
		}
		else if (opcion == "2")	{
			system("cls");
			Cabeza("Inscripciones");
			cout << endl;
			cout << "\t  C.I > ";
			getline(cin, ci);
			fflush(stdin);
			cout << "\t  ID del curso > ";
			cin >> idclase;
			borrarInscripcion(ci,idclase);
			continuar = true;
		}else
			cout << "\t  Opcion incorrecta";
	}

};
void Listada_de_Clase(){
	string aux;
	int clase = 0,tam =0;
	do{
		vaciar();
		Cabeza("Lista de Inscriptos");
		if (clase==-1 or tam==-1) 
			cout << "\t  Alguno de los parametros no fue valido" << endl;
		else
			cout << endl;
		cout << "\t  Clase \t\t>";
		cin >> aux;
		clase = toInt(aux);
		cout << "\t  Cantidad a mostrar \t>";
		cin >> aux;
		tam = toInt(aux);
	}while (clase<0 or tam<0);

	vaciar();
	Cabeza("Lista de Inscriptos");
	DtSocio** dts = obtenerInfoSociosPorClase(clase,tam);
	if( dts[0]->getCI() == 0)  {
		cout << "\t  No hay inscripciones " << endl;
	}else{
		for(int i = 0 ; i<tam;i++){
			cout << "\t  C.I. \t- " << dts[i]->getCI() << endl;
			cout << "\t  Nombre \t- " << dts[i]->getnombre() << endl;
		}
	}
	cout << "      __________________________________________________________" << endl << "    ";
	pausar();

};
void ListadoClase(){
	vaciar();
	Cabeza("Nuestras Clases");
	ImprimeClases();
	Pis();
};
void ListadoSocios(){
	vaciar();
	Cabeza("Nuestras Socios");
	ImprimeSocio();
	Pis();
};

void Home(){
	string opcionA;
	int opcion = 1;
	do{
		vaciar();
		Cabeza("Inicio");
		cout << "\t  1 Nuevo socio" << endl;
		cout << "\t  2 Nueva clase" << endl;
		cout << "\t  3 Menu inscripciones" << endl;
		cout << "\t  4 Todas nuestras clases" << endl;
		cout << "\t  5 Todos nuestros Socios" << endl;
		cout << "\t  6 Lista de clase" << endl;
		cout << "\t  7 Salir" << endl;
		cout << endl;
		if (opcion>7 or opcion<0)
			cout << "\t  Opcion no valida " << endl;
		else
			cout << endl;

		cout << "\t > ";
		cin >> opcionA;
		opcion = toInt(opcionA);
		switch(opcion){
			case 1:
				NuevoSocio();
				break;
			case 2:
				if (TipoClase() == 1){
					DtEntrenamiento* p = NuevoEntrenamiento();
					agregarClase(*p);
				}else{
					DtSpinning* p = NuevaSpinning();
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
		FormatearVentana();
		InicializaSocio();
		InicializaClases();

		Home();
	}catch(std::invalid_argument &a){
		system("color 4f");
		vaciar();
		Cabeza(a.what());
		cout << "  ";
		pausar();
	}
}
