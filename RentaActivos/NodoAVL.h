#pragma once
#include "Activo.h"

class NodoAVL
{
	Activo* activo;
	NodoAVL* hijoDer;
	NodoAVL* hijoIzq;
	int altura;

public:
	
	NodoAVL(Activo* activo);

	void setActivo(Activo* activo);
	Activo* getActivo();
	void setHijoDer(NodoAVL* hijoDer);
	NodoAVL* &getHijoDer();
	void setHijoIzq(NodoAVL* hijoIzq);
	NodoAVL* &getHijoIzq();
	void setAltura(int altura);
	int getAltura();
};

