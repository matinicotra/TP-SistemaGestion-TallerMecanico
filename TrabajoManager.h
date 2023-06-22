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
	void ListarPorPatente(const char *patente);
	void ListarPorDniCliente(const char *dniCliente);
	void ListarPorAvance(int avance);

	void Mostrar(int id);
	void Mostrar(Trabajo trabajo);

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // TRABAJOMANAGER_H
