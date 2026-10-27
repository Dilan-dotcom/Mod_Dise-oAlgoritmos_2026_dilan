//convertir en funciones de cuatro algoritmos 
//conversion de temperatura/conversion de moneda(colones por dolar)
#include <stdio.h>
#define TIPO_CAMBIO 510.0 //colones por dolar 
//prototipo de las funciones
double celsiusFahrenheit(double celsius);//devuelve los grados f
double colonesADolares(double colones);//devuelve los dolares
int esBisiesto(int anio);
int esNotavalida(double nota);

//funcion principal
int main (void){
    //prueba de temperatura 77.0 
    printf("25 C = %.1f F (esperado 77.0)\n", celsiusFahrenheit(25));

     //prueba de moneda 10.00
    printf("5100 colones  = %.2f F (esperado 10.00)\n", colonesADolares(5100));

     //prueba de año bisiesto -> 1 verdadero
    printf("2024 bisiesto :%d (esperado 1)\n", esBisiesto(2024));

     ///prueba de año bisiesto -> 0 falso
    printf("1900 bisiesto :%d (esperado 0)\n", esBisiesto(1900));

     //prueba de año
    printf("2024 bisiesto :%d (esperado 1)\n", esBisiesto(2024));
    //prueba nota invalida
    printf("nota 105 valida : %d(esperado 0)\n", esNotavalida(105));

      //prueba nota valida
    printf("nota 85 valida : %d(esperado 1)\n", esNotavalida(85));

    return 0;
}

//conversion de temperatur
double celsiusFahrenheit(double celsius){
    return celsius * 9.0 / 5.0 + 32.0;
}

//conversion moneda
double colonesADolares(double colones){
    return colones / TIPO_CAMBIO;
}

//anio bisiesto
int esBisiesto(int anio){
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

//validar nota
int esNotavalida(double nota){
    return (nota >= 0 && nota <= 100);
}

