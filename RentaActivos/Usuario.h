#pragma once

#include <iostream>
#include <string>
#include "ArbolAVL.h"

using namespace std;

class Usuario
{

	string nombre;
	string usuario;
	string contraseña;
	ArbolAVL* arbol;


public:
	Usuario(string nombre, string usuario, string contraseña);
	void setNumero(string nombre);
	string getNombre();
	void setUsuario(string usuario);
	string getUsuario();
	void setContraseña(string contraseña);
	string getContraseña();
	void setArbol(ArbolAVL* arbol);
	ArbolAVL* getArbol();
};

