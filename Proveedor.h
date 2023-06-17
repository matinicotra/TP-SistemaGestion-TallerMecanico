#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "Persona.h"

class Proveedor: public Persona {
private:
	int _idProveedor;
	std::string _rubro;
	std::string _autoparte;
	std::string _origenFabricacion;
	bool _estado;

public:
	Proveedor();

	void setRubro(std::string rubro);
	void setAutoparte(std::string autoparte);
	void setOrigeFabricacion(std::string origenFabricacion);

	std::string getRubro();
	std::string getAutoparte();
	std::string getOrigenFabricacion();

};

#endif // PROVEEDOR_H
