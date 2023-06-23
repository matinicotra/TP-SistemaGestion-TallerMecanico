#include <cstring>
#include "Persona.h"

Persona::Persona() {
	strcpy(_dni, "");
	strcpy(_nombre, "");
	strcpy(_apellido, "");
	strcpy(_eMail, "");
	strcpy(_direccion, "");
	strcpy(_telefono, "");
}

Persona::Persona(std::string dni, std::string nombre, std::string apellido, std::string eMail, std::string direccion, std::string telefono){
	strcpy(_dni, dni.c_str());
	strcpy(_nombre, nombre.c_str());
	strcpy(_apellido, apellido.c_str());
	strcpy(_eMail, eMail.c_str());
	strcpy(_direccion, direccion.c_str());
	strcpy(_telefono, telefono.c_str());
}

void Persona::setDni(std::string dni) {
	strcpy(_dni, dni.c_str());
}

void Persona::setNombre(std::string nombre) {
	strcpy(_nombre, nombre.c_str());
}

void Persona::setApellido(std::string apellido) {
	strcpy(_apellido, apellido.c_str());
}

void Persona::setEmail(std::string eMail) {
	strcpy(_eMail, eMail.c_str());
}

void Persona::setDireccion(std::string direccion) {
	strcpy(_direccion, direccion.c_str());
}

void Persona::setTelefono(std::string telefono) {
	strcpy(_telefono, telefono.c_str());
}

std::string Persona::getDni() {
	std::string dniAux = _dni;
	return dniAux;
}

std::string Persona::getNombre() {
	std::string nombreAux = _nombre;
	return nombreAux;
}

std::string Persona::getApellido() {
	std::string apellidoAux = _apellido;
	return apellidoAux;
}

std::string Persona::getEmail() {
	std::string eMailAux = _eMail;
	return eMailAux;
}

std::string Persona::getDireccion() {
	std::string direccionAux;
	return direccionAux;
}

std::string Persona::getTelefono() {
	std::string telefonoAux = _telefono;
	return telefonoAux;
}


