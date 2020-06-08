#pragma once
#include <string>

using namespace std;


class Transaccion
{

    string id;
    int idActivo;
    string nombreUsuario;
    string departamento;
    string empresa;
    string fecha;
    int dias;

public:
    Transaccion();
    Transaccion(int idActivo, string nombreUsuario, string departamento, string empresa, string fecha, int dias);
    void setIdActivo(int idActivo);
    int getIdActivo();
    void setNombreUsuario(string nombreUsuario);
    string getNombreUsuario();
    void setDepartamento(string departamento);
    string getDepartamento();
    void setEmpresa(string empresa);
    string getEmpresa();
    void setFecha(string fecha);
    string getFecha();
    void setDias(int dias);
    int getDias();

};

