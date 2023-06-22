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
	std::string _detalle;
	Fecha _fechaPresupuesto;
	bool _asistenciaGrua;
	bool _vehiculoSustitucion;
	bool _estado;

public:
	Presupuesto();
	Presupuesto(int idPresupuesto, const char* dniCliente, const char* patente, float importe, std::string detalle, Fecha fechaPresupuesto, bool asistenciaGrua, bool vehiculoSustitucion);

	void setIdPresupuesto(int idPresupuesto);
	void setDniCliente(const char *dniCliente);
	void setPatente(const char *patente);
	void setImporte(float importe);
	void setDetalle(std::string detalle);
	void setFecha(Fecha fecha);
	void setAsistenciaGrua(bool asistenciaGrua);
	void setVehiculoSustitucion(bool vehiculoSustitucion);
	void setEstado(bool estado);

	int getIdPresupuesto();
	const char *getDniCliente();
	const char *getPatente();
	float getImporte();
	std::string getDetalle();
	Fecha getFecha();
	bool getAsistenciaGrua();
	bool getVehiculoSustitucion();
	bool getEstado();

};

#endif // PRESUPUESTO_H
