//primer ejercicio del examen de programacion
//pago mensual
#include <stdio.h>   
#include<string.h>     



int main (void){
    char nombre[50];//un nombre puede llevar 50 caracteres no es algo fijo
    double vents[4] , mes=0, montoComi , montoRe, pago, bono;
    int semana ;///variable para contar los semanas 
    const double comision = 0.05 , RETENCION =  0.02,bono2=50 ;
        printf("Ingrese nombre del vendedor :");
        fgets(nombre , sizeof(nombre),stdin);//funcion trae la variables nombre con tamaño de npombe
        nombre[strcspn(nombre,"\n")]='\0'; //con strcspn vamos a quitar el salto de linea que genera el fgets 
                            //va a buscar el salto de linae y lo elimina 

        for ( semana = 0; semana < 4; semana++){

            //-------------------------------------identificador del do while -------------------------------------------------------------
        do{
            printf("ingrese el monto de la semana %d :\n",semana+1);//no afecta al contador
                
            scanf("%lf", &vents[semana]);//ventas en la pposicion semana osea los de semana +1 

            if (vents[semana] < 0 )
            {
            printf("Valor incorrecto, debe ser mayor a cero\n");
            }
            
        } while (vents[semana] < 0) ;{//es la misma condiciion la erronea que aplica la verificacion  que la que rompe el ciclo en el while
        //--------------------------------------------------------------------------------------------------------------------------------------
        }
             //se hace la usma afuera del do while porque si se escribe una variable incorrectga realizaria varias suma y daria otros resultados 
            mes= mes+vents[semana];
        }
        //---------------------------------------------------------------------------------
        //calculo de la comision del bono punto 2 

        if (mes >2000){
            printf("Si hay bono ");
        bono=bono2;
        }
        else{
            bono=0;
            printf("No hay bono pipipi");}
    //---------------------------------------------------------------------------------------
    ///punto 3 del 2% del pago
        montoComi = mes * comision;

        

        pago=montoComi + bono -montoRe;
        montoRe = (bono + montoComi) * RETENCION;
        for ( semana= 0; semana < 4; semana++)
        {
            printf("ventas de la semana %d : %.2f\n",semana+1,vents[semana]);
        }
        

        printf("El pago mensual del vendedor %s es de : %.2lf\n",nombre,pago);
        printf("====================================================\n");
        printf("El monto de ventas del mes es de : %.2lf\n",mes);
        printf("El monto de comision es de : %.2lf\n",montoComi);
        printf("El monto de retencion es de : %.2lf\n",montoRe);
        printf("El monto de bono es de : %.2lf\n",bono);
    return 0;

}

