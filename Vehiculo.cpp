#include "Vehiculo.h"
#include <cstring>

Vehiculo::Vehiculo() {
	strcpy(_patente, "");
	strcpy(_modelo, "");
	strcpy(_marca, "");
	_anio = 0;
	_estado = true;
}

Vehiculo::Vehiculo(std::string patente, std::string modelo, std::string marca, int anio, Fecha fechaAlta) {
	strcpy(_patente, patente.c_str());
	strcpy(_modelo, modelo.c_str());
	strcpy(_marca, marca.c_str());
	_anio = anio;
	_fechaAlta = fechaAlta;
	_estado = true;
}

void Vehiculo::setPatente(std::string patente) {
	strcpy(_patente, patente.c_str());
}

void Vehiculo::setModelo(std::string modelo) {
	strcpy(_modelo, modelo.c_str());
}

void Vehiculo::setMarca(std::string marca) {
	strcpy(_marca, marca.c_str());
}

void Vehiculo::setAnio(int anio) {
	_anio = anio;
}

void Vehiculo::setFechaAlta(Fecha alta) {
	_fechaAlta = alta;
}

void Vehiculo::setEstado(bool estado) {
	_estado = estado;
}

std::string Vehiculo::getPatente() {
	std::string patenteAux = _patente;
	return patenteAux;
}

std::string Vehiculo::getModelo() {
	std::string modeloAux = _modelo;
	return modeloAux;
}

std::string Vehiculo::getMarca() {
	std::string marcaAux = _marca;
	return marcaAux;
}

int Vehiculo::getAnio() {
	return _anio;
}

Fecha Vehiculo::getFechaAlta() {
	return _fechaAlta;
}

bool Vehiculo::getEstado() {
	return _estado;
}
