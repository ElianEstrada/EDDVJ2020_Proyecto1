#pragma once
#include "NodoMatriz.h"

class MatrizDispersa
{
	NodoMatriz* ini;
	NodoMatriz* cabHorizontal;
	NodoMatriz* cabVertical;

public:
	MatrizDispersa();
	void insertarCabHorizontal(string departamento);
	void insertarCabVertical(string empresa);

};

