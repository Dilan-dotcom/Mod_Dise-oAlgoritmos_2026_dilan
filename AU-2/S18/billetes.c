//desglose de billetes

#include <stdio.h>
int main (void){
    //definicion de variables 
    int monto , resto , cantidad ;
    //entradas lee monto =47500
    printf("Monto a desglosar :");
    scanf("%d", &monto);

    //procesos division entera entre 47500/ 20000 -> cantidad =2
    cantidad= monto/20000;

    //% es el residuo : 475000 %(mod) 20000->resto=7500
    monto= monto % 20000;
    //muestre -> billetes de  2000 : 2
    printf("Billetes de 2000 : %d\n",cantidad);

    cantidad =monto / 10000;//esto significa 7500 / 5000 = cantidad = 1
    //forma compacta de resto = resto % 10000 -> resto ->7500 
    monto %= 10000;//-> resto =2500
    printf("Billetes de 10000 :%d\n",cantidad);//->1
    //asi sucesivamente con el valor de cada billete
    cantidad = monto / 5000;
    monto %= 5000;
    printf("Billetes de 5000 :%d\n",cantidad);

        cantidad = monto/ 2000;
   monto %= 2000;
    printf("Billetes de 2000 :%d\n",cantidad);

    cantidad = monto / 1000;
    monto %= 1000;
    printf("Billetes de 1000 :%d\n",cantidad);

    //moneda de 500

    cantidad = resto / 500;
   monto%= 500;
    printf("Billetes de 500 :%d\n",cantidad);
    return 0;
    
}