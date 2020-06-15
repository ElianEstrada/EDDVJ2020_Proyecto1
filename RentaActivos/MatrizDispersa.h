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
	void insertarAlFinalDep(Usuario* usuario, NodoMatriz* cabeceraH, string empresa);
	void insertarAlFinalEmp(Usuario* usuario, NodoMatriz* cabeceraV, string departamento);
	void insertarAtras(Usuario* nuevoUsuario, NodoMatriz* usuarioActual);

	void insertarAlMedio(NodoMatriz* nuevoUsuario, NodoMatriz* abajo, bool bandera);
	void insertarEnmedio(Usuario* usuario, NodoMatriz* cabeceraH, NodoMatriz* cabeceraV);

	NodoMatriz* buscarCabeceraV(NodoMatriz* usuarioActual);
	NodoMatriz* buscarUsuarioAbajo(NodoMatriz* nodo, string dep);
	NodoMatriz* buscarCabeceraH(NodoMatriz* usuarioActual);
	NodoMatriz* buscarUsuarioSig(NodoMatriz* nodo, string emp);


	NodoMatriz* existe(NodoMatriz* cabezaH, string empresa);


	bool estaAbajo(NodoMatriz* nodo, string empresa);
	bool estaIzquierda(NodoMatriz* nodo, string departamento);

};

