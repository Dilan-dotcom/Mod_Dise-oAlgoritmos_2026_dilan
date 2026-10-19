/* 
   Archivo: horas.c
 Control de horas de estudio de 3 estudiantes durante 4 días de la semana,
mostrando una tabla formateada, totales, quién estudió más, el día con más horas y búsqueda por nombre.
Qué se logra: Combinar matrices, arreglos paralelos, acumuladores y strcmp.
*/

#include <stdio.h>
#include <string.h> // Necesario para strcmp

#define ESTUDIANTES 3 // Constante para el número de filas (estudiantes)
#define DIAS 4        // Constante para el número de columnas (días: Lun, Mar, Mie, Jue)

int main(void) {
    // Declaración de arreglos y matriz
    char nombres[ESTUDIANTES][20]; // Matriz de caracteres para guardar los nombres de cada estudiante
    int horas[ESTUDIANTES][DIAS];  // Matriz numérica de 3x4 para las horas de estudio
    int totales[ESTUDIANTES];      // Arreglo unidimensional para guardar el total de horas de cada estudiante
    int horasDias[DIAS] = {0};     // Arreglo acumulador para sumar las horas totales de todo el grupo por cada día
    
    int f, c;                      // Variables contadoras para filas (f) y columnas (c)
    char buscado[20];              // Variable para almacenar el nombre que el usuario quiere buscar
    int encontrada = -1;           // Bandera para la búsqueda (-1 significa que no se ha encontrado)

  
    for (f = 0; f < ESTUDIANTES; f++) {
        printf("Nombre del estudiante %d: ", f + 1);
        scanf("%s", nombres[f]); // Lee el nombre del estudiante (una sola palabra, sin '&')

        printf("Horas de Lun: ");
        scanf("%d", &horas[f][0]); // Lee el valor para el lunes (columna 0)
        printf("Horas de Mar: ");
        scanf("%d", &horas[f][1]); // Lee martes (columna 1)
        printf("Horas de Mie: ");
        scanf("%d", &horas[f][2]); // Lee miércoles (columna 2)
        printf("Horas de Jue: ");
        scanf("%d", &horas[f][3]); // Lee jueves (columna 3)
    }

    
    printf("\nNombre\tLun\tMar\tMie\tJue\tTotal\n");
    
    int maxHorasEstudiante = -1; // Variable para rastrear la mayor cantidad de horas de un estudiante
    int idxMasEstudio = 0;       // Índice del estudiante que más estudió

    for (f = 0; f < ESTUDIANTES; f++) {
        totales[f] = 0; // Reiniciamos el acumulador para cada estudiante individual
        printf("%-8s", nombres[f]); 
        
        for (c = 0; c < DIAS; c++) {
            printf("\t%d", horas[f][c]);     // Imprime la hora de la celda actual
            totales[f] += horas[f][c];       // Acumula el total semanal del estudiante actual
            horasDias[c] += horas[f][c];      // Acumula el total de todo el grupo para el día 'c'
        }
        printf("\t%d\n", totales[f]); // Imprime el total de la fila al final

    
        if (totales[f] > maxHorasEstudiante) {
            maxHorasEstudiante = totales[f];
            idxMasEstudio = f; 
        }
    }

    // PASO 3: IDENTIFICAR EL DÍA CON MÁS HORAS ACUMULADAS
    int maxHorasDia = -1;
    int idxDiaMax = 0;
    char *nombresDias[DIAS] = {"Lun", "Mar", "Mie", "Jue"}; // Arreglo auxiliar para mostrar el nombre del día
    
    for (c = 0; c < DIAS; c++) {
        if (horasDias[c] > maxHorasDia) {
            maxHorasDia = horasDias[c];
            idxDiaMax = c; // Guardamos la columna del día más lluvioso/estudioso
        }
    }

    // Mostramos los ganadores globales del grupo
    printf("\nEstudio mas: %s (%d horas)\n", nombres[idxMasEstudio], maxHorasEstudiante);
    printf("Dia con mas horas: %s (%d horas)\n", nombresDias[idxDiaMax], maxHorasDia);

 
    printf("\nBuscar estudiante: ");
    scanf("%s", buscado);

    for (f = 0; f < ESTUDIANTES; f++) {
        // strcmp compara el nombre guardado con el buscado; si da 0, son idénticos
        if (strcmp(nombres[f], buscado) == 0) {
            encontrada = f; // Guardamos la fila donde se encontró
            break;          // Rompemos el ciclo porque ya lo encontramos
        }
    }

  
    if (encontrada >= 0) {
        printf("%s estudio %d horas\n", nombres[encontrada], totales[encontrada]);
    } else {
        printf("Estudiante no encontrado en la lista.\n");
    }

    return 0; // Fin del programa con éxito