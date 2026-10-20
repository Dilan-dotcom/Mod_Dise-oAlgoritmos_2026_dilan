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
    double desc_renta = 0.0;  
    double salario_neto;
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
    
} while (strlen(nombre==0));
//calculos
do {
        printf("Salario bruto: ");
        scanf("%lf", &salarioBruto);

        if (salarioBruto <= 0) {
            printf("Error: El salario bruto debe ser mayor a 0. Intente de nuevo.\n");
        }
    } while (salarioBruto <= 0);

    
    desCaja = salarioBruto * TASACAJA;
    desCaja = salarioBruto * TASAIESS;

    if (salarioBruto > LIMITERENTA) {
        desc_renta = salarioBruto* TASARENTA;
    }