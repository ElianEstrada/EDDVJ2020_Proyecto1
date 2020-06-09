#include "NodoMatriz.h"


NodoMatriz::NodoMatriz(string cabecera) {
	setCabecera(cabecera);
	setSig(nullptr);
	setAnt(nullptr);
	setArriba(nullptr);
	setAbajo(nullptr);
	setDelante(nullptr);
	setAtras(nullptr);
}

NodoMatriz::NodoMatriz(Usuario* usuario) {

	setUsuario(usuario);
	setSig(nullptr);
	setAnt(nullptr);
	setArriba(nullptr);
	setAbajo(nullptr);
	setDelante(nullptr);
	setAtras(nullptr);

}


void NodoMatriz::setSig(NodoMatriz* sig) {
	this->sig = sig;
}

NodoMatriz* NodoMatriz::getSig() {
	return sig;
}

void NodoMatriz::setAnt(NodoMatriz* ant) {
	this->ant = ant;
}

NodoMatriz* NodoMatriz::getAnt() {
	return ant;
}

void NodoMatriz::setArriba(NodoMatriz* arriba) {
	this->arriba = arriba;
}

NodoMatriz* NodoMatriz::getArriba() {
	return arriba;
}

void NodoMatriz::setAbajo(NodoMatriz* abajo) {
	this->abajo = abajo;
}

NodoMatriz* NodoMatriz::getAbajo() {
	return abajo;
}

void NodoMatriz::setDelante(NodoMatriz* delante) {
	this->delante = delante;
}

NodoMatriz* NodoMatriz::getDelante() {
	return delante;
}

void NodoMatriz::setAtras(NodoMatriz* atras) {
	this->atras = atras;
}

NodoMatriz* NodoMatriz::getAtras() {
	return atras;
}

void NodoMatriz::setUsuario(Usuario* usuario) {
	this->usuario = usuario;
}

Usuario* NodoMatriz::getUsuario() {
	return usuario;
}

void NodoMatriz::setCabecera(string cabecera) {
	this->cabecera = cabecera;
}

string NodoMatriz::getCabecera() {
	return cabecera;
}