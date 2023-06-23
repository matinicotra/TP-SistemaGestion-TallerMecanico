#include <cstring>

#include "AutoCliente.h"

AutoCliente::AutoCliente() {
	strcpy(_dniCliente, "");
	strcpy(_patente, "");
	_estado = true;
}

AutoCliente::AutoCliente(std::string dniCliente, std::string patente) {
	strcpy(_dniCliente, dniCliente.c_str());
	strcpy(_patente, patente.c_str());
	_estado = true;
}

void AutoCliente::setDniCliente(std::string dniCliente) {
	strcpy(_dniCliente, dniCliente.c_str());
}

void AutoCliente::setPatente(std::string patente) {
	strcpy(_patente, patente.c_str());
}

void AutoCliente::setEstado(bool estado) {
	_estado = estado;
}

std::string AutoCliente::getDniCliente() {
	std::string dniClienteAux = _dniCliente;
	return dniClienteAux;
}

std::string AutoCliente::getPatente() {
	std::string patenteAux = _patente;
	return patenteAux;
}

bool AutoCliente::getEstado() {
	return _estado;
}
