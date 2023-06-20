#include <cstring>
#include "Cliente.h"

Cliente::Cliente()
{
	_estado = true;
}

void Cliente::setEstado(bool estado) {
	_estado = estado;
}

bool Cliente::getEstado() {
	return _estado;
}
