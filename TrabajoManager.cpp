#include <iostream>
#include <string>
using namespace std;

#include "Funciones.h"
#include "ClienteArchivo.h"
#include "VehiculoArchivo.h"
#include "PresupuestoArchivo.h"
#include "ProveedorArchivo.h"
#include "EmpleadoArchivo.h"
#include "ClienteManager.h"
#include "VehiculoManager.h"
#include "AutoClienteManager.h"
#include "PresupuestoManager.h"
#include "TrabajoManager.h"

int TrabajoManager::GenerarId() {
	return _archivo.GetCantidadRegistros() + 1;
}

bool TrabajoManager::ExisteId(int id) {
	return _archivo.Buscar(id) >= 0;
}

void TrabajoManager::OrdenarPorFechaEntrada(Trabajo *vec, int cantRegistros) {
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

void TrabajoManager::OrdenarPorFechaEntrega(Trabajo *vec, int cantRegistros) {
	int mayor = 0;
	Trabajo aux;

	for (int i = 0; i < cantRegistros - 1; i++) {
		mayor = i;

		for (int j = i + 1; j < cantRegistros; j++) {
			if (vec[j].getFechaEntrega().toString("YYYY/MM/DD") > vec[mayor].getFechaEntrega().toString("YYYY/MM/DD")) {
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

string TrabajoManager::IngresarVehiculo(bool &nuevoVehiculo) {
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

string TrabajoManager::IngresarCliente(bool &nuevoCliente) {
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

int TrabajoManager::IngresarPresupuesto(float &precioTrabajo) {
	PresupuestoArchivo arcPresupuesto;
	PresupuestoManager aux;
	int opc, id, pos;

	do {
		cout << "1 - INGRESAR ID DEL PRESUPUESTO" << endl;
		cout << "2 - CARGAR NUEVO PRESUPUESTO" << endl;
		cout << "0 - CARGAR MAS TARDE" << endl;
		cin >> opc;

		switch (opc) {
		case 1:
			cout << "ID #: ";
			cin >> id;
			while (arcPresupuesto.Buscar(id) == -1) {
				cout << "No existe un presupuesto con ese ID. Intente nuevamente... : ";
				cin >> id;
			}
			pos = arcPresupuesto.Buscar(id);
			precioTrabajo = arcPresupuesto.Leer(pos).getImporte();					//asignamos el importe del presu al precio del trabajo
			break;
		case 2:
			aux.Cargar();
			pos = arcPresupuesto.GetCantidadRegistros();
			id = arcPresupuesto.Leer(pos-1).getIdPresupuesto();				//buscamos el ultimo id ingresado que corresponde al ultimo presu
			precioTrabajo = arcPresupuesto.Leer(pos-1).getImporte();		//asignamos al precio del trabajo el importe del presupuesto
			aux.AsignarTrabajo(id, true); 									//setea al presupuesto como que tiene un trabajo asignado
			break;
		case 0:
			return -1;
			precioTrabajo = 0;
			break;
		}
	} while (opc != 0 && opc != 1 && opc != 2);

	return id;
}

void TrabajoManager::Cargar() {
	ProveedorArchivo arcProveedor;
	EmpleadoArchivo arcEmpleado;
	AutoClienteArchivo arcAutoCliente;

	int dia, mes, anio, idPresupuesto;
	string patente, dniCliente, dniProveedor, dniEmpleado, detalle;
	bool nuevoCliente = false;
	bool nuevoVehiculo = false;
	float precioTrabajo;

	int id = GenerarId();

	system("cls");
	cout << "CARGAR NUEVO TRABAJO" << endl;
	cout << "--------------------" << endl;
	cout << "ID DEL TRABAJO : " << id << endl;
	cout << "--------------------" << endl << endl;

	patente = IngresarVehiculo(nuevoVehiculo);				//CARGAR VEHICULO

	cout << endl;

	if (!nuevoVehiculo) {										//si el vehiculo esta cargado asigna el dni del duenio desde autocliente
		int pos = arcAutoCliente.BuscarPatente(patente);
		dniCliente = arcAutoCliente.Leer(pos).getDniCliente();
		cout << endl;
	}
	else {
		dniCliente = IngresarCliente(nuevoCliente);			//CARGAR CLIENTE
	}

	idPresupuesto = IngresarPresupuesto(precioTrabajo);		//CARGAR PRESUPUESTO

	if (precioTrabajo == 0) {
		cout << endl << "INGRESAR PRECIO FINAL DEL TRABAJO: ";
		cin >> precioTrabajo;
	}

	cout << endl;

	cin.ignore();
	cout << "INGRESAR DNI DEL PROVEEDOR DE REPUESTOS: ";
	getline(cin, dniProveedor);
	while (arcProveedor.Buscar(dniProveedor) == -1) {
		cout << "DNI inexistente. Presione '0' para continuar sin cargar o intente nuevamente... : ";
		getline(cin, dniProveedor);
		if (dniProveedor == "0") break;
	}

	cout << endl;

	cout << "INGRESAR DNI DEL EMPLEADO DESIGNADO: ";
	getline(cin, dniEmpleado);
	while (arcEmpleado.Buscar(dniEmpleado) == -1) {
		cout << "DNI inexistente. Presione '0' para continuar sin cargar o intente nuevamente... : ";
		getline(cin, dniEmpleado);
		if(dniEmpleado == "0") break;
	}

	cout << endl;

	cout << "FECHA DE ENTRADA: " << endl;
	cout << "DIA:  ";
	cin >> dia;
	cout << "MES:   ";
	cin >> mes;
	cout << "ANIO:  ";
	cin >> anio;
	Fecha fechaEntrada(dia, mes, anio);

	cout << endl;
	cout << "FECHA DE ENTREGA: " << endl;
	cout << "DIA:  ";
	cin >> dia;
	cout << "MES:   ";
	cin >> mes;
	cout << "ANIO:  ";
	cin >> anio;
	Fecha fechaEntrega(dia, mes, anio);

	Trabajo reg(id, idPresupuesto, patente, dniCliente, dniProveedor, dniEmpleado, 1, fechaEntrada, fechaEntrega, precioTrabajo);
	reg.setEstado(true);

	if (_archivo.Guardar(reg)) {
		if ((nuevoCliente && nuevoVehiculo) || (!nuevoCliente && nuevoVehiculo)) {
			AutoClienteManager aux;
			aux.Cargar(dniCliente, patente);
		}
		cout << "Registro guardado existosamente!" << endl;
	} else {
		cout << "Error al guardar el registro" << endl;
	}

	system("pause");
}

void TrabajoManager::ListarPorId() {
	int id;
	cout << "INGRESAR ID DEL TRABAJO: ";
	cin >> id;
	int pos = _archivo.Buscar(id);
    Trabajo trabajo = _archivo.Leer(pos);
	if (pos >= 0 && trabajo.getEstado() == true ) {
		ListarRegistro(_archivo.Leer(pos));
	} else cout << "No exsite registro con ID #" << id << endl;
	system("pause");
}

void TrabajoManager::ListarTodos() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		Trabajo trabajo = _archivo.Leer(i);
		if (trabajo.getEstado()) {
			ListarRegistro(trabajo);
		}
	}
	system("pause");
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

	if (posCli >= 0) {
		cout << "CLIENTE            : " << arcCliente.Leer(posCli).getNombre() << " " << arcCliente.Leer(posCli).getApellido() << endl;
	} else cout << "CLIENTE            : SIN ASIGNAR" << endl;

	if (posEmp >= 0) {
		cout << "EMPLEADO DESIGNADO : " << arcEmpleado.Leer(posEmp).getNombre() << " " << arcEmpleado.Leer(posEmp).getApellido() << endl;
	} else cout << "EMPLEADO DESIGNADO : SIN ASIGNAR" << endl;

	if (posPresu >= 0) {
		cout << "DETALLE            : " << arcPresupuesto.Leer(posPresu).getDetalle() << endl;
		cout << "PRESUPUESTO:       $ " << arcPresupuesto.Leer(posPresu).getImporte() << endl;
	} else cout << "PRESUPUESTO        : SIN ASIGNAR " << endl;

	cout << "PRECIO FINAL       $ " << trabajo.getPrecioTrabajo() << endl;

	if (posProv >= 0) {
		cout << "PROVEEDOR          : " << arcProveedor.Leer(posProv).getNombre() << " " << arcProveedor.Leer(posProv).getApellido() << endl;
		cout << "REPUESTO           : " << arcProveedor.Leer(posProv).getAutoparte() << endl;
	} else cout << "PROVEEDOR          : SIN ASIGNAR" << endl;

	cout << "FECHA DE ENTRADA   : " << trabajo.getFechaEntrada().toString("DD/MM/YYYY") << endl;
	cout << "FECHA DE ENTREGA   : " << trabajo.getFechaEntrega().toString("DD/MM/YYYY") << endl;

	cout << "ESTADO             : ";
	if (trabajo.getAvanceTrabajo() == 1) cout << "DIAGNOSTICO" << endl << endl;
	if (trabajo.getAvanceTrabajo() == 2) cout << "DESMONTAJE" << endl << endl;
	if (trabajo.getAvanceTrabajo() == 3) cout << "ENSAMBLAJE" << endl << endl;
	if (trabajo.getAvanceTrabajo() == 4) cout << "FINALIZADO" << endl << endl;
	if (trabajo.getAvanceTrabajo() == 5) cout << "ENTREGADO" << endl << endl;
}

void TrabajoManager::ListarPorPatente() {
	std::string patente;
	bool bandera = false;
	int cantRegistros = _archivo.GetCantidadRegistros();

	cin.ignore();
	cout << "INGRESAR PATENTE: ";
	getline(cin, patente);

	for (int i = 0; i < cantRegistros; i++) {
		Trabajo trabajo = _archivo.Leer(i);
		if (trabajo.getPatente() == patente && trabajo.getEstado() == true) {
			ListarRegistro(trabajo);
			cout << endl;
			bandera = true;
		}
	}
	if (!bandera) cout << "No se realizaron trabajos con la patente " << patente << endl;
	system("pause");
}

void TrabajoManager::ListarPorDniCliente() {
	std::string dni;
	bool bandera = false;
	int cantRegistros = _archivo.GetCantidadRegistros();

	cin.ignore();
	cout << "INGRESAR DNI DEL CLIENTE: ";
	getline(cin, dni);

	for (int i = 0; i < cantRegistros; i++) {
		Trabajo trabajo = _archivo.Leer(i);
		if (trabajo.getDniCliente() == dni && trabajo.getAvanceTrabajo() <= 4 && trabajo.getEstado() == true) {
			ListarRegistro(trabajo);
			cout << endl;
			bandera = true;
		}
	}
	if (!bandera) cout << "No se realizaron trabajos con el DNI " << dni << endl;
	system("pause");
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
	opc = getInteger(1, 5);

	system("cls");

	for (int i = 0; i < cantRegistros; i++) {
		Trabajo trabajo = _archivo.Leer(i);
		if (trabajo.getAvanceTrabajo() == opc && trabajo.getEstado() == true) {
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
	system("pause");
}

void TrabajoManager::ListarOrdenadosPorFecha() {
	int cantRegistros = _archivo.GetCantidadRegistros();

	Trabajo *vec = new Trabajo[cantRegistros];
	if (vec == nullptr) {
		cout << "Error" << endl;
		return;
	}

	_archivo.Leer(vec, cantRegistros);
	OrdenarPorFechaEntrada(vec, cantRegistros);

	for (int i = 0; i < cantRegistros; i++) {
            Trabajo aux = _archivo.Leer(i);
            if (aux.getEstado()){
		ListarRegistro(vec[i]);
		cout << endl;
	}}

	delete []vec;
	system("pause");
}

void TrabajoManager::ListarEntregadosPorFecha() {
	int cantRegistros = _archivo.GetCantidadRegistros();

	Trabajo *vec = new Trabajo[cantRegistros];
	if (vec == nullptr) {
		cout << "Error" << endl;
		return;
	}

	_archivo.Leer(vec, cantRegistros);
	OrdenarPorFechaEntrega(vec, cantRegistros);

	for (int i = 0; i < cantRegistros; i++) {
		if (vec[i].getAvanceTrabajo() == 5 && vec[i].getEstado()) {
			ListarRegistro(vec[i]);
			cout << endl;
		}
	}

	delete []vec;
	system("pause");
}

void TrabajoManager::ListarPorEmpleado() {
	EmpleadoArchivo arcEmpleado;
	std::string dni;
	bool bandera = false;
	int cantRegistros = _archivo.GetCantidadRegistros();

	cin.ignore();
	cout << "INGRESAR DNI DEL EMPLEADO: ";
	getline(cin, dni);
	int pos = arcEmpleado.Buscar(dni);
    Empleado emp = arcEmpleado.Leer(pos);
	if (arcEmpleado.Buscar(dni) >= 0 && emp.getEstado() == true) {
		for (int i = 0; i < cantRegistros; i++) {
			Trabajo trabajo = _archivo.Leer(i);
			if (trabajo.getDniEmpleado() == dni && trabajo.getEstado() == true) {
				ListarRegistro(trabajo);
				cout << endl;
				bandera = true;
			}
		}
		if (!bandera) cout << "El empleado aun no realizo trabajos." << endl;
	} cout << "Dni inexistente." << endl;
	system("pause");
}

void TrabajoManager::ActualizarAvance() {
	int id, nuevoEstado;

	cout << "INGRESAR ID DEL TRABAJO: ";
	cin >> id;
	int pos = _archivo.Buscar(id);

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Trabajo trabajo = _archivo.Leer(pos);
		ListarRegistro(trabajo);

		cout << endl;
		cout << "NUEVO ESTADO:" << endl;
		cout << "1 - DIAGNOSTICO" << endl;
		cout << "2 - DESMONTAJE" << endl;
		cout << "3 - REPARACION" << endl;
		cout << "4 - ENSAMBLAJE" << endl;
		cout << "5 - FINALIZADO" << endl;
		cout << "Opcion: ";
		cin >> nuevoEstado;

		trabajo.setAvanceTrabajo(nuevoEstado);

		if (_archivo.Guardar(trabajo, pos)) {
			cout << "Registro #" << id << " editado existosamente." << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "ID inexistente." << endl;
	system("pause");
}

void TrabajoManager::ActualizarProveedor() {
	ProveedorArchivo arcProveedor;
	int id;
	string dniProveedor;

	cout << "INGRESAR ID DEL TRABAJO: ";
	cin >> id;
	int pos = _archivo.Buscar(id);

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Trabajo trabajo = _archivo.Leer(pos);
		ListarRegistro(trabajo);

		cout << endl << "LISTADO DE PROVEEDORES DISPONIBLES: " << endl;
		ProveedorManager aux;
		aux.ListarTodos();

		cin.ignore();
		cout << endl << "ASIGNAR DNI DEL PROVEEDOR: " << endl;
		getline(cin, dniProveedor);

		int posProveedor = arcProveedor.Buscar(dniProveedor);
		if (posProveedor >= 0 && arcProveedor.Leer(posProveedor).getEstado() == true) {
			trabajo.setDniProveedor(dniProveedor);
		} else {
			cout << "DNI incorrecto" << endl;
			return;
		}

		if (_archivo.Guardar(trabajo, pos)) {
			cout << "Registro #" << id << " editado existosamente." << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "ID inexistente." << endl;
	system("pause");
}

void TrabajoManager::ActualizarEmpleado() {
	EmpleadoArchivo arcEmpleado;
	int id;
	string dniEmpleado;

	cout << "INGRESAR ID DEL TRABAJO: ";
	cin >> id;
	int pos = _archivo.Buscar(id);

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Trabajo trabajo = _archivo.Leer(pos);
		ListarRegistro(trabajo);

		cout << endl << "LISTADO DE EMPLEADOS: " << endl;
		EmpleadoManager aux;
		aux.ListarTodos();

		cin.ignore();
		cout << endl << "ASIGNAR DNI DEL EMPLEADO: " << endl;
		getline(cin, dniEmpleado);

		int posEmpleado = arcEmpleado.Buscar(dniEmpleado);
		if (posEmpleado >= 0 && arcEmpleado.Leer(posEmpleado).getEstado() == true) {
			trabajo.setDniEmpleado(dniEmpleado);
		} else {
			cout << "DNI incorrecto." << endl;
			return;
		}

		if (_archivo.Guardar(trabajo, pos)) {
			cout << "Registro #" << id << " editado existosamente." << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "ID inexistente." << endl;
	system("pause");
}

void TrabajoManager::AsignarPresupuesto() {
	PresupuestoArchivo arcPresupuesto;
	int id, idPresupuesto;

	cout << "INGRESAR ID DEL TRABAJO: ";
	cin >> id;
	int pos = _archivo.Buscar(id);

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Trabajo trabajo = _archivo.Leer(pos);
		ListarRegistro(trabajo);

		cout << endl << "LISTADO DE PRESUPUESTOS SIN TRABAJO ASIGNADO: " << endl;
		PresupuestoManager aux;
		aux.ListarTodosSinAsignar();

		cout << endl << "ASIGNAR PRESUPUESTO ID #: ";
		cin >> idPresupuesto;

		int posPresupuesto = arcPresupuesto.Buscar(idPresupuesto);

		if (posPresupuesto >= 0 && arcPresupuesto.Leer(posPresupuesto).getEstado() == true) {
			trabajo.setIdPresupuesto(idPresupuesto);

			Presupuesto presupuesto = arcPresupuesto.Leer(posPresupuesto);
			presupuesto.setTrabajoAsignado(true);
			arcPresupuesto.Guardar(presupuesto, posPresupuesto);

		} else {
			cout << "ID incorrecto." << endl;
			return;
		}

		if (_archivo.Guardar(trabajo, pos)) {
			cout << "Registro #" << id << " editado existosamente." << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "ID inexistente." << endl;
	system("pause");
}

void TrabajoManager::ActualizarPrecio() {
	int id;
	float nuevoPrecio;

	cout << "INGRESAR ID DEL TRABAJO: ";
	cin >> id;
	int pos = _archivo.Buscar(id);

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Trabajo trabajo = _archivo.Leer(pos);
		ListarRegistro(trabajo);

		cout << endl << "ACTUALIZAR PRECIO FINAL DEL TRABAJO: " << endl;
		cin >> nuevoPrecio;

		trabajo.setPrecioTrabajo(nuevoPrecio);

		if (_archivo.Guardar(trabajo, pos)) {
			cout << "Registro #" << id << " editado existosamente." << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "ID inexistente." << endl;
	system("pause");
}

void TrabajoManager::Eliminar() {
	int id, pos;

	cout << "INGRESAR ID DE TRABAJO: ";
	cin >> id;
	pos = _archivo.Buscar(id);

		Trabajo reg = _archivo.Leer(pos);
	if (pos >= 0 && reg.getEstado() == true) {
		ListarRegistro(reg);

		char opc;
		cout << endl << "Desea eliminar el registro? Ingresar 'S' para confirmar; 'N' para regresar.";
		cin >> opc;

		if (opc == 'S' || opc == 's') {
			reg.setEstado(false);

			if (_archivo.Guardar(reg, pos)) {
				cout << "Registro #" << id << " eliminado exitosamente." << endl;
			} else cout << "Error al eliminar el registro." << endl;

		} else if (opc == 'N' || opc == 'n') {
			cout << "No se realizaron modificaciones." << endl;
		} else cout << "El valor ingresado es incorrecto" << endl;
	} else cout << "ID inexistente." << endl;
	system("pause");
}

void TrabajoManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
		if (cantRegistros <= 0){
            cout << endl;
            cout << "No existe el archivo de Trabajos" << endl;
            cout << endl;
            system("pause");
            return;}
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
	system("pause");
}

void TrabajoManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();
		if (cantRegistros <= 0){
            cout << endl;
            cout << "No existe el archivo de Trabajos" << endl;
            cout << endl;
            system("pause");
            return;}
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
	system("pause");
}

