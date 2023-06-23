#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado: public Persona {
private:
	Fecha _fechaNacimiento;
	Fecha _fechaAlta;
	char _cargo[50];
	float _sueldo;
	char _cuentaBancaria[20];
	bool _estado;

public:
	Empleado();
	Empleado(Fecha fechaNacimiento, std::string cargo, float sueldo, std::string cuentaBancaria);

	void setFechaNacimiento(Fecha fechaNacimiento);
    void setFechaAlta(Fecha fechaAlta);
	void setCargo(std::string cargo);
	void setSueldo(float sueldo);
	void setCuentaBancaria(std::string cuenta);
	void setEstado(bool estado);

	Fecha getFechaNacimiento();
    Fecha getFechaAlta();
	std::string getCargo();
	float getSueldo();
	std::string getCuentaBancaria();
	bool getEstado();
};

#endif // EMPLEADO_H
