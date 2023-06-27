#include "Fecha.h"
#include "Empleado.h"

Empleado::Empleado() {
	strcpy(_cargo, "");
	_sueldo = 0;
	strcpy(_cuentaBancaria, "");
	_estado = true;
}

Empleado::Empleado(std::string dni, std::string nombre, std::string apellido, std::string eMail, std::string direccion, std::string telefono, Fecha fechaNacimiento, std::string cargo, float sueldo, std::string cuentaBancaria) {
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setEmail(eMail);
    setDireccion(direccion);
    setTelefono(telefono);
    setFechaNacimiento(fechaNacimiento);
	strcpy(_cargo, cargo.c_str());
	_sueldo = sueldo;
	strcpy(_cuentaBancaria, cuentaBancaria.c_str());
	_estado = true;
}

void Empleado::setFechaNacimiento(Fecha fechaNacimiento) {
	_fechaNacimiento = fechaNacimiento;
}

/*void Empleado::setFechaAlta(Fecha fechaAlta) {
	_fechaAlta = fechaAlta;
}*/

void Empleado::setCargo(std::string cargo) {
	strcpy(_cargo, cargo.c_str());
}

void Empleado::setSueldo(float sueldo) {
	_sueldo = sueldo;
}

void Empleado::setCuentaBancaria(std::string cuenta) {
	strcpy(_cuentaBancaria, cuenta.c_str());
}

void Empleado::setEstado(bool estado) {
	_estado = estado;
}

Fecha Empleado::getFechaNacimiento() {
	return _fechaNacimiento;
}

/*Fecha Empleado::getFechaAlta() {
	return _fechaAlta;
}*/

std::string Empleado::getCargo() {
	std::string cargoAux = _cargo;
	return cargoAux;
}

float Empleado::getSueldo() {
	return _sueldo;
}

std::string Empleado::getCuentaBancaria() {
	std::string cuentaAux = _cuentaBancaria;
	return cuentaAux;
}

bool Empleado::getEstado() {
	return _estado;
}
