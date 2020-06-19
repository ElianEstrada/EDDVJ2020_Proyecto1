#pragma once
#include <iostream>
#include "NodoTransaccion.h"

using namespace std;

class ListaTransaccion
{


    NodoTransaccion* ini;
    NodoTransaccion* fin;

public:
    ListaTransaccion();

    void insertarTransaccion(Transaccion* transaccion);
    void insertarAlFinal(NodoTransaccion *elemento);
    void insertarAlFrente(NodoTransaccion* elemento);
    void insertarAlMedio(NodoTransaccion* elemento, NodoTransaccion* transaccionSiguiente);

    bool recorrerLista(string usuario);
    void reporteActivosRentadosUsuario(string usuario);
    string reporteActivosRentadosUsuario(string dot, string usuario);
    void reporteTransaccionesAscendente();
    void reporteTransaccionesDescendente();

    bool estaVacia();
};

