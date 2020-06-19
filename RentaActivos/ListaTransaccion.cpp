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
        fin = elemento;
        ini->setAnt(elemento);
        elemento->getAnt()->setSig(elemento);
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

void ListaTransaccion::reporteTransacciones() {

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


    if (ini->getTransaccion()->getDias() != "") {
        dot += "\"" + ini->getTransaccion()->getId() + "\n" + "RENTADO\n" + ini->getTransaccion()->getIdActivo()->getNombre() + "\n" + ini->getTransaccion()->getNombreUsuario() + "\"->\n";
    }
    else {
        dot += "\"" + ini->getTransaccion()->getId() + "\n" + "DEVUELTO\n" + ini->getTransaccion()->getIdActivo()->getNombre() + "\n" + ini->getTransaccion()->getNombreUsuario() + "\"->\n";
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
    file.open("../Graficas/reporteTransacciones.txt");

    if (file.is_open()) {
        file << dot;
        file.close();
    }

    system("dot -Tpng ../Graficas/reporteTransacciones.txt -o ../Graficas/reporteTransacciones.png");

}


void ListaTransaccion::ordernarAscendente() {


    NodoTransaccion* aux = ini->getSig();
    NodoTransaccion* aux2;
    NodoTransaccion* aux3;


    if (aux != nullptr) {

        do {
           
            aux2 = ini;

            do {



                if (aux2->getTransaccion()->getId() > aux->getTransaccion()->getId()) {

                    aux3 = aux;
                    aux->getTransaccion()->setId(aux2->getTransaccion()->getId());
                    aux->getTransaccion()->setIdActivo(aux2->getTransaccion()->getIdActivo());
                    aux->getTransaccion()->setNombreUsuario(aux2->getTransaccion()->getNombreUsuario());
                    aux->getTransaccion()->setDepartamento(aux2->getTransaccion()->getDepartamento());
                    aux->getTransaccion()->setEmpresa(aux2->getTransaccion()->getEmpresa());
                    aux->getTransaccion()->setFecha(aux2->getTransaccion()->getFecha());
                    aux->getTransaccion()->setDias(aux2->getTransaccion()->getDias());

                    aux2->getTransaccion()->setId(aux3->getTransaccion()->getId());
                    aux2->getTransaccion()->setIdActivo(aux3->getTransaccion()->getIdActivo());
                    aux2->getTransaccion()->setNombreUsuario(aux3->getTransaccion()->getNombreUsuario());
                    aux2->getTransaccion()->setDepartamento(aux3->getTransaccion()->getDepartamento());
                    aux2->getTransaccion()->setEmpresa(aux3->getTransaccion()->getEmpresa());
                    aux2->getTransaccion()->setFecha(aux3->getTransaccion()->getFecha());
                    aux2->getTransaccion()->setDias(aux3->getTransaccion()->getDias());

                }

                aux2 = aux2->getSig();

            } while (aux2->getSig() != ini);

            aux = aux->getSig();

        } while (aux != fin);

    }


}

void ListaTransaccion::ordenarDescendnete() {

}