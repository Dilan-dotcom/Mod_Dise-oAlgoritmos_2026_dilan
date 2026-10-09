//desglose de billetes

#include <stdio.h>
int main (void){
    //definicion de variables 
    int monto , resto , cantidad ;
    //entradas lee monto =47500
    printf("Monto a desglosar :");
    scanf("%d", &monto);

    //procesos division entera entre 47500/ 20000 -> cantidad =2
    cantidad= resto/20000;

    //% es el residuo : 475000 %(mod) 20000->resto=7500
    resto= resto % 20000;
    //muestre -> billetes de  2000 : 2
    printf("Billetes de 2000 : %d\n",cantidad);

    cantidad = resto / 10000;//esto significa 7500 / 5000 = cantidad = 1
    //forma compacta de resto = resto % 10000 -> resto ->7500 
    resto %= 10000;//-> resto =2500
    printf("Billetes de 10000 :%d\n",cantidad);//->1
    //asi sucesivamente con el valor de cada billete
    cantidad = resto / 5000;
    resto %= 5000;
    printf("Billetes de 5000 :%d\n",cantidad);

        cantidad = resto / 2000;
    resto %= 2000;
    printf("Billetes de 2000 :%d\n",cantidad);

    cantidad = resto / 1000;
    resto %= 1000;
    printf("Billetes de 1000 :%d\n",cantidad);

    //moneda de 500

    cantidad = resto / 500;
    resto %= 500;
    printf("Billetes de 500 :%d\n",cantidad);
    return 0;
    
}