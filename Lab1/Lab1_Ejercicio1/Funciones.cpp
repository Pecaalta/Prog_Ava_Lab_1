#include "Funciones.h"

	Socio* socio_del_sistema[MAX_SOCIOS];
	Clase* clases_del_sistema[MAX_CLASES];
	Inscripcion* Inscripcion_del_sistema[MAX_CLASES*MAX_SOCIOS];

	void InicializaSocio(){
		for(int i = 0;i<MAX_SOCIOS;i++){
			socio_del_sistema[i]=NULL;
		}
	}
	void InicializaClases(){
		for(int i = 0;i<MAX_CLASES;i++){
			clases_del_sistema[i]=NULL;
		}
	}
	void ImprimeSocio(){
		for(int i = 0;i<MAX_SOCIOS;i++){
			Socio* aux = socio_del_sistema[i];
			if (aux != NULL) {
				cout << "ci" << aux->getCI() << endl;
				cout << "nombre " << aux->getNombre() << endl;
			}else{
				break;
			}
		}
	}
	void ImprimeClases(){
		for(int i = 0;i<MAX_CLASES;i++){
			Clase* aux = clases_del_sistema[i];
			if (aux != NULL) {
				cout << "ci " << aux->getId() << endl;
				cout << "Nombre " << aux->getNombre() << endl;
				cout << "Turno " << aux->getTurno() << endl;
			}else{
				break;
			}
		}
	}



	/*
		Crea un nuevo socio en el sistema. En caso de ya existir, levanta la excepci�n
		std::invalid_argument.
	*/
	void agregarSocio(string ci, string nombre){
		Socio* aux;
		int i = 0;

		for(i ;i<MAX_SOCIOS;i++){
			aux = socio_del_sistema[i];
			if (aux == NULL) {
				socio_del_sistema[i] = new Socio(ci,nombre);
				break;
			}
			if (aux->getCI() == ci) throw invalid_argument("CI duplicado");
		}
		if ( i == (MAX_SOCIOS - 1) )
			throw invalid_argument("Superado el limite de registros");

	}

	/*
		Crea una nueva clase en el sistema. En caso de ya existir, levanta una excepci�n
		std::invalid_argument.
	*/
	void agregarClase(DtSpinning& clase){
		Clase* aux;
		int i = 0;

		for(i ;i<MAX_CLASES;i++){
			aux = clases_del_sistema[i];
			if (aux == NULL) {
				clases_del_sistema[i] = new Spinning(clase.getid(),clase.getnombre(),clase.getturno(),clase.getcantBicicletas());
				clase.~DtSpinning();
				break;
			}
			if (aux->getId() == clase.getid()) throw invalid_argument("ID duplicado");
		}
		if ( i == (MAX_CLASES - 1) )
			throw invalid_argument("Superado el limite de registros");
	}
	void agregarClase(DtEntrenamiento& clase){
		Clase* aux;
		int i = 0;

		for(i ;i<MAX_CLASES;i++){
			aux = clases_del_sistema[i];
			if (aux == NULL) {
				clases_del_sistema[i] = new Entrenaminto(clase.getid(),clase.getnombre(),clase.getturno(),clase.getenRambla());
				clase.~DtEntrenamiento();
				break;
			}
			if (aux->getId() == clase.getid()) throw invalid_argument("ID duplicado");
		}
		if ( i == (MAX_CLASES - 1) )
			throw invalid_argument("Superado el limite de registros");
	}




	/*
		Crea una inscripci�n de un socio a una clase. La inscripci�n tiene lugar siempre y
		cuando el socio y la clase existan, de lo contrario se levanta una excepci�n
		std::invalid_argument. Si ya existe una inscripci�n de ese usuario para esa clase, o si
		el cupo de esa clase ya fue alcanzado, tambi�n se levanta una excepci�n
		std::invalid_argument.
	*/
	void agregarInscripcion(string ciSocio, int idClase, Fecha fecha){

		Clase* clase;
		Socio* socio;
		int i = 0;
		for(i ;i<MAX_CLASES;i++){
			clase = clases_del_sistema[i];
			if (clase != NULL and clase->getId() == idClase) break;
		}
		if (i == (MAX_CLASES-1)) throw invalid_argument("Id de clase invalido");
		else i = 0;
		for(i ;i<MAX_SOCIOS;i++){
			socio = socio_del_sistema[i];
			if (socio != NULL and socio->getCI() == ciSocio) break;
		}
		if (i == (MAX_SOCIOS-1)) throw invalid_argument("CI del socio invalido");
		else i = 0;

		//cobertir string a int
	
		int numb;	
		istringstream ( ciSocio ) >> numb;
		
		if (clase->searchInscripcion(numb)) throw invalid_argument("No ahi cupos para este socio en esta clase");

		DtSocio* dt_nuevoSocio = new DtSocio(numb, socio->getNombre());
		Inscripcion* nueva = new Inscripcion(&fecha,dt_nuevoSocio);

		clase->addInscripcion(nueva);

	}
	void borrarInscripcion(string ciSocio, int idClase){
		/*
			Borra la inscripci�n de un socio a una clase. Si no existe una inscripci�n de ese
			usuario para esa clase, vanta una excepci�n std::invalid_argument.
		*/
		Clase* clase;
		int i = 0;
		for(i ;i<MAX_CLASES;i++){
			clase = clases_del_sistema[i];
			if (clase != NULL and clase->getId() == idClase) break;
		}
		if (i == (MAX_CLASES-1)) throw invalid_argument("Id de clase invalido");
		int numb;	
		istringstream ( ciSocio ) >> numb;
		if(!clase->deleteInscripcion(numb)) throw invalid_argument("Socio no existe en este curso ");
	}

	DtSocio** obtenerInfoSociosPorClase (int idClase, int cantSocios){
		/*
			Retorna un arreglo con los socios que est�n inscriptos a determinada clase. El largo
			del arreglo de socios est� dado por el par�metro cantSocios.
		*/
		Clase* clase;
		int i = 0;
		for(i ;i<MAX_CLASES;i++){
			clase = clases_del_sistema[i]; 
			if (clase != NULL and clase->getId() == idClase) break;
		}
		if (i == (MAX_CLASES-1)) throw invalid_argument("Id de clase invalido");
		else i = 0;
		
		return clase->getCantSocios(cantSocios);
	}
	DtClase& obtenerClase(int idClase){
		/*
			Retorna la informaci�n de la clase identificada por idClase.
		*/
		/*
		Clase* clase;
		int i = 0;
		for(i ;i<MAX_CLASES;i++){
			clase = clases_del_sistema[i];
			if (clase != NULL and clase->getId() == idClase) break;
		}
		if (i == (MAX_CLASES-1)) throw invalid_argument("Id de clase invalido");
		*/
	}
