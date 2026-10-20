
#include <stdio.h>
#include <string.h>

#define NOTAMIN 0   //limite minimo      
#define NOTAMAX 100   //limite maximo     
#define APROBADO 70 //minimo para aprobar
#define RIESGO 60   //promedio minimo para estar en riesg

int main(void) {
    //variables
    char nombre[30];         
    float notas[3];           
    float sumaNotas = 0;   
    float promedio = 0;    
    float notaAlta = 0;    
    char condicion[20];       
    int i;
    //entrada de datos
    printf("=== Calificaciones del estudiante ===\n");
    do
{
    printf("Nombre del estudiante : ");
    fgets(nombre,sizeof(nombre),stdin);
    nombre[strcspn(nombre,"\n")]='\0';
    if (strlen(nombre)==0)
    {
        printf("Nombre invalido no se puede poner un nombre vacio : \n");
    }
    } while (strlen(nombre)==0);

    //fin del programa
    return 0;
}