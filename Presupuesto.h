#ifndef PRESUPUESTO_H
#define PRESUPUESTO_H

#include <cstring>
#include <string>
#include <Fecha.h>

class Presupuesto {
private:
	int _idPresupuesto;
	char _dniCliente[10];
	char _patente[10];
	float _importe;
	char _detalle[100];
	Fecha _fechaPresupuesto;
	bool _asistenciaGrua;
	bool _vehiculoSustitucion;
	bool _estado;

public:
	Presupuesto();
	Presupuesto(int idPresupuesto, std::string dniCliente, std::string patente, float importe, std::string detalle, Fecha fechaPresupuesto, bool asistenciaGrua, bool vehiculoSustitucion);

	void setIdPresupuesto(int idPresupuesto);
	void setDniCliente(std::string dniCliente);
	void setPatente(std::string patente);
	void setImporte(float importe);
	void setDetalle(std::string detalle);
	void setFecha(Fecha fecha);
	void setAsistenciaGrua(bool asistenciaGrua);
	void setVehiculoSustitucion(bool vehiculoSustitucion);
	void setEstado(bool estado);

	int getIdPresupuesto();
	std::string getDniCliente();
	std::string getPatente();
	float getImporte();
	std::string getDetalle();
	Fecha getFecha();
	bool getAsistenciaGrua();
	bool getVehiculoSustitucion();
	bool getEstado();

};

#endif // PRESUPUESTO_H
