#include <iostream>
using namespace std;

#include "EmpleadoManager.h"

void EmpleadoManager::OrdenarPorSueldo(Empleado *vec, int cantRegistros) {
	int mayor = 0;
	Empleado aux;
	for (int i = 0; i < cantRegistros - 1; i++) {
		mayor = i;
		for (int j = i + 1; j < cantRegistros; j++) {
			if (vec[j].getSueldo() > vec[mayor].getSueldo()) {
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

void EmpleadoManager::OrdenarPorFecha(Empleado *vec, int cantRegistros) {
	int mayor = 0;
	Empleado aux;
	for (int i = 0; i < cantRegistros - 1; i++) {
		mayor = i;
		for (int j = i + 1; j < cantRegistros; j++) {
			if (vec[j].getFechaNacimiento().toString("YYYY/MM/DD") > vec[mayor].getFechaNacimiento().toString("YYYY/MM/DD")) {
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
	cout << "ANIO                : " ;
	cin >> anio;
	cout << endl;

	Empleado reg(dni, nombre, apellido, eMail, direccion, telefono, Fecha(dia, mes, anio), cargo, sueldo, cuentaBancaria);

	if (_archivo.Guardar(reg)) {
		cout << "Registro guardado existosamente!" << endl;
	} else cout << "Error al guardar el registro" << endl;
	system("pause");
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
	system("pause");
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
	string dni;
	cin.ignore();
	cout << "INGRESAR DNI DEL EMPLEADO: ";
	getline(cin, dni);
	int pos = _archivo.Buscar(dni);
	if (pos >= 0) {
		ListarRegistro(_archivo.Leer(pos));
	} else cout << "No exsite registro con DNI " << dni << endl;
	system("pause");
}

void EmpleadoManager::ListarOrdenadoPorSueldo() {
	int cantReg = _archivo.GetCantidadRegistros();

	Empleado *vec = new Empleado[cantReg];
	if (vec == nullptr) {
		cout << "Error" << endl;
		return;
	}

	_archivo.Leer(vec, cantReg);
	OrdenarPorSueldo(vec, cantReg);

	for (int i = 0; i < cantReg; i++) {
		ListarRegistro(vec[i]);
		cout << endl;
	}

	delete []vec;
	system("pause");
}

void EmpleadoManager::ListarOrdenadoPorFechaNacimiento() {
	int cantReg = _archivo.GetCantidadRegistros();

	Empleado *vec = new Empleado[cantReg];
	if (vec == nullptr) {
		cout << "Error" << endl;
		return;
	}

	_archivo.Leer(vec, cantReg);
	OrdenarPorFecha(vec, cantReg);

	for (int i = 0; i < cantReg; i++) {
		ListarRegistro(vec[i]);
		cout << endl;
	}

	delete []vec;
	system("pause");
}

void EmpleadoManager::EditarSueldo() {
	string dni;
	float sueldo;
	cin.ignore();
	cout << "INGRESAR DNI DEL EMPLEADO: ";
	getline(cin, dni);
	int pos = _archivo.Buscar(dni);
	if (pos >= 0) {
		Empleado reg = _archivo.Leer(pos);
		ListarRegistro(reg);
		cout << endl << "INGRESAR SUELDO: ";
		cin >> sueldo;
		reg.setSueldo(sueldo);
		if (_archivo.Guardar(reg)) {
			cout << "Registro guardado existosamente!" << endl;
		} else cout << "Error al guardar el registro." << endl;
	} else cout << "DNI inexistente." << endl;
	system("pause");
}

void EmpleadoManager::Eliminar() {
	string dni;
	cin.ignore();
	cout << "INGRESAR DNI DEL EMPLEADO: ";
	getline(cin, dni);
	int pos = _archivo.Buscar(dni);
	if (pos >= 0) {
		Empleado reg = _archivo.Leer(pos);
		ListarRegistro(reg);

		char opc;
		cout << endl << "Desea eliminar el registro? Ingresar 'S' para confirmar; 'N' para regresar.";
		cin >> opc;

		if (opc == 'S' || opc == 's') {
			reg.setEstado(false);

			if (_archivo.Guardar(reg)) {
				cout << "Registro eliminado exitosamente." << endl;
			} else cout << "Error al eliminar el registro." << endl;

		} else if (opc == 'N' || opc == 'n') {
			cout << "No se realizaron modificaciones." << endl;
		} else cout << "El valor ingresado es incorrecto" << endl;
	} else cout << "DNI inexistente." << endl;
	system("pause");
}

void EmpleadoManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
		if (cantRegistros <= 0){
            cout << endl;
            cout << "No existe el archivo de Empleados" << endl;
            cout << endl;
            system("pause");
            return;}
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
	system("pause");
}

void EmpleadoManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();
		if (cantRegistros <= 0){
            cout << endl;
            cout << "No existe el archivo de Empleados" << endl;
            cout << endl;
            system("pause");
            return;}
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
	system("pause");
}
