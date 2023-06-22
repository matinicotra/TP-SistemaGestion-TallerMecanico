#include "Proveedor.h"

Proveedor::Proveedor(){
	_rubro = "";
	_autoparte = "";
	_origenFabricacion = "";
	_estado = true;
}

Proveedor::Proveedor(std::string rubro, std::string autoparte, std::string origenFabricacion){
	_rubro = rubro;
	_autoparte = autoparte;
	_origenFabricacion = origenFabricacion;
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

void Proveedor::setEstado(bool estado) {
	_estado = estado;
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

bool Proveedor::getEstado() {
	return _estado;
}
