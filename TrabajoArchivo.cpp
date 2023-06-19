
#include "TrabajoArchivo.h"

TrabajoArchivo::TrabajoArchivo() {
	_ruta = "trabajos.dat";
}

TrabajoArchivo::TrabajoArchivo(std::string ruta) {
	_ruta = ruta;
}

int TrabajoArchivo::getCantidadRegistros() {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return -1;
	fseek(p, sizeof(Trabajo), SEEK_END);
	int bytes = ftell(p);
	fclose(p);
	return bytes / sizeof(Trabajo);
}

Trabajo TrabajoArchivo::leerRegistro(int pos) {
	Trabajo aux;
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return aux;
	fseek(p, sizeof(Trabajo) * pos, SEEK_SET);
	fread(&aux, sizeof(Trabajo), 1, p);
	fclose(p);
	return aux;
}

bool TrabajoArchivo::guardar(Trabajo reg) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	bool escribio = fwrite(&reg, sizeof(Trabajo), 1, p);
	fclose(p);
	return escribio;
}
