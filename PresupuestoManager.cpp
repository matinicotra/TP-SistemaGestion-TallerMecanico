#include "PresupuestoManager.h"
#include "ClienteArchivo.h"
#include "ClienteManager.h"
#include "VehiculoArchivo.h"
#include "VehiculoManager.h"
#include "AutoClienteManager.h"

#include <iostream>
using namespace std;

int PresupuestoManager::GenerarId() {
	return _archivo.GetCantidadRegistros() + 1;
}

bool PresupuestoManager::ExisteId(int id) {
	return _archivo.Buscar(id) >= 0;
}

void PresupuestoManager::Cargar() {
	VehiculoArchivo arcVehiculo;
	ClienteArchivo arcCliente;

	string dniCliente, patente, detalle;
	float importe;
	int opc, id, dia, mes, anio;
	char valGrua, valSustitucion; //para validar la entrada de datos
	bool asistenciaGrua, vehiculoSustitucion;
	bool nuevoVehiculo = false;
	bool nuevoCliente = false;

	id = GenerarId();

	cout << "NUEVO PRESUPUESTO" << endl;
	cout << "-----------------" << endl << endl;

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
		break;
	case 2:
		VehiculoManager aux;
		aux.Cargar();
		int pos = arcVehiculo.GetCantidadRegistros();
		patente = arcVehiculo.Leer(pos).getPatente();
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
	case 2:
		ClienteManager aux;
		aux.Cargar();
		int pos = arcCliente.GetCantidadRegistros();
		dniCliente = arcCliente.Leer(pos).getDni();
		nuevoCliente = true;
		break;
	}

	cout << "INGRESAR IMPORTE TOTAL DEL TRABAJO: ";
	cin >> importe;

	cout << "INGRESAR DETALLE DEL TRABJO A REALIZAR: ";
	getline(cin, detalle);

	cout << "INGRESAR LA FECHA" << endl;
	cout << "DIA: ";
	cin >> dia;
	cout << "MES ";
	cin >> mes;
	cout << "ANIO: ";
	cin >> anio;

	cout << "INCLUYE ASISTENCIA DE GRUA, 'S' o 'N' :";
	cin >> valGrua;
	if  (valGrua == 's' || valGrua == 'S') {
		asistenciaGrua = true;
	} else if (valGrua == 'n' || valGrua == 'N') {
		asistenciaGrua = false;
	} else cout << "Valor ingresado incorrecto." << endl;

	cout << "INCLUYE VEHICULO DE SUSTITUCION, 'S' o 'N' :";
	cin >> valSustitucion;
	if  (valSustitucion == 's' || valSustitucion == 'S') {
		vehiculoSustitucion = true;
	} else if (valSustitucion == 'n' || valSustitucion == 'N') {
		vehiculoSustitucion = false;
	} else cout << "Valor ingresado incorrecto." << endl;

	Presupuesto reg(id, dniCliente, patente, importe, detalle, Fecha(dia, mes, anio), asistenciaGrua, vehiculoSustitucion);

	if (_archivo.Guardar(reg)) {
		if ((nuevoCliente && nuevoVehiculo) || (!nuevoCliente && nuevoVehiculo)) {
			AutoClienteManager aux;
			aux.Cargar(dniCliente, patente);
		}
		cout << "Registro guardado existosamente!" << endl;
	} else cout << "Error al guardar el registro" << endl;
}

void PresupuestoManager::ListarTodos() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		Presupuesto presupuesto = _archivo.Leer(i);
		if (presupuesto.getEstado()) {
			ListarRegistro(presupuesto);
			cout << endl;
		}
	}
}

void PresupuestoManager::ListarRegistro(Presupuesto presupuesto) {
	cout << "PRESUPUESTO ID # " << presupuesto.getIdPresupuesto() << endl;
	cout << "DNI CLIENTE    : " << presupuesto.getDniCliente() << endl;
	cout << "PATENTE        : " << presupuesto.getPatente() << endl;
	cout << "IMPORTE        $ " << presupuesto.getImporte() << endl;
	cout << "DETALLE        : " << presupuesto.getDetalle() << endl;
	cout << "FECHA          : ";
	presupuesto.getFecha().toString("DD/MM/YYYY");

	if (presupuesto.getAsistenciaGrua()) {
		cout << "CON ASISTENCIA DE GRUA" << endl;
	} else cout << "SIN ASISTENCIA DE GRUA" << endl;

	if (presupuesto.getVehiculoSustitucion()) {
		cout << "INCLUYE VEHICULO DE SUSTITUCION: SI" << endl;
	} cout << "INCLUYE VEHICULO DE SUSTITUCION: NO" << endl;
}

void PresupuestoManager::ListarPorId() {
	int id, pos;
	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;
	pos = _archivo.Buscar(id);
	if (pos >= 0) {
		ListarRegistro(_archivo.Leer(pos));
	} else cout << "No existe presupuesto con ID #" << id << endl;
}

void PresupuestoManager::ListarPorDni() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	string dni;
	bool existe = false;
	cout << "INGRESAR DNI DEL CLIENTE: ";
	getline(cin, dni);
	for (int i = 0; i < cantRegistros; i++) {
		Presupuesto presupuesto = _archivo.Leer(i);
		if (presupuesto.getEstado() && presupuesto.getDniCliente() == dni) {
			ListarRegistro(presupuesto);
			cout << endl;
			existe = true;
		}
	}
	if (!existe) cout << "No se encontraron registros con DNI " << dni << endl;
}

void PresupuestoManager::ListarPorPatente() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	string patente;
	bool existe = false;
	cout << "INGRESAR PATENTE DEL VEHICULO: ";
	getline(cin, patente);
	for (int i = 0; i < cantRegistros; i++) {
		Presupuesto presupuesto = _archivo.Leer(i);
		if (presupuesto.getEstado() && presupuesto.getDniCliente() == patente) {
			ListarRegistro(presupuesto);
			cout << endl;
			existe = true;
		}
	}
	if (!existe) cout << "No se encontraron registros con patente " << patente << endl;
}

void PresupuestoManager::EditarImporte() {
	int pos, id;
	float importe;
	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;
	pos = _archivo.Buscar(id);
	if (pos >= 0) {
		Presupuesto reg = _archivo.Leer(pos);
		ListarRegistro(reg);
		cout << endl << "INGRESAR NUEVO IMPORTE: ";
		cin >> importe;
		reg.setImporte(importe);
		if (_archivo.Guardar(reg)) {
			cout << "Registro guardado existosamente!" << endl;
		} cout << "Error al guardar el registro." << endl;
	} cout << "ID inexistente." << endl;
}

void PresupuestoManager::Eliminar() {
	int pos, id;

	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;

	pos = _archivo.Buscar(id);
	if (pos >= 0) {
		Presupuesto reg = _archivo.Leer(pos);
		ListarRegistro(reg);

		string opc;
		cout << endl << "Desea eliminar el registro? Ingresar 'S' para confirmar; 'N' para regresar.";
		cin.ignore();
		getline(cin, opc);

		if (opc == "S" || opc == "s") {
			reg.setEstado(false);

			if (_archivo.Guardar(reg)) {
				cout << "Registro eliminado exitosamente." << endl;
			}
			else cout << "Error al eliminar el registro." << endl;
		}
		else if (opc == "N" || opc == "n") {
			cout << "No se realizaron modificaciones." << endl;
		}
		else cout << "El valor ingresado es incorrecto" << endl;
	}
	else cout << "DNI inexistente." << endl;
}

void PresupuestoManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	Presupuesto *vec;

	vec = new Presupuesto[cantRegistros];
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

void PresupuestoManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();
	Presupuesto *vec;

	vec = new Presupuesto[cantRegistros];
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
