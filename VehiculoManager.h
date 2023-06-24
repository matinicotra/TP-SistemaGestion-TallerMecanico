#ifndef VEHICULOMANAGER_H
#define VEHICULOMANAGER_H

#include "Vehiculo.h"
#include "VehiculoArchivo.h"

class VehiculoManager {
private:
	VehiculoArchivo _archivo;
	VehiculoArchivo _archivoBkp = VehiculoArchivo("vehiculos.bkp");

public:
	void Cargar();

	void ListarTodos();
	void ListarRegistro(Vehiculo vehiculo);
	void ListarPorPatente();

	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();
};

#endif // VEHICULOMANAGER_H
