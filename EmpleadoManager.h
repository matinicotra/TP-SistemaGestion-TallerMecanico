#ifndef EMPLEADOMANAGER_H
#define EMPLEADOMANAGER_H

#include "Empleado.h"
#include "EmpleadoArchivo.h"

class EmpleadoManager {
private:
	EmpleadoArchivo _archivo;
	EmpleadoArchivo _archivoBkp = EmpleadoArchivo("empleados.bkp");

public:
	void Cargar();

	void ListarTodos();
	void ListarRegistro(Empleado empleado);
	void ListarPorDni();

	void EditarSueldo();
	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();
};

#endif // EMPLEADOMANAGER_H
