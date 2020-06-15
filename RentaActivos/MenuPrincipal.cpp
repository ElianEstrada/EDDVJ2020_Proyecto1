#include "MenuPrincipal.h"

const string admin = "admin";
const string ctrAdmin = "admin";


//Menu Principal
void menuPrincipal()
{
    system("cls");
    char opcion;

    cout << "-------------------BIENVENIDOS-------------------" << endl;
    cout << "----------------Inicio de Sesión-----------------" << endl;

    cout << "\n1. Como Administrador\n2. Como Usuario" << endl;
    cout << "\nEscoja una opción: ";
    cin >> opcion;

    switch (opcion)
    {
    case '1':
        system("cls");
        login(false); //Administrador
        break;
    case '2':
        system("cls");
        login(true); // Usuario
        break;

    default:
        cout << "\nPor favor escoja una de las opciones disponibles...";
        cin.ignore();
        cin.get();
        menuPrincipal();
    }
}


//Login
void login(bool bandera)
{
    cin.ignore();
    string usuario;
    string contrasenia;
    string departamento;
    string empresa;

    cout << "----------------Iniciar de Sesión-----------------" << endl;
    cout << "\nIngrese su nombre de usurario: ";
    getline(cin, usuario);
    cout << "Ingrese su contraseña: ";
    getline(cin, contrasenia);
    if (bandera)
    {
        cout << "Ingrese su Departamento:";
        getline(cin, departamento);
        cout << "Ingrese su Empresa:";
        getline(cin, empresa);

        if (usuario == "eliadelyn" && contrasenia == "pinponpan" && departamento == "guatemala" && empresa == "libreria h45") {
            menuUsuario(usuario);
        }
    }

    if (usuario == admin && contrasenia == ctrAdmin)
    {
        adminMenu();
    }
}

//Opciones de los menus de usario

void eleccion(bool bandera, char opcion) {

    switch (opcion)
    {
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        break;
    case '5':
        break;
    case '6':
        break;
    case '7':
        break;
    case '8':
        break;
    case '9':
        menuPrincipal();
        break;
    default:
        cout << "\nIngrese una de las opciones disponibles por favor...";
        cin.ignore();
        cin.get();
        break;
    }

}


//Menú del Administrador
void adminMenu() {

    system("cls");
    char opcion;

    cout << "-------------------Bienvenido Administrador-------------------" << endl;
    cout << "-------------Escoja la opción que quiere realizar-------------" << endl;

    cout << "\n1. Registrar Usuarios\n2. Reportes Matriz Dispersa\n3. Reporte Usuarios Registrados";
    cout << "\n4. Reporte Activos Disponibles de un Departamento\n5. Reporte Activos Disponibles de una Empresa";
    cout << "\n6. Reporte Transacciones\n7. Reporte Activos de un usuario\n8. Activos rentados por un usuario\n9. Regresar..." << endl;

    cout << "\nEscoja una opción: ";
    cin >> opcion;

    eleccion(true, opcion);


}

//Menú del Usuario
void menuUsuario(string nombre) {

    system("cls");
    char opcion;

    cout << "-------------------Bienvenido " << nombre << "-------------------" << endl;
    cout << "-----------Escoja la opción que quiere realizar---------" << endl;

    cout << "\n1. Registrar Usuarios\n2. Reportes Matriz Dispersa\n3. Reporte Usuarios Registrados";
    cout << "\n4. Reporte Activos Disponibles de un Departamento\n5. Reporte Activos Disponibles de una Empresa";
    cout << "\n6. Reporte Transacciones\n7. Reporte Activos de un usuario\n8. Activos rentados por un usuario\n9. Regresar..." << endl;

    cout << "\nEscoja una ocpión: ";
    cin >> opcion;

    eleccion(false, opcion);

}


//Dejar todo en Mayusculas

string strCast(string cadena) {

    string aux;
    for (int i = 0; i < cadena.length(); i++) {
        aux += toupper(cadena[i]);
    }

    return aux;

}
