
#include <iostream>
#include "ListaTransaccion.h"

using namespace std;

int main()
{

    ListaTransaccion lista;

    lista.insertarAlFinal(new Transaccion(1, "Elian", "Guatemala", "Libreria h45", "2020-06-07", 3));
    lista.insertarAlFinal(new Transaccion(2, "Allan", "Guatemala", "Libreria h45", "2020-06-07", 3));
    lista.insertarAlFinal(new Transaccion(3, "Norman", "Guatemala", "Libreria h45", "2020-06-07", 3));
    
    cin.ignore();
    cin.get();
    return 0;
}

