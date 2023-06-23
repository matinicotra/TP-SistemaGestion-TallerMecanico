#include <cstring>
#include "AutoClienteArchivo.h"

AutoClienteArchivo::AutoClienteArchivo() {
	_ruta = "autosclientes.dat";
}

AutoClienteArchivo::AutoClienteArchivo(std::string ruta) {
	_ruta = ruta;
}

int AutoClienteArchivo::GetCantidadRegistros() {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return -1;
	fseek(p, sizeof(AutoCliente), SEEK_END);
	int bytes = ftell(p);
	fclose(p);
	return bytes / sizeof(AutoCliente);
}

int AutoClienteArchivo::BuscarDni(std::string dni) {
	AutoCliente aux;
	int cantRegistros = this->GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		aux = this->Leer(i);
		if (aux.getDniCliente() == dni) return i;
	}
	return -1;
}

int AutoClienteArchivo::BuscarPatente(std::string patente) {
	AutoCliente aux;
	int cantRegistros = this->GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		aux = this->Leer(i);
		if (aux.getPatente() == patente) return i;
	}
	return -1;
}

AutoCliente AutoClienteArchivo::Leer(int pos) {
	AutoCliente aux;
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return aux;
	fseek(p, sizeof(AutoCliente) * pos, SEEK_SET);
	fread(&aux, sizeof(AutoCliente), 1, p);
	fclose(p);
	return aux;
}

void AutoClienteArchivo::Leer(AutoCliente *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return;
	fread(vec, sizeof(AutoCliente), cantRegistros, p);
	fclose(p);
}

bool AutoClienteArchivo::Guardar(AutoCliente reg) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	bool escribio = fwrite(&reg, sizeof(AutoCliente), 1, p);
	fclose(p);
	return escribio;
}

bool AutoClienteArchivo::Guardar(AutoCliente reg, int posReemplazo) {
	FILE *p = fopen(_ruta.c_str(), "rb+");
	if (p == NULL) return false;
	fseek(p, sizeof(AutoCliente) * posReemplazo, SEEK_SET);
	bool escribio = fwrite(&reg, sizeof(AutoCliente), 1, p);
	fclose(p);
	return escribio;
}

bool AutoClienteArchivo::Guardar(AutoCliente *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	int cantEscritos = fwrite(vec, sizeof(AutoCliente), cantRegistros, p);
	fclose(p);
	return cantEscritos == cantRegistros;
}

void AutoClienteArchivo::Vaciar() {
	FILE *p = fopen(_ruta.c_str(), "wb");
	if (p == NULL) return;
	fclose(p);
}
