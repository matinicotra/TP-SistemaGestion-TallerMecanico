#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"
#include "ClienteArchivo.h"

class ClienteManager {
private:
	ClienteArchivo _archivo;
	ClienteArchivo _archivoBkp = ClienteArchivo("clientes.bkp");

	void OrdenarPorFecha(Trabajo *vec, int cantRegistros);
	void OrdenarPorApellido(Trabajo *vec, int cantRegistros);

public:
	void Cargar();

	void ListarTodos();
	void ListarRegistro(Cliente cliente);
	void ListarPorDni();
	void ListarPorApellido();
//	void ListarTrabajosCliente();
	void ListarPorFechaDeAlta();
	void ListarPorApellido();

	void EditarTelefono();
	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // CLIENTEMANAGER_H
