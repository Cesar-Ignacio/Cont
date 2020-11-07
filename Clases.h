#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

class CONTROL
{
private:

    char codigo[20];
    char marca[15][20];
    int cmarcasD;
    char posicion[10];
    int stock;
    int estado;

public:

    char* getcodigo(){return codigo;}
    char* getposicion(){return posicion;}
    int getstock(){return stock;}
    int getestado(){return estado;}


    void setcodigo(char *codi){strcpy(codigo,codi);}
    void setposicion(char *posici){strcpy(posicion,posici);}
    void setestock(int sto){stock=sto;}
    void setestado(int esta){estado=esta;}


    int operator==(char *codigo)
    {
        if(strcmp(this->codigo,codigo)==0)
        {

            return 1;
        }
       return 0;
    }

    void CargraMarcas(void);
    void MostrarMarcas(void);
    void Cargar(void);
    void Mostrar(void);
    void ALTA(void);
    void LEER(int);
    void ACTUALIZAR(int);

};


void CONTROL::CargraMarcas()
{
    int y=1, x=0,cnom=0,opc=0;

    while(y)
    {
        fflush(stdin);
        cout<<"Palabra:";
        cin.getline(marca[x],20);

        cout<<"Agregar nombre 1=si , 0=no:";
        cin>>opc;
        system("cls");
        if(opc==0)
        {
            y=0;
        }
        x++;

    }

     cmarcasD=x;
}

void CONTROL::MostrarMarcas()
{
      cout<<"MARCAS"<<endl;
cout<<"***************"<<endl;
     for(int x=0;x<cmarcasD;x++)
     {
         cout<<marca[x]<<endl;

     }
cout<<"***************"<<endl;
}

void CONTROL::Cargar()
{
    fflush(stdin);
    CargraMarcas();
    fflush(stdin);
    cout<<"INGRESE CODIGO:";
    cin.getline(codigo,20);
    cout<<"POSICION:";
    cin.getline(posicion,10);
    cout<<"STOCK:";
    cin>>stock;
    estado=1;
}

void CONTROL::Mostrar()
{
    if(estado==1)
    {
        MostrarMarcas();
        cout<<"CODIGO DE CONTROL:"<<codigo<<endl;
        cout<<"MARCAS ACEPTADAS:"<<cmarcasD<<endl;
        cout<<"POSICION:"<<posicion<<endl;
        cout<<"STOCK:"<<stock<<endl;
        cout<<"*************"<<endl;
    }

}

void CONTROL::ALTA()
{
    Cargar();

    FILE *p;
    p=fopen(ARCHIVO_CONTROL,"wb");
    if(p==NULL)
    {
        exit(1);
    }

    fwrite(this,sizeof(CONTROL),1,p);

    fclose(p);

}

void CONTROL::LEER(int posicion)
{

    FILE *p;
    p=fopen(ARCHIVO_CONTROL,"rb");
    if(p==NULL)
    {

        exit(1);
    }

    fseek(p,sizeof(CONTROL)*posicion,0);

    fread(this,sizeof(CONTROL),1,p);

    fclose(p);
}

void CONTROL::ACTUALIZAR(int posicion)
{
    FILE *p;
    p=fopen(ARCHIVO_CONTROL,"rb+");
    if(p==NULL)
    {
        exit(1);
    }
    fseek(p,sizeof(CONTROL)*posicion,0);

    fwrite(this,sizeof(CONTROL),1,p);

    fclose(p);
}


#endif // CLASES_H_INCLUDED
