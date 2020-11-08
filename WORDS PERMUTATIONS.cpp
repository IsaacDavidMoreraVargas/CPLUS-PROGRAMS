//UNIVERSIDAD ESTATAL A DISTANCIA
//ISAAC MORERA VARGAS
//MATERIA: 831
//CEDULA: 116200798
//TAREA 3
//AÑO 2017




#include <iostream>


 using std::cin;
 using std::cout;
 using std::endl;


 void permutaciones(int contadortotal, char comparador[])//TOMA LOS VALORE DE MAIN
 {
    int i,j;
     int bandera6=0;
      int bandera1=1;
       long permutador1=0;
       char aux;

            bandera1=contadortotal;
            permutador1=contadortotal;

               while(bandera1>1)//SE ENCARGARA DE CREAR A CANTIDAD DE VECES QUE SE DARA LA PERMUTACION
                {
                 bandera1=bandera1-1;
                  permutador1=permutador1*bandera1;
                 }

cout<<"\n"<<endl;
cout<<"----------------------------------------"<<endl;
cout<<"AQUI EMPIEZAN LAS PERMUTACIONES"<<endl;
cout<<"----------------------------------------"<<endl;


while(bandera6<permutador1)
   {
    for(i=contadortotal-1;i>0;i--)//CICLO ENCARGADO DE CREAR LAS PERMUTACIONES, MOVERA UN ESPACIO HACIA ATRAS LAS LETRAS
       {
         aux=comparador[i-1];
          comparador[i-1]=comparador[i];
           comparador[i]=aux;
            cout<<'\n'<<endl;
              for (int j = 0; j < contadortotal; j++)//CICLO QUE IMPRIME RESULTADOS
               cout<<comparador[j];
                 bandera6=bandera6+1;
       }

       if(bandera6==permutador1)
        {
          break;
        }

   }

   cout<<"\n"<<endl;
   cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
   cout<<"+++++++++Cantidad de permutaciones realizadas: "<<permutador1<<"+++++++++++++"<<endl;
   cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

 }



int main()
{
int x,contador,fin,j,ini,contadortotal,pal,bandera;
char comparador[21];
char nume[21];
ini=0;
contador=0;
contadortotal=0;
fin=0;
pal=1;
bandera=1;

cout<<"Reglas: \n 1-Introducira tres palabras"<<endl;
cout<<"Requisitos: \n Cada palabra debe tener mas de 2 o menos de 6 letras "<<endl;

cout<<"+++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
while(bandera<4)//CICLO PARA RECIBIR DATOS
{
contador=0;

            cout<<"Palabra numero: "<<pal<<endl;
                cin>>nume+ini;

               for(x=ini;nume[x]!='\0';x++)
                {
                  if(nume[x]!='\0')
                  {
                     contador+=1;
                   }
                 }//endfor

                    if(contador>6 || contador<2)//CICLO EN CASO DE QUE LA PALABRA NO CUMPLA CON LA CANTIDAD DE LETRAS
                     {
                        while(contador>6 || contador<2)
                         {
                            contador=0;
                            cout<<"La palabra no cumple con los requisitos"<<endl;
                            cout<<"Recuerde mas de 2 letras o menos de 2 letras"<<endl;
                            cout<<"Redigite la palabra: "<<nume+ini<<endl;
                            cin>>nume+ini;
                              for(x=ini;nume[x]!='\0';x++)
                               {
                                 if(nume[x]!='\0')
                                   {
                                     contador+=1;
                                   }
                               }//endfor
                         }

                     }

                     fin+=contador;

                   cout<<"Cantidad de palabras: "<<contador<<endl;
                   contadortotal+=contador;//ANADE LA PALABRA A LA MATRIZ

                 for(j=ini;j<fin;j++)//inicia 0 ,menos posicion 2
                       {
                          comparador[j]=nume[j];
                       }

                ini=fin;
                contador=0;//ACTUALIZA CONTADORES Y LA POSICION DE LA MATRIZ QUE RECIBE LAS PALABRAS
                pal+=1;
bandera+=1;
}

permutaciones(contadortotal,comparador);


return 0;
}
