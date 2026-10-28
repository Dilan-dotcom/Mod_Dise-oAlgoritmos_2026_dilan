// caso integrador de la unidad 2 del curso
// enunciado el sistema registra notas de un grupo de 16 estudiantes
// contiene un menu! 1 .agregar(nota de 0  a 100 y validar eso) 2. ver notas(cada una con aprobadoy si es 70 o mas es arobado y por debajo reprobado)3.estadisticas(promedio el mayor o menor )y que se use cero para salir

#include <stdio.h>
#define MAX 16
// leer nota no recibe datos y devuelve nota valida
double leerNota(void);

// recibe el arreglo y la direccion de la cantidad
void agregarNota(double notas[], int * cantidad);

// mostrar notas recibe el arreglo y la cantidad por valor
void mostrarNotas(const double notas[], int cantidad);

// calcula estadisticas , recibe el arreglo ,la cantidad y los 3 punteros
void calcularEstadisticas(const double notas[], int cantidad, double *promedio, double *mayor, double *menor);

int main(void)
{

    double notas[MAX];

    int cantidad = 0, opcion;
    double promedio, mayor, menor;

    // ciclo para repetir hasta 0
    do
    {
        /* mostararr el menu */
        printf("\n 1. agregar 2. ver notas 3. estadisticas 0. salir\n");

        // pedir la opcione de menu
        printf("opcion: ");
        if (scanf("%d", &opcion) != 1)
        {
            int caracter;
            while ((caracter = getchar()) != '\n' && caracter != EOF)
            {
            }
            if (caracter == EOF)
            {
                break;
            }
            printf("opcion invalida\n");
            continue;
        }

        switch (opcion)
        {
        case 1:
            agregarNota(notas, &cantidad);
            break; // sale del switch

        // lista de notas
        case 2:
            mostrarNotas(notas, cantidad);
            break;

        case 3:
            // estadisticas
            if (cantidad == 0)
            {
                printf("No hay notas registradas\n");
            }
            else
            {
                // hacer la llamada que devuelva 3 resultados
                calcularEstadisticas(notas, cantidad, &promedio, &mayor, &menor);
                printf("promedio :%0.f mayor: %.1f menor :%.1f\n", promedio, mayor, menor);
            }
            break;

        case 0:
            printf("Fin del programa\n");
            break;

        // cualquier otra opcion que no sea menu
        default:
            printf("opcion invalida\n");
        }
        // repita mientras no se elija cero

    } while (opcion != 0);

    /// termine ccon main
    return 0;
}
//definicion de leer nota hasta que nota este entre 0  y 100
double leerNota(void){
    double nota;
    //ciclo de validacion 
    do
    {
        /* pedir nota */
        printf("nota (0 a 100):");
        if (scanf("%lf", &nota) != 1)
        {
            int caracter;
            while ((caracter = getchar()) != '\n' && caracter != EOF)
            {
            }
            printf("entrada invalida\n");
            if (caracter == EOF)
            {
                return 0;
            }
            nota = -1;
        }
        //repite si esta fuera del rango
    } while (nota<0||nota>100);
    return nota;
    
}

//definicion agregar nota 
void agregarNota(double notas[], int*cantidad){
    //revisar si esta vacio
    if (*cantidad<MAX)
    {
        /* guarda la nota  */
        notas[*cantidad]=leerNota();
        //aumentar cantidad
        (*cantidad)++;
    }else
    {
        printf("el grupo ya tiene %d notas\n", MAX);
    }
}

//definicion para mostrar notas

void mostrarNotas(const double notas[],int cantidad){

    //indice local para recorrer el arreglo
    int i;
    for ( i = 0; i < cantidad; i++)
    {
        /* mostrar nota y condicion  */
        printf("%2d. %5.1f %s\n", i + 1, notas[i], notas[i] >= 70 ? "aprobado" : "reprobado");

    }
}

//definicion de calcular estadaisticas 

void calcularEstadisticas(const double notas[], int cantidad , double *promedio,double*mayor, double*menor){
    //acumulador local
    double suma =0;
    //indice local para recorrer el arreglo
    int i;
    //ss supone que la primera nota  es la mayor

    *mayor = notas[0];
    *menor = notas[0];
    for ( i = 0; i < cantidad; i++)
    {
        /* suma la nota  */
        suma += notas[i];
        //compara con el mayor
        if (notas[i]>*mayor)
        {
            /* guarda el nuevo mayor */
            *mayor = notas[i];

        }
        if (notas[i] < *menor)
        {
            *menor = notas[i];
        }
        
    }
    ///calcular el promedio
    *promedio=suma/cantidad;

}