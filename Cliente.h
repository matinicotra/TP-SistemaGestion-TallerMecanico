#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente: public Persona {
private:
	std::string _razonSocial;
	bool _estado;

public:
    Cliente();

    void setDni(const char *dni);
    void setEstado(bool estado);

    const char *getDni();
    bool getEstado();

};

#endif // CLIENTE_H
