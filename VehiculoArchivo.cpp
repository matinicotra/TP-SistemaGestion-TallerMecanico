#include <cstring>
#include "VehiculoArchivo.h"

VehiculoArchivo::VehiculoArchivo() {
	_ruta = "vehiculos.dat";
}

VehiculoArchivo::VehiculoArchivo(std::string ruta) {
	_ruta = ruta;
}

int VehiculoArchivo::GetCantidadRegistros() {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return -1;
	fseek(p, sizeof(Vehiculo), SEEK_END);
	int bytes = ftell(p);
	fclose(p);
	return bytes / sizeof(Vehiculo);
}

int VehiculoArchivo::Buscar(const char *patente) {
	Vehiculo aux;
	int cantRegistros = this->GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		aux = this->Leer(i);
		if (!strcmp(aux.getPatente(), patente)) return i;
	}
	return -1;
}

Vehiculo VehiculoArchivo::Leer(int pos) {
	Vehiculo aux;
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return aux;
	fseek(p, sizeof(Vehiculo) * pos, SEEK_SET);
	fread(&aux, sizeof(Vehiculo), 1, p);
	fclose(p);
	return aux;
}

void VehiculoArchivo::Leer(Vehiculo *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return;
	fread(vec, sizeof(Vehiculo), cantRegistros, p);
	fclose(p);
}

bool VehiculoArchivo::Guardar(Vehiculo reg) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	bool escribio = fwrite(&reg, sizeof(Vehiculo), 1, p);
	fclose(p);
	return escribio;
}

bool VehiculoArchivo::Guardar(Vehiculo reg, int posReemplazo) {
	FILE *p = fopen(_ruta.c_str(), "rb+");
	if (p == NULL) return false;
	fseek(p, sizeof(Vehiculo) * posReemplazo, SEEK_SET);
	bool escribio = fwrite(&reg, sizeof(Vehiculo), 1, p);
	fclose(p);
	return escribio;
}

bool VehiculoArchivo::Guardar(Vehiculo *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	int cantEscritos = fwrite(vec, sizeof(Vehiculo), cantRegistros, p);
	fclose(p);
	return cantEscritos == cantRegistros;
}

void VehiculoArchivo::Vaciar() {
	FILE *p = fopen(_ruta.c_str(), "wb");
	if (p == NULL) return;
	fclose(p);
}
