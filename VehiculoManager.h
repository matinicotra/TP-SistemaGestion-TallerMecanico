#ifndef VEHICULOMANAGER_H
#define VEHICULOMANAGER_H

#include "Vehiculo.h"
#include "VehiculoArchivo.h"

class VehiculoManager {
private:
	VehiculoArchivo _archivo;
	VehiculoArchivo _archivoBkp = VehiculoArchivo("vehiculos.bkp");

	void OrdenarPorPatente(Vehiculo *vec, int cantRegistros);
	void OrdenarPorFecha(Vehiculo *vec, int cantRegistros);

public:
	void Cargar();

	void ListarTodos();
	void ListarRegistro(Vehiculo vehiculo);
	void ListarPorPatente();
	void ListarOrdenadosPorPatente();
	void ListarOrdenadosPorFechaAlta();

	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();
};

#endif // VEHICULOMANAGER_H
