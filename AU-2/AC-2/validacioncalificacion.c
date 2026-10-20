/*Un centro educativo necesita automatizar el cálculo de notas finales. Escriba un programa en C 
que:
1. Reciba el nombre completo del estudiante.
2. Reciba tres calificaciones de 0 a 100 y las guarde en un arreglo. Cada calificación fuera de 
rango se rechaza con un mensaje y se vuelve a pedir.
3. Calcule el promedio de las tres calificaciones y busque la calificación más alta recorriendo el 
arreglo.
4. Determine la condición: APROBADO si el promedio es 70 o más; EN RIESGO si es 60 o más, 
pero menor que 70; NO APROBADO si es menor que 60. Guarde la condición en una cadena.
5. Muestre el nombre, las tres calificaciones, el promedio (dos decimales), la calificación más alta y 
la condición//*/
#include <stdio.h>
#include <string.h>

#define NOTAMIN 0   //limite minimo      
#define NOTAMAX 100   //limite maximo     
#define APROBADO 70 //minimo para aprobar
#define RIESGO 60   //promedio minimo para estar en riesg

int main(void) {
    //variables nota cambien todo por float porque recorde que pesa menos y las hice individuales 

    char nombre[30];         
    float notas[3];           
    float sumaNotas = 0;   
    float promedio = 0;    
    float notAlta = 0;    
    char condicion[20];       
    int i;
    //entrada de datos
    printf("=== Calificaciones del estudiante ===\n");
    do
    {
    printf("Nombre del estudiante : ");
    fgets(nombre,sizeof(nombre),stdin);
    nombre[strcspn(nombre,"\n")]='\0';
    if (strlen(nombre)==0)
    {
        printf("Nombre invalido no se puede poner un nombre vacio : \n");
    }
    } while (strlen(nombre)==0);
// 2. Lectura y validación de las 3 calificaciones en un arreglo con for + do...while
    for (i = 0; i < 3; i++) {
        do {
            printf("Calificacion %d (0 a 100): ", i + 1);
            scanf("%f", &notas[i]);
            if (notas[i] < NOTAMIN || notas[i] > NOTAMAX) {
                printf("Error: Calificacion fuera de rango. Intente de nuevo.\n");
            }
        } while (notas[i] < NOTAMIN || notas[i] > NOTAMAX);

        sumaNotas += notas[i]; // Acumulación para el promedio
    }
    //calculo promedio
    promedio = sumaNotas / 3;

    //calculo de la nota alta 
    notAlta=notas[i];
    for ( i = 0; i < 3; i++){
        if (notas[i]>notAlta)
        {
            notAlta=notas[i];
        }
    }
    //muestrs la condicion del estudiante con strcpy

    if (promedio >=APROBADO) {
        strcpy(condicion, "APROBADO");
    } else if (promedio >= RIESGO) {
        strcpy(condicion, "EN RIESGO");
    } else {
        strcpy(condicion, "NO APROBADO");
    }
    
    //salida de datos 
    printf("===Resultado===\n");
    printf("Estudiante: %s\n", nombre);
    for (i = 0; i < 3; i++) {
        printf("Calificacion %d: %.1f\n", i + 1, notas[i]);
    }//esta linea gera las notaas hasta la tercer
    printf("\n");
    printf("\n");
    printf("\n");
    //fin del programa
    return 0;
}