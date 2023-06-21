#include <cstring>

#include "AutoCliente.h"

AutoCliente::AutoCliente() {
	strcpy(_dniCliente, "");
	strcpy(_patente, "");
	_estado = true;
}

AutoCliente::AutoCliente(const char *dniCliente, const char *patente) {
	strcpy(_dniCliente, dniCliente);
	strcpy(_patente, patente);
	_estado = true;
}

void AutoCliente::setDniCliente(const char *dniCliente) {
	strcpy(_dniCliente, dniCliente);
}

void AutoCliente::setPatente(const char *patente) {
	strcpy(_patente, patente);
}

void AutoCliente::setEstado(bool estado) {
	_estado = estado;
}

const char *AutoCliente::getDniCliente() {
	return _dniCliente;
}

const char *AutoCliente::getPatente() {
	return _patente;
}

bool AutoCliente::getEstado() {
	return _estado;
}
