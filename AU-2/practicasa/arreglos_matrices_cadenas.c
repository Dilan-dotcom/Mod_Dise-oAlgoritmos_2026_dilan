//practica de repaso de materia que me cuesta 
#include<stdio.h>//biblioteca determinada para hacer essto

int main (void){//funcion principal 
    int notas [5]={80,75,90,65,100};//son 5 casillas con notas que van desde el notas[0] al notas[4]
    int i;//eata es la variables que nos ayuda a recorrer todo el ciclo siempre viene con un for para hacer el recorrido 
    for ( i = 0; i < 5; i++)//el ciclo en cuestion 
    {
        printf("notas[%d]=%d\n",i,notas[i]);//abajo desglose del printf
        /*notas[...]: Es simplemente texto fijo que se imprime tal cual para que visualmente saber a en quwe vector estamos .
        
        
        */
    }
    return 0;



}