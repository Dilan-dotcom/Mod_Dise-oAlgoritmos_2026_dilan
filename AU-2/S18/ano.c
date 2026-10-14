//algoritmo para saber siel año es bisiesto o no
#include <stdio.h>
int main (void){
    //definir variables 
    int ano ;
    int esbi;
    //pedir datos del usuario
    printf("Escriba el año");
    scanf("%d", &ano);
    //parte logica 
    esbi = (ano % 4 == 0 && ano % 100 !=0) || (ano % 400==0);//recuerda aqui estamos compararndo por es0 usamos el ==(AQUI SI SE USAN NO ES DARLE UN VALOR ES COMPARAR)

    //Salida dde datos 
    if (esbi) {
        printf("El ano es bisiesto\n");
    } else {
        printf("El ano NO es bisiesto\n");
    }

    return 0;
}