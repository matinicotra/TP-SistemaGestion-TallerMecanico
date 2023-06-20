#ifndef MENU_H
#define MENU_H
#include<iostream>

class Menu
{
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
