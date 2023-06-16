#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "Persona.h"

class Proveedor: public Persona {
private:
	int _idProveedor;
	std::string _rubro;
	bool _estado;

public:
	Proveedor();

	void setRubro(std::string rubro);

	std::string getRubro();

};

#endif // PROVEEDOR_H
