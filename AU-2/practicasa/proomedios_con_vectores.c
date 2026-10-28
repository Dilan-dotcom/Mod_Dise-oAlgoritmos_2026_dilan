//practica para buscar el int main (void){//funcion principal 

#include<stdio.h>//biblioteca determinada para hacer essto

int main (void){
    int notas [5]={80,90,60,70,54},i;
    int suma=0 ;//acumuladores se inicializan la mayoria del tiempo
    double promedio;

    //recuerda que el promedio se sacaba sumando todos los elementos y dividiendolos por la canitdad de elementos que son en este caso cumar todas las notas y dividirlas entre 5
//recorre la suma 
for ( i = 0; i < 5; i++)
{
    printf("las notas [%d]=%d\n",i,notas[i]);//poner esto de enseñar las notas dentro del for mejor 
    suma+=notas[i];//esta es la variable acumuladora 
}
//fuera del for
promedio=suma/5;

printf("El promedio es : %.2f\n",promedio);



}
