#pragma once
#include <string>
#include "Activo.h"

using namespace std;


class Transaccion
{

    string id;
    Activo* idActivo;
    string nombreUsuario;
    string departamento;
    string empresa;
    string fecha;
    string dias;

public:
    Transaccion();
    Transaccion(Activo* idActivo, string nombreUsuario, string departamento, string empresa, string fecha, string dias);

    string arreglar(string id);

    void setId(string id);
    string getId();
    void setIdActivo(Activo* idActivo);
    Activo* getIdActivo();
    void setNombreUsuario(string nombreUsuario);
    string getNombreUsuario();
    void setDepartamento(string departamento);
    string getDepartamento();
    void setEmpresa(string empresa);
    string getEmpresa();
    void setFecha(string fecha);
    string getFecha();
    void setDias(string dias);
    string getDias();

};

