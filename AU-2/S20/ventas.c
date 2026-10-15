// ventas.c va a trabajar las ventas de una cadena de sodas por suscursal
// lo quwe queremos lograr es guardar en una matriz las ventas de 3 sucursales  en 4 dias
// lo que se deb hacer es  sumar cada sucursal por medio de una fila y cada dia por medio de la columna e identificar la surcursal que mas vendio con su nombre guardado en una cadena
// el resultado esperado es : centro 470 , norte 35o ,sur 410 por dia 330 270 330; sucursal con mas ventas :centro con 470

#include<stdio.h>
#include<stdlib.h>
#include<string.h>//strcpy es el elemento nuevo que veremos de esta libreria
#define SUC 3 //filas sucursales 
#define DIAS 4//columnas dias

int main (void){
    //arreglo de cadenas : una fila por nombre y le vamos a dar hasta 9 letras o caracteres mas '\0'(9 letras + ('\'))
    char nombres[SUC][10] = {"Centro", "Norte", "Sur"};
    ///ventas en miles de colones
    int ventas[SUC][DIAS] ={    {120, 100, 130, 120},
                                {90, 80, 100, 80},
                                {120, 90, 100, 100}};
    char mejor[10];//sucursal ganadora
    int s, d, total, totalDia, mayor = 0;
    //encabezado de D1 a D4
    printf("%-8s", "");
    for (d = 0; d < DIAS; d++){
        printf( "D%d" ,d+1);}
    printf( "  | total\n");

    //recorrido por filas
    for (s= 0; s < SUC; s++){
        total = 0;//de esta manera reinicimos cad fila a cero
        printf("%-8s", nombres[s]);//aparece nombre a la izquierda 
        for (d = 0; d < DIAS; d++){
            printf("%5d", ventas[s][d]);
            total += ventas[s][d]; }

        // guardar variables con mayor total ;script compia el nombre 
        if (total>mayor)
        {
            mayor = total;
            strcpy(mejor, nombres[s]);//mejor centro
        }
        
    }
    //recorrido de columnas
    printf("%-8", "DIAS");
    for (d = 0; d < DIAS; d++)
    {
        totalDia = 0;
    for (s = 0; s < SUC; s++){
        totalDia += ventas[s][d];}
    
    //salida de datos , la sucursal con mas ventas : centro con 470 (los datos nos los dieron al inicio)
    printf("\n");
    printf("sucursal con mas ventas :,%s (%d)\n", mejor, mayor);
    system("pause");
    return 0;
}

}
