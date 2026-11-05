/*Un colegio controla los pases de bus de sus estudiantes y puede registrar hasta 5 pases. De cada pase se guarda: el código (100 a 999, no se repite), el nombre del estudiante (una sola palabra, hasta 19 letras), los viajes disponibles y si el pase está activo o dado de baja. El programa inicia con 3 pases ya cargados (tabla de abajo). Debe mostrar un menú que se repite hasta elegir 0; toda opción o dato fuera de rango se vuelve a pedir.*/


/*Pases cargados al iniciar:
Código	Nombre	Viajes
201	    Ana	    5
202	    Luis	1
203	    Sofia	8
*/  

//Cargar las bibliotecas
#include <stdio.h>
#include <string.h>

//Definir las constantes
#define MAX_PASES 5       //espacios para los pases disponibles
#define TAM_NOMBRE 20     //19 caracteres o letras + el \0
#define COD_MIN 100       //codigo minimo
#define COD_MAX 999
#define VIAJES_MAX 40      //viajes maximos a incluir

//Prototipos (una funcion por tarea)
int leerEntero(const char mensaje[], int minimo, int maximo);
int buscarCodigo(const int cod[], const int activo[], int n, int codigo);
void incluir(int cod[], char nom[][TAM_NOMBRE], int viajes[], int activo[], int *n, int codigo, const char nombre[], int cantidad);
void consultar(const int cod[], const char nom[][TAM_NOMBRE], const int viajes[], const int activo[], int n);
int usarViaje(int *viajes);
void darDeBaja(int *activo);

//funcion principal
int main(void) {
    //Asigane datos de los pases
    int cod[MAX_PASES] = {201, 202, 203};
    char nom[MAX_PASES][TAM_NOMBRE] = {"Ana", "Luis", "Sofia"};
    int viajes[MAX_PASES] = {5, 1, 8};
    int activo[MAX_PASES] = {1, 1, 1};
    int n = 3; //espacios usados 
    int opcion, codigo, pos, cantidad;
    char nombre[TAM_NOMBRE];

    //Ciclo para menú
    do {
        //mostrar el menu
        printf("\n=== Pases de bus ===\n");
        printf("1. Incluir 2. Consultar 3. Registrar viaje 4. Dar de baja\n");
        printf("5. Buscar 0. Salir\n");

        //Leer la opcion
        opcion = leerEntero("Opcion", 0, 5); // no aceptar opciones inexistentes
        if (opcion >= 3) {
            codigo = leerEntero("Codigo", COD_MIN, COD_MAX);
            pos = buscarCodigo(cod, activo, n, codigo); // busca el pase activo
            //revisa si existe
            if (pos == -1) {
                //aviso
                //>>> Observacion 1: decia "No esxiste" (error de escritura).
                printf("No existe un pase activo con el codigo %d\n", codigo);
                //para continuar
                continue;
            }
        }
        switch (opcion) {
            case 1:
            if (n == MAX_PASES) {
                printf("No hay espacio para mas pases\n");
                break;//sale para volver a lmenu
            }   // AQUI se cierra el if (antes estaba despues del repetido)

            //lee codigo com oentero
            codigo = leerEntero("Codigo", COD_MIN, COD_MAX);
            //revisar si el codigo existe
            if (buscarCodigo(cod, activo, n, codigo) != -1) {
                //>>> faltaba el aviso: sin el, el usuario no sabe por que no
                //>>>   se incluyo el pase.
                printf("El codigo %d ya existe\n", codigo);
                break;  //sale para no incluir al repetido
            }
        //pide nombre
        printf("Nombre (una palabra): ");
        //leer nombre
        scanf("%19s", nombre);
        //leer los viajes
        cantidad = leerEntero("Viajes", 1, VIAJES_MAX); // DE 1 A 40 MAX
        //guardar el pase qu viene por direccion
        incluir(cod, nom, viajes, activo, &n, codigo, nombre, cantidad);
        //conformar pase incluido
        printf("Pase incluido (%d de %d)\n", n, MAX_PASES);
        break;

        case 2: 
            consultar(cod, nom, viajes, activo, n);
            break;
        case 3:
        //inetnta regstrar viaje
        if (usarViaje(&viajes[pos]))
        printf("Viaje registrado. A %s le quedan %d\n", nom[pos], viajes[pos]);
        //no quedan vieajes
        else 
            printf("%s no tiene viajes disponibles\n", nom[pos]);
        break;

        case 4: 
            darDeBaja(&activo[pos]);
            printf("Pase de %s dado de baja\n", nom[pos]);
            break;

        case 5: 
            //buscar un pase
            printf("%d %s: %d viajes\n", cod[pos], nom[pos], viajes[pos]);
            break;

        default:
            printf("Hasta luego\n");
        }

    } while (opcion !=0);
    return 0; 
    
 }

 //lectura valida de un entero
 int leerEntero(const char mensaje[], int minimo, int maximo) {
    //dato leido
    int valor;
    //ciclo validacion para qu pida el dato al menos una vez
    do {
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        //leer

        scanf("%d", &valor);
    } while (valor < minimo || valor > maximo);
    return valor;
 }

 //Busqueda secuencial de un pase

 int buscarCodigo(const int cod[], const int activo[], int n, int codigo){
    int i;
    for (i = 0; i < n; i++)
    //ignora pase dados de baja
    if (cod[i] == codigo && activo[i] == 1)
    return i;
    //no esta activo
    return -1;
 }

 //Agregar espacio en el primer espacio libre
 void incluir(int cod[], char nom[][TAM_NOMBRE], int viajes[], int activo[], int *n, int codigo, const char nombre[], int cantidad){
    //guardar el codigo
    cod[*n] = codigo;
    //guardar el nombre
    strcpy(nom[*n], nombre);
    //guardar los viajes
    viajes[*n] = cantidad;
    //pase activo
    activo[*n] = 1;
    //proximo pase a posicion siguiente
    (*n)++;
 }
 //pases activos y cuantos son
 void consultar(const int cod[], const char nom[][TAM_NOMBRE],
    const int viajes[], const int activo[], int n){
        //indice del contador
    int i, activos = 0;

    //encabezado de la tabla
    //  no cabe y la tabla se desalinea. Se usa %18s aqui y en la fila.
    printf("%-6s %-12s %18s\n", "Codigo", "Nombre", "Viajes disponibles");
    //recorrer los espacios usados
    for (i = 0; i < n; i++){
        //solo activos
        if (activo[i] == 1){
            printf("%-6d %-12s %18d\n", cod[i], nom [i], viajes[i]);
            //cuenta pases
            activos++;
        }
    }
    //mostrar total
    printf("Pases activos: %d\n", activos);
    }
    //registar viajes si quedan
    int usarViaje(int *viajes){
        //revisa si quedan viajes
        if (*viajes == 0)
        //no registra
        return 0;
        //cambio en el arreglo
        (*viajes)--;
        return 1; //para confirmar desde main
    }

    //dar de baja
    void darDeBaja(int *activo){
        //se marca como inactivo
        *activo = 0;
    }

/*

Ejemplo 1: El acumulador mal hecho (Similar al del promedio)
Código con error:
C
#include <stdio.h>

int sumarEdades(const int edades[], int n) {
    int i, total = 0;
    for (i = 0; i < n; i++) {
        total = edades[i]; // <--- ¡Aquí está el error!
    }
    return total;
}

int main(void) {
    int misEdades[3] = {15, 20, 25};
    printf("Suma: %d\n", sumarEdades(misEdades, 3));
    return 0;
}
¿Qué pasa y por qué?
La instrucción total = edades[i]; reemplaza (sobrescribe) el valor de total en cada vuelta del ciclo. Al final, la función solo se queda con el valor de la última edad (25) y olvida las demás.

Código corregido:

C
// CORRECCION: Se debe acumular sumando el valor actual al total anterior: total += edades[i];
total += edades[i];
Ejemplo 2: Modificar una variable con punteros (Paso por dirección)
Código con error:
C
#include <stdio.h>

void duplicar(int numero) {
    numero = numero * 2; // <--- ¡Aquí está el error!
}

int main(void) {
    int x = 10;
    duplicar(x);
    printf("Valor: %d\n", x); // Imprime 10 en lugar de 20
    return 0;
}
¿Qué pasa y por qué?
La función duplicar recibe int numero, lo que significa que recibe una copia del valor de x (paso por valor). Modifica la copia por dentro, pero la variable x original del main nunca se entera ni cambia.

Código corregido:

C
// CORRECCION: Para que la función modifique la variable original, debe recibir un puntero (int *numero) 
// y usar el asterisco para cambiar su contenido (*numero = *numero * 2;), 
// y en el main se llama enviando la dirección: duplicar(&x);
Ejemplo 3: Confusión entre dirección y contenido en punteros
Código con error:
C
#include <stdio.h>

void cambiarMaximo(int *a, int b) {
    if (*a < b) {
        *a = b;
    }
}

int main(void) {
    int limite = 50;
    int actual = 30;
    cambiarMaximo(limite, actual); // <--- ¡Aquí está el error!
    printf("Limite: %d\n", limite);
    return 0;
}
¿Qué pasa y por qué?
La función cambiarMaximo fue diseñada para recibir un puntero en su primer parámetro (int *a), pero al llamarla desde el main pusimos limite sin el ampersand (&). Le estás mandando un número entero en lugar de su dirección de memoria. El compilador arrojará un error de tipos.

Código corregido:

C
// CORRECCION: Al llamar a la función, hay que pasar la dirección de la variable usando '&':
cambiarMaximo(&limite, actual);
Ejemplo 4: El error  en arreglos (Desbordamiento o índice fuera de rango)
 Código con error:
C
#include <stdio.h>

int main(void) {
    int codigos[3] = {101, 102, 103};
    int i;
    
    // Queremos mostrar los 3 códigos del arreglo
    for (i = 0; i <= 3; i++) {
        printf("Codigo: %d\n", codigos[i]); // <--- ¡Aquí está el error!
    }
    return 0;
}
¿Qué pasa y por qué?
El arreglo tiene un tamaño de 3, por lo que sus posiciones válidas son 0, 1 y 2. En la condición del ciclo pusiste i <= 3, lo que hace que en la última vuelta intente leer codigos[3], una posición que no existe en el arreglo (desbordamiento de memoria / out of bounds), lo que puede causar que imprima basura o que el programa falle.

Código corregido:

C
// CORRECCION: El ciclo debe correr estrictamente menor que el tamaño: i < 3 (o i < n)
for (i = 0; i < 3; i++) {





Ejemplo 1: Olvidar el asterisco al intentar modificar el valor
Cuando trabajamos con funciones que reciben punteros para cambiar los datos originales, es muy común olvidar el asterisco al momento de hacer la asignación.

Código con error:

C
void sumarDiez(int *numero) {
    numero = *numero + 10; // <--- ¡Error aquí!
}
¿Qué pasa y por qué?
Aquí estás intentando sumar 10 al contenido de *numero, pero el resultado se lo estás asignando a numero (que es la dirección de memoria, no la caja). El compilador detectará un error de incompatibilidad de tipos porque mezclas un puntero con un entero.

Código corregido:

C
// CORRECCION: El asterisco debe ir en la variable receptora para modificar el contenido de esa dirección:
*numero = *numero + 10; // o bien: *numero += 10;
Ejemplo 2: Asignar un número entero directamente a un puntero
Un puntero no guarda números normales, guarda direcciones de memoria.
 Código con error:

C
int *p;
*p = 50; // <--- ¡Error aquí!
Qué pasa y por qué?
Declaraste el puntero p, pero nunca lo inicializaste apuntando a ninguna variable real. Al escribir *p = 50;, intentas guardar el 50 en una dirección aleatoria o vacía de la memoria (lo que puede hacer que el programa falle o se cierre de golpe, conocido como un segmentation fault).

Código corregido:

C
// CORRECCION: Primero debes hacer que el puntero apunte a una variable existente usando '&':
int x;
int *p = &x; 
*p = 50; // Ahora sí, esto guarda 50 dentro de 'x' a través del puntero.
Ejemplo 3: Confundir una variable normal con un puntero en las funciones
Este error pasa cuando diseñamos bien la función con asteriscos, pero al llamarla desde el main se nos olvida poner el ampersand (&).

Código con error:

C
void cambiarEstado(int *activo) {
    *activo = 0;
}

int main(void) {
    int estadoActual = 1;
    cambiarEstado(estadoActual); // <--- ¡Falta el '&' aquí!
    return 0;
}
¿Qué pasa y por qué?
La función espera recibir obligatoriamente la dirección de memoria de un entero (int *), pero tú le estás enviando directamente el número 1 (estadoActual). El programa no compilará porque los tipos no coinciden.

 Código corregido:

C
// CORRECCION: Debes enviar la dirección de la variable usando '&':
cambiarEstado(&estadoActual);
Ejemplo 4: Guardar una dirección en una variable entera común (int)
Al igual que en el ejemplo de ordenar los números que vimos antes, a veces confundimos los tipos de datos al usar variables temporales.

Código con error:

void intercambiar(int *a, int *b) {
    int temp = a; // <--- ¡Error aquí!
    *a = *b;
    *b = temp;
}
¿Qué pasa y por qué?temp es una variable entera normal (int), pero a es un puntero (una dirección de memoria). Estás intentando meter una dirección en una variable común, lo que genera una advertencia o error en el compilador gcc.

Código corregido:


// CORRECCION: Como 'temp' debe guardar el valor numérico (el contenido), se debe usar el asterisco:
int temp = *a; 
*a = *b;
*b = temp;
*/





