#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include "string"
#include "iostream"

#include "Persona.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Proveedor.h"
#include "Vehiculo.h"
#include "Presupuesto.h"
#include "Trabajo.h"
#include "Fecha.h"
#include "AutoCliente.h"

#include "ClienteArchivo.h"
#include "EmpleadoArchivo.h"
#include "ProveedorArchivo.h"
#include "VehiculoArchivo.h"
#include "PresupuestoArchivo.h"
#include "TrabajoArchivo.h"
#include "AutoClienteArchivo.h"

#include "ClienteManager.h"
#include "EmpleadoManager.h"
#include "ProveedorManager.h"
#include "VehiculoManager.h"
#include "PresupuestoManager.h"
#include "TrabajoManager.h"
#include "AutoClienteManager.h"


int getInteger(int minimo, int maximo);

    ///funciones para hardcodear
void clienteHardcodear();
void empleadoHardcodear();
void proveedorHardcodear();
void vehiculoHardcodear();
void presupuestoHardcodear();
void trabajoHardcodear();
void autoClienteHardcodear();
void hardcodearTodo();

    ///funciones para el menu
void recaudacionAnual();
void recaudacionCliente ();


#endif // FUNCIONES_H_INCLUDED
