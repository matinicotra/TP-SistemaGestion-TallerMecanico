#include <cstring>
#include "Trabajo.h"

Trabajo::Trabajo() {
	_idTrabajo = 0;
	_idPresupuesto = 0;
	strcpy(_patente, "");
	strcpy(_dniCliente, "");
	strcpy(_dniProveedor, "");
	strcpy(_dniEmpleado, "");
	_avanceTrabajo = 0;
	_estado = true;
}

Trabajo::Trabajo(int idTrabajo, int idPresupuesto, std::string patente, std::string dniCliente, std::string dniProveedor, std::string dniEmpleado, int avanceTrabajo, Fecha fechaEntrada, Fecha fechaEntrega) {
	_idTrabajo = idTrabajo;
	_idPresupuesto = idPresupuesto;
	strcpy(_patente, patente.c_str());
	strcpy(_dniCliente, dniCliente.c_str());
	strcpy(_dniProveedor, dniProveedor.c_str());
	strcpy(_dniEmpleado, dniEmpleado.c_str());
	_avanceTrabajo = avanceTrabajo;
	_estado = true;
}

void Trabajo::setIdTrabajo(int idTrabajo) {
	_idTrabajo = idTrabajo;
}

void Trabajo::setIdPresupuesto(int idPresupuesto) {
	_idPresupuesto = idPresupuesto;
}

void Trabajo::setPatente(std::string patente) {
	strcpy(_patente, patente.c_str());
}

void Trabajo::setDniCliente(std::string dniCliente) {
	strcpy(_dniCliente, dniCliente.c_str());
}

void Trabajo::setDniProveedor(std::string dniProveedor) {
	strcpy(_dniProveedor, dniProveedor.c_str());
}

void Trabajo::setDniEmpleado(std::string dniEmpleado) {
	strcpy(_dniEmpleado, dniEmpleado.c_str());
}

void Trabajo::setAvanceTrabajo(int avanceTrabajo) {
	_avanceTrabajo = avanceTrabajo;
}

void Trabajo::setFechaEntrada(Fecha fechaEntrada) {
	_fechaEntrada = fechaEntrada;
}

void Trabajo::setFechaEntrega(Fecha fechaEntrega) {
	_fechaEntrega = fechaEntrega;
}

void Trabajo::setEstado(bool estado) {
	_estado = estado;
}

int Trabajo::getIdTrabajo() {
	return _idTrabajo;
}

int Trabajo::getIdPresupuesto() {
	return _idPresupuesto;
}

std::string Trabajo::getPatente() {
	std::string patenteAux = _patente;
	return patenteAux;
}

std::string Trabajo::getDniCliente() {
	std::string dniClienteAux = _dniCliente;
	return dniClienteAux;
}

std::string Trabajo::getDniProveedor() {
	std::string dniProveedorAux = _dniProveedor;
	return dniProveedorAux;
}

std::string Trabajo::getDniEmpleado() {
	std::string dniEmpleadoAux = _dniEmpleado;
	return dniEmpleadoAux;
}

int Trabajo::getAvanceTrabajo() {
	return _avanceTrabajo;
}

Fecha Trabajo::getFechaEntrada() {
	return _fechaEntrada;
}

Fecha Trabajo::getFechaEntrega() {
	return _fechaEntrega;
}

bool Trabajo::getEstado() {
	return _estado;
}
