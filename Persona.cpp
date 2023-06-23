#include <cstring>
#include "Persona.h"

Persona::Persona() {
	strcpy(_dni, "");
	_nombre = "";
	_apellido = "";
	_eMail = "";
	_direccion = "";
	strcpy(_telefono, "");
}

Persona::Persona(const char* dni, std::string nombre, std::string apellido, std::string eMail, std::string direccion, const char* telefono, Fecha fechaAlta){
	strcpy(_dni, dni);
	_nombre=nombre;
	_apellido=apellido;
	_eMail=eMail;
	_direccion=direccion;
	strcpy(_telefono, telefono);
	_fechaAlta=fechaAlta;
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

