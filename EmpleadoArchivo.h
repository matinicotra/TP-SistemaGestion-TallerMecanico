#ifndef EMPLEADOARCHIVO_H
#define EMPLEADOARCHIVO_H

#include "Empleado.h"

class EmpleadoArchivo {
private:
	std::string _ruta;

public:
    EmpleadoArchivo();
    EmpleadoArchivo(std::string ruta);

	int GetCantidadRegistros();
	int Buscar(std::string dni);						///devuelve posicion en archivo ingresando dni

	Empleado Leer(int pos);
	void Leer(Empleado *vec, int cantRegistros);		///posibilita cargar en un vector todos los registros (backup)

	bool Guardar(Empleado reg);							///diferenciamos por sobrecarga
	bool Guardar(Empleado reg, int posReemplazo);		///sobreescribir
	bool Guardar(Empleado *vec, int cantRegistros);		///guardar en un vec para backup

	void Vaciar();
};

#endif // EMPLEADOARCHIVO_H
