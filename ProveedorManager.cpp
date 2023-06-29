#include <iostream>
using namespace std;

#include "ProveedorManager.h"

void ProveedorManager::OrdenarPorOrigen(Proveedor *vec, int cantRegistros) {
	int mayor = 0;
	Proveedor aux;
	for (int i = 0; i < cantRegistros - 1; i++) {
		mayor = i;
		for (int j = i + 1; j < cantRegistros; j++) {
			if (vec[j].getOrigenFabricacion() == vec[mayor].getOrigenFabricacion()) {
				mayor = j;
			}
		}
		if (i != mayor) {
			aux = vec[i];
			vec[i] = vec[mayor];
			vec[mayor] = aux;
		}
	}
}

void ProveedorManager::Cargar() {
	string dni, nombre, apellido, eMail, direccion, telefono, rubro, autoparte, origenFabricacion;

	system("cls");
	cout << "NOMBRE                : ";
	getline(cin, nombre);
	cout << "APELLIDO              : ";
	getline(cin, apellido);
	cout << "DNI                   : ";
	getline(cin, dni);
	cout << "EMAIL                 : ";
	getline(cin, eMail);
	cout << "DIRECCION             : ";
	getline(cin, direccion);
	cout << "TELEFONO              : ";
	getline(cin, telefono);
	cout << "RUBRO                 : ";
	getline(cin, rubro);
	cout << "AUTOPARTE             : ";
	getline(cin, autoparte);
	cout << "ORIGEN DE FABRICACION : ";
	getline(cin, origenFabricacion);
	cout << endl;

	Proveedor reg(dni, nombre, apellido, eMail, direccion, telefono, rubro, autoparte, origenFabricacion);

	if (_archivo.Guardar(reg)) {
		cout << "Registro guardado existosamente!" << endl;
	} else cout << "Error al guardar el registro" << endl;
	system("pause");
}

void ProveedorManager::ListarTodos() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		Proveedor proveedor = _archivo.Leer(i);
		if (proveedor.getEstado()) {
			ListarRegistro(proveedor);
			cout << endl;
		}
	}
	system("pause");
}

void ProveedorManager::ListarRegistro(Proveedor proveedor) {
	cout << "NOMBRE                : " << proveedor.getNombre() << endl;
	cout << "APELLIDO              : " << proveedor.getApellido() << endl;
	cout << "DNI                   : " << proveedor.getDni() << endl;
	cout << "EMAIL                 : " << proveedor.getEmail() << endl;
	cout << "DIRECCION             : " << proveedor.getDireccion() << endl;
	cout << "TELEFONO              : " << proveedor.getTelefono() << endl;
	cout << "RUBRO                 : " << proveedor.getRubro() << endl;
	cout << "AUTOPARTE             : " << proveedor.getAutoparte() << endl;
	cout << "ORIGEN DE FABRICACION : " << proveedor.getOrigenFabricacion() << endl;
}

void ProveedorManager::ListarPorDni() {
	int pos;
	string dni;
	cin.ignore();
	cout << "INGRESAR DNI DEL PROVEEDOR: ";
	getline(cin, dni);
	pos = _archivo.Buscar(dni);
	if (pos >= 0) {
		ListarRegistro(_archivo.Leer(pos));
	} else cout << "No exsite registro con DNI " << dni << endl;
	system("pause");
}

void ProveedorManager::ListarPorRubro() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	string rubro;
	cin.ignore();
	cout << "INGRESAR RUBRO: ";
	getline(cin, rubro);
	for (int i = 0; i < cantRegistros; i++) {
		Proveedor proveedor = _archivo.Leer(i);
		if (proveedor.getRubro() == rubro) {
			ListarRegistro(proveedor);
			cout << endl;
		}
	}
	system("pause");
}

void ProveedorManager::ListarPorOrigenFabricacion() {
	int cantRegistros = _archivo.GetCantidadRegistros();

	Proveedor *vec = new Proveedor[cantRegistros];
	if (vec == nullptr) {
		cout << "Error." << endl;
		return;
	}

	_archivo.Leer(vec, cantRegistros);
	OrdenarPorOrigen(vec, cantRegistros);

	for (int i = 0; i < cantRegistros; i++) {
		ListarRegistro(vec[i]);
		cout << endl;
	}

	delete []vec;
	system("pause");
}

void ProveedorManager::EditarTelefono() {
	string dni, telefono;

	cin.ignore();
	cout << "INGRESAR DNI DEL PROVEEDOR: ";
	getline(cin, dni);

	int pos = _archivo.Buscar(dni);

	if (pos >= 0) {
		Proveedor reg = _archivo.Leer(pos);
		ListarRegistro(reg);

		cout << endl << "INGRESAR NUEVO TELEFONO: ";
		getline(cin, telefono);
		reg.setTelefono(telefono);

		if (_archivo.Guardar(reg)) {
			cout << "Registro guardado existosamente!" << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "DNI inexistente." << endl;

	system("pause");
}

void ProveedorManager::Eliminar() {
	string dni;
	cout << "INGRESAR DNI DEL PROVEEDOR: ";
	getline(cin, dni);

	int pos = _archivo.Buscar(dni);
	if (pos >= 0) {
		Proveedor reg = _archivo.Leer(pos);
		ListarRegistro(reg);

		char opc;
		cout << endl << "Desea eliminar el registro? Ingresar 'S' para confirmar; 'N' para regresar: ";
		cin >> opc;

		if (opc == 'S' || opc == 's') {
			reg.setEstado(false);

			if (_archivo.Guardar(reg)) {
				cout << "Registro eliminado exitosamente." << endl;
			}
			else cout << "Error al eliminar el registro." << endl;
		}
		else if (opc == 'N' || opc == 'n') {
			cout << "No se realizaron modificaciones." << endl;
		} else cout << "El valor ingresado es incorrecto" << endl;
	} else cout << "DNI inexistente." << endl;

	system("pause");
}

void ProveedorManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	if (cantRegistros <= 0){
            cout << endl;
            cout << "No existe el archivo de Proveedores" << endl;
            cout << endl;
            system("pause");
            return;}
	Proveedor *vec;

	vec = new Proveedor[cantRegistros];
	if (vec == nullptr) {
		cout << "Error al realizar backup" << endl;
		return;
	}

	_archivo.Leer(vec, cantRegistros);
	_archivoBkp.Vaciar();
	if (_archivoBkp.Guardar(vec, cantRegistros)) {
		cout << "Backup realizado correctamente!" << endl;
	} else cout << "Error al realizar backup" << endl;

	delete []vec;
	system("pause");
}

void ProveedorManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();
	if (cantRegistros <= 0){
            cout << endl;
            cout << "No existe el archivo de Proveedores" << endl;
            cout << endl;
            system("pause");
            return;}
	Proveedor *vec;

	vec = new Proveedor[cantRegistros];
	if (vec == nullptr) {
		cout << "Error al realizar backup" << endl;
		return;
	}

	_archivoBkp.Leer(vec, cantRegistros);
	_archivo.Vaciar();
	if (_archivo.Guardar(vec, cantRegistros)) {
		cout << "Backup restaurado correctamente!" << endl;
	} else cout << "Error al restaurar backup" << endl;

	delete []vec;
	system("pause");
}
