#pragma once
#include "NodoMatriz.h"
#include "Usuario.h"

class MatrizDispersa
{
	NodoMatriz* ini;
	NodoMatriz* cabHorizontal;
	NodoMatriz* cabVertical;

public:
	MatrizDispersa();
	NodoMatriz* insertarCabHorizontal(string departamento);
	NodoMatriz* insertarCabVertical(string empresa);
	void insertarUsuario(Usuario* usuario, string departamento, string empresa);
	NodoMatriz* buscarDepartamento(string departamento);
	NodoMatriz* buscarEmpresa(string empresa);

	//Metodos de la lista doblemente enlazada
	void insertarAlFinal(Usuario* usuario, NodoMatriz* cabeceraH, NodoMatriz* cabeceraV);
	void insertarAlFinalDep(Usuario* usuario, NodoMatriz* cabeceraH);
	void insertarAlFinalEmp(Usuario* usuario, NodoMatriz* cabeceraV);
	void insertarEnmedio(Usuario* usuario, NodoMatriz* cabecera);

};

