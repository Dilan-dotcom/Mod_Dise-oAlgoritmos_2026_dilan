#include <stdio.h>

// Constantes
#define LIMITE 48
#define RECARGO 1.5
#define CENTINELA -1

int main(void) {
    // Variables y contadores
    int horas, tarifa, personas = 0, conExtra = 0, horasExtra;
    float pago, totalPlanilla = 0.0;

    
    printf("Horas de la semana (-1 para terminar): ");
    scanf("%d", &horas);

    // Proceso (Ciclo while con centinel
    while (horas != CENTINELA) {
        printf("Tarifa por hora: ");
        scanf("%d", &tarifa);

        if (horas > LIMITE) {
            horasExtra = horas - LIMITE;
            pago = (LIMITE * tarifa) + (horasExtra * tarifa * RECARGO);
            conExtra++;
        } else {
            pago = horas * tarifa;
        }

        printf("Pago: %.2f\n", pago);
        totalPlanilla += pago;
        personas++;

        printf("Horas de la semana (-1 para terminar): ");
        scanf("%d", &horas);
    }

    // Salida final
    printf("Personas: %d\n", personas);
    printf("Con horas extra: %d\n", conExtra);
    printf("Total de la planilla: %.2f\n", totalPlanilla);

    return 0;
}