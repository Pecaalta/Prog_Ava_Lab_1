#include "Funciones.h"

Socio* socio_del_sistema[MAX_SOCIOS];
Clase* 	clases_del_sistema[MAX_CLASES];

void InicializaSocio() {
	for (int i = 0; i < MAX_SOCIOS; i++) {
		socio_del_sistema[i] = NULL;
	}
};

void InicializaClases() {
	for (int i = 0; i < MAX_CLASES; i++) {
		clases_del_sistema[i] = NULL;
	}
};

void ImprimeSocio() {
	int cont = 0;
	for (int i = 0; i < MAX_SOCIOS; i++) {
		Socio* aux = socio_del_sistema[i];
		if (aux != NULL) {
			cont++;
			cout << "     Nombre \t" << aux->getNombre() << endl;
			cout << "     C.I. \t" << aux->getCI() << endl;
			cout << endl;
		}
	}
	if (cont == 0) {
		cout << "    No hay elementos " << endl;
	}
};

void ImprimeClases() {
	int cont = 0;
	for (int i = 0; i < MAX_CLASES; i++) {
		if (clases_del_sistema[i] != NULL) {
			cont++;
			cout << clases_del_sistema[i];
		}
	}
	if (cont == 0) {
		cout << "    No hay elementos " << endl;
	}
};

/*
Crea un nuevo socio en el sistema. En caso de ya existir, levanta la excepci�n
std::invalid_argument.
*/
void agregarSocio(string ci, string nombre) {
	Socio* aux;
	int i = 0;
	bool lleno = false;
	for (i ; i < MAX_SOCIOS; i++) {
		aux = socio_del_sistema[i];
		if (aux == NULL) {
			lleno = true;
			socio_del_sistema[i] = new Socio(ci, nombre);
			break;
		} else if (aux->getCI() == ci) {
			throw invalid_argument("CI duplicado");
		}
	}
	if ( !lleno ) {
		throw invalid_argument("Superado el limite de registros");

	}

};

/*
Crea una nueva clase en el sistema. En caso de ya existir, levanta una excepci�n
std::invalid_argument.
*/

void agregarClase(DtSpinning& clase) {
	int i = 0;
	bool lleno = true;
	for ( i = 0; i < MAX_CLASES; i++) {
		if (clases_del_sistema[i] == NULL) {
			lleno = false;
		}else if (clases_del_sistema[i]->getId() == clase.getid()) {
			throw invalid_argument("ID duplicado");
		}
	}
	if ( lleno ) {
		throw invalid_argument("No hay lugar para mas clases de ese tipo");
	}
	for (i= 0; i < MAX_CLASES; i++) {
		if (clases_del_sistema[i] == NULL) {
			clases_del_sistema[i] = new Spinning(clase.getid(), clase.getnombre(), clase.getturno(), clase.getcantBicicletas());
			clase.~DtSpinning();
			break;
		}
	}
};

void agregarClase(DtEntrenamiento& clase) {
	int i = 0;
	bool lleno = true;
	for ( i = 0; i < MAX_CLASES; i++) {
		if (clases_del_sistema[i] == NULL) {
			lleno = false;
		}else if (clases_del_sistema[i]->getId() == clase.getid()) {
			throw invalid_argument("ID duplicado");
		}
	}
	if ( lleno ) {
		throw invalid_argument("No hay lugar para mas clases de ese tipo");
	}
	for (i= 0; i < MAX_CLASES; i++) {
		if (clases_del_sistema[i] == NULL) {
			clases_del_sistema[i] = new Entrenaminto(clase.getid(), clase.getnombre(), clase.getturno(), clase.getenRambla());
			clase.~DtEntrenamiento();
			break;
		}
	}
};


/*
Crea una inscripci�n de un socio a una clase. La inscripci�n tiene lugar siempre y
cuando el socio y la clase existan, de lo contrario se levanta una excepci�n
std::invalid_argument. Si ya existe una inscripci�n de ese usuario para esa clase, o si
el cupo de esa clase ya fue alcanzado, tambi�n se levanta una excepci�n
std::invalid_argument.
*/
void agregarInscripcion(string ciSocio, int idClase, Fecha fecha) {
	Clase* clase;
	Socio* socio;
	int i = 0;
	bool invalido = false;
	/*
	Salimos en busqueda de los elementos clase, Socio si invalido sige en falso
	indica q el id/ci no se encontro nunca por lo q es invalido
	*/
	for (i ; i < MAX_CLASES; i++) {
		if (clases_del_sistema[i] != NULL and clases_del_sistema[i]->getId() == idClase) {
			invalido = true;
			clase = clases_del_sistema[i];
			break;
		}
	}
	if (!invalido) {
		throw invalid_argument("Id de clase invalido");
	} else {
		invalido = false;
		i = 0;
	}
	for (i ; i < MAX_SOCIOS; i++) {
		socio = socio_del_sistema[i];
		if (socio != NULL and socio->getCI() == ciSocio) {
			invalido = true;
			break;
		}
	}

	if (!invalido) {
		throw invalid_argument("C.I. de socio invalido");
	}


	// covertir string a int por recerimintos de parametos
	int numb;
	istringstream ( ciSocio ) >> numb;

	if (clase->searchInscripcion(numb)) {
		throw invalid_argument("No ahi cupos para este socio en esta clase");
	}

	DtSocio* dt_nuevoSocio = new DtSocio(numb, socio->getNombre());
	Inscripcion* nueva = new Inscripcion(&fecha, dt_nuevoSocio);

	clase->addInscripcion(nueva);
};

/*
Borra la inscripci�n de un socio a una clase. Si no existe una inscripci�n de ese
usuario para esa clase, vanta una excepci�n std::invalid_argument.
*/
void borrarInscripcion(string ciSocio, int idClase) {
	Clase* clase;
	int i = 0;
	bool invalido = false;
	for (i ; i < MAX_CLASES; i++) {
		if (clases_del_sistema[i] != NULL and clases_del_sistema[i]->getId() == idClase) {
			invalido = true;
			clase = clases_del_sistema[i];
			break;
		}
	}
	if (!invalido) {
		throw invalid_argument("Id de clase invalido");
	}

	int numb;
	istringstream ( ciSocio ) >> numb;

	if (!clase->deleteInscripcion(numb)) {
		throw invalid_argument("Socio no existe en este curso ");
	}
};

/*
Retorna un arreglo con los socios que est�n inscriptos a determinada clase. El largo
del arreglo de socios est� dado por el par�metro cantSocios.
*/
DtSocio** obtenerInfoSociosPorClase (int idClase, int cantSocios) {
	Clase* clase;
	int i = 0;
	bool invalido = false;
	for (i ; i < MAX_CLASES; i++) {
		if (clases_del_sistema[i] != NULL and clases_del_sistema[i]->getId() == idClase) {
			invalido = true;
			clase = clases_del_sistema[i];
			break;
		}
	}
	if ( !invalido ) {
		throw invalid_argument("Id de clase invalido");
	}
	if ( clase->cupo() < cantSocios) {
		throw invalid_argument("Se an solicitado demasiados socios");
	}

	return clase->getCantSocios(cantSocios);
};

/*
Retorna la informaci�n de la clase identificada por idClase.
*/
DtClase& obtenerClase(int idClase) {
	Clase* aux;
	Clase* clase;
	int i = 0;
	bool invalido = false;
	for (i ; i < MAX_CLASES; i++) {
		if (clases_del_sistema[i] != NULL and clases_del_sistema[i]->getId() == idClase) {
			invalido = true;
			clase = clases_del_sistema[i];
			break;
		}
	}
	if ( !invalido ) {
		throw invalid_argument("Id de clase invalido");
	} else {
		if ( clase->getType() == "Entrenaminto"){
			DtClase* ret = new DtEntrenamiento(clase->getId(), clase->getNombre(), clase->getTurno(),clase->getEnRambla());
			return *ret;
		}else{
			DtClase* ret = new DtSpinning(clase->getId(), clase->getNombre(), clase->getTurno(),clase->getCantBicicletas());
			return *ret;	
		}
		
		
	}
};
