//horas de estudio a la semana
/*registrar horas dee estudio de 3 estudiantes de lunes a jueves con la idea de 
que se digite el nombre y las horas de cada dia 
se debe mostar una tabla con el total de cada estudiante , quien estudio mas , dia con mas horas y buscar a ujna persona del grupo por su nombre */

#include<stdio.h>
#include<string.h>

//definicion de constantes 

#define EST 3//fila 
#define DIAS 4//columna ambas de matriz
int main (void){
//arreglo de cadenas para los 3 nombre 
char nombre[EST][15];
//matris de horas osea 3 filas para estudiantes y cuatro 4 columnas para los dias
int horas[EST][DIAS];
//areglo de cadenas con los nombres cortos de los dias 
char dias[DIAS][4]={"lun","mar","mier","jue"};
//indices de filas y columnas 
int e,d;
//arreglo total por estudiante, total [e] es la suma de la fila e
int total[EST];
//variable para el mejor
int mejor;
//acumulador de la columna ()horas del grupo en un dia 
int sumaDia;
//suma mayor del dia
int sumaMayor;
//posicion dia con mas horas
int diaMejor;
//cadena del nombre a buscar
char buscado[15];
//posicion donde aparece el mejor  buscado
int encontrado;
//lectura  con los for anidados
//ciclo externo : una vuelta por estudiante 
for (e = 0; e < EST; e++)
{
    /* pedir el nombre del estudiante */
    printf("nombre del estudiante %d:",e+1);
    //guardar una palabra en la fila de nombre 
    scanf("%14s",nombre[e]);
    //ciclo interno una vuelta por dia(columna) de la fila
    for (d = 0; d < DIAS; d++)
    {
        /* pedir horas del dia  */
        printf("horas del dia %s:",dias[d]);
        scanf("%d",horas[d]);
    }
    
}
//encabezado de la palabra nombre
printf("\n%-8s","nombre" );
//for para recorrer los dias 
for (d = 0; d < DIAS; d++)
{
    /* muestra cada dia */
    printf("%5s",dias[d]);
    //ultima colummna y salto de linea
    printf("%7s\n","total");

    //una fila de la tabla por estudiante
    for (e = 0; e < EST; e++)
    {
        /* reinicia el total de la fila*/
        total[e]=0;
        printf ("%-8s" , nombre[e]);

        //recorre la columna de la fila e
        for (d = 0; d < dias; d++)
        {
            /* mostrar horas de la celda  */
            printf("%5d",horas[e][d]);
            //sumar la celda total
            total[e]+=horas[e][d];
            printf("%7\n",total[e]);
    
        
        }

    }
    //mostrar el total 
            printf("%7d\n",total[e]);
}
//mayor del arreglo total
//supone que el primero estudio mas 
mejor=0;
//recorre las demas filas d estudiantes)(posiciones 1 y 2)
for (e = 0; e < EST; e++)
{
    /* compara totales */
    if (total[e]>total[d])
    {
        /* el mejor */
        mejor=e;

        //muestra quien estudio mas 
        printf("\nestudio mas :%s (%d horas)\n",nombre[mejor],total[mejor]);
        //dia con mas horas
        sumaMayor=0;
        diaMejor=0;
        
        
    }
    
}
for (d = 0; d < DIAS; d++){
            /* reinicia el acumulador */
            sumaDia=0;
            //recorre filas de esa columna
            for (e = 0; e < EST; e++){
                /* suma celda */
                sumaDia+=horas[e][d];
                //comparar  suma del dia con la mayor
                if (sumaDia>sumaMayor)
                {
                    /* guarda la nueva mayor */
                    sumaMayor=sumaDia;
                    //guardar la posicion 
                    diaMejor=d;
                }
                
            }
            
        }
        //mostrar el dia con mas horas 
        printf("dia  con mas horas : %s(%d) horas)\n",dias[diaMejor],sumaMayor);

        //busqueda por nombre
        //pedir el nombre a buscar
        printf("buscar estudiante :");
        //lee la palabra
        scanf("%14s",buscado);
        //marca que todavia no aparece 
        encontrado=-1;
        //recorrer los nombres
        for ( e = 0; e < EST; e++)
        {
            /* compara las cadenas usando strcmp */
            if (strcmp(buscado,nombre[e]==0))
            {
               encontrado=e;
            }
            if (encontrado>=0)
            {
                /* resultado */
                printf("%s estudio %d horas \n",nombre[encontrado],total[encontrado]);
            }
            else
            printf("%s no esta en la lista \n",buscado);
        }
        return 0;
}





