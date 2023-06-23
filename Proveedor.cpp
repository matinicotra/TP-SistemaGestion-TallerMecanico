#include "Proveedor.h"

Proveedor::Proveedor() {
	strcpy(_rubro, "");
	strcpy(_autoparte, "");
	strcpy(_origenFabricacion, "");
	_estado = true;
}

Proveedor::Proveedor(std::string rubro, std::string autoparte, std::string origenFabricacion){
	strcpy(_rubro, rubro.c_str());
	strcpy(_autoparte, autoparte.c_str());
	strcpy(_origenFabricacion, origenFabricacion.c_str());
	_estado = true;
}

void Proveedor::setRubro(std::string rubro) {
	strcpy(_rubro, rubro.c_str());
}

void Proveedor::setAutoparte(std::string autoparte) {
	strcpy(_autoparte, autoparte.c_str());
}

void Proveedor::setOrigeFabricacion(std::string origenFabricacion) {
	strcpy(_origenFabricacion, origenFabricacion.c_str());
}

void Proveedor::setEstado(bool estado) {
	_estado = estado;
}

std::string Proveedor::getRubro() {
	std::string rubroAux = _rubro;
	return rubroAux;
}

std::string Proveedor::getAutoparte() {
	std::string autoparteAux = _autoparte;
	return autoparteAux;
}

std::string Proveedor::getOrigenFabricacion() {
	std::string origenAux = _origenFabricacion;
	return origenAux;
}

bool Proveedor::getEstado() {
	return _estado;
}
