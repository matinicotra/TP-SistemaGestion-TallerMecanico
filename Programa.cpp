 #include <iostream>
#include "Programa.h"
#include "string"
using namespace std;

void Programa::Ejecutar() {
    char opcion;
	do {
        system("cls");
		cout << "===== TALLER MECANICO =====" << endl << endl;
		cout << "1 - IR AL MENU PRINCIPAL" << endl << endl;
		cout << "===========================" << endl << endl;
		cout << "0 - SALIR DEL PROGRAMA" << endl << endl;
		string entrada;
        cout << "INGRESE UNA OPCION: ";
        cin>>entrada;

        if (entrada.length() != 1) {
            cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        opcion = entrada[0];
		switch (opcion) {
		case '1':
			_menuTaller.displayMain();
			break;
		case '0':
			cout << "Gracias por utilizar nuestro programa!" << endl;
			cout << "by Brian Sablich & Matias Nicotra" << endl;
			break;
			cout << "Opcion incorrecta." << endl;
			break;
		}
        }
	} while (opcion != '0');

}
