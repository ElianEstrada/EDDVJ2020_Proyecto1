#include "MenuPrincipal.h"
#include "MatrizDispersa.h"

const string admin = "admin";
const string ctrAdmin = "admin";
NodoMatriz* usuarioActual = nullptr;

MatrizDispersa* matriz = new MatrizDispersa();


//Menu Principal
void menuPrincipal()
{

	matriz->insertarUsuario(new Usuario("ELIAN", "ELIADELYN", "PINPONPAN"), "GUATEMALA", "MAX");
	matriz->insertarUsuario(new Usuario("ALEX", "AFML98", "1234"), "GUATEMALA", "WALMART");
	matriz->insertarUsuario(new Usuario("ALLAN", "ALLANWEB", "4321"), "GUATEMALA", "MAX");
	matriz->insertarUsuario(new Usuario("NORMAN", "NORKY", "ABCD"), "JALAPA", "WALMART");

	system("cls");
	char opcion;

	cout << "-------------------BIENVENIDOS-------------------" << endl;
	cout << "----------------Inicio de Sesión-----------------" << endl;

	cout << "\n1. Como Administrador\n2. Como Usuario\n3. Salir" << endl;
	cout << "\nEscoja una opción: ";
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
	case '3':
		cout << "\nAdios, Vuelva pronto n_n...";
		cin.ignore();
		cin.get();
		exit(0);

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

	cout << "----------------Iniciar de Sesión-----------------" << endl;
	cout << "\nIngrese su nombre de usurario: ";
	getline(cin, usuario);
	cout << "Ingrese su contraseña: ";
	getline(cin, contrasenia);
	if (bandera)
	{
		cout << "Ingrese su Departamento: ";
		getline(cin, departamento);
		cout << "Ingrese su Empresa: ";
		getline(cin, empresa);

		NodoMatriz* aux = matriz->existe(matriz->buscarDepartamento(strCast(departamento)), strCast(empresa));
		if (aux != nullptr) {
			do{
				if (aux->getUsuario()->getUsuario() == strCast(usuario) && aux->getUsuario()->getContraseña() == strCast(contrasenia)) {
					usuarioActual = aux;
					menuUsuario(usuario);
				}

				aux = aux->getAtras();
			} while (aux != nullptr);

			cout << "\nEl usuario o la contraseña estan incorrectas..." << endl;
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
	string idActivo;
	string nuevaDescripcion;
	string diasRenta;

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
			cout << "Ingrese la contraseña: ";
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

			usuarioActual->getUsuario()->getArbol()->insertar(new Activo(strCast(nombreActivo), strCast(descripcionActivo)));

			menuUsuario(usuarioActual->getUsuario()->getNombre());
		}
		break;
	case '2':

		if (bandera) {

		}
		else {
			system("cls");
			cout << "--------------------ELIMINAR ACTIVO--------------------" << endl;
			if (!usuarioActual->getUsuario()->getArbol()->preOrden()) {
				cout << "No hay activos...";
				cin.ignore();
				menuUsuario(usuarioActual->getUsuario()->getNombre());
			}
			cout << "\n\nIngrese el ID del activo a eliminar: ";
			getline(cin, idActivo);

			usuarioActual->getUsuario()->getArbol()->eliminar(idActivo);

			cin.ignore();
			menuUsuario(usuarioActual->getUsuario()->getNombre());
		}

		break;
	case '3':

		if (bandera) {

		}
		else {
			system("cls");
			cout << "--------------------MODIFICAR ACTIVO--------------------" << endl;
			if (!usuarioActual->getUsuario()->getArbol()->preOrden()) {
				cout << "No hay activos...";
				cin.ignore();
				menuUsuario(usuarioActual->getUsuario()->getNombre());
			}
			cout << "\n\nIngrese el ID del activo a modificar: ";
			getline(cin, idActivo);
			cout << "\nIngrese la nueva descripcion: ";
			getline(cin, nuevaDescripcion);

			if (usuarioActual->getUsuario()->getArbol()->modificarActivo(idActivo, strCast(nuevaDescripcion))) {
				cout << "\nActivo Modificado exitosamente...";
				cin.ignore();
				menuUsuario(usuarioActual->getUsuario()->getNombre());
			}
			else {
				cout << "\nNo existe el activo...";
				cin.ignore();
				menuUsuario(usuarioActual->getUsuario()->getNombre());
			}

		}

		break;
	case '4':

		if (bandera) {

		}
		else {

			system("cls");
			cout << "--------------------CATALOGO DE ACTIVOS--------------------" << endl;
			
			matriz->catalogoActivos(usuarioActual->getUsuario(), true, "");
			cout << "\n\nIngrese el ID del activo a Rentar: ";
			getline(cin, idActivo);

			NodoAVL* activoRentado = matriz->catalogoActivos(usuarioActual->getUsuario(), false, idActivo);

			if (activoRentado != nullptr) {

				cout << "\nActivo a Rentar: " << endl;
				cout << "\n>> ID = " << activoRentado->getActivo()->getID() << "; Nombre = " << activoRentado->getActivo()->getNombre() << "; Descripcion = " << activoRentado->getActivo()->getDescripcion() << endl;
				activoRentado->getActivo()->setDisponible(false);

				cout << "\nIngrese los dias por rentar: ";
				cin >> diasRenta;

				menuUsuario(usuarioActual->getUsuario()->getNombre());
			}
			else {
				cout << "El activo no existe...";
				cin.ignore();
				menuUsuario(usuarioActual->getUsuario()->getNombre());
			}

			cin.ignore();
			cin.get();

		}

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

	cout << "\n1. Agregar Activo\n2. Eliminar Activo\n3. Modificar Activo";
	cout << "\n4. Rentar Activos\n5. Activos Rentados";
	cout << "\n6. Mis Activos Rentados\n7. Cerrar Sesion..." << endl;

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
