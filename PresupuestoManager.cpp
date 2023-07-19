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
 	int pos;
	string patente, entrada;
	bool bandera = true;

	do {
	    system("cls");
        cout << "====== CARGAR PRESUPUESTO =======" << endl;
		cout << "1 - INGRESAR PATENTE DEL VEHICULO" << endl;
		cout << "2 - CARGAR NUEVO VEHICULO" << endl;
		cout << "3 - CONTINUAR SIN CARGAR" << endl << endl;
		cout << "Opcion: ";
		cin >> entrada;
		if (entrada.length() != 1 || !std::isdigit(entrada[0]))
        {
            std::cout << "Error: Intente nuevamente." << std::endl;
            system ("pause");
        }
        else
        {


		switch (stoi(entrada)) {
		case 1:
			cin.ignore();
			cout << endl << "PATENTE: ";
			getline(cin, patente);
			while (arcVehiculo.Buscar(patente) == -1) {
				cout << "Patente inexistente: ingrese 0 para salir o intente nuevamente... : ";
				getline(cin, patente);
				if (patente == "0") break;
			}
			nuevoVehiculo = false;
			bandera = false;
			break;
		case 2:
			aux.Cargar();
			pos = arcVehiculo.GetCantidadRegistros();
			patente = arcVehiculo.Leer(pos-1).getPatente();
			nuevoVehiculo = true;
			bandera = false;
			break;
		case 3:
			patente = "0";
			bandera = false;
			break;
		default:
			cout << "Opcion incorrecta: Intente nuevamente." << endl;
			system("pause");
			break;
		}
	} }while (bandera);

	return patente;
}

string PresupuestoManager::IngresarCliente(bool &nuevoCliente) {
	ClienteArchivo arcCliente;
	ClienteManager aux;
	int pos;
	string dni, entrada;
	bool bandera = true;

	do {
        system("cls");
        cout << "====== CARGAR PRESUPUESTO =======" << endl;
		cout << "1 - INGRESAR DNI DEL CLIENTE" << endl;
		cout << "2 - CARGAR NUEVO CLIENTE" << endl;
		cout << "3 - CONTINUAR SIN CARGAR" << endl;
		cout << "Opcion: ";
		cin >> entrada;
		if (entrada.length() != 1 || !std::isdigit(entrada[0]))
        {
            std::cout << "Error: Intente nuevamente." << std::endl;
            system ("pause");
        }
        else
        {

		switch (stoi(entrada)) {
		case 1:
			cin.ignore();
			cout << endl << "DNI: ";
			getline(cin, dni);
			while (arcCliente.Buscar(dni) == -1) {
				cout << "DNI inexistente: ingrese 0 para salir o intente nuevamente... : ";
				getline(cin, dni);
				if (dni == "0") break;
			}
			bandera = false;
			break;
		case 2:
			aux.Cargar();
			pos = arcCliente.GetCantidadRegistros();
			dni = arcCliente.Leer(pos-1).getDni();
			nuevoCliente = true;
			bandera = false;
			break;
		case 3:
			dni = "0";
			bandera = false;
			break;
		default:
			cout << "Opcion incorrecta." << endl;
			system("pause");
			break;
		}
	}} while (bandera);

	return dni;
}


void PresupuestoManager::Cargar() {
	VehiculoManager vehiculoManagerAux;
	ClienteManager clienteManagerAux;
	AutoClienteArchivo arcAutoCliente;

	string dniCliente, patente, detalle;
	float importe;
	int id;
	string dia, mes, anio;
	char valGrua, valSustitucion; //para validar la entrada de datos
	bool asistenciaGrua, vehiculoSustitucion;
	bool nuevoVehiculo = false;
	bool nuevoCliente = false;

	id = GenerarId();

	system("cls");
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
    do {
        cout << endl << "INCLUYE ASISTENCIA DE GRUA, 'S' o 'N' :";
        cin >> valGrua;
        if  (valGrua == 's' || valGrua == 'S') {
            asistenciaGrua = true;
        } else if (valGrua == 'n' || valGrua == 'N') {
            asistenciaGrua = false;
        } else cout << "Valor ingresado incorrecto." << endl;
    } while (valGrua != 's' && valGrua != 'S' && valGrua != 'n' && valGrua != 'N');

    do {
        cout << endl << "INCLUYE VEHICULO DE SUSTITUCION, 'S' o 'N' :";
        cin >> valSustitucion;
        if  (valSustitucion == 's' || valSustitucion == 'S') {
            vehiculoSustitucion = true;
        } else if (valSustitucion == 'n' || valSustitucion == 'N') {
            vehiculoSustitucion = false;
        } else cout << "Valor ingresado incorrecto." << endl;
    } while (valSustitucion != 's' && valSustitucion != 'S' && valSustitucion != 'n' && valSustitucion != 'N');

	bool trabajoAsignado = false;

	Presupuesto reg;
	Fecha aux;

	if ((dia.length() > 2 || !isdigit(dia[0])) || (mes.length() > 2 || !isdigit(mes[0])) || (anio.length() > 4 || !isdigit(anio[0])) || aux.esFechaValida(stoi(dia), stoi(mes),stoi(anio)) == false){
	reg = Presupuesto (id, dniCliente, patente, importe, detalle, Fecha(), trabajoAsignado, asistenciaGrua, vehiculoSustitucion);
	cout << "Error en la fecha. Cargada con fecha de hoy." << endl;
	}
	else {
	reg = Presupuesto (id, dniCliente, patente, importe, detalle, Fecha(stoi(dia), stoi(mes),stoi(anio)), trabajoAsignado, asistenciaGrua, vehiculoSustitucion);
	}

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
	if (cantRegistros == -1 || cantRegistros == 0){
        cout << "No existen registros" << endl;
        system("pause");
	 return;}
	for (int i = 0; i < cantRegistros; i++) {
		Presupuesto presupuesto = _archivo.Leer(i);
		if (presupuesto.getEstado()) {
			ListarRegistro(presupuesto);
		}
	}
	system("pause");
}

int PresupuestoManager::ListarTodosSinAsignar() {
	bool band = false;
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		Presupuesto presupuesto = _archivo.Leer(i);
		if (!presupuesto.getTrabajoAsignado() && presupuesto.getEstado()) {
			ListarRegistro(presupuesto);
			band = true;
		}
	}
	if (!band) {
            cout << "No se encontraron presupuestos sin trabajos asignados..." << endl;
            return 0;}
			return 1;
	system("pause");
}

void PresupuestoManager::ListarRegistro(Presupuesto presupuesto) {
	cout << "PRESUPUESTO ID          # " << presupuesto.getIdPresupuesto() << endl;
	cout << "DNI CLIENTE             : " << presupuesto.getDniCliente() << endl;
	cout << "PATENTE                 : " << presupuesto.getPatente() << endl;
	cout << "IMPORTE                 $ " << presupuesto.getImporte() << endl;
	cout << "DETALLE                 : " << presupuesto.getDetalle() << endl;
	cout << "FECHA                   : " << presupuesto.getFecha().toString("DD/MM/YYYY") << endl;
	cout << "ASISTENCIA DE GRUA      : ";
	if (presupuesto.getAsistenciaGrua()) {
		cout << "SI" << endl;
	} else cout << "NO" << endl;
	cout << "VEHICULO DE SUSTITUCION : ";
	if (presupuesto.getVehiculoSustitucion()) {
		cout << "SI" << endl << endl;
	} else cout << "NO" << endl << endl;
}

void PresupuestoManager::ListarPorId() {
	string id;
	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;
	if (!isdigit(id[0])){
            cout << "ERROR: El ID debe ser un numero" << endl;
            system("pause");
            return;}
	int pos = _archivo.Buscar(stoi(id));
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
	string id;
	float importe;

	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;
	if (!isdigit(id[0])){
            cout << "ERROR: El ID debe ser un numero" << endl;
            system("pause");
            return;}
	int pos = _archivo.Buscar(stoi(id));

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Presupuesto presupuesto = _archivo.Leer(pos);
		ListarRegistro(presupuesto);

		cout << endl << "INGRESAR NUEVO IMPORTE: ";
		cin >> importe;
		presupuesto.setImporte(importe);

		if (_archivo.Guardar(presupuesto, pos)) {
			cout << "Registro guardado existosamente!" << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "ID inexistente." << endl;
	system("pause");
}

void PresupuestoManager::EditarDetalle() {
	string nuevoDetalle, id;

	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;
	if (!isdigit(id[0])){
            cout << "ERROR: El ID debe ser un numero" << endl;
            system("pause");
            return;}
	int pos = _archivo.Buscar(stoi(id));

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Presupuesto presupuesto = _archivo.Leer(pos);
		ListarRegistro(presupuesto);

		cin.ignore();
		cout << endl << "INGRESAR NUEVO DETALLE: ";
		getline(cin, nuevoDetalle);
		presupuesto.setDetalle(nuevoDetalle);

		if (_archivo.Guardar(presupuesto, pos)) {
			cout << "Registro guardado existosamente!" << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "ID inexistente." << endl;
	system("pause");
}

void PresupuestoManager::EditarFechaPresupuesto(){
    string id;

	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;
	if (!isdigit(id[0])){
            cout << "ERROR: El ID debe ser un numero" << endl;
            system("pause");
            return;}
	int pos = _archivo.Buscar(stoi(id));

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Presupuesto presupuesto = _archivo.Leer(pos);
		ListarRegistro(presupuesto);

		//cin.ignore();
		Fecha aux = pedirFecha();
		presupuesto.setFecha(aux);

		if (_archivo.Guardar(presupuesto, pos)) {
			cout << "Registro guardado existosamente!" << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "ID inexistente." << endl;
	system("pause");
}

void PresupuestoManager::AsignarTrabajo(int id, bool valor) {
	int pos = _archivo.Buscar(id);
	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Presupuesto presupuesto = _archivo.Leer(pos);
		presupuesto.setTrabajoAsignado(valor);
		_archivo.Guardar(presupuesto, id);
	}
}

void PresupuestoManager::Eliminar() {
	string id;

	cout << "INGRESAR ID DEL PRESUPUESTO: ";
	cin >> id;
	if (!isdigit(id[0])){
            cout << "ERROR: El ID debe ser un numero" << endl;
            system("pause");
            return;}

	int pos = _archivo.Buscar(stoi(id));
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
