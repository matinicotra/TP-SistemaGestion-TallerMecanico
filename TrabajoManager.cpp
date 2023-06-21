#include <iostream>
#include <string>
#include "ClienteArchivo.h"
#include "VehiculoArchivo.h"
#include "PresupuestoArchivo.h"
#include "TrabajoManager.h"
using namespace std;

int TrabajoManager::GenerarId() {
	return _archivo.GetCantidadRegistros() + 1;
}

bool TrabajoManager::ExisteId(int id) {
	return _archivo.Buscar(id) >= 0;
}

void TrabajoManager::Cargar() {
	Trabajo aux;
	VehiculoArchivo arcVehiculo;
	ClienteArchivo arcCliente;
	PresupuestoArchivo arcPresupuesto;

	int id, opc, dia, mes, anio;
	char patente[10];
	char dni[10];
	string detalle;

	id = GenerarId();
	aux.setIdTrabajo(id);

	//debe pedir primero el dni del cliente, patente del vehiculo y id de presupuesto y validar que esten cargados, en caso contrario, llamar a los metodos de Cargar respectivamente

	cout << "CARGAR NUEVO TRABAJO" << endl;
	cout << "--------------------" << endl;
	cout << "ID DEL TRABAJO : " << id << endl << endl;

	do {
		cout << "INGRESE PATENTE DEL VEHICULO: ";
		cin.ignore();
		cin.getline(patente, 9);

		if (arcVehiculo.Buscar(patente) == -1) {
			cout << "Patente inexistente, presione '1' para ingresar nuevamente o '2' para cargar un nuevo vehiculo: ";
			cin >> opc;
		} else opc = 0;

		switch (opc) {
		case 1:
			break;
		case 2:
			cout << "cargar vehiculo..." << endl;
			// arcVehiculo.Cargar();
			//int idAux = arcVehiculo.GetCantidadRegistros();
			//strcpy(patente, arcVehiculo.Leer(idAux).getPatente());
			break;
		case 0:
			break;
		}
	} while (true);
	aux.setPatente(patente);

	cout << "DNI CLIENTE: ";
	cin.ignore();
	cin.getline(dni, 9);
	if (arcCliente.Buscar(dni) == -1) {
		//cargar cliente
	}
	aux.setDniCliente(dni);

	cout << "FECHA DE ENTRADA: " << endl;
	cout << "DIA:  ";
	cin >> dia;
	cout << "MES:   ";
	cin >> mes;
	cout << "ANIO:  ";
	cin >> anio;
	aux.setFechaEntrada(Fecha(dia, mes, anio));

	cout << "FECHA DE ENTREGA: " << endl;		//// si nos queda tiempo podriamos usar la funcion de "agregar dias" de la clase fecha y que la fecha de entrega se calcule sola
	cout << "DIA:  ";
	cin >> dia;
	cout << "MES:   ";
	cin >> mes;
	cout << "ANIO:  ";
	cin >> anio;
	aux.setFechaEntrega(Fecha(dia, mes, anio));

	cout << "DNI PROVEEDOR: ";
	cin.ignore();
	cin.getline(dni, 9);
	aux.setDniProveedor(dni);

	cout << "DNI EMPLEADO DESIGNADO: ";
	cin.ignore();
	cin.getline(dni, 9);
	aux.setDniEmpleado(dni);

	cout << "INGRESAR DETALLE: " << endl;
	cin.ignore();
	getline(cin, detalle);
	aux.setDetalle(detalle);

	cout << "INGRESAR ID PRESUPUESTO: ";
	cin >> id;
	if (arcPresupuesto.Buscar(id) == -1) {
		//cargar presupuesto
	}
	aux.setIdPresupuesto(id);

	aux.setAvanceTrabajo(1);

	aux.setEstado(true);

	if (_archivo.Guardar(aux)) {
		cout << "Registro guardado existosamente." << endl;
	};
}
