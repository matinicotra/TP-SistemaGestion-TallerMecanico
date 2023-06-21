#include "PresupuestoArchivo.h"

PresupuestoArchivo::PresupuestoArchivo() {
	_ruta = "trabajos.dat";
}

PresupuestoArchivo::PresupuestoArchivo(std::string ruta) {
	_ruta = ruta;
}

int PresupuestoArchivo::GetCantidadRegistros() {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return -1;
	fseek(p, sizeof(Presupuesto), SEEK_END);
	int bytes = ftell(p);
	fclose(p);
	return bytes / sizeof(Presupuesto);
}

int PresupuestoArchivo::Buscar(int id) {
	Presupuesto aux;
	int cantRegistros = this->GetCantidadRegistros();
	for (int i = 0; i < cantRegistros; i++) {
		aux = this->Leer(i);
		if (aux.getIdPresupuesto() == id) return i;
	}
	return -1;
}

Presupuesto PresupuestoArchivo::Leer(int pos) {
	Presupuesto aux;
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return aux;
	fseek(p, sizeof(Presupuesto) * pos, SEEK_SET);
	fread(&aux, sizeof(Presupuesto), 1, p);
	fclose(p);
	return aux;
}

void PresupuestoArchivo::Leer(Presupuesto *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "rb");
	if (p == NULL) return;
	fread(vec, sizeof(Presupuesto), cantRegistros, p);
	fclose(p);
}

bool PresupuestoArchivo::Guardar(Presupuesto reg) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	bool escribio = fwrite(&reg, sizeof(Presupuesto), 1, p);
	fclose(p);
	return escribio;
}

bool PresupuestoArchivo::Guardar(Presupuesto reg, int posReemplazo) {
	FILE *p = fopen(_ruta.c_str(), "rb+");
	if (p == NULL) return false;
	fseek(p, sizeof(Presupuesto) * posReemplazo, SEEK_SET);
	bool escribio = fwrite(&reg, sizeof(Presupuesto), 1, p);
	fclose(p);
	return escribio;
}

bool PresupuestoArchivo::Guardar(Presupuesto *vec, int cantRegistros) {
	FILE *p = fopen(_ruta.c_str(), "ab");
	if (p == NULL) return false;
	int cantEscritos = fwrite(vec, sizeof(Presupuesto), cantRegistros, p);
	fclose(p);
	return cantEscritos == cantRegistros;
}

void PresupuestoArchivo::Vaciar() {
	FILE *p = fopen(_ruta.c_str(), "wb");
	if (p == NULL) return;
	fclose(p);
}
