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
