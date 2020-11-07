#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void NuevoControl()
{
    CONTROL objC;

    cout<<"CARGE NUEVO CONTROL"<<endl;
    cout<<"*******************"<<endl;
    objC.ALTA();
    system("pause>null");
    system("cls");
}

void BajaDeControl()
{
    CONTROL objC;
    char codigo[20];
    int UBR=0;
    cout<<"BAJA DE CONTROL"<<endl;
    cout<<"***************"<<endl;
    fflush(stdin);
    cout<<"CODIGO DE CONTROL:";
    cin.getline(codigo,20);

    UBR=UbicacionDeRegistro(codigo);

    if(UBR!=-1)
    {
        objC.LEER(UBR);
        objC.setestado(0);
        objC.ACTUALIZAR(UBR);
        cout<<"SE ELIMINO EL REGISTRO"<<endl;
    }
    else
    {
        cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
    }

    system("pause>null");
    system("cls");


}

void BuscarControl()
{
    CONTROL objC;

    char codigo[20];
    int UBR=0;

    cout<<"BUSCAR CONTROL"<<endl;
    cout<<"*************"<<endl;

    fflush(stdin);
    cout<<"INGRESE CODIGO:";
    cin.getline(codigo,20);

       UBR=UbicacionDeRegistro(codigo);
       if(UBR!=-1)
       {
           objC.LEER(UBR);
           objC.Mostrar();
       }
       else
       {

           cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
       }


    system("pause>null");
    system("cls");

}

void ListarControles()
{
    CONTROL objC;

    int CRG=ContarRegistroDeArchivo(ARCHIVO_CONTROL,sizeof(CONTROL));

    for(int x=0;x<CRG;x++)
    {
        objC.LEER(x);
        objC.Mostrar();
    }

    system("pause>null");
    system("cls");

}

void ModificarControl()
{

    CONTROL objM;

    char posicion[20],codfigo[20];
    int opc=0, stock=0,UBR=0;

    cout<<" MODIFICAR CONTROL "<<endl;
    fflush(stdin);
    cout<<" CODIGO:";
    cin.getline(codfigo,20);

    UBR=UbicacionDeRegistro(codfigo);
    if(UBR!=-1)
    {
    objM.LEER(UBR);
    objM.Mostrar();
    cout<<"MODIFICAR : 1= POSICION , 2= STOCK:";
    cin>>opc;

    if(opc==1)
    {
        fflush(stdin);
        cout<<"POSICION:";
        cin.getline(posicion,20);

        objM.setposicion(posicion);
    }
    else if(opc==2)
    {

        cout<<"STOCK:";
        cin>>stock;
        objM.setestock(stock);

    }
        objM.ACTUALIZAR(UBR);

    }
    else
    {
     cout<<"NO SE ENCONTRO EL REG"<<endl;
    }

  system("pause>null");
  system("cls");
}

void Faltantes()
{

    CONTROL objc;

    int canreg=ContarRegistroDeArchivo(ARCHIVO_CONTROL,sizeof(CONTROL));

    cout<<"CONTROLES FALTANTE"<<endl;
    for(int x=0;x<canreg;x++)
    {
        objc.LEER(x);

        if(objc.getestado()==1)
        {

            if(objc.getstock()==0)
            {
                objc.Mostrar();
            }


        }

    }

    system("pause>null");
    system("cls");

}

///FUNCIONES AYUDA

int ContarRegistroDeArchivo(const char *Archivo,int tamnio)
{
    FILE *p;
    p=fopen(Archivo,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    fseek(p,0,2);

    int cantreg=ftell(p)/tamnio;

    fclose(p);

    return cantreg;
}

int UbicacionDeRegistro(char *codigoC)
{
    CONTROL objC;
    int pos=0,cantreg=ContarRegistroDeArchivo(ARCHIVO_CONTROL,sizeof(CONTROL));

    for(int x=0;x<cantreg;x++)
    {
       objC.LEER(x);
       if(objC==codigoC)
       {
        return x;
       }

    }

    return -1;
}
#endif // FUNCIONES_H_INCLUDED
