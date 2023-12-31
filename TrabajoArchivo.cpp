#include "TrabajoArchivo.h"

TrabajoArchivo::TrabajoArchivo() {
	_ruta = "trabajos.dat";
}

TrabajoArchivo::TrabajoArchivo(std::string ruta) {
	_ruta = ruta;
}

int TrabajoArchivo::GetCantidadRegistros() {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return -1;
	fseek(p, 0, SEEK_END);
	int bytes = ftell(p);
	fclose(p);
	return bytes / sizeof(Trabajo);
}

int TrabajoArchivo::Buscar(int id) {
	Trabajo aux;
	int cantRegistros = this->GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		aux = this->Leer(i);
		if (aux.getIdTrabajo() == id) return i;
	}
	return -1;
}

Trabajo TrabajoArchivo::Leer(int pos) {
	Trabajo aux;
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return aux;
	fseek(p, sizeof(Trabajo) * pos, SEEK_SET);
	fread(&aux, sizeof(Trabajo), 1, p);
	fclose(p);
	return aux;
}

void TrabajoArchivo::Leer(Trabajo *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return;
	fread(vec, sizeof(Trabajo), cantRegistros, p);
	fclose(p);
}

bool TrabajoArchivo::Guardar(Trabajo reg) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	bool escribio = fwrite(&reg, sizeof(Trabajo), 1, p);
	fclose(p);
	return escribio;
}

bool TrabajoArchivo::Guardar(Trabajo reg, int posReemplazo) {
	FILE *p = fopen(_ruta.c_str(), "rb+");
	if (p == NULL) return false;
	fseek(p, sizeof(Trabajo) * posReemplazo, SEEK_SET);
	bool escribio = fwrite(&reg, sizeof(Trabajo), 1, p);
	fclose(p);
	return escribio;
}

bool TrabajoArchivo::Guardar(Trabajo *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	int cantEscritos = fwrite(vec, sizeof(Trabajo), cantRegistros, p);
	fclose(p);
	return cantEscritos == cantRegistros;
}

void TrabajoArchivo::Vaciar() {
	FILE *p = fopen(_ruta.c_str(), "wb");
	if (p == NULL) return;
	fclose(p);
}
