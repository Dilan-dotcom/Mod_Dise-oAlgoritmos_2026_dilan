//circulo.c Practicacon constantes (en este caso PI 3.1416)

#include<stdio.h>
//las constantes se ponen justo despues de el include

#define PI 3.14159265358979 //constante simbolica: el procesador cambia PI por el numero asignado 

int main(void){
    //constante de cadena que no puede cambiar durante el programa
    // se define con const
    const char UNIDAD[] = "cm";

    //variables reales para el radio y los resultados

    double radio, area, perimetro;

    //entrada de datos:lee el radio -> radio = 4
    printf("Radio de circulo(cm):");
    scanf("%lf", &radio);
    //En proceso en C no existe  ^ ; radio al cuadrado  = radio * radio-> 5.27

    area = PI * radio * radio;

    //perimetro = 2 * PI * radio = 23.13

    perimetro = 2 * PI * radio;

    //SALIDA DE DATOS : %.2fmuestra 2 decimales y %s muestra la cadena UNIDAD

    printf("Area : %.2f %s2\n", area , UNIDAD);
    printf("Perimetro: %.2f %s\n", perimetro, UNIDAD);
    return 0;
}


