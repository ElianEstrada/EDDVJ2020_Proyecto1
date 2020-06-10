#include "NodoArbol.h"


NodoArbol::NodoArbol(int numero) {
	setNumero(numero);
	setHijoDer(nullptr);
	setHijoIzq(nullptr);
}

void NodoArbol::setHijoIzq(NodoArbol* hijoIzq) {
	this->hijoIzq = hijoIzq;
}

NodoArbol* NodoArbol::getHijoIzq() {
	return hijoIzq;
}

void NodoArbol::setHijoDer(NodoArbol* hijoDer) {
	this->hijoDer = hijoDer;
}

NodoArbol* NodoArbol::getHijoDer() {
	return hijoDer;
}

void NodoArbol::setNumero(int numero) {
	this->numero = numero;
}

int NodoArbol::getNumero() {
	return numero;
}