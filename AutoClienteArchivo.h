#ifndef AUTOCLIENTEARCHIVO_H
#define AUTOCLIENTEARCHIVO_H

#include "AutoCliente.h"

class AutoClienteArchivo {
private:
	std::string _ruta;

public:
	AutoClienteArchivo();
    AutoClienteArchivo(std::string ruta);

	int GetCantidadRegistros();
	int BuscarDni(std::string dni);				///devuelve la posicion del registro en el archivo ingresando dni
	int BuscarPatente(std::string patente);		///devuelve la posicion del registro en el archivo ingresando patente

	AutoCliente Leer(int pos);
	void Leer(AutoCliente *vec, int cantRegistros);		///posibilita cargar en un vector todos los registros (backup)

	bool Guardar(AutoCliente reg);							///diferenciamos por sobrecarga
	bool Guardar(AutoCliente reg, int posReemplazo);		///sobreescribir
	bool Guardar(AutoCliente *vec, int cantRegistros);		///guardar desde un vec para backup

	void Vaciar();

};

#endif // AUTOCLIENTEARCHIVO_H
