// practica de notas en c

#include <stdio.h>
#include <string.h>

#define MAXIMOESTUDIANTE 4

int main(void) {
    // Declaracion de la matriz de notas y nombres
    int notas[MAXIMOESTUDIANTE][3];
    char nombres[MAXIMOESTUDIANTE][30];
    
    int f, d;
    float prom[MAXIMOESTUDIANTE];
    float mejorProm = 0;
    int posMejor = 0;
    
    // Variables para la busqueda final del estudiante
    char buscar[30];
    int encontrado = 0;
    char condicion[20];
    float evaluaProm;

    //  Pedir nombres y notas con validacion ---
    for (f = 0; f < MAXIMOESTUDIANTE; f++) {
        printf("Nombre del estudiante %d: ", f + 1);
        scanf("%s", nombres[f]);

        // Ciclo interno que recorre las 3 notas
        for (d = 0; d < 3; d++) {
            do {
                printf("  Nota %d de %s (0 a 100): ", d + 1, nombres[f]);
                scanf("%d", &notas[f][d]);
                
                // Rango de error
                if (notas[f][d] < 0 || notas[f][d] > 100) {
                    printf("  Error: Nota invalida.\n");
                }
            } while (notas[f][d] < 0 || notas[f][d] > 100);
        }
    }

    //  Sacar y guardar el promedio de cada estudiante (por filas) ---
    for (f = 0; f < MAXIMOESTUDIANTE; f++) {
        float sumaEst = 0; // Reiniciamos el acumulador para cada estudiante
        
        for (d = 0; d < 3; d++) {
            sumaEst += notas[f][d]; // Sumamos las 3 notas del estudiante
        }
        
        prom[f] = sumaEst / 3.0; // Guardamos el promedio individual
        
        // Encontramos el mejor promedio del grupo
        if (f == 0 || prom[f] > mejorProm) {
            mejorProm = prom[f];
            posMejor = f; // Guardamos la posicion exacta del mejor estudiante
        }
    }

    // Mostramos al mejor estudiante
    printf("\nMejor estudiante: %s con %.2f de promedio\n\n", nombres[posMejor], mejorProm);

    //  Calcular el promedio de cada evaluacion (por columnas) ---
    for (int j = 0; j < 3; j++) {
        float sumaEvalua = 0; // Ahora esta variable si se usa correctamente aqui
        
        for (f = 0; f < MAXIMOESTUDIANTE; f++) {
            sumaEvalua += notas[f][j]; // Sumamos la columna j para todos los estudiantes
        }
        
        evaluaProm = sumaEvalua / (float)MAXIMOESTUDIANTE;
        printf("Promedio de la evaluacion %d: %.2f\n", j + 1, evaluaProm);
    }

    //  Buscar un estudiante por nombre 
    printf("\nBuscar estudiante: ");
    scanf("%s", buscar); // Pedimos el nombre que el usuario quiere buscar
    
    // Recorremos los nombres del arreglo para compararlos uno por uno
    for (f = 0; f < MAXIMOESTUDIANTE; f++) {
        // strcmp compara dos cadenas: si retorna 0, son exactamente iguales
        if (strcmp(nombres[f], buscar) == 0) {
            encontrado = 1; // Indicamos que si lo encontramos
            
            // Determinamos si esta aprobado (promedio >= 70) o no
            if (prom[f] >= 70.0) {
                strcpy(condicion, "APROBADO");
            } else {
                strcpy(condicion, "NO APROBADO");
            }
            
            // Mostramos el resultado del estudiante encontrado
            printf("Resultado  %s: Promedio %.2f - %s\n", nombres[f], prom[f], condicion);
            break; // Rompemos el ciclo porque ya lo encontramos
        }
    }
    
    // Si despues de revisar todo el arreglo no se encontro
    if (encontrado == 0) {
        printf("El estudiante '%s' no se encuentra registrado.\n", buscar);
    }

    return 0;
}