#include "Transaccion.h"

Transaccion::Transaccion(int idActivo, string nombreUsuario, string departamento, string empresa, string fecha, int dias) {

    setIdActivo(idActivo);
    setNombreUsuario(nombreUsuario);
    setDepartamento(departamento);
    setEmpresa(empresa);
    setFecha(fecha);
    setDias(dias);
}

void Transaccion::setIdActivo(int idActivo) {
    this->idActivo = idActivo;
}

void Transaccion::setNombreUsuario(string nombreUsuario) {
    this->nombreUsuario = nombreUsuario;
}

void Transaccion::setDepartamento(string departatamento) {
    this->departamento = departamento;
}

void Transaccion::setEmpresa(string empresa) {
    this->empresa = empresa;
}

void Transaccion::setFecha(string fecha) {
    this->fecha = fecha;
}

void Transaccion::setDias(int dias) {
    this->dias = dias;
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
int Transaccion::getIdActivo() {
    return idActivo;
}
int Transaccion::getDias() {
    return dias;
}
