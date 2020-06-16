#include "NodoAVL.h"

NodoAVL::NodoAVL(Activo* activo) {

	setActivo(activo);
	setHijoDer(nullptr);
	setHijoIzq(nullptr);
	setAltura(0);


}


void NodoAVL::setActivo(Activo* activo) {
	this->activo = activo;
}

Activo* NodoAVL::getActivo() {
	return activo;
}

void NodoAVL::setHijoDer(NodoAVL* hijoDer) {
	this->hijoDer = hijoDer;
}

NodoAVL* &NodoAVL::getHijoDer() {
	return hijoDer;
}

void NodoAVL::setHijoIzq(NodoAVL* hijoIzq) {
	this->hijoIzq = hijoIzq;
}

NodoAVL* &NodoAVL::getHijoIzq() {
	return hijoIzq;
}

void NodoAVL::setAltura(int altura) {
	this->altura = altura;
}

int NodoAVL::getAltura() {
	return altura;
}