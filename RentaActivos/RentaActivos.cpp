
#include <iostream>
#include "MenuPrincipal.h"

#include "MatrizDispersa.h"

using namespace std;

int main()
{
    /*
     ListaTransaccion lista;

    lista.insertarAlFinal(new Transaccion(1, "Elian", "Guatemala", "Libreria h45", "2020-06-07", 3));
    lista.insertarAlFinal(new Transaccion(2, "Allan", "Guatemala", "Libreria h45", "2020-06-07", 3));
    lista.insertarAlFinal(new Transaccion(3, "Norman", "Guatemala", "Libreria h45", "2020-06-07", 3));
    
    */


    //menuPrincipal();

    MatrizDispersa* matriz = new MatrizDispersa();

    matriz->insertarCabHorizontal("Guatemala");
    matriz->insertarCabHorizontal("Zacapa");
    matriz->insertarCabVertical("Max");
    matriz->insertarCabVertical("Walmart");
    
    cin.ignore();
    cin.get();
    return 0;
}

