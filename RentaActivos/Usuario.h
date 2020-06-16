#pragma once

#include <iostream>
#include <string>
#include "ArbolAVL.h"

using namespace std;

class Usuario
{

	string nombre;
	string usuario;
	string contrase�a;
	ArbolAVL* arbol;


public:
	Usuario(string nombre, string usuario, string contrase�a);
	void setNumero(string nombre);
	string getNombre();
	void setUsuario(string usuario);
	string getUsuario();
	void setContrase�a(string contrase�a);
	string getContrase�a();
	void setArbol(ArbolAVL* arbol);
	ArbolAVL* getArbol();
};

