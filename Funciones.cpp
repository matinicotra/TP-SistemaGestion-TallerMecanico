#include "Funciones.h"
#include <climits>
#include <iostream>

using namespace std;

int getInteger(int minimo = INT_MIN, int maximo = INT_MAX) {
	int input;
	while(true) {
		cin >> input;
		if (cin.fail() || input < minimo || input > maximo) {
			cin.clear();
			cin.ignore();
		}
		else {
			cin.ignore();
			return input;
		}
	}
}

void clienteHardcodear(){

}
void empleadoHardcodear(){

}
void proveedorHardcodear(){

}
void vehiculoHardcodear(){

}
void presupuestoHardcodear(){

}
void trabajoHardcodear(){

}
void autoClienteHardcodear(){

}
