#pragma once
#include <iostream>
#include <string>
#include "Usuario.h"

class NodoMatriz
{
	NodoMatriz* sig;
	NodoMatriz* ant;
	NodoMatriz* arriba;
	NodoMatriz* abajo;
	NodoMatriz* delante;
	NodoMatriz* atras;
	Usuario* usuario;
	string cabecera;

public:
	NodoMatriz(string nombre);
	NodoMatriz(Usuario* usuario);
	void setSig(NodoMatriz* sig);
	NodoMatriz* getSig();
	void setAnt(NodoMatriz* ant);
	NodoMatriz* getAnt();
	void setArriba(NodoMatriz* arriba);
	NodoMatriz* getArriba();
	void setAbajo(NodoMatriz* abajo);
	NodoMatriz* getAbajo();
	void setDelante(NodoMatriz* delante);
	NodoMatriz* getDelante();
	void setAtras(NodoMatriz* atras);
	NodoMatriz* getAtras();
	void setUsuario(Usuario* usuario);
	Usuario* getUsuario();
	void setCabecera(string cabecera);
	string getCabecera();
};

