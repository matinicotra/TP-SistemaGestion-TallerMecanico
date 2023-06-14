#include "Persona.h"
#include <cstring>

Persona::Persona(const char *dni) {
	strcpy(_dni, dni);
}

void Persona::setDni(const char *dni) {
	strcpy(_dni, dni);
}

void Persona::setNombre(std::string nombre) {
	_nombre = nombre;
}

void Persona::setApellido(std::string apellido) {
	_apellido = apellido;
}

void Persona::setEmail(std::string email) {
	_email = email;
}

void Persona::setDireccion(std::string direccion) {
	_direccion = direccion;
}

void Persona::setTelefono(const char *telefono) {
	strcpy(_telefono, telefono);
}

void Persona::setEstado(bool estado) {
	_estado = estado;
}

const char *Persona::getDni() {
	return _dni;
}

std::string Persona::getNombre() {
	return _nombre;
}

std::string Persona::getApellido() {
	return _apellido;
}

std::string Persona::getEmail() {
	return _email;
}

std::string Persona::getDireccion() {
	return _direccion;
}

const char *Persona::getTelefono() {
	return _telefono;
}

bool Persona::getEstado() {
	return _estado;
}
