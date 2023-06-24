#ifndef TRABAJO_H
#define TRABAJO_H

#include <Fecha.h>
#include <string>

class Trabajo {
private:
	int _idTrabajo;
	int _idPresupuesto;
	char _patente[10];
	char _dniCliente[10];
	char _dniProveedor[10];
	char _dniEmpleado[10];
	int _avanceTrabajo; 	//1 diagnostico, 2 desmontaje, 3 ensamblaje, 4 finalizado, 5 entregado
	Fecha _fechaEntrada;
	Fecha _fechaEntrega;
	bool _estado;


public:
	Trabajo();
	Trabajo(int idTrabajo, int idPresupuesto, std::string patente, std::string dniCliente, std::string dniProveedor, std::string dniEmpleado, int avanceTrabajo, Fecha fechaEntrada, Fecha fechaEntrega);

	void setIdTrabajo(int idTrabajo);
	void setIdPresupuesto(int idPresupuesto);
	void setPatente(std::string patente);
	void setDniCliente(std::string dniCliente);
	void setDniProveedor(std::string dniProveedor);
	void setDniEmpleado(std::string dniEmpleado);
	void setAvanceTrabajo(int avanceTrabajo);
	void setFechaEntrada(Fecha fechaEntrada);
	void setFechaEntrega(Fecha fechaEntrega);
	void setEstado(bool estado);

	int getIdTrabajo();
	int getIdPresupuesto();
	std::string getPatente();
	std::string getDniCliente();
	std::string getDniProveedor();
	std::string getDniEmpleado();
	int getAvanceTrabajo();
	Fecha getFechaEntrada();
	Fecha getFechaEntrega();
	bool getEstado();

};

#endif // TRABAJO_H
