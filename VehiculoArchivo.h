#ifndef VEHICULOARCHIVO_H
#define VEHICULOARCHIVO_H

#include "Vehiculo.h"

class VehiculoArchivo {
private:
	std::string _ruta;
public:
	VehiculoArchivo();
    VehiculoArchivo(std::string ruta);

	int GetCantidadRegistros();
	int Buscar(std::string patente);			///devuelve posicion de reg en el archivo ingresando patente

	Vehiculo Leer(int pos);
	void Leer(Vehiculo *vec, int cantRegistros);		///posibilita cargar en un vector todos los registros (backup)

	bool Guardar(Vehiculo reg);							///diferenciamos por sobrecarga
	bool Guardar(Vehiculo reg, int posReemplazo);		///sobreescribir
	bool Guardar(Vehiculo *vec, int cantRegistros);		///guardar desde un vec para backup

	void Vaciar();

};

#endif // VEHICULOARCHIVO_H
