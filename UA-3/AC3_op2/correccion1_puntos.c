#include <stdio.h>

void sumarPuntos(int *puntos, int compra) {//asteriscos para llamar la funcion 
    *puntos = *puntos + compra / 1000;//faltaban los astericos para llamar la funcion 
}

int main(void) {
    int puntos = 0, compra, i;//en el main no van asteriscos 
    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
        scanf("%d", &compra);//mismo &
        sumarPuntos(&puntos, compra);//fataba y me equivoque de lugar 
    }
    printf("Puntos acumulados: %d\n", puntos);//le puse aqui un & que no hiba 
    return 0;
}
