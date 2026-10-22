//Un taller paga a sus técnicos por hora trabajada. Escriba un programa en C que:
/*1. Reciba el nombre completo del técnico (puede tener espacios; no se acepta un nombre vacío).
2. Reciba las horas trabajadas en la semana (de 1 a 60) y la tarifa por hora (mayor que 0). Un 
dato inválido muestra un mensaje y se vuelve a pedir.
3. Separe las horas: las primeras 48 son ordinarias; las que pasen de 48 son horas extra y se 
pagan al 150 % de la tarifa.
4. Calcule el salario bruto (pago ordinario + pago extra), el seguro social (10.5 % del bruto) y el 
salario neto.
5. Muestre un comprobante con el nombre, las horas y el pago ordinario, las horas y el pago extra, 
el bruto, el seguro y el neto, con dos decimales y alineados.
*/ 


#include <stdio.h>   
#include<string.h>     
//constantes
#define  JORNADA 48 //maximo de jornada
#define MAXIMOHORAS 60 //horas maximas 
#define TASARECARGO 1.5   ///valor de la tasa de recargo
#define  TASASEGURO 0.010 //tasa del seguro
//variables
int main (void){
    char nombre[30];         
    double salarioBruto;   
           
        
     
    double salarioNeto;
    int horas;
}