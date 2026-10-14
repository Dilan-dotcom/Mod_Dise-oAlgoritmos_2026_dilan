
#include <stdio.h> 

int main() {
    // Declaración de variables enteras para almacenar números sin decimales (salario, cuota, antigüedad)
    int salario, cuota;
    int antiguedad;
    char respDeudas, respFiador;
    int capacidadPago, tieneDeudas, tieneFiador, aprobado;

    // texto pidiendo el salario mensual
    printf("Salario mensual:\n");
    scanf("%d", &salario);

    //texto pidiendo la cuota del crédito
    printf("Cuota mensual del credito:\n");
    // Lee el número entero ingresado y lo guarda en la variable 'cuota'
    scanf("%d", &cuota);

    // Muestra la pregunta sobre si tiene deudas atrasadas
    printf("Tiene deudas atrasadas? (S/N)\n");
    // Lee un carácter. El espacio antes de %c (" %c") le indica a C que ignore cualquier espacio o salto previo
    scanf(" %c", &respDeudas);

    // la solicitud de los años de antigüedad laboral
    printf("Anos de antiguedad laboral:\n");
    scanf("%d", &antiguedad);

    // Muestra la pregunta sobre si tiene fiador
    printf("Tiene fiador? (S/N)\n");
    scanf(" %c", &respFiador);

    // Validamos si lo que ingresó el usuario NO es ninguna de las opciones permitidas
    if (respDeudas != 'S' && respDeudas != 's' && respDeudas != 'N' && respDeudas != 'n') {
    printf("Error: Ingrese un dato valido (S/N)\n");
    scanf(" %c", &respDeudas);
}

    capacidadPago = (salario >= (cuota * 3));
    tieneDeudas = (respDeudas == 'S' || respDeudas == 's');//la variable es verdadera si el usuario escribe A O B
    tieneFiador = (respFiador == 'S' || respFiador == 's');//recuerda estamos haciendo una comparacion no asignando un valor por eso usamos ==

    //1-Pedir los datos (printf y scanf).  2- validar los datos 3- calcular la vriable logica 4-soltar datos





    // Estructura condicional: si la variable 'aprobado' es verdadera (es 1)
    if (aprobado) {
        printf("Credito aprobado\n");
    } 
    // De lo contrario (si 'aprobado' es falso, es decir, 0)
    else {
        printf("Credito rechazado\n");
    }

    return 0; // Indica que el programa terminó de ejecutarse sin errores
}
