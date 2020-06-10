#include "ArbolActivo.h"
#include <iostream>

using namespace std;

ArbolActivo::ArbolActivo() {
	raiz = nullptr;
}

void ArbolActivo::insertarActivo(int numero, NodoArbol* raiz) {

	NodoArbol* nuevoActivo = new NodoArbol(numero);

	if (raiz != nullptr) {
		if (nuevoActivo->getNumero() >= raiz->getNumero()) {
			if (raiz->getHijoDer() != nullptr) {
				insertarActivo(numero, raiz->getHijoDer());
			}
			else {
				raiz->setHijoDer(nuevoActivo);
			}
		}
		else {
			if (raiz->getHijoIzq() != nullptr) {
				insertarActivo(numero, raiz->getHijoIzq());
			}
			else {
				raiz->setHijoIzq(nuevoActivo);
			}
			
		}
	}
	else {
		setRaiz(nuevoActivo);
	}


}

void ArbolActivo::eliminarActivo(int numero) {

	if (raiz != nullptr) {
		if (raiz->getNumero() == numero) {
			if (esHoja(raiz)) {
				setRaiz(nullptr);
			}
			else {
				if (esHoja(raiz->getHijoIzq())) {
					NodoArbol* aux = buscarMasDerecha(raiz);

					aux->setHijoDer(raiz->getHijoDer());
					setRaiz(aux);
				}
				else {
					NodoArbol* aux = buscarMasDerecha(raiz);

					if (aux != raiz->getHijoDer() && aux != raiz->getHijoIzq()) {
						aux->setHijoDer(raiz->getHijoDer());
						aux->setHijoIzq(raiz->getHijoIzq());
						setRaiz(aux);
						aux->getHijoIzq()->setHijoDer(nullptr);
					}
					else if(aux == raiz->getHijoDer()){
						setRaiz(aux);
						raiz->setHijoDer(nullptr);
					}
					else {
						setRaiz(aux);
						raiz->setHijoIzq(nullptr);
					}
				}
			}
		}
		else if (numero > raiz->getNumero()) {
			
			eliminarActivo(numero, raiz, raiz->getHijoDer(), true); //a la Derecha
		}
		else {
			eliminarActivo(numero, raiz, raiz->getHijoIzq(), false); // a la izquierda
		}
	}
	else {
		cout << "No hay elementos para eliminar" << endl;
	}

}

void ArbolActivo::eliminarActivo(int numero, NodoArbol* padre, NodoArbol* hijo, bool bandera) {


	if (hijo != nullptr) {
		if (hijo->getNumero() == numero) {
			if (esHoja(hijo)) {
				if (bandera) {
					padre->setHijoDer(nullptr);
				}
				else {
					padre->setHijoIzq(nullptr);
				}
			}
			else {
				NodoArbol* aux = buscarMasDerecha(hijo);

				if (bandera) {
					padre->setHijoDer(aux);
					aux->setHijoDer(hijo->getHijoDer());

					NodoArbol* aux2 = hijo->getHijoIzq();

					if (aux2->getNumero() != aux->getNumero()) {
						aux->setHijoIzq(hijo->getHijoIzq());
						aux->getHijoIzq()->setHijoDer(nullptr);
					}
					else {
						hijo->setHijoIzq(nullptr);
						aux->setHijoIzq(hijo->getHijoIzq());
					}
					
					
					
				}
				else {
					padre->setHijoIzq(aux);
					aux->setHijoDer(hijo->getHijoDer());
				}

			}
		}
		else {
			if (numero > hijo->getNumero()) {
				eliminarActivo(numero, hijo, hijo->getHijoDer(), true); //a la Derecha
			}
			else {
				eliminarActivo(numero, hijo, hijo->getHijoIzq(), false); //a la Izquierda
			}
		}
	}

}


bool ArbolActivo::esHoja(NodoArbol* nodo) {

	if (nodo != nullptr) {
		return nodo->getHijoDer() == nullptr && nodo->getHijoIzq() == nullptr;
	}

	return false;

}


NodoArbol* ArbolActivo::buscarMasDerecha(NodoArbol* raiz) {

	if (raiz->getHijoIzq() != nullptr) {
		if (esHoja(raiz->getHijoIzq()))
		{
			return raiz->getHijoIzq();
		}
		else {
			NodoArbol* aux = raiz->getHijoIzq();

			while (aux->getHijoDer() != nullptr) {

				aux = aux->getHijoDer();
			}

			return aux;
		}
	}
	else {
		return raiz->getHijoDer();
	}

}

void ArbolActivo::setRaiz(NodoArbol* raiz) {
	this->raiz = raiz;
}

NodoArbol* ArbolActivo::getRaiz() {
	return raiz;
}
