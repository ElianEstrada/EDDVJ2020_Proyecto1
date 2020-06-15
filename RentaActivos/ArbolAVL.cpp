#include "ArbolAVL.h"
#include <iostream>

using namespace std;

ArbolAVL::ArbolAVL() {
	raiz = nullptr;
}

void ArbolAVL::insertar(int numero) {

	insertar(numero, raiz);

}

void ArbolAVL::insertar(int numero, NodoAVL* &raiz) {

	if (raiz != nullptr) {

		if (numero > raiz->numero) {
			if (raiz->hijoDer != nullptr) {
				insertar(numero, raiz->hijoDer);
				if (facEquilibrio(alturaDer(raiz->hijoDer), alturaIzq(raiz->hijoIzq)) == 2) {

					if (numero > raiz->hijoDer->numero) {
						raiz = simpleIzq(raiz);
					}
					else {
						raiz = dobleIzq(raiz);
					}
				}
			}
			else {
				raiz->hijoDer = new NodoAVL(numero);
			}
		}
		else if(numero < raiz->numero){
			if (raiz->hijoIzq != nullptr) {
				insertar(numero, raiz->hijoIzq);

				if (facEquilibrio(alturaIzq(raiz->hijoIzq), alturaDer(raiz->hijoDer)) == 2) {
					if (numero < raiz->hijoIzq->numero) {
						raiz = simpleDer(raiz);
					}
					else {
						raiz = dobleDer(raiz);
					}

				}
			}
			else {
				raiz->hijoIzq = new NodoAVL(numero);
			}
		}

		int mayor = mayorHijo(alturaDer(raiz->hijoDer), alturaIzq(raiz->hijoIzq));

		raiz->altura = mayor + 1;

	}
	else {
		raiz = new NodoAVL(numero);
	}

}


void ArbolAVL::eliminar(int numero) {
	raiz = eliminar(numero, raiz);
}

NodoAVL* ArbolAVL::eliminar(int numero, NodoAVL*& raiz) {

	if (raiz != nullptr) {

		if (raiz->numero == numero) {
			if (esHoja(raiz)) {
				raiz = nullptr;
				return raiz;
			}
			else if(raiz->hijoDer == nullptr && raiz->hijoIzq != nullptr){
				return raiz->hijoIzq;
			}
			else if (raiz->hijoIzq == nullptr && raiz->hijoDer != nullptr) {
				return raiz->hijoDer;
			}
			else {
				NodoAVL* masDerecha = buscarMasDerecha(raiz->hijoIzq);

				if (masDerecha != nullptr) {
					raiz = eliminar(masDerecha->numero, raiz);
					raiz->numero = masDerecha->numero;
					if (facEquilibrio(alturaIzq(raiz->hijoIzq), alturaDer(raiz->hijoDer)) == 2) {

						/*if (numero > raiz->hijoDer->numero) {
							raiz = simpleDer(raiz);
						}
						else {
							raiz = dobleDer(raiz);
						}*/

						raiz = simpleDer(raiz);
					}
					return raiz;
				}
			}
		}
		else if(numero > raiz->numero){
			raiz->hijoDer = eliminar(numero, raiz->hijoDer);

			int mayor = mayorHijo(alturaDer(raiz->hijoDer), alturaIzq(raiz->hijoIzq));

			raiz->altura = mayor + 1;

			if (facEquilibrio(alturaIzq(raiz->hijoIzq), alturaDer(raiz->hijoDer)) == 2) {

				/*if (numero > raiz->hijoDer->numero) {
					raiz = simpleDer(raiz);
				}
				else {
					raiz = dobleDer(raiz);
				}*/

				raiz = simpleDer(raiz);
			}

			return raiz;
		}
		else {
			raiz->hijoIzq = eliminar(numero, raiz->hijoIzq);

			int mayor = mayorHijo(alturaDer(raiz->hijoDer), alturaIzq(raiz->hijoIzq));

			raiz->altura = mayor + 1;

			if (facEquilibrio(alturaDer(raiz->hijoDer), alturaIzq(raiz->hijoIzq)) == 2) {

				/*if (numero > raiz->hijoDer->numero) {
					raiz = simpleDer(raiz);
				}
				else {
					raiz = dobleDer(raiz);
				}*/

				raiz = simpleIzq(raiz);
			}

			return raiz;
		}
		
	}
	else {
		cout << "No hay nada que eliminar, arbol vacio"<<endl;
	}

}


void ArbolAVL::actualizar(int numero, int numeroNuevo) {

	actualizar(numero, numeroNuevo, raiz);

}

void ArbolAVL::actualizar(int numero, int numeroNuevo, NodoAVL* nodo) {

	if (nodo != nullptr) {

		NodoAVL* elemento = buscar(numero, raiz);

		if (elemento != nullptr) {

			if (esHoja(elemento)) {
				eliminar(elemento->numero);
				insertar(numeroNuevo);
			}
			else {
				NodoAVL* masDer = buscarMasDerecha(elemento->hijoIzq);
				NodoAVL* masIzq = buscarMasIzquierda(elemento->hijoDer);

				if (masDer->numero < numeroNuevo && numeroNuevo < masIzq->numero) {
					elemento->numero = numeroNuevo;
				}
				else if(masDer->numero > numeroNuevo){
					eliminar(numero);
					insertar(numeroNuevo);
				}
				else {
					eliminar(numero);
					insertar(numeroNuevo);
				}
			}

		}
		else {
			cout << "El número buscado [" << numero << "] no existe" << endl;
		}
	}
	else {
		cout << "No hay nada que modificar"<<endl;
	}

}


void ArbolAVL::buscar(int numero) {

	NodoAVL* busqueda = buscar(numero, raiz);
	if (busqueda != nullptr) {
		cout << "El valor [" << numero << "] encontrado fue: " << busqueda->numero << endl;
	}
	else {
		cout << "El valor[" << numero << "] buscado no existe" << endl;
	}
}

NodoAVL* ArbolAVL::buscar(int numero, NodoAVL* nodo) {

	if (nodo != nullptr) {

		if (nodo->numero == numero) {
			return nodo;
		}
		else if (numero > nodo->numero) {
			buscar(numero, nodo->hijoDer);
		}
		else {
			buscar(numero, nodo->hijoIzq);
		}

	}
	else {
		return nullptr;
	}

}

void ArbolAVL::preOrden() {

	preOrden(raiz);
	cout << endl << endl;

}


void ArbolAVL::preOrden(NodoAVL* nodo) {

	if (nodo != nullptr) {
		cout << nodo->numero << " ";
		preOrden(nodo->hijoIzq);
		preOrden(nodo->hijoDer);
	}

}


int ArbolAVL::alturaDer(NodoAVL* der) {

	if(der != nullptr)
		return der->altura;
	return -1;
}

int ArbolAVL::alturaIzq(NodoAVL* izq) {

	if(izq != nullptr)
		return izq->altura;
	return -1;
}

int ArbolAVL::mayorHijo(int a, int b) {

	return (a > b) ? a : b;

}

int ArbolAVL::facEquilibrio(int hijo1, int hijo2) {

	return hijo1 - hijo2;

}

NodoAVL* ArbolAVL::buscarMasDerecha(NodoAVL* nodo) {

	NodoAVL* aux = nodo;

	while (aux->hijoDer != nullptr) {

		aux = aux->hijoDer;
	}

	return aux;

}

NodoAVL* ArbolAVL::buscarMasIzquierda(NodoAVL* nodo) {

	NodoAVL* aux = nodo;

	while (aux->hijoIzq != nullptr) {

		aux = aux->hijoIzq;
	}

	return aux;

}

NodoAVL* ArbolAVL::simpleDer(NodoAVL* nodo) {

	NodoAVL* aux = nodo->hijoIzq;

	nodo->hijoIzq = aux->hijoDer;
	aux->hijoDer = nodo;

	nodo->altura = mayorHijo(alturaDer(nodo->hijoDer), alturaIzq(nodo->hijoIzq)) + 1; 
	aux->altura = mayorHijo(alturaDer(aux->hijoDer), alturaIzq(aux->hijoIzq)) + 1;

	return aux;
}

NodoAVL* ArbolAVL::simpleIzq(NodoAVL* nodo) {

	NodoAVL* aux = nodo->hijoDer;

	nodo->hijoDer = aux->hijoIzq;
	aux->hijoIzq = nodo;

	nodo->altura = mayorHijo(alturaDer(nodo->hijoDer), alturaIzq(nodo->hijoIzq)) + 1;
	aux->altura = mayorHijo(alturaDer(aux->hijoDer), alturaIzq(aux->hijoIzq)) + 1;

	return aux;

}

NodoAVL* ArbolAVL::dobleDer(NodoAVL* nodo) {

	nodo->hijoIzq = simpleIzq(nodo->hijoIzq);
	return simpleDer(nodo);

}

NodoAVL* ArbolAVL::dobleIzq(NodoAVL* nodo) {

	nodo->hijoDer = simpleDer(nodo->hijoDer);
	return simpleIzq(nodo);
}



bool ArbolAVL::esHoja(NodoAVL* nodo){

	if (nodo != nullptr) {
		return nodo->hijoDer == nullptr && nodo->hijoIzq == nullptr;
	}

}