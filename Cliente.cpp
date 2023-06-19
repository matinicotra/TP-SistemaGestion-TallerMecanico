#include <cstring>
#include "Cliente.h"

Cliente::Cliente()
{
	_idCliente = 0;
	strcpy(_dni, "");
	_estado = true;
}

void Cliente::setId(int id) {
	_idCliente = id;
}

void Cliente::setDni(const char *dni) {
	strcpy(_dni, dni);
}

void Cliente::setEstado(bool estado) {
	_estado = estado;
}

int Cliente::getIdCliente() {
	return _idCliente;
}

const char *Cliente::getDni() {
	return _dni;
}

bool Cliente::getEstado() {
	return _estado;
}
