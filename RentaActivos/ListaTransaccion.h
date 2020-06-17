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

    void insertarAlFinal(Transaccion *transaccion);
    bool recorrerLista(string usuario);
    void reporteActivosRentadosUsuario(string usuario);
    string reporteActivosRentadosUsuario(string dot, string usuario);
    bool estaVacia();
};

