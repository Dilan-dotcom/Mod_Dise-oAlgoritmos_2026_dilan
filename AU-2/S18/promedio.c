//generador de promedio de notas 

#include <stdio.h>
int main (void){
    //3 notas de entrada
    int nota1 , nota2 , nota3 , suma ;//ejm 80,75,90
    //resultado para comparar 
    double promBien , promMal ;
    //entrada de datos (las notas )
    printf("digite 3 notas :");
    scanf("%d %d %d", &nota1, &nota2 , &nota3);
    //procesos = suma de notas 
    suma=nota1 + nota2 + nota3;

    //int/int =division entera ejm 245/3=81 usualmente se realiza con bumeros reales pero en este ejercicio practicamos usando numeros enteros y que no suelten decimales en este caso no importa 
    promMal=suma/3;
    //double convierte suma a 245.0 antes de dividir ->81.666666......
    promBien = (double) suma/3;

    //salidas : sin castin 81.0 y con castin 81.67

    printf("sin casting :%.2f\n", promMal);
    printf("con casting :%.2f\n", promBien);
}