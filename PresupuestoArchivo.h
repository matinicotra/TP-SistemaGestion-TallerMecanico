#ifndef PRESUPUESTOARCHIVO_H
#define PRESUPUESTOARCHIVO_H

#include "Presupuesto.h"

class PresupuestoArchivo {
private:
	str::string _ruta;

public:
	PresupuestoArchivo();
	PresupuestoArchivo(std::string ruta);

	int GetCantidadRegistros();
	int Buscar(int id);						///devuelve posicion en archivo ingresando id

	Presupuesto Leer(int pos);
	void Leer(Presupuesto *vec, int cantRegistros);		///posibilita cargar en un vector todos los registros (backup)

	bool Guardar(Presupuesto reg);							///diferenciamos por sobrecarga
	bool Guardar(Presupuesto reg, int posReemplazo);		///sobreescribir
	bool Guardar(Presupuesto *vec, int cantRegistros);		///guardar desde un vec para backup

	void Vaciar();

};

#endif // PRESUPUESTOARCHIVO_H
