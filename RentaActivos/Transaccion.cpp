#include "Transaccion.h"

static string idLocal;

Transaccion::Transaccion(Activo* idActivo, string nombreUsuario, string departamento, string empresa, string fecha, string dias) {

    idLocal = to_string(rand()) + nombreUsuario + to_string(nombreUsuario.length()) + idActivo->getID() + to_string(departamento.length());
    setId(arreglar(idLocal));
    setIdActivo(idActivo);
    setNombreUsuario(nombreUsuario);
    setDepartamento(departamento);
    setEmpresa(empresa);
    setFecha(fecha);
    setDias(dias);
}

void Transaccion::setId(string id) {
    this->id = id;
}

void Transaccion::setIdActivo(Activo* idActivo) {
    this->idActivo = idActivo;
}

void Transaccion::setNombreUsuario(string nombreUsuario) {
    this->nombreUsuario = nombreUsuario;
}

void Transaccion::setDepartamento(string departamento) {
    this->departamento = departamento;
}

void Transaccion::setEmpresa(string empresa) {
    this->empresa = empresa;
}

void Transaccion::setFecha(string fecha) {
    this->fecha = fecha;
}

void Transaccion::setDias(string dias) {
    this->dias = dias;
}

string Transaccion::getId() {
    return id;
}

string Transaccion::getNombreUsuario() {
    return nombreUsuario;
}
string Transaccion::getDepartamento() {
    return departamento;
}
string Transaccion::getEmpresa() {
    return empresa;
}
string Transaccion::getFecha() {
    return fecha;
}
Activo* Transaccion::getIdActivo() {
    return idActivo;
}
string Transaccion::getDias() {
    return dias;
}

string Transaccion::arreglar(string id) {

    if (id.length() >= 15) {
        string aux;
        for (int i = 0; i < 15; i++) {
            aux += id[i];
        }

        id = aux;
    }
    else {
        int i = id.length() - 1;
        id += to_string(i) + id[i - 1] + to_string(i * id.length());
        id = arreglar(id);
    }

    return id;
}
