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



// en resumen se requiere dar un salario completo despues de deducciones y extras si es que lo hay ycon los datos de el trabajador , el nombre ,tarisfa y cuanto trabajo ,luego sacar las deducciones del seguro , extra(si las hay) salario bruto y neto todo tratando de que este todo dentro de los limites como por ejemplo no dejar numero en cero o menos o nombres vacios 

#include <stdio.h> //librerias  
#include<string.h>     
//constantes
#define  JORNADA 48 //maximo de jornada
#define MAXIMOHORAS 60 //horas maximas 
#define TASARECARGO 1.5   ///valor de la tasa de recargo
#define  TASASEGURO 0.105 //tasa del seguro
//variables
int main (void){
    char nombre[30]; //variables nombre de empleado        
    double salarioBruto=0; //variable del salario sin editar 
    double salarioNeto=0;//variable con el resultado editado
    
    //variables inicializada
    double seguro = 0; //tasa seguro
    double tarifa = 0;//varibale para definir la tarifa de trabajo
    double extra = 0;//variable para definir tarifa
    double extra2 = 0;//variable en caso de necesitarla
    int horas;//variable patra definir horas 
//primera entrada ,parte logica-1de datos solicitud del nombre y validacion del mismo osea no puede estar vacio
do
{
    printf("Nombre completo del tecnico: ");//esta linea se supone que indica que no puede ponerse un nombre en blanco
    fgets(nombre,sizeof(nombre),stdin);
    nombre[strcspn(nombre,"\n")]='\0';
    if (strlen(nombre)==0)
    {
        printf("Nombre invalido no se puede poner un nombre vacio : \n");//lo ddevuelve 
    }
    
} while (strlen(nombre)==0);

 //parte logica-2 ingreso de la variable tarifa y validacion de la misma 
    do {
        printf("Ingrese la tarifa que se le indico: ");
        scanf("%lf", &tarifa);

        if (tarifa <= 0) {//indica que no puede ser cero
            printf("Error: La tarifa debe ser mayor a 0. Intente de nuevo.\n");
        }
    } while (tarifa <= 0);

//parte logica-3 solicitud de horas trabajafdas del tecnico y verificacion de las mismas
do {
        printf("ingrese las horas trabajadas en la semana (de 1 a 60)  : ");
        scanf("%d", &horas);
    //definicion de horas y extras 
        if (horas <= 0) {
            printf("Error: Favor ingtresar las horas solicitadas. Intente de nuevo.\n");
        }

        
        else if (horas > MAXIMOHORAS)//esta parte habla de que si las horas se pasan el extra vale algo si no ,no
        {
                
            extra = (horas * tarifa) * TASARECARGO;//valor de horas por tarifas por el recargo
            
        }
        else if ( horas > MAXIMOHORAS )
        {
            extra = 0;
        }
        
    } while (horas <= 0);

        

    //parte logica : lo que entendi del ejercicio de la parte de horas ordinarioas es que lo que este por debajo de 48 son ordinarias y lo que este por encima son un agregado como comision o extra
    extra2 = extra;//verificacion de variable en caso de error

    //parte de calculo y variables
    //salario bruto
    salarioBruto = (horas * tarifa) + extra;
    //Calculo del seguro
    seguro = salarioBruto * TASASEGURO;
    //calculo salario neto
    salarioNeto = salarioBruto - seguro;
    ///salida de datos desglose final con los datos de nombre ,tarifa , extra , horas , salario, tanto bruto como neto y seguro  

    printf("===PAGO SEMANAL DEL TECNICO===\n");
    printf("El tecnico %s\n", nombre);
    printf("Con la tarifa de %.2f\n",tarifa);
    printf("Con un extra de (si es cero no tuvo) %.2f\n", extra2);
    printf("Horas ordinarias %d\n:", horas);
    printf("Recibe un salario bruto de %.2f\n:",salarioBruto);
    printf("Seguro social  %.2f\n:",seguro);
    printf("Recibe un salario neto de  :%.2f\n",salarioNeto);
    // esta parte verifica si hubrieron horas extras o no y se lo hace saber
if (horas>JORNADA)
        {
            printf("se hizo un excedente de horas ordinarias(48 horas) tendras extras");
        }
        else if (horas=JORNADA)
        {
            printf("se cumplio la jornada ordinaria no hay extras");
        }
        
        else if (horas<JORNADA)
        {
            printf("se cumplio menos de la jornada");
        }
        return 0;
}