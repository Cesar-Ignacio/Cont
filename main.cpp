#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctime>


using namespace std;



const char *ARCHIVO_CONTROL={"Controles.dat"};
const char *ARCHIVO_BKP_COMTROL={"Controles.bkp"};

#include "Clases.h"
#include "Prototipos.h"
#include "Funciones.h"


int main()
{
    CONTROL objC;


    int opc=0;

    while(1)
    {

        cout<<"MENU"<<endl;
        cout<<"**************"<<endl;
        cout<<"1:-NUEVO CONTROL"<<endl;
        cout<<"2:-ELIMINAR UN CONTROL"<<endl;
        cout<<"3:-BUSCAR CONGTROL"<<endl;
        cout<<"4:-LISTAR CONTROLES"<<endl;
        cout<<"5:-MODIFICAR CONTROL"<<endl;
        cout<<"6:-AGREGAR"<<endl;///es para agregar a stock mas controles, el control debe existir.
        cout<<"7:-FALTANTES"<<endl;
        cout<<"8:-BACKUP"<<endl;
        cout<<"0:-SALIR"<<endl;
        cout<<"**************"<<endl;
        cin>>opc;
        system("cls");

        if(opc==1)
        {
         NuevoControl();
        }
        if(opc==2)
        {
         BajaDeControl();
        }
        if(opc==3)
        {
          BuscarControl();
        }
        if(opc==4)
        {
          ListarControles();
        }
        if(opc==5)
        {
          ModificarControl();
        }
        if(opc==7)
        {
            Faltantes();
        }
        if(opc==8)
        {
            Backup();
        }
        if(opc==0)
        {

            return 0;
        }



    }



    system("pause");
    return 0;
}
