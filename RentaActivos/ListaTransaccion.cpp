#include <fstream>
#include "ListaTransaccion.h"

ListaTransaccion::ListaTransaccion() {
    ini = nullptr;
    fin = nullptr;
}

void ListaTransaccion::insertarTransaccion(Transaccion* transaccion) {

    NodoTransaccion* elemento = new NodoTransaccion(transaccion);

    if (!estaVacia()) {

        NodoTransaccion* aux = ini;

        if (aux == ini && aux == fin) {

            if (elemento->getTransaccion()->getId() > aux->getTransaccion()->getId()) {
                insertarAlFinal(elemento);
            }
            else if(elemento->getTransaccion()->getId() < aux->getTransaccion()->getId()){
                insertarAlFrente(elemento);
            }
        }
        else {
            while (aux != fin) {

                if (elemento->getTransaccion()->getId() > aux->getTransaccion()->getId() && elemento->getTransaccion()->getId() < aux->getSig()->getTransaccion()->getId()) {

                    insertarAlMedio(elemento, aux->getSig());
                    return;

                }
                else if (elemento->getTransaccion()->getId() < aux->getTransaccion()->getId()) {
                    insertarAlFrente(elemento);
                    return;
                }

                aux = aux->getSig();
            }

            insertarAlFinal(elemento);
        }

    }
    else {
        elemento->setSig(elemento);
        elemento->setAnt(elemento);
        ini = fin = elemento;
    }

}

void ListaTransaccion::insertarAlFinal(NodoTransaccion* elemento)
{

    elemento->setAnt(fin);
    elemento->setSig(fin->getSig());
    fin->getSig()->setAnt(elemento);
    fin->setSig(elemento);
    fin = elemento;

}

void ListaTransaccion::insertarAlFrente(NodoTransaccion* elemento) {

    elemento->setSig(ini);
    elemento->setAnt(ini->getAnt());
    ini->getAnt()->setSig(elemento);
    ini->setAnt(elemento);
    ini = elemento;

}

void ListaTransaccion::insertarAlMedio(NodoTransaccion* elemento, NodoTransaccion* transaccionSiguiente) {

    elemento->setSig(transaccionSiguiente);
    elemento->setAnt(transaccionSiguiente->getAnt());
    transaccionSiguiente->getAnt()->setSig(elemento);
    transaccionSiguiente->setAnt(elemento);

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

void ListaTransaccion::reporteTransaccionesAscendente() {

    string dot = "digraph{ \nrankdir = LR;\n node[shape = box, color = red]; \n";

    NodoTransaccion* aux = ini;

    do {

        if (aux->getTransaccion()->getDias() != "") {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
        else {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }

        aux = aux->getSig();

    } while (aux != ini);

    if (ini != fin) {

        if (ini->getTransaccion()->getDias() != "") {
            dot += "\"" + ini->getTransaccion()->getId() + "\n" + "RENTADO\n" + ini->getTransaccion()->getIdActivo()->getNombre() + "\n" + ini->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
        else {
            dot += "\"" + ini->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + ini->getTransaccion()->getIdActivo()->getNombre() + "\n" + ini->getTransaccion()->getNombreUsuario() + "\"->\n";
        }

    }


    aux = fin;

    do {

        if (aux->getTransaccion()->getDias() != "") {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
        else {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }

        aux = aux->getAnt();

    } while (aux->getAnt() != fin);

    if (aux->getTransaccion()->getDias() != "") {
        dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"";
    }
    else {
        dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"";
    }

    dot += ";\n}";

    ofstream file;
    file.open("../Graficas/reporteTransaccionesAscendente.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }

    system("dot -Tpng ../Graficas/reporteTransaccionesAscendente.txt -o ../Graficas/reporteTransaccionesAscendente.png");

}



void ListaTransaccion::reporteTransaccionesDescendente() {

    string dot = "digraph{ \nrankdir = LR;\n node[shape = box, color = red]; \n";

    NodoTransaccion* aux = fin;

    do {

        if (aux->getTransaccion()->getDias() != "") {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
        else {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }

        aux = aux->getAnt();

    } while (aux != fin);

    if (ini != fin) {

        if (fin->getTransaccion()->getDias() != "") {
            dot += "\"" + fin->getTransaccion()->getId() + "\n" + "RENTADO\n" + fin->getTransaccion()->getIdActivo()->getNombre() + "\n" + fin->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
        else {
            dot += "\"" + fin->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + fin->getTransaccion()->getIdActivo()->getNombre() + "\n" + fin->getTransaccion()->getNombreUsuario() + "\"->\n";
        }

    }


    aux = ini;

    do {

        if (aux->getTransaccion()->getDias() != "") {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }
        else {
            dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"->\n";
        }

        aux = aux->getSig();

    } while (aux->getSig() != ini);

    if (aux->getTransaccion()->getDias() != "") {
        dot += "\"" + aux->getTransaccion()->getId() + "\n" + "RENTADO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"";
    }
    else {
        dot += "\"" + aux->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + aux->getTransaccion()->getIdActivo()->getNombre() + "\n" + aux->getTransaccion()->getNombreUsuario() + "\"";
    }

    dot += ";\n}";

    ofstream file;
    file.open("../Graficas/reporteTransaccionesDescendente.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }

    system("dot -Tpng ../Graficas/reporteTransaccionesDescendente.txt -o ../Graficas/reporteTransaccionesDescendente.png");

}
