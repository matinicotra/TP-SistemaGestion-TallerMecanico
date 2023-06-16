#ifndef PRESUPUESTO_H
#define PRESUPUESTO_H


class Presupuesto {
	private:
		int _idPresupuesto;
		int _idCliente;
		char _patente[10];
		float _importe;
		std::string _detalle;
		Fecha _fechaPresupuesto;
		bool _estado;

	public:
		Presupuesto();

		void setIdPresupuesto(int id);
		void setIdCliente(int idCliente);
		void setPatente(const char *patente);
		void setImporte(float importe);
		void setDetalle(std::string detalle);
		void setFecha(Fecha fecha);
		void setEstado(bool estado);

		int getIdPresupuesto();
		int getIdCliente();
		const char *getPatente();
		float getImporte();
		std::string getDetalle();
		Fecha getFecha();
		bool getEstado();


	protected:

};

#endif // PRESUPUESTO_H
