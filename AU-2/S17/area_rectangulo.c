// Area.c - saca el area de un rectangulo 
#include <stdio.h>
int main(void){
    //Paso 1 declarar bvariable
    double base, altura, area;//son de los mismo double = real pueden ir varias variables en la misma linea
    //pedirle datos al usuario con printf en este caso base=5
    printf("Digite la base del rectanddulo(cm):  ");
    //alamecamos que tipo de dato le pedimos al usuario
    scanf("%lf", &base);
//con scanf se le pide los datos lo primero es comm reconoce le programa que tipo de variable es lo segundo es especificamnete cual
    //mensaje y lee altura
    // la altura va a valer 3
    printf("Digite la altura del rectanddulo(cm):  ");
    //alamecamos que tipo de dato le pedimos al usuario
    scanf("%lf", &altura);

    //proceso:multiplica y guarda el resultado =15
    area = base * altura;

    //salida de los datos //mostrara el area con 2 decimales
    printf("El area del rectangulo es %.2f cm2\n", area);
    return 0;
}