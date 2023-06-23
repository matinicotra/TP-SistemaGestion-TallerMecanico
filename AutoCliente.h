#ifndef AUTOCLIENTE_H
#define AUTOCLIENTE_H

#include <string>

class AutoCliente {
private:
	char _dniCliente[10];
	char _patente[10];
	bool _estado;

public:
    AutoCliente();
    AutoCliente(std::string dniCliente, std::string patente);

    void setDniCliente(std::string dniCliente);
	void setPatente(std::string patente);
	void setEstado(bool estado);

	std::string getDniCliente();
	std::string getPatente();
	bool getEstado();

};

#endif // AUTOCLIENTE_H
