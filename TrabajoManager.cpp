#include <iostream>
#include <string>

#include "ClienteArchivo.h"
#include "VehiculoArchivo.h"
#include "PresupuestoArchivo.h"
#include "TrabajoManager.h"
#include "ProveedorArchivo.h"
#include "EmpleadoArchivo.h"

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
	string patente, dni, detalle;

	int id = GenerarId();
	aux.setIdTrabajo(id);

	//debemos pedir primero el dni del cliente, patente del vehiculo e id de presupuesto y validar que esten cargados, en caso contrario, llamar a los metodos de Cargar respectivamente

	system("cls");

	cout << "CARGAR NUEVO TRABAJO" << endl;
	cout << "--------------------" << endl;
	cout << "ID DEL TRABAJO : " << id << endl << endl;

	cout << "INGRESE PATENTE DEL VEHICULO: ";
	cin.ignore();
	getline(cin, patente);
	while (arcVehiculo.Buscar(patente) == -1) {
		int opc;
		cout << "PATENTE INEXISTENTE" << endl;
		cout << "Presione '1' para ingresar nuevamente; '2' para cargar un nuevo vehiculo; '0' para salir: ";
		cin >> opc;

		switch (opc) {
		case 1:
			cout << "INGRESE PATENTE DEL VEHICULO: ";
			cin.ignore();
			getline(cin, patente);
			break;
		case 2:
			cout << "cargar vehiculo..." << endl;
			// arcVehiculo.Cargar();
			//int pos = arcVehiculo.GetCantidadRegistros();
			//strcpy(patente, arcVehiculo.Leer(pos).getPatente());
			break;
		case 0:
			return;
			break;
		}
	}
	aux.setPatente(patente);

	cout << "INGRESAR DNI DEL CLIENTE: ";
	cin.ignore();
	getline(cin, dni);
	while (arcCliente.Buscar(dni) == -1) {
		int opc;
		cout << "DNI INEXISTENTE. " << endl;
		cout << "Presione '1' para ingresar nuevamente; '2' para cargar un nuevo cliente; '0' para salir: ";
		cin >> opc;

		switch (opc) {
		case 1:
			cout << "DNI CLIENTE: ";
			cin.ignore();
			getline(cin, dni);
			break;
		case 2:
			cout << "cargar cliente..." << endl;
			// arcCliente.Cargar();
			//int pos = arcCliente.GetCantidadRegistros();
			//strcpy(dni, arcCliente.Leer(pos).getDni());
			break;
		case 0:
			return;
			break;
		}
	}
	aux.setDniCliente(dni);

	cout << "INGRESAR DNI DEL PROVEEDOR: ";
	cin.ignore();
	getline(cin, dni);
	while (arcProveedor.Buscar(dni) == -1) {
		int opc;
		cout << "DNI INEXISTENTE. " << endl;
		cout << "Presione '1' para ingresar nuevamente; '2' para cargar un nuevo proveedor; '0' para salir: ";
		cin >> opc;

		switch (opc) {
		case 1:
			cout << "DNI PROVEEDOR: ";
			cin.ignore();
			getline(cin, dni);
			break;
		case 2:
			cout << "cargar proveedor..." << endl;
			// arcProveedor.Cargar();
			//int pos = arcProveedor.GetCantidadRegistros();
			//strcpy(dni, arcProveedor.Leer(pos).getDni());
			break;
		case 0:
			return;
			break;
		}
	}
	aux.setDniProveedor(dni);

	///PRESUPUESTO
	bool band;
	int cantPresu = arcPresupuesto.GetCantidadRegistros();
	for (int i = 0; i < cantPresu; i++) {
		Presupuesto presupuesto = arcPresupuesto.Leer(i);
		if (presupuesto.getPatente() == patente && presupuesto.getEstado()) {
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
	getline(cin, dni);
	aux.setDniEmpleado(dni);		// VALIDAR PRIMERO

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

	aux.setAvanceTrabajo(1);

	aux.setEstado(true);

	if (_archivo.Guardar(aux)) {
		cout << "Registro guardado existosamente." << endl;
	};
}

void TrabajoManager::Listar(Trabajo trabajo) {
	ClienteArchivo arcCliente;
	EmpleadoArchivo arcEmpleado;
	PresupuestoArchivo arcPresupuesto;
	ProveedorArchivo arcProveedor;

	int posCli = arcCliente.Buscar(trabajo.getDniCliente());
	int posEmp = arcEmpleado.Buscar(trabajo.getDniEmpleado());
	int posPresu = arcPresupuesto.Buscar(trabajo.getIdPresupuesto());
	int posProv = arcProveedor.Buscar(trabajo.getDniProveedor());

	cout << "ID DE TRABAJO:     # " << trabajo.getIdTrabajo() << endl;
	cout << "PATENTE            : " << trabajo.getPatente() << endl;
	cout << "CLIENTE            : " << arcCliente.Leer(posCli).getNombre() << " " << arcCliente.Leer(posCli).getApellido() << endl;
	cout << "EMPLEADO DESIGNADO : " << arcEmpleado.Leer(posEmp).getNombre() << " " << arcEmpleado.Leer(posEmp).getApellido() << endl;
	cout << "DETALLE            : " << arcPresupuesto.Leer(posPresu).getDetalle() << endl;
	cout << "PRESUPUESTO:       $ " << arcPresupuesto.Leer(posPresu).getImporte() << endl;
	cout << "PROVEEDOR          : " << arcProveedor.Leer(posProv).getNombre() << " " << arcProveedor.Leer(posProv).getApellido() << endl;
	cout << "REPUESTO           : " << arcProveedor.Leer(posProv).getAutoparte() << endl;
	cout << "FECHA DE ENTRADA   : " << trabajo.getFechaEntrada().toString("DD/MM/YYYY") << endl;
	cout << "FECHA DE ENTREGA   : " << trabajo.getFechaEntrega().toString("DD/MM/YYYY") << endl;

}
