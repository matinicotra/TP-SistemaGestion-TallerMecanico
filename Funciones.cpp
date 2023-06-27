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

Fecha fecha1(10, 1, 2022);
Fecha fecha2(20, 2, 2022);
Fecha fecha3(13, 3, 2022);
Fecha fecha4(14, 4, 2022);
Fecha fecha5(15, 5, 2022);
Fecha fecha6(16, 6, 2022);
Fecha fecha7(17, 7, 2022);
Fecha fecha8(18, 8, 2022);
Fecha fecha9(19, 9, 2022);
Fecha fecha10(21, 10, 2022);

Cliente cliente1("12345678", "Emily", "Johnson", "emilyjohnson@example.com", "456 Elm St", "555-1111", "Cliente 1", fecha1);
Cliente cliente2("87654321", "James", "Brown", "jamesbrown@example.com", "789 Oak St", "555-2222", "Cliente 2", fecha2);
Cliente cliente3("56781234", "Sophia", "Garcia", "sophiagarcia@example.com", "987 Pine St", "555-3333", "Cliente 3", fecha3);
Cliente cliente4("43218765", "Isabella", "Martinez", "isabellamartinez@example.com", "654 Cedar St", "555-4444", "Cliente 4", fecha4);
Cliente cliente5("98765432", "Benjamin", "Lopez", "benjaminlopez@example.com", "321 Maple St", "555-5555", "Cliente 5", fecha5);
Cliente cliente6("65432187", "Oliver", "Gonzalez", "olivergonzalez@example.com", "543 Birch St", "555-6666", "Cliente 6", fecha6);
Cliente cliente7("87651234", "Amelia", "Rodriguez", "ameliarodriguez@example.com", "876 Walnut St", "555-7777", "Cliente 7", fecha7);
Cliente cliente8("12348765", "Ethan", "Perez", "ethanperez@example.com", "210 Spruce St", "555-8888", "Cliente 8", fecha8);
Cliente cliente9("34561278", "Mia", "Sanchez", "miasanchez@example.com", "432 Oak St", "555-9999", "Cliente 9", fecha9);
Cliente cliente10("56783421", "Charlotte", "Rivera", "charlotterivera@example.com", "123 Main St", "555-0000", "Cliente 10", fecha10);



ClienteArchivo ca;
ca.Guardar(cliente1);
ca.Guardar(cliente2);
ca.Guardar(cliente3);
ca.Guardar(cliente4);
ca.Guardar(cliente5);
ca.Guardar(cliente6);
ca.Guardar(cliente7);
ca.Guardar(cliente8);
ca.Guardar(cliente9);
ca.Guardar(cliente10);
}

void empleadoHardcodear(){

Fecha fechaNacimiento1(10, 12, 1990);
Empleado empleado1("12345600", "John", "Doe", "johndoe@example.com", "123 Main St", "555-1234", fechaNacimiento1, "Mecanico general", 5000.0, "1234567890");

Fecha fechaNacimiento2(15, 3, 1985);
Empleado empleado2("87654311", "Jane", "Smith", "janesmith@example.com", "456 Elm St", "555-5678", fechaNacimiento2, "Mecanico general", 3000.0, "0987654321");

Fecha fechaNacimiento3(5, 8, 1992);
Empleado empleado3("56781222", "Michael", "Johnson", "michaeljohnson@example.com", "789 Oak St", "555-9012", fechaNacimiento3, "Mecanico general", 2500.0, "5678901234");

Fecha fechaNacimiento4(20, 1, 1988);
Empleado empleado4("43218733", "Emily", "Davis", "emilydavis@example.com", "987 Pine St", "555-3456", fechaNacimiento4, "Mecanico general", 4000.0, "4321098765");

Fecha fechaNacimiento5(8, 6, 1995);
Empleado empleado5("98765444", "Jessica", "Brown", "jessicabrown@example.com", "654 Cedar St", "555-7890", fechaNacimiento5, "Ayudante", 2000.0, "9876543210");

Fecha fechaNacimiento6(12, 9, 1991);
Empleado empleado6("65432155", "Daniel", "Wilson", "danielwilson@example.com", "321 Maple St", "555-2345", fechaNacimiento6, "Ayudante", 3000.0, "6543210987");

Fecha fechaNacimiento7(25, 11, 1987);
Empleado empleado7("87651266", "Sophia", "Taylor", "sophiataylor@example.com", "543 Birch St", "555-6789", fechaNacimiento7, "Ayudante", 2800.0, "8765432109");

Fecha fechaNacimiento8(3, 7, 1993);
Empleado empleado8("12348777", "Oliver", "Martinez", "olivermartinez@example.com", "876 Walnut St", "555-0123", fechaNacimiento8, "Ayudante", 5500.0, "1234509876");

Fecha fechaNacimiento9(18, 2, 1989);
Empleado empleado9("34561288", "Emma", "Anderson", "emmaanderson@example.com", "210 Spruce St", "555-4567", fechaNacimiento9, "Recepcionista", 4200.0, "3456789012");

Fecha fechaNacimiento10(30, 4, 1994);
Empleado empleado10("56783499", "William", "Thompson", "williamthompson@example.com", "432 Oak St", "555-8901", fechaNacimiento10, "Jefe", 2200.0, "5678901234");

EmpleadoArchivo ea;

ea.Guardar(empleado1);
ea.Guardar(empleado2);
ea.Guardar(empleado3);
ea.Guardar(empleado4);
ea.Guardar(empleado5);
ea.Guardar(empleado6);
ea.Guardar(empleado7);
ea.Guardar(empleado8);
ea.Guardar(empleado9);
ea.Guardar(empleado10);

}

void proveedorHardcodear(){
Proveedor proveedor1("12345670", "Proveedor1", "Apellido1", "proveedor1@example.com", "Main St", "555-1234", "Amortiguadores", "Amortiguador", "Argentina");
Proveedor proveedor2("87654321", "Proveedor2", "Apellido2", "proveedor2@example.com", "Elm St", "555-5678", "Amortiguadores", "Espiral", "China");
Proveedor proveedor3("56781234", "Proveedor3", "Apellido3", "proveedor3@example.com", "Oak St", "555-9012", "Motores", "Piston", "Brasil");
Proveedor proveedor4("43218765", "Proveedor4", "Apellido4", "proveedor4@example.com", "Pine St", "555-3456", "Motores", "Viela", "China");
Proveedor proveedor5("98765432", "Proveedor5", "Apellido5", "proveedor5@example.com", "Cedar St", "555-7890", "Motores", "Tapa de cilindro", "Brasil");
Proveedor proveedor6("65432187", "Proveedor6", "Apellido6", "proveedor6@example.com", "Maple St", "555-2345", "Frenos", "Caliper", "Argentina");
Proveedor proveedor7("87651230", "Proveedor7", "Apellido7", "proveedor7@example.com", "Birch St", "555-6789", "Frenos", "Pastillas", "Brasil");
Proveedor proveedor8("12348765", "Proveedor8", "Apellido8", "proveedor8@example.com", "Walnut St", "555-0123", "Ruedas", "Neumatico", "China");
Proveedor proveedor9("34561278", "Proveedor9", "Apellido9", "proveedor9@example.com", "Spruce St", "555-4567", "Ruedas", "Llanta", "Brasil");
Proveedor proveedor10("56783429", "Proveedor10", "Apellido10", "proveedor10@example.com", "Oak St", "555-8901", "Ruedas", "Camara", "Argentina");

ProveedorArchivo pa;

pa.Guardar(proveedor1);
pa.Guardar(proveedor2);
pa.Guardar(proveedor3);
pa.Guardar(proveedor4);
pa.Guardar(proveedor5);
pa.Guardar(proveedor6);
pa.Guardar(proveedor7);
pa.Guardar(proveedor8);
pa.Guardar(proveedor9);
pa.Guardar(proveedor10);
}

void vehiculoHardcodear(){
Fecha fecha1(1, 1, 2020);
Fecha fecha2(1, 1, 2018);
Fecha fecha3(1, 1, 2019);
Fecha fecha4(1, 1, 2022);
Fecha fecha5(1, 1, 2017);
Fecha fecha6(1, 1, 2021);
Fecha fecha7(1, 1, 2016);
Fecha fecha8(1, 1, 2015);
Fecha fecha9(1, 1, 2014);
Fecha fecha10(1, 1, 2023);

Vehiculo vehiculo1("ABC123", "Prisma", "Chevrolet", 2020, fecha1);
Vehiculo vehiculo2("DEF456", "Ka", "Ford", 2018, fecha2);
Vehiculo vehiculo3("GHI789", "307", "Peugeot", 2019, fecha3);
Vehiculo vehiculo4("JKL012", "Onix", "Chevrolet", 2022, fecha4);
Vehiculo vehiculo5("MNO345", "Fiesta", "Ford", 2017, fecha5);
Vehiculo vehiculo6("PQR678", "308", "Peugeot", 2021, fecha6);
Vehiculo vehiculo7("STU901", "Tracker", "Chevrolet", 2016, fecha7);
Vehiculo vehiculo8("VWX234", "Mustang", "Ford", 2015, fecha8);
Vehiculo vehiculo9("YZA567", "208", "Peugeot", 2014, fecha9);
Vehiculo vehiculo10("BCD890", "Spark", "Chevrolet", 2023, fecha10);

VehiculoArchivo va;

va.Guardar(vehiculo1);
va.Guardar(vehiculo2);
va.Guardar(vehiculo3);
va.Guardar(vehiculo4);
va.Guardar(vehiculo5);
va.Guardar(vehiculo6);
va.Guardar(vehiculo7);
va.Guardar(vehiculo8);
va.Guardar(vehiculo9);
va.Guardar(vehiculo10);

}

void presupuestoHardcodear(){
Fecha fecha1(1, 1, 2022);
Fecha fecha2(2, 2, 2022);
Fecha fecha3(3, 3, 2022);
Fecha fecha4(4, 4, 2022);
Fecha fecha5(5, 5, 2022);
Fecha fecha6(6, 6, 2022);
Fecha fecha7(7, 7, 2022);
Fecha fecha8(8, 8, 2022);
Fecha fecha9(9, 9, 2022);
Fecha fecha10(10, 10, 2022);

Presupuesto presupuesto1(1, "12345678", "ABC123", 1000.0, "Reparación de motor", fecha1, true, false);
Presupuesto presupuesto2(2, "12345678", "DEF456", 500.0, "Cambio de frenos", fecha2, false, true);
Presupuesto presupuesto3(3, "12345678", "GHI789", 800.0, "Reparación de carrocería", fecha3, true, true);
Presupuesto presupuesto4(4, "87654321", "JKL012", 1200.0, "Cambio de embrague", fecha4, false, false);
Presupuesto presupuesto5(5, "87654321", "MNO345", 1500.0, "Reparación de suspensión", fecha5, true, true);
Presupuesto presupuesto6(6, "56781234", "PQR678", 900.0, "Cambio de aceite y filtros", fecha6, false, false);
Presupuesto presupuesto7(7, "56781234", "STU901", 700.0, "Reparación de sistema eléctrico", fecha7, true, false);
Presupuesto presupuesto8(8, "56783421", "VWX234", 1800.0, "Cambio de neumáticos", fecha8, false, true);
Presupuesto presupuesto9(9, "56783421", "YZA567", 600.0, "Reparación de sistema de escape", fecha9, true, true);
Presupuesto presupuesto10(10, "56783421", "BCD890", 2000.0, "Cambio de kit de distribución", fecha10, false, false);

PresupuestoArchivo pa;

pa.Guardar(presupuesto1);
pa.Guardar(presupuesto2);
pa.Guardar(presupuesto3);
pa.Guardar(presupuesto4);
pa.Guardar(presupuesto5);
pa.Guardar(presupuesto6);
pa.Guardar(presupuesto7);
pa.Guardar(presupuesto8);
pa.Guardar(presupuesto9);
pa.Guardar(presupuesto10);

}

void trabajoHardcodear(){
Fecha fechaEntrada1(1, 1, 2022);
Fecha fechaEntrega1(10, 1, 2022);
Fecha fechaEntrada2(2, 2, 2022);
Fecha fechaEntrega2(12, 2, 2022);
Fecha fechaEntrada3(3, 3, 2022);
Fecha fechaEntrega3(15, 3, 2022);
Fecha fechaEntrada4(4, 4, 2022);
Fecha fechaEntrega4(20, 4, 2022);
Fecha fechaEntrada5(5, 5, 2022);
Fecha fechaEntrega5(25, 5, 2022);
Fecha fechaEntrada6(6, 6, 2022);
Fecha fechaEntrega6(30, 6, 2022);
Fecha fechaEntrada7(7, 7, 2022);
Fecha fechaEntrega7(5, 7, 2022);
Fecha fechaEntrada8(8, 8, 2022);
Fecha fechaEntrega8(10, 8, 2022);
Fecha fechaEntrada9(9, 9, 2022);
Fecha fechaEntrega9(15, 9, 2022);
Fecha fechaEntrada10(10, 10, 2022);
Fecha fechaEntrega10(20, 10, 2022);

Trabajo trabajo1(1, 1, "ABC123", "12345678", "12345670", "12345600", 3, fechaEntrada1, fechaEntrega1);
Trabajo trabajo2(2, 2, "DEF456", "12345678", "12345670", "12345600", 2, fechaEntrada2, fechaEntrega2);
Trabajo trabajo3(3, 3, "GHI789", "12345678", "12345670", "12345600", 4, fechaEntrada3, fechaEntrega3);
Trabajo trabajo4(4, 4, "JKL012", "87654321", "65432187", "87654311", 1, fechaEntrada4, fechaEntrega4);
Trabajo trabajo5(5, 5, "MNO345", "87654321", "65432187", "87654311", 5, fechaEntrada5, fechaEntrega5);
Trabajo trabajo6(6, 6, "PQR678", "56781234", "65432187", "98765444", 3, fechaEntrada6, fechaEntrega6);
Trabajo trabajo7(7, 7, "STU901", "56781234", "43218765", "43218733", 2, fechaEntrada7, fechaEntrega7);
Trabajo trabajo8(8, 8, "VWX234", "56783421", "43218765", "43218733", 4, fechaEntrada8, fechaEntrega8);
Trabajo trabajo9(9, 9, "YZA567", "56783421", "56783429", "43218733", 1, fechaEntrada9, fechaEntrega9);
Trabajo trabajo10(10, 10, "BCD890", "56783421", "56783429", "56781222", 5, fechaEntrada10, fechaEntrega10);

TrabajoArchivo ta;

ta.Guardar(trabajo1);
ta.Guardar(trabajo2);
ta.Guardar(trabajo3);
ta.Guardar(trabajo4);
ta.Guardar(trabajo5);
ta.Guardar(trabajo6);
ta.Guardar(trabajo7);
ta.Guardar(trabajo8);
ta.Guardar(trabajo9);
ta.Guardar(trabajo10);

}

void autoClienteHardcodear(){
AutoCliente autoCliente1("12345678", "ABC123");
AutoCliente autoCliente2("12345678", "DEF456");
AutoCliente autoCliente3("12345678", "GHI789");
AutoCliente autoCliente4("87654321", "JKL012");
AutoCliente autoCliente5("87654321", "MNO345");
AutoCliente autoCliente6("56781234", "PQR678");
AutoCliente autoCliente7("56781234", "STU901");
AutoCliente autoCliente8("56783421", "VWX234");
AutoCliente autoCliente9("56783421", "YZA567");
AutoCliente autoCliente10("56783421", "BCD890");

AutoClienteArchivo aca;

aca.Guardar(autoCliente1);
aca.Guardar(autoCliente2);
aca.Guardar(autoCliente3);
aca.Guardar(autoCliente4);
aca.Guardar(autoCliente5);
aca.Guardar(autoCliente6);
aca.Guardar(autoCliente7);
aca.Guardar(autoCliente8);
aca.Guardar(autoCliente9);
aca.Guardar(autoCliente10);
}

void hardcodearTodo(){
    clienteHardcodear();
    empleadoHardcodear();
    proveedorHardcodear();
    vehiculoHardcodear();
    presupuestoHardcodear();
    trabajoHardcodear();
    autoClienteHardcodear();
}
