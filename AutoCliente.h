#ifndef AUTOCLIENTE_H
#define AUTOCLIENTE_H


class AutoCliente {
private:
	int _idCliente;
	int _idVehiculo;
	bool _estado;

public:
    AutoCliente();
    AutoCliente(int idCliente, int idVehiculo);

    void setIdCliente(int idCliente);
	void setIdVehiculo(int idVehiculo);
	void setEstado(bool estado);

	int getIdCliente();
	int getIdVehiculo();
	bool getEstado();

};

#endif // AUTOCLIENTE_H
