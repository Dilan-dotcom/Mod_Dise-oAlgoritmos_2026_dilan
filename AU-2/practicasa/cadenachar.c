/*   Archivo: manejo cadenas.c
Enunciado: Leer un nombre completo con espacios, copiarlo, unirlo con un sufijo, 
medir su longitud y compararlo usando la biblioteca string.h.
Qué se logra: Aplicar fgets, strcspn, strcpy, strcat, strlen y strcmp.
*/
#include <stdio.h>   // Necesaria para printf, scanf y el comando 'stdin'
#include <string.h>  // Necesaria para fgets, strcspn y strcmp
int main(void) {
    char nombre[40];    // Arreglo de tipo char para almacenar el nombre (hasta 39 letras + '\0')
    char copia[40];     // Arreglo secundario para hacer copias o modificaciones

    // ENTRADA DE DATOS
    printf("Digite su nombre completo: ");
    // fgets lee la línea completa incluyendo espacios desde el teclado (stdin)
    fgets(nombre, sizeof(nombre), stdin);

    // Limpieza del Enter: busca la posición de '\n' y la reemplaza por el carácter nulo '\0'
    nombre[strcspn(nombre, "\n")] = '\0';

    // PROCESO Y MANIPULACIÓN DE CADENAS
    // strcpy copia el contenido de nombre dentro de la variable 'copia' (Nunca usar =)
    strcpy(copia, nombre);

    // strcat concatena (agrega) el texto de la derecha al final de la variable copia
    strcat(copia, " (Activo)");


    printf("\n--- RESULTADOS ---\n");
    printf("Nombre original guardado: %s\n", nombre);
    printf("Texto modificado (copia): %s\n", copia);
    
    // strlen cuenta los caracteres reales sin contar el '\0'
    // Usamos casting '(int)' para imprimirlo sin problemas con el formato %d
    printf("El nombre tiene %d caracteres.\n", (int)strlen(nombre));

    // strcmp compara si 'nombre' es exactamente igual al texto "Ana Mora"
    // Si devuelve 0, significa que son idénticos
    if (strcmp(nombre, "Ana Mora") == 0) {
        printf("Coincidencia exacta: Es Ana Mora.\n");
    } else {
        printf("No es Ana Mora.\n");
    }

    return 0; // Finaliza el programa con éxito
}