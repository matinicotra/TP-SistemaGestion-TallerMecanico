#ifndef PRESUPUESTOMANAGER_H
#define PRESUPUESTOMANAGER_H

#include "Presupuesto.h"
#include "PresupuestoArchivo.h"

class PresupuestoManager {
private:
	PresupuestoArchivo _archivo;
	PresupuestoArchivo _archivoBkp= PresupuestoArchivo("presupuestos.bkp");

	int GenerarId();
	bool ExisteId(int id);

public:
	void Cargar();

	void ListarTodos();
	void ListarRegistro(Presupuesto presupuesto);
	void ListarPorId();
	void ListarPorDni();		///lista todos los presu que coincidan con dni ingresado
	void ListarPorPatente();	///lista todos los presu que coincidan con patente ingresada

	void EditarImporte();
	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();
};

#endif // PRESUPUESTOMANAGER_H