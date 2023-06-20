#include <cstring>
#include "Fecha.h"
#include "Empleado.h"

Empleado::Empleado() {
	_cargo = "";
	_sueldo = 0;
	strcpy(_cuentaBancaria, "");
}

void Empleado::setFechaNacimiento(Fecha fechaNacimiento) {
	_fechaNacimiento = fechaNacimiento;
}

void Empleado::setCargo(std::string cargo) {
	_cargo = cargo;
}

void Empleado::setSueldo(float sueldo) {
	_sueldo = sueldo;
}

void Empleado::setCuentaBancaria(const char *cuenta) {
	strcpy(_cuentaBancaria, cuenta);
}

void Empleado::setEstado(bool estado) {
	_estado = estado;
}

Fecha Empleado::getFechaNacimiento() {
	return _fechaNacimiento;
}

std::string Empleado::getCargo() {
	return _cargo;
}

float Empleado::getSueldo() {
	return _sueldo;
}

const char *Empleado::getCuentaBancaria() {
	return _cuentaBancaria;
}

bool Empleado::getEstado() {
	return _estado;
}
