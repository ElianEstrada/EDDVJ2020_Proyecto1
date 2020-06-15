#pragma once
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

class Activo
{

	string id;
	string nombre;
	string descripcion;
	bool disponible;

public:
	Activo(string nombre, string descripcion);


	void setNombre(string nombre);
	string getNombre();
	void setDescripcion(string descripcion);
	string getDescripcion();
	void setID(string id);
	string getID();
	void setDisponible(bool disponible);
	bool getDisponible();

	string arreglar(string id);

};

