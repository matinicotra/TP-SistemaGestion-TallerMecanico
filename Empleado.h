#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Persona.h"

class Empleado: public Persona {
private:
	Fecha _fechaNacimiento;
	std::string _cargo;
	float _sueldo;
	char _cuentaBancaria[20];
	bool _estado;

public:
	Empleado();
	Empleado(Fecha fechaNacimiento, std::string cargo, float sueldo, const char* cuentaBancaria);

	void setFechaNacimiento(Fecha fechaNacimiento);
	void setCargo(std::string cargo);
	void setSueldo(float sueldo);
	void setCuentaBancaria(const char *cuenta);
	void setEstado(bool estado);

	Fecha getFechaNacimiento();
	std::string getCargo();
	float getSueldo();
	const char *getCuentaBancaria();
	bool getEstado();
};

#endif // EMPLEADO_H
