#include "Proveedor.h"

Proveedor::Proveedor()
{
	_idProveedor = 0;
	_rubro = "";
	_estado = true;
}

void Proveedor::setIdProveedor(int id) {
	_idProveedor = id;
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

int Proveedor::getIdProveedor() {
	return _idProveedor;
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
