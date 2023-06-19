#ifndef TRABAJOARCHIVO_H
#define TRABAJOARCHIVO_H

#include <Trabajo.h>

class TrabajoArchivo {
private:
	std::string _ruta;

public:
    TrabajoArchivo();
    TrabajoArchivo(std::string ruta);

	int GetCantidadRegistros();
	int Buscar(int id);						///devuelve posicion en archivo ingresando id

	Trabajo Leer(int pos);
	void Leer(Trabajo *vec, int cantRegistros);		///posibilita cargar en un vector Trabajo todos los registros, para hacer backup

	bool Guardar(Trabajo reg);							///diferenciamos por sobrecarga
	bool Guardar(Trabajo reg, int posReemplazo);		///sobreescribir
	bool Guardar(Trabajo *vec, int cantRegistros);		///guardar desde un vec para backup


};

#endif // TRABAJOARCHIVO_H
