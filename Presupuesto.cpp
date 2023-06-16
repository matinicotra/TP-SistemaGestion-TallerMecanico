#include <cstring>
#include <string>
#include <Fecha.h>

#include "Presupuesto.h"

Presupuesto::Presupuesto() {
	_idPresupuesto = 0;
	_idCliente = 0;
	strcpy(_patente, "");
	_importe = 0;
	_detalle = "";
	_estado = true;
}

void Presupuesto::setIdPresupuesto(int id) {
	_idPresupuesto = id;
}

void Presupuesto::setIdCliente(int idCliente) {
	_idCliente = idCliente;
}

void Presupuesto::setPatente(const char *patente) {
	strcpy(_patente, patente);
}

void Presupuesto::setImporte(float importe) {
	_importe = importe;
}

void Presupuesto::setDetalle(std::string detalle) {
	_detalle = detalle;
}

void Presupuesto::setFecha(Fecha fecha) {
	_fechaPresupuesto = fecha;
}

void Presupuesto::setEstado(bool estado) {
	_estado = estado;
}

int Presupuesto::getIdPresupuesto() {
	return _idPresupuesto;
}

int Presupuesto::getIdCliente() {
	return _idCliente;
}

const char *Presupuesto::getPatente() {
	return _patente;
}

float Presupuesto::getImporte() {
	return _importe;
}

std::string Presupuesto::getDetalle() {
	return _detalle;
}

Fecha Presupuesto::getFecha() {
	return _fechaPresupuesto;
}

bool Presupuesto::getEstado() {
	return _estado;
}
