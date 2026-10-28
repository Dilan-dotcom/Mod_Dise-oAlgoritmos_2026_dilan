//lee 2 enteros de mayoor a menos con funcion que los intercambia y divide el mayor entre el menor comn otra funcion que entrega el cociente y el residuo

#include<stdio.h>

//prototipo de intercambiar 
void intercambiar (int *a,int *b);


//prototipo de dividir 
void dividir(int dividiendp, int divisor , int*cociente, int*residuo);

//funcion principal
int main (void){

//los dos numeros del cociente y residuo 
int x,y,c,r;

//pedir el primer numero  
printf("primer numero : ");
scanf("%d",&x);


printf("segundo numero : ");
scanf("%d",&y);

//validacion de si x es menor a y usando 5x= < y=17
if (x<y)
{
    //intercambiar x con y x=17 y y=5
    intercambiar(&x, &y);
}
//mostrar numeros
printf("ordenados :%d y %d\n",x , y);

//validar division entre 0
if (y==0)
{
    /* aviso */
    printf("No se puee dividir entre 0\n");
}else{
    dividir(x, y,&c ,&r);
    //mostrar la division 
    printf("%d/%d=%d residuo %d\n",x,y,c,r);
    //comprobarlo
    printf("comprobacion ; %d * %d +%d = %d",c,y,r,c * y + r);
}
return 0;
}
//hacer intercambio

void intercambiar(int * a,int * b){
//variable aux respalda el  valor x=5
int aux = *a;
//x recibe el valor y =17
*a = *b;
//recibe aux
*b = aux;
}

//definicion de dividir

void dividir(int dividiendo,int divisor, int*cociente, int *residuo) {

*cociente=dividiendo /divisor;
*residuo = dividiendo%divisor;
}
