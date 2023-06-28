#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"
#include "ClienteArchivo.h"

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
	void ListarTrabajosCliente();
	void ListarOrdenadosPorFechaAlta();
	void ListarOrdenadosPorApellido();
	//void ListarEntreFechas(Fecha fecha1, Fecha fecha2);

	void EditarTelefono();
	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // CLIENTEMANAGER_H
