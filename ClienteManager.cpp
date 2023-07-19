#include <iostream>
using namespace std;

#include "AutoClienteManager.h"
#include "ClienteManager.h"
#include "TrabajoArchivo.h"
#include "TrabajoManager.h"

void ClienteManager::OrdenarPorFecha(Cliente *vec, int cantRegistros) {
	int menor = 0;
	Cliente aux;
	for (int i = 0; i < cantRegistros - 1; i++) {
		menor = i;
		for (int j = i + 1; j < cantRegistros; j++) {
			if (vec[j].getFechaAlta().toString("YYYY/MM/DD") < vec[menor].getFechaAlta().toString("YYYY/MM/DD")) {
				menor = j;
			}
		}
		if (i != menor) {
			aux = vec[i];
			vec[i] = vec[menor];
			vec[menor] = aux;
		}
	}
}

void ClienteManager::OrdenarPorApellido(Cliente *vec, int cantRegistros) {
	int mayor = 0;
	Cliente aux;
	for (int i = 0; i < cantRegistros - 1; i++) {
		mayor = i;
		for (int j = i + 1; j < cantRegistros; j++) {
			if (vec[j].getApellido() < vec[mayor].getApellido()) {
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


void ClienteManager::Cargar() {
	string dni, nombre, apellido, eMail, direccion, telefono, razonSocial;
	string dia, mes, anio;

	cin.ignore();
	cout << "NOMBRE       : ";
	getline(cin, nombre);
	cout << "APELLIDO     : ";
	getline(cin, apellido);
	cout << "DNI          : ";
	getline(cin, dni);

	if (_archivo.Buscar(dni) >= 0){
        cout << "El registro ya existe." << endl;
        system("pause");
        return;
	}

	cout << "EMAIL        : ";
	getline(cin, eMail);
	cout << "DIRECCION    : ";
	getline(cin, direccion);
	cout << "TELEFONO     : ";
	getline(cin, telefono);
	cout << "RAZON SOCIAL : ";
	getline(cin, razonSocial);
	cout << "FECHA DE ALTA" << endl;
	cout << "DIA          : ";
	cin >> dia;
	cout << "MES          : ";
	cin >> mes;
	cout << "ANIO         : " ;
	cin >> anio;
	cout << endl;

    Cliente reg;

    if ((dia.length() > 2 || !isdigit(dia[0])) || (mes.length() > 2 || !isdigit(mes[0])) || (anio.length() > 4 || !isdigit(anio[0]))){
	reg = Cliente (dni, nombre, apellido, eMail, direccion, telefono, razonSocial, Fecha());
	cout << "Error en la fecha. Cargada con fecha de hoy." << endl;
	}
	else {
	reg = Cliente (dni, nombre, apellido, eMail, direccion, telefono, razonSocial, Fecha(stoi(dia), stoi(mes),stoi(anio)));
	}

	if (_archivo.Guardar(reg)) {
		cout << "Registro guardado existosamente!" << endl;
	} else cout << "Error al guardar el registro" << endl;
        system("pause");
}


void ClienteManager::ListarTodos() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		Cliente cliente = _archivo.Leer(i);
		if (cliente.getEstado()) {
			ListarRegistro(cliente);
		}
	}
	system("pause");
}

void ClienteManager::ListarRegistro(Cliente cliente) {
	cout << "NOMBRE        : " << cliente.getNombre() << endl;
	cout << "APELLIDO      : " << cliente.getApellido() << endl;
	cout << "DNI           : " << cliente.getDni() << endl;
	cout << "EMAIL         : " << cliente.getEmail() << endl;
	cout << "DIRECCION     : " << cliente.getDireccion() << endl;
	cout << "TELEFONO      : " << cliente.getTelefono() << endl;
	cout << "RAZON SOCIAL  : " << cliente.getRazonSocial() << endl;
	cout << "FECHA DE ALTA : " << cliente.getFechaAlta().toString("DD/MM/YYYY") << endl << endl;
}

void ClienteManager::ListarPorDni() {
	int pos;
	string dni;
	cin.ignore();
	cout << endl << "INGRESAR DNI DEL CLIENTE: ";
	getline(cin, dni);
	pos = _archivo.Buscar(dni);
	Cliente cliente = _archivo.Leer(pos);
	if (pos >= 0 && cliente.getEstado()) {
		cout << endl;
		ListarRegistro(_archivo.Leer(pos));
	} else cout << "No exsite registro con DNI " << dni << endl;
	system("pause");
}

void ClienteManager::ListarPorApellido() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	bool existeRegistro = false;
	string apellido;
	cin.ignore();
	cout << endl << "INGRESAR APELLIDO DEL CLIENTE: ";
	getline(cin, apellido);
	for (int i = 0; i < cantRegistros; i++) {
		Cliente cliente = _archivo.Leer(i);
		if (cliente.getApellido() == apellido && cliente.getEstado() == true) {
			cout << endl;
			ListarRegistro(cliente);
			existeRegistro = true;
		}
	} if (!existeRegistro){ cout << "No exsite registro con el apellido: " << apellido << endl;}
	system("pause");
}

void ClienteManager::ListarOrdenadosPorFechaAlta() {
	int cantReg = _archivo.GetCantidadRegistros();
	if (cantReg == -1 || cantReg == 0){
        cout << "No existen registros" << endl;
        system("pause");
	 return;}

	Cliente *vec = new Cliente[cantReg];
	if (vec == nullptr) {
		cout << "Error" << endl;
		return;
	}

	_archivo.Leer(vec, cantReg);
	OrdenarPorFecha(vec, cantReg);

	for (int i = 0; i < cantReg; i++) {
	    Cliente aux = _archivo.Leer(i);
            if (aux.getEstado()){
		ListarRegistro(vec[i]);
		cout << endl;
	}}

	delete []vec;
	system("pause");
}

void ClienteManager::ListarOrdenadosPorApellido() {
	int cantReg = _archivo.GetCantidadRegistros();
	if (cantReg == -1 || cantReg == 0){
        cout << "No existen registros" << endl;
        system("pause");
	 return;}

	Cliente *vec = new Cliente[cantReg];
	if (vec == nullptr) {
		cout << "Error" << endl;
		return;
	}

	_archivo.Leer(vec, cantReg);
	OrdenarPorApellido(vec, cantReg);

	for (int i = 0; i < cantReg; i++) {
            Cliente aux = _archivo.Leer(i);
            if (aux.getEstado()){
		ListarRegistro(vec[i]);
		cout << endl;
	}}

	delete []vec;
	system("pause");
}

void ClienteManager::ListarVehiculosAsociados() {
	AutoClienteManager managerAux;
	string dni;

	cin.ignore();
	cout << "INGRESAR DNI DEL CLIENTE: ";
	getline(cin, dni);

	int pos = _archivo.Buscar(dni);

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Cliente cliente = _archivo.Leer(pos);
		ListarRegistro(cliente);

		cout << endl << "VEHICULOS: " << endl;

		managerAux.ListarVehiculosPorDni(dni);

	} else cout << "DNI inexistente." << endl;

	system("pause");
}

void ClienteManager::EditarTelefono() {
	string dni, telefono;

	cin.ignore();
	cout << "INGRESAR DNI DEL CLIENTE: ";
	getline(cin, dni);

	int pos = _archivo.Buscar(dni);

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Cliente cliente = _archivo.Leer(pos);
		ListarRegistro(cliente);

		cout << endl << "INGRESAR NUEVO TELEFONO: ";
		getline(cin, telefono);
		cliente.setTelefono(telefono);

		if (_archivo.Guardar(cliente, pos)) {
			cout << "Registro guardado existosamente!" << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "DNI inexistente." << endl;

	system("pause");
}

void ClienteManager::EditarFechaAlta(){
    string dni;

	cin.ignore();
	cout << "INGRESAR DNI DEL CLIENTE: ";
	getline(cin, dni);

	int pos = _archivo.Buscar(dni);

	if (pos >= 0 && _archivo.Leer(pos).getEstado() == true) {
		Cliente cliente = _archivo.Leer(pos);
		ListarRegistro(cliente);
        Fecha aux = pedirFecha();
		cliente.setFechaAlta(aux);

		if (_archivo.Guardar(cliente, pos)) {
			cout << "Registro guardado existosamente!" << endl;
		} else cout << "Error al guardar el registro." << endl;

	} else cout << "DNI inexistente." << endl;

	system("pause");

}

void ClienteManager::Eliminar() {
	int pos;
	string dni;

	cin.ignore();
	cout << "INGRESAR DNI DEL CLIENTE: ";
	getline(cin, dni);

	pos = _archivo.Buscar(dni);

	if (pos >= 0) {
		Cliente reg = _archivo.Leer(pos);
		ListarRegistro(reg);

		char opc;
		cout << endl << "Desea eliminar el registro? Ingresar 'S' para confirmar; 'N' para regresar: ";
		cin >> opc;

		if (opc == 'S' || opc == 's') {
			reg.setEstado(false);

			if (_archivo.Guardar(reg, pos)) {
				cout << "Registro eliminado exitosamente." << endl;
			} else cout << "Error al eliminar el registro." << endl;

		} else if (opc == 'N' || opc == 'n') {
			cout << "No se realizaron modificaciones." << endl;
		} else cout << "El valor ingresado es incorrecto." << endl;

	} else cout << "DNI inexistente." << endl;

	system("pause");
}

void ClienteManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	if (cantRegistros<=0){
            cout << endl;
            cout << "No existe el archivo de Clientes" << endl;
            cout << endl;
            system("pause");
            return;}
	Cliente *vec;

	vec = new Cliente[cantRegistros];
	if (vec == nullptr) {
		cout << "Error al realizar backup." << endl;
		return;
	}

	_archivo.Leer(vec, cantRegistros);
	_archivoBkp.Vaciar();
	if (_archivoBkp.Guardar(vec, cantRegistros)) {
		cout << "Backup realizado correctamente!" << endl;
	} else cout << "Error al realizar backup." << endl;
	delete []vec;

	system("pause");
}

void ClienteManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();
    	if (cantRegistros<=0){
            cout << endl;
            cout << "No existe el archivo de Clientes" << endl;
            cout << endl;
            system("pause");
            return;}
	Cliente *vec;

	vec = new Cliente[cantRegistros];
	if (vec == nullptr) {
		cout << "Error al restaurar el backup." << endl;
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
