#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
private:
	char _patente[8];
	std::string _modelo;
	std::string _marca;
	bool _estado;

public:
    Vehiculo();

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
