#include "Activo.h"

static int idLocal = 0;

Activo::Activo(string nombre, string descripcion) {

	idLocal++;
	setID(idLocal);
	setNombre(nombre);
	setDescripcion(descripcion);
}

void Activo::setNombre(string nombre) {
	this->nombre = nombre;
}

string Activo::getNombre() {
	return nombre;
}

void Activo::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

string Activo::getDescripcion() {
	return descripcion;
}

void Activo::setID(int id) {
	this->id = id;
}

int Activo::getID() {
	return id;
}
