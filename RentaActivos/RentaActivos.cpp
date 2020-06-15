#include <iostream>
#include <cstdlib>
#include <time.h>
#include "MenuPrincipal.h"
#include "MatrizDispersa.h"

using namespace std;

int main()
{

    srand(time(NULL));

    MatrizDispersa* matriz = new MatrizDispersa();

    matriz->insertarUsuario(new Usuario("Elian", "eliadelyn", "pinponpan"), "guatemala", "libreria h45");
    matriz->insertarUsuario(new Usuario("Alex", "eliadelyn", "pinponpan"), "sacatepequez", "max");
    //matriz->insertarUsuario(new Usuario("Daniel", "eliadelyn", "pinponpan"), "suchitepequez", "walmart");

    matriz->insertarUsuario(new Usuario("Enrique", "ishky", "123123"), "suchitepequez", "libreria h45");
    matriz->insertarUsuario(new Usuario("Allan", "eliadelyn", "pinponpan"), "jalapa", "max");
    matriz->insertarUsuario(new Usuario("Sergio", "eliadelyn", "pinponpan"), "zacapa", "libreria h45");
    matriz->insertarUsuario(new Usuario("Madelyn", "eliadelyn", "pinponpan"), "zacapa", "walmart");
    matriz->insertarUsuario(new Usuario("Norman", "norky", "abcdefg"), "zacapa", "max");
    matriz->insertarUsuario(new Usuario("Tono", "termiTono", "1234"), "guatemala", "walmart");
    matriz->insertarUsuario(new Usuario("Madelyn", "eliadelyn", "pinponpan"), "sacatepequez", "walmart");
    matriz->insertarUsuario(new Usuario("Rodrigo", "eliadelyn", "pinponpan"), "zacapa", "walmart");
    matriz->insertarUsuario(new Usuario("Luis", "norky", "abcdefg"), "zacapa", "max");

    matriz->insertarUsuario(new Usuario("Aris", "yaris", "45648"), "suchitepequez", "max");
    matriz->insertarUsuario(new Usuario("Aris", "hoalek", "13213"), "suchitepequez", "max");
    matriz->insertarUsuario(new Usuario("Ana", "hoalek", "13213"), "suchitepequez", "max");
    //menuPrincipal();

    cin.ignore();
    cin.get();
    return 0;
}

