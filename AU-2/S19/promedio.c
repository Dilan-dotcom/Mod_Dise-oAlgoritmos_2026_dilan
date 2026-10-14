#include <stdio.h>

int main(void) {
    // Variables
    int cantidad, i, nota, suma = 0;
    float promedio;

    // Entrada y validación de la cantidad
    do {
        printf("Cuantas notas (1 a 10): ");
        scanf("%d", &cantidad);
    } while (cantidad < 1 || cantidad > 10);

    // Proceso: recorrido y validación de cada nota
    for (i = 1; i <= cantidad; i++) {
        do {
            printf("Nota %d (0 a 100): ", i);
            scanf("%d", &nota);
        } while (nota < 0 || nota > 100);

        suma += nota;
    }

    promedio = (float)suma / cantidad;

    // Salida
    printf("Suma: %.2f\n", (float)suma);
    printf("Promedio: %.2f\n", promedio);

    return 0;
}