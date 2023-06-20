#include "EmpleadoArchivo.h"

EmpleadoArchivo::EmpleadoArchivo() {
	_ruta = "empleados.dat";
}

EmpleadoArchivo::EmpleadoArchivo(std::string ruta) {
	_ruta = ruta;
}

int EmpleadoArchivo::GetCantidadRegistros() {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return -1;
	fseek(p, sizeof(Empleado), SEEK_END);
	int bytes = ftell(p);
	fclose(p);
	return bytes / sizeof(Empleado);
}

int EmpleadoArchivo::Buscar(const char *dni) {
	Empleado aux;
	int cantRegistros = this->GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		aux = this->Leer(i);
		if (!strcmp(aux.getDni(), dni)) return i;
	}
	return -1;
}

Empleado EmpleadoArchivo::Leer(int pos) {
	Empleado aux;
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return aux;
	fseek(p, sizeof(Empleado) * pos, SEEK_SET);
	fread(&aux, sizeof(Empleado), 1, p);
	fclose(p);
	return aux;
}

void EmpleadoArchivo::Leer(Empleado *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return;
	fread(vec, sizeof(Empleado), cantRegistros, p);
	fclose(p);
}

bool EmpleadoArchivo::Guardar(Empleado reg) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	bool escribio = fwrite(&reg, sizeof(Empleado), 1, p);
	fclose(p);
	return escribio;
}

bool EmpleadoArchivo::Guardar(Empleado reg, int posReemplazo) {
	FILE *p = fopen(_ruta.c_str(), "rb+");
	if (p == NULL) return false;
	fseek(p, sizeof(Empleado) * posReemplazo, SEEK_SET);
	bool escribio = fwrite(&reg, sizeof(Empleado), 1, p);
	fclose(p);
	return escribio;
}

bool EmpleadoArchivo::Guardar(Empleado *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	int cantEscritos = fwrite(vec, sizeof(Empleado), cantRegistros, p);
	fclose(p);
	return cantEscritos == cantRegistros;
}

void EmpleadoArchivo::Vaciar() {
	FILE *p = fopen(_ruta.c_str(), "wb");
	if (p = NULL) return;
	fclose(p);
}
