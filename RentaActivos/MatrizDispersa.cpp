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
		if (cabezaEmp == nullptr) {
			cabezaEmp = insertarCabVertical(empresa);
		}

		insertarAlFinal(usuario, cabezaDep, cabezaEmp);

	}
	else if (cabezaDep->getSig() == nullptr || cabezaEmp->getAbajo() == nullptr) {

		NodoMatriz* usuarioActual = existe(cabezaDep, empresa);

		if (cabezaDep->getSig() == nullptr && cabezaEmp->getAbajo() == nullptr) {

			if (existeNombre(usuarioActual, usuario->getNombre())) {
				if (usuarioActual != nullptr) {
					insertarAtras(usuario, usuarioActual);
				}
				else {
					insertarAlFinal(usuario, cabezaDep, cabezaEmp);
				}
			}
			else {
				cout << "No se permiten nombres repetidos en el mismo luegar" << endl;
			}

		}
		else if (cabezaDep->getSig() == nullptr) {

			if (existeNombre(usuarioActual, usuario->getNombre())) {
				if (usuarioActual != nullptr) {
					insertarAtras(usuario, usuarioActual);
				}
				else {
					insertarAlFinalEmp(usuario, cabezaEmp, departamento);
				}
			}
			else {
				cout << "No se permiten nombres repetidos en el mismo luegar" << endl;
			}

		}
		else {

			if (existeNombre(usuarioActual, usuario->getNombre())) {
				if (usuarioActual != nullptr) {
					insertarAtras(usuario, usuarioActual);
				}
				else {
					insertarAlFinalDep(usuario, cabezaDep, empresa);
				}
			}
			else {
				cout << "No se permiten nombres repetidos en el mismo luegar" << endl;
			}

		}

	}
	else {

		NodoMatriz* usuarioActual = existe(cabezaDep, empresa);

		if (existeNombre(usuarioActual, usuario->getNombre())) {
			if (usuarioActual != nullptr) {
				insertarAtras(usuario, usuarioActual);
			}
			else {
				insertarEnmedio(usuario, cabezaDep, cabezaEmp);
			}
		}
		else {
			cout << "No se permiten nombres repetidos en el mismo luegar" << endl;
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


void MatrizDispersa::insertarAlFinalEmp(Usuario* usuario, NodoMatriz* cabeceraV, string departamento) {

	NodoMatriz* nuevoUsuario = new NodoMatriz(usuario);

	NodoMatriz* auxV = cabeceraV;

	while (auxV->getSig() != nullptr) {

		auxV = auxV->getSig();
	}

	auxV->setSig(nuevoUsuario);
	nuevoUsuario->setAnt(auxV);

	NodoMatriz* userAbajo = buscarUsuarioAbajo(cabeceraV->getSig(), departamento);

	if (userAbajo != nullptr) {
		insertarAlMedio(nuevoUsuario, userAbajo, true);
	}
	else {

		NodoMatriz* auxH = ini;

		while (auxH->getSig() != nullptr) {

			auxH = auxH->getSig();
		}


		while (auxH->getAbajo() != nullptr) {

			auxH = auxH->getAbajo();
		}

		auxH->setAbajo(nuevoUsuario);
		nuevoUsuario->setArriba(auxH);

	}
	

}

void MatrizDispersa::insertarAlFinalDep(Usuario* usuario, NodoMatriz* cabeceraH, string empresa) {

	NodoMatriz* nuevoUsuario = new NodoMatriz(usuario);

	NodoMatriz* aux = cabeceraH;

	while (aux->getAbajo() != nullptr) {

		aux = aux->getAbajo();
	}

	aux->setAbajo(nuevoUsuario);
	nuevoUsuario->setArriba(aux);

	NodoMatriz* userSig = buscarUsuarioSig(cabeceraH->getSig(), empresa);
	if (userSig != nullptr) {
		insertarAlMedio(nuevoUsuario, userSig, false);
	}
	else {

		NodoMatriz* auxV = ini;

		while (auxV->getAbajo() != nullptr) {

			auxV = auxV->getAbajo();
		}

		while (auxV->getSig() != nullptr) {

			auxV = auxV->getSig();
		}

		auxV->setSig(nuevoUsuario);
		nuevoUsuario->setAnt(auxV);

	}
	

}


void MatrizDispersa::insertarEnmedio(Usuario* usuario, NodoMatriz* cabeceraH, NodoMatriz* cabeceraV) {

	NodoMatriz* nuevoUsuario = new NodoMatriz(usuario);

	NodoMatriz* auxV = cabeceraV;
	NodoMatriz* auxH = cabeceraH;

	while (auxH->getAbajo() != nullptr && !estaAbajo(buscarCabeceraV(auxH), cabeceraV->getCabecera())) {
		
		auxH = auxH->getAbajo();
	}

	if (estaAbajo(buscarCabeceraV(auxH), cabeceraV->getCabecera())) {

		insertarAlMedio(nuevoUsuario, auxH, true);

	}
	else {

		auxH->setAbajo(nuevoUsuario);
		nuevoUsuario->setArriba(auxH);

	}


	while (auxV->getSig() != nullptr && !estaIzquierda(buscarCabeceraH(auxV), cabeceraH->getCabecera())) {

		auxV = auxV->getSig();
	}

	if (estaIzquierda(buscarCabeceraH(auxV), cabeceraH->getCabecera())) {
		insertarAlMedio(nuevoUsuario, auxV, false);
	}
	else {

		auxV->setSig(nuevoUsuario);
		nuevoUsuario->setAnt(auxV);

	}

}


void MatrizDispersa::insertarAlMedio(NodoMatriz* nuevoUsuario, NodoMatriz* abajo, bool bandera) {

	if (bandera) {
		abajo->getArriba()->setAbajo(nuevoUsuario);
		nuevoUsuario->setArriba(abajo->getArriba());
		nuevoUsuario->setAbajo(abajo);
		abajo->setArriba(nuevoUsuario);
	}
	else {
		abajo->getAnt()->setSig(nuevoUsuario);
		nuevoUsuario->setAnt(abajo->getAnt());
		nuevoUsuario->setSig(abajo);
		abajo->setAnt(nuevoUsuario);
	}

}


void MatrizDispersa::insertarAtras(Usuario* nuevoUsuario, NodoMatriz* usuarioActual) {

	NodoMatriz* nuevo = new NodoMatriz(nuevoUsuario);

	NodoMatriz* aux = usuarioActual;

	while (aux->getAtras() != nullptr) {

		aux = aux->getAtras();
	}

	aux->setAtras(nuevo);
	nuevo->setDelante(aux);

}

NodoMatriz* MatrizDispersa::buscarCabeceraV(NodoMatriz* usuarioActual) {

	NodoMatriz* aux = usuarioActual;

	while (aux->getAnt() != nullptr) {

		aux = aux->getAnt();
	}

	return aux;

}

NodoMatriz* MatrizDispersa::buscarUsuarioAbajo(NodoMatriz* nodo, string dep) {

	NodoMatriz* aux = nodo;

	if (aux != nullptr) {
		while (aux->getSig() != nullptr) {

			aux = aux->getSig();
		}

		if (dep == buscarCabeceraH(aux)->getCabecera()) {
			return aux;
		}
		else {
			return buscarUsuarioAbajo(nodo->getAbajo(), dep);
		}
	}
	else {
		return nullptr;
	}

}

NodoMatriz* MatrizDispersa::buscarCabeceraH(NodoMatriz* usuarioActual) {

	NodoMatriz* aux = usuarioActual;

	while (aux->getArriba() != nullptr) {

		aux = aux->getArriba();
	}

	return aux;

}

NodoMatriz* MatrizDispersa::buscarUsuarioSig(NodoMatriz* nodo, string emp) {

	NodoMatriz* aux = nodo;

	if (aux != nullptr) {
		while (aux->getAbajo() != nullptr) {

			aux = aux->getAbajo();
		}

		if (emp == buscarCabeceraV(aux)->getCabecera()) {
			return aux;
		}
		else {
			return buscarUsuarioSig(nodo->getSig(), emp);
		}
	}
	else {
		return nullptr;
	}

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

NodoMatriz* MatrizDispersa::existe(NodoMatriz* cabezaH, string empresa) {

	NodoMatriz* aux = cabezaH;

	while (aux->getAbajo() != nullptr) {

		if (empresa == buscarCabeceraV(aux->getAbajo())->getCabecera()) {
			return aux->getAbajo();
		}

		aux = aux->getAbajo();
		
	}

	return nullptr;

}

bool MatrizDispersa::existeNombre(NodoMatriz* usuarios, string nombre) {

	NodoMatriz* aux = usuarios;

	if (aux != nullptr) {
		while (aux != nullptr) {

			if (aux->getUsuario()->getNombre() == nombre) {
				return false;
			}

			aux = aux->getAtras();
		}
	}

	return true;

}


bool MatrizDispersa::estaAbajo(NodoMatriz* nodo, string empresa) {

	NodoMatriz* aux = nodo;

	while (aux->getCabecera() != empresa && aux->getArriba() != nullptr) {

		aux = aux->getArriba();
	}

	if (aux->getArriba() == nullptr) {
		return false;
	}
	return true;

}


bool MatrizDispersa::estaIzquierda(NodoMatriz* nodo, string departamento) {

	NodoMatriz* aux = nodo;

	while (aux->getCabecera() != departamento && aux->getAnt() != nullptr) {

		aux = aux->getAnt();
	}

	if (aux->getAnt() == nullptr) {
		return false;
	}
	else {
		return true;
	}
}