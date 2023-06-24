#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"
#include "ClienteArchivo.h"

class ClienteManager {
private:
	ClienteArchivo _archivo;
	ClienteArchivo _archivoBkp = ClienteArchivo("clientes.bkp");

public:
	void Cargar();

	void ListarTodos();
	void ListarRegistro(Cliente cliente);
	void ListarPorDni();

	void EditarTelefono();
	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

protected:

};

#endif // CLIENTEMANAGER_H
