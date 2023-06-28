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
    Menu();
    /// menu principal
    void displayMain();

    /// menus secundarios
    void menuCargas();
    void menuConsultas();
    void menuListados();
    void menuInformes();
    void menuArchivos();

    ///menus terciarios

    //menus consultas
    void menuConsultasClientes();
    void menuConsultasTrabajos();
    void menuConsultasProveedores();

    //menus listados
    void menuListadoClientes();
    void menuListadoVehiculos();
    void menuListadoTrabajos();
    void menuListadoProveedores();
    void menuListadoEmpleados();

    //menus archivos
    void menuArchivoCopiar();
    void menuArchivoRestaurar();

};

#endif // MENU_H
