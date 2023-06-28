#ifndef EMPLEADOMANAGER_H
#define EMPLEADOMANAGER_H

#include "Empleado.h"
#include "EmpleadoArchivo.h"

class EmpleadoManager {
private:
	EmpleadoArchivo _archivo;
	EmpleadoArchivo _archivoBkp = EmpleadoArchivo("empleados.bkp");

	void OrdenarPorSueldo(Empleado *vec, int cantRegistros);
	void OrdenarPorFecha(Empleado *vec, int cantRegistros);

public:
	void Cargar();

	void ListarTodos();
	void ListarRegistro(Empleado empleado);
	void ListarPorDni();

	void ListarOrdenadoPorSueldo();
	void ListarOrdenadoPorFechaNacimiento();

	void EditarSueldo();
	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();
};

#endif // EMPLEADOMANAGER_H
