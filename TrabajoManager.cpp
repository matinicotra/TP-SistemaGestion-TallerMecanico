#include <iostream>
using namespace std;

#include "TrabajoManager.h"

int TrabajoManager::GenerarId() {
	return _archivo.GetCantidadRegistros() + 1;
}

bool TrabajoManager::ExisteId(int id) {
	return _archivo.Buscar(id) >= 0;
}

void TrabajoManager::Cargar() {
	Trabajo aux;
	int id = GenerarId();
	cout << "CARGAR TRABAJO" << endl;

}
