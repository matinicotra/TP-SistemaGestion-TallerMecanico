#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"
#include "ClienteArchivo.h"

#include "Funciones.h"

class ClienteManager {
private:
	ClienteArchivo _archivo;
	ClienteArchivo _archivoBkp = ClienteArchivo("clientes.bkp");

	void OrdenarPorFecha(Cliente *vec, int cantRegistros);
	void OrdenarPorApellido(Cliente *vec, int cantRegistros);

public:
	void Cargar();

	void ListarTodos();
	void ListarRegistro(Cliente cliente);
	void ListarPorDni();
	void ListarPorApellido();
	void ListarOrdenadosPorFechaAlta();
	void ListarOrdenadosPorApellido();

	void ListarVehiculosAsociados();
	void EditarVehiculosAsociados();

	void EditarTelefono();
	void EditarFechaAlta();
	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // CLIENTEMANAGER_H
