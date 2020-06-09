#include "MatrizDispersa.h"


MatrizDispersa::MatrizDispersa() {
	ini = new NodoMatriz("admin");
}

void MatrizDispersa::insertarCabHorizontal(string departamento) {

	NodoMatriz* nuevaCab = new NodoMatriz(departamento);

	NodoMatriz* aux = ini;

	while (aux->getSig() != nullptr)
	{
		aux = aux->getSig();
	}

	aux->setSig(nuevaCab);
	nuevaCab->setAnt(aux);
}


void MatrizDispersa::insertarCabVertical(string empresa) {
	
	NodoMatriz* nuevaCab = new NodoMatriz(empresa);

	NodoMatriz* aux = ini;

	while (aux->getAbajo() != nullptr) {

		aux = aux->getAbajo();
	}

	aux->setAbajo(nuevaCab);
	nuevaCab->setArriba(aux);

}