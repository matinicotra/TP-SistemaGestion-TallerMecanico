#ifndef AUTOCLIENTEMANAGER_H
#define AUTOCLIENTEMANAGER_H

#include "AutoCliente.h"
#include "AutoClienteArchivo.h"

class AutoClienteManager {
private:
	AutoClienteArchivo _archivo;
	AutoClienteArchivo _archivoBkp = AutoClienteArchivo("autocliente.bkp");

public:
	void Cargar(std::string dni, std::string patente);

	void ListarTodos();
	void ListarVehiculosPorDni(std::string dni);
	void ListarRegistro(AutoCliente reg);

	void Eliminar(std::string patente);

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // AUTOCLIENTEMANAGER_H
