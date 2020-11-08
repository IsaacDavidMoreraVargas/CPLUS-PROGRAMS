//Isaac Morera Vargas
//Cedula: 116200798
//Tarea1
//Universidad Estatal a Distancia
//Grupo 01
//Tercer cuatrimestre
//Año 2017


#include <iostream>
#include <string.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using namespace std;

int main()
{


 int bandera1,jugadores,x,ronda,i,puntaje1,ini,totaljugadores,fin,fle1,fle2,fle3,fle4,fle5,fle6,mayor,menor,flechagracia,sumatotal,y,z;
 string nombre;
 ronda=0;
 ini=0;
 bandera1=0;
 sumatotal=0;



 cout<<"Digite la cantidad de jugadores que van a jugar: "<<endl;
 cin>>jugadores;//iniciador de los vectores
   if(jugadores<2 || jugadores>4)
   {
   while(jugadores<2 || jugadores>4)
   {
   cout<<"Digite entre 2 o 4 participantes"<<endl;
   cin>>jugadores;
   }
   }
   cout<<"\n";

   totaljugadores=jugadores;
    fin=jugadores;


   //tamaño los vectores por juga3,su tamano se reescribira por el ciclo
 int fle[99999];
 string comparador[99999];



do{

     cout<<"\n"<<endl;
     cout<<"\n"<<endl;
     cout<<"¡¡¡WWWIIIIIIII SE HA ABIERTO LA RONDA!!!! #"<<ronda;
     cout<<"\n"<<endl;



      for(x=ini;x<jugadores;x++)
       {
          cout<<"\n"<<endl;
          cout<<"**************************************"<<endl;

          cout<<"Introduzca nombre del jugador: "<<x<<endl;
            cin>>nombre;//asignacion nombres

                 for(i=0;i<jugadores;i++)//ciclo para jugadores repetidos
                   {
                    if(comparador[i]==nombre)//ciclo por si se repite el nombre
                     {
                      while(comparador[i]==nombre)
                      {
                      cout<<"Los mismo jugadores tienen que jugar esta otra ronda"<<endl;
                      cin>>nombre;
                      }
                    }

                  }


            comparador[x]=nombre;//anade la variable nombre al vector-comodin comparacion2

  cout<<"\n"<<endl;
  cout<<"------------------------------------------------------------------------------"<<endl;
  cout<<"JUGADOR: "<<comparador[x]<<endl;
  cout<<"------------------------------------------------------------------------------"<<endl;

  cout<<"Flecha 1: intento 1, jugador: "<<endl;//ciclos para flechas
  cin>>fle1;
  if(fle1<1||fle1>10)
  {
    while(fle1<1||fle1>10)
    {
      cout<<"Digite entre 1 o 10"<<endl;
      cin>>fle1;
    }
  }
  cout<<"Flecha 1: intento 2, jugador: "<<endl;
  cin>>fle2;
  if(fle2<1||fle2>10)
  {
    while(fle2<1||fle2>10)
    {
      cout<<"Digite entre 1 o 10"<<endl;
      cin>>fle2;
    }
  }
  puntaje1+=(fle1+fle2)/2;

  cout<<"Flecha 2: intento 1, jugador: "<<endl;
  cin>>fle3;
  if(fle3<1||fle3>10)
  {
    while(fle3<1||fle3>10)
    {
      cout<<"Digite entre 1 o 10"<<endl;
      cin>>fle3;
    }
  }
  cout<<"Flecha 2: intento 2, jugador: "<<endl;
  cin>>fle4;
  if(fle4<1||fle4>10)
  {
    while(fle4<1||fle4>10)
    {
      cout<<"Digite entre 1 o 10"<<endl;
      cin>>fle4;
    }
  }
  puntaje1+=(fle3+fle4)/2;

  cout<<"Flecha 3: intento 1, jugador: "<<endl;
  cin>>fle5;
  if(fle5<1||fle5>10)
  {
    while(fle5<1||fle5>10)
    {
      cout<<"Digite entre 1 o 10"<<endl;
      cin>>fle5;
    }
  }
  cout<<"Flecha 3: intento 2, jugador: "<<endl;
  cin>>fle6;
  if(fle6<1||fle6>10)
  {
    while(fle6<1||fle6>10)
    {
      cout<<"Digite entre 1 o 10"<<endl;
      cin>>fle6;
    }
  }
  puntaje1+=(fle5+fle5)/2;


  fle[x]=puntaje1;//anade el valor de las feclas a una matriz


  if(mayor<puntaje1)
  {
  mayor=puntaje1;
  }

  puntaje1=0;//devuelve el aculador a cero par porteriores sumas


  }//cierre for principal




  ronda=ronda+1;
  ini=jugadores;//cambia las posiciones de los indices
  jugadores+=fin;//amplia el vector
  bandera1=bandera1+1;//aumenta la condicion de salida


}while(bandera1<fin);//opcion para ejecutar de nuevo el ciclo

  for(i=0;i<fin*fin;i++)//cicilo para encontrar el numero menor
  {

     sumatotal+=fle[i];
     menor=(sumatotal/mayor)+1;


     if(fle[y]==menor)
     {
      cout<<"\n"<<endl;
      cout<<"------------------------------------------------------------------------------"<<endl;
      cout<<"¡HORA DE TIRAR LA FLECHA PARA EL MAS GRANDE PERDEDOR DEL MUNDO!"<<endl;
      cout<<"El jugador: "<<comparador[y]<<", Le toca tirar la flecha de gracia."<<endl;
      cin>>flechagracia;
      cout<<"------------------------------------------------------------------------------"<<endl;

      if(flechagracia<1 || flechagracia>10)
         {
           while(flechagracia<1 || flechagracia>10)
            {
             cout<<"Digite entre 1 y 10 participantes"<<endl;
             cin>>flechagracia;
            }
         }

         if(flechagracia==10)
         {
           cout<<"Debe almorzar Una bolsa de palomitas con una botella de agua"<<endl;
           break;
         }
         else if(flechagracia==9)
         {
           cout<<"Debe almorzar Una botella de agua y una galleta"<<endl;
           break;
         }
         else if(flechagracia==8)
         {
           cout<<"Debe almorzar Una botella de agua y una melcocha"<<endl;
           break;
         }
         else if(flechagracia==7)
         {
           cout<<"Debe almorzar Una botella de agua y un milan"<<endl;
           break;
         }
         else if(flechagracia==6)
         {
           cout<<"Debe almorzar Una botella de agua y un confite"<<endl;
           break;
         }
         else if(flechagracia==5)
         {
           cout<<"Debe almorzar Una rosquilla"<<endl;
           break;
         }
         else if(flechagracia==4)
         {
           cout<<"Debe almorzar Una merendina"<<endl;
           break;
         }
         else if(flechagracia==3)
         {
           cout<<"Debe almorzar Una melcocha"<<endl;
           break;
         }
         else if(flechagracia==2)
         {
           cout<<"Debe almorzar 1 milan"<<endl;
           break;
         }
         else if(flechagracia==1)
         {
           cout<<"Debe almorzar Un confite"<<endl;
           break;
         }
       }
    }



    for(z=totaljugadores;z<fin*fin;z++)//ciclo para imprimir informacion
    {
     cout<<"\n"<<endl;
     cout<<"TOTAL DE PUNTOS POR JUGADOR"<<endl;
     cout<<"Puntaje jugador nombre: "<<comparador[z]<<"+++++"<<fle[z]<<endl;

    }
     cout<<"\n"<<endl;
    cout<<"Promedio de puntaje de los jugadores :"<<sumatotal/totaljugadores<<endl;


return 0;
}
