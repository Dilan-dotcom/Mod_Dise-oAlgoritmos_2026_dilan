 #include <stdio.h>

/*El símbolo & (Se lee: "La dirección de..."):Sirve para averiguar dónde vive una variable en la memoria de la computadora.   Ejemplo: &edad significa "dame la dirección exacta de memoria donde está guardada la variable edad".   


El símbolo * al declarar un puntero (Se lee: "Puntero a..."):Es una cajita especial (un puntero) cuyo único trabajo en la vida no es guardar números normales, sino guardar direcciones de casas (direcciones de memoria).   Ejemplo: int *p; significa "crea una cajita llamada p que solo puede guardar direcciones de memoria de variables tipo entero".   


El símbolo * cuando ya estás usándolo (Se lee: "El valor que hay en esa dirección" o Desreferenciar):Si usas el asterisco pegado a tu puntero (*p), la computadora hace esto: agarra la dirección que tenías guardada, viaja hasta allá como si usara el GPS, se mete a la casa y toca o modifica el objeto real que vive adentro.  */

int main(void) {

    int edad=20; //caja edad que guarda  el numero 20 adentro
    int *p = &edad; // Creamos el puntero 'p' y le guardamos la DIRECCIÓN (&) de 'edad'

    printf("edad = %d\n", edad); // Imprime: edad = 20 (solo verificamos el dato esto no es necesario)

    //  Usamos el '*' para meternos a la casa a través de la dirección y cambiar el valor original
    *p = 21;              // ¡Esto cambia la variable 'edad' a 21 de verdad!

    int x = 5; 
    int *b = &x; 
    *b = 9;  

    
    printf("x = %d\n", *b);
    printf("edad = %d\n", edad); // Ahora imprime: edad = 21
    return 0;
}