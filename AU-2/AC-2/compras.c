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

int main(void){
    char cliente[50];             
    char productos[MAXPROD][ANCHNOMBRE];     // Arreglo paralelo para los nombres de los productos
    double precios[MAXPROD];       // Arreglo paralelo para los precios unitarios
    int cantidades[MAXPROD];       // Arreglo paralelo para las cantidades compradas
    
    int totalProductos = 0;        
    double subtotalGeneral = 0;  // Acumulador de la suma de los subtotales
    char opcion;                    
    
    double descuento = 0;       
    int porceDesc = 0;       
    double totalDesc = 0;    
    double impuesto = 0;         
    double totalPagar = 0;
    //entrada de datos
    // Lectura del nombre del cliente
    printf("Nombre :");
    if (fgets(cliente, sizeof(cliente), stdin) != NULL) {
        size_t len = strlen(cliente);
        if (len > 0 && cliente[len - 1] == '\n') {
            cliente[len - 1] = '\0';
        }
    }       
}