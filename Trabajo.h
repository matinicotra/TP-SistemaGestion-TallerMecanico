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
	int _avanceTrabajo; 	//1 diagnostico, 2 desmontaje, 3 reparacion, 4 ensamblaje, 5 entregado
	Fecha _fechaEntrada;
	Fecha _fechaEntrega;
	std::string _detalle;
	bool _estado;


public:
	Trabajo();

	void setIdTrabajo(int idTrabajo);
	void setIdPresupuesto(int idPresupuesto);
	void setPatente(const char *patente);
	void setDniCliente(const char *dniCliente);
	void setDniProveedor(const char *dniProveedor);
	void setDniEmpleado(const char *dniEmpleado);
	void setAvanceTrabajo(int avanceTrabajo);
	void setFechaEntrada(Fecha fechaEntrada);
	void setFechaEntrega(Fecha fechaEntrega);
	void setDetalle(std::string detalle);
	void setEstado(bool estado);

	int getIdTrabajo();
	int getIdPresupuesto();
	const char *getPatente();
	const char *getDniCliente();
	const char *getDniProveedor();
	const char *getDniEmpleado();
	int getAvanceTrabajo();
	Fecha getFechaEntrada();
	Fecha getFechaEntrega();
	std::string getDetalle();
	bool getEstado();

};

#endif // TRABAJO_H
