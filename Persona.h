#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <cstring>
#include "Fecha.h"

class Persona {
protected:
	char _dni[10];
	char _nombre[20];
	char _apellido[20];
	char _eMail[50];
	char _direccion[100];
	char _telefono[15];

public:
    Persona();
    Persona(std::string dni, std::string nombre, std::string apellido, std::string eMail, std::string direccion, std::string telefono);

	void setDni(std::string dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setEmail(std::string eMail);
    void setDireccion(std::string direccion);
    void setTelefono(std::string telefono);

    std::string getDni();
    std::string getNombre();
    std::string getApellido();
    std::string getEmail();
    std::string getDireccion();
    std::string getTelefono();

};

#endif // PERSONA_H
