#ifndef PROVEEDORMANAGER_H
#define PROVEEDORMANAGER_H

#include "Proveedor.h"
#include "ProveedorArchivo.h"

class ProveedorManager {
private:
	ProveedorArchivo _archivo;
	ProveedorArchivo _archivoBkp = ProveedorArchivo("proveedores.bkp");

	void OrdenarPorOrigen(Proveedor *vec, int cantRegistros);

public:
	void Cargar();

	void ListarTodos();
	void ListarRegistro(Proveedor proveedor);
	void ListarPorDni();
	void ListarPorRubro();
	void ListarPorOrigenFabricacion();

	void EditarTelefono();
	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();
};

#endif // PROVEEDORMANAGER_H
