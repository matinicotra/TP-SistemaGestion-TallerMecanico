#include <iostream>
using namespace std;

#include "TrabajoManager.h"

int TrabajoManager::GenerarId() {
	return _archivo.GetCantidadRegistros() + 1;
}

bool TrabajoManager::ExisteId(int id) {
	return _archivo.Buscar(id) >= 0;
}

//void TrabajoManager::Cargar() {
//	Trabajo aux;
//	int id = GenerarId();
//	int dia, mes, anio;
//
//	cout << "CARGAR TRABAJO" << endl;
//	cout << "FECHA DE ENTRADA: " << endl;
//	cout << "DIA:  ";
//	cin >> dia;
//	cout << "MES:   ";
//	cin >> mes;
//	cout << "ANIO:  ";
//	cin >> anio;
//	cout <<
//
//
//}
