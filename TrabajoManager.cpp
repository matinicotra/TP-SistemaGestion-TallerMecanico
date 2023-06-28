#include <iostream>
#include <string>

#include "Funciones.h"
#include "ClienteArchivo.h"
#include "VehiculoArchivo.h"
#include "PresupuestoArchivo.h"
#include "TrabajoManager.h"
#include "ProveedorArchivo.h"
#include "EmpleadoArchivo.h"
#include "ClienteManager.h"
#include "VehiculoManager.h"
#include "AutoClienteManager.h"
#include "PresupuestoManager.h"

using namespace std;

int TrabajoManager::GenerarId() {
	return _archivo.GetCantidadRegistros() + 1;
}

bool TrabajoManager::ExisteId(int id) {
	return _archivo.Buscar(id) >= 0;
}

void TrabajoManager::Ordenar(Trabajo *vec, int cantRegistros) {
	int mayor = 0;
	Trabajo aux;

	for (int i = 0; i < cantRegistros - 1; i++) {
		mayor = i;

		for (int j = i + 1; j < cantRegistros; j++) {
			if (vec[j].getFechaEntrada().toString("YYYY/MM/DD") > vec[mayor].getFechaEntrada().toString("YYYY/MM/DD")) {
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

void TrabajoManager::Cargar() {
	VehiculoArchivo arcVehiculo;
	ClienteArchivo arcCliente;
	PresupuestoArchivo arcPresupuesto;
	ProveedorArchivo arcProveedor;
	EmpleadoArchivo arcEmpleado;


	Trabajo reg;
	int opc, dia, mes, anio;
	string patente, dniCliente, dni, detalle, idPresu;
	bool nuevoCliente = false;
	bool nuevoVehiculo = false;

	int id = GenerarId();
	reg.setIdTrabajo(id);

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
		reg.setPatente(patente);
		break;
	case 2:
		VehiculoManager aux;
		aux.Cargar();
		int pos = arcVehiculo.GetCantidadRegistros();
		reg.setPatente(arcVehiculo.Leer(pos).getPatente());
		nuevoVehiculo = true;
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
		getline(cin, dniCliente);
		while (arcCliente.Buscar(dniCliente) == -1) {
			cout << "DNI inexistente. Presione '0' para continuar o intente nuevamente... : ";
			getline(cin, dniCliente);
			if (dniCliente == "0") break;
		}
		reg.setDniCliente(dniCliente);
	case 2:
		ClienteManager aux;
		aux.Cargar();
		int pos = arcCliente.GetCantidadRegistros();
		reg.setDniCliente(arcCliente.Leer(pos).getDni());
		nuevoCliente = true;
		break;
	}

	cout << "INGRESAR DNI DEL PROVEEDOR DE REPUESTOS: ";
	getline(cin, dni);
	while (arcProveedor.Buscar(dni) == -1) {
		cout << "DNI inexistente. Presione '0' para continuar o intente nuevamente... : ";
		getline(cin, dni);
		if (dni == "0") break;
	}
	reg.setDniProveedor(dni);

	cout << "INGRESAR DNI DEL EMPLEADO DESIGNADO: ";
	getline(cin, dni);
	while (arcEmpleado.Buscar(dni) == -1) {
		cout << "DNI inexistente. Presione '0' para continuar o intente nuevamente... : ";
		getline(cin,dni);
		if(dni == "0") break;
	}
	reg.setDniEmpleado(dni);

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
		reg.setIdPresupuesto(id);
		break;
	case 2:
		PresupuestoManager aux;
		aux.Cargar();
		int pos = arcPresupuesto.GetCantidadRegistros();
		reg.setIdPresupuesto(arcPresupuesto.Leer(pos).getIdPresupuesto());
		reg.setPrecioTrabajo(arcPresupuesto.Leer(pos).getImporte());
		break;
	}

	cout << "FECHA DE ENTRADA: " << endl;
	cout << "DIA:  ";
	cin >> dia;
	cout << "MES:   ";
	cin >> mes;
	cout << "ANIO:  ";
	cin >> anio;
	reg.setFechaEntrada(Fecha(dia, mes, anio));

	cout << "FECHA DE ENTREGA: " << endl;
	cout << "DIA:  ";
	cin >> dia;
	cout << "MES:   ";
	cin >> mes;
	cout << "ANIO:  ";
	cin >> anio;
	reg.setFechaEntrega(Fecha(dia, mes, anio));

	reg.setAvanceTrabajo(1);
	reg.setEstado(true);


	if (_archivo.Guardar(reg)) {
		if ((nuevoCliente && nuevoVehiculo) || (!nuevoCliente && nuevoVehiculo)) {
			AutoClienteManager aux;
			aux.Cargar(dniCliente, patente);
		}
		cout << "Registro guardado existosamente!" << endl;
	} cout << "Error al guardar el registro" << endl;
}

void TrabajoManager::ListarPorId() {
	int id, pos;

	cout << "INGRESAR ID DEL TRABAJO: ";
	cin >> id;
	pos = _archivo.Buscar(id);

	if (pos >= 0) {
		ListarRegistro(_archivo.Leer(pos));
	} else cout << "No exsite registro con ID #" << id << endl;
}

void TrabajoManager::ListarTodos() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		Trabajo trabajo = _archivo.Leer(i);
		if (trabajo.getEstado()) {
			ListarRegistro(trabajo);
			cout << endl;
		}
	}
}

void TrabajoManager::ListarRegistro(Trabajo trabajo) {
	ClienteArchivo arcCliente;
	EmpleadoArchivo arcEmpleado;
	PresupuestoArchivo arcPresupuesto;
	ProveedorArchivo arcProveedor;

	int posCli = arcCliente.Buscar(trabajo.getDniCliente());
	int posEmp = arcEmpleado.Buscar(trabajo.getDniEmpleado());
	int posPresu = arcPresupuesto.Buscar(trabajo.getIdPresupuesto());
	int posProv = arcProveedor.Buscar(trabajo.getDniProveedor());

	cout << endl << "ID DE TRABAJO:     # " << trabajo.getIdTrabajo() << endl;
	cout << "PATENTE            : " << trabajo.getPatente() << endl;
	cout << "CLIENTE            : " << arcCliente.Leer(posCli).getNombre() << " " << arcCliente.Leer(posCli).getApellido() << endl;
	cout << "EMPLEADO DESIGNADO : " << arcEmpleado.Leer(posEmp).getNombre() << " " << arcEmpleado.Leer(posEmp).getApellido() << endl;
	cout << "DETALLE            : " << arcPresupuesto.Leer(posPresu).getDetalle() << endl;
	cout << "PRESUPUESTO:       $ " << arcPresupuesto.Leer(posPresu).getImporte() << endl;
	cout << "PROVEEDOR          : " << arcProveedor.Leer(posProv).getNombre() << " " << arcProveedor.Leer(posProv).getApellido() << endl;
	cout << "REPUESTO           : " << arcProveedor.Leer(posProv).getAutoparte() << endl;
	cout << "FECHA DE ENTRADA   : " << trabajo.getFechaEntrada().toString("DD/MM/YYYY") << endl;
	cout << "FECHA DE ENTREGA   : " << trabajo.getFechaEntrega().toString("DD/MM/YYYY") << endl;
	cout << "ESTADO             : ";
	if (trabajo.getAvanceTrabajo() == 1) cout << "DIAGNOSTICO" << endl;
	if (trabajo.getAvanceTrabajo() == 2) cout << "DESMONTAJE" << endl;
	if (trabajo.getAvanceTrabajo() == 3) cout << "ENSAMBLAJE" << endl;
	if (trabajo.getAvanceTrabajo() == 4) cout << "FINALIZADO" << endl;
	if (trabajo.getAvanceTrabajo() == 5) cout << "ENTREGADO" << endl;
}

void TrabajoManager::ListarPorPatente() {
	std::string patente;
	bool bandera = false;
	int cantRegistros = _archivo.GetCantidadRegistros();

	cout << "INGRESAR PATENTE: ";
	getline(cin, patente);

	for (int i = 0; i < cantRegistros; i++) {
		Trabajo trabajo = _archivo.Leer(i);
		if (trabajo.getPatente() == patente) {
			ListarRegistro(trabajo);
			cout << endl;
			bandera = true;
		}
	}

	if (!bandera) cout << "No se realizaron trabajos con la patente " << patente << endl;
}

void TrabajoManager::ListarPorDniCliente() {
	std::string dni;
	bool bandera = false;
	int cantRegistros = _archivo.GetCantidadRegistros();

	cout << "INGRESAR DNI DEL CLIENTE: ";
	getline(cin, dni);

	for (int i = 0; i < cantRegistros; i++) {
		Trabajo trabajo = _archivo.Leer(i);
		if (trabajo.getDniCliente() == dni) {
			ListarRegistro(trabajo);
			cout << endl;
			bandera = true;
		}
	}

	if (!bandera) cout << "No se realizaron trabajos con el DNI " << dni << endl;
}

void TrabajoManager::ListarPorAvance() {
	int opc;
	int cantRegistros = _archivo.GetCantidadRegistros();
	bool bandera = false;

	cout << "LISTAR TRABAJOS POR AVANCE" << endl;
	cout << "--------------------------" << endl;
	cout << "1 - DIAGNOSTICO" << endl;
	cout << "2 - DESMONTAJE" << endl;
	cout << "3 - ENSAMBLAJE" << endl;
	cout << "4 - FINALIZADO" << endl;
	cout << "5 - ENTREGADO" << endl;
	cout << "Opcion: ";
	cin >> opc;

	system("cls");

	for (int i = 0; i < cantRegistros; i++) {
		Trabajo trabajo = _archivo.Leer(i);
		if (trabajo.getAvanceTrabajo() == opc) {
			ListarRegistro(trabajo);
			cout << endl;
			bandera = true;
		}
	}
	if (!bandera) {
		cout << "No hay trabajos en estado de ";
		if (opc == 1) cout << "diagnostico." << endl;
		if (opc == 2) cout << "desmontaje." << endl;
		if (opc == 3) cout << "reparacion." << endl;
		if (opc == 4) cout << "ensamblaje." << endl;
		if (opc == 5) cout << "finalizado." << endl;
	}
}

void TrabajoManager::ListarOrdenadosPorFecha() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	Trabajo *vec;

	vec = new Trabajo[cantRegistros];
	if (vec == nullptr) {
		cout << "Error al visualizar el listado.";
		return;
	}

	_archivo.Leer(vec, cantRegistros);
	Ordenar(vec, cantRegistros);

	for (int i = 0; i < cantRegistros; i++) {
		ListarRegistro(vec[i]);
		cout << endl;
	}

	delete []vec;
}

void TrabajoManager::ActualizarAvance() {
	int id, pos;

	cout << "INGRESAR ID DEL TRABAJO: ";
	cin >> id;
	pos = _archivo.Buscar(id);

	if (pos >= 0) {
		Trabajo reg = _archivo.Leer(pos);
		ListarRegistro(reg);
		cout << endl;

		int nuevoEstado;
		cout << "NUEVO ESTADO:" << endl;
		cout << "1 - DIAGNOSTICO" << endl;
		cout << "2 - DESMONTAJE" << endl;
		cout << "3 - REPARACION" << endl;
		cout << "4 - ENSAMBLAJE" << endl;
		cout << "5 - FINALIZADO" << endl;
		cout << "Opcion: ";
		cin >> nuevoEstado;

		reg.setAvanceTrabajo(nuevoEstado);

		if (_archivo.Guardar(reg)) {
			cout << "Registro #" << id << " editado existosamente." << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "ID inexistente." << endl;
}

void TrabajoManager::Eliminar() {
	int id, pos;

	cout << "INGRESAR ID DE TRABAJO: ";
	cin >> id;
	pos = _archivo.Buscar(id);

	if (pos >= 0) {
		Trabajo reg = _archivo.Leer(pos);
		ListarRegistro(reg);

		string opc;
		cout << endl << "Desea eliminar el registro? Ingresar 'S' para confirmar; 'N' para regresar.";
		cin.ignore();
		getline(cin, opc);

		if (opc == "S" || opc == "s") {
			reg.setEstado(false);

			if (_archivo.Guardar(reg)) {
				cout << "Registro #" << id << " eliminado exitosamente." << endl;
			} else cout << "Error al eliminar el registro." << endl;

		} else if (opc == "N" || opc == "n") {
			cout << "No se realizaron modificaciones." << endl;
		} else cout << "El valor ingresado es incorrecto" << endl;
	} else cout << "ID inexistente." << endl;
}

void TrabajoManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	Trabajo *vec;

	vec = new Trabajo[cantRegistros];
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

void TrabajoManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();
	Trabajo *vec;

	vec = new Trabajo[cantRegistros];
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

