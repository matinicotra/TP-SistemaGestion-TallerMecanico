#ifndef PERSONA_H
#define PERSONA_H

#include "Fecha.h"
#include <string>

class Persona {
protected:
	char _dni[10];
	std::string _nombre;
	std::string _apellido;
	std::string _eMail;
	std::string _direccion;
	char _telefono[15];
	Fecha _fechaAlta;

public:
    Persona();
    Persona(const char* dni, std::string nombre, std::string apellido, std::string eMail, std::string direccion, const char* telefono, Fecha fechaAlta);

	void setDni(const char *dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setEmail(std::string eMail);
    void setDireccion(std::string direccion);
    void setTelefono(const char *telefono);
    void setFechaAlta(Fecha fechaAlta);

    const char *getDni();
    std::string getNombre();
    std::string getApellido();
    std::string getEmail();
    std::string getDireccion();
    const char *getTelefono();
    Fecha getFechaAlta();

};

#endif // PERSONA_H
