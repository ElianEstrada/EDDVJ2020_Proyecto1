#include "NodoTransaccion.h"

NodoTransaccion::NodoTransaccion(Transaccion* transaccion)
{
   
    setTransaccion(transaccion);
    setSig(nullptr);
    setAnt(nullptr);
}

void NodoTransaccion::setSig(NodoTransaccion* sig) {
    this->sig = sig;
}
NodoTransaccion* NodoTransaccion::getSig() {
    return sig;
}
void NodoTransaccion::setAnt(NodoTransaccion* ant) {
    this->ant = ant;
}
NodoTransaccion* NodoTransaccion::getAnt() {
    return ant;
}
void NodoTransaccion::setTransaccion(Transaccion* transaccion) {
    this->transaccion = transaccion;
}
Transaccion* NodoTransaccion::getTransaccion() {
    return transaccion;
}
