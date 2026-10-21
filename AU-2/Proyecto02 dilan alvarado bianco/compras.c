/*Una tienda de electrónica necesita procesar las compras de sus clientes. Escriba un programa en C 
que:
1. Reciba el nombre del cliente.
2. Permita registrar varios productos (máximo 10): nombre (puede tener espacios), precio 
unitario y cantidad. Después de cada producto pregunta si desea agregar otro (S/N); solo 
acepta S o N (mayúscula o minúscula).
3. Valide que el precio y la cantidad sean positivos.
4. Muestre el subtotal de cada producto (precio × cantidad) al ingresarlo y acumule el total.
5. Aplique el descuento según el total: menos de 100, sin descuento; de 100 a menos de 500, 5 %; 
de 500 a 1000, 10 %; más de 1000, 15 %.
6. Calcule el total con descuento y el impuesto (13 % sobre el total con descuento).
7. Muestre una factura con el cliente, el detalle de cada producto (nombre, precio, cantidad y 
subtotal), la cantidad de productos, el subtotal, el descuento, el total con descuento, el impuesto 
y el total a pagar.*/ 

#include <stdio.h>   
#include<string.h>

#define MAXPROD 10 
#define ANCHNOMBRE 50         // Máximo de productos permitidos 
#define TASAIMPUESTO 0.13  //impuesto

// CONSTANTES
#define MAX_PRODUCTOS 10
#define ANCHO_NOMBRE 50


int main(void){
    // VARIABLES
    char nombre[50], productos[MAX_PRODUCTOS][ANCHO_NOMBRE];
    double precios[MAX_PRODUCTOS], subtotalProduct, subtotal, totalDescuentos,impuesto, totalPagar;
    int cantidades[MAX_PRODUCTOS], i=0, totalProductos=0;
    char respuesta;

    printf("Ingrese su nombre: \n");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    do
    {
        printf("Ingrese el nombre del producto: \n");
        fgets(productos[i], sizeof(productos[i]), stdin);
        productos[i][strcspn(nombre, "\n")] = '\0';

        do
        {
            printf("Ingrese el precio del producto: \n");
            scanf("%lf", &precios[i]);

            if (precios[i] < 0)
            {
                printf("Precio incorrecto: \n");
            }
            

        } while (precios[i] < 0);

        do
        {
            printf("Ingrese la cantidad: \n");
            scanf("%d", &cantidades[i]);

            if (cantidades[i] < 0)
            {
                printf("Dato incorrecto: \n");
            }
            

        } while (cantidades[i] < 0);
        subtotalProduct=precios[i]*cantidades[i];
        printf("El subtotal producto es %.2f",subtotalProduct);

        subtotal+=subtotal+subtotalProduct;

        totalProductos++;
        i++;
        //salto de linea 
        while (getchar()!='\n')
        {
            /* code */
        }
        
        //mas productos?
        if (totalProductos <MAX_PRODUCTOS)
        {
            printf("desea seguir agregando productos ?(s/n)");
            scanf("%c",respuesta);
            if (respuesta!='s'&&respuesta!='S')
            {
                printf("Formato no valido");
            
        } while (respuesta!='S' && respuesta != 'N'&&respuesta!='n')

            
        }
        

    } while ((respuesta!='s'|| respuesta!='S')&&totalProductos< MAX_PRODUCTOS);
    
    printf("===Desglose===");
    printf("");
    printf("");
    printf("");
    printf("");

    return 0;
}