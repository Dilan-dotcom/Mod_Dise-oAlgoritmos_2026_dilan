//caja registradora  con menu

#include <stdio.h>
int main (void){
    //declaracion variables
    int opcion ;    ///opcion elegida en el menu 
    int productos = 0;  //contador de producos de la venta
    double precio;  //precio para cada producto
    double total = 0 ; //acumulador de la venta 

    //do ...while : el menu se muestra al menos una vez 
    do{
        //mostrar el menu y lee la opcion 1
        printf("\n 1. Agregar 2.ver total 3.cobrar 0.Salir\n" );
        printf("opcion: \n");
        scanf("%d", &opcion);

        //acontinuacion el switch (es como el "segun" en pseint para futruas referencias)
        //salta al case que conicida con la opcion elegida 
        switch (opcion){
            case 1:
            //validacion :repite mientras el preciio no sea positivo
            printf("Precio del producto");
            scanf("%lf", &precio);//->1500 

            if (precio<=0) {
                printf("Precio invalodo\n");
            
            }
            while(precio>=0)
            
                productos++;//cuenta productos (suma 1)
                total += precio;//suma precio
                break;//sale de switch
                case 2:
                //muestra el avance
                printf("productos :%d total :%.2f\n" ,productos , total);
                    break;

                    case 3:
                    productos = 0;
                    total = 0;
                    break;

                    case 0:
                    printf("caja cerrada");
                    break;
                    default:
                    
                    printf("opcion invalida");
                }
                //repite el numero mientras no se eliga 0
    } while (opcion != 0);
    return 0;
}
        