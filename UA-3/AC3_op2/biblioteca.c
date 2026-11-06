// biblioteca.c - AC3 parte 2: prestamo de libros (PLANTILLA DE INICIO)
// ENUNCIADO: (copie aqui el enunciado con sus palabras)
// QUE SE LOGRA: (complete)
// COMO SE LOGRA: (complete)
// RESULTADO ESPERADO: (complete con el caso de prueba)
//
// COMO USAR ESTA PLANTILLA:
//   - main, el menu y leerEntero ya estan hechos: NO necesita cambiarlos.
//   - Usted programa el CUERPO de las 5 funciones marcadas con TAREA, en el
//     orden de los numeros, siguiendo los PASOS de cada una.
//   - Compile despues de cada funcion. Al inicio aparecen advertencias
//     "unused parameter": desaparecen al completar las funciones.
//   - Agregue sus comentarios (que hace, como y para que).

#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 5  // espacios para libros
#define TAM_TITULO 20 // 19 letras + el '\0'
#define COD_MIN 100   // codigo minimo
#define COD_MAX 999   // codigo maximo
#define EJEM_MAX 20   // ejemplares maximos al incluir

// Prototipos: ya estan escritos. Fijese en los que llevan * (punteros).
int leerEntero(const char mensaje[], int minimo, int maximo);
int buscarCodigo(const int cod[], const int activo[], int n, int codigo);
void incluir(int cod[], char tit[][TAM_TITULO], int disp[], int activo[],
             int *n, int codigo, const char titulo[], int ejemplares);
void consultar(const int cod[], const char tit[][TAM_TITULO],
               const int disp[], const int activo[], int n);
int prestar(int *disponibles);
void darDeBaja(int *activo);

int main(void)
{
    int cod[MAX_LIBROS] = {101, 102, 103};
    char tit[MAX_LIBROS][TAM_TITULO] = {"Quijote", "Principito", "Cocori"};
    int disp[MAX_LIBROS] = {3, 2, 4};
    int activo[MAX_LIBROS] = {1, 1, 1}; // 1 activo, 0 dado de baja
    int n = 3;                          // espacios usados
    int opcion, codigo, pos, ejemplares;
    char titulo[TAM_TITULO];

    do
    {
        printf("\n=== Biblioteca escolar ===\n");
        printf("1 Incluir  2 Consultar  3 Prestar  4 Dar de baja\n");
        printf("5 Buscar  0 Salir\n");
        opcion = leerEntero("Opcion", 0, 5);
        // Las opciones 3, 4 y 5 necesitan un libro: se busca una sola vez.
        if (opcion >= 3)
        {
            codigo = leerEntero("Codigo", COD_MIN, COD_MAX);
            pos = buscarCodigo(cod, activo, n, codigo);
            if (pos == -1)
            {
                printf("No existe un libro activo con el codigo %d\n",
                       codigo);
                continue;
            }
        }
        switch (opcion)
        {
        case 1:
            if (n == MAX_LIBROS)
            {
                printf("No hay espacio para mas libros\n");
                break;
            }
            codigo = leerEntero("Codigo", COD_MIN, COD_MAX);
            if (buscarCodigo(cod, activo, n, codigo) != -1) // el menos uno que altere
            {
                printf("El codigo %d ya existe\n", codigo);
                break;
            }
            printf("Titulo (una palabra): ");
            scanf("%19s", titulo);
            ejemplares = leerEntero("Ejemplares", 1, EJEM_MAX);
            // &n: se envia la DIRECCION de n para que incluir la aumente
            incluir(cod, tit, disp, activo, &n, codigo, titulo,
                    ejemplares);
            printf("Libro incluido (%d de %d)\n", n, MAX_LIBROS);
            break;
        case 2:
            consultar(cod, tit, disp, activo, n);
            break;
        case 3:
            // &disp[pos]: la DIRECCION de los disponibles de ese libro
            if (prestar(&disp[pos]))
                printf("Prestado. Disponibles de %s: %d\n", tit[pos],
                       disp[pos]);
            else
                printf("No hay ejemplares disponibles de %s\n",
                       tit[pos]);
            break;
        case 4:
            // &activo[pos]: la DIRECCION del estado de ese libro
            darDeBaja(&activo[pos]);
            printf("Libro %s dado de baja\n", tit[pos]);
            break;
        case 5:
            printf("%d %s: %d disponibles\n", cod[pos], tit[pos],
                   disp[pos]);
            break;
        default:
            printf("Hasta luego\n");
        }
    } while (opcion != 0);
    return 0;
}
// Qué hace: Pide un número por pantalla asegurándose de que esté dentro de un rango mínimo y máximo permitido, repitiéndose con un ciclo do-while si el usuario ingresa un valor incorrecto
int leerEntero(const char mensaje[], int minimo, int maximo)
{
    int valor;
    do
    {
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        scanf("%d", &valor);
    } while (valor < minimo || valor > maximo);// Se repite si el valor no es válido
    return valor;
}
// Qué hace: Recorre el arreglo de códigos buscando uno específico que además esté marcado como activo (1). Si lo encuentra, devuelve su posición; si no, retorna -1.
int buscarCodigo(const int cod[], const int activo[], int n, int codigo)
{

    int i;
    for (i = 0; i < n; i++)
    {
        // Si coincide el codigo y esta activo, devuelve la posicion
        if (cod[i] == codigo && activo[i] == 1)
        {
            return i; // se cambio con i en vez de 1
            // Devuelve la posición exacta del libro
        }
    }
    // corregi el return -1 por mala posicion
    return -1;
}
// Qué hace: Registra un nuevo libro aprovechando la siguiente posición libre indicada por n, guardando su código, el título copiado, los ejemplares y el estado activo (1), para luego incrementar el contador de elementos.
void incluir(int cod[], char tit[][TAM_TITULO], int disp[], int activo[],
             int *n, int codigo, const char titulo[], int ejemplares)
{

    // guarda el codigo
    cod[*n] = codigo;
    // guardar el nombre
    strcpy(tit[*n], titulo);
    // guardar cantidades
    disp[*n] = ejemplares;
    // disponibles
    activo[*n] = 1;
    (*n)++;
}
// Qué hace: Imprime una tabla organizada con los datos de todos los libros que se encuentran activos actualmente y muestra al final el conteo total de los mismos.
void consultar(const int cod[], const char tit[][TAM_TITULO],
            const int disp[], const int activo[], int n)
{

    int i, activos = 0;
    // elimine el printf que usaba el i sin inicializar para evitar el segmentation default
    // encabezado tipo tabla
    printf("%-6s %-12s %18s\n", "Codigo", "Titulo", "Disponibles");

    for (i = 0; i < n; i++)
    {
        /* se va a evaluar el activo[i] y no disp[i]  */
        if (activo[i] == 1)
        {
            printf("%-6d %-12s %18d\n", cod[i], tit[i], disp[i]);
            activos++;// suma 1 al contador de libros activos
        }
    }
    // se muestra el total de libros activos a fuera del for
    printf("Libros activos: %d\n", activos);
}
// Qué hace: Verifica si quedan ejemplares disponibles. Si es así, descuenta uno utilizando punteros y devuelve 1 (éxito); de lo contrario, retorna 0 (sin existencias).
int prestar(int *disponibles)
{

    // Se evalúa primero si es 0 para retornar 0.
    if (*disponibles == 0)
    {
        return 0;
    }
    // Se resta  despues de validar y se devuelve 1 para confirmar.
    (*disponibles)--;
    return 1;
}
// Qué hace: Modifica el estado del libro apuntado a 0 mediante punteros, haciendo que deje de aparecer automáticamente en las consultas y búsquedas del sistema.
void darDeBaja(int *activo)
{
    //se supone que se marca como inactivo
    *activo = 0;
}
