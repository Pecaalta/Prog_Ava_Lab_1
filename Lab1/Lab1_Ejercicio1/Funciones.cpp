#include "Funciones.h"

	Socio* socio_del_sistema[MAX_SOCIOS];
	Clase* clases_del_sistema[MAX_CLASES];
	Inscripcion* Inscripcion_del_sistema[MAX_CLASES];
	
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
	


	void agregarSocio(string ci, string nombre){
		/*
			Crea un nuevo socio en el sistema. En caso de ya existir, levanta la excepción
			std::invalid_argument.
		*/
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
	
	void agregarClase(DtSpinning& clase){
		/*
			Crea una nueva clase en el sistema. En caso de ya existir, levanta una excepción
			std::invalid_argument.
		*/
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
		/*
			Crea una nueva clase en el sistema. En caso de ya existir, levanta una excepción
			std::invalid_argument.
		*/
		Clase* aux;
		int i = 0;
		
		for(i ;i<MAX_CLASES;i++){
			aux = clases_del_sistema[i];
			if (aux == NULL) {
				clases_del_sistema[i] = new Entrenaminto(clase.getid(),clase.getnombre(),clase.getturno(),clase.getenRambla());
				clase.~DtEntrenamiento();
				break;
			}
			if (aux->getId() == clase.getid()) throw invalid_argument("CI duplicado");
		}
		if ( i == (MAX_CLASES - 1) )
			throw invalid_argument("Superado el limite de registros");
	}
	
	
	
	
	
	void agregarInscripcion(string ciSocio, int idClase, Fecha fecha){
		/*
			Crea una inscripción de un socio a una clase. La inscripción tiene lugar siempre y
			cuando el socio y la clase existan, de lo contrario se levanta una excepción
			std::invalid_argument. Si ya existe una inscripción de ese usuario para esa clase, o si
			el cupo de esa clase ya fue alcanzado, también se levanta una excepción
			std::invalid_argument. 
		*/
		
	}
	void borrarInscripcion(string ciSocio, int idClase){
		/*
			Borra la inscripción de un socio a una clase. Si no existe una inscripción de ese
			usuario para esa clase, vanta una excepción std::invalid_argument.
		*/
	}
	
	DtSocio** obtenerInfoSociosPorClase (int idClase, int& cantSocios){
		/*
			Retorna un arreglo con los socios que están inscriptos a determinada clase. El largo
			del arreglo de socios está dado por el parámetro cantSocios.
		*/
	}
	DtClase& obtenerClase(int idClase){
		/*
			Retorna la información de la clase identificada por idClase.
		*/
	}
