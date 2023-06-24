#include "Presupuesto.h"

Presupuesto::Presupuesto() {
	_idPresupuesto = 0;
	strcpy(_dniCliente, "");
	strcpy(_patente, "");
	_importe = 0;
	strcpy(_detalle, "caca");
	_estado = true;
}

Presupuesto::Presupuesto(int idPresupuesto, std::string dniCliente, std::string patente, float importe, std::string detalle, Fecha fechaPresupuesto, bool asistenciaGrua, bool vehiculoSustitucion) {
	_idPresupuesto = idPresupuesto;
	strcpy(_dniCliente, dniCliente.c_str());
	strcpy(_patente, patente.c_str());
	_importe = importe;
	strcpy(_detalle, detalle.c_str());
	_asistenciaGrua = asistenciaGrua;
	_vehiculoSustitucion = vehiculoSustitucion;
	_estado = true;
}

void Presupuesto::setIdPresupuesto(int idPresupuesto) {
	_idPresupuesto = idPresupuesto;
}

void Presupuesto::setDniCliente(std::string dniCliente) {
	strcpy(_dniCliente, dniCliente.c_str());
}

void Presupuesto::setPatente(std::string patente) {
	strcpy(_patente, patente.c_str());
}

void Presupuesto::setImporte(float importe) {
	_importe = importe;
}

void Presupuesto::setDetalle(std::string detalle) {
	strcpy(_detalle, detalle.c_str());
}

void Presupuesto::setFecha(Fecha fecha) {
	_fechaPresupuesto = fecha;
}

void Presupuesto::setAsistenciaGrua(bool asistenciaGrua) {
	_asistenciaGrua = asistenciaGrua;
}

void Presupuesto::setVehiculoSustitucion(bool vehiculoSustitucion) {
	_vehiculoSustitucion = vehiculoSustitucion;
}

void Presupuesto::setEstado(bool estado) {
	_estado = estado;
}

int Presupuesto::getIdPresupuesto() {
	return _idPresupuesto;
}

std::string Presupuesto::getDniCliente() {
	std::string dniAux = _dniCliente;
	return dniAux;
}

std::string Presupuesto::getPatente() {
	std::string patenteAux = _patente;
	return patenteAux;
}

float Presupuesto::getImporte() {
	return _importe;
}

std::string Presupuesto::getDetalle() {
	std::string detalleAux = _detalle;
	return detalleAux;
}

Fecha Presupuesto::getFecha() {
	return _fechaPresupuesto;
}

bool Presupuesto::getAsistenciaGrua() {
	return _asistenciaGrua;
}

bool Presupuesto::getVehiculoSustitucion() {
	return _vehiculoSustitucion;
}

bool Presupuesto::getEstado() {
	return _estado;
}
