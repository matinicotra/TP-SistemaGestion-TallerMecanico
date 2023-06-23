#ifndef TRABAJOMANAGER_H
#define TRABAJOMANAGER_H

#include "Trabajo.h"
#include "TrabajoArchivo.h"

class TrabajoManager {
private:
	TrabajoArchivo _archivo;
	TrabajoArchivo _archivoBkp = TrabajoArchivo("trabajos.bkp");

	int GenerarId();
	bool ExisteId(int id);

public:
    void Cargar();

	void ListarTodos();
	void Listar(int id);
	void Listar(Trabajo trabajo);
	void ListarPorPatente(const char *patente);
	void ListarPorDniCliente(const char *dniCliente);
	void ListarPorAvance(int avance);

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // TRABAJOMANAGER_H
