#include <iostream>
#include <cstdlib>
#include <time.h>
#include "MenuPrincipal.h"
#include "ArbolAVL.h"

using namespace std;

int main()
{

    srand(time(NULL));

    menuPrincipal();

    cin.ignore();
    cin.get();
    return 0;
}

