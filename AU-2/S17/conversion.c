// conversion de temperatura Pratica para pasar de celsius a farenheit
#include <stdio.h> 
int main (void){
    //definicion variables
    double celsius, farenheit;

    printf("Ingrese la medida en celsius");
    scanf("%lf", &celsius);
    //proceso
    farenheit =  celsius * 9 / 5 + 32;
    

        // salida
        printf("La medida en celcius %.2f\n", celsius );
        printf("pasa a ser  %.1f\n", farenheit);
}