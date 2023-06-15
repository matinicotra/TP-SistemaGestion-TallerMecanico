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
	int _anio;
	Fecha _fechaAlta;
	bool _estado;

public:
    Vehiculo();

	void setId(int id);
    void setPatente(const char *patente);
    void setModelo(std::string modelo);
    void setMarca(std::string marca);
    void setAnio(int anio);
    void setFechaAlta(Fecha alta);
    void setEstado(bool estado);

	int getId();
    const char *getPatente();
	std::string getModelo();
    std::string getMarca();
    int getAnio();
    Fecha getFechaAlta();
    bool getEstado();

};

#endif // VEHICULO_H
