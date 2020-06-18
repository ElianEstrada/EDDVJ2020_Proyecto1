#include <fstream>
#include "ListaTransaccion.h"

ListaTransaccion::ListaTransaccion() {
    ini = nullptr;
    fin = nullptr;
}

void ListaTransaccion::insertarAlFinal(Transaccion* transaccion)
{

    NodoTransaccion* elemento = new NodoTransaccion(transaccion);

    //fin = elemento;

    if (!estaVacia()) {
        elemento->setSig(ini);
        elemento->setAnt(fin);
        fin->setSig(elemento);
        ini->setAnt(elemento);
        fin = elemento;
    }
    else {
        elemento->setSig(elemento);
        elemento->setAnt(elemento);
        ini = fin = elemento;
    }

}

bool ListaTransaccion::recorrerLista(string usuario) {

    if (!estaVacia()) {

        NodoTransaccion* aux = ini;

        do {

            if (aux->getTransaccion()->getNombreUsuario() == usuario && !aux->getTransaccion()->getIdActivo()->getDisponible()) {
                cout << ">>ID = " << aux->getTransaccion()->getIdActivo()->getID() << "; Nombre = " << aux->getTransaccion()->getIdActivo()->getNombre() << "; Tiempo de Renta = " << aux->getTransaccion()->getDias() << endl;
            }

            aux = aux->getSig();

        } while (aux != ini);

    }
    else {
        cout << "No hay transacciones disponibles...";
        return false;
        cin.ignore();
    }

    return true;

}

bool ListaTransaccion::estaVacia() {
    return ini == nullptr;
}


void ListaTransaccion::reporteActivosRentadosUsuario(string usuario) {

    string dot = "digraph{ \nrankdir = LR;\n node[shape = box]; \n";
    dot = reporteActivosRentadosUsuario(dot, usuario);
    dot += "}";

    ofstream file;
    file.open("../Graficas/activosRentados.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }

    system("dot -Tpng ../Graficas/activosRentados.txt -o ../Graficas/activosRentados.png");
}


string ListaTransaccion::reporteActivosRentadosUsuario(string dot, string usuario){

    int contador = 0;

    if (!estaVacia()) {

        NodoTransaccion* aux = ini;

        do {

            if (aux->getTransaccion()->getNombreUsuario() == usuario && aux->getTransaccion()->getDias() != "") {

                contador++;
                dot += "activo" + to_string(contador) + "[label = <" + aux->getTransaccion()->getIdActivo()->getID() + " <br /> " + aux->getTransaccion()->getIdActivo()->getNombre() + ">]\n";

                
            }
            aux = aux->getSig();

        } while (aux != ini);

        int contador2 = 0;

        do {

            if (aux->getTransaccion()->getNombreUsuario() == usuario && aux->getTransaccion()->getDias() != "" && contador2 != contador - 1) {

                contador2++;
                dot += "activo" + to_string(contador2) + "-> activo" + to_string(contador2 + 1) + "\n";

                if (contador2 = contador - 1) {
                    break;
                }

                
            }
            aux = aux->getSig();

        } while (aux != ini);

        dot += usuario + "\n";

        return dot;

    }
    else {
       
        dot += "vacio;\n" + usuario + "\n";
        return dot;
    }

}