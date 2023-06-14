#include "Vehiculo.h"
#include <cstring>

Vehiculo::Vehiculo()
{
	//ctor
}


void Vehiculo::setPatente(const char *patente) {
	strcpy(_patente, patente);
}

void Vehiculo::setModelo(std::string modelo) {
	_modelo = modelo;
}
void Vehiculo::setMarca(std::string marca) {
	_marca = marca;
}
void Vehiculo::setEstado(bool estado) {
	_estado = estado;
}

const char *Vehiculo::getPatente() {
	return _patente;
}

std::string Vehiculo::getModelo() {
	return _modelo;
}

std::string Vehiculo::getMarca() {
	return _marca;
}

bool Vehiculo::getEstado() {
	return _estado;
}
