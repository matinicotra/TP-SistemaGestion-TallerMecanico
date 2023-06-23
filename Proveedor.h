#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "Persona.h"

class Proveedor: public Persona {
private:
	char _rubro[50];
	char _autoparte[50];
	char _origenFabricacion[30];
	bool _estado;

public:
	Proveedor();
	Proveedor(std::string rubro, std::string autoparte, std::string origenFabricacion);

	void setRubro(std::string rubro);
	void setAutoparte(std::string autoparte);
	void setOrigeFabricacion(std::string origenFabricacion);
	void setEstado(bool estado);

	std::string getRubro();
	std::string getAutoparte();
	std::string getOrigenFabricacion();
	bool getEstado();

};

#endif // PROVEEDOR_H
