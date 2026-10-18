//ejercicio que con for para dominar el tema  Guardar 5 notas en un arreglo, calcular el promedio e identificar la nota mayor.
// Qué se logra: Declarar arreglos, recorrerlos con for y aplicar lógica de búsqueda del mayor
#include <stdio.h>
#define N 5 //total de notas sera de 5 por ejemplo

int main(void){
    double notas[N] ={80.5 , 90.0 ,75.0 ,60.5 , 95.0};//esto es el valor de cada una des las 5 notas que estan dentro de N recuerde el ejemplo del casillero N es el casillero grande y lo que esta adentro es la variable suma y sus datitos
    double suma = 0.0;//acumulador (siempre es cero ,aunque depende de la situacion del ejercico)
    double mayor = notas[0];////asumes que la primera nota es la mayor(recuerda la que se encarga de saber que nota es la mayor es el ciclo for de mas adelante )
    //el if compara una nota con la anterior  hasta sacar la mayor 
    int i;//variable contadora para el ciclo for (puede ser i o cualquier palabra o numero eso no importa)

    for ( i = 0; i < N; i++)//Es 5 porque i vale o y hasta que i sea igual a N(variable que vale 5 en el define)
    {
        mayor=notas[i];///si es mayor actualizamos el valor de la nota mayor
        // Comparamos si la nota actual es mayor que la que tenemos registrada como 'mayor'
       //es es el if que compara si la nota actual es mayor a la que tenemos registrada
    if (notas[i]>mayor)
    {
        mayor=notas[i];
    }
    
    }
    
}