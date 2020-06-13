#include "NodoAVL.h"

NodoAVL::NodoAVL(int numero) {

	this->numero = numero;
	this->hijoDer = nullptr;
	this->hijoIzq = nullptr;
	this->altura = 0;
}
