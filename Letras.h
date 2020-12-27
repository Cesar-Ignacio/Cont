#ifndef LETRAS_H_INCLUDED
#define LETRAS_H_INCLUDED



///prototipo

void lineaHorizontal(int ,int ,int );
void lineaVertical(int,int,int);

void lineaDiagonalAscendente(int ,int, int );
void lineaDiagonalDescendente(int ,int,int);

///funciones

void lineaHorizontal(int x,int y,int ancho)
{
   int lhx=0;
   for(lhx=x;lhx<=x+ancho;lhx++)
   {
      gotoxy(lhx,y);cout<<(char)219<<endl;
   }
}

void lineaVertical(int x,int y,int largo)
{
  int lvy=0;
  for(lvy=y;lvy<=y+largo;lvy++)
  {
      gotoxy(x,lvy);cout<<(char)219<<endl;
  }
}

void lineaDiagonalAscendente(int x,int y, int ancho)
{
    int px=0,py=y;

    for(px=x+1;px<=x+ancho;px++)
    {
        gotoxy(px,py);cout<<(char)219<<endl;
        py=py-1;
    }
}

void lineaDiagonalDescendente(int x, int y,int ancho)
{
    int px=0,py=y;

    for(px=x+1;px<=x+ancho;px++)
    {
        gotoxy(px,py);cout<<(char)219<<endl;

        py=py+1;
    }
}

void LETRAR(int x, int y,int ancho,int largo,int colorletra,char letrar )
{

color("",colorletra);

   if(letrar=='s' || letrar=='S')
   {
  lineaHorizontal(x,y,ancho);///HORIZONTAL SUPERIO

  lineaVertical(x,y,largo);///VERTIVAL SUPERIO

  lineaHorizontal(x,(y+largo)+1,ancho);///HORIZONTAL MEDIO

  lineaVertical(x+ancho,(y+largo)+1,largo);///VRTICAL INFERIOS

  lineaHorizontal(x,(y+largo*2)+2,ancho);///HORIZOBTAL INFERIOR
   }
   if(letrar=='d' || letrar=='D')
   {

    lineaHorizontal(x,y,ancho-1);///LINEA HORIZONTAL SUPERIOR

    lineaHorizontal(x,y+largo,ancho-1);///LINEA HORIZONTAL INFERIOR

    lineaVertical(x,y+1,largo-1);///LINEA VERTICAL IZQUIERDA

    lineaVertical(x+ancho,y+1,largo-2);///LINEA VERTICAL DERECHA

   }
   if(letrar=='o' || letrar=='O')
    {
    lineaHorizontal(x,y,ancho);

    lineaHorizontal(x,(y+largo)+1,ancho);

    lineaVertical(x,y+1,largo-1);

    lineaVertical(x+ancho,y+1,largo-1);
    }
   if(letrar=='c' || letrar=='C')
   {
    lineaHorizontal(x,y,ancho);///LINEA SUPERIOR

    lineaHorizontal(x,(y+largo)+1,ancho);///LINIA INFERIOR

    lineaVertical(x,y,largo);///LINIEA IZQUIERDA
   }
   if(letrar=='a' || letrar=='A')
   {
     lineaHorizontal(x,y,ancho);///LINEA SUPERIO

     lineaHorizontal(x,y+(largo/2),ancho);///LENIA MEDIA

     lineaVertical(x,y,largo);///LINEA IZQUIERDA

     lineaVertical(x+ancho,y,largo);///LINEA DERECHA
   }
   if(letrar=='e'  || letrar=='E')
   {
       lineaHorizontal(x,y,ancho);///LINEA SUPERIOR

       lineaHorizontal(x,y+(largo/2),ancho);///LINEA MEDIA

       lineaHorizontal(x,y+largo,ancho);///LINEA INFERIOS

       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA

   }
   if(letrar=='f' || letrar=='F')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZONTAL SUPERIOS

       lineaHorizontal(x,y+(largo/2),ancho);///LINEA HORIZONTAL MEDIA

       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA

   }

   if(letrar=='l' || letrar=='L')
   {
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA
       lineaHorizontal(x,(y+largo),ancho);///LINEA HORINZONTAL INFERIOR
   }

   if(letrar=='j' || letrar=='J')
   {
       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
       lineaHorizontal(x,y+largo,ancho);///LINEA HORIZAONTAL INFERIOR
   }
   if(letrar=='i' || letrar=='I')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZONTAL SUPERIOR
       lineaHorizontal(x,y+largo,ancho);///LINEA HORIZAONTA INFERIOR
       lineaVertical(x+(ancho/2),y,largo);///LINEA VERTICAL
   }
   if(letrar=='h' || letrar=='H')
   {
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA

       lineaHorizontal(x,y+(largo/2),ancho);///LINEA MEDIA

       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
   }
   if(letrar=='t' || letrar=='T')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZAONTAL SUPERIOR

       lineaVertical(x+(ancho/2),y,largo);///LINEA VERTICAL MEDIA

   }
   if(letrar=='p' || letrar=='P')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZANTAL SUPERIOR

       lineaHorizontal(x,y+(largo/2),ancho);///LINEA HORIZAONTAL MEDIA

       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA

       lineaVertical(x+ancho,y,largo/2);///LINEA VERICAL DERECHA

   }
   if(letrar=='u' || letrar=='U')
   {
       lineaHorizontal(x,y+largo+1,ancho);///LINEA HORIZAONTAL INFERIOR
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA
       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
   }
   if(letrar=='k' || letrar =='K')
   {
      if(largo%2==0 && ancho==0)
      {
       ancho=(largo/2)+1;

       lineaVertical(x,y,largo);///LINEA VERTICAL IZUIERDA

       lineaDiagonalAscendente(x,y+(largo/2),ancho);///LINEA DIAGONAL ASCENDENTE

       lineaDiagonalDescendente(x,y+(largo/2),ancho);
      }
      else
      {
          gotoxy(x,y);cout<<"ERROR"<<endl;
          gotoxy(x,y+1);cout<<"LARGO DEBE SER PAR y ANCHO=0"<<endl;
      }

   }
   if(letrar=='b' || letrar=='B')
   {
    lineaHorizontal(x,y,ancho-1);///LINEA HORIZAONTAL SUPERIOR

    lineaHorizontal(x,y+(largo/2),ancho);///LINEA HORIZAONTAL MEDIA

    lineaHorizontal(x,y+largo,ancho-1);///LINEA HORIZAONTAL INFERIOS

    lineaVertical(x,y,largo);///LINEA VERTICAL

    lineaVertical(x+ancho,y+1,largo-2);///LINEA VERTICAL DERECHA

   }

   if(letrar=='z' || letrar=='Z')
   {
       if(largo==ancho)
       {

       lineaHorizontal(x,y,ancho);///LINEA HORIZAONTAL SUPERIOR

       lineaHorizontal(x,y+largo,ancho);///LINEA HORIZONTAL INFERIOR

       lineaDiagonalAscendente(x,(y+largo)-1,ancho);///LINEA DIAGONAL ASCENDENTE
       }
       else
        {
        gotoxy(x,y);cout<<"ERROR"<<endl;
        gotoxy(x,y+1);cout<<"ANCHO==LARGO"<<endl;
        }


   }

   if(letrar=='n' || letrar=='N')
   {
       if(ancho==largo)
       {
          lineaVertical(x,y,largo);///LINEA VERTICAL OZQUIERDA
       lineaVertical(x+ancho,y,largo);///LINEA VERTCICAL DERECHA
       lineaDiagonalDescendente(x,y+1,ancho);///DIAGONAL DESCENDENTE
       }
       else
        {
         gotoxy(x,y);cout<<"ERROR"<<endl;
         gotoxy(x,y+1);cout<<"ANCHO==LARGO"<<endl;
        }
   }

   if(letrar=='_' )
   {
      if(ancho==largo)
      {
       lineaHorizontal(x+1,y-1,ancho-2);///LINEA HORIZONTAL ACENTO
       lineaVertical(x,y,largo);///LINEA VERTICAL  IZQUIERDA
       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
       lineaDiagonalDescendente(x,y+1,ancho);///LINEA DIAGONAL DESCENDENTE
      }
      else
      {
          gotoxy(x,y);cout<<"ERROR"<<endl;
          gotoxy(x,y+1);cout<<"ANCHO==LARGO"<<endl;
      }

   }

   if(letrar=='g' || letrar=='G')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZAONTAL SUPERIOR
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA
       lineaHorizontal(x,y+largo,ancho);///LINEA HORIZONTAL INFERIOR
       lineaHorizontal(x+2,y+(largo/2),ancho-2);///LINEA HORIZAONTAL MEDIA
       lineaVertical(x+ancho,y+(largo/2),largo/2);///LINEA VERTICAL DERECHA
   }

   if(letrar=='x' || letrar=='X')
   {
       if(ancho==largo)
       {
       lineaDiagonalDescendente(x,y,ancho);///LINEA DIAGONAL DESCENDENTE

       lineaDiagonalAscendente(x,(y+largo)-1,ancho);///LINEA DIAGONAL ASCENDENTE
       }
       else
        {
          gotoxy(x,y);cout<<"ERROR"<<endl;
          gotoxy(x,y+1);cout<<"ANCHO==LARGO"<<endl;
        }


   }
   if(letrar=='y' || letrar=='Y')
   {
      if(largo==ancho)
      {
       lineaDiagonalDescendente(x,y,ancho/2);///LINEA DIAGONAL DESCENDENTE
       lineaDiagonalAscendente(x,(y+largo)-1,ancho);///LINEA DIAGONAL ASCENDENTE
      }
      else
      {
         gotoxy(x,y);cout<<"ERROR"<<endl;
         gotoxy(x,y+1);cout<<"EL ANCHO==LARGO"<<endl;
      }


   }
   if(letrar=='v' || letrar=='V')
   {
       if(ancho==largo)
       {
         lineaDiagonalDescendente(x,y,ancho);
       lineaDiagonalAscendente(x+ancho,(y+largo)-2,ancho-1);
       }
       else
        {
           gotoxy(x,y);cout<<"ERROR"<<endl;
           gotoxy(x,y+1);cout<<"DEBE SER ANCHO==LARGO "<<endl;
        }

   }
   if(letrar=='r' || letrar=='R')
   {
      if(largo%2==0 && ancho==largo-1)
      {
        lineaHorizontal(x,y,ancho);
        lineaVertical(x,y,largo);
        lineaVertical(x+ancho,y,largo/2);
        lineaHorizontal(x,y+(largo/2),ancho);
        lineaDiagonalDescendente(x,y+(largo/2)+1,largo/2);
      }
      else
        {
           gotoxy(x,y);cout<<"ERROR"<<endl;
           gotoxy(x,y+1);cout<<"LARGO PAR Y ANCHO==LARGO-1"<<endl;
        }

   }
   if(letrar=='w' || letrar=='W')
   {
       if(ancho==largo)
       {
        lineaDiagonalDescendente(x,y,ancho);
       lineaDiagonalAscendente(x+ancho,(y+largo)-2,ancho-1);

       lineaDiagonalDescendente((x+ancho)-1,y,ancho);
       lineaDiagonalAscendente((x+(ancho*2))-1,(y+largo)-2,ancho-1);
       }
       else
       {
           gotoxy(x,y);cout<<"ERROR"<<endl;
           gotoxy(x,y+1);cout<<"DEBE SER ANCHO==LARGO "<<endl;
       }
   }
   if(letrar=='q' || letrar=='Q')
   {
       lineaHorizontal(x,y,ancho);///LINEA HORIZONTAL SUPERIOR
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA
       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
       lineaHorizontal(x,y+largo,ancho+1);///LINEA HORIZONTAL SUPERIOR
       lineaDiagonalDescendente((x+ancho)-2,(y+largo)-1,2);///LINEA DIAGONAL DESCENDENTE
   }
   if(letrar=='m' || letrar=='M')
   {
       ///EL ANCHO DEBE SER PAR

       if(ancho%2==0)
       {
       lineaVertical(x,y,largo);///LINEA VERTICAL IZQUIERDA
       lineaVertical(x+ancho,y,largo);///LINEA VERTICAL DERECHA
       lineaDiagonalDescendente(x,y+1,ancho/2);///LINEA DIAGONAL DESCENDENTE
       lineaDiagonalAscendente(x+(ancho/2),(y+(ancho/2))-1,ancho/2);///LINEA DIAGONAL ASCENDENTE
       }
       else
       {
        gotoxy(x,y);cout<<"ERROR"<<endl;
        gotoxy(x,y+1);cout<<"EL ANCHO BEBE SER PAR"<<endl;
       }
   }





 color("",7);
}
#endif // LETRAS_H_INCLUDED
