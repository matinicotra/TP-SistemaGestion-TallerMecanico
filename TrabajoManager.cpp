#include <iostream>
#include <string>

#include "ClienteArchivo.h"
#include "VehiculoArchivo.h"
#include "PresupuestoArchivo.h"
#include "TrabajoManager.h"
#include "ProveedorArchivo.h"

using namespace std;

int TrabajoManager::GenerarId() {
	return _archivo.GetCantidadRegistros() + 1;
}

bool TrabajoManager::ExisteId(int id) {
	return _archivo.Buscar(id) >= 0;
}

void TrabajoManager::Cargar() {
	VehiculoArchivo arcVehiculo;
	ClienteArchivo arcCliente;
	PresupuestoArchivo arcPresupuesto;
	ProveedorArchivo arcProveedor;

	Trabajo aux;
	int dia, mes, anio;
	char patente[10];
	char dni[10];
	string detalle;

	int id = GenerarId();
	aux.setIdTrabajo(id);

	//debemos pedir primero el dni del cliente, patente del vehiculo e id de presupuesto y validar que esten cargados, en caso contrario, llamar a los metodos de Cargar respectivamente

	system("cls");

	cout << "CARGAR NUEVO TRABAJO" << endl;
	cout << "--------------------" << endl;
	cout << "ID DEL TRABAJO : " << id << endl << endl;

	cout << "INGRESE PATENTE DEL VEHICULO: ";
	cin.ignore();
	cin.getline(patente, 9);
	while (arcVehiculo.Buscar(patente) == -1) {
		int opc;
		cout << "PATENTE INEXISTENTE" << endl;
		cout << "Presione '1' para ingresar nuevamente; '2' para cargar un nuevo vehiculo; '0' para salir: ";
		cin >> opc;

		switch (opc) {
		case 1:
			cout << "INGRESE PATENTE DEL VEHICULO: ";
			cin.ignore();
			cin.getline(patente, 9);
			break;
		case 2:
			cout << "cargar vehiculo..." << endl;
			// arcVehiculo.Cargar();
			//int pos = arcVehiculo.GetCantidadRegistros();
			//strcpy(patente, arcVehiculo.Leer(pos).getPatente());
			break;
		}
	}
	aux.setPatente(patente);

	cout << "DNI CLIENTE: ";
	cin.ignore();
	cin.getline(dni, 9);
	while (arcCliente.Buscar(dni) == -1) {
		int opc;
		cout << "DNI INEXISTENTE. " << endl;
		cout << "Presione '1' para ingresar nuevamente; '2' para cargar un nuevo cliente; '0' para salir: ";
		cin >> opc;

		switch (opc) {
		case 1:
			cout << "DNI CLIENTE: ";
			cin.ignore();
			cin.getline(dni, 9);
			break;
		case 2:
			cout << "cargar cliente..." << endl;
			// arcCliente.Cargar();
			//int pos = arcCliente.GetCantidadRegistros();
			//strcpy(dni, arcCliente.Leer(pos).getDni());
			break;
		case 0:
			break;
		}
	}
	aux.setDniCliente(dni);

	cout << "DNI PROVEEDOR: ";
	cin.ignore();
	cin.getline(dni, 9);
	while (arcProveedor.Buscar(dni) == -1) {
		int opc;
		cout << "DNI INEXISTENTE. " << endl;
		cout << "Presione '1' para ingresar nuevamente; '2' para cargar un nuevo proveedor; '0' para salir: ";
		cin >> opc;

		switch (opc) {
		case 1:
			cout << "DNI PROVEEDOR: ";
			cin.ignore();
			cin.getline(dni, 9);
			break;
		case 2:
			cout << "cargar proveedor..." << endl;
			// arcProveedor.Cargar();
			//int pos = arcProveedor.GetCantidadRegistros();
			//strcpy(dni, arcProveedor.Leer(pos).getDni());
			break;
		case 0:
			break;
		}
	}
	aux.setDniProveedor(dni);

	cout << "INGRESAR ID PRESUPUESTO: ";
	cin >> id;
	if (arcPresupuesto.Buscar(id) == -1) {
		//cargar presupuesto
	}

	bool band;
	int cantPresu = arcPresupuesto.GetCantidadRegistros();
	for (int i = 0; i < cantPresu; i++) {
		Presupuesto presupuesto = arcPresupuesto.Leer(i);
		if (!strcmp(patente, presupuesto.getPatente()) && presupuesto.getEstado()) {
			band = true;
		}
	}
	if (band) {
		aux.setIdPresupuesto(id);
	} else {
		//cargarpresupuesto();
		//int pos = arcPresupuesto.GetCantidadRegistros();
		//id = arcPresupuesto.Leer(pos).getIdPresupuesto();
		//aux.setIdPresupuesto(id);
	}

	cout << "DNI EMPLEADO DESIGNADO: ";
	cin.ignore();
	cin.getline(dni, 9);

	aux.setDniEmpleado(dni);


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

	cout << "INGRESAR DETALLE: " << endl;
	cin.ignore();
	getline(cin, detalle);
	aux.setDetalle(detalle);



	aux.setAvanceTrabajo(1);

	aux.setEstado(true);

	if (_archivo.Guardar(aux)) {
		cout << "Registro guardado existosamente." << endl;
	};
}
