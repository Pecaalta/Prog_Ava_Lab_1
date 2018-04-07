#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
using namespace std;
#include "Funciones.h"
#include "objet/DtSpinning.h"
#include "objet/DtEntrenamiento.h"
int ancho = 120;

#ifdef linux

#include <sys/ioctl.h>

string ASCII[] = {"\u2550", "\u2551", "\u2554", "\u2557", "\u255D", "\u255A", "\u2500"};

void vaciar() {
	system("clear");
};

void FormatearVentana() {
	printf("\033]0;%s\007", "Primer Laboratorio");
	struct winsize X;
	ioctl(0, TIOCGWINSZ, &X);
	ancho  = X.ws_col;
};

#endif
#if  defined(WIN32) || defined(_WIN32)

char ASCII[]  = {(char)205, (char)186, (char)201, (char)187, (char)188, (char)200, (char)196};

void vaciar() {
	system("cls");
};

void FormatearVentana() {
	//system("MODE CON: COLS=80 LINES=20");
	system("title Primer Laboratorio");
	system("color 0f");
};

#endif
void clean_stdin(void){
	char c;
	while((c = getchar()) != '\n' && c != EOF);
}
void pausar() {
	cout << "Precione enter para continuar...";
	cin.ignore(cin.rdbuf()->in_avail()+1);
};

int toInt(string texto) {
	int ret = 0, aux = 0, pow = 1;
	for (int i = texto.size() - 1; i >= 0; i--) {
		aux = ((int)texto[i] - 48);
		if (aux <= 9 and aux >= 0 ) {
			ret += pow * aux;
			pow *= 10;
		} else {
			return -1;
		}
	}
	return ret;
};

void header(string texto) {
	int anchoImprimible = (ancho - 10);
	int spacio = (anchoImprimible - texto.size()) / 2;
	int var1 = (spacio * 2);
	int var2 = anchoImprimible - texto.size();
	string tab = "    ";
	cout << endl;
	cout << tab << ASCII[2];
	for (int i = 0 ; i < anchoImprimible; i++) {
		cout << ASCII[0];
	}
	cout << ASCII[3] << endl;

	cout <<  tab << ASCII[1];
	for (int i = 0 ; i < spacio; i++) {
		cout << " ";
	}
	cout << texto;
	if ( var1 != var2){
		cout << " ";
	}
	for (int i = 0 ; i < spacio; i++) {
		cout << " ";
	}
	cout << ASCII[1] << endl;

	cout <<  tab << ASCII[5];
	for (int i = 0 ; i < anchoImprimible; i++) {
		cout << ASCII[0];
	}
	cout << ASCII[4] << endl;
	cout << endl;
};

void footer() {
	int anchoImprimible = (ancho - 12);
	cout << endl << "      ";
	for (int i = 0 ; i < anchoImprimible; i++) {
		cout << ASCII[6];
	}
	cout << endl << "   ";
	pausar();
};

void easterEgg(int argc, char** argv) {
	if (argc!=1){
		string str2(argv[1]);
		string str1 = "rusia";
		if (str2.compare(str1) == 0){
			vaciar();
			cout << "           . .....                                   " << endl;
			cout << "       ...MMOO88DMD.                                 " << endl;
			cout << "       .7M8OMMMMDODM.             ...8O . .          " << endl;
			cout << "       .MOOM+++++M8OMMMMMMMMMO... MOO8O88M.          " << endl;
			cout << "        M8M++++MMDO8888O88OZZZZ$MMO8MM~=NOM..        " << endl;
			cout << "       .M8M+IMOOO8888888ZZZZZZZZZZ$MM+++?ID          " << endl;
			cout << "       .MO8M8O88888888OZZZZZZZZZZZZZZM+++OM..        " << endl;
			cout << "       ..MM8888888888ZZZZZZZZZZZZZZZZONM8M..         " << endl;
			cout << "       ..M888888888OZZZZZZZZZZZZZZZZZZZMM..          " << endl;
			cout << "       .M8O8888888NMMZZZZZZZZZZZZZZZZZZZM.           " << endl;
			cout << "       N88888888OMMMMMZZZZZZZZZZZZZ8ZZZZZ.           " << endl;
			cout << "       M888888888MMMMMOZZZZZZZZZZMMMMM$ZZM.          " << endl;
			cout << "     .IM8888888888MMM$ZZZZZZZZZZZMMMMMMZZM           " << endl;
			cout << "     .M88888888888OOZZZZZZZZZZZZZZMMMMZZZM.          " << endl;
			cout << "     .MO88888888888OM~++++?MM++?$ZZZZZZZZM.  Un sabio una ves dijo:" << endl;
			cout << "    .MO88888888888NM?++++MMMMM++?+MZZZZZZM..'Que el poder de Putin te acompa" << (char)164 << "e" << endl;
			cout << "   .M88888888888O8M=++++++MMM?++++IZZZZZZZ?. yoda'" << endl;
			cout << "  .MO8888888888888OMM++IMMMMM+++?+MZZZZZZZM.         " << endl;
			cout << "..MMMM888888888888888MZM:~~~::MMMZZZZZZZZZOM..       " << endl;
			cout << "....M8888O88888888888MZM:~~~~$NDZZZZZMZZZMMNM        " << endl;
			cout << "   ,MNM8OMOOMOO888888M$$M:~~$ZMZZZ$$ZMMZM..          " << endl;
			cout << "   ,.MMMOMDNNMO888888OMZZOM8ZMZZZZZDM8MMMM.          " << endl;
			cout << "  .MMO88888O88888OOZZZZNMD$8MOZZZZZ8888ZZZNM.        " << endl;
			cout << "  7M8O8888888888OZZZZZZZZZZZZZZZZZZM888ZZZZZM.       " << endl;
			cout << " .M88888888O888OZZZZZZZZZZZZZZZZZZZM8888OZZZZM.      " << endl;
			cout << ".M8O88888M8888OZZZZZZZZZZZZZZZZZZZZM.MO88MOZZ$M.     " << endl;
			cout << ".M8888888MO8888ZZZZZZZZZZZZZZZZZZZZM...D8ZZZZZM      " << endl;
			cout << "DN8888888MNDMMMMMM8ZZZZZZZZZZZZZZZ8..?MZZZZZZM       " << endl;
			cout << "M8888888OO888O88888MZZZZZZZZZZZZZZM.DNZZZZZOM..     Enter para continuar.. ";
			clean_stdin();

		}
	}
}

int TipoClase() {
	string s_opcion = "1";
	do {
		vaciar();
		header("Tipo de Clase");
		cout << "\t  Tipo de clase: " << endl;
		cout << "\t   1 Entrenaminto" << endl;
		cout << "\t   2 Spining" << endl;
		cout << endl;
		if (s_opcion != "1") {
			cout << "\t  Opcion Invalida " << endl;
		} else {
			cout << endl;
		}
		cout << "\t  > ";
		clean_stdin();
		cin >> s_opcion;
	} while (s_opcion != "1" and s_opcion != "2");

	return toInt(s_opcion);
};

DtEntrenamiento* NuevoEntrenamiento() {
	string nombre = ".", opcion, varcin;
	int id = 1;
	Turno t;
	bool enrambla, continuar = false;
	vaciar();
	header("Nueva Clase");

	do {
		if (nombre == ""){
			cout << "\t  Campo vacio" << endl;
		}else{
			clean_stdin();
		}
		cout << "\t  Nombre > ";
		getline(cin, nombre, '\n');
	}while(nombre == "");

	while (!continuar) {
		cout << "\t  Turno: ";
		cout << endl;
		cout << "\t   1 Ma" << (char)164 << "ana " << endl;
		cout << "\t   2 Tarde " << endl;
		cout << "\t   3 Noche " << endl;
		cout << endl;
		cout << "\t    > ";
		cin >> opcion;
		if (opcion == "1")	{
			t = Manana;
			continuar = true;
		} else if (opcion == "2")	{
			t = Tarde;
			continuar = true;
		} else if (opcion == "3")	{
			t = Noche;
			continuar = true;
		} else {
			cout << "\t  Opcion incorrecta\n";
		}
	}
	continuar = false;

	while (!continuar) {
		cout << "\t  En Ruta si(1)/no(2)> ";
		clean_stdin();
		cin >> opcion;
		if (opcion == "si" or opcion == "Si" or opcion == "SI" or opcion == "s" or opcion == "S" or opcion == "1") {
			continuar = true;
			enrambla = true;
		}
		else if (opcion == "no" or opcion == "No" or opcion == "NO" or opcion == "n" or opcion == "N" or opcion == "2") {
			continuar = true;
			enrambla = false;
		} else {
			cout << "\t  Opcion incorrecta";
			cout << endl;
		}
	}

	do {
		if (id != 1) {
			cout << "\t  No es un numero " << endl;
		}
		cout << "\t  ID > ";
		clean_stdin();
		cin >> opcion;
		id = toInt(opcion);
	} while (id == -1);

	return new DtEntrenamiento(id, nombre, t, enrambla);
};

DtSpinning* NuevaSpinning() {
	string nombre = ".", opcion;
	int id = 1, cantbicis;
	Turno t;
	bool continuar = false;
	vaciar();
	header("Nueva Clase");

	do {
		if (nombre == ""){
			cout << "\t  Campo vacio" << endl;
		}else{
			clean_stdin();
		}
		cout << "\t  Nombre > ";
		getline(cin, nombre, '\n');
	}while(nombre == "");

	do{
		cout << "\t  Turno: ";
		cout << endl;
		cout << "\t   1 Ma" << (char)164 << "ana " << endl;
		cout << "\t   2 Tarde " << endl;
		cout << "\t   3 Noche " << endl;
		cout << "\t  > ";
		getline(cin, opcion, '\n');
		if (opcion == "1")	{
			t = Manana;
			continuar = true;
		} else if (opcion == "2")	{
			t = Tarde;
			continuar = true;
		} else if (opcion == "3")	{
			t = Noche;
			continuar = true;
		} else {
			cout << "\t  Opcion incorrecta\n";
		}
	}while (!continuar);

	do {
		if (id != 1) cout << "\t  No es un numero " << endl;
		cout << "\t  Canteidad de Bisicletas > ";
		cin >> opcion;
		cantbicis = toInt(opcion);
	} while (cantbicis == -1);

	do {
		if (id != 1) cout << "\t  No es un numero " << endl;
		cout << "\t  ID > ";
		cin >> opcion;
		id = toInt(opcion);
	} while (id == -1);

	return new DtSpinning(id, nombre, t, cantbicis);

};

void NuevoSocio() {
	vaciar();
	header("Nueva Socio");
	string nombre = ".", ci = ".";

	do {
		if (nombre == ""){
			cout << "\t  Campo vacio" << endl;
		}else{
			clean_stdin();
		}
		cout << "\t  Nombre > ";
		getline(cin, nombre, '\n');
	}while(nombre == "");

	do {
		if (ci == ""){
			cout << "\t  Campo vacio" << endl;
		}
		cout << "\t  C.I. > ";
		getline(cin, ci, '\n');
	}while(ci == "");

	agregarSocio(ci, nombre);

};

void Inscripcion() {
	int d, m, a, idclase;
	string ci, opcion, aux;
	bool continuar = false;

	d = m = a = 1;
	do{
		vaciar();
		header("Inscripciones");
		cout << "\t  1 Inscribirse " << endl;
		cout << "\t  2 Borrar Inscripciones " << endl;
		cout << endl;
		cout << "\t  > ";
		clean_stdin();
		getline(cin, opcion, '\n');
		if (opcion == "1")	{
			vaciar();
			header("Nueva Inscripcion");
			cout << endl;
			cout << "\t  Fecha: " << endl;

			do {
				if (d != 1) cout << "\t  No es un numero " << endl;
				cout << "\t   Dia \t\t> ";
				cin >> aux;
				d = toInt(aux);
			} while (d == -1);

			do {
				if (m != 1) cout << "\t  No es un numero " << endl;
				cout << "\t   Mes \t\t> ";
				cin >> aux;
				m = toInt(aux);
			} while (m == -1);

			do {
				if (a != 1) cout << "\t  No es un numero " << endl;
				cout << "\t   A" << (char)164 << "o \t\t> ";
				cin >> aux;
				a = toInt(aux);
			} while (a == -1);
			Fecha f(d, m, a);

			cout << "\t  ID del curso \t> ";
			cin >> idclase;
			cout << "\t  C.I \t\t> ";
			clean_stdin();
			getline(cin, ci, '\n');
			agregarInscripcion(ci, idclase, f);
			continuar = true;
		}else if (opcion == "2")	{
			vaciar();
			header("Inscripciones");
			cout << endl;
			cout << "\t  C.I > ";
			getline(cin, ci, '\n');
			cout << "\t  ID del curso > ";
			cin >> idclase;
			borrarInscripcion(ci, idclase);
			continuar = true;
		} else{
			cout << "\t  Opcion incorrecta";
		}
	}while (!continuar);

};

void Listada_de_Clase() {
	string aux;
	int clase = 0, tam = 0;

	do {
		vaciar();
		header("Lista de Inscriptos");
		if (clase == -1 or tam == -1){
			cout << "\t  Alguno de los parametros no fue valido" << endl;
		}else{
			cout << endl;
		}
		cout << "\t  Clase \t\t>";
		cin >> aux;
		clase = toInt(aux);
		cout << "\t  Cantidad a mostrar \t>";
		cin >> aux;
		tam = toInt(aux);
	} while (clase < 0 or tam < 0);

	vaciar();
	header("Lista de Inscriptos");
	DtSocio** dts = obtenerInfoSociosPorClase(clase, tam);
	if ( dts[0]->getCI() == 0)  {
		cout << "\t  No hay inscripciones " << endl;
	} else {
		for (int i = 0 ; i < tam; i++) {
			cout << endl;
			cout << "\t  C.I.   \t- " << dts[i]->getCI() << endl;
			cout << "\t  Nombre \t- " << dts[i]->getnombre() << endl;
		}
	}
	clean_stdin();
	footer();

};

void ListadoClase() {
	vaciar();
	header("Nuestras Clases");
	ImprimeClases();
	clean_stdin();
	footer();
};

void ListadoSocios() {
	vaciar();
	header("Nuestras Socios");
	ImprimeSocio();
	clean_stdin();
	footer();
};

void Info_de_clase() {
	vaciar();
	header("Informacion de Clases");
	string aux;
	int idClase = 1;
	do {
		if (idClase != 1) cout << "\t  No es un numero " << endl;
		cout << "\t   Id de la clase \t\t> ";
		cin >> aux;
		clean_stdin();
		idClase = toInt(aux);
	} while (idClase == -1);
	vaciar();
	header("Informacion de Clases");
	cout <<  obtenerClase(idClase);;
	footer();
};

void Home() {
	string opcionA;
	int opcion = 1;
	do {
		try{
			vaciar();
			header("Inicio");
			cout << "\t  1 Nuevo socio" << endl;
			cout << "\t  2 Nueva clase" << endl;
			cout << "\t  3 Menu inscripciones" << endl;
			cout << "\t  4 Todas nuestras clases" << endl;
			cout << "\t  5 Todos nuestros Socios" << endl;
			cout << "\t  6 Lista de clase" << endl;
			cout << "\t  7 Informacion de clase" << endl;
			cout << "\t  8 Salir" << endl;
			cout << endl;
			if (opcion > 7 or opcion < 0){
				cout << "\t  Opcion no valida " << endl;
			}else{
				cout << endl;
			}

			cout << "\t > ";
			cin >> opcionA;
			opcion = toInt(opcionA);
			switch (opcion) {
			case 1:
				NuevoSocio();
				break;
			case 2:
				if (TipoClase() == 1) {
					DtEntrenamiento* p = NuevoEntrenamiento();
					agregarClase(*p);
				} else {
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
			case 7:
				Info_de_clase();
				break;
			}
		} catch (invalid_argument &a) {
			system("color 4f");
			vaciar();
			header(a.what());
			cout << "  ";
			pausar();
		}
	} while (opcion != 8);
};

int main(int argc, char** argv) {

		FormatearVentana();
		InicializaSocio();
		InicializaClases();
		easterEgg(argc,argv);
		DtEntrenamiento c1(1,"primer clase",Manana,true);
		agregarClase(c1);
		DtSpinning c2(2,"segunda clase",Manana,14);
		agregarClase(c2);



		Home();
	return 1;
};
