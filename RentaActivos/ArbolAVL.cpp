#include "ArbolAVL.h"
#include <fstream>
#include <iostream>

using namespace std;

ArbolAVL::ArbolAVL() {
	raiz = nullptr;
}

void ArbolAVL::insertar(Activo* activo) {

	insertar(activo, raiz);

}

void ArbolAVL::insertar(Activo* activo, NodoAVL*& raiz) {

	if (raiz != nullptr) {

		if (activo->getID() > raiz->getActivo()->getID()) {
			if (raiz->getHijoDer() != nullptr) {
				insertar(activo, raiz->getHijoDer());
				if (facEquilibrio(alturaDer(raiz->getHijoDer()), alturaIzq(raiz->getHijoIzq())) == 2) {

					if (activo->getID() > raiz->getHijoDer()->getActivo()->getID()) {
						raiz = simpleIzq(raiz);
					}
					else {
						raiz = dobleIzq(raiz);
					}
				}
			}
			else {
				raiz->setHijoDer(new NodoAVL(activo));
			}
		}
		else if (activo->getID() < raiz->getActivo()->getID()) {
			if (raiz->getHijoIzq() != nullptr) {
				insertar(activo, raiz->getHijoIzq());

				if (facEquilibrio(alturaIzq(raiz->getHijoIzq()), alturaDer(raiz->getHijoDer())) == 2) {
					if (activo->getID() < raiz->getHijoIzq()->getActivo()->getID()) {
						raiz = simpleDer(raiz);
					}
					else {
						raiz = dobleDer(raiz);
					}

				}
			}
			else {
				raiz->setHijoIzq(new NodoAVL(activo));
			}
		}

		int mayor = mayorHijo(alturaDer(raiz->getHijoDer()), alturaIzq(raiz->getHijoIzq()));

		raiz->setAltura(mayor + 1);
	}
	else {
		raiz = new NodoAVL(activo);
	}

}


void ArbolAVL::eliminar(string id) {

	NodoAVL* eliminado = buscar(id, raiz);
	if (eliminado != nullptr) {
		string idEliminado = eliminado->getActivo()->getID();
		string nombre = eliminado->getActivo()->getNombre();
		string descripcion = eliminado->getActivo()->getDescripcion();


		raiz = eliminar(id, raiz);

		if (raiz != nullptr) {
			cout << "\nActivo Eliminado" << endl << "ID = " << idEliminado << endl;
			cout << "Nombre = " << nombre << endl << "Descripcion = " << descripcion << endl;
		}
	}
	else {
		cout << "\nEl activo no existe...";
	}
}

NodoAVL* ArbolAVL::eliminar(string id, NodoAVL*& raiz) {

	if (raiz != nullptr) {

		if (raiz->getActivo()->getID() == id) {
			if (esHoja(raiz)) {

				raiz = nullptr;
				return raiz;
			}
			else if (raiz->getHijoDer() == nullptr && raiz->getHijoIzq() != nullptr) {

				return raiz->getHijoIzq();
			}
			else if (raiz->getHijoIzq() == nullptr && raiz->getHijoDer() != nullptr) {

				return raiz->getHijoDer();
			}
			else {
				NodoAVL* masDerecha = buscarMasDerecha(raiz->getHijoIzq());

				if (masDerecha != nullptr) {

					raiz = eliminar(masDerecha->getActivo()->getID(), raiz);
					//raiz->getActivo()->setID(masDerecha->getActivo()->getID());
					raiz->setActivo(masDerecha->getActivo());
					if (facEquilibrio(alturaIzq(raiz->getHijoIzq()), alturaDer(raiz->getHijoDer())) == 2) {

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
		else if (id > raiz->getActivo()->getID()) {
			raiz->setHijoDer(eliminar(id, raiz->getHijoDer()));

			int mayor = mayorHijo(alturaDer(raiz->getHijoDer()), alturaIzq(raiz->getHijoIzq()));

			raiz->setAltura(mayor + 1);

			if (facEquilibrio(alturaIzq(raiz->getHijoIzq()), alturaDer(raiz->getHijoDer())) == 2) {

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
			raiz->setHijoIzq(eliminar(id, raiz->getHijoIzq()));

			int mayor = mayorHijo(alturaDer(raiz->getHijoDer()), alturaIzq(raiz->getHijoIzq()));

			raiz->setAltura(mayor + 1);

			if (facEquilibrio(alturaDer(raiz->getHijoDer()), alturaIzq(raiz->getHijoIzq())) == 2) {

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
		cout << "No hay nada que eliminar, arbol vacio" << endl;
	}

}

/*
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

}*/

bool ArbolAVL::modificarActivo(string id, string descripcion) {

	NodoAVL* activo = buscar(id, raiz);

	if (activo != nullptr) {
		activo->getActivo()->setDescripcion(descripcion);
		cout << "\nActivo Modificado:" << endl << "ID = " << activo->getActivo()->getID() << endl;
		cout << "Nombre = " << activo->getActivo()->getNombre() << endl << "Descripcion = " << activo->getActivo()->getDescripcion() << endl;
		return true;
	}
	return false;

}


void ArbolAVL::buscar(string id) {

	NodoAVL* busqueda = buscar(id, raiz);
	if (busqueda != nullptr) {
		cout << "El valor [" << id << "] encontrado fue: " << busqueda->getActivo()->getID() << endl;
	}
	else {
		cout << "El valor[" << id << "] buscado no existe" << endl;
	}
}

NodoAVL* ArbolAVL::buscar(string id, NodoAVL* nodo) {

	if (nodo != nullptr) {

		if (nodo->getActivo()->getID() == id) {
			return nodo;
		}
		else if (id > nodo->getActivo()->getID()) {
			return buscar(id, nodo->getHijoDer());
		}
		else {
			return buscar(id, nodo->getHijoIzq());
		}

	}
	else {
		return nullptr;
	}

}

bool ArbolAVL::preOrden(bool bandera) {

	if (raiz != nullptr) {
		preOrden(raiz, bandera);
		return true;
	}
	else {
		return false;
	}

}


void ArbolAVL::preOrden(NodoAVL* nodo, bool bandera) {

	if (bandera) {
		if (nodo != nullptr) {
			if (nodo->getActivo()->getDisponible()) {

				cout << "\n>> ID = " << nodo->getActivo()->getID() << "; Nombre = " << nodo->getActivo()->getNombre() << "; Descripcion = " << nodo->getActivo()->getDescripcion();

			}
			preOrden(nodo->getHijoIzq(), bandera);
			preOrden(nodo->getHijoDer(), bandera);
		}
	}
	else {
		if (nodo != nullptr) {

			if (!nodo->getActivo()->getDisponible()) {
				cout << "\n>> ID = " << nodo->getActivo()->getID() << "; Nombre = " << nodo->getActivo()->getNombre() << "; Descripcion = " << nodo->getActivo()->getDescripcion();
			}

			preOrden(nodo->getHijoIzq(), bandera);
			preOrden(nodo->getHijoDer(), bandera);
		}/*
		else if (nodo != nullptr) {
			preOrden(nodo->getHijoIzq(), bandera);
			preOrden(nodo->getHijoDer(), bandera);
		}*/
	}

}



int ArbolAVL::alturaDer(NodoAVL* der) {

	if (der != nullptr)
		return der->getAltura();
	return -1;
}

int ArbolAVL::alturaIzq(NodoAVL* izq) {

	if (izq != nullptr)
		return izq->getAltura();
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

	while (aux->getHijoDer() != nullptr) {

		aux = aux->getHijoDer();
	}

	return aux;

}

NodoAVL* ArbolAVL::buscarMasIzquierda(NodoAVL* nodo) {

	NodoAVL* aux = nodo;

	while (aux->getHijoIzq() != nullptr) {

		aux = aux->getHijoIzq();
	}

	return aux;

}

NodoAVL* ArbolAVL::simpleDer(NodoAVL* nodo) {

	NodoAVL* aux = nodo->getHijoIzq();

	nodo->setHijoIzq(aux->getHijoDer());
	aux->setHijoDer(nodo);

	nodo->setAltura(mayorHijo(alturaDer(nodo->getHijoDer()), alturaIzq(nodo->getHijoIzq())) + 1);
	aux->setAltura(mayorHijo(alturaDer(aux->getHijoDer()), alturaIzq(aux->getHijoIzq())) + 1);

	return aux;
}

NodoAVL* ArbolAVL::simpleIzq(NodoAVL* nodo) {

	NodoAVL* aux = nodo->getHijoDer();

	nodo->setHijoDer(aux->getHijoIzq());
	aux->setHijoIzq(nodo);

	nodo->setAltura(mayorHijo(alturaDer(nodo->getHijoDer()), alturaIzq(nodo->getHijoIzq())) + 1);
	aux->setAltura(mayorHijo(alturaDer(aux->getHijoDer()), alturaIzq(aux->getHijoIzq())) + 1);

	return aux;

}

NodoAVL* ArbolAVL::dobleDer(NodoAVL* nodo) {

	nodo->setHijoIzq(simpleIzq(nodo->getHijoIzq()));
	return simpleDer(nodo);

}

NodoAVL* ArbolAVL::dobleIzq(NodoAVL* nodo) {

	nodo->setHijoDer(simpleDer(nodo->getHijoDer()));
	return simpleIzq(nodo);
}



bool ArbolAVL::esHoja(NodoAVL* nodo) {

	if (nodo != nullptr) {
		return nodo->getHijoDer() == nullptr && nodo->getHijoIzq() == nullptr;
	}

}


void ArbolAVL::activoEliminado(Activo* activo) {

	cout << "\nActivo Eliminado: " << endl;
	cout << "Id: " << activo->getID() << endl << "Nombre: " << activo->getNombre() << endl << "Descripción: " << activo->getDescripcion() << endl;
}


void ArbolAVL::activosUsuario(NodoAVL* usuarioActual, string usuario) {

	string dot = "digraph{ \nrankdir = TB;\n node[shape = box]\n " + usuario + "\n node[shape = circle]; \n";
	dot += activosUsuarioPre(usuarioActual, dot) + "\n}";

	ofstream file;
	file.open("../Graficas/activosUsuario.txt");

	if (file.is_open()) {
		file << dot;
		file.close();
	}

	system("dot -Tpng ../Graficas/activosUsuario.txt -o ../Graficas/activosUsuario.png");


}

string ArbolAVL::activosUsuarioPre(NodoAVL* usuarioActual, string dot) {

	string dot2 = "";
	if (usuarioActual != nullptr && usuarioActual->getActivo()->getDisponible()) {

		dot2 += usuarioActual->getActivo()->getNombre() + "[ label = <" + usuarioActual->getActivo()->getID() + "<br />" + usuarioActual->getActivo()->getNombre() + "> color = blue];\n";

		if (usuarioActual->getHijoIzq() != nullptr) {
			dot2 += activosUsuarioPre(usuarioActual->getHijoIzq(), dot2) + usuarioActual->getActivo()->getNombre() + "->" + usuarioActual->getHijoIzq()->getActivo()->getNombre() + "; \n";
		}
		if (usuarioActual->getHijoDer() != nullptr) {
			dot2 += activosUsuarioPre(usuarioActual->getHijoDer(), dot2) + usuarioActual->getActivo()->getNombre() + "->" + usuarioActual->getHijoDer()->getActivo()->getNombre() + ";\n";
		}

	}

	if (usuarioActual != nullptr && !usuarioActual->getActivo()->getDisponible()) {

		dot2 += usuarioActual->getActivo()->getNombre() + "[label = <" + usuarioActual->getActivo()->getID() + "<br />" + usuarioActual->getActivo()->getNombre() + "> color = red];\n";

		if (usuarioActual->getHijoIzq() != nullptr) {
			dot2 += activosUsuarioPre(usuarioActual->getHijoIzq(), dot2) + usuarioActual->getActivo()->getNombre() + "->" + usuarioActual->getHijoIzq()->getActivo()->getNombre() + ";\n";
		}
		if (usuarioActual->getHijoDer() != nullptr) {
			dot2 += activosUsuarioPre(usuarioActual->getHijoDer(), dot2) + usuarioActual->getActivo()->getNombre() + "->" + usuarioActual->getHijoDer()->getActivo()->getNombre() + ";\n";
		}

	}
	else if (usuarioActual != nullptr) {

	}

	return dot2;

}