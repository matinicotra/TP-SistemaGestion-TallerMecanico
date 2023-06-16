#include "Proveedor.h"

Proveedor::Proveedor()
{
	_idProveedor = 0;
	_rubro = "";
	_estado = true;
}

void Proveedor::setRubro(std::string rubro) {
	_rubro = rubro;
}

std::string Proveedor::getRubro() {
	return _rubro;
}
