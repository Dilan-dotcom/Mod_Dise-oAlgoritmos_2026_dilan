//practica de notas en c

#include <stdio.h>
#include <string.h>

#define MAXIMOESTUDIANTE 4
int main(void) {
    // Declaracion de la matriz de notas (4 filas por 3 columnas) 
    // y la matriz de nombres (4 filas por hasta 30 caracteres)
    int notas[4][3];
    char nombres[4][30];
    int f, d;
    float prom[4];// Variables de control para el mejor promedio
    float mejorProm = 0;
    int posMejor = 0;
    float sumaEst=0;// Reiniciamos el acumulador para cada nuevo estudiante inicializando esta variable 
    // Variables para la busqueda final del estudiante
    char buscar[15];
    int encontrado = 0;
    char condicion[15];

for ( f = 0; f < MAXIMOESTUDIANTE; f++)//el limite de estudiantes 
{
    printf("Nombre del estudiante %d: ", f + 1);
        scanf("%s", nombres[f]);

    //ciclo interno que recorre las 3 notas 
        for ( d = 0; d < 3; d++)
        {
            do
        {
            printf("  Nota %d de %s (0 a 100): ", d + 1, nombres[f]);
                scanf("%d", &notas[f][d]);
                //rango de error 
                if (notas[f][d] < 0 || notas[f][d] > 100)
                {
                    printf("  Error: Nota invalida.\n");
                }
                
        } while (notas[f][d] < 0 || notas[f][d] > 100);
        //recordar la misma condicion de if va en el while en este caso 
        }
    }

    //sacar y guardar el promedio de cada estudiante 
    for (f = 0; f < MAXIMOESTUDIANTE; f++)
    {
        for (int d = 0; d < 3; d++) {
            sumaEst += notas[f][d]; // Sumamos las 3 notas de la fila i
        }
    }
    
}
