#include <cstring>
#include "ClienteArchivo.h"

ClienteArchivo::ClienteArchivo() {
	_ruta = "clientes.dat";
}

ClienteArchivo::ClienteArchivo(std::string ruta) {
	_ruta = ruta;
}

int ClienteArchivo::GetCantidadRegistros() {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return -1;
	fseek(p, sizeof(Cliente), SEEK_END);
	int bytes = ftell(p);
	fclose(p);
	return bytes / sizeof(Cliente);
}

int ClienteArchivo::Buscar(std::string dni) {
	Cliente aux;
	int cantRegistros = this->GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		aux = this->Leer(i);
		if (aux.getDni() == dni) return i;
	}
	return -1;
}

Cliente ClienteArchivo::Leer(int pos) {
	Cliente aux;
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return aux;
	fseek(p, sizeof(Cliente) * pos, SEEK_SET);
	fread(&aux, sizeof(Cliente), 1, p);
	fclose(p);
	return aux;
}

void ClienteArchivo::Leer(Cliente *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return;
	fread(vec, sizeof(Cliente), cantRegistros, p);
	fclose(p);
}

bool ClienteArchivo::Guardar(Cliente reg) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	bool escribio = fwrite(&reg, sizeof(Cliente), 1, p);
	fclose(p);
	return escribio;
}

bool ClienteArchivo::Guardar(Cliente reg, int posReemplazo) {
	FILE *p = fopen(_ruta.c_str(), "rb+");
	if (p == NULL) return false;
	fseek(p, sizeof(Cliente) * posReemplazo, SEEK_SET);
	bool escribio = fwrite(&reg, sizeof(Cliente), 1, p);
	fclose(p);
	return escribio;
}

bool ClienteArchivo::Guardar(Cliente *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	int cantEscritos = fwrite(vec, sizeof(Cliente), cantRegistros, p);
	fclose(p);
	return cantEscritos == cantRegistros;
}

void ClienteArchivo::Vaciar() {
	FILE *p = fopen(_ruta.c_str(), "wb");
	if (p == NULL) return;
	fclose(p);
}
