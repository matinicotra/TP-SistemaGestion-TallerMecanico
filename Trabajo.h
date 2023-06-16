#ifndef TRABAJO_H
#define TRABAJO_H

#include <Fecha.h>
#include <string>

/*
Las funciones que realiza un mecánico automotriz están relacionadas
principalmente con la revisión técnica de un vehículo.
Por lo general, estas funciones abarcan
el diagnóstico vehicular,
mantenimiento preventivo, desmontaje,
reemplazo de componentes,
reparación
y ensamblaje.
*/

class Trabajo {
private:
	int _idTrabajo;
	int _idProveedor;
	int _idVehiculo;
	int _idCliente;
	int _idEmpleado;
	int _estadoTrabajo;
	Fecha _fechaEntrada;
	Fecha _fechaEntrega;
	std::string _detalle;
	float _presupuesto;
	bool _estado;


public:
	Trabajo();

	void setId(int id);
	void setIdProveedor(int idProveedor);
	void setIdVehiculo(int idVehiculo);
	void setIdCliente(int idCliente);
	void setIdEmpleado(int idEmpleado);
	void setEstadoTrabajo(int estadoTrabajo);
	void setFechaEntrada(Fecha fechaEntrada);
	void setFechaEntrega(Fecha fechaEntrega);
	void setDetalle(std::string detalle);
	void setPresupuesto(float presupuesto);
	void setEstado(bool estado);

	int getId();
	int getIdProveedor();
	int getIdVehiculo();
	int getIdCliente();
	int getIdEmpleado();
	int getEstadoTrabajo();
	Fecha getFechaEntrada();
	Fecha getFechaEntrega();
	std::string getDetalle();
	float getPresupuesto();
	bool getEstado();


};

#endif // TRABAJO_H
