#ifndef DTCLASE_H
#define DTCLASE_H

#include "../datos.h"
#include <iostream>
#include <string>
using namespace std;

class DtClase {
private:
    int id;
    string nombre;
    Turno turno;
public:
    //void setid(int id);
    //void setnombre(string nombre);
    //void setturno(Turno turno);
    int getid();
    string getnombre();
    Turno getturno();

    friend ostream& operator<<(ostream& os,  DtClase& dt);
    friend ostream& operator<<(ostream& os,  DtClase* dt);

    DtClase(int id, string nombre, Turno turno);
    ~DtClase();
};


#endif
