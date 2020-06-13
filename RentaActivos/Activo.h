#pragma once
#include <string>

using namespace std;

class Activo
{

	int id;
	string nombre;
	string descripcion;

public:
	Activo(string nombre, string descripcion);


	void setNombre(string nombre);
	string getNombre();
	void setDescripcion(string descripcion);
	string getDescripcion();
	void setID(int id);
	int getID();

};

