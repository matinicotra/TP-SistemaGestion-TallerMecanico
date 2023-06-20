#ifndef EMPLEADOARCHIVO_H
#define EMPLEADOARCHIVO_H


class EmpleadoArchivo
{
private:
	std::string _ruta;

public:
    EmpleadoArchivo();
    EmpleadoArchivo(std::string ruta);

	int GetCantidadRegistros();
	int Buscar(int id);						///devuelve posicion en archivo ingresando id

	Empleado Leer(int pos);
	void Leer(Empleado *vec, int cantRegistros);		///posibilita cargar en un vector todos los registros (backup)

	bool Guardar(Empleado reg);							///diferenciamos por sobrecarga
	bool Guardar(Empleado reg, int posReemplazo);		///sobreescribir
	bool Guardar(Empleado *vec, int cantRegistros);		///guardar desde un vec para backup

	void Vaciar();
};

#endif // EMPLEADOARCHIVO_H
