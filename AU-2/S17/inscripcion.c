//inscripcion .c ejercicio viene de algoritmo inscripcion cursos

#include <stdio.h>
#define COSTO_MODULO 15000.0;

int main (void){
    //cadenas : arreglos de caracteres
    char nombre[30];
    char cedula[15];
    int cantidadModulos;
    double total;
    //logica en C es diferente a pseint C 1 V Y 0 F(osea uno verdad y 0 mentira o falso )
    int tieneDescuento;
    //entrada de datos
    //pide y almacena el nombre . el tipo char no usa "&" para almacenar con scanf"
    printf("Ingrese dsu nombre :");
    scanf("%29s", nombre);

    //leer la cedula como texto
    printf("Ingrese su cedula :");
    scanf("%14s", cedula);

    //Leer la cantida de modulos pedir y almacenar

    printf("Cantidad de modulos :");
    scanf("%d", &cantidadModulos);

    //procesos total = 3*15000 ->45000

    total = cantidadModulos * COSTO_MODULO ;
    //a la pregunta tiene desuento se responde con 1 para si o 0 para no
    tieneDescuento = cantidadModulos >= 3;

    //salidas
    printf("Estudiante : %s (%s)\n", nombre , cedula);//se usan ambos %s y (%s) para 
    printf("Total de inscripcion : %.2f \n", total);
    printf("Aplica para descuento ? : %d (1 = si , 0 = no) \n", tieneDescuento);
    return 0;
}