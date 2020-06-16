#include "Usuario.h"


Usuario::Usuario(string nombre, string usuario, string contraseña) {

	setNumero(nombre);
	setUsuario(usuario);
	setContraseña(contraseña);
	setArbol(new ArbolAVL());
}


void Usuario::setNumero(string nombre) {
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

void Usuario::setArbol(ArbolAVL* arbol) {
	this->arbol = arbol;
}

ArbolAVL* Usuario::getArbol() {
	return arbol;
}