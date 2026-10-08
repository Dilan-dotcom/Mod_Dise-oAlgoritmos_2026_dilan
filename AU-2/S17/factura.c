//factura con IVA

#include <stdio.h>
int main (void){
    //contante para el IVA
    const double TASA_IVA = 0.13;

    //variables enteras para cantidad y reales para montos
    int cantidad;
    double precio, subtotal , iva ,total;

    //datos entrada: pedir y almacenar cantidad.tammbien lee un entero =3

    printf("Cantida :");
    scanf("%d",  &cantidad);

    //leer un double precio como ejemplo precio=5000
    printf("Precion unitario :");
    scanf("%lf", &precio);

    //preoceso: int * dobles da double -> subtotoal = 15000
    subtotal = cantidad * precio;
    //sacamos el IVA con la constante  ->IVA =1950
    iva = subtotal * TASA_IVA;
    //total -> 16950
    total = subtotal + iva;
    //salidas : usar 2 decimales , 10 espacios
    printf("Subtotal: %10.2f\n",subtotal);
    printf("IVA (del 13%%): %10.2f\n",iva);
    printf("Total :        %10.2f\n",total);
    return 0;
}