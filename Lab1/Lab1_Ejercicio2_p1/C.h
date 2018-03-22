#ifndef C_H
#define C_H

class A;
class B;

class C {
  private:
  	A* mA;
  	B* mB;
  public:
    void imprimir(){
    	cout << "Imprecion de clase C" << endl;
	};
    C(){};
    ~C(){};
};

#include "A.h"
#include "B.h"
#endif
