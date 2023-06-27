#include "EmpleadoManager.h"
#include <iostream>
using namespace std;

void EmpleadoManager::Cargar() {
	string dni, nombre, apellido, eMail, direccion, telefono, cargo, cuentaBancaria;
	float sueldo;
	int dia, mes, anio;

	cout << "NOMBRE              : ";
	getline(cin, nombre);
	cout << "APELLIDO            : ";
	getline(cin, apellido);
	cout << "DNI                 : ";
	getline(cin, dni);
	cout << "EMAIL               : ";
	getline(cin, eMail);
	cout << "DIRECCION           : ";
	getline(cin, direccion);
	cout << "TELEFONO            : ";
	getline(cin, telefono);
	cout << "CARGO               : ";
	getline(cin, cargo);
	cout << "CUENTA BANCARIA     : ";
	getline(cin, cuentaBancaria);
	cout << "SUELDO              : ";
	cin >> sueldo;
	cout << "FECHA DE NACIMIENTO" << endl;
	cout << "DIA                 : ";
	cin >> dia;
	cout << "MES                 : ";
	cin >> mes;
	cout << "ANIO                :" ;
	cin >> anio;

	Empleado reg(dni, nombre, apellido, eMail, direccion, telefono, Fecha(dia, mes, anio), cargo, sueldo, cuentaBancaria);

	if (_archivo.Guardar(reg)) {
		cout << "Registro guardado existosamente!" << endl;
	} else cout << "Error al guardar el registro" << endl;
}

void EmpleadoManager::ListarTodos() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		Empleado empleado = _archivo.Leer(i);
		if (empleado.getEstado()) {
			ListarRegistro(empleado);
			cout << endl;
		}
	}
}

void EmpleadoManager::ListarRegistro(Empleado empleado) {
	cout << "NOMBRE               : " << empleado.getNombre() << endl;
	cout << "APELLIDO             : " << empleado.getApellido() << endl;
	cout << "DNI                  : " << empleado.getDni() << endl;
	cout << "EMAIL                : " << empleado.getEmail() << endl;
	cout << "DIRECCION            : " << empleado.getDireccion() << endl;
	cout << "TELEFONO             : " << empleado.getTelefono() << endl;
	cout << "CARGO                : " << empleado.getCargo() << endl;
	cout << "SUELDO               : " << empleado.getSueldo() << endl;
	cout << "CUENTA BANCARIA      : " << empleado.getCuentaBancaria() << endl;
	cout << "FECHA DE NACIMOIENTO : " << empleado.getFechaNacimiento().toString("DD/MM/YYYY") << endl;
}

void EmpleadoManager::ListarPorDni() {
	int pos;
	string dni;
	cout << "INGRESAR DNI DEL EMPLEADO: ";
	getline(cin, dni);
	pos = _archivo.Buscar(dni);
	if (pos >= 0) {
		ListarRegistro(_archivo.Leer(pos));
	} else cout << "No exsite registro con DNI " << dni << endl;
}

void EmpleadoManager::EditarSueldo() {
	int pos;
	string dni;
	float sueldo;
	cout << "INGRESAR DNI DEL EMPLEADO: ";
	getline(cin, dni);
	pos = _archivo.Buscar(dni);
	if (pos >= 0) {
		Empleado reg = _archivo.Leer(pos);
		ListarRegistro(reg);
		cout << endl << "INGRESAR SUELDO: ";
		cin >> sueldo;
		reg.setSueldo(sueldo);
		if (_archivo.Guardar(reg)) {
			cout << "Registro guardado existosamente!" << endl;
		} cout << "Error al guardar el registro." << endl;
	} cout << "DNI inexistente." << endl;
}

void EmpleadoManager::Eliminar() {
	int pos;
	string dni;
	cout << "INGRESAR DNI DEL EMPLEADO: ";
	getline(cin, dni);
	pos = _archivo.Buscar(dni);
	if (pos >= 0) {
		Empleado reg = _archivo.Leer(pos);
		ListarRegistro(reg);

		string opc;
		cout << endl << "Desea eliminar el registro? Ingresar 'S' para confirmar; 'N' para regresar.";
		cin.ignore();
		getline(cin, opc);

		if (opc == "S" || opc == "s") {
			reg.setEstado(false);

			if (_archivo.Guardar(reg)) {
				cout << "Registro eliminado exitosamente." << endl;
			} else cout << "Error al eliminar el registro." << endl;

		} else if (opc == "N" || opc == "n") {
			cout << "No se realizaron modificaciones." << endl;
		} else cout << "El valor ingresado es incorrecto" << endl;
	} else cout << "DNI inexistente." << endl;
}

void EmpleadoManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	Empleado *vec;

	vec = new Empleado[cantRegistros];
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
}

void EmpleadoManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();
	Empleado *vec;

	vec = new Empleado[cantRegistros];
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
}
