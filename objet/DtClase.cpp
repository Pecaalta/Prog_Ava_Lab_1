
#include "DtClase.h"

void DtClase::setid(int id){
  this->id = id;
};
void DtClase::setnombre(string nombre){
  this->nombre = nombre;
};
void DtClase::setturno(Turno turno){
  this->turno = turno;
};
int DtClase::getid(){
  return this->id;
};
string DtClase::getnombre(){
  return this->nombre;
};
Turno DtClase::getturno(){
  return this->turno;
};
DtClase::DtClase(int id, string nombre, Turno turno){
  this->id = id;
  this->nombre = nombre;
  this->turno = turno;
};
ostream& operator<<(ostream& os, const DtClase& dt)  
{  
    os << dt.id << '/' << dt.nombre << '/' << dt.turno;  
    return os;  
}  
DtClase::~DtClase(){};
