//tercer ejercicio de la practica de examen de progrmacion 

#include <stdio.h>   
#include<string.h>     
#define CENTINELA1 "FIN"
#define CENTINELA2 "fin"
#define CntidadLibros 10
#define AnchoPalabra 50

int main (void){
    char libros[CntidadLibros][AnchoPalabra], desicion[3];
    int cantidad, maximo, cantidadTotal;
    double precio,precioTotal=0;


    while (strcmp(CENTINELA1, "FIN") == 0 || strcmp(CENTINELA2, "fin") == 0)
    {
    for (maximo = 0; maximo < 10; maximo++){
        printf("Desea agregar un  libro? :");
        scanf("%2s",desicion);
        if (strcmp(desicion, "Si")==0)
        {printf("Ingrese el titulo del libro");
        fgets(libros[maximo] ,sizeof(AnchoPalabra),stdin);
        libros[0][strcspn(libros[maximo],"\n")] = '\0';
        do
        {
            printf("ingrese la cantidad de libros");
            scanf("%lf",&precio);
            if (precio <0)
            {
                printf("precio incorrecto");
            }
            
        } while (precio <0);
        precioTotal=precioTotal+precio;
        do
        {
            printf("Ingrese la cantidad ");
            scanf("%d", &cantidad);
            if (cantidad<0){
            printf("cantidad incorrecta");}

        } while (cantidad<0);
        cantidadTotal=cantidadTotal+cantidad;
        }
        else
        {
        break;
        }
        for (maximo = 0; maximo < 10; maximo++)
        {
            printf("los libros son : %s",libros[maximo]);
        }
        
    
    }
 
    }
    
    return 0;
}