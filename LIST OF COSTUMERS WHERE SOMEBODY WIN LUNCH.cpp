//Isaac Morera Vargas
//Cedula
//Universidad Estatal a distancia
//Materia 830
//Año 2017
//Grupo 2
//III cuatrimestre
//Proyecto



#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <cstdio>



using std::cin;
using std::cout;
using std::endl;
using namespace std;


   struct total//estructura del archivo
     {
       int puntos=0;
       char cedula[10]="";
       char nombre[20]="";
     };

  void registroJugador()//funcion registrar a los jugadores
    {
      system("cls");
      total clientess;//puntador a estruct total
      cin.ignore();

       ofstream archivoGuardar("clientes.txt",ios::app);
             if(archivoGuardar.bad())//cierra si el archivo no se crea
               {
                  cerr<<"El archivo no pudo crearse";
                  exit(1);
               }

               cout<<"\nIngrese la cedula del jugador a registrar"<<endl;
               cin.getline(clientess.cedula,10);
               cout<<"\nIngrese el nombre del jugador a registrar"<<endl;
               cin.getline(clientess.nombre,20);

                 archivoGuardar.write((char*)&clientess,sizeof(clientess));
                 archivoGuardar.close();
                 system("cls");

                    cout<<"\nAhora el programa se desplegara de nuevo por su comodidad"<<endl;
    }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void jugar()//funcion jugar jugadores
{

 system("cls");
 total clientess;
 cin.ignore();
 string buffer;

 int totalflecha;
 totalflecha=0;
 char ubicacion[10];
 int contador=1;
 ifstream archivoMostrar("clientes.txt");

     if(archivoMostrar.bad())
       {
         cerr<<"El archivo no pudo leerse";
         exit(1);
       }

 cout<<"Digite la cedula del jugador que va a participar"<<endl;
 cin>>ubicacion;
 cout<<"\n"<<endl;

 while(archivoMostrar && !archivoMostrar.eof())//ciclo para encontrar jugadores y jueguen la ronda
   {
     buffer=clientess.cedula;

        if(ubicacion==buffer)
         {
            system("cls");
            int intento,bandera,flecha1,flecha2;
            bandera=1;
            intento=1;
            flecha1=0;
            const int salida=4;

           while(bandera<salida)//ciclo para obtener el puntaje
            {
              cout<<"-------------------------------------"<<endl;
              cout<<"JUGADOR: "<<clientess.nombre<<endl;
              cout<<"Recuerde que el puntaje es de 1 a 10"<<endl;
              cout<<"Flecha "<<bandera<<endl;

             while(intento<3)
              {
                    cout<<"Intento : "<<intento<<"\n Digite: "<< endl;
                    cin>>flecha1;

                     if(flecha1<1||flecha1>10)
                        {
                         while(flecha1<1||flecha1>10)
                            {
                               flecha1=0;
                               cout<<"\n"<<endl;
                               cout<<"\n--------------------------------------------------------"<<endl;
                               cout<<"No digito un puntaje valido"<<endl;
                               cout<<"Flecha "<<bandera<<", intento "<<intento<<endl;
                               cout<<"Recuerde que el puntaje es de 1 a 10"<<endl;
                               cout<<"\n"<<endl;
                               cout<<"Redigite el puntaje:"<<endl;
                               cin>>flecha1;
                               system("clear");
                               cout<<"\n"<<endl;
                            }

                        }
               totalflecha=totalflecha+flecha1;
               intento++;
               system("cls");
             }
             intento=1;
             bandera++;
            }

            totalflecha=totalflecha/2;

            if(totalflecha>=21)//anuncio almuerzo gratis
             {
              cout<<"\nEl jugador: "<<clientess.nombre<<", ¡gano un almuerzo de cortesia!"<<endl;
             }


    ifstream archivoLectura("clientes.txt",ios::app);
    ofstream archivoGuardar("ranking.txt",ios::app);

     if(archivoGuardar.bad())
       {
         cerr<<"El archivo no pudo crearse";
         exit(1);
       }

        clientess.puntos=totalflecha;
        archivoGuardar.write((char*)&clientess,sizeof(clientess));

    archivoLectura.close();
    archivoGuardar.close();
    archivoMostrar.close();
    totalflecha=0;
    break;

   }

       archivoMostrar.read((char*)&clientess,sizeof(clientess));
 }

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void verAnking()//funcion ver ranking
{
   system("cls");
   total clientess;
   ifstream archivoMostrar("ranking.txt");
     if(archivoMostrar.bad())
        {
          cerr<<"El archivo no pudo abrirse";
          exit(1);
        }

   archivoMostrar.read((char*)&clientess,sizeof(clientess));

  cout<<"\t---------------------------------------------------------"<<endl;
  cout<<"\t|    CEDULA   |           NOMBRE        |     RANKING   |"<<endl;
  cout<<"\t---------------------------------------------------------"<<endl;
  while(archivoMostrar && !archivoMostrar.eof())
   {
     cout<<"\t| "<<left<<setw(12)<<setfill(' ')<<clientess.cedula<<"|  "<<left<<setw(23)<<clientess.nombre<<"| "<<clientess.puntos<<endl;
     archivoMostrar.read((char*)&clientess,sizeof(clientess));
   }

  archivoMostrar.close();

  cout<<"\n"<<endl;
  cout<<"Ahora el programa se desplegara de nuevo por su comodidad"<<endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void borrarArchivos()//funcion borrar archivos
 {
   int opcion;
   system("cls");

   cout<<"\nBienvenido al sistema de eliminacion de archivos."<<endl;
   cout<<"Digite:\n \n  1-Eliminar el archivo de registro de todos los jugadores. \n     2-Eliminar el archivo de registro del ranking."<<endl;
   cout<<"        3-Eliminar el archivo de registro de todos los jugadores \n             y el archivo de registro del ranking."<<endl;
   cin>>opcion;


    if (opcion==1 || opcion==2 || opcion==3)
     {
       try
         {
            if (opcion==1)
                {
                  remove("clientes.txt");
                }
             else
              {
             if (opcion==2)
                {
                  remove("ranking.txt");
                }
             else
              {
             if (opcion==3)
                {
                  remove("clientes.txt");
                  remove("ranking.txt");
                }
              }
              }

         }catch(exception &e)
             {
              cout<<"El programa tuvo algun percance"<<endl;
             }

     }else{
           system("cls");
           cout<<"Hubo un problema y no se pudieron eliminar los archivos,\nse cerrara el programa"<<endl;
           cout<<"\nEl error probablemente fue por no elegir una opcion correcta*"<<endl;
           exit(1);
          }

    system("cls");

 }

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

   int main()//funcion main para elegir las opciones
     {

       int eleccion;

          do{

             cout<<"\n"<<endl;
             cout<<"|--------------------------------------------------------------------------|"<<endl;
             cout<<"|                                 ¡Bienvenido!                             |"<<endl;
             cout<<"|-------------------------------|------------------------------------------|"<<endl;
             cout<<"|\tMenu:                   |\n|\t1-Registro de jugadores |\n|\t2-Jugar                 |\n|\t3-Ver ranking           |\n|\t4-Borrar archivo        |\n|\t5-Salir                 |"<<endl;
             cout<<"|-------------------------------|"<<endl;
             cout<<"\n"<<endl;
             cout<<"Elija una opcion: "<<endl;
             cin>>eleccion;


               if(eleccion!=1 && eleccion!=2 && eleccion!=3 && eleccion!=4 && eleccion!=5)
                {
                   try//bloque de mensaje al no digitar un numero correcto
                     {
                        system("cls");
                        cout<<"La eleccion fue erronea, el programa se cerrara"<<endl;
                        cout<<"\nEl problema probablemente fue por no elegir el numero correcto*"<<endl;
                         exit(1);

                     }catch(exception &e)
                        {
                           system("cls");
                           cout<<"Eligio una opcion incorrecta"<<endl;
                           exit(1);
                        }
                }else{
                          switch(eleccion)
                            {
                              case 1:
                              registroJugador();
                              break;

                              case 2:
                              jugar();
                              break;

                              case 3:
                              verAnking();
                              break;

                              case 4:
                              borrarArchivos();
                              break;

                              case 5:
                              break;
                            }
                     }

             }while(eleccion!=5);

       return 0;
    }
