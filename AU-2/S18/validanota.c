//algoritmo para validar una nota 

#include <stdio.h> 

int main(void) {
    // Definimos la variable 'nota' como un número entero 
    double nota;
    // La estructura "Repetir" de PSeInt se escribe en C como "do {"(lo appuntaste porque se te olvido )
    do {
        
        printf("Nota (0 a 100):\n");
        scanf("%lf", &nota);

        // Validamos si la nota está fuera del rango permitido
        // El símbolo || significa O
        if (nota < 0 || nota > 100) {
            printf("Nota invalida\n");
        }

    } 
    while (nota < 0 || nota > 100);

    printf("Nota registrada: %.2f\n", nota);

    return 0; 
}