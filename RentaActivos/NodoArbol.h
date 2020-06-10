#pragma once
#include <string>

using namespace std;

class NodoArbol
{

	NodoArbol* hijoIzq;
	NodoArbol* hijoDer;
	int numero;

public:
	NodoArbol(int numero);


	void setHijoIzq(NodoArbol* hijoIzq);
	NodoArbol* getHijoIzq();
	void setHijoDer(NodoArbol* hijoDer);
	NodoArbol* getHijoDer();
	void setNumero(int numero);
	int getNumero();

};

