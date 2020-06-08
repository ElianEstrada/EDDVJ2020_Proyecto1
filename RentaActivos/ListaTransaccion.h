#pragma once
#include <iostream>
#include "NodoTransaccion.h"

using namespace std;

class ListaTransaccion
{


    NodoTransaccion* ini = nullptr;
    NodoTransaccion* fin = nullptr;

public:
    void insertarAlFinal(Transaccion *transaccion);
    bool estaVacia();
};

