#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado: public Persona {
private:
	Fecha _fechaNacimiento;
	char _cargo[50];
	float _sueldo;
	char _cuentaBancaria[20];
	bool _estado;

public:
	Empleado();
	Empleado(std::string dni, std::string nombre, std::string apellido, std::string eMail, std::string direccion, std::string telefono, Fecha fechaNacimiento, std::string cargo, float sueldo, std::string cuentaBancaria);

	void setFechaNacimiento(Fecha fechaNacimiento);
	void setCargo(std::string cargo);
	void setSueldo(float sueldo);
	void setCuentaBancaria(std::string cuenta);
	void setEstado(bool estado);

	Fecha getFechaNacimiento();
	std::string getCargo();
	float getSueldo();
	std::string getCuentaBancaria();
	bool getEstado();
};

#endif // EMPLEADO_H
