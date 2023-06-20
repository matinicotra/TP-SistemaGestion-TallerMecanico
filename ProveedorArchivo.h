#ifndef PROVEEDORARCHIVO_H
#define PROVEEDORARCHIVO_H

#include <Proveedor.h>

class ProveedorArchivo {
private:
	std::string _ruta;

public:
    ProveedorArchivo();
    ProveedorArchivo(std::string ruta);

    int GetCantidadRegistros();
    int Buscar(int id);						///devuelve posicion en archivo ingresando id

	Proveedor Leer(int pos);
	void Leer(Proveedor *vec, int cantRegistros);		///posibilita cargar en un vector todos los registros (backup)

	bool Guardar(Proveedor reg);							///diferenciamos por sobrecarga
	bool Guardar(Proveedor reg, int posReemplazo);		///sobreescribir
	bool Guardar(Proveedor *vec, int cantRegistros);		///guardar desde un vec para backup

	void Vaciar();

};

#endif // PROVEEDORARCHIVO_H
