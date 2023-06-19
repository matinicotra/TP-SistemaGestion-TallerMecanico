#ifndef CLIENTE_H
#define CLIENTE_H

#include "Persona.h"

class Cliente: public Persona {
private:
	int _idCliente;
	char _dni[10];
	bool _estado;

public:
    Cliente();

    void setId(int id);
    void setDni(const char *dni);
    void setEstado(bool estado);

    int getIdCliente();
    const char *getDni();
    bool getEstado();

};

#endif // CLIENTE_H
