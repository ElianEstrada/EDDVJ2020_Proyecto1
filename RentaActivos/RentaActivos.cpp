
#include <iostream>
#include "MenuPrincipal.h"
#include "Activo.h"


using namespace std;

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


int main()
{

    Activo* a1 = new Activo("Elian", "Guapo");
    Activo* a2 = new Activo("Alex", "Meh");
    Activo* a3 = new Activo("Daniel", "Ufff");

    cout << a1->getID() << " " << a2->getID() << " " << a3->getID() << endl;

    cin.ignore();
    cin.get();
    return 0;
}

