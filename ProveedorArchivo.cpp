#include <cstring>
#include "ProveedorArchivo.h"

ProveedorArchivo::ProveedorArchivo() {
	_ruta = "proveedores.dat";
}

ProveedorArchivo::ProveedorArchivo(std::string ruta) {
	_ruta = ruta;
}

int ProveedorArchivo::GetCantidadRegistros() {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return -1;
	fseek(p, sizeof(Proveedor), SEEK_END);
	int bytes = ftell(p);
	fclose(p);
	return bytes / sizeof(Proveedor);
}

int ProveedorArchivo::Buscar(const char *dni) {
	Proveedor aux;
	int cantRegistros = this->GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		aux = this->Leer(i);
		if (!strcmp(aux.getDni(), dni)) return i;
	}
	return -1;
}

Proveedor ProveedorArchivo::Leer(int pos) {
	Proveedor aux;
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return aux;
	fseek(p, sizeof(Proveedor) * pos, SEEK_SET);
	fread(&aux, sizeof(Proveedor), 1, p);
	fclose(p);
	return aux;
}

void ProveedorArchivo::Leer(Proveedor *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return;
	fread(vec, sizeof(Proveedor), cantRegistros, p);
	fclose(p);
}

bool ProveedorArchivo::Guardar(Proveedor reg) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	bool escribio = fwrite(&reg, sizeof(Proveedor), 1, p);
	fclose(p);
	return escribio;
}

bool ProveedorArchivo::Guardar(Proveedor reg, int posReemplazo) {
	FILE *p = fopen(_ruta.c_str(), "rb+");
	if (p == NULL) return false;
	fseek(p, sizeof(Proveedor) * posReemplazo, SEEK_SET);
	bool escribio = fwrite(&reg, sizeof(Proveedor), 1, p);
	fclose(p);
	return escribio;
}

bool ProveedorArchivo::Guardar(Proveedor *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	int cantEscritos = fwrite(vec, sizeof(Proveedor), cantRegistros, p);
	fclose(p);
	return cantEscritos == cantRegistros;
}

void ProveedorArchivo::Vaciar() {
	FILE *p = fopen(_ruta.c_str(), "wb");
	if (p = NULL) return;
	fclose(p);
}
