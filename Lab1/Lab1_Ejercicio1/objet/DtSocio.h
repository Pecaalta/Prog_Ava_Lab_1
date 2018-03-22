#ifndef DTSOCIO_H
#define DTSOCIO_H

#include <string>
using namespace std;

class DtSocio {
  private:
    int CI;
    string nombre;
  public:
    //void setCI(int CI);
    //void setnombre(string nombre);
    int getCI();
    string getnombre();

    DtSocio(int CI, string nombre);
    ~DtSocio();
};


#endif
