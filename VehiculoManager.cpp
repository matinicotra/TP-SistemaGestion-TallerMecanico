#include "VehiculoManager.h"

#include <iostream>
using namespace std;

#include "ClienteManager.h"

void VehiculoManager::Cargar() {
	string patente, modelo, marca;
	int dia, mes, anio, anioModelo;

	cout << "NUEVO VEHICULO" << endl;
	cout << "--------------" << endl;
	cout << "PATENTE      : ";
	getline(cin, patente);
	cout << "MARCA        :";
	getline(cin, marca);
	cout << "MODELO       : ";
	getline(cin, modelo);
	cout << "ANIO         : ";
	cin >> anioModelo;
	cout << "FECHA DE ALTA" << endl;
	cout << "DIA          : ";
	cin >> dia;
	cout << "MES          : ";
	cin >> mes;
	cout << "ANIO         :" ;
	cin >> anio;

	Vehiculo reg(patente, modelo, marca, anio, Fecha(dia, mes, anio));

	if (_archivo.Guardar(reg)) {
		cout << "Registro guardado existosamente!" << endl;
	} else cout << "Error al guardar el registro" << endl;
}

void VehiculoManager::ListarTodos() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		Vehiculo vehiculo = _archivo.Leer(i);
		if (vehiculo.getEstado()) {
			ListarRegistro(vehiculo);
			cout << endl;
		}
	}
}

void VehiculoManager::ListarRegistro(Vehiculo vehiculo) {
	cout << "PATENTE       : " << vehiculo.getPatente() << endl;
	cout << "MARCA         : " << vehiculo.getMarca() << endl;
	cout << "MODELO        : " << vehiculo.getModelo() << endl;
	cout << "ANIO          : " << vehiculo.getAnio() << endl;
	cout << "FECHA DE ALTA : " << vehiculo.getFechaAlta().toString("DD/MM/YYYY") << endl;
}

void VehiculoManager::ListarPorPatente() {
	int pos;
	string patente;
	cout << "INGRESAR LA PATENTE DEL VEHICULO: ";
	getline(cin, patente);
	pos = _archivo.Buscar(patente);
	if (pos >= 0) {
		ListarRegistro(_archivo.Leer(pos));
	} else cout << "No exsite registro con la patente " << patente << endl;
}

void VehiculoManager::Eliminar() {
	int pos;
	string patente;
	cout << "INGRESAR LA PATENTE DEL VEHICULO: ";
	getline(cin, patente);
	pos = _archivo.Buscar(patente);
	if (pos >= 0) {
		Vehiculo reg = _archivo.Leer(pos);
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
	} else cout << "Patente inexistente." << endl;
}

void VehiculoManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	Vehiculo *vec;

	vec = new Vehiculo[cantRegistros];
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

void VehiculoManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();
	Vehiculo *vec;

	vec = new Vehiculo[cantRegistros];
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
