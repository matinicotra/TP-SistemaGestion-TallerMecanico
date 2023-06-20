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
	_detalle = "";
	_presupuesto = 0;
	_estado = true;
}

void Trabajo::setIdTrabajo(int idTrabajo) {
	_idTrabajo = idTrabajo;
}

void Trabajo::setIdPresupuesto(int idPresupuesto) {
	_idPresupuesto = idPresupuesto;
}

void Trabajo::setPatente(const char *patente) {
	strcpy(_patente, patente);
}

void Trabajo::setDniCliente(const char *dniCliente) {
	strcpy(_dniCliente, dniCliente);
}

void Trabajo::setDniProveedor(const char *dniProveedor) {
	strcpy(_dniProveedor, dniProveedor);
}

void Trabajo::setDniEmpleado(const char *dniEmpleado) {
	strcpy(_dniEmpleado, dniEmpleado);
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
void Trabajo::setDetalle(std::string detalle) {
	_detalle = detalle;
}

void Trabajo::setPresupuesto(float presupuesto) {
	_presupuesto = presupuesto;
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

const char *Trabajo::getPatente() {
	return _patente;
}

const char *Trabajo::getDniCliente() {
	return _dniCliente;
}

const char *Trabajo::getDniProveedor() {
	return _dniProveedor;
}

const char *Trabajo::getDniEmpleado() {
	return _dniEmpleado;
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

std::string Trabajo::getDetalle() {
	return _detalle;
}

float Trabajo::getPresupuesto() {
	return _presupuesto;
}

bool Trabajo::getEstado() {
	return _estado;
}
