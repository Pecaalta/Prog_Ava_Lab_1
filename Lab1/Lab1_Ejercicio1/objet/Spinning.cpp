#include "Spinning.h"

int Spinning::getCantBicicletas() {
	return this->cantBicicletas;
};

void Spinning::setCantBicicletas(int cantBicicletas) {
	if (cantBicicletas <= 50 and cantBicicletas > 0 and this->cantBicicletas != cantBicicletas) {
		Inscripcion** arr = new Inscripcion*[cantBicicletas];
		if (this->cantBicicletas > cantBicicletas) {
			int cantlimite = 0;
			for (int i = 0; i < this->cantBicicletas; i++) {
				if (this->Inscriptos[i] != NULL){
					if (cantlimite < cantBicicletas) {
						arr[i] = this->Inscriptos[i];
						cantlimite++;
					}else{
						delete this->Inscriptos[i];
					}
				}
			}
			cout << "Seran eliminados los registros exedentes!\n";
		}else{
			for (int i = 0; i < this->cantBicicletas; i++) {
				if (this->Inscriptos[i] == NULL)
					arr[i] = NULL;
				else {
					arr[i] = this->Inscriptos[i];
					delete this->Inscriptos[i];
				}
			}
			for (int i = this->cantBicicletas; i < cantBicicletas; i++){
				arr[i] = NULL;
			}
		}
		delete this->Inscriptos;
		this->Inscriptos = arr;
		this->cantBicicletas = cantBicicletas;
	} else {
		throw invalid_argument("Exede limite de bisicletas");
	}
};

int Spinning::cupo() {
	return this->cantBicicletas;
};

bool Spinning::searchInscripcion(int ciSocio) {
	for (int i = 0; i < this->cantBicicletas; i++) {
		if (this->Inscriptos[i] != NULL) {
			if (this->Inscriptos[i]->getCI() == ciSocio) {
				return true;
			}
		}
	}
	return false;
};

void Spinning::addInscripcion(Inscripcion* Nueva_Inscripto) {
	bool cant = false;
	for (int i = 0; i < this->cantBicicletas; i++) {
		if (this->Inscriptos[i] == NULL) {
			cant = true;
			this->Inscriptos[i] = Nueva_Inscripto;
			break;
		}
	}
	if (!cant) {
		throw invalid_argument("Cupos llenos");
	}
};

DtSocio** Spinning::getCantSocios(int cantSocios) {
	DtSocio * *ret = new DtSocio*[cantSocios];
	int cant = 0;
	for (int i = 0; i < cantSocios; i++) {
		if (this->Inscriptos[i] != NULL) {
			ret[i] = this->Inscriptos[i]->getcliente();
			cant++;
		}
	}
	for (int i = cant; i < cantSocios ; i++) {
		ret[i] = new DtSocio(0, " ");
	}
	return ret;
};

bool Spinning::deleteInscripcion(int ciSocio) {
	bool retorno = false;
	int lim = this->cantBicicletas, aux = 0;
	Inscripcion** ret = new Inscripcion*[lim];
	Inscripcion** auxborr = this->Inscriptos;
	for (int i = 0; i < lim; i++) {
		if (this->Inscriptos[i] != NULL) {
			if (this->Inscriptos[i]->getCI() != ciSocio) {
				ret[aux] = this->Inscriptos[i];
				aux++;
			} else {
				retorno = true;
				this->Inscriptos[i]->~Inscripcion();
			};
		}
	}
	for (int i = aux; i < lim; i++) {
		ret[i] = NULL;
	}
	delete[] auxborr;
	this->Inscriptos = ret;
	return retorno;
};

ostream& operator<<(ostream& os,  Spinning& dt)  {
	os << endl;
	os << "\t  Id Clase: " << dt.getId()  << endl ;
	os << "\t  Nombre: " << dt.getNombre() << endl;
	os << "\t  Turno: ";
	switch (dt.getTurno()) {
	case Manana:
		os << "Ma" << (char)164 << "ana";
		break;
	case Tarde:
		os << "Tarde";
		break;
	case Noche:
		os << "Noche";
		break;
	}
	os << endl;
	os << "\t  Cantidad de de bicicletas: " << dt.getCantBicicletas() << endl;
	os << endl;

	return os;
};

ostream& operator<<(ostream& os,  Spinning* dt)  {
	os << endl;
	os << "\t  Id Clase: " << dt->getId()  << endl ;
	os << "\t  Nombre: " << dt->getNombre() << endl;
	os << "\t  Turno: ";
	switch (dt->getTurno()) {
	case Manana:
		os << "Ma" << (char)164 << "ana";
		break;
	case Tarde:
		os << "Tarde";
		break;
	case Noche:
		os << "Noche";
		break;
	}
	os << endl;
	os << "\t  Cantidad de de bicicletas: " << dt->getCantBicicletas() << endl;
	os << endl;

	return os;
};

Spinning::Spinning(int id, string nombre, Turno turno, int cantBicicletas): Clase(id, nombre, turno) {

	if (cantBicicletas <= 50) {
		this->cantBicicletas = cantBicicletas;
		Inscripcion** arr = new Inscripcion*[cantBicicletas];
		this->Inscriptos = arr;
		for (int i = 0; i < cantBicicletas; i++) {
			this->Inscriptos[i] = NULL;
		}
	} else {
		throw invalid_argument("Exede limite de bisicletas");
	}
};

Spinning::~Spinning() {};
