#include <stdio.h>

int main(void) {
    // Variables
    int filas, i, j;

    // Entrada
    printf("Cantidad de filas: ");
    scanf("%d", &filas);

    // Proceso y Salida: Patrón de asteriscos (for anidados)
    for (i = 1; i <= filas; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Proceso y Salida: Patrón de números (for anidados)
    for (i = 1; i <= filas; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}