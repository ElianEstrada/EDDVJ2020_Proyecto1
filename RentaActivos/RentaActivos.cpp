
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "MenuPrincipal.h"
#include "MatrizDispersa.h"

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

    srand(time(NULL));

    MatrizDispersa* matriz = new MatrizDispersa();

    matriz->insertarUsuario(new Usuario("Elian", "eliadelyn", "pinponpan"), "guatemala", "libreria h45");
    matriz->insertarUsuario(new Usuario("Alex", "eliadelyn", "pinponpan"), "sacatepequez", "max");
    matriz->insertarUsuario(new Usuario("Daniel", "eliadelyn", "pinponpan"), "suchitepequez", "walmart");
    matriz->insertarUsuario(new Usuario("Allan", "eliadelyn", "pinponpan"), "jalapa", "max");
    matriz->insertarUsuario(new Usuario("Sergio", "eliadelyn", "pinponpan"), "zacapa", "libreria h45");
    matriz->insertarUsuario(new Usuario("Madelyn", "eliadelyn", "pinponpan"), "zacapa", "walmart");

    //menuPrincipal();

    cin.ignore();
    cin.get();
    return 0;
}

