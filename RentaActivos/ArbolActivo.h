#pragma once
#include "NodoArbol.h"

class ArbolActivo
{

	NodoArbol* raiz = nullptr;

public:
	ArbolActivo();
	void insertarActivo(int numero, NodoArbol* raiz);
	void eliminarActivo(int numero);
	void eliminarActivo(int numero, NodoArbol* padre, NodoArbol* hijo, bool bandera);
	NodoArbol* buscarMasDerecha(NodoArbol* raiz);
	bool esHoja(NodoArbol* nodo);

	void setRaiz(NodoArbol* raiz);
	NodoArbol* getRaiz();
};

