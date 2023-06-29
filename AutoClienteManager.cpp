#include <iostream>
using namespace std;
#include "AutoClienteManager.h"

void AutoClienteManager::Cargar(std::string dni, std::string patente) {
	int cantRegistros = _archivo.GetCantidadRegistros();
	bool existe = false;
	for (int i = 0; i < cantRegistros; i++) {
		AutoCliente reg = _archivo.Leer(i);
		if (reg.getEstado() && reg.getPatente() == patente && reg.getDniCliente() == dni) {
			existe = true;
		}
	}
	if (!existe) {
		AutoCliente reg(dni, patente);
		_archivo.Guardar(reg);
	}
}

void AutoClienteManager::Eliminar(std::string patente) {
	int pos = _archivo.BuscarPatente(patente);
	if (pos >= 0) {
		AutoCliente reg = _archivo.Leer(pos);
		reg.setEstado(false);
		_archivo.Guardar(reg);
	}
}

void AutoClienteManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();

    if (cantRegistros<=0){
        cout << "No existe el archivo." << endl;
        system("pause");
        return;}

	AutoCliente *vec;

	vec = new AutoCliente[cantRegistros];
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
}

void AutoClienteManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();

		if (cantRegistros<=0){
            cout << "No existe el archivo." << endl;
            system("pause");
            return;}

	AutoCliente *vec;

	vec = new AutoCliente[cantRegistros];
	if (vec == nullptr) {
        cout << "Error al realizar backup." << endl;
		return;
	}

	_archivoBkp.Leer(vec, cantRegistros);
	_archivo.Vaciar();
	if (_archivoBkp.Guardar(vec, cantRegistros)) {
		cout << "Backup realizado correctamente!" << endl;
	} else cout << "Error al realizar backup." << endl;

	delete []vec;
}

void AutoClienteManager::ListarTodos(){
    	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		AutoCliente autoCliente = _archivo.Leer(i);
		if (autoCliente.getEstado()) {
			ListarRegistro(autoCliente);
			cout << endl;
		}
	}
}

void AutoClienteManager::ListarRegistro(AutoCliente reg){
    cout << "Dni del Cliente: " << reg.getDniCliente() << "    Patente del auto: " << reg.getPatente() << endl;
}

