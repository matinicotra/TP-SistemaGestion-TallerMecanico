#include <cstring>
#include "Fecha.h"
#include "Empleado.h"

Empleado::Empleado() {
	_idEmpleado = 0;
	strcpy(_dni, "");
	_cargo = "";
	_sueldo = 0;
	strcpy(_cuentaBancaria, "");
}

void Empleado::_setIdEmpleado(int id) {
	_idEmpleado = id;
}

void Empleado::setDni(const char *dni) {
	strcpy(_dni, dni);
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

int Empleado::getIdEmpleado() {
	return _idEmpleado;
}

const char *Empleado::getDni() {
	return _dni;
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
