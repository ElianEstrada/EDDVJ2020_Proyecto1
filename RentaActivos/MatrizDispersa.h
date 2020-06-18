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
	NodoMatriz* buscarUsuarioCabeza(NodoMatriz* usuarioActual);



	NodoMatriz* existe(NodoMatriz* cabezaH, string empresa);
	bool existeNombre(NodoMatriz* usuarios, string nombre);


	bool estaAbajo(NodoMatriz* nodo, string empresa);
	bool estaIzquierda(NodoMatriz* nodo, string departamento);


	//Mostrar Activos
	NodoAVL* catalogoActivos(Usuario* usuarioActual, bool bandera, string id);
	NodoAVL* catalogoActivos(Usuario* usuarioActual, NodoMatriz* comienzo, bool bandera, string id);

};

