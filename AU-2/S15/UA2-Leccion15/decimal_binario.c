//convertir numero decimal 0 a 15 a binario de 4 bits(significa numeros de 4 digitos)
#include <stdio.h>

int main(void){//esta funcion no recibe  ningun parametro del sistema 
    int numero;//declaracion de variables tipo entero
    int cociente;
    int b0, b1, b2,b3 ;////un bit(residuo) por cada division 
    //entrada: leer eel nuemro y lo iguala  a 13 numero -< numero=13
    printf("numero decimal (0 a 15):");
    scanf("%d" , &numero);

    //Validacion :con 4 bits solo se representan los valores de 0 a 15

    if (numero<0 ||numero>15){
        printf("Fuera de rango use un numero de 0 a 15\n");
        return 1; //termina indicando que hubo 8un error
    }
    //se empieza dividiendo el numero completo -< cociente 13
    cociente=numero;
    //division entre 1: el residuo es el bit de las unidades->b0=1
    b0 = cociente % 2;
    //muestra el paso de 13 / 2/6 residuo 1 (osea 13 dividido entre 2 da 6 y residuo 1)
    printf( "%2d / 2 = %d residuo %d \n",cociente , cociente / 2, b0);
    //muestra la division 2: 6/2=2 rsidio 0 , b1=0
    cociente= cociente/2;
    b1 = cociente % 2;
    //muestra el paso 13 / 2= 6 residuo 1
    printf("%d / 2 = %d residuo %d\n",cociente, cociente /2, b1);
    cociente= cociente/2;
     //muestra la division 2: 6/2=2 rsidio 0 , b1=0
    b2 = cociente % 2;
    //muestra el paso 3/2= 6 residuo 1 b2= 0
    printf("%d / 2 = %d residuo %d\n",cociente, cociente /2, b2);
    cociente= cociente/2;
     //muestra la division 2: 1/2=2 rsidio 0 , b3=0
    b3 = cociente % 2;
    //muestra el paso 13 / 2= 6 residuo 1
    printf("%d / 2 = %d residuo %d\n",cociente, cociente /2, b3);

    //resultado los residuos se leen de abajo hacia arriba -< 1101
    printf("en binario : %d %d %d %d\n"  , b3 , b2 , b1 , b0);
    //comprobacion %o muestra en octal y %x en hexadecimal <> 15 y D 
    printf("comprobacion : octal %o , hexadecimal %X\n", numero , numero);
    return 0;
}