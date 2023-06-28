#ifndef MENU_H
#define MENU_H
#include <iostream>

#include "TrabajoManager.h"
#include "ClienteManager.h"
#include "EmpleadoManager.h"
#include "PresupuestoManager.h"
#include "VehiculoManager.h"
#include "ProveedorManager.h"
#include "AutoClienteManager.h"

class Menu {
private:
    TrabajoManager _trabajoManager;
    ClienteManager _clienteManager;
    EmpleadoManager _empleadoManager;
    PresupuestoManager _presupuestoManager;
    ProveedorManager _proveedorManager;
    VehiculoManager _vehiculoManager;
    AutoClienteManager _autoClienteManager;

public:
    void displayMain();

    void menuCargas();
    void menuConsultas();
    void menuListados();
    void menuInformes();
    void menuArchivos();

    void menuConsultasClientes();
    void menuConsultasTrabajos();
    void menuConsultasProveedores();
    void menuConsultasPresupuestos();
    void menuConsultasVehiculos();
    void menuConsultasEmpleados();

    void menuListadoClientes();
    void menuListadoVehiculos();
    void menuListadoTrabajos();
    void menuListadoProveedores()

    void menuArchivoCopiar();
    void menuArchivoRestaurar();

};

#endif // MENU_H
