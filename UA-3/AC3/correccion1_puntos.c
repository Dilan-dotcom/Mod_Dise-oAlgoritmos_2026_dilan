#include <stdio.h>

void sumarPuntos(int *puntos, int compra) {
    *puntos = *puntos + compra / 1000;//igual faltaba los puntos porque estan llamando a una funcion 
    printf("Puntos acumulados: %d\n", puntos);//corri este printf aqui para saber si estaba haciento la suma 
}

int main(void) {
    int *puntos = 0, compra, i;//faltaba * para dar direccion 
    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
        scanf("%d", &compra);//faltaba & y daba un error de segmentacion 

        sumarPuntos(puntos, compra);
    }
    printf("Puntos acumulados: %d\n", &puntos);//faltaba &
    return 0;
}
