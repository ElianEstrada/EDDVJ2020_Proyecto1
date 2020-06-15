#include "MatrizDispersa.h"


MatrizDispersa::MatrizDispersa() {
	ini = new NodoMatriz("admin");
}

NodoMatriz* MatrizDispersa::insertarCabHorizontal(string departamento) {

	NodoMatriz* nuevaCab = new NodoMatriz(departamento);

	NodoMatriz* aux = ini;

	while (aux->getSig() != nullptr)
	{
		aux = aux->getSig();
	}

	aux->setSig(nuevaCab);
	nuevaCab->setAnt(aux);

	return nuevaCab;
}


NodoMatriz* MatrizDispersa::insertarCabVertical(string empresa) {
	
	NodoMatriz* nuevaCab = new NodoMatriz(empresa);

	NodoMatriz* aux = ini;

	while (aux->getAbajo() != nullptr) {

		aux = aux->getAbajo();
	}

	aux->setAbajo(nuevaCab);
	nuevaCab->setArriba(aux);

	return nuevaCab;
}

void MatrizDispersa::insertarUsuario(Usuario* usuario, string departamento, string empresa) {

	NodoMatriz* cabezaDep = buscarDepartamento(departamento);
	NodoMatriz* cabezaEmp = buscarEmpresa(empresa);


	if (cabezaDep == nullptr || cabezaEmp == nullptr) {

		if (cabezaDep == nullptr) {
			cabezaDep = insertarCabHorizontal(departamento);
		}
		if(cabezaEmp == nullptr) {
			cabezaEmp = insertarCabVertical(empresa);
		}

		insertarAlFinal(usuario, cabezaDep, cabezaEmp);

	}
	else if(cabezaDep->getSig() == nullptr || cabezaEmp->getAbajo() == nullptr){

		if (cabezaDep->getSig() == nullptr && cabezaEmp->getAbajo() == nullptr) {

			insertarAlFinal(usuario, cabezaDep, cabezaEmp);

		}
		else if (cabezaDep->getSig() == nullptr) {

		}
		else {

		}

	}

}

void MatrizDispersa::insertarAlFinal(Usuario* usuario, NodoMatriz* cabeceraH, NodoMatriz* cabeceraV) {

	NodoMatriz* nuevoUsuario = new NodoMatriz(usuario);

	NodoMatriz* auxH = cabeceraH;
	NodoMatriz* auxV = cabeceraV;

	while (auxH->getAbajo() != nullptr) {

		auxH = auxH->getAbajo();
	}

	auxH->setAbajo(nuevoUsuario);
	nuevoUsuario->setArriba(auxH);

	while (auxV->getSig() != nullptr) {

		auxV = auxV->getSig();
	}

	auxV->setSig(nuevoUsuario);
	nuevoUsuario->setAnt(auxV);

}


void MatrizDispersa::insertarAlFinalEmp(Usuario* usuario, NodoMatriz* cabeceraV) {

	NodoMatriz* nuevoUsuario = new NodoMatriz(usuario);

	NodoMatriz* auxV = cabeceraV;

	while (auxV->getSig() != nullptr) {

		auxV = auxV->getSig();
	}

	auxV->setSig(nuevoUsuario);
	nuevoUsuario->setAnt(auxV);

}


NodoMatriz* MatrizDispersa::buscarDepartamento(string departamento) {

	NodoMatriz* aux = ini;

	while (aux->getSig() != nullptr) {
		if (aux->getSig()->getCabecera() == departamento) {
			return aux->getSig();
		}

		aux = aux->getSig();
	}

	return nullptr;

}

NodoMatriz* MatrizDispersa::buscarEmpresa(string empresa) {

	NodoMatriz* aux = ini;

	while (aux->getAbajo() != nullptr) {

		if (aux->getAbajo()->getCabecera() == empresa) {
			return aux->getAbajo();
		}

		aux = aux->getAbajo();
	}

	return nullptr;
}