#ifndef SOCIO_H
#define SOCIO_H

#include <string>
using namespace std;

class Socio {
  private:
    string CI;
    string nombre;
  public:
    string getCI();
    string getNombre();
    void setCI();
    void setNombre();
    Socio(string ci, string nombre);
    ~Socio();
};


#endif
