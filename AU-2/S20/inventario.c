#include <stdio.h>

// Constante para terminar el ciclo
#define CENTINELA 0

int main(void) {
    // Variables
    int codigo;
    int unidades;
    float precio, totalInventario = 0.0;

    // Entrada inicial (Lectura previa)
    printf("Codigo (0 para terminar): ");
    scanf("%d", &codigo);

    // Proceso (Ciclo while con centinela)
    while (codigo != CENTINELA) {
        
        // Evaluamos los códigos disponibles usando if-else básico
        if (codigo == 310) {
            // Simulamos los datos del producto encontrado
            printf("Cafe 1 kg: 12 unidades a 4500.00\n");
            
            // Calculamos el valor de este producto (unidades * precio) y lo sumamos al acumulador
            totalInventario += 12 * 4500.00;
            
        } else {
            // Si el código no coincide con ninguno registrado
            printf("Codigo %d no encontrado\n", codigo);
        }

        // Siguiente lectura previa para continuar o salir del ciclo
        printf("Codigo (0 para terminar): ");
        scanf("%d", &codigo);
    }

    // Salida final
    printf("Valor del inventario: %.2f\n", totalInventario);

    return 0;
}