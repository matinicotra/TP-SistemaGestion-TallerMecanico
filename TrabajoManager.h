#ifndef TRABAJOMANAGER_H
#define TRABAJOMANAGER_H

#include "Trabajo.h"
#include "TrabajoArchivo.h"

class TrabajoManager
{
private:
	TrabajoArchivo _archivo;
	TrabajoArchivo _archivoBkp = TrabajoArchivo("trabajos.bkp");

	int GenerarId();
	bool ExisteId(int id);

public:
    void Cargar();


};

#endif // TRABAJOMANAGER_H
