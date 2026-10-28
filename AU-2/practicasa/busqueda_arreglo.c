// ejemplo de un arreglo de busqueda donde la busqueda lineal  revisa casilla por casilla en este ejmplo el valor -1  significara no encontrado

#include<stdio.h>//biblioteca determinada para hacer essto

int main (void){
    int codigo [5]={101,205,310,412,518};
    int buscado=310 ,posicion =-1 ,i;//usamos -1 porue significa todavia no lo hemos encontrado esto signifia que como aun nose en que posicion esta guardado el valor que buscamos uso un -1 para guardarlo

    for ( i = 0; i < 5 ; i++)
    {
        //esto es lo que revisa la caja
        //codigo[i]significa caja con el buscador i o mejor dicho el arreglo que recoorre la caja y == significa , es igual aa lo que busco?buscado o el numero que requerimos , esto es lo que hace este if compara lo que hay en el vector con lo que necesitamos encontrar
        if (codigo[i]==buscado)
        {
            //lo encontre y a correr 
            //(recuerda que esto ==sigifica ¿es esta cosa igual a esta otra cosa?)
            /*si la respuesta del if es si  es decir encontramos el 310 o el valor requerido*/
        
            posicion=i;//esto siginifa encontre lo que buscaba en la caja numero "i" lo guardare en este otra caja osea posicion 

        break;//ya lo encontro apaga el ciclo a la fuerza 
        }
    
    }
    
if (posicion>=0)//esto significa si posicion ya es mayor a cero significa que lo encontramos 
{
    printf("el codigo %d esta en la posicion %d \n",buscado, posicion);
}else{printf("El codigo %d no existe",buscado);}//significa sino no se encontro



}