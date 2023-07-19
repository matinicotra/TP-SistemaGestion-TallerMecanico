#ifndef TRABAJOMANAGER_H
#define TRABAJOMANAGER_H

#include "Trabajo.h"
#include "TrabajoArchivo.h"

#include "Funciones.h"

class TrabajoManager {
private:
	TrabajoArchivo _archivo;
	TrabajoArchivo _archivoBkp = TrabajoArchivo("trabajos.bkp");

	int GenerarId();
	bool ExisteId(int id);
	void OrdenarPorFechaEntrada(Trabajo *vec, int cantRegistros);
	void OrdenarPorFechaEntrega(Trabajo *vec, int cantRegistros);

public:
    std::string IngresarVehiculo(bool &nuevoVehiculo);  //devuelve patente
    std::string IngresarCliente(bool &nuevoCliente);   //devuelve dni
    int IngresarPresupuesto(float &precioTrabajo); 	  //devuelve id de presupuesto
    void Cargar();

	void ListarPorId();
	void ListarTodos();
	void ListarRegistro(Trabajo trabajo);

	void ListarPorPatente();
	void ListarPorDniCliente();
	void ListarPorAvance();
	void ListarOrdenadosPorFecha();
	void ListarEntregadosPorFecha();
	void ListarPorEmpleado();

	void EditarFechaEntrada();
	void EditarFechaEntrega();

	void ActualizarAvance();
	void ActualizarProveedor();
	void ActualizarEmpleado();
	void AsignarPresupuesto();
	void ActualizarPrecio();

	void Eliminar();

	void HacerCopiaDeSeguridad();
	void RestaurarCopiaDeSeguridad();

};

#endif // TRABAJOMANAGER_H
