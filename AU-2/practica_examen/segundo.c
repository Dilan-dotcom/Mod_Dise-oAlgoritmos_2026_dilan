#include <stdio.h>
#include <string.h>

int main(void) {
    // Declaración de variables y arreglos
    char nombre[50];               // Almacena el nombre completo del colaborador
    char criterios[3][30] = {"puntualidad", "calidad", "trabajo en equipo"     };                                                     // Arreglo de cadenas con los nombres de los tres criterios
    float puntajes[3];             // Arreglo para almacenar el puntaje de cada criterio use float con menos espacios
    float suma = 0;                // Acumulador para sumar los tres puntajes
    float promedio = 0;            // Almacena el promedio de los puntajes
    int posMin = 0;               // Almacena la posición del puntaje más bajo en el arreglo

    printf("=== Evaluacion de desempeno ===\n");
    
    // Solicitar el nombre del colaborador (permite espacios)
    printf("Nombre del colaborador: ");
    scanf(" %[^\n]", nombre);

    // Ciclo para pedir y validar el puntaje de cada criterio
    for (int i = 0; i < 3; i++) {
        do {
            printf("Puntaje de %s (0 a 10): ", criterios[i]);
            scanf("%f", &puntajes[i]);
            
            // Validar si el puntaje está fuera del rango permitido
            if (puntajes[i] < 0 || puntajes[i] > 10) {
                printf("Puntaje invalido, debe estar entre 0 y 10\n");
            }
        } while (puntajes[i] < 0 || puntajes[i] > 10);
        
        // Acumular el puntaje válido
        suma += puntajes[i];
    }

    // Calcular el promedio de los tres criterios
    promedio = suma / 3.0;

    // Buscar el puntaje más bajo guardando su posición en el arreglo
    for (int i = 1; i < 3; i++) {
        if (puntajes[i] < puntajes[posMin]) {
            posMin = i;
        }
    }

    // Mostrar los resultados en pantalla
    printf("\nColaborador: %s\n", nombre);
    printf("Promedio: %.2f\n", promedio);

    // Determinar y mostrar el nivel de desempeño según el promedio
    if (promedio >= 9) {
        printf("Nivel: EXCELENTE\n");
    } else if (promedio >= 7) {
        printf("Nivel: BUENO\n");
    } else {
        printf("Nivel: NECESITA MEJORAR\n");
    }

    // Mostrar el criterio con el puntaje más bajo usando la posición encontrada
    printf("Puntaje mas bajo: %s (%.1f)\n", criterios[posMin], puntajes[posMin]);

    return 0;
}