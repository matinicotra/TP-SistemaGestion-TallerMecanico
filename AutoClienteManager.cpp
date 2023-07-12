#include <iostream>
using namespace std;

#include "VehiculoManager.h"
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

void AutoClienteManager::ListarTodos(){
	int cantRegistros = _archivo.GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		AutoCliente autoCliente = _archivo.Leer(i);
		if (autoCliente.getEstado()) {
			ListarRegistro(autoCliente);
		}
	}
}

void AutoClienteManager::ListarVehiculosPorDni(std::string dni) {
	string patente;
	VehiculoArchivo arcVehiculos;
	VehiculoManager managerAux;
	int cantRegistros = _archivo.GetCantidadRegistros();
	int cantVehiculos = arcVehiculos.GetCantidadRegistros();

	for (int i = 0; i < cantRegistros; i++) {
		AutoCliente autoCliente = _archivo.Leer(i);

		if (autoCliente.getDniCliente() == dni && autoCliente.getEstado()) {
			patente = autoCliente.getPatente();

			for (int j = 0; j < cantVehiculos; j++) {
				if (arcVehiculos.Leer(j).getPatente() == patente) {
					managerAux.ListarRegistro(arcVehiculos.Leer(j));
					break;
				}
			}
		}
	}
}

void AutoClienteManager::ListarRegistro(AutoCliente reg){
    cout << "Dni del Cliente: " << reg.getDniCliente() << "    Patente del auto: " << reg.getPatente() << endl << endl;
}

void AutoClienteManager::Eliminar(std::string patente) {
	int pos = _archivo.BuscarPatente(patente);
		AutoCliente reg = _archivo.Leer(pos);
	if (pos >= 0 && reg.getEstado()==true) {
		reg.setEstado(false);
		_archivo.Guardar(reg, pos);
	}
}

void AutoClienteManager::HacerCopiaDeSeguridad() {
	int cantRegistros = _archivo.GetCantidadRegistros();
	AutoCliente *vec;

	vec = new AutoCliente[cantRegistros];
	if (vec == nullptr) {
		return;
	}

	_archivo.Leer(vec, cantRegistros);
	_archivoBkp.Vaciar();
	_archivoBkp.Guardar(vec, cantRegistros);
	delete []vec;
}

void AutoClienteManager::RestaurarCopiaDeSeguridad() {
	int cantRegistros = _archivoBkp.GetCantidadRegistros();
	AutoCliente *vec;

	vec = new AutoCliente[cantRegistros];
	if (vec == nullptr) {
		return;
	}

	_archivoBkp.Leer(vec, cantRegistros);
	_archivo.Vaciar();
	_archivo.Guardar(vec, cantRegistros);
	delete []vec;
}
