#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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

int getInteger(int minimo, int maximo);

    ///funciones para hardcodear
void clienteHardcodear();
void empleadoHardcodear();
void proveedorHardcodear();
void vehiculoHardcodear();
void presupuestoHardcodear();
void trabajoHardcodear();
void autoClienteHardcodear();

#endif // FUNCIONES_H_INCLUDED
