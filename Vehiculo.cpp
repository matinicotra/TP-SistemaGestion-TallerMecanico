#include "Vehiculo.h"
#include <cstring>

Vehiculo::Vehiculo() {
	strcpy(_patente, "");
	_modelo = "";
	_marca = "";
	_anio = 0;
	_estado = true;
}

Vehiculo::Vehiculo(const char* patente, std::string modelo, std::string marca, int anio, Fecha fechaAlta) {
	strcpy(_patente, patente);
	_modelo = modelo;
	_marca = marca;
	_anio = anio;
	_fechaAlta = fechaAlta;
	_estado = true;
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

void Vehiculo::setAnio(int anio) {
	_anio = anio;
}

void Vehiculo::setFechaAlta(Fecha alta) {
	_fechaAlta = alta;
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

int Vehiculo::getAnio() {
	return _anio;
}

Fecha Vehiculo::getFechaAlta() {
	return _fechaAlta;
}

bool Vehiculo::getEstado() {
	return _estado;
}
