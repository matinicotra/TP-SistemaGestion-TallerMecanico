#include <iostream>
#include <string>
using namespace std;

#include "PresupuestoManager.h"
#include "ClienteArchivo.h"
#include "ClienteManager.h"
#include "VehiculoArchivo.h"
#include "VehiculoManager.h"
#include "AutoClienteManager.h"


int PresupuestoManager::GenerarId() {
	return _archivo.GetCantidadRegistros() + 1;
}

bool PresupuestoManager::ExisteId(int id) {
	return _archivo.Buscar(id) >= 0;
}


string PresupuestoManager::IngresarVehiculo(bool &nuevoVehiculo) {
	VehiculoArchivo arcVehiculo;
	VehiculoManager aux;
 	int opc, pos;
	string patente;

	do {
		cout << "1 - INGRESAR PATENTE DEL VEHICULO" << endl;
		cout << "2 - CARGAR NUEVO VEHICULO" << endl;
		cout << "0 - CONTINUAR SIN CARGAR" << endl;
		cout << "Opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:
			cin.ignore();
			cout << endl << "PATENTE: ";
			getline(cin, patente);
			while (arcVehiculo.Buscar(patente) == -1) {
				cout << "Patente inexistente, intente nuevamente... : ";
				getline(cin, patente);
				if (patente == "0") break;
			}
			nuevoVehiculo = false;
			break;
		case 2:
			aux.Cargar();
			pos = arcVehiculo.GetCantidadRegistros();
			patente = arcVehiculo.Leer(pos-1).getPatente();
			nuevoVehiculo = true;
			break;
		case 0:
			patente = "0";
			break;
		default:
			cout << "Opcion incorrecta." << endl;
			break;
		}
	} while (opc != 0 && opc != 1 && opc != 2);

	return patente;
}

string PresupuestoManager::IngresarCliente(bool &nuevoCliente) {
	ClienteArchivo arcCliente;
	ClienteManager aux;
	int opc, pos;
	string dni;

	do {
		cout << "1 - INGRESAR DNI DEL CLIENTE" << endl;
		cout << "2 - CARGAR NUEVO CLIENTE" << endl;
		cout << "0 - CONTINUAR SIN CARGAR" << endl;
		cout << "Opcion: ";
		cin >> opc;

		switch (opc) {
		case 1:
			cin.ignore();
			cout << endl << "DNI: ";
			getline(cin, dni);
			while (arcCliente.Buscar(dni) == -1) {
				cout << "DNI inexistente, intente nuevamente... : ";
				getline(cin, dni);
				if (dni == "0") break;
			}
			break;
		case 2:
			aux.Cargar();
			pos = arcCliente.GetCantidadRegistros();
			dni = arcCliente.Leer(pos-1).getDni();
			nuevoCliente = true;
			break;
		case 0:
			dni = "0";
			break;
		default:
			cout << "Opcion incorrecta." << endl;
			break;
		}
	} while (opc != 0 && opc != 1 && opc != 2);

	return dni;
}


void PresupuestoManager::Cargar() {
	VehiculoManager vehiculoManagerAux;
	ClienteManager clienteManagerAux;
	AutoClienteArchivo arcAutoCliente;

	string dniCliente, patente, detalle;
	float importe;
	int id, dia, mes, anio;
	char valGrua, valSustitucion; //para validar la entrada de datos
	bool asistenciaGrua, vehiculoSustitucion;
	bool nuevoVehiculo = false;
	bool nuevoCliente = false;

	id = GenerarId();

	cout << "NUEVO PRESUPUESTO" << endl;
	cout << "-----------------" << endl << endl;

	patente = IngresarVehiculo(nuevoVehiculo);

	cout << endl;

	if (!nuevoVehiculo) {								//si el vehiculo esta cargado asigna dni desde autocliente
		int pos = arcAutoCliente.BuscarPatente(patente);
		dniCliente = arcAutoCliente.Leer(pos).getDniCliente();
		cout << endl;
	}
	else {
		dniCliente = IngresarCliente(nuevoCliente);
	}

	cout << endl << "INGRESAR IMPORTE TOTAL DEL TRABAJO: ";
	cin >> importe;

	cin.ignore();
	cout << endl << "INGRESAR DETALLE DEL TRABJO A REALIZAR: ";
	getline(cin, detalle);

	cout << endl << "INGRESAR LA FECHA" << endl;
	cout << "DIA: ";
	cin >> dia;
	cout << "MES ";
	cin >> mes;
	cout << "ANIO: ";
	cin >> anio;
	cout << endl;

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
	system("pause");
}

void PresupuestoManager::ListarTodos() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		Presupuesto presupuesto = _archivo.Leer(i);
		if (presupuesto.getEstado()) {
			ListarRegistro(presupuesto);
		}
	}
	system("pause");
}

void PresupuestoManager::ListarRegistro(Presupuesto presupuesto) {
    if (presupuesto.getEstado()){
	cout << "PRESUPUESTO ID          # " << presupuesto.getIdPresupuesto() << endl;
	cout << "DNI CLIENTE             : " << presupuesto.getDniCliente() << endl;
	cout << "PATENTE                 : " << presupuesto.getPatente() << endl;
	cout << "IMPORTE                 $ " << presupuesto.getImporte() << endl;
	cout << "DETALLE                 : " << presupuesto.getDetalle() << endl;
	cout << "FECHA                   : " << presupuesto.getFecha().toString("DD/MM/YYYY") << endl << endl;
	cout << "ASISTENCIA DE GRUA      : ";
	if (presupuesto.getAsistenciaGrua()) {
		cout << "SI" << endl;
	} else cout << "NO" << endl;
	cout << "VEHICULO DE SUSTITUCION : ";
	if (presupuesto.getVehiculoSustitucion()) {
		cout << "SI" << endl;
	} else cout << "NO" << endl;
}}

void PresupuestoManager::ListarPorId() {
	int id;
	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;
	int pos = _archivo.Buscar(id);
	Presupuesto presupuesto = _archivo.Leer(pos);
	if (pos >= 0 && presupuesto.getEstado() == true) {
		ListarRegistro(_archivo.Leer(pos));
	} else cout << "No existe presupuesto con ID #" << id << endl;
	system("pause");
}

void PresupuestoManager::ListarPorDni() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	string dni;
	bool existe = false;

	cin.ignore();
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
	system("pause");
}

void PresupuestoManager::ListarPorPatente() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	string patente;
	bool existe = false;

	cin.ignore();
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
	system("pause");
}

void PresupuestoManager::EditarImporte() {
	int id;
	float importe;
	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;
	int pos = _archivo.Buscar(id);
	if (pos >= 0) {
		Presupuesto reg = _archivo.Leer(pos);
		ListarRegistro(reg);
		cout << endl << "INGRESAR NUEVO IMPORTE: ";
		cin >> importe;
		reg.setImporte(importe);
		if (_archivo.Guardar(reg, pos)) {
			cout << "Registro guardado existosamente!" << endl;
		} else cout << "Error al guardar el registro." << endl;
	} else cout << "ID inexistente." << endl;
	system("pause");
}

void PresupuestoManager::Eliminar() {
	int id;

	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;

	int pos = _archivo.Buscar(id);
	if (pos >= 0) {
		Presupuesto reg = _archivo.Leer(pos);
		ListarRegistro(reg);

		char opc;
		cout << endl << "Desea eliminar el registro? Ingresar 'S' para confirmar; 'N' para regresar.";
		cin >> opc;

		if (opc == 'S' || opc == 's') {
			reg.setEstado(false);

			if (_archivo.Guardar(reg, pos)) {
				cout << "Registro eliminado exitosamente." << endl;
			}
			else cout << "Error al eliminar el registro." << endl;
		}
		else if (opc == 'N' || opc == 'n') {
			cout << "No se realizaron modificaciones." << endl;
		}
		else cout << "El valor ingresado es incorrecto" << endl;
	}
	else cout << "DNI inexistente." << endl;
	system("pause");
}

void PresupuestoManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
		if (cantRegistros <= 0){
            cout << endl;
            cout << "No existe el archivo de Presupuestos" << endl;
            system("pause");
            cout << endl;
            return;}
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
	system("pause");
}

void PresupuestoManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();
		if (cantRegistros <= 0){
            cout << endl;
            cout << "No existe el archivo de Presupuestos" << endl;
            system("pause");
            cout << endl;
            return;}
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
	system("pause");
}
