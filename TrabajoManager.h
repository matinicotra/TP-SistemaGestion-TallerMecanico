#ifndef TRABAJOMANAGER_H
#define TRABAJOMANAGER_H

#include "Trabajo.h"
#include "TrabajoArchivo.h"

class TrabajoManager
{
private:
	TrabajoArchivo _archivo;
	TrabajoArchivo _archivoBkp = TrabajoArchivo("trabajos.bkp");

	bool ExisteId(int id);
	int GenerarId();

public:
    TrabajoManager();


};

#endif // TRABAJOMANAGER_H
