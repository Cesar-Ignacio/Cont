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

#endif // FUNCIONES_H_INCLUDED
