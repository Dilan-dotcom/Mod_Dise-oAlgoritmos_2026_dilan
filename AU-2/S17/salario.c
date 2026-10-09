//algoritmo para recibir un pago semanal 
#include<stdio.h>

int main (void){
    //definicion de constante
    const double tarifaHora = 2500;
    double horas, bruto, deduccion, neta;
    char nombre [20] ;
    //entrada de datos 
    printf("Ingrese el nombre del trabajador");
    scanf("%19s",nombre);

    printf("Ingrese las horas trabajadas");
    scanf("%lf", &horas);
    //operaciones
    bruto = horas * tarifaHora;
    deduccion = bruto * 0.10;
    neta=bruto-deduccion;

    //datos de salida
    printf("El tarbajador : %s\n", nombre );
    printf("Total bruto: %.2f \n", bruto);
    printf("Total deduccion: %.2f \n", deduccion);
    printf("Total salario: %.2f \n", neta);
    return 0;
}