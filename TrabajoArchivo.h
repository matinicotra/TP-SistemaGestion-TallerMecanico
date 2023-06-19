#ifndef TRABAJOARCHIVO_H
#define TRABAJOARCHIVO_H

#include <Trabajo.h>

class TrabajoArchivo {
private:
	std::string _ruta;

public:
    TrabajoArchivo();
    TrabajoArchivo(std::string ruta);

	int getCantidadRegistros();
	int buscar(int id);						///devuelve posicion en archivo ingresando id

	Trabajo leer(int pos);
	void leer(Trabajo *vec, int cantRegistros);		///posibilita cargar en un vector Trabajo todos los registros, para hacer backup

	bool guardar(Trabajo reg);							///diferenciamos por sobrecarga
	bool guardar(Trabajo reg, int posReemplazo);		///sobreescribir
	bool guardar(Trabajo *vec, int cantRegistros);		///guardar desde un vec para backup


};

#endif // TRABAJOARCHIVO_H
