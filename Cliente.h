#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente: public Persona {
private:
	std::string _razonSocial;
	bool _estado;

public:
    Cliente();

	void setRazonSocial(std::string razonSocial);
    void setEstado(bool estado);

	std::string getRazonSocial();
    bool getEstado();

};

#endif // CLIENTE_H
