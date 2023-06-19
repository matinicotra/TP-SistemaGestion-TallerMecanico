#include <cstring>
#include "Persona.h"

Persona::Persona() {
	_nombre = "";
	_apellido = "";
	_eMail = "";
	_direccion = "";
	strcpy(_telefono, "");
	_estado = true;
}

void Persona::setNombre(std::string nombre) {
	_nombre = nombre;
}

void Persona::setApellido(std::string apellido) {
	_apellido = apellido;
}

void Persona::setEmail(std::string eMail) {
	_eMail = eMail;
}

void Persona::setDireccion(std::string direccion) {
	_direccion = direccion;
}

void Persona::setTelefono(const char *telefono) {
	strcpy(_telefono, telefono);
}

void Persona::setFechaAlta(Fecha fechaAlta) {
	_fechaAlta = fechaAlta;
}

void Persona::setEstado(bool estado) {
	_estado = estado;
}

std::string Persona::getNombre() {
	return _nombre;
}

std::string Persona::getApellido() {
	return _apellido;
}

std::string Persona::getEmail() {
	return _eMail;
}

std::string Persona::getDireccion() {
	return _direccion;
}

const char *Persona::getTelefono() {
	return _telefono;
}

Fecha Persona::getFechaAlta() {
	return _fechaAlta;
}

bool Persona::getEstado() {
	return _estado;
}
