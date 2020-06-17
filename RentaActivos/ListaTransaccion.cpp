#include "ListaTransaccion.h"

ListaTransaccion::ListaTransaccion() {
    ini = nullptr;
    fin = nullptr;
}

void ListaTransaccion::insertarAlFinal(Transaccion* transaccion)
{

    NodoTransaccion* elemento = new NodoTransaccion(transaccion);

    //fin = elemento;

    if (!estaVacia()) {
        elemento->setSig(ini);
        elemento->setAnt(fin);
        fin->setSig(elemento);
        ini->setAnt(elemento);
        fin = elemento;
    }
    else {
        elemento->setSig(elemento);
        elemento->setAnt(elemento);
        ini = fin = elemento;
    }

}

bool ListaTransaccion::recorrerLista(string usuario) {

    if (!estaVacia()) {

        NodoTransaccion* aux = ini;

        do {

            if (aux->getTransaccion()->getNombreUsuario() == usuario && !aux->getTransaccion()->getIdActivo()->getDisponible()) {
                cout << ">>ID = " << aux->getTransaccion()->getIdActivo()->getID() << "; Nombre = " << aux->getTransaccion()->getIdActivo()->getNombre() << "; Tiempo de Renta = " << aux->getTransaccion()->getDias() << endl;
            }

            aux = aux->getSig();

        } while (aux != ini);

    }
    else {
        cout << "No hay transacciones disponibles...";
        return false;
        cin.ignore();
    }

    return true;

}

bool ListaTransaccion::estaVacia() {
    return ini == nullptr;
}


void ListaTransaccion::reporteActivosRentadosUsuario(string usuario) {

    string dot = "digraph{ node[shape = box]; \n";
    reporteActivosRentadosUsuario(dot);

}


string ListaTransaccion::reporteActivosRentadosUsuario(string dot, string usuario){

    if (!estaVacia()) {

        NodoTransaccion* aux = ini;

        do {

            if (aux->getTransaccion()->getNombreUsuario() == usuario) {



                cout << ">>ID = " << aux->getTransaccion()->getIdActivo()->getID() << "; Nombre = " << aux->getTransaccion()->getIdActivo()->getNombre() << "; Tiempo de Renta = " << aux->getTransaccion()->getDias() << endl;
            }
            aux = aux->getSig();

        } while (aux != ini);

    }
    else {
       
        dot += "vacio; }";
        return dot;
    }

}