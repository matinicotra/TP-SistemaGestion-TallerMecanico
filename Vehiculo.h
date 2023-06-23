#ifndef VEHICULO_H
#define VEHICULO_H

#include <Fecha.h>
#include <string>

class Vehiculo {
private:
 	char _patente[10];
	std::string _modelo;
	std::string _marca;
	int _anio;
	Fecha _fechaAlta;
	bool _estado;

public:
    Vehiculo();
    Vehiculo(const char* patente, std::string modelo, std::string marca, int anio, Fecha fechaAlta);

    void setPatente(const char *patente);
    void setModelo(std::string modelo);
    void setMarca(std::string marca);
    void setAnio(int anio);
    void setFechaAlta(Fecha alta);
    void setEstado(bool estado);

    const char *getPatente();
	std::string getModelo();
    std::string getMarca();
    int getAnio();
    Fecha getFechaAlta();
    bool getEstado();

};

#endif // VEHICULO_H
