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
