#include "MatrizDispersa.h"
#include <fstream>


MatrizDispersa::MatrizDispersa() {
	ini = new NodoMatriz("admin");
}


//Metodo poara crear la Cabecera Horizontal si esta no existiera
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


//Método para crear la Cabecera Vertial si esta no existiera
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


//Método general para insertar un usuario
void MatrizDispersa::insertarUsuario(Usuario* usuario, string departamento, string empresa) {

	//vemos si éxisten las cabeceras
	NodoMatriz* cabezaDep = buscarDepartamento(departamento);
	NodoMatriz* cabezaEmp = buscarEmpresa(empresa);



	//si ambas son nulas (es decir que no exisiten)
	if (cabezaDep == nullptr || cabezaEmp == nullptr) {

		//si la Horizontal no existe la creamos
		if (cabezaDep == nullptr) {
			cabezaDep = insertarCabHorizontal(departamento);
		}

		//si la Vertial no existe la creamos
		if (cabezaEmp == nullptr) {
			cabezaEmp = insertarCabVertical(empresa);
		}

		//Insertamos a final de ambas listas.
		insertarAlFinal(usuario, cabezaDep, cabezaEmp);

	}

	//Si los siguientes de las cabeceras son nulos (es decir son los ultimos de sus listas respecitvas
	else if (cabezaDep->getSig() == nullptr || cabezaEmp->getAbajo() == nullptr) {

		//verfíficamos si ya existe un usuario en esta posición
		NodoMatriz* usuarioActual = existe(cabezaDep, empresa);

		//si ambos son nulos es decir ambos son los últimos de sus listas
		if (cabezaDep->getSig() == nullptr && cabezaEmp->getAbajo() == nullptr) {

			//verificamos que el nombre no se repita
			if (existeNombre(usuarioActual, usuario->getNombre())) {

				//si existe un usuario en esa posición
				if (usuarioActual != nullptr) {
					//insertamos atras de dicho usuario
					insertarAtras(usuario, usuarioActual);
				}
				else {
					//Si no insertamos al final de cada lista respecitivamente
					insertarAlFinal(usuario, cabezaDep, cabezaEmp);
				}
			}
			else {
				cout << "\nNo se permiten nombres repetidos en el mismo luegar...";
				cin.ignore();
			}

		}

		//si solamente la cabecera Horizontal es la última
		else if (cabezaDep->getSig() == nullptr) {

			//verificamos que no exista el nombre
			if (existeNombre(usuarioActual, usuario->getNombre())) {

				//si existe un usuario en esa posición
				if (usuarioActual != nullptr) {
					//insertamos atras de ese usuario.
					insertarAtras(usuario, usuarioActual);
				}
				else {
					//Insertamos al Final de la lista de Empresas
					insertarAlFinalEmp(usuario, cabezaEmp, departamento);
				}
			}
			else {
				cout << "\nNo se permiten nombres repetidos en el mismo luegar...";
				cin.ignore();
			}

		}
		else {

			//Si solamente la Cabecera Vertial es la ultima

			//Verifico que no se repita el nombre
			if (existeNombre(usuarioActual, usuario->getNombre())) {

				//si existe un usuario en esa posición
				if (usuarioActual != nullptr) {
					//inserto atras de ese nodo;
					insertarAtras(usuario, usuarioActual);
				}
				else {
					//inserto al final de la lista de departamentos.
					insertarAlFinalDep(usuario, cabezaDep, empresa);
				}
			}
			else {
				cout << "\nNo se permiten nombres repetidos en el mismo luegar...";
				cin.ignore();
			}

		}

	}
	else {

		//Si son cabeceras que estan rodeadas por otras

		//Vemos si ya hay un usuario en esa posición
		NodoMatriz* usuarioActual = existe(cabezaDep, empresa);

		//verificamos que no exista el nombre
		if (existeNombre(usuarioActual, usuario->getNombre())) {

			//si ya existe un usuario en esa posición
			if (usuarioActual != nullptr) {
				//insertamos atras de dicho usuario.
				insertarAtras(usuario, usuarioActual);
			}
			else {
				//insetamos Enmedio
				insertarEnmedio(usuario, cabezaDep, cabezaEmp);
			}
		}
		else {
			cout << "\nNo se permiten nombres repetidos en el mismo luegar...";
			cin.ignore();
		}

	}

}


//Metodo para insetar al Final de ambas listas
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


//Metodo para insetar al Final de la lista Empresa
void MatrizDispersa::insertarAlFinalEmp(Usuario* usuario, NodoMatriz* cabeceraV, string departamento) {

	NodoMatriz* nuevoUsuario = new NodoMatriz(usuario);

	NodoMatriz* auxV = cabeceraV;


	//Insertamos al final de la lista de Empresa
	while (auxV->getSig() != nullptr) {

		auxV = auxV->getSig();
	}

	auxV->setSig(nuevoUsuario);
	nuevoUsuario->setAnt(auxV);


	//Veríficamos si el nodo que ingresamos se deberá ingrasar al medio en Departamentos o al Final
	NodoMatriz* userAbajo = buscarUsuarioAbajo(cabeceraV->getAbajo(), departamento);

	//Si hay un elemento debajo de donde tendría que ir nuestro nodo
	if (userAbajo != nullptr) {
		//insertamos al Medio de ese nodo que esta abajo.
		insertarAlMedio(nuevoUsuario, userAbajo, true);
	}
	else {

		NodoMatriz* auxH = ini;

		//Insertamos al Final de la lista Departamento.
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


//Metodo para insetar al final de la lista departamento
void MatrizDispersa::insertarAlFinalDep(Usuario* usuario, NodoMatriz* cabeceraH, string empresa) {

	NodoMatriz* nuevoUsuario = new NodoMatriz(usuario);

	NodoMatriz* aux = cabeceraH;

	//insertamos al final de la ista departamento
	while (aux->getAbajo() != nullptr) {

		aux = aux->getAbajo();
	}

	aux->setAbajo(nuevoUsuario);
	nuevoUsuario->setArriba(aux);

	//Vemos si hay algún usuario que esta a la derecha de donde devería ir nuesto nuevo usuario
	NodoMatriz* userSig = buscarUsuarioSig(cabeceraH->getSig(), empresa);

	//si existe tal usuario
	if (userSig != nullptr) {
		//insertamos al medio de ese nodo que esta a la derecha
		insertarAlMedio(nuevoUsuario, userSig, false);
	}
	else {

		NodoMatriz* auxV = ini;

		//Ingresamos al Final de la lista Empresa
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


//Metodo para saber en donde insertar el nuevo Usuario.
void MatrizDispersa::insertarEnmedio(Usuario* usuario, NodoMatriz* cabeceraH, NodoMatriz* cabeceraV) {

	NodoMatriz* nuevoUsuario = new NodoMatriz(usuario);

	NodoMatriz* auxV = cabeceraV;
	NodoMatriz* auxH = cabeceraH;

	//verifica las cabeceras de cada usuario para saber arriba de quien insertar el nuevo usuario.
	while (auxH->getAbajo() != nullptr && !estaAbajo(buscarCabeceraV(auxH), cabeceraV->getCabecera())) {
		
		auxH = auxH->getAbajo();
	}

	//aqui vemos si se iserta al medio o simplemente al final.
	if (estaAbajo(buscarCabeceraV(auxH), cabeceraV->getCabecera())) {

		insertarAlMedio(nuevoUsuario, auxH, true);

	}
	else {

		auxH->setAbajo(nuevoUsuario);
		nuevoUsuario->setArriba(auxH);

	}

	//verificiar las cabeceras de cada usuario para saber antes de quien insertar el nuveo usuario
	while (auxV->getSig() != nullptr && !estaIzquierda(buscarCabeceraH(auxV), cabeceraH->getCabecera())) {

		auxV = auxV->getSig();
	}

	//aqui vemos si se inserta al medio o simplemente al final
	if (estaIzquierda(buscarCabeceraH(auxV), cabeceraH->getCabecera())) {
		insertarAlMedio(nuevoUsuario, auxV, false);
	}
	else {

		auxV->setSig(nuevoUsuario);
		nuevoUsuario->setAnt(auxV);

	}

}


//Metodo para insertar al Medio
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


//Metodo para insertar atras de un usuario que ya este en una posición.
void MatrizDispersa::insertarAtras(Usuario* nuevoUsuario, NodoMatriz* usuarioActual) {

	NodoMatriz* nuevo = new NodoMatriz(nuevoUsuario);

	NodoMatriz* aux = usuarioActual;

	while (aux->getAtras() != nullptr) {

		aux = aux->getAtras();
	}

	aux->setAtras(nuevo);
	nuevo->setDelante(aux);

}


//Metodo para obetener las cabeceras Vertiales de un usuario.
NodoMatriz* MatrizDispersa::buscarCabeceraV(NodoMatriz* usuarioActual) {

	NodoMatriz* aux = usuarioActual;

	while (aux->getAnt() != nullptr) {

		aux = aux->getAnt();
	}

	return aux;

}

//Metodo para saber que usario esta debajo de donde se debe insertar el nuevo usuario
NodoMatriz* MatrizDispersa::buscarUsuarioAbajo(NodoMatriz* nodo, string dep) {

	NodoMatriz* aux = nodo;

	if (aux != nullptr) {

		//recorremos la lista de de usuarios en una Empresa
		while (aux->getSig() != nullptr) {

			aux = aux->getSig();
		}

		//vemos si la cabecera del ultimo usuario es igual al departamenteo en donde vamos a insertar
		if (dep == buscarCabeceraH(aux)->getCabecera()) {
			return aux;
		}
		else {
			//volvemos a llamar a la función con la empresa siguiente
			return buscarUsuarioAbajo(nodo->getAbajo(), dep);
		}
	}
	else {
		return nullptr;
	}

}


//Metodo que devuleve la cabecera de un usuario
NodoMatriz* MatrizDispersa::buscarCabeceraH(NodoMatriz* usuarioActual) {

	NodoMatriz* aux = usuarioActual;

	while (aux->getArriba() != nullptr) {

		aux = aux->getArriba();
	}

	return aux;

}


//Metodo para saber que usario esta a la derecha de donde se debe insertar el nuevo usuario
NodoMatriz* MatrizDispersa::buscarUsuarioSig(NodoMatriz* nodo, string emp) {

	NodoMatriz* aux = nodo;

	if (aux != nullptr) {

		//recorremos la lista de de usuarios en un Departamento
		while (aux->getAbajo() != nullptr) {

			aux = aux->getAbajo();
		}
		//vemos si la cabecera del ultimo usuario es igual a la empresa en donde vamos a insertar
		if (emp == buscarCabeceraV(aux)->getCabecera()) {
			return aux;
		}
		else {
			//volvemos a llamar a la función con el departamento siguiente
			return buscarUsuarioSig(nodo->getSig(), emp);
		}
	}
	else {
		return nullptr;
	}

}


NodoMatriz* MatrizDispersa::buscarUsuarioCabeza(NodoMatriz* usuarioActual) {

	NodoMatriz* aux = usuarioActual;

	while (aux->getDelante() != nullptr && aux != nullptr) {
		
		aux = aux->getDelante();

	}

	return aux;
}


//Metodo para ver si ya existe un departamento
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

//Metodo para ver si ya existe una empresa
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


//Metodo para ver si ya existe un usuario en una posición
NodoMatriz* MatrizDispersa::existe(NodoMatriz* cabezaH, string empresa) {

	NodoMatriz* aux = cabezaH;

	//Recorremos la lista de usuarios de un departamento
	if (aux != nullptr) {
		while (aux->getAbajo() != nullptr) {

			//vemos si el nombre de la empresa coincide con el nombre de la cabecera de ese usuario
			if (empresa == buscarCabeceraV(aux->getAbajo())->getCabecera()) {
				return aux->getAbajo();
			}

			aux = aux->getAbajo();

		}
	}

	return nullptr;

}

//Metodo para ver si ya existe un nombre en el mismo lugar.
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


//Metodo para saber si un nodo esta abajo del que deseamos insertar
bool MatrizDispersa::estaAbajo(NodoMatriz* nodo, string empresa) {

	NodoMatriz* aux = nodo;

	//mietras el encabezado no sea igual que la empresa buscada y no se llegue al primero
	while (aux->getCabecera() != empresa && aux->getArriba() != nullptr) {

		aux = aux->getArriba();
	}

	if (aux->getArriba() == nullptr) {
		return false;
	}
	return true;

}


//Metodo para saber si un nodo esta a la izquierda de donde queremos ingresar el usuario
bool MatrizDispersa::estaIzquierda(NodoMatriz* nodo, string departamento) {

	NodoMatriz* aux = nodo;

	//mietras la cabecera horizontal sea diferente al departamento y no se llegue al primero
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


//Metodo para mostrar todos los activos disponibles
NodoAVL* MatrizDispersa::catalogoActivos(Usuario* usuario, bool bandera, string id) {

	if (ini->getAbajo() != nullptr) {
		return catalogoActivos(usuario, ini->getAbajo(), bandera, id);
	}

}

NodoAVL* MatrizDispersa::catalogoActivos(Usuario* usuario, NodoMatriz* comienzo, bool bandera, string id) {

	NodoMatriz* aux = comienzo;
	NodoMatriz* aux2;

	if (aux != nullptr) {
		while (aux->getSig() != nullptr) {

			aux = aux->getSig();
			aux2 = aux;
			do {

				if (aux2->getUsuario() != usuario) {
					if (bandera) {
						aux2->getUsuario()->getArbol()->preOrden(true);
					}
					else {
						NodoAVL* activoRentado = aux2->getUsuario()->getArbol()->buscar(id, aux2->getUsuario()->getArbol()->raiz);

						if (activoRentado != nullptr) {
							return activoRentado;
						}
					}
				}

				aux2 = aux2->getAtras();

			} while (aux2 != nullptr);

		}

		return catalogoActivos(usuario, comienzo->getAbajo(), bandera, id);
	}

}


void MatrizDispersa::reporteActivosEmpresa(string empresa) {

	string dot = "digraph{ \nrankdir = TB;node[shape = box, color = red]\n" + empresa + "\n";

	NodoMatriz* nodoEmpresa = buscarEmpresa(empresa);
	NodoMatriz* aux = nodoEmpresa->getSig();
	NodoMatriz* aux2;

	while (aux != nullptr) {

		aux2 = aux;

		while (aux2 != nullptr) {

			dot += "node[shape = box];\n " + aux2->getUsuario()->getUsuario() +";\n node[shape = circle]; \n";
			dot += aux2->getUsuario()->getArbol()->activosUsuarioPre(aux2->getUsuario()->getArbol()->raiz, dot);

			aux2 = aux2->getAtras();
		}

		aux = aux->getSig();
	}

	dot += "\n}";


	ofstream file;
	file.open("../Graficas/reporteActivosEmpresa.txt");
	if (file.is_open()) {
		file << dot;
		file.close();
	}
	
	system("dot -Tpng ../Graficas/reporteActivosEmpresa.txt -o ../Graficas/reporteActivosEmpresa.png");

}

void MatrizDispersa::reporteActivosDepartamento(string departamento) {

	string dot = "digraph{ \nrankdir = TB;\nnode[shape = box, color = red]\n" + departamento +"\n";

	NodoMatriz* nodoDepartamento = buscarDepartamento(departamento);
	NodoMatriz* aux = nodoDepartamento->getAbajo();
	NodoMatriz* aux2;

	while (aux != nullptr) {

		aux2 = aux;

		while (aux2 != nullptr) {

			dot += "node[shape = box];\n " + aux2->getUsuario()->getUsuario() + ";\n node[shape = circle]; \n";
			dot += aux2->getUsuario()->getArbol()->activosUsuarioPre(aux2->getUsuario()->getArbol()->raiz, dot);

			aux2 = aux2->getAtras();
		}

		aux = aux->getAbajo();
	}

	dot += "\n}";


	ofstream file;
	file.open("../Graficas/reporteActivosDepartamento.txt");
	if (file.is_open()) {
		file << dot;
		file.close();
	}

	system("dot -Tpng ../Graficas/reporteActivosDepartamento.txt -o ../Graficas/reporteActivosDepartamento.png");

}


void MatrizDispersa::reporteMatrizDispersa() {

	NodoMatriz* aux = ini;
	NodoMatriz* aux2 = nullptr;

	string dot = "digraph G{\n{node[shape = box, group = a];\n";

	//Recorriendo Cabeceras Verticales
	while (aux != nullptr) {

		dot += "\"" + aux->getCabecera() + "\" ->";

		aux2 = aux;
		aux = aux->getAbajo();
	}
	
	aux = aux2->getArriba();

	while (aux != nullptr) {

		if (aux != ini) {

			dot += "\"" + aux->getCabecera() + "\" ->";
		}
		else {

			dot += "\"" + aux->getCabecera() + "\"\n}";
			break;
		}

		aux = aux->getArriba();
	}

	dot += "\n{\nrank=same;\nnode[shape = box, group = true];\n";

	//Recorrer para las cabeceras Horizontales
	while (aux != nullptr) {

		dot += "\"" + aux->getCabecera() + "\" ->";

		aux2 = aux;
		aux = aux->getSig();
	}

	aux = aux2->getAnt();

	while (aux != nullptr) {

		if (aux != ini) {

			dot += "\"" + aux->getCabecera() + "\" ->";
		}
		else {

			dot += "\"" + aux->getCabecera() + "\"\n}";
			break;
		}

		aux = aux->getAnt();
	}


	dot += "\nnode[shape = box, group = true];\n";

	//Recorrer las Filas de la Matriz
	NodoMatriz* aux3 = ini->getAbajo();
	aux = aux3;
	while (aux != nullptr) {

		if (aux->getAbajo() != nullptr) {
			dot += "{rank=same;";
		}
		else {
			dot += "{rank=max;";
		}
		while (aux != nullptr) {

			if (aux->getUsuario() != nullptr) {
				dot += "\"" + aux->getUsuario()->getUsuario() + "\" ->";
			}
			else {
				dot += "\"" + aux->getCabecera() + "\" ->";
			}

			aux2 = aux;
			aux = aux->getSig();
		}

		aux = aux2->getAnt();

		while (aux != nullptr) {

			if (aux != aux3) {

				if (aux->getUsuario() != nullptr) {
					dot += "\"" + aux->getUsuario()->getUsuario() + "\" ->";
				}
				else {
					dot += "\"" + aux->getCabecera() + "\" ->";
				}
			}
			else {

				dot += "\"" + aux->getCabecera() + "\"}\n";
				break;
			}

			aux = aux->getAnt();
		}

		aux = aux->getAbajo();
		aux3 = aux3->getAbajo();
	}


	//Recorrer Columnas de la Matriz
	aux3 = ini->getSig();
	aux = aux3;

	while (aux != nullptr) {

		while (aux != nullptr) {

			if (aux->getUsuario() != nullptr) {
				dot += "\"" + aux->getUsuario()->getUsuario() + "\" ->";
			}
			else {
				dot += "\"" + aux->getCabecera() + "\" ->";
			}

			aux2 = aux;
			aux = aux->getAbajo();
		}

		aux = aux2->getArriba();

		while (aux != nullptr) {

			if (aux != aux3) {

				if (aux->getUsuario() != nullptr) {
					dot += "\"" + aux->getUsuario()->getUsuario() + "\" ->";
				}
				else {
					dot += "\"" + aux->getCabecera() + "\" ->";
				}
			}
			else {

				dot += "\"" + aux->getCabecera() + "\"\n";
				break;
			}

			aux = aux->getArriba();
		}

		aux = aux->getSig();
		aux3 = aux3->getSig();
	}



	dot += "\n}";

	ofstream file;
	file.open("../Graficas/reporteMatrizDispersa.txt");

	if (file.is_open()) {
		file << dot;
		file.close();
	}

	system("dot -Tpng ../Graficas/reporteMatrizDispersa.txt -o ../Graficas/reporteMatrizDispersa.png");

}


void MatrizDispersa::reporteUsuarios(string empresa, string departamento) {

	string dot = "digraph G{\nrankdir = LR\nnode[shape = box];\n";
	NodoMatriz* aux = existe(buscarDepartamento(departamento), empresa);

	if (aux != nullptr) {
		while (aux != nullptr) {

			if (aux->getAtras() != nullptr) {
				dot += "\"" + aux->getUsuario()->getNombre() + "\"->";
			}
			else {
				dot += "\"" + aux->getUsuario()->getNombre() + "\"\n}";
			}

			aux = aux->getAtras();
		}

		ofstream file;
		file.open("../Graficas/reporteUsuarios.txt");

		if (file.is_open()) {
			file << dot;
			file.close();
		}

		system("dot -Tpng ../Graficas/reporteUsuarios.txt -o ../Graficas/reporteUsuarios.png");
	}
	else {
		cout << "\nEl Departamento o la empresa no existen...";
	}

}