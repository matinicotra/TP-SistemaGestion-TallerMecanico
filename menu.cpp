#include "menu.h"

///FALTA LLAMADAS A LAS FUNCIONES QUE HACEN CADA COSA, SOLO ESTÁ EL GENERAL DE LLAMAR A LOS MENUS

/// ---------------------------menu principal--------------------------------------------------
void Menu::displayMain() {
    while (true) {
        int opcion;

        system("cls");
        std::cout<<"================================"<<std::endl;
        std::cout<<"============= MENU ============="<<std::endl;
        std::cout<<"================================"<<std::endl<<std::endl;
        std::cout<<"-1 CARGAS"<<std::endl;
        std::cout<<"-2 CONSULTAS"<<std::endl;
        std::cout<<"-3 LISTADOS"<<std::endl;
        std::cout<<"-4 INFORMES"<<std::endl;
        std::cout<<"-5 MANEJO DE ARCHIVOS."<<std::endl;
        std::cout<<"-0 SALIR"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:
            menuCargas();
            break;
        case 2:
            menuConsultas();
            break;
        case 3:
            menuListados();
            break;
        case 4:
            menuInformes();
            break;
        case 5:
            menuArchivos();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

///----------------------menus secundarios-----------------------------------------

void Menu::menuCargas() {
    while (true) {
        int opcion;

        system("cls");
        std::cout<<"============ CARGAS ============"<<std::endl;
        std::cout<<"-1 CLIENTE"<<std::endl;
        std::cout<<"-2 VEHICULO"<<std::endl;
        std::cout<<"-3 PRESUPUESTO"<<std::endl;
        std::cout<<"-4 TRABAJO"<<std::endl;
        std::cout<<"-5 EMPLEADO"<<std::endl;
        std::cout<<"-6 PROVEEDOR"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:
            _clienteManager.Cargar();
            break;
        case 2:
            _vehiculoManager.Cargar();
            break;
        case 3:
            _presupuestoManager.Cargar();
            break;
        case 4:
            _trabajoManager.Cargar();
            break;
        case 5:
            _empleadoManager.Cargar();
            break;
        case 6:
            _proveedorManager.Cargar();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

void Menu::menuConsultas() {
    while (true) {
        int opcion;

        system("cls");
        std::cout<<"=========== CONSULTAS =========="<<std::endl;
        std::cout<<"-1 CLIENTE"<<std::endl;
        std::cout<<"-2 TRABAJO"<<std::endl;
        std::cout<<"-3 PROVEEDOR"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:
            menuConsultasClientes();
            break;
        case 2:
            menuConsultasTrabajos();
            break;
        case 3:
            menuConsultasProveedores();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

void Menu::menuListados() {
    while (true) {
        int opcion;

        system("cls");
        std::cout<<"=========== LISTADOS =============="<<std::endl;
        std::cout<<"-1 CLIENTES"<<std::endl;
        std::cout<<"-2 VEHICULOS"<<std::endl;
        std::cout<<"-3 TRABAJOS"<<std::endl;
        std::cout<<"-4 PROVEEDORES"<<std::endl;
        std::cout<<"-5 EMPLEADOS"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;

        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion)
        {
        case 1:
            menuListadoClientes();
            break;
        case 2:
            menuListadoVehiculos();
            break;
        case 3:
            menuListadoTrabajos();
            break;
        case 4:
            menuListadoProveedores();
            break;
        case 5:
            menuListadoEmpleados();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;

        }
    }
}

void Menu::menuInformes() {
    while (true) {
        int opcion;

        system("cls");
        std::cout<<"=========== INFORMES ==============="<<std::endl;
        std::cout<<"-1 RECAUDACION ANUAL"<<std::endl;
        std::cout<<"-2 RECAUDACION POR CLIENTE"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"===================================="<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:

            break;
        case 2:

            break;

        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

void Menu::menuArchivos() {
    while (true) {
        int opcion;

        system("cls");
        std::cout<<"=========== ARCHIVOS =============="<<std::endl;
        std::cout<<"-1 REALIZAR COPIA DE SEGURIDAD"<<std::endl;
        std::cout<<"-2 RESTAURAR COPIA DE SEGURIDAD"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:
            menuArchivoCopiar();
            break;
        case 2:
            menuArchivoRestaurar();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}
///------------------ hasta aca menus secundarios -----------------------------------------


///--------------menus terciarios------------------------------

//menus terciarios consultas

void Menu::menuConsultasClientes() {
    while (true) {
        int opcion;
        system("cls");
        std::cout<<"====== CONSULTAS CLIENTES ======"<<std::endl;
        std::cout<<"-1 POR APELLIDO"<<std::endl;
        std::cout<<"-2 POR DNI"<<std::endl;
        std::cout<<"-3 POR TRABAJO"<<std::endl<<std::endl;
        std::cout<<"-4 MODIFICAR UN NUMERO DE TELEFONO"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:
            _clienteManager.ListarPorApellido();
            break;
        case 2:
            _clienteManager.ListarPorDni();
            break;
        case 3:
//            _clienteManager.ListarTrabajosCliente();
            break;
        case 4:
            _clienteManager.EditarTelefono();
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

void Menu::menuConsultasTrabajos() {
    while (true) {
        int opcion;
        system("cls");
        std::cout<<"====== CONSULTAS TRABAJOS ======"<<std::endl;
        std::cout<<"-1 POR AVANCE"<<std::endl;
        std::cout<<"-2 POR RANGO DE FECHAS"<<std::endl;
        std::cout<<"-3 POR VEHICULO"<<std::endl;
        std::cout<<"-4 POR CLIENTE"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:
            _trabajoManager.ListarPorAvance();
            break;
        case 2:

            break;
        case 3:
            _trabajoManager.ListarPorPatente();
            break;
        case 4:
            _trabajoManager.ListarPorDniCliente();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

void Menu::menuConsultasProveedores() {
    while (true) {
        int opcion;
        system("cls");
        std::cout<<"====== CONSULTAS PROVEEDORES ===="<<std::endl;
        std::cout<<"-1 POR DNI."<<std::endl;
        std::cout<<"-2 POR RUBRO."<<std::endl;
        std::cout<<"-3 EDITAR TELEFONO DE PROVEEDOR."<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:
            _proveedorManager.ListarPorDni();
            break;
        case 2:
            _proveedorManager.ListarPorRubro();
            break;
        case 3:
            _proveedorManager.EditarTelefono();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}
//------------------hasta aca menus terciarios consultas-------------------------------------------

//menus terciarios listados
void Menu::menuListadoClientes() {
    while (true) {
        int opcion;
        system("cls");
        std::cout<<"=========== LISTADOS CLIENTES ====="<<std::endl;
        std::cout<<"-1 ORDENADO POR APLELLIDO"<<std::endl;
        std::cout<<"-2 ORDENADO POR FECHA DE ALTA"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion)
        {
        case 1:
            _clienteManager.ListarOrdenadosPorApellido();
            break;
        case 2:
            _clienteManager.ListarOrdenadosPorFechaAlta();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

void Menu::menuListadoVehiculos() {
    while (true) {
        int opcion;
        system("cls");
        std::cout<<"=========== LISTADOS VEHICULOS ====="<<std::endl;
        std::cout<<"-1 ORDENADO POR PATENTE."<<std::endl;
        std::cout<<"-2 ORDENADO POR FECHA DE ALTA."<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:
            _vehiculoManager.ListarOrdenadosPorPatente();
            break;
        case 2:
            _vehiculoManager.ListarOrdenadosPorFechaAlta();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

void Menu::menuListadoTrabajos()
{
    while (true)
    {
        system("cls");
        int opcion;
        std::cout<<"=========== LISTADOS TRABAJOS ====="<<std::endl;
        std::cout<<"-1 ORDENADO POR TIPO"<<std::endl;
        std::cout<<"-2 ORDENADO POR RANGO DE FECHAS"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;

        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;

        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

void Menu::menuListadoProveedores() {
    while (true) {
        int opcion;
        system("cls");
        std::cout<<"=========== LISTADOS PROVEEDORES ==="<<std::endl;
        std::cout<<"-1 ORDENADO POR TIPO DE REPUESTO"<<std::endl;
        std::cout<<"-2 ORDENADO POR COSTOS"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;

        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;

        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

void Menu::menuListadoEmpleados()
{
    while (true)
    {
        system("cls");
        int opcion;
        std::cout<<"=========== LISTADOS EMPLEADOS ====="<<std::endl;
        std::cout<<"-1 LISTAR TODOS."<<std::endl;
        std::cout<<"-2 MODIFICAR SUELDO DE EMPLEADO."<<std::endl;
        std::cout<<"-3 ORDENADO POR ANTIGUEDAD"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;

        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion)
        {
        case 1:
            _empleadoManager.ListarTodos();
            break;
        case 2:
            _empleadoManager.EditarSueldo();
            break;
        case 3:

            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}
//---------------hasta aca menus terciarios listados-------------------------------------------

//menus archivos
void Menu::menuArchivoCopiar() {
    while (true) {
        int opcion;

        system("cls");
        std::cout<<"=========== ARCHIVOS -> HACER COPIA DE SEGURIDAD ========="<<std::endl;
        std::cout<<"-1 CLIENTES"<<std::endl;
        std::cout<<"-2 VEHICULOS"<<std::endl;
        std::cout<<"-3 TRABAJOS"<<std::endl;
        std::cout<<"-4 PROVEEDORES"<<std::endl;
        std::cout<<"-5 EMPLEADOS"<<std::endl;
        std::cout<<"-6 AUTO-CLIENTE"<<std::endl;
        std::cout<<"-7 TODOS LOS ARCHIVOS"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:
            _clienteManager.HacerCopiaDeSeguridad();
            break;
        case 2:
            _vehiculoManager.HacerCopiaDeSeguridad();
            break;
        case 3:
            _trabajoManager.HacerCopiaDeSeguridad();
            break;
        case 4:
            _proveedorManager.HacerCopiaDeSeguridad();
            break;
        case 5:
            _empleadoManager.HacerCopiaDeSeguridad();
            break;
        case 6:
            _autoClienteManager.HacerCopiaDeSeguridad();
            break;
        case 7:
            _clienteManager.HacerCopiaDeSeguridad();
            _vehiculoManager.HacerCopiaDeSeguridad();
            _trabajoManager.HacerCopiaDeSeguridad();
            _proveedorManager.HacerCopiaDeSeguridad();
            _empleadoManager.HacerCopiaDeSeguridad();
            _autoClienteManager.HacerCopiaDeSeguridad();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

void Menu::menuArchivoRestaurar() {
    while (true) {
        int opcion;

        system("cls");
        std::cout<<"=========== ARCHIVOS -> RESTAURAR COPIA DE SEGURIDAD ========="<<std::endl;
        std::cout<<"-1 CLIENTES"<<std::endl;
        std::cout<<"-2 VEHICULOS"<<std::endl;
        std::cout<<"-3 TRABAJOS"<<std::endl;
        std::cout<<"-4 PROVEEDORES"<<std::endl;
        std::cout<<"-5 EMPLEADOS"<<std::endl;
        std::cout<<"-6 AUTO-CLIENTE"<<std::endl;
        std::cout<<"-7 TODOS LOS ARCHIVOS"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS."<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::cin>>opcion;

        switch(opcion) {
        case 1:
            _clienteManager.RestaurarCopiaDeSeguridad();
            break;
        case 2:
            _vehiculoManager.RestaurarCopiaDeSeguridad();
            break;
        case 3:
            _trabajoManager.RestaurarCopiaDeSeguridad();
            break;
        case 4:
            _proveedorManager.RestaurarCopiaDeSeguridad();
            break;
        case 5:
            _empleadoManager.RestaurarCopiaDeSeguridad();
            break;
        case 6:
            _autoClienteManager.RestaurarCopiaDeSeguridad();
            break;
        case 7:
            _clienteManager.RestaurarCopiaDeSeguridad();
            _vehiculoManager.RestaurarCopiaDeSeguridad();
            _trabajoManager.RestaurarCopiaDeSeguridad();
            _proveedorManager.RestaurarCopiaDeSeguridad();
            _empleadoManager.RestaurarCopiaDeSeguridad();
            _autoClienteManager.RestaurarCopiaDeSeguridad();
            break;
        case 0:
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}

//---------------hasta aca menus terciarios archivos-------------------------------------------
