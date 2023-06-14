#ifndef VEHICULO_H
#define VEHICULO_H

#include <Fecha.h>
#include <string>

class Vehiculo {
private:
	int _idVehiculo;
 	char _patente[10];
	std::string _modelo;
	std::string _marca;
	int anio;
	Fecha _fechaAlta;
	bool _estado;

public:
    Vehiculo(const char *patente = "0000");

    void setPatente(const char *patente);
    void setModelo(std::string modelo);
    void setMarca(std::string marca);
    void setEstado(bool estado);

    const char *getPatente();
	std::string getModelo();
    std::string getMarca();
    bool getEstado();

};

#endif // VEHICULO_H
