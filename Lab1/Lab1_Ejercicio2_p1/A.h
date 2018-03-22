#ifndef A_H
#define A_H

#include "B.h"
#include "C.h"

class A {
  private:
  	B* mB;
  	C* mC;
  public:
    void imprimir(){
    	cout << "Imprecion de clase A" << endl;
	};
    A(){};
    ~A(){};
};

#endif
