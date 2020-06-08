#pragma once

#include <string>
#include "Transaccion.h"

using namespace std;

class NodoTransaccion
{

	NodoTransaccion* sig;
	NodoTransaccion* ant;
	Transaccion* transaccion;

public:

	NodoTransaccion(Transaccion* transaccion);
	void insertarAlFinal(Transaccion* transaccion);

	void setSig(NodoTransaccion* sig);
	NodoTransaccion* getSig();
	void setAnt(NodoTransaccion* ant);
	NodoTransaccion* getAnt();
	void setTransaccion(Transaccion* transaccion);
	Transaccion* getTransaccion();

};

