
#include <iostream>
#include "MenuPrincipal.h"


#include "ArbolActivo.h"

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
    /*
        MatrizDispersa* matriz = new MatrizDispersa();

    matriz->insertarCabHorizontal("Guatemala");
    matriz->insertarCabHorizontal("Zacapa");
    matriz->insertarCabVertical("Max");
    matriz->insertarCabVertical("Walmart");
    */

    ArbolActivo* arbol = new ArbolActivo();

    arbol->insertarActivo(2, arbol->getRaiz());
    arbol->insertarActivo(1, arbol->getRaiz());
    arbol->insertarActivo(8, arbol->getRaiz());
    arbol->insertarActivo(5, arbol->getRaiz());
    arbol->insertarActivo(9, arbol->getRaiz());
    arbol->insertarActivo(0, arbol->getRaiz());
    arbol->insertarActivo(4, arbol->getRaiz());
    arbol->insertarActivo(6, arbol->getRaiz());

    arbol->eliminarActivo(8);
    arbol->eliminarActivo(5);
    arbol->eliminarActivo(6);
    arbol->eliminarActivo(9);
    arbol->eliminarActivo(1);
    arbol->eliminarActivo(4);
    arbol->eliminarActivo(2);
    arbol->eliminarActivo(0);


    cin.ignore();
    cin.get();
    return 0;
}

