#include <string>
#include "Cliente.h"

Cliente::Cliente()
{
	_razonSocial = "";
	_estado = true;
}

void Cliente::setRazonSocial(std::string razonSocial) {
	_razonSocial = razonSocial;
}

void Cliente::setEstado(bool estado) {
	_estado = estado;
}

std::string Cliente::getRazonSocial() {
	return _razonSocial;
}

bool Cliente::getEstado() {
	return _estado;
}
