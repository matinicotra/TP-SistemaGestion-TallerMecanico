#include <iostream>
#include <string>

#include "Funciones.h"
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
	EmpleadoArchivo arcEmpleado;

	Trabajo aux;
	int opc, dia, mes, anio;
	string patente, dni, detalle, idPresu;

	int id = GenerarId();
	aux.setIdTrabajo(id);

	system("cls");

	cout << "CARGAR NUEVO TRABAJO" << endl;
	cout << "--------------------" << endl;
	cout << "ID DEL TRABAJO : " << id << endl << endl;

	cout << "1 - INGRESAR PATENTE DEL VEHICULO" << endl;
	cout << "2 - CARGAR NUEVO VEHICULO" << endl;
	cout << "Opcion: ";
	cin >> opc;
	switch (opc) {
	case 1:
		cout << "PATENTE: ";
		cin.ignore();
		getline(cin, patente);
		while (arcVehiculo.Buscar(patente) == -1) {
			cout << "Patente inexistente. Presione '0' para salir o intente nuevamente... : ";
			getline(cin, patente);
			if (patente == "0") break;
		}
		aux.setPatente(patente);
		break;
	case 2:
		///CARGAR VEHICULO
		int pos = arcVehiculo.GetCantidadRegistros();
		aux.setPatente(arcVehiculo.Leer(pos).getPatente());
		break;
	}

	cout << "1 - INGRESAR DNI DEL CLIENTE" << endl;
	cout << "2 - CARGAR NUEVO CLIENTE" << endl;
	cout << "Opcion: ";
	cin >> opc;
	switch (opc) {
	case 1:
		cout << "DNI: ";
		cin.ignore();
		getline(cin, dni);
		while (arcCliente.Buscar(dni) == -1) {
			cout << "DNI inexistente. Presione '0' para continuar o intente nuevamente... : ";
			getline(cin, dni);
			if (dni == "0") break;
		}
		aux.setDniCliente(dni);
	case 2:
		///CARGAR CLIENTE
		int pos = arcCliente.GetCantidadRegistros();
		aux.setDniCliente(arcCliente.Leer(pos).getDni());
		break;
	}

	cout << "INGRESAR DNI DEL PROVEEDOR DE REPUESTOS: ";
	getline(cin, dni);
	while (arcProveedor.Buscar(dni) == -1) {
		cout << "DNI inexistente. Presione '0' para continuar o intente nuevamente... : ";
		getline(cin, dni);
		if (dni == "0") break;
	}
	aux.setDniProveedor(dni);

	cout << "INGRESAR DNI DEL EMPLEADO DESIGNADO: ";
	getline(cin, dni);
	while (arcEmpleado.Buscar(dni) == -1) {
		cout << "DNI inexistente. Presione '0' para continuar o intente nuevamente... : ";
		getline(cin,dni);
		if(dni == "0") break;
	}
	aux.setDniEmpleado(dni);

	cout << "1 - INGRESAR ID DEL PRESUPUESTO";
	cout << "2 - CARGAR PRESUPUESTO";
	cin >> opc;
	switch (opc) {
	case 1:
		cout << "ID #: ";
		cin >> id;
		while (arcPresupuesto.Buscar(id) == -1) {
			cout << "No existe un presupuesto con ese ID. Intente nuevamente... : ";		////FALTA PODER SALIR DEL WHILE SIN ID
			cin >> id;
		}
		aux.setIdPresupuesto(id);
		break;
	case 2:
		///CARGAR PRESUPUESTO
		int pos = arcPresupuesto.GetCantidadRegistros();
		aux.setIdPresupuesto(arcPresupuesto.Leer(pos).getIdPresupuesto());
		break;
	}

	cout << "FECHA DE ENTRADA: " << endl;
	cout << "DIA:  ";
	cin >> dia;
	cout << "MES:   ";
	cin >> mes;
	cout << "ANIO:  ";
	cin >> anio;
	aux.setFechaEntrada(Fecha(dia, mes, anio));

	cout << "FECHA DE ENTREGA: " << endl;
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
