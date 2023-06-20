#include "Proveedor.h"

Proveedor::Proveedor()
{
	_rubro = "";
	_estado = true;
}

void Proveedor::setRubro(std::string rubro) {
	_rubro = rubro;
}

void Proveedor::setAutoparte(std::string autoparte) {
	_autoparte = autoparte;
}

void Proveedor::setOrigeFabricacion(std::string origenFabricacion) {
	_origenFabricacion = origenFabricacion;
}

std::string Proveedor::getRubro() {
	return _rubro;
}

std::string Proveedor::getAutoparte() {
	return _autoparte;
}

std::string Proveedor::getOrigenFabricacion() {
	return _origenFabricacion;
}
