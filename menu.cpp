#include "menu.h"
#include "Funciones.h"

///MENU PRINCIPAL
void Menu::displayMain() {
    while (true) {
        system("cls");
        std::cout<<"================================"<<std::endl;
        std::cout<<"========= MENU PRINCIPAL ======="<<std::endl;
        std::cout<<"================================"<<std::endl<<std::endl;
        std::cout<<"-1 CARGAS"<<std::endl;
        std::cout<<"-2 CONSULTAS"<<std::endl;
        std::cout<<"-3 LISTADOS"<<std::endl;
        std::cout<<"-4 INFORMES"<<std::endl;
        std::cout<<"-5 MANEJO DE ARCHIVOS"<<std::endl<<std::endl;
        std::cout<<"-0 SALIR DEL MENU PRINCIPAL"<<std::endl<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"================================"<<std::endl<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
            menuCargas();
            break;
        case '2':
            menuConsultas();
            break;
        case '3':
            menuListados();
            break;
        case '4':
            menuInformes();
            break;
        case '5':
            menuArchivos();
            break;
        case '0':
            return;
            break;
        case '9':
            hardcodearTodo();
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}



//SUBMENUS

void Menu::menuCargas() {
    while (true) {
        system("cls");
        std::cout<<"============ CARGAS ============"<<std::endl;
        std::cout<<"-1 CLIENTE"<<std::endl;
        std::cout<<"-2 VEHICULO"<<std::endl;
        std::cout<<"-3 PRESUPUESTO"<<std::endl;
        std::cout<<"-4 TRABAJO"<<std::endl;
        std::cout<<"-5 EMPLEADO"<<std::endl;
        std::cout<<"-6 PROVEEDOR"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
            _clienteManager.Cargar();
            break;
        case '2':
            _vehiculoManager.Cargar();
            break;
        case '3':
            _presupuestoManager.Cargar();
            break;
        case '4':
            _trabajoManager.Cargar();
            break;
        case '5':
            _empleadoManager.Cargar();
            break;
        case '6':
            _proveedorManager.Cargar();
            break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuConsultas() {
    while (true) {
        system("cls");
        std::cout<<"=========== CONSULTAS =========="<<std::endl;
        std::cout<<"-1 CLIENTES"<<std::endl;
        std::cout<<"-2 TRABAJOS"<<std::endl;
        std::cout<<"-3 PRESUPUESTOS"<<std::endl;
        std::cout<<"-4 PROVEEDORES"<<std::endl;
        std::cout<<"-5 VEHICULOS"<<std::endl;
        std::cout<<"-6 EMPLEADOS"<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
            menuConsultasClientes();
            break;
		case '2':
            menuConsultasTrabajos();
			break;
        case '3':
            menuConsultasPresupuestos();
            break;
        case '4':
        	menuConsultasProveedores();
            break;
		case '5':
			menuConsultasVehiculos();
			break;
		case '6':
			menuConsultasEmpleados();
			break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuListados() {
    while (true) {
        system("cls");
        std::cout<<"=========== LISTADOS =============="<<std::endl;
        std::cout<<"-1 CLIENTES"<<std::endl;
        std::cout<<"-2 VEHICULOS"<<std::endl;
        std::cout<<"-3 TRABAJOS"<<std::endl;
        std::cout<<"-4 PROVEEDORES"<<std::endl;
        std::cout<<"-5 PRESUPUESTOS"<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;

        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion)
        {
        case '1':
            menuListadoClientes();
            break;
        case '2':
            menuListadoVehiculos();
            break;
        case '3':
            menuListadoTrabajos();
            break;
        case '4':
            menuListadoProveedores();
            break;
        case '5':
            menuListadoPresupuestos();
            break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;

        }
    }
}}

void Menu::menuInformes() {
    while (true) {
        system("cls");
        std::cout<<"=========== INFORMES ==============="<<std::endl;
        std::cout<<"-1 RECAUDACION ANUAL"<<std::endl;
        std::cout<<"-2 RECAUDACION POR CLIENTE"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"===================================="<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
            recaudacionAnual();
            break;
        case '2':
            recaudacionCliente();
            break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuArchivos() {
    while (true) {
        system("cls");
        std::cout<<"=========== ARCHIVOS =============="<<std::endl;
        std::cout<<"-1 REALIZAR COPIA DE SEGURIDAD"<<std::endl;
        std::cout<<"-2 RESTAURAR COPIA DE SEGURIDAD"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
            menuArchivoCopiar();
            break;
        case '2':
            menuArchivoRestaurar();
            break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}



//CONSULTAS Y EDICIONES

void Menu::menuConsultasClientes() {
    while (true) {
        system("cls");
        std::cout<<"====== CONSULTAS CLIENTES ======"<<std::endl;
        std::cout<<"-1 BUSCAR POR DNI"<<std::endl;
        std::cout<<"-2 BUSCAR POR APELLIDO"<<std::endl;
        std::cout<<"-3 MODIFICAR UN NUMERO DE TELEFONO"<<std::endl;
        std::cout<<"-4 ELIMINAR CLIENTE"<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];
        switch(opcion) {
        case '1':
            _clienteManager.ListarPorDni();
            break;
        case '2':
            _clienteManager.ListarPorApellido();
            break;
        case '3':
            _clienteManager.EditarTelefono();
            break;
        case '4':
        	_clienteManager.Eliminar();
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuConsultasTrabajos() {
    while (true) {
        system("cls");
        std::cout<<"====== CONSULTAS TRABAJOS ======"<<std::endl;
        std::cout<<"-1 BUSCAR POR ID"<<std::endl;
        std::cout<<"-2 BUSCAR POR ESTADO"<<std::endl;
        std::cout<<"-3 BUSCAR POR VEHICULO"<<std::endl;
        std::cout<<"-4 BUSCAR TRABAJOS ACTIVOS POR CLIENTE"<<std::endl;
        std::cout<<"-5 ACTUALIZAR ESTADO DE TRABAJO"<<std::endl;
        std::cout<<"-6 MODIFICAR PROVEEDOR"<<std::endl;
        std::cout<<"-7 MODIFICAR EMPLEADO ASIGNADO" << std::endl;
        std::cout<<"-8 MODIFICAR PRESUPUESTO" << std::endl;
        std::cout<<"-9 MODIFICAR PRECIO FINAL" << std::endl;
        std::cout<<"-10 ELIMINAR TRABAJO"<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
        	_trabajoManager.ListarPorId();
            break;
        case '2':
            _trabajoManager.ListarPorAvance();
            break;
        case '3':
            _trabajoManager.ListarPorPatente();
            break;
        case '4':
            _trabajoManager.ListarPorDniCliente();
            break;
        case '5':
            _trabajoManager.ActualizarAvance();
                break;
        case '6':
            _trabajoManager.ActualizarProveedor();
                break;
        case '7':
            _trabajoManager.ActualizarEmpleado();
                break;
        case '8':
            _trabajoManager.ActualizarPresupuesto();
                break;
        case '9':
            _trabajoManager.ActualizarPrecio();
                break;
        case '10':
            _trabajoManager.Eliminar();
                break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuConsultasProveedores() {
    while (true) {
        system("cls");
        std::cout<<"====== CONSULTAS PROVEEDORES ===="<<std::endl;
        std::cout<<"-1 POR DNI"<<std::endl;
        std::cout<<"-2 POR RUBRO"<<std::endl;
        std::cout<<"-3 EDITAR TELEFONO DE PROVEEDOR"<<std::endl;
        std::cout<<"-4 ELIMINAR PROVEEDOR"<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
            _proveedorManager.ListarPorDni();
            break;
        case '2':
            _proveedorManager.ListarPorRubro();
            break;
        case '3':
            _proveedorManager.EditarTelefono();
            break;
		case '4':
			_proveedorManager.Eliminar();
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuConsultasPresupuestos() {
	while (true) {
        system("cls");
        std::cout<<"======= CONSULTAS PRESUPUESTOS ====="<<std::endl;
        std::cout<<"-1 BUSCAR POR ID"<<std::endl;
        std::cout<<"-2 MODIFICAR IMPORTE"<<std::endl;
        std::cout<<"-3 ELIMINAR PRESUPUESTO"<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"===================================="<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion)
        {
        case '1':
			_presupuestoManager.ListarPorId();
            break;
        case '2':
			_presupuestoManager.EditarImporte();
            break;
		case '3':
			_presupuestoManager.Eliminar();
			break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuConsultasVehiculos() {
	while (true) {
		system("cls");
		std::cout<<"======= CONSULTAS VEHICULOS ====="<<std::endl;
		std::cout<<"-1 BUSCAR POR PATENTE"<<std::endl;
		std::cout<<"-2 ELIMINAR VEHICULO"<<std::endl<<std::endl;
		std::cout<<"-0 ATRAS"<<std::endl;
		std::cout<<"===================================="<<std::endl;
		std::cout<<"INGRESE UNA OPCION: ";
		std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

		switch(opcion)
		{
		case '1':
			_vehiculoManager.ListarPorPatente();
			break;
		case '2':
			_vehiculoManager.Eliminar();
			break;
		case '0':
			return;
			break;
		default:
			std::cout<<"OPCION NO VALIDA"<<std::endl;
			break;
		}
    }
}}

void Menu::menuConsultasEmpleados() {
	while (true) {
		system("cls");
		std::cout<<"======= CONSULTAS EMPLEADOS ====="<<std::endl;
		std::cout<<"-1 BUSCAR POR DNI"<<std::endl;
		std::cout<<"-2 LISTAR TODOS"<<std::endl;
		std::cout<<"-3 LISTAR ORDENADOS POR SUELDO"<<std::endl;
		std::cout<<"-4 LISTAR ORDENADOS POR FECHA DE NACIMIENTO"<<std::endl;
		std::cout<<"-5 EDITAR SUELDO DE EMPLEADO"<<std::endl;
		std::cout<<"-6 ELIMINAR EMPLEADO"<<std::endl;
		std::cout<<"-0 ATRAS"<<std::endl;
		std::cout<<"===================================="<<std::endl;
		std::cout<<"INGRESE UNA OPCION: ";
		std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

		switch(opcion)
		{
		case '1':
			_empleadoManager.ListarPorDni();
			break;
		case '2':
			_empleadoManager.ListarTodos();
			break;
		case '3':
			_empleadoManager.ListarOrdenadoPorSueldo();
			break;
		case '4':
			_empleadoManager.ListarOrdenadoPorFechaNacimiento();
			break;
		case '5':
			_empleadoManager.EditarSueldo();
			break;
		case '6':
			_empleadoManager.Eliminar();
		case '0':
			return;
			break;
		default:
			std::cout<<"OPCION NO VALIDA"<<std::endl;
			break;
		}
    }
}}



//LISTADOS

void Menu::menuListadoClientes() {
    while (true) {
        system("cls");
        std::cout<<"=========== LISTADOS CLIENTES ====="<<std::endl;
        std::cout<<"-1 LISTAR ORDENADOS POR APLELLIDO"<<std::endl;
        std::cout<<"-2 LISTAR ORDENADOS POR FECHA DE ALTA"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
            _clienteManager.ListarOrdenadosPorApellido();
            break;
        case '2':
            _clienteManager.ListarOrdenadosPorFechaAlta();
            break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuListadoVehiculos() {
    while (true) {
        system("cls");
        std::cout<<"=========== LISTADOS VEHICULOS ====="<<std::endl;
        std::cout<<"-1 LISTAR ORDENADOS POR PATENTE"<<std::endl;
        std::cout<<"-2 LISTAR ORDENADOS POR FECHA DE ALTA"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
            _vehiculoManager.ListarOrdenadosPorPatente();
            break;
        case '2':
            _vehiculoManager.ListarOrdenadosPorFechaAlta();
            break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuListadoTrabajos() {
    while (true)
    {
        system("cls");
        std::cout<<"=========== LISTADOS TRABAJOS ====="<<std::endl;
        std::cout<<"-1 LISTAR TODOS POR FECHA DE ENTRADA"<<std::endl;
        std::cout<<"-2 LISTAR ENTREGADOS POR FECHA"<<std::endl;
        std::cout<<"-3 LISTAR TRABAJOS POR EMPLEADO"<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;

        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion)
        {
        case '1':
			_trabajoManager.ListarOrdenadosPorFecha();
            break;
        case '2':
        	_trabajoManager.ListarEntregadosPorFecha();
            break;
		case '3':
			_trabajoManager.ListarPorEmpleado();
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuListadoProveedores() {
    while (true) {
        system("cls");
        std::cout<<"======= LISTADOS PROVEEDORES ======="<<std::endl;
        std::cout<<"-1 LISTAR TODOS"<<std::endl;
        std::cout<<"-2 ORDENADO POR ORIGEN DE FABRICACION"<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"===================================="<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
			_proveedorManager.ListarTodos();
            break;
        case '2':
        	_proveedorManager.ListarPorOrigenFabricacion();
            break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuListadoPresupuestos(){
    while (true) {
        system("cls");
        std::cout<<"======= LISTADOS PRESUPUESTO ======="<<std::endl;
        std::cout<<"-1 LISTAR TODOS"<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"===================================="<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
			_presupuestoManager.ListarTodos();
            break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}


//MANEJO DE ARCHIVOS

void Menu::menuArchivoCopiar() {
    while (true) {
        system("cls");
        std::cout<<"=========== ARCHIVOS -> HACER COPIA DE SEGURIDAD ========="<<std::endl;
        std::cout<<"-1 CLIENTES"<<std::endl;
        std::cout<<"-2 VEHICULOS"<<std::endl;
        std::cout<<"-3 TRABAJOS"<<std::endl;
        std::cout<<"-4 PROVEEDORES"<<std::endl;
        std::cout<<"-5 EMPLEADOS"<<std::endl;
        std::cout<<"-6 AUTO-CLIENTE"<<std::endl;
        std::cout<<"-7 TODOS LOS ARCHIVOS"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
            _clienteManager.HacerCopiaDeSeguridad();
            break;
        case '2':
            _vehiculoManager.HacerCopiaDeSeguridad();
            break;
        case '3':
            _trabajoManager.HacerCopiaDeSeguridad();
            break;
        case '4':
            _proveedorManager.HacerCopiaDeSeguridad();
            break;
        case '5':
            _empleadoManager.HacerCopiaDeSeguridad();
            break;
        case '6':
            _autoClienteManager.HacerCopiaDeSeguridad();
            break;
        case '7':
            hacerCopiaDeSeguridadTodo();
            break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}

void Menu::menuArchivoRestaurar() {
    while (true) {
        system("cls");
        std::cout<<"=========== ARCHIVOS -> RESTAURAR COPIA DE SEGURIDAD ========="<<std::endl;
        std::cout<<"-1 CLIENTES"<<std::endl;
        std::cout<<"-2 VEHICULOS"<<std::endl;
        std::cout<<"-3 TRABAJOS"<<std::endl;
        std::cout<<"-4 PROVEEDORES"<<std::endl;
        std::cout<<"-5 EMPLEADOS"<<std::endl;
        std::cout<<"-6 AUTO-CLIENTE"<<std::endl;
        std::cout<<"-7 TODOS LOS ARCHIVOS"<<std::endl<<std::endl;
        std::cout<<"-0 ATRAS"<<std::endl;
        std::cout<<"================================"<<std::endl;
        std::cout<<"INGRESE UNA OPCION: ";
        std::string entrada;

        std::cin>>entrada;

        if (entrada.length() != 1) {
            std::cout << "Error: Debe ingresar solo un caracter. Intente nuevamente." << std::endl;
        } else {
        char opcion = entrada[0];

        switch(opcion) {
        case '1':
            _clienteManager.RestaurarCopiaDeSeguridad();
            break;
        case '2':
            _vehiculoManager.RestaurarCopiaDeSeguridad();
            break;
        case '3':
            _trabajoManager.RestaurarCopiaDeSeguridad();
            break;
        case '4':
            _proveedorManager.RestaurarCopiaDeSeguridad();
            break;
        case '5':
            _empleadoManager.RestaurarCopiaDeSeguridad();
            break;
        case '6':
            _autoClienteManager.RestaurarCopiaDeSeguridad();
            break;
        case '7':
            hacerRestauracionDeSeguridadTodo();
            break;
        case '0':
            return;
            break;
        default:
            std::cout<<"OPCION NO VALIDA"<<std::endl;
            break;
        }
    }
}}



