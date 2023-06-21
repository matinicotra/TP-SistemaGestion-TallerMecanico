#ifndef AUTOCLIENTE_H
#define AUTOCLIENTE_H


class AutoCliente {
private:
	char _dniCliente[10];
	char _patente[10];
	bool _estado;

public:
    AutoCliente();
    AutoCliente(const char *dniCliente, const char *patente);

    void setDniCliente(const char *dniCliente);
	void setPatente(const char *patente);
	void setEstado(bool estado);

	const char *getDniCliente();
	const char *getPatente();
	bool getEstado();

};

#endif // AUTOCLIENTE_H
