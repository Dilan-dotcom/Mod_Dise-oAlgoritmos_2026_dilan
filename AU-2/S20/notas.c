//arreglo de notas ahora las notas se guardan 
#include <stdio.h>
#include <stdlib.h>
#define N 5
int main (void){
    double notas[N];//definicion del arreglo
    double suma = 0, promedio, mayor, menor;
    int i;

    //lectura de datos
    for (i = 0; i < N; i++){
        //validacion se puede usar el while y do while 
        do
        {
            printf("Nota %d ( 0 a 100):",i+1);
            scanf("%lf", &notas[i]);//guuarda en notas 
        } while (notas[i]<0|| notas[i]>100);//la condicion que suma
        suma += notas[i];
    }
    promedio = suma / N;
    //mayor y menor y se comienza desde la priera nota y se compara con el resto
    mayor = notas[0];//Recuerda que la primera nota esta en la casilla cero
    menor = notas[0];

    for ( i = 1; i < N; i++){
        if (notas[i]>mayor){
            mayor = notas[i];
        }
    }

for ( i = 1; i < N; i++){
        if (notas[i]<menor){
            menor = notas[i];
        }

    }
    
    printf("Promedio : %.f\n", promedio);
    printf("Mayor : %.f\n", mayor);
    printf("Menor : %.f\n", menor);

    //segundo recorrrido
    printf("sobre el promedio :");
    for (i = 0; i < N; i++)  {
        if (notas[i]>promedio){
            printf("%.lf", notas[i]);
        }
    
    
    }
    printf("\n");

    system("pause");
    return 0;
}