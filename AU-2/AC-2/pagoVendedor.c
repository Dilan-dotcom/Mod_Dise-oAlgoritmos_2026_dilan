//primer ejercicio del examen se reuiere recibir el nombre de un vendedor las ventas de 4 semanas junto con comision , bonos y retencion  
//se requiere obtenerlas ventas de cada semana,el total ya calculado con sus arreglos 
#include <stdio.h>   
#include<string.h>     
//constantes
#define  TASACAJA 0.095  
#define TASAIESS 0.025
#define TASARENTA 0.10     
#define  LIMITERENTA 800

int main (void){
    char nombre[30];         
    double salarioBruto;   
    double desCaja;         
    double descIess;         
    double descRenta = 0;  
    double salarioNeto;
//validacion nombrre
do
{
    printf("Nombre completo : ");
    fgets(nombre,sizeof(nombre),stdin);
    nombre[strcspn(nombre,"\n")]='\0';
    if (strlen(nombre)==0)
    {
        printf("Nombre invalido no se puede poner un nombre vacio : \n");
    }
    
} while (strlen(nombre)==0);
//calculos
do {
        printf("Salario bruto: ");
        scanf("%lf", &salarioBruto);

        if (salarioBruto <= 0) {
            printf("Error: El salario bruto debe ser mayor a 0. Intente de nuevo.\n");
        }
    } while (salarioBruto <= 0);

    
    desCaja = salarioBruto * TASACAJA;
    descIess = salarioBruto * TASAIESS;

    if (salarioBruto > LIMITERENTA) {
        descRenta = salarioBruto* TASARENTA;
    }
    //Salario neto
    salarioNeto=salarioBruto-(desCaja+descIess+descRenta);
    
    //salida de datos
    printf("------- Comprobante de pago -------\n");
    printf("Empleado: %s\n", nombre);
    printf("Salario bruto: %.2f\n", salarioBruto);
    printf("Descuento CAJA (9.5%%): %.2f\n", desCaja);
    printf("Descuento IESS (2.5%%): %.2f\n", descIess);
    printf("Impuesto renta (10%%): %.2f\n", descRenta);
    printf("Salario neto: %.2f\n", salarioNeto);
    return 0;
}