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
	bool _estado;

public:
    Persona();

	void setDni(const char *dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setEmail(std::string eMail);
    void setDireccion(std::string direccion);
    void setTelefono(const char *telefono);
    void setFechaAlta(Fecha fechaAlta);
    void setEstado(bool estado);

    const char *getDni();
    std::string getNombre();
    std::string getApellido();
    std::string getEmail();
    std::string getDireccion();
    const char *getTelefono();
    Fecha getFechaAlta();
    bool getEstado();

};

#endif // PERSONA_H
