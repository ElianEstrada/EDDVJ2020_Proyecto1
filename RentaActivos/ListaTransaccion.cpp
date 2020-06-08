#include "ListaTransaccion.h"

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

bool ListaTransaccion::estaVacia() {
    return ini == nullptr;
}
