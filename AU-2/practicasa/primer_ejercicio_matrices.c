/*primera parte para entender matrices 
ejemplo de mtrices (arreglo con filas y columnas ) sucursal y dias de la semana 
en las matrices ya no se basta solo coon un solo numero para encontrar un dato se necesitan 2 dirrecciones(filas y columnas)
en C las matrices se ven asi matriz[fila][columna] y simeppre se empieza desde el cero*/

//Primero, sobre el objetivo del ejercicio: estás en lo correcto. El programa toma una matriz de 2 sucursales (filas) y 3 días (columnas), imprime los valores de cada día y al final de cada fila calcula el total de ventas específico de esa sucursal (la tienda 1 vendió 345 en total y la tienda 2 vendió 280)


#include<stdio.h>

int main (void){
    //para crear una matriz se necesita lo siguiente decirle el tipo de dato , un nombrey indicar el  tamaño
    int ventas [2][3]={
        // del primer parentesis cuadrado
        /*sucursal 1 */ {120,95,130},//fila 0(sucursal 1)
        /*segunda sucursal*/ {80,110,90}//fila 1(sucursal 2)
        //el primer 2 da esas 2 lineas
    };
    int e,i,total;//nota se inicializa esta variable porque es acumulativa en el ejercicio del profe viene inicializada desde el punto en el que se usa , no tiene mas raxzon recuerda variables acumulativas osea juntan varias valor al final se inicializan (donde quieras )

    //un for se recorre con lo que se conoce como un for anidado osea un for para cad una di las filas
    //parra usar ambos for recuerda crear una variable diferennte para cada for osea un i y un h por ejemplo y se ve asi
    
    for (e = 0; e < 2; e++)
    {
        // Reiniciar el acumulador para cada sucursal.
        total = 0;
        
        for (i = 0; i < 3; i++)
        {
            total += ventas[e][i]; // Sumar las ventas de esta sucursal.
        }
        printf("  Total: %d\n", total);
    }
    


return 0;
}