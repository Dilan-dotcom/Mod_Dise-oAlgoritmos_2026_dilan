//practica con matrices para buscar un nombre 

#include<stdio.h>//biblioteca determinada para hacer essto
#include <string.h>

int main (void){

    char nombres [4][20]= {"Ana", "Carlos", "Sofia", "Lucia"};
    char buscado[20]="sofia";
    int i  ;
    double posicion=-1;
for ( i = 0; i < 4; i++)
{//en C no se puede usar == para comparar texto para solucionarlo C nos da la herramienta  
    if (strcmp(nombres[i],buscado)==0)//funcion para buscar 
    {
        posicion =i;//guarda la posicion 
        break;
    }
    
}
// 3. El reporte final (igualito que con los números)
if (posicion >= 0) {
    printf("El nombre %s esta en la posicion %d\n", buscado, posicion);
} else {
    printf("El nombre %s no existe en la lista\n", buscado);
}

}