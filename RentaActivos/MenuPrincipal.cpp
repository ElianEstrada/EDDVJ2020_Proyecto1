#include "MenuPrincipal.h"
#include "MatrizDispersa.h"

const string admin = "admin";
const string ctrAdmin = "admin";
NodoMatriz* usuarioActual = nullptr;

MatrizDispersa* matriz = new MatrizDispersa();

//Menu Principal
void menuPrincipal()
{
	system("cls");
	char opcion;

	cout << "-------------------BIENVENIDOS-------------------" << endl;
	cout << "----------------Inicio de Sesi�n-----------------" << endl;

	cout << "\n1. Como Administrador\n2. Como Usuario" << endl;
	cout << "\nEscoja una opci�n: ";
	cin >> opcion;

	switch (opcion)
	{
	case '1':
		//system("cls");
		login(false); //Administrador
		break;
	case '2':
		//system("cls");
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
	system("cls");
	string usuario;
	string contrasenia;
	string departamento;
	string empresa;

	cout << "----------------Iniciar de Sesi�n-----------------" << endl;
	cout << "\nIngrese su nombre de usurario: ";
	getline(cin, usuario);
	cout << "Ingrese su contrase�a: ";
	getline(cin, contrasenia);
	if (bandera)
	{
		cout << "Ingrese su Departamento: ";
		getline(cin, departamento);
		cout << "Ingrese su Empresa: ";
		getline(cin, empresa);

		usuarioActual = matriz->existe(matriz->buscarDepartamento(strCast(departamento)), strCast(empresa));
		NodoMatriz* aux = usuarioActual;
		if (usuarioActual != nullptr) {
			do{
				if (usuarioActual->getUsuario()->getUsuario() == strCast(usuario) && usuarioActual->getUsuario()->getContrase�a() == strCast(contrasenia)) {
					menuUsuario(usuario);
				}

				aux = aux->getAtras();
			} while (aux != nullptr);

			cout << "\nEl usuario o la contrase�a estan incorrectas..." << endl;
			menuPrincipal();
		}
		else {
			cout << "\nEl usuario no existe..." << endl;
			cin.ignore();
			menuPrincipal();
		}

	}

	if (usuario == admin && contrasenia == ctrAdmin)
	{
		adminMenu();
	}
}

//Opciones de los menus de usario

void eleccion(bool bandera, char opcion) {

	cin.ignore();
	string nombreCompleto;
	string usuario;
	string contrasenia;
	string departamento;
	string empresa;
	string nombreActivo;
	string descripcionActivo;

	switch (opcion)
	{
	case '1':

		if (bandera) {

			system("cls");
			cout << "--------------------CREAR USUARIO--------------------" << endl;
			cout << "\nIngrese el nombre completo: ";
			getline(cin, nombreCompleto);
			cout << "Ingrese el nombre de Usuario: ";
			getline(cin, usuario);
			cout << "Ingrese la contrase�a: ";
			getline(cin, contrasenia);
			cout << "Ingrese el departamento: ";
			getline(cin, departamento);
			cout << "ingrese la empresa: ";
			getline(cin, empresa);

			matriz->insertarUsuario(new Usuario(strCast(nombreCompleto), strCast(usuario), strCast(contrasenia)), strCast(departamento), strCast(empresa));

			adminMenu();
		}
		else {

			system("cls");
			cout << "--------------------AGREGAR ACTIVO--------------------" << endl;
			cout << "\nIngrese el nombre: ";
			getline(cin, nombreActivo);
			cout << "Ingrese la descripcion: ";
			getline(cin, descripcionActivo);

			usuarioActual->getUsuario()->getArbol()->insertar(new Activo(nombreActivo, descripcionActivo));

			menuUsuario(usuarioActual->getUsuario()->getNombre());
		}

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

		if (bandera) {

		}
		else {

			usuarioActual = nullptr;
			menuPrincipal();
		}

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


//Men� del Administrador
void adminMenu() {

	system("cls");
	char opcion;

	cout << "-------------------Bienvenido Administrador-------------------" << endl;
	cout << "-------------Escoja la opci�n que quiere realizar-------------" << endl;

	cout << "\n1. Registrar Usuarios\n2. Reportes Matriz Dispersa\n3. Reporte Usuarios Registrados";
	cout << "\n4. Reporte Activos Disponibles de un Departamento\n5. Reporte Activos Disponibles de una Empresa";
	cout << "\n6. Reporte Transacciones\n7. Reporte Activos de un usuario\n8. Activos rentados por un usuario\n9. Regresar..." << endl;

	cout << "\nEscoja una opci�n: ";
	cin >> opcion;

	eleccion(true, opcion);


}

//Men� del Usuario
void menuUsuario(string nombre) {

	system("cls");
	char opcion;

	cout << "-------------------Bienvenido " << nombre << "-------------------" << endl;
	cout << "-----------Escoja la opci�n que quiere realizar---------" << endl;

	cout << "\n1. Agregar Activo\n2. Eliminar Activo\n3. Modificar Activo";
	cout << "\n4. Rentar Activos\n5. Activos Rentados";
	cout << "\n6. Mis Activos Rentados\n7. Cerrar Sesion..." << endl;

	cout << "\nEscoja una ocpi�n: ";
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
