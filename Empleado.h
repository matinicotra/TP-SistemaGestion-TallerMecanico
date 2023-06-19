#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado: public Persona {
private:
	int _idEmpleado;
	char _dni[10];
	Fecha _fechaNacimiento;
	std::string _cargo;
	float _sueldo;
	char _cuentaBancaria[20];

public:
	Empleado();

	void _setIdEmpleado(int id);
	void setDni(const char *dni);
	void setFechaNacimiento(Fecha fechaNacimiento);
	void setCargo(std::string cargo);
	void setSueldo(float sueldo);
	void setCuentaBancaria(const char *cuenta);

	int getIdEmpleado();
	const char *getDni();
	Fecha getFechaNacimiento();
	std::string getCargo();
	float getSueldo();
	const char *getCuentaBancaria();

};

#endif // EMPLEADO_H
