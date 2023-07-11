#include "VehiculoManager.h"

#include <iostream>
using namespace std;

#include "ClienteManager.h"

void VehiculoManager::OrdenarPorFecha(Vehiculo *vec, int cantRegistros) {
	int mayor = 0;
	Vehiculo aux;
	for (int i = 0; i < cantRegistros - 1; i++) {
		mayor = i;
		for (int j = i + 1; j < cantRegistros; j++) {
			if (vec[j].getFechaAlta().toString("YYYY/MM/DD") > vec[mayor].getFechaAlta().toString("YYYY/MM/DD")) {
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

void VehiculoManager::OrdenarPorPatente(Vehiculo *vec, int cantRegistros) {
	int mayor = 0;
	Vehiculo aux;
	for (int i = 0; i < cantRegistros - 1; i++) {
		mayor = i;
		for (int j = i + 1; j < cantRegistros; j++) {
			if (vec[j].getPatente() > vec[mayor].getPatente()) {
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


void VehiculoManager::Cargar() {
	string patente, modelo, marca;
	int dia, mes, anio, anioModelo;

	cin.ignore();
	cout << "NUEVO VEHICULO" << endl;
	cout << "--------------" << endl;
	cout << "PATENTE      : ";
	getline(cin, patente);
	cout << "MARCA        : ";
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
	cout << "ANIO         : " ;
	cin >> anio;
	cout << endl;

	Vehiculo reg(patente, modelo, marca, anio, Fecha(dia, mes, anio));

	if (_archivo.Guardar(reg)) {
		cout << "Registro guardado existosamente!" << endl;
	} else cout << "Error al guardar el registro" << endl;
	system("pause");
}

void VehiculoManager::ListarTodos() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		Vehiculo vehiculo = _archivo.Leer(i);
		if (vehiculo.getEstado()) {
			ListarRegistro(vehiculo);
		}
	}
	system("pause");
}

void VehiculoManager::ListarRegistro(Vehiculo vehiculo) {
	cout << "PATENTE       : " << vehiculo.getPatente() << endl;
	cout << "MARCA         : " << vehiculo.getMarca() << endl;
	cout << "MODELO        : " << vehiculo.getModelo() << endl;
	cout << "ANIO          : " << vehiculo.getAnio() << endl;
	cout << "FECHA DE ALTA : " << vehiculo.getFechaAlta().toString("DD/MM/YYYY") << endl << endl;
}

void VehiculoManager::ListarPorPatente() {
	int pos;
	string patente;
	cin.ignore();
	cout << "INGRESAR LA PATENTE DEL VEHICULO: ";
	getline(cin, patente);
	pos = _archivo.Buscar(patente);
	Vehiculo vehiculo = _archivo.Leer(pos);
	if (pos >= 0 && vehiculo.getEstado() == true) {
		ListarRegistro(_archivo.Leer(pos));
	} else cout << "No exsite registro con la patente " << patente << endl;
	system("pause");
}

void VehiculoManager::ListarOrdenadosPorFechaAlta() {
	int cantReg = _archivo.GetCantidadRegistros();

	Vehiculo *vec = new Vehiculo[cantReg];
	if (vec == nullptr) {
		cout << "Error" << endl;
		return;
	}

	_archivo.Leer(vec, cantReg);
	OrdenarPorFecha(vec, cantReg);

	for (int i = 0; i < cantReg; i++) {
        Vehiculo aux = _archivo.Leer(i);
            if (aux.getEstado()){
		ListarRegistro(vec[i]);
		cout << endl;
	}}

	delete []vec;
	system("pause");
}

void VehiculoManager::ListarOrdenadosPorPatente() {
	int cantReg = _archivo.GetCantidadRegistros();

	Vehiculo *vec = new Vehiculo[cantReg];
	if (vec == nullptr) {
		cout << "Error" << endl;
		return;
	}

	_archivo.Leer(vec, cantReg);
	OrdenarPorPatente(vec, cantReg);

	for (int i = 0; i < cantReg; i++) {
        Vehiculo aux = _archivo.Leer(i);
            if (aux.getEstado()){
		ListarRegistro(vec[i]);
		cout << endl;
	}}

	delete []vec;
	system("pause");
}

void VehiculoManager::Eliminar() {
	int pos;
	string patente;

	cin.ignore();
	cout << "INGRESAR LA PATENTE DEL VEHICULO: ";
	getline(cin, patente);

	pos = _archivo.Buscar(patente);

		Vehiculo reg = _archivo.Leer(pos);
	if (pos >= 0 && reg.getEstado() == true) {
		ListarRegistro(reg);

		char opc;
		cout << endl << "Desea eliminar el registro? Ingresar 'S' para confirmar; 'N' para regresar.";
		cin >> opc;

		if (opc == 'S' || opc == 's') {
			reg.setEstado(false);

			if (_archivo.Guardar(reg, pos)) {
				cout << "Registro eliminado exitosamente." << endl;
			} else cout << "Error al eliminar el registro." << endl;

		} else if (opc == 'N' || opc == 'n') {
			cout << "No se realizaron modificaciones." << endl;
		} else cout << "El valor ingresado es incorrecto" << endl;
	} else cout << "Patente inexistente." << endl;

	system("pause");
}

void VehiculoManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	if (cantRegistros <= 0){
            cout << endl;
            cout << "No existe el archivo de Vehiculos" << endl;
            cout << endl;
            system("pause");
            return;}
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

	system("pause");
}

void VehiculoManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();

		if (cantRegistros <= 0){
            cout << endl;
            cout << "No existe el archivo de Vehiculos" << endl;
            system("pause");
            cout << endl;
            return;}

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

	system("pause");
}
