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
	Trabajo leerRegistro(int pos);
	bool guardar(Trabajo reg);

};

#endif // TRABAJOARCHIVO_H
