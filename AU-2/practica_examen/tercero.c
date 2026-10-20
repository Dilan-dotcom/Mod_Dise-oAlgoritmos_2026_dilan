//tercer ejercicio de la practica de examen de progrmacion 

#include <stdio.h>   
#include<string.h>   
//constantes
#define CENTINELA1 "FIN"
#define CENTINELA2 "fin"
#define Max_Libros 10
#define ANCHOPALABRA 50

int main (void){
    char libros[Max_Libros][ANCHOPALABRA];
    //declaracion [cantidad de libros y [anchopalabra]]
    double precios[Max_Libros];//Maximo de 10 libros y usamos double para precio//las veces que vamos  a poner el precio de libros osea vamos a ponerle un valor a cada libro (10)es un arrglo paralelo(buscar el tema de areglos paralelos)
    double TotalPrecios=0;
    int cantidad [Max_Libros],contadorLibros=0 , totalCantidad=0;//csntidad maxima//

    char tituloTemp [ANCHOPALABRA];//guarda del titulo para la verificacion

    printf("Ingrese un titulo del libro (FIN para terminar) :\n");
    fgets(tituloTemp , sizeof(tituloTemp) ,stdin);//usamos fgets porque estamos usando una cadena de palabras   se usa para palabras largas

    tituloTemp[strcspn(tituloTemp,"\n")] ='\0';//gurdar el texto en el titulo temporay y quitar el salto de linea 


    while (strcmp(CENTINELA1, "FIN")!=0||strcmp(CENTINELA2, "fin")!=0|| contadorLibros< Max_Libros)//si nos piden centiles se usa wl while y la expresion significa que mientras centinela 1 sea diferente a cero o fin en este caso seguira funcionando 
    /* vamoos a usar strcmp para compara las aadenas , para comparalas trata de hacer la estrcutura igual */
    //ponemos un contdor de 10 para limitar el proceso ya que solo se nos pidio 10 libros sin tendriamos que usar un if(la linea i < Max_Libros)
    {
        //guradar titulo temporal en matriz 
        strcpy(libros[contadorLibros],tituloTemp);

        //validar precio y cantidad

        do
        {
        printf("ingrese el precio del libro : \n");
        scanf("%lf",&precios[contadorLibros]);
        
 
        if ( precios[contadorLibros] < 0)
        {
            printf("no valido debe de swer mayor a cero \n");
        }
        } while (precios[contadorLibros]<0);

        ///validador del contador de cantidad
        do
        {
        printf("ingrese el precio del libro : \n");
        scanf("%lf",&precios[contadorLibros]);
        

        if ( precios[contadorLibros] < 0)
        {
            printf("no valido debe de swer mayor a cero \n");
        }
        } while (precios[contadorLibros]<0);

        //acumulacion de el total de precios y el total de cantidades
        totalCantidad = totalCantidad+cantidad[contadorLibros];
        TotalPrecios = precios[contadorLibros]*cantidad[contadorLibros];

        //se suma el contador 
        contadorLibros= contadorLibros+1;
        while (getchar() !='\n')//arregla el salto de linea extra que genera
        {
            /* code */
        }
        

        //pedir los datos
        printf("Ingrese un titulo del libro (FIN para terminar) :\n");
        fgets(tituloTemp , sizeof(tituloTemp) ,stdin);
        //titulo temporal
        tituloTemp[strcspn(tituloTemp,"\n")] ='\0';
    }
    for ( contadorLibros = 0; contadorLibros < 10; contadorLibros++)
    {
        printf("%s\n",libros[contadorLibros]);
        printf("%d\n",cantidad[contadorLibros]);
        printf("%f\n",precios[contadorLibros]);
    }
    return 0;
}