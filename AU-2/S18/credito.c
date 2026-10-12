// Regla: capacidad de pago Y sin deudas Y (antigüedad >= 1 O fiador)

#include <stdio.h>
int main (void){

    double salario , cuota ;
    int antiguedad ;
    char respDeudas , respFiador ;
    int capacidadPago, tieneDeudas, tieneFiador, aprobado;

    printf("salario mensual :");
    scanf("%lf", salario);

    printf("cuota mensual :");
    scanf("%lf", cuota);

    printf("tiene deudas atrasadas(S/N) :");
    scanf("%29s", salario);

    printf("años de antiguedad laboral :");
    scanf("%d", antiguedad);

    printf("tiene fiador(S/N) :");
    scanf("%29s", respFiador);

    capacidadPago=salario>=cuota*3;
    tieneDeudas=(respDeudas) = "S";
    tieneFiador =(respFiador) = "S";



}