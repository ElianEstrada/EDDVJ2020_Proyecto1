#include "Usuario.h"


Usuario::Usuario(string nombre, string usuario, string contraseña) {

	setNombre(nombre);
	setUsuario(usuario);
	setContraseña(contraseña);
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

void Usuario::setContraseña(string contraseña) {
	this->contraseña = contraseña;
}

string Usuario::getContraseña() {
	return contraseña;
}