#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctime>


using namespace std;

#include "gotoxy.h"
#include "color.h"
#include "Cuadros.h"
#include "Letras.h"
const char *ARCHIVO_CONTROL={"Controles.dat"};
const char *ARCHIVO_BKP_COMTROL={"Controles.bkp"};

#include "Clases.h"
#include "Prototipos.h"
#include "Funciones.h"
#include "Marcos.h"

int main()
{
    CONTROL objC;


    int opc=0;




    while(1)
    {
        marco_Principal();
        gotoxy(35,10);cout<<"MENU"<<endl;

        gotoxy(15,12);cout<<"1:\t-NUEVO CONTROL"<<endl;
        gotoxy(15,13);cout<<"2:\t-ELIMINAR UN CONTROL"<<endl;
        gotoxy(15,14);cout<<"3:\t-BUSCAR CONGTROL"<<endl;
        gotoxy(15,15);cout<<"4:\t-LISTAR CONTROLES"<<endl;
        gotoxy(15,16);cout<<"5:\t-MODIFICAR CONTROL"<<endl;
        gotoxy(15,17);cout<<"6:\t-AGREGAR"<<endl;///es para agregar a stock mas controles, el control debe existir.
        gotoxy(15,18);cout<<"7:\t-FALTANTES"<<endl;
        gotoxy(15,19);cout<<"8:\t-BACKUP"<<endl;
        gotoxy(15,20);cout<<"0:\t-SALIR"<<endl;
        gotoxy(74,12);cout<<"OPCION:"<<endl;
        gotoxy(81,12);cin>>opc;
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
