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
	void Ordenar(Trabajo *vec, int cantRegistros); ///por fecha

public:
    void Cargar();

	void ListarPorId();
	void ListarTodos();
	void ListarRegistro(Trabajo trabajo);

	void ListarPorPatente();
	void ListarPorDniCliente();
	void ListarPorAvance();
	void ListarOrdenadosPorFecha();

	void ActualizarAvance();
	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // TRABAJOMANAGER_H
