#include <stdio.h>

void duplicar(int x){
    x =x*2;
    printf("dentro: x = %d\n", x);//recibe esa copia y la guarda en su propia caja temporal que llamo  x desde este instante ahora x vale 5
}
 int main (void){
    int numero =5 ;//parte original se crea una caja llamada numero y se mete el num 5
    duplicar(numero); 


    printf("main: numero = %d\n", numero);
    return 0;

 }