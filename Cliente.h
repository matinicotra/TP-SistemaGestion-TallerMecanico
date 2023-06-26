#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente: public Persona {
private:
	char _razonSocial[50];
	bool _estado;
	Fecha _fechaAlta;

public:
    Cliente();
    Cliente (std::string dni, std::string nombre, std::string apellido, std::string eMail, std::string direccion, std::string telefono, std::string razonSocial, Fecha fechaAlta);

	void setRazonSocial(std::string razonSocial);
    void setEstado(bool estado);
    void setFechaAlta(Fecha fechaAlta);

	std::string getRazonSocial();
    Fecha getFechaAlta();
    bool getEstado();

};

#endif // CLIENTE_H
