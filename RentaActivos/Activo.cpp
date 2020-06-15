#include "Activo.h"



static string idLocal;

Activo::Activo(string nombre, string descripcion) {

	idLocal = to_string(rand()) +nombre + to_string(nombre.length()) + descripcion + to_string(descripcion.length());
	setID(arreglar(idLocal));
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

void Activo::setID(string id) {
	this->id = id;
}


string Activo::getID() {
	return id;
}

void Activo::setDisponible(bool disponible) {
	this->disponible = disponible;
}

bool Activo::getDisponible() {
	return disponible;
}

string Activo::arreglar(string id) {

	if (id.length() >= 15) {
		string aux; 
		for (int i = 0; i < 15; i++) {
			aux += id[i];
		}

		id = aux;
	}
	else {
		int i = id.length() - 1;
		id += to_string(i) + id[i - 1] + to_string(i * id.length());
		id = arreglar(id);
	}

	return id;
}