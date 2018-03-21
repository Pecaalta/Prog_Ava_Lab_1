#include <iostream>
#include <string>
using namespace std;

#include "C.h"
#include "B.h"
#include "A.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	A* insA = new A();
	B* insB = new B();
	C* insC = new C();
	insA->imprimir();
	insB->imprimir();
	insC->imprimir();
}
