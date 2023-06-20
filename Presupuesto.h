#ifndef PRESUPUESTO_H
#define PRESUPUESTO_H


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
