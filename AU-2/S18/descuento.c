//10% de descuento para compras de 50000 o mas 
#include <stdio.h>
int main (void){

    double compra,  descuento,  total;

    printf("Ingrese el monto comprado :");
    scanf("%lf", &compra);

    if (compra >=50000){
        descuento=compra*0.10;
    }else{
        descuento=0;
    }
    total=compra-descuento;

    printf("Total comprado :%.2f\n",compra);
    printf("Total descuento :%.2f\n",descuento);
    printf("Total a pagar: %.2f\n",total);
    return 0;
}