//programa que debe de registra el nombre de un cliene con cantidad minima  de 1 y maxima de 10 cliengtes por compra  y validarlo , registra la cantidad(de 1 a 8 entradas minmax) y el tipo de entradas(3 tipos) , y validarlo ,poder aplicar un descuento del 10% en caso de compara mas de  5 entradas d e cualquier tipo y al finalizar entregar una tabla con una lista de todo lo anterior ,junto con el total vendido , compra mayor y cuantas veces hubieron descuento


#include <stdio.h>
#define MAXIMOCLIENTES 10
#define MAXIMOENTRADAS 8
#define VERIFICADOR 0
#define GENERAL 3500
#define NINO 2500
#define ANCIANO 2000
#define DESCUENTO 0.10
#define MINDESCUENTO 5
//protottipo de funciones
int leerEntero(const char mensaje, int minimo, int maximo);
double precioEntrada(int tipo);
double calcularTotal(int tipo, int cantidad);
void resumir(const int cant[], const double tot[], int n, double *total, int *posMayor, int *conDescuento);

int main (void){

//definir arreglos y variables

char cliente[MAXIMOCLIENTES][30];//almacena el nombre de cada cliente
int cantidad[MAXIMOCLIENTES];//cantidad de veces que se puede comprar, es 10 porque revisa las compras de cada cliente si compran 10 clientes
double total[MAXIMOCLIENTES];//total de cada compra 
//cantidad de compras , indice y tipo de entradas
int n, i,clase;
//cantidad de compras(el total)
double totalVendido;
//resultados
//este comproMas es para descubrir quien compro mas
int comproMas, aplicaDes;

///portada venta entradas
printf("======Venta de entardas======");
printf("Mostrar tipo");
printf("1.General:3500 2.Nino:2500 3.Anciano:2000");

//leer cantidad
n = leerEntero("Cantidad de compras", 1, MAXIMOCLIENTES);

//FOR para una vuelta por compra
for ( i = 0; i < n; i++)//no se escoge el maximo compra porque puede ser que no se compre 10 veces puede ser que se usse 3 veces el sitema y si lo aplicamos a maximo cliente que es 10 daria 10 vueltas cuando no es necesario
{
    /* almacena nombre de cliente  */
    printf("Compras %d\n cliente",i+1);
    scanf("%14s",cliente[i]);

   // leer tipo de entrada
    clase = leerEntero("tipo",1,3);//esto valida sin usar un do-while

    //leer cantidad de entradas
    cantidad[i] = leerEntero("Entradas", 1, 8);

    //calcular el total de  la compra
    total[i] = calcularTotal(clase, cantidad[i]);

}
resumir(cantidad, total, n, &totalVendido,&comproMas,&aplicaDes);

//encabezad
printf("\n%-12s%9d%12.2f\n",cliente[i],cantidad[i], total[i]);

// recorrer compras 
for ( i = 0; i < n; i++)
{
    /* mostrar fila */
    printf("%-12s%9d%12.2f\n",cliente[i],cantidad[i], total[i]);

    //total vendido
    printf("Total vendido %12.2f\n:",totalVendido);
    //compra mayor
    printf("Compra mayor : %s (%.2f)\n",cliente[comproMas],total[comproMas]);
    //cpmras con descuento
    printf("Con descuento :  %d compra(s)\n",aplicaDes);
    //total final 
return 0;
}


}

//defininciones .leer entero

int leerEntero(const char mensaje, int minimo, int maximo){
//variable local para el dato
int valor;

do{
    printf("%s(%d a %d) :",mensaje,minimo,maximo);
    scanf("%d",&valor);
} while (valor<minimo||valor > maximo);
return valor;
}
//definicion precioEntero

double precioEntrada(int tipo){
    switch (tipo){
    case 1:
        return GENERAL;
    case 2:
        return NINO;
    }
}

//definicion de calcular total

double calcularTotal(int tipo,int cantidad){
    double total = precioEntrada(tipo * cantidad);

    if (cantidad>=MINDESCUENTO)
    {
        total = total * (1 - DESCUENTO);
    }
    return total;
}
//definir resumir
void resumir (const int cant[], const double tot[],int n,double *total,int *comproMas,int*aplicaDes){
    int i;

    *total = 0;
    *comproMas = 0;
    aplicaDes = 0;
    //recorrer las compras 
    for ( i = 0; i < n; i++)
    {
        *total += tot[i];

        //comparar
        if (tot[i]>tot[*comproMas])
        {
            *comproMas = i;

            if (cant[i]>=MINDESCUENTO)
            {
                (*aplicaDes)++;
            }
            
        }
        
    }
    
}

