#include "Usuario.h"


Usuario::Usuario(string nombre, string usuario, string contrase�a) {

	setNombre(nombre);
	setUsuario(usuario);
	setContrase�a(contrase�a);
}


void Usuario::setNombre(string nombre) {
	this->nombre = nombre;
}

string Usuario::getNombre() {
	return nombre;
}

void Usuario::setUsuario(string usuario) {
	this->usuario = usuario;
}

string Usuario::getUsuario() {
	return usuario;
}

void Usuario::setContrase�a(string contrase�a) {
	this->contrase�a = contrase�a;
}

string Usuario::getContrase�a() {
	return contrase�a;
}