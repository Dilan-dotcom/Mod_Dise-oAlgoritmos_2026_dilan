//temperaturas c
/*programa que recibe la temperatura maxima de 7 dias consucutivos junto con el nombre del dia en cuestion  y se debe calcular el promedio del temperatura y el dia mas caluroso junto con una lista de dias que superaron el promedio*/

#include <stdio.h>  //Entradas y salidas
#include <string.h> //Manipulación de texto

    //Definir constantes
    #define MAXDIAS 7//maximo de dias
    #define MAXITEMP 45 //maximo de temperaturas 
    #define MINTEMP 0//limite minimo de temperaturas 

int main(void){
//variables 

char Dias[MAXDIAS][6] = {"Lun", "Mar", "Mie", "Jue"," VIer","Sab","Dom"};//maximo de 7 dias con capacidad de 5 espacios
double temperaturas[MAXDIAS];
int masCalor=0;
double Prom =0;
int d ;
int cantDias=0;//dias donde  se supero l{a temp maxima}
char sobreProm[MAXDIAS] ;//guarda los valores que guardabnn el promedio 
for (d = 0; d < MAXDIAS; d++){//ciclo for para guardar las temperaturas por dia 
        //pedimos nombre del estudiante
        
    do
    {
        printf("Ingrese la temperatura de dia(0 a 45) %s:", Dias[MAXDIAS] );
        scanf("%lf", &temperaturas[d]); 

        if (temperaturas[d]<MINTEMP||temperaturas[d]>MAXITEMP)
        {
            printf("Error : la temperatura se encuentra o por debajo o excediendo el limite(1 a 45)\n");
        }
        


    } while (temperaturas[d] < MINTEMP||temperaturas[d]>MAXITEMP); 
    }

        //es 1 porque inicializamos la variable arriba 
    for (d = 1; d < MAXDIAS; d++)
    {
        if (temperaturas[d]>temperaturas[masCalor])//actualiza el valor  si el valor anterior es mayor o menor que el nuevo , este se actualiza dependiendo del dato
        {
            masCalor=d;//si la temperatura entrante es mayor a la temperatura del mas calor , mas calor se actualiza 
        }
        
    }
    //sacamos el promedio
    for ( d = 0; d < MAXDIAS; d++)
    {
        Prom+=temperaturas[d];
    }
    Prom=Prom/7;//se deja afuera del for porque el valor de esta operacion entra en un conflicto raro con el prom del for 
    for (d = 0; d < MAXDIAS; d++)
    {
        if( temperaturas[d] > Prom){ //parte calcula si temp d es mayor al promedio la cantidad de dias se suma 
            cantDias++;
            sobreProm[d]=d;
    }
    //salida de datos
    for (d = 0; d< MAXDIAS; d++)
    {
        printf("=====Reporte semanal=====");
    printf("Temperatura del dia %s es:%.1f C\n",Dias[d],temperaturas[d]);
    }
}
    printf("Promedio %.2f C\n",Prom);
    printf("Dia mas caluroso :%s (%.f)C\n",Dias[masCalor],temperaturas[masCalor]);
    for ( d = 0; d < MAXDIAS; d++)
    {
    printf("El sobre prom es %d\n",sobreProm[d]);
    }
    
    
    for (d = 0; d < MAXDIAS; d++)
    {
        printf("%d",cantDias);

    }
    printf ("(%d dias)",cantDias);
    return 0;
}