//10% de descuento para compras de 50000 o mas 
#include <stdio.h>
int main (void){

    double compra ,  descuento,  total;

    printf("Ingrese el monto comprado :");
    scanf("lf\n",compra);

    if (compra >=50000){
        descuento=compra*0.10;
    }else{
        descuento=0;
    }
    total=compra-descuento;

    printf("Total comprado:%f\n",compra);
    printf("Total descuento:%f\n",descuento);
    printf("Total a pagar :%f\n",total);

}