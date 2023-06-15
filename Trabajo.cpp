#include "Trabajo.h"

Trabajo::Trabajo() {
	_idTrabajo = 0;
	_idProveedor = 0;
	_idVehiculo = 0;
	_idCliente = 0;
	_idEmpleado = 0;
	_estadoTrabajo = 0;
	_detalle = "";
	_presupuesto = 0;
	_estado = true;
}

void Trabajo::setId(int id) {
	_idTrabajo = id;
}

void Trabajo::setIdProveedor(int idProveedor) {
	_idProveedor = idProveedor;
}

void Trabajo::setIdVehiculo(int idVehiculo) {
	_idVehiculo = idVehiculo;
}

void Trabajo::setIdCliente(int idCliente) {
	_idCliente = idCliente;
}

void Trabajo::setIdEmpleado(int idEmpleado) {
	_idEmpleado = idEmpleado;
}

void Trabajo::setEstadoTrabajo(int estadoTrabajo) {
	_estadoTrabajo = estadoTrabajo;
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

int Trabajo::getId() {
	return _idTrabajo;
}

int Trabajo::getIdProveedor() {
	return _idProveedor;
}

int Trabajo::getIdVehiculo() {
	return _idVehiculo;
}

int Trabajo::getIdCliente() {
	return _idCliente;
}

int Trabajo::getIdEmpleado() {
	return _idEmpleado;
}

int Trabajo::getEstadoTrabajo() {
	return _estadoTrabajo;
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
