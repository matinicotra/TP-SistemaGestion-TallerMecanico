

#include "Presupuesto.h"

Presupuesto::Presupuesto() {
	_idPresupuesto = 0;
	strcpy(_dniCliente, "");
	strcpy(_patente, "");
	_importe = 0;
	_detalle = "";
	_estado = true;
}

Presupuesto::Presupuesto(int idPresupuesto, const char* dniCliente, const char* patente, float importe, std::string detalle, Fecha fechaPresupuesto, bool asistenciaGrua, bool vehiculoSustitucion) {
	_idPresupuesto = idPresupuesto;
	strcpy(_dniCliente, dniCliente);
	strcpy(_patente, patente);
	_importe = importe;
	_detalle = detalle;
	_asistenciaGrua = asistenciaGrua;
	_vehiculoSustitucion = vehiculoSustitucion;
	_estado = true;
}

void Presupuesto::setIdPresupuesto(int idPresupuesto) {
	_idPresupuesto = idPresupuesto;
}

void Presupuesto::setDniCliente(const char *dniCliente) {
	strcpy(_dniCliente, dniCliente);
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

const char *Presupuesto::getDniCliente() {
	return _dniCliente;
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

bool Presupuesto::getAsistenciaGrua() {
	return _asistenciaGrua;
}

bool Presupuesto::getVehiculoSustitucion() {
	return _vehiculoSustitucion;
}

bool Presupuesto::getEstado() {
	return _estado;
}
