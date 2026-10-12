//tabla de multiplicar RESUELVE  LA TABLA DEL 7

#include <stdio.h>

//centila se puede definir como una constante
#define CENTINELA 0 //el cero indica que no hay tablast
int main (void){
    ///declaracion variables 
    int numero, i;
    int tablas = 0;

    //lectura previa el primer numero se lee antes del while
    printf("Numero de la tabla (0 para terminar)");
    scanf("%d", &numero);

    //while con cenntinela lo que hara es que se repite bmientras el numero no sea cero

    while  (numero != CENTINELA){
        //empezamos con un for anidado que dara 10 vueltas por cada numero -> 1=1,2,3,4....10
        for (i = 1; i <= 10;i++){
            //2d% alimea 2 espacios  ->
            printf("%d x %2d  =%2d\n",numero,i ,numero * i);
}
            tablas++;//cuenta la tabla mostrada -> 1 luego 2 y asi sucesivamente
            //siguiente dato al final del cuerpo ->3 , luego 0

            printf("Numero de la tabla(0 para terminar): ");
            scanf("%d",&numero);
        
    }
    //despues del while (se digito el cero) tablas mostradas = 2
    printf("Tablas mostradas :%d\n", tablas);
    return 0;
}