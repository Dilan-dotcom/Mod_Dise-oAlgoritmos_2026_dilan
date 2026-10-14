//el grupo va aelegir al representante entre 3 cantidades cada estudiante pasa a la computadora y digita el numero del candidato , se suman los votos 
//cualquier otro voto es voto nulo 
#include <stdio.h>//printf y scanf
#define FIN 0// va sin comillas

int main(void) {//funcion principal
    int i;//contador del for interno osea una vuelta por cada asterisco 
    int c;//candidatos que debuja el for externo 1 a 3
    int cantidad ;//votos del candidato
    int voto ;//numero que digita cada estudiante 
    int total=0;//contador de votos recibidos (tanto validos como nulos )
    int ana =0;/// de aqui para abajo todos son nulos 
    int luis =0;
    int sofia =0;
    int nulos =0;
    int mayor ;//saca el ganador 
    int empate; //en caso de habr empate
    printf("=====Eleccion de representantes=====\n");
    printf("1 Ana  2 Luis  3 Sofia  (0 cierra el programa)\n\n");

    //lecturas previas 
    printf("Voto :");
    scanf("%d", &voto);

    //while se repite el bucle mientras el voto no sea cero
    while (voto != FIN){
       total++; //cuenta el voto -< 1 2 3 etc hasta el 0 que cierra el programa osea el total de votos contados 
       //NUEVA LECTURA: sin la nueva lectura el voto no cambia y el while no termina
    switch (voto){
    case1 : ana++; break;
    case2 : luis++; break;
    case3 : sofia++; break;
        default://cualquier otro numero osea la exepcion 
        nulos++;
        printf("Voto nulo\n");
    }
    
    printf("voto :");
    scanf("%d",&voto);

    }

    //for externo una vuelta por candidato -> c=1,2,3 

    for (c = 1 ; c<= 3; c++)
    {
    switch (c){
    case 1:printf("Ana  "); cantidad = ana; break;
    case 2:printf("Luis  "); cantidad = luis; break;
    default: printf("Sofia  "); cantidad = sofia; break;
    

    }
    //for anidado en este caso el interno un for  * y otro por voto -> ana*****
    
    for (i = 1; i <= cantidad; i++)
    
    printf("%d\n", cantidad);
    printf("nulos :(%d)",cantidad);
}
if (luis>mayor) mayor=luis;
if (sofia>mayor) mayor=sofia;
if (ana>mayor) mayor=ana;
//empatados
empate =0;
if (luis==mayor) empate++;
if (sofia==mayor) empate++;
if (ana==mayor) empate++;

if (mayor==0)
printf("no hubo votos validos ");
else if (empate>1);



printf ("nulos :%d",nulos);
    return 0;

}

