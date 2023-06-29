#include <iostream>
#include "Programa.h"
using namespace std;

void Programa::Ejecutar() {
	int opc;
	do {
        system("cls");
		cout << "===== TALLER MECANICO =====" << endl;
		cout << "1 - IR AL MENU PRINCIPAL" << endl;
		cout << "===========================" << endl;
		cout << "0 - SALIR DEL PROGRAMA" << endl;
		cin >> opc;

		switch (opc) {
		case 1:
			_menuTaller.displayMain();
			break;
		case 0:
			cout << "Gracias por utilizar nuestro programa!" << endl;
			cout << "by Brian Sablich & Matias Nicotra" << endl;
			break;
		default:
			cout << "Opcion incorrecta." << endl;
			break;
		}
	} while (opc != 0);
}
