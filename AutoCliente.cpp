#include "AutoCliente.h"

AutoCliente::AutoCliente() {
	_idCliente = 0;
	_idVehiculo = 0;
	_estado = true;
}

AutoCliente::AutoCliente(int idCliente, int idVehiculo) {
	_idCliente = idCliente;
	_idVehiculo = idVehiculo;
	_estado = true;
}

void AutoCliente::setIdCliente(int idCliente) {
	_idCliente = idCliente;
}

void AutoCliente::setIdVehiculo(int idVehiculo) {
	_idVehiculo = idVehiculo;
}

void AutoCliente::setEstado(bool estado) {
	_estado = estado;
}

int AutoCliente::getIdCliente() {
	return _idCliente;
}

int AutoCliente::getIdVehiculo() {
	return _idVehiculo;
}

bool AutoCliente::getEstado() {
	return _estado;
}
