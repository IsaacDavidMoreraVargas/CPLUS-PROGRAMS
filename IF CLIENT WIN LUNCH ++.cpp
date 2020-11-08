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


 int b1,juga,juga2,juga3,x,ronda,promedio,i,almuerzo;
 char opc;
 string nombre;
 promedio=0;
 ronda=0;
 b1=0;
 juga=0;
 juga2=0;
 juga3=0;
 almuerzo=0;

 cout<<"Digite la cantidad de jugadores para la ronda: "<<endl;
 cin>>juga3;//iniciador de los vectores
   if(juga3<=0)
   {
    while(juga3<=0)
     {
     cout<<"Digite una cantidad de particpantes mayor a 0"<<endl;
      cin>>juga3;
     }
   }
   juga=juga3;//inicializador del acumulador que se usara en los calculos posteriores

do{

//tamaño los vectores por juga3,su tamano se reescribira por el ciclo
 int fle1[juga];
 int fle2[juga];
 int fle3[juga];

 string companom[juga];
 string companom1[juga];



      for(x=b1;x<juga;x++)
       {

        cout<<"\n"<<endl;
        cout<<"---------------------------------------------"<<endl;
          cout<<"Introduzca nombre del jugador: "<<x<<endl;
            cin>>nombre;//asignacion nombres

              companom1[x]=nombre;//añade la variable nombre al vector comparacion1

                  if(companom[x]==nombre)//ciclo por si se repite el nombre
                     {
                    while(companom[x]==nombre)
                     {
                     cout<<"El jugador numero: "<<x<<", "<<companom1[x]<<", Ya jugo"<<endl;
                     cout<<"Por favor digite otro jugador"<<endl;
                      cin>>nombre;
                      }
                    }
         cout<<"---------------------------------------------"<<endl;

                 companom[x]=companom1[x];//anade la variable nombre al vector comparacion2

              cout<<"Introduzca la flecha 1, jugador: "<<x<<endl;
                cin>>fle1[x];//asignacion valor flecha1


                  if(fle1[x]<1||fle1[x]>10)//ciclo por si el numero es menor a 1 o mayor 10{
                      {
                       while(fle1[x]<1||fle1[x]>10)
                        {
                         cout<<"Digite un valor entre 1 y 10"<<endl;
                           cin>>fle1[x];
                        }
                      }

                  almuerzo+=fle1[x];//sumador para saber si se gana un almuerzo



                 cout<<"Introduzca la flecha 2, jugador: "<<x<<endl;
                    cin>>fle2[x];//asignacion valor flecha2

                     if(fle2[x]<1||fle2[x]>10)//ciclo por si el numero es menor a 1 o mayor 10{
                      {
                       while(fle2[x]<1||fle2[x]>10)
                        {
                         cout<<"Digite un valor entre 1 y 10"<<endl;
                           cin>>fle2[x];
                        }
                      }//}



                     almuerzo+=fle2[x];//sumador para saber si se gana un almuerzo




                      cout<<"Introduzca la flecha 3, jugador: "<<x<<endl;
                        cin>>fle3[x];//asignacion valor flecha3

                          if(fle3[x]<1||fle3[x]>10)//ciclo por si el numero es menor a 1 o mayor 10{
                           {
                            while(fle3[x]<1||fle3[x]>10)
                              {
                               cout<<"Digite un valor entre 1 y 10"<<endl;
                                 cin>>fle3[x];
                              }
                           }//}


                      almuerzo+=fle3[x];//sumador para saber si se gana un almuerzo


                      promedio+=(fle1[x]+fle2[x]+fle3[x]);//contador del promedio total de puntos

                                if(almuerzo>=21)
                                 {

                                 cout<<"\n"<<endl;
                                 cout<<"''''''''''''''''''''''''''''''''''''''''"<<endl;
                                   cout<<"El participante: "<<nombre<<", ¡GANO UN ALMUERZO!"<<endl;
                                 cout<<"''''''''''''''''''''''''''''''''''''''''"<<endl;
                                 cout<<"\n"<<endl;
                                 }


                                almuerzo=0;//reinicia el contador a 0 para posteriores ciclos

       }//cierre ciclo for


        cout<<""<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<""<<endl;
          cout<<"Quiere añadir mas jugadores"<<endl;
           cout<<"Digite o S o N"<<endl;
            cin>>opc;//opc para elegir mas jugadores

              if(opc!='n'&& opc!='N'&& opc!='S'&& opc!='s')//ciclo por si no se elige S o N
                {
                  while(opc!='n'&& opc!='N'&& opc!='S'&& opc!='s')
                       {
                        cout<<"Digite o S o N"<<endl;
                         cin>>opc;
                       }
                 }
         cout<<""<<endl;
         cout<<"---------------------------------------------"<<endl;
         cout<<""<<endl;


                  if (opc=='s'||opc=='S')//ciclo que reasignara los nuevos valores para los vectores
                     {
                       b1=juga;//reasigna el inicio en los for para su llenado
                         cout<<"Digite la nueva cantidad de jugadores"<<endl;
                           cin>>juga2;//valor que ampliara el tamaño los vectores
                             juga+=juga2;//reasigna el final en los for
                     }


}while(opc=='s'||opc=='S');//opcion para ejecutar de nuevo el ciclo



         cout<<"---------------------------------------------"<<endl;
         cout<<""<<endl;
               //contadores finales de total de jugadores y promedio de puntos totales {
                cout<<"Cantidad jugadores: "<<juga<<endl;
                  cout<<"Promedio: "<<promedio/juga<<endl;
              //}
         cout<<""<<endl;
         cout<<"---------------------------------------------"<<endl;

return 0;
}
