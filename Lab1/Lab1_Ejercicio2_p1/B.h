#ifndef B_H
#define B_H

class A;
class C;

class B {
  private:
  	A* mA;
  	C* mC;
  public:
    void imprimir(){
    	cout << "Imprecion de clase B" << endl;
	};
    B(){};
    ~B(){};
};

#include "C.h"
#include "A.h"

#endif
