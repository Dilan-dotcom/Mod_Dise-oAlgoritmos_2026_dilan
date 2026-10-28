//practica de repaso de materia que me cuesta 
#include<stdio.h>//biblioteca determinada para hacer essto

int main (void){//funcion principal 
    //contenedor con tamaños y valoores especificos 
    int notas [5]={80,75,90,65,100};//son 5 casillas con notas que van desde el notas[0] al notas[4]
    int i;//eata es la variables que nos ayuda a recorrer todo el ciclo siempre viene con un for para hacer el recorrido 
    for ( i = 0; i < 5; i++)//el ciclo en cuestion 
    {
        printf("notas[%d]=%d\n",i,notas[i]);//abajo desglose del printf
        /*notas[...]: Es simplemente texto fijo que se imprime tal cual para que visualmente saber a en quwe vector estamos .
        el %d que va  adentro de notas es un especificadoor de formato , en este caso representa a el valor de la variable "i"que nos dara la posicion del vector
        = este igual es texto fijo 
        el segundo %d nos da el valor de la otra variable notas[i]
        al final las variables ,i,notas[i] reemplazan  a los %d (valores enteros)en el orden exacto que aparecen por decir asi el i reemplaza al primer %d y el notas[i] reemplaza en segundo %d
        
        */
    }
    return 0;

/*nota

#define N 5
int notas[N] = {80, 75, 90, 65, 100};
for (i = 0; i < N; i++) {
printf("%d\n", notas[i]);
}
// Siempre < N
esta es una manera favorable de hacerla con consttantes se define como una buena practica
}*/

}