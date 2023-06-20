#ifndef CLIENTEARCHIVO_H
#define CLIENTEARCHIVO_H


class ClienteArchivo
{
private:
	std::string _ruta;

public:
    ClienteArchivo();
    ClienteArchivo(std::string ruta);

	int GetCantidadRegistros();
	int Buscar(int id);						///devuelve posicion en archivo ingresando id

	Cliente Leer(int pos);
	void Leer(Cliente *vec, int cantRegistros);		///posibilita cargar en un vector todos los registros (backup)

	bool Guardar(Cliente reg);							///diferenciamos por sobrecarga
	bool Guardar(Cliente reg, int posReemplazo);		///sobreescribir
	bool Guardar(Cliente *vec, int cantRegistros);		///guardar desde un vec para backup

	void Vaciar();
};

#endif // CLIENTEARCHIVO_H
