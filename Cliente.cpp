#include <cstring>
#include "Cliente.h"

Cliente::Cliente() {
    strcpy(_razonSocial, "");
	_estado = true;
}

Cliente::Cliente(std::string dni, std::string nombre, std::string apellido, std::string eMail, std::string direccion, std::string telefono, std::string razonSocial){
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setEmail(eMail);
    setDireccion(direccion);
    setTelefono(telefono);
}

Cliente::Cliente (std::string razonSocial){
    strcpy(_razonSocial, razonSocial.c_str());
    _estado = true;
}

void Cliente::setRazonSocial(std::string razonSocial) {
    strcpy(_razonSocial, razonSocial.c_str());
}

void Cliente::setFechaAlta(Fecha fechaAlta) {
	_fechaAlta = fechaAlta;
}

void Cliente::setEstado(bool estado) {
	_estado = estado;
}


std::string Cliente::getRazonSocial() {
	std::string razonSocialAux = _razonSocial;
	return razonSocialAux;
}

Fecha Cliente::getFechaAlta() {
	return _fechaAlta;
}

bool Cliente::getEstado() {
	return _estado;
}
