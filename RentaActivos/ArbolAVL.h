#pragma once
#include "NodoAVL.h"

class ArbolAVL
{

public:
	NodoAVL* raiz;
	ArbolAVL();

	void insertar(int numero);
	void insertar(int numero, NodoAVL* &raiz);
	void eliminar(int numero);
	NodoAVL* eliminar(int numero, NodoAVL* &raiz);
	NodoAVL* buscarMasDerecha(NodoAVL* nodo);
	NodoAVL* buscarMasIzquierda(NodoAVL* nodo);
	void actualizar(int numero, int numeroNuevo);
	void actualizar(int numero, int numeroNuevo, NodoAVL* nodo);
	NodoAVL* buscar(int numero, NodoAVL* nodo);
	void buscar(int numero);

	bool esHoja(NodoAVL* nodo);
	NodoAVL* simpleIzq(NodoAVL* nodo);
	NodoAVL* simpleDer(NodoAVL* nodo);
	NodoAVL* dobleDer(NodoAVL* nodo);
	NodoAVL* dobleIzq(NodoAVL* nodo);

	void preOrden();
	void preOrden(NodoAVL* nodo);

	int alturaDer(NodoAVL* der);
	int alturaIzq(NodoAVL* izq);

	int mayorHijo(int a, int b);

	int facEquilibrio(int hijo1, int hijo2);

};

