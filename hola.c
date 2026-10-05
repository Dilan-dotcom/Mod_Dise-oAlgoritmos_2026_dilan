//Hola.c - Prueba del entorno de la unidad de aprendizaje 2 
#include <stdio.h>
int main(void) {
    int edad;
    //mostrar mensaje por pantalla
    printf("Entorno listo para la UA2\n");
    //pedir elementos (un nunero)
    printf("Digite su edad: ");
    scanf("%d", &edad);

    //mostar la salida
    printf("Edad registrada: %d\n", edad);

    return 0;
}