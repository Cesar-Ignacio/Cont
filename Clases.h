#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

class CONTROL
{
private:

    char codigo[20];
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


    void Cargar(void);
    void Mostrar(void);
    void ALTA(void);
    void LEER(int);
    void ACTUALIZAR(int);

};


void CONTROL::Cargar()
{
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
        cout<<"CODIGO DE CONTROL:"<<codigo<<endl;
        cout<<"POSICION:"<<posicion<<endl;
        cout<<"STOCK:"<<stock<<endl;
        cout<<"*************"<<endl;
    }

}

void CONTROL::ALTA()
{
    Cargar();

    FILE *p;
    p=fopen(ARCHIVO_CONTROL,"ab");
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
