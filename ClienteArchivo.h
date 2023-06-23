#ifndef CLIENTEARCHIVO_H
#define CLIENTEARCHIVO_H

#include "Cliente.h"

class ClienteArchivo {
private:
	std::string _ruta;

public:
    ClienteArchivo();
    ClienteArchivo(std::string ruta);

	int GetCantidadRegistros();
	int Buscar(std::string dni);						///devuelve posicion en archivo ingresando dni

	Cliente Leer(int pos);
	void Leer(Cliente *vec, int cantRegistros);			///posibilita cargar en un vector todos los registros (backup)

	bool Guardar(Cliente reg);							///diferenciamos por sobrecarga
	bool Guardar(Cliente reg, int posReemplazo);		///sobreescribir
	bool Guardar(Cliente *vec, int cantRegistros);		///guardar en un vec (para backup)

	void Vaciar();
};

#endif // CLIENTEARCHIVO_H
